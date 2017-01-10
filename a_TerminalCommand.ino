void __emptyInputBuffer()
{
  while (SERIAL.available()) {
    if (SERIAL.read() == '\n') {
      return;
    }
  }
  fifo_readindex = fifo_writeindex = 0;
}

void checkTerminalCommands()
{
  while (SERIAL.available() || fifo_readindex != fifo_writeindex) {
    static boolean shiftable;
    char c;

    if (SERIAL.available()) {
      c = SERIAL.read();
    } else {
      c = command_buf[fifo_readindex];
      ++fifo_readindex %= MEWPRO_BUFFER_LENGTH;
    }
    BROADCAST.write(c);
    SERIAL.print(c);
    
    switch (c) {
      case ' ':
        shiftable = false;
        continue;
      case '\r':
      case '\n':
        if (bufp != 1) {
          buf[0] = bufp - 1;
          bufp = 1;
          parseSerialWrite();
          updateLCD();
        }
        return;
      case '@':
        bufp = 1;
        session = 0xFF;
        SERIAL.println(F("\ncamera power on"));
        __emptyInputBuffer();
        startupSession = 0; // emit power on sequence
        disp_state = MENU_MAIN;
        setting.p.mode = setting.p.default_app_mode;
        updateLCD();
        return; 
      default:
        if (bufp >= 3 && isxdigit(c)) {
          c -= '0';
          if (c >= 10) {
            c = (c & 0x0f) + 9;
          }    
        }
        if (bufp < 4) {
          shiftable = true;
          buf[bufp++] = c;
        } else {
          if (shiftable) {
            buf[bufp-1] = (buf[bufp-1] << 4) + c;
          } else {
            buf[bufp++] = c;
          }
          shiftable = !shiftable;      
        }
        break;
    }
  }
}

