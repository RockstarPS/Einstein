#include "NvM.h"
#include "SNvM.h"
#include "Fee.h"
#include "FeeExt.h"
#include "Fls.h"
#include "EmulatedEEPROM.h"

// Main Cfg

#define EEPROM_IMAGE_GEN                STD_ON
#define FLASHCONSTANT_IMAGE_GEN         STD_ON 
#define NVMDEFAULTS_IMAGE_GEN           STD_ON
#define SREC_DYNAMIC_ADDRESS
#define SREC_FIXED_ADDRESS
#define FLS_SREC_GEN                    STD_ON
#define FLS_ULP_GEN                     STD_ON


#define MEMSTACK_INIT()                 NvM_Init();\    
                                        SNvM_Init();\
                                        Fee_Init();\
                                        Fls_Init();


#define MEMSTACK_MAINFUNCTION()         NvM_MainFunction();\
                                        SNvM_MainFunction();\
                                        Fee_MainFunction();

#define NVMDEFAULTS_START_INDEX         0x8000


// Flash Driver Configs
#define EEPROM_SIZE                     128*1024 //128KB
#define EEPROM_ERASE_VALUE              0xFF
#define EEP_DRIVER_TYPE                 WORKFLASH



// NvM Default Values Cfg
#define NUM_OF_VARIANT                  29


// Fls Configuration
#define NO_OF_DYNAMIC_PARTITION         FEE_NUM_PARTITIONS
#define SECTOR_FOOTER_LENGTH            16 //need to revisit

#define EEPROM_OFSET                    0x14000000
#define FLS_SREC_OFSET                  0x10080000
#define FLS_ULP_OFSET                   0

#define EEPROM_SREC_DATA_BYTES_PER_LINE 16
#define FLS_SREC_DATA_BYTES_PER_LINE    16
#define FLS_ULP_DATA_BYTES_PER_LINE     16

#define FLS_CONST_IMAGE_SIZE            0xFFFF

#define EEPROM_SREC_IMG_TYPE            S37REC
#define FLS_SREC_IMG_TYPE               S37REC
#define FLS_ULP_IMG_TYPE                S19REC


// Small Sector Configs
#define NO_OF_FIXED_PARTITION           1

extern const uint32 FixedPartitionStartAddress[NO_OF_FIXED_PARTITION];
extern const uint32 FixedPartitionEndAddress[NO_OF_FIXED_PARTITION];

// File Name Config
extern const char varinat_name[NUM_OF_VARIANT+30][100];