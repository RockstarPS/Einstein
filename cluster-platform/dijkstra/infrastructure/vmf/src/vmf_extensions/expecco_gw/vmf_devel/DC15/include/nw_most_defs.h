


#ifndef _MOST_DEFS_H
#define _MOST_DEFS_H

/* MOST state */
#define MOST_NET_OFF                            ((unsigned8)0x00)
#define MOST_NET_ON                             ((unsigned8)0x01)

/*
==============================================================================
    MOST wake up reason
==============================================================================
*/
#define SYS_WAKE_UP_REASON__NO_FSTP             ((unsigned8)0)
#define SYS_WAKE_UP_REASON__FSTP                ((unsigned8)(SYS_WAKE_UP_REASON__NO_FSTP + 1))

/*
==============================================================================
    MOST node default address
==============================================================================
*/
#define MOST_FAKE_MODE_DEV_ID                   ((unsigned16) 0x0100)

/*
==============================================================================
    FBlock constants
==============================================================================
*/
#define MOST_TGT_INIC                           ((unsigned16) 0x0001)
#define MOST_TGT_NETWORK_TIMING_MASTER          ((unsigned16) 0x0100)
#define MOST_TGT_BROADCAST                      ((unsigned16) 0x03C8)
#define MOST_TGT_INVALID_ADDR                   ((unsigned16) 0xFFFF)

#define MOST_ERR_MSG___NOT_TO_BE_SENT           ((unsigned8)0xFF)
#define MOST_ERR_MSG___OK_TO_SEND               ((unsigned8)0x00)

/*
==============================================================================
    FBlock constants
==============================================================================
*/

#define MOST_FBLOCK_INIC                        ((unsigned8) 0x00)
#define MOST_FBLOCK_NETBLOCK                    ((unsigned8) 0x01)
#define MOST_FBLOCK_NETWORKMASTER               ((unsigned8) 0x02)
#define MOST_FBLOCK_CONNECTMASTER               ((unsigned8) 0x03)
#define MOST_FBLOCK_POWERMASTER                 ((unsigned8) 0x04)
#define MOST_FBLOCK_VEHICLE                     ((unsigned8) 0x05)
#define MOST_FBLOCK_DIAGNOSTICS                 ((unsigned8) 0x06)
#define MOST_FBLOCK_KOMBI_MISC                  ((unsigned8) 0xCA)
#define MOST_FBLOCK_ET                          ((unsigned8) 0x0F)
#define MOST_FBLOCK_ALL                         ((unsigned8) 0xFF)

/*
==============================================================================
    InstIds constants
==============================================================================
*/
#define MOST_INST_ANY                           ((unsigned8) 0x00)
#define MOST_INST_ALL                           ((unsigned8) 0xFF)
#define MOST_INST_ID_UNUSED                     ((unsigned8) 0x00)
#define MOST_INSTID_VEHICLE                     ((unsigned8) 0x00)
#define MOST_INSTID_KOMBI_MISC_FUNC             ((unsigned8) 0x00)

/*------------------------------------------------------------------- */
/* FunctionIDs of FBlock NetBlock */
/*------------------------------------------------------------------- */
#define MOST_NB_FUNC_FBLOCKIDS                  ((unsigned16) 0x000)   /* FBlock IDs */
#define MOST_NB_FUNC_DEVICEINFO                 ((unsigned16) 0x001)   /* Device Info */
#define MOST_NB_FUNC_NODEPOSITION               ((unsigned16) 0x002)   /* Node Position Address */
#define MOST_NB_FUNC_NODEADDRESS                ((unsigned16) 0x003)   /* Node Address */
#define MOST_NB_FUNC_GROUPADDRESS               ((unsigned16) 0x004)   /* Group Address */
#define MOST_NB_FUNC_ABILITYTOWAKE              ((unsigned16) 0x005)   /* Ability To Wake */
#define MOST_NB_FUNC_SHUTDOWN                   ((unsigned16) 0x006)   /* Shut Down */
#define MOST_NB_FUNC_RETRYPARAMETERS            ((unsigned16) 0x007)   /* Retry Parameters */
#define MOST_NB_FUNC_SAMPLINGFREQUENCY          ((unsigned16) 0x008)   /* Sampling Frequency */
#define MOST_NB_FUNC_SOURCEHANDLES              ((unsigned16) 0x100)   /* Source Handles */
#define MOST_NB_FUNC_NOTIFICATION               ((unsigned16) 0x401)   /* Notification */
#define MOST_NB_FUNC_NOTIFICATIONCHECK          ((unsigned16) 0x402)   /* NotificationCheck */
#define MOST_NB_FUNC_RBD_DOWNSTREAM             ((unsigned16) 0xC02)   /* JLR RBD Downstream */
/*------------------------------------------------------------------- */

