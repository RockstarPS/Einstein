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
#include "string.h" 
#include "UpdateCdd_Types.h"
#include "UPDi_IoAdapter.h"
#include "UPDi_Session.h"
#include "UPDi_BlockInstaller.h"

 
//=====================================================================================================================
//  CONSTANTS & TYPES &global variables
//=====================================================================================================================

//=====================================================================================================================
//  Static Variables
//=====================================================================================================================
tUPDiAbstractInstaller_Vtbl UPDBlockInstaller_Vtbl =
{
    .GetExtension = (tpfGetExtension)UPDBlockInstaller_GetExtension,
    .InstallStart = (tpfInstallStart)UPDBlockInstaller_InstallStart,
    .InstallData  = (tpfInstallData) UPDBlockInstaller_InstallData,
    .InstallExit  = (tpfInstallExit) UPDBlockInstaller_InstallExit,
    .Serialize    = (tpfSerialize)   UPDBlockInstaller_Serialize,
    .Deserialize  = (tpfDeserialize) UPDBlockInstaller_Deserialize,
	.Rewind      = (tpfRewind)      UPDBlockInstaller_Rewind,
};

//=====================================================================================================================
//  Private functions
//=====================================================================================================================
static boolean UPDBlockInstaller_IsInvalid(tUPDiBlockInstaller* this)
{
    boolean ret = TRUE;
#ifndef UPDd_POINTER_TEST_DISABLED
    if (this != NULL)
    {
        ret = (this->Vtbl == NULL);
    }
#else
    ret = FALSE;
#endif
    return ret;
}
static boolean UPDBlockInstaller_IsValid(tUPDiBlockInstaller* this)
{
    return UPDBlockInstaller_IsInvalid(this);
}

//=====================================================================================================================
//  Interface
//=====================================================================================================================
const char*    UPDBlockInstaller_GetExtension(tUPDiBlockInstaller* this)
{
    return UPDBlockInstaller_IsValid(this) ? "": "raw";
}

/*=====================================================================================================================================================
* Std_ReturnType UPDBlockInstaller_InstallStart(tUPDiBlockInstaller* this, tUPDiInstallSession* pSession, PackageName, uint32_t Size)  
* Function description : This function shall perform start download service
* Input arguments      : session id,installation package name,package size
* Return               : E_OK      : start download service completed successfully
*                        E_PENDING : start download service ongoing
*                        E_NOT_OK  : start download service failed
* Function scope : private method
* =====================================================================================================================================================*/ 
Std_ReturnType UPDBlockInstaller_InstallStart(tUPDiBlockInstaller* this, tUPDiInstallSession* pSession, const char* PackageName, uint32_t Size)
{
    Std_ReturnType Status = E_NOT_OK;
   if (UPDBlockInstaller_IsInvalid(this) || (pSession == NULL)) {}
   else
   {
       Status = UPDiSession_StartPartitionUpdate(pSession, PackageName, Size, FALSE);
   }

   return Status;
}
/*===========================================================================================================================================
* Std_ReturnType UPDBlockInstaller_InstallData(tUPDiBlockInstaller* this, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t Size)  
* Function description : This function shall perform transfer data service
* Input arguments      : session id,installation package name,package size
* Return               : E_OK - transfer data service accepted
                         E_PENDING - transfer data service not accepted
*============================================================================================================================================*/ 
Std_ReturnType UPDBlockInstaller_InstallData(tUPDiBlockInstaller* this, tUPDiInstallSession* pSession, uint8_t* Data, uint32_t Size)
{
    Std_ReturnType Status = E_NOT_OK;
    if (UPDBlockInstaller_IsInvalid(this)) {}
    else
    {
 	    Status = UPDiSession_WriteNext(pSession,  Data, Size);
    }
    return Status;
}
/*===========================================================================================================================================
* Private function :Std_ReturnType UPDBlockInstaller_InstallExit(tUPDiBlockInstaller* this, tUPDiInstallSession* pSession) 
* Function description : This function shall exit the download service
* E_OK - Successful exit 
* E_PENDING - pending
* E_NOT_OK  - Error while exiting
*============================================================================================================================================*/
Std_ReturnType UPDBlockInstaller_InstallExit(tUPDiBlockInstaller* this, tUPDiInstallSession* pSession)
{
    Std_ReturnType Status = E_NOT_OK;
    if (UPDBlockInstaller_IsInvalid(this)) {}
    else
    {
        Status = UPDiSession_FinishPartitionUpdate(pSession);
    }
    return Status;
}
/*===========================================================================================================================================
* Std_ReturnType UPDBlockInstaller_Serialize(tUPDiBlockInstaller* this, uint32_t SizeIn, uint8_t* data)
* Function description : This function shall copy the target manifest information to nvm buffer
* Return : E_OK
*============================================================================================================================================*/
Std_ReturnType UPDBlockInstaller_Serialize(tUPDiBlockInstaller* this, uint32_t SizeIn, uint8_t* data, uint32_t* SizeOut)
{
    return E_NOT_OK;
}
/*===========================================================================================================================================
* Std_ReturnType UPDInstallMan_Deserialize(uint32_t SizeIn, uint8_t* data) 
* Function description : This function shall copy nvm buffer information to target ram
* Return : E_OK
*============================================================================================================================================*/
Std_ReturnType UPDBlockInstaller_Deserialize(tUPDiBlockInstaller* this, uint32_t SizeIn, uint8_t* data, uint32_t* SizeOut)
{
    return E_NOT_OK;
}

/*===========================================================================================================================================
* Std_ReturnType UPDInstallMan_Deserialize(uint32_t SizeIn, uint8_t* data)
* Function description : This function shall copy nvm buffer information to target ram
* Return : E_OK
*============================================================================================================================================*/
boolean UPDBlockInstaller_Rewind(tUPDiBlockInstaller* This, uint32_t FlashOffset, uint32_t* pImageOffset)
{
	boolean ContinueFlashing = FALSE;
	if( UPDBlockInstaller_IsInvalid(This)  )
	{}
	else
	{
		*pImageOffset = FlashOffset;
		ContinueFlashing = TRUE;
	}
	return ContinueFlashing;
}
