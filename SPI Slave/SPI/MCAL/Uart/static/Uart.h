/*
 * Uart.h
 *
 * Created: 10/21/2021 4:59:19 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef UART_H_
#define UART_H_

#include "Std_Types.h"
#include "Uart_Pcfg.h"

typedef enum
{
	UART_CHANNEL_0	
}Uart_ChannelType;

typedef enum
{
	UART_ASYNCH_MODE,
	UART_SYNCH_MODE
}Uart_OperModeType;

typedef enum
{
	UART_NORMAL_MODE,
	UART_DOUBLE_SPEED_MODE
}Uart_SpeedType;

typedef enum
{
	UART_5_DATA_BITS,
	UART_6_DATA_BITS,
	UART_7_DATA_BITS,
	UART_8_DATA_BITS,
	UART_9_DATA_BITS = 0x03U
}Uart_DataType;

typedef enum
{
	UART_ONE_STOP_BIT,
	UART_TWO_STOP_BITS
}Uart_StopBitsType;

typedef enum
{
	UART_PARITY_DISABLED,
	UART_EVEN_PARITY  = 0x02U,
	UART_ODD_PARITY
}Uart_ParityType;

typedef enum
{
	UART_TX_ON_RISING_RX_ON_FALLING,
	UART_TX_ON_FALLING_RX_ON_RISING
}Uart_PolarityType;

typedef enum
{
	UART_TX_RX_DISABLED,
	UART_TX,
	UART_RX,
	UART_TX_RX
}Uart_ModeType;

typedef enum
{
	UART_BAUD_2400		=2400U,
	UART_BAUD_4800		=4800U,
	UART_BAUD_9600		=9600U,
	UART_BAUD_14400		=14400U,
	UART_BAUD_19200		=19200U,
	UART_BAUD_28800		=28800U,
	UART_BAUD_38400		=38400U,
	UART_BAUD_57600		=57600U,
	UART_BAUD_76800		=76800U,
	UART_BAUD_115200	=115200U,
	UART_BAUD_230400	=230400U,
	UART_BAUD_250k		=250000U,
}Uart_BuadrateType;

typedef enum
{
	UART_INTERRUPT_DISABLE,
	UART_DATA_REG_EMPTY_INTERRUPT_ENABLE  = 0x20U,
	UART_TX_INTERRUPT_ENABLE              = 0x40U,
	UART_RX_INTERRUPT_ENABLE              = 0x80U,
	UART_TX_RX_INTERRUPT_ENABLE           = 0xC0U,
	UART_TX_RX_UDRE_INTERRUPT_ENABLE      = 0xE0U
}Uart_InterruptType;

typedef enum
{
	UART_BUSY,
	UART_TX_COMPLETE,
	UART_RX_COMPLETE
}Uart_StatusType;

typedef struct
{
	Uart_ChannelType  	Channel;
	Uart_OperModeType 	OperationMode;
	Uart_SpeedType      Speed;
	Uart_ModeType 	  	Mode;
	Uart_BuadrateType 	Baudrate;
	Uart_DataType     	DataBits;
	Uart_StopBitsType 	StopBits;
	Uart_ParityType   	Parity;
	Uart_InterruptType  IntState;
	Uart_PolarityType   ClkPolarity;   /* In case of Synchronous mode */
}Uart_ConfigType;

void Uart_Init(const Uart_ConfigType *ConfigPtr);
void Uart_Transmit(const uint8 Data);
void Uart_Receive(uint8 *ReceiveBuff);
void Uart_StringTransmit(const uint8 *Str);
void Uart_StringReceive(uint8 *ReceiveBuff);
Uart_StatusType Uart_StatusGet(Uart_ModeType Mode);



extern Uart_ConfigType gStrUart_Configuration;

#endif /* UART_H_ */
