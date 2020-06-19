#ifndef __USER_UART_H__
#define __USER_UART_H__


#ifdef USER_UART_GLOBALS
#define USER_UART_EXT
#else
#define USER_UART_EXT extern 
#endif

/*****************************************************************************
函数名称 : uart1_init
功能描述 : uart1初始化
输入参数 : 无
返回参数 : 无
使用说明 : 无
*****************************************************************************/
void uart1_init(void);
void Uart2Init(void);
/*****************************************************************************
函数名称 : Uart_PutChar
功能描述 : 串口发送
输入参数 : dat:待发送数据
返回参数 : 无
使用说明 : 无
*****************************************************************************/
void Uart_PutChar(unsigned char dat);

#endif

