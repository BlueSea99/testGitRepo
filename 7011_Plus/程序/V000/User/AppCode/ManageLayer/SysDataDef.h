#ifndef	__SYS_DATA_DEF_H
#define	__SYS_DATA_DEF_H

#include "TypeDef.h"
#include "Gpio.h"


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

extern Dimmer_Def Dimmer;


typedef enum
{
    STEP_IDLE = 0,
    STEP_LOWPOWER,
    STEP_OPENDRELAY,
    STEP_ADDBRIGHT,
    STEP_DIMMER,
    STEP_NETWORK,
    STEP_FALLBRIGHT,
    STEP_CLOSERELAY,
} WORK_STATE;

typedef struct
{
    WORK_STATE State;
    UI16 CtrlTim;
    
} Face_Def;

extern Face_Def Face;


extern UI16 SysPara;
#define SwitchF         (SysPara & Bit0)
#define SetSwitchF      SysPara |= Bit0
#define ClrSwitchF      SysPara &= CBit0

#define PwmF            (SysPara & Bit1)
#define SetPwmF         SysPara |= Bit1; PWMP = 0
#define ClrPwmF         SysPara &= CBit1; PWMP = 1

#define AllFlashF      (SysPara & Bit2)
#define SetAllFlashF    SysPara |= Bit2
#define ClrAllFlashF    SysPara &= CBit2;Fls[0] = 0xFF

#define FastFlashF      (SysPara & Bit3)
#define SetFastFlashF    SysPara |= Bit3
#define ClrFastFlashF    SysPara &= CBit3

#define SlowFlashF      (SysPara & Bit4)
#define SetSlowFlashF    SysPara |= Bit4
#define ClrSlowFlashF    SysPara &= CBit4

#define StartUpF        (SysPara & Bit5)   // 表示开关启动时或关闭时标志
#define SetStartUpF     SysPara |= Bit5
#define ClrStartUpF     SysPara &= CBit5

#define NetSuccessF     (SysPara & Bit6)   // 表示开关启动时或关闭时标志
#define SetNetSuccessF  SysPara |= Bit6
#define ClrNetSuccessF  SysPara &= CBit6

#define DimmerKeyF     (SysPara & Bit7)     // 表示调光按键按下标识标志
#define SetDimmerKeyF  SysPara |= Bit7
#define ClrDimmerKeyF  SysPara &= CBit7

#define DpSwitchF      (SysPara & Bit8)
#define SetDpSwitchF    SysPara |= Bit8
#define ClrDpSwitchF    SysPara &= CBit8

#define DpBrightF      (SysPara & Bit9)
#define SetDpBrightF    SysPara |= Bit9
#define ClrDpBrightF    SysPara &= CBit9

#define WifiTestF      (SysPara & Bit10)
#define SetWifiTestF    SysPara |= Bit10
#define ClrWifiTestF    SysPara &= CBit10

#define AdjustLightF    (SysPara & Bit11)
#define SetAdjustLightF SysPara |= Bit11
#define ClrAdjustLightF SysPara &= CBit11

#define FirstGearF      (SysPara & Bit12)
#define SetFirstGearF    SysPara |= Bit12
#define ClrFirstGearF    SysPara &= CBit12

#define SecondGearF      (SysPara & Bit12)
#define SetSecondGearF    SysPara |= Bit12
#define ClrSecondGearF    SysPara &= CBit12

#define ThirdGearF      (SysPara & Bit12)
#define SetThirdGearF    SysPara |= Bit12
#define ClrThirdGearF    SysPara &= CBit12

#define SetPwmTriggerF  TR1 = 1;EX0 = 1
#define ClrPwmTriggerF  TR1 = 0;EX0 = 0

#define SwitchP         RELAY
#define OpenSwitchP     RELAY = 1
#define CloseSwitchP    RELAY = 0

extern UI08 Dig[1];
extern UI08 Fls[1];
extern UI08 DigBuf[1];
extern UI08 LightValTab[];
extern UI08 ShowValTab[];
#endif
