#ifndef	__GPIO_H
#define	__GPIO_H

#include "STC8.H"

typedef enum
{
	GPIO_ERROR_OK =	0,      // Everything executed normally // �ɹ�
	GPIO_ERROR_NULL =	1,  //	�ղ���
	GPIO_ERROR_FAILURE = 2, //	ʧ��
	GPIO_ERROR_LAST
}Gpio_e;
	
Gpio_e	Init_GPIO(void);


///*********************  �ض���IO *************************/

//sbit K1	= P5^3;  	//����1		
//sbit K3 = P0^2;		//����3
//sbit K4 = P0^3;		//����4

//#ifdef	Debug
////sbit K1	=	P5^3;  	//����1
//sbit K2 = P3^4;		//����2
////sbit K3 = P0^2;		//����3
////sbit K4 = P0^3;		//����4
//sbit BUTTON_DEC		=	P5^2;		// ��������
//sbit BUTTON_ADD		=	P5^3;		// ��������

//#else
//sbit K2				=	P3^3;  		// ����2
//sbit BUTTON_DEC		=	P3^6;		// ��������
//sbit BUTTON_ADD		=	P3^7;		// ��������
//#endif
////////////////////////////////////////////////////////////////////////////

//#define Red   P22 // ��ɫ��
//#define Green P21 // ��ɫ��
//#define Blue  P20 // ��ɫ��

#define DispVccP    P23         // ����ܵ�Դ����
#define SetDispVccP P23 = 1
#define ClrDispVccP P23 = 0

#define	RELAY		P00  // �̵���
#define SYNCP		P32	 // ͬ��
#define	PWMP		P01  // �ɿع�



#endif
