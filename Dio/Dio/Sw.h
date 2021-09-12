/*
 * Sw.h
 *
 * Created: 9/12/2021 9:25:14 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Dio.h"

#ifndef SW_H_
#define SW_H_


typedef enum
{
	SW_RELEASED,
	SW_PRESSED	
}Sw_StateEnum_t;

typedef struct
{
	DioPortEnum_t Sw_Port;
	DioPinEnum_t Sw_Pin;
	DioPinStateEnum_t Sw_PrevState;
}SwStr_t;

void Sw_init(SwStr_t *Sw);
Sw_StateEnum_t Sw_StateGet(SwStr_t *Sw);


extern SwStr_t aStr_KitSwitchs[3];

#endif /* SW_H_ */