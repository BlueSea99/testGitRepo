/*****************************Copyright (c)************************************
**
**------------------------------------------------------------------------------
*******************************************************************************/
/*-------------------------------    -------------------------------------*/

#include "TaskProc.h"
#include "Gpio.h"
#include "Timer.h"
#include "Rcc.h"
#include "SysDataDef.h"
#include "Usart.h"
#include "Panel.h"
#include "wifi.h"


void Init_Device(void)
{
    CloseSwitchP;   // 关闭继电器
    ClrPwmF;        // 关闭Pwm波
    SetDispVccP;   // 数码管显示

}

void Init_Para(void)
{
    extern bit wifi_heart_close;
    
    Face.State = 0;
    Dig[0] = 20;        // 上电默认“0”
    wifi_heart_close = ENABLE;
}

void main(void)
{
    Init_Rcc();
    Init_GPIO();
    Init_Device();
    Init_PanelFlash();
    Init_Para();
    Uart2Init();
    Init_Int0();
    Init_Timer0();
    Init_Timer1();
    wifi_protocol_init();
    
    EA = 1;                 //允许总中断

//  mcu_reset_wifi();  // 复位wifi

    while(1)
    { 
        TimeEvent();
    }
}



