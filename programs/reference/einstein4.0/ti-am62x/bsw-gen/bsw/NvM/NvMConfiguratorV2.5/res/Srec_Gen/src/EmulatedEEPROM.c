#include <stdio.h>
#include "Std_Types.h"

#include "EmulatedEEPROM.h"

#include "Fls.h"
#include "MemIf.h"
#include "General_Cfg.h"


static uint8 EmulatedEEPROM[EEPROM_SIZE];

uint8 * EmulatedEEPROM_GetImage(void)
{
   return (uint8 *)&EmulatedEEPROM[0];
}

void Fls_Init(void)
{
    uint64 fl_itr;
    // printf("Init_FLS\n");
    for(fl_itr = 0; fl_itr < EEPROM_SIZE; fl_itr++)
    {
        // printf ("index = %d\n",fl_itr);
        EmulatedEEPROM[fl_itr] = EEPROM_ERASE_VALUE;
    }
    printf("Init_FLS\n");
}

Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    uint64 fl_itr;
    for (fl_itr = 0; fl_itr < Length; fl_itr++)
    {
        // printf("Erase %l %d\n",TargetAddress, Length);
        // while(1){};
        EmulatedEEPROM[TargetAddress + fl_itr] = EEPROM_ERASE_VALUE;
    }
    return E_OK;
}


Std_ReturnType Fls_Write(Fls_AddressType TargetAddress,uint8 *SourceAddressPtr,Fls_LengthType Length)
{
    uint64 fl_itr;
    for (fl_itr = 0; fl_itr < Length; fl_itr++)
    {
        EmulatedEEPROM[fl_itr + TargetAddress] = SourceAddressPtr[fl_itr];
    }
    return E_OK;
}

Std_ReturnType Fls_Read (Fls_AddressType SourceAddress,uint8 *TargetAddressPtr,Fls_LengthType Length)
{
    uint64 fl_itr;
    for (fl_itr = 0; fl_itr < Length; fl_itr++)
    {
        TargetAddressPtr[fl_itr] = EmulatedEEPROM[fl_itr + SourceAddress];
    }
    return E_OK;
}

Std_ReturnType Fls_ReadImmediate (Fls_AddressType SourceAddress,uint8 *TargetAddressPtr,Fls_LengthType Length)
{
    uint64 fl_itr;
    for (fl_itr = 0; fl_itr < Length; fl_itr++)
    {
        TargetAddressPtr[fl_itr] = EmulatedEEPROM[fl_itr + SourceAddress];
    }
    return E_OK;
}

#if(EEP_DRIVER_TYPE == WORKFLASH)
void Fls_MainFunction(void)
{
}

void Fls_Cancel(void)
{
}

Std_ReturnType Fls_GetStatus(void)
{
 return MEMIF_IDLE;
}

Std_ReturnType Fls_GetJobResult(void)
{
   return MEMIF_JOB_OK;
}
#endif