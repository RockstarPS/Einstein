///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///---------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include "UclALOs.h"

//TestSemaphore
static uint32 UclALOsTest_TestSem1_Id;
static uint8 UclALOsTest_TestSem_Task1_data;
static uint8 UclALOsTest_TestSem_Task2_data;
static uint32 UclALOsTest_TestSem_Task1_Id;
static uint32 UclALOsTest_TestSem_Task2_Id;
void *UclALOsTest_TestSem_Task1(void *arg);
void *UclALOsTest_TestSem_Task2(void *arg);

//TestMutex
static uint32 UclALOsTest_TestMutex1_Id;
static uint8 UclALOsTest_TestMutex_Task1_data;
static uint8 UclALOsTest_TestMutex_Task2_data;
static uint32 UclALOsTest_TestMutex_Task1_Id;
static uint32 UclALOsTest_TestMutex_Task2_Id;
void *UclALOsTest_TestMutex_Task1(void *arg);
void *UclALOsTest_TestMutex_Task2(void *arg);

// TestTask
static uint32 UclALOsTest_TestTask_Task1_Id;
static uint32 UclALOsTest_TestTask_Task2_Id;
static uint32 UclALOsTest_TestTask_Task3_Id;
static uint32 UclALOsTest_TestTask_Task4_Id;
static uint32 UclALOsTest_TestTask_Task5_Id;
static uint8 UclALOsTest_TestTask_Task1_data;
static uint8 UclALOsTest_TestTask_Task2_data;
static uint8 UclALOsTest_TestTask_Task3_data;
static uint8 UclALOsTest_TestTask_Task4_data;
static uint8 UclALOsTest_TestTask_Task5_data;
void *UclALOsTest_TestTask_Task1(void *arg);
void *UclALOsTest_TestTask_Task2(void *arg);
void *UclALOsTest_TestTask_Task3(void *arg);
void *UclALOsTest_TestTask_Task4(void *arg);
void *UclALOsTest_TestTask_Task5(void *arg);

// TestTimer
static uint32 UclALOsTest_TestTimer_Timer1_Id;
static uint32 UclALOsTest_TestTimer_Timer2_Id;
static uint8 UclALOsTest_TestTimer_Task1_data;
static uint8 UclALOsTest_TestTimer_Task2_data;
void *UclALOsTest_TestTimer_Task1(void *arg);
void *UclALOsTest_TestTimer_Task2(void *arg);

static void UclALOsTest_TestTask(uint8 InstId);
static void UclALOsTest_TestTimer(uint8 InstId);
static void UclALOsTest_TestMutex(uint8 InstId);
static void UclALOsTest_TestSem(uint8 InstId);

void UclALOsTest_Init(uint8 InstId)
{
    UclALOsTest_TestTask_Task1_data = 0;
    UclALOsTest_TestTask_Task2_data = 0;
    UclALOsTest_TestTask_Task3_data = 0;
    UclALOsTest_TestTask_Task4_data = 0;
    UclALOsTest_TestTask_Task5_data = 0;

    UclALOsTest_TestTimer_Task1_data = 0;
    UclALOsTest_TestTimer_Task2_data = 0;

    UclALOsTest_TestMutex_Task1_data = 0;
    UclALOsTest_TestMutex_Task2_data = 0;

    UclALOsTest_TestSem_Task1_data = 0;
    UclALOsTest_TestSem_Task2_data = 0;
}

void UclALOsTest_Run(uint8 InstId)
{
    uint64 time;

    time = UclALOs_GetSystemTimeMs(0);
    printf("BEGIN: Test %" PRIu64 "\n", time);

    UclALOsTest_TestTask(InstId);
    UclALOsTest_TestTimer(InstId);
    UclALOsTest_TestMutex(InstId);
    UclALOsTest_TestSem(InstId);

    time = UclALOs_GetSystemTimeMs(0);
    printf("END: Test %" PRIu64 "\n", time);
}

