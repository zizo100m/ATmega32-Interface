/*
 * Twi.h
 *
 * Created: 11/8/2021 1:46:46 PM
 *  Author: Abdelaziz Moustafa
 */

#ifndef TWI_H_
#define TWI_H_

#include "Std_Types.h"
#include "Twi_Pcfg.h"

typedef enum
{
    TW_START = 0x08U,         // start has been sent
    TW_REP_START = 0x10U,     // repeated start
    TW_MT_SLA_W_ACK = 0x18U,  // Master transmit ( slave address + Write request ) to slave + Ack received from slave
    TW_MT_SLA_W_NACK = 0x20,  // Master transmit ( slave address + Write request ) to slave + No Ack received from slave
    TW_MT_SLA_R_ACK = 0x40U,  // Master transmit ( slave address + Read request ) to slave + Ack received from slave
	TW_MT_SLA_R_NACK = 0x48U, // Master transmit ( slave address + Read request ) to slave + No Ack received from slave
    TW_MT_DATA_ACK = 0x28U,   // Master transmit data and ACK has been received from Slave.
    TW_MT_DATA_W_NACK = 0x30, // Master transmit data and No ACK has been received from Slave.
    TW_MR_DATA_ACK = 0x50U,   // Master received data and send ACK to slave
    TW_MR_DATA_NACK = 0x58U   // Master received data but doesn't send ACK to slave 
} Twi_StatusType;

typedef enum
{
    TWI_PRESCALE1,
    TWI_PRESCALE4,
    TWI_PRESCALE16,
    TWI_PRESCALE64
} Twi_PrescalerType;

typedef enum
{
	TWI_STANDARD_SPEED    = 100000U,   // 100Kpbs
	TWI_FULL_SPEED        = 400000U,   // 400Kpbs
	TWI_FAST_SPEED        = 1000000U,  // 1Mbps
	TWI_HIGH_SPEED        = 3200000U,  // 3.2Mpbs
}Twi_SpeedType;

typedef enum
{
    TWI_INTERRUPT_DISABLE,
    TWI_INTERRUPT_ENABLE
} Twi_IntStateType;

typedef struct 
{
    Twi_PrescalerType Prescale;
    Twi_IntStateType IntState;
    Twi_SpeedType F_SCL;
} Twi_ConfigType;

void Twi_Init(const Twi_ConfigType *ConfigPtr);
void Twi_Start(void);
void Twi_Stop(void);
void Twi_Write(uint8 data);
uint8 Twi_ReadWithACK(void);
uint8 Twi_ReadWithNACK(void);
Twi_StatusType Twi_StatusGet(void);

extern const Twi_ConfigType gStrTwi_Configuration;

#endif /* TWI_H_ */