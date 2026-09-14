/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
 *  File Name         :  DltExt_MemCfg.h                                             *
 *  Module Short Name :  DltExt_MemCfg.h                                               *
 *  Description       :  This file contains implementations of the Diagnostic *
 *                       Log and Trace Extension                              *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS Multi                                              *
 * Target Hardware  :  Platform Independent                                   *
 *                                                                            *
 ******************************************************************************/
#ifndef DLTEXT_MEMCFG_H
#define DLTEXT_MEMCFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

#define DLTEXT_LAST_REST_HISTORY_NUM    (uint8)(5u)
#define DLTEXT_LAST_APP_HISTORY_NUM     (uint8)(8u)
#define ADDITIONAL_DATA_SIZE            (uint8)(5u)

#define DLT_FAULT_TYPE_OFST             (uint8)(8u) /* Use MSB for fault type  --> to be moved to Dlt_Type.c */
#define NUM_TYPE_CODES                  (uint8)(7u) /* --> to be moved to Dlt_Type.c */
#define DLT_NUM_ERROR_CODE              (uint8)(75u)
#define DLT_NUM_ERROR_CFG               (uint8)(49u)
#define RESET_CODE_DEFAULT              (uint16)(0x0000u)
#define DLTEXT_TYPE2_ROUTINE            (uint8)(0x02u) /* Value that indicates a Type 2 routine */
#define DLTEXT_ROUTINE_COMPLETED        (uint8)(0x00u)
#define DLTEXT_ROUTINE_ACTIVE           (uint8)(0x02u)
#define DLTEXT_MAX_NVM_SIZE             (uint8)(160u)
#define DLTEXT_MAX_RESETCODE_SIZE       (uint8)(12u)

/*KPI related macros*/
#define DLTEXT_NUM_KPI                  (uint8)(4u) 
#define DLTEXT_KPI1_SIZE                (uint8)(10u) /*Size of each Kpi event in the cyclic buffer */ 
#define DLTEXT_KPI2_SIZE                (uint8)(5u)
#define DLTEXT_KPI3_SIZE                (uint8)(5u)
#define DLTEXT_KPI4_SIZE                (uint8)(16u)
#define DLTEXT_NUM_KPI_METRIC           (uint8)(36u) /*Max size of the KPI metrics array*/

#endif /* DLTEXT_MEMCFG_H */


