/*
 * Uart.c
 *
 * Created: 10/21/2021 4:51:05 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "uart.h"
#include "LCD.h"
#include "ATmega32_Cfg.h"
#include <util/delay.h>

int main(void)
{
	LCD_Init();
	Uart_Init(&gStrUart_Configuration);
	uint8 u8LocalVar;
    while (1) 
    {
		Uart_Receive(&u8LocalVar);
		LCD_CharDisplay(u8LocalVar);
		_delay_ms(1000U);
    }
}

