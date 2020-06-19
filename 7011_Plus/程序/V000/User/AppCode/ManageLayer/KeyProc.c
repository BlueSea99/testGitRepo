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
            else    // ��ʾ����������
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
                else   // ��ʾ���������� 
                {
                    key_value = 0;
                    i = 0;
                    Count = 0;
                    return 0xFF;
                }                
            }
            break;
    }
    
	return 0;	// �ް�������
}

/*****************************************************************************
�������� : key_scan
�������� : ɨ�谴��
������� : ��
���ز��� : ��
ʹ��˵�� : ��
*****************************************************************************/
void KeyProc(void)
{
    static UI08 time_count = 0;
	UI08  key;
    UI08 wifi_state = 0;
    UI08 temp_value = 0;
    
    if(StartUpF)    return;     // ���ؿ����͹ر�ʱ��������Ч
    
	key = KeyScan();
	
    if(key == 0x00) return;
    
	switch(key)
	{        
		// ����
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
        
        // ��������
        case 0x11:
            time_count++;
            if(time_count > 250)    time_count = 250;
        
            if(++time_count == 12)    // 
            {               
                wifi_state = mcu_get_wifi_work_state();  // ��ȡWifi״̬
                
                if(wifi_state != SMART_CONFIG_STATE || wifi_state != AP_STATE)
                {
                    mcu_reset_wifi();  // ��λwifi
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
		
		// �������Ȱ���
		case 2:
        case 0x12:
            if(!SwitchF) return;
            
            SetDimmerKeyF;      // ��־���ڽ��е��ƣ�3s���������״̬
            SetDpBrightF;       // �ϱ�APP ����ֵ ������ֵ�����Ʒ�������
            Face.CtrlTim = 0;
        
            temp_value = LedShowTrans(Dimmer.FaceValue);
            if(--temp_value < 1)  temp_value = 1;
            
            Dimmer.FaceValue = LightValTab[temp_value - 1];
       
            
            break;
		
		
        // �������Ȱ���
		case 3:
		case 0x13:
            if(!SwitchF) return;
            
            SetDimmerKeyF;
            SetDpBrightF;       // �ϱ�APP ����ֵ ������ֵ�����Ʒ�������
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
