#ifndef Eep24xx_H
#define Eep24xx_H

#include "MemIf_Types.h"
#include "Dummy_Types.h"

typedef struct
{
    void * Config_Ptr;
}EepDrv_ConfigType;

typedef uint16  EepDrv_AddressType;
typedef uint16  EepDrv_LengthType;

extern void EepDrv_Init(const EepDrv_ConfigType* ConfigPtr);
extern void EepDrv_SetMode(MemIf_ModeType Mode);
extern Std_ReturnType EepDrv_Read(EepDrv_AddressType EepromAddress, uint8* DataBufferPtr,EepDrv_LengthType Length);
extern Std_ReturnType EepDrv_Write(EepDrv_AddressType EepromAddress,const uint8* DataBufferPtr,EepDrv_LengthType Length);
extern Std_ReturnType EepDrv_Erase(EepDrv_AddressType EepromAddress, EepDrv_LengthType Length);
extern Std_ReturnType EepDrv_Compare(EepDrv_AddressType EepromAddress,const uint8* DataBufferPtr,EepDrv_LengthType Length);
extern void EepDrv_Cancel (void);
extern void EepDrv_MainFunction (void);
extern MemIf_StatusType EepDrv_GetStatus(void);
extern MemIf_JobResultType EepDrv_GetJobResult(void);

#endif