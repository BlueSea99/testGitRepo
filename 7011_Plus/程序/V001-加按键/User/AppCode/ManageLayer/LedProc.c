#include "LedProc.h"
#include "TypeDef.h"
#include "SysDataDef.h"

LED_DEF Led;
UI16 LedFlashTim = 150;

//共阴
UI08 code LedCodeTab[] = { 
0x00,		// 0 灭
0x28,		// 1  1
0xB6,		// 2  2
0xBA,		// 3  3
0x78,		// 4  4
0xDA,		// 5  5
0xDE,		// 6  6
0xA8,		// 7  7
0xFF,		// 8  8
0xFB,		// 9  9
0x7d,		// 10 H
0xFD,		// 11 A
0x5F,		// 12 b
0xC7,		// 13 c
0x3F,		// 14 d
0xD7,		// 15 E
0xD5,		// 16 F
0x46,		// 17 L
0xf5,		// 18 P
0x6f,		// 19 U
0xEF,		// 20 0
0x10 		// 21 -
};
		
		
/*********************************************************************************************************
** 函数名称: HC595SendData
** 功能描述: 向SPI总线发送数据
*********************************************************************************************************/
void HC595SendData(u8 SendVal)
{  
	u8 i;
	
	for(i=0;i<8;i++) 
	{
		if((SendVal<<i) & (0x80)) 
		{
			MOSIO = 1; //set dataline high  0X80  最高位与SendVal左移的最高位 进行逻辑运算
		}
		else
		{
			MOSIO = 0;	// 如果为真 MOSIO = 1  
		}
		
		S_CLK=0;
		NOP2();
		S_CLK=1;	
	}
   
		R_CK=0; //set dataline low
		NOP2();
		R_CK=1; //片选
}
/********************************************************
函数：Init_Panel()
功能：初始化数组
耗时：
输入：无
输出：无
返回：无
时间：2019/8/5
********************************************************/
void Init_PanelFlash(void)
{
    Fls[0] = 0xFF;

    Led.FlashOn = 0xFF;
    Led.FlashOff = 0xFF;
}

/********************************************************
函数：LED_ReLedFlash()
功能：LED闪烁更新函数
周期：1ms
耗时：
输入：
输出：无
返回：无
时间：2019/8/5
********************************************************/
void LED_ReLedFlash(void)
{
    if(!AllFlashF) return;
    
    if((Led.Flag) && (Led.Tim >= LedFlashTim))
    {

        Fls[0] |= Led.FlashOn;
        Led.Tim = 0;
        Led.Flag = 0;
    }
    else if((!(Led.Flag)) && (Led.Tim >= LedFlashTim))
    {
        Fls[0] &= Led.FlashOff;
        Led.Tim = 0;
        Led.Flag = 1;
    }
    
    Led.Tim++;
}

/********************************************************
函数：LED_SetDigFlash()
功能：设置一个数码管闪烁
周期：无
耗时：
输入：DigNum: 位选地址(0 - 15)
      Mode：闪烁模式 (0 - 3)
输出：无
返回：无
时间：2019/8/5
*******************************************************/
void LED_SetFlash(UI08 Mode)
{
    Led.FlashOn = 0xff; 
    Led.FlashOff = 0x00;
    
    if(Mode == 0)
        LedFlashTim = 150;
    else
        LedFlashTim = 25;    
}

/********************************************************
函数：LED_ClrFlash()
功能：清除一个数码管闪烁
周期：无
耗时：
输入：DigNum: 位选地址(0 - 15)
输出：无
返回：无
时间：2019/8/5
********************************************************/
void LED_ClrFlash(void)
{
    Led.FlashOn = 0xff; 
    Led.FlashOff = 0xff;
}

void LED_ShowProc(void)
{   
    DigBuf[0]  = Dig[0] & Fls[0];
        
    if(DigBuf[0] > 21)	DigBuf[0] = 21;
    
    HC595SendData(LedCodeTab[DigBuf[0]]);

}

UI08 LedShowTrans(UI16 Value)
{
    UI08 show_value = 0;
    
    if(Value < LightValTab[Dimmer.MinLightVal][0])
    {
        show_value = 0;
    }
    else if(Value >= LightValTab[Dimmer.MinLightVal][0] && Value < LightValTab[Dimmer.MinLightVal][1])
    {
        show_value = 1;
    }
    else if(Value >= LightValTab[Dimmer.MinLightVal][1] && Value < LightValTab[Dimmer.MinLightVal][2])
    {
        show_value = 2;
    }
    else if(Value >= LightValTab[Dimmer.MinLightVal][2] && Value < LightValTab[Dimmer.MinLightVal][3])
    {
        show_value = 3;
    }
    else if(Value >= LightValTab[Dimmer.MinLightVal][3] && Value < LightValTab[Dimmer.MinLightVal][4])
    {
        show_value = 4;
    } 
    else if(Value >= LightValTab[Dimmer.MinLightVal][4] && Value < LightValTab[Dimmer.MinLightVal][5])
    {
        show_value = 5;
    }
    else if(Value >= LightValTab[Dimmer.MinLightVal][5] && Value < LightValTab[Dimmer.MinLightVal][6])
    {
        show_value = 6;
    }
    else if(Value >= LightValTab[Dimmer.MinLightVal][6] && Value < LightValTab[Dimmer.MinLightVal][7])
    {
        show_value = 7;
    }
    else if(Value >= LightValTab[Dimmer.MinLightVal][7] && Value < LightValTab[Dimmer.MinLightVal][8])
    {
        show_value = 8;
    } 
    else if(Value >= LightValTab[Dimmer.MinLightVal][8] && (Value < LightValTab[Dimmer.MinLightVal][8] + 22))
    {
        show_value = 9;
    }
    else if((Value >= LightValTab[Dimmer.MinLightVal][8] + 22))
    {
        show_value = 10;
    }

    return show_value;
}
