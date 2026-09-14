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

#ifndef UPDi_Types_H
#define UPDi_Types_H

#include "Std_Types.h"
#include "UPD_Types.h"
#include "UPDd_Types.h"
#include <stdint.h>


//=====================================================================================================================
/* CONSTANTS & TYPES */
//=====================================================================================================================

#define UPDd_HASH_TYPE (eUPDiHash_Sha256)
#define UPDd_HASH_SIZE (32)

typedef enum
{
    eUPDiMode_Reprog,
    eUPDiMode_App
} tUPDiMode;
struct sUPDiInstallSession;
typedef struct sUPDiInstallSession tUPDiInstallSession;

struct sUPDiTarget;
struct sUPDiIoAdapterVtbl;
struct sUPDiAbstractInstaller;

#ifndef UPDd_INJECTION_TESTING
typedef const struct
#else
typedef struct
#endif
{
    tUPDiMode Mode;
    uint8_t TargetsCount;
    uint8_t InstallersCount;
    const struct sUPDiTarget** Targets;
    const struct sUPDiAbstractInstaller** Installers;
} tUPDiUpdateCdd;

typedef uint32_t tUPDiSha256[8];

typedef struct sUPDiHashingContext
{
	tUPDHashingType HashingTypes; // Bit field, several hash types can be required
	union
	{
		uint32_t Crc32;
		tUPDiSha256 Sha256;
	};
} tUPDiHashingContext;

typedef enum
{
    eUPDiIoReq_Hash,
    eUPDiIoReq_Read,
    eUPDiIoReq_Write,
    eUPDiIoReq_Erase,
    eUPDiIoReq_Init,
    eUPDiIoReq_Decrypt,
    eUPDiIoReq_SignVerify,
    eUPDiIoReq_Idle
} tUPDiIoReqType;

typedef /*const*/ struct sUPDiPartition
{
    // Only for /dev
    const char* path;
    uint32_t Address;
    uint32_t Size;
    const struct sUPDiIoAdapter* IoAdapter;
} tUPDiPartition;

typedef const struct sUPDiPartitionGroup
{
    const char * Name;
    tUPDiPartition* BankA;
    tUPDiPartition* BankB;
    tUPDiPartition* BankExt;
} tUPDiPartitionGroup;

typedef char tUPDdPackageName[UPDd_MAX_PACKAGE_NAME_SIZE];

#endif 
