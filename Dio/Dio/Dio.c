/*
 * Dio.c
 *
 * Created: 9/12/2021 7:09:28 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Dio.h"
#include "Macros.h"
#include "Std_Types.h"
#include "ATmega32_Cfg.h"

void Dio_ChannelDirectionSet(DioPortEnum_t Port, DioPinEnum_t Channel, DioPinDirectionEnum_t Direction)
{
	volatile uint8 *pu8_LocalReg = NULL_PTR;
	switch (Port)
	{
		case DIO_PORTA:
		pu8_LocalReg = PORTA_DIR_REG;
		break;
		case DIO_PORTB:
		pu8_LocalReg = PORTB_DIR_REG;
		break;
		case DIO_PORTC:
		pu8_LocalReg = PORTC_DIR_REG;
		break;
		case DIO_PORTD:
		pu8_LocalReg = PORTD_DIR_REG;
		break;
		default:
		break;
	}
	switch(Direction)
	{
		case DIO_INPUT:
		CLEAR_BIT(*pu8_LocalReg,Channel);
		break;
		case DIO_OUTPUT:
		SET_BIT(*pu8_LocalReg,Channel);
		break;
		default:
		break;
	}
}
DioPinStateEnum_t Dio_ChannelRead(DioPortEnum_t Port, DioPinEnum_t Channel)
{
	volatile uint8 *pu8_LocalReg = NULL_PTR;
	switch (Port)
	{
		case DIO_PORTA:
		pu8_LocalReg = PORTA_INP_REG;
		break;
		case DIO_PORTB:
		pu8_LocalReg = PORTB_INP_REG;
		break;
		case DIO_PORTC:
		pu8_LocalReg = PORTC_INP_REG;
		break;
		case DIO_PORTD:
		pu8_LocalReg = PORTD_INP_REG;
		break;
		default:
		break;
	}	
	DioPinStateEnum_t u8LocalPinValue = READ_BIT(*pu8_LocalReg,Channel);
	return (u8LocalPinValue);
}
void Dio_ChannelWrite(DioPortEnum_t Port, DioPinEnum_t Channel, DioPinStateEnum_t State)
{
	volatile uint8 *pu8_LocalReg = NULL_PTR;
	switch (Port)
	{
		case DIO_PORTA:
		pu8_LocalReg = PORTA_OUT_REG;
		break;
		case DIO_PORTB:
		pu8_LocalReg = PORTB_OUT_REG;
		break;
		case DIO_PORTC:
		pu8_LocalReg = PORTC_OUT_REG;
		break;
		case DIO_PORTD:
		pu8_LocalReg = PORTD_OUT_REG;
		break;
		default:
		break;
	}	
	switch(State)
	{
		case DIO_LOW:
		CLEAR_BIT(*pu8_LocalReg,Channel);
		break;
		case DIO_HIGH:
		SET_BIT(*pu8_LocalReg,Channel);
		break;
		default:
		break;
	}	
}
void Dio_ChannelToggle(DioPortEnum_t Port, DioPinEnum_t Channel)
{
	volatile uint8 *pu8_LocalReg = NULL_PTR;
	switch (Port)
	{
		case DIO_PORTA:
		pu8_LocalReg = PORTA_OUT_REG;
		break;
		case DIO_PORTB:
		pu8_LocalReg = PORTB_OUT_REG;
		break;
		case DIO_PORTC:
		pu8_LocalReg = PORTC_OUT_REG;
		break;
		case DIO_PORTD:
		pu8_LocalReg = PORTD_OUT_REG;
		break;
		default:
		break;
	}
	TOGGLE_BIT(*pu8_LocalReg,Channel);
}
void Dio_PortWrite(DioPortEnum_t Port, uint8 Value)
{
	volatile uint8 *pu8_LocalReg = NULL_PTR;
	switch (Port)
	{
		case DIO_PORTA:
		pu8_LocalReg = PORTA_OUT_REG;
		break;
		case DIO_PORTB:
		pu8_LocalReg = PORTB_OUT_REG;
		break;
		case DIO_PORTC:
		pu8_LocalReg = PORTC_OUT_REG;
		break;
		case DIO_PORTD:
		pu8_LocalReg = PORTD_OUT_REG;
		break;
		default:
		break;
	}
	*pu8_LocalReg = Value;
}
uint8 Dio_PortRead(DioPortEnum_t Port)
{
	volatile uint8 *pu8_LocalReg = NULL_PTR;
	switch (Port)
	{
		case DIO_PORTA:
		pu8_LocalReg = PORTA_INP_REG;
		break;
		case DIO_PORTB:
		pu8_LocalReg = PORTB_INP_REG;
		break;
		case DIO_PORTC:
		pu8_LocalReg = PORTC_INP_REG;
		break;
		case DIO_PORTD:
		pu8_LocalReg = PORTD_INP_REG;
		break;
		default:
		break;
	}
	uint8 u8LocalPortValue = *pu8_LocalReg;
	return u8LocalPortValue;
}