/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file EthIf_Types.h
*    @ingroup EthIf
*    @brief This file provides the types for the EthIf module.
********************************************************************************************************************/
#ifndef ETHIF_TYPES_H
#define ETHIF_TYPES_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Eth_GeneralTypes.h" 
/********************************************************************************************************************
*   MACRO AND DATA TYPES                                                                                            *
********************************************************************************************************************/
/********************************************************************************************************************
*                                 #! memory and pointer classes.                                                    *
********************************************************************************************************************/
#ifndef AUTOMATIC
#define AUTOMATIC
#endif

#ifndef ETHIF_CODE
#define ETHIF_CODE
#endif 

#ifndef ETHIF_CONST
#define ETHIF_CONST
#endif  

#ifndef ETHIF_APPL_DATA
#define ETHIF_APPL_DATA
#endif

#ifndef ETHIF_APPL_CONST
#define ETHIF_APPL_CODE
#endif

#ifndef ETHIF_CALLOUT_CODE
#define ETHIF_CALLOUT_CODE
#endif

#ifndef ETHIF_VAR
#define ETHIF_VAR
#endif

#ifndef ETHIF_VAR_INIT
#define ETHIF_VAR_INIT
#endif

#ifndef ETHIF_VAR_NOINIT
#define ETHIF_VAR_NOINIT
#endif

#ifndef ETHIF_VAR_POWER_ON_INIT
#define ETHIF_VAR_POWER_ON_INIT
#endif

#ifndef ETHIF_VAR_FAST
#define ETHIF_VAR_FAST
#endif

#ifndef ETHIF_VAR_SLOW
#define ETHIF_VAR_SLOW
#endif

/* #! EthIf Types */
/*! @brief Defines the Data Type that represents the Ethernet interface switch port group index. 
The index is zero based and unique for every configured switch port group. */
typedef uint8 EthIf_SwitchPortGroupIdxType;
/*! @brief Measurement index of dropped datagrams caused by invalid CrtlIdx/VLAN */
#define ETHIF_MEAS_DROP_CRTLIDX 0x01U
/*! @brief represents all measurement indexes */
#define ETHIF_MEAS_ALL          0xFFU
/*! @brief Index to select specific measurement data */
typedef uint8 EthIf_MeasurementIdxType;

/*! @brief Defines the type for the signal quality */
typedef struct
{
    uint32 HighestSignalQuality; /*! @brief the highest signal quality of a link since last clear */
    uint32 LowestSignalQuality;  /*! @brief the lowest signal quality of a link since last clear */
    uint32 ActualSignalQuality;  /*! @brief the actual signal quality */
}EthIf_SignalQualityResultType;

/*! @brief Defines the type of Etherner interface state  */
typedef enum 
{
    ETHIF_STATE_UNINIT=0U,   /*! @brief Status of EthIf module before EthIf_Init function*/
    ETHIF_STATE_INIT     /*! @brief Status of EthIf module after EthIf_Init function called*/
}EthIf_StateType;

#endif /* ETHIF_TYPES_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
