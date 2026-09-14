/*
*
* Copyright (c) 2023 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifdef __cplusplus
extern "C"{
#endif

/* ========================================================================== */
/*                           Include Files                                    */
/* ========================================================================== */

#include "CanStub.h"

void CanDrv_Test(void)
{
    // Can_PduType CanPduInfo;
    // uint8 buffer[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    // CanPduInfo.sdu = &buffer[0];
    // CanPduInfo.id = 0x100; // Can Message ID
    // CanPduInfo.length = 8;
    // CanPduInfo.swPduHandle = 0; // Called when message transmits

    // Can_Write(0, &CanPduInfo);
    // Can_Write(1, &CanPduInfo);
}


static volatile uint8 ComFunctionEnabled = 0;
void CanStub_StartEarlyCommunication(void)
{
    static boolean EarlyCommunicationStarted = FALSE;
    if (EarlyCommunicationStarted == FALSE)
    {
        /* Activate COM groups before the first Com_MainFunctionTx execution. */
       Com_IpduGroupStart(COM_IPDU_GROUP_PDUGROUP_CAN0_RX, TRUE);
       Com_IpduGroupStart(COM_IPDU_GROUP_PDUGROUP_CAN0_TX, TRUE);
        /* Channel 0 is the first CAN network. */
        ComM_CommunicationAllowed(0U, TRUE);
        /* This API expects a ComM user, not a channel. */
        (void)ComM_RequestComMode(
           COMM_USER_CAN_USER_ID1,
           COMM_FULL_COMMUNICATION);
        EarlyCommunicationStarted = TRUE;
    }
}

void ComM_TestActivate(void)
{
    if (ComFunctionEnabled == 0U)
    {
        ComFunctionEnabled = 1;
    }
    
}

void stackTest(void)
{
    if(1 == ComFunctionEnabled )
    {
        // ComM_CommunicationAllowed(0, TRUE);
        // ComM_RequestComMode(0, COMM_FULL_COMMUNICATION);
        
        // CanIf_SetPduMode(0, CANIF_ONLINE);
        // CanIf_SetPduMode(1, CANIF_ONLINE);
        Com_IpduGroupStart(0, TRUE);
        Com_IpduGroupStart(1, TRUE);
        //Com_IpduGroupStart(2, TRUE);
        //Com_IpduGroupStart(3, TRUE);
        ComFunctionEnabled = 2;
    }
}

void Can_PlatformInit(void)
{
    volatile uint32_t regVal  = 0U;

    /* Unlock lock key registers for PAD CONFIG: IO PAD configuration registers in PADCFG_CTRL */
	
    /* write Partition 1 Lock Key 0 Register */	
    LLD_REG32_WR(0x4080000UL + 0x5008, 0x68EF3490);
	
    /* write Partition 1 Lock Key 1 Register */
    LLD_REG32_WR(0x4080000UL + 0x500C, 0xD172BC5A);
	
    /* Check for unlock */
    regVal = LLD_REG32_RD(0x4080000UL + 0x5008);
    while ((regVal & 0x1) != 0x1U)
    {
        regVal = LLD_REG32_RD(0x4080000UL + 0x5008);
    }

    /* Unlocking done */
    /* Below code will be replaced by Port module in further releases */
    /* MCU MCAN 0 Tx PAD configuration */
    regVal = 0x10000U;
    LLD_REG32_WR(0x4080000UL + 0x4034U, regVal);
    /* MCU MCAN 0 Rx PAD configuration */
    regVal = 0x50000U;
    LLD_REG32_WR(0x4080000UL + 0x4038U, regVal);
    /* MCU MCAN 1 Tx PAD configuration */
    regVal = 0x60000U;
    LLD_REG32_WR(0x4080000UL + 0x403CU, regVal);
    /* MCU MCAN 1 Rx PAD configuration */
    regVal = 0x60000U;
    LLD_REG32_WR(0x4080000UL + 0x4040U, regVal);
	/* MAIN MCAN 0 Tx PAD configuration */
    regVal = 0x60000U;
    LLD_REG32_WR(0x4080000UL + 0x41D8U, regVal);
    /* MAIN MCAN 0 Rx PAD configuration */
    regVal = 0x60000U;
    LLD_REG32_WR(0x4080000UL + 0x41DCU, regVal);
	
#if defined (SOC_J721E) || defined (SOC_J7200)
    /* Unlock lock key registers for Partition 7: IO PAD
       configuration registers in MAIN_CTRL_MMR */
    /* write Partition 7 Lock Key 0 Register */
    LLD_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1D008, 0x68EF3490);
    /* write Partition 7 Lock Key 1 Register */
    LLD_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1D00C, 0xD172BC5A);
    /* Check for unlock */
    regVal = LLD_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1D008);
    while ((regVal & 0x1) != 0x1U)
    {
        regVal = LLD_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1D008);
    }

    /* Unlock lock key registers for Partition 7: IO PAD
       configuration registers in MAIN_CTRL_MMR */
    /* write Partition 7 Lock Key 0 Register */
    LLD_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1D008, 0x68EF3490);
    /* write Partition 7 Lock Key 1 Register */
    LLD_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1D00C, 0xD172BC5A);
    /* Check for unlock */
    regVal = LLD_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE + 0x1D008);
    while ((regVal & 0x1) != 0x1U)
    {
        regVal = LLD_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE + 0x1D008);
    }

    /* Unlocking done */
    /* Below code will be replaced by Port module in further releases */
    /* MCU MCAN 0 Tx PAD configuration */
    regVal = 0x60000U;
    LLD_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0A8U, regVal);
    /* MCU MCAN 0 Rx PAD configuration */
    regVal = 0x60000U;
    LLD_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0ACU, regVal);
    /* MCU MCAN 1 Tx PAD configuration */
    regVal = 0x60000U;
    LLD_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0C0U, regVal);
    /* MCU MCAN 1 Rx PAD configuration */
    regVal = 0x60000U;
    LLD_REG32_WR(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C0C4U, regVal);
    /* MAIN MCAN 0 Tx PAD configuration */
    regVal = 0x60000U;
    LLD_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C20CU, regVal);
    /* MAIN MCAN 0 Rx PAD configuration */
    regVal = 0x60000U;
    LLD_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C208U, regVal);

    /* MAIN MCAN 4 Tx PAD configuration */
    regVal = 0x60006U;
    LLD_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C020U, regVal);
    /* MAIN MCAN 4 Rx PAD configuration */
    regVal = 0x60006U;
    LLD_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C024U, regVal);
    /* MAIN MCAN 9 Tx PAD configuration */
    regVal = 0x60006U;
    LLD_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C0CCU, regVal);
    /* MAIN MCAN 9 Rx PAD configuration */
    regVal = 0x60006U;
    LLD_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C0D0U, regVal);
    /* MAIN MCAN 11 Tx PAD configuration */
    regVal = 0x60006U;
    LLD_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C11CU, regVal);
    /* MAIN MCAN 11 Rx PAD configuration */
    regVal = 0x60006U;
    LLD_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE + 0x1C120U, regVal);
    #endif
    // Can_TestLoopBackModeEnable(0, 0U);
    // Can_TestLoopBackModeEnable(1, 0U);
}
void CanNmCallOut_PduRxIndication(NetworkHandleType Channel)
{
    (void)Channel;
}
#ifdef __cplusplus
}
#endif