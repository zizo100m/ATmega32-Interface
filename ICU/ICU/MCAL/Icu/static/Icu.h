/*
 * Icu.h
 *
 * Created: 10/22/2021 1:11:05 AM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef ICU_H_
#define ICU_H_

#include "Std_Types.h"
#include "Icu_Pcfg.h"

typedef uint16 Icu_ValueType;

typedef enum
{
	ICU_CHANNEL_0,
}Icu_ChannelType;

typedef enum
{
	ICU_NO_CLK_SOURCE,
	ICU_NO_PRESCALE,
	ICU_PRESCALE_8,
	ICU_PRESCALE_64,
	ICU_PRESCALE_256,
	ICU_PRESCALE_1024,
	ICU_EXT_CLK_T0_FALLING,
	ICU_EXT_CLK_T0_RISING
}Icu_PrescaleType;

typedef enum
{
	ICU_RISING_EDGE,
	ICU_FALLING_EDGE
}Icu_ActivationType;

typedef enum
{
	ICU_INTERRUPT_DISABLE,
	ICU_INTERRUPT_ENABLE
}Icu_InterruptType;

typedef enum
{
	ICU_STATUS_RUNNING,
	ICU_STATUS_EVENT_CAP
}ICU_StatusType;

typedef struct
{
	Icu_ValueType ActiveTime;
	Icu_ValueType PeriodTime;
}Icu_DutyCycleType;

typedef struct
{
	Icu_ChannelType    Channel;
	Icu_PrescaleType   Prescale;
	Icu_ActivationType ActivationEdge;
	Icu_InterruptType  IntState;
}Icu_ConfigType;

void Icu_Init(const Icu_ConfigType *ConfigPtr);
void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation);
void Icu_ClearTimerValue(void);
Icu_ValueType Icu_GetInputCaptureValue(void);
ICU_StatusType ICU_StatusGet(Icu_ChannelType Channel);
void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues);

extern const Icu_ConfigType gStrIcu_Configuration;

#endif /* ICU_H_ */
