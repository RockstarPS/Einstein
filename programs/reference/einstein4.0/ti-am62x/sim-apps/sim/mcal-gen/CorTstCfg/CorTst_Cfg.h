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
#ifndef CORTST_CFG_H
#define CORTST_CFG_H
/*!***************************************************************************
 * @ingroup
 * @file CorTst_Cfg.h
 * @brief Configuration header file for CorTst inputs
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "Std_Types.h"
/*****************************************************************************
 *  Public Macros Definitions                                                *
 ******************************************************************************/

/**
 * @brief Macro to enable API
 */
#define CORTST_ABORT_API					(STD_ON)
#define CORTST_GET_CURRENT_STATUS_API		(STD_ON)
#define CORTST_GET_FGND_SIGNATURE_API		(STD_ON)
#define CORTST_GET_SIGNATURE_API			(STD_ON)
#define CORTST_GET_STATE_API				(STD_ON)
#define CORTST_START_API					(STD_ON)
#define CORTST_VERSION_INFO_API				(STD_ON)
#define CORTSTNOTIFICATIONSUPPORTED			(STD_ON)

#define CORTST_MAX_BGNDTASK                     1U
#define CORTST_MAX_FGNDTASK                     1U
/*Switch for enabling test result comparison within the Core test driver.
 In this mode a core test result OK or NOTOK shall not be calculated from the core test driver.
 Within core test driver no comparison against the reference value is processed.*/
/*MISRA C-2012 Rule 2.5 : CorTstTestResultMode will be used in future implementation. It will not have any functional Impact*/
#define CorTstTestResultMode			(STD_OFF)
/* Number of configuration to be tested in background mode without checking user requests (Abort) */
#define CorTstNumberconfigurationAtomic            1U
/* Number of configuration to be tested in Fackground mode */
#define CORTSTFGNDTESTNUMBER                 1U
/* Number of configuration to be tested in background mode */
#define CORTSTBGNDTESTNUMBER                 1U

/* The end value of the Test Interval Id after this mainfunction will reset the Test Interval Id as Zero. */
#define CorTstTestIntervalIdEndValue               4U

/*****************************************************************************
 *  Type Declarations                                              			 *
 ******************************************************************************/
/**
* @brief Typedef for test enable or disable type
*/
typedef enum
{
    SELECTED, NOT_SELECTED,
} testype;
/**
 * @brief Typedef for CorTst Fgnd test ID type
 */
typedef uint32 CorTst_TestIdFgndType;
/**
 * @brief Typedef for block config structure
 */
typedef struct
{
    CorTst_TestIdFgndType testId;
    testype CorTstAddress;
    testype CorTstAlu;
    testype CorTstCache;
    testype CorTstInterrupt;
    testype CorTstMemoryIf;
    testype CorTstMpu;
    testype CorTstRegister;
} CorTstSelect;

/**
 * @brief Typedef for CorTst result type
 */
typedef enum
{
    CORTST_E_NOT_OK = 0x0, CORTST_E_OKAY, CORTST_E_NOT_TESTED,
} CorTst_ResultType;

/**
 * @brief Typedef for CorTst error information type
 */
typedef struct
{
    uint32 CorTstTestIntervalId;
    CorTst_ResultType returnvalue;
} CorTst_ErrOkType;

/**
 * @brief Typedef for CorTst notification function
 */
typedef void (*CorTstNotify)(CorTst_ErrOkType ResultOfLastCorTstRun);


/**
 * @brief Typedef for CorTst config structure
 */
typedef struct
{
    /*MISRA C-2012 Rule 5.8 : As per visteon coding standard the configuration is done for CorTstBlockBgnd where pointer name is same as external linkage name. This implementation does not have functional impact*/
    const CorTstSelect *CorTstBlockFgnd;
    /*MISRA C-2012 Rule 5.8 : As per visteon coding standard the configuration is done for CorTstBlockBgnd where pointer name is same as external linkage name. This implementation does not have functional impact*/
    const CorTstSelect *CorTstBlockBgnd;
    CorTstNotify CorTst_TestCompletedNotification;
} CorTst_ConfigType;

/*****************************************************************************
 *  Public Forward Declarations                                          	 *
 ******************************************************************************/
extern const CorTstSelect CorTstBlockFgnd[CORTSTFGNDTESTNUMBER];
extern const CorTstSelect CorTstBlockBgnd[CORTSTBGNDTESTNUMBER];
extern const CorTst_ConfigType CorTstBlock;

#endif /* CorTst_CFG_H */

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
 
