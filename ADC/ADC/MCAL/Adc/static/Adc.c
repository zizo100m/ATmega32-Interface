/*
 * Adc.c
 *
 * Created: 10/7/2021 4:31:59 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Adc.h"
#include "Macros.h"

/*******************************************************************************
 *                      Private Function Prototypes                            *
 *******************************************************************************/
static Adc_StatusType Adc_ConvStateGet(void);

/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/
void Adc_Init(const Adc_ConfigType *ConfigPtr)
{
	/* !Comment: Clear the ADC Registers before applying the configuration */
	*ADC_MUX_REG = 0x00U;
	*ADC_CTRL_STATUS_A_REG = 0x00U;
	*SPECIAL_FUNC_IO_REG &= 0x1FU;
	
	/* !Comment: Apply the configuration of the desired ADC Group */
	switch(ConfigPtr->AdcGroup)
	{
		case ADC_GROUP_0:
		/* !Comment: Set the Conversion mode/Trigger Source of the ADC Group */
		switch(ConfigPtr->ConvMode)
		{
			case ADC_CON_MODE_ONESHOT:
			break;
			case ADC_CON_MODE_CONTINUOUS:
			SET_BIT(*ADC_CTRL_STATUS_A_REG, ADC_AUTO_TRIGGER_ENABLE_BIT_NUM);
			*SPECIAL_FUNC_IO_REG |= ADC_CON_MODE_CONTINUOUS;
			break;
			case ADC_CON_MODE_TRIGGER:
			SET_BIT(*ADC_CTRL_STATUS_A_REG, ADC_AUTO_TRIGGER_ENABLE_BIT_NUM);
			*SPECIAL_FUNC_IO_REG |= ConfigPtr->TriggerSource;
			break;
			default:
			break;
		}
		/* !Comment: Set the voltage reference for the ADC Group */
		*ADC_MUX_REG |= ConfigPtr->VoltRef;
		/* !Comment: Check the ADC Resolution, and in order to Work with 8-Bit Precision The Data Must Be Left Adjusted */
		switch(ConfigPtr->Resolution)
		{
			case ADC_EIGHT_BIT:
			/* !Comment: Align the result left */
			*ADC_MUX_REG |= ADC_ALIGN_LEFT;
			break;
			case ADC_TEN_BIT:
			/* !Comment: Align the result as Configured */
			*ADC_MUX_REG |= ConfigPtr->ResAlignment;
			break;
			default:
			break;
		}
		/* !Comment: Set the Clock division and Interrupt state for the ADC Group */
		*ADC_CTRL_STATUS_A_REG |= ConfigPtr->ClkDivFactor | ConfigPtr->IntState;
		/* !Comment: Enable ADC unit by setting the ADEN bit.*/
		SET_BIT(*ADC_CTRL_STATUS_A_REG, ADC_ENABLE_BIT_NUM);		
		break;
		default:
		break;
	}
}

void Adc_StartGroupConversion(Adc_GroupType Group)
{
	/* !Comment: Start conversion of the specified ADC Group */
	switch(Group)
	{
		case ADC_GROUP_0:
		SET_BIT(*ADC_CTRL_STATUS_A_REG, ADC_START_CONV_BIT_NUM);
		break;
		default:
		break;
	}
}

void Adc_StopGroupConversion(Adc_GroupType Group)
{
	/* !Comment: Stop conversion of the specified ADC Group */
	switch(Group)
	{
		case ADC_GROUP_0:
		CLEAR_BIT(*ADC_CTRL_STATUS_A_REG, ADC_START_CONV_BIT_NUM);
		break;
		default:
		break;
	}	
}

void Adc_ReadChannel(Adc_ChannelType Channel, Adc_ResolutionType Resolution, Adc_ValueType *DataBufferPtr)
{
	/* !Comment: Clear the channel selection bits in the ADMUX register */
	*ADC_MUX_REG &= 0xE0U;
	/* !Comment: Select the required channel to read the result from it */
	*ADC_MUX_REG |= Channel;
	/* !Comment: Wait until the Conversion is finished */
	while (Adc_ConvStateGet() == ADC_BUSY)
	{
		/* Do Nothing */
	}
	/* !Comment: Read the result when the conversion is completed */
	switch(Resolution)
	{
		case ADC_EIGHT_BIT:
		*DataBufferPtr = *ADC_DATA_HIGH_REG;
		break;
		case ADC_TEN_BIT:
		switch(gStrAdc_Configuration.ResAlignment)
		{
			case ADC_ALIGN_RIGHT:
			*DataBufferPtr = *(uint16*)ADC_DATA_LOW_REG;
			break;
			case ADC_ALIGN_LEFT:
			*DataBufferPtr = (uint16)((*(uint16*)ADC_DATA_LOW_REG>>6U));
			break;
			default:
			break;
		}	
		break;
		default:
		break;
	}
	/* !Comment: Clear the ADIF by writing logic one after reading the result */
	SET_BIT(*ADC_CTRL_STATUS_A_REG, ADC_INT_FLAG_BIT_NUM);
}

static Adc_StatusType Adc_ConvStateGet(void)
{
	Adc_StatusType eLocalAdcState = ADC_BUSY;
	if(READ_BIT(*ADC_CTRL_STATUS_A_REG, ADC_INT_FLAG_BIT_NUM))
	{
		eLocalAdcState = ADC_COMPLETED;
	}
	else
	{
		/* Do Nothing */
	}
	return (eLocalAdcState);
}