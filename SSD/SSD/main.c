/*
 * SSD.c
 *
 * Created: 9/23/2021 3:08:00 PM
 * Author : Abdelaziz Moustafa
 */ 

#include "SSD.h"
#include "Macros.h"
#include <util/delay.h>


int main(void)
{
    SSD_Init();
    while (1) 
    {
		SSD_NumSet(76);
    }
}

