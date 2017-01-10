// these functions are called after camera power on
void startup_delay0()
{
  delay(5000);
}

void startup_delay()
{
  delay(1000);
}
void startup0()
{
  Broadcast_ChangeSettings();
}
//

void sprintHex(int index, uint8_t d)
{
  char t;
  char a = 'A';
  t = d >> 4 | '0';
  if (t > '9') {
    t += a - '9' - 1;
  }
  FIFO(index) = t;
  t = d & 0xF | '0';
  if (t > '9') {
    t += a - '9' - 1;
  }
  FIFO(index + 1) = t;
}

void __queueIn(char c1, char c2, char arg)
{
  FIFO(0) = c1;
  FIFO(1) = c2;
  sprintHex(2, arg);
  FIFO(4) = '\n';
  FIFO_INC(5);
}

void FIFOCPY_P(int index, const __FlashStringHelper *p, int s)
{
  for (int i = 0; i < s; i++) {
    FIFO(index + i) = (char)pgm_read_byte((char *)p + i);
  }
}

void Broadcast_ChangeMode()
{
  // next mode
  switch (setting.p.mode) {
    case MODE_VIDEO:
      setting.p.mode = MODE_PHOTO;
      break;
    case MODE_PHOTO:
      setting.p.mode = MODE_BURST;
      break;
    case MODE_BURST:
      setting.p.mode = MODE_TIMELAPSE;
      break;
    case MODE_TIMELAPSE:
      setting.p.mode = MODE_SETTINGS;
      break;
    case MODE_SETTINGS:
      setting.p.mode = MODE_VIDEO;
      break;
  }
  __queueIn('C', 'M', setting.p.mode);
}

char settings_level;

void Broadcast_ChangeSettings()
{
  DateTime now;
  if (startupSession == STARTUP_HALT) {
    // not within startup sessions
    while (nextWidget()) { // update to permissible options
      ;
    }
#ifndef BULK_SETTING_TRANSFER
    return;
#endif
  }
  FIFOCPY_P(0, F("TD"), 2);
  now = rtc.now();
  sprintHex(0 * 2 + 2, (uint8_t)(now.year() % 100));
  sprintHex(1 * 2 + 2, (uint8_t)now.month());
  sprintHex(2 * 2 + 2, (uint8_t)now.day());
  sprintHex(3 * 2 + 2, (uint8_t)now.hour());
  sprintHex(4 * 2 + 2, (uint8_t)now.minute());
  sprintHex(5 * 2 + 2, (uint8_t)now.second());
  sprintHex(6 * 2 + 2, setting.p.mode);
  sprintHex(7 * 2 + 2, setting.p.photo_resolution);
  sprintHex(8 * 2 + 2, 0xff);
  sprintHex(9 * 2 + 2, setting.p.video_resolution);
  sprintHex(10 * 2 + 2, setting.p.video_fps);
  sprintHex(11 * 2 + 2, setting.p.video_fov);
  sprintHex(12 * 2 + 2, setting.p.spot_meter);
  sprintHex(13 * 2 + 2, setting.p.timelapse_rate);
  sprintHex(14 * 2 + 2, 0);
  sprintHex(15 * 2 + 2, setting.p.beep_volume);
  sprintHex(16 * 2 + 2, setting.p.video_format);
  sprintHex(17 * 2 + 2, setting.p.osd);
  sprintHex(18 * 2 + 2, setting.p.led);
  sprintHex(19 * 2 + 2, setting.p.piv);
  sprintHex(20 * 2 + 2, setting.p.looping);
  sprintHex(21 * 2 + 2, setting.p.continuous_rate);
  sprintHex(22 * 2 + 2, setting.p.burst_rate);
  sprintHex(23 * 2 + 2, setting.p.protune);
  sprintHex(24 * 2 + 2, setting.p.auto_power_down);
  sprintHex(25 * 2 + 2, setting.p.protune_white_balance);
  sprintHex(26 * 2 + 2, 0);
  sprintHex(27 * 2 + 2, 0);
  sprintHex(28 * 2 + 2, 0);
  sprintHex(29 * 2 + 2, 0);
  sprintHex(30 * 2 + 2, 0);
  sprintHex(31 * 2 + 2, 0);
  sprintHex(32 * 2 + 2, setting.p.orientation);
  sprintHex(33 * 2 + 2, setting.p.default_app_mode);
  sprintHex(34 * 2 + 2, setting.p.protune_color);
  sprintHex(35 * 2 + 2, setting.p.protune_iso);
  sprintHex(36 * 2 + 2, setting.p.protune_sharpness);
  sprintHex(37 * 2 + 2, setting.p.protune_ev);
  FIFO(78) = '\n';
  FIFO_INC(79);
}


