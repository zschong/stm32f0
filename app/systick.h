#ifndef __SYSTICK_H__
#define __SYSTICK_H__
#include "stm32f0xx.h"
#include "stm32f0xx_conf.h"

uint32_t SystickConfig(void);
uint32_t GetTimeTick(void);
uint32_t GetTimeSecond(void);
uint32_t MTimeout(uint32_t *last, uint32_t ms);
uint32_t Timeout(uint32_t *last, uint32_t s);
void msleep(uint32_t ms);
void sleep(uint32_t s);

#endif//__SYSTICK_H__
