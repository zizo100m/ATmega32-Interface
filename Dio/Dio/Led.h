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

typedef struct
{
	DioPortEnum_t Led_Port;
	DioPinEnum_t  Led_Pin;
	
}LedStr_t;

void Led_Init(LedStr_t *Led);
void Led_StateSet(LedStr_t *Led, LedStateEnum_t state);

extern LedStr_t aStr_KitLeds[3];

#endif /* LED_H_ */