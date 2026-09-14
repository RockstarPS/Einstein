///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
/// @defgroup UclSys
/// @brief UCL System handles the Ucl Stack, provides API's for applications to call the Ucl functions
/// @file
/// @ingroup UclSys
/// UCL System Interface APIs.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLSYS_H
#define UCLSYS_H

#include "UclSys_Types.h" //MISRA C++-2008 Rule 16-0-1
#include "UclDL_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

///
/// @brief This method is used to initialize the UclSys Instance
///
/// @param InstId Instance Id to initialize
///
/// @return UCL_E_OK 	Initialization Success
///	@return	UCL_E_NOK 	Initialization Failed
///
Ucl_ReturnType UclSys_Initialize(uint8 InstId);

///
/// @brief This method is used to shutdown the UclSys Instance
///
/// @param InstId Instance Id to shutdown
///
/// @return UCL_E_OK 	Shutdown Success
///	@return	UCL_E_NOK 	Shutdown Failed
///
Ucl_ReturnType UclSys_Shutdown(uint8 InstId);

///
/// @brief This method is used to send a UCL message for specific DL Instance
///        UclSysDL Implementation supports this method
///
/// @param InstId Instance Id of UclSys
/// @param DLInst Instance Id of UclDL
/// @param pMsg Pointer to the UclDL Message
///
/// @return UCL_E_OK 	Send Success
///	@return	UCL_E_NOK Send Failed
/// @return UCL_E_NOT_SUPPORTED Method not supported
///
Ucl_ReturnType UclSys_Send(uint8 InstId, uint8 DLInst, SUclDLMsg *pMsg);

///
/// @brief This method is used to run the Ucl Stack
///        This should be used called periodically as per the
///        OS tick configuration in RTOS based systems
///
/// @param InstId Instance Id of UclSys
///
/// @return None
///
void UclSys_Task(uint8 InstId);

#ifdef __cplusplus
}
#endif
#endif //UCLSYS_H
