#ifndef UCLILSTREAM_H
#define UCLILSTREAM_H

#include "UclILStream_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

///
/// @brief This method is used to initialize the UclILStream Instance
///
/// @param InstId Instance Id to initialize
///
/// @return UCL_E_OK 	Initialization Success
///	@return	UCL_E_NOK 	Initialization Failed
///
Ucl_ReturnType UclILStream_Initialize(uint8 InstId);

///
/// @brief This method is used to shutdown the UclILStream Instance
///
/// @param InstId Instance Id to shutdown
///
/// @return UCL_E_OK 	Shutdown Success
///	@return	UCL_E_NOK 	Shutdown Failed
///
Ucl_ReturnType UclILStream_Shutdown(uint8 InstId);

///
/// @brief  Open an UCL Channel
///
/// @param InstId Instance Id to Open
/// @param[in]  chId    Channel Identifier
/// @param[in]  flags   @ref UCL_O_FLAGS
///
/// @return > 0 File descriptor to be used
/// @return < 0 @ref UCL_ERR
///
sint32 UclILStream_Open(uint8 instId, uint8 chId, uint16 flags);

///
/// @brief  Close an UCL Channel
///
/// @param InstId Instance Id to Close
/// @param[in]  fd  File descriptor returned by the open call
///
/// @return @ref UCL_E_OK   Successfully closed the channel
/// @return @ref UCL_ERR
///
sint32 UclILStream_Close(uint8 instId, sint32 fd);

///
/// @brief  Read data from the UCL channel
///
/// @param InstId Instance Id to Read
/// @param[in]  fd      File descriptor returned by the open call
/// @param[out] pBuffer Buffer to return the received data
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes read
/// @return < 0 @ref UCL_ERR
///
sint32 UclILStream_Read(uint8 instId, sint32 fd, uint8  *pBuffer, uint32  size);

///
/// @brief  Write data to the UCL channel
///
/// @param InstId Instance Id to Write
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes sent
/// @return < 0 @ref UCL_ERR
///
sint32 UclILStream_Write(uint8 instId, sint32 fd, uint8  *pBuffer, uint32  size);

///
/// @brief  Poll the UCL channel to check for receive data
///
/// @param InstId Instance Id to Poll
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  timeout Timeout to wait for data
///
/// @return > 0 number of bytes waiting to be read
/// @return < 0 @ref UCL_ERR
///
sint32 UclILStream_Poll(uint8 instId, sint32 fd, uint32 timeout);

///
/// @brief  Poll the UCL channel to check for transmit confirmation
///
/// @param InstId Instance Id to PollEx
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  reqId   Request ID used in the ucl_write_ex call
/// @param[out] pStatus Transmit status of the message
/// @param[in]  timeout Timeout to wait for the confirmation
///
/// @return @ref UCL_E_OK   Status returned successfully
/// @return < 0 @ref UCL_ERR
///
sint32 UclILStream_PollEx(uint8 instId, sint32 fd, uint8 reqId, uint32 *pStatus, uint32 timeout);

///
/// @brief  Write data to the UCL channel along with the request id
///
/// @param InstId Instance Id to WriteEx
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  reqId   Request ID to be associated with this write request
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes sent
/// @return < 0 @ref UCL_ERR
///
sint32 UclILStream_WriteEx(uint8 instId, sint32 fd, uint8 reqId, uint8 *pBuffer, uint32 size);

///
/// @brief  UCL Input/Output Control API to configure channel parameters
///
/// @param InstId Instance Id to Ioctl
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  request @ref UCL_IOCTL
/// @param[in]  pData   Pointer to the structure corresponding to the request
/// @param[in]  size    Size of the structure
///
/// @return @ref UCL_E_OK   Success
/// @return @ref UCL_ERR
///
sint32 UclILStream_Ioctl(uint8 instId, sint32 fd, uint16 request, void *pData, uint16 size);



#ifdef __cplusplus
}
#endif
#endif //UCLILSTREAM_H
