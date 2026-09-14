/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file Xcp_Cfg.h
*    @ingroup XcpConfiguration
*    @brief This is Xcp Pre-compile time configuration header file. It contains definitions of pre-compile time 
*    configuration parameters for the Xcp module.
*    @defgroup XcpConfiguration
*    @brief This contains the configuration files for the Xcp module.
********************************************************************************************************************/
#ifndef XCP_CFG_H
#define XCP_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Xcp_Types.h"
#include "SchM_Xcp.h"
/********************************************************************************************************************
*  #! Precompile Configuration                                                                                      *
********************************************************************************************************************/
/*! @brief  Switches the development error detection and notification on or off.
    STD_ON  : detection and notification is enabled.
    STD_OFF : detection and notification is disabled. */
#define XCP_DEV_ERROR_DETECT                STD_ON
/*! @brief Defines the Xcp version info api support */
#define XCP_VERSION_INFO_API                STD_OFF
/*! @brief Sets the DAQ_CONFIG_TYPE bit within the DAQ_PROPERTIES parameter to "static" or to "dynamic". If 
    DAQ_STATIC is selected, the DAQ_CONFIG_TYPE bit is set to "0". If DAQ_DYNAMIC is selected,
    the DAQ_CONFIG_TYPE bit is set to "1".*/
#define XCP_DAQ_CONFIG_TYPE                 DAQ_DYNAMIC
/*! @brief Enable/Disable of XCP Flash programming functionality */
#define XCP_FLASH_PROGRAMMING_ENABLED       STD_OFF
/*! @brief Type of Identification Field the slave will use when transferring DAQ Packets to the master. 
    The master has to use the same Type of Identification Field when transferring STIM Packets to the slave.*/
#define XCP_IDENTIFICATION_FIELD_TYPE       ABSOLUTE
/*! @brief This parameter enables and disables the support for Prescaler support. True is Enabled, False is disabled */
#define XCP_PRESCALAR_SUPPORTED             STD_ON 
/*! @brief Switches the support of suppressing transmission of PDUs per communication channel on or off.
    TRUE: Suppressing of TxPDUs supported FALSE: Suppressing of TxPDUs not supported */
#define XCP_SUPPRESS_TX_SUPPORT             STD_ON 
/*! @brief Defines the bit mask for DAQ Timestamp size   */
#define XCP_DAQ_TIMESTAMP_SIZE              XCP_DAQ_TIMESTAMP_BYTE
/*! @brief Defines the Timestamp unit configured */
#define XCP_DAQ_TIMESTAMP_UNIT              XCP_DAQ_TIMESTAMP_UNIT_1MS
/*! @brief Defines the main function period in milliseconds */
#define XCP_MAIN_FUNCTION_PERIOD            10U  
/*! @brief Indicates the number of DAQ lists for dynamic configuration. */
#define XCP_DAQ_COUNT                       8u
/*! @brief MAX_CTO shows the maximum length of a CTO packet in bytes. */
#define XCP_MAX_CTO                         255U 
/*! @brief MAX_DTO shows the maximum length of a DTO packet in bytes.*/
#define XCP_MAX_DTO                         255U 
/*! @brief MAX_DTO shows the maximum number of event channel to be configured .*/
#define XCP_MAX_EVENT_CHANNEL               2U
/*! @brief Indicates the number of predefined, read only DAQ lists on the XCP slave. */
#define XCP_MIN_DAQ                         1U
/*! @brief This parameter indicates the amount of ODTs of a DAQ list using dynamic DAQ list configuration. */
#define XCP_ODT_COUNT                       10U
/*! @brief Indicates the amount of entries into an ODT using dynamic DAQ list configuration. */
#define XCP_ODT_ENTRIES_COUNT               2U
/*! @brief Indicates the size of an element described by an ODT entry to the DaqListType for a DAQ. */
#define XCP_ODT_ENTRY_SIZE_DAQ              1U
/*! @brief Indicates the size of an element described by an ODT entry to the DaqListType for a stim. */
#define XCP_ODT_ENTRY_SIZE_STIM             1U 
/*! @brief Defines the timestamp ticks per unit value */
#define XCP_DAQ_TIMESTAMP_TICKS_PER_UNIT    0x1U

