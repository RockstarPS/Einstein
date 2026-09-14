/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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

# ifndef CLIENT_H
# define CLIENT_H


#include "string.h"
#include "Dcm.h"
#include "ClientUpdateMan.h"
#include "Rte_CUpdateCdd.h"
//=====================================================================================================================
/*Constants and types*/
# define DNLD_RESP_SIZE                              (0x20u)
# define DNLD_REQ_BLK_SIZE                           (0x0400u)
# define DNLD_COMPRESS_LZSS                          (0x10u)
# define DNLD_DELTA_COMPRESS_LZSS                    (0x20u)
# define DNLD_ENCRYPT	                             (0x01u)
# define DNLD_RAW   	                             (0x00u)
# define CRYPTO_DATA_START_ADDR_OFFSET               ((uint8) 1)
# define CRYPTO_DATA_SIZE_OFFSET                     ((uint8) 5)
# define CRYPTO_SIGN_SIZE_OFFSET                     ((uint8) 14)
# define CRYPTO_SIGN_START_ADDR_OFFSET               ((uint8) 16)
# define PDUR_MODULE_ID                              (3U)
# define CRYPTO_SIGN_SIZE                            (256u)
# define SID_IDLE                                    (0u)
# define SID_TRANSFERSTART                           (34u)
# define SID_TRANSFERDATA                            (36u)
# define SID_TRANSFEREXIT                            (37u)     

/****************************NRC CODES*******************************/
# define NRC_GENERAL_PROGRAMMINGFAILURE              (0x72u)
# define NRC_INCORRECTMESSAGEFORMAT_INVALIDFORMAT    (0x13u) 
# define NRC_SEQUENCEMISMATCH_ERROR                  (0x73u)
# define NRC_REQUESTSEQUENCE_ERROR                   (0x24u)
# define NRC_REPROGRAMMINDLIMIT_EXCEEDED             (0x71u) 
# define NRC_SECURITYLEVELCHECK_ERROR                (0x33u)
# define NRC_SIGNATURE_NONCE_RECEIVEERROR            (0x70u)
//=====================================================================================================================
/*Global variables*/
//=====================================================================================================================
//  Internal CDD accessors
//=====================================================================================================================

//=====================================================================================================================
//  Deployment functions - To be defined by the children class
//=====================================================================================================================
Std_ReturnType UpdateCdd_ClientInit(void);
Std_ReturnType UpdateCdd_GenericRequest_Verify_RSA_SignatureValue (Dcm_OpStatusType opStatus, uint8 *pMsgContext, Dcm_NegativeResponseCodeType *ErrorCode);
/*=====================================================================================================================*/
/* tUPDiUpdateCdd configuration*/
/*=====================================================================================================================*/

# endif /*CLIENT_H*/
