void initWidget()
{
  setup_id = 1;
  settings_level = 0;
}

boolean nextWidget()
{
  char *display_hint, **addr, *txt;
  int i = 0;
  char val, id;
  switch (settings_level) {
    case 0:
      display_hint = GPCAMERA_GROUP_CAMERA_SETTINGS;
      break;
    case 1:
      display_hint = GPCAMERA_GROUP_CAPTURE_SETTINGS;
      break;
    case 2:
      display_hint = GPCAMERA_GROUP_SETUP;
      break;
  }
  do {
    id = (char)pgm_read_byte(display_hint + i);
    if (id == 0) {
      // current setup_id is not listed in display_hint
      // let's start over
      i = -1;
      break;
    }
    if (id == setup_id) {
      break;
    }
    i++;
  } while (1);
  do {
    i++;
    id = (char)pgm_read_byte(display_hint + i);
    if (id == 0) {
      // no next widget
      return false;
    }
    addr = (char **)pgm_read_word(&widgets[id].option_txt);
    if ((char *)pgm_read_word(addr) == NULL) {
      setup_id = id;
      return true; // goto submenu
    }
    while ((txt = (char *)pgm_read_word(addr++)) != NULL) {
      val = (char)pgm_read_byte(txt);
      if (!blacklist(id, val)) {
        if (blacklist(id, setting.b[id])) {
          // current value is blacklisted
          setting.b[id] = val;
          Broadcast_ChangeSetting(id);
        }
        setup_id = id;
        return true;
      }
    }
  } while (1);
}

const char __fps[] = {
  0, 11, 2, 4, 3, 5, 7, 6, 8, 8, 10, 1
};

void setNextValue()
{
  char **addr, *txt, c;
  addr = (char **)pgm_read_word(&widgets[setup_id].option_txt);
  do {
    txt = (char *)pgm_read_word(addr);
    if (txt == NULL)
      return;
    if ((char)pgm_read_byte(txt) == setting.b[setup_id]) {
      break;
    }
    addr++;
  } while (1);
  do {
    addr++;
    txt = (char *)pgm_read_word(addr);
    if (txt == NULL) {
      addr = (char **)pgm_read_word(&widgets[setup_id].option_txt);
      txt = (char *)pgm_read_word(addr);
      if (txt == NULL) return;
    }
    c = (char)pgm_read_byte(txt);
    if (c == setting.b[setup_id]) {
      return;
    }
    if (!blacklist(setup_id, c)) {
      setting.b[setup_id] = c;
      Broadcast_ChangeSetting(setup_id);
      if (&setting.b[setup_id] == &setting.p.video_format) {
        // a video mode can have different fps for NTSC and PAL 
        setting.p.video_fps = __fps[setting.p.video_fps];
        if (setting.p.video_resolution == 720 && setting.p.video_format == 0 && setting.p.video_fps == 8) {
          setting.p.video_fps = 9;
        }
        Broadcast_ChangeSetting(&setting.p.video_fps - setting.b); // send this for workaround Hero 3+B bug
      }
      return;
    }
  } while (1);
}
