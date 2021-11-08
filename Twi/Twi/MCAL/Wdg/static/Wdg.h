/*
 * Wdg.h
 *
 * Created: 10/21/2021 4:00:31 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef WDG_H_
#define WDG_H_

#define WDG_RESET_FLAG_BIT         (3U)
#define WDG_TURN_OFF_ENABLE_BIT    (4U)
#define WDG_ENABLE_BIT             (3U)

typedef enum
{
	WDG_TIMEOUT_16_3_MS,
	WDG_TIMEOUT_32_5_MS,
	WDG_TIMEOUT_65_MS,
	WDG_TIMEOUT_0_13_S,
	WDG_TIMEOUT_0_26_S,
	WDG_TIMEOUT_0_52_S,
	WDG_TIMEOUT_1_0_S,
	WDG_TIMEOUT_2_1_S,	
}Wdg_TimeoutType;

typedef enum
{
	WDG_DISABLE,
	WDG_ENABLE	
}Wdg_StateType;

typedef struct
{
	Wdg_StateType State;
	Wdg_TimeoutType Timeout;
}Wdg_ConfigType;

void Wdg_Init(const Wdg_ConfigType *ConfigPtr);
void Wdg_StateSet(Wdg_StateType State);
void Wdg_Trigger(void);

extern Wdg_ConfigType gStrWdg_Configuration;

#endif /* WDG_H_ */