/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2025. Visteon Corporation owns all rights to           *
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
*  File Name         :  RamTst.h                                             *
*  Module Short Name :  RamTst                                               *
*  Description       :  RamTst main layer which handles the Init,            *
*                       Mainfunctions and APIs for SWCs                      *
*  Organization     :   Driver Information Software Section,                 *
*                       Visteon Software Operation                           *
*                       Visteon Corporation                                  *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                         *
* Target Hardware  :  AM62PX micro based Hardware Platform                   *
*                                                                            *
******************************************************************************/
#ifndef RAMTST_H
#define RAMTST_H
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "Std_Types.h"
#include "RamTst_Types.h"
#include "RamTst_Cfg.h"
#include "SysTst_Cfg.h"

/*****************************************************************************
 *   Macros Definitions                                                      *
 *****************************************************************************/
/* Service ID defined */
#define RAMTST_API_INIT                          (0x00U)
#define RAMTST_API_DEINIT                        (0x0CU)
#define RAMTST_API_STOP                          (0x02U)
#define RAMTST_API_ALLOW                         (0x03U)
#define RAMTST_API_SUSPEND                       (0x0DU)
#define RAMTST_API_RESUME                        (0x0EU)
#define RAMTST_API_GET_EXECUTION_STATUS          (0x04U)
#define RAMTST_API_GET_TEST_RESULT               (0x05U)
#define RAMTST_API_GET_TEST_RESULT_PER_BLOCK     (0x06U)
#define RAMTST_API_GET_VERSION_INFO              (0x0AU)
#define RAMTST_API_GET_ALG_PARAMS                (0x12U)
#define RAMTST_API_GET_TEST_ALGORITHM            (0x07U)
#define RAMTST_API_GET_NUMBER_OF_TESTED_CELLS    (0x09U)
#define RAMTST_API_SELECT_ALG_PARAMS             (0x0BU)
#define RAMTST_API_CHANGE_NUMBER_OF_TESTED_CELLS (0x08U)
#define RAMTST_API_RUN_FULL_TEST                 (0x10U)
#define RAMTST_API_RUN_PARTIAL_TEST              (0x11U)
#define RAMTST_API_MAIN_FUNCTION                 (0x01U)

/**
 * @brief Typedef for test result structure
 */
typedef struct
{
    RamTst_TestResultType BlockResult[NO_OF_ALGPARAMS][NO_OF_BLOCKS];
    RamTst_TestResultType Result;
} RamTst_TestOverallResultType;
/*****************************************************************************
 *  Public Forward Declarations                                          	 *
 *****************************************************************************/
extern void RamTst_Init(const RamTst_ConfigType *ConfigPtr);
extern void RamTst_MainFunction(void);
extern void RamTst_DeInit(void);
extern void RamTst_Stop(void);
extern void RamTst_Allow(void);
extern void RamTst_Suspend(void);
extern void RamTst_Resume(void);
extern RamTst_ExecutionStatusType RamTst_GetExecutionStatus(void);
extern void RamTst_GetVersionInfo(const Std_VersionInfoType *versioninfo);
extern RamTst_TestResultType RamTst_GetTestResult(void);
extern RamTst_TestResultType RamTst_GetTestResultPerBlock(RamTst_NumberOfBlocksType BlockID);
extern RamTst_AlgParamsIdType RamTst_GetAlgParams(void);
extern RamTst_AlgorithmType RamTst_GetTestAlgorithm(void);
extern RamTst_NumberOfTestedCellsType RamTst_GetNumberOfTestedCells(void);
extern void RamTst_SelectAlgParams(RamTst_AlgParamsIdType NewAlgParamsId);
extern void RamTst_ChangeNumberOfTestedCells(RamTst_NumberOfTestedCellsType NewNumberOfTestedCells);
extern void RamTst_RunFullTest(void);
extern void RamTst_RunPartialTest(RamTst_NumberOfBlocksType BlockId);

#endif /*RAMTST_H*/
/*End of File*/
/*****************************************************************************
*     End of File
*
*******************************************************************************/
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