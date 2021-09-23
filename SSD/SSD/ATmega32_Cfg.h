/*
 * ATmega32_Cfg.h
 *
 * Created: 9/12/2021 9:35:26 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef ATMEGA32_CFG_H_
#define ATMEGA32_CFG_H_


#define  F_CPU 16000000U

#define PORTA_DIR_REG      ((volatile uint8*)0x3AU)
#define PORTA_INP_REG      ((volatile uint8*)0x39U)
#define PORTA_OUT_REG      ((volatile uint8*)0x3BU)

#define PORTB_DIR_REG      ((volatile uint8*)0x37U)
#define PORTB_INP_REG      ((volatile uint8*)0x36U)
#define PORTB_OUT_REG      ((volatile uint8*)0x38U)

#define PORTC_DIR_REG      ((volatile uint8*)0x34U)
#define PORTC_INP_REG      ((volatile uint8*)0x33U)
#define PORTC_OUT_REG      ((volatile uint8*)0x35U)

#define PORTD_DIR_REG      ((volatile uint8*)0x31U)
#define PORTD_INP_REG      ((volatile uint8*)0x30U)
#define PORTD_OUT_REG      ((volatile uint8*)0x32U)


#endif /* ATMEGA32_CFG_H_ */