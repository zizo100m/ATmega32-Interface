/*
 * StepperMotor.c
 *
 * Created: 10/2/2021 2:37:29 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "StepperMotor.h"
#include "Sw.h"

int main(void)
{
	StepperMotor_Init();
	Sw_init(SW1_2_DIR_REG, SW1);
	Sw_init(SW1_2_DIR_REG, SW2);
	while (1)
	{
		while(Sw_StateGet(SW1_2_INP_REG, SW1) == SW_PRESSED)
		{
			StepperMotor_TurnCW();
		}
		while(Sw_StateGet(SW1_2_INP_REG, SW2) == SW_PRESSED)
		{
			StepperMotor_TurnCCW();
		}
	}
}
