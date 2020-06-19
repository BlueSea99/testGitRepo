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
    CloseSwitchP;   // �رռ̵���
    ClrPwmF;        // �ر�Pwm��
    SetDispVccP;   // �������ʾ

}

void Init_Para(void)
{
    extern bit wifi_heart_close;
    
    Face.State = 0;
    Dig[0] = 20;        // �ϵ�Ĭ�ϡ�0��
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
    
    EA = 1;                 //�������ж�

//  mcu_reset_wifi();  // ��λwifi

    while(1)
    { 
        TimeEvent();
    }
}



