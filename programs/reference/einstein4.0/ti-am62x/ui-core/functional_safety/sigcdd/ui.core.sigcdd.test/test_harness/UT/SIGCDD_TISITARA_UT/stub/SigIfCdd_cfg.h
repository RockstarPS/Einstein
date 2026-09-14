/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2021. Visteon Corporation owns all rights to this work and
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
 **============================================================================
 **
 ** Name:           SigIfCdd_cfg.h
 **
 ** Description:    
 **
 ** Organization:   HMI COC, Visteon.
 **
 **============================================================================
 **
 **==========================================================================*/
#ifndef SIG_IF_CDD_CFG_H
#define SIG_IF_CDD_CFG_H
/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*
** Configure the macro SIGNATURE_UNITS_TO_USE as below.
**  
** Define 0 for SIGNATURE_UNITS_TO_USE if SigUnit 0 to use.
** Define 1 for SIGNATURE_UNITS_TO_USE if SigUnit 1 to use.
** Define 2 for SIGNATURE_UNITS_TO_USE if SigUnit 0 and 1 to use.
*/

#define SIGNATURE_UNITS_TO_USE  (0U)       /* TIDSS has 2 Signature Units */

/* 
** Window 0 is mapped to VP Safety Region 0 ( CSL_DSS_VP_SAFETY_REGION_0 )
** Window 1 is mapped to VP Safety Region 1 ( CSL_DSS_VP_SAFETY_REGION_1 )
** Window 2 is mapped to VP Safety Region 2 ( CSL_DSS_VP_SAFETY_REGION_2 )
** Window 3 is mapped to VP Safety Region 3 ( CSL_DSS_VP_SAFETY_REGION_3 )
*/

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*
** SIG_WIN_SETUP_T is required for the driver API as well as in the HMI code to pass the win configuration.
** If it's not defined in RTE/Application code, this can be uncomment here
*/
#ifndef Rte_TypeDef_SIG_WIN_SETUP_T
#define Rte_TypeDef_SIG_WIN_SETUP_T
typedef struct
{
  UINT32 control;       /*!<Bit0 (EnEvalWin)    1: Enable Safety Window, 0: Disable Safety Window */
  UINT16 winsx;         /*!<CRC window start x-14bits */
  UINT16 winsy;         /*!<CRC window start y-14bits */
  UINT16 winex;		    /*!<CRC window end x-14bits */
  UINT16 winey;		    /*!<CRC window end y-14bits */
  UINT32 ref_crc;       /*!<Reference CRC */
}SIG_WIN_SETUP_T;
#endif

#ifndef Rte_TypeDef_SIG_WIN_INFO_T
#define Rte_TypeDef_SIG_WIN_INFO_T
typedef struct
{
  UINT8 sig_unit;
  UINT8 window;
} SIG_WIN_INFO_T;
#endif

#ifndef Rte_TypeDef_SIG_WIN_CRC_RGB_T
#define Rte_TypeDef_SIG_WIN_CRC_RGB_T
typedef struct
{		  
   UINT32 crc;    
}SIG_WIN_CRC_RGB_T;
#endif
/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/


#ifdef  __cplusplus
}
#endif
/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**

**
**==========================================================================*/

/* end of file =============================================================*/
#endif
