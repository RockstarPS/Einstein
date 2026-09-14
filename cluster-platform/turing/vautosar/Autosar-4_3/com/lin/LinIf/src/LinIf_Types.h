/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
* File Name         :  LinIf_Types                                           *
* Module Short Name :  LinIf                                                 *
* Description       :  Header file for LinIf component                       *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Turing A                                               *
*                                                                            *
*****************************************************************************/
#ifndef LINIF_TYPES_H
#define LINIF_TYPES_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "Std_Types.h"
#include "LinIf_Cfg.h"
#include "ComStack_Types.h"


/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/



/**
  * @brief This macro defines Lin TPU Pdu Size.
  * unit : N/A
  * Resolution: N/A
  * Range: 0 to 65535
  * Applicablity: N/A
  */
# define LINIF_LINPDU_SIZE                          (8u)


/**
  * @brief This macro defines Wake up flag as set.
  * unit : N/A
  * Resolution: N/A
  * Range: 0 to 1
  * Applicablity: N/A
  */
#define LINIF_WAKEUP_OCCURRED    (uint8)0x01

/**
  * @brief This macro defines Wake up flag as not set.
  * unit : N/A
  * Resolution: N/A
  * Range: 0 to 1
  * Applicablity: N/A
  */
#define LINIF_WAKEUP_NOT_OCCURRED    (uint8)0x00

/**
  * @brief This macro defines no error constant value 
  * unit : N/A
  * Resolution: N/A
  * Range: 0 
  * Applicablity: N/A
  */
#define LINIF_E_NO_ERROR   (uint8)0x00


/**
  * @brief This macro defines  error constant value 
  * unit : N/A
  * Resolution: N/A
  * Range:  1
  * Applicablity: N/A
  */
#define LINIF_E_ERROR   (uint8)0x01


/**
  * @brief This macro defines  the null schedule  value 
  * unit : N/A
  * Resolution: N/A
  * Range:  0
  * Applicablity: N/A
  */
#define NULL_SCHEDULE                        ((LinIf_SchHandleType)0x00u)


/**
  * @brief This macro defines Lininterface set   value 
  * unit : N/A
  * Resolution: N/A
  * Range:  1
  * Applicablity: N/A
  */
#define LINIF_SET              (uint8)0x01   


/**
  * @brief This macro defines Lininterface Clear value 
  * unit : N/A
  * Resolution: N/A
  * Range:  0
  * Applicablity: N/A
  */
#define LINIF_CLEAR              (uint8)0x00

/*Description: Upper layer modules for Notification*/
typedef enum
{
    CDD,
    LIN_SM
} LinIfConfirmationULtype;

/*
Description: Lin Frame Checksum .
*/
typedef enum
{
    LINIF_ENHANCED,
    LINIF_CLASSIC
} LinIf_ChecksumType;

/*
Description: Types of LIN Frames Supported
*/
typedef enum
{
    ASSIGN,
    ASSIGN_NAD,
    CONDITIONAL,
    EVENT_TRIGGERED,
    FREE,
    MRF,
    SPORADIC,
    SRF,
    UNASSIGN,
    UNCONDITIONAL
} LinIf_FrameTypeType;

/* Direction of a Lin PDU */
typedef enum
{
    LinIfInternalPdu,
    LinIfRxPdu,
    LinIfSlaveToSlavePdu,
    LinIfTxPdu
} LinIf_PduDirectionType;

typedef enum
{
    LINIF_UNINIT,
    LINIF_INITIALIZATION,
    LINIF_CHANNEL_UNINIT,
    LINIF_CHANNEL_OPERATIONAL,
    LINIF_CHANNEL_SLEEP_TRANS,
    LINIF_CHANNEL_SLEEP,
} LinIf_StatusType;

/* Resuming modes of schedule table after having been
 * interrupted by another RUN_ONCE schedule table */
