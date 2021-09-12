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


void Sw_init(SwStr_t *Sw)
{
	Dio_ChannelDirectionSet(Sw->Sw_Port,Sw->Sw_Pin, DIO_INPUT);
	Sw->Sw_PrevState = Dio_ChannelRead(Sw->Sw_Port, Sw->Sw_Pin);
}
Sw_StateEnum_t Sw_StateGet(SwStr_t *Sw)
{
	Sw_StateEnum_t LocalSwState = SW_RELEASED;
	if(Sw->Sw_PrevState != Dio_ChannelRead(Sw->Sw_Port, Sw->Sw_Pin))
	{
		_delay_ms(DEBOUNCE_PERIOD);

		Sw->Sw_PrevState = Dio_ChannelRead(Sw->Sw_Port, Sw->Sw_Pin);
		if (Sw->Sw_PrevState == DIO_HIGH)
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
