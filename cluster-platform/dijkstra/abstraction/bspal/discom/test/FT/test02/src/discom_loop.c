#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <img/img.h>
#include <screen/screen.h>

#include "CDiscom_DK_BSPAL.h"

static uint32_t xz_crc32_table[256];

int display = 1;
int n_display = 0;
int pipeline = -1;
int uif_rect[4] = { 0 };

int usage = SCREEN_USAGE_NATIVE;
int format = SCREEN_FORMAT_RGBX8888;

int screen_size[2] = { 0 };
int image_size[2] = { 0 };

char image_path[50] =  { 0 };
char l_image_path[36][30] =  {
	"/tmp/L_Turn.png",
	"/tmp/R_Turn.png",
	"/tmp/Rear_Fog.png",
	"/tmp/SSA_Grey.png",
	"/tmp/SSA_Green.png",
	"/tmp/Feb_EAP_Off.png",
	"/tmp/ShBW.png",
	"/tmp/PMenu_P.png",
	"/tmp/PMenu_R.png",
	"/tmp/PMenu_N.png",
	"/tmp/PMenu_D.png",
	"/tmp/PMenu_L.png",
	"/tmp/PMenu_1.png",
	"/tmp/PMenu_2.png",
	"/tmp/PMenu_3.png",
	"/tmp/PMenu_4.png",
	"/tmp/PMenu_5.png",
	"/tmp/PMenu_6.png",
	"/tmp/PMenu_7.png",
	"/tmp/PMenu_8.png",
	"/tmp/PMenu_9.png",
	"/tmp/GShift_P.png",
	"/tmp/GShift_R.png",
	"/tmp/GShift_N.png",
	"/tmp/GShift_D.png",
	"/tmp/GShift_L.png",
	"/tmp/GShift_1.png",
	"/tmp/GShift_2.png",
	"/tmp/GShift_3.png",
	"/tmp/GShift_4.png",
	"/tmp/GShift_5.png",
	"/tmp/GShift_6.png",
	"/tmp/GShift_7.png",
	"/tmp/GShift_8.png",
	"/tmp/GShift_9.png"
	};

ts_SSigUnitWinCfg_t data[36] = {
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x17, .lowerright_y_U16 = 0x14},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x17, .lowerright_y_U16 = 0x14},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x14, .lowerright_y_U16 = 0x16},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x22, .lowerright_y_U16 = 0xB},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x22, .lowerright_y_U16 = 0xB},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x13, .lowerright_y_U16 = 0xA},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x18, .lowerright_y_U16 = 0x8},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x8, .lowerright_y_U16 = 0x4},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x5, .lowerright_y_U16 = 0x3},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x3, .lowerright_y_U16 = 0x9},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x6, .lowerright_y_U16 = 0x4},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x4, .lowerright_y_U16 = 0x4},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x6, .lowerright_y_U16 = 0xA},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0xE, .lowerright_y_U16 = 0x6},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0xE, .lowerright_y_U16 = 0x3},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x5, .lowerright_y_U16 = 0xB},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x20, .lowerright_y_U16 = 0x2},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x18, .lowerright_y_U16 = 0x3},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0xF, .lowerright_y_U16 = 0x2},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x9, .lowerright_y_U16 = 0x5},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0xA, .lowerright_y_U16 = 0x4},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0xA, .lowerright_y_U16 = 0x2},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x9, .lowerright_y_U16 = 0x5},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x4, .lowerright_y_U16 = 0xA},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x3, .lowerright_y_U16 = 0x7},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0xB, .lowerright_y_U16 = 0x4},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x5, .lowerright_y_U16 = 0xA},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0xD, .lowerright_y_U16 = 0x3},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x9, .lowerright_y_U16 = 0x4},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x8, .lowerright_y_U16 = 0x3},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x9, .lowerright_y_U16 = 0x3},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x11, .lowerright_y_U16 = 0x2},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0xB, .lowerright_y_U16 = 0x5},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x13, .lowerright_y_U16 = 0x2},
		{.upperleft_x_U16 = 0, .upperleft_y_U16 = 0, .lowerright_x_U16 = 0x5, .lowerright_y_U16 = 0x3}
};

struct crc32_info {
    void *pbuf;
    size_t stride;
    uint32_t expect;
    uint32_t actual;
} crc32;

screen_context_t screen_ctx = NULL;
screen_display_t *screen_disps = NULL;
screen_display_t screen_disp = NULL;
screen_window_t screen_win = NULL;
screen_buffer_t screen_buf[2];

extern void xz_crc32_init(void);
extern uint32_t xz_crc32(const uint8_t *buf, size_t size, uint32_t crc);

uint32_t calculate_crc(void)
{
    void* p_roi;
    uint32_t crc = 0;
    uint32_t img_rect[4] = { 0 };

    memcpy(img_rect, uif_rect, 4 * sizeof(int));

    p_roi = crc32.pbuf + (img_rect[0] * 4);
    p_roi += crc32.stride * img_rect[1];

    for(uint32_t row = 0; row < img_rect[3]; row++) {
        crc = xz_crc32(p_roi, img_rect[2] * 4, crc);
        p_roi += crc32.stride;
    }

    return crc;
}

