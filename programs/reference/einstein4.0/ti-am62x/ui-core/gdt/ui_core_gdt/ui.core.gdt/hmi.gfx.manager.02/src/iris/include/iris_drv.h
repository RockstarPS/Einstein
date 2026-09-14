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
 * \date        2010
 * \file        iris_drv.h
 *              Iris driver
 * \brief       Main include file. The application should include this file only.
 *
 */

#ifndef IRIS_DRIVER_H
    #define IRIS_DRIVER_H

#ifdef __cplusplus
    extern "C"
    {
#endif

/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/

#include "mm_types.h"
#include "hweb.h"
#include "iris_api_export.h"
#include "mml_gdc_sysinit.h"
#include "mml_gdc_config.h"
#include "mml_gdc_sync.h"
#include "mml_gdc_surfman.h"
#include "mml_gdc_pixeng.h"
#include "mml_gdc_display.h"
#include "mml_gdc_interrupt.h"
#include "mml_gdc_sig.h"


/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** TYPES / STRUCTURES ******************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** GLOBAL VARIABLES ********************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** FUNCTIONS ***************************************************************/
/*****************************************************************************/

#ifdef __cplusplus
    }
#endif

#endif /* IRIS_DRIVER_H */
