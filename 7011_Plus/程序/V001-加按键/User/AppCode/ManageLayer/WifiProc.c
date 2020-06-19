#include "WifiProc.h"
#include "wifi.h"
#include "SysDataDef.h"


void WifiProc(void)
{
//    static UI08 self_lock_flag = 0;
    static UI08 reset_time = 0;
    UI08 wifi_state = 0;
    
    wifi_state = mcu_get_wifi_work_state();  // ��ȡWifi״̬
    
//    if(wifi_state != SMART_CONFIG_STATE && !self_lock_flag) 
//    {
//        self_lock_flag = 1;
//        mcu_set_wifi_mode(SMART_CONFIG);    // ����Ĭ��״̬
//    }
    
    switch(wifi_state)
    {
        // smartconfig ����״̬  8 ����
        case SMART_CONFIG_STATE:
            ClrNetSuccessF;
            SetFastFlashF;
            ClrSlowFlashF;
            break;
        
        // AP ����״̬ A ����
        case AP_STATE: 
            ClrNetSuccessF;
            SetSlowFlashF;
            ClrFastFlashF;
            break;
        
        // WIFI�����õ�δ���ӵ�·���� - ����
        case WIFI_NOT_CONNECTED:
            ClrNetSuccessF;
            SetSlowFlashF;
            ClrFastFlashF;
            break;
        
        // WIFI������������·����
        case WIFI_CONNECTED: 
        // WIFI������·���������ӵ��ƶ�            
        case WIFI_CONN_CLOUD:       
            SetNetSuccessF;
            ClrSlowFlashF;
            ClrFastFlashF;
            break;
        
        // �͹���ģʽ
        case WIFI_LOW_POWER:        
            break;
        
        case WIFI_SATE_UNKNOW:
            if(++reset_time > 60)   // 6s ��λһ��
            {
                reset_time = 0;
                ClrNetSuccessF;
                mcu_reset_wifi();  // ��λwifi
            }
            break;

        default:
            wifi_state = WIFI_SATE_UNKNOW;
            break;
    }
}

UI16 BrightApp2Mcu(UI16 AppValue)
{
    UI16 temp_brightval = 0;
    
    switch(Dimmer.MinLightVal)      // ���ƶ�ֵ����ʾֵ��Ӧ����
    {
        case 0:
            temp_brightval = ((AppValue + 8) * 3 / 5);
            break;
        
        case 1:
            temp_brightval = ((AppValue + 49) >> 1);
            break;
        
        case 2:
            temp_brightval = (((AppValue + 100) << 1) / 5);
            break;
        
        default:
            break;
    }
    
    return temp_brightval;  
}


UI16 BrightMcu2App(UI16 McuValue)
{
    UI16 temp_brightval = 0;
    
    switch(Dimmer.MinLightVal)      // ���ƶ�ֵ����ʾֵ��Ӧ����
    {
        case 0:
            temp_brightval = (McuValue * 5 / 3 - 8);
            break;
        
        case 1:
            temp_brightval = ((McuValue << 1) - 49);
            break;
        
        case 2:
            if(McuValue == 138)
            {
                temp_brightval = (((McuValue * 5) >> 1) - 120);
            }
            else
            {
                temp_brightval = (((McuValue * 5) >> 1) - 100);
            }
            break;
        
        default:
            break;
    }
    
    if(temp_brightval > 255)
    {
        temp_brightval = 255;
    }
    
    return temp_brightval;
}
    
    
void UpdateDpValue(void)
{
    UI08 switch_value = 0;
    UI16 bright_value = 0;
    
    if(DpSwitchF)
    {
        ClrDpSwitchF;
        
        switch_value = SwitchF ? 1 : 0;
        mcu_dp_bool_update(DPID_LED_SWITCH,switch_value);
    }
    
    if(DpBrightF)
    {
        ClrDpBrightF;
        
        bright_value = BrightMcu2App(Dimmer.FaceValue);
        
        mcu_dp_value_update(DPID_BRIGHT_VALUE,bright_value);
    }
}

void WifiTest(void)
{
    static UI16 show_value = 0;
    static UI08 i = 0;
    
    if(!WifiTestF)  return;
    
    switch(i)
    {
        case 0:
            SetPwmF;
            OpenSwitchP;            // �� 500ms
            i++;
            break;
        
        case 1:
            if(++show_value > 50)   // �� 500ms
            {
                CloseSwitchP;
                
                show_value = 0;
                i++;
            }
            break;
            
        case 2:
            if(++show_value > 50)   // �� 500ms
            {
                OpenSwitchP;
                
                show_value = 0;
                i++;
            }
            break;
            
        case 3:
            if(++show_value > 50)   // �� 500ms
            {
                CloseSwitchP;                

//                ClrWifiTestF;
                show_value = 0;
                i = 0;
            }
            break;
            
        case 4:
            break;
    }
}

//void WaveTiggerProc(void)
//{
//    if(!ClrPwmF)     
//    ClrPwmF;
//}
