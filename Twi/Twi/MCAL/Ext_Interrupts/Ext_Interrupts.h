/*
 * Ext_Interrupts.h
 *
 * Created: 10/8/2021 4:03:50 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef EXT_INTERRUPTS_H_
#define EXT_INTERRUPTS_H_

#define INT0_MODE_SEL_BIT0			  (0U)
#define INT0_MODE_SEL_BIT1			  (1U)
#define INT1_MODE_SEL_BIT0			  (2U)
#define INT1_MODE_SEL_BIT1			  (3U)
#define INT2_MODE_SEL_BIT			  (6U)

#define INT0_SOURCE_ENABLE_BIT		  (6U)
#define INT1_SOURCE_ENABLE_BIT		  (7U)
#define INT2_SOURCE_ENABLE_BIT		  (5U)

#define GLOBAL_INTERRUPTS_ENABLE_BIT  (7U)

typedef enum
{
	GLOBAL_INT_DISABLE,
	GLOBAL_INT_ENABLE	
}GlobalInt_StateEnum_t;

typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2
}Ext_InterruptSourceEnum_t;

typedef enum
{
	EXT_INT_LOW_LEVEL,
	EXT_INT_FALLING_EDGE,
	EXT_INT_RISING_EDGE,
	EXT_INT_BOTH_EDGES
}Ext_InterruptModeEnum_t;

void Ext_Interrupts_Enable(Ext_InterruptSourceEnum_t Source, Ext_InterruptModeEnum_t Mode);
void EXT_Interrupts_Disable(Ext_InterruptSourceEnum_t Source);
void Global_Interrupts_StateSet(GlobalInt_StateEnum_t State);
#endif /* EXT_INTERRUPTS_H_ */