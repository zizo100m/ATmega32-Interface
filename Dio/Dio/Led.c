/*
 * Led.c
 *
 * Created: 9/12/2021 10:35:46 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Led.h"
#include "Dio.h"

void Led_Init(LedStr_t *Led)
{
	Dio_ChannelDirectionSet(Led->Led_Port, Led->Led_Pin, DIO_OUTPUT);
	Dio_ChannelWrite(Led->Led_Port, Led->Led_Pin, DIO_LOW);
}
void Led_StateSet(LedStr_t *Led, LedStateEnum_t state)
{
	if (state == LED_TOGGLE)
	{
		Dio_ChannelToggle(Led->Led_Port, Led->Led_Pin);
	}
	else
	{
		Dio_ChannelWrite(Led->Led_Port, Led->Led_Pin, state);
	}
}