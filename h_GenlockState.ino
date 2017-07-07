unsigned long command_sent;

void checkGenlockState_Video()
{
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_START:
      command_sent = millis();
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_SYNC_ON: 
      if (millis() - command_sent > 1000) {
        DEBUG_print(F("genlock signal start: (resolution, fps) = (0x0"));
        DEBUG_print(setting.p.video_resolution, HEX);
        DEBUG_print(F(", 0x0"));
        DEBUG_print(setting.p.video_fps, HEX);
        DEBUG_println(F(")"));
        if (setting.p.video_fov != 2) { // WIDE or MEDIUM
          StartSyncSignal(setting.p.video_resolution * FPS_TABLE_SIZE + setting.p.video_fps);
        } else { // NARROW
          switch (setting.p.video_resolution) {
            case 1: // 720p
              StartSyncSignal(SYNC_TIME_720_NARROW * FPS_TABLE_SIZE + setting.p.video_fps);
              break;
            case 3: // 1080p
              StartSyncSignal(SYNC_TIME_1080_NARROW * FPS_TABLE_SIZE + setting.p.video_fps);
              break;
          }
        }
        recording_state = STATE_RECORDING;
        updateLCD();
      }
      break;
    case STATE_RECORDING:
      break;
    case STATE_STOP:
      command_sent = millis();
      recording_state = STATE_END;
      break;
    case STATE_END:
      if (millis() - command_sent > 400) {
        digitalWrite(TRIG, LOW); // video stops at FALLING edge
        delay(1);
        digitalWrite(TRIG, HIGH);
        recording_state = STATE_SYNC_OFF;
      }
      break;
    case STATE_SYNC_OFF:
      if (millis() - command_sent > 1400) {
        DEBUG_println(F("genlock signal stop"));
        StopSyncSignal();
        recording_state = STATE_IDLE;
        updateLCD();
      }
      break;
  }
}

void checkGenlockState_Photo()
{
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_START:
      command_sent = millis();
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_SYNC_ON:        
      if (millis() - command_sent > 800) {
        DEBUG_print(F("genlock signal start: resolution = 0x0"));
        DEBUG_println(setting.p.photo_resolution, HEX);
        StartSyncSignal(SYNC_TIME_PHOTO * FPS_TABLE_SIZE + setting.p.photo_resolution); // photo modes are stored at the end of the video mode table
        recording_state = STATE_RECORDING;
      }
      break;
    case STATE_RECORDING:
      if (millis() - command_sent > 3500) {
        recording_state = STATE_SYNC_OFF;
      }
      break;
    case STATE_SYNC_OFF:
      if (millis() - command_sent > 1400) {
        DEBUG_println(F("genlock signal stop"));
        StopSyncSignal();
        recording_state = STATE_IDLE;
        updateLCD();
      }
      break;
  }
}

void checkGenlockState_Burst()
{
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_START:
      command_sent = millis();
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_SYNC_ON:        
      if (millis() - command_sent > 800) {
        DEBUG_print(F("genlock signal start: resolution = 0x0"));
        DEBUG_println(setting.p.photo_resolution, HEX);
        StartSyncSignal(SYNC_TIME_PHOTO * FPS_TABLE_SIZE + setting.p.photo_resolution); // photo modes are stored at the end of the video mode table
        recording_state = STATE_RECORDING;
      }
      break;
    case STATE_RECORDING:
      if (millis() - command_sent > 5000) {
        recording_state = STATE_SYNC_OFF;
      }
      break;
    case STATE_SYNC_OFF:
      if (millis() - command_sent > 1400) {
        DEBUG_println(F("genlock signal stop"));
        StopSyncSignal();
        recording_state = STATE_IDLE;
        updateLCD();
      }
      break;
  }
}

void checkGenlockState_Timelapse()
{
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_START:
      delay(165);
      StartTimerInterrupt(setting.p.timelapse_rate);
      command_sent = millis();
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_SYNC_ON:
      if (millis() - command_sent > 110) {
        digitalWrite(TRIG, LOW);
        delay(10);
        digitalWrite(TRIG, HIGH);
        delay(50);
        DEBUG_print(F("genlock signal start: resolution = 0x0"));
        DEBUG_println(setting.p.photo_resolution, HEX);
        StartSyncSignal(SYNC_TIME_PHOTO * FPS_TABLE_SIZE + setting.p.photo_resolution); // photo modes are stored at the end of the video mode table
        recording_state = STATE_RECORDING;
      }
      break;
    case STATE_RECORDING:
      if (millis() - command_sent > 1370) {
        recording_state = STATE_SYNC_OFF;
      }
      break;
    case STATE_SYNC_OFF:
      DEBUG_println(F("genlock signal stop"));
      StopSyncSignal();
      recording_state = STATE_PAUSE;
      break;
    case STATE_PAUSE:
      if (rate == 0) {
        recording_state = STATE_IDLE;
        updateLCD();
      }
      break;
    case STATE_RESTART:
      command_sent = millis();
      WRITE_CHAR('S'); WRITE_CHAR('Y'); WRITE_CHAR('2'); WRITE_CHAR('\n');
      recording_state = STATE_SYNC_ON;
      break;
  }
}

void checkGenlockState()
{
  switch (setting.p.mode) {
    case MODE_VIDEO:
      checkGenlockState_Video();
      break;
    case MODE_PHOTO:
      checkGenlockState_Photo();
      break;
    case MODE_BURST:
      checkGenlockState_Burst();
      break;
    case MODE_TIMELAPSE:
      checkGenlockState_Timelapse();
      break;
  }
}
