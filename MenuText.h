const char MODE_VIDEO = 0;
const char MODE_PHOTO = 1;
const char MODE_BURST = 2;
const char MODE_TIMELAPSE = 3;
const char MODE_PLAYBACK = 5;
const char MODE_SETTINGS = 7;
const char MODE_DUAL = 8;

const char GPCAMERA_GROUP_CAMERA_SETTINGS[] PROGMEM = { 1, 2, 3, 4, 6, 7, 8, 9, 0 };
const char GPCAMERA_GROUP_CAPTURE_SETTINGS[] PROGMEM = { 10, 11, 14, 15, 16, 17, 18, 19, 0 };
const char GPCAMERA_GROUP_SETUP[] PROGMEM = { 20, 22, 23, 24, 25, 26, 0 };

// VV
const char title_txt_1[] PROGMEM = "\x01""Video Resolution";
const char option_txt_1_0[] PROGMEM = "\x08""4K 17:9";
const char option_txt_1_1[] PROGMEM = "\x06""4K";
const char option_txt_1_2[] PROGMEM = "\x07""2.7K 17:9";
const char option_txt_1_3[] PROGMEM = "\x05""2.7K";
const char option_txt_1_4[] PROGMEM = "\x04""1440";
const char option_txt_1_5[] PROGMEM = "\x09""1080 SuperView";
const char option_txt_1_6[] PROGMEM = "\x03""1080";
const char option_txt_1_7[] PROGMEM = "\x02""960";
const char option_txt_1_8[] PROGMEM = "\x0a""720 SuperView";
const char option_txt_1_9[] PROGMEM = "\x01""720";
const char option_txt_1_10[] PROGMEM = "\x00""WVGA";
const char* const option_txt_1[] PROGMEM = {
option_txt_1_0, option_txt_1_1, option_txt_1_2, option_txt_1_3, option_txt_1_4, option_txt_1_5, option_txt_1_6, option_txt_1_7, option_txt_1_8, option_txt_1_9, option_txt_1_10, NULL
};

// FS
const char title_txt_2[] PROGMEM = "\x02""Video FPS";
const char option_txt_2_0[] PROGMEM = "\x0a""240";
const char option_txt_2_1[] PROGMEM = "\x09""120";
const char option_txt_2_2[] PROGMEM = "\x08""100";
const char option_txt_2_3[] PROGMEM = "\x07""60";
const char option_txt_2_4[] PROGMEM = "\x06""50";
const char option_txt_2_5[] PROGMEM = "\x05""48";
const char option_txt_2_6[] PROGMEM = "\x04""30";
const char option_txt_2_7[] PROGMEM = "\x03""25";
const char option_txt_2_8[] PROGMEM = "\x02""24";
const char option_txt_2_9[] PROGMEM = "\x01""15";
const char option_txt_2_10[] PROGMEM = "\x0b""12.5";
const char option_txt_2_11[] PROGMEM = "\x00""12";
const char* const option_txt_2[] PROGMEM = {
option_txt_2_0, option_txt_2_1, option_txt_2_2, option_txt_2_3, option_txt_2_4, option_txt_2_5, option_txt_2_6, option_txt_2_7, option_txt_2_8, option_txt_2_9, option_txt_2_10, option_txt_2_11, NULL
};

// FV
const char title_txt_3[] PROGMEM = "\x03""Video FOV";
const char option_txt_3_0[] PROGMEM = "\x00""Ultra Wide";
const char option_txt_3_1[] PROGMEM = "\x01""Medium";
const char option_txt_3_2[] PROGMEM = "\x02""Narrow";
const char* const option_txt_3[] PROGMEM = {
option_txt_3_0, option_txt_3_1, option_txt_3_2, NULL
};