/*------------------------------------------------------------------- */
/* mandatory FunctionIDs  */
/*------------------------------------------------------------------- */
#define MOST_FUNC_FUNCID                        ((unsigned16) 0x000)        /* FunctionIds */
#define MOST_FUNC_NOTIF                         ((unsigned16) 0x001)        /* Notification */
#define MOST_FUNC_NOTIF_CHECK                   ((unsigned16) 0x002)        /* Notification Check */

/*------------------------------------------------------------------- */
/* FunctionIDs of FBlock NetworkMaster FBlock and shadow              */
/*------------------------------------------------------------------- */
#define MOST_NM_FUNC_CONFIG                     ((unsigned16) 0xA00)        /* Configuration */
#define MOST_NM_FUNC_CENT_REG                   ((unsigned16) 0xA01)        /* Central Registry */
#define MOST_NM_FUNC_SAVE_CONFIG                ((unsigned16) 0xA02)        /* Save Central registry as default */
#define MOST_NM_FUNC_BOUNDARY                   ((unsigned16) 0xA03)        /* async/sync boundary */


/*------------------------------------------------------------------- */
/* FunctionIDs of FBlock KombiMiscFunctions */
/*------------------------------------------------------------------- */
#define MOST_KOMBI_MISC_FUNC_FUNCID             ((unsigned16) 0x000)        /* FunctionIds */
#define MOST_KOMBI_MISC_FUNC_KM_INIDCATOR       ((unsigned16) 0x247)        /* Kilometer indicator */

/*------------------------------------------------------------------- */
/* FunctionIDs of FBlock vehicle (not complete) */
/*------------------------------------------------------------------- */
#define MOST_VEHICLE_FUNC_MILEAGE               ((unsigned16) 0x507)        /* mileage */

/*------------------------------------------------------------------- */
/* FunctionID of audio FBlocks (not complete) */
/*------------------------------------------------------------------- */
#define MOST_FUNC_ALLOCATION                    ((unsigned16) 0x101)        /* allocation */
/*
-------------------------------------------------------------------------------
 MOST Operation types
-------------------------------------------------------------------------------
*/

/* properties: */
#define MOST_OP_SET                             ((unsigned8) 0x0)
#define MOST_OP_GET                             ((unsigned8) 0x1)
#define MOST_OP_SETGET                          ((unsigned8) 0x2)
#define MOST_OP_INC                             ((unsigned8) 0x3)
#define MOST_OP_DEC                             ((unsigned8) 0x4)
#define MOST_OP_GETINTERFACE                    ((unsigned8) 0x5)

#define MOST_OP_STATUS                          ((unsigned8) 0xC)
#define MOST_OP_INTERFACE                       ((unsigned8) 0xE)
#define MOST_OP_ERROR                           ((unsigned8) 0xF)

/* methods: */
#define MOST_OP_START                           ((unsigned8) 0x0)
#define MOST_OP_ABORT                           ((unsigned8) 0x1)
#define MOST_OP_STARTRESULT                     ((unsigned8) 0x2)

#define MOST_OP_STARTRESULTACK                  ((unsigned8) 0x6)
#define MOST_OP_ABORTACK                        ((unsigned8) 0x7)
#define MOST_OP_STARTACK                        ((unsigned8) 0x8)

#define MOST_OP_ERRORACK                        ((unsigned8) 0x9)
#define MOST_OP_PROCESSINGACK                   ((unsigned8) 0xA)
#define MOST_OP_PROCESSING                      ((unsigned8) 0xB)
#define MOST_OP_RESULT                          ((unsigned8) 0xC)
#define MOST_OP_RESULTACK                       ((unsigned8) 0xD)

#define MOST_OP_REPORTS                         ((unsigned8) 0x9)   /* First OP_Type of a report msg */


#define MOST_OPTYPE_COMMAND(OpType)             ((unsigned8)OpType < MOST_OP_REPORTS)
#define MOST_OPTYPE_REPORT(OpType)              ((unsigned8)OpType >= MOST_OP_REPORTS)

