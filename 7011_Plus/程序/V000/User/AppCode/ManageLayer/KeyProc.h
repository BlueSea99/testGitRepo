#ifndef __MANAGE_KEY_H__
#define __MANAGE_KEY_H__

#include "STC8.h"


#define  KEY1  P33  	//按键1 开关/长按按键
#define	 KEY2  P36		//按键2 增加亮度按键
#define  KEY3  P37		//按键3 降低亮度按键

#define FirstGearP 	    P13
#define SecondGearP   	P14
#define ThirdGearP		P12

#define AdjustLightP    P02
#define LedBulb     P22
#define IncBulb     P03

void KeyProc(void);
#endif
