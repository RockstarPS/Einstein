/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/

/*************************************************************************//**

  \file                 nw_vmf_nw_status_handler.h
  \brief                header file for vmf network status handler

  \author               Joachim Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef _NW_VMF_STAUS_HDLR_H
#define _NW_VMF_STAUS_HDLR_H


#define NW_STAT_HDLR_CENT_REG_ENTRIES   (100)

/* high byte of least significant word */
#define GET_HB(u16)                     (unsigned8)(((u16) >> 8) & 0xFF)

/* low byte of least significant word  */
#define GET_LB(u16)                     (unsigned8)((u16) & 0xFF)

#define NW_STAT_HDLR_DEF_DEV_ID         (0x100)
#define NW_STAT_HDLR_DEF_COUNT          (1)

#if 1
#define NW_VMF_STAT_DEBUG(verbose,args...)  {                                           \
                                                if (verbose <=1)                        \
                                                {                                       \
                                                    NW_VMF_DEBUG_ERROR(args);           \
                                                }                                       \
                                                else                                    \
                                                {                                       \
                                                    NW_VMF_DEBUG_PRINT("",verbose,args);\
                                                }                                       \
                                            }
#else
#define NW_VMF_STAT_DEBUG(verbose,args...)  {                                           \
                                                if (verbose <=1)                        \
                                                {                                       \
                                                    printf(args);                       \
                                                    fflush(ERROR_CHANNEL);                     \
                                                }                                       \
                                                else if (verbose <=3)                   \
                                                {                                       \
                                                    printf(args);                       \
                                                    fflush(ERROR_CHANNEL);                     \
                                                }                                       \
                                                else                                    \
                                                {                                       \
                                                }                                       \
                                            }
#endif

#pragma pack(push,1)

/*! Central-Registry entry */
typedef struct
{
    struct
    {
        unsigned8           h;                      /* device id high byte */
        unsigned8           l;                      /* device id low byte */
    }device_id;
    unsigned8           fblock_id;                  /* fblock id */
    unsigned8           inst_id;                    /* inst ID */
}vmf_stat_hdlr_cent_reg_entry_t;


/*! Cental Registry definition  */
typedef struct
{
    unsigned8                       num_entries;
    vmf_stat_hdlr_cent_reg_entry_t  cr_entry[NW_STAT_HDLR_CENT_REG_ENTRIES];
}vmf_stat_hdlr_cent_reg_t;

#pragma pack(pop)


/* global functions */
bool vmf_nw_status_create_thread(void);
vmf_client_id_t my_trhread_vmf_client_id_get(void);
#endif
