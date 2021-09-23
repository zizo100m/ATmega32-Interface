/*
 * SSD.h
 *
 * Created: 9/23/2021 3:18:29 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef SSD_H_
#define SSD_H_

#include "ATmega32_Cfg.h"
#include "Std_Types.h"
#include "Dio.h"

#define SSD_DATA_DIR_REG  (PORTA_DIR_REG)
#define SSD_DATA_OUT_REG  (PORTA_OUT_REG)

#define SSD_CTRL_DIR_REG  (PORTB_DIR_REG)
#define SSD_CTRL_OUT_REG  (PORTB_OUT_REG)

#define SSD1_EN           (DIO_PIN1)
#define SSD2_EN           (DIO_PIN2)

#define SSD_TYPE          (SSD_COMMON_CATHODE)

typedef enum
{
	SSD_COMMON_CATHODE,
	SSD_COMMON_ANODE	
}SSD_TypeEnum_t;

typedef enum
{
	ZERO = 0x00U,  ONE   = 0x10U,
	TWO  = 0x20U,  THREE = 0x30U,
	FOUR = 0x40U,  FIVE  = 0x50U,
	SIX  = 0x60U,  SEVEN = 0X70U,
	EIGHT= 0x80U,  NINE  = 0x90U,	
}SSD_LedsEnum_t;


void SSD_Init(void);
void SSD_NumberDisplay(SSD_LedsEnum_t Num, uint8 SSD_no);
void SSD_NumSet(uint16 Number);

extern const uint8 gau8SSD_arr[10];


#endif /* SSD_H_ */