/*
 * Relay.c
 *
 * Created: 9/23/2021 8:41:52 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Relay.h"

void Relay_Init(void)
{
	Dio_ChannelDirectionSet(RELAY_DIR_REG, RELAY_PIN, DIO_OUTPUT);
}
void Relay_StateSet(RelayStateEnum_t state)
{
	Dio_ChannelWrite(RELAY_OUT_REG, RELAY_PIN, state);
}