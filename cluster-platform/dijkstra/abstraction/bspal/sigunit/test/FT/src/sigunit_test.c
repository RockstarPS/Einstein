#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <sys/syspage.h>
#include <screen/screen.h>
#include "dk_logger.h"
#include "CSigUnit_DK_BSPAL.h"
#include "CSigUnit_Cfg.h"

#define SIGUINIT_ID									(uint8_t)0
#define SIG0_PANIC_COLOUR							((uint32_t)0xFFFFFF80)
#define SIG0_ERROR_THRESHOLD_VALUE					(uint8_t)0
#define SIG0_ERROR_THRESHOLD_RESET_VALUE			(uint8_t)0

enum eTestCase
{
	TestCase1, //Any Window , Any Region. Needed options: t, w, r
	TestCase2, //All Window , Fixed Region. Needed options: t
	TestCase3, //Any Window , All Region. Needed options: t, w
	TestCase4, //All Window , All Region. Needed options: t
	TestCase5, //All Window , Fixed Region, FPS measurement. Needed options: t, d, v
	TestCase6, //All Window , All Region, FPS measurement. Needed options: t, d, v
	TestCase7, //One Window , Full Screen. Needed options: w, t, d, v
	TestCaseLast
};

typedef struct 
{
	uint16_t x1;
	uint16_t y1;
	uint16_t x2;
	uint16_t y2;
} region_t;
region_t regions[8] = {
	{10, 10, 210, 210},
	{490, 10, 690, 210},
	{970, 10, 1180, 210},
	{1450, 10, 1660, 210},
	{10, 370, 210, 580},
	{490, 370, 690, 580},
	{970, 370, 1180, 580},
	{1450, 370, 1660, 580}
};

uint32_t testcase = 0;
uint8_t testcase_state = 0;
uint8_t testcase_run_count = 0;
uint8_t verbosity = 100;
uint32_t duration = 5;

ts_SSigUnitCfg_t cfg;
ts_SSigUnitWinCfg_t eval_win;
uint8_t win_id = 0;
uint8_t region_id = 0;
uint8_t sig_id = SIGUINIT_ID;

screen_context_t screen_ctx = NULL;
screen_display_t *screen_disps = NULL;
screen_display_t screen_disp = NULL;
int screen_size[2] = { 0 };
int display = 1;

void testcase_1_setup(void);
void testcase_1_run(void);
void testcase_1_close(void);
void testcase_2_setup(void);
void testcase_2_run(void);
void testcase_2_close(void);
void testcase_3_setup(void);
void testcase_3_run(void);
void testcase_3_close(void);
void testcase_4_setup(void);
void testcase_4_run(void);
void testcase_4_close(void);
void testcase_5_setup(void);
void testcase_5_run(void);
void testcase_5_close(void);
void testcase_6_setup(void);
void testcase_6_run(void);
void testcase_6_close(void);
void testcase_7_setup(void);
void testcase_7_run(void);
void testcase_7_close(void);


int check_display(void)
{
    int temp;
	int n_display = 0;

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

    return screen_disp ? 0 : -1;
}

void sigunit_init(void)
{
	int32_t status;
	
    cfg.panic_rgba_U32     = SIG0_PANIC_COLOUR;
    cfg.error_threshold_U8 = SIG0_ERROR_THRESHOLD_VALUE;
    cfg.reset_threshold_U8 = SIG0_ERROR_THRESHOLD_RESET_VALUE;	

	status = dk_bspal_sigunit_initialize(sig_id, &cfg);
	if(EOK == status)
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_initialize: PASS\n");
    }
    else
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_initialize: FAIL\n");
    }	
}

void sigunit_shutdown_single_win(void)
{
	int32_t status;
	
    status = dk_bspal_sigunit_eval_win_stop(win_id);
    if(EOK == status)
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_eval_win_stop: PASS\n");
    }
    else
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_eval_win_stop: FAIL\n");
    }
	
	status = dk_bspal_sigunit_shutdown();
    if(EOK == status)
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_shutdown: PASS\n");
    }
    else
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_shutdown: FAIL\n");
    }
}

