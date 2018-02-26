

    #include<s3c2440.h>
    #include<stdarg.h>
    #include"uart.h"

    #define PCLK   50000000
    #define UART_BRD     (int)((PCLK/(baudrate*16))-1)

    /***********************************************
    *函数名称：void Uart0_Init(unsigned int baudrate)
    *参数说明：baudrate：波特率
    *返 回 值：无
    *全局变量: 无
    *功    能：对UART0进行初始化                         
    ************************************************/
    void Uart0_Init(unsigned int baudrate)
    {
         GPHCON&=~((3<<4)|(3<<6));  //GPH2--TXD0;GPH3--RXD0
         GPHCON|=((2<<4)|(2<<6));    //设置GPH2、GPH3为TXD0、RXD0功能
         GPHUP=0x00;                 //上拉电阻使能
          ULCON0|=0x03;              //设置数据发送格式：8个数据位，1个停止位，无校验位
          UCON0=0x05;                //发送模式和接收模式都使用查询模式
         UBRDIV0=UART_BRD;         //设置波特率，其中波特率作为一个参数传递到该初始化函数
         URXH0=0;          //将URXH0清零
    }

    /***********************************************
    *函数名称：void putc(unsigned char c)
    *参数说明：c:通过串口接收到的字符，注意这里是8位数据
    *返 回 值：无
    *全局变量: 无
    *功    能：将通过串口接收到的字符发送给PC机并显示在
    *          串口调试工具。                
    ************************************************/
    void putc(unsigned char c)
    {
         UTXH0=c;
         while(!(UTRSTAT0&(1<<2)));    //等待发送完成
    }

    /***********************************************
    *函数名称：unsigned char getc(void)
    *参数说明：无
    *返 回 值：c:通过串口接收到的字符，注意这里是8位数据
    *全局变量: 无
    *功    能：接收并保存通过串口输入的数据                         
    ************************************************/
    unsigned char getc(void)
    {
         unsigned char c;
         while(!(UTRSTAT0&(1<<0)));     //查询是否接收到有效数据
         c=URXH0;
         return c;
    }
    /***********************************************
    *函数名称：static void Uart0_SendByte(int data)
    *参数说明：data:一个字节的数据
    *返 回 值：无
    *全局变量: 无
    *功    能：向串口发送一个字节的数据。这个函数只在本
    *          C文件内使用，不被其他文件所调用，故使用
    *     static来修饰。                 
    ************************************************/

    static void Uart0_SendByte(int data)
    {
         if(data=='\n')      //注意，在超级终端中使用的换行符是'\r'，因此当遇到'\n'时
        {                        //需要将其转换为'r'
           while(!(UTRSTAT0&(1<<2)));    //等待发送完成
           UTXH0='\r';  
        }
        while(!(UTRSTAT0&(1<<2)));    //等待发送完成完成后，将新发送
        UTXH0=data;                         //的数据写入发送寄存器
    }
    /***********************************************
    *函数名称：static void Uart0_SendString(char *pt)
    *参数说明：pt:指针，指向将要发送的数据所在数组的地址
    *返 回 值：无
    *全局变量: 无
    *功    能：发送字符串                 
    ************************************************/
    static void Uart0_SendString(char *pt)
    {
       while(*pt)
       {
          Uart0_SendByte(*pt++); 
       }
    }
    /***********************************************
    *函数名称：void Uart0_Printf(const char *fmt,...)
    *参数说明：可变参数
    *返 回 值：无
    *全局变量: 无
    *功    能：将()的内容通过串口发送并在PC机显示                
    ************************************************/
    void Uart0_Printf(const char *fmt,...)
    {
       va_list ap;                   //定义了一个指向可变参数列表指针
       char string[50];          //存储要发送的内容

       va_start(ap,fmt);     //是参数列表指针ap指向函数参数列表中的第一个可变参数
       vsprintf(string,fmt,ap);
       va_end(ap);              //清空参数列表
       Uart0_SendString(string);   //将该缓冲区中的数据打印到串口中
    }
