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
 * \file        iris_api_export.h
 *              Iris driver
 * \brief       Definition of the IRIS_API interface type
 *
 */

#ifndef __IRIS_API_H__
#define __IRIS_API_H__

#if defined(IrisDriver_EXPORTS)
    #define IRIS_API __declspec(dllexport)
#else
    #define IRIS_API extern
#endif

#endif /* __IRIS_API_H__ */
