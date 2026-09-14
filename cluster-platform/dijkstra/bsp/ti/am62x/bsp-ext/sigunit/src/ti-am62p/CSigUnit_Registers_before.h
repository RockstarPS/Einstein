/*============================================================================
 **
 **  \file CSigUnit_Registers.h
 **
 **  \brief Interface to interact with the Signature Unit of iMX8
 **
 **  This file provides functional defines for a Signature Unit module
 **
 **  Component Name: Signature Unit
 **  Archive:
 **  Date: May 11 2020
 **  Author: Dinakar Babu
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/


#ifndef SIGUNIT_REGISTERS_H
#define SIGUNIT_REGISTERS_H

#define MM_IO_SEERIS_BASE       0x56180000
#define MM_IO_SEERIS_SIZE       0x3FFFF

#define SIG_UNIT_0_REG_BASE     MM_IO_SEERIS_BASE + 0xD000  //0xD000 - 0xD13C
#define SIG_UNIT_1_REG_BASE     MM_IO_SEERIS_BASE + 0xEC00  //0xEC00 - 0xED3C
#define SIG_UNIT_REG_SIZE       0x140  //0x13C

/* DISENG_DISENGCFG_SRCSELECT0: Tap selection for Signature and Frame Dump (display stream 0). */
#define     DISENG_DISENGCFG_SRCSELECT0 0x0000B410u
#define     DISENG_DISENGCFG_SIG_SELECT0_FRAMEGEN 0x0 /* Source is FrameGen#0 output. */
#define     DISENG_DISENGCFG_SIG_SELECT0_GAMMACOR 0x1 /* Source is GammaCor#0 output. */
#define     DISENG_DISENGCFG_SIG_SELECT0_MATRIX 0x2 /* Source is Matrix#0 output. */
#define     DISENG_DISENGCFG_SIG_SELECT0_DITHER 0x3 /* Source is Dither#0 output. */

/* DISENG_DISENGCFG_SRCSELECT1: Tap selection for Signature and Frame Dump (display stream 1). */
#define     DISENG_DISENGCFG_SRCSELECT1 0x0000B430u
#define     DISENG_DISENGCFG_SIG_SELECT1_FRAMEGEN 0x0 /* Source is FrameGen#1 output. */
#define     DISENG_DISENGCFG_SIG_SELECT1_GAMMACOR 0x1 /* Source is GammaCor#1 output. */
#define     DISENG_DISENGCFG_SIG_SELECT1_MATRIX 0x2 /* Source is Matrix#1 output. */
#define     DISENG_DISENGCFG_SIG_SELECT1_DITHER 0x3 /* Source is Dither#1 output. */

/* Signature Unit 0 and 1*/

#define    DISENG_SIG_LOCKUNLOCK (uint32_t) 0x00 		/*Register to change the protection status of this address block. (sig*_LockUnlock)*/
/* SIG*_LOCKUNLOCK Register values */
#define     DISENG_SIG_LOCKUNLOCK_lock_key 0x5651F763u /* Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1. */
#define     DISENG_SIG_LOCKUNLOCK_unlock_key 0x691DB936u /* Increments the unlock counter. Max allowed value is 15. */
#define     DISENG_SIG_LOCKUNLOCK_privilege_key 0xAEE95CDCu /* Enables privilege protection. Disabled after reset. */
#define     DISENG_SIG_LOCKUNLOCK_unprivilege_key 0xB5E2466Eu /* Disables privilege protection. */
#define     DISENG_SIG_LOCKUNLOCK_freeze_key 0xFBE8B1E6u /* Freezes current protection status. Writing keys to this register has no more effect until reset. */

