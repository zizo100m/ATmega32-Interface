/*
 * Adc_Lcfg.c
 *
 * Created: 10/7/2021 4:32:48 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Adc.h"

const Adc_ConfigType gStrAdc_Configuration = 
{
	ADC_GROUP_0,
	ADC_REF_AVCC,
	ADC_CON_MODE_ONESHOT,
	ADC_PRESCALE_128,
	ADC_TEN_BIT,
	0U,  /* No trigger source */
	ADC_ALIGN_LEFT,
	ADC_INTERRUPT_DISABLE
};

