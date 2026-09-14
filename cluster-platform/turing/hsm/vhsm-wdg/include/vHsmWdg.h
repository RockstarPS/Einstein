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
 * \file vHsmWdg.h
 *
 * \brief
 * HSM Watchdog Implementation for AM62PX HSM M4F core Header File
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
#ifndef VHSMWDG_H
#define VHSMWDG_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"


/******************************************************************************
 *  PUBLIC FUNCTION DECLARATIONS
 *****************************************************************************/
/********************************************************************************
 * \fn vHsmWdg_Init(void);
 *
 * Initilizes Watchdog for HSM using DWD-RTI
 *
 * \return <br>
 * This function returns: NONE
 *****************************************************************************/
void vHsmWdg_Init(void);

/********************************************************************************
 * \fn vHsmWdg_getPreloadCounter(void);
 *
 * Return the Preload Value of Watchdog
 *
 * \return uint32<br>
 * This function returns: Counter of Watchdog
 *****************************************************************************/
uint32 vHsmWdg_getPreloadCounter(void);

/********************************************************************************
 * \fn vHsmWdg_Counter(void);
 *
 * Return the Remaining counter Value of Watchdog
 *
 * \return uint32<br>
 * This function returns: Counter of Watchdog
 *****************************************************************************/
uint32 vHsmWdg_Counter(void);

/********************************************************************************
 * \fn vHsmWdg_SOCReset(void);
 *
 * Generate system Reset for internal purpose
 *
 * \return <br>
 * This function returns: None
 *****************************************************************************/
void vHsmWdg_SOCReset(void);

/********************************************************************************
 * \fn vHsmWdg_Service(void);
 *
 * Service the HSM Watchdog before Expiry
 *
 * \return <br>
 * This function returns: NONE
 *****************************************************************************/
void vHsmWdg_Service(void);

#endif /*VHSMWDG_H*/
/*EOF*/
