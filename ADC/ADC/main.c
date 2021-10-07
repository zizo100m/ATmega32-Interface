/*
 * ADC.c
 *
 * Created: 10/7/2021 4:00:33 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "Adc.h"
#include "LCD.h"
#include "TempSensor.h"
#include <util/delay.h>

int main(void)
{
    TempSensor_Init();
	LCD_Init();
	uint8 u8TempReading = 0;
    while (1) 
    {
		u8TempReading = TempSensor_ValueGet();
		LCD_IntegerDisplay(u8TempReading);
		_delay_ms(500);
		LCD_Clear();
    }
}

