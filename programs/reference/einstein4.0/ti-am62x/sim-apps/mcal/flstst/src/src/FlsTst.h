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
 * @file FlsTst.h
 * @brief Main header file for FlsTst
 * ****************************************************************************/
#ifndef FLSTST_H
#define FLSTST_H
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "Std_Types.h"
#include "FlsTst_Cfg.h"

/*****************************************************************************
 *   Macros Definitions                                                **
 ******************************************************************************/

/* Service ID defined */
#define FLSTST_API_INIT                 (0x00U)
#define FLSTST_API_DEINIT               (0x01U)
#define FLSTST_API_STARTFGND            (0x02U)
#define FLSTST_API_ABORT                (0x03U)
#define FLSTST_API_SUSPEND              (0x04U)
#define FLSTST_API_RESUME               (0x05U)
#define FLSTST_API_GETCURRENTSTATE      (0x06U)
#define FLSTST_API_GETTESTRESULTBGND    (0x07U)
#define FLSTST_API_GETVERSIONINFO       (0x08U)
/*#define FLSTST_API_GETTESTSIGNATUREBGND (0x09U)
#define FLSTST_API_GETTESTSIGNATUREFGND (0x0AU)*/
#define FLSTST_API_GETERRORDETAILS      (0x0BU)
#define FLSTST_API_TESTECC              (0x0CU)
#define FLSTST_API_MAINFUNCTION         (0x0DU)

/* Error information defined */
#define FLSTST_E_STATE_FAILURE          (0x01U) /* Failure within Flash Test execution state */
#define FLSTST_E_PARAM_INVALID          (0x02U) /* API parameter out of specified range */
#define FLSTST_E_UNINIT                 (0x03U) /* API service used without module initialization */
#define FLSTST_E_ALREADY_INITIALIZED    (0x04U) /* Flash Test module is already initialized */
#define FLSTST_E_PARAM_CONFIG           (0x05U) /* For Variant PB: Configuration pointer is a NULL pointer */
#define FLSTST_E_PARAM_POINTER          (0x06U) /* Pointer is a NULL pointer */

/**
 * @brief Typedef for FgndBlockId type
 */
typedef uint32 FlsTst_BlockIdFgndType;
/**
 * @brief Typedef for FlsTst state
 */
typedef enum
{
    FLSTST_UNINIT = 0x0,
    FLSTST_INIT,
    FLSTST_RUNNING,
    FLSTST_ABORTED,
    FLSTST_SUSPENDED,
} FlsTst_StateType;

/**
 * @brief Typedef for FlsTst test result type
 */
typedef enum
{
    FLSTST_RESULT_NOT_TESTED = 0x0, FLSTST_RESULT_OK, FLSTST_RESULT_NOT_OK,
} FlsTst_TestResultType;

/**
 * @brief Typedef for FlsTst Fgnd test result type
 */
typedef enum
{
    FLSTST_NOT_TESTED = 0x0, FLSTST_OK = 0x1, FLSTST_NOT_OK,
} FlsTst_TestResultFgndType;

/**
 * @brief Typedef for FlsTst overall Bgnd test result type
 */
typedef struct
{
    uint32 FlsTstTestCurrentIntervalId;
    FlsTst_TestResultType result;
} FlsTst_TestResultBgndType;

/**
 * @brief Typedef for FlsTst specific error information type
 */
typedef struct
{
    FlsTst_TestResultType result;
    uint32 BitError;
    uint32 blockID;
} FlsTst_ErrorDetailsType;

/**
 * @brief Typedef for  FlsTst state info type.
 */
typedef struct
{
    uint32 CurrentFgndBlockID;
    FlsTst_TestResultFgndType FgndResultBuffer[NO_OF_FNG_BLOCK];
    boolean FgndExeStatus;
    FlsTst_ErrorDetailsType FgndErrorInfo;
    uint32 CurrentBgndBlockID;
    uint32 CurrentBgndstartadress;
    FlsTst_TestResultType BgndResultBuffer[NO_OF_BNG_BLOCK];
    boolean BgndTestloopCount;
    boolean BgndExeStatus;
    uint32 AtomicIntervalCount;
    uint32 CurrentTestIntervalId;
    FlsTst_TestResultType OverallBngResultBuffer;
    FlsTst_ErrorDetailsType BgndErrorInfo;

} Flstst_StateInfotype;
/*****************************************************************************
 *  Public Forward Declarations                                          	 *
 ******************************************************************************/
extern Flstst_StateInfotype FlsTst_Infoptr;
extern void FlsTst_Init(const FlsTst_ConfigType *ConfigPtr);
extern void FlsTst_MainFunction(void);
extern void FlsTst_DeInit(void);
extern Std_ReturnType FlsTst_StartFgnd(FlsTst_BlockIdFgndType FgndBlockId);
extern void FlsTst_Abort(void);
extern void FlsTst_Suspend(void);
extern void FlsTst_Resume(void);
extern FlsTst_StateType FlsTst_GetCurrentState(void);
extern FlsTst_TestResultBgndType FlsTst_GetTestResultBgnd(void);
extern FlsTst_TestResultFgndType FlsTst_GetTestResultFgnd(void);
extern void FlsTst_GetVersionInfo(Std_VersionInfoType *versioninfo);
// extern FlsTst_TestSignatureBgndType FlsTst_GetTestSignatureBgnd( void );
// extern FlsTst_TestSignatureFgndType FlsTst_GetTestSignatureFgnd( void );
extern FlsTst_ErrorDetailsType FlsTst_GetErrorDetails(void);
extern Std_ReturnType FlsTst_TestEcc(void);

#endif //FlsTst_H

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
 Date              :02-Jul-2020
 By                :bbaskara
 Traceability      :RTC
 Change Description:Initial Version for FlsTst implementation
 ******************************************************************************/

