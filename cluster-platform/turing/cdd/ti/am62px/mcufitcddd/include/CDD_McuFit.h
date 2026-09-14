/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
/*!*****************************************************************************************************************
 *    @file CDD_Mcufit.h
 *    @ingroup Mcufitcdd
 *    @brief Interfaces & Instants Declaration for CDD_Mcufit
 ********************************************************************************************************************/
#ifndef CDD_MCUFIT_H
#define CDD_MCUFIT_H

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "Std_Types.h"
#include "CDD_McuFit_Cfg.h"
#include "CDD_FitManager_Cfg.h"
#include "CDD_McuFit_UserHandler.h"
#include "CDD_McuFit_Types.h"
#include "FltM_Soc.h"
#include "FltM_Soc_Cfg.h"
#include "FltM_Soc_Ppu_Cfg.h"


/*============================================================================
 ** T Y P E   D E F I N I T I O N S
 **==========================================================================*/

#define DCC_DCCGCTRL_ADDR           0x00800000U
#define DDR_CODE_APP_CHKSUM_ADDRESS 0x82600000U 
#define SINGLESHOT_MASK     ((uint32_t)((uint32_t)0xFU << 8U)) 
#define SINGLESHOT_VALUE    ((uint32_t)((uint32_t)0xFU << 8U))  

#define MAX_POK_CORES (7U)
#define POK_CHCK_UV_OV (2U)


void CDD_McuFit_InjectPPU_ReadBackFail(void);



/*============================================================================
 ** E N T R Y   P O I N T S
 **==========================================================================*/
#endif /* CDD_MCUFIT_H */

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
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
**============================================================================
Date              : 01/Dec/2023
By                : ksankara
Traceability      : 
Change Description: Initial Version
**============================================================================
**==========================================================================*/