#define    DISENG_SIG_LOCKSTATUS 0x04 		/*Protection status of this address block. (sig*_LockStatus)*/
/* SIG*_LOCKSTATUS Register values */
#define     INACTIVE_DISENG_SIG_LOCKSTATUS_RESET 0x0uL  	/*BIT Location : 0; Current status of lock protection: 0 = inactive (unlock counter > 0), 1 = active (unlock counter == 0).*/
#define     ACTIVE_DISENG_SIG_LOCKSTATUS_RESET 0x1uL
#define     INACTIVE_DISENG_SIG_PRIVILEGESTATUS_RESET 0x0uL	/*BIT Location : 4; Current status of privilege protection: 0 = inactive , 1 = active. */
#define     ACTIVE_DISENG_SIG_PRIVILEGESTATUS_RESET (0x1uL << 4)
#define     CHANGED_DISENG_SIG_FREEZESTATUS_RESET 0x0uL 	/*BIT Location : 8; Current freeze status: 0 = protection status can be changed, 1 = cannot be changed. */
#define     NOT_CHANGED_DISENG_SIG_FREEZESTATUS_RESET (0x1uL << 8)

#define    DISENG_SIG_STATICCONTROL 0x08 	/*Global configuration shared by all evaluation windows. (sig*_StaticControl)*/
/* SIG*_STATICCONTROL Register values */
#define     DISENG_SIG_SHDEN_RESET 0x0uL   /*SHDEN: Enables shadow registers for RWS type fields (0 = write through, 1 = shadowed). */
/*SHDLDSEL: Source select for events that will load shadow registers into the active configuration. */
#define     DISENG_SIG_SHDLDSEL_LOCAL (0x0 << 4) /* Shadows are loaded at start of frame for each evaluation window for which ShdLdReq has been set. */
#define     DISENG_SIG_SHDLDSEL_GLOBAL (0x1 << 4)	/* Shadows of all evaluation windows are loaded synchronous to the display stream (shadow load token received on frame input port). */
#define     DISENG_SIG_SHDLDSEL_RESET 0x0uL
#define     DISENG_SIG_ERRTHRES_SHIFT (0x0 << 16) /*ERRTHRES: Number of frames with signature violation before StsSigError is set for an evaluation window. */
#define     DISENG_SIG_ERRTHRES_MASK 0xffuL
#define     DISENG_SIG_ERRTHRESRESET_RESET (0x8uL << 24) /*ERRTHRESRESET: Number of consecutive frames without signature violation before StsSigError is reset for an evaluation window. */

#define    DISENG_SIG_PANICCOLOR 0x0C 		/*Overlay color for evaluation windows in panic mode. (sig*_PanicColor)*/
/* SIG*_PANICCOLOR Register values */
#define      DISENG_SIG_PANICALPHA_RESET (0x0uL << 7)	/*Alpha mask bit. */
#define      DISENG_SIG_PANICBLUE_RESET (0x0uL << 8)	/*Blue color component. */
#define      DISENG_SIG_PANICGREEN_RESET (0x0uL << 16) 	/*Green color component. */
#define      DISENG_SIG_PANICRED_RESET (0x0uL << 24)	/*Red color component. */

/*WINDOW 0 for both Signature Unit 0 & 1*/
#define    DISENG_SIG_EVALCONTROL0 0x10u 	/*Control settings for evaluation window 0. (sig*_EvalControl0)*/
#define    DISENG_SIG_EVALUPPERLEFT0 0x14u 	/*Upper left corner of evaluation window 0. (sig*_EvalUpperLeft0)*/
#define    DISENG_SIG_EVALLOWERRIGHT0 0x18u 	/*Lower right corner of evaluation window 0. (sig*_EvalLowerRight0)*/
#define    DISENG_SIG_SIGCRCREDREF0 0x1C 	/*Reference signature of red channel for evaluation window 0. (sig*_SigCRCRedRef0)*/
#define    DISENG_SIG_SIGCRCGREENREF0 0x20 	/*Reference signature of green channel for evaluation window 0. (sig*_SigCRCGreenRef0)*/
#define    DISENG_SIG_SIGCRCBLUEREF0 0x24 	/*Reference signature of blue channel for evaluation window 0. (sig*_SigCRCBlueRef0)*/
#define    DISENG_SIG_SIGCRCRED0 0x28 		/*Measured signature of red channel for evaluation window 0. (sig*_SigCRCRed0)*/
#define    DISENG_SIG_SIGCRCGREEN0 0x2C 	/*Measured signature of green channel for evaluation window 0. (sig*_SigCRCGreen0)*/
#define    DISENG_SIG_SIGCRCBLUE0 0x30 		/*Measured signature of blue channel for evaluation window 0. (sig*_SigCRCBlue0)*/

