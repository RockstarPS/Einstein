#ifndef SREC_MAKE_H
#define SREC_MAKE_H

#include "General_Cfg.h"


typedef enum
{
    S19REC = 0,
    S28REC,
    S37REC
}SrecType_Type;

typedef struct
{
    uint16    NoOfDynamicPartition; 
    uint16    NoOfFixedPartition;  
    uint8     BytesPerLine;
    uint8     SectorFooterLen;
    SrecType_Type SrecType;
    uint32    Partition_StartAddress[NO_OF_DYNAMIC_PARTITION];
    uint32    Partition_SectorSize[NO_OF_DYNAMIC_PARTITION];
    uint32    Fixed_Start_Address[NO_OF_FIXED_PARTITION];
    uint32    Fixed_End_Address[NO_OF_FIXED_PARTITION];
    char      FileName [100];
    uint32    SrecOffset;
}SrecMake_ConfigType;

extern SrecMake_ConfigType SrecMake_Config;


extern void srec_main();

#endif
