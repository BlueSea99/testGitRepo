#ifndef	__GPIO_H
#define	__GPIO_H

#include "STC8.H"

typedef enum
{
	GPIO_ERROR_OK =	0,      // Everything executed normally // 成功
	GPIO_ERROR_NULL =	1,  //	空操作
	GPIO_ERROR_FAILURE = 2, //	失败
	GPIO_ERROR_LAST
}Gpio_e;
	
Gpio_e	Init_GPIO(void);


///*********************  重定义IO *************************/

//sbit K1	= P5^3;  	//按键1		
//sbit K3 = P0^2;		//按键3
//sbit K4 = P0^3;		//按键4

//#ifdef	Debug
////sbit K1	=	P5^3;  	//按键1
//sbit K2 = P3^4;		//按键2
////sbit K3 = P0^2;		//按键3
////sbit K4 = P0^3;		//按键4
//sbit BUTTON_DEC		=	P5^2;		// 降低亮度
//sbit BUTTON_ADD		=	P5^3;		// 增加亮度

//#else
//sbit K2				=	P3^3;  		// 按键2
//sbit BUTTON_DEC		=	P3^6;		// 降低亮度
//sbit BUTTON_ADD		=	P3^7;		// 增加亮度
//#endif
////////////////////////////////////////////////////////////////////////////

//#define Red   P22 // 红色灯
//#define Green P21 // 绿色灯
//#define Blue  P20 // 蓝色灯

#define DispVccP    P23         // 数码管电源控制
#define SetDispVccP P23 = 1
#define ClrDispVccP P23 = 0

#define	RELAY		P00  // 继电器
#define SYNCP		P32	 // 同步
#define	PWMP		P01  // 可控硅



#endif
