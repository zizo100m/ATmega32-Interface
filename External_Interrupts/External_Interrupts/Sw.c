/*
 * Sw.c
 *
 * Created: 9/12/2021 9:25:26 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Dio.h"
#include "Sw.h"
#include "ATmega32_Cfg.h"
#include <util/delay.h>

#define DEBOUNCE_PERIOD (20U)

DioPinStateEnum_t Sw_PrevState = SW_RELEASED;
void Sw_init(volatile uint8 *Sw_Reg, SwEnumt_t Sw_no)
{
	Dio_ChannelDirectionSet   (Sw_Reg, Sw_no, DIO_INPUT);
}
Sw_StateEnum_t Sw_StateGet(volatile uint8 *Sw_Reg, SwEnumt_t Sw_no)
{
	Sw_StateEnum_t LocalSwState = SW_RELEASED;
	
	if(Sw_PrevState != Dio_ChannelRead(Sw_Reg, Sw_no))
	{
		_delay_ms(DEBOUNCE_PERIOD);

		Sw_PrevState = Dio_ChannelRead(Sw_Reg, Sw_no);
		if (Sw_PrevState == DIO_HIGH)
		{
			LocalSwState = SW_PRESSED;
		}
		else
		{
			LocalSwState = SW_RELEASED;
		}
	}
	return LocalSwState;
}
