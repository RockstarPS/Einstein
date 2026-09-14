#if !defined( FLS_H )
#define FLS_H

#include "General_Cfg.h"    
#if(EEP_DRIVER_TYPE == WORKFLASH)
#include "MemIf_Types.h"

extern Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length);

extern Std_ReturnType Fls_Write(Fls_AddressType TargetAddress,uint8 *SourceAddressPtr, Fls_LengthType Length);

extern Std_ReturnType Fls_GetJobResult(void);

extern Std_ReturnType Fls_Read(Fls_AddressType SourceAddress,uint8 *TargetAddressPtr, Fls_LengthType Length);

#endif /** EEP_DRIVER_TYPE **/
#endif /** FLS_H **/