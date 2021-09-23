/*
 * Buzzer.c
 *
 * Created: 9/23/2021 8:24:06 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Buzzer.h"

void Buzzer_Init(void)
{
	Dio_ChannelDirectionSet(BUZZER_DIR_REG, BUZZER_PIN, DIO_OUTPUT);
}
void Buzzer_StateSet(BuzzerStateEnum_t state)
{
	Dio_ChannelWrite(BUZZER_OUT_REG, BUZZER_PIN, state);
}