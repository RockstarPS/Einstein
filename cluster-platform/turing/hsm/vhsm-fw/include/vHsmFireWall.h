/***************************************************************************
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
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
 * \file vHsmFireWall.h
 *
 * \brief
 * HSM FireWall settings for AM62PX HSM M4F core source file
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 |            | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/
#ifndef VHSMFW_H
#define VHSMFW_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"
#include "config.h"
#include "vHsmFWCfg.h"

#ifdef VHSMFW_ENABLE

/**
 *********************************************************************************************
 ** \fn        vHsmFireWall_isEnable
 **
 ** \brief     Check if FireWall sub-system is enabled for HSM
 **
 ** \param[in] void
 **
 ** \return    0: FireWall sub-system is disabled, 1: FireWall sub-system is enabled
 **
 ** \note      This function is used to check the status of HSM firewall.
 **
 *********************************************************************************************
 */
uint8 vHsmFireWall_isEnable(void);

/**
 *********************************************************************************************
 ** \fn        vHsmFireWall_init
 **
 ** \brief     Initialize HSM FireWall sub-system
 **
 ** \param[in] void
 **
 ** \return    void
 **
 ** \note      This function is mandatory to Enable FireWall in HSM.
 **
 *********************************************************************************************
 */
void vHsmFireWall_init(void);
#ifdef FIREWALL_FETCHAPI
/**
 *********************************************************************************************
 ** \fn        vHsmFireWall_ChangeOwner
 **
 ** \brief     Function to Change the owner for particular FW ID using TISCI message to TIFS
 **
 ** \param[in] fw_Id,   firewall ID in question. fw_Id is defined in the TRM.
 ** \param[in] region,  Region or channel number if applicable
 ** \param[in] owner_index,  New owner index to transfer ownership to
 **
 ** \return    Std_ReturnType E_OK     success
 **                           E_NOT_OK Failure
 **
 ** \note This function is used to change Firewall owner
 **
 *********************************************************************************************
 */
Std_ReturnType vHsmFireWall_ChangeOwner(uint16 fw_Id, uint16 region, uint8 owner_index);

/**
 *********************************************************************************************
 ** \fn        vHsmFireWall_GetFireWall
 **
 ** \brief     Function to get the owner for particular FW ID using TISCI message to TIFS
 **
 ** \param[in] fw_Id,   firewall ID in question. fw_Id is defined in the TRM.
 ** \param[in] region,  Region or channel number if applicable
 ** \param[in] n_permission_regs,  Number of Permission register required
 **
 ** \return    Std_ReturnType E_OK     success
 **                           E_NOT_OK Failure
 **
 ** \note This function is used when to change FireWall
 **
 *********************************************************************************************
 */
Std_ReturnType vHsmFireWall_GetFireWall(uint16 fw_Id, uint16 region, uint32 n_permission_regs);
#endif /*FIREWALL_FETCHAPI*/
#endif /*VHSMFW_ENABLE*/
#endif /*VHSMFW_H*/
/*EOF*/
