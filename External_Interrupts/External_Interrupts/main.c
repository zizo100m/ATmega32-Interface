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
    ExtInterrupt_Enable(EXT_INT0, RISING_EDGE_MODE);
	GlobaleInterrupts_StateSet(GLOBAL_INTERRUPTS_ENABLE);
	Sw_init(SW1_2_DIR_REG, SW2);
	Led_Init(LED0_1_DIR_REG, LED0);
    while (1) 
    {
    }
}

