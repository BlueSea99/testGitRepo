#ifndef __MANAGE_LED_H
#define __MANAGE_LED_H

#include "STC8.h"
#include "TypeDef.h"

typedef struct
{
    BOOL Flag;
    UI16 Tim;
    UI08 FlashOn;
    UI08 FlashOff;
}LED_DEF;

#ifdef	Debug
sbit S_CLK =P4^0;  //pin 11 
sbit R_CK	 =P2^6;  //pin 12
sbit MOSIO =P2^4;  //pin 14
#else
sbit MOSIO =P1^6;  //pin 14
sbit R_CK	 =P1^7;  //pin 12
sbit S_CLK =P1^5;  //pin 11
#endif

void Init_PanelFlash(void);
void LED_ReLedFlash(void);
void LED_SetFlash(UI08 Mode);
void LED_ClrFlash(void);
void LED_ShowProc(void);
UI08 LedShowTrans(UI16 Value);



#endif
