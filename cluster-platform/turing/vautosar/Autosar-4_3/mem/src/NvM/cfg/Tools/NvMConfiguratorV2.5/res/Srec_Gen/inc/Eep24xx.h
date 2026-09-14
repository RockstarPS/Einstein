#ifndef Eep24xx_H
#define Eep24xx_H

#include "MemIf_Types.h"
#include "Dummy_Types.h"

typedef struct
{
    void * Config_Ptr;
}Eep24xx_ConfigType;

typedef uint16  Eep24xx_AddressType;
typedef uint16  Eep24xx_LengthType;

extern void Eep24xx_Init(const Eep24xx_ConfigType* ConfigPtr);
extern void Eep24xx_SetMode(MemIf_ModeType Mode);
extern Std_ReturnType Eep24xx_Read(Eep24xx_AddressType EepromAddress, uint8* DataBufferPtr,Eep24xx_LengthType Length);
extern Std_ReturnType Eep24xx_Write(Eep24xx_AddressType EepromAddress,const uint8* DataBufferPtr,Eep24xx_LengthType Length);
extern Std_ReturnType Eep24xx_Erase(Eep24xx_AddressType EepromAddress, Eep24xx_LengthType Length);
extern Std_ReturnType Eep24xx_Compare(Eep24xx_AddressType EepromAddress,const uint8* DataBufferPtr,Eep24xx_LengthType Length);
extern void Eep24xx_Cancel (void);
extern void Eep24xx_MainFunction (void);
extern MemIf_StatusType Eep24xx_GetStatus(void);
extern MemIf_JobResultType Eep24xx_GetJobResult(void);

#endif