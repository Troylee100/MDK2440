/*
*  使用定时器0的定时功能，使LED灯每秒钟闪烁一次
*/

#include<s3c2440.h>
#include"timer.h"
#include"led.h"

int main()
{
    int flag=0;

    Led_Init();   //对LED初始化为全灭
    Timer0_Init();  //定时器0初始化，打开定时器0，定时器0开始进行减1计数。
    
    while(1)
    {
        if(SRCPND&(1<<10))     //当TCNT0中的计数值减为0时，定时器0中断标志会置位
        {                                     //因此，在程序中可以通过不断的检测该位是否置位来判断1s定时
            flag=!flag;                     //是否到达。定时器0中断标志位位于SRCPND寄存器的第10位
            SRCPND|=(1<<10);     //清除定时器0中断标志位
        }
        if(1==flag)                      //判断falg是否为1，这里使用一个小技巧，使用if(1==flag)。也可以
        {
            Led1_On();
        }  
        else
        {
           Led1_Off();
        }
    }
}
