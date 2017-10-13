#include "gpio.h"
#include "systick.h"


static uint32_t timetick = 0;

uint32_t SystickConfig(void)
{
	return SysTick_Config(SystemCoreClock/1000);
}
uint32_t GetTimeTick(void)
{
	return timetick;
}
uint32_t GetTimeSecond(void)
{
	return timetick/1000;
}
uint32_t MTimeout(uint32_t *last, uint32_t ms)
{
	if( 0 == last )
	{
		return 0;
	}
	if( timetick - *last < ms )
	{
		return 0;
	}
	*last = timetick;
	return 1;
}
uint32_t Timeout(uint32_t *last, uint32_t ms)
{
	return MTimeout(last, ms * 1000);
}
void msleep(uint32_t ms)
{
	uint32_t last = timetick;
	while(timetick - last < ms);
}
void sleep(uint32_t s)
{
	msleep(s * 1000);
}
void SysTick_Handler(void)
{
	timetick++;
}
