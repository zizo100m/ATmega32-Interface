/*
 * Ext_Interrupts.c
 *
 * Created: 10/2/2021 9:08:42 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Ext_Interrupts.h"
#include "ATmega32_Cfg.h"
#include "Macros.h"

void ExtInterrupt_Enable(ExtInterruptSourceEnum_t Source, ExtInterruptModeEnum_t Mode)
{
	switch(Source)
	{
		case EXT_INT0:
		/* 1- Configure INT0 Mode  */
		switch(Mode)
		{
			case LOW_LEVEL_MODE:
			CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC00);
			CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC01);
			break;
			case EDGE_TRIGGER_MODE:
			SET_BIT(*MCU_CTRL_REG, INT0_ISC00);
			CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC01);
			break;
			case FALLING_EDGE_MODE:
			CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC00);
			SET_BIT(*MCU_CTRL_REG, INT0_ISC01);
			break;
			case RISING_EDGE_MODE:
			SET_BIT(*MCU_CTRL_REG, INT0_ISC00);
			SET_BIT(*MCU_CTRL_REG, INT0_ISC01);
			break;
			default:
			break;
		}
		/* 2 - Enable INT0 */
		SET_BIT(*GENRAL_INT_CTRL_REG, INT0_ENABLE_BIT); 
		break;
		case EXT_INT1:
		/* 1 - Configure INT1 Mode */
		switch(Mode)
		{
			case LOW_LEVEL_MODE:
			CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC10);
			CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC11);
			break;
			case EDGE_TRIGGER_MODE:
			SET_BIT(*MCU_CTRL_REG, INT1_ISC10);
			CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC11);
			break;
			case FALLING_EDGE_MODE:
			CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC10);
			SET_BIT(*MCU_CTRL_REG, INT1_ISC11);
			break;
			case RISING_EDGE_MODE:
			SET_BIT(*MCU_CTRL_REG, INT1_ISC10);
			SET_BIT(*MCU_CTRL_REG, INT1_ISC11);
			break;
			default:
			break;
		}
		/* 2 - Enable INT1  */
		SET_BIT(*GENRAL_INT_CTRL_REG, INT1_ENABLE_BIT);
		break;
		case EXT_INT2:
		/* 1 - COnfigure IN2 Mode */
		switch(Mode)
		{
			case FALLING_EDGE_MODE:
			CLEAR_BIT(*MCU_CTRL_STATUS_REG, INT2_ISC2);
			break;
			case RISING_EDGE_MODE:
			SET_BIT(*MCU_CTRL_STATUS_REG, INT2_ISC2);
			break;
			default:
			break;
		}
		break;
		/* 2- Enable INT2 */
		SET_BIT(*GENRAL_INT_CTRL_REG, INT2_ENABLE_BIT);
		default:
		break;
	}
}
void ExtInterrupt_Disable(ExtInterruptSourceEnum_t Source)
{
	switch(Source)
	{
		case EXT_INT0:
		CLEAR_BIT(*GENRAL_INT_CTRL_REG, INT0_ENABLE_BIT);
		break;
		case EXT_INT1:
		CLEAR_BIT(*GENRAL_INT_CTRL_REG, INT1_ENABLE_BIT);
		break;
		case EXT_INT2:
		CLEAR_BIT(*GENRAL_INT_CTRL_REG, INT2_ENABLE_BIT);
		break;
		default:
		break;
	}	
}
void GlobaleInterrupts_StateSet(GlobalInterruptsStateEnum_t State)
{
	switch(State)
	{
		case GLOBAL_INTERRUPTS_DISABLE:
		CLEAR_BIT(*AVR_STATUS_REG, GLOBALE_INTERRUPTS_ENABLE_BIT);
		break;
		case GLOBAL_INTERRUPTS_ENABLE:
		SET_BIT(*AVR_STATUS_REG, GLOBALE_INTERRUPTS_ENABLE_BIT);
		break;
		default:
		break;
	}
}