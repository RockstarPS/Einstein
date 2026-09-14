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
 * \file vHsmDmnMgr.c
 *
 * \brief
 * Domain Manger API's for Invoking HSM core Graceshutdown
 *
 *
 * \version 1.0.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 10/Jun/'25 | kjohn    |         |                                       |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Banumathi Jayaram        | bjayara2  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Sudhakar Magesh          | msudhaka  | VTSC, Coimbatore, India
 ******************************************************************************/
#ifndef VHSMMAGICFLAG_H
#define VHSMMAGICFLAG_H
#include "Std_Types.h"
#include "Rte_Type.h"

/******************************************************************************
 ** \fn vHsmDmnMgr_Init
 **
 ** vHsmDmnMgr Init Function.
 **
 ** This function returns None 
 **
 ** \param none
 *****************************************************************************/
void vHsmDmnMgr_Init(void);
/******************************************************************************
 ** \fn HSM_DmnMgr_SystemChangeRequest
 **
 ** API to write Magic Flag.
 **
 ** This function returns Std_ReturnType - E_OK or E_NOT_OK
 **
 ** \param [in]  Request
 *****************************************************************************/
Std_ReturnType HSM_DmnMgr_SystemChangeRequest(ESystemState Request);
/******************************************************************************
 ** \fn vHsmDmnMgr_MainFunction
 **
 ** MainFunction to Monitor the Job
 **
 ** This function returns None
 **
 ** \param none
 *****************************************************************************/
void vHsmDmnMgr_MainFunction(void);
#endif /*VHSMMAGICFLAG*/
/*EOF*/