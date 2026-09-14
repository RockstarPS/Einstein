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
* @file IoHwAb_DIn_Cfg.h
* @brief Configuration header file for digital inputs
* ****************************************************************************/

#ifndef IOHWAB_DIN_CFG_H
#define IOHWAB_DIN_CFG_H

/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/

#include "Rte_Type.h"
#include "Dio.h"
#include "IoExp.h"
/*****************************************************************************
*  Public Macros Definitions                                                *                                                                                       *
******************************************************************************/


/**
* @brief Macro to enable the IoHwAb Digital input Module
*/
#define IOHWAB_DIN_ENABLE			(STD_ON)
/*****************************************************************************
*  Private Macros Definitions                                                *                                                                                       *
******************************************************************************/
#if (IOHWAB_DIN_ENABLE == STD_ON)
/**
* @brief Number of digital input variants
*/
#define IOHWAB_DIN_NUM_OF_VARIANTS     		 	1U
/**
* @brief Maximum Number of digital input variants
*/
#define IOHWAB_MAX_NUM_OF_DIN_VARIANTS		1u
/**
* @brief Number of digital inputs configured
*/
#define IOHWAB_NUM_DIN_INPUT            		14U

/*****************************************************************************
*  Type Definitions                                                          *
******************************************************************************/


/**
 * @brief Number of adc Singal Sources
*/
typedef enum{
    IOHWAB_SOURCE_DIN_MCAL=0,
    IOHWAB_SOURCE_DIN_EXTERNAL=1
}IohwAb_DInSourceSignalType;

/**
* @brief Defines the digital input signal group id type
*/
typedef enum
{
    IOHWAB_DIN_ACTIVE_LOW = 0u,				/**<Active low level value for input*/
    IOHWAB_DIN_ACTIVE_HIGH					/**<Active low level value for input*/
}IoHwAb_DinActiveType;


/**
* @brief This structure defines the channel level config parameters for digital inputs
*/
typedef struct
{
    Dio_ChannelType       Hw_ChannelId;   /**< Mcal dio channel id*/
    IoHwAb_DinActiveType  ActiveLevel;    /**< Active level of the input pins*/
    IohwAb_DInSourceSignalType SourceSignalId; /**<DIn Source Signal Id */
    uint8                 DebGroupId ;	  /**< Debounce Group Id*/
    uint8                 DebChannelId;   /**< Debounce channel Id*/
} IoHwAb_DInChannelType;

/**
* @brief This structure defines the configuration parameters for digital inputs
*/
typedef struct
{
    IoHwAb_DInChannelType   IoHwAb_DInChannel[IOHWAB_DIN_NUM_OF_VARIANTS];	/**< Digital Input configuration parameters*/
    IoHwAb_DInSignalIdType  SignalId;										/**< Digital Input signal Id*/
} IoHwAb_DInCfgType;

/*****************************************************************************
*  Public Forward Declarations                                          	 *
******************************************************************************/
extern const IoHwAb_DInCfgType IoHwAb_DInCfg[IOHWAB_NUM_DIN_INPUT];

/*****************************************************************************
*  Private Forward Declarations                                          	 *
******************************************************************************/
Std_ReturnType IoHwAb_DIn_GetCurrentVariant(uint8* DInVariantId);
Std_ReturnType IoHwAb_DIn_PreHook(void);

uint8 IoHwAb_Dio_ReadChannel(Dio_ChannelType ChannelId, IohwAb_DInSourceSignalType SourceSignalId);


#endif
#endif /*IOHWAB_DIN_CFG_H*/

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