// PR
const char title_txt_4[] PROGMEM = "\x04""Photo Resolution";
const char option_txt_4_0[] PROGMEM = "\x05""12MP Wide";
const char option_txt_4_1[] PROGMEM = "\x04""7MP Wide";
const char option_txt_4_2[] PROGMEM = "\x06""7MP Med";
const char option_txt_4_3[] PROGMEM = "\x03""5MP Med";
const char* const option_txt_4[] PROGMEM = {
option_txt_4_0, option_txt_4_1, option_txt_4_2, option_txt_4_3, NULL
};

// CS (not supported)
const char title_txt_5[] PROGMEM = "\x05""Continuous Photo";
const char option_txt_5_0[] PROGMEM = "\x00""Single";
const char option_txt_5_1[] PROGMEM = "\x03""3 FPS";
const char option_txt_5_2[] PROGMEM = "\x05""5 FPS";
const char option_txt_5_3[] PROGMEM = "\x0a""10 FPS";
const char* const option_txt_5[] PROGMEM = {
option_txt_5_0, option_txt_5_1, option_txt_5_2, option_txt_5_3, NULL
};

// BU
const char title_txt_6[] PROGMEM = "\x06""Burst Photo";
const char option_txt_6_0[] PROGMEM = "\x00""3 P / 1 Sec";
const char option_txt_6_1[] PROGMEM = "\x01""5 P / 1 Sec";
const char option_txt_6_2[] PROGMEM = "\x02""10 P / 1 Sec";
const char option_txt_6_3[] PROGMEM = "\x03""10 P / 2 Sec";
const char option_txt_6_4[] PROGMEM = "\x04""30 P / 1 Sec";
const char option_txt_6_5[] PROGMEM = "\x05""30 P / 2 Sec";
const char option_txt_6_6[] PROGMEM = "\x06""30 P / 3 Sec";
const char* const option_txt_6[] PROGMEM = {
option_txt_6_0, option_txt_6_1, option_txt_6_2, option_txt_6_3, option_txt_6_4, option_txt_6_5, option_txt_6_6, NULL
};

// TI
const char title_txt_7[] PROGMEM = "\x07""Time Lapse";
//const char option_txt_7_0[] PROGMEM = "\x00""1 P / 0.5 Sec";
//const char option_txt_7_1[] PROGMEM = "\x01""1 P / 1 Sec";
const char option_txt_7_2[] PROGMEM = "\x02""1 P / 2 Sec";
const char option_txt_7_3[] PROGMEM = "\x05""1 P / 5 Sec";
const char option_txt_7_4[] PROGMEM = "\x0a""1 P / 10 Sec";
const char option_txt_7_5[] PROGMEM = "\x1e""1 P / 30 Sec";
const char option_txt_7_6[] PROGMEM = "\x3c""1 P / 60 Sec";
const char* const option_txt_7[] PROGMEM = {
/* option_txt_7_0, option_txt_7_1, */ option_txt_7_2, option_txt_7_3, option_txt_7_4, option_txt_7_5, option_txt_7_6, NULL
};

const char title_txt_8[] PROGMEM = "\x08""Capture Settings";
const char* const option_txt_8[] PROGMEM = {
NULL
};

const char title_txt_9[] PROGMEM = "\x09""Set Up";
const char* const option_txt_9[] PROGMEM = {
NULL
};

// UP
const char title_txt_10[] PROGMEM = "\x0a""Upside Down";
const char option_txt_10_0[] PROGMEM = "\x00""ON";
const char option_txt_10_1[] PROGMEM = "\x01""OFF";
const char* const option_txt_10[] PROGMEM = {
option_txt_10_0, option_txt_10_1, NULL
};

// EX
const char title_txt_11[] PROGMEM = "\x0b""Spot Meter";
const char option_txt_11_0[] PROGMEM = "\x01""ON";
const char option_txt_11_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_11[] PROGMEM = {
option_txt_11_0, option_txt_11_1, NULL
};

