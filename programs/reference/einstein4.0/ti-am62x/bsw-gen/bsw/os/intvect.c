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
*    Auto generated code in vAUTOSAR TOOL by SGOPAL1 at 2026-03-31 13:17:24.328626600
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
    osISRWrap_FltM_FwlExceptionInterrupt,        /* #20:FltM_FwlExceptionInterrupt */
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
    osISRWrap_MAIN_ISR_34,        /* #32:MAIN_ISR_34 */
    osISRWrap_MAIN_ISR_35,        /* #33:MAIN_ISR_35 */
    osISRUnhandledException,        /* #34:not configured */
    osISRUnhandledException,        /* #35:not configured */
    osISRUnhandledException,        /* #36:not configured */
    osISRUnhandledException,        /* #37:not configured */
    osISRUnhandledException,        /* #38:not configured */
    osISRUnhandledException,        /* #39:not configured */
    osISRWrap_McuDss0Isr,        /* #40:McuDss0Isr */
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
    osISRWrap_Mcu_Udma_Vintr64,        /* #64:Mcu_Udma_Vintr64 */
    osISRWrap_Mcu_Udma_Vintr65,        /* #65:Mcu_Udma_Vintr65 */
    osISRWrap_Eth_TxIrqHdlr_0,        /* #66:Eth_TxIrqHdlr_0 */
    osISRWrap_Eth_RxIrqHdlr_0,        /* #67:Eth_RxIrqHdlr_0 */
    osISRWrap_Mcu_Udma_Vintr68,        /* #68:Mcu_Udma_Vintr68 */
    osISRWrap_Mcu_Udma_Vintr69,        /* #69:Mcu_Udma_Vintr69 */
    osISRWrap_Mcu_Udma_Vintr70,        /* #70:Mcu_Udma_Vintr70 */
    osISRWrap_Mcu_Udma_Vintr71,        /* #71:Mcu_Udma_Vintr71 */
    osISRWrap_Mcu_Udma_Vintr72,        /* #72:Mcu_Udma_Vintr72 */
    osISRWrap_Mcu_Udma_Vintr73,        /* #73:Mcu_Udma_Vintr73 */
    osISRWrap_Mcu_Udma_Vintr74,        /* #74:Mcu_Udma_Vintr74 */
    osISRWrap_Mcu_Udma_Vintr75,        /* #75:Mcu_Udma_Vintr75 */
    osISRWrap_Mcu_Udma_Vintr76,        /* #76:Mcu_Udma_Vintr76 */
    osISRWrap_Mcu_Udma_Vintr77,        /* #77:Mcu_Udma_Vintr77 */
    osISRWrap_Mcu_Udma_Vintr78,        /* #78:Mcu_Udma_Vintr78 */
    osISRWrap_Mcu_Udma_Vintr79,        /* #79:Mcu_Udma_Vintr79 */
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
    osISRWrap_MCU_ResetIsolationReq,        /* #101:MCU_ResetIsolationReq */
    osISRUnhandledException,        /* #102:not configured */
    osISRUnhandledException,        /* #103:not configured */
    osISRUnhandledException,        /* #104:not configured */
    osISRUnhandledException,        /* #105:not configured */
    osISRWrap_MCU_ISR_6,        /* #106:MCU_ISR_6 */
    osISRWrap_MCU_ISR_7,        /* #107:MCU_ISR_7 */
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
    osISRWrap_Eth_MdioIrqHdlr,        /* #135:Eth_MdioIrqHdlr */
    osISRUnhandledException,        /* #136:not configured */
    osISRUnhandledException,        /* #137:not configured */
    osISRWrap_Gpt_Ch3Isr,        /* #138:Gpt_Ch3Isr */
    osISRWrap_Gpt_Ch4Isr,        /* #139:Gpt_Ch4Isr */
    osISRWrap_FltM_WkupEsmCfgInterrupt,        /* #140:FltM_WkupEsmCfgInterrupt */
    osISRWrap_FltM_WkupEsmHiInterrupt,        /* #141:FltM_WkupEsmHiInterrupt */
    osISRWrap_FltM_WkupEsmLowInterrupt,        /* #142:FltM_WkupEsmLowInterrupt */
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
    osISRWrap_MainI2c1DacIsr,        /* #194:MainI2c1DacIsr */
    osISRWrap_MainI2c2RtcIsr,        /* #195:MainI2c2RtcIsr */
    osISRWrap_McuI2c3IoIsr,        /* #196:McuI2c3IoIsr */
    osISRWrap_McuI2c0PmicIsr,        /* #197:McuI2c0PmicIsr */
    osISRUnhandledException,        /* #198:not configured */
    osISRUnhandledException,        /* #199:not configured */
    osISRUnhandledException,        /* #200:not configured */
    osISRUnhandledException,        /* #201:not configured */
    osISRUnhandledException,        /* #202:not configured */
    osISRUnhandledException,        /* #203:not configured */
    osISRWrap_Spi_IrqUnitMcspi0TxRx,        /* #204:Spi_IrqUnitMcspi0TxRx */
    osISRUnhandledException,        /* #205:not configured */
    osISRWrap_Spi_IrqUnitMcspi2TxRx,        /* #206:Spi_IrqUnitMcspi2TxRx */
    osISRWrap_McuSpi0NvmRxTxIsr,        /* #207:McuSpi0NvmRxTxIsr */
    osISRUnhandledException,        /* #208:not configured */
    osISRUnhandledException,        /* #209:not configured */
    osISRUnhandledException,        /* #210:not configured */
    osISRUnhandledException,        /* #211:not configured */
    osISRUnhandledException,        /* #212:not configured */
    osISRUnhandledException,        /* #213:not configured */
    osISRUnhandledException,        /* #214:not configured */
    osISRUnhandledException,        /* #215:not configured */
    osISRUnhandledException,        /* #216:not configured */
    osISRWrap_MCU_IntrISR_UART0,        /* #217:MCU_IntrISR_UART0 */
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
	207U,   /* McuSpi0NvmRxTxIsr */
	40U,   /* McuDss0Isr */
	196U,   /* McuI2c3IoIsr */
	66U,   /* Eth_TxIrqHdlr_0 */
	67U,   /* Eth_RxIrqHdlr_0 */
	135U,   /* Eth_MdioIrqHdlr */
	141U,   /* FltM_WkupEsmHiInterrupt */
	217U,   /* MCU_IntrISR_UART0 */
	197U,   /* McuI2c0PmicIsr */
	138U,   /* Gpt_Ch3Isr */
	139U,   /* Gpt_Ch4Isr */
	206U,   /* Spi_IrqUnitMcspi2TxRx */
	106U,   /* MCU_ISR_6 */
	32U,   /* MAIN_ISR_34 */
	33U,   /* MAIN_ISR_35 */
	107U,   /* MCU_ISR_7 */
	140U,   /* FltM_WkupEsmCfgInterrupt */
	142U,   /* FltM_WkupEsmLowInterrupt */
	204U,   /* Spi_IrqUnitMcspi0TxRx */
	195U,   /* MainI2c2RtcIsr */
	101U,   /* MCU_ResetIsolationReq */
	20U,   /* FltM_FwlExceptionInterrupt */
	242U,   /* Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 */
	64U,   /* Mcu_Udma_Vintr64 */
	65U,   /* Mcu_Udma_Vintr65 */
	66U,   /* Mcu_Udma_Vintr66 */
	67U,   /* Mcu_Udma_Vintr67 */
	68U,   /* Mcu_Udma_Vintr68 */
	69U,   /* Mcu_Udma_Vintr69 */
	70U,   /* Mcu_Udma_Vintr70 */
	71U,   /* Mcu_Udma_Vintr71 */
	72U,   /* Mcu_Udma_Vintr72 */
	73U,   /* Mcu_Udma_Vintr73 */
	74U,   /* Mcu_Udma_Vintr74 */
	75U,   /* Mcu_Udma_Vintr75 */
	76U,   /* Mcu_Udma_Vintr76 */
	77U,   /* Mcu_Udma_Vintr77 */
	78U,   /* Mcu_Udma_Vintr78 */
	79U,   /* Mcu_Udma_Vintr79 */
	194U,   /* MainI2c1DacIsr */
    0U  /* ISR osSystemCat2ISR */
};


