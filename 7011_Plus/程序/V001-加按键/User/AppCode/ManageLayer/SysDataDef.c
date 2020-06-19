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

UI08 LightValTab[][10] = {
//   0   1   2   3   4   5   6    7    8    9
//   1   2   3   4   5   6   7    8    9    H
//       7   10  13  15  18  20   17   18   112  
    {20, 27, 37, 50, 65, 83, 103, 120, 138, 250},
    
//       6   8   10  12  14  16   17   18   112
    {37, 43, 51, 61, 73, 87, 103, 120, 138, 250},
    
//       5   7   9   11  13  13   17   18   112
    {50, 55, 62, 71, 82, 95, 107, 120, 138, 250}
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
    UI16 MinLightVal;
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
    0,    // 最小亮度值
};