// PN (not supported)
const char title_txt_12[] PROGMEM = "\x0c""Video + Photo";
const char option_txt_12_0[] PROGMEM = "\x00""OFF";
const char option_txt_12_1[] PROGMEM = "\x01""5 Seconds";
const char option_txt_12_2[] PROGMEM = "\x02""10 Seconds";
const char option_txt_12_3[] PROGMEM = "\x03""30 Seconds";
const char option_txt_12_4[] PROGMEM = "\x04""60 Seconds";
const char* const option_txt_12[] PROGMEM = {
option_txt_12_0, option_txt_12_1, option_txt_12_2, option_txt_12_3, option_txt_12_4, NULL
};

// LO (not supported)
const char title_txt_13[] PROGMEM = "\x0d""Looping";
const char option_txt_13_0[] PROGMEM = "\x00""OFF";
const char option_txt_13_1[] PROGMEM = "\x05""Max";
const char option_txt_13_2[] PROGMEM = "\x01""5 Minutes";
const char option_txt_13_3[] PROGMEM = "\x02""20 Minutes";
const char option_txt_13_4[] PROGMEM = "\x03""60 Minutes";
const char option_txt_13_5[] PROGMEM = "\x04""120 Minutes";
const char* const option_txt_13[] PROGMEM = {
option_txt_13_0, option_txt_13_1, option_txt_13_2, option_txt_13_3, option_txt_13_4, option_txt_13_5, NULL
};

// PT
const char title_txt_14[] PROGMEM = "\x0e""Protune";
const char option_txt_14_0[] PROGMEM = "\x01""ON";
const char option_txt_14_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_14[] PROGMEM = {
option_txt_14_0, option_txt_14_1, NULL
};

// WB
const char title_txt_15[] PROGMEM = "\x0f""White Balance";
const char option_txt_15_0[] PROGMEM = "\x00""Auto";
const char option_txt_15_1[] PROGMEM = "\x01""3000K";
const char option_txt_15_2[] PROGMEM = "\x02""5500K";
const char option_txt_15_3[] PROGMEM = "\x03""6500K";
const char option_txt_15_4[] PROGMEM = "\x04""Cam RAW";
const char* const option_txt_15[] PROGMEM = {
option_txt_15_0, option_txt_15_1, option_txt_15_2, option_txt_15_3, option_txt_15_4, NULL
};

// CO
const char title_txt_16[] PROGMEM = "\x10""Color";
const char option_txt_16_0[] PROGMEM = "\x00""GoPro Color";
const char option_txt_16_1[] PROGMEM = "\x01""Flat";
const char* const option_txt_16[] PROGMEM = {
option_txt_16_0, option_txt_16_1, NULL
};

// GA
const char title_txt_17[] PROGMEM = "\x11""ISO Limit";
const char option_txt_17_0[] PROGMEM = "\x00""6400";
const char option_txt_17_1[] PROGMEM = "\x01""1600";
const char option_txt_17_2[] PROGMEM = "\x02""400";
const char* const option_txt_17[] PROGMEM = {
option_txt_17_0, option_txt_17_1, option_txt_17_2, NULL
};

// SP
const char title_txt_18[] PROGMEM = "\x12""Sharpness";
const char option_txt_18_0[] PROGMEM = "\x00""High";
const char option_txt_18_1[] PROGMEM = "\x01""Medium";
const char option_txt_18_2[] PROGMEM = "\x02""Low";
const char* const option_txt_18[] PROGMEM = {
option_txt_18_0, option_txt_18_1, option_txt_18_2, NULL
};

// EV
const char title_txt_19[] PROGMEM = "\x13""EV Comp";
const char option_txt_19_0[] PROGMEM = "\x06""-2.0";
const char option_txt_19_1[] PROGMEM = "\x07""-1.5";
const char option_txt_19_2[] PROGMEM = "\x08""-1.0";
const char option_txt_19_3[] PROGMEM = "\x09""-0.5";
const char option_txt_19_4[] PROGMEM = "\x0a""0.0";
const char option_txt_19_5[] PROGMEM = "\x0b""0.5";
const char option_txt_19_6[] PROGMEM = "\x0c""1.0";
const char option_txt_19_7[] PROGMEM = "\x0d""1.5";
const char option_txt_19_8[] PROGMEM = "\x0e""2.0";
const char* const option_txt_19[] PROGMEM = {
option_txt_19_0, option_txt_19_1, option_txt_19_2, option_txt_19_3, option_txt_19_4, option_txt_19_5, option_txt_19_6, option_txt_19_7, option_txt_19_8, NULL
};

