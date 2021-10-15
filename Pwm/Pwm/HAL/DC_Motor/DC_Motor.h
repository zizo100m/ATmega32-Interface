/*
 * DC_Motor.h
 *
 * Created: 10/15/2021 1:30:05 AM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Dio.h"
#include "ATmega32_Cfg.h"


#define DC_MOTOR_DIR_REG        (PORTC_DIR_REG)
#define DC_MOTOR_OUT_REG        (PORTC_OUT_REG)
#define DC_MOTOR_IN1_PIN        (DIO_PIN5)
#define DC_MOTOR_IN2_PIN        (DIO_PIN6)

#define DC_MOTOR_EN_DIR_REG     (PORTD_DIR_REG)
#define DC_MOTOR_EN_PIN         (DIO_PIN5)

typedef enum
{
	DC_MOTOR_TURN_CW,
	DC_MOTOR_TURN_CCW
}DcMotor_RotationDirType;

typedef enum
{
	DC_MOTOR_SPEED_LOW,
	DC_MOTOR_SPEED_MID,
	DC_MOTOR_SPEED_HIGH
}DcMotor_SpeedType;

void DcMotor_Init(void);
void DcMotor_Control(DcMotor_RotationDirType Dir, DcMotor_SpeedType Speed);

#endif /* DC_MOTOR_H_ */