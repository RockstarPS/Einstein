/*
 *  Copyright (C) 2023-2024 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <kernel/dpl/DebugP.h>
#include <kernel/dpl/ClockP.h>
#include "ti_drivers_config.h"
#include "ti_board_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include "FreeRTOS.h"
#include "task.h"
#include <drivers/device_manager/sciserver/sciserver_init.h>
#include "program_cfg.h"
#include <sdl/rti/v0/sdl_rti.h>
#include <sdl/rti/v0/sdl_ip_rti.h>
#include <sdl/dpl/sdl_dpl.h>
#include <kernel/dpl/SemaphoreP.h>
#ifdef KPI_GPIO
#include <drivers/gpio.h>
#include <drivers/pinmux.h>
#endif
#include "boot_kpi_r5_dm.h"
#include "dlt.h"

/* Stack size allocated for the sciserver task */
#define SCISERVER_TASK_STACK_SIZE                   (2U*1024U)

/* Stack memory alignment requirement for the sciserver task */
#define SCISERVER_TASK_STACK_ALIGNMENT              (32U)
/* Stack buffers for user high and low priority tasks */
uint8_t __attribute__((aligned(SCISERVER_TASK_STACK_ALIGNMENT))) gUserHiTaskStack[SCISERVER_TASK_STACK_SIZE];
uint8_t __attribute__((aligned(SCISERVER_TASK_STACK_ALIGNMENT))) gUserLoTaskStack[SCISERVER_TASK_STACK_SIZE];

#define TASK_PRI_MAIN_THREAD  (configMAX_PRIORITIES-1)
#define TASK_PRI_EMMC_LOADER_THREAD  (configMAX_PRIORITIES-1)
#define TASK_PRI_NOR_LOADER_THREAD  (configMAX_PRIORITIES-1)
#define TASK_PRI_IPC_THREAD  (configMAX_PRIORITIES-1)

#define IPC_SHUTDOWN_MESSAGE_REMOTE_ENDPT 15
#define IPC_DLT_MESSAGE_REMOTE_ENDPT 14
#define IPC_LOCAL_ENDPT 15
#define IPC_RPMESSAGE_MAX_MSG_SIZE 512

#define TASK_SIZE (16384U/sizeof(configSTACK_DEPTH_TYPE))

StackType_t gMainTaskStack[TASK_SIZE] __attribute__((aligned(32)));
StaticTask_t gMainTaskObj;
TaskHandle_t gMainTask;
DM_LPMData_t gDMLPMData __attribute__((section(".lpm_data"), aligned(4)));
StackType_t gEmmcLoaderTaskStack[TASK_SIZE] __attribute__((aligned(32)));
StaticTask_t gEmmcLoaderTaskObj;
TaskHandle_t gEmmcLoaderTask;

StackType_t gNorLoaderTaskStack[TASK_SIZE] __attribute__((aligned(32)));
StaticTask_t gNorLoaderTaskObj;
TaskHandle_t gNorLoaderTask;

StackType_t gIpcTaskStack[TASK_SIZE] __attribute__((aligned(32)));
StaticTask_t gIpcTaskObj;
TaskHandle_t gIpcTask;

uint8_t NORReady=0;
uint8_t eMMCReady=0;
#ifndef DM_WD_DISABLE
static SemaphoreP_Object WD_sem;
#endif
extern SemaphoreP_Object eMMC_sem;

RPMessage_Object gRecvMsgObject;

void sbl_emmc_loader_stage2_main(void *args);
void sbl_nor_loader_stage2_main(void *args);
int32_t AppEmmcLoader_driversOpen(void);

#ifndef DM_WD_DISABLE
void InternalWatchdog_Service(void)
{
	const uint32_t baseAddr = SDL_WKUP_RTI0_CFG_BASE;
	
	SemaphoreP_pend(&WD_sem,SystemP_WAIT_FOREVER);
	
	/* First write operation 0xE51A */
	HW_WR_FIELD32(baseAddr + RTI_RTIWDKEY,
				  RTI_RTIWDKEY_WDKEY,
				  RTI_RTIWDKEY_WDKEY_FIRST_WRITE);
	/* Second write operation 0xA35C */
	HW_WR_FIELD32(baseAddr + RTI_RTIWDKEY,
				  RTI_RTIWDKEY_WDKEY,
				  RTI_RTIWDKEY_WDKEY_SECOND_WRITE);

	SemaphoreP_post(&WD_sem);
}
#endif

