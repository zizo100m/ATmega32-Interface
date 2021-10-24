/*
 * Spi.h
 *
 * Created: 10/23/2021 9:38:42 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "Spi_Pcfg.h"
#include "Std_Types.h"
typedef enum
{
	SPI_SLAVE,
	SPI_MASTER
}Spi_OperType;

typedef enum
{
	SPI_NORMAL_SPEED,
	SPI_DOUBLE_SPEED
}Spi_SpeedType;

typedef enum
{
	SPI_MSB_FIRST,
	SPI_LSB_FIRST
}Spi_DataOrderType;

typedef enum
{
	SPI_LEAD_RISE_SAMPLE=0x00,     /* CPOL = 0, CPHA = 0 */
	SPI_LEAD_RISE_SETUP=0x04,      /* CPOL = 0, CPHA = 1 */
	SPI_LEAD_FALLING_SAMPLE=0x08,  /* CPOL = 1, CPHA = 0 */
	SPI_LEAD_FALLING_SETUP=0x0C,   /* CPOL = 1, CPHA = 1 */
}Spi_ModeType;

typedef enum 
{
	SPI_MASTER_PRESCALER4,
	SPI_MASTER_PRESCALER16,
	SPI_MASTER_PRESCALER64,
	SPI_MASTER_PRESCALER128,
}SPI_PrescaleType;

typedef enum
{
	SPI_INTERRUPT_DISABLED,
	SPI_INTERRUPT_ENABLE
}Spi_IntStateType;

typedef struct
{
	Spi_OperType      OperationType;
	Spi_SpeedType     Speed;
	Spi_DataOrderType DataOrder;
	Spi_ModeType      Mode;
	SPI_PrescaleType  ClkDivision;
	Spi_IntStateType  IntState;
}Spi_ConfigType;

void Spi_Init(const Spi_ConfigType *ConfigPtr);
void Spi_Transmit(uint8 Data);
uint8 Spi_Receive(void);
uint8 Spi_TransmitReceive(uint8 Data);

extern const Spi_ConfigType gStrSpi_Configuration;

#endif /* SPI_H_ */