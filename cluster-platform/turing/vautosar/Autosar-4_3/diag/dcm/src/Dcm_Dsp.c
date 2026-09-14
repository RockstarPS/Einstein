/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2016. Visteon Corporation owns all rights to           *
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
#ifndef DCM_DSP_C
#define DCM_DSP_C
/*****************************************************************************
 *  File Name         :  Dcm_Dsp.c                                            *
 *  Module Short Name :  DiagMgr                                              *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response Service processing functionalities          *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS                                                    *
 * Target Hardware  :                                                         *
 *                                                                            *
 ******************************************************************************/
/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Dcm.h"
#include "Dcm_Dsp.h"
#include "Dcm_Dsd.h"
#include "Dcm_Cbk.h"
#include "Dcm_Internal.h"
#include "Dem.h"
#include "Dem_Dcm.h"
#include "NvM.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

#if(DCM_SVC_22_SUPPORT_ENABLED == STD_ON)
#define DCM_DSP_DID_READ                    0x01U
#define DCM_DIDMGR_OP_READ                  0x01U
#define DCM_DIDMGR_OPTYPE_READ              0x01U
#define DCM_DIDMGR_OPTYPE_READCHKCOND       0x03U
#define DCM_DIDMGR_OPCLS_READ_SYNC          0x01U
#define DCM_DIDMGR_OPCLS_READ_ASYNC         0x02U
#endif

#if(DCM_SVC_2E_SUPPORT_ENABLED == STD_ON)
#define DCM_DSP_DID_WRITE                   0x02U
#define DCM_DIDMGR_OP_WRITE                 0x02U
#define DCM_DIDMGR_OPTYPE_WRITE             0x02U
#define DCM_DIDMGR_OPCLS_WRITE_SYNC         0x01U
#define DCM_DIDMGR_OPCLS_WRITE_ASYNC        0x02U
#endif

#if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
#define DCM_DSP_DID_IO                      0x04U
#define DCM_DIDMGR_OP_IO                    0x04U
#define DCM_DIDMGR_OPTYPE_IO                0x04U
#define DCM_DIDMGR_OPTYPE_IO_RETCTRL2ECU    0x01U
#define DCM_DIDMGR_OPTYPE_IO_RST2DEF        0x02U
#define DCM_DIDMGR_OPTYPE_IO_FRZCURSTATE    0x04U
#define DCM_DIDMGR_OPTYPE_IO_SHRTTRMADJ     0x08U

# define DCM_DSP_RETCTRL2ECU                0x00U
# define DCM_DSP_RST2DEF                    0x01U
# define DCM_DSP_FRZCURSTATE                0x02U
# define DCM_DSP_SHRTTRMADJ                 0x03U
#endif

#if(DCM_SVC_31_SUPPORT_ENABLED == STD_ON)
#define S31_MAX_SUPPORTED_SUB_FUNCTION      0x03U

#define DCM_DSP_RID_START                   0x01U
#define DCM_DSP_RID_STOP                    0x02U
#define DCM_DSP_RID_RESULTS                 0x03U
#endif

#if(DCM_SVC_10_SUPPORT_ENABLED == STD_ON)
/* Extract a concrete byte of a WORD */
# define Dsp_UtiGetHiByte(data16)           ((uint8)(((uint16)(data16))>>8))         /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define Dsp_UtiGetLoByte(data16)           ((uint8)(((uint16)(data16)) & 0xFFu))    /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define DSP_Diag_Entered                    0x04U
#endif

#define DSP_PerformHardReset                0x01U
#define DSP_Fbl_EntryReset                  0x02U

#if(DCM_SVC_19_SUPPORT_ENABLED == STD_ON)
# define DEM_SETFILTER_CLASS_01             ((Dcm_Svc19DemSetFilterClassType)0U) /* SF 0x01, 0x02, 0x0A */
# define DEM_SETFILTER_CLASS_02             ((Dcm_Svc19DemSetFilterClassType)1U) /* SF 0x07, SF 0x08, SF 0x09*/
# define DEM_SETFILTER_CLASS_03             ((Dcm_Svc19DemSetFilterClassType)2U) /* SF 0x11, 0x0F  */
# define DEM_SETFILTER_CLASS_04             ((Dcm_Svc19DemSetFilterClassType)3U) /* SF 0x12, 0x13 */
# define DEM_SETFILTER_CLASS_05             ((Dcm_Svc19DemSetFilterClassType)4U) /* SF 0x15 */
# define DEM_SETFILTER_CLASS_06             ((Dcm_Svc19DemSetFilterClassType)5U) /* SF 0x17 */
# define DEM_SETFILTER_NUM_CLASSES          (DEM_SETFILTER_CLASS_06+1U)

# define DCM_SVC_19_USE_MASK_REQ            ((Dcm_Svc19DemSetFilterMaskUsageType)0U)
# define DCM_SVC_19_USE_MASK_ALL            ((Dcm_Svc19DemSetFilterMaskUsageType)1U)
#endif

#define DCM_SESSION_STATE_CHECK(StateRef, Session)             (((Dcm_DsdStateRef[StateRef].Session) & (0x01u << Session)) != DCM_FALSE)
#define DCM_SECURITY_STATE_CHECK(StateRef, Security)            (((Dcm_DsdStateRef[StateRef].Security) & (0x01u << Security)) != DCM_FALSE)

#if(DCM_SVC_3E_SUPPORT_ENABLED == STD_ON)
#define DCM_S3E_ZEROSUBFUNCTION             0x0U
#endif

#define DCM_MIN_REQ_LENGTH                  1U

#define DCM_DSP_0x01u                       0x01U
#define DCM_DSP_0x02u                       0x02U
#define DCM_DSP_0x03u                       0x03U
#define DCM_DSP_0x04u                       0x04U
#define DCM_DSP_0x05U                       0x05U
#define DCM_DSP_0x06u                       0x06U
#define DCM_DSP_0x08U                       (uint8)8U
#define DCM_DSP_16U                         (uint8)16U
#define DCM_DSP_100U                        100U
#define DCM_DSP_255U                        255U
#define DCM_DSP_127U                        127U
#define DCM_DSP_0x0AU                       0x0AU
#define DCM_DSP_0x0EU                       0x0EU
#define DCM_DSP_0x3FU                       0x3FU
#define DCM_DSP_0x40U                       0x40U
#define DCM_DSP_0x07U                       0x07U
#define DCM_DSP_0xAAU                       0xAAU
#define DCM_DSP_0xF0U                       0xF0U
#define DCM_DSP_0x0FU                       0x0FU
#define DCM_DSP_0xFFU                       0xFFU
#define DCM_DSP_0xFEU                       0xFEU
#define DCM_DSP_0XFFFFFFU                   0XFFFFFFUL
#define DCM_DSP_0xAAAAAAAAU                 0xAAAAAAAAUL
#define DCM_DSP_0xFFFFFFFEuL                0xFFFFFFFEUL

#if((DCM_SVC_34_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_35_SUPPORT_ENABLED == STD_ON) || \
    (DCM_SVC_36_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_37_SUPPORT_ENABLED == STD_ON))
#define DCM_DATA_TRANSFER_STATE_IDLE                           (0x00U) /*!< Setup download */
#define DCM_DOWNLOAD_STATE_READY_FOR_TRANSFER                  (0x01U) /*!< Ready and waiting for downloading */
#define DCM_UPLOAD_STATE_READY_FOR_TRANSFER					   (0x02U) /*!< Ready and waiting for uploading */
#define DCM_DOWNLOAD_STATE_IN_PROGRESS                         (0x03U) /*!< Transfer and write the data to the memory */
#define DCM_UPLOAD_STATE_IN_PROGRESS                           (0x04U)
#define DCM_DATA_TRANSFER_DONE_STATE                           (0x05U)
#endif

#if(DCMEXT_PROG_MAGIC_FLAG_HANDLER != STD_ON)
# pragma ghs section data = ".fbl_magic_flag"
uint32 APPLN_REQUEST = 0U;
uint8 fblAppMagicFlag[4] =
{ 0xFFu, 0xFEu, 0xFDu, 0xFCu };
# pragma ghs section data =default
#endif

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/
#if(DCM_SVC_19_SUPPORT_ENABLED == STD_ON)
typedef uint8 Dcm_Svc19DemSetFilterClassType;
typedef uint8 Dcm_Svc19DemSetFilterMaskUsageType;

struct DCM_SVC19DEMDTCFILTERINFOTYPE_TAG
{
    Dem_DTCKindType Kind;
    Dem_DTCOriginType Origin;
    Dem_FilterWithSeverityType ConsiderSeverity;
};

typedef struct DCM_SVC19DEMDTCFILTERINFOTYPE_TAG Dcm_Svc19DemDtcFilterInfoType;
#endif

#if(DCM_SVC_22_SUPPORT_ENABLED == STD_ON)
typedef struct
{
    uint16 Did[S22_MAX_SUPPORTED_DID_READ];
    Dcm_MsgLenType MaxDataLen;
    Dcm_MsgLenType resDataLen;
    Dcm_MsgLenType FinalDataLen;
    Dcm_MsgType resData;
    uint16 DidIndex;
    uint8  PosRespCounter;
    uint8  DidReqCount;
    uint8  DidProcessIndex;
    uint8  PendingIsActive;
} Dcm_Svc22InfoType;
#endif

#if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
typedef struct
{
    uint16 ActiveDid[DCM_NO_IODIDS];
    uint8 ActiveDidcount;
    Dcm_BooleanType IsActive;
} Dcm_Svc2FActiveInfoType;
#endif

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
typedef struct
{
    uint16 WindowTimeCounter;
    uint16 TesterSourceAddress;
    uint8 WindowTime;
    uint8 PreviousEventStatus;
    uint8 EventStatus;
    uint8 StatusMask;
    uint8 RequestedSession;
    Dcm_BooleanType EventOccurred;
    Dcm_BooleanType StoreEvent;
    Dcm_BooleanType RoeExpected;
} Dcm_DspROEInternalType;
#endif

/*****************************************************************************
 *                                 Const Declarations                          *
 ******************************************************************************/
#define DIAGMGR_CONST_SEC_START
#include "MemMap.h"

#if(DCM_SVC_19_SUPPORT_ENABLED == STD_ON)
static const Dcm_Svc19DemDtcFilterInfoType Dcm_Svc19DemDtcFilterInfo[DEM_SETFILTER_NUM_CLASSES] = /* PRQA S 3218 *//* MD_Dcm_CodingRule_3218 */
{
    {
        DEM_DTC_KIND_ALL_DTCS, DEM_DTC_ORIGIN_PRIMARY_MEMORY,
        DEM_FILTER_WITH_SEVERITY_NO
    } /* SF 0x01, 0x02, 0x0A */
    ,
    {
        DEM_DTC_KIND_ALL_DTCS, DEM_DTC_ORIGIN_PRIMARY_MEMORY,
        DEM_FILTER_WITH_SEVERITY_YES
    } /* SF 0x07 */
    ,
    {
        DEM_DTC_KIND_ALL_DTCS, DEM_DTC_ORIGIN_MIRROR_MEMORY,
        DEM_FILTER_WITH_SEVERITY_NO
    } /* SF 0x11, 0x0F  */
    ,
    {
        DEM_DTC_KIND_EMISSION_REL_DTCS, DEM_DTC_ORIGIN_PRIMARY_MEMORY,
        DEM_FILTER_WITH_SEVERITY_NO
    } /* SF 0x12, 0x13 */
    ,
    {
        DEM_DTC_KIND_ALL_DTCS, DEM_DTC_ORIGIN_PERMANENT_MEMORY,
        DEM_FILTER_WITH_SEVERITY_NO
    } /* SF 0x15 */
    ,
    {
        DEM_DTC_KIND_ALL_DTCS, DEM_DTC_ORIGIN_USER_MEMORY,
        DEM_FILTER_WITH_SEVERITY_NO
    } /* SF 0x17 */
};
#endif

static const Dcm_NegativeResponseCodeType Dcm_StateSessionNrcs[DSP_NUM_DIAG_CHK_LVLS] =
{
    DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION /* on SID level */
    , DCM_E_REQUESTOUTOFRANGE /* on Parameter (DID, RID, etc.) level */
    , DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION /* on SubFunction level */
};

#define DIAGMGR_CONST_SEC_END
#include "MemMap.h"
/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/
#define DIAGMGR_DATA_SEC_START
#include "MemMap.h"

#if(DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
static uint8 Request_seed_rcvd[No_of_security_level] = { 0u };

#if(S27_STATIC_SEED_SUPPORTED == TRUE)
static uint8 S27_SeedBuffer[S27_STATIC_SEED_BUFFER_SIZE] =  { 0u };
#endif

#if(S27_DELAY_SUPPORTED == TRUE)
static uint8 S27_fail_counter = 0u;
static uint32 S27_retry_delay = 0u;
#endif

#if(S27_RESET_DELAY_SUPPORTED == TRUE)
static uint16 S27_reset_delay = 0u;
#endif
#endif

#if(DCM_SVC_10_SUPPORT_ENABLED == STD_ON)
static uint8 Old_Session;
#endif

#if(DCM_SVC_28_SUPPORT_ENABLED == STD_ON)
static uint8 Communication_Status;
#endif
static uint8 Dsp_PostProcessingFlag;

#if(DCM_SVC_14_SUPPORT_ENABLED == STD_ON)
static uint32 Group_DTC;
#endif

#if((DCM_SVC_23_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_3D_SUPPORT_ENABLED == STD_ON))
#define DcmDspSupportedAddressAndLengthFormatIdentifier   0x44u
#endif

#if(DCM_SVC_19_SUPPORT_ENABLED == STD_ON)
static uint16 No_Of_Matching_DTC;
#endif

#if(DCM_SVC_22_SUPPORT_ENABLED == STD_ON)
static Dcm_Svc22InfoType Dcm_svc22Info;
#endif

#if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
static Dcm_Svc2FActiveInfoType Dcm_svc2FInfo;
#endif

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
static Dcm_DspROEInternalType Dcm_DspROEInternal[Svc86NumOfROE];
#endif

#if((DCM_SVC_34_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_35_SUPPORT_ENABLED == STD_ON) || \
    (DCM_SVC_36_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_37_SUPPORT_ENABLED == STD_ON))
static Dcm_DataTransferType Dcm_DataTransfer;
#endif

#define DIAGMGR_DATA_SEC_END
#include "MemMap.h"

/*****************************************************************************
 *                                 Locally used Function Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/
#define DIAGMGR_CODE_SEC_START
#include "MemMap.h"
#if((DCM_SVC_22_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_2E_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_2F_SUPPORT_ENABLED == STD_ON))
static uint16 Dcm_DspGetStateRefIndex(uint16 Index, uint8 Operations, uint8 ConditionRef);
#endif

#if(DCM_SVC_31_SUPPORT_ENABLED == STD_ON)
static uint8 Dcm_S31_Opindex_check(uint8 operation, uint8 subfunction);
#endif

#if(DCM_SVC_22_SUPPORT_ENABLED == STD_ON)
static Std_ReturnType Dcm_Svc22DidLookUp(uint16 *flDidIndex, Dcm_NegativeResponseCodeType *NegRes);
static Std_ReturnType Dcm_Svc22Handler(Dcm_OpStatusType OpStatus, uint16 flDidIndex, Dcm_NegativeResponseCodeType *NegRes);
#endif

#if(DCM_SVC_19_SUPPORT_ENABLED == STD_ON)
static Std_ReturnType Dcm_DspSvc19UtiDemGetNumFltrdDtc(Dcm_MsgContextType *pMsgContext);
static Std_ReturnType Dcm_DspSvc19UtiDemGetNxtFltrdDtc(Dcm_MsgContextType *pMsgContext, Dcm_BooleanType flFilterForFDC, Dcm_BooleanType flFilterForSeverity);
static Std_ReturnType Dcm_DspSvc19UtiCpyLinearData(Dcm_MsgContextType *pMsgContext, Dcm_BooleanType flFilterForFDC, Dcm_BooleanType flFilterForSeverity);
static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtFltrdDtc(Dcm_DemClientIdType DcmDemClientId,Dcm_MsgType pData, Dcm_MsgLenType *pAvailLen,
        Dcm_BooleanType flFilterForFDC);
static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtSeverityFltrdDtc(Dcm_DemClientIdType DcmDemClientId,Dcm_MsgType pData, Dcm_MsgLenType *pAvailLen,
        Dcm_BooleanType flFilterForFDC, Dcm_BooleanType flFilterForSeverity);

#if((DCM_SVC_19_01_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_19_07_SUPPORT_ENABLED == STD_ON))
static Std_ReturnType Dcm_DspSvc19UtiReportNumDtcByStatusMaskData(uint8 dsfClass, uint8 dtcStatusMask,
        uint8 dtcSeverity, Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if((DCM_SVC_19_02_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_19_0A_SUPPORT_ENABLED == STD_ON))
static Std_ReturnType Dcm_DspSvc19UtiReportDtcByStatusMaskData(uint8 dsfClass,
        Dcm_Svc19DemSetFilterMaskUsageType maskUsage,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if(DCM_SVC_19_08_SUPPORT_ENABLED == STD_ON)
static Std_ReturnType Dcm_DspSvc19UtiReportDtcBySeverityMaskData(uint8 dsfClass,uint8 dtcStatusMask,uint8 dtcSeverity,
        Dcm_Svc19DemSetFilterMaskUsageType maskUsage,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if(DCM_SVC_19_14_SUPPORT_ENABLED == STD_ON)
static Std_ReturnType Dcm_DspSvc19UtiReportDtcByFdc(uint8 dsfClass, Dcm_Svc19DemSetFilterMaskUsageType maskUsage,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if(DCM_SVC_19_03_SUPPORT_ENABLED == STD_ON)
static Std_ReturnType Dcm_DspSvc19UtiSnapshotIdentification(uint8 dsfClass, Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtFltrdRecord(Dcm_DemClientIdType DcmDemClientId, Dcm_MsgType pData, Dcm_MsgLenType *pAvailLen,
        uint8 NumberOfFilteredRecords);
#endif

#if (DCM_SVC_19_04_SUPPORT_ENABLED == STD_ON)
static Std_ReturnType Dcm_DspSvc19UtiSnapshotByDtc(uint8 dsfClass, Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif

#if (DCM_SVC_19_06_SUPPORT_ENABLED == STD_ON)
static Std_ReturnType Dcm_DspSvc19UtiExtendedData(uint8 dsfClass, Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes);
#endif
#endif

#if(DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
static Dcm_NegativeResponseCodeType Dcm_27Service_seed_Process(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, uint8 SubFunction, const uint8 Counter);
static Dcm_NegativeResponseCodeType Dcm_27Service_key_Process(Dcm_OpStatusType OpStatus, Dcm_MsgContextType  *pMsgContext, uint8 SubFunction, const uint8 Counter);
#endif

#if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
static void Dcm_2FSetActiveIODids(Dcm_DspDidIdentifierTableType Did, Dcm_MsgContextType *pMsgContext);
static void Dcm_svc2FStateChange(uint8 State);
#endif

#if(DCM_SVC_14_SUPPORT_ENABLED == STD_ON)
static Std_ReturnType Dcm_DemInternalClearProcessing(const Dcm_MsgContextType *pMsgContext,uint32 Group_DTC);
#endif


/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

/*****************************************************************************
 *                   Extern Functions                                                *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

/**************************************************************************
 Function name       : void Dsp_Init(void)
 Description         : Initializes the Diag Service Processing
 Parameters (in)     : None.
 Parameters (out)    : None
 Return value        : None
 Design Information  :
 **************************************************************************/

void Dsp_Init(void)
{
#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
    uint8 Index = 0U;
#endif

    DCMEXT_INIT();

    #if(DCM_SVC_10_SUPPORT_ENABLED == STD_ON)
    Old_Session = DCM_DEFAULT_SESSION;
    #endif

    #if(DCM_SVC_28_SUPPORT_ENABLED == STD_ON)
    Communication_Status = DCM_ENABLE_RX_TX_NORM;
    #endif

    Dsp_PostProcessingFlag = 0u;

    #if(DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
    #if(S27_DELAY_SUPPORTED == TRUE)
    S27_fail_counter = 0u;

    #if(S27_RESET_DELAY_SUPPORTED == TRUE)
    S27_reset_delay = 0u;
    #endif
    #endif /* (S27_DELAY_SUPPORTED == TRUE) */
    #endif

    #if(DCM_SVC_22_SUPPORT_ENABLED == STD_ON) 
    ClearDcm_svc22Info();
    #endif

    #if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON) 
    ClearDcm_svc2FInfo();
    #endif

    #if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
    for(Index = 0u; Index < Svc86NumOfROE; Index++)
    {
        Dcm_DspROEInternal[Index].EventOccurred = DCM_FALSE;
        Dcm_DspROEInternal[Index].StoreEvent = DCM_FALSE;
        Dcm_DspROEInternal[Index].RoeExpected = DCM_FALSE;
        Dcm_DspROEInternal[Index].EventStatus = DCM_ROE_CLEARED;
        Dcm_DspROEInternal[Index].PreviousEventStatus = DCM_ROE_CLEARED;
        Dcm_DspROEInternal[Index].StatusMask = 0x0U;
        Dcm_DspROEInternal[Index].TesterSourceAddress = 0x0U;
        Dcm_DspROEInternal[Index].RequestedSession = 0x0U;
        Dcm_DspROEInternal[Index].WindowTime = DCM_ROE_EVENT_WINDOW_CURRENT_CYCLE;
    }
    #endif

    #if(DCM_SVC_36_SUPPORT_ENABLED == STD_ON)
	Dcm_DataTransfer.Dcm_DataTransferState= DCM_DATA_TRANSFER_STATE_IDLE;
	Dcm_DataTransfer.MemAddress= 0u;
	Dcm_DataTransfer.MemSize= 0u;
	Dcm_DataTransfer.Blocklength= 0u;
	Dcm_DataTransfer.Dcm_DataTransferOldBlockCounter= 0u;
    #endif
}

/**************************************************************************
 Function name       : void Dsp_Main(void)
 Description         : Diag Service Processing Main function
 Parameters (in)     : None.
 Parameters (out)    : None
 Return value        : None
 Design Information  :
 **************************************************************************/

void Dsp_Main(void)
{
    #if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
    uint8 Index = 0u;
    Dcm_SesCtrlType flSession = 0U;
    PduInfoType flInfo = { NULL, DCM_ZERO };
    PduLengthType flBufPtr;

    flInfo.SduDataPtr = (uint8 *)Dcm_DspRoeOnDTCStatusChange.Strtrd;
    flInfo.SduLength = Svc86NumOfStrtrdParameters;
    for(Index = 0u; Index < Svc86NumOfROE; Index++)
    {
        if(DcmDspRoeEvent[Index].Prop == DCM_ROE_ONDTCSTATUSCHANGE)
        {
            if(Dcm_DspROEInternal[Index].EventStatus == DCM_ROE_STARTED)
            {
                if(Dcm_DspROEInternal[Index].EventOccurred != DCM_FALSE)
                {
                    (void)Dcm_GetSesCtrlType(&flSession);
                    if(Dcm_DspROEInternal[Index].RequestedSession == flSession)
                    {
                        if(BUFREQ_OK == Dcm_StartOfReception(Dcm_DspROEInternal[Index].TesterSourceAddress,
                                                             ( const PduInfoType *) &flInfo, (PduLengthType)Svc86NumOfStrtrdParameters, &flBufPtr))
                        {
                            if(BUFREQ_OK == Dcm_CopyRxData(Dcm_DspROEInternal[Index].TesterSourceAddress,
                                                           (const PduInfoType *)&flInfo, &flBufPtr))
                            {
                                Dcm_TpRxIndication(Dcm_DspROEInternal[Index].TesterSourceAddress, DCM_E_OK);
                                Dcm_DspROEInternal[Index].EventOccurred = DCM_FALSE;
                                Dcm_DspROEInternal[Index].RoeExpected = DCM_TRUE;
                                #if(DCM_SVC_86_EMULATION_ENABLED == STD_ON)
                                IsEventOccurred = TRUE;
                                #endif
                            }
                        }
                    }
                }
            }
        }
    }
    #endif

    #if(DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
    #if(S27_DELAY_SUPPORTED == TRUE)
    if(S27_retry_delay > (S27_FAIL_COUNT_TIME_MS / DCM_TASK_PERIODICITY))
    {
        S27_retry_delay = 0U;
    }
    if(S27_retry_delay != 0U)
    {
        S27_retry_delay --;
    }

    #if(S27_RESET_DELAY_SUPPORTED == TRUE)
    if(S27_reset_delay > (S27_RSTDELAY_TIME_MS / DCM_TASK_PERIODICITY))
    {
        S27_reset_delay = 0U;
    }
    if(S27_reset_delay != 0U)
    {
        S27_reset_delay --;
    }
    #endif
    #endif /* (S27_DELAY_SUPPORTED == TRUE) */
    #endif

    DCMEXT_MAINFUNCTION();
}

