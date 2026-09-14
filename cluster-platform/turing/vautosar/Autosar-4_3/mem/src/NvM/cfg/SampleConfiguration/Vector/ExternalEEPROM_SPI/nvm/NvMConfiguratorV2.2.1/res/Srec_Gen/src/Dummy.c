#include <stdio.h>
#include "Std_Types.h"

#include "Rte.h"
#include "Dummy_Types.h"
#include "Dem_Cbk.h"

typedef enum
{
    MEMIF_MODE_SLOW = 0,
    MEMIF_MODE_FAST
}MemIf_ModeType;

// #define NVMEXT_INVALID_RETENTION_BLOCKS     0xA5A5

// uint16 RetentionBlockStatus = NVMEXT_INVALID_RETENTION_BLOCKS;
// const uint16 RetentionBlockStatusDefault = NVMEXT_INVALID_RETENTION_BLOCKS; 
// uint16 _NvMExt_RetRAM_GP1_START = NVMEXT_INVALID_RETENTION_BLOCKS;
// uint16 _NvMExt_RetRAM_GP2_START = NVMEXT_INVALID_RETENTION_BLOCKS;
// Dem_Cfg_AdminDataType Dem_Cfg_AdminData = NVMEXT_INVALID_RETENTION_BLOCKS;
// Dem_Cfg_StatusDataType Dem_Cfg_StatusData = NVMEXT_INVALID_RETENTION_BLOCKS;
