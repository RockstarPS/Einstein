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
 * \file vHsmMPU.c
 *
 * \brief
 * HSM MPU settings for AM62PX HSM M4F core source file
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
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"
#include "vHsmMPU.h"
#include "interrupt.h"
#include "trace.h"
#include "vHsmMemMap.h"

#ifdef VHSMMPU_ENABLE

/* Max possible regions in ARMv7-M CPU */
#define MpuP_MAX_REGIONS    (8u)

#define MPU_BASE        (0xE000ED90u)
#define MPU_CTRL        (volatile uint32 *)((MPU_BASE) + 0x04u)
#define MPU_RNR         (volatile uint32 *)((MPU_BASE) + 0x08u)
#define MPU_RBAR        (volatile uint32 *)((MPU_BASE) + 0x0Cu)
#define MPU_RASR        (volatile uint32 *)((MPU_BASE) + 0x10u)


/* these are defined as part of SysConfig */
extern vHsmMPU_Config MpuConfig;
extern vHsmMPU_RegionConfig MpuRegionConfig[];

/**
 *********************************************************************************************
 ** \fn        vHsmMPU_getAttrsAndSize
 **
 ** \brief     Gets values to MPU_RegionAttrs
 **
 ** \param[out] region parameter structure to set to default
 ** \param[in]  size size of the region
 **
 ** \return    uint32 Region attribute
 **
 ** \note Strongly recommended to be called before seting values in MPU_RegionAttrs
 **
 *********************************************************************************************
 */
static FUNC(uint32, MPU_CODE)vHsmMPU_getAttrsAndSize(vHsmMPU_RegionAttrs *region, uint32 size)
{
    uint32 regionAttrs =
          ((uint32)(region->isExecuteNever & (uint32)0x1U) << 28)
        | ((uint32)(region->accessPerm     & (uint32)0x7U) << 24)
        | ((uint32)(region->tex            & (uint32)0x7U) << 19)
        | ((uint32)(region->isSharable     & (uint32)0x1U) << 18)
        | ((uint32)(region->isCacheable    & (uint32)0x1U) << 17)
        | ((uint32)(region->isBufferable   & (uint32)0x1U) << 16)
        | ((uint32)(region->subregionDisableMask & (uint32)0xFFU) << 8)
        | ((uint32)(size & 0x1FU)                  << 1)
        | ((uint32)(region->isEnable       & (uint32)0x1U) << 0)
        ;

    return regionAttrs;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmMPU_RegionAttrs_init
 *********************************************************************************************
 */
FUNC(void,MPU_CODE) vHsmMPU_RegionAttrs_init(vHsmMPU_RegionAttrs *region)
{
    region->isExecuteNever = 0;
    region->accessPerm     = MPU_AP_S_RW_U_R;
    region->tex            = 0;
    region->isSharable     = 1;
    region->isCacheable    = 0;
    region->isBufferable   = 0;
    region->isEnable       = 0;
    region->subregionDisableMask = 0;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmMPU_setRegion
 *********************************************************************************************
 */
FUNC(void,MPU_CODE) vHsmMPU_setRegion(uint32 regionNum, void * addr, uint32 size, vHsmMPU_RegionAttrs *attrs)
{
    uint32 baseAddress, regionAndSizeAttrs;
    boolean enabled;
    if(MpuP_MAX_REGIONS > regionNum)
    {
            /* size 5b field */
        size = (size & 0x1FU);

        /* align base address to region size */
        baseAddress = ((uint32)addr & ~( (1U<<((uint64)size+1U))-1U ));

        /* get region attribute mask */
        regionAndSizeAttrs = vHsmMPU_getAttrsAndSize(attrs, size);

        enabled = (boolean)vHsmMPU_isEnable();

        /* disable the MPU (if already disabled, does nothing) */
        vHsmMPU_disable();

        mask_interrupts(); /*Disbale all interrupts*/

        *MPU_RNR  = regionNum;
        *MPU_RBAR = (baseAddress & (0xFFFFFFE0u));
        *MPU_RASR = regionAndSizeAttrs;

        unmask_interrupts();

        if (enabled == TRUE) {
            vHsmMPU_enable();
        }
    }
    else
    {
        /* Log and Reset*/
    }    
}

/**
 *********************************************************************************************
 ** \copydoc vHsmMPU_resetRegion
 *********************************************************************************************
 */
FUNC(void,MPU_CODE) vHsmMPU_resetRegion(uint32 regionNum)
{
    *MPU_RNR  = regionNum;
    *MPU_RBAR = 0u;
    *MPU_RASR = 0u;
}

/**
 *********************************************************************************************
 ** \copydoc vHsmMPU_enable
 *********************************************************************************************
 */
FUNC(void,MPU_CODE) vHsmMPU_enable(void)
{
    if(vHsmMPU_isEnable()== 0UL)
    {
        uint32 value;
        mask_interrupts();
        value = 0;
        if ((boolean)MpuConfig.enableBackgroundRegion == TRUE) 
        {
            value |= (1u << 2u);  /* PRIVDEFENA, 0: Disables the default memory map,1: enable default memory map for non mapped regions*/
        }
        value |= (1u << 1u);  /* HFNMIENA, 0: disable MPU for fault handlers, 1: enable MPU for fault handlers */
        value |= (1u << 0u);  /* 0: MPU disable, 1: MPU enable */
        *MPU_CTRL = value;
        dsb();
        isb();
        unmask_interrupts();
    }
}

/**
 *********************************************************************************************
 ** \copydoc vHsmMPU_disable
 *********************************************************************************************
 */
FUNC(void,MPU_CODE) vHsmMPU_disable(void)
{
    if((boolean)vHsmMPU_isEnable() == TRUE)
    {
        mask_interrupts();
        dsb();
        *MPU_CTRL = 0; /* Disable MPU */
        unmask_interrupts();
    }
}

/**
 *********************************************************************************************
 ** \copydoc vHsmMPU_isEnable
 *********************************************************************************************
 */
FUNC(uint32,MPU_CODE) vHsmMPU_isEnable(void)
{
    return (*MPU_CTRL & 0x1U);
}

/**
 *********************************************************************************************
 ** \copydoc vHsmMPU_init
 *********************************************************************************************
 */
FUNC(void,MPU_CODE) vHsmMPU_init(void)
{
    uint32 i;
    if((boolean)vHsmMPU_isEnable() == TRUE) 
    {
        vHsmMPU_disable();
    }
    /*
     * Reset all the regions
     */
    for(i = 0; i < MpuP_MAX_REGIONS; i++)
    {
        vHsmMPU_resetRegion(i);
    }

    /*
     * Initialize MPU regions
     */
    for(i = 0; i < MpuConfig.numRegions; i++)
    {
       vHsmMPU_setRegion(i,(void*)MpuRegionConfig[i].baseAddr,MpuRegionConfig[i].size,&MpuRegionConfig[i].attrs);
    }
    if ((boolean)MpuConfig.enableMpu == TRUE) {
        vHsmMPU_enable();
        TRACE_info("\r\n MPU enabled");
    }

}

#endif

