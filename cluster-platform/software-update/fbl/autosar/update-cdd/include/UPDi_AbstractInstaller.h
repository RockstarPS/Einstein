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

# ifndef UPD_AbstractInstaller_H
# define UPD_AbstractInstaller_H

//# include "UPDi.h"
# include "UPDi_Types.h"
# include "UPDd.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
struct sUPDiAbstractInstaller;
struct sUPDiInstallSession;

typedef const char* (*tpfGetExtension)(const struct sUPDiAbstractInstaller* this);
typedef Std_ReturnType(*tpfInstallStart)(const struct sUPDiAbstractInstaller* this,tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
typedef Std_ReturnType(*tpfInstallData)(const struct sUPDiAbstractInstaller* this, tUPDiInstallSession* pSession, uint8* Data, uint32_t Size);
typedef Std_ReturnType(*tpfInstallExit)(const struct sUPDiAbstractInstaller* this, tUPDiInstallSession* pSession);

typedef boolean(*tpfRewind)(const struct sUPDiAbstractInstaller* This, uint32_t FlashOffset, uint32_t* pImageOffset);
typedef Std_ReturnType(*tpfSerialize)(const struct sUPDiAbstractInstaller* this, tUPDStream *pStream);
typedef Std_ReturnType(*tpfDeserialize)(const struct sUPDiAbstractInstaller* this, tUPDStream *pStream);

typedef const struct
{
    tpfGetExtension GetExtension;
    tpfInstallStart InstallStart;
    tpfInstallData InstallData;
    tpfInstallExit InstallExit;
    tpfSerialize Serialize;
    tpfDeserialize Deserialize;
    tpfRewind Rewind;
} tUPDiAbstractInstaller_Vtbl;

typedef const struct sUPDiAbstractInstaller
{
    tUPDiAbstractInstaller_Vtbl* Vtbl;
} tUPDiAbstractInstaller;

//=====================================================================================================================
//  Interfaces
//=====================================================================================================================
const char*    UPDAbstractInstaller_GetExtension(tUPDiAbstractInstaller* this );
Std_ReturnType UPDAbstractInstaller_InstallStart(tUPDiAbstractInstaller* this, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size);
Std_ReturnType UPDAbstractInstaller_InstallData(tUPDiAbstractInstaller* this, tUPDiInstallSession* pSession, uint8* Data, uint32_t Size);
Std_ReturnType UPDAbstractInstaller_InstallExit(tUPDiAbstractInstaller* this, tUPDiInstallSession* pSession);

boolean        UPDAbstractInstaller_Rewind(tUPDiAbstractInstaller* This, uint32_t FlashOffset, uint32_t* pImageOffset );
Std_ReturnType UPDAbstractInstaller_Serialize(tUPDiAbstractInstaller* this, tUPDStream *pStream);
Std_ReturnType UPDAbstractInstaller_Deserialize(tUPDiAbstractInstaller* this, tUPDStream *pStream);

# endif /*UPD_AbstractInstaller_H*/
