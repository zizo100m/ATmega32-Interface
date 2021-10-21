/*
 * Wdt.c
 *
 * Created: 10/21/2021 3:25:27 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "Wdg.h"
#include "Led.h"
#include <util/delay.h>

int main(void)
{
	Led_Init(LED0_1_DIR_REG, LED0);
	Wdg_Init(&gStrWdg_Configuration);
	
	Led_StateSet(LED0_1_OUT_REG, LED0, LED_ON);
	_delay_ms(1000);
	Led_StateSet(LED0_1_OUT_REG, LED0, LED_OFF);
    while (1) 
    {
		Wdg_Trigger();
    }
}

