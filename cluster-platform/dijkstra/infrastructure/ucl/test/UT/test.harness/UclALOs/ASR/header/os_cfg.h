/* Kernbauer Version: 2.16 Konfiguration: ArmCortexR Erzeugungsgangnummer: 59 Zweig: 1 */

/*****************************************************************************
| Project Name: MICROSAR OS
|    File Name: Os_Cfg.h
|
|
|
|                   !!! THIS IS A BETA VERSION ONLY !!!
|
|
|  General code: @Version: 9.01.06@
|  Module version: $vv$=1.05
|
|  Description: Included by the OS standard header Os.h
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2008-2015 Vector Informatik GmbH          All rights reserved.
|****************************************************************************/

/* CovComment 0:  file: os_cfg.h */
/* double include preventer */
#ifndef _OS_CFG_H
#define _OS_CFG_H

/* Vector release management */
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif
/* KB begin vrmReleaseNumber (overwritten) */
/* Source release number */
#define osdVrmMajRelNum 7
#define osdVrmMinRelNum 0
/* KB end vrmReleaseNumber */
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

#if defined USE_QUOTE_INCLUDES
 #include "osek.h"
#else
 #include <osek.h>
#endif

#endif/* double include preventer */

/* END OF HEADER Os_cfg.h */

