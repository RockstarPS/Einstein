/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2018. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*!***************************************************************************
* @ingroup Input-Output Hardware Abstraction
* @file IoHwAb_DOut_Cfg.h
* @brief Configuration header file for digital output
* ****************************************************************************/
#ifndef IOHWAB_DOUT_CFG_H
#define IOHWAB_DOUT_CFG_H
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "Dio.h"
#include "Rte_Type.h"
#include "IoExp.h"

/*****************************************************************************
*  Prublic Macros Definitions                                                *                                                                                       *
******************************************************************************/
 
 



/**
* @brief Macro to enable the IoHwAb Digital output Module
*/
#define IOHWAB_DOUT_ENABLE			STD_ON
/*****************************************************************************
*  Private Macros Definitions                                                *                                                                                       *
******************************************************************************/
#if (IOHWAB_DOUT_ENABLE == STD_ON)
/**
* @brief Number of digital output variants
*/
#define IOHWAB_DOUT_NUM_OF_VARIANTS     	1U
/**
* @brief Maximum Number of digital output variants
*/
#define IOHWAB_MAX_NUM_OF_DOUT_VARIANTS 	1u
/**
* @brief Number of digital outputs configured
*/
#define IOHWAB_NUM_DOUT_OUTPUT            29U
/**
* @brief Refresh counts per each cycle. Used to reduce the cpu load.
*/
#define IOHWAB_REFRESH_PERCYCLE             5U

/*****************************************************************************
*  Type Declarations                                                         *
******************************************************************************/

/**
* @brief Defines the digital output group id type
*/
//typedef uint8 IoHwAb_DOutGroupIdType;

/**
* @brief This structure defines the active types for digital outputs
*/

/**
 * @brief Number of adc Singal Sources
*/
typedef enum{
  IOHWAB_SOURCE_DOUT_MCAL=0,
  IOHWAB_SOURCE_DOUT_EXTERNAL=1
}IoHwAb_DOutSourceSignalType;

typedef enum
{
  IOHWAB_DOUT_ACTIVE_LOW = 0u,			 /**<Active low level value for output*/
  IOHWAB_DOUT_ACTIVE_HIGH				 /**<Active high level value for output*/
}IoHwAb_DOutActiveType;

/**
* @brief This structure defines the configuration parameters for digital output channel
*/
typedef struct
{
    Dio_ChannelType 		Hw_ChannelId;		/**< Mcal dio channel id*/
    Dio_LevelType  			InitValue;			/**< Init Value of the output signal*/
    IoHwAb_DOutSourceSignalType SourceSignalId; /**<DOut Source Signal Id */
    IoHwAb_DOutActiveType   ActiveLevel;		/**< Active level of output*/
} IoHwAb_DOutChannelType;

/**
* @brief This structure defines the configuration parameters for digital output module
*/
typedef struct
{
    IoHwAb_DOutChannelType IoHwAb_DOutChannel[IOHWAB_DOUT_NUM_OF_VARIANTS];		/**< Digital output configuration parameters*/
    IoHwAb_DOutSignalIdType  SignalId;											/**< Digital output signal id*/
} IoHwAb_DOutCfgType;

/*****************************************************************************
*  Public Forward Declarations                                          	 *
******************************************************************************/
extern const IoHwAb_DOutCfgType IoHwAb_DOutCfg[IOHWAB_NUM_DOUT_OUTPUT];

/*****************************************************************************
*  Private Forward Declarations                                          	 *
******************************************************************************/

Std_ReturnType IoHwAb_DOut_GetCurrentVariant(uint8* DOutVariantId);
Std_ReturnType IoHwAb_DOut_PreHook(void);

void IoHwAb_Dio_WriteChannel(uint16 channelId, uint8 Level, IoHwAb_DOutSourceSignalType SourceSignalId);

#endif
#endif /* IOHWAB_DOUT_CFG_H */

/*End of File*/
/*****************************************************************************
*  for each change to this file, be sure to record:                         *
*     1.  who made the change and when the change was made                  *
*     2.  why the change was made and the intended result                   *
*  Following block needs to be repeated for each change
******************************************************************************
*  Note: In the trace-ability column we need to trace back to the Design Doc.*
*  For the initial version it is traced to the Design Document section.     *
*  For further changes it shall trace to the source of the change which may *
*  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*  other reason                                                            *
******************************************************************************/
/*****************************************************************************
Date              :22-Aug-2018
By                :pragesh
Traceability      :RTC-1181436:MMC: Safe IoHwAb Delivery
Change Description:Initial Version for IoHwAb safe implementation
******************************************************************************/

