/******************************************************************************
*                                                                             *
*                   CONFIDENTIAL - Visteon Automotive Systems                 *
*                                                                             *
*  This is an unpublished work, which is a trade secret, created in 2007.     *
*  Visteon Automotive Systems owns all rights to this work and intends to     *
*  maintain it in confidence to preserve its trade secret status.  Visteon    *
*  Automotive Systems reserves the right to protect this work as an           *
*  unpublished copyrighted work in the event of an inadvertent or deliberate  *
*  unauthorized publication.  Visteon Automotive Systems also reserves        *
*  its rights under the copyright laws to protect this work as a published    *
*  work.  Those having access to this work may not copy it, use it, or        *
*  disclose the information contained in it without the written authorization *
*  of Visteon Automotive Systems.                                             *
*                                                                             *
*******************************************************************************
*  PROJECT NAME :  VMF                                                        *
*******************************************************************************
*  MODULE NAME  :  nw_vmf_tardis.h                                            *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   23th April 2013                                           *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  header file of vmf tardis                                                  *
******************************************************************************/
#ifndef __VMF_TARDIS_H
#define __VMF_TARDIS_H

#define VMF_TARDIS_PORT         56567
#define VMF_TL_TARDIS_PORT      56568
#define VMF_TL_TARDIS_PORT_NUM  5


#define VMF_TARDIS_BUF_LEN      50
#define VMF_MAX_TARDIS_NAME_LEN 20


/* protocol offsets */
#define VMF_TARDIS_OS_DIR       0
#define VMF_TARDIS_OS_CMD       1
#define VMF_TARDIS_OS_PH        2
#define VMF_TARDIS_OS_PL        3

/* VMF_TARDIS_TIME_SYNC offsets */
#define VMF_TARDIS_TS_HH        2   /* high high byte of time */
#define VMF_TARDIS_TS_HL        2   /* high low  byte of time */
#define VMF_TARDIS_TS_LH        2   /* low high  byte of time */
#define VMF_TARDIS_TS_LL        2   /* low low   byte of time */

/* valid directions */
#define VMF_TARDIS_DIR_TAR2TOOL  0x5a
#define VMF_TARDIS_DIR_TAR2TAR   0x55
#define VMF_TARDIS_DIR_TOOL2AR   0xa5
#define VMF_TARDIS_DIR_TOOL2TOOL 0xaa

/* valid commands */
enum
{
    VMF_TARDIS_INVALID = 0,
    VMF_TARDIS_NAME_REQUEST   = 1,  /* request a single or all target names and IP addresses */
    VMF_TARDIS_NAME_RESPONSE  = 2,  /* Name response from target */
    VMF_TARDIS_TIME_REQUEST   = 3,  /* VMF time reuest */
    VMF_TARDIS_TIME_RESPONSE  = 4,  /* VMF time response */
    VMF_TARDIS_START_MONITORING=5,  /* Start Tracer/Spy */
    VMF_TARDIS_SYSINFO_REQUEST =6,  /* VMF system info request */
    VMF_TARDIS_SYSINFO_RESPONSE=7,  /* VMF system info response */

    VMF_TARDIS_BYE_BYE=0xF0         /* Send before ending VMF Tool */
};


/* target class */
enum
{
    VMF_TARDIS_TC_INVALID = 0,
    VMF_TARDIS_TC_HU=1,         /* head unit */
    VMF_TARDIS_TC_DIAG=2,       /* Diag tester */
    VMF_TARDIS_TC_MEDIA=3,      /* media player */
    VMF_TARDIS_TC_TOOL=4        /* VMF tool */
};


/* global function prototypes */
vmf_ret_t nw_vmf_create_tardis_thread (void);


#endif


