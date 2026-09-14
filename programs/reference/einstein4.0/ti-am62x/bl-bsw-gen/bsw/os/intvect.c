/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2026 by Visteon Corporation.       All rights reserved.         
*                                                                                                                    
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                   
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve              
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States     
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,             
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its       
* rights under all copyright laws to protect this work as a published work, when appropriate.                        
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it   
* without the written authorization of Visteon Corporation.                                                          
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file Os_IntvectCfg.c
*    @ingroup Os Configuration
*    @brief This is Os link time configuration source file. It contains definitions of link time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.351151300
********************************************************************************************************************/

#ifndef INTVECT_C
#define INTVECT_C
#include "OsPrivate.h"
#include "intvect.h"
#include "Os_HooksCfg.h"


#define OsPreISRHook(x)         OsCfgPreISRHook(x)
#define OsPostISRHook(x)        OsCfgPostISRHook(x)


#pragma clang section rodata    = ".osIrqVecTab"

const osVoidFunctionType osIRQTable[osdNumberOfIRQs] =
{
    osISRUnhandledException,        /* #0:not configured */
    osISRUnhandledException,        /* #1:not configured */
    osISRUnhandledException,        /* #2:not configured */
    osISRUnhandledException,        /* #3:not configured */
    osISRUnhandledException,        /* #4:not configured */
    osISRUnhandledException,        /* #5:not configured */
    osISRUnhandledException,        /* #6:not configured */
    osISRUnhandledException,        /* #7:not configured */
    osISRUnhandledException,        /* #8:not configured */
    osISRUnhandledException,        /* #9:not configured */
    osISRUnhandledException,        /* #10:not configured */
    osISRUnhandledException,        /* #11:not configured */
    osISRUnhandledException,        /* #12:not configured */
    osISRUnhandledException,        /* #13:not configured */
    osISRUnhandledException,        /* #14:not configured */
    osISRUnhandledException,        /* #15:not configured */
    osISRUnhandledException,        /* #16:not configured */
    osISRUnhandledException,        /* #17:not configured */
    osISRUnhandledException,        /* #18:not configured */
    osISRUnhandledException,        /* #19:not configured */
    osISRUnhandledException,        /* #20:not configured */
    osISRUnhandledException,        /* #21:not configured */
    osISRUnhandledException,        /* #22:not configured */
    osISRUnhandledException,        /* #23:not configured */
    osISRUnhandledException,        /* #24:not configured */
    osISRUnhandledException,        /* #25:not configured */
    osISRUnhandledException,        /* #26:not configured */
    osISRUnhandledException,        /* #27:not configured */
    osISRWrap_McuOsGptIsr,        /* #28:McuOsGptIsr */
    osISRUnhandledException,        /* #29:not configured */
    osISRUnhandledException,        /* #30:not configured */
    osISRUnhandledException,        /* #31:not configured */
    osISRUnhandledException,        /* #32:not configured */
    osISRUnhandledException,        /* #33:not configured */
    osISRUnhandledException,        /* #34:not configured */
    osISRUnhandledException,        /* #35:not configured */
    osISRUnhandledException,        /* #36:not configured */
    osISRUnhandledException,        /* #37:not configured */
    osISRUnhandledException,        /* #38:not configured */
    osISRUnhandledException,        /* #39:not configured */
    osISRUnhandledException,        /* #40:not configured */
    osISRUnhandledException,        /* #41:not configured */
    osISRUnhandledException,        /* #42:not configured */
    osISRWrap_McuCan0RxTxIsr,        /* #43:McuCan0RxTxIsr */
    osISRUnhandledException,        /* #44:not configured */
    osISRUnhandledException,        /* #45:not configured */
    osISRWrap_McuCan1RxTxIsr,        /* #46:McuCan1RxTxIsr */
    osISRUnhandledException,        /* #47:not configured */
    osISRUnhandledException,        /* #48:not configured */
    osISRUnhandledException,        /* #49:not configured */
    osISRUnhandledException,        /* #50:not configured */
    osISRUnhandledException,        /* #51:not configured */
    osISRUnhandledException,        /* #52:not configured */
    osISRUnhandledException,        /* #53:not configured */
    osISRUnhandledException,        /* #54:not configured */
    osISRUnhandledException,        /* #55:not configured */
    osISRUnhandledException,        /* #56:not configured */
    osISRUnhandledException,        /* #57:not configured */
    osISRUnhandledException,        /* #58:not configured */
    osISRUnhandledException,        /* #59:not configured */
    osISRUnhandledException,        /* #60:not configured */
    osISRUnhandledException,        /* #61:not configured */
    osISRUnhandledException,        /* #62:not configured */
    osISRUnhandledException,        /* #63:not configured */
    osISRUnhandledException,        /* #64:not configured */
    osISRUnhandledException,        /* #65:not configured */
    osISRUnhandledException,        /* #66:not configured */
    osISRUnhandledException,        /* #67:not configured */
    osISRUnhandledException,        /* #68:not configured */
    osISRUnhandledException,        /* #69:not configured */
    osISRUnhandledException,        /* #70:not configured */
    osISRUnhandledException,        /* #71:not configured */
    osISRUnhandledException,        /* #72:not configured */
    osISRUnhandledException,        /* #73:not configured */
    osISRUnhandledException,        /* #74:not configured */
    osISRUnhandledException,        /* #75:not configured */
    osISRUnhandledException,        /* #76:not configured */
    osISRUnhandledException,        /* #77:not configured */
    osISRUnhandledException,        /* #78:not configured */
    osISRUnhandledException,        /* #79:not configured */
    osISRUnhandledException,        /* #80:not configured */
    osISRUnhandledException,        /* #81:not configured */
    osISRUnhandledException,        /* #82:not configured */
    osISRUnhandledException,        /* #83:not configured */
    osISRUnhandledException,        /* #84:not configured */
    osISRUnhandledException,        /* #85:not configured */
    osISRUnhandledException,        /* #86:not configured */
    osISRUnhandledException,        /* #87:not configured */
    osISRUnhandledException,        /* #88:not configured */
    osISRUnhandledException,        /* #89:not configured */
    osISRUnhandledException,        /* #90:not configured */
    osISRUnhandledException,        /* #91:not configured */
    osISRUnhandledException,        /* #92:not configured */
    osISRUnhandledException,        /* #93:not configured */
    osISRUnhandledException,        /* #94:not configured */
    osISRUnhandledException,        /* #95:not configured */
    osISRUnhandledException,        /* #96:not configured */
    osISRUnhandledException,        /* #97:not configured */
    osISRUnhandledException,        /* #98:not configured */
    osISRUnhandledException,        /* #99:not configured */
    osISRUnhandledException,        /* #100:not configured */
    osISRUnhandledException,        /* #101:not configured */
    osISRUnhandledException,        /* #102:not configured */
    osISRUnhandledException,        /* #103:not configured */
    osISRUnhandledException,        /* #104:not configured */
    osISRUnhandledException,        /* #105:not configured */
    osISRWrap_PmicCdd_nINTGpioInterrupt,        /* #106:PmicCdd_nINTGpioInterrupt */
    osISRUnhandledException,        /* #107:not configured */
    osISRUnhandledException,        /* #108:not configured */
    osISRUnhandledException,        /* #109:not configured */
    osISRUnhandledException,        /* #110:not configured */
    osISRUnhandledException,        /* #111:not configured */
    osISRUnhandledException,        /* #112:not configured */
    osISRUnhandledException,        /* #113:not configured */
    osISRUnhandledException,        /* #114:not configured */
    osISRUnhandledException,        /* #115:not configured */
    osISRUnhandledException,        /* #116:not configured */
    osISRUnhandledException,        /* #117:not configured */
    osISRUnhandledException,        /* #118:not configured */
    osISRUnhandledException,        /* #119:not configured */
    osISRUnhandledException,        /* #120:not configured */
    osISRUnhandledException,        /* #121:not configured */
    osISRUnhandledException,        /* #122:not configured */
    osISRUnhandledException,        /* #123:not configured */
    osISRUnhandledException,        /* #124:not configured */
    osISRUnhandledException,        /* #125:not configured */
    osISRUnhandledException,        /* #126:not configured */
    osISRUnhandledException,        /* #127:not configured */
    osISRUnhandledException,        /* #128:not configured */
    osISRUnhandledException,        /* #129:not configured */
    osISRUnhandledException,        /* #130:not configured */
    osISRUnhandledException,        /* #131:not configured */
    osISRUnhandledException,        /* #132:not configured */
    osISRUnhandledException,        /* #133:not configured */
    osISRUnhandledException,        /* #134:not configured */
    osISRUnhandledException,        /* #135:not configured */
    osISRUnhandledException,        /* #136:not configured */
    osISRUnhandledException,        /* #137:not configured */
    osISRWrap_Gpt_Ch3Isr,        /* #138:Gpt_Ch3Isr */
    osISRWrap_Gpt_Ch4Isr,        /* #139:Gpt_Ch4Isr */
    osISRUnhandledException,        /* #140:not configured */
    osISRUnhandledException,        /* #141:not configured */
    osISRUnhandledException,        /* #142:not configured */
    osISRUnhandledException,        /* #143:not configured */
    osISRUnhandledException,        /* #144:not configured */
    osISRUnhandledException,        /* #145:not configured */
    osISRUnhandledException,        /* #146:not configured */
    osISRUnhandledException,        /* #147:not configured */
    osISRUnhandledException,        /* #148:not configured */
    osISRUnhandledException,        /* #149:not configured */
    osISRUnhandledException,        /* #150:not configured */
    osISRUnhandledException,        /* #151:not configured */
    osISRUnhandledException,        /* #152:not configured */
    osISRUnhandledException,        /* #153:not configured */
    osISRUnhandledException,        /* #154:not configured */
    osISRUnhandledException,        /* #155:not configured */
    osISRUnhandledException,        /* #156:not configured */
    osISRUnhandledException,        /* #157:not configured */
    osISRUnhandledException,        /* #158:not configured */
    osISRUnhandledException,        /* #159:not configured */
    osISRUnhandledException,        /* #160:not configured */
    osISRUnhandledException,        /* #161:not configured */
    osISRUnhandledException,        /* #162:not configured */
    osISRUnhandledException,        /* #163:not configured */
    osISRUnhandledException,        /* #164:not configured */
    osISRUnhandledException,        /* #165:not configured */
    osISRUnhandledException,        /* #166:not configured */
    osISRUnhandledException,        /* #167:not configured */
    osISRUnhandledException,        /* #168:not configured */
    osISRUnhandledException,        /* #169:not configured */
    osISRUnhandledException,        /* #170:not configured */
    osISRUnhandledException,        /* #171:not configured */
    osISRUnhandledException,        /* #172:not configured */
    osISRUnhandledException,        /* #173:not configured */
    osISRUnhandledException,        /* #174:not configured */
    osISRUnhandledException,        /* #175:not configured */
    osISRUnhandledException,        /* #176:not configured */
    osISRUnhandledException,        /* #177:not configured */
    osISRUnhandledException,        /* #178:not configured */
    osISRUnhandledException,        /* #179:not configured */
    osISRUnhandledException,        /* #180:not configured */
    osISRUnhandledException,        /* #181:not configured */
    osISRUnhandledException,        /* #182:not configured */
    osISRUnhandledException,        /* #183:not configured */
    osISRUnhandledException,        /* #184:not configured */
    osISRUnhandledException,        /* #185:not configured */
    osISRUnhandledException,        /* #186:not configured */
    osISRUnhandledException,        /* #187:not configured */
    osISRUnhandledException,        /* #188:not configured */
    osISRUnhandledException,        /* #189:not configured */
    osISRUnhandledException,        /* #190:not configured */
    osISRUnhandledException,        /* #191:not configured */
    osISRUnhandledException,        /* #192:not configured */
    osISRUnhandledException,        /* #193:not configured */
    osISRUnhandledException,        /* #194:not configured */
    osISRUnhandledException,        /* #195:not configured */
    osISRWrap_McuI2c3IoIsr,        /* #196:McuI2c3IoIsr */
    osISRWrap_McuI2c0PmicIsr,        /* #197:McuI2c0PmicIsr */
    osISRUnhandledException,        /* #198:not configured */
    osISRUnhandledException,        /* #199:not configured */
    osISRUnhandledException,        /* #200:not configured */
    osISRUnhandledException,        /* #201:not configured */
    osISRUnhandledException,        /* #202:not configured */
    osISRUnhandledException,        /* #203:not configured */
    osISRUnhandledException,        /* #204:not configured */
    osISRUnhandledException,        /* #205:not configured */
    osISRUnhandledException,        /* #206:not configured */
    osISRUnhandledException,        /* #207:not configured */
    osISRUnhandledException,        /* #208:not configured */
    osISRUnhandledException,        /* #209:not configured */
    osISRUnhandledException,        /* #210:not configured */
    osISRUnhandledException,        /* #211:not configured */
    osISRUnhandledException,        /* #212:not configured */
    osISRUnhandledException,        /* #213:not configured */
    osISRUnhandledException,        /* #214:not configured */
    osISRUnhandledException,        /* #215:not configured */
    osISRUnhandledException,        /* #216:not configured */
    osISRUnhandledException,        /* #217:not configured */
    osISRUnhandledException,        /* #218:not configured */
    osISRUnhandledException,        /* #219:not configured */
    osISRUnhandledException,        /* #220:not configured */
    osISRUnhandledException,        /* #221:not configured */
    osISRUnhandledException,        /* #222:not configured */
    osISRUnhandledException,        /* #223:not configured */
    osISRUnhandledException,        /* #224:not configured */
    osISRUnhandledException,        /* #225:not configured */
    osISRUnhandledException,        /* #226:not configured */
    osISRUnhandledException,        /* #227:not configured */
    osISRUnhandledException,        /* #228:not configured */
    osISRUnhandledException,        /* #229:not configured */
    osISRUnhandledException,        /* #230:not configured */
    osISRUnhandledException,        /* #231:not configured */
    osISRUnhandledException,        /* #232:not configured */
    osISRUnhandledException,        /* #233:not configured */
    osISRUnhandledException,        /* #234:not configured */
    osISRUnhandledException,        /* #235:not configured */
    osISRUnhandledException,        /* #236:not configured */
    osISRUnhandledException,        /* #237:not configured */
    osISRUnhandledException,        /* #238:not configured */
    osISRUnhandledException,        /* #239:not configured */
    osISRUnhandledException,        /* #240:not configured */
    osISRUnhandledException,        /* #241:not configured */
    osISRWrap_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0,        /* #242:Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 */
    osISRUnhandledException,        /* #243:not configured */
    osISRUnhandledException,        /* #244:not configured */
    osISRUnhandledException,        /* #245:not configured */
    osISRUnhandledException,        /* #246:not configured */
    osISRUnhandledException,        /* #247:not configured */
    osISRUnhandledException,        /* #248:not configured */
    osISRUnhandledException,        /* #249:not configured */
    osISRUnhandledException,        /* #250:not configured */
    osISRUnhandledException,        /* #251:not configured */
    osISRUnhandledException,        /* #252:not configured */
    osISRUnhandledException,        /* #253:not configured */
    osISRUnhandledException,        /* #254:not configured */
    osISRUnhandledException        /* #255:not configured */
};