const osIntPrioType osIRQPrioTable[osdNumberOfConfiguredIRQs+1] =
{
	{ 28, 0 },   /* McuOsGptIsr */
	{ 43, 1 },   /* McuCan0RxTxIsr */
	{ 46, 2 },   /* McuCan1RxTxIsr */
	{ 207, 6 },   /* McuSpi0NvmRxTxIsr */
	{ 40, 8 },   /* McuDss0Isr */
	{ 196, 12 },   /* McuI2c3IoIsr */
	{ 66, 8 },   /* Eth_TxIrqHdlr_0 */
	{ 67, 9 },   /* Eth_RxIrqHdlr_0 */
	{ 135, 12 },   /* Eth_MdioIrqHdlr */
	{ 141, 9 },   /* FltM_WkupEsmHiInterrupt */
	{ 217, 17 },   /* MCU_IntrISR_UART0 */
	{ 197, 13 },   /* McuI2c0PmicIsr */
	{ 138, 14 },   /* Gpt_Ch3Isr */
	{ 139, 16 },   /* Gpt_Ch4Isr */
	{ 206, 21 },   /* Spi_IrqUnitMcspi2TxRx */
	{ 106, 15 },   /* MCU_ISR_6 */
	{ 32, 18 },   /* MAIN_ISR_34 */
	{ 33, 19 },   /* MAIN_ISR_35 */
	{ 107, 20 },   /* MCU_ISR_7 */
	{ 140, 10 },   /* FltM_WkupEsmCfgInterrupt */
	{ 142, 11 },   /* FltM_WkupEsmLowInterrupt */
	{ 204, 22 },   /* Spi_IrqUnitMcspi0TxRx */
	{ 195, 23 },   /* MainI2c2RtcIsr */
	{ 101, 24 },   /* MCU_ResetIsolationReq */
	{ 20, 25 },   /* FltM_FwlExceptionInterrupt */
	{ 242, 26 },   /* Cdd_IpcIrqMbxFromWKUP_R5FSS0_0 */
	{ 64, 27 },   /* Mcu_Udma_Vintr64 */
	{ 65, 28 },   /* Mcu_Udma_Vintr65 */
	{ 66, 29 },   /* Mcu_Udma_Vintr66 */
	{ 67, 30 },   /* Mcu_Udma_Vintr67 */
	{ 68, 31 },   /* Mcu_Udma_Vintr68 */
	{ 69, 32 },   /* Mcu_Udma_Vintr69 */
	{ 70, 33 },   /* Mcu_Udma_Vintr70 */
	{ 71, 34 },   /* Mcu_Udma_Vintr71 */
	{ 72, 35 },   /* Mcu_Udma_Vintr72 */
	{ 73, 36 },   /* Mcu_Udma_Vintr73 */
	{ 74, 37 },   /* Mcu_Udma_Vintr74 */
	{ 75, 38 },   /* Mcu_Udma_Vintr75 */
	{ 76, 39 },   /* Mcu_Udma_Vintr76 */
	{ 77, 40 },   /* Mcu_Udma_Vintr77 */
	{ 78, 41 },   /* Mcu_Udma_Vintr78 */
	{ 79, 42 },   /* Mcu_Udma_Vintr79 */
	{ 194, 43 },   /* MainI2c1DacIsr */
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

CLANG_CAT2_INTERRUPT void osCallISRHooks_McuSpi0NvmRxTxIsr(void)
{
    OsPreISRHook(3);
    Spi_IrqUnitMcuMcspi0TxRxfunc();
    OsPostISRHook(3);
    osVIMHoldClear(3);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_McuDss0Isr(void)
{
    OsPreISRHook(4);
    Dss_0_Isrfunc();
    OsPostISRHook(4);
    osVIMHoldClear(4);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_McuI2c3IoIsr(void)
{
    OsPreISRHook(5);
    McuI2c3IoIsrfunc();
    OsPostISRHook(5);
    osVIMHoldClear(5);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Eth_TxIrqHdlr_0(void)
{
    OsPreISRHook(6);
    Eth_TxIrqHdlr_0func();
    OsPostISRHook(6);
    osVIMHoldClear(6);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Eth_RxIrqHdlr_0(void)
{
    OsPreISRHook(7);
    Eth_RxIrqHdlr_0func();
    OsPostISRHook(7);
    osVIMHoldClear(7);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Eth_MdioIrqHdlr(void)
{
    OsPreISRHook(8);
    Eth_MdioIrqHdlrfunc();
    OsPostISRHook(8);
    osVIMHoldClear(8);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_FltM_WkupEsmHiInterrupt(void)
{
    OsPreISRHook(9);
    FltM_WkupEsmHiInterruptfunc();
    OsPostISRHook(9);
    osVIMHoldClear(9);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_MCU_IntrISR_UART0(void)
{
    OsPreISRHook(10);
    MCU_IntrISR_UART0func();
    OsPostISRHook(10);
    osVIMHoldClear(10);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_McuI2c0PmicIsr(void)
{
    OsPreISRHook(11);
    McuI2c0PmicIsrfunc();
    OsPostISRHook(11);
    osVIMHoldClear(11);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Gpt_Ch3Isr(void)
{
    OsPreISRHook(12);
    Gpt_Ch3Isrfunc();
    OsPostISRHook(12);
    osVIMHoldClear(12);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Gpt_Ch4Isr(void)
{
    OsPreISRHook(13);
    Gpt_Ch4Isrfunc();
    OsPostISRHook(13);
    osVIMHoldClear(13);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Spi_IrqUnitMcspi2TxRx(void)
{
    OsPreISRHook(14);
    Spi_IrqUnitMcspi2TxRxfunc();
    OsPostISRHook(14);
    osVIMHoldClear(14);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_MCU_ISR_6(void)
{
    OsPreISRHook(15);
    MCU_ISR_6func();
    OsPostISRHook(15);
    osVIMHoldClear(15);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_MAIN_ISR_34(void)
{
    OsPreISRHook(16);
    MAIN_ISR_34func();
    OsPostISRHook(16);
    osVIMHoldClear(16);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_MAIN_ISR_35(void)
{
    OsPreISRHook(17);
    MAIN_ISR_35func();
    OsPostISRHook(17);
    osVIMHoldClear(17);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_MCU_ISR_7(void)
{
    OsPreISRHook(18);
    MCU_ISR_7func();
    OsPostISRHook(18);
    osVIMHoldClear(18);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_FltM_WkupEsmCfgInterrupt(void)
{
    OsPreISRHook(19);
    FltM_WkupEsmCfgInterruptfunc();
    OsPostISRHook(19);
    osVIMHoldClear(19);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_FltM_WkupEsmLowInterrupt(void)
{
    OsPreISRHook(20);
    FltM_WkupEsmLowInterruptfunc();
    OsPostISRHook(20);
    osVIMHoldClear(20);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Spi_IrqUnitMcspi0TxRx(void)
{
    OsPreISRHook(21);
    Spi_IrqUnitMcspi0TxRxfunc();
    OsPostISRHook(21);
    osVIMHoldClear(21);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_MainI2c2RtcIsr(void)
{
    OsPreISRHook(22);
    MainI2c2RtcIsrfunc();
    OsPostISRHook(22);
    osVIMHoldClear(22);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_MCU_ResetIsolationReq(void)
{
    OsPreISRHook(23);
    MCU_ResetIsolationReqfunc();
    OsPostISRHook(23);
    osVIMHoldClear(23);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_FltM_FwlExceptionInterrupt(void)
{
    OsPreISRHook(24);
    FltM_FwlExceptionInterruptfunc();
    OsPostISRHook(24);
    osVIMHoldClear(24);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Cdd_IpcIrqMbxFromWKUP_R5FSS0_0(void)
{
    OsPreISRHook(25);
    Cdd_IpcIrqMbxFromWKUP_R5FSS0_0func();
    OsPostISRHook(25);
    osVIMHoldClear(25);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr64(void)
{
    OsPreISRHook(26);
    Mcu_Udma_Vintr64func();
    OsPostISRHook(26);
    osVIMHoldClear(26);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr65(void)
{
    OsPreISRHook(27);
    Mcu_Udma_Vintr65func();
    OsPostISRHook(27);
    osVIMHoldClear(27);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr66(void)
{
    OsPreISRHook(28);
    Mcu_Udma_Vintr66func();
    OsPostISRHook(28);
    osVIMHoldClear(28);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr67(void)
{
    OsPreISRHook(29);
    Mcu_Udma_Vintr67func();
    OsPostISRHook(29);
    osVIMHoldClear(29);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr68(void)
{
    OsPreISRHook(30);
    Mcu_Udma_Vintr68func();
    OsPostISRHook(30);
    osVIMHoldClear(30);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr69(void)
{
    OsPreISRHook(31);
    Mcu_Udma_Vintr69func();
    OsPostISRHook(31);
    osVIMHoldClear(31);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr70(void)
{
    OsPreISRHook(32);
    Mcu_Udma_Vintr70func();
    OsPostISRHook(32);
    osVIMHoldClear(32);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr71(void)
{
    OsPreISRHook(33);
    Mcu_Udma_Vintr71func();
    OsPostISRHook(33);
    osVIMHoldClear(33);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr72(void)
{
    OsPreISRHook(34);
    Mcu_Udma_Vintr72func();
    OsPostISRHook(34);
    osVIMHoldClear(34);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr73(void)
{
    OsPreISRHook(35);
    Mcu_Udma_Vintr73func();
    OsPostISRHook(35);
    osVIMHoldClear(35);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr74(void)
{
    OsPreISRHook(36);
    Mcu_Udma_Vintr74func();
    OsPostISRHook(36);
    osVIMHoldClear(36);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr75(void)
{
    OsPreISRHook(37);
    Mcu_Udma_Vintr75func();
    OsPostISRHook(37);
    osVIMHoldClear(37);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr76(void)
{
    OsPreISRHook(38);
    Mcu_Udma_Vintr76func();
    OsPostISRHook(38);
    osVIMHoldClear(38);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr77(void)
{
    OsPreISRHook(39);
    Mcu_Udma_Vintr77func();
    OsPostISRHook(39);
    osVIMHoldClear(39);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr78(void)
{
    OsPreISRHook(40);
    Mcu_Udma_Vintr78func();
    OsPostISRHook(40);
    osVIMHoldClear(40);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_Mcu_Udma_Vintr79(void)
{
    OsPreISRHook(41);
    Mcu_Udma_Vintr79func();
    OsPostISRHook(41);
    osVIMHoldClear(41);
}

CLANG_CAT2_INTERRUPT void osCallISRHooks_MainI2c1DacIsr(void)
{
    OsPreISRHook(42);
    MainI2c1DacIsrfunc();
    OsPostISRHook(42);
    osVIMHoldClear(42);
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

