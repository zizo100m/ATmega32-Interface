/*
 * StepperMotor.c
 *
 * Created: 9/30/2021 6:02:17 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "StepperMotor.h"
#include <util/delay.h>

#define STEPPER_MOTOR_STATES_NUM        (4U)

uint8 gau8StepperRotation_CW[4U]  = {0x10U, 0x20U, 0x40U, 0x80U};
uint8 gau8StepperRotation_CCW[4U] = {0x80U, 0x40U, 0x20U, 0x10U};	

void StepperMotor_Init(void)
{
	/* !Comment: Initialize the 4 pins of the Stepper Motor to be OUTPUT */
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN1_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN2_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN3_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN4_PIN, DIO_OUTPUT);
}

 void StepperMotor_TurnCW(void)
 {
	 uint8 u8LocalLoopIndex = 0;
	 for (u8LocalLoopIndex = 0; u8LocalLoopIndex < STEPPER_MOTOR_STATES_NUM; u8LocalLoopIndex++)
	 {
		 Dio_PortWrite(STEPPER_MOTOR_OUT_REG, gau8StepperRotation_CW[u8LocalLoopIndex]);
		 _delay_ms(STEPPER_STEP_DELAY_MS);
	 }
 }

 void StepperMotor_TurnCCW(void)
{
	uint8 u8LocalLoopIndex = 0;
	for (u8LocalLoopIndex = 0; u8LocalLoopIndex < STEPPER_MOTOR_STATES_NUM; u8LocalLoopIndex++)
	{
		Dio_PortWrite(STEPPER_MOTOR_OUT_REG, gau8StepperRotation_CCW[u8LocalLoopIndex]);
		_delay_ms(STEPPER_STEP_DELAY_MS);
	}
}