#pragma clang section rodata    = ".osconst"

const osuint16 osIsrIdTable[osdNumberOfConfiguredIRQs+1] =
{
	28U,   /* McuOsGptIsr */
	43U,   /* McuCan0RxTxIsr */
	46U,   /* McuCan1RxTxIsr */
	196U,   /* McuI2c3IoIsr */
	197U,   /* McuI2c0PmicIsr */
	138U,   /* Gpt_Ch3Isr */
	139U,   /* Gpt_Ch4Isr */
	106U,   /* PmicCdd_nINTGpioInterrupt */
	242U,   /* Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 */
    0U  /* ISR osSystemCat2ISR */
};


const osIntPrioType osIRQPrioTable[osdNumberOfConfiguredIRQs+1] =
{
	{ 28, 0 },   /* McuOsGptIsr */
	{ 43, 1 },   /* McuCan0RxTxIsr */
	{ 46, 2 },   /* McuCan1RxTxIsr */
	{ 196, 12 },   /* McuI2c3IoIsr */
	{ 197, 13 },   /* McuI2c0PmicIsr */
	{ 138, 14 },   /* Gpt_Ch3Isr */
	{ 139, 16 },   /* Gpt_Ch4Isr */
	{ 106, 15 },   /* PmicCdd_nINTGpioInterrupt */
	{ 242, 11 },   /* Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 */
    { 0, 0 }  /* Dummy element to avoid empty array */
};

