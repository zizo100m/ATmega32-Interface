/*
 * Ext_Interrupts.h
 *
 * Created: 10/2/2021 9:08:17 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef EXT_INTERRUPTS_H_
#define EXT_INTERRUPTS_H_


typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2	
}ExtInterruptSourceEnum_t;

typedef enum
{
	RISING_EDGE_MODE,
	FALLING_EDGE_MODE,
	EDGE_TRIGGER_MODE,
	LOW_LEVEL_MODE	
}ExtInterruptModeEnum_t;

typedef enum
{
	GLOBAL_INTERRUPTS_DISABLE,
	GLOBAL_INTERRUPTS_ENABLE	
}GlobalInterruptsStateEnum_t;

#define INT0_ISC00					  (0U)
#define INT0_ISC01					  (1U)
#define INT1_ISC10					  (2U)
#define INT1_ISC11					  (3U)
#define INT2_ISC2					  (6U)

#define INT0_ENABLE_BIT				  (6U)
#define INT1_ENABLE_BIT				  (7U)
#define INT2_ENABLE_BIT				  (5U)
#define GLOBALE_INTERRUPTS_ENABLE_BIT (7U)

void ExtInterrupt_Enable(ExtInterruptSourceEnum_t Source, ExtInterruptModeEnum_t Mode);
void ExtInterrupt_Disable(ExtInterruptSourceEnum_t Source);
void GlobaleInterrupts_StateSet(GlobalInterruptsStateEnum_t State);


#endif /* EXT_INTERRUPTS_H_ */