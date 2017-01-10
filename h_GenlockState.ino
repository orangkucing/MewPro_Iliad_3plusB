void checkGenlockState()
{
  static unsigned long command_sent;
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_RECORDING:
      switch (setting.p.mode) {
        case MODE_VIDEO:
        case MODE_TIMELAPSE:
          break;
        case MODE_PHOTO:
          if (millis() - command_sent > 3500) {
            recording_state = STATE_SYNC_OFF;
          }
          break;
        case MODE_BURST:
          if (millis() - command_sent > 5000) {
            recording_state = STATE_SYNC_OFF;
          }
          break;
      }
      break;
    case STATE_RESTART: // Time Lapse only
      command_sent = millis();
      {
        char c;
        c = 'S'; BROADCAST.write(c); SERIAL.print(c);
        c = 'Y'; BROADCAST.write(c); SERIAL.print(c);
        c = '2'; BROADCAST.write(c); SERIAL.print(c);
        c = '\n'; BROADCAST.write(c); SERIAL.print(c);
      }
      SERIAL.println(command_sent, DEC);
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_START:
      if (setting.p.mode == MODE_TIMELAPSE) {
        delay(165);
        StartTimerInterrupt();
        command_sent = millis();
      } else {
        command_sent = millis();
      }
      SERIAL.println(command_sent, DEC);
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_STOP:
      command_sent = millis();
      recording_state = STATE_END;
      break;
    case STATE_SYNC_ON:
      switch (setting.p.mode) {
        case MODE_VIDEO:
          if (millis() - command_sent > 1000) {
            SERIAL.print(F("genlock signal start: (resolution, fps) = (0x0"));
            SERIAL.print(setting.p.video_resolution, HEX);
            SERIAL.print(F(", 0x0"));
            SERIAL.print(setting.p.video_fps, HEX);
            SERIAL.println(F(")"));
            StartSyncSignal(setting.p.video_resolution * FPS_TABLE_SIZE + setting.p.video_fps);
            recording_state = STATE_RECORDING;
            updateLCD();
          }
          break;
        case MODE_TIMELAPSE:
          if (millis() - command_sent > 110) {
            digitalWrite(TRIG, LOW);
            delay(10);
            digitalWrite(TRIG, HIGH);
            delay(50);
            SERIAL.print(millis(), DEC); SERIAL.print(" ");
            SERIAL.print(F("genlock signal start: resolution = 0x0"));
            SERIAL.println(setting.p.photo_resolution, HEX);
            StartSyncSignal(11 * FPS_TABLE_SIZE + setting.p.photo_resolution); // photo modes are stored at the end of the video mode table
            delay(1200);
            StopSyncSignal();
            recording_state = STATE_RECORDING;
          }
          break;
        case MODE_PHOTO:
        case MODE_BURST:
          if (millis() - command_sent > 800) {
            SERIAL.print(F("genlock signal start: resolution = 0x0"));
            SERIAL.println(setting.p.photo_resolution, HEX);
            StartSyncSignal(11 * FPS_TABLE_SIZE + setting.p.photo_resolution); // photo modes are stored at the end of the video mode table
            recording_state = STATE_RECORDING;
          }
          break;
      }
      break;
    case STATE_END:
      Serial.println("end");
      switch (setting.p.mode) {
        case MODE_VIDEO:
          if (millis() - command_sent > 400) {
            digitalWrite(TRIG, LOW); // video stops at FALLING edge
            delay(1);
            digitalWrite(TRIG, HIGH);
            recording_state = STATE_SYNC_OFF;
          }
          break;
        case MODE_TIMELAPSE:
          StopTimerInterrupt();
          recording_state = STATE_IDLE;
          break;
      }
      break;
    case STATE_SYNC_OFF:
      if (millis() - command_sent > 1400) {
       Serial.println("sync_off");
       SERIAL.println(F("genlock signal stop"));
        StopSyncSignal();
        recording_state = STATE_IDLE;
        updateLCD();
      }
      break;
  }
}

