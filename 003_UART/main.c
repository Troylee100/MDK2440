#include"uart.h"

int main()
{   
    unsigned char a;
    Uart0_Init(115200);     //初始化并设置波特率为115200
    while(1)
    {
        a=getc();                    //获取串口输入的字符
        putc(a);                     //PC机显示通过串口接收到的字符
    }     
}
