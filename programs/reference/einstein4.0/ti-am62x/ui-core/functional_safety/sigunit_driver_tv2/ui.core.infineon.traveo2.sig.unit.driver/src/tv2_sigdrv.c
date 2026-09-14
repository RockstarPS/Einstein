/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2021. Visteon Corporation owns all rights to this work and
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
 ** Name:           tv2_sigdrv.c
 **
 ** Description:    This module will be useful to Read/Write the Signature
 **                 Unit related registers. 
 **
 ** Organization:   User Experience COC, Visteon.
 **
 **============================================================================
 **
 **==========================================================================*/
#define TV2_SIGDRV_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "tv2_sigdrv.h"
#include "cygfx_defines.h"
#include "gfxreg_videoss_addressmap.h"
#include "gfxreg_disengcfg_register.h"
#include "gfxreg_sig_register.h"
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/
#define SIG_REG_READ32(ADDR)          (*((volatile uint32_t *)(ADDR)))
#define SIG_REG_WRITE32(ADD, VAL)     (*((volatile uint32_t*)(ADD)) = (VAL))

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/
#if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
/*! 
  * \brief unlock sig unit for writing
 */
void iris_sigdrv_sig0_unlock(void)
{
}
void iris_sigdrv_sig0_lock(void)
{
}
void iris_sigdrv_sig0_initialize(SIG_SETUP_T const * const p_setup)
{
    uint32_t reset =(uint32_t)p_setup->reset_threshold;
    uint32_t error =(uint32_t)p_setup->error_threshold;
    uint32_t threshold = (reset <<24)|(error<<16)|(uint32_t)0x01;
   /*Dynamic Continuous mode*/
   /*Set the input Source Select point for signature unit#0 as after Frame Generator.*/
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_DISENGCFG_BASE + GFXREG_DISENGCFG_SIGSELECT),(p_setup->source &SIG_SOURCE_MASK));
   /*Set panic RGBA colour values.*/
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +  GFXREG_SIG_PANICCOLOR), (p_setup->panic_rgba & SIG_PANIC_COLOR_MASK));
   /*Set ShdEn(Bit0) and ShdLdSel(Bit4) as LOCAL(0-default) in Static Control Register alongwith threshold values.*/
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATICCONTROL), threshold);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_CONTINUOUSMODE),(uint32_t)0);
}
/*
\fn  void iris_sigdrv_sig0_uninitialize(void)
\brief [9, 10] Turn off measurement steps.
*/
void iris_sigdrv_sig0_uninitialize(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_CONTINUOUSMODE),(uint32_t)0);
    /*
    Poll StsSigIdle status field until unit is idle.
    StsSigIdle(Bit#20) = 1: Signature is in Idle state(default). StsSigIdle = 0: Signature runs.
    */
    while((SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATUS)& SIG_IDLE_STATUS_MASK)==(uint32_t)0)
    {
        ;
    }
}
void iris_sigdrv_sig0_set_cnt_mode(void)
{
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_CONTINUOUSMODE),(uint32_t)1);
}

void iris_sigdrv_sig0_clear_cnt_mode(void)
{
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_CONTINUOUSMODE),(uint32_t)0);
}

uint32_t iris_sigdrv_sig0_get_win_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATUS)& (uint32_t)SIG_WIN_STATUS_MASK);
    return(win_status); 
}
/*
Shadow load request for each evaluation window (bit index = window index). 
Writing a '1' to a bit will load the shadows into the active configuration for that window at start of next frame.
Writing a '0' has no effect. The flag is reset by HW once the shadows have been loaded. 
A shadow load interrupt signal is generated when shadows have been loaded for at least one evaluation window. 
Has only effect when ShdLdSel is set to LOCAL.
*/
void iris_sigdrv_sig0_ldcfg_win0(void)
{ 
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN0_BIT));
}
void iris_sigdrv_sig0_setup_win0(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;
   /* Restrict the window sx, sy, ex and ey 14bits each.*/
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALCONTROL0),    eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT0),  ((((uint32_t)p_swconf->winsy & SIG_WIN_CORDINATE_MASK)<<16)|(((uint32_t)p_swconf->winsx & SIG_WIN_CORDINATE_MASK))));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT0), ((((uint32_t)p_swconf->winey & SIG_WIN_CORDINATE_MASK)<<16)|(((uint32_t)p_swconf->winex & SIG_WIN_CORDINATE_MASK))));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF0),   p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF0), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF0),  p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig0_get_win0_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATUS)& (uint32_t)SIG_WIN0_BIT);
    return(win_status); 
}
uint32_t iris_sigdrv_sig0_get_win0_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCRED0));
}
uint32_t iris_sigdrv_sig0_get_win0_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN0));
}
uint32_t iris_sigdrv_sig0_get_win0_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE0));
}