void ipc_thread(void *args)
{
    RPMessage_CreateParams createParams;
    int32_t status;
 
    RPMessage_CreateParams_init(&createParams);
    createParams.localEndPt = IPC_LOCAL_ENDPT;
    status = RPMessage_construct(&gRecvMsgObject, &createParams);
    DebugP_assert(status==SystemP_SUCCESS);

        /* wait for messages forever in a loop */
    while(1)
    {
        uint8_t recvMsg[IPC_RPMESSAGE_MAX_MSG_SIZE + 1];
        uint16_t recvMsgSize, remoteCoreId;
        uint32_t remoteCoreEndPt;
		int32_t status;

        /* set 'recvMsgSize' to size of recv buffer,
        * after return `recvMsgSize` contains actual size of valid data in recv buffer
        */
        recvMsgSize = sizeof(recvMsg);
        /* wait for message */
        status = RPMessage_recv(&gRecvMsgObject,
            recvMsg, &recvMsgSize,
            &remoteCoreId, &remoteCoreEndPt,
            SystemP_WAIT_FOREVER);
 
		if( (remoteCoreId == CSL_CORE_ID_MCU_R5FSS0_0) && (status == SystemP_SUCCESS))
		{
			switch (remoteCoreEndPt)
			{
				case IPC_SHUTDOWN_MESSAGE_REMOTE_ENDPT:
				{
					const uint32_t shutdown_request = 0xFAFBFCFA; // Data from VIP for shutdown request
					uint32_t shutdown_response = 0xAFAFBFBF; // Data to send back to VIP from DM

					if ((recvMsgSize==sizeof(shutdown_request)) && (memcmp(recvMsg,&shutdown_request,sizeof(shutdown_request))==0))
					{
						// shutdown, drivers already closed, nothing to do
						
						RPMessage_send( // confirm shutdown
							&shutdown_response, sizeof(shutdown_response),
							remoteCoreId, remoteCoreEndPt,
							RPMessage_getLocalEndPt(&gRecvMsgObject),
							SystemP_WAIT_FOREVER);
					}
					break;
				}
				case IPC_DLT_MESSAGE_REMOTE_ENDPT:
				{
					callback_DLT_VP_MESSAGE(recvMsg, recvMsgSize);						
					break;
				}
			}
		}
    }
}


void EmmcDriverOpen(void)
{   int32_t status;
    status = AppEmmcLoader_driversOpen();
    if(status == SystemP_FAILURE)
    {
	DebugP_logError("S2 AppEmmc_driversOpen  :Failed status %d \r\n", status);
	DLT_LogMessage(DLT_LOG_FATAL, 0xF937, NULL, 0, "S2 eMMC driver open failed");
    }
}