/*WINDOW 1 for both Signature Unit 0 & 1*/
#define    DISENG_SIG_EVALCONTROL1 0x34 	/*Control settings for evaluation window 1. (sig*_EvalControl1)*/
#define    DISENG_SIG_EVALUPPERLEFT1 0x38 	/*Upper left corner of evaluation window 1. (sig*_EvalUpperLeft1)*/
#define    DISENG_SIG_EVALLOWERRIGHT1 0x3C 	/*Lower right corner of evaluation window 1. (sig*_EvalLowerRight1)*/
#define    DISENG_SIG_SIGCRCREDREF1 0x40 	/*Reference signature of red channel for evaluation window 1. (sig*_SigCRCRedRef1)*/
#define    DISENG_SIG_SIGCRCGREENREF1 0x44 	/*Reference signature of green channel for evaluation window 1. (sig*_SigCRCGreenRef1)*/
#define    DISENG_SIG_SIGCRCBLUEREF1 0x48 	/*Reference signature of blue channel for evaluation window 1. (sig*_SigCRCBlueRef1)*/
#define    DISENG_SIG_SIGCRCRED1 0x4C 		/*Measured signature of red channel for evaluation window 1. (sig*_SigCRCRed1)*/
#define    DISENG_SIG_SIGCRCGREEN1 0x50 	/*Measured signature of green channel for evaluation window 1. (sig*_SigCRCGreen1)*/
#define    DISENG_SIG_SIGCRCBLUE1 0x54 		/*Measured signature of blue channel for evaluation window 1. (sig*_SigCRCBlue1)*/

/*WINDOW 2 for both Signature Unit 0 & 1*/
#define    DISENG_SIG_EVALCONTROL2 0x58 	/*Control settings for evaluation window 2. (sig*_EvalControl2)*/
#define    DISENG_SIG_EVALUPPERLEFT2 0x5C 	/*Upper left corner of evaluation window 2. (sig*_EvalUpperLeft2)*/
#define    DISENG_SIG_EVALLOWERRIGHT2 0x60	/*Lower right corner of evaluation window 2. (sig*_EvalLowerRight2)*/
#define    DISENG_SIG_SIGCRCREDREF2 0x64 	/*Reference signature of red channel for evaluation window 2. (sig*_SigCRCRedRef2)*/
#define    DISENG_SIG_SIGCRCGREENREF2 0x68 	/*Reference signature of green channel for evaluation window 2. (sig*_SigCRCGreenRef2)*/
#define    DISENG_SIG_SIGCRCBLUEREF2 0x6C 	/*Reference signature of blue channel for evaluation window 2. (sig*_SigCRCBlueRef2)*/
#define    DISENG_SIG_SIGCRCRED2 0x70 		/*Measured signature of red channel for evaluation window 2. (sig*_SigCRCRed2)*/
#define    DISENG_SIG_SIGCRCGREEN2 0x74 	/*Measured signature of green channel for evaluation window 2. (sig*_SigCRCGreen2)*/
#define    DISENG_SIG_SIGCRCBLUE2 0x78 		/*Measured signature of blue channel for evaluation window 2. (sig*_SigCRCBlue2)*/

