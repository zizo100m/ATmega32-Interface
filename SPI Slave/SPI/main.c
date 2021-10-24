/*
 * SPI.c
 *
 * Created: 10/24/2021 2:00:46 AM
 * Author : Abdelaziz Moustafa
 */ 

#include "LCD.h"
#include "Spi.h"


int main(void)
{
    Spi_Init(&gStrSpi_Configuration);
    LCD_Init();
    uint8 u8LocalReceivedData = 0U;
    while (1)
    {
	    u8LocalReceivedData = Spi_TransmitReceive(5);
	    LCD_IntegerDisplay(u8LocalReceivedData);
    }
}

