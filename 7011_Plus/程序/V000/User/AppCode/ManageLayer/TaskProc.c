#include "TypeDef.h"
#include "TaskProc.h"
#include "Gpio.h"
#include "LedProc.h"
#include "ParaProc.h"
#include "wifi.h"
#include "WifiProc.h"
#include "SysDataDef.h"

void TimeEvent(void)
{
	extern UI08 TimeEventF;
	static UI08 Event10msF = 0;
	static UI08 Event100msF = 0;
	
	static UI08 Event1ms = 0;
	static UI08 Event10ms = 0;
	static UI08 Event100ms = 0;
	
	if(!TimeEventF)	return;
	TimeEventF = 0;
    
//	PWMP = 1;
    
	switch(++Event1ms)
	{
		case 1:
			wifi_uart_service();
			break;
		
		case 2:
			
			break;
		
		case 3:
			StateProc();
			break;
		
		case 4:
			Event1ms = 0;
			Event10msF = 1;
			break;
		
		default:
			Event1ms = 0;
			Event10msF = 1;
			break;
	}
	
	if(Event10msF)
	{
		Event10msF = 0;
		switch(++Event10ms)
		{
			case 1:
				KeyProc();
				break;
			
			case 2:
				LED_ShowProc();
				break;
			
			case 3:
				break;
			
			case 4:
                FlashParaProc();
				break;
			
			case 5:

				break;
			
			case 6:
                UpdateDpValue();    // 上报更新Dp值
				break;
			
			case 7:
                LED_ReLedFlash();
				break;
			
			case 8:
//                WifiTest();     // 产测
				break;
			
			case 9:
//#ifdef WIFI_TEST_ENABLE                
//                if(WifiTestF)   return;
//            
//                mcu_start_wifitest();
//#endif            
				break;
			
			case 10:
				Event10ms = 0;
				Event100msF = 1;
				break;
			
			default:
				Event10ms = 0;
				Event100msF = 1;
				break;
		}
	}
	
	if(Event100msF)
	{
		Event100msF = 0;
		switch(++Event100ms)
		{
			case 1:
                WifiProc();         // WiFi连接状态处理
				break;
			
			case 2:
				break;
			
			case 3:
				break;
			
			case 4:
				break;
			
			case 5:
				break;
			
			case 6:
				break;
			
			case 7:
				break;	
			
			case 8:
				break;
			
			case 9:
				break;
			
			case 10:
				Event100ms = 0;
				break;
			
			default:
				Event100ms = 0;
				break;
		}
	}
	
//	PWMP = 0;
}
	