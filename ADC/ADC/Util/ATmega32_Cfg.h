/*
 * ATmega32_Cfg.h
 *
 * Created: 9/12/2021 9:35:26 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef ATMEGA32_CFG_H_
#define ATMEGA32_CFG_H_

#include "Std_Types.h"

#define  F_CPU 16000000U

#define PORTA_DIR_REG			((volatile uint8*)0x3AU)
#define PORTA_INP_REG			((volatile uint8*)0x39U)
#define PORTA_OUT_REG			((volatile uint8*)0x3BU)

#define PORTB_DIR_REG			((volatile uint8*)0x37U)
#define PORTB_INP_REG			((volatile uint8*)0x36U)
#define PORTB_OUT_REG			((volatile uint8*)0x38U)

#define PORTC_DIR_REG			((volatile uint8*)0x34U)
#define PORTC_INP_REG			((volatile uint8*)0x33U)
#define PORTC_OUT_REG			((volatile uint8*)0x35U)

#define PORTD_DIR_REG			((volatile uint8*)0x31U)
#define PORTD_INP_REG			((volatile uint8*)0x30U)
#define PORTD_OUT_REG			((volatile uint8*)0x32U)

/* External Interrupts Registers */
#define MCU_CTRL_REG			((volatile uint8*)0x55U)  /* MCUCR */
#define MCU_CTRL_STATUS_REG		((volatile uint8*)0x54U)  /* MCUCSR */
#define GENRAL_INT_CTRL_REG		((volatile uint8*)0x5BU)  /* GICR */
#define AVR_STATUS_REG			((volatile uint8*)0x5FU)  /* SREG */

/* ADC Registers    */
#define ADC_MUX_REG             ((volatile uint8*)0x27U)  /* ADMUX */
#define ADC_CTRL_STATUS_A_REG   ((volatile uint8*)0x26U)  /* ADCSRA */
#define ADC_DATA_HIGH_REG       ((volatile uint8*)0x25U)  /* ADCH */
#define ADC_DATA_LOW_REG        ((volatile uint8*)0x24U)  /* ADCL */

/* Special Function Registers */ 
#define SPECIAL_FUNC_IO_REG     ((volatile uint8*)0x50U)  /* SFIOR */
#endif /* ATMEGA32_CFG_H_ */