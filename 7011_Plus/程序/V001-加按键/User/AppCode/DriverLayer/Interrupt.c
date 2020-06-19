#include "Interrupt.h"
#include "TypeDef.h"
#include "Gpio.h"
#include "SysDataDef.h"


void Init_Int0(void)
{
	IE0  = 0;   //将INT0中断请求标志位清"0"
	IT0 = 0;    //选择INT0为上升和下降沿触发方式
    EX0 = 1;    //使能INT0中断允许位
//	EA = 1; //允许总中断
}

extern UI16 PwmValue;

/**************************************
功能描述：外部中断服务程序
入口参数：无
返回值：无
***************************************/
void INT0 (void) interrupt INT0_VECTOR               
{
    if(SYNCP)
    {
        ClrPwmF;
        
        TL1 = (65535 - PwmValue) & 0XFF;    //设置定时初值
        TH1 = (65535 - PwmValue) >> 8;      //设置定时初值

        TR1 = 1;		                    //定时器0开始计时
    }
}
