#include"uart.h"

int main()
{   
    unsigned char a;
    Uart0_Init(115200);     //��ʼ�������ò�����Ϊ115 200
    while(1)
    {
        a=getc();                    //��ȡ����������ַ�
        putc(a);                     //PC����ʾͬͨ�����ڽ��յ����ַ�
    }     
}