#pragma clang section rodata    = ".osFiqVecTab"



const osVoidFunctionType osFIQTable[osdNumberOfFIQs] =
{
    osISRUnhandledException,        /* #0:not configured */
    osISRUnhandledException,        /* #1:not configured */
    osISRUnhandledException,        /* #2:not configured */
    osISRUnhandledException,        /* #3:not configured */
    osISRUnhandledException,        /* #4:not configured */
    osISRUnhandledException,        /* #5:not configured */
    osISRUnhandledException,        /* #6:not configured */
    osISRUnhandledException,        /* #7:not configured */
    osISRUnhandledException,        /* #8:not configured */
    osISRUnhandledException,        /* #9:not configured */
    osISRUnhandledException,        /* #10:not configured */
    osISRUnhandledException,        /* #11:not configured */
    osISRUnhandledException,        /* #12:not configured */
    osISRUnhandledException,        /* #13:not configured */
    osISRUnhandledException,        /* #14:not configured */
    osISRUnhandledException,        /* #15:not configured */
    osISRUnhandledException,        /* #16:not configured */
    osISRUnhandledException,        /* #17:not configured */
    osISRUnhandledException,        /* #18:not configured */
    osISRUnhandledException,        /* #19:not configured */
    osISRUnhandledException,        /* #20:not configured */
    osISRUnhandledException,        /* #21:not configured */
    osISRUnhandledException,        /* #22:not configured */
    osISRUnhandledException,        /* #23:not configured */
    osISRUnhandledException,        /* #24:not configured */
    osISRUnhandledException,        /* #25:not configured */
    osISRUnhandledException,        /* #26:not configured */
    osISRUnhandledException,        /* #27:not configured */
    osISRUnhandledException,        /* #28:not configured */
    osISRUnhandledException,        /* #29:not configured */
    osISRUnhandledException,        /* #30:not configured */
    osISRUnhandledException        /* #31:not configured */
};


