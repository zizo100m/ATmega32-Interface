/*
 * Led.c
 *
 * Created: 9/12/2021 10:35:46 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Led.h"
#include "Dio.h"

void Led_Init(volatile uint8 *Led_reg, LedEnum_t Led_no)
{
	Dio_ChannelDirectionSet(Led_reg, Led_no, DIO_OUTPUT);
}
void Led_StateSet(volatile uint8 *Led_reg, LedEnum_t Led_no, LedStateEnum_t state)
{
	if (state == LED_TOGGLE)
	{
		Dio_ChannelToggle(Led_reg, Led_no);
	}
	else
	{
		Dio_ChannelWrite(Led_reg, Led_no, state);
	}
}