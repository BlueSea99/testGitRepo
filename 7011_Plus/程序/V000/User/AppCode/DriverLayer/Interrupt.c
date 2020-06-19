#include "Interrupt.h"
#include "TypeDef.h"
#include "Gpio.h"
#include "SysDataDef.h"


void Init_Int0(void)
{
	IE0  = 0;   //��INT0�ж������־λ��"0"
	IT0 = 0;    //ѡ��INT0Ϊ�������½��ش�����ʽ
    EX0 = 1;    //ʹ��INT0�ж�����λ
//	EA = 1; //�������ж�
}

extern UI16 PwmValue;

/**************************************
�����������ⲿ�жϷ������
��ڲ�������
����ֵ����
***************************************/
void INT0 (void) interrupt INT0_VECTOR               
{
    if(SYNCP)
    {
        ClrPwmF;
        
        TL1 = (65535 - PwmValue) & 0XFF;    //���ö�ʱ��ֵ
        TH1 = (65535 - PwmValue) >> 8;      //���ö�ʱ��ֵ

        TR1 = 1;		                    //��ʱ��0��ʼ��ʱ
    }
}