/*WINDOW 3 for both Signature Unit 0 & 1*/
#define    DISENG_SIG_EVALCONTROL3 0x7C 	/*Control settings for evaluation window 3. (sig*_EvalControl3)*/
#define    DISENG_SIG_EVALUPPERLEFT3 0x80 	/*Upper left corner of evaluation window 3. (sig*_EvalUpperLeft3)*/
#define    DISENG_SIG_EVALLOWERRIGHT3 0x84 	/*Lower right corner of evaluation window 3. (sig*_EvalLowerRight3)*/
#define    DISENG_SIG_SIGCRCREDREF3 0x88 	/*Reference signature of red channel for evaluation window 3. (sig*_SigCRCRedRef3)*/
#define    DISENG_SIG_SIGCRCGREENREF3 0x8C 	/*Reference signature of green channel for evaluation window 3. (sig*_SigCRCGreenRef3)*/
#define    DISENG_SIG_SIGCRCBLUEREF3 0x90 	/*Reference signature of blue channel for evaluation window 3. (sig*_SigCRCBlueRef3)*/
#define    DISENG_SIG_SIGCRCRED3 0x94 		/*Measured signature of red channel for evaluation window 3. (sig*_SigCRCRed3)*/
#define    DISENG_SIG_SIGCRCGREEN3 0x98 	/*Measured signature of green channel for evaluation window 3. (sig*_SigCRCGreen3)*/
#define    DISENG_SIG_SIGCRCBLUE3 0x9C 		/*Measured signature of blue channel for evaluation window 3. (sig*_SigCRCBlue3)*/

/*WINDOW 4 for both Signature Unit 0 & 1*/
#define    DISENG_SIG_EVALCONTROL4 0xA0 	/*Control settings for evaluation window 4. (sig*_EvalControl4)*/
#define    DISENG_SIG_EVALUPPERLEFT4 0xA4 	/*Upper left corner of evaluation window 4. (sig*_EvalUpperLeft4)*/
#define    DISENG_SIG_EVALLOWERRIGHT4 0xA8 	/*Lower right corner of evaluation window 4. (sig*_EvalLowerRight4)*/
#define    DISENG_SIG_SIGCRCREDREF4 0xAC 	/*Reference signature of red channel for evaluation window 4. (sig*_SigCRCRedRef4)*/
#define    DISENG_SIG_SIGCRCGREENREF4 0xB0 	/*Reference signature of green channel for evaluation window 4. (sig*_SigCRCGreenRef4)*/
#define    DISENG_SIG_SIGCRCBLUEREF4 0xB4 	/*Reference signature of blue channel for evaluation window 4. (sig*_SigCRCBlueRef4)*/
#define    DISENG_SIG_SIGCRCRED4 0xB8 		/*Measured signature of red channel for evaluation window 4. (sig*_SigCRCRed4)*/
#define    DISENG_SIG_SIGCRCGREEN4 0xBC 	/*Measured signature of green channel for evaluation window 4. (sig*_SigCRCGreen4)*/
#define    DISENG_SIG_SIGCRCBLUE4 0xC0 		/*Measured signature of blue channel for evaluation window 4. (sig*_SigCRCBlue4)*/

/*WINDOW 5 for both Signature Unit 0 & 1*/
#define    DISENG_SIG_EVALCONTROL5 0xC4 	/*Control settings for evaluation window 5. (sig*_EvalControl5)*/
#define    DISENG_SIG_EVALUPPERLEFT5 0xC8 	/*Upper left corner of evaluation window 5. (sig*_EvalUpperLeft5)*/
#define    DISENG_SIG_EVALLOWERRIGHT5 0xCC 	/*Lower right corner of evaluation window 5. (sig*_EvalLowerRight5)*/
#define    DISENG_SIG_SIGCRCREDREF5 0xD0 	/*Reference signature of red channel for evaluation window 5. (sig*_SigCRCRedRef5)*/
#define    DISENG_SIG_SIGCRCGREENREF5 0xD4 	/*Reference signature of green channel for evaluation window 5. (sig*_SigCRCGreenRef5)*/
#define    DISENG_SIG_SIGCRCBLUEREF5 0xD8 	/*Reference signature of blue channel for evaluation window 5. (sig*_SigCRCBlueRef5)*/
#define    DISENG_SIG_SIGCRCRED5 0xDC 		/*Measured signature of red channel for evaluation window 5. (sig*_SigCRCRed5)*/
#define    DISENG_SIG_SIGCRCGREEN5 0xE0 	/*Measured signature of green channel for evaluation window 5. (sig*_SigCRCGreen5)*/
#define    DISENG_SIG_SIGCRCBLUE5 0xE4 		/*Measured signature of blue channel for evaluation window 5. (sig*_SigCRCBlue5)*/

