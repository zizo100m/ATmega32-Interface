/*
 * Ext_Interrupts.c
 *
 * Created: 10/8/2021 4:04:12 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Ext_Interrupts.h"
#include "Macros.h"
#include "ATmega32_Cfg.h"

static void Ext_Interrupt_ModeSet(Ext_InterruptModeEnum_t Mode, uint8 bit0, uint8 bit1);

void Ext_Interrupts_Enable(Ext_InterruptSourceEnum_t Source, Ext_InterruptModeEnum_t Mode)
{
	switch(Source)
	{
		case EXT_INT0:
		/* !Comment: Configured INT0 Mode */
		Ext_Interrupt_ModeSet(Mode, INT0_MODE_SEL_BIT0, INT0_MODE_SEL_BIT1);
		/* !Comment: Enable INTO Source */
		SET_BIT(*GENRAL_INT_CTRL_REG, INT0_SOURCE_ENABLE_BIT);
		break;
		case EXT_INT1:
		/* !Comment: Configured INT1 Mode */
		Ext_Interrupt_ModeSet(Mode, INT1_MODE_SEL_BIT0, INT1_MODE_SEL_BIT1);
		/* !Comment: Enable INT1 Source */
		SET_BIT(*GENRAL_INT_CTRL_REG, INT1_SOURCE_ENABLE_BIT);
		break;
		case EXT_INT2:
		/* !Comment: Configured INT2 Mode */
		switch(Mode)
		{
			case EXT_INT_FALLING_EDGE:
			CLEAR_BIT(*MCU_CTRL_STATUS_REG, INT2_MODE_SEL_BIT);
			break;
			case EXT_INT_RISING_EDGE:
			SET_BIT(*MCU_CTRL_STATUS_REG, INT2_MODE_SEL_BIT);
			break;
			default:
			break;
		}
		/* !Comment: Enable INT2 Source */
		SET_BIT(*GENRAL_INT_CTRL_REG, INT2_SOURCE_ENABLE_BIT);
		break;
		default:
		break;
	}
}

void EXT_Interrupts_Disable(Ext_InterruptSourceEnum_t Source)
{
	switch(Source)
	{
		case EXT_INT0:
		CLEAR_BIT(*GENRAL_INT_CTRL_REG, INT0_SOURCE_ENABLE_BIT);
		break;
		case EXT_INT1:
		CLEAR_BIT(*GENRAL_INT_CTRL_REG, INT1_SOURCE_ENABLE_BIT);
		break;
		case EXT_INT2:
		CLEAR_BIT(*GENRAL_INT_CTRL_REG, INT2_SOURCE_ENABLE_BIT);
		break;
		default:
		break;
	}
}
void Global_Interrupts_StateSet(GlobalInt_StateEnum_t State)
{
	switch(State)
	{
		case GLOBAL_INT_DISABLE:
		CLEAR_BIT(*AVR_STATUS_REG, GLOBAL_INTERRUPTS_ENABLE_BIT);
		break;
		case GLOBAL_INT_ENABLE:
		SET_BIT(*AVR_STATUS_REG, GLOBAL_INTERRUPTS_ENABLE_BIT);
		break;
		default:
		break;
	}
}

static void Ext_Interrupt_ModeSet(Ext_InterruptModeEnum_t Mode, uint8 bit0, uint8 bit1)
{
	switch(Mode)
	{
		case EXT_INT_LOW_LEVEL:
		CLEAR_BIT(*MCU_CTRL_REG, bit0);
		CLEAR_BIT(*MCU_CTRL_REG, bit1);
		break;
		case EXT_INT_FALLING_EDGE:
		CLEAR_BIT(*MCU_CTRL_REG, bit0);
		SET_BIT(*MCU_CTRL_REG, bit1);
		break;
		case EXT_INT_RISING_EDGE:
		SET_BIT(*MCU_CTRL_REG, bit0);
		SET_BIT(*MCU_CTRL_REG, bit1);
		break;
		case EXT_INT_BOTH_EDGES:
		SET_BIT(*MCU_CTRL_REG, bit0);
		CLEAR_BIT(*MCU_CTRL_REG, bit1);
		break;
		default:
		break;
	}
}