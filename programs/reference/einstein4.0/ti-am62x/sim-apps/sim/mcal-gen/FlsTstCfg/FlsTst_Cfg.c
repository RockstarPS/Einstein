/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2018. Visteon Corporation owns all rights to           *
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
/*!***************************************************************************
 * @ingroup
 * @file FlsTst_Cfg.c
 * @brief Configuration definitions for Flstst inputs
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "FlsTst_Cfg.h"
#include "FlsTst.h"

/*****************************************************************************
 *  Configuration Definitions                                                 *                                                                           *
 ******************************************************************************/
#define FLSTST_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/**
 * @brief Filters and their array index used for Analog signals
 */
const FlsTstBlocktype FlsTstBlockFgnd[NO_OF_FNG_BLOCK] = { { 0x0, 0x1FFE0100,
        0x1FFE04FF, 1024, FLSTST_ECC, 4 } };
const FlsTstBlocktype FlsTstBlockBgnd[NO_OF_BNG_BLOCK] = { { 0x0, 0x1FFE0100,
        0x1FFE04FF, 1024, FLSTST_ECC, 4 } };
const FlsTst_ConfigType FlsTstBlock = { &FlsTstBlockFgnd[0],
        &FlsTstBlockBgnd[0], NULL_PTR };
#define FLSTST_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*****************************************************************************
 *  Private Function Definitions                                              *
 ******************************************************************************/

#define FLSTST_START_SEC_CODE
#include "MemMap.h"

void FlsTst_ReportDetError(uint32 APIID, uint32 ErrorID)
{
        (void)APIID;
        (void)ErrorID;
}

#define FLSTST_STOP_SEC_CODE
#include "MemMap.h"

//#endif

/*End of File*/
/*****************************************************************************
 *  for each change to this file, be sure to record:                         *
 *     1.  who made the change and when the change was made                  *
 *     2.  why the change was made and the intended result                   *
 *  Following block needs to be repeated for each change
 ******************************************************************************
 *  Note: In the trace-ability column we need to trace back to the Design Doc.*
 *  For the initial version it is traced to the Design Document section.     *
 *  For further changes it shall trace to the source of the change which may *
 *  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
 *  other reason                                                            *
 ******************************************************************************/
/*****************************************************************************
 Date              :16-Jul-2020
 By                :bbaskara
 Traceability      :RTC
 Change Description:Initial Version for FlsTst implementation
 ******************************************************************************/
