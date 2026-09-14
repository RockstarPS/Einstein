/*******************************************************************************
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
 ********************************************************************************
 **
 ** Name:           SigIfCdd_cfg.h
 **
 ** Description:    
 **
 ** Organization:   HMI COC, Visteon.
 **
 ********************************************************************************
 **
 *********************************************************************************/
 
#ifndef SIG_IF_CDD_CFG_H
#define SIG_IF_CDD_CFG_H

/*******************************************************************************
**                  Include files
*********************************************************************************/
#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

/*
** TIDSS has 2 Signature Units supported
** Configure the macro SIGNATURE_UNITS_TO_USE as below.
**  
** if SigUnit#0 to use, 
** #define SIGNATURE_UNITS_TO_USE       (0U)
**
** if SigUnit#1 to use,
** #define SIGNATURE_UNITS_TO_USE       (1U)
**
** if both SigUnit#0 and SigUnit#1 to use,
** #define SIGNATURE_UNITS_TO_USE       (2U)
*/

#define SIGNATURE_UNITS_TO_USE          (0U)

#define CONFIG_DSS_NUM_SAFETY_REGIONS          1U
/*******************************************************************************
** E N T R Y   P O I N T S
*********************************************************************************/


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