int display_image(void)
{
    int dirty[4] = { 0 };

    if(screen_get_window_property_pv(screen_win, SCREEN_PROPERTY_RENDER_BUFFERS, (void **)screen_buf) < 0) {
        fprintf(stderr, "screen_get_window_property_pv(SCREEN_PROPERTY_RENDER_BUFFERS) failed (%s)\n", strerror(errno));
        return -1;
    }

    dirty[2] = image_size[0];
    dirty[3] = image_size[1];

    if(screen_post_window(screen_win, *screen_buf, 1, dirty, 0) < 0) {
        fprintf(stderr, "screen_post_window() failed (%s)\n", strerror(errno));
        return -1;
    }

    return 0;
}

int decompr_setup(uintptr_t data, img_t *img, unsigned flags)
{
    screen_window_t screen_win = (screen_window_t)data;

    image_size[0] = img->w;
    image_size[1] = img->h;

    if((image_size[0] > screen_size[0]) || (image_size[1] > screen_size[1])) {
        fprintf(stderr, "Image size exceed monitor's native resolution\n");
        return IMG_ERR_INTR;
    }

    if(screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_SIZE, image_size) < 0) {
        fprintf(stderr, "screen_set_window_property_iv(SCREEN_PROPERTY_SIZE) failed (%s)\n", strerror(errno));
        return IMG_ERR_INTR;
    }

    screen_create_window_buffers(screen_win, 1);

    screen_get_window_property_pv(screen_win, SCREEN_PROPERTY_RENDER_BUFFERS, (void **)screen_buf);
    screen_get_buffer_property_pv(*screen_buf, SCREEN_PROPERTY_POINTER, (void **)&img->access.direct.data);
    screen_get_buffer_property_iv(*screen_buf, SCREEN_PROPERTY_STRIDE, (int *)&img->access.direct.stride);

    crc32.pbuf = img->access.direct.data;
    crc32.stride = img->access.direct.stride;

    img->flags |= IMG_DIRECT;

    return IMG_ERR_OK;
}

int decompr_image(void)
{
    int rc;
    img_t img = { 0 };
    img_decode_callouts_t callouts = { 0 };
    img_lib_t ilib = NULL;

    if((rc = img_lib_attach(&ilib)) != IMG_ERR_OK) {
        fprintf(stderr, "img_lib_attach() failed (err %d)\n", rc);
        return -1;
    }

    img.flags |= IMG_FORMAT;
    img.format = IMG_FMT_PKLE_XRGB8888;

    callouts.setup_f = decompr_setup;
    callouts.data = (uintptr_t)screen_win;

    if((rc = img_load_file(ilib, image_path, &callouts, &img)) != IMG_ERR_OK) {
        fprintf(stderr, "img_load_file() failed (err %d)\n", rc);
        return -1;
    }

    img_lib_detach(ilib);

    return (rc == IMG_ERR_OK) ? 0 : -1;
}

int create_window(void)
{
    if(screen_create_window(&screen_win, screen_ctx) < 0) {
        fprintf(stderr, "screen_create_window() failed (%s)\n", strerror(errno));
        return -1;
    }

    if(screen_set_window_property_pv(screen_win, SCREEN_PROPERTY_DISPLAY, (void**)&screen_disp) < 0) {
        fprintf(stderr, "screen_set_window_property_pv(SCREEN_PROPERTY_DISPLAY) failed (%s)\n", strerror(errno));
        return -1;
    }

    if(screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_USAGE, &usage) < 0) {
        fprintf(stderr, "screen_set_window_property_iv(SCREEN_PROPERTY_USAGE) failed (%s)\n", strerror(errno));
        return -1;
    }

    if(screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_FORMAT, &format) < 0) {
        fprintf(stderr, "screen_set_window_property_iv(SCREEN_PROPERTY_FORMAT) failed (%s)\n", strerror(errno));
        return -1;
    }

    if(screen_get_window_property_iv(screen_win, SCREEN_PROPERTY_PIPELINE, &pipeline) < 0) {
        fprintf(stderr, "screen_get_window_property_iv(SCREEN_PROPERTY_PIPELINE) failed (%s)\n", strerror(errno));
        return -1;
    }

    return 0;
}

int verify_option(void)
{
#if 0
    if(strlen(image_path) == 0) {
        fprintf(stderr, "Please specify image path\n");
        return -1;
    }

    if(access(image_path, F_OK) < 0) {
        fprintf(stderr, "Image file not exist\n");
        return -1;
    }
#endif
    return 0;
}

int check_display(void)
{
    int temp;

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

    return screen_disp ? 0 : -1;
}