void iris_sigdrv_sig0_ldcfg_win1(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN1_BIT));
}
void iris_sigdrv_sig0_setup_win1(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALCONTROL1), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT1), ((((uint32_t)p_swconf->winsy & SIG_WIN_CORDINATE_MASK )<<16)|((uint32_t)p_swconf->winsx & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT1), ((((uint32_t)p_swconf->winey & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF1),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF1), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF1), p_swconf->crc_ref_b); 
}
uint32_t iris_sigdrv_sig0_get_win1_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN1_BIT);
    return(win_status); 
}
uint32_t iris_sigdrv_sig0_get_win1_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCRED1));
}
uint32_t iris_sigdrv_sig0_get_win1_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN1));
}
uint32_t iris_sigdrv_sig0_get_win1_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE1));
}

void iris_sigdrv_sig0_ldcfg_win2(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN2_BIT));
}

void iris_sigdrv_sig0_setup_win2(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALCONTROL2), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT2),((((uint32_t)p_swconf->winsy  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winsx  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT2), ((((uint32_t)p_swconf->winey  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF2),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF2), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF2), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig0_get_win2_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN2_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig0_get_win2_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCRED2));
}

uint32_t iris_sigdrv_sig0_get_win2_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN2));
}

uint32_t iris_sigdrv_sig0_get_win2_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE2));
}

void iris_sigdrv_sig0_ldcfg_win3(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN3_BIT));
}

void iris_sigdrv_sig0_setup_win3(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALCONTROL3), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT3),((((uint32_t)p_swconf->winsy & SIG_WIN_CORDINATE_MASK )<<16)|((uint32_t)p_swconf->winsx & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT3), ((((uint32_t)p_swconf->winey & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF3),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF3), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF3), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig0_get_win3_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN3_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig0_get_win3_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCRED3));
}

uint32_t iris_sigdrv_sig0_get_win3_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN3));
}

uint32_t iris_sigdrv_sig0_get_win3_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE3));
}

void iris_sigdrv_sig0_ldcfg_win4(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN4_BIT));
}

void iris_sigdrv_sig0_setup_win4(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALCONTROL4), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT4),((((uint32_t)p_swconf->winsy & SIG_WIN_CORDINATE_MASK)<<16 )|((uint32_t)p_swconf->winsx  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT4), ((((uint32_t)p_swconf->winey  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF4),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF4), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF4), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig0_get_win4_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN4_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig0_get_win4_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCRED4));
}

uint32_t iris_sigdrv_sig0_get_win4_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN4));
}

uint32_t iris_sigdrv_sig0_get_win4_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE4));
}

void iris_sigdrv_sig0_ldcfg_win5(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN5_BIT));
}

void iris_sigdrv_sig0_setup_win5(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALCONTROL5), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT5),((((uint32_t)p_swconf->winsy  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winsx & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT5), ((((uint32_t)p_swconf->winey  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF5),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF5), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF5), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig0_get_win5_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN5_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig0_get_win5_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCRED5));
}

uint32_t iris_sigdrv_sig0_get_win5_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN5));
}

uint32_t iris_sigdrv_sig0_get_win5_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE5));
}

void iris_sigdrv_sig0_ldcfg_win6(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN6_BIT));
}

void iris_sigdrv_sig0_setup_win6(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALCONTROL6), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT6),((((uint32_t)p_swconf->winsy  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winsx  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT6), ((((uint32_t)p_swconf->winey  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF6),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF6), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF6), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig0_get_win6_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN6_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig0_get_win6_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCRED6));
}

uint32_t iris_sigdrv_sig0_get_win6_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN6));
}

uint32_t iris_sigdrv_sig0_get_win6_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE6));
}

void iris_sigdrv_sig0_ldcfg_win7(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN7_BIT));
}

void iris_sigdrv_sig0_setup_win7(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALCONTROL7), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT7),((((uint32_t)p_swconf->winsy  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winsx  & SIG_WIN_CORDINATE_MASK )));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT7), ((((uint32_t)p_swconf->winey  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF7),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF7), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF7), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig0_get_win7_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN7_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig0_get_win7_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCRED7));
}

uint32_t iris_sigdrv_sig0_get_win7_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN7));
}

uint32_t iris_sigdrv_sig0_get_win7_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG0_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE7));
}

#endif

#if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
/* -------------- SIG1 unit  -------------- */
/*! 
  * \brief unlock sig unit for writing
 */
