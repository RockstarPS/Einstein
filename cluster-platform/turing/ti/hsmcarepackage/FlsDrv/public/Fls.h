/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file Fls.h
 *
 * \brief
 * HSM FLS driver header file for AM62PX
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 |            | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"


/**
 *********************************************************************************************
 ** \enum     vHsmFls_StatusType
 **
 ** \brief    vHsmFls status type.
 **
 *********************************************************************************************
 */
typedef enum
{
    vHSMFLS_UNINIT = 0,        /**< Fls Driver not initialized */
    vHSMFLS_IDLE,              /**< Fls driver is idle */
    vHSMFLS_BUSY,              /**< Fls driver is busy processing a job */
    vHSMFLS_BUSY_INTERNAL      /**< Fls driver is busy internally */
}vHsmFls_StatusType;


/**
 *********************************************************************************************
 ** \fn        Fls_MainFunction
 **
 ** \brief     Flash driver main function for job processing.
 **
 ** \details   Should be called periodically by the OS or scheduler. It processes
 **            ongoing flash operations (erase/write/read), handles timeouts,
 **            and invokes the job result notification callbacks.
 **
 ** \param[in] void
 **
 ** \return    void
 **
 ** \note      This function is mandatory for non-blocking flash operations.
 **
 *********************************************************************************************
 */
void Fls_MainFunction(void);
/**
 *********************************************************************************************
 ** \fn        Fls_GetStatus
 **
 ** \brief     Returns the current job status of the Flash driver.
 **
 ** \details   This function allows the upper layer to check the status of an
 **            ongoing flash operation (e.g., busy, idle).
 **
 ** \param[in] void
 **
 ** \return    MemIf_StatusType
 **            vHSMFLS_BUSY    - A job is being processed.
 **            vHSMFLS_IDLE    - No job is being processed.
 **
 ** \note      Useful for polling job status in synchronous systems.
 **
 *********************************************************************************************
 */
vHsmFls_StatusType Fls_GetStatus(void);
/**
 *********************************************************************************************
 ** \fn        Fls_Read
 **
 ** \brief     Starts a flash read operation.
 **
 ** \details   Sync Read of a block of data from the flash memory into a RAM buffer.
 **            as of now only one sector read is supported.
 **
 ** \param[in] flsaddressoff  Flash address to start reading from.
 ** \param[in] dataPtr        Pointer to the RAM buffer to store the read data.
 ** \param[in] Length         Number of bytes to read.
 **
 ** \return    Std_ReturnType
 **            E_OK      - Read job accepted.
 **            E_NOT_OK  - Read job failed to start.
 **
 ** \note      Flash must be initialized before invoking this function.
 **
 *********************************************************************************************
 */

Std_ReturnType Fls_Read(uint32 flsaddressoff, uint8 * dataPtr, uint32 Length);
/**
 *********************************************************************************************
 ** \fn        Fls_Erase
 **
 ** \brief     Starts a flash erase operation.
 **
 ** \details   Initiates the erase process for the specified flash memory range. 
 **            It erases one or more complete sectors starting at the provided address.
 **
 ** \param[in] flsaddressoff  The start address in flash memory to begin erasing.
 ** \param[in] Length         The number of bytes to erase (must align with sector size).
 **
 ** \return    Std_ReturnType
 **            E_OK      - Job has been accepted successfully.
 **            E_NOT_OK  - Job could not be started.
 **
 ** \note      Ensure that Fls_Init has been called before this function.
 **
 *********************************************************************************************
 */
Std_ReturnType Fls_Erase(uint32 flsaddressoff,uint32 Length);
/**
 *********************************************************************************************
 ** \fn        Fls_Write
 **
 ** \brief     Starts a flash write operation.
 **
 ** \details   Syncrounous Write a block of data to the flash memory at the given address.
 **            Data will be written from the source buffer to flash in pages or chunks.
 **
 ** \param[in] flsaddressoff  The start address in flash memory to begin writing.
 ** \param[in] dataPtr  Pointer to the data to write.
 ** \param[in] Length         Number of bytes to write.
 **
 ** \return    Std_ReturnType
 **            E_OK      - Job has been accepted.
 **            E_NOT_OK  - Write job could not be started.
 **
 ** \note      This function must be called after Fls_Init.
 **
 *********************************************************************************************
 */
Std_ReturnType Fls_Write(uint32 flsaddressoff, uint8 * dataPtr, uint32 Length);

/**
 ********************************************************************************************
 ** \fn        Fls_Init
 **
 ** \brief     Initializes the Flash driver module.
 **
 ** \details   This function initializes the AUTOSAR Flash (Fls) driver.
 **            It must be called before any other Fls function.
 **
 ** \param     void 
 **
 ** \return    void
 **
 ** \note      This function is typically called during the system initialization phase.
 **
 *********************************************************************************************
 */
void Fls_Init(void);

/*EOF*/
