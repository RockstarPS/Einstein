//*****Automatically Generated From NvM Configurator Tool*****

#ifndef SREC_GEN_CFG_H
#define SREC_GEN_CFG_H

#include "Fls_Simulator.h"
#include "fls.h"
#include "SNvM.h"
#define FLASH_Simulator_Init()                  Fls_Driver_Init()
#define FLASH_Simulator_Free()                  Fls_Driver_Free()
#define FLASH_Simulator_getImage()              Fls_Driver_getImage()
#define FLASH_Simulator_getMemMap()             Fls_Driver_getMemMap()

#define S19REC                                  0
#define S28REC                                  1
#define S37REC                                  2

//#define Little_Endian 
#define SREC_DYNAMIC_ADDRESS
#define SREC_FIXED_ADDRESS

#define MEM1_MainFunction()                     Fee_MainFunction();
#define MEM2_MainFunction()                     SNvM_MainFunction();
#define MEM_MainFunction()                      Fls_MainFunction();

#define MEM1_Init()                             Fee_Init();
#define MEM2_Init()                             SNvM_Init();
#define MEM_Init(x)                             Fls_Init(x);

#define MEM_Start_Address                       335544320u
#define BYTES_PER_LINE                          16u
#define SREC_MEMORY_SIZE                        65536u
#define SREC_TYPE                               S37REC
#define INTERNAL_MEM                            TRUE


#endif
