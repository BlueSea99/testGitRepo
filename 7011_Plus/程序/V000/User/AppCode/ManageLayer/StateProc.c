#include "StateProc.h"
#include "Typedef.h"
#include "SysDataDef.h"
#include "wifi.h"
#include "LedProc.h"
#include "Gpio.h"

void ManageAdjust(void)
{
	switch(Face.State)
    {
        case STEP_LOWPOWER:
            
            if(SwitchF || !NetSuccessF)
            {
                Face.CtrlTim = 0;
                Face.State = STEP_IDLE;
                SetDispVccP;                
            }
            break;
            
        case STEP_IDLE:
            
            Dig[0] = 20;                // 显示 “0”

            if(!NetSuccessF)            // 如果配网不成功，3s后进入配网状态
            {
                if(++Face.CtrlTim > 3000)
                {   
                    SetDispVccP;
                    ClrDimmerKeyF;
                    Face.CtrlTim = 0;
                    Face.State = STEP_NETWORK;
                }
            }
            else
            {
                if(++Face.CtrlTim > 3000)
                {
                    ClrDispVccP; 
                    Face.State = STEP_LOWPOWER; 
                }
            }
                
            if(SwitchF)
            {
                Face.CtrlTim = 0;
                Face.State = STEP_OPENDRELAY;
                SetDispVccP;
                
                if(NetSuccessF)
                {
                    SetDpBrightF;   // 上报Dp值
                }
                
            }
            break;
        
        case STEP_OPENDRELAY:
            OpenSwitchP;
            Dig[0] = 20;                      // 显示 “0”
        
            Face.CtrlTim++;

            if(Face.CtrlTim == 500)           // 延时，防止继电器打开时灯闪烁
            {
                SetPwmTriggerF;
            }
            else if(Face.CtrlTim == 700)     // 启动时，稳住下最小暗度
            {
                Face.CtrlTim = 0;
                Dimmer.TmepValue = LightValTab[2]; //控制启动时开始电压
                Face.State = STEP_ADDBRIGHT;
            }
            break;
            
        case STEP_ADDBRIGHT:
            if(Dimmer.TmepValue < Dimmer.FaceValue)
            {
                if(Dimmer.TmepValue > LightValTab[8])
                {
                    if(++Face.CtrlTim > 20)
                    {
                        Face.CtrlTim = 0;
                        Dimmer.TmepValue ++;
                        Dig[0] = LedShowTrans(Dimmer.TmepValue);
                    }
                }
                else 
                {
                    if(++Face.CtrlTim > 25)     // 控制启动灯亮度增加速率
                    {
                        Face.CtrlTim = 0;
                        Dimmer.TmepValue ++;
                        Dig[0] = LedShowTrans(Dimmer.TmepValue);
                    }
                }
            }
            else
            {
                Face.CtrlTim = 0;
                Face.State = STEP_DIMMER;
                ClrStartUpF;                // 清除启动标志
            }
            break;
        
        case STEP_DIMMER:
            
            Dig[0] = LedShowTrans(Dimmer.FaceValue);
            
            if(Dimmer.TmepValue > Dimmer.FaceValue)
            {
                if(++Face.CtrlTim > 25)     // 控制灯熄灭的速率
                {
                    Face.CtrlTim = 0;
                    Dimmer.TmepValue--;
                }
            }
            else if(Dimmer.TmepValue < Dimmer.FaceValue)
            {
                if(++Face.CtrlTim > 25)     // 控制灯熄灭的速率
                {
                    Face.CtrlTim = 0;
                    Dimmer.TmepValue++;
                }
            }
            
            if(!NetSuccessF)    // 如果配网不成功，3s进入配网状态
            {
                Face.CtrlTim++;
                if(Face.CtrlTim > 3000)
                {
                    Face.CtrlTim = 0;
                    ClrDimmerKeyF;
                    
                    Face.State = STEP_NETWORK;
                }
            }
            
            if(!SwitchF)
            {
                Face.CtrlTim = 0;
                Face.State = STEP_FALLBRIGHT;
            }
            break;
        
        case STEP_NETWORK:
            SetAllFlashF;
        
            if(wifi_work_state == SMART_CONFIG_STATE)    // 快闪 250ms
            {
                Dig[0] = 8;         // 8
                LED_SetFlash(1);    // 快闪

            }
            else if(wifi_work_state == AP_STATE)         // 慢闪 1500ms
            {
                Dig[0] = 11;        // A
                LED_SetFlash(0);    // 慢闪
            }
            else if(wifi_work_state == WIFI_NOT_CONNECTED)   // 慢闪 “-” 1500ms 
            {
                Dig[0] = 21;        // -
                LED_SetFlash(0);    // 慢闪
            }
            
            if(StartUpF)            // 配网状态进入启动状态
            {
                if(SwitchF)
                {
                    Face.State = STEP_OPENDRELAY;
                }
                else
                {
                    Face.State = STEP_FALLBRIGHT;
                }
                ClrAllFlashF;
                Face.CtrlTim = 0;
            }
            
            if(DimmerKeyF)          // 如果调光按键按下，回到调光状态
            {
                ClrAllFlashF;
                Face.CtrlTim = 0;
                Face.State = STEP_DIMMER; 
            }
            
            if(NetSuccessF)
            {
                ClrAllFlashF;
                Dig[0] = 17;        // 显示 ‘L’
                if(++Face.CtrlTim > 4000)
                {
                    Face.CtrlTim = 0;
                    Face.State = SwitchF ? STEP_DIMMER : STEP_IDLE; 
                }
            }
            break;

        case STEP_FALLBRIGHT:
            if(Dimmer.TmepValue > LightValTab[8])
            {
                if(++Face.CtrlTim > 5)     // 控制灯熄灭的速率
                {
                    Face.CtrlTim = 0;
                    
                    Dimmer.TmepValue --;
                    Dig[0] = LedShowTrans(Dimmer.TmepValue);
                }
            }
            else if(Dimmer.TmepValue > LightValTab[4])
            {
                if(++Face.CtrlTim > 20)     // 控制灯熄灭的速率
                {
                    Face.CtrlTim = 0;
                    
                    Dimmer.TmepValue --;
                    Dig[0] = LedShowTrans(Dimmer.TmepValue);
                }
            }
            else if(Dimmer.TmepValue > LightValTab[2])
            {
                if(++Face.CtrlTim > 30)     // 控制灯熄灭的速率
                {
                    Face.CtrlTim = 0;
                    
                    Dimmer.TmepValue --;
                    Dig[0] = LedShowTrans(Dimmer.TmepValue);
                }
            }
            else
            {
                if(++Face.CtrlTim > 200)        // 调到最暗时稳住
                {
                    ClrPwmF;                
                    ClrPwmTriggerF;
                    Face.CtrlTim = 0;
                    Face.State = STEP_CLOSERELAY;
                }
            }
            break;
            
        case STEP_CLOSERELAY:
            if(++Face.CtrlTim > 500)
            {
                Dig[0] = 20;
                CloseSwitchP;
                Face.CtrlTim = 0;
                Face.State = STEP_IDLE;
                ClrStartUpF;                
            }
            break;
            
        default:
            Face.CtrlTim = 0;
            Face.State = STEP_IDLE;
            break;
    }
}

