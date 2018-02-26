#ifndef UART_H
#define UART_H
extern void Uart0_Init(unsigned int baudrate);
extern void putc(unsigned char c);
extern unsigned char getc(void);
extern void Uart0_Printf(const char *fmt, ...);

#endif  //UART_H