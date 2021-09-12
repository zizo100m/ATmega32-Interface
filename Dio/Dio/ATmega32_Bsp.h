/*
 * ATmega32_Bsp.h
 *
 * Created: 9/12/2021 10:45:23 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef ATMEGA32_BSP_H_
#define ATMEGA32_BSP_H_

#include "Dio.h"

#define LED0_PORT  (DIO_PORTC)
#define LED0_PIN   (DIO_PIN2)

#define LED1_PORT  (DIO_PORTC)
#define LED1_PIN   (DIO_PIN7)

#define LED2_PORT  (DIO_PORTD)
#define LED2_PIN   (DIO_PIN3)

#define SW0_PORT  (DIO_PORTB)
#define SW0_PIN   (DIO_PIN0)

#define SW1_PORT  (DIO_PORTD)
#define SW1_PIN   (DIO_PIN6)

#define SW2_PORT  (DIO_PORTD)
#define SW2_PIN   (DIO_PIN2)


#endif /* ATMEGA32_BSP_H_ */