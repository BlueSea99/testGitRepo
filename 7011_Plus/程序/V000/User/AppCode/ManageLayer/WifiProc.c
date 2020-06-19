#include "WifiProc.h"
#include "TypeDef.h"
#include "wifi.h"
#include "SysDataDef.h"


void WifiProc(void)
{
    static UI08 self_lock_flag = 0;
    static UI08 reset_time = 0;
    UI08 wifi_state = 0;
    
    wifi_state = mcu_get_wifi_work_state();  // 获取Wifi状态
    
//    if(wifi_state != SMART_CONFIG_STATE && !self_lock_flag) 
//    {
//        self_lock_flag = 1;
//        mcu_set_wifi_mode(SMART_CONFIG);    // 设置默认状态
//    }
    
    switch(wifi_state)
    {
        // smartconfig 配置状态  8 快闪
        case SMART_CONFIG_STATE:
            ClrNetSuccessF;
            SetFastFlashF;
            ClrSlowFlashF;
            break;
        
        // AP 配置状态 A 慢闪
        case AP_STATE: 
            ClrNetSuccessF;
            SetSlowFlashF;
            ClrFastFlashF;
            break;
        
        // WIFI已配置但未连接到路由器 - 慢闪
        case WIFI_NOT_CONNECTED:
            ClrNetSuccessF;
            SetSlowFlashF;
            ClrFastFlashF;
            break;
        
        // WIFI已配置且连上路由器
        case WIFI_CONNECTED: 
        // WIFI已连上路由器且连接到云端            
        case WIFI_CONN_CLOUD:       
            SetNetSuccessF;
            ClrSlowFlashF;
            ClrFastFlashF;
            break;
        
        // 低功耗模式
        case WIFI_LOW_POWER:        
            break;
        
        case WIFI_SATE_UNKNOW:
            if(++reset_time > 60)   // 6s 复位一次
            {
                reset_time = 0;
                ClrNetSuccessF;
                mcu_reset_wifi();  // 复位wifi
            }
            break;

        default:
            wifi_state = WIFI_SATE_UNKNOW;
            break;
    }
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
        
        bright_value = ((Dimmer.FaceValue * 3) >> 1);
        
        if(bright_value > 255)
        {
            bright_value = 255;
        }
        
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
            OpenSwitchP;            // 开 500ms
            i++;
            break;
        
        case 1:
            if(++show_value > 50)   // 关 500ms
            {
                CloseSwitchP;
                
                show_value = 0;
                i++;
            }
            break;
            
        case 2:
            if(++show_value > 50)   // 开 500ms
            {
                OpenSwitchP;
                
                show_value = 0;
                i++;
            }
            break;
            
        case 3:
            if(++show_value > 50)   // 关 500ms
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
