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

  \file                 vmf_mi_mqx.h
  \brief                header of vmf mi connector for mqx

  \author               Joachim Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef __VMF_MI_MQX_H__
#define __VMF_IPC_H__

/* macrso */

#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
#define VMF_MI_DEVICE   "ttye:"
#else
#define VMF_MI_DEVICE   "ittye:"
#endif
#define VMF_MI_GROUPS   {VMF_TRACE_IN, VMF_TRACE_CTRL,1,2,4}

#define VALID_TOKEN         0xaa55
#define VALID_TOKEN0        0x55
#define VALID_TOKEN1        0xaa
#define START_TOKEN         0xbb        /* send by gateway to start communication */
#define VMF_MI_COMP_MIN     (100)
#define VMF_MI_MAX_Q_LEN    (50)

/* supported compression types */
enum VMF_MI_COMP_T
{
    COMP_MI_NO      = 0,                                        /* no cpmresssion                               */
    COMP_MI_LZWR3   = 1                                         /* lzwr version 3                               */
};

#define VMF_MI_VERISION_L                   02
#define VMF_MI_VERISION_H                   02

/* v2.2  vmf mi message transfer format  */
#pragma pack(push,1)
typedef struct
{
    unsigned8                               token0;             /* VALID_TOKEN0                                 */
    unsigned8                               token1;             /* VALID_TOKEN1                                 */
    unsigned8                               version_l;
    unsigned8                               version_h;
    unsigned8                               comp;               /* 0 = no compression, 1 = LZW                  */
    unsigned8                               reserved;
    unsigned8                               csum_l;             /* 0x0000 == ignore checksum                    */
    unsigned8                               csum_h;
    unsigned16                              svmf_len;           /* len of (vmf) message in bytes (little endian)*/
    svmf_msg_t                              svmf_msg;
}nw_vmf_mi_transfer_v2_t;


typedef struct
{
    unsigned8                               token0;             /* VALID_TOKEN0                                 */
    unsigned8                               token1;             /* VALID_TOKEN1                                 */
    unsigned8                               version_l;
    unsigned8                               version_h;
    unsigned8                               comp;               /* 0 = no compression, 1 = LZW                  */
    unsigned8                               reserved;
    unsigned8                               csum_l;             /* 0x0000 == ignore checksum                    */
    unsigned8                               csum_h;
    unsigned16                              svmf_len;           /* len of (vmf) message in bytes (little endian)*/
}nw_vmf_mi_transfer_v2_header_t;
#pragma pack(pop)






/* function prototypes */
BOOL vmf_mi_mqx_create_thread(void *param);
#endif

