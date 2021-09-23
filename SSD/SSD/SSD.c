/*
 * SSD.c
 *
 * Created: 9/23/2021 4:07:34 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "SSD.h"
#include "Dio.h"
#include "Macros.h"
#include <util/delay.h>

const uint8 gau8SSD_arr[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

void SSD_Init(void)
{
	/* Make Seven Segment Enable Pins in OUTPUT Mode */
	Dio_ChannelDirectionSet(SSD_CTRL_DIR_REG, SSD1_EN ,DIO_OUTPUT);
	Dio_ChannelDirectionSet(SSD_CTRL_DIR_REG, SSD2_EN ,DIO_OUTPUT);
	
	/* Make Seven Segment Data Pins in OUTPUT Mode */
	*SSD_DATA_DIR_REG = 0xF0U;   /* 0b11110000 */
}

void SSD_NumberDisplay(SSD_LedsEnum_t Num, uint8 SSD_no)
{
	/* Enable the SSD first */
	switch(SSD_no)
	{
		case SSD1_EN:
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD1_EN, DIO_HIGH);
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD2_EN, DIO_LOW);
			break;
		case SSD2_EN:
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD2_EN, DIO_HIGH);
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD1_EN, DIO_LOW);
			break;
		default:
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD1_EN, DIO_LOW);
			Dio_ChannelWrite(SSD_CTRL_OUT_REG, SSD2_EN, DIO_LOW);
		break;
	}
	/* Write the number to the Data pins */
    if(SSD_TYPE == SSD_COMMON_CATHODE)
	{
		*SSD_DATA_OUT_REG &= ~(0xF0U);
		*SSD_DATA_OUT_REG |= (Num & 0xF0U) ;
	}
	else
	{
		*SSD_DATA_OUT_REG |= (~Num & 0xF0U);
	}
}
void SSD_NumSet(uint16 Number)
{
	SSD_NumberDisplay(gau8SSD_arr[(Number%100)/10],SSD2_EN);
	_delay_ms(10);
	SSD_NumberDisplay(gau8SSD_arr[(Number%10)],SSD1_EN);
	_delay_ms(10);
}