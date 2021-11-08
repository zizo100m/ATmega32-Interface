/*
 * Twi_Lcfg.c
 *
 * Created: 11/8/2021 2:27:01 PM
 *  Author: Abdelaziz Moustafa
 */

#include "Twi.h"

const Twi_ConfigType gStrTwi_Configuration =
{
    TWI_PRESCALE1,
    TWI_INTERRUPT_DISABLE,
    TWI_STANDARD_SPEED, // bitrate : 1Mbps
};