void iris_sigdrv_sig1_unlock(void)
{
}
void iris_sigdrv_sig1_lock(void)
{
}
void iris_sigdrv_sig1_initialize(SIG_SETUP_T const * const p_setup)
{
    uint32_t reset =(uint32_t)p_setup->reset_threshold;
    uint32_t error =(uint32_t)p_setup->error_threshold;
    uint32_t threshold = (reset <<24)|(error<<16)|(uint32_t)0x01;
   /*Dynamic Continuous mode*/
   /*Set the input Source Select point for signature unit#0 as after Frame Generator.*/
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_DISENGCFG_BASE + GFXREG_DISENGCFG_SIGSELECT),(p_setup->source &SIG_SOURCE_MASK));
   /*Set panic RGBA colour values.*/
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +  GFXREG_SIG_PANICCOLOR), (p_setup->panic_rgba & SIG_PANIC_COLOR_MASK));
   /*Set ShdEn(Bit0) and ShdLdSel(Bit4) as LOCAL(0-default) in Static Control Register alongwith threshold values.*/
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATICCONTROL), threshold);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_CONTINUOUSMODE),(uint32_t)0);
}
/*
\fn  void iris_sigdrv_sig0_uninitialize(void)
\brief [9, 10] Turn off measurement steps.
*/
void iris_sigdrv_sig1_uninitialize(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_CONTINUOUSMODE),(uint32_t)0);
    /*
    Poll StsSigIdle status field until unit is idle.
    StsSigIdle(Bit#20) = 1: Signature is in Idle state(default). StsSigIdle = 0: Signature runs.
    */
    while((SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATUS)& SIG_IDLE_STATUS_MASK)==(uint32_t)0)
    {
        ;
    }
}
void iris_sigdrv_sig1_set_cnt_mode(void)
{
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_CONTINUOUSMODE),(uint32_t)1);
}

void iris_sigdrv_sig1_clear_cnt_mode(void)
{
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_CONTINUOUSMODE),(uint32_t)0);
}

uint32_t iris_sigdrv_sig1_get_win_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATUS)& (uint32_t)SIG_WIN_STATUS_MASK);
    return(win_status); 
}
/*
Shadow load request for each evaluation window (bit index = window index). 
Writing a '1' to a bit will load the shadows into the active configuration for that window at start of next frame.
Writing a '0' has no effect. The flag is reset by HW once the shadows have been loaded. 
A shadow load interrupt signal is generated when shadows have been loaded for at least one evaluation window. 
Has only effect when ShdLdSel is set to LOCAL.
*/
void iris_sigdrv_sig1_ldcfg_win0(void)
{ 
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN0_BIT));
}
void iris_sigdrv_sig1_setup_win0(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;
   /* Restrict the window sx, sy, ex and ey 14bits each.*/
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALCONTROL0),    eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT0),  ((((uint32_t)p_swconf->winsy & SIG_WIN_CORDINATE_MASK)<<16)|(((uint32_t)p_swconf->winsx & SIG_WIN_CORDINATE_MASK))));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT0), ((((uint32_t)p_swconf->winey & SIG_WIN_CORDINATE_MASK)<<16)|(((uint32_t)p_swconf->winex & SIG_WIN_CORDINATE_MASK))));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF0),   p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF0), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF0),  p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig1_get_win0_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATUS)& (uint32_t)SIG_WIN0_BIT);
    return(win_status); 
}
uint32_t iris_sigdrv_sig1_get_win0_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCRED0));
}
uint32_t iris_sigdrv_sig1_get_win0_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN0));
}
uint32_t iris_sigdrv_sig1_get_win0_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE0));
}

void iris_sigdrv_sig1_ldcfg_win1(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN1_BIT));
}
void iris_sigdrv_sig1_setup_win1(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALCONTROL1), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT1), ((((uint32_t)p_swconf->winsy & SIG_WIN_CORDINATE_MASK )<<16)|((uint32_t)p_swconf->winsx & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT1), ((((uint32_t)p_swconf->winey & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF1),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF1), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF1), p_swconf->crc_ref_b); 
}
uint32_t iris_sigdrv_sig1_get_win1_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN1_BIT);
    return(win_status); 
}
uint32_t iris_sigdrv_sig1_get_win1_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCRED1));
}
uint32_t iris_sigdrv_sig1_get_win1_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN1));
}
uint32_t iris_sigdrv_sig1_get_win1_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE1));
}

void iris_sigdrv_sig1_ldcfg_win2(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN2_BIT));
}

void iris_sigdrv_sig1_setup_win2(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALCONTROL2), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT2),((((uint32_t)p_swconf->winsy  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winsx  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT2), ((((uint32_t)p_swconf->winey  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF2),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF2), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF2), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig1_get_win2_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN2_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig1_get_win2_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCRED2));
}

uint32_t iris_sigdrv_sig1_get_win2_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN2));
}

uint32_t iris_sigdrv_sig1_get_win2_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE2));
}

