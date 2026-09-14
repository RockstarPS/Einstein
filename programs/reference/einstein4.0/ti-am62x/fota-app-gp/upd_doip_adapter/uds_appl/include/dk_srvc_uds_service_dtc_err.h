/*
 * dk_srvc_uds_service_dtc_err.h
 *
 *  Created on: May 4, 2020
 *      Author: MMK
 */

#ifndef DK_SRVC_UDS_SERVICE_DTC_ERR_H
#define DK_SRVC_UDS_SERVICE_DTC_ERR_H

#include "dk_srvc_uds_service_dtc_handler.h"

/* Maximum response length */
#define MAX_DATA_RESPONSE                                    (4096u)  //1026u

/*
** Positive response suppression
*/
#define RESPONSE_SUPPRESS_MASK              (0x7Fu)
#define UDS_INSPECT_POS_RSP_SUPPRESSED(x)   ((udsdiagu8)(x[0] & \
                                            (udsdiagu8)(~(udsdiagu8)RESPONSE_SUPPRESS_MASK)))

#define UDS_MGR_READDTCINFORMATIONSERVICEID          ((uint8_t) 0x19U)
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#define UDS_MGR_READDTCINFORMATIONREQUEST_CONSTANTSIZE                       \
                                                      ((uint16_t) 1)
#define UDS_MGR_READDTCINFORMATIONBYMASKREQUEST_CONSTANTSIZE                 \
                                                      ((uint16_t) 2)
#define UDS_MGR_READDTCINFORMATIONREQUEST_SUBFUNCTIONINDEX                  (1)
#define UDS_MGR_READDTCINFORMATIONREQUEST_MASKINDEX                         (2)


#define UDS_MGR_READDTCINFORMATIONRESPONSE_CONSTANTSIZE                     (3)
#define UDS_MGR_READDTCINFORMATIONRESPONSECOUNTERS_CONSTANTSIZE             (2)
#define UDS_MGR_READDTCINFORMATIONRESPONSE_INDEX                            (2)
#define UDS_MGR_READDTCINFORMATIONRESPONSE_DTCINDEX                         (3)
#define UDS_MGR_READDTCINFORMATIONRESPONSECOUNTERS_DTCINDEX                 (2)
#define UDS_MGR_READDTCINFORMATIONRESPONSEBYMASK_CONSTANTSIZE               (6)
#define UDS_MGR_READDTCINFORMATIONRESPONSEBYMASK_INDEX                      (2)
#define UDS_MGR_READDTCINFORMATIONRESPONSEBYMASK_DTCINDEX                   (3)

#define UDS_MGR_DTCFORMATIDENTIFIER                            ((uint8_t)0x00U)


#define UDS_MGR_MESSAGEMAXSIZE                                   ( 1026UL )

#define UDS_MGR_DTCNOTTESTED                     ((uint8_t)0x10U)
#define UDS_MGR_DTCTESTFAILED                    ((uint8_t)0x01U)
#define UDS_MGR_DTCTESTOK                        ((uint8_t)0x00U)
#define UDS_MGR_LOGICALZONESCOUNT                    2U
#define UDS_MGR_GLOBALDTCCOUNT                           1
#define UDS_MGR_BASEDTCMIN                               ( 0xFD00U)
#define UDS_MGR_BASEDTCMAX       ((UDS_MGR_BASEDTCMIN + (UDS_MGR_LOGICALZONESCOUNT - 1)))
#define UDS_MGR_ALLDTCMAX        ((UDS_MGR_BASEDTCMIN + ((UDS_MGR_LOGICALZONESCOUNT + UDS_MGR_GLOBALDTCCOUNT) - 1)))
#define UDS_MGR_GLOBALDTC        ((UDS_MGR_BASEDTCMIN + ((UDS_MGR_LOGICALZONESCOUNT + UDS_MGR_GLOBALDTCCOUNT) - 1)))

#define UDS_MGR_RCREQUEST_DTCLOGZONEIDMIN                  UDS_MGR_BASEDTCMIN
#define UDS_MGR_RCREQUEST_DTCLOGZONEIDMAX                  UDS_MGR_BASEDTCMAX
#define UDS_MGR_RCREQUEST_DTCGLOBALID                      UDS_MGR_GLOBALDTC


#define UDS_MGR_GENERALMEMORYFAILUREDTC          ((uint8_t) 0x42U)
#define UDS_MGR_PROGLIMITCNTRREPORTLIMITVALUE    ((uint16_t)1000)

#define UDS_MGR_C2 2
#define UDS_MGR_C3 3
#define UDS_MGR_C4 4
#define UDS_MGR_C8 8
#define UDS_MGR_U16MASK ((uint16_t)0x00FFU)


#define UDS_MGR_VALIDDTC                         ((uint8_t) 0x51U)

#define UDS_MGR_GENERALMEMORYFAILUREDTC          ((uint8_t) 0x42U)
#define GIP_DTC_42                              ((uint8_t) 0x00U)   //hardcoded 

//#define UDS_MGR_PROGLIMITCNTRREPORTLIMITVALUE    ((uint16_t)126)
#define UDS_MGR_PROGLIMITCNTRREPORTLIMITVALUE    ((uint16_t)1000)


#define UDS_MGR_READDTCINFORMATIONSERVICEID          ((uint8_t) 0x19U)

#endif /* DK_SRVC_UDS_SERVICE_DTC_ERR_H */
