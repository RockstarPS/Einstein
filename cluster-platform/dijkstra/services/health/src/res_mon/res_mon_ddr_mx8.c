/*---------------------------------------------------------------------------------------------------------------------

 VISTEON CORPORATION CONFIDENTIAL
 ________________________________

 [2020] Visteon Corporation
 All Rights Reserved.

 NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 under all copyright laws to protect this work as a published work, when appropriate.
 Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/
#include <hw/inout.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/slog.h>
#include <sys/syspage.h>
#include <unistd.h>
#include "res_mon.h"
#include "debug.h"

#define IMX_DRC_PERF_MON_SIZE           0x100

#define IMX8_QXP_DDR_PERF_MON_BASE      0x5C020000

#define AXI_BITS2BYTES                  16
#define SEC_TO_MICROSEC     0xF4240u
#define ONE_MB              0x100000u
#define IMX_DMON_CNT_COUNTERS           4
    #define IMX_DMON_CNT_CYCLE              0
    #define IMX_DMON_CNT_EVENT0             1
    #define IMX_DMON_CNT_EVENT1             2
    #define IMX_DMON_CNT_EVENT2             3

/* Event indexes */
#define IMX_DMON_EVT_CYCLES                     0
#define IMX_DMON_EVT_SELFRESH                   1
#define IMX_DMON_EVT_READ_ACCESS                2
#define IMX_DMON_EVT_WRITE_ACCESS               3
#define IMX_DMON_EVT_READ_QUEUE_DEPTH           4
#define IMX_DMON_EVT_WRITE_QUEUE_DEPTH          5
#define IMX_DMON_EVT_LP_READ_CREDIT_CNT         6
#define IMX_DMON_EVT_HP_READ_CREDIT_CNT         7
#define IMX_DMON_EVT_WRITE_CREDIT_CNT           8
#define IMX_DMON_EVT_READ_COMMAND               9
#define IMX_DMON_EVT_WRITE_COMMAND              10
#define IMX_DMON_EVT_READ_MODIFY_WRITE_COMMAND  11
#define IMX_DMON_EVT_HP_READ                    12
#define IMX_DMON_EVT_HP_REQ_NODCREDIT           13
#define IMX_DMON_EVT_HP_XACT_CREDIT             14
#define IMX_DMON_EVT_LP_REQ_NOCREDIT            15
#define IMX_DMON_EVT_LP_XACT_CREDIT             16
#define IMX_DMON_EVT_WR_XACT_CREDIT             17
#define IMX_DMON_EVT_READ_CYCLES                18
#define IMX_DMON_EVT_READ_BYTES                 19
#define IMX_DMON_EVT_WRITE_CYCLES               20
#define IMX_DMON_EVT_WRITE_BYTES                21
#define IMX_DMON_EVT_READ_WRITE_TRANSITION      22
#define IMX_DMON_EVT_PRECHARGE                  23
#define IMX_DMON_EVT_ACTIVATE                   24
#define IMX_DMON_EVT_LOAD_MODE                  25
#define IMX_DMON_EVT_MWR                        26
#define IMX_DMON_EVT_READ                       27
#define IMX_DMON_EVT_READ_ACTIVATE              28
#define IMX_DMON_EVT_REFRESH                    29
#define IMX_DMON_EVT_WRITE                      30
#define IMX_DMON_EVT_RAW_HAZARD                 31
#define IMX_DMON_EVT_AXID_READ                  32
#define IMX_DMON_EVT_AXID_WRITE                 33

/* Event register values */
typedef enum {
    cycles = 0x0,
    selfresh = 0x1,
    read_access = 0x4,
    write_access = 0x5,
    read_queue_depth = 0x8,
    write_queue_depth = 0x9,
    lp_read_credit_cnt = 0x10,
    hp_read_credit_cnt = 0x11,
    write_credit_cnt = 0x12,
    read_command = 0x20,
    write_command = 0x21,
    read_modify_write_command = 0x22,
    hp_read = 0x23,
    hp_req_nodcredit = 0x24,
    hp_xact_credit = 0x25,
    lp_req_nocredit = 0x26,
    lp_xact_credit = 0x27,
    wr_xact_credit = 0x29,
    read_cycles = 0x2A,
    read_bytes = 0x12A,
    write_cycles = 0x2B,
    write_bytes = 0x12B,
    read_write_transition = 0x30,
    precharge = 0x31,
    activate = 0x32,
    load_mode = 0x33,
    mwr = 0x34,
    ddrmon_read = 0x35,
    read_activate = 0x36,
    refresh = 0x37,
    ddrmon_write = 0x38,
    raw_hazard = 0x39,
    axid_read = 0x41,
    axid_write = 0x42,
} imx_dmon_event_t;

/* I/O space */
#define IMX_DMON_CNT0_CTRL 0x0
#define IMX_DMON_CNT1_CTRL 0x4
#define IMX_DMON_CNT2_CTRL 0x8
#define IMX_DMON_CNT3_CTRL 0xC
    #define IMX_DMON_CNT_CSV_SHIFT      24
    #define IMX_DMON_CNT_CSV_MASK       (0xFF << IMX_DMON_CNT_CSV_SHIFT)
    #define IMX_DMON_CNT_EN_SHIFT       2
    #define IMX_DMON_CNT_EN_MASK        (0x1 << IMX_DMON_CNT_EN_SHIFT)
    #define IMX_DMON_CNT_CLR_SHIFT      1
    #define IMX_DMON_CNT_CLR_MASK       (0x1 << IMX_DMON_CNT_CLR_SHIFT)
    #define IMX_DMON_CNT_OVRFL_SHIFT    0
    #define IMX_DMON_CNT_OVRFL_MASK     (0x1 << IMX_DMON_CNT_OVRFL_SHIFT)

