#ifndef __MANAGE_KEY_H__
#define __MANAGE_KEY_H__

#include "STC8.h"


#define  KEY1  P33  	//����1 ����/��������
#define	 KEY2  P36		//����2 �������Ȱ���
#define  KEY3  P37		//����3 �������Ȱ���

#define FirstGearP 	    P12
#define SecondGearP   	P14
#define ThirdGearP		P13

#define AdjustLightP    P02
//#define AdjustLightP     P22
//#define AdjustLightP     P03

void KeyProc(void);
void ModeKeyProc(void);

#endif
