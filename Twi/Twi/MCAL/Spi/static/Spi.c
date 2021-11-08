/*
 * Spi.c
 *
 * Created: 10/23/2021 9:39:00 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Spi.h"
#include "ATmega32_Cfg.h"
#include "Macros.h"
#include "Dio.h"

void Spi_Init(const Spi_ConfigType *ConfigPtr)
{
	switch(ConfigPtr->OperationType)
	{
		case SPI_MASTER:
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN4, DIO_OUTPUT); //SS
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN5, DIO_OUTPUT); //MOSI
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN7, DIO_OUTPUT); //SCK
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN6, DIO_INPUT); //MISO
		break;
		case SPI_SLAVE:
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN4, DIO_INPUT); //SS
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN5, DIO_INPUT); //MOSI
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN7, DIO_INPUT); //SCK
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN6, DIO_OUTPUT); //MISO
		break;
		default:
		break;
	}
	/* !Comment: Clear Registers before applying configuration */
	*SPI_CTRL_REG = 0x00U;
	*SPI_STATUS_REG = 0x00U;
	/* !Comment: Apply Configuration */
	*SPI_CTRL_REG |= (ConfigPtr->OperationType << SPI_MASTER_SLAVE_SEL_BIT);
	*SPI_CTRL_REG |= (ConfigPtr->DataOrder << SPI_DATA_ORDER_BIT);
	*SPI_CTRL_REG |= (ConfigPtr->IntState << SPI_INTERRUPT_ENABLE_BIT);
	*SPI_CTRL_REG |= ConfigPtr->Mode;
	*SPI_CTRL_REG |= ConfigPtr->ClkDivision;
	
	*SPI_STATUS_REG |= ConfigPtr->Speed;
	
	/* !Comment: Enable SPI Module */
	SET_BIT(*SPI_CTRL_REG, SPI_ENABLE_BIT);
}
void Spi_Transmit(uint8 Data)
{
	*SPI_DATA_REG = Data;	
	while(READ_BIT(*SPI_STATUS_REG, SPI_INTERRUPT_FLAG) == 0U)
	{
		/* Do Nothing */
	}
}
uint8 Spi_Receive(void)
{
	while(READ_BIT(*SPI_STATUS_REG, SPI_INTERRUPT_FLAG) == 0U)
	{
		/* Do Nothing */
	}
	return (*SPI_DATA_REG);
}
uint8 Spi_TransmitReceive(uint8 Data)
{
	*SPI_DATA_REG = Data;
	/* Wait until SPIF is 1 */
	while(READ_BIT(*SPI_STATUS_REG, SPI_INTERRUPT_FLAG) == 0U)
	{
		/* Do Nothing */
	}
	/* Clear SPIF flag */
	SET_BIT(*SPI_STATUS_REG, SPI_INTERRUPT_FLAG);
	
	return (*SPI_DATA_REG);
}