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
#include "UclSys.h"
#include "UclALDebug.h"
#include "UclDL_Types.h"
#include "UclTest.h"
#include "UclDLCbk_Types.h"

int main(int c, char **argv)
{
    UclSys_Initialize(0);

    UclTest_Initialize(0);

    while (1)
    {
        usleep(1000000);
    }
}

void App_UclFatalError(uint8 DLInst, uint8 Status)
{
}

void App_UclMsgReceivedFunc(uint8 DLInst, EUclDLRxStatus Status, SUclDLMsg *pMsg)
{
}

void App_UclMsgTransmitStatusFunc(uint8 DLInst, uint16 MsgId, EUclDLAckStatus Status)
{
}

void App_UclLinkStatusChangedFunc(uint8 DLInst, EUclDLLinkStatus Status)
{
    UclTest_Start(0);
}