#if(DCM_SVC_10_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_10ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : DiagnosticSessionControl 0x10 service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_10ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    uint16 flP2StarServerResolution = 0U;
    uint8 SubFunction = 0u;
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint8 index = 0U;
    uint8 StateRef = 0u;


    SubFunction = pMsgContext->reqData[0];
    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    for (index = 0u; index < NO_OF_SUPPORTTED_SESSIONS; index++)
    {
        if(SubFunction == Dcm_DsdSubService10[index].SubServiceId)
        {
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            if(pMsgContext->reqDataLen == DCM_DSP_0x01u)
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                if(Dcm_DsdSubService10[index].SubServiceFnc != NULL_PTR)
                {
                    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
                    StateRef = Dcm_DsdSubService10[index].State_Ref;
                    *ErrorCode = Dcm_DspCheckSessionSecurity (StateRef, DSP_DIAG_CHK_LVL_SUBFUNC);
                    if(DCM_E_OK == *ErrorCode)
                    {
                        RetVal = Dcm_DsdSubService10[index].SubServiceFnc(OpStatus, pMsgContext, ErrorCode);
                        if(DCM_E_OK == RetVal)
                        {
                            DslInternal_SetSecurityLevel (DCM_SEC_LEV_LOCKED);
                            if(SubFunction != Old_Session)
                            {
                                DslInternal_SetSesCtrlType(index);
                                Old_Session = SubFunction;
                            }
                            pMsgContext->resData = &pMsgContext->resData[2];
                            pMsgContext->resData[0] = Dsp_UtiGetHiByte(Dcm_DsdSessionInfo[index].P2);
                            pMsgContext->resData[DCM_DSP_0x01u] = Dsp_UtiGetLoByte(Dcm_DsdSessionInfo[index].P2);
                            flP2StarServerResolution = Dcm_DsdSessionInfo[index].P2Star / DCM_TASK_PERIODICITY;
                            pMsgContext->resData[DCM_DSP_0x02u] = Dsp_UtiGetHiByte(flP2StarServerResolution);
                            pMsgContext->resData[DCM_DSP_0x03u] = Dsp_UtiGetLoByte(flP2StarServerResolution);
                            pMsgContext->resDataLen = DCM_DSP_0x04u;
                        }
                    }
                }
            }
            index = NO_OF_SUPPORTTED_SESSIONS;
        }
    }
    return (RetVal);
}

/**************************************************************************
 Function name       : Std_ReturnType Dcm_01DefaultProcess(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes)
 Description         :
 Parameters (in)     :
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_01DefaultProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
    DCM_IGNORE_UNREF_PARAM(OpStatus);

    *NegRes = DCM_E_POSITIVERESPONSE;
    return (DCM_E_OK);
}

/**************************************************************************
 Function name       : Std_ReturnType Dcm_02PgmProcess(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes)
 Description         :
 Parameters (in)     :
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_02PgmProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType RetVal;

    DCM_IGNORE_UNREF_PARAM(OpStatus);

    *NegRes = DCM_E_CONDITIONSNOTCORRECT;
    RetVal = DCMEXT_PROG_ENTRY_CONDITION_CHECK(pMsgContext, NegRes);
    if(DCM_E_OK == RetVal)
    {
        #if(DCMEXT_PROG_MAGIC_FLAG_HANDLER == STD_ON)
        RetVal = DCMEXT_SET_PROGRAM_FLAG(NegRes);
        #else
        /* Write the Magic Flag for Program Entry */
        APPLN_REQUEST = DCM_DSP_0xAAAAAAAAU;
        fblAppMagicFlag[0] = DCM_DSP_0xAAU;
        fblAppMagicFlag[DCM_DSP_0x01u] = DCM_DSP_0xAAU;
        fblAppMagicFlag[DCM_DSP_0x02u] = DCM_DSP_0xAAU;
        fblAppMagicFlag[DCM_DSP_0x03u] = DCM_DSP_0xAAU;
        RetVal = DCM_E_OK;
        #endif
        if(RetVal == DCM_E_OK)
        {
            Dsp_PostProcessingFlag |= DSP_Fbl_EntryReset;
        }
    }
    return (RetVal);
}

/**************************************************************************
 Function name       : Std_ReturnType Dcm_03ExtnDiagProcess(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *NegRes)
 Description         :
 Parameters (in)     :
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_03ExtnDiagProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType RetVal;

    DCM_IGNORE_UNREF_PARAM(OpStatus);

    *NegRes = DCM_E_CONDITIONSNOTCORRECT;
    RetVal = DCMEXT_DIAG_ENTRY_CONDITION_CHECK(pMsgContext, NegRes);
    if(DCM_E_OK == RetVal)
    {
        Dsp_PostProcessingFlag |= DSP_Diag_Entered;
    }
    return (RetVal);
}
#endif

#if(DCM_SVC_11_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_11ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ECUReset
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_11ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    uint8 SubFunction = 0u;
    uint8 Counter = 0u;
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint8 StateRef = 0u;

    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    SubFunction = pMsgContext->reqData[0];
    for (Counter = 0u; Counter < Svc11NumOfSubFunc; Counter++)
    {
        if(SubFunction == Dcm_DsdSubService11[Counter].SubServiceId)
        {
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            if(pMsgContext->reqDataLen == DCM_DSP_0x01u)
            {
                StateRef = Dcm_DsdSubService11[Counter].State_Ref;
                *ErrorCode = Dcm_DspCheckSessionSecurity (StateRef, DSP_DIAG_CHK_LVL_PARAMETER);
                if(*ErrorCode == DCM_E_POSITIVERESPONSE)
                {
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    if(Dcm_DsdSubService11[Counter].SubServiceFnc != NULL_PTR)
                    {
                        RetVal = DCM_11S_PRE_CONDITION_CHECK(pMsgContext,ErrorCode);
                        if (DCM_E_OK == RetVal)
                        {
                            RetVal = Dcm_DsdSubService11[Counter].SubServiceFnc(OpStatus, ErrorCode);
                            pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x02u];
                            pMsgContext->resDataLen = 0u;
                        } // if (DCM_E_OK == DCM_11S_PRE_CONDITION_CHECK())
                    }
                }
            }
            break;
        }
    }
    return (RetVal);
}
#endif

#if(DCM_SVC_22_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : void ClearDcm_svc22Info(void)
 Description         : set svc22Info to initial state
 Parameters (in)     : none
 Parameters (out)    : none
 Return value        : none
 Design Information  :
 **************************************************************************/
void ClearDcm_svc22Info(void)
{
    Dcm_svc22Info.PosRespCounter = 0x0u;
    Dcm_svc22Info.DidIndex = 0x0u;
    Dcm_svc22Info.DidProcessIndex = 0x0u;
    Dcm_svc22Info.FinalDataLen = 0x0u;
    Dcm_svc22Info.MaxDataLen = 0x0u;
    Dcm_svc22Info.resDataLen = 0x0u;
    Dcm_svc22Info.DidReqCount = 0x0u;
    Dcm_svc22Info.resData = NULL_PTR;
    Dcm_svc22Info.PendingIsActive = 0u;
}
#endif

#if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : void ClearDcm_svc2FInfo(void)
 Description         : set svc2FInfo to initial state
 Parameters (in)     : none
 Parameters (out)    : none
 Return value        : none
 Design Information  :
 **************************************************************************/
void ClearDcm_svc2FInfo(void)
{
  uint8 counter;
  for(counter = 0; counter < DCM_NO_IODIDS; counter++)
  {
    Dcm_svc2FInfo.ActiveDid[counter] = 0x0u;
  }
  Dcm_svc2FInfo.ActiveDidcount = 0x0u;
  Dcm_svc2FInfo.IsActive = DCM_FALSE;
}
#endif

#if(DCM_SVC_22_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : static Std_ReturnType Dcm_Svc22Handler (uint16 flDidIndex, Dcm_NegativeResponseCodeType *NegRes)
 Description         : Lookup for the supported DID's
 Parameters (in)     : uint8* flDidIndex)
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_Svc22Handler(Dcm_OpStatusType OpStatus, uint16 flDidIndex, Dcm_NegativeResponseCodeType *NegRes)
{
    uint16 MaxLen = 0;
    uint16 Index = 0u;
    uint8 StateRef = 0u;
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    Dcm_MsgLenType RegDataLen = 0x0u;
    DidOpFuncType FuncPtr ;

    *NegRes = DCM_E_REQUESTOUTOFRANGE;
    if(flDidIndex < DcmNumOfDIDSupported)
    {
        if((Dcm_DspDidInfo[flDidIndex].Operations & DCM_DIDMGR_OPTYPE_READ) == DCM_DIDMGR_OPTYPE_READ)
        {
            Index = Dcm_DspDidInfo[flDidIndex].OpInfoRef;
            if(Index < DcmDspNumOfDidOpInfo)
            {
                StateRef = Dcm_DspDidOpInfo[Index].State_Ref;
                *NegRes = Dcm_DspCheckSessionSecurity (StateRef, DSP_DIAG_CHK_LVL_PARAMETER);
                if(DCM_E_OK == *NegRes)
                {
                    *NegRes = DCM_E_CONDITIONSNOTCORRECT;
                    if(DCM_FALSE != (Dcm_DspDidOpInfo[Index].CallTypes & DCM_DIDMGR_OPCLS_READ_SYNC))
                    {
                        MaxLen = Dcm_DspDidOpInfo[Index].Max_ReqLength;
                        Index = Dcm_DspDidOpInfo[Index].SignalInfo_Ref;
                        *NegRes = DCM_E_SERVICENOTSUPPORTED;
                        if(Index < DcmDspNumOfDidSignalInfo)
                        {
                            if(FALSE != (Dcm_DspDidSignalInfo[Index].FunClass & DCM_DIDMGR_OPCLS_READ_SYNC))
                            {
                                /**Coverity - Fix for CID 12247064 (#1 of 1): Potential Array Indexed Problem (POTENTIAL_OVERRUN) */
                                if((Dcm_svc22Info.DidProcessIndex < S22_MAX_SUPPORTED_DID_READ) &&
                                        (Dcm_DspDidSignalInfo[Index].DidOpFunc_Ref < DidNumOfOpFunc))
                                {
                                    FuncPtr = DidOpFunc[Dcm_DspDidSignalInfo[Index].DidOpFunc_Ref];
                                    if(NULL != FuncPtr)
                                    {
                                        *NegRes = DCM_E_REQUESTOUTOFRANGE;
                                        /* ReadData function can check for max avail. buffer size before copy */
                                        RegDataLen = DcmDslBufferSize - Dcm_svc22Info.FinalDataLen;
                                        RetVal = FuncPtr( OpStatus, DCM_DSP_DID_READ, Dcm_svc22Info.Did[Dcm_svc22Info.DidProcessIndex], RegDataLen,
                                                          Dcm_svc22Info.resData, &Dcm_svc22Info.resDataLen, NegRes);
                                    }
                                }
                            }
                        }
                    }
                }
                if(DCM_E_OK == RetVal)
                {
                    if((Dcm_svc22Info.resDataLen == 0u) && (MaxLen != 0u)) // if not set by called FuncPtr
                    {
                        Dcm_svc22Info.resDataLen = MaxLen;
                    }
                    Dcm_svc22Info.FinalDataLen += Dcm_svc22Info.resDataLen;
                }
                else if(DCM_E_NOT_OK == RetVal)
                {
                    Dcm_svc22Info.resDataLen = 0x0u;
                    Dcm_svc22Info.resData -= DCM_DSP_0x02u;
                    Dcm_svc22Info.FinalDataLen -= DCM_DSP_0x02u;
                }
                else
                {
                    /* to avoid misra warning */
                }
            }
        }
    }
    return RetVal;
}

/**************************************************************************
 Function name       : static Std_ReturnType Dcm_Svc22DidLookUp (uint16* flDidIndex,
                             Dcm_NegativeResponseCodeType *NegRes)
 Description         : Lookup for the supported DID's
 Parameters (in)     : none
 Parameters (out)    : uint8* flDidIndex, Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_Svc22DidLookUp(uint16 *flDidIndex, Dcm_NegativeResponseCodeType *NegRes)
{
    uint16 fl_Length = 0u;
    uint16 Counter = 0u;
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 Index = 0u;

    *NegRes = DCM_E_REQUESTOUTOFRANGE;
    if(Dcm_svc22Info.DidProcessIndex < S22_MAX_SUPPORTED_DID_READ)
    {
        fl_Length = Dcm_DspDidIdentifierTable[0];
        if(fl_Length == DcmNumOfDIDSupported)
        {
            for (Counter = 0; Counter < fl_Length; Counter++)
            {
                if((Dcm_DspDidIdentifierTable[Counter + DCM_DSP_0x01u] == Dcm_svc22Info.Did[Dcm_svc22Info.DidProcessIndex]) && (Dcm_DspDidInfo[Counter].DcmDspDidUsed == TRUE))
                {
                    if( (Dcm_DspDidInfo[Counter].Operations & DCM_DIDMGR_OPTYPE_READ) == DCM_DIDMGR_OPTYPE_READ )
                    {
                        Index = Dcm_DspDidInfo[Counter].OpInfoRef;
                        Index = Dcm_DspGetStateRefIndex(Index, Dcm_DspDidInfo[Counter].Operations, DCM_DIDMGR_OPTYPE_READ);
                        if(Index < DcmDspNumOfDidOpInfo)
                        {
                            /* in case of multi DID request, Max_ReqLength shall be configured */
                            if((Dcm_svc22Info.DidReqCount > DCM_DSP_0x01u) && (0u == Dcm_DspDidOpInfo[Index].Max_ReqLength))
                            {
                                *NegRes = DCM_E_GENERALREJECT;
                            }
                            else
                            {
                                Dcm_svc22Info.MaxDataLen += Dcm_DspDidOpInfo[Index].Max_ReqLength;
                                *flDidIndex = Counter;
                                RetVal = E_OK;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    return RetVal;
}

/**************************************************************************
 Function name       : Std_ReturnType Dcm_22ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ReadDataByIdentifier Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_22ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint16 Counter = 0U;

    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    if(   (0u == (pMsgContext->reqDataLen & DCM_DSP_0x01u)) /* length is an odd (wrong) or even (right) number */
            && (pMsgContext->reqDataLen <= (Dcm_MsgLenType) (S22_MAX_SUPPORTED_DID_READ * DCM_DSP_0x02u))) /* Also the capacity of the ECU shall not be exceeded */
    {
        if((0u == Dcm_svc22Info.DidProcessIndex) && (0u == Dcm_svc22Info.PendingIsActive))
        {
            Dcm_svc22Info.DidReqCount = (uint8)pMsgContext->reqDataLen / DCM_DSP_0x02u;
            Dcm_svc22Info.DidIndex = 0u;

            for (Counter = 0; Counter < Dcm_svc22Info.DidReqCount; Counter++)
            {
                Dcm_svc22Info.Did[Counter] = ((uint16) ( (((uint16)pMsgContext->reqData[Dcm_svc22Info.DidIndex] << DCM_DSP_0x08U))
                                              |  (uint16)pMsgContext->reqData[Dcm_svc22Info.DidIndex + DCM_DSP_0x01u]));
                Dcm_svc22Info.DidIndex += DCM_DSP_0x02u;
            }
            Dcm_svc22Info.resData = &pMsgContext->resData[DCM_DSP_0x01u];
            Dcm_svc22Info.FinalDataLen = DCM_DSP_0x01u;
        }

        for (Counter = Dcm_svc22Info.DidProcessIndex; Counter < Dcm_svc22Info.DidReqCount; Counter++)
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            if(0u == Dcm_svc22Info.PendingIsActive)
            {
                RetVal = Dcm_Svc22DidLookUp(&Dcm_svc22Info.DidIndex, ErrorCode);
            }
            else
            {
                RetVal = DCM_E_OK;
            }
            if(DCM_E_NOT_OK != RetVal)
            {
                if(Dcm_svc22Info.MaxDataLen > DcmDslBufferSize)
                {
                    /* To trigger NRC for response too long */
                    *ErrorCode = DCM_E_RESPONSETOOLONG;
                    pMsgContext->resDataLen = Dcm_svc22Info.MaxDataLen;
                    break;
                }
                if(0u == Dcm_svc22Info.PendingIsActive)
                {
                    if((Dcm_svc22Info.resDataLen < DCM_DSP_0xFFFFFFFEuL ) && (Dcm_svc22Info.DidProcessIndex < S22_MAX_SUPPORTED_DID_READ))
                    {
                        Dcm_svc22Info.resData[Dcm_svc22Info.resDataLen] = (uint8)(DCM_DSP_0xFFU & (Dcm_svc22Info.Did[Dcm_svc22Info.DidProcessIndex] >> DCM_DSP_0x08U));
                        Dcm_svc22Info.resData[Dcm_svc22Info.resDataLen + DCM_DSP_0x01u] = (uint8)(DCM_DSP_0xFFU & Dcm_svc22Info.Did[Dcm_svc22Info.DidProcessIndex]);
                        Dcm_svc22Info.resData = &Dcm_svc22Info.resData[Dcm_svc22Info.resDataLen + DCM_DSP_0x02u];
                        Dcm_svc22Info.resDataLen = 0x0u;
                        Dcm_svc22Info.FinalDataLen += DCM_DSP_0x02u;
                    }
                }
                RetVal = Dcm_Svc22Handler(OpStatus, Dcm_svc22Info.DidIndex, ErrorCode);
                if(DCM_E_OK == RetVal)
                {
                    Dcm_svc22Info.PendingIsActive = 0u;
                    if(Dcm_svc22Info.PosRespCounter < DCM_DSP_0xFFU)
                    {
                        Dcm_svc22Info.PosRespCounter++;
                    }
                }
                else if(DCM_E_NOT_OK == RetVal)
                {
                    Dcm_svc22Info.PendingIsActive = 0u;
                    if((*ErrorCode == DCM_E_SECURITYACCESSDENIED) || (*ErrorCode == DCM_E_CONDITIONSNOTCORRECT))
                    {
                        Dcm_svc22Info.PosRespCounter = 0x0u;
                        break; // according to ISO14229-1_2013-03, fig. 15: in case of NRC 0x33 or 0x22 exit loop and return the NRC
                    }
                }
                else if(DCM_E_PENDING == RetVal)
                {
                    Dcm_svc22Info.PendingIsActive = DCM_DSP_0x01u;
                }
                else
                {
                    /* to avoid misra warning */
                }
            }
            else
            {
                if(*ErrorCode == DCM_E_GENERALREJECT) /* to detect problem with Max_ReqLength configuration */
                {
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    break;
                }
            }
            if((DCM_E_OK == RetVal) || (DCM_E_NOT_OK == RetVal))
            {
                Dcm_svc22Info.DidProcessIndex += DCM_DSP_0x01u;
            }
            else
            {
                /* Response Pending Transmission handle? - msavariy*/
                break;
            }
        }
        if(*ErrorCode != DCM_E_RESPONSETOOLONG)
        {
            pMsgContext->resDataLen = Dcm_svc22Info.FinalDataLen;
        }
    }
    if((RetVal == DCM_E_NOT_OK) && (0u < Dcm_svc22Info.PosRespCounter))
    {
        RetVal = DCM_E_OK; // correct in case of multiple request and last DID is NRC
    }

    if((DCM_E_OK == RetVal) || (DCM_E_NOT_OK == RetVal))
    {
        ClearDcm_svc22Info();
    }
    return (RetVal);
}
#endif

#if(DCM_SVC_23_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_23ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ReadMemoryByAddress Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_23ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    Dcm_ReturnReadMemoryType Read_RetVal = DCM_READ_FAILED;
    uint32 MemAddress = 0u;
    uint32 MemEndAddess = 0u;
    uint32 MemSize = 0u;
    uint8 index = 0u;
    uint8 StateRef = 0u;
    uint8 MemSizeCount = 0u;
    uint8 AddrSizeCount = 0u;
    uint8 MemoryIdentifier = 0u;
    Dcm_BooleanType isvalidALFID = DCM_FALSE;

    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    #if(DcmDevAdditionalCoverityChecks == TRUE)
    if((NULL != pMsgContext) && (NULL != pMsgContext->reqData) && (NULL != pMsgContext->resData))
    #endif
    {
        #if(DCM_ALFID_EXIST == STD_ON) 
        for(index=0u; index < DCM_NUM_ALFID; index++)  
        {         
            if(pMsgContext->reqData[0] == Dcm_AlfidList[index])                           //Check DcmDspSupportedAddressAndLengthFormatIdentifier is valid. DcmDspSupportedAddressAndLengthFormatIdentifier is program specific so putting as configuration parameter			
            {
                isvalidALFID = DCM_TRUE;
                break;
            }
        }
        #else
        isvalidALFID = DCM_TRUE;
        #endif           
        if(isvalidALFID == DCM_TRUE)
        {
            MemSizeCount  = (uint8)((pMsgContext->reqData[0] & DCM_DSP_0xF0U) >> DCM_DSP_0x04u);     
            AddrSizeCount = (uint8)(pMsgContext->reqData[0] & DCM_DSP_0x0FU);                       
            MemAddress = 0u;
            for(index = 0u; index < AddrSizeCount; index++)
            {
                MemAddress = (uint32)(MemAddress << DCM_DSP_0x08U) + pMsgContext->reqData[index + DCM_DSP_0x01u];
            }
            MemSize = 0u;
            for(index = 0u; index < MemSizeCount; index++)
            {
                MemSize = (uint32)(MemSize << DCM_DSP_0x08U) + pMsgContext->reqData[index + AddrSizeCount + DCM_DSP_0x01u];
            }
            MemEndAddess = (uint32)((MemAddress + MemSize) - (uint32)DCM_DSP_0x01u);

            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            if(pMsgContext->reqDataLen == (uint32)(DCM_DSP_0x01u + MemSizeCount + AddrSizeCount))
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                if((MemSize < DcmDslBufferSize) && (MemSize != 0x0u))
                {
                    for(index = 0u; index < NumOfReadMemoryByAddressRanges; index++)
                    {
                        if((MemAddress >= Dcm_DspReadMemoryRange[index].MemRangeLow) &&
                                (MemEndAddess <= Dcm_DspReadMemoryRange[index].MemRangeHigh))
                        {
                            StateRef = Dcm_DspReadMemoryRange[index].State_Ref;
                            *ErrorCode = Dcm_DspCheckSessionSecurity(StateRef, DSP_DIAG_CHK_LVL_PARAMETER);
                            if(DCM_E_POSITIVERESPONSE == (*ErrorCode))
                            {
                                RetVal = DCM_23S_PRE_CONDITION_CHECK(pMsgContext, ErrorCode);
                                if (DCM_E_OK == RetVal)
                                {
                                    Dcm_MsgLenType aLength;
                                    pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x01u];
                                    pMsgContext->resDataLen = MemSize;
                                    Read_RetVal = DcmExt_ReadMemory(OpStatus, MemoryIdentifier, MemAddress, MemSize, pMsgContext->resData,
                                                                        ErrorCode);
                                    if(Read_RetVal != DCM_READ_OK)
                                    {
                                      if(Read_RetVal == DCM_READ_FAILED)
                                      {
                                        RetVal = DCM_E_NOT_OK;
                                      }
                                      else
                                      {
                                        RetVal = DCM_E_PENDING;
                                      }
                                    }
                                    else
                                    {
                                      RetVal = DCM_E_OK;
                                    }
                                    break;
                                } /* if (DCM_E_OK == DCM_23S_PRE_CONDITION_CHECK()) */
                            }
                        }
                    }
                }
            }
        }
    }
    return (RetVal);
}
#endif

