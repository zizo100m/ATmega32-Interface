/*
 * Led.h
 *
 * Created: 9/12/2021 10:36:11 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef LED_H_
#define LED_H_

#include "Dio.h"
#include "ATmega32_Cfg.h"
 
#define LED0_1_DIR_REG      (PORTC_DIR_REG)
#define LED0_1_OUT_REG      (PORTC_OUT_REG)

#define LED2_DIR_REG        (PORTD_DIR_REG)
#define LED2_OUT_REG        (PORTD_OUT_REG)

typedef enum
{
	LED_OFF,
	LED_ON,
	LED_TOGGLE,
}LedStateEnum_t;

typedef enum
{
	LED0 = DIO_PIN2,
	LED1 = DIO_PIN7,
	LED2 = DIO_PIN3	
}LedEnum_t;

void Led_Init(volatile uint8 *Led_reg, LedEnum_t Led_no);
void Led_StateSet(volatile uint8 *Led_reg, LedEnum_t Led_no, LedStateEnum_t state);



#endif /* LED_H_ */