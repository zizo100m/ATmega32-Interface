/*
 * Spi_Lcfg.c
 *
 * Created: 10/23/2021 9:39:14 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Spi.h"

const Spi_ConfigType gStrSpi_Configuration =
{
	SPI_MASTER,
	SPI_NORMAL_SPEED,
	SPI_MSB_FIRST,
	SPI_LEAD_RISE_SAMPLE,
	SPI_MASTER_PRESCALER16,
	SPI_INTERRUPT_DISABLED
};