/*
 * doip_dtc.h
 *
 *  Created on: May 19, 2020
 *      Author: MMK
 */

#ifndef DTC_DOIP_DTC_H
#define DTC_DOIP_DTC_H


#define UDS_MGR_VALIDDTC                         ((uint8_t) 0x51U)
#define UDS_MGR_DTCNOTTESTED                     ((uint8_t)0x10U)
#define UDS_MGR_DTCTESTFAILED                    ((uint8_t)0x01U)
#define UDS_MGR_DTCTESTOK                        ((uint8_t)0x00U)

#define UDS_MGR_LOGICALZONESCOUNT                    2U
#define UDS_MGR_GLOBALDTCINDEX   ((uint8_t)(UDS_MGR_LOGICALZONESCOUNT))

#define UDS_MGR_ECUCOMPATIBILITYDTC              ((uint8_t) 0x06U)

#endif /* DTC_DOIP_DTC_H */