// DM
const char title_txt_20[] PROGMEM = "\x14""Default Mode";
const char option_txt_20_0[] PROGMEM = "\x00""Video";
const char option_txt_20_1[] PROGMEM = "\x01""Photo";
const char option_txt_20_2[] PROGMEM = "\x02""Burst Photo";
const char option_txt_20_3[] PROGMEM = "\x03""Time Lapse";
//const char option_txt_20_4[] PROGMEM = "\x08""Dual";
const char* const option_txt_20[] PROGMEM = {
option_txt_20_0, option_txt_20_1, option_txt_20_2, option_txt_20_3, /* option_txt_20_4, */ NULL
};

// (no I2C command. Wi-Fi command OB)
const char title_txt_21[] PROGMEM = "\x15""One Button";
const char option_txt_21_0[] PROGMEM = "\x01""ON";
const char option_txt_21_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_21[] PROGMEM = {
option_txt_21_0, option_txt_21_1, NULL
};

// VM
const char title_txt_22[] PROGMEM = "\x16""Video Format";
const char option_txt_22_0[] PROGMEM = "\x00""NTSC";
const char option_txt_22_1[] PROGMEM = "\x01""PAL";
const char* const option_txt_22[] PROGMEM = {
option_txt_22_0, option_txt_22_1, NULL
};

// DS
const char title_txt_23[] PROGMEM = "\x17""OSD";
const char option_txt_23_0[] PROGMEM = "\x01""ON";
const char option_txt_23_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_23[] PROGMEM = {
option_txt_23_0, option_txt_23_1, NULL
};

// LB
const char title_txt_24[] PROGMEM = "\x18""LED Blink";
const char option_txt_24_0[] PROGMEM = "\x00""OFF";
const char option_txt_24_1[] PROGMEM = "\x01""2";
const char option_txt_24_2[] PROGMEM = "\x02""4";
const char* const option_txt_24[] PROGMEM = {
option_txt_24_0, option_txt_24_1, option_txt_24_2, NULL
};

// BS
const char title_txt_25[] PROGMEM = "\x19""Beeps";
const char option_txt_25_0[] PROGMEM = "\x00""OFF";
const char option_txt_25_1[] PROGMEM = "\x01""70%";
const char option_txt_25_2[] PROGMEM = "\x02""100%";
const char* const option_txt_25[] PROGMEM = {
option_txt_25_0, option_txt_25_1, option_txt_25_2, NULL
};

// AO
const char title_txt_26[] PROGMEM = "\x1a""Auto Off";
const char option_txt_26_0[] PROGMEM = "\x00""NEVER";
const char option_txt_26_1[] PROGMEM = "\x01""1 MIN";
const char option_txt_26_2[] PROGMEM = "\x02""2 MIN";
const char option_txt_26_3[] PROGMEM = "\x03""5 MIN";
const char* const option_txt_26[] PROGMEM = {
option_txt_26_0, option_txt_26_1, option_txt_26_2, option_txt_26_3, NULL
};

struct Widget {
const char * title_txt;
const char * const *option_txt;
} Widget;

