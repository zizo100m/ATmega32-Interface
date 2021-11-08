/*
 * Adc.h
 *
 * Created: 10/7/2021 4:32:12 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "Std_Types.h"
#include "Adc_Pcfg.h"

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* !Comment: The Following Enumeration selects the ADC Group (Module) */
typedef enum
{
	ADC_GROUP_0
}Adc_GroupType;

/* !Comment: The Following Enumeration selects the channel of the ADC */
typedef enum
{
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7
}Adc_ChannelType;

/* !Comment: The Following Enumeration Define The Different Voltage Reference Modes in ADC 
 *		Note That if The Vin Exceeded The Vref This will Result in a Code 
 *		Equal to 0x3FF Or 0xFF Depending on Your Resolution 
 */
typedef enum
{
	ADC_REF_AREF				= 0x00U,
	ADC_REF_AVCC				= 0x40U, 
	ADC_REF_2_56V	            = 0xC0U
}Adc_RefType;

/* !Comment: in order to Work with 8-Bit Precision The Data Must Be Left Adjusted 
 *		then you should Read ADCH , ADLAR is Responsible for Adjusting 
 *		The Data to Right(0) or Left(1) 
 */ 
typedef enum
{
	ADC_EIGHT_BIT,
	ADC_TEN_BIT
}Adc_ResolutionType;

/* !Comment: The Following Enumeration selects the conversion mode of the ADC */
typedef enum
{
	ADC_CON_MODE_CONTINUOUS     = 0x00U,
	ADC_CON_MODE_ONESHOT        = 0x01U,
	ADC_CON_MODE_TRIGGER        = 0x02U 
}Adc_ConModeType;

/* !Comment: The Following Enumeration selects the trigger source of the ADC */
typedef enum
{
	ADC_ANALOG_COMPARATOR       = 0x20U,
	ADC_EXT_INTERRUPT0          = 0x40U,
	ADC_TIMER0_CMP_MATCH        = 0x60U,
	ADC_TIMER0_OVF              = 0x80U,
	ADCE_TIMER1_CMP_MATCH_B     = 0xA0U,
	ADC_TIMER1_OVF              = 0xC0U,
	ADC_TIMER1_CAPTURE_EVENT    = 0xE0U
}Adc_TriggerSourceType;

/* !Comment: The Following Enumeration selects the Alignment of the ADC Result */
typedef enum
{
	ADC_ALIGN_LEFT              = 0x20U,
	ADC_ALIGN_RIGHT             = 0x00U 
}Adc_ResultAlignmentType;

/* !Comment: The Following Enumeration selects the Prescale value of the ADC */
typedef enum
{
	ADC_PRESCALE_2              = 0x01U,
	ADC_PRESCALE_4,
	ADC_PRESCALE_8,
	ADC_PRESCALE_16,
	ADC_PRESCALE_32,
	ADC_PRESCALE_64,
	ADC_PRESCALE_128
}Adc_PrescaleType;

/* !Comment: The following Enumeration Defines whether the ADC Interrupt enabled or disabled.*/
typedef enum
{
	ADC_INTERRUPT_DISABLE      = 0x00U,
	ADC_INTERRUPT_ENABLE	   = 0x08U
}Adc_IntStateType;

/* !Comment: The Following Enumeration lists the status of the ADC Module */
typedef enum
{
	ADC_IDLE,
	ADC_BUSY,
	ADC_COMPLETED
}Adc_StatusType;

/* ! Comment: Type definition of the ADC result value */
typedef uint16 Adc_ValueType;

/* !Comment: Data Structure that holds the ADC Module configuration and required for initializing the ADC Driver */
typedef struct
{
	Adc_GroupType           AdcGroup;
	Adc_RefType				VoltRef;
	Adc_ConModeType			ConvMode;
	Adc_PrescaleType		ClkDivFactor;
	Adc_ResolutionType		Resolution; 
	Adc_TriggerSourceType   TriggerSource;
	Adc_ResultAlignmentType ResAlignment;
	Adc_IntStateType        IntState;
} Adc_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void Adc_Init(const Adc_ConfigType *ConfigPtr);
void Adc_StartGroupConversion(Adc_GroupType Group);
void Adc_StopGroupConversion(Adc_GroupType Group);
void Adc_ReadChannel(Adc_ChannelType Channel, Adc_ResolutionType Resolution, Adc_ValueType *DataBufferPtr);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Lcfg structures to be used by ADC and other modules */
extern const Adc_ConfigType gStrAdc_Configuration;

#endif /* ADC_H_ */