void main_thread(void *args)
{
    int32_t status = SystemP_SUCCESS;
	#ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("MAIN THREAD: Enter...");
    #endif
	
#if 0

	int32_t pinNum;
        /* ETH PIN */
    pinNum       = 91; //DO_ENET_EN
    GPIO_setDirMode(CSL_GPIO0_BASE, pinNum, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(CSL_GPIO0_BASE, pinNum);
    /* ETH PIN */
    pinNum       = 87; //DO_ENET_RSTB;
    GPIO_setDirMode(CSL_GPIO0_BASE, pinNum, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(CSL_GPIO0_BASE, pinNum);
    /* HDMI PD PIN */
    pinNum       = 65; //HDMI_PD_PIN;
    GPIO_setDirMode(CSL_GPIO0_BASE, pinNum, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteLow(CSL_GPIO0_BASE, pinNum);

    pinNum       = 67; //UB940 PD _PIN;
    GPIO_setDirMode(CSL_GPIO0_BASE, pinNum, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(CSL_GPIO0_BASE, pinNum);


    pinNum       = 2; // UB940 1_2v Enable;
    GPIO_setDirMode(CSL_GPIO1_BASE, pinNum, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(CSL_GPIO1_BASE, pinNum);



    uint32_t gpioBaseAddr_MCU;

     /* Get address after translation translate */
    gpioBaseAddr_MCU =  (uint32_t) AddrTranslateP_getLocalAddr(CONFIG_GPIO0_BASE_ADDR);
    pinNum       = 22; //DO_3V3_DISP
    GPIO_setDirMode(gpioBaseAddr_MCU, pinNum, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteLow(gpioBaseAddr_MCU, pinNum);

    pinNum       = 52; //DO_DISP_RESET 
    GPIO_setDirMode(CSL_GPIO0_BASE, pinNum, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(CSL_GPIO0_BASE, pinNum);

    pinNum       = 45; //DO_DISP_STBY
    GPIO_setDirMode(CSL_GPIO1_BASE, pinNum, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(CSL_GPIO1_BASE, pinNum);
    
    pinNum       = 23; // DO_TFT_BL_EN
    GPIO_setDirMode(gpioBaseAddr_MCU, pinNum, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(gpioBaseAddr_MCU, pinNum);

    pinNum       = 9; //PWM_TFT_DIMMING
    GPIO_setDirMode(CSL_GPIO1_BASE, pinNum, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(CSL_GPIO1_BASE, pinNum);

#endif

	#ifndef DM_WD_DISABLE
	SemaphoreP_constructMutex(&WD_sem);
	InternalWatchdog_Service();
	#endif
	SemaphoreP_constructMutex(&eMMC_sem);
	DLT_init();

    /* Configure sciserver task parameters */
    Sciserver_TirtosCfgPrms_t sciserverCfg = {0};
    sciserverCfg.hiTaskStack    =   gUserHiTaskStack;
    sciserverCfg.loTaskStack    =   gUserLoTaskStack;
    sciserverCfg.taskStackSize  =   SCISERVER_TASK_STACK_SIZE;

    /* Open drivers */
    Drivers_open();

    /* Open flash and board drivers */
    status = Board_driversOpen();
    DebugP_assert(status==SystemP_SUCCESS);

    /* Init LPM specific data */
    Sciclient_initDeviceManagerLPMData(&gDMLPMData);

    gUartHandle[CONFIG_UART_SBL] = UART_open(CONFIG_UART_SBL, &gUartParams[CONFIG_UART_SBL]);
    if(NULL == gUartHandle[CONFIG_UART_SBL])
    {
        DebugP_logError("UART open failed for instance %d !!!\r\n", CONFIG_UART_SBL);
    }

	#ifdef DLT_TEST_LOGGING
	DLT_LogMessage(DLT_LOG_FATAL, 0xF900, NULL, 0, "Test log message"); // test write to eMMC
	#endif
	
    gIpcTask = xTaskCreateStatic( ipc_thread,   /* Pointer to the function that implements the task. */
                                  "ipc_thread", /* Text name for the task.  This is to facilitate debugging only. */
                                  TASK_SIZE,  /* Stack depth in units of StackType_t typically uint32_t on 32b CPUs */
                                  (void*)1,            /* We are not using the task parameter. */
                                  TASK_PRI_IPC_THREAD,   /* task priority, 0 is lowest priority, configMAX_PRIORITIES-1 is highest */
                                  gIpcTaskStack,  /* pointer to stack base */
                                  &gIpcTaskObj ); /* pointer to statically allocated task object memory */
    configASSERT(gIpcTask != NULL);


#ifdef MULTITHREADSBL2  // Bootloader SDK is not thread-safe, disable threading
#if defined(ENABLE_HSM) || defined(ENABLE_MCU)
    gNorLoaderTask = xTaskCreateStatic( sbl_nor_loader_stage2_main,   /* Pointer to the function that implements the task. */
                                  "nor_loader_thread", /* Text name for the task.  This is to facilitate debugging only. */
                                  TASK_SIZE,  /* Stack depth in units of StackType_t typically uint32_t on 32b CPUs */
                                  (void*)1,            /* We are not using the task parameter. */
                                  TASK_PRI_NOR_LOADER_THREAD,   /* task priority, 0 is lowest priority, configMAX_PRIORITIES-1 is highest */
                                  gNorLoaderTaskStack,  /* pointer to stack base */
                                  &gNorLoaderTaskObj ); /* pointer to statically allocated task object memory */
    configASSERT(gNorLoaderTask != NULL);
#endif

#ifdef ENABLE_GIP
    gEmmcLoaderTask = xTaskCreateStatic( sbl_emmc_loader_stage2_main,   /* Pointer to the function that implements the task. */
                                  "emmc_loader_thread", /* Text name for the task.  This is to facilitate debugging only. */
                                  TASK_SIZE,  /* Stack depth in units of StackType_t typically uint32_t on 32b CPUs */
                                  (void*)1,            /* We are not using the task parameter. */
                                  TASK_PRI_EMMC_LOADER_THREAD,   /* task priority, 0 is lowest priority, configMAX_PRIORITIES-1 is highest */
                                  gEmmcLoaderTaskStack,  /* pointer to stack base */
                                  &gEmmcLoaderTaskObj ); /* pointer to statically allocated task object memory */
    configASSERT(gEmmcLoaderTask != NULL);
#endif
#endif

    BOOT_KPI_LOG(KPI_ID_SBL_S2_MAIN_SCISERVER_START, "S2: SCISERVER_INIT ");
    sciServer_init(&sciserverCfg);

#ifndef MULTITHREADSBL2 
	// call loaders as functions
	sbl_nor_loader_stage2_main(NULL);
	if (1==NORReady)
	{
		sbl_emmc_loader_stage2_main(NULL);
	}
#endif

    #ifdef KPI_GPIO
    GPIO_pinWriteLow(KPI_STAGE2_GPIO_BASE, KPI_STAGE2_GPIO_PINNUM);
    #endif
    BOOT_KPI_LOG(KPI_ID_SBL_S2_MAIN_END, "S2: Main END");
    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("MAIN THREAD: EXIT !!!");
    #endif
	
	#ifdef DLT_TEST_LOGGING
	int x=0;
	char s[28];
	#endif

	// DM main loop
	while (1)
	{
		#ifndef DM_WD_DISABLE
		if (NORReady && eMMCReady) 
		{
			InternalWatchdog_Service();
		}
		#endif

		vTaskDelay( pdMS_TO_TICKS( 100UL ) );		
		callback_DLT_TimerTick(100);

		#ifdef DLT_TEST_LOGGING
		x++;
		if((x%11) == 10)
		{
			callback_DLT_RAM_BufferEmptyNotification(1);
		}
		sprintf(s,"log message %d",x);
		DLT_LogMessage(DLT_LOG_INFO, 0xF900, NULL, 0, s);
		DebugP_log("%s\r\n",s);
		#endif
	}

    /* Close board and flash drivers */
    Board_driversClose();
    /* Close drivers */
    Drivers_close();

    vTaskDelete(NULL);
}

#ifdef KPI_GPIO
static Pinmux_PerCfg_t gPinMuxMainCfg[] = {
    {
        KPI_STAGE2_GPIO_PIN_NAME,
        PIN_MODE(7) | ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END, PINMUX_END}
};
#endif

int main()
{
    #ifdef KPI_GPIO
    Pinmux_config(gPinMuxMainCfg, PINMUX_DOMAIN_ID_MAIN);
    GPIO_setDirMode(KPI_STAGE2_GPIO_BASE, KPI_STAGE2_GPIO_PINNUM, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(KPI_STAGE2_GPIO_BASE, KPI_STAGE2_GPIO_PINNUM);
    #endif
	BOOT_KPI_LOG(KPI_ID_SBL_S2_MAIN_START, "S2_START");
    Bootloader_profileReset();


    /* init SOC specific modules */
    System_init();
    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("System_init");
    #endif

    Module_clockSBLEnable();
    Module_clockSBLSetFrequency();
    
    Board_init();
    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("Board_init");
    #endif
    
    DebugP_uartSetDrvIndex(CONFIG_UART_SBL);

    gMainTask = xTaskCreateStatic( main_thread,   /* Pointer to the function that implements the task. */
                                  "main_thread", /* Text name for the task.  This is to facilitate debugging only. */
                                  TASK_SIZE,  /* Stack depth in units of StackType_t typically uint32_t on 32b CPUs */
                                  NULL,            /* We are not using the task parameter. */
                                  TASK_PRI_MAIN_THREAD,   /* task priority, 0 is lowest priority, configMAX_PRIORITIES-1 is highest */
                                  gMainTaskStack,  /* pointer to stack base */
                                  &gMainTaskObj ); /* pointer to statically allocated task object memory */
    configASSERT(gMainTask != NULL);

    Bootloader_profileAddProfilePoint("Start OS");

    /* Start the scheduler to start the tasks executing. */
    vTaskStartScheduler();

    /* The following line should never be reached because vTaskStartScheduler()
    will only return if there was not enough FreeRTOS heap memory available to
    create the Idle and (if configured) Timer tasks.  Heap management, and
    techniques for trapping heap exhaustion, are described in the book text. */
    DebugP_assertNoLog(0);

    return 0;
}
