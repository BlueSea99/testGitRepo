#include "Typedef.h"
#include "Gpio.h"
#include "SysDataDef.h"
#include "LedProc.h"

UI16 PwmValue = 0;

#define Supplement 255

void FlashParaProc(void)
{
    UI08 multiple = 0;
    UI16 temp_dimmer_value = 0;
    
    /* 
     * 499��Ӧ�в��������ƶ�1ms  
     * �в��η�ΧΪDimmer.Ledmin - Dimmer.Ledmax��1250 - 3750������2.5ms - 7.5ms
     * ͨ������Dimmer.LeftMove��Dimmer.RightMove�����в��η�Χ
     */ 

//    multiple = (Dimmer.LedMax - Dimmer.LeftMove - Dimmer.LedMin - Dimmer.RightMove) / 250;
//    PwmValue = (Dimmer.LedMin + Dimmer.LeftMove)+ ((255 - Dimmer.TmepValue) * multiple);
//    multiple = (Dimmer.LedMax - Dimmer.LedMin) / 250;
//    temp_dimmer_value = LedShowTrans(Dimmer.TmepValue);
//    
//    temp_dimmer_value = LightValTab[temp_dimmer_value - 1];
//    
//    PwmValue = (Dimmer.LedMin)+ ((255 - temp_dimmer_value) * 15);    

      PwmValue = (Dimmer.LedMin)+ ((250 - Dimmer.TmepValue) * 17); 

//    if(!DownLight)
//    {
//        if(!FirstSupple)
//        {
//            Dimmer.LeftMove = 0;
//        }
//        else if(!SecondSupple)
//        {
//            Dimmer.LeftMove = Supplement;
//        }
//        else if(!ThirdSupple)
//        {
//            Dimmer.LeftMove = Supplement << 1;
//        }
//    }
//    else if(LedBulb == 0)
//    {
//        if(!FirstSupple)
//        {
//            
//        }
//        else if(!SecondSupple)
//        {
//            
//        }
//        else if(!ThirdSupple)
//        {
//            
//        }  
//    }
//    else if(IncBulb == 0)
//    {
//        if(!FirstSupple)
//        {
//            
//        }
//        else if(!SecondSupple)
//        {
//            
//        }
//        else if(!ThirdSupple)
//        {
//            
//        }  
//    }
}