static void UclALOsTest_TestSem(uint8 InstId)
{
    Ucl_ReturnType Ret;
    uint8 bFailed = FALSE;

    printf("BEGIN: TestSem\n");

    Ret = UclALOs_SemCreate(0, &UclALOsTest_TestSem1_Id, 1);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestSem MutexCreate %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TaskCreate(0, &UclALOsTest_TestSem_Task1_Id, UclALOsTest_TestSem_Task1,
                             &UclALOsTest_TestSem_Task1_data);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestSem TaskCreate %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TaskCreate(0, &UclALOsTest_TestSem_Task2_Id, UclALOsTest_TestSem_Task2,
                             &UclALOsTest_TestSem_Task2_data);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestSem TaskCreate %d, %d\n", 2, Ret);
        bFailed = TRUE;
    }

    usleep(10000000);

    printf("DESTROY: TestSem\n");

    Ret = UclALOs_SemDestroy(0, UclALOsTest_TestSem1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestSem MutexDestroy %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }

    if (1 != UclALOsTest_TestSem_Task1_data)
    {
        printf("FAIL: TestSem TaskExec %d, %d\n", 1, UclALOsTest_TestSem_Task1_data);
        bFailed = TRUE;
    }
    if (1 != UclALOsTest_TestSem_Task2_data)
    {
        printf("FAIL: TestSem TaskExec %d, %d\n", 2, UclALOsTest_TestSem_Task2_data);
        bFailed = TRUE;
    }

    if (FALSE == bFailed)
    {
        printf("PASS: TestSem\n");
    }
}

static void UclALOsTest_TestMutex(uint8 InstId)
{
    Ucl_ReturnType Ret;
    uint8 bFailed = FALSE;

    printf("BEGIN: TestMutex\n");

    Ret = UclALOs_MutexCreate(0, &UclALOsTest_TestMutex1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestMutex MutexCreate %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TaskCreate(0, &UclALOsTest_TestMutex_Task1_Id, UclALOsTest_TestMutex_Task1,
                             &UclALOsTest_TestMutex_Task1_data);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestMutex TaskCreate %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TaskCreate(0, &UclALOsTest_TestMutex_Task2_Id, UclALOsTest_TestMutex_Task2,
                             &UclALOsTest_TestMutex_Task2_data);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestMutex TaskCreate %d, %d\n", 2, Ret);
        bFailed = TRUE;
    }

    usleep(10000000);

    printf("DESTROY: TestMutex\n");

    Ret = UclALOs_MutexDestroy(0, UclALOsTest_TestMutex1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestMutex MutexDestroy %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }

    if (1 != UclALOsTest_TestMutex_Task1_data)
    {
        printf("FAIL: TestMutex TaskExec %d, %d\n", 1, UclALOsTest_TestMutex_Task1_data);
        bFailed = TRUE;
    }
    if (1 != UclALOsTest_TestMutex_Task2_data)
    {
        printf("FAIL: TestMutex TaskExec %d, %d\n", 2, UclALOsTest_TestMutex_Task2_data);
        bFailed = TRUE;
    }

    if (FALSE == bFailed)
    {
        printf("PASS: TestMutex\n");
    }
}

static void UclALOsTest_TestTask(uint8 InstId)
{
    Ucl_ReturnType Ret;
    uint8 bFailed = FALSE;

    printf("BEGIN: TestTask\n");

    Ret = UclALOs_TaskCreate(0, &UclALOsTest_TestTask_Task1_Id, UclALOsTest_TestTask_Task1,
                             &UclALOsTest_TestTask_Task1_data);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTask TaskCreate %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TaskCreate(0, &UclALOsTest_TestTask_Task2_Id, UclALOsTest_TestTask_Task2,
                             &UclALOsTest_TestTask_Task2_data);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTask TaskCreate %d, %d\n", 2, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TaskCreate(0, &UclALOsTest_TestTask_Task3_Id, UclALOsTest_TestTask_Task3,
                             &UclALOsTest_TestTask_Task3_data);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTask TaskCreate %d, %d\n", 3, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TaskCreate(0, &UclALOsTest_TestTask_Task4_Id, UclALOsTest_TestTask_Task4,
                             &UclALOsTest_TestTask_Task4_data);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTask TaskCreate %d, %d\n", 4, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TaskCreate(0, &UclALOsTest_TestTask_Task5_Id, UclALOsTest_TestTask_Task5,
                             &UclALOsTest_TestTask_Task5_data);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTask TaskCreate %d, %d\n", 5, Ret);
        bFailed = TRUE;
    }

    usleep(6000000);

    Ret = UclALOs_TaskDestroy(0, UclALOsTest_TestTask_Task5_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTask TaskDestroy %d, %d\n", 5, Ret);
        bFailed = TRUE;
    }

    if (5 != UclALOsTest_TestTask_Task1_data)
    {
        printf("FAIL: TestTask TaskExec %d, %d\n", 1, UclALOsTest_TestTask_Task1_data);
        bFailed = TRUE;
    }
    if (5 != UclALOsTest_TestTask_Task2_data)
    {
        printf("FAIL: TestTask TaskExec %d, %d\n", 2, UclALOsTest_TestTask_Task2_data);
        bFailed = TRUE;
    }
    if (5 != UclALOsTest_TestTask_Task3_data)
    {
        printf("FAIL: TestTask TaskExec %d, %d\n", 3, UclALOsTest_TestTask_Task3_data);
        bFailed = TRUE;
    }
    if (5 != UclALOsTest_TestTask_Task4_data)
    {
        printf("FAIL: TestTask TaskExec %d, %d\n", 4, UclALOsTest_TestTask_Task4_data);
        bFailed = TRUE;
    }
    if (5 > UclALOsTest_TestTask_Task5_data)
    {
        printf("FAIL: TestTask TaskExec %d, %d\n", 5, UclALOsTest_TestTask_Task5_data);
        bFailed = TRUE;
    }

    if (FALSE == bFailed)
    {
        printf("PASS: TestTask\n");
    }
}

