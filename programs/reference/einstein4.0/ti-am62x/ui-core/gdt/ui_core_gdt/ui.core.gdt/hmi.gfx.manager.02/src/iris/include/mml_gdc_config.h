/********************************************************************/
/*          (c) 2011 Fujitsu Semiconductor Europe GmbH              */
/*                                                                  */
/* ALL RIGHTS RESERVED. No part of this publication may be copied   */
/* and provided to any third party in any form or by any means      */
/* without the written permission of Fujitsu, unless expressly      */
/* agreed to in written form by Fujitsu.                            */
/* All trademarks used in this document are the property of their   */
/* respective owners.                                               */
/*                                                                  */
/* For further provisions please refer to the respective License    */
/* Agreement.                                                       */
/* (V1.3)                                                           */
/********************************************************************/

/*!
 * \author      Fujitsu GCC Neuried
 * \version     0.01
 * \date        2011
 * \file        mml_gdc_config.h
 * \brief       Controls global graphics driver configurations
 *
 */

#ifndef MML_GDC_CONFIG_H
#define MML_GDC_CONFIG_H

/*lint -save -e621 */

/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/

/**
 * \defgroup config_api Configuration API
 *  The Configuration API allows to change global graphics driver configurations
 *  or to get driver information.
 * @{
 */

/*!
 * Config error code
 **/
#define  MML_ERR_GDC_CONFIG_INVALID_PARAMETER         MM_ERRCODE(0xC00C0B01) /*!< The parameter is wrong */
#define  MML_ERR_GDC_CONFIG_INTERNAL_ERROR            MM_ERRCODE(0xC00C0B02) /*!< Graphics driver internal error */
#define  MML_ERR_GDC_CONFIG_HARDWARE_NOT_AVAILABLE    MM_ERRCODE(0xC00C0B03) /*!< Try to access features that are not availale for this hardware */

/*!
* Define Debug modules
**/
#define IRIS_DBG_MOD_DEFAULT    0x00000001U
#define IRIS_DBG_MOD_GENERIC    0x00000010U
#define IRIS_DBG_MOD_MATH       0x00000020U
#define IRIS_DBG_MOD_SURFACE    0x00000040U
#define IRIS_DBG_MOD_CONTXT     0x00000080U
#define IRIS_DBG_MOD_INTCTRL    0x00000100U
#define IRIS_DBG_MOD_CMDSEQ     0x00000200U
#define IRIS_DBG_MOD_DISP       0x00000400U
#define IRIS_DBG_MOD_SIG        0x00000800U
#define IRIS_DBG_PAR            0x10000000U

/*! The scaler will not be used */
#define MML_GDC_CONFIG_ATTR_ASSIGN_SCALER_OFF          0UL
/*! The scaler will be reserved for use in the blit path. */
#define MML_GDC_CONFIG_ATTR_ASSIGN_SCALER_TO_BLIT      1UL
/*! The scaler will be reserved for use in the display path. */
#define MML_GDC_CONFIG_ATTR_ASSIGN_SCALER_TO_DISPLAY   2UL

/*!
 * Enumeration of config attributes
 **/
