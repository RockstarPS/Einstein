/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2018. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** \file     mm_gdc_iris_registers.h
**
** \brief    This file has address of Signature unit registers and its possible values.
**           This file is taken from Iris Driver Source and removed the unwanted items
**           and the macro names changed to remove the MISRA warnings.
**
** Organization:   UE COC, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef MM_GDC_IRIS_IRIS_MGP_REGISTERS_H
#define MM_GDC_IRIS_IRIS_MGP_REGISTERS_H

/*! \cond Hide for doxygen */
#define SIG_REG_READ32(ADDR)          (*((volatile uint32_t *)(ADDR)))
#define SIG_REG_WRITE32(ADD, VAL)     (*((volatile uint32_t*)(ADD)) = (VAL))

/******************************************************************************/
/* iris_mgp registers */
/******************************************************************************/
/* PRQA S 380,779,857,3453 EOF */  /* <msr id=3,8,3,1> */


/* DISENG_DISENGCFG_SRCSELECT0: Tap selection for Signature and Frame Dump (display stream 0). */
#define     DISENG_DISENGCFG_SRCSELECT0 0x0000c410u
#define     DISENG_DISENGCFG_SIG_SELECT0_NONE 0x0 /* No source. */
#define     DISENG_DISENGCFG_SIG_SELECT0_FRAMEGEN 0x1 /* Source is FrameGen#0 output. */
#define     DISENG_DISENGCFG_SIG_SELECT0_GAMMACOR 0x2 /* Source is GammaCor#0 output. */
#define     DISENG_DISENGCFG_SIG_SELECT0_DITHER 0x3 /* Source is Dither#0 output. */
#define     DISENG_DISENGCFG_SIG_SELECT0_RESET 0x0uL

/* DISENG_DISENGCFG_SRCSELECT1: Tap selection for Signature and Frame Dump (display stream 1). */
#define     DISENG_DISENGCFG_SRCSELECT1 0x0000c430u
#define     DISENG_DISENGCFG_SIG_SELECT1_NONE 0x0 /* No source. */
#define     DISENG_DISENGCFG_SIG_SELECT1_FRAMEGEN 0x1 /* Source is FrameGen#1 output. */
#define     DISENG_DISENGCFG_SIG_SELECT1_GAMMACOR 0x2 /* Source is GammaCor#1 output. */
#define     DISENG_DISENGCFG_SIG_SELECT1_DITHER 0x3 /* Source is Dither#1 output. */
#define     DISENG_DISENGCFG_SIG_SELECT1_RESET 0x0uL


/* DISENG_SIG0_LOCKUNLOCK: Register to change the protection status of this address block.
   When lock protection is active, no write but only read access is possible to all registers of this address block. */
#define     DISENG_SIG0_LOCKUNLOCK 0x0000e000u

#define     DISENG_SIG0_LOCKUNLOCK_lock_key 0x5651F763 /* Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1. */
#define     DISENG_SIG0_LOCKUNLOCK_unlock_key 0x691DB936 /* Increments the unlock counter. Max allowed value is 15. */
#define     DISENG_SIG0_LOCKUNLOCK_privilege_key 0xAEE95CDC /* Enables privilege protection. Disabled after reset. */
#define     DISENG_SIG0_LOCKUNLOCK_unprivilege_key 0xB5E2466E /* Disables privilege protection. */
#define     DISENG_SIG0_LOCKUNLOCK_freeze_key 0xFBE8B1E6 /* Freezes current protection status. Writing keys to this register has no more effect until reset. */
#define     DISENG_SIG0_LOCKUNLOCK_RESET (none)uL

/* DISENG_SIG0_LOCKSTATUS: Protection status of this address block. */
#define     DISENG_SIG0_LOCKSTATUS 0x0000e004u

#define     DISENG_SIG0_LOCKSTATUS_RESET 0x0uL

/* DISENG_SIG0_PRIVILEGESTATUS: Current status of privilege protection: 0 = inactive , 1 = active. */
#define     DISENG_SIG0_PRIVILEGESTATUS_RESET 0x0uL

/* DISENG_SIG0_FREEZESTATUS: Current freeze status: 0 = protection status can be changed, 1 = cannot be changed. */
#define     DISENG_SIG0_FREEZESTATUS_RESET 0x0uL

/* DISENG_SIG0_STATICCONTROL: Global configuration shared by all evaluation windows. */
#define     DISENG_SIG0_STATICCONTROL 0x0000e008u
/* DISENG_SIG0_SHDEN: Enables shadow registers for RWS type fields (0 = write through, 1 = shadowed). */

#define     DISENG_SIG0_SHDEN_RESET 0x0uL

/* DISENG_SIG0_SHDLDSEL: Source select for events that will load shadow registers into the active configuration. */

#define     DISENG_SIG0_SHDLDSEL_LOCAL 0x0 /* Shadows are loaded at start of frame for each evaluation window for which ShdLdReq has been set. */
#define     DISENG_SIG0_SHDLDSEL_GLOBAL 0x1 /* Shadows of all evaluation windows are loaded synchronous to the display stream (shadow load token received on frame input port). */
#define     DISENG_SIG0_SHDLDSEL_RESET 0x0uL

/* DISENG_SIG0_ERRTHRES: Number of frames with signature violation before StsSigError is set for an evaluation window. */
#define     DISENG_SIG0_ERRTHRES_SHIFT 16u
#define     DISENG_SIG0_ERRTHRES_MASK 0xffuL

#define     DISENG_SIG0_ERRTHRES_RESET 0x0uL

/* DISENG_SIG0_ERRTHRESRESET: Number of consecutive frames without signature violation before StsSigError is reset for an evaluation window. */

#define     DISENG_SIG0_ERRTHRESRESET_RESET 8uL

/* DISENG_SIG0_PANICCOLOR: Overlay color for evaluation windows in panic mode.
   This constant color replaces the color of pixels that lie inside of an evaluation window for which local panic is enabled and the error status active. */
#define     DISENG_SIG0_PANICCOLOR 0x0000e00cu
/* DISENG_SIG0_PANICALPHA: Alpha mask bit. */

#define     DISENG_SIG0_PANICALPHA_RESET 0x0uL

/* DISENG_SIG0_PANICBLUE: Blue color component. */
#define     DISENG_SIG0_PANICBLUE_RESET 0x0uL

/* DISENG_SIG0_PANICGREEN: Green color component. */

#define     DISENG_SIG0_PANICGREEN_RESET 0x0uL

/* DISENG_SIG0_PANICRED: Red color component. */

#define     DISENG_SIG0_PANICRED_RESET 0x0uL

