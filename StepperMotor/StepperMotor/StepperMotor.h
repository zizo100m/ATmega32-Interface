/*
 * StepperMotor.h
 *
 * Created: 9/30/2021 6:01:59 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

#include "ATmega32_Cfg.h"
#include "Dio.h"
#include "Std_Types.h"

#define STEPPER_MOTOR_DIR_REG         (PORTA_DIR_REG)
#define STEPPER_MOTOR_OUT_REG         (PORTA_OUT_REG)
#define STEPPER_MOTOR_IN1_PIN         (DIO_PIN4)
#define STEPPER_MOTOR_IN2_PIN         (DIO_PIN5)
#define STEPPER_MOTOR_IN3_PIN         (DIO_PIN6)
#define STEPPER_MOTOR_IN4_PIN         (DIO_PIN7)

#define STEPPER_STEP_DELAY_MS         (50U)

void StepperMotor_Init(void);
void StepperMotor_TurnCW(void);
void StepperMotor_TurnCCW(void);

#endif /* STEPPERMOTOR_H_ */