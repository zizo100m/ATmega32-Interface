/*
 * Pwm.c
 *
 * Created: 10/14/2021 11:20:54 PM
 * Author : Abdelaziz Moustafa
 */ 


#include "DC_Motor.h"

int main(void)
{
	DcMotor_Init();
	while (1)
	{
		DcMotor_Control(DC_MOTOR_TURN_CW, DC_MOTOR_SPEED_MID);
	}
}

