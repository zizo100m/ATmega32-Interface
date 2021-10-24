/*
 * TempSensor.h
 *
 * Created: 10/7/2021 11:46:31 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#include "Adc.h"

#define TEMP_SENSOR_PIN                (ADC_CHANNEL_0)

#define ADC_TEN_BIT_PRECISION          (1024U)
#define ADC_EIGHT_BIT_PRECISION        (256U)
#define ADC_5_VOLT_REF                 (5.0)
#define ADC_3_3V_VOLT_REF              (3.3)

void TempSensor_Init(void);
uint8 TempSensor_ValueGet(void);



#endif /* TEMPSENSOR_H_ */