/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_PtrView_Type.h
 *        Config:  Turing.dpa
 *   ECU-Project:  TuringECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Application types header file for SW-C <PtrView>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PTRVIEW_TYPE_H
# define _RTE_PTRVIEW_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef eDcmExt_Write
#   define eDcmExt_Write (0U)
#  endif

#  ifndef eDcmExt_Read
#   define eDcmExt_Read (1U)
#  endif

#  ifndef eDcmExt_IOCtrl
#   define eDcmExt_IOCtrl (2U)
#  endif

#  ifndef eDcmExt_RoutineCtrl
#   define eDcmExt_RoutineCtrl (3U)
#  endif

#  ifndef eHmiSubId_Welcome
#   define eHmiSubId_Welcome (0U)
#  endif

#  ifndef eHmiSubId_ETM100
#   define eHmiSubId_ETM100 (1U)
#  endif

#  ifndef eHmiSubId_ETM110
#   define eHmiSubId_ETM110 (2U)
#  endif

#  ifndef eHmiSubId_ETM120
#   define eHmiSubId_ETM120 (3U)
#  endif

#  ifndef eHmiSubId_ETM130
#   define eHmiSubId_ETM130 (4U)
#  endif

#  ifndef eHmiSubId_ETM230
#   define eHmiSubId_ETM230 (5U)
#  endif

#  ifndef eHmiSubId_ETM233
#   define eHmiSubId_ETM233 (6U)
#  endif

#  ifndef eHmiSubId_Count
#   define eHmiSubId_Count (7U)
#  endif

#  ifndef CAN_SIGNAL_ABSENT
#   define CAN_SIGNAL_ABSENT (0)
#  endif

#  ifndef CAN_SIGNAL_PENDING
#   define CAN_SIGNAL_PENDING (1)
#  endif

#  ifndef CAN_SIGNAL_VALID
#   define CAN_SIGNAL_VALID (2)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PTRVIEW_TYPE_H */
