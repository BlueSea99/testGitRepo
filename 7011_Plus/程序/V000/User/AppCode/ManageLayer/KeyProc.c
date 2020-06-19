#include "KeyProc.h"
#include "TypeDef.h"
#include "SysDataDef.h"
#include "LedProc.h"
#include "wifi.h"


void JudgeWorkMode(void)
{
    if(AdjustLightP)
    {
        SetAdjustLightF;
    }
    else
    {
        ClrAdjustLightF;
    }
    
    if(FirstGearP)
    {
        SetFirstGearF;
        ClrSecondGearF;
        ClrThirdGearF;
    }
    else if(SecondGearP)
    {
        SetSecondGearF;
        ClrFirstGearF;
        ClrThirdGearF;
    }
    else if(ThirdGearP)
    {
        SetThirdGearF;
        ClrFirstGearF;
        ClrSecondGearF;
    }
}
    
UI08 KeyScan(void)
{
	#define KEY_TIME	50
    
    static UI08 i = 0;
	static UI16 Count = 0;
    static UI08 key_value = 0;
//	UI08 key_value = 0;
    
    switch(i)
    {
        case 0:
            if(KEY1 == 0 || KEY2 == 0 || KEY3 == 0)
            {
                i++;  
            }
            break;
        
        case 1:
            if(KEY1 == 0 || KEY2 == 0 || KEY3 == 0)
            {
                i++;
                if(KEY1 == 0)	    key_value = 0x01;
                else if(KEY2 == 0)	key_value = 0x02;
                else if(KEY3 == 0)	key_value = 0x03;
            }
            else
            {
                key_value = 0;
                i = 0;  
            }
            
            break;
        
        case 2:
            if(KEY1 == 0 || KEY2 == 0 || KEY3 == 0)    
            {}
            else    // 表示都弹起来了
            {
                i = 0;
                Count = 0;
                
                if(key_value == 0x01)	    
                {
                    key_value = 0;
                    return 0x01;
                }
                else if(key_value == 0x02)	
                {
                    key_value = 0;
                    return 0x02;
                }
                else if(key_value == 0x03)	
                {
                    key_value = 0;
                    return 0x03; 
                }
            }
            
            if((++Count) > KEY_TIME)
            {
                i++;
            }
            break;
            
        case 3:
            if((++Count) >= KEY_TIME)
            {
                Count = 0;

                if(KEY1 == 0)	    return 0x11;
                else if(KEY2 == 0)	return 0x12;
                else if(KEY3 == 0)	return 0x13;
                
                if(KEY1 == 0 || KEY2 == 0 || KEY3 == 0)
                {}
                else   // 表示都弹起来了 
                {
                    key_value = 0;
                    i = 0;
                    Count = 0;
                    return 0xFF;
                }                
            }
            break;
    }
    
	return 0;	// 无按键按下
}

/*****************************************************************************
函数名称 : key_scan
功能描述 : 扫描按键
输入参数 : 无
返回参数 : 无
使用说明 : 无
*****************************************************************************/
void KeyProc(void)
{
    static UI08 time_count = 0;
	UI08  key;
    UI08 wifi_state = 0;
    UI08 temp_value = 0;
    
    if(StartUpF)    return;     // 开关开启和关闭时，按键无效
    
	key = KeyScan();
	
    if(key == 0x00) return;
    
	switch(key)
	{        
		// 开关
		case 0X01:

            if(SwitchF) 
            {
                ClrSwitchF;
                SetStartUpF;
                SetDpSwitchF;
            }
            else
            {
                SetSwitchF;
                SetStartUpF;
                SetDpSwitchF;
            }
            
//#ifdef WIFI_TEST_ENABLE		
//                mcu_start_wifitest();
//#endif            
			break;
        
        // 长按按键
        case 0x11:
            time_count++;
            if(time_count > 250)    time_count = 250;
        
            if(++time_count == 12)    // 
            {               
                wifi_state = mcu_get_wifi_work_state();  // 获取Wifi状态
                
                if(wifi_state != SMART_CONFIG_STATE || wifi_state != AP_STATE)
                {
                    mcu_reset_wifi();  // 复位wifi
                }
                else
                {
                    if(wifi_state == SMART_CONFIG_STATE)
                    {
                        mcu_set_wifi_mode(AP_CONFIG);                        
                    }
                    else if(wifi_state == AP_STATE)
                    {
                        mcu_set_wifi_mode(SMART_CONFIG);
                    }
                }
            }
            break;
		
		// 降低亮度按键
		case 2:
        case 0x12:
            if(!SwitchF) return;
            
            SetDimmerKeyF;      // 标志正在进行调灯，3s后进入配网状态
            SetDpBrightF;       // 上报APP 调光值 将亮度值传到云服务器中
            Face.CtrlTim = 0;
        
            temp_value = LedShowTrans(Dimmer.FaceValue);
            if(--temp_value < 1)  temp_value = 1;
            
            Dimmer.FaceValue = LightValTab[temp_value - 1];
       
            
            break;
		
		
        // 增加亮度按键
		case 3:
		case 0x13:
            if(!SwitchF) return;
            
            SetDimmerKeyF;
            SetDpBrightF;       // 上报APP 调光值 将亮度值传到云服务器中
            Face.CtrlTim = 0;
        
            temp_value = LedShowTrans(Dimmer.FaceValue);
            if(++temp_value > 10)  temp_value = 10;
            
            Dimmer.FaceValue = LightValTab[temp_value - 1];         
			break;
		
        case 0xFF:
            time_count = 0;
            break;
        
		default:
			break;
			
	}		
}
