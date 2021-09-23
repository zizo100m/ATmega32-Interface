/*
 * LCD.c
 *
 * Created: 9/23/2021 10:28:46 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "LCD.h"
#include <util/delay.h>

int main(void)
{
	LCD_Init();
    /* Replace with your application code */
    while (1) 
    {
		LCD_SHIFT(LCD_SHIFT_LEFT);
		LCD_RowCol_Select(0,5);
		LCD_StringDisplay("Hello!");
		LCD_RowCol_Select(1,0);
		LCD_StringDisplay("Welcome LCD ");
		LCD_IntegerDisplay(101);
    }
}

