/*
 * Ext_Eeprom.h
 *
 * Created: 11/8/2021 3:00:10 PM
 *  Author: Abdelaziz Moustafa
 */

#ifndef EXT_EEPROM_H_
#define EXT_EEPROM_H_

#include "Std_Types.h"

#define EEPROM_ADDRESS (0xA2U)

typedef enum
{
    EEPROM_WRITE,
    EEPROM_READ
} Eeprom_OperationType;

typedef enum
{
    EEPROM_E_NOK,
    EEPROM_E_OK
} Eeprom_StatusType;

void Eeprom_Init(void);
Eeprom_StatusType Eeprom_WriteByte(uint8 u8Addr, uint8 u8Data);
Eeprom_StatusType Eeprom_ReadByte(uint8 u8Addr, uint8 *u8Data);
Eeprom_StatusType Eeprom_CurrenAddReadByte(uint8 *u8Data);
#endif /* EXT_EEPROM_H_ */