#ifndef STUBS_H
#define STUBS_H

#include "Std_Types.h"

#define OS_CODE              /*NCHELLAP Added to resolve compilation error from OS function declaration*/

#ifndef NULL
#define NULL ((void *)0)
#endif

#define E_NOT_READY         ((Std_ReturnType) 2u)    /* NCHELLAP : Added to resolve compilation error from CmpLib */

typedef uint16 NvM_BlockIdType;

#define	EcuMConf_EcuMWakeupSource_MCU_TIMER0			(1)     /*NCHELLAP Stub Added to resolve compilation error from Gpt_PBCfg.c This is added in TI delivered EcuM.h stub*/
#define	EcuMConf_EcuMWakeupSource_MCU_TIMER1			(2)
#define	EcuMConf_EcuMWakeupSource_MCU_TIMER2			(3)
#define	EcuMConf_EcuMWakeupSource_MCU_TIMER3			(4)

extern void i2c_test();

#endif