/* DISENG_SIG0_EVALCONTROL0: Control settings for evaluation window 0.
   In case of overlapping evaluation windows, a pixel contributes to the window with highest index (0 = bottom most, 7 = top most). */
#define     DISENG_SIG0_EVALCONTROL0 0x0000e010u

#define     DISENG_SIG0_ENEVALWIN0_RESET 0x0uL

/* DISENG_SIG0_ENCRC0: When enabled (value 1) the measured signature is checked against a reference value (SigCRCRef). */
#define     DISENG_SIG0_ENCRC0_RESET 0x0uL

/* DISENG_SIG0_ALPHAMASK0: When enabled (value 1) pixels with alpha bit = 0 are ignored for signature computation. */
#define     DISENG_SIG0_ALPHAMASK0_RESET 0x0uL

/* DISENG_SIG0_ALPHAINV0: When enabled (value 1) the effect of AlphaMask is inverted (pixels with alpha bit = 1 are ignored then). */

#define     DISENG_SIG0_ALPHAINV0_RESET 0x0uL

/* DISENG_SIG0_ENLOCALPANIC0: When enabled (value 1) the error status this window (StsSigError) will replace all pixels inside the window by a constant color on the display. Skip regions due to other evaluation windows on top are not modified. AlphaMask, when enabled, is not considered for this replacement. */

#define     DISENG_SIG0_ENLOCALPANIC0_RESET 0x0uL

/* DISENG_SIG0_ENGLOBALPANIC0: When enabled (value 1) the error status of this window (StsSigError) will activate the panic mode of the display stream's Frame Generator, which can switch to another display mode in response. */

#define     DISENG_SIG0_ENGLOBALPANIC0_RESET 0x0uL

/* DISENG_SIG0_EVALUPPERLEFT0: Upper left corner of evaluation window 0.
   Coordinates are relative to active display area (origin at top-left corner). */
#define     DISENG_SIG0_EVALUPPERLEFT0 0x0000e014u
/* DISENG_SIG0_XEVALUPPERLEFT0: X coordinate. */


/* DISENG_SIG0_EVALLOWERRIGHT0: Lower right corner of evaluation window 0.
   Coordinates are relative to active display area (origin at top-left corner). */
#define     DISENG_SIG0_EVALLOWERRIGHT0 0x0000e018u

/* DISENG_SIG0_SIGCRCREDREF0: Reference signature of red channel for evaluation window 0. */
#define     DISENG_SIG0_SIGCRCREDREF0 0x0000e01cu

#define     DISENG_SIG0_SIGCRCREDREF0_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREENREF0: Reference signature of green channel for evaluation window 0. */
#define     DISENG_SIG0_SIGCRCGREENREF0 0x0000e020u

#define     DISENG_SIG0_SIGCRCGREENREF0_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUEREF0: Reference signature of blue channel for evaluation window 0. */
#define     DISENG_SIG0_SIGCRCBLUEREF0 0x0000e024u

#define     DISENG_SIG0_SIGCRCBLUEREF0_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCRED0: Measured signature of red channel for evaluation window 0. */
#define     DISENG_SIG0_SIGCRCRED0 0x0000e028u

#define     DISENG_SIG0_SIGCRCRED0_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREEN0: Measured signature of green channel for evaluation window 0. */
#define     DISENG_SIG0_SIGCRCGREEN0 0x0000e02cu

#define     DISENG_SIG0_SIGCRCGREEN0_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUE0: Measured signature of blue channel for evaluation window 0. */
#define     DISENG_SIG0_SIGCRCBLUE0 0x0000e030u

#define     DISENG_SIG0_SIGCRCBLUE0_RESET 4294967295uL

/* DISENG_SIG0_EVALCONTROL1: Control settings for evaluation window 1. */
#define     DISENG_SIG0_EVALCONTROL1 0x0000e034u

/* DISENG_SIG0_EVALUPPERLEFT1: Upper left corner of evaluation window 1. */
#define     DISENG_SIG0_EVALUPPERLEFT1 0x0000e038u


/* DISENG_SIG0_EVALLOWERRIGHT1: Lower right corner of evaluation window 1. */
#define     DISENG_SIG0_EVALLOWERRIGHT1 0x0000e03cu

/* DISENG_SIG0_SIGCRCREDREF1: Reference signature of red channel for evaluation window 1. */
#define     DISENG_SIG0_SIGCRCREDREF1 0x0000e040u

#define     DISENG_SIG0_SIGCRCREDREF1_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREENREF1: Reference signature of green channel for evaluation window 1. */
#define     DISENG_SIG0_SIGCRCGREENREF1 0x0000e044u

#define     DISENG_SIG0_SIGCRCGREENREF1_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUEREF1: Reference signature of blue channel for evaluation window 1. */
#define     DISENG_SIG0_SIGCRCBLUEREF1 0x0000e048u

#define     DISENG_SIG0_SIGCRCBLUEREF1_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCRED1: Measured signature of red channel for evaluation window 1. */
#define     DISENG_SIG0_SIGCRCRED1 0x0000e04cu

#define     DISENG_SIG0_SIGCRCRED1_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREEN1: Measured signature of green channel for evaluation window 1. */
#define     DISENG_SIG0_SIGCRCGREEN1 0x0000e050u

#define     DISENG_SIG0_SIGCRCGREEN1_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUE1: Measured signature of blue channel for evaluation window 1. */
#define     DISENG_SIG0_SIGCRCBLUE1 0x0000e054u

#define     DISENG_SIG0_SIGCRCBLUE1_RESET 4294967295uL

/* DISENG_SIG0_EVALCONTROL2: Control settings for evaluation window 2. */
#define     DISENG_SIG0_EVALCONTROL2 0x0000e058u

#define     DISENG_SIG0_ENEVALWIN2_RESET 0x0uL

/* DISENG_SIG0_ENCRC2: See EnCRC0. */

#define     DISENG_SIG0_ENCRC2_RESET 0x0uL


/* DISENG_SIG0_EVALUPPERLEFT2: Upper left corner of evaluation window 2. */
#define     DISENG_SIG0_EVALUPPERLEFT2 0x0000e05cu

/* DISENG_SIG0_EVALLOWERRIGHT2: Lower right corner of evaluation window 2. */
#define     DISENG_SIG0_EVALLOWERRIGHT2 0x0000e060u

/* DISENG_SIG0_SIGCRCREDREF2: Reference signature of red channel for evaluation window 2. */
#define     DISENG_SIG0_SIGCRCREDREF2 0x0000e064u
/* DISENG_SIG0_SIGCRCREDREF2: See SigCRCRedRef0. */