/********************************************************************************************************************
*  #! XcpOnEth Internal feature support                                                                             *
********************************************************************************************************************/
#ifndef XCP_DUMMY_STATEMENT
#define XCP_DUMMY_STATEMENT(v) (void)v
#endif

/*******************************************************************************************************************
*  #! Xcp module configuration                                                                                     *
*******************************************************************************************************************/
/*! @brief Defines the id for the ethernet transported layer */
#define XCP_TRANSPORT_LAYER_ETH         0U
/*! @brief Defines the  number of TL supported  */
#define XCP_NUM_OF_TL_SUPPORTED         1U
/*! @brief Defines the maximum number of xcp channel supported */
#define XCP_NUM_OF_CHANNELS             1U
/*! @brief Defines the max checksum block size supported */
#define XCP_CHECKSUM_MAX_BLOCK_SIZE     1U
/*! @brief Defines the length of the station id */
#define XCP_STATION_ID_LENGTH           7U
/*! @brief Defines the maximum cto value supported */
#define XCP_MAX_CTO_MAX                 255U
/*! @brief Defines the DAQ header length */
#define XCP_DAQ_HDR_LEN                 1U
/*! @brief Defines the maximum download block size  */
#define XCP_MAX_DOWNLOAD_BLOCK_SIZE     1U
/*! @brief Defines the download seperation time in milliseconds (ST IN MS /MAIN FUNCTION PERIOD IN MS )  */
#define XCP_MAX_ST                      1U
/*! @brief Defines the maximum segment supported  */
#define XCP_MAX_SEGMENT                 10U
/*! @brief Defines the maximum page supported  */
#define XCP_MAX_PAGE                    10U
/*! @brief Defines the maximum download length in bytes  */
#define XCP_MAX_DOWNLOAD_BYTES          10U
/*! @brief Defines the transmit queue size  */
#define XCP_DAQ_SEND_QUEUE_SIZE         1U
/*! @brief Defines the min stmin supported for this channel */
#define XCP_GET_MIN_ST_PGM(Ch)          10U
/*! @brief Defines the maximum number of sector supported */
#define XCP_MAX_NUMBER_OF_SECTOR        1U
/*! @brief Defines the maximum number of program sector supported */
#define XCP_MAX_PGM_SECTOR              1U
/*! @brief Defines the maximum number of event supported */
#define XCP_MAX_EVENT                   1U 
/*! @brief Defines the max DAQ supported */
#define XCP_MAX_DAQ                     (XCP_DAQ_COUNT+XCP_MIN_DAQ)
/*! @brief Defines the max ODT supported */
#define XCP_MAX_ODT                     XCP_ODT_COUNT
/*! @brief Defines the max ODT entries supported */
#define XCP_MAX_ODT_ENTRIES             XCP_ODT_ENTRIES_COUNT
/*! @brief Defines the max ODT daq supported */
#define XCP_MAX_ODT_DAQ                 XCP_ODT_ENTRY_SIZE_DAQ
/*! @brief Defines the max ODT stim supported */
#define XCP_MAX_ODT_STIM                XCP_ODT_ENTRY_SIZE_STIM
/*! @brief Defines the max DTO size */
#define XCP_MAX_DTO_MAX                 XCP_MAX_DTO
/*! @brief Defines the max CTO size */
#define XCP_CTO_MAX_SIZE                XCP_MAX_CTO
/*! @brief Defines the support for page calibrarion feature  */
#define XCP_CALIBRATION_PAGE_ENABLED    STD_ON
/*! @brief Defines the support for DAQ feature */
#define XCP_DAQ_ENABLED                 STD_ON
/*! @brief Defines the support for stim feature */
#define XCP_STIM_ENABLED                STD_ON
/*! @brief Defines the support for program feature */
#define XCP_PROGRAM_ENABLED             STD_ON
/*! @brief Defines the support for comm mode information */
#define XCP_COMM_MODE_INFO              STD_ON
/*! @brief Defines the support for block upload feature */
#define XCP_BLOCK_UPLOAD                STD_ON
/*! @brief Defines the support for get id */
#define XCP_GET_ID_GENERIC              STD_ON
/*! @brief Defines the support for fixed time stamp */
#define XCP_DAQ_TIMESTAMP_FIXED         STD_OFF
/*! @brief Defines the support for DAQ resume  */
#define XCP_DAQ_RESUME                  STD_ON
/*! @brief Defines the support for page freeze */
#define XCP_PAGE_FREEZE                 STD_ON
/*! @brief Defines the support for seed key */
#define XCP_SEED_KEY                    STD_ON
/*! @brief Defines the support for checksum */
#define XCP_CHECKSUM                    STD_ON
/*! @brief Defines the support for user command  */
#define XCP_USER_COMMAND                STD_ON
/*! @brief Defines the support for calibration */
#define XCP_CALIBRATION                 STD_ON
/*! @brief Defines the support for block download */
#define XCP_BLOCK_DOWNLOAD              STD_ON
/*! @brief Defines the support for short download */
#define XCP_SHORT_DOWNLOAD              STD_ON
/*! @brief Defines the support for modify bits */
#define XCP_MODIFY_BITS                 STD_ON
/*! @brief Defines the support for calibration page support */
#define XCP_CALIBRATION_PAGE            STD_ON
/*! @brief Defines the support for page info  */
#define XCP_PAGE_INFO                   STD_ON
/*! @brief Defines the support for page freeze */
#define XCP_PAGE_FREEZE                 STD_ON
/*! @brief Defines the support for copy calibration page */
#define XCP_COPY_CAL_PAGE               STD_ON
/*! @brief Defines the support for DAQ */
#define XCP_DAQ                         STD_ON
/*! @brief Defines the support for DAQ event info */
#define XCP_DAQ_EVENT_INFO              STD_ON
/*! @brief Defines the support for program */
#define XCP_PROGRAM                     STD_ON
/*! @brief Defines the support for bootloader  */
#define XCP_BOOTLOADER_DOWNLOAD         STD_ON
/*! @brief Defines the support for program info */
#define XCP_PROGRAM_INFO                STD_ON
/*! @brief Defines the support for write multiple DAQ */
#define XCP_WRITE_DAQ_MULTIPLE          STD_ON
/*! @brief Defines the support for STIM */
#define XCP_STIM                        STD_ON
/*! @brief Defines the support for block upload */
#define XCP_BLOCK_UPLOAD                STD_ON
/********************************************************************************************************************
*  #! SW and AUTOSAR Version Macros                                                                                 *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the Xcp configuration software Major version */
#define XCP_CFG_SW_MAJOR_VERSION                      1u
/*! @brief Defines the Xcp configuration software Minor version */
#define XCP_CFG_SW_MINOR_VERSION                      0u
/*! @brief Defines the Xcp configuration software Patch version */
#define XCP_CFG_SW_PATCH_VERSION                      0u
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by Xcp configuration  */
#define XCP_CFG_AR_RELEASE_MAJOR_VERSION              4u
/*! @brief Defines the AUTOSAR Release Minor version supported by Xcp configuration  */
#define XCP_CFG_AR_RELEASE_MINOR_VERSION              3u
/*! @brief Defines the AUTOSAR Release patch version supported by Xcp configuration  */
#define XCP_CFG_AR_RELEASE_REVISION_VERSION           1u
/********************************************************************************************************************
* #! XcpOnEth types                                                                                                 *
* #! macro , typedef declaration                                                                                    *
********************************************************************************************************************/
/*! @brief Defines the Xcp PB configuration type */
typedef struct 
{
    uint8 dummy; /*! @brief dummy element */
}Xcp_ConfigType;

