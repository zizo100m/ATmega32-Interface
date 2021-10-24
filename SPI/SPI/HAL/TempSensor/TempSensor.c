/*
 * TempSensor.c
 *
 * Created: 10/7/2021 11:46:56 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "TempSensor.h"

void TempSensor_Init(void)
{
	Adc_Init(&gStrAdc_Configuration);
}
uint8 TempSensor_ValueGet(void)
{
	Adc_ValueType u16LocalAdcReading = 0U;
	uint16 u16LocalAdcPrecision = 0U;
	uint8 u8LocalTemp = 0U;
	Adc_StartGroupConversion(ADC_GROUP_0);
	Adc_ReadChannel(TEMP_SENSOR_PIN, gStrAdc_Configuration.Resolution, &u16LocalAdcReading);
	switch(gStrAdc_Configuration.Resolution)
	{
		case ADC_TEN_BIT:
		u16LocalAdcPrecision = ADC_TEN_BIT_PRECISION;
		break;
		case ADC_EIGHT_BIT:
		u16LocalAdcPrecision = ADC_EIGHT_BIT_PRECISION;
		break;
		default:
		break;
	}
	/* !Comment: Temperature Sensor equation */
	u8LocalTemp = (((u16LocalAdcReading * ADC_5_VOLT_REF) / u16LocalAdcPrecision) * 100.0) ;
	
	return (u8LocalTemp);	
}
