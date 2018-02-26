#include<s3c2440.h>
#include"uart.h"
int main()
{   
    unsigned int a=10;       //系统时钟初始化，FCLK=400MHz,HCLK=100MHz,PCLK=50MHz
    Uart0_Init(115200);      //初始化并设置波特率为115 200
    while(1)
    {
       Uart0_Printf("Uart0_Printf test output is:%d\n",a);
    }     
}