#if(DCM_SVC_3D_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_3DServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ReadMemoryByAddress Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_3DServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    /* CERT C fix  20072997 initialized below variables* 0521 */
    Dcm_ReturnWriteMemoryType Write_RetVal = DCM_WRITE_FAILED;
    uint32 MemAddress = 0U;
    uint32 MemEndAddess = 0U;
    uint32 MemSize = 0U;
    uint8 index = 0U;
    uint8 StateRef = 0U;
    uint8 MemSizeCount = 0U;
    uint8 AddrSizeCount = 0U;
    uint8 MemoryIdentifier = 0u;
    Dcm_BooleanType isvalidALFID = DCM_FALSE;

    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    if(NULL != pMsgContext)
    {
        #if(DCM_ALFID_EXIST == STD_ON) 
        for(index=0u; index < DCM_NUM_ALFID; index++)  
        {         
            if(pMsgContext->reqData[0] == Dcm_AlfidList[index])                           //Check DcmDspSupportedAddressAndLengthFormatIdentifier is valid. DcmDspSupportedAddressAndLengthFormatIdentifier is program specific so putting as configuration parameter			
            {
                isvalidALFID = DCM_TRUE;
                break;
            }
        }
        #else
        isvalidALFID = DCM_TRUE;
        #endif           
        if(isvalidALFID == DCM_TRUE)
        {
            MemSizeCount  = (uint8)((pMsgContext->reqData[0] & DCM_DSP_0xF0U) >> DCM_DSP_0x04u);     // get the bytes require to indicate memory size
            AddrSizeCount = (uint8)(pMsgContext->reqData[0] & DCM_DSP_0x0FU);
            MemAddress = 0u;
            for(index = 0u; index < AddrSizeCount; index++)
            {
                MemAddress = (uint32)(MemAddress << DCM_DSP_0x08U) + (uint32) pMsgContext->reqData[index + DCM_DSP_0x01u];
            }

            for(index = 0u; index < MemSizeCount; index++)
            {
                MemSize = (uint32)(MemSize << DCM_DSP_0x08U) + (uint32)pMsgContext->reqData[index + AddrSizeCount + DCM_DSP_0x01u];
            }
            /* CERT C fix 17225587 */
            if(0u < (MemAddress + MemSize))
            {
                MemEndAddess = (uint32)((MemAddress + MemSize) - (DCM_DSP_0x01u));
            }

            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            if(pMsgContext->reqDataLen == (DCM_DSP_0x01u + MemSizeCount + AddrSizeCount + MemSize))
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                if((MemSize < DcmDslBufferSize) && (0x0u != MemSize))
                {
                    for(index = 0u; index < NumOfWriteMemoryByAddressRanges; index++)
                    {
                        if((MemAddress >= Dcm_DspWriteMemoryRange[index].MemRangeLow) &&
                                (MemEndAddess <= Dcm_DspWriteMemoryRange[index].MemRangeHigh))
                        {
                            StateRef = Dcm_DspWriteMemoryRange[index].State_Ref;
                            *ErrorCode = Dcm_DspCheckSessionSecurity(StateRef, DSP_DIAG_CHK_LVL_PARAMETER);
                            if(DCM_E_POSITIVERESPONSE == (*ErrorCode))
                            {
                                RetVal = DCM_3DS_PRE_CONDITION_CHECK(OpStatus, pMsgContext, ErrorCode);
                                if(DCM_E_OK == RetVal)
                                {
                                    Dcm_MsgLenType aLength;
                                    pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x0AU];
                                    pMsgContext->resDataLen = 0;
                                    Write_RetVal = DcmExt_WriteMemory(OpStatus, MemoryIdentifier, MemAddress, MemSize, pMsgContext->resData,
                                                                         ErrorCode);
                                    if(Write_RetVal != DCM_WRITE_OK)
                                    {
                                      if(Write_RetVal == DCM_WRITE_FAILED)
                                      {
                                        RetVal = DCM_E_NOT_OK;
                                      }
                                      else
                                      {
                                        RetVal = DCM_E_PENDING;
                                      }
                                    }
                                    else
                                    {
                                      RetVal = DCM_E_OK;
                                    }
                                    break;
                                } //if (DCM_E_OK == DCM_3DS_PRE_CONDITION_CHECK())
                            }
                        }
                    }
                }
            }
        }
    }
    return (RetVal);
}
#endif

#if(DCM_SVC_34_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_34ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : RoutineControl Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  : NRC_NOTSUPPORTEDINACTIVESESSION provided by Dcm_Dsd
 **************************************************************************/
