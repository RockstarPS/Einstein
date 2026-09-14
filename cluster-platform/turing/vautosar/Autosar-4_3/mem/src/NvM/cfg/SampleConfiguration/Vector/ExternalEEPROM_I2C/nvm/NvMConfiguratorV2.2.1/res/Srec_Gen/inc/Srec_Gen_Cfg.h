//*****Automatically Generated From NvM Configurator Tool*****

#ifndef SREC_GEN_CFG_H
#define SREC_GEN_CFG_H

#include "Eep_Driver.h"
#include "Eep24xx.h"

#define FLASH_Simulator_Init()                  Eep_Driver_Init()
#define FLASH_Simulator_Free()                  Eep_Driver_Free()
#define FLASH_Simulator_getImage()              Eep_Driver_getImage()
#define FLASH_Simulator_getMemMap()             Eep_Driver_getMemMap()

//#define Little_Endian 


#define MEM1_MainFunction()                     Ea_MainFunction();
#define MEM_MainFunction()                      EepDrv_MainFunction();

#define MEM1_Init()                             Ea_Init();
#define MEM_Init(x)                             EepDrv_Init(x);

#define MEM_Start_Address                       0u
#define BYTES_PER_LINE                          16u
#define INTERNAL_MEM                            FALSE


#endif
