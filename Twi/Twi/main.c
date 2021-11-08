/*
 * Twi.c
 *
 * Created: 11/8/2021 1:38:30 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "Ext_Eeprom.h"
#include "LCD.h"
#include "ATmega32_Cfg.h"
#include <util/delay.h>

int main(void)
{
	Eeprom_Init();
	LCD_Init();

    while (1) 
    {
		uint8 u8LocalRecData = 0U;
		Eeprom_WriteByte(0x00, 0x05);
		_delay_ms(1000);// You must allow sufficient delay for the EEPROM to complete its write cycle
		Eeprom_ReadByte(0x00, &u8LocalRecData);
		LCD_RowCol_Select(0,0);
		LCD_StringDisplay("From EEPROM");
		LCD_RowCol_Select(1,5);
		LCD_IntegerDisplay(u8LocalRecData);
		_delay_ms(1000);
    }
}