Std_ReturnType Dcm_34ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint32 MemEndAddress = 0U;
    uint32 Block;
    uint8 index = 0U;
    uint8 StateRef = 0U;
    uint8 MemSizeCount = 0U;
    uint8 AddrSizeCount = 0U;
    uint8 lengthFormatIdentifier =0U;
    uint32 MemAddress=0U;
    uint32 MemSize=0U;
    uint32 Blocklength=0U;
    Dcm_BooleanType isvalidALFID = DCM_FALSE;
    Dcm_BooleanType isvalidDFID = DCM_FALSE;
    
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;

    if(NULL != pMsgContext)
	{
        for(index=0u; index < DCM_NUM_DFID; index++)  
        {         
            if(pMsgContext->reqData[0] == Dcm_DfidList[index])   
            {                        
                isvalidDFID = DCM_TRUE;
                break;
            }
        }
		if(isvalidDFID == DCM_TRUE)                 // Check DataFormatIdentifier is valid & DataFormatIdentifier depends upon the configuration
		{
            #if(DCM_ALFID_EXIST == STD_ON) 
            for(index=0u; index < DCM_NUM_ALFID; index++)  
            {         
                if(pMsgContext->reqData[1] == Dcm_AlfidList[index])                           //Check DcmDspSupportedAddressAndLengthFormatIdentifier is valid. DcmDspSupportedAddressAndLengthFormatIdentifier is program specific so putting as configuration parameter			
                {
                    isvalidALFID = DCM_TRUE;
                    break;
                }
            }
            #else
            isvalidALFID = DCM_TRUE;
            #endif           
            if(isvalidALFID == DCM_TRUE)
            {
                MemSizeCount  = (uint8)((pMsgContext->reqData[1] & DCM_DSP_0xF0U) >> DCM_DSP_0x04u);     // get the bytes require to indicate memory size
                AddrSizeCount = (uint8)(pMsgContext->reqData[1] & DCM_DSP_0x0FU);                       // get the bytes require to indicate memory address
                for(index = 0u; index < AddrSizeCount; index++)                                        // get memory address
                {
                    MemAddress = (uint32)(MemAddress << DCM_DSP_0x08U) + (uint32) pMsgContext->reqData[index + DCM_DSP_0x02u];
                }

                for(index = 0u; index < MemSizeCount; index++)                                         // get memory size
                {
                    MemSize = (uint32)(MemSize << DCM_DSP_0x08U) + (uint32)pMsgContext->reqData[index + AddrSizeCount + DCM_DSP_0x02u];
                }
                if(0u < (MemAddress + MemSize))
                {
                    MemEndAddress = ((uint32)((MemAddress + MemSize) - DCM_DSP_0x01u));            // calculate end address
                }

                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                if(pMsgContext->reqDataLen == (DCM_DSP_0x02u + MemSizeCount + AddrSizeCount))                    // Check the total length
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    if(0x0u != MemSize)                       // MemSize should be less than buffer size that is to be configured
                    {                
                        for(index = 0u; index < NumOfWriteMemoryByAddressRanges; index++)                                         // Check the memory address is in configured memory address range
                        {
                            if((MemAddress >= Dcm_DspWriteMemoryRange[index].MemRangeLow) &&
                                    (MemEndAddress <= Dcm_DspWriteMemoryRange[index].MemRangeHigh))
                            {
                                StateRef = Dcm_DspWriteMemoryRange[index].State_Ref;
                                *ErrorCode = Dcm_DspCheckSessionSecurity(StateRef, DSP_DIAG_CHK_LVL_PARAMETER);                  // Check security
                                if(DCM_E_POSITIVERESPONSE == (*ErrorCode))
                                {
                                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                                    if((Dcm_DataTransfer.Dcm_DataTransferState== DCM_DATA_TRANSFER_STATE_IDLE)||(Dcm_DataTransfer.Dcm_DataTransferState==DCM_DATA_TRANSFER_DONE_STATE))
                                    {
                                        RetVal = DCM_34S_PRE_CONDITION_CHECK(OpStatus, pMsgContext, ErrorCode);                                            // Check for the precoditions
                                        if(DCM_E_OK == RetVal)
                                        {
                                            RetVal=DcmExt_ProcessRequestDownload(OpStatus, pMsgContext->reqData[0], MemAddress, MemSize, &Blocklength,ErrorCode);     // Calling to get block length 
                                        }
                                        else
                                        {
                                            *ErrorCode=DCM_E_UPLOADDOWNLOADNOTACCEPTED;
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }	
                } 
            }       
		}
	}
	
	if(RetVal == E_OK)
	{
		if (OpStatus == DCM_CANCEL)
		{
			RetVal = E_NOT_OK;
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		}
		else
		{
			if (Blocklength > (pMsgContext->resMaxDataLen-1u))                              // check the block length whether it is less than maximum response length, substracting 1 since 1 byte is for lengthFormatIdentifier in the response  
			{
				RetVal = E_NOT_OK;
				*ErrorCode = DCM_E_PANIC_NRC;                                                                                                                
			}
			else
			{
				Dcm_DataTransfer.Dcm_DataTransferState= DCM_DOWNLOAD_STATE_READY_FOR_TRANSFER;
				lengthFormatIdentifier=0;
                Block= Blocklength;
				Dcm_DataTransfer.Dcm_DataTransferOldBlockCounter= 0;
				while(Block!=0)                                                            
				{
					lengthFormatIdentifier++;
					Block >>=8;
				}				
				pMsgContext->resDataLen= lengthFormatIdentifier + DCM_DSP_0x02u;
				pMsgContext->resData[1]= ((lengthFormatIdentifier<<4u) & 0xF0);
                Block= Blocklength;                                                   
				for(index=0; index< lengthFormatIdentifier; index++)
                {
	                pMsgContext->resData[index+DCM_DSP_0x02u]=(uint8)(Block>>(8u*(lengthFormatIdentifier-(index+DCM_DSP_0x01u)))); 
                }
                Dcm_DataTransfer.MemAddress=  MemAddress;
                Dcm_DataTransfer.MemSize= MemSize;
                Dcm_DataTransfer.Blocklength= Blocklength;
			}
		}
	}
    
	return RetVal;
}
#endif

#if(DCM_SVC_35_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_35ServiceProcess(Dcm_MsgContextType *pMsgContext)
 Description         : RoutineControl Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  : NRC_NOTSUPPORTEDINACTIVESESSION provided by Dcm_Dsd
 **************************************************************************/
Std_ReturnType Dcm_35ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint32 MemEndAddress = 0U;
    uint32 Block;
    uint8 index = 0U;
    uint8 StateRef = 0U;
    uint8 MemSizeCount = 0U;
    uint8 AddrSizeCount = 0U;
    uint8 lengthFormatIdentifier=0U;
    uint32 MemAddress=0U;
    uint32 MemSize=0U;
    uint32 Blocklength=0U;
    Dcm_BooleanType isvalidALFID = DCM_FALSE;
    Dcm_BooleanType isvalidDFID = DCM_FALSE;

    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;

    if(NULL != pMsgContext)
	{
        for(index=0u; index < DCM_NUM_DFID; index++)  
        {         
            if(pMsgContext->reqData[0] == Dcm_DfidList[index])                           			
            {
                isvalidDFID = DCM_TRUE;
                break;
            }
        }
		if(isvalidDFID == DCM_TRUE)                   // Check DataFormatIdentifier is valid & DataFormatIdentifier depends upon the configuration
		{
            #if(DCM_ALFID_EXIST == STD_ON) 
            for(index=0u; index < DCM_NUM_ALFID; index++)  
            {         
                if(pMsgContext->reqData[1] == Dcm_AlfidList[index])                           //Check DcmDspSupportedAddressAndLengthFormatIdentifier is valid. DcmDspSupportedAddressAndLengthFormatIdentifier is program specific so putting as configuration parameter			
                {
                    isvalidALFID = DCM_TRUE;
                    break;
                }
            }
            #else
            isvalidALFID = DCM_TRUE;
            #endif 
            if(isvalidALFID == DCM_TRUE)
            {
                MemSizeCount  = (uint8)((pMsgContext->reqData[1] & DCM_DSP_0xF0U) >> DCM_DSP_0x04u);
                AddrSizeCount = (uint8)(pMsgContext->reqData[1] & DCM_DSP_0x0FU);
                MemAddress = 0u;
                for(index = 0u; index < AddrSizeCount; index++)
                {
                    MemAddress = (uint32)(MemAddress << DCM_DSP_0x08U) + (uint32) pMsgContext->reqData[index + DCM_DSP_0x02u];
                }

                for(index = 0u; index < MemSizeCount; index++)
                {
                    MemSize = (uint32)(MemSize << DCM_DSP_0x08U) + (uint32)pMsgContext->reqData[index + AddrSizeCount + DCM_DSP_0x02u];
                }
                if(0u < (MemAddress + MemSize))
                {
                    MemEndAddress = ((uint32)(MemAddress + MemSize - DCM_DSP_0x01u));
                }

                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                if(pMsgContext->reqDataLen == (DCM_DSP_0x02u + MemSizeCount + AddrSizeCount))
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    if(0x0u != MemSize)
                    {
                        for(index = 0u; index < NumOfReadMemoryByAddressRanges; index++)
                        {
                            if((MemAddress >= Dcm_DspReadMemoryRange[index].MemRangeLow) &&
                                    (MemEndAddress <= Dcm_DspReadMemoryRange[index].MemRangeHigh))
                            {
                                StateRef = Dcm_DspReadMemoryRange[index].State_Ref;
                                *ErrorCode = Dcm_DspCheckSessionSecurity(StateRef, DSP_DIAG_CHK_LVL_PARAMETER);
                                if(DCM_E_POSITIVERESPONSE == (*ErrorCode))
                                {
                                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                                    if((Dcm_DataTransfer.Dcm_DataTransferState== DCM_DATA_TRANSFER_STATE_IDLE)||(Dcm_DataTransfer.Dcm_DataTransferState==DCM_DATA_TRANSFER_DONE_STATE))
                                    {
                                        RetVal = DCM_35S_PRE_CONDITION_CHECK(pMsgContext, ErrorCode);
                                        if(DCM_E_OK == RetVal)
                                        {
                                            RetVal=DcmExt_ProcessRequestUpload(OpStatus, pMsgContext->reqData[0], MemAddress, MemSize, &Blocklength,ErrorCode);// pass the arguments
                                        }
                                        else
                                        {
                                            *ErrorCode=DCM_E_UPLOADDOWNLOADNOTACCEPTED;
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }	
                }
            }
		}
	}
	
	if(RetVal == E_OK)
	{
		if (OpStatus == DCM_CANCEL)
		{
			RetVal = E_NOT_OK;
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		}
		else
		{
			if (Blocklength > (pMsgContext->resMaxDataLen-1))                     // check the block length whether it is less than maximum response length, substracting 1 since 1 byte is for lengthFormatIdentifier in the response
			{
				RetVal = E_NOT_OK;
				*ErrorCode = DCM_E_PANIC_NRC;                                                                                                                
			}
			else
			{				
				Dcm_DataTransfer.Dcm_DataTransferState= DCM_UPLOAD_STATE_READY_FOR_TRANSFER;
				lengthFormatIdentifier=0;
                Block= Blocklength;
				Dcm_DataTransfer.Dcm_DataTransferOldBlockCounter= 0;
				while(Block!=0)
				{
					lengthFormatIdentifier++;
					Block >>=8;
				}				
				pMsgContext->resDataLen= lengthFormatIdentifier + 0x02u;
				pMsgContext->resData[1]=lengthFormatIdentifier<<4 & 0xF0u; 
                Block= Blocklength;                                                                  
				for(index=0; index< lengthFormatIdentifier; index++)
                {
	                pMsgContext->resData[index+DCM_DSP_0x02u]=(uint8)(Block>>(8u*(lengthFormatIdentifier-(index+DCM_DSP_0x01u)))); 
                } 
                Dcm_DataTransfer.MemAddress=  MemAddress;
                Dcm_DataTransfer.MemSize= MemSize;
                Dcm_DataTransfer.Blocklength= Blocklength;               
			}
		}
	}

	return RetVal;
}
#endif

#if(DCM_SVC_36_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_36ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : RoutineControl Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  : NRC_NOTSUPPORTEDINACTIVESESSION provided by Dcm_Dsd
 **************************************************************************/
Std_ReturnType Dcm_36ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    #if((DCM_SVC_3D_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_34_SUPPORT_ENABLED == STD_ON))    
    Dcm_ReturnWriteMemoryType Write_RetVal = DCM_WRITE_FAILED;
    #endif
    #if((DCM_SVC_23_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_35_SUPPORT_ENABLED == STD_ON))    
    Dcm_ReturnReadMemoryType Read_RetVal = DCM_READ_FAILED;
    #endif
    uint32 MemAddress=0u;
    uint32 MemSize=0U;
    uint32 Blocklength=0U;
    uint8 Dcm_DataTransferState=0U;
    uint8 OldBlockCounter= Dcm_DataTransfer.Dcm_DataTransferOldBlockCounter;
    uint8 MemoryIdentifier = 0;

    MemAddress= Dcm_DataTransfer.MemAddress;
    MemSize= Dcm_DataTransfer.MemSize;
	Blocklength= Dcm_DataTransfer.Blocklength;
	Dcm_DataTransferState= Dcm_DataTransfer.Dcm_DataTransferState;

    if(NULL != pMsgContext)
    {
	    if((Dcm_DataTransferState == DCM_DOWNLOAD_STATE_READY_FOR_TRANSFER) || (Dcm_DataTransferState== DCM_UPLOAD_STATE_READY_FOR_TRANSFER)||(Dcm_DataTransferState== DCM_DOWNLOAD_STATE_IN_PROGRESS)||(Dcm_DataTransferState== DCM_UPLOAD_STATE_IN_PROGRESS))      // check the states to ensure the request sequences
	    {
            *ErrorCode = DCM_E_TRANSFERDATASUSPENDED;                     
            if((pMsgContext->reqDataLen-1u) <=Blocklength)                                //Check for Data transfer can continue AND memorySize is respected and handle for NRC NRC 0x71
            {                                                                 
                if((Dcm_DataTransferState== DCM_DOWNLOAD_STATE_READY_FOR_TRANSFER) || (Dcm_DataTransferState== DCM_UPLOAD_STATE_READY_FOR_TRANSFER))           // Check for first block 
                {
                    if((pMsgContext->reqData[0] == 1u) && (OldBlockCounter==0u))                                 
                    {
                        RetVal= DCM_E_OK;
                    }
                    else
                    {
                        *ErrorCode = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
                    }                                                                        
                }
                else
                {
	   	            if((pMsgContext->reqData[0] == OldBlockCounter) || (((uint8)(pMsgContext->reqData[0])) == ((uint8)(OldBlockCounter + 1u))))
                    {
                      RetVal = DCM_E_OK;
                    }
                    else
                    {
                      *ErrorCode = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
                    }
                }
                if(RetVal == DCM_E_OK)
                {  
                    if (OpStatus == DCM_CANCEL)
                    {
                        RetVal = E_NOT_OK;
                        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    }
                    else   
                    {   
                        if((MemSize >= (pMsgContext->reqDataLen-1u)) || (Dcm_DataTransferState== DCM_UPLOAD_STATE_READY_FOR_TRANSFER) || 
	   	      	  	               (Dcm_DataTransferState== DCM_UPLOAD_STATE_IN_PROGRESS))
                        {
                            if (pMsgContext->reqData[0] == OldBlockCounter)
                            {
                              // do nothing
                            }
                            else
                            {                                
                                OldBlockCounter = pMsgContext->reqData[0];
                                if((Dcm_DataTransferState== DCM_DOWNLOAD_STATE_READY_FOR_TRANSFER) || (Dcm_DataTransferState== DCM_DOWNLOAD_STATE_IN_PROGRESS))                
                                {
                                    #if((DCM_SVC_3D_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_34_SUPPORT_ENABLED == STD_ON))
	   	      	  	                MemSize = MemSize - (pMsgContext->reqDataLen-1u);
	   	      	  	                MemAddress = MemAddress + (pMsgContext->reqDataLen-1u);
                                    Dcm_DataTransferState = DCM_DOWNLOAD_STATE_IN_PROGRESS;
                                    Write_RetVal = DcmExt_WriteMemory(OpStatus, MemoryIdentifier, MemAddress, (pMsgContext->reqDataLen-1u), &pMsgContext->reqData[1],ErrorCode); 
                                    if(Write_RetVal != DCM_WRITE_OK)
                                    {
                                      if(Write_RetVal == DCM_WRITE_FAILED)
                                      {
                                        RetVal = DCM_E_NOT_OK;
                                      }
                                      else
                                      {
                                        RetVal = DCM_E_PENDING;
                                      }
                                    }
                                    else
                                    {
                                      RetVal = DCM_E_OK;
                                    }                                  
                                    pMsgContext->resDataLen = 0x02u;
                                    pMsgContext->resData[1]= pMsgContext->reqData[0];
                                    #endif
                                }
                                else                                                                                                                                                                  
                                {
                                    #if((DCM_SVC_23_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_35_SUPPORT_ENABLED == STD_ON))
	   	      	  	                MemSize = MemSize - Blocklength;
	   	      	  	                MemAddress = MemAddress + Blocklength;
                                    Dcm_DataTransferState = DCM_UPLOAD_STATE_IN_PROGRESS;
	   	      	  	                pMsgContext->resDataLen = 0x02u+Blocklength;
	   	      	  	                pMsgContext->resData[1]= pMsgContext->reqData[0];
                                    Read_RetVal= DcmExt_ReadMemory(OpStatus,MemoryIdentifier,MemAddress, Blocklength, &pMsgContext->resData[2],ErrorCode);
                                    if(Read_RetVal != DCM_READ_OK)
                                    {
                                      if(Read_RetVal == DCM_READ_FAILED)
                                      {
                                        RetVal = DCM_E_NOT_OK;
                                      }
                                      else
                                      {
                                        RetVal = DCM_E_PENDING;
                                      }
                                    }
                                    else
                                    {
                                      RetVal = DCM_E_OK;
                                    }
                                    #endif
                                }
                                if(RetVal == E_OK)
                                {
                                    if(MemSize == 0u)
                                    {
                                      Dcm_DataTransferState = DCM_DATA_TRANSFER_DONE_STATE;
                                      OldBlockCounter = 0;
                                    }
                                    Dcm_DataTransfer.MemAddress= MemAddress;
                                    Dcm_DataTransfer.MemSize= MemSize;
                                    Dcm_DataTransfer.Blocklength= Blocklength;
                                    Dcm_DataTransfer.Dcm_DataTransferState= Dcm_DataTransferState;                        
                                    Dcm_DataTransfer.Dcm_DataTransferOldBlockCounter= OldBlockCounter;
                                }                              
                            }
                        }   
                        else
                        {   
                            RetVal = E_NOT_OK;
                            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                        }   
                    }   
                }     
            }
	    }
    }
    return RetVal;
}
#endif


#if(DCM_SVC_37_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_37ServiceProcess(Dcm_MsgContextType *pMsgContext)
 Description         : RoutineControl Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  : NRC_NOTSUPPORTEDINACTIVESESSION provided by Dcm_Dsd
 **************************************************************************/
Std_ReturnType Dcm_37ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
  *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
  Std_ReturnType RetVal = DCM_E_NOT_OK;
	
  if(NULL != pMsgContext)
  {
    if (OpStatus == DCM_CANCEL)
    {
      RetVal = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
      if ((Dcm_DataTransfer.Dcm_DataTransferState == DCM_DATA_TRANSFER_DONE_STATE)||(Dcm_DataTransfer.Dcm_DataTransferState == DCM_DOWNLOAD_STATE_READY_FOR_TRANSFER)||(Dcm_DataTransfer.Dcm_DataTransferState == DCM_UPLOAD_STATE_READY_FOR_TRANSFER))
      {
	      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        if(pMsgContext->reqDataLen == 0u)
        {
          *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;				   
          RetVal = DCM_37S_PRE_CONDITION_CHECK(OpStatus, pMsgContext, ErrorCode);
          if(DCM_E_OK == RetVal)
          {
            *ErrorCode=DCM_E_POSITIVERESPONSE;
            pMsgContext-> resDataLen= 1;
            Dcm_DataTransfer.Dcm_DataTransferState= DCM_DATA_TRANSFER_STATE_IDLE;
            Dcm_DataTransfer.MemAddress= 0u;
            Dcm_DataTransfer.MemSize= 0u;
            Dcm_DataTransfer.Blocklength= 0u;
            Dcm_DataTransfer.Dcm_DataTransferOldBlockCounter= 0u;
          }
        }
      }
    }
  }
  return RetVal;
}
#endif

#if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_2FServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : InputOutputControlByIdentifier
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_2FServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint16 Did = 0u;
    uint16 Counter = 0u;
    uint16 fl_Length = 0u;
    uint16 Index = 0u;
    uint8 StateRef = 0u;
    DidOpFuncType FuncPtr ;
    Dcm_SesCtrlType Session = 0u;
    Dcm_SecLevelType Security = 0u;

    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    Did = ((uint16) ((((uint16) pMsgContext->reqData[0] << DCM_DSP_0x08U)) | (uint16) (pMsgContext->reqData[DCM_DSP_0x01u])));
    fl_Length = Dcm_DspDidIdentifierTable[0];
    if(fl_Length == DcmNumOfDIDSupported)
    {
        for (Counter = 0u; Counter < fl_Length; Counter++)
        {
            if((Dcm_DspDidIdentifierTable[Counter + DCM_DSP_0x01u] == Did)&& (Dcm_DspDidInfo[Counter].DcmDspDidUsed == TRUE))
            {
                fl_Length = 0x0;
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                if((Dcm_DspDidInfo[Counter].Operations & DCM_DIDMGR_OPTYPE_IO) == DCM_DIDMGR_OPTYPE_IO)
                {
                    Index = Dcm_DspDidInfo[Counter].OpInfoRef;
                    Index = Dcm_DspGetStateRefIndex (Index, Dcm_DspDidInfo[Counter].Operations, DCM_DIDMGR_OPTYPE_IO);
                    if(Index < DcmDspNumOfDidOpInfo)
                    {
                        StateRef = Dcm_DspDidOpInfo[Index].State_Ref;
                        (void) Dcm_GetSesCtrlTypeIndex (&Session);
                        if(DCM_FALSE != (DCM_SESSION_STATE_CHECK(StateRef,Session)))
                        {
                            if(DCM_FALSE != (Dcm_DspDidOpInfo[Index].CallTypes & (DCM_DSP_0x01u << pMsgContext->resData[DCM_DSP_0x03u])))
                            {
                                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                                if(DCM_DSP_SHRTTRMADJ == pMsgContext->resData[DCM_DSP_0x03u])
                                {
                                    fl_Length = Dcm_DspDidOpInfo[Index].Max_ReqLength;
                                }
                                else
                                {
                                    fl_Length = Dcm_DspDidOpInfo[Index].Min_ReqLength;
                                }
                                if(pMsgContext->reqDataLen == (uint32)(fl_Length + DCM_DSP_0x03u))
                                {
                                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                                    RetVal = DCM_2FS_PRE_CONDITION_CHECK(pMsgContext,ErrorCode); 
                                    if (DCM_E_OK == RetVal)
                                    {
                                        RetVal = DCM_E_NOT_OK;
                                        *ErrorCode = DCM_E_SECURITYACCESSDENIED;      
                                        (void) Dcm_GetSecurityLevel (&Security);
                                        if(DCM_FALSE != (DCM_SECURITY_STATE_CHECK(StateRef,Security)))
                                        {
                                            Index = Dcm_DspDidOpInfo[Index].SignalInfo_Ref;
                                            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                                            if(Index < DcmDspNumOfDidSignalInfo)
                                            {
                                                if(FALSE != (Dcm_DspDidSignalInfo[Index].FunClass & DCM_DIDMGR_OPCLS_WRITE_SYNC))
                                                {
                                                    pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x03u];
                                                    if(Dcm_DspDidSignalInfo[Index].DidOpFunc_Ref < DidNumOfOpFunc)
                                                    {
                                                        FuncPtr = DidOpFunc[Dcm_DspDidSignalInfo[Index].DidOpFunc_Ref];
                                                        if(NULL != FuncPtr)
                                                        {
                                                            *ErrorCode = DCM_E_POSITIVERESPONSE;
                                                            RetVal = FuncPtr( OpStatus, DCM_DSP_DID_IO,
                                                                          Did, pMsgContext->reqDataLen,
                                                                          pMsgContext->resData,
                                                                          &pMsgContext->resDataLen, ErrorCode);
                                                        }
                                                    }
                                                }
                                            }
                                        } // DCM_E_OK == DCM_2FS_PRE_CONDITION_CHECK();
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }

    if(RetVal == DCM_E_OK)
    {
        Dcm_2FSetActiveIODids(Did, pMsgContext);
    }
    return (RetVal);
}

/**************************************************************************
 Function name       : void Dcm_2FSetActiveIODids(Dcm_DspDidIdentifierTableType Did, 
 Description         : To set active IODIDs other than RCTU
 Parameters (in)     : Dcm_DspDidIdentifierTableType Did, Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : void
 Design Information  :
 **************************************************************************/
static void Dcm_2FSetActiveIODids(Dcm_DspDidIdentifierTableType Did, 
                                                Dcm_MsgContextType *pMsgContext)
{
   uint8 index;
    
  if(pMsgContext->resData[0] != DCM_DSP_RETCTRL2ECU)
  {
    Dcm_svc2FInfo.IsActive = DCM_TRUE;
    Dcm_svc2FInfo.ActiveDidcount++; 
    if(Dcm_svc2FInfo.ActiveDidcount > DCM_NO_IODIDS)
    {
        Dcm_svc2FInfo.ActiveDidcount = DCM_NO_IODIDS;
    } 
    for(index = 0; index < Dcm_svc2FInfo.ActiveDidcount; index++)      
    {
        if(Dcm_svc2FInfo.ActiveDid[index] == 0u)
        {
           Dcm_svc2FInfo.ActiveDid[index] = Did;
        }
    }  
  }
  else
  {
    for(index = 0; index < Dcm_svc2FInfo.ActiveDidcount; index++)
    {
      if(Dcm_svc2FInfo.ActiveDid[index] == Did)
      {
        Dcm_svc2FInfo.ActiveDid[index] = 0u;
        Dcm_svc2FInfo.ActiveDidcount--;
      }
    }
  }
}
#endif

#if(DCM_SVC_31_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_31ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : RoutineControl Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/

Std_ReturnType Dcm_31ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    RidOpFuncType FuncPtr ;
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint16 Rid = 0u;
    uint16 Counter = 0u;
    uint16 fl_length = 0u;
    uint16 Index = 0u;
    uint8 StateRef = 0u;
    uint8 SubFunction = 0u;

    *ErrorCode = DCM_E_SERVICENOTSUPPORTED;
    SubFunction = pMsgContext->reqData[0];
    Rid = ((uint16) ((((uint16) pMsgContext->reqData[DCM_DSP_0x01u] << DCM_DSP_0x08U)) | (uint16) (pMsgContext->reqData[DCM_DSP_0x02u])));

    fl_length = Dcm_DspRidIdentifierTable[0];
    if(fl_length == DcmNumOfRIDSupported)
    {
        for(Counter = 0u; Counter < fl_length; Counter++)
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            if((Dcm_DspRidIdentifierTable[Counter + DCM_DSP_0x01u] == Rid)&& (Dcm_DspRidInfo[Counter].DcmDspRidUsed == TRUE))
            {
              StateRef = Dcm_DspRidInfo[Counter].State_Ref;
              *ErrorCode = Dcm_DspCheckSessionSecurity (StateRef, DSP_DIAG_CHK_LVL_PARAMETER);
              if(DCM_E_POSITIVERESPONSE == *ErrorCode)
              {       
                *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                if((0u < SubFunction) && (SubFunction <= S31_MAX_SUPPORTED_SUB_FUNCTION))
                {
                    if(0u != (Dcm_DspRidInfo[Counter].Operation & (DCM_DSP_0x01u << (SubFunction - DCM_DSP_0x01u))))
                    {
                        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                        Index = Dcm_S31_Opindex_check (Dcm_DspRidInfo[Counter].Operation, SubFunction);
                        Index = Dcm_DspRidInfo[Counter].SignalInfo_Ref + Index;
                        if(Index < DcmDspNumOfRidSignalInfo)
                        {
                            if((pMsgContext->reqDataLen >= (Dcm_DspRidSignalInfo[Index].Min_ReqLength + DCM_DSP_0x03u))
                                    && (pMsgContext->reqDataLen <= (Dcm_DspRidSignalInfo[Index].Max_ReqLength + DCM_DSP_0x03u)))
                            {
                                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                                    pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x04u];
                                    /* Exclude SF + RID as it is passed as function parameter */
                                    pMsgContext->reqDataLen = (pMsgContext->reqDataLen - DCM_DSP_0x03u);
                                    pMsgContext->resDataLen = Dcm_DspRidSignalInfo[Index].Max_RespLength;
                                    Index = Dcm_DspRidSignalInfo[Index].RidOpFunc_Ref;
                                    if(Index < RidNumOfOpFunc)
                                    {
                                        FuncPtr = RidOpFunc[Index];
                                        if(NULL != FuncPtr)
                                        {
                                            *ErrorCode = DCM_E_POSITIVERESPONSE;
                                            RetVal = FuncPtr(OpStatus, SubFunction, Rid, pMsgContext->reqDataLen, pMsgContext->resData,
                                                             &pMsgContext->resDataLen, ErrorCode);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    return (RetVal);
}
#endif

#if(DCM_SVC_3E_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_3EServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : Tester Present Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_3EServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;

    DCM_IGNORE_UNREF_PARAM(OpStatus);

    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    if(pMsgContext->reqData[0] == DCM_S3E_ZEROSUBFUNCTION)
    {
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        if(pMsgContext->reqDataLen == DCM_DSP_0x01u)
        {
            RetVal = DCM_E_OK;
            pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x02u];
            pMsgContext->resDataLen = 0u;
        }
    }
    return (RetVal);
}

#endif

#if(DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_27ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : SecurityAccess Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_27ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    uint8 SubFunction = 0u;
    uint8 Counter = 0u;
    uint8 StateRef = 0u;
    Std_ReturnType RetVal = DCM_E_NOT_OK;

    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

    SubFunction = pMsgContext->reqData[0];

    /* No_of_security_level */
    for (Counter = 0u; Counter < (No_of_security_level * DCM_DSP_0x02u); Counter++)
    {
        *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        if(Dcm_DsdSubService27[Counter].SubServiceId == SubFunction)
        {
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            if(Dcm_DsdSubService27[Counter].Req_Length == pMsgContext->reqDataLen)
            {
                StateRef = Dcm_DsdSubService27[Counter].State_Ref;
                *ErrorCode = Dcm_DspCheckSessionSecurity (StateRef, DSP_DIAG_CHK_LVL_SUBFUNC);
                if(DCM_E_POSITIVERESPONSE == (*ErrorCode))
                {
                    switch (SubFunction % DCM_DSP_0x02u)
                    {
                        /* send key*/
                        case 0:
                            *ErrorCode = Dcm_27Service_key_Process(OpStatus, pMsgContext, SubFunction, Counter);
                            break;
                        /* request seed*/
                        case 1:
                            #if(S27_FAIL_COUNT_NVM_SUPPORTED == TRUE)
                            if(ReadFailCounter(&S27_fail_counter) == NVM_REQ_PENDING)
                            {
                                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                            }
                            else
                            #endif /* (S27_FAIL_COUNT_NVM_SUPPORTED == TRUE) */
                            {
                                *ErrorCode = Dcm_27Service_seed_Process(OpStatus, pMsgContext, SubFunction, Counter);
                            }
                            break;
                        default:
                            /* This is not reachable */
                            break;
                    }
                }
            }
            break;
        }
    }
    if((*ErrorCode) == DCM_E_POSITIVERESPONSE)
    {
        RetVal = DCM_E_OK;
    }
    else if((*ErrorCode) == DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING)
    {
        RetVal = DCM_E_PENDING;
    }
    else
    {
        RetVal = DCM_E_NOT_OK;
    }
    return RetVal;
}
#endif

#if(DCM_SVC_28_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_28ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : Communication Control Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_28ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    uint8 ComM_Type = 0u;
    uint8 ComM_Action = 0u;
    uint8 flIndex = 0u;
    Std_ReturnType RetVal = DCM_E_NOT_OK;

    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;

    #if(DcmDevAdditionalCoverityChecks == TRUE)
    if((NULL != pMsgContext) && (NULL != pMsgContext->reqData) && (NULL != pMsgContext->resData))
    #endif
    {
        for(flIndex = 0u; flIndex < NO_OF_SUPPORTTED_COM_CONTROL; flIndex++)
        {
            if(pMsgContext->reqData[0] == Dcm_DsdSubService28[flIndex].ControlType)
            {
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                if(pMsgContext->reqDataLen == DCM_DSP_0x02u)
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    /* Communication Type 0x00 - ISO reserved, Supported ComM Type 0x01 - 0x03 */
                    if(pMsgContext->reqData[DCM_DSP_0x01u] == Dcm_DsdSubService28[flIndex].CommunicationType)
                    {
                        RetVal = DCM_28S_PRE_CONDITION_CHECK(pMsgContext, ErrorCode);
                        if (DCM_E_OK == RetVal)
                        {
                            pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x02u];
                            ComM_Action = pMsgContext->reqData[0] & DCM_DSP_0x03u;
                            ComM_Type = pMsgContext->reqData[DCM_DSP_0x01u] & DCM_DSP_0x03u;
                            pMsgContext->resDataLen = 0u;
                            RetVal = DCMEXT_COMM_ACTION(OpStatus, ComM_Type, ComM_Action);
                            if(RetVal == DCM_E_OK)
                            {
                                Communication_Status = ComM_Action;
                            }
                        }
                    } /* if (DCM_E_OK == DCM_28S_PRE_CONDITION_CHECK()) */
                }
            }
        }
    }
    return (RetVal);
}
#endif

#if(DCM_SVC_2E_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_2EServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : WriteDataByIdentifier Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_2EServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    DidOpFuncType FuncPtr ;
    Dcm_DspDidSignalInfoType SignalInfo;
    Dcm_SesCtrlType Session = 0u;
    Dcm_SecLevelType Security = 0u;
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint16 Did = 0u;
    uint16 Counter   = 0u;
    uint16 fl_length = 0u;
    uint16 Index     = 0u;
    uint8 StateRef   = 0u;

    *ErrorCode = DCM_E_SERVICENOTSUPPORTED;
    Did = ((uint16)((((uint16)pMsgContext->reqData[0] << DCM_DSP_0x08U)) | (uint16)(pMsgContext->reqData[DCM_DSP_0x01u])));

    fl_length = Dcm_DspDidIdentifierTable[0];
    if(fl_length == DcmNumOfDIDSupported)
    {
        for( Counter = 0; Counter < fl_length; Counter++ )
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            if( (Dcm_DspDidIdentifierTable[Counter + DCM_DSP_0x01u] == Did)&& (Dcm_DspDidInfo[Counter].DcmDspDidUsed == TRUE) )
            {
                if( (Dcm_DspDidInfo[Counter].Operations & DCM_DIDMGR_OPTYPE_WRITE) == DCM_DIDMGR_OPTYPE_WRITE )
                {
                    Index  = Dcm_DspDidInfo[Counter].OpInfoRef;
                    Index = Dcm_DspGetStateRefIndex (Index, Dcm_DspDidInfo[Counter].Operations, DCM_DIDMGR_OPTYPE_WRITE);
                    if( Index < DcmDspNumOfDidOpInfo )
                    {
                      StateRef = Dcm_DspDidOpInfo[Index].State_Ref;
                      (void) Dcm_GetSesCtrlTypeIndex (&Session);
                      if(DCM_FALSE != (DCM_SESSION_STATE_CHECK(StateRef,Session)))
                      {
                        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                        if(    (pMsgContext->reqDataLen >= (Dcm_DspDidOpInfo[Index].Min_ReqLength + 2u))
                                && (pMsgContext->reqDataLen <= (Dcm_DspDidOpInfo[Index].Max_ReqLength + DCM_DSP_0x02u)) )
                        {
                            *ErrorCode = DCM_E_SECURITYACCESSDENIED;      
                            (void) Dcm_GetSecurityLevel (&Security);
                            if(DCM_FALSE != (DCM_SECURITY_STATE_CHECK(StateRef,Security)))
                            {
                                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                                if( DCM_FALSE != (Dcm_DspDidOpInfo[Index].CallTypes & DCM_DIDMGR_OPCLS_WRITE_SYNC) )
                                {
                                    Index  = Dcm_DspDidOpInfo[Index].SignalInfo_Ref;
                                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                                    if(Index < DcmDspNumOfDidSignalInfo)
                                    {
                                        SignalInfo = Dcm_DspDidSignalInfo[Index];
                                        if(FALSE != (SignalInfo.FunClass & DCM_DIDMGR_OPCLS_WRITE_SYNC))
                                        {
                                            pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x03u];
                                            pMsgContext->reqDataLen = (pMsgContext->reqDataLen - DCM_DSP_0x02u);
                                            if(SignalInfo.DidOpFunc_Ref < DidNumOfOpFunc)
                                            {
                                                FuncPtr = DidOpFunc[SignalInfo.DidOpFunc_Ref];
                                                if(NULL != FuncPtr)
                                                {
                                                    *ErrorCode = DCM_E_POSITIVERESPONSE;
                                                    RetVal = FuncPtr( OpStatus, DCM_DSP_DID_WRITE,
                                                                      Did, pMsgContext->reqDataLen,
                                                                      pMsgContext->resData,
                                                                      &pMsgContext->resDataLen, ErrorCode);
                                                   }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    return( RetVal );
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_86_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Std_ReturnType Dcm_19ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ReadDTCInformation Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_19ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint8 Counter = 0u;
    uint8 StateRef = 0u;

    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;

    for (Counter = 0u; Counter < Svc19NumOfsubFunc; Counter++)
    {
        if(pMsgContext->reqData[0] == Dcm_DsdSubService19[Counter].SubServiceId)
        {
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            if(pMsgContext->reqDataLen == Dcm_DsdSubService19[Counter].Length)
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                StateRef = Dcm_DsdSubService19[Counter].State_Ref;
                *ErrorCode = Dcm_DspCheckSessionSecurity (StateRef, DSP_DIAG_CHK_LVL_SUBFUNC);
                if(DCM_E_POSITIVERESPONSE == (*ErrorCode))
                {
                    #if(DcmDevAdditionalCoverityChecks == TRUE)
                    if((NULL != Dcm_DsdSubService19[Counter].SubServiceFnc) && (NULL != pMsgContext->resData))
                    #endif
                    {
                        pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x02u];
                        RetVal = Dcm_DsdSubService19[Counter].SubServiceFnc(OpStatus, pMsgContext, ErrorCode);
                    }
                }
            }
            break;
        }
    }

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
    uint8 Index;
    for(Index = 0; Index < Svc86NumOfROE; Index++)
    {
        /* Ideally it should be checked with Dcm_DspRoeOnDTCStatusChange.Strtrd[1], not hard-coded 0x0E */
        if(   (pMsgContext->reqData[0] == DCM_DSP_0x0EU)
                && (Dcm_DspROEInternal[Index].RoeExpected != DCM_FALSE))
        {
            *ErrorCode = DCM_E_POSITIVERESPONSE;
            pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x02u];
            RetVal = Dcm_DspService19_0EProcessor(OpStatus, pMsgContext, ErrorCode);
            break;
        }
    }
#endif

    return (RetVal);
}
#endif

#if(DCM_SVC_14_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_14ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : Clear DiagnosticInformation Service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_14ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    Std_ReturnType SelectDtcType = 0u;

    DCM_IGNORE_UNREF_PARAM(OpStatus);

    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    if(pMsgContext->reqDataLen == DCM_DSP_0x03u)
    {
        Group_DTC = ((uint32)(  ((uint32)pMsgContext->reqData[0] << DCM_DSP_16U)
                                | ((uint32)pMsgContext->reqData[DCM_DSP_0x01u] <<  DCM_DSP_0x08U)
                                | ((uint32)pMsgContext->reqData[DCM_DSP_0x02u] <<  0u)));
                                
        SelectDtcType = Dcm_DemInternalClearProcessing(pMsgContext,Group_DTC);                                                
        switch (SelectDtcType)
        {
        case DEM_CLEAR_PENDING:
            *ErrorCode = DCM_E_POSITIVERESPONSE;
            RetVal = DCM_E_PENDING; /* try again later */
            break;

        case DEM_CLEAR_WRONG_DTC:
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            RetVal = DCM_E_NOT_OK;
            break;

        case DEM_CLEAR_OK:
            RetVal = Dcm_ClearDTCCheckFnc(Group_DTC, ErrorCode);
            if (DCM_E_OK == RetVal)
            {
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    DCM_14S_PRE_NOTIFICATION();
                    RetVal = Dem_ClearDTC(pMsgContext->DemClientId);
                    switch (RetVal)
                    {
                    case DEM_CLEAR_OK:
                        pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x01u];
                        pMsgContext->resDataLen = 0u;
                        *ErrorCode = DCM_E_POSITIVERESPONSE;
                        RetVal = DCM_E_OK;
                        break;

                    case DEM_CLEAR_PENDING:
                        pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x01u];
                        pMsgContext->resDataLen = 0u;
                        *ErrorCode = DCM_E_POSITIVERESPONSE;
                        RetVal = DCM_E_PENDING; /* try again later */
                        break;

                    case DEM_CLEAR_WRONG_DTC:
                        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                        RetVal = DCM_E_NOT_OK;
                        break;

                    case DEM_CLEAR_FAILED:
                        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                        RetVal = DCM_E_NOT_OK;
                        break;

#if defined(DEM_CLEAR_BUSY)
                    case DEM_CLEAR_BUSY:
                        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                        RetVal = DCM_E_NOT_OK;
                        break;
#endif
#if defined(DEM_CLEAR_MEMORY_ERROR)
                    case DEM_CLEAR_MEMORY_ERROR:
                        *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                        RetVal = DCM_E_NOT_OK;
                        break;
#endif
                    default:
                        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                        RetVal = DCM_E_NOT_OK;
                        break;
                    }
                }
            }
            break;

        default:
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            RetVal = DCM_E_NOT_OK;
            break;
        }
    }
    return (RetVal);
}


/**************************************************************************
 Function name       : Std_ReturnType Dcm_DemInternalClearProcessing(uint32 Group_DTC)
 Description         : Clear DiagnosticInformation Service
 Parameters (in)     : uint32 Group_DTC
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DemInternalClearProcessing(const Dcm_MsgContextType *pMsgContext, uint32 Group_DTC)
{
    Std_ReturnType RetVal = E_NOT_OK;
    Dem_DTCOriginType DTCOrigin;

    /* Dynamically determine the DTC origin */
    DTCOrigin = Dem_InternalGetDTCOrigin(Group_DTC);

    if((DTCOrigin != DEM_DTC_ORIGIN_INVALID_MEMORY) || (Group_DTC == DEM_DTC_GROUP_ALL_DTCS))
    {
      RetVal = Dem_SelectDTC(pMsgContext->DemClientId, Group_DTC, DEM_DTC_FORMAT_UDS, DTCOrigin);
    
      if(RetVal == E_OK)
      {
        RetVal =  Dem_GetDTCSelectionResult(pMsgContext->DemClientId);
      }
    }
  
  return RetVal;
}
#endif

#if(DCM_SVC_85_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_85ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : ControlDTCSetting service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_85ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal;
    uint32 DTC_group = 0u;
    uint8 Counter = 0u;
    uint8 StateRef = 0u;
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    RetVal = DCM_85S_PRE_CONDITION_CHECK(pMsgContext, ErrorCode);
    if (E_OK == RetVal)
    {
        RetVal = DCM_E_NOT_OK;
        *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        for (Counter = 0u; Counter < Svc85NumOfsubFunc; Counter++)
        {
            if (pMsgContext->reqData[0] == Dcm_DsdSubService85[Counter].SubServiceId)
            {
                #if (DCM_SVC_85_DTC_GRP_ENABLED != FALSE)
                if (pMsgContext->reqDataLen == DCM_DSP_0x04u)
                #else
                if (pMsgContext->reqDataLen == DCM_DSP_0x01u)
                #endif
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    StateRef = Dcm_DsdSubService85[Counter].State_Ref;
                    *ErrorCode = Dcm_DspCheckSessionSecurity (StateRef, DSP_DIAG_CHK_LVL_SUBFUNC);
                    if (DCM_E_POSITIVERESPONSE == (*ErrorCode))
                    {
                        #if (DCM_SVC_85_DTC_GRP_ENABLED != FALSE)
                        DTC_group = ((uint32)( (((uint32)pMsgContext->reqData[DCM_DSP_0x01u] << DCM_DSP_16U))
                                               | ((uint32)pMsgContext->reqData[DCM_DSP_0x02u] << DCM_DSP_0x08U)
                                               | ((uint32)pMsgContext->reqData[DCM_DSP_0x03u])));
                        #else
                        DTC_group = DEM_DTC_GROUP_ALL_DTCS;
                        #endif
						if (DTC_group != 0xFFFFFFu)
						{
						  *ErrorCode= DCM_E_REQUESTOUTOFRANGE;
						}
						else
						{
                            RetVal = Dcm_DsdSubService85[Counter].SubServiceFnc(pMsgContext->DemClientId);   
                            switch (RetVal)
                            {
                                case DEM_CONTROL_DTC_SETTING_OK:
                                    /* success */
                                    pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x02u];
                                    pMsgContext->reqDataLen = 0u;
                                    *ErrorCode = DCM_E_POSITIVERESPONSE;
                                    RetVal = DCM_E_OK;
                                    break;
                                case DEM_CONTROL_DTC_SETTING_N_OK:
                                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                                    RetVal = DCM_E_NOT_OK;
                                    break;
                                #if (DCM_SVC_85_DTC_GRP_ENABLED != FALSE)
                                case DEM_CONTROL_DTC_WRONG_DTCGROUP:
                                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                                    RetVal = DCM_E_NOT_OK;
                                    break;
                                #endif
                                default:
                                    *ErrorCode = DCM_E_PANIC_NRC;
                                    RetVal = DCM_E_NOT_OK;
                                    break;

                            }
						}
                    }
                }
                else
                {
                    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                }
                break;
            }
        }
    } //DCM_85S_PRE_CONDITION_CHECK
    DCM_IGNORE_UNREF_PARAM(OpStatus);
    return (RetVal);
}
#endif

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_86ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : Responsee On Event service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_86ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint8 Counter = 0u;

    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    for (Counter = 0u; Counter < Svc86NumOfsubFunc; Counter++)
    {
        if((DCM_DSP_0x3FU & pMsgContext->reqData[0]) == Dcm_DsdSubService86[Counter].SubServiceId)
        {
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            if(pMsgContext->reqDataLen == Dcm_DsdSubService86[Counter].Length)
            {
                *ErrorCode = DCM_E_POSITIVERESPONSE;
                /* Check Storage State in requested sub -function */
                if((DCM_DSP_0x40U & pMsgContext->reqData[0]) != FALSE)
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    /* If storage state is set then it should have infinite event window time */
                    if(pMsgContext->reqData[DCM_DSP_0x01u] == DCM_ROE_EVENT_WINDOW_INFINITE)
                    {
                        *ErrorCode = DCM_E_POSITIVERESPONSE;
                    }
                }
                if(DCM_E_POSITIVERESPONSE == (*ErrorCode))
                {
                    pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x01u];
                    RetVal = Dcm_DsdSubService86[Counter].SubServiceFnc(OpStatus, pMsgContext, ErrorCode);
                }
            }
            break;
        }
    }
    return (RetVal);
}

/**************************************************************************
Function name       : Dcm_DspService0x86_0x00Processor
Description         : Service 0x86 subfunction 0. stopResponseOnEvent
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService0x86_0x00Processor (Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType RetVal = DCM_E_OK;
    uint8 Index = 0u;

    DCM_IGNORE_UNREF_PARAM(OpStatus);

    for(Index = 0; Index < Svc86NumOfROE; Index++)
    {
        Dcm_DspROEInternal[Index].EventStatus = DCM_ROE_STOPPED;
        Dcm_DspROEInternal[Index].PreviousEventStatus = DCM_ROE_STOPPED;
    }
    Dem_DcmControlDTCStatusChangedNotification(DCM_FALSE);
    pMsgContext->resDataLen = DCM_DSP_0x02u;
    return (RetVal);
}

/**************************************************************************
Function name       : Dcm_DspService0x86_0x01Processor
Description         : Service 0x86 subfunction 1.
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService0x86_0x01Processor (Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint8 Index = 0u;
    uint8 EventId = DCM_DSP_0xFFU;

    DCM_IGNORE_UNREF_PARAM(OpStatus);

    *NegRes = DCM_E_REQUESTOUTOFRANGE;
    pMsgContext->resDataLen = DCM_DSP_0x01u;


    for(Index = 0; Index < Svc86NumOfROE; Index++)
    {
        if(DcmDspRoeEvent[Index].Prop == DCM_ROE_ONDTCSTATUSCHANGE)
        {
            EventId = Index;
            Index = Svc86NumOfROE;
        }
    }
    if(EventId != DCM_DSP_0xFFU)
    {
        *NegRes = DCM_E_POSITIVERESPONSE;
        for(Index = 0; Index < Svc86NumOfStrtrdParameters; Index++)
        {
            if(pMsgContext->resData[Index+DCM_DSP_0x02u] != Dcm_DspRoeOnDTCStatusChange.Strtrd[Index])
            {
                *NegRes = DCM_E_REQUESTOUTOFRANGE;
            }
        }
        if(*NegRes == DCM_E_POSITIVERESPONSE)
        {
            Dcm_DspROEInternal[EventId].StoreEvent = DCM_FALSE;
            if(pMsgContext->resData[0] & DCM_DSP_0x40U)
            {
                Dcm_DspROEInternal[EventId].StoreEvent = DCM_TRUE;
            }
            Dcm_DspROEInternal[EventId].EventStatus = DCM_ROE_STOPPED;
            Dcm_DspROEInternal[EventId].PreviousEventStatus = DCM_ROE_STOPPED;
            (void)Dcm_GetSesCtrlType(&Dcm_DspROEInternal[EventId].RequestedSession);
            Dcm_DspROEInternal[EventId].TesterSourceAddress = pMsgContext->rxPduId;
            Dcm_DspROEInternal[EventId].WindowTime = pMsgContext->resData[DCM_DSP_0x01u];
            if(Dcm_DspROEInternal[EventId].WindowTime > DCM_DSP_0x04u)
            {
                Dcm_DspROEInternal[EventId].WindowTimeCounter = (Dcm_DspROEInternal[EventId].WindowTime * DCM_DSP_100U);
            }
            pMsgContext->resData[DCM_DSP_0x01u] = Svc86NumOfROE;
            pMsgContext->resData[DCM_DSP_0x02u] = Dcm_DspROEInternal[EventId].WindowTime;
            for(Index = 0; Index < Svc86NumOfStrtrdParameters; Index++)
            {
                pMsgContext->resData[DCM_DSP_0x03u + Index] = Dcm_DspRoeOnDTCStatusChange.Strtrd[Index];
            }
            pMsgContext->resDataLen = DCM_DSP_0x04u;
            RetVal = DCM_E_OK;
        }
    }
    return (RetVal);
}

/**************************************************************************
Function name       : Dcm_DspService0x86_0x03Processor
Description         : Service 0x86 subfunction 3.
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService0x86_0x03Processor (Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
    return DCM_E_NOT_OK;
}

/**************************************************************************
Function name       : Dcm_DspService0x86_0x05Processor
Description         : Service 0x86 subfunction 5.startResponseOnEvent
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService0x86_0x05Processor (Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{

    uint8 Index = 0u;
    Std_ReturnType RetVal = DCM_E_OK;

    DCM_IGNORE_UNREF_PARAM(OpStatus);

    for(Index = 0; Index < Svc86NumOfROE; Index++)
    {
        Dcm_DspROEInternal[Index].EventStatus = DCM_ROE_STARTED;
        Dcm_DspROEInternal[Index].PreviousEventStatus = DCM_ROE_STARTED;
    }
    Dem_DcmControlDTCStatusChangedNotification(DCM_TRUE);
    /* Window Time */
    pMsgContext->reqData[DCM_DSP_0x02u] = pMsgContext->reqData[DCM_DSP_0x01u];
    /* numberOfIdentifiedEvents */
    pMsgContext->reqData[DCM_DSP_0x01u] = Svc86NumOfROE;
    pMsgContext->resDataLen = DCM_DSP_0x03u;
    return (RetVal);
}

/**************************************************************************
Function name       : Std_ReturnType Dcm_DspService0x86_0x06Processor(Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
Description         : Service 0x86 subfunction 6 clearResponseOnEvent.
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService0x86_0x06Processor (Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType *NegRes)
{
    uint8 Index = 0u;
    Std_ReturnType RetVal = DCM_E_OK;

    DCM_IGNORE_UNREF_PARAM(OpStatus);

    for(Index = 0; Index < Svc86NumOfROE; Index++)
    {
        Dcm_DspROEInternal[Index].EventOccurred = DCM_FALSE;
        Dcm_DspROEInternal[Index].StoreEvent = DCM_FALSE;
        Dcm_DspROEInternal[Index].RoeExpected = DCM_FALSE;
        Dcm_DspROEInternal[Index].EventStatus = DCM_ROE_CLEARED;
        Dcm_DspROEInternal[Index].PreviousEventStatus = DCM_ROE_CLEARED;
        Dcm_DspROEInternal[Index].StatusMask = 0x0U;
        Dcm_DspROEInternal[Index].TesterSourceAddress = 0x0;
        Dcm_DspROEInternal[Index].RequestedSession = 0x0;
        Dcm_DspROEInternal[Index].WindowTime = DCM_ROE_EVENT_WINDOW_CURRENT_CYCLE;
    }
    Dem_DcmControlDTCStatusChangedNotification(DCM_FALSE);
    pMsgContext->resDataLen = DCM_DSP_0x02u;
    return (RetVal);
}
#endif /* #if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */

#if(DCM_SVC_87_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_87ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
 Description         : Link Control service
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_87ServiceProcess(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, Dcm_NegativeResponseCodeType* ErrorCode)
{
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint8 u8Counter = 0u;
    uint8 u8ParamCounter = 0u;
    uint8 u8StateRef = 0u;

    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    for(u8Counter = 0u; u8Counter < NO_OF_LINK_CTRL_TYPES; u8Counter++)
    {
        if(pMsgContext->reqData[0] == Dcm_LinkControlTypeEnable[u8Counter].LinkCtrlType)
        {
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            if(pMsgContext->reqDataLen == Dcm_LinkControlTypeEnable[u8Counter].Length)
            {
                *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                if(DCM_FALSE != Dcm_LinkControlTypeEnable[u8Counter].IsEnabled)
                {
                    u8StateRef = Dcm_LinkControlTypeEnable[u8Counter].State_Ref;
                    *ErrorCode = Dcm_DspCheckSessionSecurity(u8StateRef, DSP_DIAG_CHK_LVL_SUBFUNC);
                    if(DCM_E_POSITIVERESPONSE == (*ErrorCode))
                    {
                        switch(Dcm_LinkControlTypeEnable[u8Counter].LinkCtrlType)
                        {
                            case LC_VMTWFP:
                            {
                                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                                for(u8ParamCounter = 0u; u8ParamCounter < NO_OF_LINK_CTRL_MODES; u8ParamCounter++)
                                {
                                    if(pMsgContext->reqData[DCM_DSP_0x01u] == Dcm_LinkControlModeEnable[u8ParamCounter].LinkCtrlIdentifier)
                                    {
                                        if(DCM_FALSE != Dcm_LinkControlModeEnable[u8ParamCounter].IsEnabled)
                                        {
                                            if(NULL == Dcm_LinkControlModeEnable[u8ParamCounter].SubServiceFnc_VMTWFP)
                                            {
                                                /* no change speed, only positive response */
                                                *ErrorCode = DCM_E_POSITIVERESPONSE;
                                                RetVal = DCM_E_OK;
                                                pMsgContext->resData = &pMsgContext->reqData[DCM_DSP_0x01u];
                                                pMsgContext->resDataLen = 0;
                                                break;
                                            }
                                            else
                                            {
                                                RetVal = Dcm_LinkControlModeEnable[u8ParamCounter].SubServiceFnc_VMTWFP(OpStatus, pMsgContext, ErrorCode);
                                                if(DCM_E_OK == RetVal)
                                                {
                                                    pMsgContext->resData = &pMsgContext->reqData[DCM_DSP_0x01u];
                                                    pMsgContext->resDataLen = 0;
                                                }
                                                break;
                                            }
                                        }
                                    }
                                }
                                break;
                            }

                            case LC_VMTWSP:
                            {
                                uint32 u32Record = (uint32)(  ((uint32)(pMsgContext->reqData[DCM_DSP_0x01u]) << DCM_DSP_16U)
                                                              + ((uint32)(pMsgContext->reqData[DCM_DSP_0x02u]) <<  DCM_DSP_0x08U)
                                                              + ((uint32)(pMsgContext->reqData[DCM_DSP_0x03u]) <<  0));
                                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                                for(u8ParamCounter = 0u; u8ParamCounter < NO_OF_LINK_REC_MODES; u8ParamCounter++)
                                {
                                    if(u32Record == Dcm_LinkRecordEnable[u8ParamCounter].LinkRecordIdentifier)
                                    {
                                        if(NULL == Dcm_LinkRecordEnable[u8ParamCounter].SubServiceFnc_VMTWSP)
                                        {
                                            /* no change speed, only positive response */
                                            *ErrorCode = DCM_E_POSITIVERESPONSE;
                                            RetVal = DCM_E_OK;
                                            pMsgContext->resData = &pMsgContext->reqData[DCM_DSP_0x01u];
                                            pMsgContext->resDataLen = 0;
                                            break;
                                        }
                                        else
                                        {
                                            RetVal = Dcm_LinkRecordEnable[u8ParamCounter].SubServiceFnc_VMTWSP(OpStatus, pMsgContext, ErrorCode);
                                            if(DCM_E_OK == RetVal)
                                            {
                                                pMsgContext->resData = &pMsgContext->reqData[DCM_DSP_0x01u];
                                                pMsgContext->resDataLen = 0;
                                            }
                                            break;
                                        }
                                    }
                                }
                                break;
                            }

                            case LC_TM:
                            {
                                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                                if(NULL == Dcm_LinkTransitionMode.SubServiceFnc_TM)
                                {
                                    /* no change speed, only positive response */
                                    *ErrorCode = DCM_E_POSITIVERESPONSE;
                                    RetVal = DCM_E_OK;
                                    pMsgContext->resData = &pMsgContext->reqData[DCM_DSP_0x01u];
                                    pMsgContext->resDataLen = 0;
                                }
                                else
                                {
                                    RetVal = Dcm_LinkTransitionMode.SubServiceFnc_TM(OpStatus, pMsgContext, ErrorCode);
                                    if(DCM_E_OK == RetVal)
                                    {
                                        pMsgContext->resData = &pMsgContext->reqData[DCM_DSP_0x01u];
                                        pMsgContext->resDataLen = 0;
                                    }
                                }
                                break;
                            }
                        } /* switch */
                    }
                }
            }
        }
    }
    return (RetVal);
}
#endif /* DCM_SVC_87_SUPPORT_ENABLED */

/**************************************************************************
 Function name       : Dcm_DspDemTriggerOnDTCStatus(uint32 DTC,
                       Dem_UdsStatusByteType DTCStatusOld,
                       Dem_UdsStatusByteType DTCStatusNew)
 Description         :
 Parameters (in)     : uint32 DTC,
                       Dem_UdsStatusByteType DTCStatusOld,
                       Dem_UdsStatusByteType DTCStatusNew
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspDemTriggerOnDTCStatus(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew)
{
    Std_ReturnType fl_RetVal = DCM_E_OK;

    DCM_IGNORE_UNREF_PARAM(DTC);
    DCM_IGNORE_UNREF_PARAM(DTCStatusOld);
#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
    uint8 Index = 0u;
    if(DTCStatusNew & DEM_UDS_STATUS_CDTC)
    {
        for(Index = 0; Index < Svc86NumOfROE; Index++)
        {
            if(DcmDspRoeEvent[Index].Prop == DCM_ROE_ONDTCSTATUSCHANGE)
            {
                if(Dcm_DspROEInternal[Index].EventStatus == DCM_ROE_STARTED)
                {
                    Dcm_DspROEInternal[Index].EventOccurred = DCM_TRUE;
                }
            }
        }
    }
#else
    DCM_IGNORE_UNREF_PARAM(DTCStatusNew);
#endif
    return fl_RetVal;
}

/**************************************************************************
 Function name   : void Dsp_DslConfirmation
 Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
 Return type     : void
 Description     : Dcm Confirmation.
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(DcmRxPduId);
 ** DCM_IGNORE_UNREF_PARAM(result);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/

void Dsp_DslConfirmation(PduIdType DcmRxPduId, Std_ReturnType result)
{
    /*QAC fix*/
    DCM_IGNORE_UNREF_PARAM(DcmRxPduId);

    DcmExt_Confirmation(result);
    if(DCM_FALSE != (Dsp_PostProcessingFlag & DSP_Fbl_EntryReset))
    {
        Dsp_PostProcessingFlag &= ~DSP_Fbl_EntryReset;
        DCMEXT_PERFORM_HARD_RESET();
    }
}

/**************************************************************************
 Function name   : Dcm_DspCheckSessionSecurity
 Arguments       : uint8 StateRef, Dcm_DspDiagCheckLvlType LevelRef
 Return type     : Dcm_NegativeResponseCodeType
 Description     :
 **************************************************************************/
Dcm_NegativeResponseCodeType Dcm_DspCheckSessionSecurity(uint8 StateRef, Dcm_DspDiagCheckLvlType LevelRef)
{
    Dcm_NegativeResponseCodeType NegRes = DCM_E_REQUESTOUTOFRANGE;
    Dcm_SesCtrlType flSessionIndex = 0u;
    Dcm_SecLevelType fl_Security = 0u;

    (void) Dcm_GetSesCtrlTypeIndex (&flSessionIndex);

    if(StateRef < DcmDsdNumOfStateRef)
    {
        if(((Dcm_DsdStateRef[StateRef].Session) & (DCM_DSP_0x01u << flSessionIndex)) != DCM_FALSE)
        {
            NegRes = DCM_E_SECURITYACCESSDENIED;
            (void) Dcm_GetSecurityLevel (&fl_Security);
            if(((Dcm_DsdStateRef[StateRef].Security) & (DCM_DSP_0x01u << (fl_Security))) != DCM_FALSE)
            {
                NegRes = DCM_E_POSITIVERESPONSE;
            }
        }
        else
        {
            if(LevelRef < DSP_NUM_DIAG_CHK_LVLS)
            {
                NegRes = Dcm_StateSessionNrcs[LevelRef];
            }
        }
    }
    return NegRes;
}

#if((DCM_SVC_22_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_2E_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_2F_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name   : Dcm_DspGetStateRefIndex
 Arguments       : uint16 Index, uint8 Operations, uint8 ConditionRef
 Return type     : uint16
 Description     :
 **************************************************************************/
static uint16 Dcm_DspGetStateRefIndex(uint16 Index, uint8 Operations, uint8 ConditionRef)
{
    while (0 != ConditionRef)
    {
        if((FALSE != (Operations & DCM_DSP_0x01u)) && (Index < DcmDspNumOfDidOpInfo))
        {
            Index = Index + DCM_DSP_0x01u;
        }
        Operations = Operations >> DCM_DSP_0x01u;
        ConditionRef = ConditionRef >> DCM_DSP_0x01u;
    }
    Index = Index - DCM_DSP_0x01u;
    return Index;
}
#endif

#if(DCM_SVC_31_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name   : Dcm_S31_Opindex_check
 Arguments       : uint8 operation, uint8 subfunction
 Return type     : uint8
 Description     :
 **************************************************************************/
static uint8 Dcm_S31_Opindex_check(uint8 operation, uint8 subfunction)
{
    uint8 fl_return = E_OK;

    switch (operation)
    {
    case 1:
    case 3:
    case 7:
        /*CERT C fix 17225741 */
        if(subfunction > 0)
        {
            fl_return = subfunction - DCM_DSP_0x01u;
        }
        else
        {
            fl_return = E_NOT_OK;
        }
        break;
    case 2:
    case 4:
        fl_return = 0u;
        break;
    case 6:  
        fl_return = subfunction - DCM_DSP_0x02u;
        break;
    case 5:
        if(subfunction == DCM_DSP_0x01u)
        {
            fl_return = 0u;
        }
        else if(subfunction == DCM_DSP_0x03u)
        {
            fl_return = DCM_DSP_0x01u;
        }
        else
        {
            /*wrong place to come*/
        }
        break;
    default:
        /*Do nothing - MISRA Fix snaray12*/
        break;
    }
    return fl_return;
}
#endif

/**************************************************************************
 Function name   : Dcm_SessionChangeAction
 Arguments       : Dcm_OpStatusType OpStatus, uint8 SubFunction, uint8 Source
 Return type     : void
 Description     :
 **************************************************************************/
void Dcm_SessionChangeAction(Dcm_OpStatusType OpStatus, uint8 SubFunction, uint8 Source)
{
    #if(DCM_SVC_28_SUPPORT_ENABLED == STD_ON)
    uint8 counter = 0u;
    #endif

    #if(DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
    uint8 index = 0u;
    #endif

    DCMEXT_BROADCAST_SESSION_STATE_CHANGES(SubFunction, Source);

    #if(DCM_SVC_10_SUPPORT_ENABLED == STD_ON)
    Old_Session = SubFunction;
    #endif

    #if(DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
    /* Reset the Seed received as well for session change */
    for(index = 0; index < No_of_security_level; index++)
    {
        Request_seed_rcvd[index] = 0u;
    }
    #if(S27_STATIC_SEED_SUPPORTED == TRUE)
    for (index = 0u; index < S27_STATIC_SEED_BUFFER_SIZE; index++)
    {
        S27_SeedBuffer[index] = 0u;
    }
    #endif
    #endif

    #if(DCM_SVC_28_SUPPORT_ENABLED == STD_ON)
    for (counter = 0u; counter < NO_OF_SUPPORTTED_SESSIONS; counter++)
    {
        if(Dcm_SessionCommEnable[counter].Subfunction == SubFunction)
        {
            if(Dcm_SessionCommEnable[counter].Comm_support != FALSE)
            {
                /* empty */
            }
            else if(Communication_Status != DCM_ENABLE_RX_TX_NORM)
            {
                (void)DCMEXT_COMM_ACTION(OpStatus, DCM_DSP_0x01u, DCM_ENABLE_RX_TX_NORM);
                Communication_Status = DCM_ENABLE_RX_TX_NORM;
            }
            else
            {
                /*Do nothing*/
            }
        }
    }
    #endif


    #if(DCM_SVC_85_SUPPORT_ENABLED == STD_ON)    
    if(SubFunction == DCM_DSP_0x01u)
    {
        (void) Dem_EnableDTCSetting(DEM_DCM_CLIENT);
    }
    #endif  

    #if(DCM_SVC_36_SUPPORT_ENABLED == STD_ON)
	Dcm_DataTransfer.Dcm_DataTransferState= DCM_DATA_TRANSFER_STATE_IDLE;
	Dcm_DataTransfer.MemAddress= 0u;
	Dcm_DataTransfer.MemSize= 0u;
	Dcm_DataTransfer.Blocklength= 0u;
	Dcm_DataTransfer.Dcm_DataTransferOldBlockCounter= 0u;
    #endif

    #if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
    Dcm_svc2FStateChange(SubFunction);
    #endif
}

/**************************************************************************
 Function name   : Dcm_SecurityChangeAction
 Arguments       : uint8 SubFunction, uint8 Source
 Return type     : void
 Description     :
 **************************************************************************/
void Dcm_SecurityChangeAction(uint8 SubFunction, uint8 Source)
{
	DCMEXT_BROADCAST_SECURITY_STATE_CHANGES(SubFunction, Source);

    #if(DCM_SVC_36_SUPPORT_ENABLED == STD_ON)
	Dcm_DataTransfer.Dcm_DataTransferState= DCM_DATA_TRANSFER_STATE_IDLE;
	Dcm_DataTransfer.MemAddress= 0u;
	Dcm_DataTransfer.MemSize= 0u;
	Dcm_DataTransfer.Blocklength= 0u;
	Dcm_DataTransfer.Dcm_DataTransferOldBlockCounter= 0u;
    #endif

    #if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
    Dcm_svc2FStateChange(SubFunction);
    #endif
}

#if(DCM_SVC_2F_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name   : Dcm_svc2FStateChange
 Arguments       : uint8 State
 Return type     : void
 Description     :
 **************************************************************************/
static void Dcm_svc2FStateChange(uint8 State)
{
    Dcm_NegativeResponseCodeType NegRes = DCM_E_POSITIVERESPONSE;
    uint16 Did;
    uint16 fl_Length = 0u;
    uint16 Counter;
    uint16 count;
    uint16 Operation = 0u;
    uint8 StateRef = 0u;
    uint8 num_iodids = 0u;

    if(Dcm_svc2FInfo.IsActive == DCM_TRUE)
    {
        Dcm_svc2FInfo.IsActive = DCM_FALSE; 
        num_iodids = Dcm_svc2FInfo.ActiveDidcount;

        for(count = 0; count < num_iodids; count++)
        {
            fl_Length = Dcm_DspDidIdentifierTable[0];
            Did = Dcm_svc2FInfo.ActiveDid[count];
            for (Counter = 0u; Counter < fl_Length; Counter++)
            {        
               if(Dcm_DspDidIdentifierTable[Counter + 0x01u] == Did)
               {
                    Operation = Dcm_DspDidInfo[Counter].OpInfoRef;
                    Operation = Dcm_DspGetStateRefIndex (Operation, Dcm_DspDidInfo[Counter].Operations, DCM_DIDMGR_OPTYPE_IO);
                    if(DCM_FALSE != (Dcm_DspDidOpInfo[Operation].CallTypes & (0x01u << DCM_DSP_RETCTRL2ECU)))
                    {
                        StateRef = Dcm_DspDidOpInfo[Operation].State_Ref;
                        NegRes = Dcm_DspCheckSessionSecurity (StateRef, DSP_DIAG_CHK_LVL_PARAMETER);
                        if(DCM_E_POSITIVERESPONSE != NegRes)
                        {
                            NegRes = DCM_E_POSITIVERESPONSE;
                            DCM_2FS_STATE_CHANGE(Did, &NegRes);
                            Dcm_svc2FInfo.ActiveDid[count] = 0u;
                            Dcm_svc2FInfo.ActiveDidcount--;
                            break;              
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }          
                }
            }
        }
        if(Dcm_svc2FInfo.ActiveDidcount != 0u)
        {
            Dcm_svc2FInfo.IsActive = DCM_TRUE;
        }
    }   
}   
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_01_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_01Processor
 Description         : Service 19 subfunction 1.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRe
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_01Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    DCM_IGNORE_UNREF_PARAM(OpStatus);
    return Dcm_DspSvc19UtiReportNumDtcByStatusMaskData (DEM_SETFILTER_CLASS_01, pMsgContext->reqData[DCM_DSP_0x01u], 0,
            pMsgContext, NegRes);
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_02_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_02Processor
 Description         : Service 19 subfunction 2.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_02Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    DCM_IGNORE_UNREF_PARAM(OpStatus);
    return Dcm_DspSvc19UtiReportDtcByStatusMaskData (DEM_SETFILTER_CLASS_01,
            DCM_SVC_19_USE_MASK_REQ,
            pMsgContext, NegRes);
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_03_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_03Processor
 Description         : Service 19 subfunction 03.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_03Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    DCM_IGNORE_UNREF_PARAM(OpStatus);
    return Dcm_DspSvc19UtiSnapshotIdentification (DEM_SETFILTER_CLASS_01, pMsgContext, NegRes);
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_04_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_04Processor
 Description         : Service 19 subfunction 04.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_04Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    DCM_IGNORE_UNREF_PARAM(OpStatus);
    return Dcm_DspSvc19UtiSnapshotByDtc (DEM_SETFILTER_CLASS_01, pMsgContext, NegRes);
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_06_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_06Processor
 Description         : Service 19 subfunction 6.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_06Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    DCM_IGNORE_UNREF_PARAM(OpStatus);
    return Dcm_DspSvc19UtiExtendedData (DEM_SETFILTER_CLASS_01, pMsgContext, NegRes);
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_07_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
Function name       : Dcm_DspService19_07Processor
Description         : Service 19 subfunction 7.
Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                      Dcm_NegativeResponseCodeType *NegRes
Return value        : Std_ReturnType
Design Information  :
**************************************************************************/
Std_ReturnType Dcm_DspService19_07Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    DCM_IGNORE_UNREF_PARAM(OpStatus);
    /* Fix swapped function arguments - dtcStatusMask and dtcSeverity*/
    return Dcm_DspSvc19UtiReportNumDtcByStatusMaskData (DEM_SETFILTER_CLASS_02, pMsgContext->reqData[2], pMsgContext->reqData[1],
            pMsgContext, NegRes);
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_08_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_08Processor
 Description         : Service 19 subfunction 8.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_08Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    DCM_IGNORE_UNREF_PARAM(OpStatus);
    return Dcm_DspSvc19UtiReportDtcBySeverityMaskData (DEM_SETFILTER_CLASS_02,pMsgContext->reqData[2], pMsgContext->reqData[1],
            DCM_SVC_19_USE_MASK_REQ,
            pMsgContext, NegRes);
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_09_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_09Processor
 Description         : Service 19 subfunction 9.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_09Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType ret_val = DCM_E_NOT_OK;
    uint32 DTC = 0uL;
    Dem_ReturnGetSeverityOfDTCType lseverity = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
    Dem_ReturnGetFunctionalUnitOfDTCType lFunctionalUnit = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
    Dem_ReturnGetStatusOfDTCType lDtcStatus = DEM_STATUS_WRONG_DTC;

    DCM_IGNORE_UNREF_PARAM(OpStatus);

    pMsgContext->resData[DCM_DSP_0x03u] = pMsgContext->reqData[DCM_DSP_0x01u];
    pMsgContext->resData[DCM_DSP_0x04u] = pMsgContext->reqData[DCM_DSP_0x02u];
    pMsgContext->resData[DCM_DSP_0x05U] = pMsgContext->reqData[DCM_DSP_0x03u];
    DTC = (uint32)(  ((uint32)(pMsgContext->reqData[DCM_DSP_0x01u]) << DCM_DSP_16U)
                     | ((uint32)(pMsgContext->reqData[DCM_DSP_0x02u]) <<  DCM_DSP_0x08U)
                     | ((uint32)(pMsgContext->reqData[DCM_DSP_0x03u]) <<  0));
  	ret_val =  Dem_GetDTCStatusAvailabilityMask (pMsgContext->DemClientId, &pMsgContext->resData[0]);
    if(ret_val == E_OK)
    {
        pMsgContext->resData[0] = DemDtcStatusAvailabilityMask_Def;
        ret_val= Dem_SelectDTC(pMsgContext->DemClientId, DTC, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY); 
        if(E_OK == ret_val)
        {
            lseverity = Dem_GetSeverityOfDTC(pMsgContext->DemClientId, &pMsgContext->resData[DCM_DSP_0x01u]);
            lFunctionalUnit = Dem_GetFunctionalUnitOfDTC(pMsgContext->DemClientId, &pMsgContext->resData[2]);
            lDtcStatus = Dem_GetStatusOfDTC (pMsgContext->DemClientId, (uint8*) &pMsgContext->resData[6]);
        }
        if ((lseverity!= DEM_GET_SEVERITYOFDTC_OK) && (lFunctionalUnit != DEM_GET_FUNCTIONALUNITOFDTC_OK) && (lDtcStatus != DEM_STATUS_OK))
        {
            *NegRes = DCM_E_REQUESTOUTOFRANGE;
            ret_val = DCM_E_NOT_OK;
        }
        else
        {
            ret_val = DCM_E_OK;
            pMsgContext->resDataLen = DCM_DSP_0x07U;
        }
    }
    else
    {
        *NegRes = DCM_E_REQUESTOUTOFRANGE;
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_0A_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Std_ReturnType Dcm_DspService19_0AProcessor(Dcm_MsgContextType *pMsgContext)
 Description         : Service 19 subfunction 0x0A.
 Parameters (in)     : Dcm_MsgContextType *pMsgContext
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_0AProcessor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    DCM_IGNORE_UNREF_PARAM(OpStatus);
    return Dcm_DspSvc19UtiReportDtcByStatusMaskData (DEM_SETFILTER_CLASS_01,
            DCM_SVC_19_USE_MASK_ALL,
            pMsgContext, NegRes);
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_0C_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_0CProcessor
 Description         : Service 19 subfunction C.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_0CProcessor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType ret_val = DCM_E_NOT_OK;
    uint32 DTC = 0uL;

    DCM_IGNORE_UNREF_PARAM(OpStatus);
    ret_val = Dem_GetDTCByOccurrenceTime(pMsgContext->DemClientId, DEM_FIRST_DET_CONFIRMED_DTC, &DTC);
    if(ret_val == DCM_E_OK)
    {
        pMsgContext->resData[0] = DemDtcStatusAvailabilityMask;
        pMsgContext->resData[DCM_DSP_0x01u] = (uint8) (DTC >> DCM_DSP_16U);
        pMsgContext->resData[DCM_DSP_0x02u] = (uint8) (DTC >> DCM_DSP_0x08U);
        pMsgContext->resData[DCM_DSP_0x03u] = (uint8) (DTC);

        if(DEM_STATUS_OK == Dem_GetStatusOfDTC (pMsgContext->DemClientId, (uint8*) &pMsgContext->resData[DCM_DSP_0x04u]))
        {
            ret_val = DCM_E_OK;
        }
        else
        {
            *NegRes = DCM_E_REQUESTOUTOFRANGE;
            ret_val = DCM_E_NOT_OK;
        }
        pMsgContext->resDataLen = DCM_DSP_0x05U;
    }
    else
    {
        pMsgContext->resData[0] = DemDtcStatusAvailabilityMask;
        pMsgContext->resDataLen = DCM_DSP_0x01u;
        ret_val = DCM_E_OK;
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_14_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_14Processor
 Description         : Service 19 subfunction 0x14.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_14Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    DCM_IGNORE_UNREF_PARAM(OpStatus);
    return Dcm_DspSvc19UtiReportDtcByFdc (DEM_SETFILTER_CLASS_01,
                                          DCM_SVC_19_USE_MASK_ALL,
                                          pMsgContext, NegRes);
}
#endif

#if(((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_0E_SUPPORT_ENABLED == STD_ON)) || (DCM_SVC_86_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_0EProcessor
 Description         : Service 19 subfunction 0x0E.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_0EProcessor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType ret_val = DCM_E_NOT_OK;
    uint32 DTC = 0u;

    DCM_IGNORE_UNREF_PARAM(OpStatus);
    DCM_IGNORE_UNREF_PARAM(NegRes);

#if(DCM_SVC_86_SUPPORT_ENABLED == STD_ON)
    uint8 Index;
    for(Index = 0; Index < Svc86NumOfROE; Index++)
    {
        if(DcmDspRoeEvent[Index].Prop == DCM_ROE_ONDTCSTATUSCHANGE)
        {
            if(Dcm_DspROEInternal[Index].EventStatus == DCM_ROE_STARTED)
            {
                if(Dcm_DspROEInternal[Index].RoeExpected != FALSE)
                {
                    Dcm_DspROEInternal[Index].RoeExpected = FALSE;
                    ret_val = DCM_E_OK;
                }
            }
        }
    }
#endif

    ret_val = Dem_GetDTCByOccurrenceTime(pMsgContext->DemClientId, DEM_MOST_RECENT_FAILED_DTC, &DTC);
    if(ret_val == DCM_E_OK)
    {
        pMsgContext->resData[0] = DemDtcStatusAvailabilityMask_Def;
        pMsgContext->resData[DCM_DSP_0x01u] = (uint8) (DTC >> DCM_DSP_16U);
        pMsgContext->resData[DCM_DSP_0x02u] = (uint8) (DTC >> DCM_DSP_0x08U);
        pMsgContext->resData[DCM_DSP_0x03u] = (uint8) (DTC);
        if(DEM_STATUS_OK == Dem_GetStatusOfDTC (pMsgContext->DemClientId, (uint8*) &pMsgContext->resData[DCM_DSP_0x04u]))
        {
            ret_val = DCM_E_OK;
        }
        else
        {
            *NegRes = DCM_E_REQUESTOUTOFRANGE;
            ret_val = DCM_E_NOT_OK;
        }
        pMsgContext->resDataLen = DCM_DSP_0x05U;
    }
    else
    {
        pMsgContext->resData[0] = DemDtcStatusAvailabilityMask_Def;
        pMsgContext->resDataLen = DCM_DSP_0x01u;
        ret_val = DCM_E_OK;
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_17_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_17Processor
 Description         : Service 19 subfunction 0x17.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_17Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    uint8 dtcStatusMask = 0u;
    uint8 dtcStatusAvailMask = 0u;
    Dem_ReturnSetFilterType demResultSetFilter = DEM_WRONG_FILTER;
    Std_ReturnType ret_val = DCM_E_OK;
    uint8 MemoryId = 0u;

    dtcStatusMask = pMsgContext->reqData[1];/* save the requested mask */
    MemoryId = pMsgContext->reqData[2];

    if(MemoryId != DCM_USER_MEM_ID)
    {
        *NegRes = DCM_E_REQUESTOUTOFRANGE;
        ret_val = DCM_E_NOT_OK;
    }
    else
    {
        ret_val = Dem_GetDTCStatusAvailabilityMask (pMsgContext->DemClientId,&dtcStatusAvailMask); /* Copy the status availability mask (in any case) */
        if(ret_val == E_OK)
        {
            pMsgContext->resData[0] = MemoryId;
            pMsgContext->resData[1] = dtcStatusAvailMask;
            dtcStatusMask &= dtcStatusAvailMask; /* Form the relevant status bits */
            if(dtcStatusMask == 0u)
            {
                ret_val = DCM_E_OK;/* no DTCs to report */
                pMsgContext->resDataLen = DCM_DSP_0x02u;
            }
            else
            {
    
                demResultSetFilter = Dem_SetDTCFilter (pMsgContext->DemClientId, dtcStatusMask,
                                     DEM_DTC_FORMAT_UDS,
                                     Dcm_Svc19DemDtcFilterInfo[DEM_SETFILTER_CLASS_06].Origin,
                                     DEM_FILTER_WITH_SEVERITY_NO,
                                     0, /* parameter not used */
                                     DEM_FILTER_FOR_FDC_NO);
                *NegRes = DCM_E_REQUESTOUTOFRANGE;
                ret_val = DCM_E_NOT_OK;
                if(demResultSetFilter == DEM_FILTER_ACCEPTED)
                {
                    pMsgContext->resData = &pMsgContext->resData[2];
                    ret_val = Dcm_DspSvc19UtiDemGetNumFltrdDtc (pMsgContext);
                    if(ret_val == DCM_E_OK)
                    {
                        ret_val = Dcm_DspSvc19UtiDemGetNxtFltrdDtc (pMsgContext, DEM_FILTER_FOR_FDC_NO, DEM_FILTER_WITH_SEVERITY_NO);
                    }
                }
            }       
        }
        else
        {
            *NegRes = DCM_E_REQUESTOUTOFRANGE;
            ret_val = DCM_E_NOT_OK;
        }
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_18_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_18Processor
 Description         : Service 19 subfunction 0x18.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_18Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType ret_val = DCM_E_NOT_OK;
    Std_ReturnType SnapshotDataReturnStatus = DEM_GET_FFDATABYDTC_WRONG_DTC;
    uint8 SnapshotRecordNumber = 0u;
    uint8 flFreezeFrameIteration = 0U;
    uint32 DtcId = 0uL;
    uint8 MemoryId = 0u;
    uint16 flFFMultiRecordLength = 0U;
    uint16 flRespDataBufferLen = 5u;
    
    *NegRes = DCM_E_REQUESTOUTOFRANGE;
    DtcId = (uint32)(  ((uint32)(pMsgContext->reqData[DCM_DSP_0x01u]) << DCM_DSP_16U)
                       | ((uint32)(pMsgContext->reqData[DCM_DSP_0x02u]) <<  DCM_DSP_0x08U)
                       | ((uint32)(pMsgContext->reqData[DCM_DSP_0x03u]) <<  0));
    SnapshotRecordNumber = pMsgContext->reqData[DCM_DSP_0x04u];
    MemoryId = pMsgContext->reqData[DCM_DSP_0x05U];
    
    if(MemoryId != DCM_USER_MEM_ID)
    {
        *NegRes = DCM_E_REQUESTOUTOFRANGE;
        ret_val = DCM_E_NOT_OK;
    }
    else
    {    
        ret_val= Dem_SelectDTC(pMsgContext->DemClientId, DtcId, DEM_DTC_FORMAT_UDS, Dcm_Svc19DemDtcFilterInfo[DEM_SETFILTER_CLASS_06].Origin); 
        if(E_OK == ret_val)
        {
            pMsgContext->resData[0] = MemoryId;
            pMsgContext->resData[DCM_DSP_0x01u] = (uint8) (DtcId >> DCM_DSP_16U);
            pMsgContext->resData[DCM_DSP_0x02u] = (uint8) (DtcId >> DCM_DSP_0x08U);
            pMsgContext->resData[DCM_DSP_0x03u] = (uint8) (DtcId);
    
            ret_val= Dem_GetStatusOfDTC (pMsgContext->DemClientId, (uint8*) &pMsgContext->resData[DCM_DSP_0x04u]);
            if(DEM_STATUS_OK == ret_val)
            {
                ret_val= Dem_SelectFreezeFrameData(pMsgContext->DemClientId,SnapshotRecordNumber);
                if(E_OK == ret_val)
                {
                    SnapshotDataReturnStatus = Dem_GetNextFreezeFrameData(pMsgContext->DemClientId, &pMsgContext->resData[5], (uint16*) &flFFMultiRecordLength);
                    if(SnapshotDataReturnStatus == DEM_GET_FFDATABYDTC_OK)
                    {
                        pMsgContext->resDataLen = flFFMultiRecordLength;
                        pMsgContext->resDataLen += 5u; /*DTC H M L + DTC Status*/
                        ret_val = DCM_E_OK;
                    }
                    else if(SnapshotDataReturnStatus == DEM_GET_FFDATABYDTC_PENDING)
                    {
                        ret_val = DCM_E_PENDING;
                    }
                    else
                    {
                        *NegRes = DCM_E_REQUESTOUTOFRANGE;
                        ret_val = DCM_E_NOT_OK;
                        pMsgContext->resDataLen = 3u;
                    }
                }
            }
        }   
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_19_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : Dcm_DspService19_19Processor
 Description         : Service 19 subfunction 0x19.
 Parameters (in)     : Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Parameters (out)    : Dcm_MsgContextType *pMsgContext,
                       Dcm_NegativeResponseCodeType *NegRes
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
Std_ReturnType Dcm_DspService19_19Processor(Dcm_OpStatusType OpStatus,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Dem_ReturnGetFreezeFrameDataByDTCType ExtendedDataReturnStatus = DEM_RECORD_WRONG_DTC;
    uint8 ExtendedDataNumber = 0u;
    uint32 DtcId = 0u;
    uint8 MemoryId = 0u;
    uint16 flFFMultiRecordLength = 0u;
    Std_ReturnType ret_val = DCM_E_OK;


    DtcId = (uint32)(  ((uint32)(pMsgContext->reqData[DCM_DSP_0x01u]) << DCM_DSP_16U)
                       | ((uint32)(pMsgContext->reqData[DCM_DSP_0x02u]) <<  DCM_DSP_0x08U)
                       | ((uint32)(pMsgContext->reqData[DCM_DSP_0x03u]) <<  0));
    ExtendedDataNumber = pMsgContext->reqData[DCM_DSP_0x04u];

    MemoryId = pMsgContext->reqData[DCM_DSP_0x05U];

    if(MemoryId != DCM_USER_MEM_ID)
    {
        *NegRes = DCM_E_REQUESTOUTOFRANGE;
        ret_val = DCM_E_NOT_OK;
    }
    else
    {
        ret_val= Dem_SelectDTC(pMsgContext->DemClientId, DtcId, DEM_DTC_FORMAT_UDS, Dcm_Svc19DemDtcFilterInfo[DEM_SETFILTER_CLASS_06].Origin); 
    
        if(E_OK == ret_val)
        {
            pMsgContext->resData[0] = MemoryId;
            pMsgContext->resData[DCM_DSP_0x01u] = (uint8) (DtcId >> DCM_DSP_16U);
            pMsgContext->resData[DCM_DSP_0x02u] = (uint8) (DtcId >> DCM_DSP_0x08U);
            pMsgContext->resData[DCM_DSP_0x03u] = (uint8) (DtcId);
    
            ret_val= Dem_GetStatusOfDTC (pMsgContext->DemClientId, (uint8*) &pMsgContext->resData[DCM_DSP_0x04u]);
            if(DEM_STATUS_OK == ret_val)
            {
                pMsgContext->resDataLen = 5u;
                ret_val= Dem_SelectExtendedDataRecord(pMsgContext->DemClientId, ExtendedDataNumber);
                if(E_OK == ret_val)
                {
                    ExtendedDataReturnStatus = Dem_GetNextExtendedDataRecord (pMsgContext->DemClientId, &pMsgContext->resData[5], (uint16*) &flFFMultiRecordLength);
                    if(ExtendedDataReturnStatus == DEM_RECORD_OK)
                    {
                        pMsgContext->resDataLen += flFFMultiRecordLength;
                        ret_val = DCM_E_OK;
                    }
                    else
                    {
                        *NegRes = DCM_E_REQUESTOUTOFRANGE;
                        ret_val = DCM_E_NOT_OK;
                    }
                }
            }
        }
        else
        {
            *NegRes = DCM_E_REQUESTOUTOFRANGE;
            ret_val = DCM_E_NOT_OK;
        }
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && ((DCM_SVC_19_01_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_19_07_SUPPORT_ENABLED == STD_ON)))
/**************************************************************************
 Function name       : Std_ReturnType Dcm_DspSvc19UtiReportNumDtcByStatusMaskData(uint8 dsfClass,uint8 dtcStatusMask,uint8 dtcSeverity,Dcm_MsgContextType *pMsgContext)
 Description         : Report number of DTC by status mask.
 Parameters (in)     : uint8 dsfClass,uint8 dtcStatusMask,uint8 dtcSeverity,Dcm_MsgContextType *pMsgContext.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiReportNumDtcByStatusMaskData(uint8 dsfClass, uint8 dtcStatusMask,
        uint8 dtcSeverity, Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType ret_val = E_NOT_OK;
    Dem_ReturnSetFilterType demResultSetFilter = DEM_WRONG_FILTER;

    ret_val = Dem_GetDTCStatusAvailabilityMask (pMsgContext->DemClientId, pMsgContext->resData); /* Copy the status availability mask (in any case) */
    if(ret_val == E_OK)
    {
        dtcStatusMask &= pMsgContext->resData[0];
        if(0 != dtcStatusMask)
        {
            if(dsfClass < DEM_SETFILTER_NUM_CLASSES)
            {
                demResultSetFilter = Dem_SetDTCFilter (pMsgContext->DemClientId, dtcStatusMask,
                                     DEM_DTC_FORMAT_UDS,
                                     Dcm_Svc19DemDtcFilterInfo[dsfClass].Origin,
                                     Dcm_Svc19DemDtcFilterInfo[dsfClass].ConsiderSeverity, dtcSeverity,
                                     DEM_FILTER_FOR_FDC_NO);
                if(demResultSetFilter == DEM_FILTER_ACCEPTED)
                {
                    ret_val = Dcm_DspSvc19UtiDemGetNumFltrdDtc (pMsgContext);
                    if(ret_val == DCM_E_OK)
                    {
                        pMsgContext->resData[DCM_DSP_0x01u] = Dem_GetTranslationType(pMsgContext->DemClientId);
                        pMsgContext->resData[DCM_DSP_0x02u] = (uint8) (No_Of_Matching_DTC >> DCM_DSP_0x08U);
                        pMsgContext->resData[DCM_DSP_0x03u] = (uint8) (No_Of_Matching_DTC);
                        pMsgContext->resDataLen = DCM_DSP_0x04u;
                    }
                }
                else
                {
                    *NegRes = DCM_E_REQUESTOUTOFRANGE;
                    ret_val = DCM_E_NOT_OK;
                }
            }
            else
            {
                *NegRes = DCM_E_REQUESTOUTOFRANGE;
                ret_val = DCM_E_NOT_OK;
            }
        }
        else
        {
            pMsgContext->resData[DCM_DSP_0x01u] = Dem_GetTranslationType(pMsgContext->DemClientId);
            pMsgContext->resData[DCM_DSP_0x02u] = 0u;
            pMsgContext->resData[DCM_DSP_0x03u] = 0u;
            pMsgContext->resDataLen = DCM_DSP_0x04u;
            ret_val = DCM_E_OK;
        }
    }
    else
    {
        *NegRes = DCM_E_REQUESTOUTOFRANGE;
        ret_val = DCM_E_NOT_OK;
    }
    return ret_val;
}
#endif

#if(DCM_SVC_19_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : Std_ReturnType Dcm_DspSvc19UtiDemGetNumFltrdDtc(Dcm_MsgContextType *pMsgContext)
 Description         : Get the number of filtered DTC.
 Parameters (in)     : Dcm_MsgContextType *pMsgContext.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
/******************************MISRA Warning Begin***********************************
 ** CID : 3112
 ** MISRA Title : Redundancy
 ** MISRA: There shall be no dead code (MISRA C-2012 Rule 2.2)
 ** MISRA Message :
 ** This statement has no side-effect - it can be removed.
 ** DCM_IGNORE_UNREF_PARAM(pMsgContext);
 ** Rational:
 ** This warning is reviewed and team decided to approve since this implementation
 ** is design intended and it will not impact the functionalities.
 ** Approved Status: Yes
 ** Approved Date : 05-05-2017
 ** Approved By : DI COC Team
 ******************************MISRA Warning End************************************/
static Std_ReturnType Dcm_DspSvc19UtiDemGetNumFltrdDtc(Dcm_MsgContextType *pMsgContext) /* PRQA S 3673 *//* MD_Dcm_Design_3673 */
{
    Std_ReturnType ret_val = DCM_E_NOT_OK;
    uint8 demResult = DEM_NUMBER_FAILED;

    DCM_IGNORE_UNREF_PARAM(pMsgContext);

    demResult = Dem_GetNumberOfFilteredDTC (pMsgContext->DemClientId, &No_Of_Matching_DTC);
    switch (demResult)
    {
    case DEM_NUMBER_OK:
        ret_val = DCM_E_OK;
        break;
    case DEM_NUMBER_PENDING:
        ret_val = DCM_E_PENDING;
        break;
    default:
        ret_val = DCM_E_NOT_OK;
        break;
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_03_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiSnapshotIdentification(uint8 dsfClass, Dcm_MsgContextType *pMsgContext)
 Description         : Report number of Snapshot Identification.
 Parameters (in)     : uint8 dsfClass,Dcm_MsgContextType *pMsgContext.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiSnapshotIdentification(uint8 dsfClass, Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType ret_val = DCM_E_NOT_OK;
    Std_ReturnType lStdResult = DEM_WRONG_FILTER;
    Dem_ReturnSetFilterType SnapshotIDReturnStatus = DEM_WRONG_FILTER;
    uint16 NumOfFF = 0U;
    Dcm_MsgLenType remainingData = (Dcm_MsgLenType) pMsgContext->resMaxDataLen;

    *NegRes = DCM_E_REQUESTOUTOFRANGE;
    if(dsfClass < DEM_SETFILTER_NUM_CLASSES)
    {
        SnapshotIDReturnStatus = Dem_SetFreezeFrameRecordFilter(pMsgContext->DemClientId, DEM_DTC_FORMAT_UDS, &NumOfFF);
        if(SnapshotIDReturnStatus == DEM_FILTER_ACCEPTED)
        {
            lStdResult= Dcm_DspSvc19UtiCpyDemGetNxtFltrdRecord(pMsgContext->DemClientId, pMsgContext->resData, &remainingData, (uint8)NumOfFF);
            if(lStdResult == DEM_FILTER_ACCEPTED)
            {
                ret_val = DCM_E_OK;
            }
        }

        if(pMsgContext->resMaxDataLen >= remainingData)
        {
            remainingData = (Dcm_MsgLenType) (pMsgContext->resMaxDataLen - remainingData);
        }
        else
        {
            /*Handle with Error */
        }

        pMsgContext->resDataLen = remainingData; /* PRQA S 3109 *//* MD_MSR_14.3 */
    }
    return ret_val;
}

/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtFltrdRecord(Dcm_MsgType pData,Dcm_MsgLenType* pAvailLen)
 Description         : get next filtered data.
 Parameters (in)     : Dcm_MsgType pData,Dcm_MsgLenType* pAvailLen.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtFltrdRecord(Dcm_DemClientIdType DcmDemClientId, Dcm_MsgType pData, Dcm_MsgLenType *pAvailLen,
        uint8 NumberOfFilteredRecords)
{
    uint32 lDtc = 0U;
    uint16 lAvailLen = 0U;
    uint8 Record_Number = 0U;
    Dem_ReturnGetNextFilteredElementType lStdResult = DEM_FILTER_ACCEPTED;

    lAvailLen = (uint16)*pAvailLen;

    while(0u < NumberOfFilteredRecords)
    {
        lStdResult = Dem_GetNextFilteredRecord(DcmDemClientId, &lDtc, &Record_Number);
        if(lStdResult == DEM_FILTER_ACCEPTED)
        {
            pData[0] = (uint8) (lDtc >> DCM_DSP_16U);
            pData[DCM_DSP_0x01u] = (uint8) (lDtc >> DCM_DSP_0x08U);
            pData[DCM_DSP_0x02u] = (uint8) (lDtc);
            pData[DCM_DSP_0x03u] = Record_Number;
            /* commit data */
            pData = &(pData)[DCM_DSP_0x04u];
            lAvailLen -= DCM_DSP_0x04u;
        }
        NumberOfFilteredRecords--;
    }

    *pAvailLen = (uint16) lAvailLen; /* commit all copied data */
    return lStdResult; /*lint !e438 pData is always post incremented */
} /* PRQA S 6080 *//* MD_MSR_STMIF */
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_04_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiSnapshotByDtc(uint8 dsfClass, Dcm_MsgContextType *pMsgContext)
 Description         : Report number of DTC by status mask.
 Parameters (in)     : uint8 dsfClass,Dcm_MsgContextType *pMsgContext.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiSnapshotByDtc(uint8 dsfClass, Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType ret_val = DCM_E_NOT_OK;
    Std_ReturnType SnapshotDataReturnStatus = DEM_GET_FFDATABYDTC_WRONG_DTC;
    uint8 SnapshotRecordNumber = 0u;
    uint8 flFreezeFrameIteration = 0U;
    uint32 DtcId = 0uL;
    uint16 flFFMultiRecordLength = 0U;
    uint16 flRespDataBufferLen = DCM_DSP_0x04u;

    *NegRes = DCM_E_REQUESTOUTOFRANGE;
    DtcId = (uint32)(  ((uint32)(pMsgContext->reqData[DCM_DSP_0x01u]) << DCM_DSP_16U)
                       | ((uint32)(pMsgContext->reqData[DCM_DSP_0x02u]) <<  DCM_DSP_0x08U)
                       | ((uint32)(pMsgContext->reqData[DCM_DSP_0x03u]) <<  0));
    SnapshotRecordNumber = pMsgContext->reqData[DCM_DSP_0x04u];
    if(dsfClass < DEM_SETFILTER_NUM_CLASSES)
    {
        ret_val= Dem_SelectDTC(pMsgContext->DemClientId, DtcId, DEM_DTC_FORMAT_UDS, Dcm_Svc19DemDtcFilterInfo[dsfClass].Origin); 
        if(E_OK == ret_val)
        {
            ret_val= Dem_GetStatusOfDTC (pMsgContext->DemClientId, (uint8*) &pMsgContext->resData[DCM_DSP_0x03u]);
            if(DEM_STATUS_OK == ret_val)
            {
                #if(DemTypeofFreezeFrameRecordNumeration != DEM_FF_RECNUM_CALCULATED)
                if(SnapshotRecordNumber != DCM_DSP_0xFFU)
                #endif
                {
                    ret_val= Dem_SelectFreezeFrameData(pMsgContext->DemClientId,SnapshotRecordNumber);
                    if(E_OK == ret_val)
                    {
                        SnapshotDataReturnStatus = Dem_GetNextFreezeFrameData(pMsgContext->DemClientId, &pMsgContext->resData[DCM_DSP_0x04u], (uint16*) &flFFMultiRecordLength);
                        if(SnapshotDataReturnStatus == DEM_GET_FFDATABYDTC_OK)
                        {
                            pMsgContext->resDataLen = flFFMultiRecordLength;
                            pMsgContext->resDataLen += DCM_DSP_0x04u; /*DTC H M L + DTC Status*/
                            ret_val = DCM_E_OK;
                        }
                        else if(SnapshotDataReturnStatus == DEM_GET_FFDATABYDTC_PENDING)
                        {
                            ret_val = DCM_E_PENDING;
                        }
                        else
                        {
                            *NegRes = DCM_E_REQUESTOUTOFRANGE;
                            ret_val = DCM_E_NOT_OK;
                            pMsgContext->resDataLen = 3u;
                        }
                    }
                }
                #if(DemTypeofFreezeFrameRecordNumeration != DEM_FF_RECNUM_CALCULATED)                
                else
                {
                    for(flFreezeFrameIteration = 0U; flFreezeFrameIteration <= DCM_DSP_0xFEU; flFreezeFrameIteration++)
                    {
                        #if(DcmDevAdditionalCoverityChecks == TRUE)
                        if((DcmDslBufferSize - flRespDataBufferLen) > flRespDataBufferLen)
                        #endif
                        {
                            ret_val= Dem_SelectFreezeFrameData(pMsgContext->DemClientId,flFreezeFrameIteration);
                            if(E_OK == ret_val)
                            {
                                SnapshotDataReturnStatus = Dem_GetNextFreezeFrameData(pMsgContext->DemClientId, &pMsgContext->resData[DCM_DSP_0x04u], (uint16*) &flFFMultiRecordLength);
                                if(SnapshotDataReturnStatus == DEM_GET_FFDATABYDTC_OK)
                                {
                                    flRespDataBufferLen += flFFMultiRecordLength;
                                    ret_val = DCM_E_OK;
                                }
                                else if(SnapshotDataReturnStatus == DEM_GET_FFDATABYDTC_PENDING)
                                {
                                    ret_val = DCM_E_PENDING;
                                }
                                else
                                {
                                  /* keep empty */
                                }
                            }  
                        }
                    }
                    pMsgContext->resDataLen = flRespDataBufferLen;
                }
                #endif
            }
        }  
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_06_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiExtendedData(uint8 dsfClass, Dcm_MsgContextType *pMsgContext)
 Description         :
 Parameters (in)     : uint8 dsfClass,Dcm_MsgContextType *pMsgContext.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiExtendedData(uint8 dsfClass, Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Dem_ReturnGetFreezeFrameDataByDTCType ExtendedDataReturnStatus = DEM_RECORD_WRONG_DTC;
    uint8 ExtendedDataNumber = 0u;
    uint32 DtcId = 0u;
    uint16 flFFMultiRecordLength = 0u;
    Std_ReturnType ret_val = DCM_E_OK;

    pMsgContext->resData[0] = pMsgContext->reqData[DCM_DSP_0x01u];
    pMsgContext->resData[DCM_DSP_0x01u] = pMsgContext->reqData[DCM_DSP_0x02u];
    pMsgContext->resData[DCM_DSP_0x02u] = pMsgContext->reqData[DCM_DSP_0x03u];

    DtcId = (uint32)(  ((uint32)(pMsgContext->reqData[DCM_DSP_0x01u]) << DCM_DSP_16U)
                       | ((uint32)(pMsgContext->reqData[DCM_DSP_0x02u]) <<  DCM_DSP_0x08U)
                       | ((uint32)(pMsgContext->reqData[DCM_DSP_0x03u]) <<  0));
    ExtendedDataNumber = pMsgContext->reqData[DCM_DSP_0x04u];

    if(dsfClass < DEM_SETFILTER_NUM_CLASSES)
    {
        ret_val= Dem_SelectDTC(pMsgContext->DemClientId, DtcId, DEM_DTC_FORMAT_UDS, Dcm_Svc19DemDtcFilterInfo[dsfClass].Origin); 
        if(E_OK == ret_val)
        {
            ret_val= Dem_GetStatusOfDTC (pMsgContext->DemClientId, (uint8*) &pMsgContext->resData[DCM_DSP_0x03u]);
            if(DEM_STATUS_OK == ret_val)
            {
                pMsgContext->resDataLen = DCM_DSP_0x04u;
                ret_val= Dem_SelectExtendedDataRecord(pMsgContext->DemClientId, ExtendedDataNumber);
                if(E_OK == ret_val)
                {
                    ExtendedDataReturnStatus = Dem_GetNextExtendedDataRecord (pMsgContext->DemClientId, &pMsgContext->resData[4], (uint16*) &flFFMultiRecordLength);
                    if(ExtendedDataReturnStatus == DEM_RECORD_OK)
                    {
                        pMsgContext->resDataLen += flFFMultiRecordLength;
                        ret_val = DCM_E_OK;
                    }
                    else
                    {
                        *NegRes = DCM_E_REQUESTOUTOFRANGE;
                        ret_val = DCM_E_NOT_OK;
                    }
                }
            }
        }
        else
        {
            *NegRes = DCM_E_REQUESTOUTOFRANGE;
            ret_val = DCM_E_NOT_OK;
        }
    }
    else
    {
        *NegRes = DCM_E_REQUESTOUTOFRANGE;
        ret_val = DCM_E_NOT_OK;
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && ((DCM_SVC_19_01_SUPPORT_ENABLED == STD_ON) || (DCM_SVC_19_0A_SUPPORT_ENABLED == STD_ON)))
/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiReportDtcByStatusMaskData(uint8 dsfClass,Dcm_Svc19DemSetFilterMaskUsageType maskUsage,Dcm_MsgContextType *pMsgContext)
 Description         : Report number of DTC by status mask.
 Parameters (in)     : uint8 dsfClass,Dcm_Svc19DemSetFilterMaskUsageType maskUsage,Dcm_MsgContextType *pMsgContext.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiReportDtcByStatusMaskData(uint8 dsfClass,
        Dcm_Svc19DemSetFilterMaskUsageType maskUsage,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    uint8 dtcStatusMask = 0u;
    Dem_ReturnSetFilterType demResultSetFilter = DEM_WRONG_FILTER;
    Std_ReturnType ret_val = DCM_E_OK;

    dtcStatusMask = pMsgContext->resData[0];/* save the requested mask */
    ret_val = Dem_GetDTCStatusAvailabilityMask (pMsgContext->DemClientId,pMsgContext->resData); /* Copy the status availability mask (in any case) */
    if(ret_val == E_OK)
    {
        dtcStatusMask &= pMsgContext->resData[0]; /* Form the relevant status bits */
        if((maskUsage == DCM_SVC_19_USE_MASK_REQ) && (dtcStatusMask == 0u))
        {
            ret_val = DCM_E_OK;/* no DTCs to report */
            pMsgContext->resDataLen = DCM_DSP_0x01u;
        }
        else
        {
            if(maskUsage != DCM_SVC_19_USE_MASK_REQ)
            {
                dtcStatusMask = 0u; /* all DTCs to be filtered */
            }
            if(dsfClass < DEM_SETFILTER_NUM_CLASSES)
            {
                demResultSetFilter = Dem_SetDTCFilter (pMsgContext->DemClientId, dtcStatusMask,
                                     DEM_DTC_FORMAT_UDS,
                                     Dcm_Svc19DemDtcFilterInfo[dsfClass].Origin,
                                     DEM_FILTER_WITH_SEVERITY_NO,
                                     0, /* parameter not used */
                                     DEM_FILTER_FOR_FDC_NO);

                *NegRes = DCM_E_REQUESTOUTOFRANGE;
                ret_val = DCM_E_NOT_OK;
                if(demResultSetFilter == DEM_FILTER_ACCEPTED)
                {
                    pMsgContext->resData = &pMsgContext->resData[1];
                    ret_val = Dcm_DspSvc19UtiDemGetNumFltrdDtc (pMsgContext);
                    if(ret_val == DCM_E_OK)
                    {
                        ret_val = Dcm_DspSvc19UtiDemGetNxtFltrdDtc (pMsgContext, DEM_FILTER_FOR_FDC_NO, DEM_FILTER_WITH_SEVERITY_NO);
                    }
                }
            }
            else
            {
                *NegRes = DCM_E_REQUESTOUTOFRANGE;
                ret_val = DCM_E_NOT_OK;
            }
        }
    }
    else
    {
        *NegRes = DCM_E_REQUESTOUTOFRANGE;
        ret_val = DCM_E_NOT_OK;
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_08_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiReportDtcBySeverityMaskData(uint8 dsfClass,uint8 dtcStatusMask,uint8 dtcSeverity,Dcm_Svc19DemSetFilterMaskUsageType maskUsage,Dcm_MsgContextType *pMsgContext)
 Description         : Report number of DTC by Severity mask.
 Parameters (in)     : uint8 dsfClass,Dcm_Svc19DemSetFilterMaskUsageType maskUsage,Dcm_MsgContextType *pMsgContext.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiReportDtcBySeverityMaskData(uint8 dsfClass,uint8 dtcStatusMask,uint8 dtcSeverity,
        Dcm_Svc19DemSetFilterMaskUsageType maskUsage,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType ret_val = E_NOT_OK;
    Dem_ReturnSetFilterType demResultSetFilter;

  ret_val = Dem_GetDTCStatusAvailabilityMask (pMsgContext->DemClientId, &pMsgContext->resData[0]); /* Copy the status availability mask (in any case) */
    if(ret_val == E_OK)
    {
        dtcStatusMask &= pMsgContext->resData[0]; /* Form the relevant status bits */
        if((maskUsage == DCM_SVC_19_USE_MASK_REQ) && (dtcStatusMask == 0u))
        {
            ret_val = DCM_E_OK;/* no DTCs to report */
            pMsgContext->resDataLen = DCM_DSP_0x01u;
        }
        else
        {
            if(dsfClass < DEM_SETFILTER_NUM_CLASSES)
            {
        demResultSetFilter = Dem_SetDTCFilter (pMsgContext->DemClientId, dtcStatusMask, 
                                     DEM_DTC_FORMAT_UDS,
                                     Dcm_Svc19DemDtcFilterInfo[dsfClass].Origin,
                                     Dcm_Svc19DemDtcFilterInfo[dsfClass].ConsiderSeverity,
                                     dtcSeverity,
                                     DEM_FILTER_FOR_FDC_NO);

                *NegRes = DCM_E_REQUESTOUTOFRANGE;
                ret_val = DCM_E_NOT_OK;
                if(demResultSetFilter == DEM_FILTER_ACCEPTED)
                {
                    pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x01u];
                    ret_val = Dcm_DspSvc19UtiDemGetNumFltrdDtc (pMsgContext);
                    if(ret_val == DCM_E_OK)
                    {
                        ret_val = Dcm_DspSvc19UtiDemGetNxtFltrdDtc (pMsgContext, DEM_FILTER_FOR_FDC_NO, DEM_FILTER_WITH_SEVERITY_YES );
                    }
                }
            }
            else
            {
                *NegRes = DCM_E_REQUESTOUTOFRANGE;
                ret_val = DCM_E_NOT_OK;
            }
        }
    }
    else
    {
        *NegRes = DCM_E_REQUESTOUTOFRANGE;
        ret_val = DCM_E_NOT_OK;
    }
    return ret_val;
}
#endif

#if((DCM_SVC_19_SUPPORT_ENABLED == STD_ON) && (DCM_SVC_19_14_SUPPORT_ENABLED == STD_ON))
/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiReportDtcByFdc(uint8 dsfClass,Dcm_Svc19DemSetFilterMaskUsageType maskUsage,Dcm_MsgContextType *pMsgContext)
 Description         : Report number of DTC by status mask.
 Parameters (in)     : uint8 dsfClass,Dcm_Svc19DemSetFilterMaskUsageType maskUsage,Dcm_MsgContextType *pMsgContext.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiReportDtcByFdc(uint8 dsfClass, Dcm_Svc19DemSetFilterMaskUsageType maskUsage,
        Dcm_MsgContextType *pMsgContext,
        Dcm_NegativeResponseCodeType *NegRes)
{
    Std_ReturnType ret_val = DCM_E_NOT_OK;
    uint8 dtcStatusMask = 0x00u;
    uint16 NumOfDtc = 0U;
    Dem_ReturnSetFilterType demResultSetFilter = DEM_WRONG_FILTER;

    DCM_IGNORE_UNREF_PARAM(maskUsage);

    /* Coverity fix - CID 12247065 (#2 of 2): Potential Array Indexed Problem (POTENTIAL_OVERRUN)
     potential_overrun: Index dsfClass may be outside the bounds of Dcm_Svc19DemDtcFilterInfo.*/
    if(dsfClass < DEM_SETFILTER_NUM_CLASSES)
    {
    demResultSetFilter = Dem_SetDTCFilter (pMsgContext->DemClientId, dtcStatusMask, 
                             DEM_DTC_FORMAT_UDS,
                             Dcm_Svc19DemDtcFilterInfo[dsfClass].Origin,
                             DEM_FILTER_WITH_SEVERITY_NO,
                             0, /* parameter not used */
                             DEM_FILTER_FOR_FDC_YES);
    }

    *NegRes = DCM_E_REQUESTOUTOFRANGE;
    if(demResultSetFilter == DEM_FILTER_ACCEPTED)
    {
        ret_val = Dem_GetNumberOfFilteredDTC (pMsgContext->DemClientId, (uint16*) &NumOfDtc);
        if(ret_val == DCM_E_OK)
        {
            ret_val = Dcm_DspSvc19UtiDemGetNxtFltrdDtc (pMsgContext, DEM_FILTER_FOR_FDC_YES, DEM_FILTER_WITH_SEVERITY_NO);
        }
    }
    return ret_val;
}
#endif

#if(DCM_SVC_19_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiDemGetNxtFltrdDtc(Dcm_MsgContextType *pMsgContext)
 Description         : Copy the filtered data.
 Parameters (in)     : Dcm_MsgContextType *pMsgContext.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiDemGetNxtFltrdDtc(Dcm_MsgContextType *pMsgContext, Dcm_BooleanType flFilterForFDC, Dcm_BooleanType flFilterForSeverity)
{
    Std_ReturnType ret_val = 0u;

    ret_val = Dcm_DspSvc19UtiCpyLinearData (pMsgContext, flFilterForFDC, flFilterForSeverity);
    return ret_val;
}

/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiCpyLinearData(Dcm_MsgContextType *pMsgContext)
 Description         : Copy the linear data.
 Parameters (in)     : Dcm_MsgContextType *pMsgContext.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiCpyLinearData(Dcm_MsgContextType *pMsgContext, Dcm_BooleanType flFilterForFDC, Dcm_BooleanType flFilterForSeverity)
{
    Std_ReturnType lStdResult = 0u;
    Dcm_MsgLenType remainingData = (Dcm_MsgLenType) pMsgContext->resMaxDataLen;
    Dcm_DemClientIdType DcmDemClientId = pMsgContext->DemClientId;
    if (flFilterForSeverity == DEM_FILTER_WITH_SEVERITY_YES)
    {
        lStdResult = Dcm_DspSvc19UtiCpyDemGetNxtSeverityFltrdDtc (DcmDemClientId, pMsgContext->resData, &remainingData, flFilterForFDC, flFilterForSeverity);
    }
    else
    {
        lStdResult = Dcm_DspSvc19UtiCpyDemGetNxtFltrdDtc (DcmDemClientId, pMsgContext->resData, &remainingData, flFilterForFDC); /* commit copied data */
    }

    /* CERT C fix 17224196 */
    if(pMsgContext->resMaxDataLen >= remainingData)
    {
        remainingData = (Dcm_MsgLenType) (pMsgContext->resMaxDataLen - remainingData);
    }
    else
    {
        /*Handle with Error */
    }
    pMsgContext->resDataLen = remainingData; /* PRQA S 3109 *//* MD_MSR_14.3 */
    return lStdResult;
}

/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtFltrdDtc(Dcm_DemClientIdType DcmDemClientId,Dcm_MsgType pData,Dcm_MsgLenType* pAvailLen)
 Description         : get next filtered data.
 Parameters (in)     : Dcm_MsgType pData,Dcm_MsgLenType* pAvailLen.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtFltrdDtc(Dcm_DemClientIdType DcmDemClientId, Dcm_MsgType pData, Dcm_MsgLenType *pAvailLen,
        Dcm_BooleanType flFilterForFDC)
{
    uint32 lDtc = 0U;
    uint32 lAvailLen = *pAvailLen;
    uint8 dtcStatus = 0U;
    sint8 flFdcCounter = 0;
    Std_ReturnType lStdResult = DCM_E_BUFFERTOOLOW;

    while (lAvailLen >= DCM_DSP_0x04u)
    {
        if(DEM_FILTER_FOR_FDC_YES != flFilterForFDC)
        {
            lStdResult = Dem_GetNextFilteredDTC (DcmDemClientId, &lDtc, &dtcStatus);
        }
        else
        {
            lStdResult = Dem_GetNextFilteredDTCAndFDC (DcmDemClientId, &lDtc, &flFdcCounter);
        }
        if(lStdResult == DCM_DEM_RET_FILTERED_OK)
        {
            pData[0] = (uint8) (lDtc >> DCM_DSP_16U);
            pData[DCM_DSP_0x01u] = (uint8) (lDtc >> DCM_DSP_0x08U);
            pData[DCM_DSP_0x02u] = (uint8) (lDtc);
            if(DEM_FILTER_FOR_FDC_YES != flFilterForFDC)
            {
                pData[DCM_DSP_0x03u] = dtcStatus;
                /* commit data */
                pData = &(pData)[DCM_DSP_0x04u];
                lAvailLen -= DCM_DSP_0x04u;
            }
            else
            {
                if((flFdcCounter > 0) && (flFdcCounter < DCM_DSP_127U))
                {
                    pData[DCM_DSP_0x03u] = flFdcCounter;
                    /* commit data */
                    pData = &(pData)[DCM_DSP_0x04u];
                    lAvailLen -= DCM_DSP_0x04u;
                }
            }
        }
        else
        {
            lStdResult = E_OK;
            break;
        }
    }

    *pAvailLen = (uint16) lAvailLen; /* commit all copied data */
    return lStdResult; /*lint !e438 pData is always post incremented */
} /* PRQA S 6080 *//* MD_MSR_STMIF */

/**************************************************************************
 Function name       : static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtFltrdDtc(Dcm_DemClientIdType DcmDemClientId,Dcm_MsgType pData,Dcm_MsgLenType* pAvailLen)
 Description         : get next filtered data.
 Parameters (in)     : Dcm_MsgType pData,Dcm_MsgLenType* pAvailLen.
 Parameters (out)    : none
 Return value        : Std_ReturnType
 Design Information  :
 **************************************************************************/
static Std_ReturnType Dcm_DspSvc19UtiCpyDemGetNxtSeverityFltrdDtc(Dcm_DemClientIdType DcmDemClientId, Dcm_MsgType pData, Dcm_MsgLenType *pAvailLen,
        Dcm_BooleanType flFilterForFDC, Dcm_BooleanType flFilterForSeverity)
{
    uint32 lDtc = 0U;
    uint32 lAvailLen = *pAvailLen;
    uint8 dtcStatus = 0U;
    uint8 dtcSeverity = 0U;
    uint8 dTCFunctionalUnit = 0U;
    Std_ReturnType lStdResult = DCM_E_BUFFERTOOLOW;

    DCM_IGNORE_UNREF_PARAM(flFilterForFDC);


    while (lAvailLen >= DCM_DSP_0x06u)
    {
        if (DEM_FILTER_WITH_SEVERITY_YES == flFilterForSeverity)
        {
      		lStdResult = Dem_GetNextFilteredDTCAndSeverity (DcmDemClientId, &lDtc, &dtcStatus, &dtcSeverity, &dTCFunctionalUnit);
            if(lStdResult == DEM_FILTERED_OK)
            {
                if(NULL != pData)
                {
                    pData[0] = dtcSeverity;
                    pData[DCM_DSP_0x01u] = dTCFunctionalUnit;
                    pData[DCM_DSP_0x02u] = (uint8) (lDtc >> DCM_DSP_16U);
                    pData[DCM_DSP_0x03u] = (uint8) (lDtc >> DCM_DSP_0x08U);
                    pData[DCM_DSP_0x04u] = (uint8) (lDtc);
                    pData[DCM_DSP_0x05U] = dtcStatus;
                    /* commit data */
                    pData = &(pData)[DCM_DSP_0x06u];
                    lAvailLen -= DCM_DSP_0x06u;
                }
                else
                {
                    lStdResult = DCM_E_BUFFERTOOLOW;
                    break;
                }
            }
            else
            {
                lStdResult = E_OK;
                break;
            }
        }
        else
        {
            lStdResult = DCM_E_BUFFERTOOLOW;
            break;
        }
    }
    *pAvailLen = (uint16) lAvailLen; /* commit all copied data */
    return lStdResult; /*lint !e438 pData is always post incremented */
} /* PRQA S 6080 *//* MD_MSR_STMIF */
#endif

#if(DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
/**************************************************************************
 Function name       : static Dcm_NegativeResponseCodeType Dcm_27Service_key_Process(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, const uint8 Counter)
 Description         :
 Parameters (in)     : Dcm_MsgContextType *pMsgContext, uint8 Counter
 Parameters (out)    : Dcm_MsgContextType *pMsgContext
 Return value        : Dcm_NegativeResponseCodeType
 Design Information  :
 **************************************************************************/
static Dcm_NegativeResponseCodeType Dcm_27Service_key_Process(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, uint8 SubFunction, const uint8 Counter)
{
    Dcm_NegativeResponseCodeType NegRes = DCM_E_GENERALREJECT;
    Std_ReturnType RetVal = DCM_E_NOT_OK;
    uint8 flRequestedLevel = 0u;
    uint8 index = 0U;
	Dcm_SesCtrlType flSession = 0u;
    #if(S27_STATIC_SEED_SUPPORTED == TRUE)
    uint8 indexBuffer = 0U;
    #endif

    /* CERT C fix 17225716 */
    if(Counter < DCM_DSP_255U)
    {
        flRequestedLevel = (Counter + DCM_DSP_0x01u) / DCM_DSP_0x02u;
    }
    else
    {
        flRequestedLevel = 0u;
    }

    if((flRequestedLevel > 0u) && ((flRequestedLevel-DCM_DSP_0x01u) < No_of_security_level) && (Counter < (No_of_security_level*DCM_DSP_0x02u)))
    {
        NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        if(Dcm_DsdSubService27[Counter].Req_Length == pMsgContext->reqDataLen)
        {
            if(Request_seed_rcvd[flRequestedLevel - DCM_DSP_0x01u] == DCM_FALSE)
            {
                NegRes = DCM_E_REQUESTSEQUENCEERROR;
            }
            else
            {
                pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x02u];
                (void)Dcm_GetSesCtrlType(&flSession);
                NegRes = DCM_E_INVALIDKEY;
                if(NULL != Dcm_DsdSubService27[Counter].SubServiceFnc)
                {
                    RetVal = Dcm_DsdSubService27[Counter].SubServiceFnc(OpStatus, pMsgContext->resData, SubFunction, &NegRes, flSession);
                    pMsgContext->resDataLen = 0u;
                }
                if(RetVal == DCM_E_OK)
                {
                    NegRes = DCM_E_POSITIVERESPONSE;
                    DslInternal_SetSecurityLevel (flRequestedLevel);
                    #if(S27_DELAY_SUPPORTED == TRUE)
                    S27_fail_counter = 0U;
                    S27_retry_delay = 0U;
                    #if(S27_FAIL_COUNT_NVM_SUPPORTED == TRUE)
                    (void)SaveFailCounter(&S27_fail_counter);
                    #endif
                    #endif /* (S27_DELAY_SUPPORTED == TRUE) */
                    #if(S27_STATIC_SEED_SUPPORTED == TRUE)
                    for (indexBuffer = 0u; indexBuffer < S27_STATIC_SEED_BUFFER_SIZE; indexBuffer++)
                    {
                        S27_SeedBuffer[indexBuffer] = 0u;
                    }
                    #endif
                }
                else if(RetVal == DCM_E_NOT_OK)
                {
                    switch(NegRes)
                    {
                        case DCM_E_CONDITIONSNOTCORRECT:
                        break;

                        default:
                        #if(S27_DELAY_SUPPORTED == TRUE)
                        if (S27_fail_counter > S27_FAIL_COUNT)
                        {
                            NegRes = DCM_E_EXCEEDNUMBEROFATTEMPTS;
                            S27_retry_delay = S27_FAIL_COUNT_TIME_MS / DCM_TASK_PERIODICITY;
                            /* start counter for exceededNumberOfAttempts */
                        }
                        else if(S27_fail_counter <= S27_FAIL_COUNT)
                        {
                            S27_fail_counter += DCM_DSP_0x01u;
                            #if(S27_FAIL_COUNT_NVM_SUPPORTED == TRUE)
                            (void)SaveFailCounter(&S27_fail_counter);
                            #endif
                        }
                        else
                        {
                            /*do nothing*/
                        }
                        #endif /* (S27_DELAY_SUPPORTED == TRUE) */
                        break;
                    }
				}
                else
                {

                    // do nothing
                }
            }
        }
        /* Reset the Seed received for all levels  */
        if(RetVal != DCM_E_PENDING)
        {
            for(index = 0; index < No_of_security_level; index++)
            {
                Request_seed_rcvd[index] = 0U;
            }
        }
	}
    return (NegRes);
}

/**************************************************************************
 Function name       : static Dcm_NegativeResponseCodeType Dcm_27Service_seed_Process(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, const uint8 Counter)
 Description         :
 Parameters (in)     : Dcm_MsgContextType *pMsgContext, uint8 Counter
 Parameters (out)    : Dcm_MsgContextType *pMsgContext
 Return value        : Dcm_NegativeResponseCodeType
 Design Information  :
 **************************************************************************/
static Dcm_NegativeResponseCodeType Dcm_27Service_seed_Process(Dcm_OpStatusType OpStatus, Dcm_MsgContextType *pMsgContext, uint8 SubFunction, const uint8 Counter)
{
    SubService27 FncPtr ;
    Dcm_NegativeResponseCodeType NegRes = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    Std_ReturnType RetVal = DCM_E_NOT_OK;
	Dcm_SesCtrlType flSession = 0u;
    Dcm_SecLevelType fl_Security = 0u;
    uint16 flRespIndex = 0U;
    #if(S27_DELAY_SUPPORTED == TRUE)
    Dcm_BooleanType Dcm_Timer_Elapsed_Status = DCM_TRUE;
    #endif
    #if(S27_STATIC_SEED_SUPPORTED == TRUE)
    uint16 indexBuffer = 0u;
    #endif
    uint8 index = 0u;
    uint8 flRequestedLevel = 0u;

    if(NULL != pMsgContext)
    {
        flRequestedLevel = (Counter / 2) + 1;
        if(flRequestedLevel > 0u)
        {
          Request_seed_rcvd[flRequestedLevel -1] = 0u;
        } 
        if((Counter < (No_of_security_level*DCM_DSP_0x02u)) && (Dcm_DsdSubService27[Counter].Req_Length == pMsgContext->reqDataLen))
        {
            NegRes = DCM_E_POSITIVERESPONSE;
            #if(S27_DELAY_SUPPORTED == TRUE)
            #if(S27_RESET_DELAY_SUPPORTED == TRUE)
            if (0u != S27_reset_delay)
            {
                Dcm_Timer_Elapsed_Status = DCM_FALSE;
            }
            #endif
            if (S27_fail_counter > S27_FAIL_COUNT)
            {
                if (0u != S27_retry_delay)
                {
                    Dcm_Timer_Elapsed_Status = DCM_FALSE;
                }
				else
                {
                S27_fail_counter -= S27_REATTEMPT_COUNT;
                }
            }
            if (Dcm_Timer_Elapsed_Status == DCM_FALSE)
            {
                #if(S27_RESET_DELAY_SUPPORTED == TRUE)
                S27_reset_delay = S27_RSTDELAY_TIME_MS / DCM_TASK_PERIODICITY;
                #endif
                NegRes = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
            }
            else
            {
                #if(S27_RESET_DELAY_SUPPORTED == TRUE)
                if (0u != S27_reset_delay)
                {
                    S27_reset_delay = 0U;
                }
                #endif
            }
            if (NegRes == DCM_E_POSITIVERESPONSE)
            #endif /* (S27_DELAY_SUPPORTED == TRUE) */
            {
                flRequestedLevel = (Counter / DCM_DSP_0x02u) + DCM_DSP_0x01u;
                (void) Dcm_GetSecurityLevel (&fl_Security);
                if(fl_Security == flRequestedLevel)
                {
                    pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x02u];
                    for(flRespIndex = 0; flRespIndex < Dcm_DsdSubService27[Counter].Resp_Length; flRespIndex++)
                    {
                        pMsgContext->resData[flRespIndex] = 0u;
                    }
                    pMsgContext->resDataLen = Dcm_DsdSubService27[Counter].Resp_Length;
                    }
                else
                {
                    #if(S27_STATIC_SEED_SUPPORTED == TRUE)
                    if((Request_seed_rcvd[flRequestedLevel - DCM_DSP_0x01u] == DCM_FALSE) && (S27_SeedBuffer[0] == 0x0u))
                    {
                    #endif
                        /* Reset the Seed received for all levels  */
                        for(index = 0; index < No_of_security_level; index++)
                        {                            
                            Request_seed_rcvd[index] = 0u;
                        }
                        /* Set the seed received only for current level */
                        /* CERT C 17224226 */
                        if(flRequestedLevel > 0u)
                        {
                            Request_seed_rcvd[flRequestedLevel - DCM_DSP_0x01u] = DCM_TRUE;
                        }
                        else
                        {
                            /*Handle with Error*/
                        }
						(void)Dcm_GetSesCtrlType(&flSession);
                        pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x02u];
                        FncPtr = Dcm_DsdSubService27[Counter].SubServiceFnc;
                        if(NULL != FncPtr)
                        {
                            RetVal = FncPtr(OpStatus, pMsgContext->resData, SubFunction, &NegRes, flSession);
                        }
                        if(RetVal == DCM_E_OK)
                        {
                            pMsgContext->resDataLen = Dcm_DsdSubService27[Counter].Resp_Length;
                        }
                    #if(S27_STATIC_SEED_SUPPORTED == TRUE)
                        if(NULL != pMsgContext->resData)
                        {
                            for (indexBuffer = 0u; indexBuffer < Dcm_DsdSubService27[Counter].Resp_Length; indexBuffer++)
                            {
                                S27_SeedBuffer[indexBuffer] = pMsgContext->resData[indexBuffer];
                            }
                        }
                        else
                        {
                            NegRes = DCM_E_GENERALREJECT;
                        }
                    }
                    else
                    {
                        pMsgContext->resData = &pMsgContext->resData[DCM_DSP_0x02u];
                        pMsgContext->resDataLen = Dcm_DsdSubService27[Counter].Resp_Length;
                        /* Set the seed received only for current level */
                        Request_seed_rcvd[flRequestedLevel - DCM_DSP_0x01u] = DCM_TRUE;
                        if(NULL != pMsgContext->resData)
                        {
                            for (indexBuffer = 0u; indexBuffer < Dcm_DsdSubService27[Counter].Resp_Length; indexBuffer++)
                            {
                                pMsgContext->resData[indexBuffer] = S27_SeedBuffer[indexBuffer];
                            }
                        }
                        else
                        {
                            NegRes = DCM_E_GENERALREJECT;
                        }
                    }
                    #endif
                }
            }
        }
    }
    return (NegRes);
}
#endif

#define DIAGMGR_CODE_SEC_END
#include "MemMap.h"

#endif /* DCM_DSP_C*/

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
/*Date              : 17-Jun-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Data design And Framework implemented, Initial Version*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-Sep-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 10,11,22 implementation						            */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Oct-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 2E,2F,31 implementation						            */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-Oct-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 3E,27 implementation						              */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-Nov-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 746031,RTC 746018                                 */
/*Change Description: service 28 and 27 timing implementation			          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Dec-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Session & Security state checking logic changes for   */
/*			  DID which supporting multiple operations. (Read | Write | IO) */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 20-Jan-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 765864,765855,765852.                             */
/*Change Description: Service 0x14,0x85 and sercice 19 with subfunction 0x01*/
/*                    0x02 and 0x0A Implementation.                         */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-March-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 822374                                           */
/*Change Description: Coverity issue fixes                                  */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-March-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 830120                                           */
/*Change Description: Control DTC setting is enabled on transition to       */
/*					  default session.   	                                          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-March-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 828126                                           */
/*Change Description: Service 27 request positive response at reset is 	    */
/*						changed from 10 second to 8 second                            */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 3-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 838240                                            */
/*Change Description: Fixed the compiler warnings.                          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 5-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 833391                                            */
/*Change Description: NRC priority issue on multiple NRC is fixed           */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 7-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 842239                                            */
/*Change Description: Pr review comment fixed                               */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-April-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 841275                                            */
/*Change Description: NRC updated for session not supportted in subfunction */
/*                    and DID or RID level.                                 */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 20-April-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 847171                                            */
/*Change Description: Test code update for DTC addition                     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc#                                                  */
/*Change Description: QAC warning fixes                                     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 05-Nov-2019                                           */
/*Version           :                                                       */
/*By                : snaray12                                              */
/*Traceability      : Rtc#639145                                            */
/*Change Description: MISRA warning fixes                                   */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-Nov-2019                                           */
/*Version           :                                                       */
/*By                : snaray12                                              */
/*Traceability      : Rtc#639145                                            */
/*Change Description: MISRA warning fixes                                   */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 27-Nov-2019                                           */
/*Version           :                                                       */
/*By                : snaray12                                              */
/*Traceability      : Rtc#639145                                            */
/*Change Description: PR defects fixed for MISRA                            */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 05-Feb-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Rtc#735134                                            */
/*Change Description: 0x19-0x14 service issue fix and design changes        */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 14-Mar-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : 794563: Multi DID support for 0x22 service Multi      */
/*                    channel support                                       */
/*Change Description: Multi Read DID support and design optimization        */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 20-Mar-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :i) 818177: Reception Diagnostic Tool Connection Not    */
/*                    Established in TuringC stream                         */
/*                    channel support                                       */
/*                   ii) 818468: [Diagnostic][A12]28 service NRC is wrong   */
/*                   iii) 817372 :- Service 0x86 basic frame Work           */
/*Change Description: Multi Read DID support and design optimization        */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 31-Mar-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Dcm migration to Bookshelf - support (830050)         */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Apr-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Service 0x23 & 0x3D implementation                    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 29-Aug-2020                                           */
/*Version           :                                                       */
/*By                : bbaskara                                              */
/*Traceability      : Rtc#1029668                                           */
/*Change Description: 0x19 0x06 service design changes                      */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 19-Sep-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Rtc#1046434                                           */
/*Change Description: 0x19 0x04 service design changes and defect fixes     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Nov-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : 1126336: [vAutosar] Dcm - Quality                     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 24-Jan-2021                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : 1183724:                                              */
/* unauthorized access more than once, NRC respond error                    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 25-Feb-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      :                                                       */
/*Change Description: Implement 0x87 and 0x27 services                      */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Jun-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1376136                                           */
/*Change Description: Implement service preconditions                       */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 20-Jul-2021                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1408913                                           */
/*Change Description: Wrong NAK In case of Diagnostic Buffer overflow       */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-Jan-2022                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1560389                                           */
/*Change Description: DCM and DEM Autosar 4.2.2 Migration                   */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 06-Jul-2022                                           */
/*Version           :                                                       */
/*By                : dbalasub                                              */
/*Traceability      : Rtc#1706585                                           */
/*Change Description: Audit fix                                             */
/*--------------------------------------------------------------------------*/