const struct Widget widgets[] PROGMEM = {
{ NULL, NULL },
{ title_txt_1, option_txt_1 },
{ title_txt_2, option_txt_2 },
{ title_txt_3, option_txt_3 },
{ title_txt_4, option_txt_4 },
{ title_txt_5, option_txt_5 },
{ title_txt_6, option_txt_6 },
{ title_txt_7, option_txt_7 },
{ title_txt_8, option_txt_8 },
{ title_txt_9, option_txt_9 },
{ title_txt_10, option_txt_10 },
{ title_txt_11, option_txt_11 },
{ title_txt_12, option_txt_12 },
{ title_txt_13, option_txt_13 },
{ title_txt_14, option_txt_14 },
{ title_txt_15, option_txt_15 },
{ title_txt_16, option_txt_16 },
{ title_txt_17, option_txt_17 },
{ title_txt_18, option_txt_18 },
{ title_txt_19, option_txt_19 },
{ title_txt_20, option_txt_20 },
{ title_txt_21, option_txt_21 },
{ title_txt_22, option_txt_22 },
{ title_txt_23, option_txt_23 },
{ title_txt_24, option_txt_24 },
{ title_txt_25, option_txt_25 },
{ title_txt_26, option_txt_26 },
};

#define SETUP_LEN 27
typedef union Setting {
  byte b[SETUP_LEN];
  struct {
    byte mode;
    byte video_resolution;
    byte video_fps;
    byte video_fov;
    byte photo_resolution;
    byte continuous_rate;
    byte burst_rate;
    byte timelapse_rate;
    byte reserved[2];
    byte orientation;
    byte spot_meter;
    byte piv;
    byte looping;
    byte protune;
    byte protune_white_balance;
    byte protune_color;
    byte protune_iso;
    byte protune_sharpness;
    byte protune_ev;  
    byte default_app_mode;
    byte quick_capture;
    byte video_format;
    byte osd;
    byte led;
    byte beep_volume;
    byte auto_power_down;
  } p;
} Setting;

Setting setting =
{
         // id path
  0,     //  0 
  4,     //  1 video_resolution
  5,     //  2 video_fps
  0,     //  3 video_fov
  5,     //  4 photo_resolution
  0,     //  5 continuous_rate
  4,     //  6 burst_rate
  2,     //  7 timelapse_rate
  0,     //  8
  0,     //  9
  1,     // 10 orientation
  0,     // 11 spot_meter
  0,     // 12 piv
  0,     // 13 looping
  1,     // 14 protune
  0,     // 15 protune_white_balance
  0,     // 16 protune_color
  0,     // 17 protune_iso
  0,     // 18 protune_sharpness
 10,     // 19 protune_ev  
  0,     // 20 default_app_mode
  0,     // 21 quick_capture
  0,     // 22 video_format
  1,     // 23 osd
  2,     // 24 led
  2,     // 25 beep_volume
  0,     // 26 auto_power_down
};

