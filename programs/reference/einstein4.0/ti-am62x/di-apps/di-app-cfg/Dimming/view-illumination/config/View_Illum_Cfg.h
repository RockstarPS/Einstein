/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2017 -2018. Visteon Corporation owns all rights to this work and
 ** intends to maintain it in confidence to preserve its trade secret status.
 ** Visteon Corporation reserves the right, under the copyright laws of the
 ** United States or those of any other country that may have jurisdiction,
 ** to protect this work as an unpublished work, in the event of an
 ** inadvertent or deliberate unauthorized publication. Visteon Corporation
 ** also reserves its rights under all copyright laws to protect this work as
 ** a published work, when appropriate. Those having access to this work may
 ** not copy it, use it, modify it or disclose the information contained in
 ** it without the written authorization of Visteon Corporation.
 **
 **==========================================================================*/
#ifndef VIEW_ILLUM_CFG_H
#define VIEW_ILLUM_CFG_H
/*============================================================================*/
#include "View_Illumination_Extn.h"
#include "View_Illumination.h"
#include "Rte_View_Illumination.h"
#include "Rte_Type.h"


#define RTE_READ_ILLUMCTRL_OP(pdata)   Rte_Read_View_Illumination_rp_IllumCtrl_Op_IllumCtrl_Op_Data(pdata)


#define SEND_TO_IOHWAB(pdata,type)       IoHwAb_Data_Out(pdata,type) 
#define SEND_TO_UCL(pdata,type)            UCL_Data_Out(pdata,type) 
#define SEND_TO_CAN(pdata,type)           CAN_Data_Out(pdata,type)

#define VIEW_ILLUMINATION_INPUT_ADAPATER(pdata)  ViewIllumination_InputAdapter(pdata)






#endif
/*============================================================================*/
/*============================================================================
**
** Date              : 16-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-17414
** Change Description: View-Illumination - Config - Inital version
**
**============================================================================*/
