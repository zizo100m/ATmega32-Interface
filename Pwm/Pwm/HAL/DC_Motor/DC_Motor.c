/*
 * DC_Motor.c
 *
 * Created: 10/15/2021 1:30:21 AM
 *  Author: Abdelaziz Moustafa
 */ 

#include "DC_Motor.h"
#include "Pwm.h"

void DcMotor_Init(void)
{
	/* !Comment: Initialize the DC Motor direction selection Pins */
	Dio_ChannelDirectionSet(DC_MOTOR_DIR_REG, DC_MOTOR_IN1_PIN, DIO_OUTPUT);	
	Dio_ChannelDirectionSet(DC_MOTOR_DIR_REG, DC_MOTOR_IN2_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(DC_MOTOR_EN_DIR_REG, DC_MOTOR_EN_PIN, DIO_OUTPUT);
	/* !Comment: Initialize PWM module */
	Pwm_Init(&gStrPwm_Configuration[PWM_CHANNEL_1]);
}
void DcMotor_Control(DcMotor_RotationDirType Dir, DcMotor_SpeedType Speed)
{
	switch(Dir)
	{
		case DC_MOTOR_TURN_CW:
		Dio_ChannelWrite(DC_MOTOR_OUT_REG, DC_MOTOR_IN1_PIN, DIO_HIGH);
		Dio_ChannelWrite(DC_MOTOR_OUT_REG, DC_MOTOR_IN2_PIN, DIO_LOW);
		break;
		case DC_MOTOR_TURN_CCW:
		Dio_ChannelWrite(DC_MOTOR_OUT_REG, DC_MOTOR_IN1_PIN, DIO_LOW);
		Dio_ChannelWrite(DC_MOTOR_OUT_REG, DC_MOTOR_IN2_PIN, DIO_HIGH);
		break;		
		default:
		break;
	}	
	switch(Speed)
	{
		case DC_MOTOR_SPEED_LOW:
		Pwm_SetDutyCycle(PWM_CHANNEL_1, 20U);
		break;
		case DC_MOTOR_SPEED_MID:
		Pwm_SetDutyCycle(PWM_CHANNEL_1, 50U);
		break;
		case DC_MOTOR_SPEED_HIGH:
		Pwm_SetDutyCycle(PWM_CHANNEL_1, 90U);
		break;
		default:
		break;
	}
}