#define     DISENG_SIG0_SIGCRCREDREF2_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREENREF2: Reference signature of green channel for evaluation window 2. */
#define     DISENG_SIG0_SIGCRCGREENREF2 0x0000e068u
/* DISENG_SIG0_SIGCRCGREENREF2: See SigCRCGreenRef0. */

#define     DISENG_SIG0_SIGCRCGREENREF2_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUEREF2: Reference signature of blue channel for evaluation window 2. */
#define     DISENG_SIG0_SIGCRCBLUEREF2 0x0000e06cu
/* DISENG_SIG0_SIGCRCBLUEREF2: See SigCRCBlueRef0. */

#define     DISENG_SIG0_SIGCRCBLUEREF2_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCRED2: Measured signature of red channel for evaluation window 2. */
#define     DISENG_SIG0_SIGCRCRED2 0x0000e070u
/* DISENG_SIG0_SIGCRCRED2: See SigCRCRed0. */

#define     DISENG_SIG0_SIGCRCRED2_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREEN2: Measured signature of green channel for evaluation window 2. */
#define     DISENG_SIG0_SIGCRCGREEN2 0x0000e074u

#define     DISENG_SIG0_SIGCRCGREEN2_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUE2: Measured signature of blue channel for evaluation window 2. */
#define     DISENG_SIG0_SIGCRCBLUE2 0x0000e078u

#define     DISENG_SIG0_SIGCRCBLUE2_RESET 4294967295uL

/* DISENG_SIG0_EVALCONTROL3: Control settings for evaluation window 3. */
#define     DISENG_SIG0_EVALCONTROL3 0x0000e07cu

/* DISENG_SIG0_EVALUPPERLEFT3: Upper left corner of evaluation window 3. */
#define     DISENG_SIG0_EVALUPPERLEFT3 0x0000e080u
/* DISENG_SIG0_XEVALUPPERLEFT3: See XEvalUpperLeft0. */

/* DISENG_SIG0_EVALLOWERRIGHT3: Lower right corner of evaluation window 3. */
#define     DISENG_SIG0_EVALLOWERRIGHT3 0x0000e084u

/* DISENG_SIG0_SIGCRCREDREF3: Reference signature of red channel for evaluation window 3. */
#define     DISENG_SIG0_SIGCRCREDREF3 0x0000e088u

#define     DISENG_SIG0_SIGCRCREDREF3_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREENREF3: Reference signature of green channel for evaluation window 3. */
#define     DISENG_SIG0_SIGCRCGREENREF3 0x0000e08cu

#define     DISENG_SIG0_SIGCRCGREENREF3_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUEREF3: Reference signature of blue channel for evaluation window 3. */
#define     DISENG_SIG0_SIGCRCBLUEREF3 0x0000e090u

#define     DISENG_SIG0_SIGCRCBLUEREF3_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCRED3: Measured signature of red channel for evaluation window 3. */
#define     DISENG_SIG0_SIGCRCRED3 0x0000e094u

#define     DISENG_SIG0_SIGCRCRED3_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREEN3: Measured signature of green channel for evaluation window 3. */
#define     DISENG_SIG0_SIGCRCGREEN3 0x0000e098u

#define     DISENG_SIG0_SIGCRCGREEN3_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUE3: Measured signature of blue channel for evaluation window 3. */
#define     DISENG_SIG0_SIGCRCBLUE3 0x0000e09cu

#define     DISENG_SIG0_SIGCRCBLUE3_RESET 4294967295uL

/* DISENG_SIG0_EVALCONTROL4: Control settings for evaluation window 4. */
#define     DISENG_SIG0_EVALCONTROL4 0x0000e0a0u

/* DISENG_SIG0_EVALUPPERLEFT4: Upper left corner of evaluation window 4. */
#define     DISENG_SIG0_EVALUPPERLEFT4 0x0000e0a4u

/* DISENG_SIG0_EVALLOWERRIGHT4: Lower right corner of evaluation window 4. */
#define     DISENG_SIG0_EVALLOWERRIGHT4 0x0000e0a8u

/* DISENG_SIG0_SIGCRCREDREF4: Reference signature of red channel for evaluation window 4. */
#define     DISENG_SIG0_SIGCRCREDREF4 0x0000e0acu

#define     DISENG_SIG0_SIGCRCREDREF4_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREENREF4: Reference signature of green channel for evaluation window 4. */
#define     DISENG_SIG0_SIGCRCGREENREF4 0x0000e0b0u

#define     DISENG_SIG0_SIGCRCGREENREF4_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUEREF4: Reference signature of blue channel for evaluation window 4. */
#define     DISENG_SIG0_SIGCRCBLUEREF4 0x0000e0b4u

#define     DISENG_SIG0_SIGCRCBLUEREF4_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCRED4: Measured signature of red channel for evaluation window 4. */
#define     DISENG_SIG0_SIGCRCRED4 0x0000e0b8u

#define     DISENG_SIG0_SIGCRCRED4_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREEN4: Measured signature of green channel for evaluation window 4. */
#define     DISENG_SIG0_SIGCRCGREEN4 0x0000e0bcu

#define     DISENG_SIG0_SIGCRCGREEN4_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUE4: Measured signature of blue channel for evaluation window 4. */
#define     DISENG_SIG0_SIGCRCBLUE4 0x0000e0c0u

#define     DISENG_SIG0_SIGCRCBLUE4_RESET 4294967295uL

/* DISENG_SIG0_EVALCONTROL5: Control settings for evaluation window 5. */
#define     DISENG_SIG0_EVALCONTROL5 0x0000e0c4u

/* DISENG_SIG0_EVALUPPERLEFT5: Upper left corner of evaluation window 5. */
#define     DISENG_SIG0_EVALUPPERLEFT5 0x0000e0c8u

/* DISENG_SIG0_EVALLOWERRIGHT5: Lower right corner of evaluation window 5. */
#define     DISENG_SIG0_EVALLOWERRIGHT5 0x0000e0ccu