/*! @brief Defines the type for Xcp channel */
typedef uint8 Xcp_ChannelType;
/*! @brief Defines the type for Xcp address pointer type */
typedef uint32 Xcp_AddressPtrType;

/*! @brief Defines the type for the standard page info */
typedef struct Xcp_PagCmd
{
    /*! @brief Defines the max pages */
    uint8 MaxPages;
    /*! @brief Defines the address extension value*/
    uint8 AddressExtension;
    /*! @brief Defines the number of address range mapping */
    uint8 NumOfAddrRangeMapping;
    /*! @brief Defines the compression method used */
    uint8 CompressionMethod;
    /*! @brief Defines the encrytion method used */
    uint8 EncryptionMethod;
}Xcp_PageStandardInfoType;

/*! @brief Defines the type for the page address mapping info */
typedef struct 
{
    /*! @brief Defines the source address of the page */
    uint32 SourceAddress;
    /*! @brief Defines the destination address of the page */
    uint32 DestinationAddress;
    /*! @brief Defines the length of the page address */
    uint32 Length;
}Xcp_PageAddressMappinInfoType;

/*! @brief Defines the type for xcp control state .*/
typedef enum
{
    /*! @brief Defines the xcp control state disable.*/
    XCP_CONTROL_STATE_DISABLE=0U,
    /*! @brief Defines the xcp control state enable.*/
    XCP_CONTROL_STATE_ENABLE
}Xcp_ControlStateType;

