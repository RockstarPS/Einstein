/*============================================================================
 **
 **  \file misr_ti_test.c
 **
 **  \brief Interface to interact with the Signature Unit of iMX8
 **
 **  Component Name: Signature Unit
 **  Date: SEP 10 2024
 **  Author: DAMUDHAR
 **
 ** @Version
 ** 21OCT2024   | PKRISH12 |  TFDCX32348-50216 | Ported for TIAM62P - Linux platform. 
 **==========================================================================*/
/* -----------------------------------------------------------------------------
 * Includes
 * ---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <xf86drm.h>

#ifdef LINUX_PLATFORM	
#include <fcntl.h>
#include <sys/ioctl.h>
#include "CSigUnit_Ioctl.h"
#elif defined(QNX_PLATFORM)
#include <sys/syspage.h>
#include <screen/screen.h>
#include "CSigUnit_Cfg.h"
#endif 
#include "CSigUnit_DK_BSPAL.h"
#include "dk_logger.h"
#define SIGUINIT_ID    (uint8_t)0

#ifdef QNX_PLATFORM
screen_context_t screen_ctx = NULL;
screen_display_t *screen_disps = NULL;
screen_display_t screen_disp = NULL;
#endif 

int screen_size[2] = { 0 };
int display = 1;

#ifdef QNX_PLATFORM	
int check_display(void)
{
    int temp;
    int n_display = 0;

    (void)fprintf(stderr, "check_display start\n");

    if(screen_create_context(&screen_ctx, SCREEN_APPLICATION_CONTEXT) < 0) {
        fprintf(stderr, "screen_create_context() failed (%s)\n", strerror(errno));
        return -1;
    }

    if(screen_get_context_property_iv(screen_ctx, SCREEN_PROPERTY_DISPLAY_COUNT, &n_display) < 0) {
        fprintf(stderr, "screen_get_context_property_iv(SCREEN_PROPERTY_DISPLAY_COUNT) failed (%s)\n", strerror(errno));
        return -1;
    }

    if(!(screen_disps = calloc(n_display, sizeof(screen_display_t)))) {
        fprintf(stderr, "calloc() failed (%s)\n", strerror(errno));
        return -1;
    }

    if(screen_get_context_property_pv(screen_ctx, SCREEN_PROPERTY_DISPLAYS, (void **)screen_disps) < 0) {
        fprintf(stderr, "screen_get_context_property_iv(SCREEN_PROPERTY_DISPLAYS) failed (%s)\n", strerror(errno));
        return -1;
    }

    for(int i = 0; i < n_display; i++) {
        if(screen_get_display_property_iv(screen_disps[i], SCREEN_PROPERTY_ID, &temp) < 0) {
            fprintf(stderr, "screen_get_display_property_iv(SCREEN_PROPERTY_ID) failed (%s)\n", strerror(errno));
            return -1;
        }
        if(temp == display) {
            screen_disp = screen_disps[i];
            break;
        }
    }

    if(screen_disp) {
        if(screen_get_display_property_iv(screen_disp, SCREEN_PROPERTY_SIZE, screen_size) < 0) {
            fprintf(stderr, "screen_get_display_property_iv(SCREEN_PROPERTY_SIZE) failed (%s)\n", strerror(errno));
            return -1;
        }
    } else {
        fprintf(stderr, "Invalid display id\n");
        return -1;
    }

    (void)fprintf(stderr, "check_display screen_disp is %d end\n",screen_disp);

    return screen_disp ? 0 : -1;
}
#endif

int wait_for_vsync(int drm_fd) 
{
    drmVBlank vblank = {0};
    vblank.request.type = DRM_VBLANK_RELATIVE;
    vblank.request.sequence = 1;

    if (drmWaitVBlank(drm_fd, &vblank) != 0) 
	{
        fprintf(stderr, "drmWaitVBlank failed: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}
/* -----------------------------------------------------------------------------
 * Main
 * ---------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
    uint32_t eval_data[11], option, i=0;
    uint8_t sig_id = 0, win_id = 0;
    int32_t status = !EOK;
    ts_SSigUnitCfg_t cfg;
    ts_SSigUnitWinCfg_t EvWindow;
    ts_SSigUnitGetWinStatus_t crc_sts;
    int32_t drm_fd;

    drm_fd = open("/dev/dri/card0", O_RDWR | O_CLOEXEC);
    if (drm_fd < 0) {
        perror("Cannot open /dev/dri/card0");
        return -1;
    }

    LOG_REGISTER_APP_SLOG2("SigUnitFT","BSPALSigUnit TEST");
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
                        if (i != 11) {
                        fprintf(stderr, "Option -%c requires 11 arguments.\n", optopt);
                        return 1;
                    }
                        EvWindow.upperleft_x_U16 = (uint16_t)eval_data[0];
                        EvWindow.upperleft_y_U16 = (uint16_t)eval_data[1];
                        EvWindow.lowerright_x_U16 = (uint16_t)eval_data[2];
                        EvWindow.lowerright_y_U16 = (uint16_t)eval_data[3];
                        EvWindow.ref_crc.red_U32 = eval_data[4];
                        //EvWindow.safetyChkEnable_U8 = (uint8_t)eval_data[5];
                        //EvWindow.safetyChkMode_U8 = (uint8_t)eval_data[6];
                        //EvWindow.seedSelectEnable_U8 = (uint8_t)eval_data[7];
                        EvWindow.alpha_U8 = (uint16_t)eval_data[8];
                        EvWindow.action_U8 = (uint8_t)eval_data[9];
                        cfg.panic_rgba_U32 = eval_data[10];

                        (void)fprintf(stderr, "upperleft_x_U16 0x%x, upperleft_y_U16 0x%x, lowerright_x_U16 0x%x, lowerright_y_U16 0x%x, red_U32 0x%x, alpha_U8 0x%x, action_U8 0x%x, panic_rgba_U32 0x%x\n",
                         EvWindow.upperleft_x_U16, EvWindow.upperleft_y_U16, EvWindow.lowerright_x_U16,
                         EvWindow.lowerright_y_U16, EvWindow.ref_crc.red_U32, EvWindow.alpha_U8,
                         EvWindow.action_U8, cfg.panic_rgba_U32);

                        //fprintf(stderr, "safetyChkEnable_U8 0x%x, safetyChkMode_U8 0x%x, seedSelectEnable_U8 0x%x\n",
                        //        EvWindow.safetyChkEnable_U8, EvWindow.safetyChkMode_U8, EvWindow.seedSelectEnable_U8);

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
                fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
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
    status = dk_bspal_sigunit_eval_win_setup(win_id, &EvWindow);
    if (EOK == status)
    {
        (void)fprintf(stderr, "dk_bspal_sigunit_eval_win_setup: PASS\n");
    }
    else
    {
        (void)fprintf(stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
        return 1;
    }
    status = dk_bspal_sigunit_eval_win_start(win_id);
    if (EOK == status)
    {
        (void)fprintf(stderr, "win_id is %d dk_bspal_sigunit_eval_win_start: PASS\n", win_id);

#ifdef QNX_PLATFORM
    (void)fprintf(stderr, "screen_wait_vsync 1\n");
    screen_wait_vsync(screen_disp);
    (void)fprintf(stderr, "screen_wait_vsync 2\n");
    screen_wait_vsync(screen_disp);
    (void)fprintf(stderr, "screen_wait_vsync 3\n");
    screen_wait_vsync(screen_disp);
#endif  
     
 
        if (wait_for_vsync(drm_fd) != 0)
        {
             fprintf(stderr, "VSYNC wait failed\n");
        }

        close(drm_fd);
        crc_sts = dk_bspal_sigunit_get_win_crc_sts(win_id);
        (void) fprintf (stderr, "MISR ROI CRC 0x%x\n", crc_sts.crc.red_U32);
        status = dk_bspal_sigunit_eval_win_stop(win_id);
        if(EOK == status)
        {
        (void) fprintf (stderr, "win_id is %d dk_bspal_sigunit_eval_win_stop: PASS\n",win_id);	
        }
        else
        {
        (void) fprintf (stderr, "win_id is %d dk_bspal_sigunit_eval_win_stop: FAIL\n",win_id);
        }
    }
    else
    {
        (void)fprintf(stderr, "win_id is %d dk_bspal_sigunit_eval_win_start: FAIL\n", win_id);
        return 1;
    }
    return 0;
}
