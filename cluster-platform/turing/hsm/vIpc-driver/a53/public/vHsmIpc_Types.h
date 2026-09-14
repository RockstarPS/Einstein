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
 * \file vHsmIpc_Types.h
 *
 * \brief
 * Std Types for HSM Ipc.
 *
 * \version 1.0.02
 * |Version | Date       | Author   | Task Id         | Description                           |
 * |--------|------------|----------|-----------------|---------------------------------------|
 * |1.00.00 | 03/Dec/'24 | kjohn    | PE4TI29141-4969 | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/******************************************************************************
 *  MACROS
 *****************************************************************************/
#ifndef LOCAL
#define LOCAL static
#endif /* LOCAL */

#define E_OK       0x0
#define E_NOT_OK   0x1

#define  FALSE  0x0
#define  TRUE   0x1
#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif

#define FUNC(rettype, memclass) rettype 

/******************************************************************************
 *  TypeDefs
 *****************************************************************************/

typedef uint8_t Std_ReturnType;
typedef uint8_t boolean;




