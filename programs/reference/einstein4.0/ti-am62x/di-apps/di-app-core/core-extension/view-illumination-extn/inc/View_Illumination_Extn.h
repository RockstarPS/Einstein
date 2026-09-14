/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2025. Visteon Corporation owns all rights to this work and
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
#ifndef VIEW_ILLUMINATION_EXTN_H
#define VIEW_ILLUMINATION_EXTN_H
/*==========================================================================*/
#include "Rte_Type.h"
#include "View_Illumination.h"
#include "Rte_View_Illumination.h" 
#include "View_Illumination_Cfg.h"

void IoHwAb_Data_Out(uint16 data, uint8 type);
void UCL_Data_Out(uint16 data, uint8 type);
void CAN_Data_Out(uint16 data, uint8 type);

void ViewIllumination_InputAdapter(View_Ip *l_View_Ip);


#define FUTILITY_UNUSED_VAR(x) (void)(x)



#endif
/*==========================================================================*/
/*============================================================================
**
** Date              : 16-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-17658
** Change Description: View-Illumination-Extn - Inital version
**
**============================================================================*/
/*============================================================================
**
** Date              : 27-06-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-23936
** Change Description: View-Illumination-Extn - Version 2
**
**============================================================================*/

