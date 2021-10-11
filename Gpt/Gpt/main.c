/*
 * Gpt.c
 *
 * Created: 10/11/2021 8:33:12 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "Gpt.h"
#include "Led.h"
#include "Ext_Interrupts.h"
#include <avr/interrupt.h>

#define ONE_SECOND_GPT_OVF_NUM   (244U)

volatile uint8 gu8GptCounter = 0;
ISR(TIMER0_OVF_vect)
{
	gu8GptCounter++;
}

ISR(TIMER1_COMPA_vect)
{
	Led_StateSet(LED0_1_OUT_REG, LED1, LED_TOGGLE);
}

int main(void)
{
    Gpt_Init(&gaStrGpt_Configuration[GPT_TIMER0]);	
	Gpt_Init(&gaStrGpt_Configuration[GPT_TIMER1]);
	Led_Init(LED0_1_DIR_REG, LED0);
	Led_Init(LED0_1_DIR_REG, LED1);
	Global_Interrupts_StateSet(GLOBAL_INT_ENABLE);
    while (1) 
    {
		if(gu8GptCounter >= ONE_SECOND_GPT_OVF_NUM)
		{
			Led_StateSet(LED0_1_OUT_REG, LED0, LED_TOGGLE);
			gu8GptCounter = 0U;
		}
    }
}

