/*
 * StepperMotor.c
 *
 * Created: 10/2/2021 2:55:25 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "StepperMotor.h"
#include "Std_Types.h"
#include <util/delay.h>

#define STEPPER_MOTOR_COILS_NUM    (4U)

#if STEPPER_UPPER_PORT
uint8 gau8StepperRotation[STEPPER_MOTOR_COILS_NUM] = {0x10U, 0x20U, 0x40U, 0x80U};
#else
uint8 gau8StepperRotation[STEPPER_MOTOR_COILS_NUM] = {0x01U, 0x02U, 0x04U, 0x08U};
#endif		

void StepperMotor_Init(void)
{
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN1_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN2_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN3_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN4_PIN, DIO_OUTPUT);
}
void StepperMotor_TurnCW(void)
{
	uint8 u8LocalLoopIndex;
	for (u8LocalLoopIndex = 0U; u8LocalLoopIndex < STEPPER_MOTOR_COILS_NUM; u8LocalLoopIndex++)
	{
#if STEPPER_UPPER_PORT
		*STEPPER_MOTOR_OUT_REG &= 0x0FU;
#else
		*STEPPER_MOTOR_OUT_REG &= 0xF0U;
#endif
		*STEPPER_MOTOR_OUT_REG |= gau8StepperRotation[u8LocalLoopIndex]; 
		_delay_ms(STEPPER_MOTOR_STEP_DELAY_MS);
	}
}
void StepperMotor_TurnCCW(void)
{
	sint8 s8LocalLoopIndex;
	for (s8LocalLoopIndex = (STEPPER_MOTOR_COILS_NUM -1U) ;s8LocalLoopIndex >=0 ; s8LocalLoopIndex--)
	{
#if STEPPER_UPPER_PORT
		*STEPPER_MOTOR_OUT_REG &= 0x0FU;
#else
		*STEPPER_MOTOR_OUT_REG &= 0xF0U;
#endif
		*STEPPER_MOTOR_OUT_REG |= gau8StepperRotation[s8LocalLoopIndex];
		_delay_ms(STEPPER_MOTOR_STEP_DELAY_MS);
	}
}