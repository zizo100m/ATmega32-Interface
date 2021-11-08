/*
 * Wdg.c
 *
 * Created: 10/21/2021 4:00:44 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Wdg.h"
#include "Macros.h"
#include "ATmega32_Cfg.h"

static void Wdg_Disable(void);

void Wdg_Init(const Wdg_ConfigType *ConfigPtr)
{
	/* !Comment: Clear the register before applying the configuration */
	*WDG_CTRL_REG = 0x00U;
	/* !Comment: Apply the configuration */
	*WDG_CTRL_REG |= ConfigPtr->Timeout;
	switch(ConfigPtr->State)
	{
		case WDG_ENABLE:
		SET_BIT(*WDG_CTRL_REG, WDG_ENABLE_BIT);
		break;
		case WDG_DISABLE:
		Wdg_Disable();
		break;
		default:
		break;
	}
}
void Wdg_StateSet(Wdg_StateType State)
{
	switch(State)
	{
		case WDG_ENABLE:
		SET_BIT(*WDG_CTRL_REG, WDG_ENABLE_BIT);
		break;
		case WDG_DISABLE:
		Wdg_Disable();
		break;
		default:
		break;
	}	
}
void Wdg_Trigger(void)
{
	__asm__ __volatile__ ("wdr");
}

static void Wdg_Disable(void)
{
	SET_BIT(*WDG_CTRL_REG, WDG_ENABLE_BIT);
	SET_BIT(*WDG_CTRL_REG, WDG_TURN_OFF_ENABLE_BIT);
	
	CLEAR_BIT(*WDG_CTRL_REG, WDG_ENABLE_BIT);
}