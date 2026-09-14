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
 * \file        iris_base.h
 * \brief       Iris base address definitions.
 *              This file is not part of the driver, should be part of
 *              global headers (calypso) or of the application. Provided
 *              for convenience. You can override some of the values per
 *              compiler defines.
 *
 */

#ifndef __IRIS_BASE_H__
#define __IRIS_BASE_H__

#define IRIS_MEMORY_BASE            0x40000000UL
#define IRIS_HSSPI_BASE             IRIS_MEMORY_BASE
#define IRIS_VRAM_BASE              (IRIS_MEMORY_BASE + 0x10000000UL)

#ifndef IRIS_VRAM0_BASE
#define IRIS_VRAM0_BASE             (IRIS_MEMORY_BASE + 0x10000000UL)
#endif

#ifndef IRIS_VRAM0_SIZE
#define IRIS_VRAM0_SIZE             0x00100000UL                         /* 1MB */
#endif

#ifndef IRIS_VRAM1_BASE
#define IRIS_VRAM1_BASE             (IRIS_VRAM0_BASE + IRIS_VRAM0_SIZE)
#endif

#ifndef IRIS_VRAM1_SIZE
#define IRIS_VRAM1_SIZE             0x00100000UL                         /* 1MB */
#endif

#define IRIS_HOST_BASE              (0x00000004UL)/*???? pk: don't know. We decided 0 is not valid, so just add a small offset */
#define IRIS_HOST_SIZE              ((10UL * 1024UL * 1024UL) - 0x4UL)
#define IRIS_FLASH_SIZE             (4UL * 1024UL * 1024UL)

#endif /* __IRIS_BASE_H__ */
