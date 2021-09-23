/*
 * Buzzer.h
 *
 * Created: 9/23/2021 8:20:01 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "ATmega32_Cfg.h"
#include "Dio.h"

#define BUZZER_DIR_REG    (PORTA_DIR_REG)
#define BUZZER_OUT_REG    (PORTA_OUT_REG)
#define BUZZER_PIN        (DIO_PIN3)

typedef enum
{
	BUZZER_OFF,
	BUZZER_ON	
}BuzzerStateEnum_t;


void Buzzer_Init(void);
void Buzzer_StateSet(BuzzerStateEnum_t state);


#endif /* BUZZER_H_ */