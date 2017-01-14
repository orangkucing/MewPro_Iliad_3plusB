#define EEPROM_ID_LEN 32
#define IR_REMOTE_LEN 32
#define IDSTRING "MewPro 3+B"

void ROM_Read()
{
  int base, i, j;
  byte *addr;
  boolean f = true;
  // signature check
  char tmp[EEPROM_ID_LEN + 1] = IDSTRING ":" __VERSION_STRING__;
  
  for (i = 0; i < EEPROM_ID_LEN; i++) {
     f &= (EEPROM.read(i) == tmp[i]);
  }
  if (!f) {
    SERIAL.println("factory reset");
    base = 0;
    for (i = 0; i < EEPROM_ID_LEN; i++) {
      EEPROM.write(i, tmp[i]);
    }
    ROM_write();
    // factory reset doesn't override IR remote settings
    // because these values are garbage initially.
  }
  base = EEPROM_ID_LEN;
  addr = (byte *)IRkey.l;
  for (i = 0; i < sizeof(IRkey); i++) {
    *(addr + i) = EEPROM.read(i + base);
  }
  base += IR_REMOTE_LEN;
  for (i = 0; i < SETUP_LEN; i++) {
    setting.b[i] = EEPROM.read(i + base);
  }
  setting.p.mode = setting.p.default_app_mode;
}

void ROM_write()
{
  int i, j;
  int base = EEPROM_ID_LEN + IR_REMOTE_LEN;
  for (i = 0; i < SETUP_LEN; i++) {
    EEPROM.write(i + base, setting.b[i]);
  }
}

