/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2025. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  RamTst_Cfg.h
Module Short Name:  RamTst_Cfg.h
VOBName          :  
Author           :  sgopal1
Description      :  This file contains configurations needed for RamTst
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/
#ifndef RAMTST_CFG_H
#define RAMTST_CFG_H

/******************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "Std_Types.h"

/******************************************************************************
 *  Public Macros Definitions                                                 *
 ******************************************************************************/

/**
 * @brief Macro to enable API
 */

 #define RAMTST_DEV_ERROR_DETECT                  STD_ON
 #define RAMTST_STOP_API                          STD_ON
 #define RAMTST_ALLOW_API                         STD_ON
 #define RAMTST_SUSPEND_API                       STD_ON
 #define RAMTST_RESUME_API                        STD_ON
 #define RAMTST_GET_EXECUTION_STATUS_API          STD_ON
 #define RAMTST_GET_TEST_RESULT_API               STD_ON
 #define RAMTST_GET_TEST_RESULT_PER_BLOCK_API     STD_ON
 #define RAMTST_GET_VERSION_INFO_API              STD_ON
 #define RAMTST_GET_ALG_PARAMS_API                STD_ON
 #define RAMTST_GET_TEST_ALGORITHM_API            STD_ON
 #define RAMTST_GET_NUMBER_OF_TESTED_CELLS_API    STD_ON
 #define RAMTST_SELECT_ALG_PARAMS_API             STD_ON
 #define RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API STD_ON
 #define RAMTST_RUN_FULL_TEST_API                 STD_ON
 #define RAMTST_RUN_PARTIAL_TEST_API              STD_ON
 
 /*This value should be same as RamTstNumberOfAlgParamSets in struct RamTstConfig */
 #define NO_OF_ALGPARAMS 1U

 /*This value should be same as sum of RamTstNumberOfBlocks in struct */
 #define NO_OF_BLOCKS_ALG 1U
 
 #define NO_OF_BLOCKS 1U

/* Number of cells to be tested in background mode without checking user requests (Abort, Suspend) */
#define RamTstNumberOfTestedCellsAtomic            512

/* The end value of the Test Interval Id after this maninfunction will reset the Test Interval Id as Zero. */
#define RamTstTestIntervalIdEndValue               4

/*****************************************************************************
 *  Type Declarations                                              			 *
 ******************************************************************************/

 /**
 * @brief Typedef for RamTst algorithms type
 */
typedef enum
{
    RAMTST_ALGORITHM_UNDEFINED,
    RAMTST_CHECKERBOARD_TEST,
    RAMTST_MARCH_TEST,
    RAMTST_WALK_PATH_TEST,
    RAMTST_GALPAT_TEST,
    RAMTST_TRANSP_GALPAT_TEST,
    RAMTST_ABRAHAM_TEST,
} RamTst_AlgorithmType;

/**
 * @brief Typedef for policy
 */
typedef enum
{
    RAMTEST_DESTRUCTIVE, 
    RAMTEST_NON_DESTRUCTIVE,
} RamTstTestPolicytype;

/**
 * @brief Typedef for block config structure
 */
typedef struct
{
    uint16 RamTstBlockId;
    uint32 RamTstStartAddress;
    uint32 RamTstEndAddress;
    uint32 RamTstFillPattern;
    RamTstTestPolicytype RamTstTestPolicy;
    uint32 RamTstDataBackUpAreaStart;
} RamTstBlockParamstype;

/**
 * @brief Typedef for  algorithms config structure
 */
typedef struct
{
    uint8 RamTstAlgParamsId;
    RamTst_AlgorithmType RamTstAlgorithm;
    uint32 RamTstExtNumberOfTestedCells;
    uint32 RamTstMaxNumberOfTestedCells;
    uint16 RamTstNumberOfBlocks;
    uint32 RamTstNumberOfTestedCells;
    const RamTstBlockParamstype *BlockPtr;
    uint32 RamTstDataBackUpAreaEnd;
} RamTstAlgParamstype;
/**
 * @brief Typedef for RamTst notification
 */
typedef void (*RamTstNotify)(void);
/**
 * @brief Typedef for RamTst configuration structure
 */
typedef struct
{
    uint8 RamTstDefaultAlgParamsId;
    uint32 RamTstMinNumberOfTestedCells;
    uint32 RamTstNumberOfAlgParamSets;
    RamTstNotify RamTstTestCompletedNotification;
    RamTstNotify RamTstTestErrorNotification;    //need to do type bbaskara
} RamTst_ConfigType;

void RAMTST_ENTERCRITICALSECTION(void);
 
void RAMTST_EXITCRITICALSECTION(void);
/*****************************************************************************
 *  Public Forward Declarations                                          	 *
 ******************************************************************************/
extern const RamTstBlockParamstype BlockConfig_1[NO_OF_BLOCKS_ALG];
extern const RamTstAlgParamstype Algconfig[NO_OF_ALGPARAMS];
extern const RamTst_ConfigType RamTstConfig;
#endif //RAMTST_CFG_H//
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 25-02-2025                                            */
/*Version           :                                                       */
/*By                : sgopal1                                               */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/