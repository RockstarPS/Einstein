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

  \file                 vmf_trace_cli.c
  \brief                Main routine for test trace client

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
#include <sys/syspage.h>
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
 *   Main entry point for test trace cöient
 *
 *   \param[in]     argc -- number of arguments
 *   \param[in]     argv -- pointer to array with arguments
 *   \return        error code
 *
 ******************************************************************************/
int main(int argc, char *argv[])
{
    vmf_ret_t ret_val = 0;
    unsigned8   my_trid;
    unsigned8   my_trid2;
    unsigned8   my_trid3;
    unsigned8   my_trid4;
	unsigned8	my_sev=0;
	
    VMF_TRACE_INFO_PRINT("vmf_trace_client started\n");

    ret_val = vmf_trace_register(&my_trid,"test_cli");
    if (ret_val < 0)
    {
        VMF_TRACE_ERROR_PRINT("vmf_trace_register failed - ret=%d\n",ret_val);
    }

    ret_val = vmf_trace_register(&my_trid2,"test_cli2");
    if (ret_val < 0)
    {
        VMF_TRACE_ERROR_PRINT("vmf_trace_register failed - ret=%d\n",ret_val);
    }

    ret_val = vmf_trace_register(&my_trid3,"test_cli3");
    if (ret_val < 0)
    {
        VMF_TRACE_ERROR_PRINT("vmf_trace_register failed - ret=%d\n",ret_val);
    }

    ret_val = vmf_trace_register(&my_trid4,"test_cli4");
    if (ret_val < 0)
    {
        VMF_TRACE_ERROR_PRINT("vmf_trace_register failed - ret=%d\n",ret_val);
    }

    VMF_TRACE_INFO_PRINT("vmf_trace_client vmf_trace_register() OK - my_trid=%d\n",my_trid);

    while(1)
    {
    	unsigned8 data[]={0,1,2,3,4,5,6,7,8,9};
        vmf_trace_hex   (my_trid,my_sev,"tr1-ta1","hex",sizeof(data),data);
        vmf_trace_printf(my_trid,my_sev,"tr1-ta1","printf","%s,%d","string",my_sev);
        vmf_trace_printf(my_trid,my_sev,"tr1-ta1","printf","ohne arg");
        ret_val = vmf_trace(my_trid,my_sev,"tr1-ta1","tr1-ta1-sc1","tr1-ta1-sc1-test message");
	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }


        ret_val = vmf_trace(my_trid,my_sev++,"tr1-ta2","tr1-ta2-sc2","tr1-ta2-sc2-test message trace_client2");
	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }

        ret_val = vmf_trace(my_trid,my_sev++,"tr1-ta3","tr1-ta3-sc3","tr1-ta3-sc3-test message trace_client3");

	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }

// trid 2

        ret_val = vmf_trace(my_trid2,my_sev++,"tr2-ta1","tr2-ta1-sc1","tr2-ta1-sc1-test message");
	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }


        ret_val = vmf_trace(my_trid2,my_sev++,"tr2-ta2","tr2-ta2-sc2","tr2-ta2-sc2-test message trace_client2");
	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }

        ret_val = vmf_trace(my_trid2,my_sev++,"tr2-ta3","tr2-ta3-sc3","tr2-ta3-sc3-test message trace_client3");

	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }


// trid 3

        ret_val = vmf_trace(my_trid3,my_sev++,"tr3-ta1","tr3-ta1-sc1","tr3-ta1-sc1-test message");
	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }


        ret_val = vmf_trace(my_trid3,my_sev++,"tr3-ta2","tr3-ta2-sc2","tr3-ta2-sc2-test message trace_client2");
	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }

        ret_val = vmf_trace(my_trid3,my_sev++,"tr3-ta3","tr3-ta3-sc3","tr3-ta3-sc3-test message trace_client3");

	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }

// trid 4

        ret_val = vmf_trace(my_trid4,my_sev++,"tr4-ta1","tr4-ta1-sc1","tr4-ta1-sc1-test message");
	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }

        ret_val = vmf_trace(my_trid4,my_sev++,"tr4-ta2","tr4-ta2-sc2","tr4-ta2-sc2-test message trace_client2");
	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }

        ret_val = vmf_trace(my_trid4,my_sev++,"tr4-ta3","tr4-ta3-sc3","tr4-ta3-sc3-test message trace_client3");

	    if (ret_val < 0)
	    {
	        VMF_TRACE_ERROR_PRINT("vmf_trace_client - vmf_trace() failed - ret=%d\n",ret_val);
	    }

		if (my_sev > 120)
		{
			my_sev=0;
		}

		delay(100);
    }
    return (int)ret_val;
}


#undef _NW_VMF_SERVER_C_
