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
#include "Rte_UclProxyCdd.h"
#include "Std_Types.h"
#include "CmpLib.h"
#include "UclSys.h"
#include <UclILAdapter.h>


CMPLIB_INSTANCE(UclProxyCdd)

static uint8 UclStackRunning;

static Std_ReturnType CmpInit(void)
{
    UclStackRunning = FALSE;
    return E_OK;
}

static Std_ReturnType CmpDeInit(void)
{
    UclStackRunning = FALSE;
    return E_OK;
}

static Std_ReturnType CmpActivation(void)
{
    return E_OK;
}

static Std_ReturnType CmpDeActivation(void)
{
    return E_OK;
}

static Std_ReturnType CmpActive(void)
{
    if (TRUE == UclStackRunning)
    {
        UclSys_Task(0);
    }
    // Temporary fix Begin
    else
    {
        if (UCL_E_OK == UclSys_Initialize(0))
        {
            UclStackRunning = TRUE;
            return E_OK;
        }
    }
    // Temporary fix End
    return E_OK;
}

static Std_ReturnType CmpDiag(void)
{
    return E_NOT_OK;
}

static Std_ReturnType CmpDiagReturn(void)
{
    return E_OK;
}

Std_ReturnType CUclProxyCdd_Impl_Initialize(void)
{
	if(UclStackRunning == FALSE )
	{
		 UclGen_AsrAdapterInit(); //Fix for VIP Sleep/WakeUP or selective GIP reset sequence
		
		if (UCL_E_OK == UclSys_Initialize(0))
		{
			UclStackRunning = TRUE;
			return E_OK;
		}
	}
    return E_NOT_OK;
}

Std_ReturnType CUclProxyCdd_Impl_Shutdown(void)
{
    UclStackRunning = FALSE;

    if (UCL_E_OK == UclSys_Shutdown(0))
    {
        return E_OK;
    }
    return E_NOT_OK;
}

Std_ReturnType CUclProxyCdd_Impl_InvalidateSecurityKey(uint8 DLInst)
{
    return E_NOT_OK;
}

Std_ReturnType CUclProxyCdd_Impl_GetStatus(uint8 DLInst, uint8 *Status)
{
    return E_NOT_OK;
}
