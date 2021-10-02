/*
 * StepperMotor.h
 *
 * Created: 10/2/2021 2:54:49 PM
 *  Author: Abdelaziz Moustafa
 */ 



#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

#include "ATmega32_Cfg.h"
#include "Dio.h"

#define STEPPER_MOTOR_DIR_REG           (PORTA_DIR_REG)
#define STEPPER_MOTOR_OUT_REG           (PORTA_OUT_REG)

#define STEPPER_MOTOR_IN1_PIN           (DIO_PIN4)
#define STEPPER_MOTOR_IN2_PIN           (DIO_PIN5)
#define STEPPER_MOTOR_IN3_PIN           (DIO_PIN6)
#define STEPPER_MOTOR_IN4_PIN           (DIO_PIN7)

#define STEPPER_UPPER_PORT              (1U)   /* 1: Upper Port,  0: Lower Port */

#define STEPPER_MOTOR_STEP_DELAY_MS     (5U)

void StepperMotor_Init(void);
void StepperMotor_TurnCW(void);
void StepperMotor_TurnCCW(void);


#endif /* STEPPERMOTOR_H_ */