void Broadcast_ChangeSetting(char id)
{
#ifndef BULK_SETTING_TRANSFER
  switch (id) {
    case &setting.p.video_resolution - setting.b:
      __queueIn('V', 'V', setting.p.video_resolution); break;
    case &setting.p.video_fps - setting.b:
      __queueIn('F', 'S', setting.p.video_fps); break;
    case &setting.p.video_fov - setting.b:
      __queueIn('F', 'V', setting.p.video_fov); break;
    case &setting.p.photo_resolution - setting.b:
      __queueIn('P', 'R', setting.p.photo_resolution); break;
    case &setting.p.continuous_rate - setting.b:
      __queueIn('C', 'S', setting.p.continuous_rate); break;
    case &setting.p.burst_rate - setting.b:
      __queueIn('B', 'U', setting.p.burst_rate); break;
    case &setting.p.timelapse_rate - setting.b:
      __queueIn('T', 'I', setting.p.timelapse_rate); break;
    case &setting.p.orientation - setting.b:
      __queueIn('U', 'P', setting.p.orientation); break;
    case &setting.p.spot_meter - setting.b:
      __queueIn('E', 'X', setting.p.spot_meter); break;
    case &setting.p.piv - setting.b:
      __queueIn('P', 'N', setting.p.piv); break;
    case &setting.p.looping - setting.b:
      __queueIn('L', 'O', setting.p.looping); break;
    case &setting.p.protune - setting.b:
      __queueIn('P', 'T', setting.p.protune); break;
    case &setting.p.protune_white_balance - setting.b:
      __queueIn('W', 'B', setting.p.protune_white_balance); break;
    case &setting.p.protune_color - setting.b:
      __queueIn('C', 'O', setting.p.protune_color); break;
    case &setting.p.protune_iso - setting.b:
      __queueIn('G', 'A', setting.p.protune_iso); break;
    case &setting.p.protune_sharpness - setting.b:
      __queueIn('S', 'P', setting.p.protune_sharpness); break;
    case &setting.p.protune_ev - setting.b:
      __queueIn('E', 'V', setting.p.protune_ev); break;  
    case &setting.p.default_app_mode - setting.b:
      __queueIn('D', 'M', setting.p.default_app_mode); break;
//    case &setting.p.quick_capture - setting.b:
//      __queueIn('O', 'B', setting.p.quick_capture); break;
    case &setting.p.video_format - setting.b:
      __queueIn('V', 'M', setting.p.video_format); break;
    case &setting.p.osd - setting.b:
      __queueIn('D', 'S', setting.p.osd); break;
    case &setting.p.led - setting.b:
      __queueIn('L', 'B', setting.p.led); break;
    case &setting.p.beep_volume - setting.b:
      __queueIn('B', 'S', setting.p.beep_volume); break;
    case &setting.p.auto_power_down - setting.b:
      __queueIn('A', 'O', setting.p.auto_power_down); break;
  }
#endif /* not BULK_SETTING_TRANSFER */
}

void Broadcast_StartRecording()
{
  __queueIn('S', 'Y', 1);
}

void Broadcast_StopRecording()
{
  __queueIn('S', 'Y', 0);
}

void Broadcast_PowerOn()
{
  FIFO(0) = '@';
  FIFO(1) = '\n';
  FIFO_INC(2);
}

void Broadcast_PowerOff()
{
  __queueIn('P', 'W', 0);
}

