/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_UserTypes.h
 *           Config:  Audi_Etron_TV2.dpa
 *      ECU-Project:  Audi_Etron_TV2
 *
 *        Generator:  MICROSAR RTE Generator Version 4.39.00
 *                    RTE Core Version 4.39.00
 *          License:  CBD2500735
 *
 *      Description:  User Types header file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_USERTYPES_H
# define RTE_USERTYPES_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

# include "ComStack_Types.h"

#ifndef IOHWAB_E_ADC_ERROR				   /* RTE Compilation Purpose */
#define IOHWAB_E_ADC_ERROR (8U)
#endif

#  ifndef IOHWAB_E_ADC_ID_INVALID          /* RTE Compilation Purpose */
#   define IOHWAB_E_ADC_ID_INVALID (9U)
#  endif

#  ifndef IOHWAB_E_ERROR                   /* RTE Compilation Purpose */
#   define IOHWAB_E_ERROR (10U)
#  endif

#  ifndef IOHWAB_E_DOUT_ID_INVALID         /* RTE Compilation Purpose */
#   define IOHWAB_E_DOUT_ID_INVALID (11U)
#  endif

#  ifndef IOHWAB_E_NO_ERROR                /* RTE Compilation Purpose */
#   define IOHWAB_E_NO_ERROR (12U)
#  endif
 
#  ifndef IOHWAB_E_DIN_ID_INVALID          /* RTE Compilation Purpose */
#   define IOHWAB_E_DIN_ID_INVALID (13U)
#  endif

#  ifndef e_SafeStateInActive
#   define e_SafeStateInActive (0U)
#  endif

#  ifndef e_SafeStateActive
#   define e_SafeStateActive (1U)
#  endif

#  ifndef e_SafeStateMax
#   define e_SafeStateMax (2U)
#  endif

#  ifndef eIO_DO_DISP_RESET
#   define eIO_DO_DISP_RESET (0U)
#  endif

#  ifndef eIO_DI_DISP_PON
#   define eIO_DI_DISP_PON (1U)
#  endif

#  ifndef eIO_DI_DISP_FDET
#   define eIO_DI_DISP_FDET (5U)
#  endif

# define Rte_TypeDef_ESafeStateType
typedef uint8 ESafeStateType;
typedef sint32 EcuMExt_WakeupReasonType;
typedef uint8 EcuMExt_ResetType;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#endif /* RTE_USERTYPES_H */
