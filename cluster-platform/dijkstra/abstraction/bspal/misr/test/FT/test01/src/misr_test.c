
/*! \file */
/*
================================================================================

File: misr_test.c

$File:  $

================================================================================
Copyright (c) 2019 - 2020 Qualcomm Technologies, Inc.
All Rights Reserved.
Qualcomm Technologies Proprietary and Confidential.
================================================================================
*/

/* -----------------------------------------------------------------------------
 * Includes
 * ---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <WF/wfd.h>
#include <WF/wfdext2.h>

#include "CMisr_DK_BSPAL.h"

/* -----------------------------------------------------------------------------
 * Main
 * ---------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
    uint32_t eval_data[9], option, i=0;
    uint8_t sig_id = 0, win_id = 0;
    int32_t status = !EOK;
    ts_SSigUnitCfg_t cfg;
    ts_SSigUnitWinCfg_t EvWindow;
    ts_SSigUnitGetWinStatus_t crc_sts;

    while ((option = getopt(argc, argv, "s:w:c:h:")) != (uint32_t) -1)
        switch (option)
        {
        case 's':
            if (optarg != NULL)
            {
                sig_id = atoi(optarg);
            }
            else
            {
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                return 1;
            }
            break;
        case 'w':
            if (optarg != NULL)
            {
                win_id = atoi(optarg);
            }
            else
            {
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                return 1;
            }
            break;
        case 'c':
            if (optarg != NULL)
            {
                // Returns first token
                char *token = strtok(optarg, ",");
                while (token != NULL)
                {
                    eval_data[i] = (int)strtol(token, NULL, 16);
                    token = strtok(NULL, ",");
                    i++;
                }
                if (i != 9)
                {
                    fprintf(stderr, "Option -%c requires an 9 argument.\n", optopt);
                    return 1;
                }
                EvWindow.upperleft_x_U16 = eval_data[0];
                EvWindow.upperleft_y_U16 = eval_data[1];
                EvWindow.lowerright_x_U16 = eval_data[2];
                EvWindow.lowerright_y_U16 = eval_data[3];
                EvWindow.alpha_U8 = eval_data[4];
                EvWindow.action_U8 = eval_data[5];
                EvWindow.ref_crc.red_U32 = eval_data[6];
                EvWindow.ref_crc.green_U32 = eval_data[7];
                EvWindow.ref_crc.blue_U32 = eval_data[8];
//                (void) fprintf (stderr, "0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x",EvWindow.upperleft_x_U16, EvWindow.upperleft_y_U16, EvWindow.lowerright_x_U16,
//                                EvWindow.lowerright_y_U16, EvWindow.alpha_U8, EvWindow.action_U8, EvWindow.ref_crc.red_U32, EvWindow.ref_crc.green_U32, EvWindow.ref_crc.blue_U32);
            }
            else
            {
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                return 1;
            }
            break;
#if 0
        case 'h':
            help();
            return 1;
#endif
        case '?':
            if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf(stderr, "UnknDEBUGLOG(1,tion character `\\x%x'.\n", optopt);
            return 1;
        default:
            abort();
        }


    status = dk_bspal_sigunit_initialize(sig_id, &cfg);
    if(EOK == status)
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_initialize: PASS\n");
    }
    else
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_initialize: FAIL\n");
    }
    status = dk_bspal_sigunit_eval_win_stop(win_id);
    if(EOK == status)
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_eval_win_stop: PASS\n");
    }
    else
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_eval_win_stop: FAIL\n");
    }
    status = dk_bspal_sigunit_eval_win_setup(win_id,&EvWindow);
    if(EOK == status)
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: PASS\n");
    }
    else
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
    }
    status = dk_bspal_sigunit_eval_win_commit();
    if(EOK == status)
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_eval_win_commit: PASS\n");
    }
    else
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_eval_win_commit: FAIL\n");
    }


    /* Get ROI CRC */
    crc_sts = dk_bspal_sigunit_get_win_crc_sts(win_id);
        (void) fprintf (stderr, "MISR ROI CRC 0x%x\n", crc_sts.crc.rgb_crc_U32);

  return 0;
}

