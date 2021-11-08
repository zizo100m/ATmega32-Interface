/*
 * Ext_Eeprom.c
 *
 * Created: 11/8/2021 3:01:27 PM
 *  Author: Abdelaziz Moustafa
 */

#include "Ext_Eeprom.h"
#include "Twi.h"

void Eeprom_Init(void)
{
    /* just initialize the I2C(TWI) module inside the MC */
    Twi_Init(&gStrTwi_Configuration);
}

Eeprom_StatusType Eeprom_WriteByte(uint8 u8Addr, uint8 u8Data)
{
    /* Send the Start Bit */
    Twi_Start();
    if (Twi_StatusGet() != TW_START)
    {
        return EEPROM_E_NOK;
    }

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    Twi_Write((uint8)(EEPROM_ADDRESS | (EEPROM_WRITE)));
    if (Twi_StatusGet() != TW_MT_SLA_W_ACK)
    {
        return EEPROM_E_NOK;
    }

    /* Send the required memory location address */
    Twi_Write((uint8)(u8Addr));
    if (Twi_StatusGet() != TW_MT_DATA_ACK)
    {
        return EEPROM_E_NOK;
    }

    /* write byte to eeprom */
    Twi_Write(u8Data);
    if (Twi_StatusGet() != TW_MT_DATA_ACK)
    {
        return EEPROM_E_NOK;
    }

    /* Send the Stop Bit */
    Twi_Stop();

    return EEPROM_E_OK;
}

Eeprom_StatusType Eeprom_ReadByte(uint8 u8Addr, uint8 *u8Data)
{
    /* Send the Start Bit */
    Twi_Start();
    if (Twi_StatusGet() != TW_START)
    {
        return EEPROM_E_NOK;
    }

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    Twi_Write((uint8)(EEPROM_ADDRESS | (EEPROM_WRITE)));
    if (Twi_StatusGet() != TW_MT_SLA_W_ACK)
    {
        return EEPROM_E_NOK;
    }
	
    /* Send the required memory location address */
    Twi_Write((uint8)(u8Addr));
    if (Twi_StatusGet() != TW_MT_DATA_ACK)
    {
        return EEPROM_E_NOK;
    }

    /* Send the Repeated Start Bit */
    Twi_Start();
    if (Twi_StatusGet() != TW_REP_START)
    {
        return EEPROM_E_NOK;
    }

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
    Twi_Write((uint8)(EEPROM_ADDRESS | (EEPROM_READ)));
    if (Twi_StatusGet() != TW_MT_SLA_R_ACK)
    {
        return EEPROM_E_NOK;
    }

    /* Read Byte from Memory without send ACK */
    *u8Data = Twi_ReadWithNACK();
    if (Twi_StatusGet() != TW_MR_DATA_NACK)
    {
        return EEPROM_E_NOK;
    }

    /* Send the Stop Bit */
    Twi_Stop();
    return EEPROM_E_OK;
}


Eeprom_StatusType Eeprom_CurrenAddReadByte(uint8 *u8Data)
{
    /* Send the Start Bit */
    Twi_Start();
    if (Twi_StatusGet() != TW_START)
    {
        return EEPROM_E_NOK;
    }
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
    Twi_Write((uint8)(EEPROM_ADDRESS | (EEPROM_READ)));
    if (Twi_StatusGet() != TW_MT_SLA_R_ACK)
    {
        return EEPROM_E_NOK;
    }

    /* Read Byte from Memory without send ACK */
    *u8Data = Twi_ReadWithNACK();
    if (Twi_StatusGet() != TW_MR_DATA_NACK)
    {
        return EEPROM_E_NOK;
    }

    /* Send the Stop Bit */
    Twi_Stop();
    return EEPROM_E_OK;
}