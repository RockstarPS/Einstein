///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///---------------------------------------------------------------------------------------------------------------------
#include "UclSys_Impl.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include "UclILSched.h"
#include "UclILRouter.h"

Ucl_ReturnType UclSys_Impl_IUclSys_Initialize(SUclSysInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret;

    Ret = UclALOs_Initialize(pInst->pIUclALOs[0]);

    if (UCL_E_OK == Ret)
    {
        UclALDebug_Initialize(pInst->pIUclALDebug[0]);

        Ret = UclILRouter_Initialize(pInst->pIUclILRouter[0]);
    }

    if (UCL_E_OK == Ret)
    {
        Ret = UclILSched_Initialize(pInst->pIUclILSched[0]);
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclSys_Impl", "%s", "IUclSys_Initialize: Success");
		pInst->UclSysState = TRUE;
    }
    else
    {
        LOGE(0, "UclSys_Impl", "IUclSys_Initialize: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclSys_Impl_IUclSys_Shutdown(SUclSysInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

	if(pInst->UclSysState == TRUE)
	{
		pInst->UclSysState = FALSE;
		Ret = UclILSched_Shutdown(pInst->pIUclILSched[0]);

		if (UCL_E_OK == Ret)
		{
			Ret = UclILRouter_Shutdown(pInst->pIUclILRouter[0]);
		}

		if (UCL_E_OK == Ret)
		{
			UclALDebug_Shutdown(pInst->pIUclALDebug[0]);

			Ret = UclALOs_Shutdown(pInst->pIUclALOs[0]);
		}

		if (UCL_E_OK == Ret)
		{
			LOGI(0, "UclSys_Impl", "%s", "IUclSys_Shutdown: Success");			
		}
		else
		{
			LOGE(0, "UclSys_Impl", "IUclSys_Shutdown: Failed %d", Ret);
		}
	}

    return Ret;
}

Ucl_ReturnType UclSys_Impl_IUclSys_Task(SUclSysInst *pInst, uint8 InstId)
{
    UclALOs_Tick(pInst->pIUclALOs[0]);
    return UCL_E_OK;
}

Ucl_ReturnType UclSys_Impl_IUclSys_Send(SUclSysInst *pInst, uint8 InstId, uint8 DLInst, SUclDLMsg *pMsg)
{
    return UCL_E_NOT_SUPPORTED;
}
