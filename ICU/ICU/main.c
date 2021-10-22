/*
 * ICU.c
 *
 * Created: 10/22/2021 1:09:39 AM
 * Author : Abdelaziz Moustafa
 */ 

#include "Icu.h"
#include "LCD.h"
#include <util/delay.h>

int main(void)
{
	Icu_Init(&gStrIcu_Configuration);
	LCD_Init();
	Icu_DutyCycleType u16LocalDutyValues;
	uint8 u8LocalDutyCyle = 0;
    while (1) 
    {
		Icu_GetDutyCycleValues(ICU_CHANNEL_0, &u16LocalDutyValues);
		u8LocalDutyCyle = ((float32)u16LocalDutyValues.ActiveTime / (float32)u16LocalDutyValues.PeriodTime) * 100U; 
		LCD_IntegerDisplay(u8LocalDutyCyle);
		_delay_ms(200);
		LCD_Clear();
    }
}

