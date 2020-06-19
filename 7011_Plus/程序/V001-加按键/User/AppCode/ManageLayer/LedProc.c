#include "LedProc.h"
#include "TypeDef.h"
#include "SysDataDef.h"

LED_DEF Led;
UI16 LedFlashTim = 150;

//����
UI08 code LedCodeTab[] = { 
0x00,		// 0 ��
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
** ��������: HC595SendData
** ��������: ��SPI���߷�������
*********************************************************************************************************/
void HC595SendData(u8 SendVal)
{  
	u8 i;
	
	for(i=0;i<8;i++) 
	{
		if((SendVal<<i) & (0x80)) 
		{
			MOSIO = 1; //set dataline high  0X80  ���λ��SendVal���Ƶ����λ �����߼�����
		}
		else
		{
			MOSIO = 0;	// ���Ϊ�� MOSIO = 1  
		}
		
		S_CLK=0;
		NOP2();
		S_CLK=1;	
	}
   
		R_CK=0; //set dataline low
		NOP2();
		R_CK=1; //Ƭѡ
}
/********************************************************
������Init_Panel()
���ܣ���ʼ������
��ʱ��
���룺��
�������
���أ���
ʱ�䣺2019/8/5
********************************************************/
void Init_PanelFlash(void)
{
    Fls[0] = 0xFF;

    Led.FlashOn = 0xFF;
    Led.FlashOff = 0xFF;
}

/********************************************************
������LED_ReLedFlash()
���ܣ�LED��˸���º���
���ڣ�1ms
��ʱ��
���룺
�������
���أ���
ʱ�䣺2019/8/5
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
������LED_SetDigFlash()
���ܣ�����һ���������˸
���ڣ���
��ʱ��
���룺DigNum: λѡ��ַ(0 - 15)
      Mode����˸ģʽ (0 - 3)
�������
���أ���
ʱ�䣺2019/8/5
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
������LED_ClrFlash()
���ܣ����һ���������˸
���ڣ���
��ʱ��
���룺DigNum: λѡ��ַ(0 - 15)
�������
���أ���
ʱ�䣺2019/8/5
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
