/*
 * Dio.c
 *
 * Created: 9/12/2021 7:07:52 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "ATmega32_Cfg.h"
#include "Dio.h"
#include "Macros.h"
#include "Sw.h"
#include "Led.h"
#include <util/delay.h>


int main(void)
{
	Led_Init(&aStr_KitLeds[0]);
	Sw_init(&aStr_KitSwitchs[1]);
	
    /* Replace with your application code */
    while (1) 
    {
		Sw_StateEnum_t SW1 = Sw_StateGet(&aStr_KitSwitchs[1]);
		if (SW1 == SW_PRESSED)
		{
			Led_StateSet(&aStr_KitLeds[0], LED_TOGGLE);
		}
    }
}