static void UclALOsTest_TestTimer(uint8 InstId)
{
    Ucl_ReturnType Ret;
    uint8 bFailed = FALSE;

    printf("BEGIN: TestTimer\n");

    Ret = UclALOs_TimerCreate(0, &UclALOsTest_TestTimer_Timer1_Id, UclALOsTest_TestTimer_Task1,
                              &UclALOsTest_TestTimer_Task1_data, eUclOsTimerType_OneShot);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerCreate %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TimerCreate(0, &UclALOsTest_TestTimer_Timer2_Id, UclALOsTest_TestTimer_Task2,
                              &UclALOsTest_TestTimer_Task2_data, eUclOsTimerType_Periodic);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerCreate %d, %d\n", 2, Ret);
        bFailed = TRUE;
    }

    printf("START: TestTimer\n");
    Ret = UclALOs_TimerStart(0, UclALOsTest_TestTimer_Timer1_Id, 1000);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerStart %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TimerStart(0, UclALOsTest_TestTimer_Timer2_Id, 1500);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerStart %d, %d\n", 2, Ret);
        bFailed = TRUE;
    }

    usleep(5000000);

    printf("STOP: TestTimer\n");
    Ret = UclALOs_TimerStop(0, UclALOsTest_TestTimer_Timer1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerStop %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TimerStop(0, UclALOsTest_TestTimer_Timer2_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerStop %d, %d\n", 2, Ret);
        bFailed = TRUE;
    }

    usleep(5000000);

    printf("START: TestTimer\n");
    Ret = UclALOs_TimerStart(0, UclALOsTest_TestTimer_Timer1_Id, 1000);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerStart %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TimerStart(0, UclALOsTest_TestTimer_Timer2_Id, 1500);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerStart %d, %d\n", 2, Ret);
        bFailed = TRUE;
    }

    usleep(5000000);

    printf("STOP: TestTimer\n");
    Ret = UclALOs_TimerStop(0, UclALOsTest_TestTimer_Timer1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerStop %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TimerStop(0, UclALOsTest_TestTimer_Timer2_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerStop %d, %d\n", 2, Ret);
        bFailed = TRUE;
    }

    Ret = UclALOs_TimerDestroy(0, UclALOsTest_TestTimer_Timer1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerDestroy %d, %d\n", 1, Ret);
        bFailed = TRUE;
    }
    Ret = UclALOs_TimerDestroy(0, UclALOsTest_TestTimer_Timer2_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestTimer TimerDestroy %d, %d\n", 2, Ret);
        bFailed = TRUE;
    }

    if (FALSE == bFailed)
    {
        printf("PASS: TestTimer\n");
    }
}

void *UclALOsTest_TestSem_Task1(void *arg)
{
    Ucl_ReturnType Ret;
    uint8 *data = (uint8 *)arg;

    (*data) = (*data) + 1;
    printf("UclALOsTest_TestSem_Task1 started\n");

    Ret = UclALOs_SemWait(0, UclALOsTest_TestSem1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestSem SemWait %d, %d\n", 1, Ret);
        (*data) = 0;
    }
    printf("UclALOsTest_TestSem_Task1 Sem 1 Locked\n");

    usleep(2000000);

    printf("UclALOsTest_TestSem_Task1 Sem 1 UnLocked\n");
    Ret = UclALOs_SemPost(0, UclALOsTest_TestSem1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestSem SemPost %d, %d\n", 1, Ret);
        (*data) = 0;
    }
    return NULL;
}

void *UclALOsTest_TestSem_Task2(void *arg)
{
    Ucl_ReturnType Ret;
    uint8 *data = (uint8 *)arg;

    (*data) = (*data) + 1;
    printf("UclALOsTest_TestSem_Task2 started\n");

    usleep(1000000);

    printf("UclALOsTest_TestSem_Task2 Waiting to Lock Sem 1\n");

    Ret = UclALOs_SemWait(0, UclALOsTest_TestSem1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestSem SemWait %d, %d\n", 1, Ret);
        (*data) = 0;
    }
    printf("UclALOsTest_TestSem_Task2 Locked Sem 1\n");

    usleep(2000000);

    printf("UclALOsTest_TestSem_Task2 Sem 1 UnLocked\n");
    Ret = UclALOs_SemPost(0, UclALOsTest_TestSem1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestSem SemPost %d, %d\n", 1, Ret);
        (*data) = 0;
    }

    return NULL;
}