/*WINDOW 6 for both Signature Unit 0 & 1*/
#define    DISENG_SIG_EVALCONTROL6 0xE8 	/*Control settings for evaluation window 6. (sig*_EvalControl6)*/
#define    DISENG_SIG_EVALUPPERLEFT6 0xEC 	/*Upper left corner of evaluation window 6. (sig*_EvalUpperLeft6)*/
#define    DISENG_SIG_EVALLOWERRIGHT6 0xF0 	/*Lower right corner of evaluation window 6. (sig*_EvalLowerRight6)*/
#define    DISENG_SIG_SIGCRCREDREF6 0xF4 	/*Reference signature of red channel for evaluation window 6. (sig*_SigCRCRedRef6)*/
#define    DISENG_SIG_SIGCRCGREENREF6 0xF8 	/*Reference signature of green channel for evaluation window 6. (sig*_SigCRCGreenRef6)*/
#define    DISENG_SIG_SIGCRCBLUEREF6 0xFC 	/*Reference signature of blue channel for evaluation window 6. (sig*_SigCRCBlueRef6)*/
#define    DISENG_SIG_SIGCRCRED6 0x100 		/*Measured signature of red channel for evaluation window 6. (sig*_SigCRCRed6)*/
#define    DISENG_SIG_SIGCRCGREEN6 0x104 	/*Measured signature of green channel for evaluation window 6. (sig*_SigCRCGreen6)*/
#define    DISENG_SIG_SIGCRCBLUE6 0x108 	/*Measured signature of blue channel for evaluation window 6. (sig*_SigCRCBlue6)*/

/*WINDOW 7 for both Signature Unit 0 & 1*/
#define    DISENG_SIG_EVALCONTROL7 0x10C 	/*Control settings for evaluation window 7. (sig*_EvalControl7)*/
#define    DISENG_SIG_EVALUPPERLEFT7 0x110 	/*Upper left corner of evaluation window 7. (sig*_EvalUpperLeft7)*/
#define    DISENG_SIG_EVALLOWERRIGHT7 0x114	/*Lower right corner of evaluation window 7. (sig*_EvalLowerRight7)*/
#define    DISENG_SIG_SIGCRCREDREF7 0x118 	/*Reference signature of red channel for evaluation window 7. (sig*_SigCRCRedRef7)*/
#define    DISENG_SIG_SIGCRCGREENREF7 0x11C	/*Reference signature of green channel for evaluation window 7. (sig*_SigCRCGreenRef7)*/
#define    DISENG_SIG_SIGCRCBLUEREF7 0x120 	/*Reference signature of blue channel for evaluation window 7. (sig*_SigCRCBlueRef7)*/
#define    DISENG_SIG_SIGCRCRED7 0x124 		/*Measured signature of red channel for evaluation window 7. (sig*_SigCRCRed7)*/
#define    DISENG_SIG_SIGCRCGREEN7 0x128 	/*Measured signature of green channel for evaluation window 7. (sig*_SigCRCGreen7)*/
#define    DISENG_SIG_SIGCRCBLUE7 0x12C 	/*Measured signature of blue channel for evaluation window 7. (sig*_SigCRCBlue7)*/

#define    DISENG_SIG_SHADOWLOAD 0x130 		/*Shadow load control register. (sig*_ShadowLoad)*/
#define    DISENG_SIG_CONTINUOUSMODE 0x134 	/*Signature operation mode control. (sig*_ContinuousMode)*/
#define    DISENG_SIG_SOFTWAREKICK 0x138 	/*Signature measurement trigger. (sig*_SoftwareKick)*/
#define    DISENG_SIG_STATUS (uint32_t) 0x13C 			/*Module status. (sig*_Status)*/

#endif /* SIGUNIT_REGISTERS_H */