void sigunit_shutdown_all_win(void)
{
	int32_t status;
	
	for(int8_t id = 0; id < 8; id++)
	{
		status = dk_bspal_sigunit_eval_win_stop(id);
		if(EOK == status)
		{
			(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_stop %d: PASS\n",id);
		}
		else
		{
			(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_stop %d: FAIL\n",id);
		}
	}

	status = dk_bspal_sigunit_shutdown();
    if(EOK == status)
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_shutdown: PASS\n");
    }
    else
    {
        (void) fprintf (stderr, "dk_bspal_sigunit_shutdown: FAIL\n");
    }
}

void testcase_1_setup(void)
{
	int32_t status;
	
    sigunit_init();

	eval_win.upperleft_x_U16 = regions[region_id].x1;
	eval_win.upperleft_y_U16 = regions[region_id].y1;
	eval_win.lowerright_x_U16 = regions[region_id].x2;
	eval_win.lowerright_y_U16 = regions[region_id].y2;
	eval_win.alpha_U8 = 0;
	eval_win.action_U8 = 0;
	eval_win.ref_crc.red_U32 = 0;
	eval_win.ref_crc.green_U32 = 0;
	eval_win.ref_crc.blue_U32 = 0;
	
	(void) fprintf (stderr, "X1, Y1, X2, Y2 : %d, %d, %d, %d\n", eval_win.upperleft_x_U16, eval_win.upperleft_y_U16, eval_win.lowerright_x_U16, eval_win.lowerright_y_U16);

	screen_wait_vsync(screen_disp);
	status = dk_bspal_sigunit_eval_win_setup(win_id, &eval_win);

	if(EOK != status)
	{
		(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
	}
	
	status = dk_bspal_sigunit_eval_win_start(win_id);
	if(EOK != status)
	{
		(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
	}

	testcase_state++;
}

void testcase_1_run(void)
{	
	ts_SSigUnitGetWinStatus_t p_win_crc_sts;

	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);
	do
	{
		p_win_crc_sts = dk_bspal_sigunit_get_win_crc_sts(win_id);

		(void) fprintf (stderr, "Win%d status    : 0x%x, R : 0x%x, G : 0x%x, B : 0x%x\n", p_win_crc_sts.eval_win_id, p_win_crc_sts.err_status_U32, p_win_crc_sts.crc.red_U32, p_win_crc_sts.crc.green_U32, p_win_crc_sts.crc.blue_U32);
		
		if((p_win_crc_sts.crc.red_U32 != 0xFFFFFFFF) && (p_win_crc_sts.crc.green_U32 != 0xFFFFFFFF) && (p_win_crc_sts.crc.blue_U32 != 0xFFFFFFFF))
		{
			break;
		}
		screen_wait_vsync(screen_disp);
	} while(1);
	
	testcase_run_count++;
	if(testcase_run_count > 0)
	{
		testcase_state++;
	}
}

void testcase_1_close(void)
{
	sigunit_shutdown_single_win();
	
	testcase_state++;
}

void testcase_2_setup(void)
{
	int32_t status;

    sigunit_init();
	
	screen_wait_vsync(screen_disp);
	
	for(uint8_t id = 0; id < 8; id++)
	{
		eval_win.alpha_U8 = 0;
		eval_win.action_U8 = 0;
		eval_win.ref_crc.red_U32 = 0;
		eval_win.ref_crc.green_U32 = 0;
		eval_win.ref_crc.blue_U32 = 0;
		eval_win.upperleft_x_U16 = regions[id].x1;
		eval_win.upperleft_y_U16 = regions[id].y1;
		eval_win.lowerright_x_U16 = regions[id].x2;
		eval_win.lowerright_y_U16 = regions[id].y2;
		
		status = dk_bspal_sigunit_eval_win_setup(id, &eval_win);
		if(EOK != status)
		{
			(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
		}
		
		status = dk_bspal_sigunit_eval_win_start(id);
		if(EOK != status)
		{
			(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
		}
	}

	testcase_state++;
}

void testcase_2_run(void)
{
	ts_SSigUnitGetWinStatus_t p_win_crc_sts;

	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);

	for(int8_t id = 0; id < 8; id++)
	{
		do
		{
			p_win_crc_sts = dk_bspal_sigunit_get_win_crc_sts(id);

			(void) fprintf (stderr, "Win%d status    : 0x%x, R : 0x%x, G : 0x%x, B : 0x%x\n", p_win_crc_sts.eval_win_id, p_win_crc_sts.err_status_U32, p_win_crc_sts.crc.red_U32, p_win_crc_sts.crc.green_U32, p_win_crc_sts.crc.blue_U32);				
			if((p_win_crc_sts.crc.red_U32 != 0xFFFFFFFF) && (p_win_crc_sts.crc.green_U32 != 0xFFFFFFFF) && (p_win_crc_sts.crc.blue_U32 != 0xFFFFFFFF))
			{
				break;
			}
			screen_wait_vsync(screen_disp);			
		} while(1);
	}

	testcase_run_count++;
	if(testcase_run_count > 0)
	{
		testcase_state++;
	}	
}

void testcase_2_close(void)
{
	sigunit_shutdown_all_win();
	testcase_state++;
}

void testcase_3_setup(void)
{
	sigunit_init();
	testcase_state++;
}

void testcase_3_run(void)
{
	int32_t status;
	ts_SSigUnitGetWinStatus_t p_win_crc_sts;
	
	eval_win.alpha_U8 = 0;
	eval_win.action_U8 = 0;
	eval_win.ref_crc.red_U32 = 0;
	eval_win.ref_crc.green_U32 = 0;
	eval_win.ref_crc.blue_U32 = 0;
	eval_win.upperleft_x_U16 = regions[testcase_run_count].x1;
	eval_win.upperleft_y_U16 = regions[testcase_run_count].y1;
	eval_win.lowerright_x_U16 = regions[testcase_run_count].x2;
	eval_win.lowerright_y_U16 = regions[testcase_run_count].y2;
	
	screen_wait_vsync(screen_disp);
	status = dk_bspal_sigunit_eval_win_setup(win_id, &eval_win);

	if(EOK != status)
	{
		(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
	}
	
	status = dk_bspal_sigunit_eval_win_start(win_id);
	if(EOK != status)
	{
		(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
	}
	
	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);
	
	do
	{
		p_win_crc_sts = dk_bspal_sigunit_get_win_crc_sts(win_id);

		(void) fprintf (stderr, "Win%d status    : 0x%x, R : 0x%x, G : 0x%x, B : 0x%x\n", p_win_crc_sts.eval_win_id, p_win_crc_sts.err_status_U32, p_win_crc_sts.crc.red_U32, p_win_crc_sts.crc.green_U32, p_win_crc_sts.crc.blue_U32);
		
		if((p_win_crc_sts.crc.red_U32 != 0xFFFFFFFF) && (p_win_crc_sts.crc.green_U32 != 0xFFFFFFFF) && (p_win_crc_sts.crc.blue_U32 != 0xFFFFFFFF))
		{
			break;
		}
		screen_wait_vsync(screen_disp);		
	} while(1);
	
	testcase_run_count++;
	if(testcase_run_count > 7)
	{
		testcase_state++;
	}	
}

void testcase_3_close(void)
{
	sigunit_shutdown_single_win();
	
	testcase_state++;
}

void testcase_4_setup(void)
{
	sigunit_init();
	
	testcase_state++;
}

void testcase_4_run(void)
{
	int32_t status;
	ts_SSigUnitGetWinStatus_t p_win_crc_sts;
	
	(void) fprintf (stderr, "Loop %d\n", testcase_run_count);
	
	screen_wait_vsync(screen_disp);
		
	for(int8_t id = 0; id < 8; id++)
	{
		eval_win.alpha_U8 = 0;
		eval_win.action_U8 = 0;
		eval_win.ref_crc.red_U32 = 0;
		eval_win.ref_crc.green_U32 = 0;
		eval_win.ref_crc.blue_U32 = 0;
		eval_win.upperleft_x_U16 = regions[(testcase_run_count + id) % 8].x1;
		eval_win.upperleft_y_U16 = regions[(testcase_run_count + id) % 8].y1;
		eval_win.lowerright_x_U16 = regions[(testcase_run_count + id) % 8].x2;
		eval_win.lowerright_y_U16 = regions[(testcase_run_count + id) % 8].y2;


		status = dk_bspal_sigunit_eval_win_setup(id, &eval_win);
		if(EOK != status)
		{
			(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
		}
		
		status = dk_bspal_sigunit_eval_win_start(id);
		if(EOK != status)
		{
			(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
		}

	}
			
	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);

	for(int8_t id = 0; id < 8; id++)
	{	
		do
		{
			screen_wait_vsync(screen_disp);
			p_win_crc_sts = dk_bspal_sigunit_get_win_crc_sts(id);

			(void) fprintf (stderr, "Win%d status    : 0x%x, R : 0x%x, G : 0x%x, B : 0x%x\n", p_win_crc_sts.eval_win_id, p_win_crc_sts.err_status_U32, p_win_crc_sts.crc.red_U32, p_win_crc_sts.crc.green_U32, p_win_crc_sts.crc.blue_U32);
			
			if((p_win_crc_sts.crc.red_U32 != 0xFFFFFFFF) && (p_win_crc_sts.crc.green_U32 != 0xFFFFFFFF) && (p_win_crc_sts.crc.blue_U32 != 0xFFFFFFFF))
			{
				break;
			}
			screen_wait_vsync(screen_disp);
		} while(1);
	}
	
	testcase_run_count++;
	if(testcase_run_count > 7)
	{
		testcase_state++;
	}
}

void testcase_4_close(void)
{
	sigunit_shutdown_all_win();
	
	testcase_state++;
}

void testcase_5_setup(void)
{
	sigunit_init();
	
	testcase_state++;	
}

void testcase_5_run(void)
{
	int32_t status;
	ts_SSigUnitGetWinStatus_t p_win_crc_sts;
	unsigned long int cps = SYSPAGE_ENTRY(qtime)->cycles_per_sec;
	unsigned long int end = 0, cb1 = 0, cb2 = 0, diff = 0, total = 0;
	double	elapsed = 0.0f, avg = 0.0f;
	
	screen_wait_vsync(screen_disp);
	
	for(uint8_t id = 0; id < 8; id++)
	{
		eval_win.alpha_U8 = 0;
		eval_win.action_U8 = 0;
		eval_win.ref_crc.red_U32 = 0;
		eval_win.ref_crc.green_U32 = 0;
		eval_win.ref_crc.blue_U32 = 0;
		eval_win.upperleft_x_U16 = regions[id].x1;
		eval_win.upperleft_y_U16 = regions[id].y1;
		eval_win.lowerright_x_U16 = regions[id].x2;
		eval_win.lowerright_y_U16 = regions[id].y2;
		
		status = dk_bspal_sigunit_eval_win_setup(id, &eval_win);
		if(EOK != status)
		{
			(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
		}
		
		status = dk_bspal_sigunit_eval_win_start(id);
		if(EOK != status)
		{
			(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
		}
	}
	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);
	
	end = ClockCycles() + (cps * duration);
	do
	{
		cb1 = ClockCycles();
		screen_wait_vsync(screen_disp);
		for(int8_t id = 0; id < 8; id++)
		{
			p_win_crc_sts = dk_bspal_sigunit_get_win_crc_sts(id);
			if(verbosity > 1)
			{
				(void) fprintf (stderr, "Win%d status    : 0x%x, R : 0x%08x, G : 0x%08x, B : 0x%08x\n", p_win_crc_sts.eval_win_id, p_win_crc_sts.err_status_U32, p_win_crc_sts.crc.red_U32, p_win_crc_sts.crc.green_U32, p_win_crc_sts.crc.blue_U32);
			}
			
			if((p_win_crc_sts.crc.red_U32 == 0xFFFFFFFF) || (p_win_crc_sts.crc.green_U32 == 0xFFFFFFFF) || (p_win_crc_sts.crc.blue_U32 == 0xFFFFFFFF))
			{
				(void) fprintf (stderr, "Invalid CRC\n");
			}
		}
		cb2 = ClockCycles();
		diff = (cb2 - cb1);
		total = total + diff;
		elapsed = (double)((double)((double)((double)cb2 - (double)cb1) * (double)1000) / (double)cps);
		avg = (avg + elapsed) / 2;
		
		if(verbosity > 0)
		{
			(void) fprintf (stderr, "Elapsed : %f\n", elapsed);
		}
	} while(end > cb2);
	
	(void) fprintf (stderr, "Average : %f\n", avg);
	
	testcase_state++;
}

void testcase_5_close(void)
{
	sigunit_shutdown_all_win();
	
	testcase_state++;	
}

void testcase_6_setup(void)
{
	sigunit_init();
	
	testcase_state++;	
}

void testcase_6_run(void)
{
	int32_t status;
	ts_SSigUnitGetWinStatus_t p_win_crc_sts;
	unsigned long int cps = SYSPAGE_ENTRY(qtime)->cycles_per_sec;
	unsigned long int end = 0, cb1 = 0, cb2 = 0, diff = 0, total = 0;
	double	elapsed = 0.0f, avg = 0.0f;
		
	end = ClockCycles() + (cps * duration);
	
	screen_wait_vsync(screen_disp);
	do
	{
		cb1 = ClockCycles();
		for(uint8_t id = 0; id < 8; id++)
		{
			eval_win.alpha_U8 = 0;
			eval_win.action_U8 = 0;
			eval_win.ref_crc.red_U32 = 0;
			eval_win.ref_crc.green_U32 = 0;
			eval_win.ref_crc.blue_U32 = 0;
			eval_win.upperleft_x_U16 = regions[(testcase_run_count + id) % 8].x1;
			eval_win.upperleft_y_U16 = regions[(testcase_run_count + id) % 8].y1;
			eval_win.lowerright_x_U16 = regions[(testcase_run_count + id) % 8].x2;
			eval_win.lowerright_y_U16 = regions[(testcase_run_count + id) % 8].y2;
			
			status = dk_bspal_sigunit_eval_win_setup(id, &eval_win);
			if(EOK != status)
			{
				(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
			}
			
			//status = dk_bspal_sigunit_eval_win_start(id);
			//if(EOK != status)
			//{
			//	(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
			//}
		}
		status = dk_bspal_sigunit_eval_win_start(0xFF);
		if(EOK != status)
		{
			(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
		}
		screen_wait_vsync(screen_disp);
		screen_wait_vsync(screen_disp);
		//screen_wait_vsync(screen_disp);
		for(int8_t id = 0; id < 8; id++)
		{
			p_win_crc_sts = dk_bspal_sigunit_get_win_crc_sts(id);
			if(verbosity > 1)
			{
				(void) fprintf (stderr, "Win%d status    : 0x%x, R : 0x%08x, G : 0x%08x, B : 0x%08x\n", p_win_crc_sts.eval_win_id, p_win_crc_sts.err_status_U32, p_win_crc_sts.crc.red_U32, p_win_crc_sts.crc.green_U32, p_win_crc_sts.crc.blue_U32);
			}
			
			if((p_win_crc_sts.crc.red_U32 == 0xFFFFFFFF) || (p_win_crc_sts.crc.green_U32 == 0xFFFFFFFF) || (p_win_crc_sts.crc.blue_U32 == 0xFFFFFFFF))
			{
				(void) fprintf (stderr, "Invalid CRC\n");
			}
		}
		cb2 = ClockCycles();
		diff = (cb2 - cb1);
		total = total + diff;
		elapsed = (double)((double)((double)((double)cb2 - (double)cb1) * (double)1000) / (double)cps);
		avg = (avg + elapsed) / 2;
		
		if(verbosity > 0)
		{
			(void) fprintf (stderr, "Elapsed : %f\n", elapsed);
		}
		testcase_run_count++;
	} while(end > cb2);
	
	(void) fprintf (stderr, "Average : %f\n", avg);
	
	testcase_state++;
}

void testcase_6_close(void)
{
	sigunit_shutdown_all_win();
	
	testcase_state++;		
}

void testcase_7_setup(void)
{
	sigunit_init();
	
	testcase_state++;		
}

void testcase_7_run(void)
{
	int32_t status;
	ts_SSigUnitGetWinStatus_t p_win_crc_sts;
	unsigned long int cps = SYSPAGE_ENTRY(qtime)->cycles_per_sec;
	unsigned long int end = 0, cb1 = 0, cb2 = 0, diff = 0, total = 0;
	double	elapsed = 0.0f, avg = 0.0f;
	
	//fprintf(stderr, "%s\n", __FUNC__ );
	
	eval_win.alpha_U8 = 0;
	eval_win.action_U8 = 0;
	eval_win.ref_crc.red_U32 = 0;
	eval_win.ref_crc.green_U32 = 0;
	eval_win.ref_crc.blue_U32 = 0;
	eval_win.upperleft_x_U16 = 0;
	eval_win.upperleft_y_U16 = 0;
	eval_win.lowerright_x_U16 = 1920;
	eval_win.lowerright_y_U16 = 720;
	
	screen_wait_vsync(screen_disp);
	status = dk_bspal_sigunit_eval_win_setup(win_id, &eval_win);

	if(EOK != status)
	{
		(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
	}
	
	status = dk_bspal_sigunit_eval_win_start(win_id);
	if(EOK != status)
	{
		(void) fprintf (stderr, "dk_bspal_sigunit_eval_win_setup: FAIL\n");
	}
	
	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);
	screen_wait_vsync(screen_disp);

	end = ClockCycles() + (cps * duration);
	
	do
	{
		p_win_crc_sts = dk_bspal_sigunit_get_win_crc_sts(win_id);

		(void) fprintf (stderr, "Win%d status    : 0x%x, R : 0x%x, G : 0x%x, B : 0x%x\n", p_win_crc_sts.eval_win_id, p_win_crc_sts.err_status_U32, p_win_crc_sts.crc.red_U32, p_win_crc_sts.crc.green_U32, p_win_crc_sts.crc.blue_U32);
		
		if((p_win_crc_sts.crc.red_U32 != 0xFFFFFFFF) && (p_win_crc_sts.crc.green_U32 != 0xFFFFFFFF) && (p_win_crc_sts.crc.blue_U32 != 0xFFFFFFFF))
		{
			break;
		}
		screen_wait_vsync(screen_disp);		

		cb2 = ClockCycles();
		diff = (cb2 - cb1);
		total = total + diff;
		elapsed = (double)((double)((double)((double)cb2 - (double)cb1) * (double)1000) / (double)cps);
		avg = (avg + elapsed) / 2;
		
		if(verbosity > 0)
		{
			(void) fprintf (stderr, "Elapsed : %f\n", elapsed);
		}

	(void) fprintf (stderr, "end : %lu, cb2 : %lu\n", end, cb2);
	} while(end > cb2);
	
	(void) fprintf (stderr, "Average : %f\n", avg);
	
	testcase_state++;
}

void testcase_7_close(void)
{
	sigunit_shutdown_single_win();
	
	testcase_state++;
}

int main(int argc, char **argv)
{
	int32_t option;

	LOG_REGISTER_APP_SLOG2("BspalSIGUNIT","BspalSIGUNIT Test");
	/*Logging directly in DLT, 'SIGFT' is trancated up to its first 4 characters. 'SIGFT'->'SIGF'*/
//	LOG_REGISTER_APP_DLT("SIGFT","BspalSIGUNIT Test");

	while ((option = getopt(argc, argv, "t:w:r:v:d:")) != (uint32_t) -1)
	{
		switch (option)
        {
			case 't':
			testcase = atoi(optarg);
			break;
			case 'w':
			win_id = atoi(optarg);
			break;
			case 'r':
			region_id = atoi(optarg);
			break;
			case 'v':
			verbosity = atoi(optarg);
			break;
			case 'd':
			duration = atoi(optarg);
			break;
			
			default:
			break;
		}
	}
	
	check_display();
	
	(void) fprintf (stderr, "TestCase ID : %d\n", testcase);
	
	while(testcase_state < 3)
	{	
		switch(testcase)
		{
			case TestCase1:
				switch(testcase_state)
				{
					case 0:
					testcase_1_setup();
					break;
					case 1:
					testcase_1_run();
					break;
					case 2:
					testcase_1_close();
					break;
					default:
					break;
				}
			break;
			case TestCase2:
				switch(testcase_state)
				{
					case 0:
					testcase_2_setup();
					break;
					case 1:
					testcase_2_run();
					break;
					case 2:
					testcase_2_close();
					break;
					default:
					break;
				}
			break;
			case TestCase3:
				switch(testcase_state)
				{
					case 0:
					testcase_3_setup();
					break;
					case 1:
					testcase_3_run();
					break;
					case 2:
					testcase_3_close();
					break;
					default:
					break;
				}
			break;
			case TestCase4:
				switch(testcase_state)
				{
					case 0:
					testcase_4_setup();
					break;
					case 1:
					testcase_4_run();
					break;
					case 2:
					testcase_4_close();
					break;
					default:
					break;
				}
			break;
			case TestCase5:
				switch(testcase_state)
				{
					case 0:
					testcase_5_setup();
					break;
					case 1:
					testcase_5_run();
					break;
					case 2:
					testcase_5_close();
					break;
					default:
					break;
				}
			break;
			case TestCase6:
				switch(testcase_state)
				{
					case 0:
					testcase_6_setup();
					break;
					case 1:
					testcase_6_run();
					break;
					case 2:
					testcase_6_close();
					break;
					default:
					break;
				}
			break;
			case TestCase7:
				switch(testcase_state)
				{
					case 0:
					testcase_7_setup();
					break;
					case 1:
					//testcase_7_run();
					break;
					case 2:
					testcase_7_close();
					break;
					default:
					break;
				}
			break;
			
			default:
			break;
		}
		usleep(1000);
	}
	
	
    return 0;
}
