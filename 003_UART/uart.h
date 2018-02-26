#ifndef __UART_H__
#define __UART_H__

/***********************************************
*函数名称：void Uart0_Init(unsigned int baudrate)
*参数说明：baudrate：波特率
*返 回 值：无
*全局变量: 无
*功    能：对UART0进行初始化                         
************************************************/
void Uart0_Init(unsigned int baudrate);

/***********************************************
*函数名称：void putc(unsigned char c)
*参数说明：c:通过串口接收到的字符，注意这里是8位数据
*返 回 值：无
*全局变量: 无
*功    能：将通过串口接收到的字符发送给PC机并显示在
*          串口调试工具。                
************************************************/
void putc(unsigned char c);

/***********************************************
*函数名称：unsigned char getc(void)
*参数说明：无
*返 回 值：c:通过串口接收到的字符，注意这里是8位数据
*全局变量: 无
*功    能：接收并保存通过串口输入的数据                         
************************************************/
unsigned char getc(void); 

#endif
