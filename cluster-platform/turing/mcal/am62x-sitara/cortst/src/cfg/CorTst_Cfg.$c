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
#ifndef CORTST_CFG_C
#define CORTST_CFG_C
/*!***************************************************************************
 * @ingroup
 * @file CorTst_Cfg.c
 * @brief Configuration definitions for Cortst inputs
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "CorTst_Cfg.h"
#include "CorTst.h"

/*****************************************************************************
 *  Configuration Definitions                                                 *                                                                           *
 ******************************************************************************/
/*MISRA C-2012 Rule 2.5 : As per visteon standard CORTST_START_SEC_CONST_UNSPECIFIED is used. It will not have any functional impact*/
#define CORTST_START_SEC_CONST_UNSPECIFIED
#include "CorTst_MemMap.h"

/**
 * @brief Array blocks with test Id and test types to be performed
 */
const CorTstSelect CorTstBlockFgnd[CORTST_MAX_FGNDTASK] =
    { 
        {
            1 /*testId/index */,
            SELECTED /* CorTstAddress */,
            SELECTED /* CorTstAlu */, 
            NOT_SELECTED /* CorTstCache */,
            NOT_SELECTED /* CorTstInterrupt */,
            SELECTED /* CorTstMemoryIf */, 
            NOT_SELECTED /* CorTstMpu */,
            SELECTED /* CorTstRegister */
        }
    };
const CorTstSelect CorTstBlockBgnd[CORTST_MAX_BGNDTASK] = 
    { 
        { 
            1 /*testId/index */,
            SELECTED /* CorTstAddress */,
            SELECTED /* CorTstAlu */, 
            NOT_SELECTED /* CorTstCache */,
            NOT_SELECTED /* CorTstInterrupt */,
            SELECTED /* CorTstMemoryIf */, 
            NOT_SELECTED /* CorTstMpu */,
            SELECTED /* CorTstRegister */
        }
    };
const CorTst_ConfigType CorTstBlock = 
    { &CorTstBlockFgnd[0],&CorTstBlockBgnd[0], NULL_PTR };

/*MISRA C-2012 Rule 2.5 : As per visteon standard CORTST_STOP_SEC_CONST_UNSPECIFIED is used. It will not have any functional impact*/
#define CORTST_STOP_SEC_CONST_UNSPECIFIED
/*MISRA C-2012 Rule 20.1 : As per visteon standard CorTst_MemMap.h is used. It will not have any functional impact*/
#include "CorTst_MemMap.h"

/*****************************************************************************
 *  Private Function Definitions                                              *
 ******************************************************************************/

#endif /*CORTST_CFG_C*/

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
/**-------------------------------------------------------------------------*/
/*Date              : 24-02-2025                                            */
/*Version           :                                                       */
/*By                : kporkodi                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/
 