/*! @brief Defines the type for xcp Init state .*/
typedef enum
{
    /*! @brief Defines the xcp Init state as uninitialized. */
    XCP_INIT_STATE_UNINTITIALIZED=0U,
    /*! @brief Defines the xcp Init state as initialized. */
    XCP_INIT_STATE_INTITIALIZED
}Xcp_InitStateType;

/*! @brief Defines the type for xcp connection state type .*/
typedef enum
{
    /*! @brief Defines the xcp connection state type as unconnected . */
    XCP_CONNECTION_STATE_TYPE_UNCONNECTED=0U,
    /*! @brief Defines the xcp connection state type as connected . */
    XCP_CONNECTION_STATE_TYPE_CONNECTED
}Xcp_ConnectionStateType;

/*! @brief Defines the type for the odt entry index */
#if( XCP_MAX_ODT_ENTRIES < 256 )
typedef uint8 Xcp_OdtEntryIdxType; 
#else
typedef uint16 Xcp_OdtEntryIdxType; 
#endif
/*! @brief Defines the type for the Odt index */
typedef uint16 Xcp_OdtIdxType; 

/*! @brief Defines the type for the DTO buffer */
typedef struct 
{
    /*! @brief Defines the buffer for DTO*/
    uint8 Buffer[XCP_MAX_DTO_MAX];
    /*! @brief Defines the current buffer length for DTO*/
    uint8 BufferLength;
}Xcp_DtoBufferType;
/*! @brief Defines the type for Xcp stim mode */
typedef uint8 Xcp_StimModeType;
/*! @brief Defines the type for Xcp send status for the channel */
typedef uint8 Xcp_ChannelSendStatusType;
/*! @brief Defines the type for Xcp session status */
typedef uint8 Xcp_ChannelSessionStatusType;
/*! @brief Defines the resource protection bit mask for cal page access */
#define XCP_RESOURCE_PROTECTION_STATUS_CAL_PAG_BIT  0x01U
/*! @brief Defines the resource protection bit mask for DAQ access */
#define XCP_RESOURCE_PROTECTION_STATUS_DAQ_BIT      0x04U
/*! @brief Defines the resource protection bit mask for STIM access */
#define XCP_RESOURCE_PROTECTION_STATUS_STIM_BIT     0x08U
/*! @brief Defines the resource protection bit mask for PGM access */
#define XCP_RESOURCE_PROTECTION_STATUS_PGM_BIT      0x10U
/*! @brief Defines the resource protection bit mask status type */
typedef uint8 Xcp_ChannelResourceProtectionStatusype;
/*! @brief Defines the type for DAQ list status */
typedef struct 
{
    /*! @brief Defines the current number of Daq lists supported */
    uint16  NumOfDaqLists;
    /*! @brief Defines the current number of Odts supported */
    uint16  NumOfOdts;
    /*! @brief Defines the current number of Odt Entries supported */
    uint16  NumOfOdtEntries;
    /*! @brief Defines the current active Odt Entry Idx */
    Xcp_OdtEntryIdxType ActiveOdtEntryIdx;
    /*! @brief Defines the array containaing the first Odt id of each Daq */
    Xcp_OdtIdxType FirstOdtIdxOfDaq[XCP_MAX_DAQ];
    /*! @brief Defines the array containing number of odts supported for each daq */
    uint8 NumOfOdtsOfDaq[XCP_MAX_DAQ];
    /*! @brief Defines the array containing the first Odt entry id of each Daq */
    Xcp_OdtEntryIdxType FirstOdtEntryIdxOfDaq[XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM];
    /*! @brief Defines the array containing number of odts supported for each daq */
    uint8 NumOfOdtEntriesOfDaq[XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM];
    /*! @brief Defines the array containing the mapping of event channel to the Daq */
    uint16 DaqToEventChannelMap[XCP_MAX_DAQ];
    /*! @brief Defines the array containing the odt entries (address for the entry)*/
    Xcp_AddressPtrType  OdtEntries[XCP_MAX_ODT_ENTRIES];
    /*! @brief Defines the array containing the size of odt entries (odt entry element size  )*/
    Xcp_AddressPtrType  OdtEntriesSize[XCP_MAX_ODT_ENTRIES];
    /*! @brief Defines the array containing the Daq list mode */
    uint8 DaqListMode[XCP_MAX_DAQ];
    /*! @brief Defines the array containing the Daq list status */
    uint8 DaqListStatus[XCP_MAX_DAQ];
    /*! @brief Defines the array containing the Daq list mode */
    uint8 DaqListPrescalarInitialValue[XCP_MAX_DAQ];
    /*! @brief Defines the array containing the Daq list status */
    uint8 DaqListPrescalarCounter[XCP_MAX_DAQ];
    /*! @brief Defines the array containging the pointer reference to the STIM buffer of each daq */
    P2VAR(Xcp_DtoBufferType, AUTOMATIC, XCP_VAR_NOINIT) pStimBuffer[XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM];
}Xcp_DaqListStatusType;

