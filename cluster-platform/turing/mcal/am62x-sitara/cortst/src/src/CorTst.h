/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2024. Visteon Corporation owns all rights to           *
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
#ifndef CORTST_H
#define CORTST_H
/*!***************************************************************************
 * @ingroup
 * @file CorTst.h
 * @brief Main header file for CorTst
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "Std_Types.h"
#include "CorTst_Cfg.h"
#include "Det.h"

/*****************************************************************************
 *   Macros Definitions                                                **
 ******************************************************************************/

/* Service ID defined */
#define CORTST_API_INIT					(0x0U)
#define CORTST_API_DEINIT				(0x1U)
#define CORTST_API_ABORT				(0x2U)
/*MISRA C-2012 Rule 2.5 : CORTST_API_GET_STATE is used to provide Det report error of CorTst_GetState. It will be used in future implementations*/
#define CORTST_API_GET_STATE			(0x3U)
#define CORTST_API_GET_CURRENT_STATUS	(0x4U)
#define CORTST_API_GET_SIGNATURE		(0x5U)
#define CORTST_API_GET_FGND_SIGNATURE	(0x6U)
#define CORTST_API_START				(0x7U)
#define CORTST_API_GET_VERSION_INFO		(0x8U)
#define CORTST_API_MAINFUNCTION			(0x0bU)

/* Error information defined */
/*MISRA C-2012 Rule 2.5 : CORTST_E_PARAM_INVALID is defined as per Autosar standard. It will be used in future implementations. It will not have any functional Impact*/
#define CORTST_E_PARAM_INVALID          (0x11U)  /* API parameter out of specified range */
#define CORTST_E_UNINIT                 (0x20U)  /* API service used without module initialization */
#define CORTST_E_ALREADY_INITIALIZED	(0x23U)  /* Flash Test module is already initialized */
#define CORTST_E_PARAM_POINTER   	    (0x24U)  /* For Variant PB: Configuration pointer is a NULL pointer */
#define CORTST_E_STATUS_FAILURE         (0x01U)  /* Failure within Flash Test execution state */

#define CORTST_ADDRESS_SIGNATURE   		0x101U
#define CORTST_ALU_SIGNATURE   			0x202U
/*MISRA C-2012 Rule 2.5 : CORTST_CACHE_SIGNATURE is defined as per Autosar requirement. It will be used in future implementations*/
#define CORTST_CACHE_SIGNATURE   		0x404U
/*MISRA C-2012 Rule 2.5 : CORTST_INTERRUPT_SIGNATURE is defined as per Autosar requirement. It will be used in future implementations*/
#define CORTST_INTERRUPT_SIGNATURE   	0x808U
#define CORTST_MEMORYIF_SIGNATURE   	0x1010U
/*MISRA C-2012 Rule 2.5 : CORTST_MPU_SIGNATURE is defined as per autosar requirement. It will be used in future implementation*/
#define CORTST_MPU_SIGNATURE   			0x2020U
#define CORTST_REGISTER_SIGNATURE   	0x4040U

#define CORTST_INSTANCE_ID              (0x00U)

#define CORTST_VENDOR_ID					  0x33U
#define CORTST_MODULE_ID                      103U
/*MISRA C-2012 Rule 2.5 : CORTST_AR_RELEASE_MAJOR_VERSION is defined as per Autosar Requirement. It will be used in Future Implementations*/
#define CORTST_AR_RELEASE_MAJOR_VERSION       4U
/*MISRA C-2012 Rule 2.5 : CORTST_AR_RELEASE_MINOR_VERSION is defined as per Autosar Requirement. It will be used in Future Implementations*/
#define CORTST_AR_RELEASE_MINOR_VERSION       3U
/*MISRA C-2012 Rule 2.5 : CORTST_AR_RELEASE_REVISION_VERSION  is defined as per Autosar Requirement. It will be used in Future Implementations*/
#define CORTST_AR_RELEASE_REVISION_VERSION    1U
#define CORTST_SW_MAJOR_VERSION               0U
#define CORTST_SW_MINOR_VERSION               0U
#define CORTST_SW_PATCH_VERSION               7U

/**
 * @brief Typedef for Core Test return value if a checksum/signature
 */
typedef uint32 CorTst_CsumSignatureType;
/**
 * @brief Typedef for CorTst States
 */
typedef enum
{
    CORTST_ABORT = 0x0U, CORTST_INIT, CORTST_UNINIT, CORTST_RUNNING_BGND,
} CorTst_StateType;

/**
 * @brief Typedef for test signature in background mode
 */
typedef struct
{
    uint32 SignatureValue;
    uint32 CorTstTestIntervalId;
} CorTst_CsumSignatureBgndType;

/**
 * @brief Typedef for CorTst overall Bgnd test result type
 */
typedef struct
{
    uint32 CorTstTestCurrentIntervalId;
    CorTst_ResultType result;
} CorTst_TestResultBgndType;
/*MISRA C-2012 Rule 2.3 : CorTst_TestResultBgndType is used to check the current intervalID and result of Background test. It will be used in future implementation. It will not have any functional impact*/
/**
 * @brief Typedef for CorTst state info type
 */
typedef struct
{
    CorTst_TestIdFgndType CurrentBgndBlockID;
    boolean BgndExeStatus;
    uint32 AtomicIntervalCount;
    uint32 CurrentTestIntervalId;
    CorTst_ResultType ResultBuffer;
    CorTst_ResultType OverallBngResultBuffer;

} Cortst_StateInfotype;
/*****************************************************************************
 *  Public Forward Declarations                                          	 *
 ******************************************************************************/
/*MISRA C-2012 Directive 4.5 : CORTST_INIT macro and CorTst_Init function were defined as per Autosar requirements. It will not have any functional impact*/
extern void CorTst_Init(const CorTst_ConfigType *ConfigPtr);
/*MISRA C-2012 Rule 8.5 : CorTst_MainFunction is declared based on Autosar standards. It will not have any functional impact*/
extern void CorTst_MainFunction(void);
extern void CorTst_DeInit(void);
/*MISRA C-2012 Directive 4.5 : CORTST_ABORT macro and CorTst_Abort function were defined as per Autosar requirements. It will not have any functional impact*/
extern void CorTst_Abort(void);
extern CorTst_StateType CorTst_GetState(void);
extern void CorTst_GetCurrentStatus(CorTst_ErrOkType *ErrOk);
extern CorTst_CsumSignatureBgndType CorTst_GetSignature(void);
extern CorTst_CsumSignatureType CorTst_GetFgndSignature(void);
extern Std_ReturnType CorTst_Start(CorTst_TestIdFgndType TestId);
extern void CorTst_GetVersionInfo(Std_VersionInfoType *versioninfo);
extern void Cortst_CpuTestFail(void);
extern void Cortst_AddressGenerationFail(void);
extern void Cortst_MemoryInterfaceFail(void);
/*MISRA C-2012 Rule 8.6 : CorTst_TestRegister is defined in Cortstcpu.asm file.It will not have any functional impact */
extern void CorTst_TestRegister(void);
/*MISRA C-2012 Rule 8.6 : CorTst_TestMemIf is defined in Cortstcpu.asm.It will not have any functional impact*/
extern void CorTst_TestMemIf(void);
/*MISRA C-2012 Rule 8.6 : CorTst_TestAddrGeneration is defined in Cortstcpu.asm file. It will not have any functional Impact*/
extern void CorTst_TestAddrGeneration(void);
#endif /*CorTst_H*/

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
 

