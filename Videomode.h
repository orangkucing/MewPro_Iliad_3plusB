#define SYNC_TIME_HSYNC 0
#define SYNC_TIME_VSYNC 1
#define SYNC_TIME_STRETCH 2
#define FPS_TABLE_SIZE 12

#define SYNC_TIME_720_NARROW  11
#define SYNC_TIME_1080_NARROW 12
#define SYNC_TIME_PHOTO       13

#define _NA_ {0,0,0}

const unsigned int syncTime[][3] PROGMEM = {
// HSYNC duration unit is the number of clock cycles in 16MHz AVR, i.e. 1 clock = 62.5 ns
// VSYNC duration unit is the number of HSYNC pulses
// Note: the 2nd last HSYNC duration followed by VSYNC will be longer than others by STRETCH (clock)
//
// frame per second = 16000000 / (HSYNC * VSYNC + STRETCH)
//
// video modes WIDE and/or MEDIUM
// {HSYNC (clock), VSYNC (pulse), STRETCH (clock)}
// 12            15            24                25              30              48             50             60             100            120           240         12.5
// 0x00: WVGA                 848x480
_NA_,           _NA_,           _NA_,           _NA_,           _NA_,           _NA_,           _NA_,          _NA_,          _NA_,          _NA_,         {80,825,529},_NA_,
// 0x01: 720                 1280x720
_NA_,           _NA_,           _NA_,           _NA_,           _NA_,           _NA_,           {142,2250,500},{121,2200,11}, {200,800,0},   {173,770,508},_NA_,        _NA_,
// 0x02: 960                 1280x960
_NA_,           _NA_,           _NA_,           _NA_,           _NA_,           {86,3850,2567}, {89,3600,800}, {78,3422,28},  {142,1125,250},_NA_,         _NA_,        _NA_,
// 0x03: 1080                1920x1080
_NA_,           _NA_,           {146,4550,2921},{284,2250,1000},{235,2275,0},   {146,2275,1517},{142,2250,500},{121,2200,11}, _NA_,          _NA_,         _NA_,        _NA_,
// 0x04: 1440                1920x1440
_NA_,           _NA_,           {213,3121,1408},{160,4000,0},   {171,3120,1387},{86,3850,2567}, _NA_,          _NA_,          _NA_,          _NA_,         _NA_,        _NA_,
// 0x05: 2.7K                2704x1524
_NA_,           _NA_,           _NA_,           {284,2250,1000},{235,2275,0},   _NA_,           _NA_,          _NA_,          _NA_,          _NA_,         _NA_,        _NA_,
// 0x06: 4K                  3840x2160
_NA_,           {234,4550,2671},_NA_,           _NA_,           _NA_,           _NA_,           _NA_,          _NA_,          _NA_,          _NA_,         _NA_,        {284,4500,2000},
// 0x07: 2.7K 17:9           2704x1440
_NA_,           _NA_,           {293,2275,1405},_NA_,           _NA_,           _NA_,           _NA_,          _NA_,          _NA_,          _NA_,         _NA_,        _NA_,
// 0x08: 4K 17:9             4096x2160
{293,4550,2809},_NA_,           _NA_,           _NA_,           _NA_,           _NA_,           _NA_,          _NA_,          _NA_,          _NA_,         _NA_,        _NA_,
// 0x09: 1080 SuperView      1920x1080  
_NA_,           _NA_,           {213,3121,1408},{160,4000,0},  {171,3120,1387}, {86,3850,2567}, {89,3600,800}, {78,3422,28},  _NA_,          _NA_,         _NA_,        _NA_,
// 0x0a: 720 SuperView       1280x720
_NA_,           _NA_,           _NA_,           _NA_,          _NA_,            {86,3850,2567}, {89,3600,800}, {78,3422,28},  {142,1125,250},_NA_,         _NA_,        _NA_,
//
// video modes NARROW
// 11:   720 NARROW
_NA_,           _NA_,           _NA_,           _NA_,           _NA_,           _NA_,           {222,1440,320},{195,1365,314},{111,1440,640},{97,1365,601},_NA_,        _NA_,
// 12:   1080 NARROW
_NA_,           _NA_,           {391,1706,744},{444,1440,640},{391,1365,607},   {244,1365,615}, {222,1440,320},{195,1365,314},_NA_,          _NA_,         _NA_,        _NA_,
//
// 13:   photo mode
//              5MP M          7MP W           12MP W          7MP M
_NA_,_NA_,_NA_,{147,7272,107},{149,3119,1109},{149,3119,1109},{147,7272,107}
};
