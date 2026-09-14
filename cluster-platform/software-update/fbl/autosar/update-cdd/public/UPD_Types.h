/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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

# ifndef UPD_Types_H
# define UPD_Types_H

#include "Std_Types.h" // for uint8, uint16, uint32, boolean
#include <stdint.h>

//=====================================================================================================================
//  CONSTANTS & TYPES

enum
{
	UPD_MODE_BG = 0x1,
	UPD_MODE_FG = 0x2,
};
typedef uint8_t tUPDCommMode;

enum
{
    UPD_MODE_REPROG = 0x1,
    UPD_MODE_APP = 0x2
};
typedef uint8_t tUPDMode;

enum
{
    eUPDiUpdate_BankInvalid,
    eUPDiUpdate_BankActive,
    eUPDiUpdate_BankInactive,
};
typedef uint8_t tUPDBank;


enum
{
    eUPDiUpdate_Idle         = 0x0100, // There is no update activity
		eUPDiUpdate_Idle_Booting               = 0x0101, // waiting BootStatus() notification
		eUPDiUpdate_Idle_Hold                  = 0x0102, // Inspection & Synch are delayed for a while after boot to not overspend CPU  early
		eUPDiUpdate_Idle_InspectingAndSynching = 0x0103, // Inspecting, Synching or reparing
		eUPDiUpdate_Idle_Healthy               = 0x0104, // A and B integrity test passed
		eUPDiUpdate_Idle_AutoSwapPending       = 0x0105, // Active is damaged, Inactive is ok, we'll swap at next boot
		eUPDiUpdate_Idle_Damaged               = 0x0106, // System is not recoverable both A & B are damaged
		eUPDiUpdate_Idle_Mask                  = 0xFF00,
    eUPDiUpdate_Updating    = 0x0200, // Update is ongoing
    eUPDiUpdate_Validation  = 0x0300, // Update is done, validation is ongoing (Hash verification and custom validation)
	eUPDiUpdate_Validated   = 0x0400, // Waiting the activation request
	eUPDiUpdate_Activation  = 0x0500, // Waiting reset
    eUPDiUpdate_Activated   = 0x0600, // Reset done
		eUPDiUpdate_Activated_Booting      = 0x0601, // waiting BootStatus() notification
		eUPDiUpdate_Activated_Success      = 0x0602, // New chain is running boot is successful
		eUPDiUpdate_Activated_Failure      = 0x0603, // New chain is running boot failed
		eUPDiUpdate_Activated_RollbackDone = 0x0604, // We are running on the old chain
    eUPDiUpdate_RollingBack = 0x0700, // Rollback pending, waiting reboot
    eUPDiUpdate_Level1Mask  = 0xFF00,
};
typedef uint16_t tUPDUpdateState;

enum
{
    eUPDiHash_Invalid = 0x00,
    eUPDiHash_Crc32 = 0x01,     /*for Polynomial 0x04C11DB7 (standard for Ethernet and Arm)*/
    eUPDiHash_Sha256 = 0x02
};
typedef uint8_t tUPDHashingType;

enum
{
    eUPDiTarget_Uninst     = 0x100,
		eUPDiTarget_UninstMask       = 0xF00,
		eUPDiTarget_UninstErasing    = 0x110,// 272 in decimal
		eUPDiTarget_UninstIdle       = 0x120,// 288  in decimal
			eUPDiTarget_UninstIdleMask           = 0xFF0,
			eUPDiTarget_UninstIdleUndef          = 0x122,// 290 in decimal
			eUPDiTarget_UninstIdleEmpty          = 0x123,// 291 in decimal
		eUPDiTarget_UninstInstalling = 0x130, // 304 in decimal
		eUPDiTarget_UninstCopiyng    = 0x140, // 320 in decimal
    eUPDiTarget_Installed  = 0x200,
		eUPDiTarget_InstMask         = 0xF00,
		eUPDiTarget_InstUnVerified   = 0x210,
			eUPDiTarget_InstUnVerified_Mask      = 0xFF0,
			eUPDiTarget_InstUnVerified_Verfiable = 0x211, // 529 in decimal
			eUPDiTarget_InstUnVerified_Verfiyng  = 0x212, // 530 in decimal
			eUPDiTarget_InstUnVerified_Hashing   = 0x213, // 531 in decimal
			eUPDiTarget_InstUnVerified_Hashed    = 0x218, // 536 in decimal
		eUPDiTarget_InstVerfied      = 0x220,
			eUPDiTarget_InstVerfiedMask          = 0xFF0,
			eUPDiTarget_InstVerfiedDeployable    = 0x221, // 545 in decimal
			eUPDiTarget_InstVerfiedDeploying     = 0x222, // 546 in decimal
			eUPDiTarget_InstVerfiedDeployed      = 0x223, // 547 in decimal
    eUPDiTarget_Invalid     = 0xFFF,
};
typedef uint16_t tUPDiTargetState;


enum // Operation are sorted per priority
{    // low prio are first
	eUPDOpNone 			  = 0x00,
	eUPDOpOperating       = 0x10,
	eUPDOpCopyng          = 0x11,
	eUPDOpHashingInactive = 0x12,
	eUPDOpHashingActive   = 0x13,
	eUPDOpErasingInactive = 0x14,
	eUPDOpErasingActive   = 0x15,
	eUPDOpOperatingMask   = 0xF0,
	eUPDOpInstalling      = 0x20,
	eUPDOpSchedule        = 0xFF,
};
typedef uint8_t tUPDiOpType;

enum
{
    eUPD_Ok,
    eUPD_NotOk,
    eUPD_Pending,
};
typedef uint8_t tUPDStatus;

enum /*tUPDWorkload*/
{
    eUPD_eWlIdle =0,
    eUPD_eWlLow,
    eUPD_eWlHigh,
    eUPD_eWlFull,
};
typedef uint8_t tUPDWorkload;

typedef struct
{
    uint32_t             QueueSize;
    uint8_t              TargetCount;
    char*              ServiceName;
} tUPDMeta;

typedef struct
{
    uint8_t              HashSize; // Size in Byte, 4 for CRC32, 32 for SHA256
    tUPDHashingType   HashType;
    uint8_t*             pHash;
} tUPDHashInfo;

typedef struct
{
    // KPIs
    uint32_t          TansferDurationMs;
    uint32_t          MaxQueueOccupation;
    uint32_t          AverageQueueOccupation;
    uint32_t          MinQueueOccupation;
    uint8_t           IoLoad;     //Percentage of time spent with a non-empty Io queue 
    uint8_t           UpdateLoad; //Percentage of time spent with a non-empty update queue 
} tUPDTransferKPIs;

typedef struct
{
	uint32_t size;
	void* data;
	boolean overflow;
	boolean badData;
	boolean keepDefault;
} tUPDStream;

#endif /*UPD_Types_H*/