/* DISENG_SIG0_SIGCRCREDREF5: Reference signature of red channel for evaluation window 5. */
#define     DISENG_SIG0_SIGCRCREDREF5 0x0000e0d0u
#define     DISENG_SIG0_SIGCRCREDREF5_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREENREF5: Reference signature of green channel for evaluation window 5. */
#define     DISENG_SIG0_SIGCRCGREENREF5 0x0000e0d4u
#define     DISENG_SIG0_SIGCRCGREENREF5_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUEREF5: Reference signature of blue channel for evaluation window 5. */
#define     DISENG_SIG0_SIGCRCBLUEREF5 0x0000e0d8u
/* DISENG_SIG0_SIGCRCBLUEREF5: See SigCRCBlueRef0. */
#define     DISENG_SIG0_SIGCRCBLUEREF5_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCRED5: Measured signature of red channel for evaluation window 5. */
#define     DISENG_SIG0_SIGCRCRED5 0x0000e0dcu
#define     DISENG_SIG0_SIGCRCRED5_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREEN5: Measured signature of green channel for evaluation window 5. */
#define     DISENG_SIG0_SIGCRCGREEN5 0x0000e0e0u
#define     DISENG_SIG0_SIGCRCGREEN5_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUE5: Measured signature of blue channel for evaluation window 5. */
#define     DISENG_SIG0_SIGCRCBLUE5 0x0000e0e4u
/* DISENG_SIG0_SIGCRCBLUE5: See SigCRCBlue0. */
#define     DISENG_SIG0_SIGCRCBLUE5_RESET 4294967295uL

/* DISENG_SIG0_EVALCONTROL6: Control settings for evaluation window 6. */
#define     DISENG_SIG0_EVALCONTROL6 0x0000e0e8u

/* DISENG_SIG0_EVALUPPERLEFT6: Upper left corner of evaluation window 6. */
#define     DISENG_SIG0_EVALUPPERLEFT6 0x0000e0ecu

/* DISENG_SIG0_EVALLOWERRIGHT6: Lower right corner of evaluation window 6. */
#define     DISENG_SIG0_EVALLOWERRIGHT6 0x0000e0f0u

/* DISENG_SIG0_SIGCRCREDREF6: Reference signature of red channel for evaluation window 6. */
#define     DISENG_SIG0_SIGCRCREDREF6 0x0000e0f4u
#define     DISENG_SIG0_SIGCRCREDREF6_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREENREF6: Reference signature of green channel for evaluation window 6. */
#define     DISENG_SIG0_SIGCRCGREENREF6 0x0000e0f8u
#define     DISENG_SIG0_SIGCRCGREENREF6_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUEREF6: Reference signature of blue channel for evaluation window 6. */
#define     DISENG_SIG0_SIGCRCBLUEREF6 0x0000e0fcu
#define     DISENG_SIG0_SIGCRCBLUEREF6_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCRED6: Measured signature of red channel for evaluation window 6. */
#define     DISENG_SIG0_SIGCRCRED6 0x0000e100u
#define     DISENG_SIG0_SIGCRCRED6_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREEN6: Measured signature of green channel for evaluation window 6. */
#define     DISENG_SIG0_SIGCRCGREEN6 0x0000e104u
#define     DISENG_SIG0_SIGCRCGREEN6_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUE6: Measured signature of blue channel for evaluation window 6. */
#define     DISENG_SIG0_SIGCRCBLUE6 0x0000e108u
#define     DISENG_SIG0_SIGCRCBLUE6_RESET 4294967295uL

/* DISENG_SIG0_EVALCONTROL7: Control settings for evaluation window 7. */
#define     DISENG_SIG0_EVALCONTROL7 0x0000e10cu

/* DISENG_SIG0_EVALUPPERLEFT7: Upper left corner of evaluation window 7. */
#define     DISENG_SIG0_EVALUPPERLEFT7 0x0000e110u

/* DISENG_SIG0_EVALLOWERRIGHT7: Lower right corner of evaluation window 7. */
#define     DISENG_SIG0_EVALLOWERRIGHT7 0x0000e114u

/* DISENG_SIG0_SIGCRCREDREF7: Reference signature of red channel for evaluation window 7. */
#define     DISENG_SIG0_SIGCRCREDREF7 0x0000e118u
/* DISENG_SIG0_SIGCRCREDREF7: See SigCRCRedRef0. */
#define     DISENG_SIG0_SIGCRCREDREF7_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREENREF7: Reference signature of green channel for evaluation window 7. */
#define     DISENG_SIG0_SIGCRCGREENREF7 0x0000e11cu
/* DISENG_SIG0_SIGCRCGREENREF7: See SigCRCGreenRef0. */
#define     DISENG_SIG0_SIGCRCGREENREF7_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUEREF7: Reference signature of blue channel for evaluation window 7. */
#define     DISENG_SIG0_SIGCRCBLUEREF7 0x0000e120u
/* DISENG_SIG0_SIGCRCBLUEREF7: See SigCRCBlueRef0. */
#define     DISENG_SIG0_SIGCRCBLUEREF7_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCRED7: Measured signature of red channel for evaluation window 7. */
#define     DISENG_SIG0_SIGCRCRED7 0x0000e124u
#define     DISENG_SIG0_SIGCRCRED7_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCGREEN7: Measured signature of green channel for evaluation window 7. */
#define     DISENG_SIG0_SIGCRCGREEN7 0x0000e128u
/* DISENG_SIG0_SIGCRCGREEN7: See SigCRCGreen0. */
#define     DISENG_SIG0_SIGCRCGREEN7_RESET 4294967295uL

/* DISENG_SIG0_SIGCRCBLUE7: Measured signature of blue channel for evaluation window 7. */
#define     DISENG_SIG0_SIGCRCBLUE7 0x0000e12cu
#define     DISENG_SIG0_SIGCRCBLUE7_RESET 4294967295uL

/* DISENG_SIG0_SHADOWLOAD: Shadow load control register. */
#define     DISENG_SIG0_SHADOWLOAD 0x0000e130u

/* DISENG_SIG0_CONTINUOUSMODE: Signature operation mode control. */
#define     DISENG_SIG0_CONTINUOUSMODE 0x0000e134u

/* DISENG_SIG0_SOFTWAREKICK: Signature measurement trigger. */
#define     DISENG_SIG0_SOFTWAREKICK 0x0000e138u
#define     DISENG_SIG0_KICK_RESET 0x0uL    

/* DISENG_SIG0_STATUS: Module status. */
#define     DISENG_SIG0_STATUS 0x0000e13cu
/* DISENG_SIG0_STSSIGERROR: Error status bits for all evaluation windows (bit index = window index). */

#define     DISENG_SIG0_STSSIGERROR_RESET 0x0uL

/* DISENG_SIG0_STSSIGVALID: Measured signature values are valid. */
#define     DISENG_SIG0_STSSIGVALID_RESET 0x0uL

/* DISENG_SIG0_STSSIGIDLE: StsSigIdle = 1: Signature is in Idle state. */
#define     DISENG_SIG0_STSSIGIDLE_RESET 1uL