int main(int argc, char **argv)
{
    int rc;
    uint8_t sig_id = 0, win_id = 0;
    uint32_t eval_data[9], option, i=0;
    ts_SSigUnitWinCfg_t EvWindow;
    ts_SSigUnitGetWinStatus_t p_win_crc_sts;
    ts_SSigUnitCfg_t cfg;
#if 0
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
#endif
	for(i=0;i<35;i++){
		uif_rect[0] = data[i].upperleft_x_U16;
		uif_rect[1] = data[i].upperleft_y_U16;
		uif_rect[2] = data[i].lowerright_x_U16;
		uif_rect[3] = data[i].lowerright_y_U16;
		strcpy(image_path,l_image_path[i]);
		
		if(screen_create_context(&screen_ctx, SCREEN_APPLICATION_CONTEXT) < 0) {
			fprintf(stderr, "screen_create_context() failed (%s)\n", strerror(errno));
			return -1;
		}

//	    xz_crc32_init();

		if((check_display() < 0) ||
		   (verify_option() < 0) ||
		   (create_window() < 0) ||
		   (decompr_image() < 0) ||
		   (display_image() < 0)) {
			goto cleanup;
		}

		if(!uif_rect[2] && !uif_rect[3]) {
			uif_rect[2] = image_size[0];
			uif_rect[3] = image_size[1];
		}

		EvWindow.upperleft_x_U16 = uif_rect[0];
		EvWindow.upperleft_y_U16 = uif_rect[1];
		EvWindow.lowerright_x_U16 = uif_rect[2];
		EvWindow.lowerright_y_U16 = uif_rect[3];

//	printf("EvWindow.upperleft_x_U16=%d,EvWindow.upperleft_y_U16 =%d, EvWindow.lowerright_x_U16 =%d, EvWindow.lowerright_y_U16 =%d\n", EvWindow.upperleft_x_U16,EvWindow.upperleft_y_U16, EvWindow.lowerright_x_U16,EvWindow.lowerright_y_U16);

		if((rc = dk_bspal_sigunit_initialize(sig_id, &cfg)) != EOK) {
			fprintf(stderr, "DCMD_DISCOM_ATTACH() failed (%s)\n", strerror(rc));
			goto cleanup;
		}

	//    screen_wait_vsync(screen_disp);

		if((rc = dk_bspal_sigunit_eval_win_setup(win_id, &EvWindow)) != EOK) {
			fprintf(stderr, "DCMD_DISCOM_SOURCE_RECTANGLE() failed (%s)\n", strerror(rc));
			goto detach;
		}

		if((rc = dk_bspal_sigunit_eval_win_start(win_id)) != EOK) {
			fprintf(stderr, "DCMD_DISCOM_START() failed (%s)\n", strerror(rc));
			goto detach;
		}

		screen_wait_vsync(screen_disp);

		if((rc = dk_bspal_sigunit_eval_win_stop(win_id)) != EOK) {
			fprintf(stderr, "DCMD_DISCOM_STOP() failed (%s)\n", strerror(rc));
			goto detach;
		}

		screen_wait_vsync(screen_disp);

		p_win_crc_sts = dk_bspal_sigunit_get_win_crc_sts(win_id);

//	    crc32.expect = calculate_crc();

	    fprintf(stdout, "Calculated CRC of %s ROI: 0x%08x\n", image_path, p_win_crc_sts.crc.rgb_crc_U32);
//	    fprintf(stdout, "Expect: 0x%08x\n", crc32.expect);
//		fprintf(stdout, "For %s Expect: 0x%08x Actual: 0x%08x\n", image_path,crc32.expect, p_win_crc_sts.crc.rgb_crc_U32);
	#if 0
		if(p_win_crc_sts.crc.rgb_crc_U32 != crc32.expect) {
			fprintf(stdout, "Result:\033[1;31m Failed \033[0;0m\n");
		} else {
			fprintf(stdout, "Result:\033[1;32m Passed \033[0;0m\n");
		}
	#endif
	detach:
		if((rc = dk_bspal_sigunit_shutdown()) != EOK) {
			fprintf(stderr, "DCMD_DISCOM_DETACH() failed (%s)\n", strerror(rc));
		}

	cleanup:
		if(screen_ctx) {
			screen_destroy_context(screen_ctx);
		}
		if(screen_win) {
			screen_destroy_window(screen_win);
		}
		if(screen_disps) {
			free(screen_disps);
		}
}
    return 0;
}


void xz_crc32_init(void)
{
    const uint32_t poly = 0xEDB88320u;

    uint32_t i;
    uint32_t j;
    uint32_t r;

    for(i = 0; i < 256u; ++i) {
        r = i;
        for(j = 0; j < 8u; ++j) {
            r = (r >> 1) ^ (poly & ~((r & 1u) - 1u));
        }
        xz_crc32_table[i] = r;
    }
}

uint32_t xz_crc32(const uint8_t *buf, size_t size, uint32_t crc)
{
    crc = ~crc;

    while(size != 0u) {
        crc = xz_crc32_table[*buf++ ^ (crc & 0xFFu)] ^ (crc >> 8);
        --size;
    }

    return ~crc;
}
