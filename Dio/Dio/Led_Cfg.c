/*
 * Led_Cfg.c
 *
 * Created: 9/12/2021 10:35:59 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Led.h"
#include "ATmega32_Bsp.h"

LedStr_t aStr_KitLeds[3] = 
{
	{LED0_PORT, LED0_PIN},
	{LED1_PORT, LED1_PIN},
	{LED2_PORT, LED2_PIN}
};