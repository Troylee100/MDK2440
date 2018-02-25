#define rGPBCON (*(volatile unsigned long*)0x56000010)
#define rGPBDAT (*(volatile unsigned long*)0x56000014)

#define Led1_On ~(1<<5)
#define Led1_Off (1<<5)

void Led_Port_Init(void);
void delay(int i);

int main(void)
{
	Led_Port_Init();
	while(1)
	{
		//Led1´ò¿ª
		rGPBDAT&=Led1_On;
		delay(10000);
		//Led1¹Ø±Õ
		rGPBDAT|=Led1_Off;
		delay(10000);
	}
}


void Led_Port_Init(void)
{
	//????GPB5???????
	rGPBCON &= ~(3<<10);
	rGPBCON |= (1<<10);
}

void delay(int t)
{
	int a,b;
	for(a = 0; a <= t; a++)
		for(b = 0; b <= 100; b++);
}
