///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation.
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
/// @defgroup UclALPhy
/// @brief UCL Physical Layer Abstraction Layer. Provides APIs to send and receive data over variety of physical transports.
/// @file
/// @ingroup UclALPhy
/// UCL Physical Layer Abstraction Layer. Provides APIs to send and receive data over variety of physical transports.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_H
#define UCLALPHY_H
#ifdef __cplusplus
extern "C" {
#endif

#include "UclALPhy_Types.h"

///
/// @brief This method is used to initialize the UclALPhy Instance
///
/// @param InstId Instance Id to initialize
///
/// @return UCL_E_OK 	Initialization Success
///	@return	UCL_E_NOK 	Initialization Failed
///
Ucl_ReturnType UclALPhy_Initialize(uint8 InstId);

///
/// @brief This method is used to shutdown the UclALPhy Instance
///
/// @param InstId Instance Id to shutdown
///
/// @return UCL_E_OK 	Shutdown Success
///	@return	UCL_E_NOK 	Shutdown Failed
///
Ucl_ReturnType UclALPhy_Shutdown(uint8 InstId);

///
/// @brief This method is used to send data to the UclALPhy Instance
///
/// @param InstId Instance Id to send data
/// @param pData  Pointer to the data buffer
/// @param Size   Size of the data buffer
///
/// @return UCL_E_OK 		Data Transmit Success
/// @return UCL_E_PENDING 	Message Accepted for transmission
///	@return	UCL_E_NOK 		Data Transmit Rejected
///
Ucl_ReturnType UclALPhy_Write(uint8 InstId, uint8 *pData, uint16 size);

///
/// @brief This method is used to read a data frame from the UclALPhy Instance
///
/// @param InstId Instance Id to read the data frame
/// @param pData  Pointer to the data buffer
/// @param pSize  [in] Size of the data buffer, [out] Size of the data frame
///
/// @return UCL_E_OK 		Data available
///	@return	UCL_E_NOK 		Data not available
///
Ucl_ReturnType UclALPhy_Read(uint8 InstId, uint8 *pData, uint16 *pSize);

#ifdef __cplusplus
}
#endif
#endif //UCLALPHY_H
