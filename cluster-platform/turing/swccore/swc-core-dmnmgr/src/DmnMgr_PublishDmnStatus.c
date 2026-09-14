//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
///--------------------------------------------------------------------------------------------------------------------
#include "DmnMgr_PublishDmnStatus.h"

#define DMNMGR_START_SEC_VAR_INIT_ASIL_B_8
#include "MemMap.h"

static SDmnStatus oDmnStatus = {0};

#define DMNMGR_STOP_SEC_VAR_INIT_ASIL_B_8
#include "MemMap.h"


#define DMNMGR_START_SEC_CODE_ASIL_B
#include "MemMap.h"

static Std_ReturnType DmnMgr_SetDmnInfo_linkStatus(const EUclLinkState_t *pData);
static Std_ReturnType DmnMgr_SetDmnInfo_uclErrCode(const sint32 *pData);
static Std_ReturnType DmnMgr_SetDmnInfo_dmnHealthState(const EDmnHealthState_t *pData);
#ifdef DMNMGR_FATALERROR_APPLICATION_NOTIFICATION
static Std_ReturnType DmnMgr_SetDmnInfo_compIdx(const UInt32  pData);
#endif
static Std_ReturnType DmnMgr_SetDmnInfo_state(const ESystemState *pData);
static Std_ReturnType DmnMgr_SetDmnInfo_dmnStatus(const EDmnOverallState_t *pData);


Std_ReturnType DmnMgr_SetDmnInfo_dmnId(const EDomainId *pData)
{
	(void)Rte_Read_rpSR_DmnInfo_SDmnStatus(&oDmnStatus);
	oDmnStatus.dmnId = *pData;

	return Rte_Write_ppSR_DmnInfo_SDmnStatus(&oDmnStatus); 
}

static Std_ReturnType DmnMgr_SetDmnInfo_linkStatus(const EUclLinkState_t *pData)
{
	(void)Rte_Read_rpSR_DmnInfo_SDmnStatus(&oDmnStatus);
	oDmnStatus.linkStatus = *pData;

	return Rte_Write_ppSR_DmnInfo_SDmnStatus(&oDmnStatus); 
}

static Std_ReturnType DmnMgr_SetDmnInfo_uclErrCode(const sint32 *pData)
{
	(void)Rte_Read_rpSR_DmnInfo_SDmnStatus(&oDmnStatus);
	oDmnStatus.uclErrCode = *pData;

	return Rte_Write_ppSR_DmnInfo_SDmnStatus(&oDmnStatus);     
}

static Std_ReturnType DmnMgr_SetDmnInfo_dmnHealthState(const EDmnHealthState_t *pData)
{
	(void)Rte_Read_rpSR_DmnInfo_SDmnStatus(&oDmnStatus);
	oDmnStatus.dmnHealthState = *pData;

	return Rte_Write_ppSR_DmnInfo_SDmnStatus(&oDmnStatus);    
}
#ifdef DMNMGR_FATALERROR_APPLICATION_NOTIFICATION
static Std_ReturnType DmnMgr_SetDmnInfo_compIdx(const UInt32 pData)
{
	(void)Rte_Read_rpSR_DmnInfo_SDmnStatus(&oDmnStatus);
	oDmnStatus.compIdx = pData;

	return Rte_Write_ppSR_DmnInfo_SDmnStatus(&oDmnStatus);    
}
#endif

static Std_ReturnType DmnMgr_SetDmnInfo_state(const ESystemState *pData)
{
	(void)Rte_Read_rpSR_DmnInfo_SDmnStatus(&oDmnStatus);
	oDmnStatus.state = *pData;

	return Rte_Write_ppSR_DmnInfo_SDmnStatus(&oDmnStatus); 
}

static Std_ReturnType  DmnMgr_SetDmnInfo_dmnStatus(const EDmnOverallState_t *pData)
{
	(void)Rte_Read_rpSR_DmnInfo_SDmnStatus(&oDmnStatus);
	oDmnStatus.dmnStatus = *pData;

	return Rte_Write_ppSR_DmnInfo_SDmnStatus(&oDmnStatus); 
}

DmnMgr_ReturnType DmnMgr_PublishUclLinkStatus(EDomainId dmnId)
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	SDmnRunTimeStatus *pDmnSts = NULL;

	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{
		//Publish Domain Link Status
		(void)DmnMgr_SetDmnInfo_linkStatus(&pDmnSts->dmnUclLinkState);

		//Publish Overall Domain Status
		(void)DmnMgr_SetDmnInfo_dmnStatus(&pDmnSts->dmnStatus);
	}
	else
	{
		ret = DMNMGR_E_NOK;
		//Invoke DET
	}
	
	return ret;
}

DmnMgr_ReturnType DmnMgr_PublishUclFatatError(EDomainId dmnId)
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	SDmnRunTimeStatus *pDmnSts = NULL;

	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{
		//Publish UCL fatal error
		(void)DmnMgr_SetDmnInfo_uclErrCode(&pDmnSts->dmnUclFatalErrorRcvd);

		//Publish Overall Domain Status
		(void)DmnMgr_SetDmnInfo_dmnStatus(&pDmnSts->dmnStatus);
	}
	else
	{
		ret = DMNMGR_E_NOK;
		//Invoke DET
	}
	
	return ret;
}


DmnMgr_ReturnType DmnMgr_PublishDmnSystemState(EDomainId dmnId)
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	SDmnRunTimeStatus *pDmnSts = NULL;

	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{
		//Publish Health state of the Domain
		(void)DmnMgr_SetDmnInfo_state(&pDmnSts->dmnCurSystemState);

		//Publish Overall Domain Status
		(void)DmnMgr_SetDmnInfo_dmnStatus(&pDmnSts->dmnStatus);
	}
	else
	{
		ret = DMNMGR_E_NOK;
		//Invoke DET
	}
	
	return ret;
}

DmnMgr_ReturnType DmnMgr_PublishDmnHealthStaus(EDomainId dmnId)
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	SDmnRunTimeStatus *pDmnSts = NULL;

	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{
		//Publish Health state of the Domain
		(void)DmnMgr_SetDmnInfo_dmnHealthState(&pDmnSts->dmnHealthState);
		#ifdef DMNMGR_FATALERROR_APPLICATION_NOTIFICATION
		if (pDmnSts->dmnHealthState == EDmnHealth_Fatal_Error)
		{
		   (void)DmnMgr_SetDmnInfo_compIdx(pDmnSts->compldx);
		}
        else
		{
           (void)DmnMgr_SetDmnInfo_compIdx(0);
		   pDmnSts->compldx = 0;
		}
		#endif
		//Publish Overall Domain Status
		(void)DmnMgr_SetDmnInfo_dmnStatus(&pDmnSts->dmnStatus);
	}
	else
	{
		ret = DMNMGR_E_NOK;
		//Invoke DET
	}
	
	return ret;
}

DmnMgr_ReturnType DmnMgr_PublishDmnThermalState(EDomainId dmnId)
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	
	(void)dmnId;
	
	return ret;
}

#define DMNMGR_STOP_SEC_CODE_ASIL_B
#include "MemMap.h"
