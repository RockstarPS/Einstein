/*============================================================================
 **
 **  \file CSigUnit_HwIf.c
 **
 **  \brief Interface to interact with the Signature Unit of iMX8
 **
 **  This file provides functional defines for a Signature Unit module
 **
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                         |
 **  | 2020-08-02 |  RBABU9  | Create Initial Module.
 **  | 2023-09-13 | damudhar | Added Doxygen document
 **  | 2024-09-10 | damudhar | updated according to TI misr
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>
#include <errno.h>
#include <sys/mman.h>
#include <hw/inout.h>

#include "dk_logger.h"
#include "CSigUnit_HwIf.h"
//#include "CSigUnit_Registers.h"
LOG_IMPORT_CONTEXT ( gResMgrSigUnitLogContext );
#include "DSSRegisters.h"

/*!****************************************************************************
Function Name: sig_hw_init
 @brief     Function that is called to do IO Mapping with the SigUnit's Base Address
 @param     const ts_sigunit_dev_t *sighwinit_p
 @return    bool
 *****************************************************************************/

bool sigunit_hw_init ( ts_sigunit_dev_t *p_sighwinit_SP )
{

    bool l_ret_BOOL = true;

    LOGD(&gResMgrSigUnitLogContext,"Initializing Signature Unit HW for Device: %d", p_sighwinit_SP->devnum_U8);

    if(MISR_UNIT_0 == p_sighwinit_SP->devnum_U8)
    {
        LOGD(&gResMgrSigUnitLogContext,"Mapping register base for MISR_UNIT_0: 0x%lx", DSS_UNIT_0_VP1_REG_BASE);
        p_sighwinit_SP->regbase = mmap_device_io(DSS_UNIT_REG_SIZE, DSS_UNIT_0_VP1_REG_BASE);
         /* coverity[cert_err30_c_violation] : FALSE */
        if ( ( errno == EINVAL ) || ( errno == ENOMEM ) || ( errno == ENXIO ) )
        {
            /* coverity[cert_con33_c_violation] : FALSE */
            LOGE(&gResMgrSigUnitLogContext,"mmap_device_io() failed %s", strerror (errno));
            l_ret_BOOL  = false;
        }
        else
        {
            //Misra
            LOGD(&gResMgrSigUnitLogContext,"Successfully mapped MISR_UNIT_0, regbase (virtual address): 0x%x", p_sighwinit_SP->regbase);
        }
    }
    else if(MISR_UNIT_1 == p_sighwinit_SP->devnum_U8)
    {
        LOGD(&gResMgrSigUnitLogContext,"Mapping register base for MISR_UNIT_1: 0x%lx", DSS_UNIT_1_VP2_REG_BASE);
        p_sighwinit_SP->regbase = mmap_device_io(DSS_UNIT_REG_SIZE, DSS_UNIT_1_VP2_REG_BASE);
         /* coverity[cert_err30_c_violation] : FALSE */
        if ( ( errno == EINVAL ) || ( errno == ENOMEM ) || ( errno == ENXIO) )
        {
             /* coverity[cert_con33_c_violation] : FALSE */
            LOGE(&gResMgrSigUnitLogContext,"mmap_device_io() failed %s", strerror (errno));
            l_ret_BOOL  = false;
        }
        else 
        {
            //Misra
            LOGD(&gResMgrSigUnitLogContext,"Successfully mapped MISR_UNIT_1, regbase (virtual address): 0x%x", p_sighwinit_SP->regbase);
        }
    }
    else if(MISR_UNIT_2 == p_sighwinit_SP->devnum_U8)
    {
        LOGD(&gResMgrSigUnitLogContext,"Mapping register base for MISR_UNIT_2: 0x%lx", DSS_UNIT_2_VP1_REG_BASE);
        p_sighwinit_SP->regbase = mmap_device_io(DSS_UNIT_REG_SIZE, DSS_UNIT_2_VP1_REG_BASE);
         /* coverity[cert_err30_c_violation] : FALSE */
        if ( ( errno == EINVAL ) || ( errno == ENOMEM ) || ( errno == ENXIO) )
        {
             /* coverity[cert_con33_c_violation] : FALSE */
            LOGE(&gResMgrSigUnitLogContext,"mmap_device_io() failed %s", strerror (errno));
            l_ret_BOOL  = false;
        }
        else 
        {
            //Misra
            LOGD(&gResMgrSigUnitLogContext,"Successfully mapped MISR_UNIT_2, regbase (virtual address): 0x%x", p_sighwinit_SP->regbase);
        }
    }
    else if(MISR_UNIT_3 == p_sighwinit_SP->devnum_U8)
    {
        LOGD(&gResMgrSigUnitLogContext,"Mapping register base for MISR_UNIT_3: 0x%lx", DSS_UNIT_3_VP2_REG_BASE);
        p_sighwinit_SP->regbase = mmap_device_io(DSS_UNIT_REG_SIZE, DSS_UNIT_3_VP2_REG_BASE);
         /* coverity[cert_err30_c_violation] : FALSE */
        if ( ( errno == EINVAL ) || ( errno == ENOMEM ) || ( errno == ENXIO) )
        {
             /* coverity[cert_con33_c_violation] : FALSE */
            LOGE(&gResMgrSigUnitLogContext,"mmap_device_io() failed %s", strerror (errno));
            l_ret_BOOL  = false;
        }
        else 
        {
            //Misra
            LOGD(&gResMgrSigUnitLogContext,"Mapping register base for MISR_UNIT_3: 0x%lx", DSS_UNIT_3_VP2_REG_BASE);
        }
    }
    else
    {
        LOGE(&gResMgrSigUnitLogContext,"Invalid Signature Unit ID %d", p_sighwinit_SP->devnum_U8);
        l_ret_BOOL  = false;
    }
    // Final log for successful initialization
    if (l_ret_BOOL) {
        LOGD(&gResMgrSigUnitLogContext,"Signature Unit HW initialization completed successfully for Device: %d", p_sighwinit_SP->devnum_U8);
    }
    return l_ret_BOOL;
}


/*!****************************************************************************
Function Name: sig_hw_fini
 @brief     Function that is called to do IO UnMapping with the banks having bits set more than 0
 @param    ts_sigunit_dev_t *sighwfini_p
 @return    bool
 *****************************************************************************/

bool sigunit_hw_fini ( const ts_sigunit_dev_t *p_sighwfini_SP )
{
    bool l_ret_BOOL = true;
    if ( ( munmap_device_io ( p_sighwfini_SP->regbase, sizeof ( p_sighwfini_SP->regbase ) ) ) == -1 )
    {
        LOGE(&gResMgrSigUnitLogContext,"mummap_device_io failed ");
        l_ret_BOOL = false;
    }
    else
    {
        LOGI(&gResMgrSigUnitLogContext,"mummap_device_io is success");
    }

    return l_ret_BOOL;
}

