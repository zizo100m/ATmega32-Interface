/*
 * Icu.c
 *
 * Created: 10/22/2021 1:11:22 AM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Icu.h"
#include "Atmega32_Cfg.h"
#include "Macros.h"

void Icu_Init(const Icu_ConfigType *ConfigPtr)
{
	/* !Comment: Configure ICP1/PD6 as i/p pin */
	SET_BIT(*PORTD_DIR_REG, ICU_ICP_PIN);
	switch(ConfigPtr->Channel)
	{
		case ICU_CHANNEL_0:
			/* !Comment: Clear Registers before applying configuration */
			*TIMER1_CTRL_A_REG = 0x00U;
			*TIMER1_CTRL_B_REG = 0x00U;
			/* !Comment: Apply configuration */
			switch(ConfigPtr->ActivationEdge)
			{
			case ICU_RISING_EDGE:
				SET_BIT(*TIMER1_CTRL_B_REG, ICU_INP_CAP_EDGE_SELECT_BIT);
				break;
			case ICU_FALLING_EDGE:
				CLEAR_BIT(*TIMER1_CTRL_B_REG, ICU_INP_CAP_EDGE_SELECT_BIT);
				break;
			default:
				break;
			}
			*TIMER1_CTRL_B_REG |= ConfigPtr->Prescale;
			/* !Comment: Initial Value for Timer1 */
			*(uint16 *)TIMER1_COUNTER_LOW_REG = 0x00U;
			/* !Comment: Initial Value for the input capture register */
			*(uint16 *)TIMER1_INP_CAP_LOW_REG = 0x00U;
			/* !Comment: Set The interrupt State */
			*TIMER_INT_MASK_REG |= (ConfigPtr->IntState << ICU_INT_ENABLE_BIT);
			break;
		default:
			break;
	}
}

void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
	switch(Channel)
	{
		case ICU_CHANNEL_0:
		switch(Activation)
		{
		case ICU_RISING_EDGE:
			SET_BIT(*TIMER1_CTRL_B_REG, ICU_INP_CAP_EDGE_SELECT_BIT);
			break;
		case ICU_FALLING_EDGE:
			CLEAR_BIT(*TIMER1_CTRL_B_REG, ICU_INP_CAP_EDGE_SELECT_BIT);
			break;
		default:
			break;
		}
		break;
		default:
		break;
	}
}

void Icu_ClearTimerValue(void)
{
	*(uint16 *)TIMER1_COUNTER_LOW_REG = 0x00U;
}

Icu_ValueType Icu_GetInputCaptureValue(void)
{
	Icu_ValueType u16LocalInpCapValue;
	u16LocalInpCapValue = *(uint16 *)TIMER1_INP_CAP_LOW_REG;
	return (u16LocalInpCapValue);
}

ICU_StatusType ICU_StatusGet(Icu_ChannelType Channel)
{
	ICU_StatusType enuLocalIcuStatus = ICU_STATUS_RUNNING;
	switch(Channel)
	{
		case ICU_CHANNEL_0:

			if (READ_BIT(*TIMER_INT_FLAG_REG, ICU_INP_CAP_FLAG))
			{
				enuLocalIcuStatus = ICU_STATUS_EVENT_CAP;
				/* !Comment: Clear The ICF1 bit */
				SET_BIT(*TIMER_INT_FLAG_REG, ICU_INP_CAP_FLAG);
			}
			else
			{
				/* Do Nothing */
			}
			break;

		default:
			break;
	}
	return (enuLocalIcuStatus);
}

void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues)
{
	Icu_ValueType u16ValueAtStartFirstRising = 0U;
	Icu_ValueType u16ValueAtStartFalling = 0U;
	Icu_ValueType u16ValueAtStartSecondRising = 0U;

	switch(Channel)
	{
		case ICU_CHANNEL_0:
			/* !Comment: Clear The ICF1 bit */
			SET_BIT(*TIMER_INT_FLAG_REG, ICU_INP_CAP_FLAG);
			Icu_ClearTimerValue();

			Icu_SetActivationCondition(ICU_CHANNEL_0, ICU_RISING_EDGE);
			while(ICU_StatusGet(ICU_CHANNEL_0) != ICU_STATUS_EVENT_CAP)
			{
				/* Do Nothing */
			}
			u16ValueAtStartFirstRising = Icu_GetInputCaptureValue();

			Icu_SetActivationCondition(ICU_CHANNEL_0, ICU_FALLING_EDGE);
			while(ICU_StatusGet(ICU_CHANNEL_0) != ICU_STATUS_EVENT_CAP)
			{
				/* Do Nothing */
			}
			u16ValueAtStartFalling = Icu_GetInputCaptureValue();

			Icu_SetActivationCondition(ICU_CHANNEL_0, ICU_RISING_EDGE);
			while(ICU_StatusGet(ICU_CHANNEL_0) != ICU_STATUS_EVENT_CAP)
			{
				/* Do Nothing */
			}
			u16ValueAtStartSecondRising = Icu_GetInputCaptureValue();

			/* !Comment: Check for valid condition, to avoid timer overflow reading */
			if((u16ValueAtStartFirstRising < u16ValueAtStartFalling) && (u16ValueAtStartFalling < u16ValueAtStartSecondRising))
			{
				DutyCycleValues->ActiveTime = u16ValueAtStartFalling - u16ValueAtStartFirstRising;
				DutyCycleValues->PeriodTime = u16ValueAtStartSecondRising - u16ValueAtStartFirstRising;
			}
			else
			{
				/* Do Nothing */
			}
			break;

		default:
			break;
	}

}
