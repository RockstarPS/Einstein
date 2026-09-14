#if !defined( FLS_H )
#define FLS_H

#include "Fls_TypesLib.h"
#include "MemIf_Types.h"

extern FUNC(Std_ReturnType, FLS_CODE) Fls_Erase
(
    Fls_AddressType TargetAddress,
    Fls_LengthType Length
);

extern FUNC(Std_ReturnType, FLS_CODE) Fls_Write
(
    Fls_AddressType TargetAddress,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) SourceAddressPtr,
    Fls_LengthType Length
);

extern FUNC(MemIf_JobResultType, FLS_CODE) Fls_GetJobResult(void);

extern FUNC(Std_ReturnType, FLS_CODE) Fls_Read
(
    Fls_AddressType SourceAddress,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr,
    Fls_LengthType Length
);

#endif 