typedef enum {
     /*! This attribute can be used to read the main version number of the driver.
      *  An error will returned if the attribute is used with #mmlGdcConfigSetAttribute.
      */
    MML_GDC_CONFIG_ATTR_MAIN_VERSION,
     /*! This attribute can be used to read the sub version number of the driver.
      *  An error will returned if the attribute is used with #mmlGdcConfigSetAttribute.
      */
    MML_GDC_CONFIG_ATTR_SUB_VERSION,
     /*! This attribute can be used to read the build version number of the driver.
      *  An error will returned if the attribute is used with #mmlGdcConfigSetAttribute.
      */
    MML_GDC_CONFIG_ATTR_BUILD_VERSION,
     /*! This attribute can be used to assign scaler hardware blocks to the display or
      *  blit path.
      *  Supported parameters are:
      *  -#MML_GDC_CONFIG_ATTR_ASSIGN_SCALER_OFF
      *  -#MML_GDC_CONFIG_ATTR_ASSIGN_SCALER_TO_BLIT (default)
      *  -#MML_GDC_CONFIG_ATTR_ASSIGN_SCALER_TO_DISPLAY
      */
    MML_GDC_CONFIG_ATTR_ASSIGN_SCALER,
    /*! The value for this attribute defines which modue should
      * print debug messages. This feature is not available in the
      * product version of the driver.
      * Supported parameters are the IRIS_DBG_MOD_... values defined above or a
      * '|' combination of them.
      */
    MML_GDC_CONFIG_ATTR_DEBUG_MODULE,
    /*! MM_TRUE: The driver will only support features for Titan:
      * Scaler and second blend unit is not avalable.
      * MM_FALSE: Full Calypso hardware support.
      */
    MML_GDC_CONFIG_ATTR_TITAN_MODE,
    /*! This attribute is only available in #mmlGdcConfigGetAttribute.
      * The returned value represents the smallest available InstructionBuffer
      * in bytes during all calls. A function call with this parameter
      * resets the measurement.
      * The returned value can be used by an application to measure the
      * usage of the instruction buffer assigned by #mmlGdcSysSetInstructionBuffer.
      */
    MML_GDC_CONFIG_ATTR_MIN_INSTRUCTION_BUFFER,
    /*! This attribute is only available in #mmlGdcConfigGetAttribute.
      * The returned value represents the current available InstructionBuffer
      * in bytes.
      * The returned value can be used by an application to decide
      * whether or not further render steps should be delayed and continued
      * later because the hardware is currently still busy.
      */
    MML_GDC_CONFIG_ATTR_CURRENT_INSTRUCTION_BUFFER

} MML_GDC_CONFIG_ATTR;


/*****************************************************************************/
/*** TYPES / STRUCTURES ******************************************************/
/*****************************************************************************/


/*******************************************************************************
 Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/**
 * [SWDD2035] Assign internal VRAM for command queue
 * \cond Related to SWAD000, SWAD801 \endcond
 *
 * @note The command queue is required to buffer the render instrunction to
 * allow a non-blocking API handling. The required instruction buffer size depends
 * on the amount and complexity of the render instructions and which synchronization
 * instructions are used. A recommended size is 8 kByte. To get information about the
 * instruction buffer usage an application can use the #mmlGdcConfigGetAttribute
 * function with attibute #MML_GDC_CONFIG_ATTR_MIN_INSTRUCTION_BUFFER.
 * The function must be called after #mmlGdcSysInitializeDriver be before any render or
 * display operations. A reconfiguration of the instruction buffer is not possible.
 * @param address Start address in the VRAM
 * @param size Size in bytes of the buffer to assign, must be DWORD (4 Bytes) aligned,
 *             the function will return an error otherwise. The application must ensure
 *             that the address as well as the address plus size are within the range
 *             of the Iris VRAM memory, the function will not do this.
 *  @return MML_OK on success,\n
 *          otherwise the related error code\n
 **/
IRIS_API MM_S32 mmlGdcSysSetInstructionBuffer(void* address, MM_U32 size);


/**
 * [SWDD2050] Sets a graphics library attribute.
 * See #MML_GDC_CONFIG_ATTR for a list of attributes.
 * \cond Related to SWAD000, SWAD204, SWAD205 \endcond
 *
 *
 * \brief Sets a graphics library attribute.
 * \param pname  Name of the attribute to set. See #MML_GDC_CONFIG_ATTR
 * \param param  Value to set.
 *
 * \return MML_OK on success, otherwise the related error code
 */
IRIS_API MM_S32 mmlGdcConfigSetAttribute( MML_GDC_CONFIG_ATTR pname, MM_U32 param );

/**
 * [SWDD2060] Gets the current value of a graphics library attribute.
 * See #MML_GDC_CONFIG_ATTR for a list of attributes.
 * \cond Related to SWAD000, SWAD203, SWAD810 \endcond
 *
 *
 * \brief Gets a graphics library attribute.
 * \param pname  Name of the attribute to get. See #MML_GDC_CONFIG_ATTR
 * \param pParam Pointer to a variable to receive the requested value.
 *
 * \return MML_OK on success, otherwise the related error code
 */
IRIS_API MM_S32 mmlGdcConfigGetAttribute( MML_GDC_CONFIG_ATTR pname, MM_U32 *pParam );

/** @}*/


#ifdef __cplusplus
    }
#endif

/*lint -restore */

#endif /* MML_GDC_CONFIG_H */
