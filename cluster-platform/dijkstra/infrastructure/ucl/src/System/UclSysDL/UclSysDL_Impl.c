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
#include "UclSysDL_Impl.h"
#include "UclDL.h"
#include "UclALOs.h"
#include "UclALDebug.h"

Ucl_ReturnType UclSysDL_Impl_IUclSys_Initialize(SUclSysDLInst *pInst, uint8 InstId)
{
  Ucl_ReturnType Ret;
  uint8 i;

  UclALDebug_Initialize(0);

  Ret = UclALOs_Initialize(0);

  if (UCL_E_OK == Ret)
  {
    for (i = 0; i < pInst->numIUclDL; i++)
    {
      Ret = UclDL_Initialize(pInst->pIUclDL[i]);
      if (UCL_E_OK != Ret)
      {
        break;
      }
    }
  }

  if (Ret == UCL_E_NOK)
  {
    LOGE(0, "UclSysDL_Impl", "UclSys_Initialize: Failed %ld", Ret);
  }
  else
  {
    LOGI(0, "UclSysDL_Impl", "%s", "UclSys_Initialize: Success");
  }

  return Ret;
}

Ucl_ReturnType UclSysDL_Impl_IUclSys_Shutdown(SUclSysDLInst *pInst, uint8 InstId)
{
  Ucl_ReturnType Ret = UCL_E_NOK;
  uint8 i;

  for (i = 0; i < pInst->numIUclDL; i++)
  {
    Ret = UclDL_Shutdown(pInst->pIUclDL[i]);
    if (UCL_E_OK != Ret)
    {
      break;
    }
  }

  if (UCL_E_OK == Ret)
  {
    //Ret = UclALOs_Shutdown(0);
  }

  UclALDebug_Shutdown(0);

  return Ret;
}

Ucl_ReturnType UclSysDL_Impl_IUclSys_Task(SUclSysDLInst *pInst, uint8 InstId)
{

  UclALOs_Tick(0);

  return UCL_E_OK;
}

Ucl_ReturnType UclSysDL_Impl_IUclSys_Send(SUclSysDLInst *pInst, uint8 InstId, uint8 DLInst, SUclDLMsg *pMsg)
{
  return UclDL_Send(DLInst, pMsg);
}

void UclSysDL_Impl_IUclDLCbk_FatalError(SUclSysDLInst *pInst, uint8 InstId, uint8 Status)
{
  if (NULL != pInst->pCfg->pFatalErrorFunc)
  {
    pInst->pCfg->pFatalErrorFunc(InstId, Status);
  }
}

void UclSysDL_Impl_IUclDLCbk_MsgReceived(SUclSysDLInst *pInst, uint8 InstId, EUclDLRxStatus Status, SUclDLMsg *pMsg)
{
  if (NULL != pInst->pCfg->pMsgReceivedFunc)
  {
    pInst->pCfg->pMsgReceivedFunc(InstId, Status, pMsg);
  }
}

void UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus(SUclSysDLInst *pInst, uint8 InstId, uint16 MsgId, EUclDLAckStatus Status)
{
  if (NULL != pInst->pCfg->pMsgTransmitStatusFunc)
  {
    pInst->pCfg->pMsgTransmitStatusFunc(InstId, MsgId, Status);
  }
}

void UclSysDL_Impl_IUclDLCbk_LinkStatusChanged(SUclSysDLInst *pInst, uint8 InstId, EUclDLLinkStatus Status)
{
  if (NULL != pInst->pCfg->pLinkStatusChangedFunc)
  {
    pInst->pCfg->pLinkStatusChangedFunc(InstId, Status);
  }
}
