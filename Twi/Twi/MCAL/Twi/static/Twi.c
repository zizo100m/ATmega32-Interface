/*
 * Twi.c
 *
 * Created: 11/8/2021 1:46:54 PM
 *  Author: Abdelaziz Moustafa
 */

#include "Twi.h"
#include "Macros.h"
#include "ATmega32_Cfg.h"
#include "avr/io.h"
void Twi_Init(const Twi_ConfigType *ConfigPtr)
{
     /* !Comment: Clear Registers before applying configuration */
     *TWI_CTRL_REG = 0x00U;
     *TWI_SLAVE_ADDRESS_REG = 0x00U;
     *TWI_BITRATE_REG = 0x00U;
     *TWI_STATUS_REG = 0x00U;

     /* !Comment: Apply configuration */
     *TWI_SLAVE_ADDRESS_REG = TWI_SLAVE_ADDRESS;

     switch (ConfigPtr->Prescale)
     {
     case TWI_PRESCALE1:
         *TWI_BITRATE_REG = (uint8)(((float)F_CPU / (2.0 * ConfigPtr->F_SCL)) - 8U);
         break;
     case TWI_PRESCALE4:
         *TWI_BITRATE_REG = (uint8)(((float)F_CPU / (8.0 * ConfigPtr->F_SCL)) - 2U);
         break;
     case TWI_PRESCALE16:
         *TWI_BITRATE_REG = (uint8)(((float)F_CPU / (32 * ConfigPtr->F_SCL)) - 0.5);
         break;
     case TWI_PRESCALE64:
         *TWI_BITRATE_REG = (uint8)(((float)F_CPU / (128 * ConfigPtr->F_SCL)) - 0.125);
         break;
     default:
         break;
     }

     *TWI_STATUS_REG |= ConfigPtr->Prescale;

     *TWI_CTRL_REG |= ConfigPtr->IntState;

     SET_BIT(*TWI_CTRL_REG, TWI_ENABLE_BIT);
}

void Twi_Start(void)
{
    /*
     * Clear the TWINT flag before sending the start bit TWINT=1
     * send the start bit by TWSTA=1
     * Enable TWI Module TWEN=1
     */
	*TWI_CTRL_REG = (1U<<TWI_INT_FLAG_BIT) | (1U<<TWI_START_BIT) | (1U<<TWI_ENABLE_BIT);
    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while (READ_BIT(*TWI_CTRL_REG, TWI_INT_FLAG_BIT) == 0U)
    {
        /* Do Nothing */
    }
}

void Twi_Stop(void)
{
    /*
     * Clear the TWINT flag before sending the stop bit TWINT=1
     * send the stop bit by TWSTO=1
     * Enable TWI Module TWEN=1
     */
	*TWI_CTRL_REG = (1U<<TWI_STOP_BIT) | (1U<<TWI_ENABLE_BIT) | (1U<<TWI_INT_FLAG_BIT);
}

void Twi_Write(uint8 data)
{
    /* Put data On TWI data Register */
    *TWI_DATA_REG = data;
    /*
     * Clear the TWINT flag before sending the data TWINT=1
     * Enable TWI Module TWEN=1
     */
	*TWI_CTRL_REG = (1U<<TWI_INT_FLAG_BIT)|(1U<<TWI_ENABLE_BIT);

    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while (READ_BIT(*TWI_CTRL_REG, TWI_INT_FLAG_BIT) == 0U)
    {
        /* Do Nothing */
    }
}

uint8 Twi_ReadWithACK(void)
{
    uint8 u8LocalRecData = 0U;
    /*
     * Clear the TWINT flag before reading the data TWINT=1
     * Enable sending ACK after reading or receiving data TWEA=1
     * Enable TWI Module TWEN=1
     */
	*TWI_CTRL_REG = (1U<<TWI_ENABLE_ACK_BIT) | (1U<<TWI_ENABLE_BIT) | (1U<<TWI_INT_FLAG_BIT);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while (READ_BIT(*TWI_CTRL_REG, TWI_INT_FLAG_BIT) == 0U)
    {
        /* Do Nothing */
    }
    /* Read Data */
    u8LocalRecData = *TWI_DATA_REG;
    return (u8LocalRecData);
}

uint8 Twi_ReadWithNACK(void)
{
    uint8 u8LocalRecData = 0U;
    /*
     * Clear the TWINT flag before reading the data TWINT=1
     * Enable TWI Module TWEN=1
     */
	*TWI_CTRL_REG = (1U<<TWI_INT_FLAG_BIT) | (1U<<TWI_ENABLE_BIT);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while (READ_BIT(*TWI_CTRL_REG, TWI_INT_FLAG_BIT) == 0U)
    {
        /* Do Nothing */
    }
    /* Read Data */
    u8LocalRecData = *TWI_DATA_REG;
    return (u8LocalRecData);
}

Twi_StatusType Twi_StatusGet(void)
{
    Twi_StatusType u8LocalStatus;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    u8LocalStatus = *TWI_STATUS_REG & 0xF8U;  
    return u8LocalStatus;
}