typedef enum
{
    CONTINUE_AT_IT_POINT,
    START_FROM_BEGINNING
} LinIf_ResumePositionType;

/* Run modes of a schedule table */
typedef enum
{
    RUN_CONTINUOUS,
    RUN_ONCE
} LinIfRunModeType;

/* Lin frame */
typedef struct
{
    LinIf_ChecksumType LinIfChecksumType;
    LinIf_FrameTypeType LinIfFrameType;
    uint8 LinIfLength;
    uint8 LinIfPid;
    PduIdType LinIfTxTargetPduId;
    uint8 *LinIfFixedFrameSdu;
    LinIf_PduDirectionType LinIfPduDirection;
} LinIf_FrameType;

/* Master node type */
typedef struct
{
    uint32 LinIfJitter;
} LinIf_MasterType;

/* Slave node type */
typedef struct
{
    uint32 LinIfConfiguredNad;
    uint32 LinIfFunctionId;
    char *LinIfProtocolVersion;
    uint32 LinIfResponseErrorBitPos;
    uint32 LinIfSupplierId;
    uint32 LinIfVariant;
    uint32 LinIfResponseErrorEventRef;
    uint16 LinIfResponseErrorFrameRef;
} LinIf_SlaveType;

/* Entry type */
typedef struct
{
    uint16 LinIfDelay;
    uint16 LinIfEntryIndex;
    uint16 LinIfCollisionResolvingRef;
    LinIf_FrameType* LinIfFrameRef; /* Index in the LinIfFrameCfg array */
} LinIfEntryType;

/* Lin schedule table */
typedef struct
{
    LinIf_ResumePositionType LinIfResumePosition;
    LinIfRunModeType LinIfRunMode;
    char *LinIfScheduleTableName;
    const LinIfEntryType *LinIfEntry;
    uint16 LinIfNofEntries;
} LinIf_ScheduleTableType;

/*Define lin interface wakeup source data type*/
typedef uint8 LinIf_WakeUpSourceType;



/* General settings as structure. */
typedef struct
{
    /* Switches the Development Error Detection and Notification ON or OFF. */
    boolean LinIfDevErrorDetect;

    /* States if multiple drivers are included in the LIN Interface or not.
     * The reason for this parameter is to reduce the size of LIN Interface if
     * multiple drivers are not used. */
    boolean LinIfMultipleDriversSupported;
    
    /*States if transceiver driver support is included in the LIN Interface or not.
     The reason for this parameter is to reduce the size of LIN Interface if transceiver drivers are not used.*/
    boolean LinIfTrcvDriverSupported;

    /* States if the node configuration commands Assign NAD and Conditional
     * Change NAD are supported. */

    boolean LinIfNcOptionalRequestSupported; 

    /*States if multiple transceiver drivers are supported by the LIN Interface or not.
     The reason for this parameter is to reduce the size of LIN Interface if multiple transceiver drivers are not used..*/
    boolean LinIfMultipleTrcvDriverSupported;

    /*Global Pre-Compile Switch to enable/disable the APIs LinIf_CancelTransmit/LinTp_CancelReceive.*/
    boolean LinIfCancelTransmitSupported;

    /* States if the TP is included in the LIN Interface or not. The reason for
     * this parameter is to reduce the size of LIN Interface if the TP is not
     * used. */

    boolean LinIfTpSupported;
    /* Switches the LinIf_GetVersionInfo function ON or OFF. */
    boolean LinIfVersionInfoApi;
} LinIf_GeneralType;

/*Define Schedule handle data type*/
typedef uint8 LinIf_SchHandleType;