void *UclALOsTest_TestMutex_Task1(void *arg)
{
    Ucl_ReturnType Ret;
    uint8 *data = (uint8 *)arg;

    (*data) = (*data) + 1;
    printf("UclALOsTest_TestMutex_Task1 started\n");

    Ret = UclALOs_MutexLock(0, UclALOsTest_TestMutex1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestMutex MutexLock %d, %d\n", 1, Ret);
        (*data) = 0;
    }
    printf("UclALOsTest_TestMutex_Task1 Mutex 1 Locked\n");

    usleep(2000000);

    printf("UclALOsTest_TestMutex_Task1 Mutex 1 UnLocked\n");
    Ret = UclALOs_MutexUnlock(0, UclALOsTest_TestMutex1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestMutex MutexLock %d, %d\n", 1, Ret);
        (*data) = 0;
    }
    return NULL;
}

void *UclALOsTest_TestMutex_Task2(void *arg)
{
    Ucl_ReturnType Ret;
    uint8 *data = (uint8 *)arg;

    (*data) = (*data) + 1;
    printf("UclALOsTest_TestMutex_Task2 started\n");

    usleep(1000000);

    printf("UclALOsTest_TestMutex_Task2 Waiting to Lock Mutex 1\n");

    Ret = UclALOs_MutexLock(0, UclALOsTest_TestMutex1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestMutex MutexLock %d, %d\n", 1, Ret);
        (*data) = 0;
    }
    printf("UclALOsTest_TestMutex_Task2 Locked Mutex 1\n");

    usleep(2000000);

    printf("UclALOsTest_TestMutex_Task2 Mutex 1 UnLocked\n");
    Ret = UclALOs_MutexUnlock(0, UclALOsTest_TestMutex1_Id);
    if (UCL_E_OK != Ret)
    {
        printf("FAIL: TestMutex MutexLock %d, %d\n", 1, Ret);
        (*data) = 0;
    }

    return NULL;
}

void *UclALOsTest_TestTimer_Task1(void *arg)
{
    uint8 *data = (uint8 *)arg;
    (*data) = (*data) + 1;
    printf("UclALOsTest_TestTimer_Task1 running 0x%04x %d\n", data, *data);
    return NULL;
}

void *UclALOsTest_TestTimer_Task2(void *arg)
{
    uint8 *data = (uint8 *)arg;
    printf("UclALOsTest_TestTimer_Task2 running 0x%04x %d\n", data, *data);
    (*data) = (*data) + 1;
    return NULL;
}

void *UclALOsTest_TestTask_Task1(void *arg)
{
    uint8 *data = (uint8 *)arg;
    while (1)
    {
        (*data) = (*data) + 1;
        printf("UclALOsTest_TestTask_Task1 running 0x%04x %d\n", data, *data);
        usleep(1000000);
        if (*data >= 5)
        {
            break;
        }
    }
    return NULL;
}

void *UclALOsTest_TestTask_Task2(void *arg)
{
    uint8 *data = (uint8 *)arg;
    while (1)
    {
        (*data) = (*data) + 1;
        printf("UclALOsTest_TestTask_Task2 running 0x%04x %d\n", data, *data);
        usleep(1000000);
        if (*data >= 5)
        {
            break;
        }
    }
    return NULL;
}

void *UclALOsTest_TestTask_Task3(void *arg)
{
    uint8 *data = (uint8 *)arg;
    while (1)
    {
        (*data) = (*data) + 1;
        printf("UclALOsTest_TestTask_Task3 running 0x%04x %d\n", data, *data);
        usleep(1000000);
        if (*data >= 5)
        {
            break;
        }
    }
    return NULL;
}

void *UclALOsTest_TestTask_Task4(void *arg)
{
    uint8 *data = (uint8 *)arg;
    while (1)
    {
        (*data) = (*data) + 1;
        printf("UclALOsTest_TestTask_Task4 running 0x%04x %d\n", data, *data);
        usleep(1000000);
        if (*data >= 5)
        {
            break;
        }
    }
    return NULL;
}

void *UclALOsTest_TestTask_Task5(void *arg)
{
    uint8 *data = (uint8 *)arg;
    while (1)
    {
        (*data) = (*data) + 1;
        printf("UclALOsTest_TestTask_Task5 running 0x%04x %d\n", data, *data);
        usleep(1000000);
    }
}
