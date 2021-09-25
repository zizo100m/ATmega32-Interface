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
	Led_Init(LED2_DIR_REG, LED2);
	Sw_init(SW1_2_DIR_REG, SW2);
	
    /* Replace with your application code */
    while (1) 
    {
		Sw_StateEnum_t  Sw_State = Sw_StateGet(SW1_2_INP_REG,SW2);
		if(Sw_State == SW_PRESSED)
		{
			Led_StateSet(LED2_OUT_REG, LED2, LED_TOGGLE);
		}
		else
		{
			/* Do Nothing */
		}
		
		
    }
}

