#include "Gpio.h"
#include "TypeDef.h"

//#define Main_Fosc_KHZ	(MAIN_Fosc / 1000)

#define	GPIO_PullUp		0	//上拉准双向口
#define	GPIO_HighZ		1	//浮空输入
#define	GPIO_OUT_OD		2	//开漏输出
#define	GPIO_OUT_PP		3	//推挽输出

#define	GPIO_Pin_0		0x01	//IO引脚 Px.0
#define	GPIO_Pin_1		0x02	//IO引脚 Px.1
#define	GPIO_Pin_2		0x04	//IO引脚 Px.2
#define	GPIO_Pin_3		0x08	//IO引脚 Px.3
#define	GPIO_Pin_4		0x10	//IO引脚 Px.4
#define	GPIO_Pin_5		0x20	//IO引脚 Px.5
#define	GPIO_Pin_6		0x40	//IO引脚 Px.6
#define	GPIO_Pin_7		0x80	//IO引脚 Px.7
#define	GPIO_Pin_All	0xFF	//IO所有引脚
	
#define	GPIO_P0			0		//
#define	GPIO_P1			1
#define	GPIO_P2			2
#define	GPIO_P3			3
#define	GPIO_P4			4
#define	GPIO_P5			5


typedef struct
{
	UI08	Mode;		//IO模式,  		GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	UI08	Pin;		//要设置的端口	
} GPIO_InitTypeDef;




//========================================================================
// 函数: u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
// 描述: 初始化IO口.
// 参数: GPIOx: 结构参数,请参考timer.h里的定义.
// 返回: 成功返回0, 空操作返回1,错误返回2.
// 版本: V1.0, 2017-3-3
//========================================================================
Gpio_e	GPIO_Inilize(UI08 GPIO, GPIO_InitTypeDef *GPIOx)
{
	if(GPIO > GPIO_P5)						return (GPIO_ERROR_NULL);	//空操作
	if(GPIOx->Mode > GPIO_OUT_PP)	return (GPIO_ERROR_FAILURE);	//错误
	if(GPIO == GPIO_P0)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P0M1 &= ~GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;}	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)			{P0M1 |=  GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;}	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		{P0M1 |=  GPIOx->Pin,	P0M0 |=  GPIOx->Pin;}	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		{P0M1 &= ~GPIOx->Pin,	P0M0 |=  GPIOx->Pin;}	 //推挽输出
	}
	if(GPIO == GPIO_P1)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P1M1 &= ~GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;}	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)			{P1M1 |=  GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;}	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		{P1M1 |=  GPIOx->Pin,	P1M0 |=  GPIOx->Pin;}	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		{P1M1 &= ~GPIOx->Pin,	P1M0 |=  GPIOx->Pin;}	 //推挽输出
	}
	if(GPIO == GPIO_P2)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P2M1 &= ~GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;}	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)			{P2M1 |=  GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;}	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		{P2M1 |=  GPIOx->Pin,	P2M0 |=  GPIOx->Pin;}	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		{P2M1 &= ~GPIOx->Pin,	P2M0 |=  GPIOx->Pin;}	 //推挽输出
	}
	if(GPIO == GPIO_P3)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P3M1 &= ~GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;}	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)			{P3M1 |=  GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;}	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		{P3M1 |=  GPIOx->Pin,	P3M0 |=  GPIOx->Pin;}	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		{P3M1 &= ~GPIOx->Pin,	P3M0 |=  GPIOx->Pin;}	 //推挽输出
	}
	if(GPIO == GPIO_P4)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P4M1 &= ~GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;}	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)			{P4M1 |=  GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;}	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		{P4M1 |=  GPIOx->Pin,	P4M0 |=  GPIOx->Pin;}	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		{P4M1 &= ~GPIOx->Pin,	P4M0 |=  GPIOx->Pin;}	 //推挽输出
	}
	if(GPIO == GPIO_P5)
	{
		if(GPIOx->Mode == GPIO_PullUp)		{P5M1 &= ~GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;}	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)			{P5M1 |=  GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;}	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		{P5M1 |=  GPIOx->Pin,	P5M0 |=  GPIOx->Pin;}	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		{P5M1 &= ~GPIOx->Pin,	P5M0 |=  GPIOx->Pin;}	 //推挽输出
	}
	return (GPIO_ERROR_OK);	//成功
}
//========================================================================
// 函数: u8	GPIO_Init(void)
// 描述: 初始化IO口.
// 参数: GPIOx: 结构参数,请参考timer.h里的定义.
// 返回: 成功返回0, 空操作返回1,错误返回2.
// 版本: V1.0, 2017-3-3
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
	

	GPIO_InitStructure.Pin  = GPIO_Pin_0;	    // 继电器 推挽输出
	GPIO_InitStructure.Mode = GPIO_OUT_PP;	
	GPIO_Inilize(GPIO_P0,&GPIO_InitStructure);

	GPIO_InitStructure.Pin  = GPIO_Pin_3;	    // LED灯亮度控制
	GPIO_InitStructure.Mode = GPIO_OUT_PP;	
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin  = GPIO_Pin_6;	    // 按键
	GPIO_InitStructure.Mode = GPIO_HighZ;	
	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin  = GPIO_Pin_7;	    // 按键
	GPIO_InitStructure.Mode = GPIO_HighZ;	
	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);

	return (GPIO_ERROR_OK);	//成功
}