#include "SysDataDef.h"
#include "TypeDef.h"
#include "TaskProc.h"
#include "Gpio.h"

UI16 SysPara = 0;  // STC单片机不初始化为0，可能不为0
UI08 Dig[1];
UI08 Fls[1];
UI08 DigBuf[1];
Face_Def Face;

UI08 ShowValTab[] = {
    25,     // 0 1
    50,     // 1 2
    75,     // 2 3
    100,    // 3 4
    125,    // 4 5
    150,    // 5 6
    175,    // 6 7
    200,    // 7 8
    225,    // 8 9
    250,    // 9 H
};

UI08 LightValTab[] = {
    20,     // 0 1
    27,     // 1 2
    37,     // 2 3
    50,     // 3 4
    65,     // 4 5
    83,     // 5 6
    103,    // 6 7
    120,    // 7 8
    138,    // 8 9
    250,    // 9 H
};

#define __STEP  (Dimmer.LedMax - Dimmer.LedMin) / 10


/*
typedef struct
{
    UI08 Step;
    UI16 LedMin;
    UI16 LedMax;
    UI16 IncMin;
    UI16 IncMax;

    UI16 TmepValue;
    UI16 FaceValue;
    UI16 Power;
    UI16 LeftMove;
    UI16 RightMove;
} Dimmer_Def;
*/


// 500对应右移1ms
Dimmer_Def Dimmer = {
    25,
    250,   // 右移0.5ms
    4000,  // 右移8.0ms
    80,
    250,
    
    0,
    250,    // 默认亮度
};
