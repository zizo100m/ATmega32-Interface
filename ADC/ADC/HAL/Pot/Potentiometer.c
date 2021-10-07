/*
 * Potentiometer.c
 *
 * Created: 10/7/2021 10:40:54 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Potentiometer.h"

void Pot_Init(void)
{
	Adc_Init(&gStrAdc_Configuration);
}

uint16 Pot_ValueGet(void)
{
	Adc_ValueType u16LocalAdcReading = 0U;
	Adc_StartGroupConversion(ADC_GROUP_0);
	Adc_ReadChannel(POT_PIN, gStrAdc_Configuration.Resolution, &u16LocalAdcReading);
	return u16LocalAdcReading;
}