void ManageNoAdjust(void)
{
	switch(Face.State)
    {
        case STEP_LOWPOWER:
            
            if(SwitchF || !NetSuccessF)
            {
                Face.CtrlTim = 0;
                Face.State = STEP_IDLE;
                SetDispVccP;                
            }
            break;
            
        case STEP_IDLE:
            
            Dig[0] = 20;                // 显示 “0”

            if(!NetSuccessF)            // 如果配网不成功，3s后进入配网状态
            {
                if(++Face.CtrlTim > 3000)
                {   
                    SetDispVccP;
                    ClrDimmerKeyF;
                    Face.CtrlTim = 0;
                    Face.State = STEP_NETWORK;
                }
            }
            else
            {
                if(++Face.CtrlTim > 3000)
                {
                    ClrDispVccP; 
                    Face.State = STEP_LOWPOWER; 
                }
            }
                
            if(SwitchF)
            {
                Face.CtrlTim = 0;
                Face.State = STEP_OPENDRELAY;
                SetDispVccP;
                
                Dimmer.TmepValue = LightValTab[9];
                
                if(NetSuccessF)
                {
                    SetDpBrightF;   // 上报Dp值
                }
                
            }
            break;
            
        case STEP_OPENDRELAY:
            OpenSwitchP;
            Dig[0] = 20;                      // 显示 “0”
        
            Face.CtrlTim++;

            if(Face.CtrlTim == 500)           // 延时，防止继电器打开时灯闪烁
            {
                SetPwmTriggerF;
                Dimmer.TmepValue = LightValTab[9]; //控制启动时开始电压
                Dimmer.FaceValue = LightValTab[9];
                Face.State = STEP_DIMMER;
            }
            break;
            
        case STEP_DIMMER:
            
            Dig[0] = LedShowTrans(Dimmer.FaceValue);
            
            if(!NetSuccessF)    // 如果配网不成功，3s进入配网状态
            {
                Face.CtrlTim++;
                if(Face.CtrlTim > 3000)
                {
                    Face.CtrlTim = 0;
                    ClrDimmerKeyF;
                    
                    Face.State = STEP_NETWORK;
                }
            }
            
            if(!SwitchF)
            {
                Face.CtrlTim = 0;
                Face.State = STEP_FALLBRIGHT;
            }
            break;
        
        case STEP_NETWORK:
            SetAllFlashF;
        
            if(wifi_work_state == SMART_CONFIG_STATE)    // 快闪 250ms
            {
                Dig[0] = 8;         // 8
                LED_SetFlash(1);    // 快闪

            }
            else if(wifi_work_state == AP_STATE)         // 慢闪 1500ms
            {
                Dig[0] = 11;        // A
                LED_SetFlash(0);    // 慢闪
            }
            else if(wifi_work_state == WIFI_NOT_CONNECTED)   // 慢闪 “-” 1500ms 
            {
                Dig[0] = 21;        // -
                LED_SetFlash(0);    // 慢闪
            }

            if(DimmerKeyF)          // 如果调光按键按下，回到调光状态
            {
                ClrAllFlashF;
                Face.CtrlTim = 0;
                Face.State = STEP_DIMMER; 
            }
            
            if(NetSuccessF)
            {
                ClrAllFlashF;
                Dig[0] = 17;        // 显示 ‘L’
                if(++Face.CtrlTim > 4000)
                {
                    Face.CtrlTim = 0;
                    Face.State = SwitchF ? STEP_DIMMER : STEP_IDLE; 
                }
            }
            break;
            
        case STEP_CLOSERELAY:
            if(++Face.CtrlTim > 500)
            {
                Dig[0] = 20;
                CloseSwitchP;
                Face.CtrlTim = 0;
                Face.State = STEP_IDLE;
                ClrStartUpF;                
            }
            break;
            
        default:
            Face.CtrlTim = 0;
            Face.State = STEP_IDLE;
            break;
    }   
}

void StateProc(void)
{
    if(AdjustLightF)
    {
       ManageAdjust(); 
    }
    else
    {
       ManageNoAdjust(); 
    }
}
