/*
 * Uart_Lcfg.c
 *
 * Created: 10/21/2021 4:59:48 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Uart.h"

Uart_ConfigType gStrUart_Configuration =
{
	UART_CHANNEL_0,
	UART_ASYNCH_MODE,
	UART_NORMAL_MODE,
	UART_TX,
	UART_BAUD_9600,
	UART_8_DATA_BITS,
	UART_ONE_STOP_BIT,
	UART_PARITY_DISABLED,
	UART_INTERRUPT_DISABLE,
	UART_TX_ON_FALLING_RX_ON_RISING
};
