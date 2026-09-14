/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_UserTypes.h
 *        Config:  Traveo2.dpa
 *   ECU-Project:  CLU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  User Types header file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_USERTYPES_H
# define _RTE_USERTYPES_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

# include "ComStack_Types.h"


typedef uint8 Dcm_ProtocolType;
typedef uint8 Dcm_CommunicationModeType;
typedef uint8 Dcm_ConfirmationStatusType;
typedef uint8 TPulseClientId;
typedef uint8 EDisplayStatus;

#define eDisplayFault		0u

#   define DCM_E_REQUESTOUTOFRANGE (49U)

#   define IOHWAB_E_ADC_ERROR (8U)
#   define IOHWAB_E_ADC_ID_INVALID (9U)
#   define IOHWAB_E_ERROR (10U)
#   define IOHWAB_E_DOUT_ID_INVALID (11U)
#   define IOHWAB_E_NO_ERROR (12U)
#   define IOHWAB_E_DIN_ID_INVALID (13U)

#   define DCM_RES_POS_OK (0U)
#   define DCM_RES_POS_NOT_OK (1U)
#   define DCM_RES_NEG_OK (2U)
#   define DCM_RES_NEG_NOT_OK (3U)


#define eIO_ADC_AI_VDB 			0u
#define eIO_ADC_AI_VTEMP		0u

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#endif /* _RTE_USERTYPES_H */
