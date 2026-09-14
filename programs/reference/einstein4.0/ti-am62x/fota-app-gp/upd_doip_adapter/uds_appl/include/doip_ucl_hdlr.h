/*
 * doip_ucl_hdlr.h
 *
 *  Created on: May 17, 2020
 *      Author: MMK
 */

#ifndef DOIP_UCL_HDLR_H
#define DOIP_UCL_HDLR_H

#define UCL_MSG_HDR 0x00

#define ReadDIDReqID 0x9901
#define ReadDTCReqID 0x9902
#define WriteDTCReqID 0x9903
#define ECUResetReqID 0x9904
#define ReadDigestReqID 0x9905
#define ReadGIPDigestReqID 0x9906
#define ReadGlobalDTCReqID 0x9907
#define WriteFingerprintReqID 0x990A

#define ReadDIDRespID 0x9941
#define ReadDTCRespID 0x9942
#define WriteDTCRespID 0x9943
#define ECUResetRespID 0x9944
#define ReadDigestRespID 0x9945
#define ReadGIPDigestRespID 0x9946
#define ReadGlobalDTCRespID 0x9947
#define WriteFingerprintRespID 0x994A

#define ReadDIDReqPayLoadSize 2
#define ReadDTCReqPayLoadSize 2
#define WriteDTCReqPayLoadSize 3
#define ECUResetReqPayLoadSize 2
#define ReadDigestReqPayLoadSize 2
#define ReadGIPDigestReqPayLoadSize 2
#define ReadGlobalDTCReqPayLoadSize 2
#define WriteFingerPrintReqPayloadSize 18 

#define ReadDIDRespPayLoadSize 116
#define ReadDTCResPayLoadSize 3
#define WriteDTCRespSize 1
#define ReadDigestRespPayLoadSize 256
#define ReadGIPDigestRespPayLoadSize 34
#define ReadGlobalDTCRespPayLoadSize 2

#endif /* DOIP_UCL_HDLR_H */
