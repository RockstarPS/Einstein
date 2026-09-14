/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2024. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        FltM_Soc.c
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef  FLTM_SOC_PPU_C_
#define  FLTM_SOC_PPU_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Ppu.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

#if(FLTM_PPU_ENABLE == STD_ON)
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

static int32_t FltM_Ppu_FireWallConfigure(void);

/*****************************************************************************
*                             Functions                                      *
******************************************************************************/
/*============================================================================
**
** Function Name    :   FltM_Ppu_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise firewall
**                      protection.
**
** Invocation       :   FltM_Soc_Init
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_Ppu_Init(void)
{
    Std_ReturnType flRetVal = E_NOT_OK;
    int32_t status = SystemP_FAILURE;

    status = FltM_Ppu_FireWallConfigure();

    if(SystemP_SUCCESS == status)
    {
        flRetVal = E_OK;
    }
    else
    {
        flRetVal = E_NOT_OK;
    }
    return(flRetVal);
}

/*============================================================================
**
** Function Name    :   FltM_PPU_ReadBack
**
** Visibility       :   Public
**
** Description      :   Periodic Readback for PPU.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_PPU_ReadBack(void)
{
    Std_ReturnType retval = E_OK;
    int32_t status = SystemP_FAILURE;
    uint8 PpuIndex = 0;

    for(PpuIndex = 0; ((PpuIndex < PPU_INSTANCE_CONFIGURED) &&
                                       (retval == E_OK)); PpuIndex++)
    {

        const struct tisci_msg_fwl_get_firewall_region_req fwl_get_req =
        {
            .fwl_id = Ppu_Config[PpuIndex].fwl_id,
            .region = Ppu_Config[PpuIndex].region_id,
            .n_permission_regs = Ppu_Config[PpuIndex].n_permission_regs,
        };
        struct tisci_msg_fwl_get_firewall_region_resp fwl_get_resp = { 0 };
        /* Readback the firewall configurations done */
        status = Sciclient_firewallGetRegion(&fwl_get_req, &fwl_get_resp, FLTM_PPU_TIMEOUT);

        /* Compare with Configuration Settings */
        if(status == SystemP_SUCCESS)
        {
            if((fwl_get_resp.control != Ppu_Config[PpuIndex].control) ||
                (fwl_get_resp.permissions[0] != Ppu_Config[PpuIndex].permissions_0) ||
                (fwl_get_resp.permissions[1] != Ppu_Config[PpuIndex].permissions_1) ||
                (fwl_get_resp.permissions[2] != Ppu_Config[PpuIndex].permissions_2))
            {
                retval = E_NOT_OK;
            }
            else
            {
                retval = E_OK;
            }

        }
        else
        {
            retval = E_NOT_OK;
        }
    }

    return retval;
}

/*============================================================================
**
** Function Name    :   FltM_Ppu_FireWallConfigure
**
** Visibility       :   Private
**
** Description      :   Translates 64-bit address to 32-bit address space
**
** Invocation       :   FltM_Ppu_Init
**
** Inputs           :   None
**
** Outputs          :   uint32
**
** Critical Section :   No
**
**==========================================================================*/
static int32_t FltM_Ppu_FireWallConfigure(void)
{
    int32_t status = SystemP_SUCCESS;
    uint8 PpuIndex = 0;

    for(PpuIndex = 0; ((PpuIndex < PPU_INSTANCE_CONFIGURED) &&
                                       (status == SystemP_SUCCESS)); PpuIndex++)
    {
        /* Lock the region ownership to MCU core, so that other cores cannot
        *  modify the below region firewall configuration.
        */
        if(Ppu_Config[PpuIndex].control == FLTM_FIREWALL_FGND)
        {
            const struct tisci_msg_fwl_change_owner_info_req fwl_owner_req =
            {
                .fwl_id = Ppu_Config[PpuIndex].fwl_id,
                .region = Ppu_Config[PpuIndex].region_id,
                .owner_index = TISCI_HOST_ID_MCU_0_R5_0,
            };
            struct tisci_msg_fwl_change_owner_info_resp fwl_owner_resp = { 0 };
            status = Sciclient_firewallChangeOwnerInfo(&fwl_owner_req, &fwl_owner_resp, FLTM_PPU_TIMEOUT);
        }
        if(status == SystemP_SUCCESS)
        {
            const struct tisci_msg_fwl_set_firewall_region_req fwl_set_req =
            {
                .fwl_id = Ppu_Config[PpuIndex].fwl_id,
                .region = Ppu_Config[PpuIndex].region_id,
                .n_permission_regs = Ppu_Config[PpuIndex].n_permission_regs,
                .control = Ppu_Config[PpuIndex].control,
                .permissions[0] = Ppu_Config[PpuIndex].permissions_0,
                .permissions[1] = Ppu_Config[PpuIndex].permissions_1,
                .permissions[2] = Ppu_Config[PpuIndex].permissions_2,
                .start_address  = Ppu_Config[PpuIndex].start_address,
                .end_address    = Ppu_Config[PpuIndex].end_address,
            };
            struct tisci_msg_fwl_set_firewall_region_resp fwl_set_resp = { 0 };

            status = Sciclient_firewallSetRegion(&fwl_set_req, &fwl_set_resp, FLTM_PPU_TIMEOUT);
        }
    }
    return(status);
}

/*============================================================================
**
** Function Name    :   FltM_FwlExceptionHandler
**
** Visibility       :   Public
**
** Description      :   Handles firewall exceptions
**
** Invocation       :   Interrupt Service
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_FwlExceptionHandler(void)
{
    FltM_FireWallExceptionCallBack();
}

#endif /*#if(FLTM_PPU_ENABLE == STD_ON)*/

#define FLTM_SEC_CODE_STOP
#define FLTM_CORE_CONST_SEC_END
#define FLTM_CORE_DATA_SEC_END
#define FLTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif
/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/*----------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :02-Jun-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-8501
Change Description:PPU Implementation
-----------------------------------------------------------------------------*/
