/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2012. Visteon Corporation owns all rights to           *
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
*****************************************************************************/
/*****************************************************************************
*  File Name         :  RamTst_Types.h                                       *
*  Module Short Name :  RamTst Module                                        *
*  VOBName           :                                                       *
*  Author            : sgopal1                                               *
*  Description       : This file contains the typedefs for RamTst            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Independent                                            *
*                                                                            *
******************************************************************************/
#ifndef RAMTST_TYPES_H
#define RAMTST_TYPES_H
/*****************************************************************************
 *  Include Files                                                            *
 *****************************************************************************/
#include "Std_Types.h"

/*****************************************************************************
 *   Macros Definitions                                                      *
 *****************************************************************************/

/* Error information defined */
#define RAMTST_E_STATUS_FAILURE          (0x01U) /* Failure within Flash Test execution state */
#define RamTst_E_PARAM_INVALID          (0x02U) /* API parameter out of specified range */
#define RamTst_E_UNINIT                 (0x03U) /* API service used without module initialization */
#define RamTst_E_ALREADY_INITIALIZED    (0x04U) /* Flash Test module is already initialized */
#define RamTst_E_PARAM_CONFIG           (0x05U) /* For Variant PB: Configuration pointer is a NULL pointer */
#define RamTst_E_PARAM_POINTER          (0x06U) /* Pointer is a NULL pointer */
#define RAMTST_E_OUT_OF_RANGE           (0x02U)

/**
 * @brief Typedef State of RamTst
 */
typedef enum
{
    RAMTST_EXECUTION_UNINIT = 0x0,
    RAMTST_EXECUTION_STOPPED,
    RAMTST_EXECUTION_RUNNING,
    RAMTST_EXECUTION_SUSPENDED,
} RamTst_ExecutionStatusType;

/**
 * @brief Typedef State of RamTst test result type
 */
typedef enum
{
    RAMTST_RESULT_NOT_TESTED = 0x0,
    RAMTST_RESULT_OK,
    RAMTST_RESULT_NOT_OK,
    RAMTST_RESULT_UNDEFINED,
} RamTst_TestResultType;

/**
 * @brief Typedef State of RamTst RamTst_AlgParamsIdType type
 */

typedef uint8 RamTst_AlgParamsIdType;
/**
 * @brief Typedef for number of tested RAM cells
 */

typedef uint32 RamTst_NumberOfTestedCellsType;
/**
 * @brief Typedef for RAM blocks given count in the test configuration parameters
 */

typedef uint16 RamTst_NumberOfBlocksType;

typedef unsigned long int	uintptr_t;

/**
 * @brief Typedef for test mode
 */
typedef enum
{
    /* The RAM Test is not executed. */
    RAMTST_MODE_NONE = 0,
    /* The RAM Test execute in background mode. */
    RAMTST_MODE_BACKGROUND,
    /* The RAM Test execute in foreground mode. */
    RAMTST_MODE_FOREGROUND
} RamTst_TestModeType;
/**
 * @brief Typedef for test result structure
 */
typedef struct
{
    RamTst_AlgParamsIdType CurrentBgndAlgParamsId;
    RamTst_AlgParamsIdType CurrentFgndAlgParamsId;
    RamTst_NumberOfTestedCellsType RamTst_NumberOfTestedCells;
    uint32 CurrentBgndBlockID;
    uint32 CurrentBgndstartadress;
    boolean BgndExeStatus;
} RamTst_StateInfotype;

/*****************************************************************************
 *  Public Forward Declarations                                          	 *
 ******************************************************************************/
#endif /*RAMTST_TYPES_H*/
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