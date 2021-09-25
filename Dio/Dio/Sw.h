/*
 * Sw.h
 *
 * Created: 9/12/2021 9:25:14 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Dio.h"

#ifndef SW_H_
#define SW_H_

#define SW0_DIR_REG   (PORTB_DIR_REG)
#define SW0_INP_REG   (PORTB_INP_REG)

#define SW1_2_DIR_REG (PORTD_DIR_REG)
#define SW1_2_INP_REG (PORTD_INP_REG)

typedef enum
{
	SW_RELEASED,
	SW_PRESSED	
}Sw_StateEnum_t;

typedef enum   
{
	SW0 = DIO_PIN0,
	SW1 = DIO_PIN6,
	SW2	= DIO_PIN2
}SwEnumt_t;

void Sw_init(volatile uint8 *Sw_Reg, SwEnumt_t Sw_no);
Sw_StateEnum_t Sw_StateGet(volatile uint8 *Sw_Reg, SwEnumt_t Sw_no);


#endif /* SW_H_ */