/* DISENG_FRAMEGEN1_LOCKUNLOCK: Register to change the protection status of this address block.
   When lock protection is active, no write but only read access is possible to all registers of this address block. */
#define     DISENG_FRAMEGEN1_LOCKUNLOCK 0x0000e400u
#define     DISENG_FRAMEGEN1_LOCKUNLOCK_lock_key 0x5651F763 /* Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1. */
#define     DISENG_FRAMEGEN1_LOCKUNLOCK_unlock_key 0x691DB936 /* Increments the unlock counter. Max allowed value is 15. */
#define     DISENG_FRAMEGEN1_LOCKUNLOCK_privilege_key 0xAEE95CDC /* Enables privilege protection. Disabled after reset. */
#define     DISENG_FRAMEGEN1_LOCKUNLOCK_unprivilege_key 0xB5E2466E /* Disables privilege protection. */
#define     DISENG_FRAMEGEN1_LOCKUNLOCK_freeze_key 0xFBE8B1E6 /* Freezes current protection status. Writing keys to this register has no more effect until reset. */
#define     DISENG_FRAMEGEN1_LOCKUNLOCK_RESET (none)uL

/* DISENG_FRAMEGEN1_LOCKSTATUS: Protection status of this address block. */
#define     DISENG_FRAMEGEN1_LOCKSTATUS 0x0000e404u
#define     DISENG_FRAMEGEN1_LOCKSTATUS_RESET 0x0uL

/* DISENG_FRAMEGEN1_PRIVILEGESTATUS: Current status of privilege protection: 0 = inactive , 1 = active. */
#define     DISENG_FRAMEGEN1_PRIVILEGESTATUS_RESET 0x0uL

/* DISENG_FRAMEGEN1_FREEZESTATUS: Current freeze status: 0 = protection status can be changed, 1 = cannot be changed. */
#define     DISENG_FRAMEGEN1_FREEZESTATUS_RESET 0x0uL

/* DISENG_FRAMEGEN1_FGSTCTRL: FrameGen Static Control Register */
#define     DISENG_FRAMEGEN1_FGSTCTRL 0x0000e408u
/* DISENG_FRAMEGEN1_SHDEN: Enables shadowing for RWS type configuration fields. */

/* DISENG_FRAMEGEN1_INT0CONFIG: Coordinates of the trigger point for generation of the Int0 interrupt signal
   The fields in this register can be written at any time, even though they are static. They will have an immediate effect, they are not shadowed. Register can only be accessed if display clock is running. */
#define     DISENG_FRAMEGEN1_INT0CONFIG 0x0000e41cu


/* DISENG_SIG1_LOCKUNLOCK: Register to change the protection status of this address block.
   When lock protection is active, no write but only read access is possible to all registers of this address block. */
#define     DISENG_SIG1_LOCKUNLOCK 0x0000f800u
/* DISENG_SIG1_LOCKUNLOCK: The protection status is changed by writing one of the following key values to this field: */
#define     DISENG_SIG1_LOCKUNLOCK_lock_key 0x5651F763 /* Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1. */
#define     DISENG_SIG1_LOCKUNLOCK_unlock_key 0x691DB936 /* Increments the unlock counter. Max allowed value is 15. */
#define     DISENG_SIG1_LOCKUNLOCK_privilege_key 0xAEE95CDC /* Enables privilege protection. Disabled after reset. */
#define     DISENG_SIG1_LOCKUNLOCK_unprivilege_key 0xB5E2466E /* Disables privilege protection. */
#define     DISENG_SIG1_LOCKUNLOCK_freeze_key 0xFBE8B1E6 /* Freezes current protection status. Writing keys to this register has no more effect until reset. */
#define     DISENG_SIG1_LOCKUNLOCK_RESET (none)uL

/* DISENG_SIG1_LOCKSTATUS: Protection status of this address block. */
#define     DISENG_SIG1_LOCKSTATUS 0x0000f804u
/* DISENG_SIG1_STATICCONTROL: Global configuration shared by all evaluation windows. */
#define     DISENG_SIG1_STATICCONTROL 0x0000f808u

/* DISENG_SIG1_PANICCOLOR: Overlay color for evaluation windows in panic mode.
   This constant color replaces the color of pixels that lie inside of an evaluation window for which local panic is enabled and the error status active. */
#define     DISENG_SIG1_PANICCOLOR 0x0000f80cu

/* DISENG_SIG1_EVALCONTROL0: Control settings for evaluation window 0.
   In case of overlapping evaluation windows, a pixel contributes to the window with highest index (0 = bottom most, 7 = top most). */
#define     DISENG_SIG1_EVALCONTROL0 0x0000f810u

/* DISENG_SIG1_EVALUPPERLEFT0: Upper left corner of evaluation window 0.
   Coordinates are relative to active display area (origin at top-left corner). */
#define     DISENG_SIG1_EVALUPPERLEFT0 0x0000f814u

/* DISENG_SIG1_EVALLOWERRIGHT0: Lower right corner of evaluation window 0.
   Coordinates are relative to active display area (origin at top-left corner). */
#define     DISENG_SIG1_EVALLOWERRIGHT0 0x0000f818u

/* DISENG_SIG1_SIGCRCREDREF0: Reference signature of red channel for evaluation window 0. */
#define     DISENG_SIG1_SIGCRCREDREF0 0x0000f81cu
/* DISENG_SIG1_SIGCRCREDREF0: Reference value that is compared against measured SigCRCRed value. */
#define     DISENG_SIG1_SIGCRCREDREF0_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREENREF0: Reference signature of green channel for evaluation window 0. */
#define     DISENG_SIG1_SIGCRCGREENREF0 0x0000f820u
/* DISENG_SIG1_SIGCRCGREENREF0: Reference value that is compared against measured SigCRCGreen value. */
#define     DISENG_SIG1_SIGCRCGREENREF0_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUEREF0: Reference signature of blue channel for evaluation window 0. */
#define     DISENG_SIG1_SIGCRCBLUEREF0 0x0000f824u
/* DISENG_SIG1_SIGCRCBLUEREF0: Reference value that is compared against measured SigCRCBlue value. */
#define     DISENG_SIG1_SIGCRCBLUEREF0_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCRED0: Measured signature of red channel for evaluation window 0. */
#define     DISENG_SIG1_SIGCRCRED0 0x0000f828u
/* DISENG_SIG1_SIGCRCRED0: CRC values from red channel. */
#define     DISENG_SIG1_SIGCRCRED0_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREEN0: Measured signature of green channel for evaluation window 0. */
#define     DISENG_SIG1_SIGCRCGREEN0 0x0000f82cu
/* DISENG_SIG1_SIGCRCGREEN0: CRC values from green channel. */
#define     DISENG_SIG1_SIGCRCGREEN0_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUE0: Measured signature of blue channel for evaluation window 0. */
#define     DISENG_SIG1_SIGCRCBLUE0 0x0000f830u
/* DISENG_SIG1_SIGCRCBLUE0: CRC values from blue channel. */
#define     DISENG_SIG1_SIGCRCBLUE0_RESET 4294967295uL

