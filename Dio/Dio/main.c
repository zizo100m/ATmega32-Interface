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
#include "Buzzer.h"
#include <util/delay.h>


int main(void)
{
	Sw_init(PORTD_DIR_REG, SW2);
	Sw_init(PORTD_DIR_REG, SW1);
	Buzzer_Init();
	
    /* Replace with your application code */
    while (1) 
    {
		Sw_StateEnum_t  Sw2_State = Sw_StateGet(PORTD_INP_REG,SW2);
		Sw_StateEnum_t  Sw1_State = Sw_StateGet(PORTD_INP_REG,SW1);
		if(Sw2_State == SW_PRESSED)
		{
			Buzzer_StateSet(BUZZER_ON);
		}
		else if (Sw1_State == SW_PRESSED)
		{
			Buzzer_StateSet(BUZZER_OFF);
		}

    }
}