#define IMX_DMON_CNT0_DATA 0x20
#define IMX_DMON_CNT1_DATA 0x24
#define IMX_DMON_CNT2_DATA 0x28
#define IMX_DMON_CNT3_DATA 0x2C

#define IMX_DMON_MRR0_DATA 0x40
#define IMX_DMON_MRR1_DATA 0x44

uintptr_t vbase;
imx_dmon_event_t events[IMX_DMON_CNT_COUNTERS];
uint16_t txt_idx[IMX_DMON_CNT_COUNTERS]={0};
uint16_t evt = 1;
uint64_t cps, cycle1, cycle2 = 0;
uint32_t rspeed = 0;
uint32_t wspeed = 0;

void ddr_mon_enable(uintptr_t base, bool enable)
{
    uint32_t val;

    if (enable) {
        /* Disable counter before enable */
        out32(base + IMX_DMON_CNT0_CTRL, 0);
        val = IMX_DMON_CNT_EN_MASK | IMX_DMON_CNT_CLR_MASK;
    } else {
        /* Disable counter */
        val = in32(base + IMX_DMON_CNT0_CTRL);
        val &= ~IMX_DMON_CNT_EN_MASK;
    }
    out32(base + IMX_DMON_CNT0_CTRL, val);
}

void ddr_mon_event_enable(uintptr_t base, int counter, imx_dmon_event_t event, bool enable)
{
    uint16_t cnt_offset = IMX_DMON_CNT0_CTRL + (counter * 4);
    int32_t val;

    if (enable) {
        /* Disable counter before enable */
        out32(base + cnt_offset, 0);
        val = IMX_DMON_CNT_EN_MASK | IMX_DMON_CNT_CLR_MASK;
        val |= (event << IMX_DMON_CNT_CSV_SHIFT) & IMX_DMON_CNT_CSV_MASK;
    } else {
        /* Disable counter */
        val = in32(base + cnt_offset);
        val &= ~IMX_DMON_CNT_EN_MASK;
    }
    out32(base + cnt_offset, val);
}

uint32_t ddr_mon_read_counter(uintptr_t base, uint32_t counter)
{
    return in32(base + IMX_DMON_CNT0_DATA + (counter * 4));
}

uint32_t get_speed_mb(uint32_t event_cycles, uint32_t time_diff_us)
{
	uint32_t l_speed_mb_U32 = 0;
	uint32_t l_speed_temp_U32 = 0;
	if( ( 0 != time_diff_us ) && ( 0 != event_cycles ) )
	{
	    l_speed_temp_U32 =  ( event_cycles * SEC_TO_MICROSEC ) / time_diff_us;
	    l_speed_temp_U32 = l_speed_temp_U32 * AXI_BITS2BYTES;
	    l_speed_mb_U32 = l_speed_temp_U32 / ONE_MB;
	}
	else
	{
		 LOGE ( "cant calculate speed since time_diff_us is 0: %d", time_diff_us );
	}
    return l_speed_mb_U32;
}

int32_t ResMonDDR_Init ( void )
{
	int32_t ret = RM_OK;
	uint32_t i;

    /* Map IO space */
    if ((vbase = (uintptr_t)mmap_device_io(IMX_DRC_PERF_MON_SIZE, IMX8_QXP_DDR_PERF_MON_BASE)) == (uintptr_t)MAP_FAILED) {
        LOGE( "%s", "Error base mmap_device_memory" );
        ret = RM_FAILED;
    }

    cps = SYSPAGE_ENTRY(qtime)->cycles_per_sec;

    evt = 1;
    events[evt] = read_cycles;
    txt_idx[evt] = IMX_DMON_EVT_READ_CYCLES;
    evt++;
    events[evt] = write_cycles;
    txt_idx[evt] = IMX_DMON_EVT_WRITE_CYCLES;
    evt++;

    ddr_mon_enable(vbase, false);
    for (i = 1; i < evt; i++) {
        ddr_mon_event_enable(vbase, i, events[i], false);
        ddr_mon_event_enable(vbase, i, events[i], true);
    }
    ddr_mon_enable(vbase, true);
    cycle1 = ClockCycles();

    return ret;
}

int32_t ResMonDDR_Log ( void )
{
	int32_t ret = RM_OK;
	int32_t i;
	uint32_t evt_cyc, time_dif;

    /*Reinitialize to zero before assigning new updated value*/
	rspeed = 0;
	wspeed = 0;
	
	for (i=1; i < evt; i++)
	{
		cycle2 = ClockCycles();
        evt_cyc = ddr_mon_read_counter(vbase, i);
        time_dif = (int)((cycle2 - cycle1) * 1000 / (cps / 1000));

        if (events[i] == read_cycles)
        {
        	rspeed = get_speed_mb(evt_cyc, time_dif);
        }
        if (events[i] == write_cycles)
        {
        	wspeed = get_speed_mb(evt_cyc, time_dif);
        }
	}

    LOGI ( "DDR_IO: %d %d", rspeed, wspeed );

	if ( ( in32(vbase) & IMX_DMON_CNT_OVRFL_MASK ) != 0 )
	{
	    ddr_mon_enable(vbase, false);
	    for (i = 1; i < evt; i++) {
	        ddr_mon_event_enable(vbase, i, events[i], false);
	        ddr_mon_event_enable(vbase, i, events[i], true);
	    }
	    ddr_mon_enable(vbase, true);
	    cycle1 = ClockCycles();
	}

	return ret;
}

int32_t ResMonDDR_Shutdown ( void )
{
	int32_t ret = RM_OK;

	// Release map
	( void ) munmap_device_io ( IMX8_QXP_DDR_PERF_MON_BASE, IMX_DRC_PERF_MON_SIZE );

	return ret;
}
