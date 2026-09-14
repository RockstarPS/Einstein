/*
 * uds_mgr_doip_error.h
 *
 *  Created on: May 15, 2020
 *      Author: MMK
 */

#ifndef UDS_MGR_DOIP_ERROR_H
#define UDS_MGR_DOIP_ERROR_H

#define FBL_OK							0U
#define FBL_FAIL						1U
#define FBL_TIMEOUT						2U
#define FBL_INVALID_PARAM				3U
#define FBL_INVALID_ADDR				4U
#define FBL_INVALID_SIZE				5U
#define FBL_BUSY						7U
#define FBL_COMM_FAIL					8U

/* Negative Response Code */

#define NO_ERROR                                             0x00u
#define NRC_GENERAL_REJECT                                   0x10u
#define NRC_SERVICE_NOT_SUPPORTED                            0x11u
#define NRC_SUBFUNCTION_NOT_SUPPORTED                        0x12u
#define NRC_INVALID_FORMAT                                   0x13u
#define NRC_BUSY_REPEAT_REQUEST                              0x21u
#define NRC_CONDITIONS_NOT_CORRECT                           0x22u
#define NRC_ROUTINE_NOT_COMPLETED                            0x23u
#define NRC_REQUEST_SEQUENCE_ERROR                           0x24u
#define NRC_REQUEST_OUT_OF_RANGE                             0x31u
#define NRC_SECURITY_ACCESS_DENIED                           0x33u
#define NRC_INVALID_KEY                                      0x35u
#define NRC_EXCEEDED_NUMBER_ATTEMPTS                         0x36u
#define NRC_REQUIRED_TIME_DELAY_NOT_EXPIRED                  0x37u
#define NRC_TRANSFER_DATA_SUSPENDED                          0x71u
#define NRC_GENERAL_PROGRAMMING_FAILURE                      0x72u
#define NRC_WRONG_BLOCK_SEQ_COUNTER                          0x73u
#define NRC_RESPONSE_PENDING                                 0x78u
#define NRC_SUBFUNCTION_NOT_SUPPORTED_IN_ACTIVE_SESSION      0x7Eu
#define NRC_SERVICE_NOT_SUPPORTED_IN_ACTIVE_SESSION          0x7Fu
#define NRC_DOWNLOAD_NOT_ACCEPTED                            0x70u

#endif /* UDS_MGR_DOIP_ERROR_H */
