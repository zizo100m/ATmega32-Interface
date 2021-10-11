/*
 * External_Interrupts.c
 *
 * Created: 10/2/2021 9:02:47 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "Ext_Interrupts.h"
#include "Led.h"
#include "Sw.h"
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	/* Toggle LED */
	Led_StateSet(LED0_1_OUT_REG, LED0, LED_TOGGLE);
}

int main(void)
{
    Ext_Interrupts_Enable(EXT_INT0, EXT_INT_RISING_EDGE);
	Global_Interrupts_StateSet(GLOBAL_INT_ENABLE);
	Sw_init(SW1_2_DIR_REG, SW2);
	Led_Init(LED0_1_DIR_REG, LED0);
    while (1) 
    {
    }
}

