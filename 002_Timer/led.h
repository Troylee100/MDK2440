#ifndef __LED_H__
#define __LED_H__
#include<s3c2440.h> 

#define Led1_On() {GPBDAT&=(~(1<<5));}       //在程序调用函数时，调用函数需要保存函数的返回地址，
#define Led1_Off() {GPBDAT|=(1<<5);}           //然后从函数返回是需要将返回地址赋值给PC，这些都会
#define Led2_On() {GPBDAT&=(~(1<<6));}    //使程序执行速度变慢。为了改善这种情况，对于这种
#define Led2_Off() {GPBDAT|=(1<<6);}         //代码量很小的程序段，可以使用宏的形式实现。
#define Led3_On() {GPBDAT&=(~(1<<7));}
#define Led3_Off() {GPBDAT|=(1<<7);}
#define Led4_On() {GPBDAT&=(~(1<<8));}
#define Led4_Off() {GPBDAT|=(1<<8);}
/***************************************************************
* 函数名称:void Led_Init(void)
* 参数说明:无
* 全局变量:无
* 返 回 值:无
* 功    能:led初始化函数，使4个led初始化为灭
*     的输入时钟。
***************************************************************/
void Led_Init(void);
#endif
