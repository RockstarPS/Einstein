/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file main.c
 *
 * \brief
 * This file shall be the main implementation of the CM0plus Core in Traveo2 (HSM)
 *
 * \version 1.0.00
 * |Version | Date       | Author   | Task Id | Description                                   |
 * |--------|------------|----------|-----------------|---------------------------------------|
 * |1.00.00 | 26/09/2024 | kjohn    | PE4TI29141-4589 | HSM KPI timers                       ||
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <sa2ul.h>
#include <hs_security_init.h>
#include <hsm_core/hsm.h>
#include <ti_app.h>
#include <trace.h>
#include <arch/interrupt.h>
#include <sec_proxy.h>
#include <soc_hsm_data.h>
#include "vHsmTimer.h"
#include "osal_platform.h"
#include "vHsmIpc.h"
#include "vHsmIpcHostManager.h"
#include "vHsmCrypt.h"
#include "aes_unittest.h"
#include "vHsmWdg.h"
#include "vHsmShutdownMgr.h"
#include "vHsmKeyStore.h"
#include "Fls.h"
#include "vHsmStack.h"
#include "vHsmMPU.h"
#include "vHsmFireWall.h"
#include "vDLT.h"

#define TASK_100MS         (100UL)
#define TASK_10MS          (10UL)
#define TASK_50MS          (50UL)
#define TASK_5MS           (5UL)
#define LOCAL static

extern int main(void);
LOCAL void Task_10ms(void);
LOCAL void Task_5ms(void);

static u32 l_OsSystemCounter_U32;
static u32 l_Counter10ms_U32 = 0;
static u32 l_Counter5ms_U32 = 0;
static u32 l_PrevCounter10ms_U32 = 0;
static u32 l_PrevCounter5ms_U32 = 0;
static u32 l_second_counter_U32 = 0;

extern u32 __Vectors[DMSC_MAX_INTERRUPTS];
extern void delay_1us(void);

int main(void)
{
#ifdef HSMSTACKPROTECTION
	STACK_CANARY_START();
#endif
	u32 err = 0;
	u32 HOLD = 0x100;
	l_OsSystemCounter_U32 = 0;
	HSM_init();
#ifdef VDLT_ENABLE
    vDLT_Init();
#endif
#ifdef VHSMFW_ENABLE
	vHsmFireWall_init();
#endif
	TRACE_info("\r\n\n\n#############  HSM UP    ############## \n");
	vHsmTimer_Init();
	vHsmIpc_Init();
	vHsmTrng_Init();
	vHsmDmnMgr_Init();
	err = hs_security_early_init_hsm();
	if (!ft_is_ok(err))
	{
		TRACE_info("\r\n Crypto Init Failed");
	}
	else
	{
		TRACE_info("\r\n Waiting to Initilize Engines");
		HOLD = vHsmTimer_TickCount();
		TRACE_info_arg_hsm("\r\n Count %x",HOLD );
#ifdef HSMWDG_ENABLE
       vHsmWdg_Init();
#endif
	}
	for(;;)
	{
		Task_10ms();
		Task_5ms();
#ifdef HSMSTACKPROTECTION
	    STACK_CANARY_CHECK()
#endif
	}

}

void OsClock_Callback(void)
{
	l_OsSystemCounter_U32 += 1u;
	if((l_OsSystemCounter_U32 % TASK_10MS) == 0)
	{
		l_Counter10ms_U32 += 1u;
	}
	if((l_OsSystemCounter_U32 % TASK_5MS) == 0)
	{
		l_Counter5ms_U32 += 1u;
	}
}
LOCAL void Task_10ms(void)
{
	if(l_Counter10ms_U32 > l_PrevCounter10ms_U32)
	{
		vHsmIpc_HostManager_PeriodicCheck();
		vHsmDmnMgr_MainFunction();
#ifdef VDLT_ENABLE
        vDLT_mainFunction();
#endif
		l_PrevCounter10ms_U32 = l_Counter10ms_U32;
		if((l_PrevCounter10ms_U32 % HSMWDG_PETCOUNTER) == 0u)
		{
#ifdef HSMWDG_ENABLE
			vHsmWdg_Service();
#endif
		}
		if((l_PrevCounter10ms_U32 % 100u) == 0u)
		{
			l_second_counter_U32 += 1u;
			if((l_second_counter_U32 % 60) == 0)
			{
				TRACE_info_arg_hsm("\r\n ",(l_second_counter_U32/60));
				TRACE_info("Minutes elapsed");
			}
		}
		
	}

}
LOCAL void Task_5ms(void)
{
	if(l_Counter5ms_U32 > l_PrevCounter5ms_U32)
	{
	    Fls_MainFunction();
		vHsmKeyStore_MainFunction();
		l_PrevCounter5ms_U32 = l_Counter5ms_U32;
	}	
}

/*EOF*/
