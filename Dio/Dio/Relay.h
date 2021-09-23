/*
 * Relay.h
 *
 * Created: 9/23/2021 8:40:24 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef RELAY_H_
#define RELAY_H_


#include "ATmega32_Cfg.h"
#include "Dio.h"

#define RELAY_DIR_REG    (PORTA_DIR_REG)
#define RELAY_OUT_REG    (PORTA_OUT_REG)
#define RELAY_PIN        (DIO_PIN2)

typedef enum
{
	RELAY_OFF,
	RELAY_ON
}RelayStateEnum_t;


void Relay_Init(void);
void Relay_StateSet(RelayStateEnum_t state);


#endif /* RELAY_H_ */