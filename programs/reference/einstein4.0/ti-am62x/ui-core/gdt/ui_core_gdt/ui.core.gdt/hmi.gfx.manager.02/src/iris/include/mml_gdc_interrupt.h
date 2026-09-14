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
 * \file        mml_gdc_interrupt.h
 * \brief       Iris Interrupt Controller API definition.
 *
 */

#ifndef __MML_GDC_INTERRUPT_H__
    #define __MML_GDC_INTERRUPT_H__

#ifdef __cplusplus
    extern "C"
    {
#endif

/**
 * @defgroup mml_gdc_interrupt Iris Interrupt Controller API
 *  The interrupt controller API provides all functions for setting up the
 *  Iris interrupt controller. The interrupt controller module is used to react
 *  on different HW or SW generated events. These events can be routed independently
 *  to the external interrupt lines.
 *
 *  At the initialization all pending interrupts are cleared and then disabled,
 *  all internal variables are initialized to known values.
 *  The driver allows assignment of the interrupts to one of the two external interrupt
 *  lines that are connected to the main processor's interrupt controller. The signature
 *  unit will also generate a non-maskable  interrupt (NMI)  in case of an error.
 *
 *  The driver allows enabling/disabling each of the supported interrupts (so that they are
 *  not delivered to the external interrupt lines). Clearing and presetting the interrupts
 *  is also allowed only internally (except for the software interrupts that have to be
 *  triggered by the software itself) , but this will only be propagated depending on the
 *  enable/disable state of the interrupt. The NMI interrupt has to be cleared/preset
 *  independently (internally).
 *
 *  Internally the driver takes care of setting/clearing the interrupts. The driver provides
 *  an interrupt service routine, that has o be called from the main interrupt service routine
 *  provided by the application (called by the main processor's interrupt controller when one
 *  of the two external interrupts lines or the NMI line gets active). This driver function will
 *  read and return the interrupt status to the application, also taking care of clearing the
 *  interrupts. It is the job of the application's interrupt routine to react on the interrupts
 *  accordingly.
 * @{
 **/

/*****************************************************************************/
/*** INCLUDES ****************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*** DEFINITIONS *************************************************************/
/*****************************************************************************/

/* Interrupt signals definition */
#define MML_GDC_INTERRUPT_NONE             0x00000000UL /*!< No interrupt */
#define MML_GDC_INTERRUPT_DISP_FRAME_START 0x00000010UL /*!< Start sending a new frame to the display controller */
#define MML_GDC_INTERRUPT_DISP_FRAME_END   0x00000040UL /*!< Frame sent to the display controller */
#define MML_GDC_INTERRUPT_CMDSEQ_FULL      0x00000800UL /*!< Command FIFO is full */
#define MML_GDC_INTERRUPT_DISP_POS0        0x00004000UL /*!< Reached programmable frame position 0 */
#define MML_GDC_INTERRUPT_DISP_POS1        0x00008000UL /*!< Reached programmable frame position 1 */
#define MML_GDC_INTERRUPT_DISP_POS2        0x00010000UL /*!< Reached programmable frame position 2 */
#define MML_GDC_INTERRUPT_SIG_CONFIG       0x00020000UL /*!< Loading of the shadow configuration completed */
#define MML_GDC_INTERRUPT_SIG_VALID        0x00040000UL /*!< Signature computation completed and result register valid */
#define MML_GDC_INTERRUPT_SIG_ERROR        0x00080000UL /*!< Signature violation (number of error frames exceeded threshold value */
#define MML_GDC_INTERRUPT_GP_INT0          0x00100000UL /*!< General purpose interrupt 0 */
#define MML_GDC_INTERRUPT_GP_INT1          0x00200000UL /*!< General purpose interrupt 1 */
#define MML_GDC_INTERRUPT_GP_INT2          0x00400000UL /*!< General purpose interrupt 2 */
#define MML_GDC_INTERRUPT_GP_INT3          0x00800000UL /*!< General purpose interrupt 3 */

/* NMI interrupt signals definition */
#define MML_GDC_INTERRUPT_NMI_NONE         0x00000000UL /*!< No NMI interrupt */
#define MML_GDC_INTERRUPT_NMI_SIG_ERROR    0x00000001UL /*!< Signature violation (number of error frames exceeded threshold value */

/*****************************************************************************/
/*** TYPES / STRUCTURES ******************************************************/
/*****************************************************************************/

/* Interrupt controller external lines */
typedef enum
{
    MML_GDC_INT_CTRL_LINE_0  = 0x0,    /*!< External line0 */
    MML_GDC_INT_CTRL_LINE_1  = 0x1     /*!< External line1*/
} MML_GDC_INT_CTRL;

/*****************************************************************************/
/*** FUNCTION PROTOTYPES *****************************************************/
/*****************************************************************************/

/** @name Interrupt Operations Functions
 * @{
 */

/**
 * [SWDD7010] Interrupt Controller External Lines Assignment\n
 * \cond Related to SWAD000, SWAD700, SWAD702 \endcond
 *
 * Assign internal interrupts to external interrupt lines\n
 * @param uInterruptMask Interrupt mask to be mapped to the line
 * @param eInterruptLine External interrupt line to map to.\n
 *        Can be either #MML_GDC_INT_CTRL_LINE_0 or #MML_GDC_INT_CTRL_LINE_1
 **/
IRIS_API void mmlGdcInterruptMap(MM_U32 uInterruptMask, MML_GDC_INT_CTRL eInterruptLine);

/**
* [SWDD7020] Enable Interrupts\n
* \cond Related to SWAD000, SWAD700, SWAD703\n \endcond
*
* Enable interrupts specified as mask as defined in this API\n
* @param uInterruptMask Interrupts mask to be enabled
**/
IRIS_API void mmlGdcInterruptEnable(MM_U32 uInterruptMask);

/**
 * [SWDD7030] Disable Interrupts\n
 * \cond Related to SWAD000, SWAD700, SWAD703\n \endcond
 *
 * Disable specified interrupts\n
 * @param uInterruptMask Interrupts to be disabled, as mask as specified in this API
 **/
IRIS_API void mmlGdcInterruptDisable(MM_U32 uInterruptMask);

/**
 * [SWDD7040] Preset Interrupts\n
 * \cond Related to SWAD000, SWAD700, SWAD703\n \endcond
 *
 * Triggers specified interrupts\n
 * @param uInterruptMask Interrupt mask to be triggered as defined in this API
 **/
IRIS_API void mmlGdcInterruptPreset(MM_U32 uInterruptMask);

/**
 * [SWDD7050] Interrupt Handler Function\n
 * \cond Related to SWAD000, SWAD700, SWAD704\n \endcond
 *
 * Called by the application upon entering service routine. This function has to be
 * called by the application in it's interrupt service routine. The return value
 * tells the application which of the interrupts associated with the interrupt line
 * occurred so it can react accordingly.\n
 * @param eInterruptLine External interrupt line number
 * @return Interrupt status as mask as defined in this API
 **/
IRIS_API MM_U32 mmlGdcInterruptHandler(MML_GDC_INT_CTRL eInterruptLine);

/**
 * [SWDD7060] NMI Interrupt Handler Function\n
 * \cond Related to SWAD000, SWAD700, SWAD704\n \endcond
 *
 * Called by the application upon entering service routine. This function has to be
 * called by the application in it's NMI interrupt service routine. The return value
 * tells the application which of the interrupts associated with the NMI interrupt line
 * occurred so it can react accordingly.\n
 * @return NMI Interrupt status as mask as defined in this API
 **/
IRIS_API MM_U32 mmlGdcInterruptNMIHandler(void);

/**
 *! @}
 **/

/**
 *! @}
 **/

#ifdef __cplusplus
    }
#endif

#endif /* __MML_GDC_INTERRUPT_H__ */
