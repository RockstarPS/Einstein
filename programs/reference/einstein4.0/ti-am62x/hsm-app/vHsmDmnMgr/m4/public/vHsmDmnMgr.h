/***************************************************************************/
/**
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
 * \file vHsmDmnMgr.h
 *
 * \brief
 * Domain Manager Grace shutdown of HSM core header
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Chennai, India
 ******************************************************************************/
#ifndef VHSMDMNMGR_H
#define VHSMDMNMGR_H

#include "Std_Types.h"

/**
 *********************************************************************************************
 ** \fn        vHsmDmnMgr_Init
 **
 ** \brief     Initialize the Domain Manager
 **
 ** \details   Initializes Grace shutdown
 **
 ** \param[in] void
 **
 ** \return    void
 **
 ** \note      This function is mandatory Domain Manager.
 **
 *********************************************************************************************
 */
void vHsmDmnMgr_Init(void);

/**
 *********************************************************************************************
 ** \fn        vHsmDmnMgr_Shutdown
 **
 ** \brief     API to Start grace shutdown
 **
 ** \details   Function to Start Grace shutdown.
 **
 ** \param[in] void
 **
 ** \return    Std_ReturnType
 **            E_OK      - Write job accepted.
 **            E_NOT_OK  - Write job failed to start.
 **
 **
 *********************************************************************************************
 */
Std_ReturnType vHsmDmnMgr_Shutdown(void);

/**
 *********************************************************************************************
 ** \fn        vHsmDmnMgr_MainFunction
 **
 ** \brief     MainFunction to monitor Grace shutdown
 **
 ** \details   Should be called periodically by the OS or scheduler. It processes
 **            ongoing Domain Manager shutdown.
 **
 ** \param[in] void
 **
 ** \return    void
 **
 ** \note      This function is mandatory for non-blocking HSM core shutdown.
 **
 *********************************************************************************************
 */
void vHsmDmnMgr_MainFunction(void);
#endif /*VHSMDMNMGR*/
/*EOF*/