boolean blacklist(byte id, byte v)
{
if(id==1&&setting.b[14]==1)switch(v){case 0:return true;}
if(id==2&&setting.b[1]==8&&setting.b[22]==0)switch(v){case 10:case 9:case 8:case 7:case 6:case 5:case 4:case 3:case 2:case 1:case 11:return true;}
if(id==2&&setting.b[1]==6&&setting.b[22]==0)switch(v){case 10:case 9:case 8:case 7:case 6:case 5:case 4:case 3:case 2:case 11:case 0:return true;}
if(id==2&&setting.b[1]==7&&setting.b[22]==0)switch(v){case 10:case 9:case 8:case 7:case 6:case 5:case 4:case 3:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==5&&setting.b[22]==0)switch(v){case 10:case 9:case 8:case 7:case 6:case 5:case 3:case 2:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==4&&setting.b[22]==0)switch(v){case 10:case 9:case 8:case 7:case 6:case 3:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==9&&setting.b[22]==0)switch(v){case 10:case 9:case 8:case 6:case 3:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==3&&setting.b[22]==0)switch(v){case 10:case 9:case 8:case 6:case 3:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==2&&setting.b[22]==0)switch(v){case 10:case 9:case 6:case 4:case 3:case 2:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==2&&setting.b[22]==0&&setting.b[14]==1)switch(v){case 5:return true;}
if(id==2&&setting.b[1]==10&&setting.b[22]==0)switch(v){case 10:case 9:case 6:case 4:case 3:case 2:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==10&&setting.b[22]==0&&setting.b[14]==1)switch(v){case 5:return true;}
if(id==2&&setting.b[1]==1&&setting.b[22]==0)switch(v){case 10:case 8:case 6:case 5:case 4:case 3:case 2:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==0&&setting.b[22]==0)switch(v){case 9:case 8:case 7:case 6:case 5:case 4:case 3:case 2:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==8&&setting.b[22]==1)switch(v){case 10:case 9:case 8:case 7:case 6:case 5:case 4:case 3:case 2:case 1:case 11:return true;}
if(id==2&&setting.b[1]==6&&setting.b[22]==1)switch(v){case 10:case 9:case 8:case 7:case 6:case 5:case 4:case 3:case 2:case 1:case 0:return true;}
if(id==2&&setting.b[1]==7&&setting.b[22]==1)switch(v){case 10:case 9:case 8:case 7:case 6:case 5:case 4:case 3:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==5&&setting.b[22]==1)switch(v){case 10:case 9:case 8:case 7:case 6:case 5:case 4:case 2:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==4&&setting.b[22]==1)switch(v){case 10:case 9:case 8:case 7:case 6:case 4:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==9&&setting.b[22]==1)switch(v){case 10:case 9:case 8:case 7:case 4:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==3&&setting.b[22]==1)switch(v){case 10:case 9:case 8:case 7:case 4:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==2&&setting.b[22]==1)switch(v){case 10:case 9:case 7:case 4:case 3:case 2:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==2&&setting.b[22]==1&&setting.b[14]==1)switch(v){case 5:return true;}
if(id==2&&setting.b[1]==10&&setting.b[22]==1)switch(v){case 10:case 9:case 7:case 4:case 3:case 2:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==10&&setting.b[22]==1&&setting.b[14]==1)switch(v){case 5:return true;}
if(id==2&&setting.b[1]==1&&setting.b[22]==1)switch(v){case 10:case 9:case 7:case 5:case 4:case 3:case 2:case 1:case 11:case 0:return true;}
if(id==2&&setting.b[1]==0&&setting.b[22]==1)switch(v){case 9:case 8:case 7:case 6:case 5:case 4:case 3:case 2:case 1:case 11:case 0:return true;}
if(id==3&&setting.b[1]==8)switch(v){case 1:case 2:return true;}
if(id==3&&setting.b[1]==6)switch(v){case 1:case 2:return true;}
if(id==3&&setting.b[1]==7)switch(v){case 2:return true;}
if(id==3&&setting.b[1]==5)switch(v){case 2:return true;}
if(id==3&&setting.b[1]==4)switch(v){case 1:case 2:return true;}
if(id==3&&setting.b[1]==9)switch(v){case 1:case 2:return true;}
if(id==3&&setting.b[1]==2)switch(v){case 1:case 2:return true;}
if(id==3&&setting.b[1]==10)switch(v){case 1:case 2:return true;}
if(id==3&&setting.b[1]==1&&setting.b[2]==9)switch(v){case 1:return true;}
if(id==3&&setting.b[1]==1&&setting.b[2]==8)switch(v){case 1:return true;}
if(id==3&&setting.b[1]==0)switch(v){case 1:case 2:return true;}
if(id==14&&setting.b[1]==2&&setting.b[2]==5)switch(v){case 1:return true;}
if(id==14&&setting.b[1]==10&&setting.b[2]==5)switch(v){case 1:return true;}
if(id==14&&setting.b[1]==0)switch(v){case 1:return true;}
if(id==15&&setting.b[14]==0)switch(v){case 0:case 1:case 2:case 3:case 4:return true;}
if(id==16&&setting.b[14]==0)switch(v){case 0:case 1:return true;}
if(id==17&&setting.b[14]==0)switch(v){case 0:case 1:case 2:return true;}
if(id==18&&setting.b[14]==0)switch(v){case 0:case 1:case 2:return true;}
if(id==19&&setting.b[14]==0)switch(v){case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:return true;}
return false;
}