#pragma clang section rodata    = ".osconst"

const osIntPrioType osFIQPrioTable[1] =
{
{ 0, 0 }, /* Dummy element to avoid empty array */
};


#pragma clang section rodata    = ".osArmExcVecTab"

const osVoidFunctionType osExceptionTable[osdNumberOfExceptions] =
{
osISRUnhandledException,
osUndefinedInstructionException,
osSVCHandlerAsm,
osMemProtectionFault,
osDataAbortHandler,
osISRUnhandledException,
osISRUnhandledException,
osISRUnhandledException
};



#define osVIMHoldClear(x)       ({\
                                  volatile osuint32 *RegAddr;\
                                  osuint32 BitPos;\
                                  osuint32 IntrNum = osIsrIdTable[x];\
                                  RegAddr  = (volatile osuint32 *)osVIM_GET_STSHWADDR(IntrNum);\
                                  BitPos   = osVIM_BIT_POS(IntrNum);\
                                  *RegAddr = (volatile osuint32)( 0x1u << BitPos);\
                                  osVIM_IRQVECADDR = IntrNum;\
                                 })


#pragma clang section rodata    = ".osconst"
#pragma clang section text      = ".oscode"
CLANG_CAT2_INTERRUPT void osCallISRHooks_McuOsGptIsr(void)
{
    OsPreISRHook(0);
    osTimerInterruptfunc();
    OsPostISRHook(0);
    osVIMHoldClear(0);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_McuCan0RxTxIsr(void)
{
    OsPreISRHook(1);
    Can_0_Int0ISRfunc();
    OsPostISRHook(1);
    osVIMHoldClear(1);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_McuCan1RxTxIsr(void)
{
    OsPreISRHook(2);
    Can_1_Int0ISRfunc();
    OsPostISRHook(2);
    osVIMHoldClear(2);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_McuI2c3IoIsr(void)
{
    OsPreISRHook(3);
    McuI2c3IoIsrfunc();
    OsPostISRHook(3);
    osVIMHoldClear(3);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_McuI2c0PmicIsr(void)
{
    OsPreISRHook(4);
    McuI2c0PmicIsrfunc();
    OsPostISRHook(4);
    osVIMHoldClear(4);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Gpt_Ch3Isr(void)
{
    OsPreISRHook(5);
    Gpt_Ch3Isrfunc();
    OsPostISRHook(5);
    osVIMHoldClear(5);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Gpt_Ch4Isr(void)
{
    OsPreISRHook(6);
    Gpt_Ch4Isrfunc();
    OsPostISRHook(6);
    osVIMHoldClear(6);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_PmicCdd_nINTGpioInterrupt(void)
{
    OsPreISRHook(7);
    PmicCdd_nINTGpioInterruptfunc();
    OsPostISRHook(7);
    osVIMHoldClear(7);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0(void)
{
    OsPreISRHook(8);
    Cdd_IpcIrqMbxFromWKUP_R5FSS0_0();
    OsPostISRHook(8);
    osVIMHoldClear(8);
}


void osSetupConfiguredInterrupts(void)
{
    osuint32 i;
    for (i=0; i<osdNumberOfConfiguredIRQs; i++)
    {
        osuint16 isrnum=osIRQPrioTable[i].osIPNumber;
        osVIM_INT_EN(isrnum)   = 1UL<<(isrnum&31);   /* enable the interrupt */
    }
}

#pragma clang section text     = ""
#pragma clang section rodata   = ""
#pragma clang section data     = ""
#pragma clang section bss      = ""



		#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

