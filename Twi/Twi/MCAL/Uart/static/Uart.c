/*
 * Uart.c
 *
 * Created: 10/21/2021 4:59:32 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Uart.h"
#include "Atmega32_Cfg.h"
#include "Macros.h"
#include <avr/io.h>
void Uart_Init(const Uart_ConfigType *ConfigPtr)
{
	/* !Comment: Clear the registers before applying the configuration */
	*UART_CTRL_STATUS_A_REG = 0x00U;
	*UART_CTRL_STATUS_B_REG = 0x00U;
	*UART_CTRL_STATUS_C_REG = 0x00U;

	/* !Comment: Select to write on UCSRC by setting the register select bit */
	SET_BIT(*UART_CTRL_STATUS_C_REG, UART_REGISTER_SELECT_BIT);
	/* !Comment: Select the Operation Mode of the UART: Asynchronous/ Synchronous */
	*UART_CTRL_STATUS_C_REG |= (ConfigPtr->OperationMode << UART_MODE_SELECT_BIT);
	/* !Comment: Select Parity: Disabled / Odd / Even */
	*UART_CTRL_STATUS_C_REG |= (ConfigPtr->Parity << UART_PARITY_SELECT_BITS);
	/* !Comment: Select Data bits in UART frame: 5, 6, 7, 8, 9 bits */
	if(ConfigPtr->DataBits == UART_9_DATA_BITS)
	{
		SET_BIT(*UART_CTRL_STATUS_B_REG, UART_CHAR_SIZE_BIT);
	}
	else
	{
		/* Do Nothing */
	}
	*UART_CTRL_STATUS_C_REG |= (ConfigPtr->DataBits << UART_DATA_BITS_NUM);
	/* !Comment: Select the Clock polarity in case of Synchronous mode */
	if(ConfigPtr->OperationMode == UART_SYNCH_MODE)
	{
		*UART_CTRL_STATUS_C_REG |= ConfigPtr->ClkPolarity;
	}
	else
	{
		/* Do Nothing */
	}
	/* !Comment: Select UART Communication Type: Full-Duplex/Half-Duplex */
	*UART_CTRL_STATUS_B_REG |= (ConfigPtr->Mode << UART_COMM_TYPE_BIT);
	/* !Comment: Select UART Interrupt state */
	*UART_CTRL_STATUS_B_REG |= (ConfigPtr->IntState << UART_INT_STATE_BITS);
	/* !Comment: Select UART Speed: Normal Mode/Double Speed Mode */
	*UART_CTRL_STATUS_A_REG |= (ConfigPtr->Speed << UART_DOUBLE_SPEED_BIT);

	/* !Comment: Set the UART Baudrate */
	/* !Comment: Select to write on UBRRH by Clearing the register select bit */
	CLEAR_BIT(*UART_CTRL_STATUS_C_REG, UART_REGISTER_SELECT_BIT);
	/* !Comment: Set the UART Baudrate */
	switch(ConfigPtr->Speed)
	{
	case UART_NORMAL_MODE:
		*UART_BAUDRATE_HIGH_REG = (uint8)((uint16)(F_CPU/(16.0 * ConfigPtr->Baudrate) - 1) >> 8U);
		*UART_BAUDRATE_LOW_REG  = (uint8)(F_CPU/(16.0 * ConfigPtr->Baudrate) - 1 );
		break;
	case UART_DOUBLE_SPEED_MODE:
		*UART_BAUDRATE_HIGH_REG = ((uint16)(F_CPU/(8.0 * ConfigPtr->Baudrate) - 1) >> 8U);
		*UART_BAUDRATE_LOW_REG  = (uint8)(F_CPU/(8.0 * ConfigPtr->Baudrate) - 1);
		break;
	default:
		break;
	}

}

void Uart_Transmit(const uint8 Data)
{
	/* !Comment: Wait until the previous transmission is complete */
	while(Uart_StatusGet(UART_TX) != UART_TX_COMPLETE)
	{
		/* Do Nothing */
	}
	*UART_DATA_REG = Data;
}

void Uart_Receive(uint8 *ReceiveBuff)
{
	/* !Comment: Wait until the There is data received */
	while(Uart_StatusGet(UART_RX) != UART_RX_COMPLETE)
	{

	}
	*ReceiveBuff = *UART_DATA_REG;
}

void Uart_StringTransmit(const uint8 *Str)
{
	while(*Str != '\0')
	{
		Uart_Transmit(*Str);
	    Str++;
	}
}

void Uart_StringReceive(uint8 *ReceiveBuff)
{
	uint8 u8LocalIndex = 0U;
	Uart_Receive(&ReceiveBuff[u8LocalIndex]);
	while(ReceiveBuff[u8LocalIndex] != '\0')
	{
		u8LocalIndex++;
		Uart_Receive(&ReceiveBuff[u8LocalIndex]);
	}
	ReceiveBuff[u8LocalIndex] = '\0';
}

Uart_StatusType Uart_StatusGet(Uart_ModeType Mode)
{
	Uart_StatusType u8LocalUartState = UART_BUSY;
	switch(Mode)
	{
	case UART_TX:
		if(READ_BIT(*UART_CTRL_STATUS_A_REG, UART_DATA_REG_EMPTY_FLAG) == 1U)
		{
			u8LocalUartState = UART_TX_COMPLETE;
		}
		else
		{
			/* Do Nothing */
		}
		break;
	case UART_RX:
		if(READ_BIT(*UART_CTRL_STATUS_A_REG, UART_RX_COMPLETE_FLAG))
		{
			u8LocalUartState = UART_RX_COMPLETE;
		}
		else
		{
			/* Do Nothing */
		}
		break;
	default:
		break;
	}
	return (u8LocalUartState);
}