/*------------------------------------------------- */
/* Parameters of Telegram FBlockID.Notification.Set */
/*------------------------------------------------- */
#define MOST_NTF_SET_ALL                        ((unsigned8)0x00) /* Set notification in all properties */
#define MOST_NTF_SET_FUNC                       ((unsigned8)0x01) /* Set notification in some (following) properties */
#define MOST_NTF_CLR_ALL                        ((unsigned8)0x02) /* Clear notification in all properties */
#define MOST_NTF_CLR_FUNC                       ((unsigned8)0x03) /* Clear notification in some (following) properties */

/*------------------------------------------------------------------- */
/* Parameters for NWM.Configuration.Status() */
/*------------------------------------------------------------------- */
#define MOST_CFG_STATUS_NOTOK                   ((unsigned8)0x00)
#define MOST_CFG_STATUS_OK                      ((unsigned8)0x01)
#define MOST_CFG_STATUS_INVALID                 ((unsigned8)0x02)
#define MOST_CFG_STATUS_NEW                     ((unsigned8)0x03)

/*
-------------------------------------------------------------------------------
 MOST Ability To Wake codes
-------------------------------------------------------------------------------
*/
#define MOST_ABILITY_TO_WAKE_OFF                ((unsigned8)0x00)
#define MOST_ABILITY_TO_WAKE_ON                 ((unsigned8)0x01)
#define MOST_ABILITY_TO_WAKE_CRITICAL           ((unsigned8)0x02)

/*
-------------------------------------------------------------------------------
 MOST Error codes
-------------------------------------------------------------------------------
*/

#define MOST_ERR_FBLOCKID                       ((unsigned8) 0x01)   /* FBlockID not available */
#define MOST_ERR_INSTID                         ((unsigned8) 0x02)   /* InstID not available */
#define MOST_ERR_FKTID                          ((unsigned8) 0x03)   /* FktID not available */
#define MOST_ERR_OPTYPE                         ((unsigned8) 0x04)   /* OPType not available */
#define MOST_ERR_LENGTH                         ((unsigned8) 0x05)   /* Invalid length */

#define MOST_ERR_PARAM_WRONG                    ((unsigned8) 0x06)   /* Param wrong/out of range */
#define MOST_ERR_PARAM_NOTAVAILABLE             ((unsigned8) 0x07)   /* Parameter not available */
#define MOST_ERR_PARAM_MISSING                  ((unsigned8) 0x08)   /* Parameter missing */
#define MOST_ERR_PARAM_TOOMANY                  ((unsigned8) 0x09)   /* too many parameters */

#define MOST_ERR_SECONDARY_NODE                 ((unsigned8) 0x0A)   /* Secondary Node */
#define MOST_ERR_DEVICE_MALFUNC                 ((unsigned8) 0x0B)   /* Device Malfunction */
#define MOST_ERR_SEGMENTATION                   ((unsigned8) 0x0C)   /* Segmentation Error */

#define MOST_ERR_FUNC_SPECIFIC                  ((unsigned8) 0x20)   /* Function specific error */
#define MOST_ERR_BUSY                           ((unsigned8) 0x40)   /* Function busy */
#define MOST_ERR_NOTAVAILABLE                   ((unsigned8) 0x41)   /* Function not available */
#define MOST_ERR_PROCESSING                     ((unsigned8) 0x42)   /* processing a method */
#define MOST_ERR_METHOD_ABORTED                 ((unsigned8) 0x43)   /* Method aborted */

/*
-------------------------------------------------------------------------------
 MOST NetBlock shutdown parameters
-------------------------------------------------------------------------------
*/
#define MOST_NB_SHUTDOWN_SUSPEND_QUERY          ((unsigned8)0)
#define MOST_NB_SHUTDOWN_SUSPEND_SUSPEND        ((unsigned8)1)
#define MOST_NB_SHUTDOWN_SUSPEND_EXECUTE        ((unsigned8)2)
#define MOST_NB_SHUTDOWN_SUSPEND_TEMPERATURE    ((unsigned8)3)

/*
-------------------------------------------------------------------------------
 MOST FOT temperature staus
-------------------------------------------------------------------------------
*/
#define FOT_TEMP_OK                             ((unsigned8)0)
#define FOT_TEMP_HEATING                        ((unsigned8)1)
#define FOT_TEMP_COOLING                        ((unsigned8)2)
#define FOT_OVER_TEMPERATURE                    ((unsigned8)3)

/*
-------------------------------------------------------------------------------
 Legal Disclaimer Status
-------------------------------------------------------------------------------
*/
#define LEGAL_DISCLAIMER_STAUS_UNCONFIRMED      ((unsigned8)0)
#define LEGAL_DISCLAIMER_STAUS_CONFIRMED        ((unsigned8)1)

#endif  /* MOST_DEFS_H */
