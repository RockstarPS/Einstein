/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
*  File Name         :  Lin_GeneralTypes.h                                   *
*  Module Short Name :  LinGeneralTypes                                      *
*  Description       :  This file contains implementations of the Lin Driver *
*                       for AM62PX series microcontrollers.                  *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                         *
* Target Hardware  :  AM62PX micro based Hardware Platform                   *
*                                                                            *
******************************************************************************/

#ifndef LIN_GENERAL_TYPES_H
#define LIN_GENERAL_TYPES_H

/*****************************************************************************
*                               Include files                                *
******************************************************************************/

/*****************************************************************************
*                              Macro Definitions                             *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                   Enums                                    *
******************************************************************************/

/**
* @brief          Checksum models for the LIN Frame.
* @details        This type is used to specify the Checksum model to be
*                 used for the LIN Frame.
* @implements     Lin_FrameCsModelType_enumeration
*/
typedef enum
{
    LIN_ENHANCED_CS,    /**< @brief Enhanced checksum model.*/
    LIN_CLASSIC_CS      /**< @brief Classic checksum model.*/
}Lin_FrameCsModelType;

/**
* @brief          Frame response types.
* @details        This type is used to specify whether the frame
*                 processor is required to transmit the response
*                 part of the LIN frame.
* @implements     Lin_FrameResponseType_enumeration
*/
typedef enum
{
    LIN_MASTER_RESPONSE,    /**< @brief Response is generated from
                                        this (master) node.*/
    LIN_SLAVE_RESPONSE,     /**< @brief Response is generated from a
                                        remote slave node.*/
    LIN_SLAVE_TO_SLAVE      /**< @brief Response is generated from one
                                        slave to another slave.*/
                            /**< @brief For the master the response
                                        will be anonymous, it does not
                                        have to receive the response.*/
}Lin_FrameResponseType;

/**
* @brief          LIN Frame and Channel states operation.
* @details        LIN operation states for a LIN channel or frame, as returned
*                 by the API service Lin_GetStatus().
*                 part of the LIN frame.
* @implements     Lin_StatusType_enumeration
*/
typedef enum
{
    LIN_NOT_OK = 0,     /**< @brief Development or production error
                                    occurred.*/
    LIN_TX_OK,          /**< @brief Successful transmission.*/
    LIN_TX_BUSY,        /**< @brief Ongoing transmission (Header or
                                    Response).*/
    LIN_TX_HEADER_ERROR,/**< @brief Erroneous header transmission such
                                    as:
                                     - Mismatch between sent and read
                                       back data
                                     - Identifier parity error
                                     - Physical bus error.*/
    LIN_TX_ERROR,       /**< @brief Erroneous transmission such as:
                                     - Mismatch between sent and read
                                       back data
                                     - Physical bus error.*/
    LIN_RX_OK,          /**< @brief Reception of correct response.*/
    LIN_RX_BUSY,        /**< @brief Ongoing reception:
                                    at least one response byte has
                                    been received, but the checksum
                                    byte has not been received.*/
    LIN_RX_ERROR,       /**< @brief Erroneous reception such as:
                                     - Framing error
                                     - Overrun error
                                     - Checksum error
                                     - Short response.*/
    LIN_RX_NO_RESPONSE, /**< @brief No response byte has been received
                                    so far.*/
                        /**< @brief This is a mess !!
                                   Frame status is mixed with channel
                                   status but i kept it here only
                                   because of LIN168.*/
    LIN_OPERATIONAL,    /**< @brief Normal operation;
                                     - The related LIN channel is ready
                                       to transmit next header
                                     - No data from previous frame
                                       available (e.g. after
                                       initialization).*/
    LIN_CH_SLEEP        /**< @brief Sleep mode operation;
                                     - In this mode wake-up detection
                                       from slave nodes is enabled.*/
}Lin_StatusType;

/**
* @brief          Transmission status types.
* @details        This type is used to check the
*                 status of frame transmission.
* @implements     Lin_TxStatusType_enumeration
*/
typedef enum
{
  LIN_TX_DISABLED,
  LIN_TX_IDLE,
  LIN_TX_CONFIRMATION_PENDING,
  LIN_TX_CONFIRMATION_SUCCESS
}Lin_TxStatusType;

/**
* @brief          Reception status types.
* @details        This type is used to check the
*                 status of frame reception.
* @implements     Lin_RxStatusType_enumeration
*/
typedef enum
{
  LIN_RX_DISABLED,
  LIN_RX_IDLE,
  LIN_RX_CONFIRMATION_PENDING,
  LIN_RX_CONFIRMATION_SUCCESS
}Lin_RxStatusType;

/*****************************************************************************
*                       Structures and Type Declarations                     *
******************************************************************************/
/**
* @brief          Data length of a LIN Frame.
* @details        This type is used to specify the number of SDU
*                 data bytes to copy.
* @implements     Lin_FrameDlType_typedef
*/
typedef uint8 Lin_FrameDlType;

/**
* @brief          The LIN identifier (0..0x3F) with its parity bits.
* @details        Represents all valid protected Identifier used by
*                 Lin_SendFrame().
* @implements     Lin_FramePidType_typedef
*/
typedef uint8 Lin_FramePidType;

/**
* @brief          The LIN identifier (0..0x3F) with its parity bits.
* @details        This Type is used to provide PID, checksum model,
*                 data length and SDU pointer from the LIN Interface
*                 to the LIN driver.
* @implements     Lin_PduType_struct
*/
typedef struct
{
    Lin_FramePidType      Pid;     /**< @brief LIN frame identifier.*/
    Lin_FrameCsModelType  Cs;      /**< @brief Checksum model type.*/
    Lin_FrameResponseType Drc;     /**< @brief Response type.*/
    Lin_FrameDlType       Dl;      /**< @brief Data length.*/
    uint8*                SduPtr;  /**< @brief Pointer to Sdu.*/
}Lin_PduType;

#endif /* LIN_GENERAL_TYPES_H */

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : -05-2024                                              */
/*Version           :                                                       */
/*By                : mhishamu                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/