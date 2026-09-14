/*============================================================================
 **
 **  \file CSigUnit_Proto.h
 **
 **  \brief Interface to interact with the Signature Unit of iMX8
 **
 **  This file provides functional defines for a Signature Unit module
 **
 **  Component Name: Signature Unit
 **  Archive:
 **  Date: May 11 2020
 **  Author: Dinakar Babu
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/


#ifndef CSIGUNIT_RM_H
#define CSIGUNIT_RM_H

#include <sys/dispatch.h>

#define SIGUNIT_INVALID_DEVID                     (0xFF)

typedef struct
{
    uint8_t             devnum_U8;
    dispatch_t          *dpp_SP;
    dispatch_context_t  *ctp_UP;

    int32_t              id_INT32;
    uintptr_t            regbase;
} ts_sigunit_dev_t;

extern ts_sigunit_dev_t dev;

#endif /* CSIGUNIT_RM_H */
