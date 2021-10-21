/*
 * Uart.c
 *
 * Created: 10/21/2021 4:51:05 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "uart.h"
#include "ATmega32_Cfg.h"
#include <util/delay.h>

int main(void)
{
	Uart_Init(&gStrUart_Configuration);
    while (1) 
    {
		Uart_StringTransmit("Hi!");
		_delay_ms(500);
    }
}