/* DISENG_SIG1_EVALCONTROL1: Control settings for evaluation window 1. */
#define     DISENG_SIG1_EVALCONTROL1 0x0000f834u

/* DISENG_SIG1_EVALUPPERLEFT1: Upper left corner of evaluation window 1. */
#define     DISENG_SIG1_EVALUPPERLEFT1 0x0000f838u

/* DISENG_SIG1_EVALLOWERRIGHT1: Lower right corner of evaluation window 1. */
#define     DISENG_SIG1_EVALLOWERRIGHT1 0x0000f83cu

/* DISENG_SIG1_SIGCRCREDREF1: Reference signature of red channel for evaluation window 1. */
#define     DISENG_SIG1_SIGCRCREDREF1 0x0000f840u
/* DISENG_SIG1_SIGCRCREDREF1: See SigCRCRedRef0. */
#define     DISENG_SIG1_SIGCRCREDREF1_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREENREF1: Reference signature of green channel for evaluation window 1. */
#define     DISENG_SIG1_SIGCRCGREENREF1 0x0000f844u
/* DISENG_SIG1_SIGCRCGREENREF1: See SigCRCGreenRef0. */
#define     DISENG_SIG1_SIGCRCGREENREF1_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUEREF1: Reference signature of blue channel for evaluation window 1. */
#define     DISENG_SIG1_SIGCRCBLUEREF1 0x0000f848u
/* DISENG_SIG1_SIGCRCBLUEREF1: See SigCRCBlueRef0. */
#define     DISENG_SIG1_SIGCRCBLUEREF1_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCRED1: Measured signature of red channel for evaluation window 1. */
#define     DISENG_SIG1_SIGCRCRED1 0x0000f84cu
/* DISENG_SIG1_SIGCRCRED1: See SigCRCRed0. */
#define     DISENG_SIG1_SIGCRCRED1_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREEN1: Measured signature of green channel for evaluation window 1. */
#define     DISENG_SIG1_SIGCRCGREEN1 0x0000f850u
/* DISENG_SIG1_SIGCRCGREEN1: See SigCRCGreen0. */
#define     DISENG_SIG1_SIGCRCGREEN1_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUE1: Measured signature of blue channel for evaluation window 1. */
#define     DISENG_SIG1_SIGCRCBLUE1 0x0000f854u
/* DISENG_SIG1_SIGCRCBLUE1: See SigCRCBlue0. */
#define     DISENG_SIG1_SIGCRCBLUE1_RESET 4294967295uL

/* DISENG_SIG1_EVALCONTROL2: Control settings for evaluation window 2. */
#define     DISENG_SIG1_EVALCONTROL2 0x0000f858u

/* DISENG_SIG1_EVALUPPERLEFT2: Upper left corner of evaluation window 2. */
#define     DISENG_SIG1_EVALUPPERLEFT2 0x0000f85cu

/* DISENG_SIG1_EVALLOWERRIGHT2: Lower right corner of evaluation window 2. */
#define     DISENG_SIG1_EVALLOWERRIGHT2 0x0000f860u

/* DISENG_SIG1_SIGCRCREDREF2: Reference signature of red channel for evaluation window 2. */
#define     DISENG_SIG1_SIGCRCREDREF2 0x0000f864u
/* DISENG_SIG1_SIGCRCREDREF2: See SigCRCRedRef0. */
#define     DISENG_SIG1_SIGCRCREDREF2_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREENREF2: Reference signature of green channel for evaluation window 2. */
#define     DISENG_SIG1_SIGCRCGREENREF2 0x0000f868u
/* DISENG_SIG1_SIGCRCGREENREF2: See SigCRCGreenRef0. */
#define     DISENG_SIG1_SIGCRCGREENREF2_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUEREF2: Reference signature of blue channel for evaluation window 2. */
#define     DISENG_SIG1_SIGCRCBLUEREF2 0x0000f86cu
/* DISENG_SIG1_SIGCRCBLUEREF2: See SigCRCBlueRef0. */
#define     DISENG_SIG1_SIGCRCBLUEREF2_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCRED2: Measured signature of red channel for evaluation window 2. */
#define     DISENG_SIG1_SIGCRCRED2 0x0000f870u
/* DISENG_SIG1_SIGCRCRED2: See SigCRCRed0. */
#define     DISENG_SIG1_SIGCRCRED2_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREEN2: Measured signature of green channel for evaluation window 2. */
#define     DISENG_SIG1_SIGCRCGREEN2 0x0000f874u
/* DISENG_SIG1_SIGCRCGREEN2: See SigCRCGreen0. */
#define     DISENG_SIG1_SIGCRCGREEN2_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUE2: Measured signature of blue channel for evaluation window 2. */
#define     DISENG_SIG1_SIGCRCBLUE2 0x0000f878u
/* DISENG_SIG1_SIGCRCBLUE2: See SigCRCBlue0. */
#define     DISENG_SIG1_SIGCRCBLUE2_RESET 4294967295uL

/* DISENG_SIG1_EVALCONTROL3: Control settings for evaluation window 3. */
#define     DISENG_SIG1_EVALCONTROL3 0x0000f87cu

/* DISENG_SIG1_EVALUPPERLEFT3: Upper left corner of evaluation window 3. */
#define     DISENG_SIG1_EVALUPPERLEFT3 0x0000f880u

/* DISENG_SIG1_EVALLOWERRIGHT3: Lower right corner of evaluation window 3. */
#define     DISENG_SIG1_EVALLOWERRIGHT3 0x0000f884u

