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

  \file                 vmf_trace_svr.c
  \brief                Main routine for test trace server

  \author               J. Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  \compiler             gcc
  \target               any

  *****************************************************************************/
#define _NW_VMF_SERVER_C_

/* QNX includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>
#include <pthread.h>

/* system includes */
#include "os_types.h"

/* application includes */
#include "nw_vmf_types.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_trace.h"

/***************************************************************************//**
 *
 *   Main entry point for test trace server
 *
 *   \param[in]     argc -- number of arguments
 *   \param[in]     argv -- pointer to array with arguments
 *   \return        error code
 *
 ******************************************************************************/
int main(int argc, char *argv[])
{
    vmf_ret_t ret_val = 0;

    VMF_TRACE_INFO_PRINT("vmf_trace_server started\n");

    /* start the router */
    if (VMF_OK != vmf_trace_server_create_thread())
    {
        ret_val = VMF_ERROR;
    }

    while(1)
    {
        delay(10000);
    }
    return (int)ret_val;
}


#undef _NW_VMF_SERVER_C_
