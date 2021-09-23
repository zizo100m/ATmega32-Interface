/*
 * Led.h
 *
 * Created: 9/12/2021 10:36:11 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef LED_H_
#define LED_H_

#include "Dio.h"

typedef enum
{
	LED_OFF,
	LED_ON,
	LED_TOGGLE,
}LedStateEnum_t;

typedef enum
{
	LED0,
	LED1,
	LED2	
}LedEnum_t;

void Led_Init(volatile uint8 *Led_reg, LedEnum_t Led_no);
void Led_StateSet(volatile uint8 *Led_reg, LedEnum_t Led_no, LedStateEnum_t state);



#endif /* LED_H_ */