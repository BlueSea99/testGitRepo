#include "Gpio.h"
#include "TypeDef.h"

//#define Main_Fosc_KHZ	(MAIN_Fosc / 1000)

#define	GPIO_PullUp		0	//����׼˫���
#define	GPIO_HighZ		1	//��������
#define	GPIO_OUT_OD		2	//��©���
#define	GPIO_OUT_PP		3	//�������

#define	GPIO_Pin_0		0x01	//IO���� Px.0
#define	GPIO_Pin_1		0x02	//IO���� Px.1
#define	GPIO_Pin_2		0x04	//IO���� Px.2
#define	GPIO_Pin_3		0x08	//IO���� Px.3
#define	GPIO_Pin_4		0x10	//IO���� Px.4
#define	GPIO_Pin_5		0x20	//IO���� Px.5
#define	GPIO_Pin_6		0x40	//IO���� Px.6
#define	GPIO_Pin_7		0x80	//IO���� Px.7
#define	GPIO_Pin_All	0xFF	//IO��������
	
#define	GPIO_P0			0		//
#define	GPIO_P1			1
#define	GPIO_P2			2
#define	GPIO_P3			3
#define	GPIO_P4			4
#define	GPIO_P5			5


typedef struct
{
	UI08	Mode;		//IOģʽ,  		GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	UI08	Pin;		//Ҫ���õĶ˿�	
} GPIO_InitTypeDef;




//========================================================================
// ����: u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
// ����: ��ʼ��IO��.
// ����: GPIOx: �ṹ����,��ο�timer.h��Ķ���.
// ����: �ɹ�����0, �ղ�������1,���󷵻�2.
// �汾: V1.0, 2017-3-3
//========================================================================
Gpio_e	GPIO_Inilize(UI08 GPIO, GPIO_InitTypeDef *GPIOx)
{
	if(GPIO > GPIO_P5)						return (GPIO_ERROR_NULL);	//�ղ���
	if(GPIOx->Mode > GPIO_OUT_PP)	return (GPIO_ERROR_FAILURE);	//����
	if(GPIO == GPIO_P0)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P0M1 &= ~GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;}	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)			{P0M1 |=  GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;}	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		{P0M1 |=  GPIOx->Pin,	P0M0 |=  GPIOx->Pin;}	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		{P0M1 &= ~GPIOx->Pin,	P0M0 |=  GPIOx->Pin;}	 //�������
	}
	if(GPIO == GPIO_P1)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P1M1 &= ~GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;}	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)			{P1M1 |=  GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;}	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		{P1M1 |=  GPIOx->Pin,	P1M0 |=  GPIOx->Pin;}	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		{P1M1 &= ~GPIOx->Pin,	P1M0 |=  GPIOx->Pin;}	 //�������
	}
	if(GPIO == GPIO_P2)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P2M1 &= ~GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;}	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)			{P2M1 |=  GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;}	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		{P2M1 |=  GPIOx->Pin,	P2M0 |=  GPIOx->Pin;}	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		{P2M1 &= ~GPIOx->Pin,	P2M0 |=  GPIOx->Pin;}	 //�������
	}
	if(GPIO == GPIO_P3)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P3M1 &= ~GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;}	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)			{P3M1 |=  GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;}	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		{P3M1 |=  GPIOx->Pin,	P3M0 |=  GPIOx->Pin;}	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		{P3M1 &= ~GPIOx->Pin,	P3M0 |=  GPIOx->Pin;}	 //�������
	}
	if(GPIO == GPIO_P4)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P4M1 &= ~GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;}	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)			{P4M1 |=  GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;}	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		{P4M1 |=  GPIOx->Pin,	P4M0 |=  GPIOx->Pin;}	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		{P4M1 &= ~GPIOx->Pin,	P4M0 |=  GPIOx->Pin;}	 //�������
	}
	if(GPIO == GPIO_P5)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P5M1 &= ~GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;}	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)			{P5M1 |=  GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;}	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		{P5M1 |=  GPIOx->Pin,	P5M0 |=  GPIOx->Pin;}	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		{P5M1 &= ~GPIOx->Pin,	P5M0 |=  GPIOx->Pin;}	 //�������
	}
	return (GPIO_ERROR_OK);	//�ɹ�
}
//========================================================================
// ����: u8	GPIO_Init(void)
// ����: ��ʼ��IO��.
// ����: GPIOx: �ṹ����,��ο�timer.h��Ķ���.
// ����: �ɹ�����0, �ղ�������1,���󷵻�2.
// �汾: V1.0, 2017-3-3
//========================================================================
Gpio_e	Init_GPIO(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;	
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;	
	GPIO_InitStructure.Mode = GPIO_PullUp;	
	GPIO_Inilize(GPIO_P0,&GPIO_InitStructure);
	

	GPIO_InitStructure.Pin  = GPIO_Pin_All;	
	GPIO_InitStructure.Mode = GPIO_PullUp;
	GPIO_Inilize(GPIO_P1,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;	
	GPIO_InitStructure.Mode = GPIO_PullUp;	
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);
	

	GPIO_InitStructure.Pin  = GPIO_Pin_All;	
	GPIO_InitStructure.Mode = GPIO_PullUp;	
	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);

	GPIO_InitStructure.Pin  = GPIO_Pin_All;	
	GPIO_InitStructure.Mode = GPIO_PullUp;	
	GPIO_Inilize(GPIO_P4,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;	
	GPIO_InitStructure.Mode = GPIO_PullUp;	
	GPIO_Inilize(GPIO_P5,&GPIO_InitStructure);
	

	GPIO_InitStructure.Pin  = GPIO_Pin_0;	    // �̵��� �������
	GPIO_InitStructure.Mode = GPIO_OUT_PP;	
	GPIO_Inilize(GPIO_P0,&GPIO_InitStructure);

	GPIO_InitStructure.Pin  = GPIO_Pin_3;	    // LED�����ȿ���
	GPIO_InitStructure.Mode = GPIO_OUT_PP;	
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin  = GPIO_Pin_6;	    // ����
	GPIO_InitStructure.Mode = GPIO_HighZ;	
	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin  = GPIO_Pin_7;	    // ����
	GPIO_InitStructure.Mode = GPIO_HighZ;	
	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);

	return (GPIO_ERROR_OK);	//�ɹ�
}