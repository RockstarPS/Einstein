/*
*
* Copyright (c) 2024 Texas Instruments Incorporated
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

/**
 *  \file     Dio.c
 *
 *  \brief    This file contains DIO MCAL driver
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "string.h"
/*
 * Design: MCAL-5509
 */
#include "Dio.h"
#include "Dio_Priv.h"

/* Include to use the CSL library read/writes*/

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* AUTOSAR version information check has to match definition in header file */
#if ((DIO_AR_RELEASE_MAJOR_VERSION != (0x04U)) || \
    (DIO_AR_RELEASE_MINOR_VERSION != (0x03U)) ||  \
    (DIO_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "AUTOSAR Version Numbers of Dio are different"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((DIO_SW_MAJOR_VERSION != (10U)) || (DIO_SW_MINOR_VERSION != (1U)))
  #error "Version numbers of Dio.c and Dio.h are inconsistent!"
#endif

/* To Return 0 when Improper ID is passed to Read functions */
#define DIO_RETURN_ZERO                        (0U)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

Dio_LevelType lDioLevels[500];

#if (STD_ON == DIO_VERSION_INFO_API)
/**
 *\brief   This function is used to get the version information of DIO module
 *
 */

/*
 * Design: MCAL-5473,MCAL-5497,MCAL-5496
 */
FUNC(void, DIO_CODE)  Dio_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) versioninfo)
{
    
}
#endif  /*(STD_ON == DIO_VERSION_INFO_API)*/

/**
 *\brief   This function is used to read from a channel
 *
 */

/*
 * Design: MCAL-5505,MCAL-5424,MCAL-5472
 */
FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel(
    Dio_ChannelType ChannelId)
{
    Dio_LevelType chLevelVal = (Dio_LevelType) DIO_RETURN_ZERO;
	if(ChannelId < 500)
	{
		chLevelVal = lDioLevels[ChannelId];
	}
    return (chLevelVal);
}

/**
 *\brief   This function is used to write a value to a channel
 *
 */

/*
 * Design: MCAL-5478,MCAL-5483,MCAL-5524,MCAL-5472,MCAL-5427
 */
FUNC(void, DIO_CODE) Dio_WriteChannel(
    Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    if(ChannelId < 500)
	{
	lDioLevels[ChannelId] = Level;
	}
}

/**
 *\brief   This function is used to read the value from a port
 *
 */

/*
 * Design: MCAL-5475,MCAL-5474
 */
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort(
    Dio_PortType PortId)
{
    /*
    * Design: MCAL-5511
    */
    Dio_PortLevelType portVal = (Dio_PortLevelType) DIO_RETURN_ZERO;
    return (portVal);
}

/**
 *\brief   This function is used to write a value to a port
 *
 */

/*
 * Design: MCAL-5512,MCAL-5490,MCAL-5456
 */
FUNC(void, DIO_CODE) Dio_WritePort(
    Dio_PortType PortId, Dio_PortLevelType Level)
{

}

/**
 *\brief   This function is used to read a value to a channel group
 *
 */

/*
 * Design: MCAL-5471,MCAL-5444,MCAL-5522
 */
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup
    (const Dio_ChannelGroupType *ChannelGroupIdPtr)
{
    /*
    * Design: MCAL-5435
    */
    Dio_PortLevelType portLevelVal = (Dio_PortLevelType) DIO_RETURN_ZERO;
    return (portLevelVal);
}

/**
 *\brief   This function is used to write a value to a channel group
 *
 */

/*
 * Design: MCAL-5426,MCAL-5457,MCAL-5476
 */
FUNC(void, DIO_CODE) Dio_WriteChannelGroup(
    const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level)
{
    
}

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/**
 *\brief   This function is used to flip the value of a pin
 *
 */

/*
 * Design: MCAL-5460,MCAL-5531
 */
FUNC(Dio_LevelType, DIO_CODE) Dio_FlipChannel(
    Dio_ChannelType ChannelId)
{
    Dio_LevelType channelVal = (Dio_LevelType) DIO_RETURN_ZERO;
    return (channelVal);
}
#endif /*(STD_ON == DIO_FLIP_CHANNEL_API)*/

#if (STD_ON == DIO_REGISTER_READBACK_API)
/**
 *\brief   This function is used to readback some critical DIO registers
 *
 */
 /*
 * Design: MCAL-4945,MCAL-4944,MCAL-4942
 */
FUNC(Std_ReturnType, DIO_CODE) Dio_RegisterReadback(
            Dio_ChannelType ChannelId, Dio_RegisterReadbackType *DioRegRbPtr)
{
    Std_ReturnType     retVal = ((Std_ReturnType) E_OK);
    return (retVal);
}
#endif  /* #if (STD_ON == DIO_REGISTER_READBACK_API) */

/**************************************************************************/
/********************    Internal Functions *******************************/
/**************************************************************************/

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