void iris_sigdrv_sig1_ldcfg_win3(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN3_BIT));
}

void iris_sigdrv_sig1_setup_win3(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALCONTROL3), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT3),((((uint32_t)p_swconf->winsy & SIG_WIN_CORDINATE_MASK )<<16)|((uint32_t)p_swconf->winsx & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT3), ((((uint32_t)p_swconf->winey & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF3),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF3), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF3), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig1_get_win3_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN3_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig1_get_win3_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCRED3));
}

uint32_t iris_sigdrv_sig1_get_win3_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN3));
}

uint32_t iris_sigdrv_sig1_get_win3_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE3));
}

void iris_sigdrv_sig1_ldcfg_win4(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN4_BIT));
}

void iris_sigdrv_sig1_setup_win4(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALCONTROL4), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT4),((((uint32_t)p_swconf->winsy & SIG_WIN_CORDINATE_MASK)<<16 )|((uint32_t)p_swconf->winsx  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT4), ((((uint32_t)p_swconf->winey  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF4),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF4), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF4), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig1_get_win4_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN4_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig1_get_win4_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCRED4));
}

uint32_t iris_sigdrv_sig1_get_win4_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN4));
}

uint32_t iris_sigdrv_sig1_get_win4_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE4));
}

void iris_sigdrv_sig1_ldcfg_win5(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN5_BIT));
}

void iris_sigdrv_sig1_setup_win5(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALCONTROL5), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT5),((((uint32_t)p_swconf->winsy  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winsx & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT5), ((((uint32_t)p_swconf->winey  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF5),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF5), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF5), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig1_get_win5_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN5_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig1_get_win5_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCRED5));
}

uint32_t iris_sigdrv_sig1_get_win5_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN5));
}

uint32_t iris_sigdrv_sig1_get_win5_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE5));
}

void iris_sigdrv_sig1_ldcfg_win6(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN6_BIT));
}

void iris_sigdrv_sig1_setup_win6(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALCONTROL6), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT6),((((uint32_t)p_swconf->winsy  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winsx  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT6), ((((uint32_t)p_swconf->winey  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF6),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF6), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF6), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig1_get_win6_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN6_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig1_get_win6_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCRED6));
}

uint32_t iris_sigdrv_sig1_get_win6_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN6));
}

uint32_t iris_sigdrv_sig1_get_win6_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE6));
}

void iris_sigdrv_sig1_ldcfg_win7(void)
{
    SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD),((*(uint32_t *)(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SHADOWLOAD))| SIG_WIN7_BIT));
}

void iris_sigdrv_sig1_setup_win7(SIG_WIN_SETUP_T const * const p_swconf)
{
   uint32_t eval_ctrl=(SIG_ENABLE_EVWIN|SIG_ENABLE_CRC|SIG_ENABLE_ALPHAMASK|SIG_ENABLE_ALPHAINV|SIG_ENABLE_LOCALPANIC);

   eval_ctrl &=p_swconf->control;

   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALCONTROL7), eval_ctrl);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALUPPERLEFT7),((((uint32_t)p_swconf->winsy  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winsx  & SIG_WIN_CORDINATE_MASK )));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_EVALLOWERRIGHT7), ((((uint32_t)p_swconf->winey  & SIG_WIN_CORDINATE_MASK)<<16)|((uint32_t)p_swconf->winex  & SIG_WIN_CORDINATE_MASK)));
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCREDREF7),  p_swconf->crc_ref_r); 
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREENREF7), p_swconf->crc_ref_g);
   SIG_REG_WRITE32((GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUEREF7), p_swconf->crc_ref_b); 
}

uint32_t iris_sigdrv_sig1_get_win7_status(void)
{
    uint32_t win_status = (SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_STATUS)&(uint32_t)SIG_WIN7_BIT);
    return(win_status); 
}

uint32_t iris_sigdrv_sig1_get_win7_crc_r(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCRED7));
}

uint32_t iris_sigdrv_sig1_get_win7_crc_g(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCGREEN7));
}

uint32_t iris_sigdrv_sig1_get_win7_crc_b(void)
{
    return(SIG_REG_READ32(GFXREG_VIDEOIO_DISENG1_SIG_BASE +     GFXREG_SIG_SIGCRCBLUE7));
}

#endif


/*============================================================================
 **
 **============================================================================
 ** C M S    R E V I S I O N    N O T E S
 **============================================================================
 **
 ** For each change to this file, be sure to record:
 ** 1.  Who made the change and when the change was made.
 ** 2.  Why the change was made and the intended result.
 **
 ** CMS Rev #        Date         By
 ** CMS Rev X.X      mm/dd/yy     CDSID
 **
 **============================================================================

 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