/* DISENG_SIG1_SIGCRCREDREF3: Reference signature of red channel for evaluation window 3. */
#define     DISENG_SIG1_SIGCRCREDREF3 0x0000f888u
/* DISENG_SIG1_SIGCRCREDREF3: See SigCRCRedRef0. */
#define     DISENG_SIG1_SIGCRCREDREF3_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREENREF3: Reference signature of green channel for evaluation window 3. */
#define     DISENG_SIG1_SIGCRCGREENREF3 0x0000f88cu
/* DISENG_SIG1_SIGCRCGREENREF3: See SigCRCGreenRef0. */
#define     DISENG_SIG1_SIGCRCGREENREF3_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUEREF3: Reference signature of blue channel for evaluation window 3. */
#define     DISENG_SIG1_SIGCRCBLUEREF3 0x0000f890u
/* DISENG_SIG1_SIGCRCBLUEREF3: See SigCRCBlueRef0. */
#define     DISENG_SIG1_SIGCRCBLUEREF3_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCRED3: Measured signature of red channel for evaluation window 3. */
#define     DISENG_SIG1_SIGCRCRED3 0x0000f894u
/* DISENG_SIG1_SIGCRCRED3: See SigCRCRed0. */
#define     DISENG_SIG1_SIGCRCRED3_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREEN3: Measured signature of green channel for evaluation window 3. */
#define     DISENG_SIG1_SIGCRCGREEN3 0x0000f898u
/* DISENG_SIG1_SIGCRCGREEN3: See SigCRCGreen0. */
#define     DISENG_SIG1_SIGCRCGREEN3_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUE3: Measured signature of blue channel for evaluation window 3. */
#define     DISENG_SIG1_SIGCRCBLUE3 0x0000f89cu
/* DISENG_SIG1_SIGCRCBLUE3: See SigCRCBlue0. */
#define     DISENG_SIG1_SIGCRCBLUE3_RESET 4294967295uL

/* DISENG_SIG1_EVALCONTROL4: Control settings for evaluation window 4. */
#define     DISENG_SIG1_EVALCONTROL4 0x0000f8a0u

/* DISENG_SIG1_EVALUPPERLEFT4: Upper left corner of evaluation window 4. */
#define     DISENG_SIG1_EVALUPPERLEFT4 0x0000f8a4u

/* DISENG_SIG1_EVALLOWERRIGHT4: Lower right corner of evaluation window 4. */
#define     DISENG_SIG1_EVALLOWERRIGHT4 0x0000f8a8u

/* DISENG_SIG1_SIGCRCREDREF4: Reference signature of red channel for evaluation window 4. */
#define     DISENG_SIG1_SIGCRCREDREF4 0x0000f8acu
/* DISENG_SIG1_SIGCRCREDREF4: See SigCRCRedRef0. */
#define     DISENG_SIG1_SIGCRCREDREF4_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREENREF4: Reference signature of green channel for evaluation window 4. */
#define     DISENG_SIG1_SIGCRCGREENREF4 0x0000f8b0u
/* DISENG_SIG1_SIGCRCGREENREF4: See SigCRCGreenRef0. */
#define     DISENG_SIG1_SIGCRCGREENREF4_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUEREF4: Reference signature of blue channel for evaluation window 4. */
#define     DISENG_SIG1_SIGCRCBLUEREF4 0x0000f8b4u
/* DISENG_SIG1_SIGCRCBLUEREF4: See SigCRCBlueRef0. */
#define     DISENG_SIG1_SIGCRCBLUEREF4_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCRED4: Measured signature of red channel for evaluation window 4. */
#define     DISENG_SIG1_SIGCRCRED4 0x0000f8b8u
/* DISENG_SIG1_SIGCRCRED4: See SigCRCRed0. */
#define     DISENG_SIG1_SIGCRCRED4_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREEN4: Measured signature of green channel for evaluation window 4. */
#define     DISENG_SIG1_SIGCRCGREEN4 0x0000f8bcu
/* DISENG_SIG1_SIGCRCGREEN4: See SigCRCGreen0. */
#define     DISENG_SIG1_SIGCRCGREEN4_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUE4: Measured signature of blue channel for evaluation window 4. */
#define     DISENG_SIG1_SIGCRCBLUE4 0x0000f8c0u
/* DISENG_SIG1_SIGCRCBLUE4: See SigCRCBlue0. */
#define     DISENG_SIG1_SIGCRCBLUE4_RESET 4294967295uL

/* DISENG_SIG1_EVALCONTROL5: Control settings for evaluation window 5. */
#define     DISENG_SIG1_EVALCONTROL5 0x0000f8c4u

/* DISENG_SIG1_EVALUPPERLEFT5: Upper left corner of evaluation window 5. */
#define     DISENG_SIG1_EVALUPPERLEFT5 0x0000f8c8u

/* DISENG_SIG1_EVALLOWERRIGHT5: Lower right corner of evaluation window 5. */
#define     DISENG_SIG1_EVALLOWERRIGHT5 0x0000f8ccu

/* DISENG_SIG1_SIGCRCREDREF5: Reference signature of red channel for evaluation window 5. */
#define     DISENG_SIG1_SIGCRCREDREF5 0x0000f8d0u
/* DISENG_SIG1_SIGCRCREDREF5: See SigCRCRedRef0. */
#define     DISENG_SIG1_SIGCRCREDREF5_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREENREF5: Reference signature of green channel for evaluation window 5. */
#define     DISENG_SIG1_SIGCRCGREENREF5 0x0000f8d4u
/* DISENG_SIG1_SIGCRCGREENREF5: See SigCRCGreenRef0. */
#define     DISENG_SIG1_SIGCRCGREENREF5_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUEREF5: Reference signature of blue channel for evaluation window 5. */
#define     DISENG_SIG1_SIGCRCBLUEREF5 0x0000f8d8u
/* DISENG_SIG1_SIGCRCBLUEREF5: See SigCRCBlueRef0. */
#define     DISENG_SIG1_SIGCRCBLUEREF5_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCRED5: Measured signature of red channel for evaluation window 5. */
#define     DISENG_SIG1_SIGCRCRED5 0x0000f8dcu
/* DISENG_SIG1_SIGCRCRED5: See SigCRCRed0. */
#define     DISENG_SIG1_SIGCRCRED5_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREEN5: Measured signature of green channel for evaluation window 5. */
#define     DISENG_SIG1_SIGCRCGREEN5 0x0000f8e0u
/* DISENG_SIG1_SIGCRCGREEN5: See SigCRCGreen0. */
#define     DISENG_SIG1_SIGCRCGREEN5_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUE5: Measured signature of blue channel for evaluation window 5. */
#define     DISENG_SIG1_SIGCRCBLUE5 0x0000f8e4u
/* DISENG_SIG1_SIGCRCBLUE5: See SigCRCBlue0. */
#define     DISENG_SIG1_SIGCRCBLUE5_RESET 4294967295uL

/* DISENG_SIG1_EVALCONTROL6: Control settings for evaluation window 6. */
#define     DISENG_SIG1_EVALCONTROL6 0x0000f8e8u