/* Lin channel */
typedef struct
{
    /* Internal ID for the channel on LIN Interface level. This parameter shall
     * map the NetworkHandleType to the physical LIN channel.
     * Implementation Type: NetworkHandleType */
    uint8 LinIfChannelId;
    /* Generic container for all types of LIN frames. */
    const LinIf_FrameType *LinIfFrame;
    /* Each Master can only be connected to one physical channel.
     * This could be compared to the Node parameter in a LDF file. */
    LinIf_MasterType LinIfMaster;
    /* Describes a schedule table. Each LinIfChannel may have several schedule tables.
     * Each schedule table can only be connected to one channel. */
    const LinIf_ScheduleTableType *LinIfScheduleTable;
    /* The Node attributes of the Slaves are provided with these parameter. */
    const LinIf_SlaveType *LinIfSlave;
    /* This container contains the configuration (parameters) needed
    to configure a wakeup capable channel */
    const LinIf_WakeUpSourceType *LinIfWakeUpSource;
    /* Startup state */
    LinIf_StatusType LinIfStartupState;
} LinIf_ChannelType;

/* Global configuration */
typedef struct
{
    /*Defines the interval of calls to main functions in seconds.*/
    uint16 LinIfTimeBase;

    /*Describes each LIN channel the LinIf is connected to.*/
    const LinIf_ChannelType *LinIfChannel;

    /* Lin Frame list to coresponding linif channel */
    const LinIf_FrameType *LinIfFrameConfig;
    
    /*This parameter defines the upper layer (UL) module to which the confirmation 
    of the goto-sleep command shall be sent.*/
    LinIfConfirmationULtype LinIfGotoSleepConfirmationUL;

    /*This parameter defines the upper layer (UL) module to which the confirmation of the successfully performed 
    schedule table change shall be sent.*/
    LinIfConfirmationULtype LinIfScheduleRequestConfirmationUL;

    /*This parameter defines the upper layer (UL) module to which the confirmation of the wake-up shall be sent.*/
    LinIfConfirmationULtype LinIfWakeupConfirmationUL;
    
} LinIf_ConfigType;

/* Lin configuration */
typedef struct
{
    const LinIf_GeneralType *LinIfGeneral;
    const LinIf_ConfigType *LinIfGlobalConfig;
} LinIf_Type;


typedef struct 
{
    /* Individual Status of Each Channels */
    LinIf_StatusType Channel_Status; 
    /* Current Ticks executed data of each Channel  */
    uint16 Current_DelayInTicks; 
    /* Current Schedule table which in execution */
    LinIf_ScheduleTableType *Current_ScheduleTable_InExecution; 
    /* Previous Schedule table which in execution */  
    LinIf_ScheduleTableType *Previous_ScheduleTable_InExecution;  
     /* New Schedule Requested Flag */ 
    boolean IsNewScheduleRequestReceived;      
     /* New table to be changed */
    LinIf_SchHandleType New_ScheduleRequest;   
    /* Flag to indicate Sleep Requests Status */
    boolean SleepRequestStatus;  
    /*Flag to indicate Wake Up request received during Sleep Transistions  */
    boolean NewWakeUpRequestReceived; 
    /* Current index of the Schedule Table */ 
    uint16 CurrentScheduleTableIndex; 
    /* Current index of the Schedule Table */
    uint16 Previous_ScheduleTableIndex;     
    /*Collison Schedule request status*/
    uint8 New_CollisonScheduleRequest_Status;  
    /*Lin interface wakeup flag*/
    uint8  LinIf_WakeupFlag; 
      /*Lin interface Tx Data*/
    uint8  LinIf_TxData[LINIF_LINPDU_SIZE];
     /*Lin interface Rx Data*/
    uint8  LinIf_RxData[LINIF_LINPDU_SIZE]; 
     
}LinIf_ChannelDataType;


/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================

**============================================================================
**Date               : 10-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description :  Update Channel data type for collison schedule table, Tx ,Rx data
                        and constant Macro
**============================================================================
**============================================================================
**Date               : 10-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description :  Update Wake up Flag macro and defines upper layer module for notification 
                        against Wake and Sleep Request.
**============================================================================
**============================================================================
**Date               : 26-JULY-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296     
**Change Description : Initial Version
**============================================================================*/
#endif // LINIF_TYPES_H
