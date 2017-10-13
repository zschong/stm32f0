
#include "main.h"
#include "gpio.h"
#include "delay.h"
#include "stdio.h"
#include "usart.h"

int main(void)
{
	SystickConfig();
	UsartConfig(USART1, 9600, 0, 8, 1);
	
	GpioInit(PA2, GPIO_Mode_OUT, GPIO_Speed_50MHz);
	GpioOn(PA2);

	GpioInit(PA8, GPIO_Mode_OUT, GPIO_Speed_50MHz);
	GpioOn(PA8);

	

	while(1)
	{
		uint8_t buf[] = {0xAA, 0xBB};
		for(int i = 0; i < 2; i++)
		{   
			USART_SendData(USART1, buf[i]);
			while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
		}
		GpioOn(PA2);
		msleep(100);
		GpioOff(PA2);
		msleep(100);
		printf("stm32f0\n ");
	}
}
