void printHex(uint8_t d, boolean upper)
{
  char t;
  char a = upper ? 'A' : 'a';
  t = d >> 4 | '0';
  if (t > '9') {
    t += a - '9' - 1;
  }
  SERIAL.print(t);
  t = d & 0xF | '0';
  if (t > '9') {
    t += a - '9' - 1;
  }
  SERIAL.print(t);
}

void _printOutPut()
{
  int buflen = buf[0];
  SERIAL.print(F("> "));
  for (int i = 1; i <= buflen; i++) {
    if ((i == 1 || i == 2) && isprint(buf[i])) {
      SERIAL.print(' '); SERIAL.print((char) buf[i]);
    } else {
      printHex(buf[i], false);
    }
    SERIAL.print(' ');
  }
  SERIAL.println("");
}

// parse command that is broadcasted to cameras
void parseSerialWrite()
{
  _printOutPut();
  if (buf[0] >= 3) {
    switch ((buf[1] << 8) + buf[2]) {
      case ('A' << 8) + 'I': // SET_CAMERA_AUDIOINPUTMODE
        break;
      case ('A' << 8) + 'O': // SET_CAMERA_AUTO_POWEROFF
        setting.p.auto_power_down = buf[3];
        break;
      case ('B' << 8) + 'S': // SET_CAMERA_BEEP_SOUND
        setting.p.beep_volume = buf[3];
        break;
      case ('B' << 8) + 'U': // SET_CAMERA_BURST_RATE
        setting.p.burst_rate = buf[3];
        break;
      case ('C' << 8) + 'M': // SET_CAMERA_MODE
        setting.p.mode = buf[3];
        break;
      case ('C' << 8) + 'O': // SET_CAMERA_PROTUNE_COLOR
        setting.p.protune_color = buf[3];
        break;
      case ('C' << 8) + 'S': // SET_CAMERA_CONTINUOUS_SHOT
        setting.p.continuous_rate = buf[3];
        break;
      case ('D' << 8) + 'A': // SET_CAMERA_DELETE_ALL
        break;
      case ('D' << 8) + 'L': // SET_CAMERA_DELETE_LAST
        break;
      case ('D' << 8) + 'M': // SET_CAMERA_DEFAULT_MODE
        setting.p.default_app_mode = buf[3];
        break;
      case ('D' << 8) + 'S': // SET_CAMERA_ONSCREEN_DISPLAY
        setting.p.osd = buf[3];
        break;
      case ('E' << 8) + 'V': // SET_CAMERA_PROTUNE_EXPOSURE_VALUE
        setting.p.protune_ev = buf[3];
        break;
      case ('E' << 8) + 'X': // SET_CAMERA_EXPOSURE
        setting.p.spot_meter = buf[3];
        break;
      case ('F' << 8) + 'N': // SET_CAMERA_FAULT
        break;
      case ('F' << 8) + 'S': // SET_CAMERA_FRAMES_PER_SEC
        setting.p.video_fps = buf[3];
        break;
      case ('F' << 8) + 'V': // SET_CAMERA_FOV
        setting.p.video_fov = buf[3];
        break;
      case ('G' << 8) + 'A': // SET_CAMERA_PROTUNE_GAIN
        setting.p.protune_iso = buf[3];
        break;
      case ('L' << 8) + 'B': // SET_CAMERA_LEDBLINK
        setting.p.led = buf[3];
        break;
      case ('L' << 8) + 'O': // SET_CAMERA_LOOPING_MODE
        setting.p.looping = buf[3];
        break;
      case ('P' << 8) + 'N': // SET_CAMERA_PHOTO_INVIDEO
        setting.p.piv = buf[3];
        break;
      case ('P' << 8) + 'R': // SET_CAMERA_PHOTO_RESOLUTION
        setting.p.photo_resolution = buf[3];
        break;
      case ('P' << 8) + 'T': // SET_CAMERA_PROTUNE_MODE
        setting.p.protune = buf[3];
        break;
      case ('P' << 8) + 'W': // SET_CAMERA_POWER_STATE
        switch (buf[3]) {
          case 0: // power off
            disp_state = MENU_START;
            ROM_write(); // store settings to EEPROM
            break;
        }
        break;
      case ('S' << 8) + 'H': // SET_CAMERA_SHUTTER_ACTION
        break;
      case ('S' << 8) + 'P': // SET_CAMERA_PROTUNE_SHARPNESS
        setting.p.protune_sharpness = buf[3];
        break;
      case ('S' << 8) + 'Y': // SET_CAMERA_3D_SYNCHRONIZE
        switch (buf[3]) {
          case 0: // sync stop
            recording_state = STATE_STOP;
            break;
          case 1: // shutter button depressed. start
            recording_state = STATE_START;
            break;
        }
        break;
      case ('T' << 8) + 'D': // SET_CAMERA_SETTING
        rtc.adjust(DateTime((int)(2000 + buf[3]), buf[4], buf[5], buf[6], buf[7], buf[8]));
        setting.p.mode = buf[9];
        setting.p.photo_resolution = buf[10];
        // buf[11]
        setting.p.video_resolution = buf[12];
        setting.p.video_fps = buf[13];
        setting.p.video_fov = buf[14];
        setting.p.spot_meter = buf[15];
        setting.p.timelapse_rate = buf[16];
        // buf[17]
        setting.p.beep_volume = buf[18];
        setting.p.video_format = buf[19];
        setting.p.osd = buf[20];
        setting.p.led = buf[21];
        setting.p.piv = buf[22];
        setting.p.looping = buf[23];
        setting.p.continuous_rate = buf[24];
        setting.p.burst_rate = buf[25];
        setting.p.protune = buf[26];
        setting.p.auto_power_down = buf[27];
        setting.p.protune_white_balance = buf[28];
        // buf[29]
        // buf[30]
        // buf[31]
        // buf[32]
        // buf[33]
        // buf[34]
        setting.p.orientation = buf[35];
        setting.p.default_app_mode = buf[36];
        setting.p.protune_color = buf[37];
        setting.p.protune_iso = buf[38];
        setting.p.protune_sharpness = buf[39];
        setting.p.protune_ev = buf[40];
        break;
      case ('T' << 8) + 'I': // SET_CAMERA_PHOTO_XSEC
        setting.p.timelapse_rate = buf[3];
        break;
      case ('T' << 8) + 'M': // SET_CAMERA_DATE_TIME
        rtc.adjust(DateTime((int)(2000 + buf[3]), buf[4], buf[5], buf[6], buf[7], buf[8]));
        break;
      case ('T' << 8) + 'S': // SET_CAMERA_TIME_LAPSE
        // obsolete (use TI)
        break;
      case ('U' << 8) + 'M': // SET_CAMERA_USBMODE
        break;
      case ('U' << 8) + 'P': // SET_CAMERA_FLIP_MIRROR
        setting.p.orientation = buf[3];
        break;
      case ('V' << 8) + 'M': // SET_CAMERA_NTSC_PAL
        setting.p.video_format = buf[3];
        break;
      case ('V' << 8) + 'O': // SET_CAMERA_VIDEO_OUTPUT
        break;
      case ('V' << 8) + 'R': // SET_CAMERA_VIDEORESOLUTION
        // obsolete (use VV)
        break;
      case ('V' << 8) + 'V': // SET_CAMERA_VIDEORESOLUTION_VV
        setting.p.video_resolution = buf[3];
        break;
      case ('W' << 8) + 'B': // SET_CAMERA_WHITE_BALANCE
        setting.p.protune_white_balance = buf[3];
        break;
      case ('X' << 8) + 'S': // SET_CAMERA_SLAVE_SETTINGS
        break;
    }
  }
}