/*! @brief Defines the type for the XCP channel control status */
typedef struct
{
    /*! @brief Defines the XCP channel connection state */
    Xcp_ConnectionStateType                 ConnectionState;
    /*! @brief Defines the XCP channel send status */
    Xcp_ChannelSendStatusType               SendStatus;  
    /*! @brief Defines the XCP channel session status */
    Xcp_ChannelSessionStatusType            SessionStatus;  
    /*! @brief Defines the XCP channel max DTO size */
    Xcp_ChannelSessionStatusType            MaxDto;  
    /*! @brief Defines the XCP channel max CTO size */
    Xcp_ChannelSessionStatusType            MaxCto; 
    /*! @brief Defines the XCP channel MTA extension  */
    uint8                                   MTAExtension;
    /*! @brief Defines the XCP channel next data block size for download/upload  */
    uint8                                   NextDataBlockSize;
    /*! @brief Defines the XCP channel current active Transport layer  */
    uint8                                   ActiveTl;
    /*! @brief Defines the XCP channel response pending status */
    boolean                                 ResponsePending;
    /*! @brief Defines the XCP channel current resource protection status */
    Xcp_ChannelResourceProtectionStatusype  ResourceProtectionStatus;
    /*! @brief Defines the XCP channel resource protection Init status */
    Xcp_ChannelResourceProtectionStatusype  ResourceProtectionInitStatus;
    /*! @brief Defines the XCP channel session configuration id */
    uint16                                  SessionConfigurationId;
    /*! @brief Defines the XCP channel event frame length */
    uint16                                  EventFrameLength;
    /*! @brief Defines the XCP channel response buffer length */
    uint16                                  ResponseBufferLen;
    /*! @brief Defines the XCP channel current MTA  */
    Xcp_AddressPtrType                      MTA;
    /*! @brief Defines the XCP channel response buffer  */
    uint8                                   ResponseBuffer[XCP_CTO_MAX_SIZE];
    /*! @brief Defines the XCP channel event frame buffer  */
    uint8                                   EventFrameBuffer[XCP_CTO_MAX_SIZE];
    /*! @brief Defines the XCP channel DAQ list status  */
    Xcp_DaqListStatusType                   Xcp_DaqListStatus;
}Xcp_ChannelCtrlStatusType;