/* DISENG_SIG1_EVALUPPERLEFT6: Upper left corner of evaluation window 6. */
#define     DISENG_SIG1_EVALUPPERLEFT6 0x0000f8ecu
/* DISENG_SIG1_EVALLOWERRIGHT6: Lower right corner of evaluation window 6. */
#define     DISENG_SIG1_EVALLOWERRIGHT6 0x0000f8f0u


/* DISENG_SIG1_SIGCRCREDREF6: Reference signature of red channel for evaluation window 6. */
#define     DISENG_SIG1_SIGCRCREDREF6 0x0000f8f4u
/* DISENG_SIG1_SIGCRCREDREF6: See SigCRCRedRef0. */
#define     DISENG_SIG1_SIGCRCREDREF6_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREENREF6: Reference signature of green channel for evaluation window 6. */
#define     DISENG_SIG1_SIGCRCGREENREF6 0x0000f8f8u
/* DISENG_SIG1_SIGCRCGREENREF6: See SigCRCGreenRef0. */
#define     DISENG_SIG1_SIGCRCGREENREF6_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUEREF6: Reference signature of blue channel for evaluation window 6. */
#define     DISENG_SIG1_SIGCRCBLUEREF6 0x0000f8fcu
/* DISENG_SIG1_SIGCRCBLUEREF6: See SigCRCBlueRef0. */
#define     DISENG_SIG1_SIGCRCBLUEREF6_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCRED6: Measured signature of red channel for evaluation window 6. */
#define     DISENG_SIG1_SIGCRCRED6 0x0000f900u
/* DISENG_SIG1_SIGCRCRED6: See SigCRCRed0. */
#define     DISENG_SIG1_SIGCRCRED6_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREEN6: Measured signature of green channel for evaluation window 6. */
#define     DISENG_SIG1_SIGCRCGREEN6 0x0000f904u
#define     DISENG_SIG1_SIGCRCGREEN6_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUE6: Measured signature of blue channel for evaluation window 6. */
#define     DISENG_SIG1_SIGCRCBLUE6 0x0000f908u
#define     DISENG_SIG1_SIGCRCBLUE6_RESET 4294967295uL

/* DISENG_SIG1_EVALCONTROL7: Control settings for evaluation window 7. */
#define     DISENG_SIG1_EVALCONTROL7 0x0000f90cu

/* DISENG_SIG1_EVALUPPERLEFT7: Upper left corner of evaluation window 7. */
#define     DISENG_SIG1_EVALUPPERLEFT7 0x0000f910u

/* DISENG_SIG1_EVALLOWERRIGHT7: Lower right corner of evaluation window 7. */
#define     DISENG_SIG1_EVALLOWERRIGHT7 0x0000f914u

/* DISENG_SIG1_SIGCRCREDREF7: Reference signature of red channel for evaluation window 7. */
#define     DISENG_SIG1_SIGCRCREDREF7 0x0000f918u
/* DISENG_SIG1_SIGCRCREDREF7: See SigCRCRedRef0. */
#define     DISENG_SIG1_SIGCRCREDREF7_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREENREF7: Reference signature of green channel for evaluation window 7. */
#define     DISENG_SIG1_SIGCRCGREENREF7 0x0000f91cu
/* DISENG_SIG1_SIGCRCGREENREF7: See SigCRCGreenRef0. */
#define     DISENG_SIG1_SIGCRCGREENREF7_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUEREF7: Reference signature of blue channel for evaluation window 7. */
#define     DISENG_SIG1_SIGCRCBLUEREF7 0x0000f920u
/* DISENG_SIG1_SIGCRCBLUEREF7: See SigCRCBlueRef0. */
#define     DISENG_SIG1_SIGCRCBLUEREF7_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCRED7: Measured signature of red channel for evaluation window 7. */
#define     DISENG_SIG1_SIGCRCRED7 0x0000f924u
/* DISENG_SIG1_SIGCRCRED7: See SigCRCRed0. */
#define     DISENG_SIG1_SIGCRCRED7_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCGREEN7: Measured signature of green channel for evaluation window 7. */
#define     DISENG_SIG1_SIGCRCGREEN7 0x0000f928u
/* DISENG_SIG1_SIGCRCGREEN7: See SigCRCGreen0. */
#define     DISENG_SIG1_SIGCRCGREEN7_RESET 4294967295uL

/* DISENG_SIG1_SIGCRCBLUE7: Measured signature of blue channel for evaluation window 7. */
#define     DISENG_SIG1_SIGCRCBLUE7 0x0000f92cu
/* DISENG_SIG1_SIGCRCBLUE7: See SigCRCBlue0. */
#define     DISENG_SIG1_SIGCRCBLUE7_RESET 4294967295uL

/* DISENG_SIG1_SHADOWLOAD: Shadow load control register. */
#define     DISENG_SIG1_SHADOWLOAD 0x0000f930u
/* DISENG_SIG1_SHDLDREQ: Shadow load request for each evaluation window (bit index = window index). */
#define     DISENG_SIG1_SHDLDREQ_RESET 0x0uL

/* DISENG_SIG1_CONTINUOUSMODE: Signature operation mode control. */
#define     DISENG_SIG1_CONTINUOUSMODE 0x0000f934u
/* DISENG_SIG1_ENCONT: EnCont = 0: disables continuous mode. */
#define     DISENG_SIG1_ENCONT_RESET 0x0uL

/* DISENG_SIG1_SOFTWAREKICK: Signature measurement trigger. */
#define     DISENG_SIG1_SOFTWAREKICK 0x0000f938u
/* DISENG_SIG1_KICK: ContinueMode.EnCont=0: Write '1' to this field in order to start signature computation with next frame. */

#define     DISENG_SIG1_KICK_RESET 0x0uL

/* DISENG_SIG1_STATUS: Module status. */
#define     DISENG_SIG1_STATUS 0x0000f93cu
/* DISENG_SIG1_STSSIGERROR: Error status bits for all evaluation windows (bit index = window index). */
#define     DISENG_SIG1_STSSIGERROR_RESET 0x0uL

/* DISENG_SIG1_STSSIGVALID: Measured signature values are valid. */
#define     DISENG_SIG1_STSSIGVALID_RESET 0x0uL

/* DISENG_SIG1_STSSIGIDLE: StsSigIdle = 1: Signature is in Idle state. */

#define     DISENG_SIG1_STSSIGIDLE_RESET 1uL


/*! \endcond Hide for doxygen */

#endif /* MM_GDC_IRIS_IRIS_MGP_REGISTERS_H */

