/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/

#ifndef UPD_ICry_H
#define UPD_ICry_H

#include "UPD_Types.h"

//=====================================================================================================================
//  Crypto interface for UPD
//=====================================================================================================================
Std_ReturnType UPD_ICry_Hash_Init(tUPDHashInfo* pHash);
Std_ReturnType UPD_ICry_Hash_Update(tUPDHashInfo* pHash, uint8* pBuffer, uint32 Size);
Std_ReturnType UPD_ICry_Hash_Final(tUPDHashInfo* pHash);

Std_ReturnType UPD_ICry_Decrypt_Init(void);
Std_ReturnType UPD_ICry_Decrypt_Update(uint8* pInBuffer, uint32 InSize, uint8* pOutBuffer, uint32* OutSize);
Std_ReturnType UPD_ICry_Decrypt_Final(uint8* pOutBuffer, uint32* OutSize);

#endif /*UPD_ICry_H*/
