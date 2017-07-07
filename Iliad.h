#include <Arduino.h>
#include <avr/wdt.h>
#include <EEPROM.h>
#include "Pins.h"
#include "Videomode.h"
#include "MenuText.h"

#define __VERSION_STRING__ "v1.3.5"

#ifdef USE_LCD
#  include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
// lcd(RS, Enable, Data4, Data5, Data6, Data7)
LiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_DATA4, LCD_DATA5, LCD_DATA6, LCD_DATA7);
#  define LCD_SIZE_X 16
#  define LCD_SIZE_Y 2
#endif /* USE_LCD */

#ifdef USE_IR_REMOTE
// using IRremote library at
//     https://github.com/z3t0/Arduino-IRremote
// WARNING: The IRremote library conflicts with RobotIRremote library in the standard Arduino IDE.
// So please delete your_IDE_folder/Contents/Java/libraries/RobotIRremote 
#  include <IRremote.h>
IRrecv irrecv(IR_RECEIVE);
#endif /* USE_IR_REMOTE */

#ifdef USE_RTC
#  include <Wire.h>
// using RTClib at
//     https://learn.adafruit.com/adafruit-ds3231-precision-rtc-breakout/wiring-and-test
// ***** comment out the following line unless USE_RTC
#  include "RTClib.h"
RTC_DS3231 rtc;
#else
// Time and TimeAlarms libraries are downloadable from
//   http://www.pjrc.com/teensy/td_libs_Time.html
// ***** uncomment unless USE_RTC
//#  include <TimeLib.h>
#endif /* USE_RTC */

#define MEWPRO_BUFFER_LENGTH 256

byte command_buf[MEWPRO_BUFFER_LENGTH];
int fifo_readindex = 0;
int fifo_writeindex = 0;
#define FIFO(i) (command_buf[(fifo_writeindex + (i)) % MEWPRO_BUFFER_LENGTH])
#define FIFO_INC(n) do { fifo_writeindex = (fifo_writeindex + (n)) % MEWPRO_BUFFER_LENGTH; } while (0)

byte buf[MEWPRO_BUFFER_LENGTH];
int bufp = 1;
unsigned char session = 0xFF;

int protocol = 1;
int state = 0;

// IR remote
union {
  unsigned long l[4];
  struct {
    unsigned long MENU;
    unsigned long OK;
    unsigned long DOWN;
    unsigned long POWER;
  } p;
} IRkey;

// menu
#define MENU_START   0
#define MENU_MAIN    1
#define MENU_SUB     2
#define MENU_EXIT    3
#define MENU_SETTING 4
// recording_state
#define STATE_IDLE      0
#define STATE_START     1
#define STATE_SYNC_ON   2
#define STATE_RECORDING 3
#define STATE_STOP      4
#define STATE_END       5
#define STATE_SYNC_OFF  6
#define STATE_RESTART   7  // timelapse only
#define STATE_PAUSE     8  // timelapse only
char setup_id = 0;
char disp_state = MENU_START;
volatile char recording_state = STATE_IDLE;
unsigned long start_time;
unsigned int record_time;

// startup
#define STARTUP_HALT (-1)
char startupSession = STARTUP_HALT;
// function prototype declaration required here
// because current Arduino IDE can't automatically do this
boolean startup_init(void);
boolean startup_delay0(void);
boolean startup0(void);

boolean (*startup[])(void) = {
  startup_init,
  startup_delay0,
  startup0,
  NULL
};