/*! @brief Defines the type for program sector configuration */
typedef struct 
{
    /*! @brief Defines the program sector start address */
    uint32 SectorStartAddress;
    /*! @brief Defines the program sector end address */
    uint32 SectorEndAddress;
    /*! @brief Defines the program sector length */
    uint32 SectorLength;
}Xcp_PgmSectorConfigType;

/*! @brief Defines the Xcp command return code as OK */
#define XCP_CMD_OK                            0x00u
/*! @brief Defines the Xcp command return code as pending */
#define XCP_CMD_PENDING                       0x01u
/* Error Codes */
/*! @brief Defines the error command for Command processor synchronization. */
#define XCP_ERR_CMD_SYNCH                     0x00u
/*! @brief Defines the error command for Command was not executed. */
#define XCP_ERR_CMD_BUSY                      0x10u
/*! @brief Defines the error command for Command rejected because DAQ is running. */
#define XCP_ERR_DAQ_ACTIVE                    0x11u
/*! @brief Defines the error command for Command rejected because PGM is running. */
#define XCP_ERR_PRM_ACTIVE                    0x12u
/*! @brief Defines the error command for Unknown command or not implemented optional command. */
#define XCP_ERR_CMD_UNKNOWN                   0x20u
/*! @brief Defines the error command for Command syntax invalid */
#define XCP_ERR_CMD_SYNTAX                    0x21u
/*! @brief Defines the error command for Command syntax valid but command parameter(s) out of range */
#define XCP_ERR_OUT_OF_RANGE                  0x22u
/*! @brief Defines the error command for the memory location is write protected. */
#define XCP_ERR_WRITE_PROTECTED               0x23u
/*! @brief Defines the error command for memory location is not accessible. */
#define XCP_ERR_ACCESS_DENIED                 0x24u
/*! @brief Defines the error command for Access denied, Seed & Key is required */
#define XCP_ERR_ACCESS_LOCKED                 0x25u
/*! @brief Defines the error command for Selected page not available  */
#define XCP_ERR_PAGE_NOT_VALID                0x26u
/*! @brief Defines the error command for Selected page mode not available */
#define XCP_ERR_PAGE_MODE_NOT_VALID           0x27u
/*! @brief Defines the error command for Selected segment not valid */
#define XCP_ERR_SEGMENT_NOT_VALID             0x28u
/*! @brief Defines the error command for Sequence error */
#define XCP_ERR_SEQUENCE                      0x29u
/*! @brief Defines the error command for DAQ configuration not valid */
#define XCP_ERR_DAQ_CONFIG                    0x2Au
/*! @brief Defines the error command for Memory overflow error */
#define XCP_ERR_MEMORY_OVERFLOW               0x30u
/*! @brief Defines the error command for Generic error. */
#define XCP_ERR_GENERIC                       0x31u
/*! @brief Defines the error command for the slave internal program verify routine detects an error. */
#define XCP_ERR_VERIFY                        0x32u
/*! @brief Defines the error command for the Access to the requested resource is temporary not possible. */
#define XCP_ERR_RESOURCE_TEMP_NOT_ACCESSIBLE  0x33u
/*! @brief Defines the error command for other error . */
#define XCP_CMD_ERROR                         0xFFu

#include "Xcp_Appl.h"

#endif /* XCP_CFG_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
