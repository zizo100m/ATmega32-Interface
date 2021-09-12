/*
 * SW_Cfg.c
 *
 * Created: 9/12/2021 10:22:48 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Sw.h"
#include "ATmega32_Bsp.h"

SwStr_t aStr_KitSwitchs[3] = 
{
	{SW0_PORT, SW0_PIN, SW_RELEASED},
	{SW1_PORT, SW1_PIN, SW_RELEASED},
	{SW2_PORT, SW2_PIN, SW_RELEASED}	
};