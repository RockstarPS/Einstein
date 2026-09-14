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

#include "UPDi.h"
#include <string.h>

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  Static Variables
//=====================================================================================================================

//=====================================================================================================================
//  Private functions
//=====================================================================================================================
static boolean UPDAbstractInstaller_IsInvalid(tUPDiAbstractInstaller *This)
{
	boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
	if (This != NULL)
	{
		ret = (This->Vtbl == NULL);
	}
#else
    ret = FALSE; 
#endif
	return ret;
}

//=====================================================================================================================
//  Public  functions  internal to updatecdd
//=====================================================================================================================

Std_ReturnType UPDAbstractInstaller_InstallStart(tUPDiAbstractInstaller *This,
		tUPDiInstallSession *pSession, const char *PackageName, uint32_t Size)
{
	Std_ReturnType Status = E_NOT_OK;
	if (!UPDAbstractInstaller_IsInvalid(This))
	{
		Status = This->Vtbl->InstallStart(This, pSession, PackageName, Size);
	}
	return Status;
}
Std_ReturnType UPDAbstractInstaller_InstallData(tUPDiAbstractInstaller *This,
		tUPDiInstallSession *pSession, uint8_t *Data, uint32_t Size)
{
	Std_ReturnType Status = E_NOT_OK;
	if (!UPDAbstractInstaller_IsInvalid(This))
	{
		Status = This->Vtbl->InstallData(This, pSession, Data, Size);
	}
	return Status;
}
Std_ReturnType UPDAbstractInstaller_InstallExit(tUPDiAbstractInstaller *This,
		tUPDiInstallSession *pSession)
{
	Std_ReturnType Status = E_NOT_OK;
	if (!UPDAbstractInstaller_IsInvalid(This))
	{
		Status = This->Vtbl->InstallExit(This, pSession);
	}
	return Status;
}

boolean UPDAbstractInstaller_Rewind(tUPDiAbstractInstaller *This,
		uint32_t FlashOffset, uint32_t *pImageOffset)
{
	boolean ContinueFlashing = FALSE;
	if (UPDAbstractInstaller_IsInvalid(This))
	{
	}
	else if (This->Vtbl->Rewind == NULL)
	{
	}
	else
	{
		ContinueFlashing = This->Vtbl->Rewind(This, FlashOffset, pImageOffset);
	}
	return ContinueFlashing;
}

Std_ReturnType UPDAbstractInstaller_Serialize(tUPDiAbstractInstaller *This,
		tUPDStream *pStream)
{
	Std_ReturnType Status = E_NOT_OK;
	if (UPDAbstractInstaller_IsInvalid(This))
	{
	}
	else if (This->Vtbl->Serialize == NULL)
	{
		Status = E_OK; //  if This->Vtbl->Serialize is not defined, there is nothing to serialize
	}
	else
	{
		Status = This->Vtbl->Serialize(This, pStream);
	}
	return Status;
}
Std_ReturnType UPDAbstractInstaller_Deserialize(tUPDiAbstractInstaller *This,
		tUPDStream *pStream)
{
	Std_ReturnType Status = E_NOT_OK;
	if (UPDAbstractInstaller_IsInvalid(This))
	{
	}
	else if (This->Vtbl->Deserialize == NULL)
	{
		Status = E_OK; //  if This->Vtbl->Deserialize is not defined, there is nothing to deserialize
	}
	else
	{
		Status = This->Vtbl->Deserialize(This, pStream);
	}
	return Status;
}
const char* UPDAbstractInstaller_GetExtension(tUPDiAbstractInstaller *This)
{
	return UPDAbstractInstaller_IsInvalid(This) ?
			"" : This->Vtbl->GetExtension(This);
}

