#include "Std_Types.h"

#ifndef EEPROM_TYPE_DEFINED
#define EEPROM_TYPE_DEFINED
typedef enum
{
    WORKFLASH = 0,
    EEP_DRV
}EEPROM_Type;
#endif

extern uint8 * EmulatedEEPROM_GetImage(void);
