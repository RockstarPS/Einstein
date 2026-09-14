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

# ifndef UPD_BlockInstaller_H
# define UPD_BlockInstaller_H

# include "UPDi_AbstractInstaller.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
struct sUPDiPartition;

typedef const struct 
{ 
    tUPDiAbstractInstaller_Vtbl* Vtbl; 
} tUPDiBlockInstaller;

//=====================================================================================================================
//  Interface
//=====================================================================================================================
const char*    UPDBlockInstaller_GetExtension(tUPDiBlockInstaller* this);
Std_ReturnType UPDBlockInstaller_InstallStart(tUPDiBlockInstaller* this, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
Std_ReturnType UPDBlockInstaller_InstallData(tUPDiBlockInstaller* this, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t Size);
Std_ReturnType UPDBlockInstaller_InstallExit(tUPDiBlockInstaller* this, tUPDiInstallSession* pSession);

boolean        UPDBlockInstaller_Rewind(tUPDiBlockInstaller* This, uint32_t FlashOffset, uint32_t* pImageOffset);
Std_ReturnType UPDBlockInstaller_Serialize(tUPDiBlockInstaller* this, uint32_t SizeIn, uint8_t* data, uint32_t* SizeOut);
Std_ReturnType UPDBlockInstaller_Deserialize(tUPDiBlockInstaller* this, uint32_t SizeIn, uint8_t* data, uint32_t* SizeOut);

//=====================================================================================================================
//  extern VTBL
//=====================================================================================================================
extern tUPDiAbstractInstaller_Vtbl UPDBlockInstaller_Vtbl;
extern tUPDBank UpdateCdd_UpdatedBank;

# endif /*UPD_BlockInstaller_H*/
