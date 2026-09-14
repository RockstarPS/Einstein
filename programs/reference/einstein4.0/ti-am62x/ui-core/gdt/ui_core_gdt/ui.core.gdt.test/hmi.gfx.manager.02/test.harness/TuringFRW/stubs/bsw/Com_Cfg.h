/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2012 - 2016 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: Visteon Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Spansion Traveo S6J32BALSB
 *    License Scope : The usage is restricted to CBD1400814_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Cfg.h
 *   Generation Time: 2016-01-05 11:43:47
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1400814_D02
 *      Tool Version: DaVinci Configurator (beta) 5.10.16 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


#if !defined (COM_CFG_H)
# define COM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Types.h"
//# include "Com_Lcfg.h"
//# include "Com_PBcfg.h"
//# include "Com_Cbk.h"
//# include "PduR_Cfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

#ifndef COM_USE_DUMMY_FUNCTIONS
#define COM_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef COM_USE_DUMMY_STATEMENT
#define COM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef COM_DUMMY_STATEMENT
#define COM_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT_CONST
#define COM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef COM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define COM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef COM_ATOMIC_VARIABLE_ACCESS
#define COM_ATOMIC_VARIABLE_ACCESS 16U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef COM_PROCESSOR_S6J324CXS
#define COM_PROCESSOR_S6J324CXS
#endif
#ifndef COM_COMP_GREENHILLS
#define COM_COMP_GREENHILLS
#endif
#ifndef COM_GEN_GENERATOR_MSR
#define COM_GEN_GENERATOR_MSR
#endif
#ifndef COM_CPUTYPE_BITORDER_LSB2MSB
#define COM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef COM_CONFIGURATION_VARIANT_PRECOMPILE
#define COM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef COM_CONFIGURATION_VARIANT_LINKTIME
#define COM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef COM_CONFIGURATION_VARIANT
#define COM_CONFIGURATION_VARIANT COM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef COM_POSTBUILD_VARIANT_SUPPORT
#define COM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE-COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PCDataSwitches  Data Switches  (PRE-COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COM_ALLSIGCNT                                                 STD_ON
#define COM_ALLSIGGRPCNT                                              STD_ON
#define COM_CBKINVFUNCPTR                                             STD_OFF  /**< Deactivateable: 'Com_CbkInvFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_CBKRXACKFUNCPTR                                           STD_ON
#define COM_CBKRXTOUTFUNCPTR                                          STD_ON
#define COM_CBKTXACKDEFFUNCPTR                                        STD_OFF  /**< Deactivateable: 'Com_CbkTxAckDefFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_CBKTXACKIMFUNCPTR                                         STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_CBKTXERRFUNCPTR                                           STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_CBKTXTOUTFUNCPTR                                          STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_CONFIGID                                                  STD_ON
#define COM_CONSTVALUEXINT16                                          STD_ON
#define COM_CONSTVALUEXINT32                                          STD_OFF  /**< Deactivateable: 'Com_ConstValueXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_CONSTVALUEXINT8                                           STD_ON
#define COM_CURRENTTXMODE                                             STD_ON
#define COM_CYCLETIMECNT                                              STD_ON
#define COM_CYCLICSENDREQUEST                                         STD_ON
#define COM_DELAYTIMECNT                                              STD_OFF  /**< Deactivateable: 'Com_DelayTimeCnt' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_FILTERINFO                                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define COM_APPLTYPEOFFILTERINFO                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo.ApplType' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_FILTERALGOOFFILTERINFO                                    STD_OFF  /**< Deactivateable: 'Com_FilterInfo.FilterAlgo' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_FILTERPARAMIDXOFFILTERINFO                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo.FilterParamIdx' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_FILTERPARAMUSEDOFFILTERINFO                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo.FilterParamUsed' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_LENGTHOFFILTERINFO                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo.Length' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_FINALMAGICNUMBER                                          STD_OFF  /**< Deactivateable: 'Com_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GWEVENT                                                   STD_OFF  /**< Deactivateable: 'Com_GwEvent' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPING                                           STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWGRPSIGMAPPING                          STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGIDOFGWGRPSIGMAPPING                                  STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define COM_GWINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwInfo' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGENDIDXOFGWINFO                             STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGSTARTIDXOFGWINFO                           STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGUSEDOFGWINFO                               STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGENDIDXOFGWINFO                                STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGSTARTIDXOFGWINFO                              STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGUSEDOFGWINFO                                  STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPING                                           STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGENDIDXOFGWSIGGRPMAPPING                    STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGSTARTIDXOFGWSIGGRPMAPPING                  STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGGRPIDOFGWSIGGRPMAPPING                               STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.TxSigGrpId' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPING                                              STD_OFF  /**< Deactivateable: 'Com_GwSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWSIGMAPPING                             STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGIDOFGWSIGMAPPING                                     STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define COM_HANDLERXPDUDEFERRED                                       STD_ON
#define COM_HANDLETXPDUDEFERRED                                       STD_ON
#define COM_IPDUGROUPINFO                                             STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO      STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO    STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO        STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_INVALIDHNDOFIPDUGROUPINFO                                 STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.InvalidHnd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                         STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                       STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_RXPDUINFOINDUSEDOFIPDUGROUPINFO                           STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                         STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                       STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_TXPDUINFOINDUSEDOFIPDUGROUPINFO                           STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOOFRXPDUINFOIND                               STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfoOfRxPduInfoInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOOFTXPDUINFOIND                               STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfoOfTxPduInfoInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSIND                           STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfoToSubIPduGroupsInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPSTATE                                            STD_OFF  /**< Deactivateable: 'Com_IPduGroupState' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_INITDATAHASHCODE                                          STD_OFF  /**< Deactivateable: 'Com_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZED                                               STD_ON
#define COM_PDUGRPCNT                                                 STD_ON
#define COM_PDUGRPVECTOR                                              STD_ON
#define COM_REPCNT                                                    STD_ON
#define COM_REPCYCLECNT                                               STD_ON
#define COM_RXACCESSINFO                                              STD_ON
#define COM_APPLTYPEOFRXACCESSINFO                                    STD_ON
#define COM_BITLENGTHOFRXACCESSINFO                                   STD_ON
#define COM_BITPOSITIONOFRXACCESSINFO                                 STD_ON
#define COM_BUFFERIDXOFRXACCESSINFO                                   STD_ON
#define COM_BUFFERUSEDOFRXACCESSINFO                                  STD_ON
#define COM_BUSACCOFRXACCESSINFO                                      STD_ON
#define COM_BYTELENGTHOFRXACCESSINFO                                  STD_ON
#define COM_BYTEPOSITIONOFRXACCESSINFO                                STD_ON
#define COM_GWINFOIDXOFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INITVALUEIDXOFRXACCESSINFO                                STD_ON
#define COM_INITVALUEUSEDOFRXACCESSINFO                               STD_ON
#define COM_INVALIDHNDOFRXACCESSINFO                                  STD_ON
#define COM_PDUIDOFRXACCESSINFO                                       STD_ON
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO           STD_ON
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO          STD_ON
#define COM_SHDBUFFERIDXOFRXACCESSINFO                                STD_ON
#define COM_SHDBUFFERUSEDOFRXACCESSINFO                               STD_ON
#define COM_SIGNEXTREQUIREDOFRXACCESSINFO                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.SignExtRequired' Reason: 'the value of Com_SignExtRequiredOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_RXACCESSINFOIND                                           STD_ON
#define COM_RXACCESSINFOREPLACEGRPSIGIND                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceGrpSigInd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_RXACCESSINFOREPLACESIGIND                                 STD_ON
#define COM_RXDEFPDUBUFFER                                            STD_ON
#define COM_RXDYNSIGNALLENGTH                                         STD_OFF  /**< Deactivateable: 'Com_RxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXDYNSIGNALTMPLENGTHFORSIGNALGROUPS                       STD_OFF  /**< Deactivateable: 'Com_RxDynSignalTmpLengthForSignalGroups' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXGRPSIGINFO                                              STD_ON
#define COM_FILTERINFOIDXOFRXGRPSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_RxGrpSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxGrpSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_FILTERINFOUSEDOFRXGRPSIGINFO                              STD_OFF  /**< Deactivateable: 'Com_RxGrpSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxGrpSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_INVVALUEIDXOFRXGRPSIGINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxGrpSigInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxGrpSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_INVVALUEUSEDOFRXGRPSIGINFO                                STD_OFF  /**< Deactivateable: 'Com_RxGrpSigInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxGrpSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXACCESSINFOIDXOFRXGRPSIGINFO                             STD_ON
#define COM_TMPBUFFERIDXOFRXGRPSIGINFO                                STD_ON
#define COM_TMPBUFFERUSEDOFRXGRPSIGINFO                               STD_ON
#define COM_RXPDUCALLOUTFUNCPTR                                       STD_OFF  /**< Deactivateable: 'Com_RxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_RXPDUDMSTATE                                              STD_ON
#define COM_RXPDUGRPACTIVE                                            STD_ON
#define COM_RXPDUGRPINFO                                              STD_ON
#define COM_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                          STD_ON
#define COM_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                        STD_ON
#define COM_PDUGRPVECTORUSEDOFRXPDUGRPINFO                            STD_ON
#define COM_RXPDUINFO                                                 STD_ON
#define COM_GWINFOENDIDXOFRXPDUINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOSTARTIDXOFRXPDUINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXPDUINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                         STD_ON
#define COM_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                        STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO              STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndEndIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO            STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndStartIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndUsed' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_INVALIDHNDOFRXPDUINFO                                     STD_ON
#define COM_RXACCESSINFOINDENDIDXOFRXPDUINFO                          STD_ON
#define COM_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                        STD_ON
#define COM_RXACCESSINFOINDUSEDOFRXPDUINFO                            STD_ON
#define COM_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                           STD_ON
#define COM_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                           STD_ON
#define COM_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                         STD_ON
#define COM_RXDEFPDUBUFFERUSEDOFRXPDUINFO                             STD_ON
#define COM_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXPDUCALLOUTFUNCPTRUSEDOFRXPDUINFO                        STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                          STD_ON
#define COM_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                        STD_ON
#define COM_RXSIGGRPINFOINDUSEDOFRXPDUINFO                            STD_ON
#define COM_RXSIGINFOENDIDXOFRXPDUINFO                                STD_ON
#define COM_RXSIGINFOSTARTIDXOFRXPDUINFO                              STD_ON
#define COM_RXSIGINFOUSEDOFRXPDUINFO                                  STD_ON
#define COM_RXTOUTINFOIDXOFRXPDUINFO                                  STD_ON
#define COM_RXTOUTINFOINDENDIDXOFRXPDUINFO                            STD_ON
#define COM_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                          STD_ON
#define COM_RXTOUTINFOINDUSEDOFRXPDUINFO                              STD_ON
#define COM_RXTOUTINFOUSEDOFRXPDUINFO                                 STD_ON
#define COM_RXTPINFOIDXOFRXPDUINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFOUSEDOFRXPDUINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXPDUINFOIND                                              STD_OFF  /**< Deactivateable: 'Com_RxPduInfoInd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_RXSHDBUFFERXINT16                                         STD_ON
#define COM_RXSHDBUFFERXINT32                                         STD_OFF  /**< Deactivateable: 'Com_RxShdBufferXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_RXSHDBUFFERXINT8                                          STD_ON
#define COM_RXSIGBUFFERXINT16                                         STD_ON
#define COM_RXSIGBUFFERXINT32                                         STD_OFF  /**< Deactivateable: 'Com_RxSigBufferXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_RXSIGBUFFERXINT8                                          STD_ON
#define COM_RXSIGGRPINFO                                              STD_ON
#define COM_ARRAYACCESSUSEDOFRXSIGGRPINFO                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ArrayAccessUsed' Reason: 'the value of Com_ArrayAccessUsedOfRxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define COM_CBKINVFUNCPTRIDXOFRXSIGGRPINFO                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.CbkInvFuncPtrIdx' Reason: 'the optional indirection is deactivated because CbkInvFuncPtrUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKINVFUNCPTRUSEDOFRXSIGGRPINFO                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.CbkInvFuncPtrUsed' Reason: 'the optional indirection is deactivated because CbkInvFuncPtrUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKRXACKFUNCPTRIDXOFRXSIGGRPINFO                          STD_ON
#define COM_CBKRXACKFUNCPTRUSEDOFRXSIGGRPINFO                         STD_ON
#define COM_CONSTVALUEXINT8ENDIDXOFRXSIGGRPINFO                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueXInt8EndIdx' Reason: 'the optional indirection is deactivated because ConstValueXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CONSTVALUEXINT8LENGTHOFRXSIGGRPINFO                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueXInt8Length' Reason: 'the optional indirection is deactivated because ConstValueXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CONSTVALUEXINT8STARTIDXOFRXSIGGRPINFO                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueXInt8StartIdx' Reason: 'the optional indirection is deactivated because ConstValueXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CONSTVALUEXINT8USEDOFRXSIGGRPINFO                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueXInt8Used' Reason: 'the optional indirection is deactivated because ConstValueXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_FILTEREVENTOFRXSIGGRPINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.FilterEvent' Reason: 'the value of Com_FilterEventOfRxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define COM_GWINFOIDXOFRXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INVEVENTOFRXSIGGRPINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.InvEvent' Reason: 'the value of Com_InvEventOfRxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define COM_INVALIDHNDOFRXSIGGRPINFO                                  STD_ON
#define COM_RXGRPSIGINFOENDIDXOFRXSIGGRPINFO                          STD_ON
#define COM_RXGRPSIGINFOSTARTIDXOFRXSIGGRPINFO                        STD_ON
#define COM_RXPDUINFOIDXOFRXSIGGRPINFO                                STD_ON
#define COM_RXPDUINFOUSEDOFRXSIGGRPINFO                               STD_ON
#define COM_RXSHDBUFFERXINT8ENDIDXOFRXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxShdBufferXInt8EndIdx' Reason: 'the optional indirection is deactivated because RxShdBufferXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXSHDBUFFERXINT8LENGTHOFRXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxShdBufferXInt8Length' Reason: 'the optional indirection is deactivated because RxShdBufferXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXSHDBUFFERXINT8STARTIDXOFRXSIGGRPINFO                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxShdBufferXInt8StartIdx' Reason: 'the optional indirection is deactivated because RxShdBufferXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXSHDBUFFERXINT8USEDOFRXSIGGRPINFO                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxShdBufferXInt8Used' Reason: 'the optional indirection is deactivated because RxShdBufferXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXSIGGRPINFO                               STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXTOUTINFOUSEDOFRXSIGGRPINFO                              STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_SIGNALPROCESSINGOFRXSIGGRPINFO                            STD_ON
#define COM_STARTBYTEPOSITIONOFRXSIGGRPINFO                           STD_ON
#define COM_UBIDXOFRXSIGGRPINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbIdx' Reason: 'the value of Com_UbIdxOfRxSigGrpInfo is always 'COM_NO_UBIDXOFRXSIGGRPINFO' due to this, the array is deactivated.' */
#define COM_UBMASKIDXOFRXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_UBMASKUSEDOFRXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_VALIDDLCOFRXSIGGRPINFO                                    STD_ON
#define COM_RXSIGGRPINFOIND                                           STD_ON
#define COM_RXSIGINFO                                                 STD_ON
#define COM_CBKINVFUNCPTRIDXOFRXSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.CbkInvFuncPtrIdx' Reason: 'the optional indirection is deactivated because CbkInvFuncPtrUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKINVFUNCPTRUSEDOFRXSIGINFO                              STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.CbkInvFuncPtrUsed' Reason: 'the optional indirection is deactivated because CbkInvFuncPtrUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKRXACKFUNCPTRIDXOFRXSIGINFO                             STD_ON
#define COM_CBKRXACKFUNCPTRUSEDOFRXSIGINFO                            STD_ON
#define COM_FILTERINFOIDXOFRXSIGINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_FILTERINFOUSEDOFRXSIGINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_GWINFOIDXOFRXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INVVALUEIDXOFRXSIGINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_INVVALUEUSEDOFRXSIGINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXACCESSINFOIDXOFRXSIGINFO                                STD_ON
#define COM_RXTOUTINFOIDXOFRXSIGINFO                                  STD_ON
#define COM_RXTOUTINFOUSEDOFRXSIGINFO                                 STD_ON
#define COM_SIGNALPROCESSINGOFRXSIGINFO                               STD_ON
#define COM_UBIDXOFRXSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbIdx' Reason: 'the value of Com_UbIdxOfRxSigInfo is always 'COM_NO_UBIDXOFRXSIGINFO' due to this, the array is deactivated.' */
#define COM_UBMASKIDXOFRXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_UBMASKUSEDOFRXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_VALIDDLCOFRXSIGINFO                                       STD_ON
#define COM_RXTOUTCNT                                                 STD_ON
#define COM_RXTOUTINFO                                                STD_ON
#define COM_CBKRXTOUTFUNCPTRENDIDXOFRXTOUTINFO                        STD_ON
#define COM_CBKRXTOUTFUNCPTRSTARTIDXOFRXTOUTINFO                      STD_ON
#define COM_CBKRXTOUTFUNCPTRUSEDOFRXTOUTINFO                          STD_ON
#define COM_FACTOROFRXTOUTINFO                                        STD_ON
#define COM_FIRSTFACTOROFRXTOUTINFO                                   STD_ON
#define COM_RXACCESSINFOREPLACEGRPSIGINDENDIDXOFRXTOUTINFO            STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndEndIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDSTARTIDXOFRXTOUTINFO          STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndStartIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDUSEDOFRXTOUTINFO              STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndUsed' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_RXACCESSINFOREPLACESIGINDENDIDXOFRXTOUTINFO               STD_ON
#define COM_RXACCESSINFOREPLACESIGINDSTARTIDXOFRXTOUTINFO             STD_ON
#define COM_RXACCESSINFOREPLACESIGINDUSEDOFRXTOUTINFO                 STD_ON
#define COM_RXPDUINFOIDXOFRXTOUTINFO                                  STD_ON
#define COM_RXTOUTINFOIND                                             STD_ON
#define COM_RXTPBUFFER                                                STD_OFF  /**< Deactivateable: 'Com_RxTpBuffer' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPCONNECTIONSTATE                                       STD_OFF  /**< Deactivateable: 'Com_RxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_RxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFRXTPINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGIDXOFRXTPINFO                           STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGUSEDOFRXTPINFO                          STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERENDIDXOFRXTPINFO                                STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERSTARTIDXOFRXTPINFO                              STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERUSEDOFRXTPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPSDULENGTH                                             STD_OFF  /**< Deactivateable: 'Com_RxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPWRITTENBYTESCOUNTER                                   STD_OFF  /**< Deactivateable: 'Com_RxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGGRPEVENTFLAG                                           STD_ON
#define COM_SIZEOFCBKRXACKFUNCPTR                                     STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTR                                    STD_ON
#define COM_SIZEOFCONSTVALUEXINT16                                    STD_ON
#define COM_SIZEOFCONSTVALUEXINT8                                     STD_ON
#define COM_SIZEOFCURRENTTXMODE                                       STD_ON
#define COM_SIZEOFCYCLETIMECNT                                        STD_ON
#define COM_SIZEOFCYCLICSENDREQUEST                                   STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERRED                                 STD_ON
#define COM_SIZEOFHANDLETXPDUDEFERRED                                 STD_ON
#define COM_SIZEOFPDUGRPVECTOR                                        STD_ON
#define COM_SIZEOFREPCNT                                              STD_ON
#define COM_SIZEOFREPCYCLECNT                                         STD_ON
#define COM_SIZEOFRXACCESSINFO                                        STD_ON
#define COM_SIZEOFRXACCESSINFOIND                                     STD_ON
#define COM_SIZEOFRXACCESSINFOREPLACESIGIND                           STD_ON
#define COM_SIZEOFRXDEFPDUBUFFER                                      STD_ON
#define COM_SIZEOFRXGRPSIGINFO                                        STD_ON
#define COM_SIZEOFRXPDUDMSTATE                                        STD_ON
#define COM_SIZEOFRXPDUGRPACTIVE                                      STD_ON
#define COM_SIZEOFRXPDUGRPINFO                                        STD_ON
#define COM_SIZEOFRXPDUINFO                                           STD_ON
#define COM_SIZEOFRXSHDBUFFERXINT16                                   STD_ON
#define COM_SIZEOFRXSHDBUFFERXINT8                                    STD_ON
#define COM_SIZEOFRXSIGBUFFERXINT16                                   STD_ON
#define COM_SIZEOFRXSIGBUFFERXINT8                                    STD_ON
#define COM_SIZEOFRXSIGGRPINFO                                        STD_ON
#define COM_SIZEOFRXSIGGRPINFOIND                                     STD_ON
#define COM_SIZEOFRXSIGINFO                                           STD_ON
#define COM_SIZEOFRXTOUTCNT                                           STD_ON
#define COM_SIZEOFRXTOUTINFO                                          STD_ON
#define COM_SIZEOFRXTOUTINFOIND                                       STD_ON
#define COM_SIZEOFSIGGRPEVENTFLAG                                     STD_ON
#define COM_SIZEOFTMPRXBUFFER                                         STD_ON
#define COM_SIZEOFTMPRXSHDBUFFERXINT16                                STD_ON
#define COM_SIZEOFTMPRXSHDBUFFERXINT8                                 STD_ON
#define COM_SIZEOFTRANSMITREQUEST                                     STD_ON
#define COM_SIZEOFTXMODEINFO                                          STD_ON
#define COM_SIZEOFTXMODETRUE                                          STD_ON
#define COM_SIZEOFTXPDUBUFFER                                         STD_ON
#define COM_SIZEOFTXPDUGRPACTIVE                                      STD_ON
#define COM_SIZEOFTXPDUGRPINFO                                        STD_ON
#define COM_SIZEOFTXPDUINFO                                           STD_ON
#define COM_SIZEOFTXPDUINITVALUE                                      STD_ON
#define COM_SIZEOFTXSDULENGTH                                         STD_ON
#define COM_SIZEOFTXSHDBUFFER                                         STD_ON
#define COM_SIZEOFTXSIGGRPINFO                                        STD_ON
#define COM_SIZEOFTXSIGGRPINFOIND                                     STD_ON
#define COM_SIZEOFTXSIGGRPMASK                                        STD_ON
#define COM_SIZEOFTXSIGINFO                                           STD_ON
#define COM_SIZEOFWAITINGFORCONFIRMATION                              STD_ON
#define COM_TMPRXBUFFER                                               STD_ON
#define COM_TMPRXSHDBUFFERXINT16                                      STD_ON
#define COM_TMPRXSHDBUFFERXINT32                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TMPRXSHDBUFFERXINT8                                       STD_ON
#define COM_TRANSMITREQUEST                                           STD_ON
#define COM_TXDYNSIGNALLENGTH                                         STD_OFF  /**< Deactivateable: 'Com_TxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXFILTERINITSTATE                                         STD_OFF  /**< Deactivateable: 'Com_TxFilterInitState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXFILTERINITVALUEXINT16                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueXInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXFILTERINITVALUEXINT32                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXFILTERINITVALUEXINT8                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueXInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXFILTEROLDVALUEXINT16                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueXInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXFILTEROLDVALUEXINT32                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXFILTEROLDVALUEXINT8                                     STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueXInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXFILTERSTATE                                             STD_OFF  /**< Deactivateable: 'Com_TxFilterState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXMODEFALSE                                               STD_OFF  /**< Deactivateable: 'Com_TxModeFalse' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define COM_DIRECTOFTXMODEFALSE                                       STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.Direct' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_PERIODICOFTXMODEFALSE                                     STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.Periodic' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_REPCNTOFTXMODEFALSE                                       STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepCnt' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_REPPERIODOFTXMODEFALSE                                    STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepPeriod' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TIMEOFFSETOFTXMODEFALSE                                   STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.TimeOffset' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TIMEPERIODOFTXMODEFALSE                                   STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.TimePeriod' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXMODEINFO                                                STD_ON
#define COM_INITMODEOFTXMODEINFO                                      STD_ON
#define COM_INVALIDHNDOFTXMODEINFO                                    STD_ON
#define COM_MINIMUMDELAYOFTXMODEINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.MinimumDelay' Reason: 'the value of Com_MinimumDelayOfTxModeInfo is always '0' due to this, the array is deactivated.' */
#define COM_TXFILTERINITSTATEENDIDXOFTXMODEINFO                       STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXMODEINFO                     STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXMODEINFO                         STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXMODEFALSEIDXOFTXMODEINFO                                STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxModeFalseIdx' Reason: 'the optional indirection is deactivated because TxModeFalseUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXMODEFALSEUSEDOFTXMODEINFO                               STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxModeFalseUsed' Reason: 'the optional indirection is deactivated because TxModeFalseUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXMODETRUEIDXOFTXMODEINFO                                 STD_ON
#define COM_TXMODETRUEUSEDOFTXMODEINFO                                STD_ON
#define COM_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO             STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO           STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO               STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndUsed' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXMODETRUE                                                STD_ON
#define COM_DIRECTOFTXMODETRUE                                        STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.Direct' Reason: 'the value of Com_DirectOfTxModeTrue is always 'false' due to this, the array is deactivated.' */
#define COM_PERIODICOFTXMODETRUE                                      STD_ON
#define COM_REPCNTOFTXMODETRUE                                        STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.RepCnt' Reason: 'the value of Com_RepCntOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define COM_REPPERIODOFTXMODETRUE                                     STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define COM_TIMEOFFSETOFTXMODETRUE                                    STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeTrue is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODETRUE                                    STD_ON
#define COM_TXPDUBUFFER                                               STD_ON
#define COM_TXPDUCALLOUTFUNCPTR                                       STD_OFF  /**< Deactivateable: 'Com_TxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXPDUGRPACTIVE                                            STD_ON
#define COM_TXPDUGRPINFO                                              STD_ON
#define COM_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                          STD_ON
#define COM_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                        STD_ON
#define COM_PDUGRPVECTORUSEDOFTXPDUGRPINFO                            STD_ON
#define COM_TXPDUINFO                                                 STD_ON
#define COM_CANCELLATIONSUPPORTOFTXPDUINFO                            STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CancellationSupport' Reason: 'the value of Com_CancellationSupportOfTxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_CBKTXACKDEFFUNCPTRENDIDXOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKTXACKDEFFUNCPTRSTARTIDXOFTXPDUINFO                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKTXACKDEFFUNCPTRUSEDOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrUsed' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRENDIDXOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRSTARTIDXOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRUSEDOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrUsed' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKTXERRFUNCPTRENDIDXOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrEndIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKTXERRFUNCPTRSTARTIDXOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrStartIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CBKTXERRFUNCPTRUSEDOFTXPDUINFO                            STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrUsed' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CLRUBOFTXPDUINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_CONSTVALUEXINT8UBCLEARMASKENDIDXOFTXPDUINFO               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueXInt8UbClearMaskEndIdx' Reason: 'the optional indirection is deactivated because ConstValueXInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CONSTVALUEXINT8UBCLEARMASKSTARTIDXOFTXPDUINFO             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueXInt8UbClearMaskStartIdx' Reason: 'the optional indirection is deactivated because ConstValueXInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_CONSTVALUEXINT8UBCLEARMASKUSEDOFTXPDUINFO                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueXInt8UbClearMaskUsed' Reason: 'the optional indirection is deactivated because ConstValueXInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_EXTERNALIDOFTXPDUINFO                                     STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO              STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndEndIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO            STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndStartIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndUsed' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_INVALIDHNDOFTXPDUINFO                                     STD_ON
#define COM_METADATALENGTHOFTXPDUINFO                                 STD_ON
#define COM_PDUWITHMETADATALENGTHOFTXPDUINFO                          STD_ON
#define COM_TXPDUBUFFERENDIDXOFTXPDUINFO                              STD_ON
#define COM_TXPDUBUFFERLENGTHOFTXPDUINFO                              STD_ON
#define COM_TXPDUBUFFERMETADATAENDIDXOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduBufferMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUBUFFERMETADATASTARTIDXOFTXPDUINFO                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduBufferMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUBUFFERMETADATAUSEDOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduBufferMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUBUFFERSTARTIDXOFTXPDUINFO                            STD_ON
#define COM_TXPDUBUFFERUSEDOFTXPDUINFO                                STD_ON
#define COM_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXPDUCALLOUTFUNCPTRUSEDOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXPDUINITVALUEENDIDXOFTXPDUINFO                           STD_ON
#define COM_TXPDUINITVALUEMETADATAENDIDXOFTXPDUINFO                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATASTARTIDXOFTXPDUINFO                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATAUSEDOFTXPDUINFO                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUESTARTIDXOFTXPDUINFO                         STD_ON
#define COM_TXPDUINITVALUEUSEDOFTXPDUINFO                             STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXPDUTTCALLOUTFUNCPTRUSEDOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                          STD_ON
#define COM_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                        STD_ON
#define COM_TXSIGGRPINFOINDUSEDOFTXPDUINFO                            STD_ON
#define COM_TXTOUTINFOIDXOFTXPDUINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXTOUTINFOUSEDOFTXPDUINFO                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXTPINFOIDXOFTXPDUINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFOUSEDOFTXPDUINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXPDUINFOIND                                              STD_OFF  /**< Deactivateable: 'Com_TxPduInfoInd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXPDUINITVALUE                                            STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTR                                     STD_OFF  /**< Deactivateable: 'Com_TxPduTTCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXSDULENGTH                                               STD_ON
#define COM_TXSHDBUFFER                                               STD_ON
#define COM_TXSIGGRPINFO                                              STD_ON
#define COM_ARRAYACCESSUSEDOFTXSIGGRPINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.ArrayAccessUsed' Reason: 'the value of Com_ArrayAccessUsedOfTxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define COM_INVALIDHNDOFTXSIGGRPINFO                                  STD_ON
#define COM_PDUIDOFTXSIGGRPINFO                                       STD_ON
#define COM_PDUOFFSETOFTXSIGGRPINFO                                   STD_ON
#define COM_SIGGROUPONCHANGEOFFSETOFTXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGESTARTPOSITIONOFTXSIGGRPINFO               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPOFFSETOFTXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPSTARTPOSITIONOFTXSIGGRPINFO     STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TRANSFERPROPERTYOFTXSIGGRPINFO                            STD_ON
#define COM_TXSHDBUFFERENDIDXOFTXSIGGRPINFO                           STD_ON
#define COM_TXSHDBUFFERLENGTHOFTXSIGGRPINFO                           STD_ON
#define COM_TXSHDBUFFERSTARTIDXOFTXSIGGRPINFO                         STD_ON
#define COM_TXSHDBUFFERUSEDOFTXSIGGRPINFO                             STD_ON
#define COM_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                          STD_ON
#define COM_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                          STD_ON
#define COM_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                        STD_ON
#define COM_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                            STD_ON
#define COM_TXSIGGRPONCHANGEMASKONCHANGEENDIDXOFTXSIGGRPINFO          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGELENGTHOFTXSIGGRPINFO          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGESTARTIDXOFTXSIGGRPINFO        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEUSEDOFTXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPENDIDXOFTXSIGGRPINFO STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPLENGTHOFTXSIGGRPINFO STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPSTARTIDXOFTXSIGGRPINFO STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPUSEDOFTXSIGGRPINFO  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigInfoInvValueIndUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigInfoInvValueIndUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXSIGINFOINVVALUEINDUSEDOFTXSIGGRPINFO                    STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndUsed' Reason: 'the optional indirection is deactivated because TxSigInfoInvValueIndUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXTOUTINFOIDXOFTXSIGGRPINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXTOUTINFOUSEDOFTXSIGGRPINFO                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_UBIDXOFTXSIGGRPINFO                                       STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbIdx' Reason: 'the value of Com_UbIdxOfTxSigGrpInfo is always 'COM_NO_UBIDXOFTXSIGGRPINFO' due to this, the array is deactivated.' */
#define COM_UBMASKIDXOFTXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_UBMASKUSEDOFTXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXSIGGRPINFOIND                                           STD_ON
#define COM_TXSIGGRPMASK                                              STD_ON
#define COM_TXSIGGRPONCHANGEMASK                                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpOnChangeMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFO                                                 STD_ON
#define COM_APPLTYPEOFTXSIGINFO                                       STD_ON
#define COM_BITLENGTHOFTXSIGINFO                                      STD_ON
#define COM_BITPOSITIONOFTXSIGINFO                                    STD_ON
#define COM_BUSACCOFTXSIGINFO                                         STD_ON
#define COM_BYTELENGTHOFTXSIGINFO                                     STD_ON
#define COM_BYTEPOSITIONOFTXSIGINFO                                   STD_ON
#define COM_FILTERINFOIDXOFTXSIGINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_FILTERINFOUSEDOFTXSIGINFO                                 STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_FILTERINITVALUEIDXOFTXSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueIdx' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_FILTERINITVALUEUSEDOFTXSIGINFO                            STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueUsed' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_INVVALUEIDXOFTXSIGINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_INVVALUEUSEDOFTXSIGINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_INVALIDHNDOFTXSIGINFO                                     STD_ON
#define COM_ONCHANGEIDXOFTXSIGINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChangeIdx' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_ONCHANGEUSEDOFTXSIGINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChangeUsed' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_PDUIDOFTXSIGINFO                                          STD_ON
#define COM_TRIGGEREDOFTXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.Triggered' Reason: 'the value of Com_TriggeredOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXFILTERINITSTATEIDXOFTXSIGINFO                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGINFO                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXSIGGRPINFOIDXOFTXSIGINFO                                STD_ON
#define COM_TXSIGGRPINFOUSEDOFTXSIGINFO                               STD_ON
#define COM_TXTOUTINFOIDXOFTXSIGINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_TXTOUTINFOUSEDOFTXSIGINFO                                 STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_UBIDXOFTXSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbIdx' Reason: 'the value of Com_UbIdxOfTxSigInfo is always 'COM_NO_UBIDXOFTXSIGINFO' due to this, the array is deactivated.' */
#define COM_UBMASKIDXOFTXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_UBMASKUSEDOFTXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define COM_WITHOUTREPOFTXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.WithoutRep' Reason: 'the value of Com_WithoutRepOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXSIGINFOFILTERINITVALUEIND                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfoFilterInitValueInd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXSIGINFOINVVALUEIND                                      STD_OFF  /**< Deactivateable: 'Com_TxSigInfoInvValueInd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXTOUTCNT                                                 STD_OFF  /**< Deactivateable: 'Com_TxTOutCnt' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXTOUTINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define COM_CBKTXTOUTFUNCPTRENDIDXOFTXTOUTINFO                        STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrEndIdx' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_CBKTXTOUTFUNCPTRSTARTIDXOFTXTOUTINFO                      STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrStartIdx' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_CBKTXTOUTFUNCPTRUSEDOFTXTOUTINFO                          STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrUsed' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_FACTOROFTXTOUTINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Factor' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_NONEMODEOFTXTOUTINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.NoneMode' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXPDUINFOIDXOFTXTOUTINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.TxPduInfoIdx' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXPDUINFOUSEDOFTXTOUTINFO                                 STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.TxPduInfoUsed' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define COM_TXTMPTPPDULENGTH                                          STD_OFF  /**< Deactivateable: 'Com_TxTmpTpPduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPCONNECTIONSTATE                                       STD_OFF  /**< Deactivateable: 'Com_TxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_TxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFTXTPINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXPDUBUFFERENDIDXOFTXTPINFO                               STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxPduBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXPDUBUFFERLENGTHOFTXTPINFO                               STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxPduBufferLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXPDUBUFFERSTARTIDXOFTXTPINFO                             STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxPduBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXPDUBUFFERUSEDOFTXTPINFO                                 STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxPduBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXSIGINFODYNSIGIDXOFTXTPINFO                              STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXSIGINFODYNSIGUSEDOFTXTPINFO                             STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPSDULENGTH                                             STD_OFF  /**< Deactivateable: 'Com_TxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPWRITTENBYTESCOUNTER                                   STD_OFF  /**< Deactivateable: 'Com_TxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_WAITINGFORCONFIRMATION                                    STD_ON
#define COM_PCCONFIG                                                  STD_ON
#define COM_ALLSIGCNTOFPCCONFIG                                       STD_ON
#define COM_ALLSIGGRPCNTOFPCCONFIG                                    STD_ON
#define COM_CBKRXACKFUNCPTROFPCCONFIG                                 STD_ON
#define COM_CBKRXTOUTFUNCPTROFPCCONFIG                                STD_ON
#define COM_CONFIGIDOFPCCONFIG                                        STD_ON
#define COM_CONSTVALUEXINT16OFPCCONFIG                                STD_ON
#define COM_CONSTVALUEXINT8OFPCCONFIG                                 STD_ON
#define COM_CURRENTTXMODEOFPCCONFIG                                   STD_ON
#define COM_CYCLETIMECNTOFPCCONFIG                                    STD_ON
#define COM_CYCLICSENDREQUESTOFPCCONFIG                               STD_ON
#define COM_FINALMAGICNUMBEROFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Com_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_HANDLERXPDUDEFERREDOFPCCONFIG                             STD_ON
#define COM_HANDLETXPDUDEFERREDOFPCCONFIG                             STD_ON
#define COM_INITDATAHASHCODEOFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Com_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZEDOFPCCONFIG                                     STD_ON
#define COM_PDUGRPCNTOFPCCONFIG                                       STD_ON
#define COM_PDUGRPVECTOROFPCCONFIG                                    STD_ON
#define COM_REPCNTOFPCCONFIG                                          STD_ON
#define COM_REPCYCLECNTOFPCCONFIG                                     STD_ON
#define COM_RXACCESSINFOINDOFPCCONFIG                                 STD_ON
#define COM_RXACCESSINFOOFPCCONFIG                                    STD_ON
#define COM_RXACCESSINFOREPLACESIGINDOFPCCONFIG                       STD_ON
#define COM_RXDEFPDUBUFFEROFPCCONFIG                                  STD_ON
#define COM_RXGRPSIGINFOOFPCCONFIG                                    STD_ON
#define COM_RXPDUDMSTATEOFPCCONFIG                                    STD_ON
#define COM_RXPDUGRPACTIVEOFPCCONFIG                                  STD_ON
#define COM_RXPDUGRPINFOOFPCCONFIG                                    STD_ON
#define COM_RXPDUINFOOFPCCONFIG                                       STD_ON
#define COM_RXSHDBUFFERXINT16OFPCCONFIG                               STD_ON
#define COM_RXSHDBUFFERXINT8OFPCCONFIG                                STD_ON
#define COM_RXSIGBUFFERXINT16OFPCCONFIG                               STD_ON
#define COM_RXSIGBUFFERXINT8OFPCCONFIG                                STD_ON
#define COM_RXSIGGRPINFOINDOFPCCONFIG                                 STD_ON
#define COM_RXSIGGRPINFOOFPCCONFIG                                    STD_ON
#define COM_RXSIGINFOOFPCCONFIG                                       STD_ON
#define COM_RXTOUTCNTOFPCCONFIG                                       STD_ON
#define COM_RXTOUTINFOINDOFPCCONFIG                                   STD_ON
#define COM_RXTOUTINFOOFPCCONFIG                                      STD_ON
#define COM_SIGGRPEVENTFLAGOFPCCONFIG                                 STD_ON
#define COM_SIZEOFCBKRXACKFUNCPTROFPCCONFIG                           STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTROFPCCONFIG                          STD_ON
#define COM_SIZEOFCONSTVALUEXINT16OFPCCONFIG                          STD_ON
#define COM_SIZEOFCONSTVALUEXINT8OFPCCONFIG                           STD_ON
#define COM_SIZEOFCURRENTTXMODEOFPCCONFIG                             STD_ON
#define COM_SIZEOFCYCLETIMECNTOFPCCONFIG                              STD_ON
#define COM_SIZEOFCYCLICSENDREQUESTOFPCCONFIG                         STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERREDOFPCCONFIG                       STD_ON
#define COM_SIZEOFHANDLETXPDUDEFERREDOFPCCONFIG                       STD_ON
#define COM_SIZEOFPDUGRPVECTOROFPCCONFIG                              STD_ON
#define COM_SIZEOFREPCNTOFPCCONFIG                                    STD_ON
#define COM_SIZEOFREPCYCLECNTOFPCCONFIG                               STD_ON
#define COM_SIZEOFRXACCESSINFOINDOFPCCONFIG                           STD_ON
#define COM_SIZEOFRXACCESSINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXACCESSINFOREPLACESIGINDOFPCCONFIG                 STD_ON
#define COM_SIZEOFRXDEFPDUBUFFEROFPCCONFIG                            STD_ON
#define COM_SIZEOFRXGRPSIGINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXPDUDMSTATEOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_SIZEOFRXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFRXSHDBUFFERXINT16OFPCCONFIG                         STD_ON
#define COM_SIZEOFRXSHDBUFFERXINT8OFPCCONFIG                          STD_ON
#define COM_SIZEOFRXSIGBUFFERXINT16OFPCCONFIG                         STD_ON
#define COM_SIZEOFRXSIGBUFFERXINT8OFPCCONFIG                          STD_ON
#define COM_SIZEOFRXSIGGRPINFOINDOFPCCONFIG                           STD_ON
#define COM_SIZEOFRXSIGGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFRXTOUTCNTOFPCCONFIG                                 STD_ON
#define COM_SIZEOFRXTOUTINFOINDOFPCCONFIG                             STD_ON
#define COM_SIZEOFRXTOUTINFOOFPCCONFIG                                STD_ON
#define COM_SIZEOFSIGGRPEVENTFLAGOFPCCONFIG                           STD_ON
#define COM_SIZEOFTMPRXBUFFEROFPCCONFIG                               STD_ON
#define COM_SIZEOFTMPRXSHDBUFFERXINT16OFPCCONFIG                      STD_ON
#define COM_SIZEOFTMPRXSHDBUFFERXINT8OFPCCONFIG                       STD_ON
#define COM_SIZEOFTRANSMITREQUESTOFPCCONFIG                           STD_ON
#define COM_SIZEOFTXMODEINFOOFPCCONFIG                                STD_ON
#define COM_SIZEOFTXMODETRUEOFPCCONFIG                                STD_ON
#define COM_SIZEOFTXPDUBUFFEROFPCCONFIG                               STD_ON
#define COM_SIZEOFTXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_SIZEOFTXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFTXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFTXPDUINITVALUEOFPCCONFIG                            STD_ON
#define COM_SIZEOFTXSDULENGTHOFPCCONFIG                               STD_ON
#define COM_SIZEOFTXSHDBUFFEROFPCCONFIG                               STD_ON
#define COM_SIZEOFTXSIGGRPINFOINDOFPCCONFIG                           STD_ON
#define COM_SIZEOFTXSIGGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFTXSIGGRPMASKOFPCCONFIG                              STD_ON
#define COM_SIZEOFTXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFWAITINGFORCONFIRMATIONOFPCCONFIG                    STD_ON
#define COM_TMPRXBUFFEROFPCCONFIG                                     STD_ON
#define COM_TMPRXSHDBUFFERXINT16OFPCCONFIG                            STD_ON
#define COM_TMPRXSHDBUFFERXINT8OFPCCONFIG                             STD_ON
#define COM_TRANSMITREQUESTOFPCCONFIG                                 STD_ON
#define COM_TXMODEINFOOFPCCONFIG                                      STD_ON
#define COM_TXMODETRUEOFPCCONFIG                                      STD_ON
#define COM_TXPDUBUFFEROFPCCONFIG                                     STD_ON
#define COM_TXPDUGRPACTIVEOFPCCONFIG                                  STD_ON
#define COM_TXPDUGRPINFOOFPCCONFIG                                    STD_ON
#define COM_TXPDUINFOOFPCCONFIG                                       STD_ON
#define COM_TXPDUINITVALUEOFPCCONFIG                                  STD_ON
#define COM_TXSDULENGTHOFPCCONFIG                                     STD_ON
#define COM_TXSHDBUFFEROFPCCONFIG                                     STD_ON
#define COM_TXSIGGRPINFOINDOFPCCONFIG                                 STD_ON
#define COM_TXSIGGRPINFOOFPCCONFIG                                    STD_ON
#define COM_TXSIGGRPMASKOFPCCONFIG                                    STD_ON
#define COM_TXSIGINFOOFPCCONFIG                                       STD_ON
#define COM_WAITINGFORCONFIRMATIONOFPCCONFIG                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PCNoReferenceDefines  No Reference Defines (PRE-COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define COM_NO_FILTERPARAMIDXOFFILTERINFO                             65535U
#define COM_NO_LENGTHOFFILTERINFO                                     65535U
#define COM_NO_GWSIGGRPMAPPINGENDIDXOFGWINFO                          65535U
#define COM_NO_GWSIGGRPMAPPINGSTARTIDXOFGWINFO                        65535U
#define COM_NO_GWSIGMAPPINGENDIDXOFGWINFO                             65535U
#define COM_NO_GWSIGMAPPINGSTARTIDXOFGWINFO                           65535U
#define COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO   65535U
#define COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO 65535U
#define COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                      65535U
#define COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                    65535U
#define COM_NO_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                      65535U
#define COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                    65535U
#define COM_NO_IPDUGROUPINFOOFRXPDUINFOIND                            65535U
#define COM_NO_IPDUGROUPINFOOFTXPDUINFOIND                            65535U
#define COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSIND                        65535U
#define COM_NO_BUFFERIDXOFRXACCESSINFO                                255U
#define COM_NO_GWINFOIDXOFRXACCESSINFO                                65535U
#define COM_NO_INITVALUEIDXOFRXACCESSINFO                             255U
#define COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO        255U
#define COM_NO_SHDBUFFERIDXOFRXACCESSINFO                             255U
#define COM_NO_RXACCESSINFOIND                                        255U
#define COM_NO_RXACCESSINFOREPLACEGRPSIGIND                           65535U
#define COM_NO_RXACCESSINFOREPLACESIGIND                              255U
#define COM_NO_FILTERINFOIDXOFRXGRPSIGINFO                            65535U
#define COM_NO_INVVALUEIDXOFRXGRPSIGINFO                              65535U
#define COM_NO_TMPBUFFERIDXOFRXGRPSIGINFO                             255U
#define COM_NO_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                       255U
#define COM_NO_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                     255U
#define COM_NO_GWINFOENDIDXOFRXPDUINFO                                65535U
#define COM_NO_GWINFOSTARTIDXOFRXPDUINFO                              65535U
#define COM_NO_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                      255U
#define COM_NO_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO           65535U
#define COM_NO_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO         65535U
#define COM_NO_RXACCESSINFOINDENDIDXOFRXPDUINFO                       255U
#define COM_NO_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                     255U
#define COM_NO_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                        255U
#define COM_NO_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                      255U
#define COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                      65535U
#define COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                       255U
#define COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                     255U
#define COM_NO_RXSIGINFOENDIDXOFRXPDUINFO                             255U
#define COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO                           255U
#define COM_NO_RXTOUTINFOIDXOFRXPDUINFO                               255U
#define COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO                         255U
#define COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                       255U
#define COM_NO_RXTPINFOIDXOFRXPDUINFO                                 65535U
#define COM_NO_RXPDUINFOIND                                           65535U
#define COM_NO_CBKINVFUNCPTRIDXOFRXSIGGRPINFO                         65535U
#define COM_NO_CBKRXACKFUNCPTRIDXOFRXSIGGRPINFO                       255U
#define COM_NO_CONSTVALUEXINT8ENDIDXOFRXSIGGRPINFO                    65535U
#define COM_NO_CONSTVALUEXINT8STARTIDXOFRXSIGGRPINFO                  65535U
#define COM_NO_GWINFOIDXOFRXSIGGRPINFO                                65535U
#define COM_NO_RXPDUINFOIDXOFRXSIGGRPINFO                             255U
#define COM_NO_RXSHDBUFFERXINT8ENDIDXOFRXSIGGRPINFO                   65535U
#define COM_NO_RXSHDBUFFERXINT8STARTIDXOFRXSIGGRPINFO                 65535U
#define COM_NO_RXTOUTINFOIDXOFRXSIGGRPINFO                            65535U
#define COM_NO_UBIDXOFRXSIGGRPINFO                                    65535U
#define COM_NO_UBMASKIDXOFRXSIGGRPINFO                                65535U
#define COM_NO_RXSIGGRPINFOIND                                        255U
#define COM_NO_CBKINVFUNCPTRIDXOFRXSIGINFO                            65535U
#define COM_NO_CBKRXACKFUNCPTRIDXOFRXSIGINFO                          255U
#define COM_NO_FILTERINFOIDXOFRXSIGINFO                               65535U
#define COM_NO_GWINFOIDXOFRXSIGINFO                                   65535U
#define COM_NO_INVVALUEIDXOFRXSIGINFO                                 65535U
#define COM_NO_RXTOUTINFOIDXOFRXSIGINFO                               255U
#define COM_NO_UBIDXOFRXSIGINFO                                       65535U
#define COM_NO_UBMASKIDXOFRXSIGINFO                                   65535U
#define COM_NO_CBKRXTOUTFUNCPTRENDIDXOFRXTOUTINFO                     255U
#define COM_NO_CBKRXTOUTFUNCPTRSTARTIDXOFRXTOUTINFO                   255U
#define COM_NO_RXACCESSINFOREPLACEGRPSIGINDENDIDXOFRXTOUTINFO         65535U
#define COM_NO_RXACCESSINFOREPLACEGRPSIGINDSTARTIDXOFRXTOUTINFO       65535U
#define COM_NO_RXACCESSINFOREPLACESIGINDENDIDXOFRXTOUTINFO            255U
#define COM_NO_RXACCESSINFOREPLACESIGINDSTARTIDXOFRXTOUTINFO          255U
#define COM_NO_RXTOUTINFOIND                                          255U
#define COM_NO_RXACCESSINFODYNSIGIDXOFRXTPINFO                        65535U
#define COM_NO_RXTPBUFFERENDIDXOFRXTPINFO                             65535U
#define COM_NO_RXTPBUFFERSTARTIDXOFRXTPINFO                           65535U
#define COM_NO_TXFILTERINITSTATEENDIDXOFTXMODEINFO                    65535U
#define COM_NO_TXFILTERINITSTATESTARTIDXOFTXMODEINFO                  65535U
#define COM_NO_TXMODEFALSEIDXOFTXMODEINFO                             65535U
#define COM_NO_TXMODETRUEIDXOFTXMODEINFO                              255U
#define COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO          65535U
#define COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO        65535U
#define COM_NO_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                       255U
#define COM_NO_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                     255U
#define COM_NO_CBKTXACKDEFFUNCPTRENDIDXOFTXPDUINFO                    65535U
#define COM_NO_CBKTXACKDEFFUNCPTRSTARTIDXOFTXPDUINFO                  65535U
#define COM_NO_CBKTXACKIMFUNCPTRENDIDXOFTXPDUINFO                     65535U
#define COM_NO_CBKTXACKIMFUNCPTRSTARTIDXOFTXPDUINFO                   65535U
#define COM_NO_CBKTXERRFUNCPTRENDIDXOFTXPDUINFO                       65535U
#define COM_NO_CBKTXERRFUNCPTRSTARTIDXOFTXPDUINFO                     65535U
#define COM_NO_CONSTVALUEXINT8UBCLEARMASKENDIDXOFTXPDUINFO            65535U
#define COM_NO_CONSTVALUEXINT8UBCLEARMASKSTARTIDXOFTXPDUINFO          65535U
#define COM_NO_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO           65535U
#define COM_NO_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO         65535U
#define COM_NO_TXPDUBUFFERENDIDXOFTXPDUINFO                           255U
#define COM_NO_TXPDUBUFFERMETADATAENDIDXOFTXPDUINFO                   65535U
#define COM_NO_TXPDUBUFFERMETADATASTARTIDXOFTXPDUINFO                 65535U
#define COM_NO_TXPDUBUFFERSTARTIDXOFTXPDUINFO                         255U
#define COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                      65535U
#define COM_NO_TXPDUINITVALUEENDIDXOFTXPDUINFO                        255U
#define COM_NO_TXPDUINITVALUEMETADATAENDIDXOFTXPDUINFO                65535U
#define COM_NO_TXPDUINITVALUEMETADATASTARTIDXOFTXPDUINFO              65535U
#define COM_NO_TXPDUINITVALUESTARTIDXOFTXPDUINFO                      255U
#define COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                    65535U
#define COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                       255U
#define COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                     255U
#define COM_NO_TXTOUTINFOIDXOFTXPDUINFO                               65535U
#define COM_NO_TXTPINFOIDXOFTXPDUINFO                                 65535U
#define COM_NO_TXPDUINFOIND                                           65535U
#define COM_NO_TXSHDBUFFERENDIDXOFTXSIGGRPINFO                        255U
#define COM_NO_TXSHDBUFFERSTARTIDXOFTXSIGGRPINFO                      255U
#define COM_NO_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                       255U
#define COM_NO_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                     255U
#define COM_NO_TXSIGGRPONCHANGEMASKONCHANGEENDIDXOFTXSIGGRPINFO       65535U
#define COM_NO_TXSIGGRPONCHANGEMASKONCHANGESTARTIDXOFTXSIGGRPINFO     65535U
#define COM_NO_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPENDIDXOFTXSIGGRPINFO 65535U
#define COM_NO_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPSTARTIDXOFTXSIGGRPINFO 65535U
#define COM_NO_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO               65535U
#define COM_NO_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO             65535U
#define COM_NO_TXTOUTINFOIDXOFTXSIGGRPINFO                            65535U
#define COM_NO_UBIDXOFTXSIGGRPINFO                                    65535U
#define COM_NO_UBMASKIDXOFTXSIGGRPINFO                                65535U
#define COM_NO_TXSIGGRPINFOIND                                        255U
#define COM_NO_FILTERINFOIDXOFTXSIGINFO                               65535U
#define COM_NO_FILTERINITVALUEIDXOFTXSIGINFO                          65535U
#define COM_NO_INVVALUEIDXOFTXSIGINFO                                 65535U
#define COM_NO_ONCHANGEIDXOFTXSIGINFO                                 65535U
#define COM_NO_TXFILTERINITSTATEIDXOFTXSIGINFO                        65535U
#define COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO                             255U
#define COM_NO_TXTOUTINFOIDXOFTXSIGINFO                               65535U
#define COM_NO_UBIDXOFTXSIGINFO                                       65535U
#define COM_NO_UBMASKIDXOFTXSIGINFO                                   65535U
#define COM_NO_TXSIGINFOFILTERINITVALUEIND                            65535U
#define COM_NO_TXSIGINFOINVVALUEIND                                   65535U
#define COM_NO_CBKTXTOUTFUNCPTRENDIDXOFTXTOUTINFO                     65535U
#define COM_NO_CBKTXTOUTFUNCPTRSTARTIDXOFTXTOUTINFO                   65535U
#define COM_NO_TXPDUINFOIDXOFTXTOUTINFO                               65535U
#define COM_NO_TXPDUBUFFERENDIDXOFTXTPINFO                            65535U
#define COM_NO_TXPDUBUFFERSTARTIDXOFTXTPINFO                          65535U
#define COM_NO_TXSIGINFODYNSIGIDXOFTXTPINFO                           65535U
/** 
  \}
*/ 

/** 
  \defgroup  PCEnumExistsDefines  Enum Exists Defines (PRE-COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define COM_EXISTS_BOOLEAN_APPLTYPEOFFILTERINFO                       STD_OFF
#define COM_EXISTS_UINT8_APPLTYPEOFFILTERINFO                         STD_OFF
#define COM_EXISTS_SINT8_APPLTYPEOFFILTERINFO                         STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFFILTERINFO                        STD_OFF
#define COM_EXISTS_SINT16_APPLTYPEOFFILTERINFO                        STD_OFF
#define COM_EXISTS_UINT32_APPLTYPEOFFILTERINFO                        STD_OFF
#define COM_EXISTS_SINT32_APPLTYPEOFFILTERINFO                        STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFFILTERINFO                       STD_OFF
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFFILTERINFO                     STD_OFF
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO                       STD_OFF
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO STD_OFF
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO        STD_OFF
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO         STD_OFF
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO              STD_OFF
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO               STD_OFF
#define COM_EXISTS_BOOLEAN_APPLTYPEOFRXACCESSINFO                     STD_ON
#define COM_EXISTS_UINT8_APPLTYPEOFRXACCESSINFO                       STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFRXACCESSINFO                       STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFRXACCESSINFO                      STD_ON
#define COM_EXISTS_SINT16_APPLTYPEOFRXACCESSINFO                      STD_ON
#define COM_EXISTS_UINT32_APPLTYPEOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_SINT32_APPLTYPEOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFRXACCESSINFO                     STD_ON
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFRXACCESSINFO                   STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFRXACCESSINFO                          STD_ON
#define COM_EXISTS_BYTE_BUSACCOFRXACCESSINFO                          STD_ON
#define COM_EXISTS_NBYTE_BUSACCOFRXACCESSINFO                         STD_ON
#define COM_EXISTS_NBYTE_SW_BUSACCOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_NBITNBYTE_BUSACCOFRXACCESSINFO                     STD_OFF
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFRXACCESSINFO                  STD_OFF
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO            STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGGRPINFO           STD_OFF
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO               STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO              STD_OFF
#define COM_EXISTS_TRANSMIT_CLRUBOFTXPDUINFO                          STD_OFF
#define COM_EXISTS_TRIGGER_TRANSMIT_CLRUBOFTXPDUINFO                  STD_OFF
#define COM_EXISTS_NOT_USED_CLRUBOFTXPDUINFO                          STD_OFF
#define COM_EXISTS_CONFIRMATION_CLRUBOFTXPDUINFO                      STD_OFF
#define COM_EXISTS_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO             STD_ON
#define COM_EXISTS_TRIGGERED_TRANSFERPROPERTYOFTXSIGGRPINFO           STD_OFF
#define COM_EXISTS_TRIGGERED_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO STD_OFF
#define COM_EXISTS_TRIGGERED_ON_CHANGE_TRANSFERPROPERTYOFTXSIGGRPINFO STD_OFF
#define COM_EXISTS_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO STD_OFF
#define COM_EXISTS_BOOLEAN_APPLTYPEOFTXSIGINFO                        STD_OFF
#define COM_EXISTS_UINT8_APPLTYPEOFTXSIGINFO                          STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFTXSIGINFO                          STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFTXSIGINFO                         STD_ON
#define COM_EXISTS_SINT16_APPLTYPEOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_UINT32_APPLTYPEOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_SINT32_APPLTYPEOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFTXSIGINFO                        STD_ON
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFTXSIGINFO                      STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFTXSIGINFO                             STD_ON
#define COM_EXISTS_BYTE_BUSACCOFTXSIGINFO                             STD_ON
#define COM_EXISTS_NBYTE_BUSACCOFTXSIGINFO                            STD_ON
#define COM_EXISTS_NBYTE_SW_BUSACCOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_NBITNBYTE_BUSACCOFTXSIGINFO                        STD_OFF
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFTXSIGINFO                     STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  PCEnumDefines  Enum Defines (PRE-COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define COM_BOOLEAN_APPLTYPEOFFILTERINFO                              0x00U
#define COM_UINT8_APPLTYPEOFFILTERINFO                                0x01U
#define COM_SINT8_APPLTYPEOFFILTERINFO                                0x02U
#define COM_UINT16_APPLTYPEOFFILTERINFO                               0x03U
#define COM_SINT16_APPLTYPEOFFILTERINFO                               0x04U
#define COM_UINT32_APPLTYPEOFFILTERINFO                               0x05U
#define COM_SINT32_APPLTYPEOFFILTERINFO                               0x06U
#define COM_UINT8_N_APPLTYPEOFFILTERINFO                              0x07U
#define COM_UINT8_DYN_APPLTYPEOFFILTERINFO                            0x08U
#define COM_NEVER_FILTERALGOOFFILTERINFO                              0x05U
#define COM_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO      0x00U
#define COM_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO               0x01U
#define COM_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO                0x02U
#define COM_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO                     0x03U
#define COM_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO                      0x04U
#define COM_INACTIVE_IPDUGROUPSTATE                                   0x00U
#define COM_ACTIVE_DMINACTIVE_IPDUGROUPSTATE                          0x01U
#define COM_ACTIVE_DMACTIVE_IPDUGROUPSTATE                            0x02U
#define COM_BOOLEAN_APPLTYPEOFRXACCESSINFO                            0x00U
#define COM_UINT8_APPLTYPEOFRXACCESSINFO                              0x01U
#define COM_SINT8_APPLTYPEOFRXACCESSINFO                              0x02U
#define COM_UINT16_APPLTYPEOFRXACCESSINFO                             0x03U
#define COM_SINT16_APPLTYPEOFRXACCESSINFO                             0x04U
#define COM_UINT32_APPLTYPEOFRXACCESSINFO                             0x05U
#define COM_SINT32_APPLTYPEOFRXACCESSINFO                             0x06U
#define COM_UINT8_N_APPLTYPEOFRXACCESSINFO                            0x07U
#define COM_UINT8_DYN_APPLTYPEOFRXACCESSINFO                          0x08U
#define COM_NBIT_BUSACCOFRXACCESSINFO                                 0x00U
#define COM_BYTE_BUSACCOFRXACCESSINFO                                 0x01U
#define COM_NBYTE_BUSACCOFRXACCESSINFO                                0x02U
#define COM_NBYTE_SW_BUSACCOFRXACCESSINFO                             0x03U
#define COM_NBITNBYTE_BUSACCOFRXACCESSINFO                            0x04U
#define COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO                         0x05U
#define COM_INACTIVE_RXPDUDMSTATE                                     0x00U
#define COM_ACTIVE_RXPDUDMSTATE                                       0x01U
#define COM_OCCURRED_RXPDUDMSTATE                                     0x03U
#define COM_OCCURRED_FLAG_RXPDUDMSTATE                                0x02U
#define COM_CLEAR_OCCURRED_FLAG_RXPDUDMSTATE                          0xFDU
#define COM_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO                   0x00U
#define COM_IMMEDIATE_SIGNALPROCESSINGOFRXSIGGRPINFO                  0x01U
#define COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO                      0x00U
#define COM_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO                     0x01U
#define COM_READY_RXTPCONNECTIONSTATE                                 0x00U
#define COM_RECEPTION_STARTED_RXTPCONNECTIONSTATE                     0x01U
#define COM_COPYING_RXTPCONNECTIONSTATE                               0x02U
#define COM_WAITING_FOR_INDICATION_RXTPCONNECTIONSTATE                0x03U
#define COM_TP_ERROR_RXTPCONNECTIONSTATE                              0x04U
#define COM_TRANSMIT_CLRUBOFTXPDUINFO                                 0x00U
#define COM_TRIGGER_TRANSMIT_CLRUBOFTXPDUINFO                         0x01U
#define COM_NOT_USED_CLRUBOFTXPDUINFO                                 0x02U
#define COM_CONFIRMATION_CLRUBOFTXPDUINFO                             0x03U
#define COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO                    0x00U
#define COM_TRIGGERED_TRANSFERPROPERTYOFTXSIGGRPINFO                  0x01U
#define COM_TRIGGERED_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO 0x03U
#define COM_TRIGGERED_ON_CHANGE_TRANSFERPROPERTYOFTXSIGGRPINFO        0x05U
#define COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO 0x07U
#define COM_BOOLEAN_APPLTYPEOFTXSIGINFO                               0x00U
#define COM_UINT8_APPLTYPEOFTXSIGINFO                                 0x01U
#define COM_SINT8_APPLTYPEOFTXSIGINFO                                 0x02U
#define COM_UINT16_APPLTYPEOFTXSIGINFO                                0x03U
#define COM_SINT16_APPLTYPEOFTXSIGINFO                                0x04U
#define COM_UINT32_APPLTYPEOFTXSIGINFO                                0x05U
#define COM_SINT32_APPLTYPEOFTXSIGINFO                                0x06U
#define COM_UINT8_N_APPLTYPEOFTXSIGINFO                               0x07U
#define COM_UINT8_DYN_APPLTYPEOFTXSIGINFO                             0x08U
#define COM_NBIT_BUSACCOFTXSIGINFO                                    0x00U
#define COM_BYTE_BUSACCOFTXSIGINFO                                    0x01U
#define COM_NBYTE_BUSACCOFTXSIGINFO                                   0x02U
#define COM_NBYTE_SW_BUSACCOFTXSIGINFO                                0x03U
#define COM_NBITNBYTE_BUSACCOFTXSIGINFO                               0x04U
#define COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO                            0x05U
#define COM_READY_TXTPCONNECTIONSTATE                                 0x00U
#define COM_TRANSMISSION_STARTED_TXTPCONNECTIONSTATE                  0x01U
#define COM_COPYING_TXTPCONNECTIONSTATE                               0x02U
#define COM_WAITING_FOR_CONFIRMATION_TXTPCONNECTIONSTATE              0x03U
#define COM_TP_ERROR_TXTPCONNECTIONSTATE                              0x04U
/** 
  \}
*/ 

/** 
  \defgroup  PCIsReducedToDefineDefines  Is Reduced To Define Defines (PRE-COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define COM_ISDEF_CBKINVFUNCPTR                                       STD_OFF
#define COM_ISDEF_CBKRXACKFUNCPTR                                     STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTR                                    STD_OFF
#define COM_ISDEF_CBKTXACKDEFFUNCPTR                                  STD_OFF
#define COM_ISDEF_CBKTXACKIMFUNCPTR                                   STD_OFF
#define COM_ISDEF_CBKTXERRFUNCPTR                                     STD_OFF
#define COM_ISDEF_CBKTXTOUTFUNCPTR                                    STD_OFF
#define COM_ISDEF_CONSTVALUEXINT16                                    STD_OFF
#define COM_ISDEF_CONSTVALUEXINT32                                    STD_OFF
#define COM_ISDEF_CONSTVALUEXINT8                                     STD_OFF
#define COM_ISDEF_APPLTYPEOFFILTERINFO                                STD_OFF
#define COM_ISDEF_FILTERALGOOFFILTERINFO                              STD_OFF
#define COM_ISDEF_FILTERPARAMIDXOFFILTERINFO                          STD_OFF
#define COM_ISDEF_FILTERPARAMUSEDOFFILTERINFO                         STD_OFF
#define COM_ISDEF_LENGTHOFFILTERINFO                                  STD_OFF
#define COM_ISDEF_RXACCESSINFOIDXOFGWGRPSIGMAPPING                    STD_OFF
#define COM_ISDEF_TXSIGIDOFGWGRPSIGMAPPING                            STD_OFF
#define COM_ISDEF_GWSIGGRPMAPPINGENDIDXOFGWINFO                       STD_OFF
#define COM_ISDEF_GWSIGGRPMAPPINGSTARTIDXOFGWINFO                     STD_OFF
#define COM_ISDEF_GWSIGGRPMAPPINGUSEDOFGWINFO                         STD_OFF
#define COM_ISDEF_GWSIGMAPPINGENDIDXOFGWINFO                          STD_OFF
#define COM_ISDEF_GWSIGMAPPINGSTARTIDXOFGWINFO                        STD_OFF
#define COM_ISDEF_GWSIGMAPPINGUSEDOFGWINFO                            STD_OFF
#define COM_ISDEF_GWGRPSIGMAPPINGENDIDXOFGWSIGGRPMAPPING              STD_OFF
#define COM_ISDEF_GWGRPSIGMAPPINGSTARTIDXOFGWSIGGRPMAPPING            STD_OFF
#define COM_ISDEF_TXSIGGRPIDOFGWSIGGRPMAPPING                         STD_OFF
#define COM_ISDEF_RXACCESSINFOIDXOFGWSIGMAPPING                       STD_OFF
#define COM_ISDEF_TXSIGIDOFGWSIGMAPPING                               STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO  STD_OFF
#define COM_ISDEF_INVALIDHNDOFIPDUGROUPINFO                           STD_OFF
#define COM_ISDEF_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                   STD_OFF
#define COM_ISDEF_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                 STD_OFF
#define COM_ISDEF_RXPDUINFOINDUSEDOFIPDUGROUPINFO                     STD_OFF
#define COM_ISDEF_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                   STD_OFF
#define COM_ISDEF_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                 STD_OFF
#define COM_ISDEF_TXPDUINFOINDUSEDOFIPDUGROUPINFO                     STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOIND                         STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOIND                         STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSIND                     STD_OFF
#define COM_ISDEF_PDUGRPVECTOR                                        STD_OFF
#define COM_ISDEF_APPLTYPEOFRXACCESSINFO                              STD_OFF
#define COM_ISDEF_BITLENGTHOFRXACCESSINFO                             STD_OFF
#define COM_ISDEF_BITPOSITIONOFRXACCESSINFO                           STD_OFF
#define COM_ISDEF_BUFFERIDXOFRXACCESSINFO                             STD_OFF
#define COM_ISDEF_BUFFERUSEDOFRXACCESSINFO                            STD_OFF
#define COM_ISDEF_BUSACCOFRXACCESSINFO                                STD_OFF
#define COM_ISDEF_BYTELENGTHOFRXACCESSINFO                            STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_GWINFOIDXOFRXACCESSINFO                             STD_OFF
#define COM_ISDEF_GWINFOUSEDOFRXACCESSINFO                            STD_OFF
#define COM_ISDEF_INITVALUEIDXOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_INITVALUEUSEDOFRXACCESSINFO                         STD_OFF
#define COM_ISDEF_INVALIDHNDOFRXACCESSINFO                            STD_OFF
#define COM_ISDEF_PDUIDOFRXACCESSINFO                                 STD_OFF
#define COM_ISDEF_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO     STD_OFF
#define COM_ISDEF_RXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO    STD_OFF
#define COM_ISDEF_SHDBUFFERIDXOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_SHDBUFFERUSEDOFRXACCESSINFO                         STD_OFF
#define COM_ISDEF_SIGNEXTREQUIREDOFRXACCESSINFO                       STD_OFF
#define COM_ISDEF_RXACCESSINFOIND                                     STD_OFF
#define COM_ISDEF_RXACCESSINFOREPLACEGRPSIGIND                        STD_OFF
#define COM_ISDEF_RXACCESSINFOREPLACESIGIND                           STD_OFF
#define COM_ISDEF_FILTERINFOIDXOFRXGRPSIGINFO                         STD_OFF
#define COM_ISDEF_FILTERINFOUSEDOFRXGRPSIGINFO                        STD_OFF
#define COM_ISDEF_INVVALUEIDXOFRXGRPSIGINFO                           STD_OFF
#define COM_ISDEF_INVVALUEUSEDOFRXGRPSIGINFO                          STD_OFF
#define COM_ISDEF_RXACCESSINFOIDXOFRXGRPSIGINFO                       STD_OFF
#define COM_ISDEF_TMPBUFFERIDXOFRXGRPSIGINFO                          STD_OFF
#define COM_ISDEF_TMPBUFFERUSEDOFRXGRPSIGINFO                         STD_OFF
#define COM_ISDEF_RXPDUCALLOUTFUNCPTR                                 STD_OFF
#define COM_ISDEF_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                    STD_OFF
#define COM_ISDEF_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                  STD_OFF
#define COM_ISDEF_PDUGRPVECTORUSEDOFRXPDUGRPINFO                      STD_OFF
#define COM_ISDEF_GWINFOENDIDXOFRXPDUINFO                             STD_OFF
#define COM_ISDEF_GWINFOSTARTIDXOFRXPDUINFO                           STD_OFF
#define COM_ISDEF_GWINFOUSEDOFRXPDUINFO                               STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                   STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                  STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO        STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO      STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO          STD_OFF
#define COM_ISDEF_INVALIDHNDOFRXPDUINFO                               STD_OFF
#define COM_ISDEF_RXACCESSINFOINDENDIDXOFRXPDUINFO                    STD_OFF
#define COM_ISDEF_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                  STD_OFF
#define COM_ISDEF_RXACCESSINFOINDUSEDOFRXPDUINFO                      STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                     STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                     STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                   STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERUSEDOFRXPDUINFO                       STD_OFF
#define COM_ISDEF_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                   STD_OFF
#define COM_ISDEF_RXPDUCALLOUTFUNCPTRUSEDOFRXPDUINFO                  STD_OFF
#define COM_ISDEF_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                    STD_OFF
#define COM_ISDEF_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                  STD_OFF
#define COM_ISDEF_RXSIGGRPINFOINDUSEDOFRXPDUINFO                      STD_OFF
#define COM_ISDEF_RXSIGINFOENDIDXOFRXPDUINFO                          STD_OFF
#define COM_ISDEF_RXSIGINFOSTARTIDXOFRXPDUINFO                        STD_OFF
#define COM_ISDEF_RXSIGINFOUSEDOFRXPDUINFO                            STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXPDUINFO                            STD_OFF
#define COM_ISDEF_RXTOUTINFOINDENDIDXOFRXPDUINFO                      STD_OFF
#define COM_ISDEF_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                    STD_OFF
#define COM_ISDEF_RXTOUTINFOINDUSEDOFRXPDUINFO                        STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXPDUINFO                           STD_OFF
#define COM_ISDEF_RXTPINFOIDXOFRXPDUINFO                              STD_OFF
#define COM_ISDEF_RXTPINFOUSEDOFRXPDUINFO                             STD_OFF
#define COM_ISDEF_RXPDUINFOIND                                        STD_OFF
#define COM_ISDEF_ARRAYACCESSUSEDOFRXSIGGRPINFO                       STD_OFF
#define COM_ISDEF_CBKINVFUNCPTRIDXOFRXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_CBKINVFUNCPTRUSEDOFRXSIGGRPINFO                     STD_OFF
#define COM_ISDEF_CBKRXACKFUNCPTRIDXOFRXSIGGRPINFO                    STD_OFF
#define COM_ISDEF_CBKRXACKFUNCPTRUSEDOFRXSIGGRPINFO                   STD_OFF
#define COM_ISDEF_CONSTVALUEXINT8ENDIDXOFRXSIGGRPINFO                 STD_OFF
#define COM_ISDEF_CONSTVALUEXINT8LENGTHOFRXSIGGRPINFO                 STD_OFF
#define COM_ISDEF_CONSTVALUEXINT8STARTIDXOFRXSIGGRPINFO               STD_OFF
#define COM_ISDEF_CONSTVALUEXINT8USEDOFRXSIGGRPINFO                   STD_OFF
#define COM_ISDEF_FILTEREVENTOFRXSIGGRPINFO                           STD_OFF
#define COM_ISDEF_GWINFOIDXOFRXSIGGRPINFO                             STD_OFF
#define COM_ISDEF_GWINFOUSEDOFRXSIGGRPINFO                            STD_OFF
#define COM_ISDEF_INVEVENTOFRXSIGGRPINFO                              STD_OFF
#define COM_ISDEF_INVALIDHNDOFRXSIGGRPINFO                            STD_OFF
#define COM_ISDEF_RXGRPSIGINFOENDIDXOFRXSIGGRPINFO                    STD_OFF
#define COM_ISDEF_RXGRPSIGINFOSTARTIDXOFRXSIGGRPINFO                  STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXSIGGRPINFO                          STD_OFF
#define COM_ISDEF_RXPDUINFOUSEDOFRXSIGGRPINFO                         STD_OFF
#define COM_ISDEF_RXSHDBUFFERXINT8ENDIDXOFRXSIGGRPINFO                STD_OFF
#define COM_ISDEF_RXSHDBUFFERXINT8LENGTHOFRXSIGGRPINFO                STD_OFF
#define COM_ISDEF_RXSHDBUFFERXINT8STARTIDXOFRXSIGGRPINFO              STD_OFF
#define COM_ISDEF_RXSHDBUFFERXINT8USEDOFRXSIGGRPINFO                  STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXSIGGRPINFO                         STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXSIGGRPINFO                        STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_STARTBYTEPOSITIONOFRXSIGGRPINFO                     STD_OFF
#define COM_ISDEF_UBIDXOFRXSIGGRPINFO                                 STD_OFF
#define COM_ISDEF_UBMASKIDXOFRXSIGGRPINFO                             STD_OFF
#define COM_ISDEF_UBMASKUSEDOFRXSIGGRPINFO                            STD_OFF
#define COM_ISDEF_VALIDDLCOFRXSIGGRPINFO                              STD_OFF
#define COM_ISDEF_RXSIGGRPINFOIND                                     STD_OFF
#define COM_ISDEF_CBKINVFUNCPTRIDXOFRXSIGINFO                         STD_OFF
#define COM_ISDEF_CBKINVFUNCPTRUSEDOFRXSIGINFO                        STD_OFF
#define COM_ISDEF_CBKRXACKFUNCPTRIDXOFRXSIGINFO                       STD_OFF
#define COM_ISDEF_CBKRXACKFUNCPTRUSEDOFRXSIGINFO                      STD_OFF
#define COM_ISDEF_FILTERINFOIDXOFRXSIGINFO                            STD_OFF
#define COM_ISDEF_FILTERINFOUSEDOFRXSIGINFO                           STD_OFF
#define COM_ISDEF_GWINFOIDXOFRXSIGINFO                                STD_OFF
#define COM_ISDEF_GWINFOUSEDOFRXSIGINFO                               STD_OFF
#define COM_ISDEF_INVVALUEIDXOFRXSIGINFO                              STD_OFF
#define COM_ISDEF_INVVALUEUSEDOFRXSIGINFO                             STD_OFF
#define COM_ISDEF_RXACCESSINFOIDXOFRXSIGINFO                          STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXSIGINFO                            STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXSIGINFO                           STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXSIGINFO                         STD_OFF
#define COM_ISDEF_UBIDXOFRXSIGINFO                                    STD_OFF
#define COM_ISDEF_UBMASKIDXOFRXSIGINFO                                STD_OFF
#define COM_ISDEF_UBMASKUSEDOFRXSIGINFO                               STD_OFF
#define COM_ISDEF_VALIDDLCOFRXSIGINFO                                 STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRENDIDXOFRXTOUTINFO                  STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRSTARTIDXOFRXTOUTINFO                STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRUSEDOFRXTOUTINFO                    STD_OFF
#define COM_ISDEF_FACTOROFRXTOUTINFO                                  STD_OFF
#define COM_ISDEF_FIRSTFACTOROFRXTOUTINFO                             STD_OFF
#define COM_ISDEF_RXACCESSINFOREPLACEGRPSIGINDENDIDXOFRXTOUTINFO      STD_OFF
#define COM_ISDEF_RXACCESSINFOREPLACEGRPSIGINDSTARTIDXOFRXTOUTINFO    STD_OFF
#define COM_ISDEF_RXACCESSINFOREPLACEGRPSIGINDUSEDOFRXTOUTINFO        STD_OFF
#define COM_ISDEF_RXACCESSINFOREPLACESIGINDENDIDXOFRXTOUTINFO         STD_OFF
#define COM_ISDEF_RXACCESSINFOREPLACESIGINDSTARTIDXOFRXTOUTINFO       STD_OFF
#define COM_ISDEF_RXACCESSINFOREPLACESIGINDUSEDOFRXTOUTINFO           STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXTOUTINFO                            STD_OFF
#define COM_ISDEF_RXTOUTINFOIND                                       STD_OFF
#define COM_ISDEF_BUFFERSIZEOFRXTPINFO                                STD_OFF
#define COM_ISDEF_RXACCESSINFODYNSIGIDXOFRXTPINFO                     STD_OFF
#define COM_ISDEF_RXACCESSINFODYNSIGUSEDOFRXTPINFO                    STD_OFF
#define COM_ISDEF_RXTPBUFFERENDIDXOFRXTPINFO                          STD_OFF
#define COM_ISDEF_RXTPBUFFERSTARTIDXOFRXTPINFO                        STD_OFF
#define COM_ISDEF_RXTPBUFFERUSEDOFRXTPINFO                            STD_OFF
#define COM_ISDEF_TXFILTERINITSTATE                                   STD_OFF
#define COM_ISDEF_TXFILTERINITVALUEXINT16                             STD_OFF
#define COM_ISDEF_TXFILTERINITVALUEXINT32                             STD_OFF
#define COM_ISDEF_TXFILTERINITVALUEXINT8                              STD_OFF
#define COM_ISDEF_DIRECTOFTXMODEFALSE                                 STD_OFF
#define COM_ISDEF_PERIODICOFTXMODEFALSE                               STD_OFF
#define COM_ISDEF_REPCNTOFTXMODEFALSE                                 STD_OFF
#define COM_ISDEF_REPPERIODOFTXMODEFALSE                              STD_OFF
#define COM_ISDEF_TIMEOFFSETOFTXMODEFALSE                             STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODEFALSE                             STD_OFF
#define COM_ISDEF_INITMODEOFTXMODEINFO                                STD_OFF
#define COM_ISDEF_INVALIDHNDOFTXMODEINFO                              STD_OFF
#define COM_ISDEF_MINIMUMDELAYOFTXMODEINFO                            STD_OFF
#define COM_ISDEF_TXFILTERINITSTATEENDIDXOFTXMODEINFO                 STD_OFF
#define COM_ISDEF_TXFILTERINITSTATESTARTIDXOFTXMODEINFO               STD_OFF
#define COM_ISDEF_TXFILTERINITSTATEUSEDOFTXMODEINFO                   STD_OFF
#define COM_ISDEF_TXMODEFALSEIDXOFTXMODEINFO                          STD_OFF
#define COM_ISDEF_TXMODEFALSEUSEDOFTXMODEINFO                         STD_OFF
#define COM_ISDEF_TXMODETRUEIDXOFTXMODEINFO                           STD_OFF
#define COM_ISDEF_TXMODETRUEUSEDOFTXMODEINFO                          STD_OFF
#define COM_ISDEF_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO       STD_OFF
#define COM_ISDEF_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO     STD_OFF
#define COM_ISDEF_TXSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO         STD_OFF
#define COM_ISDEF_DIRECTOFTXMODETRUE                                  STD_OFF
#define COM_ISDEF_PERIODICOFTXMODETRUE                                STD_OFF
#define COM_ISDEF_REPCNTOFTXMODETRUE                                  STD_OFF
#define COM_ISDEF_REPPERIODOFTXMODETRUE                               STD_OFF
#define COM_ISDEF_TIMEOFFSETOFTXMODETRUE                              STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODETRUE                              STD_OFF
#define COM_ISDEF_TXPDUCALLOUTFUNCPTR                                 STD_OFF
#define COM_ISDEF_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                    STD_OFF
#define COM_ISDEF_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                  STD_OFF
#define COM_ISDEF_PDUGRPVECTORUSEDOFTXPDUGRPINFO                      STD_OFF
#define COM_ISDEF_CANCELLATIONSUPPORTOFTXPDUINFO                      STD_OFF
#define COM_ISDEF_CBKTXACKDEFFUNCPTRENDIDXOFTXPDUINFO                 STD_OFF
#define COM_ISDEF_CBKTXACKDEFFUNCPTRSTARTIDXOFTXPDUINFO               STD_OFF
#define COM_ISDEF_CBKTXACKDEFFUNCPTRUSEDOFTXPDUINFO                   STD_OFF
#define COM_ISDEF_CBKTXACKIMFUNCPTRENDIDXOFTXPDUINFO                  STD_OFF
#define COM_ISDEF_CBKTXACKIMFUNCPTRSTARTIDXOFTXPDUINFO                STD_OFF
#define COM_ISDEF_CBKTXACKIMFUNCPTRUSEDOFTXPDUINFO                    STD_OFF
#define COM_ISDEF_CBKTXERRFUNCPTRENDIDXOFTXPDUINFO                    STD_OFF
#define COM_ISDEF_CBKTXERRFUNCPTRSTARTIDXOFTXPDUINFO                  STD_OFF
#define COM_ISDEF_CBKTXERRFUNCPTRUSEDOFTXPDUINFO                      STD_OFF
#define COM_ISDEF_CLRUBOFTXPDUINFO                                    STD_OFF
#define COM_ISDEF_CONSTVALUEXINT8UBCLEARMASKENDIDXOFTXPDUINFO         STD_OFF
#define COM_ISDEF_CONSTVALUEXINT8UBCLEARMASKSTARTIDXOFTXPDUINFO       STD_OFF
#define COM_ISDEF_CONSTVALUEXINT8UBCLEARMASKUSEDOFTXPDUINFO           STD_OFF
#define COM_ISDEF_EXTERNALIDOFTXPDUINFO                               STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO        STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO      STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO          STD_OFF
#define COM_ISDEF_INVALIDHNDOFTXPDUINFO                               STD_OFF
#define COM_ISDEF_METADATALENGTHOFTXPDUINFO                           STD_OFF
#define COM_ISDEF_PDUWITHMETADATALENGTHOFTXPDUINFO                    STD_OFF
#define COM_ISDEF_TXPDUBUFFERENDIDXOFTXPDUINFO                        STD_OFF
#define COM_ISDEF_TXPDUBUFFERLENGTHOFTXPDUINFO                        STD_OFF
#define COM_ISDEF_TXPDUBUFFERMETADATAENDIDXOFTXPDUINFO                STD_OFF
#define COM_ISDEF_TXPDUBUFFERMETADATASTARTIDXOFTXPDUINFO              STD_OFF
#define COM_ISDEF_TXPDUBUFFERMETADATAUSEDOFTXPDUINFO                  STD_OFF
#define COM_ISDEF_TXPDUBUFFERSTARTIDXOFTXPDUINFO                      STD_OFF
#define COM_ISDEF_TXPDUBUFFERUSEDOFTXPDUINFO                          STD_OFF
#define COM_ISDEF_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                   STD_OFF
#define COM_ISDEF_TXPDUCALLOUTFUNCPTRUSEDOFTXPDUINFO                  STD_OFF
#define COM_ISDEF_TXPDUINITVALUEENDIDXOFTXPDUINFO                     STD_OFF
#define COM_ISDEF_TXPDUINITVALUEMETADATAENDIDXOFTXPDUINFO             STD_OFF
#define COM_ISDEF_TXPDUINITVALUEMETADATASTARTIDXOFTXPDUINFO           STD_OFF
#define COM_ISDEF_TXPDUINITVALUEMETADATAUSEDOFTXPDUINFO               STD_OFF
#define COM_ISDEF_TXPDUINITVALUESTARTIDXOFTXPDUINFO                   STD_OFF
#define COM_ISDEF_TXPDUINITVALUEUSEDOFTXPDUINFO                       STD_OFF
#define COM_ISDEF_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                 STD_OFF
#define COM_ISDEF_TXPDUTTCALLOUTFUNCPTRUSEDOFTXPDUINFO                STD_OFF
#define COM_ISDEF_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                    STD_OFF
#define COM_ISDEF_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                  STD_OFF
#define COM_ISDEF_TXSIGGRPINFOINDUSEDOFTXPDUINFO                      STD_OFF
#define COM_ISDEF_TXTOUTINFOIDXOFTXPDUINFO                            STD_OFF
#define COM_ISDEF_TXTOUTINFOUSEDOFTXPDUINFO                           STD_OFF
#define COM_ISDEF_TXTPINFOIDXOFTXPDUINFO                              STD_OFF
#define COM_ISDEF_TXTPINFOUSEDOFTXPDUINFO                             STD_OFF
#define COM_ISDEF_TXPDUINFOIND                                        STD_OFF
#define COM_ISDEF_TXPDUINITVALUE                                      STD_OFF
#define COM_ISDEF_TXPDUTTCALLOUTFUNCPTR                               STD_OFF
#define COM_ISDEF_ARRAYACCESSUSEDOFTXSIGGRPINFO                       STD_OFF
#define COM_ISDEF_INVALIDHNDOFTXSIGGRPINFO                            STD_OFF
#define COM_ISDEF_PDUIDOFTXSIGGRPINFO                                 STD_OFF
#define COM_ISDEF_PDUOFFSETOFTXSIGGRPINFO                             STD_OFF
#define COM_ISDEF_SIGGROUPONCHANGEOFFSETOFTXSIGGRPINFO                STD_OFF
#define COM_ISDEF_SIGGROUPONCHANGESTARTPOSITIONOFTXSIGGRPINFO         STD_OFF
#define COM_ISDEF_SIGGROUPONCHANGEWITHOUTREPOFFSETOFTXSIGGRPINFO      STD_OFF
#define COM_ISDEF_SIGGROUPONCHANGEWITHOUTREPSTARTPOSITIONOFTXSIGGRPINFO STD_OFF
#define COM_ISDEF_TRANSFERPROPERTYOFTXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_TXSHDBUFFERENDIDXOFTXSIGGRPINFO                     STD_OFF
#define COM_ISDEF_TXSHDBUFFERLENGTHOFTXSIGGRPINFO                     STD_OFF
#define COM_ISDEF_TXSHDBUFFERSTARTIDXOFTXSIGGRPINFO                   STD_OFF
#define COM_ISDEF_TXSHDBUFFERUSEDOFTXSIGGRPINFO                       STD_OFF
#define COM_ISDEF_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                    STD_OFF
#define COM_ISDEF_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                    STD_OFF
#define COM_ISDEF_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                  STD_OFF
#define COM_ISDEF_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_TXSIGGRPONCHANGEMASKONCHANGEENDIDXOFTXSIGGRPINFO    STD_OFF
#define COM_ISDEF_TXSIGGRPONCHANGEMASKONCHANGELENGTHOFTXSIGGRPINFO    STD_OFF
#define COM_ISDEF_TXSIGGRPONCHANGEMASKONCHANGESTARTIDXOFTXSIGGRPINFO  STD_OFF
#define COM_ISDEF_TXSIGGRPONCHANGEMASKONCHANGEUSEDOFTXSIGGRPINFO      STD_OFF
#define COM_ISDEF_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPENDIDXOFTXSIGGRPINFO STD_OFF
#define COM_ISDEF_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPLENGTHOFTXSIGGRPINFO STD_OFF
#define COM_ISDEF_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPSTARTIDXOFTXSIGGRPINFO STD_OFF
#define COM_ISDEF_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPUSEDOFTXSIGGRPINFO STD_OFF
#define COM_ISDEF_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO            STD_OFF
#define COM_ISDEF_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO          STD_OFF
#define COM_ISDEF_TXSIGINFOINVVALUEINDUSEDOFTXSIGGRPINFO              STD_OFF
#define COM_ISDEF_TXTOUTINFOIDXOFTXSIGGRPINFO                         STD_OFF
#define COM_ISDEF_TXTOUTINFOUSEDOFTXSIGGRPINFO                        STD_OFF
#define COM_ISDEF_UBIDXOFTXSIGGRPINFO                                 STD_OFF
#define COM_ISDEF_UBMASKIDXOFTXSIGGRPINFO                             STD_OFF
#define COM_ISDEF_UBMASKUSEDOFTXSIGGRPINFO                            STD_OFF
#define COM_ISDEF_TXSIGGRPINFOIND                                     STD_OFF
#define COM_ISDEF_TXSIGGRPMASK                                        STD_OFF
#define COM_ISDEF_TXSIGGRPONCHANGEMASK                                STD_OFF
#define COM_ISDEF_APPLTYPEOFTXSIGINFO                                 STD_OFF
#define COM_ISDEF_BITLENGTHOFTXSIGINFO                                STD_OFF
#define COM_ISDEF_BITPOSITIONOFTXSIGINFO                              STD_OFF
#define COM_ISDEF_BUSACCOFTXSIGINFO                                   STD_OFF
#define COM_ISDEF_BYTELENGTHOFTXSIGINFO                               STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_FILTERINFOIDXOFTXSIGINFO                            STD_OFF
#define COM_ISDEF_FILTERINFOUSEDOFTXSIGINFO                           STD_OFF
#define COM_ISDEF_FILTERINITVALUEIDXOFTXSIGINFO                       STD_OFF
#define COM_ISDEF_FILTERINITVALUEUSEDOFTXSIGINFO                      STD_OFF
#define COM_ISDEF_INVVALUEIDXOFTXSIGINFO                              STD_OFF
#define COM_ISDEF_INVVALUEUSEDOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_INVALIDHNDOFTXSIGINFO                               STD_OFF
#define COM_ISDEF_ONCHANGEIDXOFTXSIGINFO                              STD_OFF
#define COM_ISDEF_ONCHANGEUSEDOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_PDUIDOFTXSIGINFO                                    STD_OFF
#define COM_ISDEF_TRIGGEREDOFTXSIGINFO                                STD_OFF
#define COM_ISDEF_TXFILTERINITSTATEIDXOFTXSIGINFO                     STD_OFF
#define COM_ISDEF_TXFILTERINITSTATEUSEDOFTXSIGINFO                    STD_OFF
#define COM_ISDEF_TXSIGGRPINFOIDXOFTXSIGINFO                          STD_OFF
#define COM_ISDEF_TXSIGGRPINFOUSEDOFTXSIGINFO                         STD_OFF
#define COM_ISDEF_TXTOUTINFOIDXOFTXSIGINFO                            STD_OFF
#define COM_ISDEF_TXTOUTINFOUSEDOFTXSIGINFO                           STD_OFF
#define COM_ISDEF_UBIDXOFTXSIGINFO                                    STD_OFF
#define COM_ISDEF_UBMASKIDXOFTXSIGINFO                                STD_OFF
#define COM_ISDEF_UBMASKUSEDOFTXSIGINFO                               STD_OFF
#define COM_ISDEF_WITHOUTREPOFTXSIGINFO                               STD_OFF
#define COM_ISDEF_TXSIGINFOFILTERINITVALUEIND                         STD_OFF
#define COM_ISDEF_TXSIGINFOINVVALUEIND                                STD_OFF
#define COM_ISDEF_CBKTXTOUTFUNCPTRENDIDXOFTXTOUTINFO                  STD_OFF
#define COM_ISDEF_CBKTXTOUTFUNCPTRSTARTIDXOFTXTOUTINFO                STD_OFF
#define COM_ISDEF_CBKTXTOUTFUNCPTRUSEDOFTXTOUTINFO                    STD_OFF
#define COM_ISDEF_FACTOROFTXTOUTINFO                                  STD_OFF
#define COM_ISDEF_NONEMODEOFTXTOUTINFO                                STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXTOUTINFO                            STD_OFF
#define COM_ISDEF_TXPDUINFOUSEDOFTXTOUTINFO                           STD_OFF
#define COM_ISDEF_BUFFERSIZEOFTXTPINFO                                STD_OFF
#define COM_ISDEF_TXPDUBUFFERENDIDXOFTXTPINFO                         STD_OFF
#define COM_ISDEF_TXPDUBUFFERLENGTHOFTXTPINFO                         STD_OFF
#define COM_ISDEF_TXPDUBUFFERSTARTIDXOFTXTPINFO                       STD_OFF
#define COM_ISDEF_TXPDUBUFFERUSEDOFTXTPINFO                           STD_OFF
#define COM_ISDEF_TXSIGINFODYNSIGIDXOFTXTPINFO                        STD_OFF
#define COM_ISDEF_TXSIGINFODYNSIGUSEDOFTXTPINFO                       STD_OFF
#define COM_ISDEF_CBKRXACKFUNCPTROFPCCONFIG                           STD_ON
#define COM_ISDEF_CBKRXTOUTFUNCPTROFPCCONFIG                          STD_ON
#define COM_ISDEF_CONSTVALUEXINT16OFPCCONFIG                          STD_ON
#define COM_ISDEF_CONSTVALUEXINT8OFPCCONFIG                           STD_ON
#define COM_ISDEF_CURRENTTXMODEOFPCCONFIG                             STD_ON
#define COM_ISDEF_CYCLETIMECNTOFPCCONFIG                              STD_ON
#define COM_ISDEF_CYCLICSENDREQUESTOFPCCONFIG                         STD_ON
#define COM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                          STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDOFPCCONFIG                       STD_ON
#define COM_ISDEF_HANDLETXPDUDEFERREDOFPCCONFIG                       STD_ON
#define COM_ISDEF_INITDATAHASHCODEOFPCCONFIG                          STD_OFF
#define COM_ISDEF_INITIALIZEDOFPCCONFIG                               STD_ON
#define COM_ISDEF_PDUGRPVECTOROFPCCONFIG                              STD_ON
#define COM_ISDEF_REPCNTOFPCCONFIG                                    STD_ON
#define COM_ISDEF_REPCYCLECNTOFPCCONFIG                               STD_ON
#define COM_ISDEF_RXACCESSINFOINDOFPCCONFIG                           STD_ON
#define COM_ISDEF_RXACCESSINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXACCESSINFOREPLACESIGINDOFPCCONFIG                 STD_ON
#define COM_ISDEF_RXDEFPDUBUFFEROFPCCONFIG                            STD_ON
#define COM_ISDEF_RXGRPSIGINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXPDUDMSTATEOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_ISDEF_RXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_RXSHDBUFFERXINT16OFPCCONFIG                         STD_ON
#define COM_ISDEF_RXSHDBUFFERXINT8OFPCCONFIG                          STD_ON
#define COM_ISDEF_RXSIGBUFFERXINT16OFPCCONFIG                         STD_ON
#define COM_ISDEF_RXSIGBUFFERXINT8OFPCCONFIG                          STD_ON
#define COM_ISDEF_RXSIGGRPINFOINDOFPCCONFIG                           STD_ON
#define COM_ISDEF_RXSIGGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_RXTOUTCNTOFPCCONFIG                                 STD_ON
#define COM_ISDEF_RXTOUTINFOINDOFPCCONFIG                             STD_ON
#define COM_ISDEF_RXTOUTINFOOFPCCONFIG                                STD_ON
#define COM_ISDEF_SIGGRPEVENTFLAGOFPCCONFIG                           STD_ON
#define COM_ISDEF_TMPRXBUFFEROFPCCONFIG                               STD_ON
#define COM_ISDEF_TMPRXSHDBUFFERXINT16OFPCCONFIG                      STD_ON
#define COM_ISDEF_TMPRXSHDBUFFERXINT8OFPCCONFIG                       STD_ON
#define COM_ISDEF_TRANSMITREQUESTOFPCCONFIG                           STD_ON
#define COM_ISDEF_TXMODEINFOOFPCCONFIG                                STD_ON
#define COM_ISDEF_TXMODETRUEOFPCCONFIG                                STD_ON
#define COM_ISDEF_TXPDUBUFFEROFPCCONFIG                               STD_ON
#define COM_ISDEF_TXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_ISDEF_TXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_TXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_TXPDUINITVALUEOFPCCONFIG                            STD_ON
#define COM_ISDEF_TXSDULENGTHOFPCCONFIG                               STD_ON
#define COM_ISDEF_TXSHDBUFFEROFPCCONFIG                               STD_ON
#define COM_ISDEF_TXSIGGRPINFOINDOFPCCONFIG                           STD_ON
#define COM_ISDEF_TXSIGGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_TXSIGGRPMASKOFPCCONFIG                              STD_ON
#define COM_ISDEF_TXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_WAITINGFORCONFIRMATIONOFPCCONFIG                    STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PCEqualsAlwaysToDefines  Equals Always To Defines (PRE-COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define COM_EQ2_CBKINVFUNCPTR                                         
#define COM_EQ2_CBKRXACKFUNCPTR                                       
#define COM_EQ2_CBKRXTOUTFUNCPTR                                      
#define COM_EQ2_CBKTXACKDEFFUNCPTR                                    
#define COM_EQ2_CBKTXACKIMFUNCPTR                                     
#define COM_EQ2_CBKTXERRFUNCPTR                                       
#define COM_EQ2_CBKTXTOUTFUNCPTR                                      
#define COM_EQ2_CONSTVALUEXINT16                                      
#define COM_EQ2_CONSTVALUEXINT32                                      
#define COM_EQ2_CONSTVALUEXINT8                                       
#define COM_EQ2_APPLTYPEOFFILTERINFO                                  
#define COM_EQ2_FILTERALGOOFFILTERINFO                                
#define COM_EQ2_FILTERPARAMIDXOFFILTERINFO                            
#define COM_EQ2_FILTERPARAMUSEDOFFILTERINFO                           
#define COM_EQ2_LENGTHOFFILTERINFO                                    
#define COM_EQ2_RXACCESSINFOIDXOFGWGRPSIGMAPPING                      
#define COM_EQ2_TXSIGIDOFGWGRPSIGMAPPING                              
#define COM_EQ2_GWSIGGRPMAPPINGENDIDXOFGWINFO                         
#define COM_EQ2_GWSIGGRPMAPPINGSTARTIDXOFGWINFO                       
#define COM_EQ2_GWSIGGRPMAPPINGUSEDOFGWINFO                           
#define COM_EQ2_GWSIGMAPPINGENDIDXOFGWINFO                            
#define COM_EQ2_GWSIGMAPPINGSTARTIDXOFGWINFO                          
#define COM_EQ2_GWSIGMAPPINGUSEDOFGWINFO                              
#define COM_EQ2_GWGRPSIGMAPPINGENDIDXOFGWSIGGRPMAPPING                
#define COM_EQ2_GWGRPSIGMAPPINGSTARTIDXOFGWSIGGRPMAPPING              
#define COM_EQ2_TXSIGGRPIDOFGWSIGGRPMAPPING                           
#define COM_EQ2_RXACCESSINFOIDXOFGWSIGMAPPING                         
#define COM_EQ2_TXSIGIDOFGWSIGMAPPING                                 
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO  
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO 
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO    
#define COM_EQ2_INVALIDHNDOFIPDUGROUPINFO                             
#define COM_EQ2_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                     
#define COM_EQ2_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                   
#define COM_EQ2_RXPDUINFOINDUSEDOFIPDUGROUPINFO                       
#define COM_EQ2_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                     
#define COM_EQ2_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                   
#define COM_EQ2_TXPDUINFOINDUSEDOFIPDUGROUPINFO                       
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOIND                           
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOIND                           
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSIND                       
#define COM_EQ2_PDUGRPVECTOR                                          
#define COM_EQ2_APPLTYPEOFRXACCESSINFO                                
#define COM_EQ2_BITLENGTHOFRXACCESSINFO                               
#define COM_EQ2_BITPOSITIONOFRXACCESSINFO                             
#define COM_EQ2_BUFFERIDXOFRXACCESSINFO                               
#define COM_EQ2_BUFFERUSEDOFRXACCESSINFO                              
#define COM_EQ2_BUSACCOFRXACCESSINFO                                  
#define COM_EQ2_BYTELENGTHOFRXACCESSINFO                              
#define COM_EQ2_BYTEPOSITIONOFRXACCESSINFO                            
#define COM_EQ2_GWINFOIDXOFRXACCESSINFO                               
#define COM_EQ2_GWINFOUSEDOFRXACCESSINFO                              
#define COM_EQ2_INITVALUEIDXOFRXACCESSINFO                            
#define COM_EQ2_INITVALUEUSEDOFRXACCESSINFO                           
#define COM_EQ2_INVALIDHNDOFRXACCESSINFO                              
#define COM_EQ2_PDUIDOFRXACCESSINFO                                   
#define COM_EQ2_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO       
#define COM_EQ2_RXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO      
#define COM_EQ2_SHDBUFFERIDXOFRXACCESSINFO                            
#define COM_EQ2_SHDBUFFERUSEDOFRXACCESSINFO                           
#define COM_EQ2_SIGNEXTREQUIREDOFRXACCESSINFO                         
#define COM_EQ2_RXACCESSINFOIND                                       
#define COM_EQ2_RXACCESSINFOREPLACEGRPSIGIND                          
#define COM_EQ2_RXACCESSINFOREPLACESIGIND                             
#define COM_EQ2_FILTERINFOIDXOFRXGRPSIGINFO                           
#define COM_EQ2_FILTERINFOUSEDOFRXGRPSIGINFO                          
#define COM_EQ2_INVVALUEIDXOFRXGRPSIGINFO                             
#define COM_EQ2_INVVALUEUSEDOFRXGRPSIGINFO                            
#define COM_EQ2_RXACCESSINFOIDXOFRXGRPSIGINFO                         
#define COM_EQ2_TMPBUFFERIDXOFRXGRPSIGINFO                            
#define COM_EQ2_TMPBUFFERUSEDOFRXGRPSIGINFO                           
#define COM_EQ2_RXPDUCALLOUTFUNCPTR                                   
#define COM_EQ2_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                      
#define COM_EQ2_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                    
#define COM_EQ2_PDUGRPVECTORUSEDOFRXPDUGRPINFO                        
#define COM_EQ2_GWINFOENDIDXOFRXPDUINFO                               
#define COM_EQ2_GWINFOSTARTIDXOFRXPDUINFO                             
#define COM_EQ2_GWINFOUSEDOFRXPDUINFO                                 
#define COM_EQ2_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                     
#define COM_EQ2_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                    
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO          
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO        
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO            
#define COM_EQ2_INVALIDHNDOFRXPDUINFO                                 
#define COM_EQ2_RXACCESSINFOINDENDIDXOFRXPDUINFO                      
#define COM_EQ2_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                    
#define COM_EQ2_RXACCESSINFOINDUSEDOFRXPDUINFO                        
#define COM_EQ2_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                       
#define COM_EQ2_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                       
#define COM_EQ2_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                     
#define COM_EQ2_RXDEFPDUBUFFERUSEDOFRXPDUINFO                         
#define COM_EQ2_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                     
#define COM_EQ2_RXPDUCALLOUTFUNCPTRUSEDOFRXPDUINFO                    
#define COM_EQ2_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                      
#define COM_EQ2_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                    
#define COM_EQ2_RXSIGGRPINFOINDUSEDOFRXPDUINFO                        
#define COM_EQ2_RXSIGINFOENDIDXOFRXPDUINFO                            
#define COM_EQ2_RXSIGINFOSTARTIDXOFRXPDUINFO                          
#define COM_EQ2_RXSIGINFOUSEDOFRXPDUINFO                              
#define COM_EQ2_RXTOUTINFOIDXOFRXPDUINFO                              
#define COM_EQ2_RXTOUTINFOINDENDIDXOFRXPDUINFO                        
#define COM_EQ2_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                      
#define COM_EQ2_RXTOUTINFOINDUSEDOFRXPDUINFO                          
#define COM_EQ2_RXTOUTINFOUSEDOFRXPDUINFO                             
#define COM_EQ2_RXTPINFOIDXOFRXPDUINFO                                
#define COM_EQ2_RXTPINFOUSEDOFRXPDUINFO                               
#define COM_EQ2_RXPDUINFOIND                                          
#define COM_EQ2_ARRAYACCESSUSEDOFRXSIGGRPINFO                         
#define COM_EQ2_CBKINVFUNCPTRIDXOFRXSIGGRPINFO                        
#define COM_EQ2_CBKINVFUNCPTRUSEDOFRXSIGGRPINFO                       
#define COM_EQ2_CBKRXACKFUNCPTRIDXOFRXSIGGRPINFO                      
#define COM_EQ2_CBKRXACKFUNCPTRUSEDOFRXSIGGRPINFO                     
#define COM_EQ2_CONSTVALUEXINT8ENDIDXOFRXSIGGRPINFO                   
#define COM_EQ2_CONSTVALUEXINT8LENGTHOFRXSIGGRPINFO                   
#define COM_EQ2_CONSTVALUEXINT8STARTIDXOFRXSIGGRPINFO                 
#define COM_EQ2_CONSTVALUEXINT8USEDOFRXSIGGRPINFO                     
#define COM_EQ2_FILTEREVENTOFRXSIGGRPINFO                             
#define COM_EQ2_GWINFOIDXOFRXSIGGRPINFO                               
#define COM_EQ2_GWINFOUSEDOFRXSIGGRPINFO                              
#define COM_EQ2_INVEVENTOFRXSIGGRPINFO                                
#define COM_EQ2_INVALIDHNDOFRXSIGGRPINFO                              
#define COM_EQ2_RXGRPSIGINFOENDIDXOFRXSIGGRPINFO                      
#define COM_EQ2_RXGRPSIGINFOSTARTIDXOFRXSIGGRPINFO                    
#define COM_EQ2_RXPDUINFOIDXOFRXSIGGRPINFO                            
#define COM_EQ2_RXPDUINFOUSEDOFRXSIGGRPINFO                           
#define COM_EQ2_RXSHDBUFFERXINT8ENDIDXOFRXSIGGRPINFO                  
#define COM_EQ2_RXSHDBUFFERXINT8LENGTHOFRXSIGGRPINFO                  
#define COM_EQ2_RXSHDBUFFERXINT8STARTIDXOFRXSIGGRPINFO                
#define COM_EQ2_RXSHDBUFFERXINT8USEDOFRXSIGGRPINFO                    
#define COM_EQ2_RXTOUTINFOIDXOFRXSIGGRPINFO                           
#define COM_EQ2_RXTOUTINFOUSEDOFRXSIGGRPINFO                          
#define COM_EQ2_SIGNALPROCESSINGOFRXSIGGRPINFO                        
#define COM_EQ2_STARTBYTEPOSITIONOFRXSIGGRPINFO                       
#define COM_EQ2_UBIDXOFRXSIGGRPINFO                                   
#define COM_EQ2_UBMASKIDXOFRXSIGGRPINFO                               
#define COM_EQ2_UBMASKUSEDOFRXSIGGRPINFO                              
#define COM_EQ2_VALIDDLCOFRXSIGGRPINFO                                
#define COM_EQ2_RXSIGGRPINFOIND                                       
#define COM_EQ2_CBKINVFUNCPTRIDXOFRXSIGINFO                           
#define COM_EQ2_CBKINVFUNCPTRUSEDOFRXSIGINFO                          
#define COM_EQ2_CBKRXACKFUNCPTRIDXOFRXSIGINFO                         
#define COM_EQ2_CBKRXACKFUNCPTRUSEDOFRXSIGINFO                        
#define COM_EQ2_FILTERINFOIDXOFRXSIGINFO                              
#define COM_EQ2_FILTERINFOUSEDOFRXSIGINFO                             
#define COM_EQ2_GWINFOIDXOFRXSIGINFO                                  
#define COM_EQ2_GWINFOUSEDOFRXSIGINFO                                 
#define COM_EQ2_INVVALUEIDXOFRXSIGINFO                                
#define COM_EQ2_INVVALUEUSEDOFRXSIGINFO                               
#define COM_EQ2_RXACCESSINFOIDXOFRXSIGINFO                            
#define COM_EQ2_RXTOUTINFOIDXOFRXSIGINFO                              
#define COM_EQ2_RXTOUTINFOUSEDOFRXSIGINFO                             
#define COM_EQ2_SIGNALPROCESSINGOFRXSIGINFO                           
#define COM_EQ2_UBIDXOFRXSIGINFO                                      
#define COM_EQ2_UBMASKIDXOFRXSIGINFO                                  
#define COM_EQ2_UBMASKUSEDOFRXSIGINFO                                 
#define COM_EQ2_VALIDDLCOFRXSIGINFO                                   
#define COM_EQ2_CBKRXTOUTFUNCPTRENDIDXOFRXTOUTINFO                    
#define COM_EQ2_CBKRXTOUTFUNCPTRSTARTIDXOFRXTOUTINFO                  
#define COM_EQ2_CBKRXTOUTFUNCPTRUSEDOFRXTOUTINFO                      
#define COM_EQ2_FACTOROFRXTOUTINFO                                    
#define COM_EQ2_FIRSTFACTOROFRXTOUTINFO                               
#define COM_EQ2_RXACCESSINFOREPLACEGRPSIGINDENDIDXOFRXTOUTINFO        
#define COM_EQ2_RXACCESSINFOREPLACEGRPSIGINDSTARTIDXOFRXTOUTINFO      
#define COM_EQ2_RXACCESSINFOREPLACEGRPSIGINDUSEDOFRXTOUTINFO          
#define COM_EQ2_RXACCESSINFOREPLACESIGINDENDIDXOFRXTOUTINFO           
#define COM_EQ2_RXACCESSINFOREPLACESIGINDSTARTIDXOFRXTOUTINFO         
#define COM_EQ2_RXACCESSINFOREPLACESIGINDUSEDOFRXTOUTINFO             
#define COM_EQ2_RXPDUINFOIDXOFRXTOUTINFO                              
#define COM_EQ2_RXTOUTINFOIND                                         
#define COM_EQ2_BUFFERSIZEOFRXTPINFO                                  
#define COM_EQ2_RXACCESSINFODYNSIGIDXOFRXTPINFO                       
#define COM_EQ2_RXACCESSINFODYNSIGUSEDOFRXTPINFO                      
#define COM_EQ2_RXTPBUFFERENDIDXOFRXTPINFO                            
#define COM_EQ2_RXTPBUFFERSTARTIDXOFRXTPINFO                          
#define COM_EQ2_RXTPBUFFERUSEDOFRXTPINFO                              
#define COM_EQ2_TXFILTERINITSTATE                                     
#define COM_EQ2_TXFILTERINITVALUEXINT16                               
#define COM_EQ2_TXFILTERINITVALUEXINT32                               
#define COM_EQ2_TXFILTERINITVALUEXINT8                                
#define COM_EQ2_DIRECTOFTXMODEFALSE                                   
#define COM_EQ2_PERIODICOFTXMODEFALSE                                 
#define COM_EQ2_REPCNTOFTXMODEFALSE                                   
#define COM_EQ2_REPPERIODOFTXMODEFALSE                                
#define COM_EQ2_TIMEOFFSETOFTXMODEFALSE                               
#define COM_EQ2_TIMEPERIODOFTXMODEFALSE                               
#define COM_EQ2_INITMODEOFTXMODEINFO                                  
#define COM_EQ2_INVALIDHNDOFTXMODEINFO                                
#define COM_EQ2_MINIMUMDELAYOFTXMODEINFO                              
#define COM_EQ2_TXFILTERINITSTATEENDIDXOFTXMODEINFO                   
#define COM_EQ2_TXFILTERINITSTATESTARTIDXOFTXMODEINFO                 
#define COM_EQ2_TXFILTERINITSTATEUSEDOFTXMODEINFO                     
#define COM_EQ2_TXMODEFALSEIDXOFTXMODEINFO                            
#define COM_EQ2_TXMODEFALSEUSEDOFTXMODEINFO                           
#define COM_EQ2_TXMODETRUEIDXOFTXMODEINFO                             
#define COM_EQ2_TXMODETRUEUSEDOFTXMODEINFO                            
#define COM_EQ2_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO         
#define COM_EQ2_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO       
#define COM_EQ2_TXSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO           
#define COM_EQ2_DIRECTOFTXMODETRUE                                    
#define COM_EQ2_PERIODICOFTXMODETRUE                                  
#define COM_EQ2_REPCNTOFTXMODETRUE                                    
#define COM_EQ2_REPPERIODOFTXMODETRUE                                 
#define COM_EQ2_TIMEOFFSETOFTXMODETRUE                                
#define COM_EQ2_TIMEPERIODOFTXMODETRUE                                
#define COM_EQ2_TXPDUCALLOUTFUNCPTR                                   
#define COM_EQ2_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                      
#define COM_EQ2_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                    
#define COM_EQ2_PDUGRPVECTORUSEDOFTXPDUGRPINFO                        
#define COM_EQ2_CANCELLATIONSUPPORTOFTXPDUINFO                        
#define COM_EQ2_CBKTXACKDEFFUNCPTRENDIDXOFTXPDUINFO                   
#define COM_EQ2_CBKTXACKDEFFUNCPTRSTARTIDXOFTXPDUINFO                 
#define COM_EQ2_CBKTXACKDEFFUNCPTRUSEDOFTXPDUINFO                     
#define COM_EQ2_CBKTXACKIMFUNCPTRENDIDXOFTXPDUINFO                    
#define COM_EQ2_CBKTXACKIMFUNCPTRSTARTIDXOFTXPDUINFO                  
#define COM_EQ2_CBKTXACKIMFUNCPTRUSEDOFTXPDUINFO                      
#define COM_EQ2_CBKTXERRFUNCPTRENDIDXOFTXPDUINFO                      
#define COM_EQ2_CBKTXERRFUNCPTRSTARTIDXOFTXPDUINFO                    
#define COM_EQ2_CBKTXERRFUNCPTRUSEDOFTXPDUINFO                        
#define COM_EQ2_CLRUBOFTXPDUINFO                                      
#define COM_EQ2_CONSTVALUEXINT8UBCLEARMASKENDIDXOFTXPDUINFO           
#define COM_EQ2_CONSTVALUEXINT8UBCLEARMASKSTARTIDXOFTXPDUINFO         
#define COM_EQ2_CONSTVALUEXINT8UBCLEARMASKUSEDOFTXPDUINFO             
#define COM_EQ2_EXTERNALIDOFTXPDUINFO                                 
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO          
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO        
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO            
#define COM_EQ2_INVALIDHNDOFTXPDUINFO                                 
#define COM_EQ2_METADATALENGTHOFTXPDUINFO                             
#define COM_EQ2_PDUWITHMETADATALENGTHOFTXPDUINFO                      
#define COM_EQ2_TXPDUBUFFERENDIDXOFTXPDUINFO                          
#define COM_EQ2_TXPDUBUFFERLENGTHOFTXPDUINFO                          
#define COM_EQ2_TXPDUBUFFERMETADATAENDIDXOFTXPDUINFO                  
#define COM_EQ2_TXPDUBUFFERMETADATASTARTIDXOFTXPDUINFO                
#define COM_EQ2_TXPDUBUFFERMETADATAUSEDOFTXPDUINFO                    
#define COM_EQ2_TXPDUBUFFERSTARTIDXOFTXPDUINFO                        
#define COM_EQ2_TXPDUBUFFERUSEDOFTXPDUINFO                            
#define COM_EQ2_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                     
#define COM_EQ2_TXPDUCALLOUTFUNCPTRUSEDOFTXPDUINFO                    
#define COM_EQ2_TXPDUINITVALUEENDIDXOFTXPDUINFO                       
#define COM_EQ2_TXPDUINITVALUEMETADATAENDIDXOFTXPDUINFO               
#define COM_EQ2_TXPDUINITVALUEMETADATASTARTIDXOFTXPDUINFO             
#define COM_EQ2_TXPDUINITVALUEMETADATAUSEDOFTXPDUINFO                 
#define COM_EQ2_TXPDUINITVALUESTARTIDXOFTXPDUINFO                     
#define COM_EQ2_TXPDUINITVALUEUSEDOFTXPDUINFO                         
#define COM_EQ2_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                   
#define COM_EQ2_TXPDUTTCALLOUTFUNCPTRUSEDOFTXPDUINFO                  
#define COM_EQ2_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                      
#define COM_EQ2_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                    
#define COM_EQ2_TXSIGGRPINFOINDUSEDOFTXPDUINFO                        
#define COM_EQ2_TXTOUTINFOIDXOFTXPDUINFO                              
#define COM_EQ2_TXTOUTINFOUSEDOFTXPDUINFO                             
#define COM_EQ2_TXTPINFOIDXOFTXPDUINFO                                
#define COM_EQ2_TXTPINFOUSEDOFTXPDUINFO                               
#define COM_EQ2_TXPDUINFOIND                                          
#define COM_EQ2_TXPDUINITVALUE                                        
#define COM_EQ2_TXPDUTTCALLOUTFUNCPTR                                 
#define COM_EQ2_ARRAYACCESSUSEDOFTXSIGGRPINFO                         
#define COM_EQ2_INVALIDHNDOFTXSIGGRPINFO                              
#define COM_EQ2_PDUIDOFTXSIGGRPINFO                                   
#define COM_EQ2_PDUOFFSETOFTXSIGGRPINFO                               
#define COM_EQ2_SIGGROUPONCHANGEOFFSETOFTXSIGGRPINFO                  
#define COM_EQ2_SIGGROUPONCHANGESTARTPOSITIONOFTXSIGGRPINFO           
#define COM_EQ2_SIGGROUPONCHANGEWITHOUTREPOFFSETOFTXSIGGRPINFO        
#define COM_EQ2_SIGGROUPONCHANGEWITHOUTREPSTARTPOSITIONOFTXSIGGRPINFO 
#define COM_EQ2_TRANSFERPROPERTYOFTXSIGGRPINFO                        
#define COM_EQ2_TXSHDBUFFERENDIDXOFTXSIGGRPINFO                       
#define COM_EQ2_TXSHDBUFFERLENGTHOFTXSIGGRPINFO                       
#define COM_EQ2_TXSHDBUFFERSTARTIDXOFTXSIGGRPINFO                     
#define COM_EQ2_TXSHDBUFFERUSEDOFTXSIGGRPINFO                         
#define COM_EQ2_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                      
#define COM_EQ2_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                      
#define COM_EQ2_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                    
#define COM_EQ2_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                        
#define COM_EQ2_TXSIGGRPONCHANGEMASKONCHANGEENDIDXOFTXSIGGRPINFO      
#define COM_EQ2_TXSIGGRPONCHANGEMASKONCHANGELENGTHOFTXSIGGRPINFO      
#define COM_EQ2_TXSIGGRPONCHANGEMASKONCHANGESTARTIDXOFTXSIGGRPINFO    
#define COM_EQ2_TXSIGGRPONCHANGEMASKONCHANGEUSEDOFTXSIGGRPINFO        
#define COM_EQ2_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPENDIDXOFTXSIGGRPINFO 
#define COM_EQ2_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPLENGTHOFTXSIGGRPINFO 
#define COM_EQ2_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPSTARTIDXOFTXSIGGRPINFO 
#define COM_EQ2_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPUSEDOFTXSIGGRPINFO 
#define COM_EQ2_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO              
#define COM_EQ2_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO            
#define COM_EQ2_TXSIGINFOINVVALUEINDUSEDOFTXSIGGRPINFO                
#define COM_EQ2_TXTOUTINFOIDXOFTXSIGGRPINFO                           
#define COM_EQ2_TXTOUTINFOUSEDOFTXSIGGRPINFO                          
#define COM_EQ2_UBIDXOFTXSIGGRPINFO                                   
#define COM_EQ2_UBMASKIDXOFTXSIGGRPINFO                               
#define COM_EQ2_UBMASKUSEDOFTXSIGGRPINFO                              
#define COM_EQ2_TXSIGGRPINFOIND                                       
#define COM_EQ2_TXSIGGRPMASK                                          
#define COM_EQ2_TXSIGGRPONCHANGEMASK                                  
#define COM_EQ2_APPLTYPEOFTXSIGINFO                                   
#define COM_EQ2_BITLENGTHOFTXSIGINFO                                  
#define COM_EQ2_BITPOSITIONOFTXSIGINFO                                
#define COM_EQ2_BUSACCOFTXSIGINFO                                     
#define COM_EQ2_BYTELENGTHOFTXSIGINFO                                 
#define COM_EQ2_BYTEPOSITIONOFTXSIGINFO                               
#define COM_EQ2_FILTERINFOIDXOFTXSIGINFO                              
#define COM_EQ2_FILTERINFOUSEDOFTXSIGINFO                             
#define COM_EQ2_FILTERINITVALUEIDXOFTXSIGINFO                         
#define COM_EQ2_FILTERINITVALUEUSEDOFTXSIGINFO                        
#define COM_EQ2_INVVALUEIDXOFTXSIGINFO                                
#define COM_EQ2_INVVALUEUSEDOFTXSIGINFO                               
#define COM_EQ2_INVALIDHNDOFTXSIGINFO                                 
#define COM_EQ2_ONCHANGEIDXOFTXSIGINFO                                
#define COM_EQ2_ONCHANGEUSEDOFTXSIGINFO                               
#define COM_EQ2_PDUIDOFTXSIGINFO                                      
#define COM_EQ2_TRIGGEREDOFTXSIGINFO                                  
#define COM_EQ2_TXFILTERINITSTATEIDXOFTXSIGINFO                       
#define COM_EQ2_TXFILTERINITSTATEUSEDOFTXSIGINFO                      
#define COM_EQ2_TXSIGGRPINFOIDXOFTXSIGINFO                            
#define COM_EQ2_TXSIGGRPINFOUSEDOFTXSIGINFO                           
#define COM_EQ2_TXTOUTINFOIDXOFTXSIGINFO                              
#define COM_EQ2_TXTOUTINFOUSEDOFTXSIGINFO                             
#define COM_EQ2_UBIDXOFTXSIGINFO                                      
#define COM_EQ2_UBMASKIDXOFTXSIGINFO                                  
#define COM_EQ2_UBMASKUSEDOFTXSIGINFO                                 
#define COM_EQ2_WITHOUTREPOFTXSIGINFO                                 
#define COM_EQ2_TXSIGINFOFILTERINITVALUEIND                           
#define COM_EQ2_TXSIGINFOINVVALUEIND                                  
#define COM_EQ2_CBKTXTOUTFUNCPTRENDIDXOFTXTOUTINFO                    
#define COM_EQ2_CBKTXTOUTFUNCPTRSTARTIDXOFTXTOUTINFO                  
#define COM_EQ2_CBKTXTOUTFUNCPTRUSEDOFTXTOUTINFO                      
#define COM_EQ2_FACTOROFTXTOUTINFO                                    
#define COM_EQ2_NONEMODEOFTXTOUTINFO                                  
#define COM_EQ2_TXPDUINFOIDXOFTXTOUTINFO                              
#define COM_EQ2_TXPDUINFOUSEDOFTXTOUTINFO                             
#define COM_EQ2_BUFFERSIZEOFTXTPINFO                                  
#define COM_EQ2_TXPDUBUFFERENDIDXOFTXTPINFO                           
#define COM_EQ2_TXPDUBUFFERLENGTHOFTXTPINFO                           
#define COM_EQ2_TXPDUBUFFERSTARTIDXOFTXTPINFO                         
#define COM_EQ2_TXPDUBUFFERUSEDOFTXTPINFO                             
#define COM_EQ2_TXSIGINFODYNSIGIDXOFTXTPINFO                          
#define COM_EQ2_TXSIGINFODYNSIGUSEDOFTXTPINFO                         
#define COM_EQ2_CBKRXACKFUNCPTROFPCCONFIG                             Com_CbkRxAckFuncPtr
#define COM_EQ2_CBKRXTOUTFUNCPTROFPCCONFIG                            Com_CbkRxTOutFuncPtr
#define COM_EQ2_CONSTVALUEXINT16OFPCCONFIG                            Com_ConstValueXInt16
#define COM_EQ2_CONSTVALUEXINT8OFPCCONFIG                             Com_ConstValueXInt8
#define COM_EQ2_CURRENTTXMODEOFPCCONFIG                               Com_CurrentTxMode.raw
#define COM_EQ2_CYCLETIMECNTOFPCCONFIG                                Com_CycleTimeCnt.raw
#define COM_EQ2_CYCLICSENDREQUESTOFPCCONFIG                           Com_CyclicSendRequest.raw
#define COM_EQ2_FINALMAGICNUMBEROFPCCONFIG                            
#define COM_EQ2_HANDLERXPDUDEFERREDOFPCCONFIG                         Com_HandleRxPduDeferred.raw
#define COM_EQ2_HANDLETXPDUDEFERREDOFPCCONFIG                         Com_HandleTxPduDeferred
#define COM_EQ2_INITDATAHASHCODEOFPCCONFIG                            
#define COM_EQ2_INITIALIZEDOFPCCONFIG                                 Com_Initialized
#define COM_EQ2_PDUGRPVECTOROFPCCONFIG                                Com_PduGrpVector
#define COM_EQ2_REPCNTOFPCCONFIG                                      Com_RepCnt.raw
#define COM_EQ2_REPCYCLECNTOFPCCONFIG                                 Com_RepCycleCnt.raw
#define COM_EQ2_RXACCESSINFOINDOFPCCONFIG                             Com_RxAccessInfoInd
#define COM_EQ2_RXACCESSINFOOFPCCONFIG                                Com_RxAccessInfo
#define COM_EQ2_RXACCESSINFOREPLACESIGINDOFPCCONFIG                   Com_RxAccessInfoReplaceSigInd
#define COM_EQ2_RXDEFPDUBUFFEROFPCCONFIG                              Com_RxDefPduBuffer.raw
#define COM_EQ2_RXGRPSIGINFOOFPCCONFIG                                Com_RxGrpSigInfo
#define COM_EQ2_RXPDUDMSTATEOFPCCONFIG                                Com_RxPduDmState
#define COM_EQ2_RXPDUGRPACTIVEOFPCCONFIG                              Com_RxPduGrpActive
#define COM_EQ2_RXPDUGRPINFOOFPCCONFIG                                Com_RxPduGrpInfo
#define COM_EQ2_RXPDUINFOOFPCCONFIG                                   Com_RxPduInfo
#define COM_EQ2_RXSHDBUFFERXINT16OFPCCONFIG                           Com_RxShdBufferXInt16.raw
#define COM_EQ2_RXSHDBUFFERXINT8OFPCCONFIG                            Com_RxShdBufferXInt8.raw
#define COM_EQ2_RXSIGBUFFERXINT16OFPCCONFIG                           Com_RxSigBufferXInt16.raw
#define COM_EQ2_RXSIGBUFFERXINT8OFPCCONFIG                            Com_RxSigBufferXInt8.raw
#define COM_EQ2_RXSIGGRPINFOINDOFPCCONFIG                             Com_RxSigGrpInfoInd
#define COM_EQ2_RXSIGGRPINFOOFPCCONFIG                                Com_RxSigGrpInfo
#define COM_EQ2_RXSIGINFOOFPCCONFIG                                   Com_RxSigInfo
#define COM_EQ2_RXTOUTCNTOFPCCONFIG                                   Com_RxTOutCnt
#define COM_EQ2_RXTOUTINFOINDOFPCCONFIG                               Com_RxTOutInfoInd
#define COM_EQ2_RXTOUTINFOOFPCCONFIG                                  Com_RxTOutInfo
#define COM_EQ2_SIGGRPEVENTFLAGOFPCCONFIG                             Com_SigGrpEventFlag
#define COM_EQ2_TMPRXBUFFEROFPCCONFIG                                 Com_TmpRxBuffer
#define COM_EQ2_TMPRXSHDBUFFERXINT16OFPCCONFIG                        Com_TmpRxShdBufferXInt16.raw
#define COM_EQ2_TMPRXSHDBUFFERXINT8OFPCCONFIG                         Com_TmpRxShdBufferXInt8.raw
#define COM_EQ2_TRANSMITREQUESTOFPCCONFIG                             Com_TransmitRequest.raw
#define COM_EQ2_TXMODEINFOOFPCCONFIG                                  Com_TxModeInfo
#define COM_EQ2_TXMODETRUEOFPCCONFIG                                  Com_TxModeTrue
#define COM_EQ2_TXPDUBUFFEROFPCCONFIG                                 Com_TxPduBuffer.raw
#define COM_EQ2_TXPDUGRPACTIVEOFPCCONFIG                              Com_TxPduGrpActive
#define COM_EQ2_TXPDUGRPINFOOFPCCONFIG                                Com_TxPduGrpInfo
#define COM_EQ2_TXPDUINFOOFPCCONFIG                                   Com_TxPduInfo
#define COM_EQ2_TXPDUINITVALUEOFPCCONFIG                              Com_TxPduInitValue
#define COM_EQ2_TXSDULENGTHOFPCCONFIG                                 Com_TxSduLength
#define COM_EQ2_TXSHDBUFFEROFPCCONFIG                                 Com_TxShdBuffer.raw
#define COM_EQ2_TXSIGGRPINFOINDOFPCCONFIG                             Com_TxSigGrpInfoInd
#define COM_EQ2_TXSIGGRPINFOOFPCCONFIG                                Com_TxSigGrpInfo
#define COM_EQ2_TXSIGGRPMASKOFPCCONFIG                                Com_TxSigGrpMask
#define COM_EQ2_TXSIGINFOOFPCCONFIG                                   Com_TxSigInfo
#define COM_EQ2_WAITINGFORCONFIRMATIONOFPCCONFIG                      Com_WaitingForConfirmation
/** 
  \}
*/ 

/** 
  \defgroup  PCSymbolicInitializationPointers  Symbolic Initialization Pointers (PRE-COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Com_Config_Ptr                                                NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Com' */
/** 
  \}
*/ 

/** 
  \defgroup  PCInitializationSymbols  Initialization Symbols (PRE-COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Com_Config                                                    NULL_PTR  /**< symbolic identifier which could be used to initialize 'Com */
/** 
  \}
*/ 

/** 
  \defgroup  PCGeneral  General (PRE-COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define COM_CHECK_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define COM_FINAL_MAGIC_NUMBER                                        0x321EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of Com */
#define COM_INDIVIDUAL_POSTBUILD                                      STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Com' is not configured to be postbuild capable. */
#define COM_INIT_DATA                                                 COM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define COM_INIT_DATA_HASH_CODE                                       -2111758871L  /**< the precompile constant to validate the initialization structure at initialization time of Com with a hashcode. The seed value is '0x321EU' */
#define COM_USE_ECUM_BSW_ERROR_HOOK                                   STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define COM_USE_INIT_POINTER                                          STD_OFF  /**< STD_ON if the init pointer Com shall be used. */
/** 
  \}
*/ 



/* General */
#define COM_DEV_ERROR_DETECT                 STD_ON  /**< /ActiveEcuC/EcuC/EcucGeneral[0:EcuCSafeBswChecks] || /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_DEV_ERROR_REPORT                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_TSI_TESTCODE                     STD_OFF
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS   STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComRetryFailedTransmitRequests] */
#define COM_IPDUCALLOUT_USEPDUINFOPTR        STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComAdvancedIPduCallouts] */

/* Optimization */
#define COM_OFTENER_SHORTER                  0U
#define COM_FEWER_LONGER                     1U
#define COM_EXCLUSIVE_AREA_RX_USAGE          COM_OFTENER_SHORTER
#define COM_EXCLUSIVE_AREA_TX_USAGE          COM_OFTENER_SHORTER
#define COM_EXCLUSIVE_AREA_ROUTE_USAGE       COM_OFTENER_SHORTER

/* API */
#define COM_COMMUNICATION_INTERFACE          STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRCommunicationInterface] */
#define COM_TRANSPORT_PROTOCOL               STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTransportProtocol] */

#define COM_TRIGGER_TRANSMIT_API             STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTriggertransmit] */
#define COM_TX_CONFIRMATION_API              STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTxConfirmation] */
#define COM_TRIGGER_IPDU_SEND_API            STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComTriggerIPDUSendApi] */
#define COM_TRIGGER_IPDU_SEND_WITH_META_DATA_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] */
#define COM_SWITCH_IPDU_TX_MODE_API          STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComSwitchIpduTxModeApi] */
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] */

#define COM_IPDU_GROUP_CONTROL_API           STD_ON
#define COM_RECEPTION_DM_CONTROL_API         STD_ON

#define COM_IPDU_GROUP_START_API             STD_OFF
#define COM_IPDU_GROUP_STOP_API              STD_OFF
#define COM_ENABLE_RECEPTION_DM_API          STD_OFF
#define COM_DISABLE_RECEPTION_DM_API         STD_OFF

#define COM_DE_INIT_API                      STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComDeInitApi] */
#define COM_GET_STATUS_API                   STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComGetStatusApi] */
#define COM_VERSION_INFO_API                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComVersionInfoApi] */

/* Com_TxModeHdlr */
#if ((COM_PERIODICOFTXMODETRUE == STD_OFF) && (COM_PERIODICOFTXMODEFALSE == STD_OFF))
# define COM_TXMODEHDLR_CYCLIC_TRANSMISSION               STD_OFF
#else
# define COM_TXMODEHDLR_CYCLIC_TRANSMISSION               STD_ON
#endif
#if ((COM_DIRECTOFTXMODETRUE == STD_OFF) && (COM_DIRECTOFTXMODEFALSE == STD_OFF))
# define COM_TXMODEHDLR_DIRECT_TRANSMISSION               STD_OFF
#else
# define COM_TXMODEHDLR_DIRECT_TRANSMISSION               STD_ON
#endif
#if ((COM_REPCNTOFTXMODETRUE == STD_OFF) && (COM_REPCNTOFTXMODEFALSE == STD_OFF))
# define COM_TXMODEHDLR_DIRECT_REPETITION                 STD_OFF
#else
# define COM_TXMODEHDLR_DIRECT_REPETITION                 STD_ON
#endif

#if ((COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO == STD_ON) || (COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO == STD_ON))
# define COM_EXISTS_DEFERRED_SIGNALPROCESSING             STD_ON
#else
# define COM_EXISTS_DEFERRED_SIGNALPROCESSING             STD_OFF
#endif

#if ((COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGGRPINFO == STD_ON) || (COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO == STD_ON))
# define COM_EXISTS_IMMEDIATE_SIGNALPROCESSING            STD_ON
#else
# define COM_EXISTS_IMMEDIATE_SIGNALPROCESSING            STD_OFF
#endif

#define COM_LMGT_MAXIPDUGROUPVECTORBYTECNT                1U


/* \defgroup Handle IDs of handle space ComRxSig [Rx Signals].
 * \{
 */
 
/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComGroupSignal_E2E_RxFilteredSpeedSft_cb1e8587        16
#define ComConf_ComGroupSignal_E2E_Rx_CRC_cb1e8587                    17
#define ComConf_ComGroupSignal_E2E_Rx_SeqNumber_cb1e8587              18
#define ComConf_ComSignal_BrkLamp_B_Rq_610999c4                       0
#define ComConf_ComSignal_BtnCES_Down_c0440b7e                        1
#define ComConf_ComSignal_BtnCES_Left_c0440b7e                        2
#define ComConf_ComSignal_BtnCES_OK_c0440b7e                          3
#define ComConf_ComSignal_BtnCES_Right_c0440b7e                       4
#define ComConf_ComSignal_BtnCES_Up_c0440b7e                          5
#define ComConf_ComSignal_Button_1_c0440b7e                           6
#define ComConf_ComSignal_Button_2_c0440b7e                           7
#define ComConf_ComSignal_Button_3_c0440b7e                           8
#define ComConf_ComSignal_Button_4_c0440b7e                           9
#define ComConf_ComSignal_Button_5_c0440b7e                           10
#define ComConf_ComSignal_DimGeneral_0e65ef90                         11
#define ComConf_ComSignal_Disable_Neutral_Tow_610999c4                12
#define ComConf_ComSignal_DownTranOfEngCoolantTempCAN_46dad878        13
#define ComConf_ComSignal_DrStatDrv_B_Actl_610999c4                   14
#define ComConf_ComSignal_DrStatPsngr_B_Actl_610999c4                 15
#define ComConf_ComSignal_Enable_Neutral_Tow_610999c4                 19
#define ComConf_ComSignal_EngineCoolantTempCAN_46dad878               20
#define ComConf_ComSignal_FOTA_Request_e06f7a0b                       21
#define ComConf_ComSignal_FUEL_LEVEL_CAN_24f27db7                     22
#define ComConf_ComSignal_KeyPos_70b9e74d                             23
#define ComConf_ComSignal_LeftTurnOn_365ba238                         24
#define ComConf_ComSignal_MyKey_Active_610999c4                       25
#define ComConf_ComSignal_NewRollingOdo_9d7d00df                      26
#define ComConf_ComSignal_RightTurnOn_365ba238                        27
#define ComConf_ComSignal_Slow_For_HDC_610999c4                       28
#define ComConf_ComSignal_SpeedRef_a9ab8ab7                           29
#define ComConf_ComSignal_TachoRef_3db35f78                           30
#define ComConf_ComSignal_Tire_Press_System_Stat_610999c4             31
#define ComConf_ComSignal_WarningWaterTempCAN_46dad878                32
/**
 * \ }
 */

/* \defgroup Handle IDs of handle space ComTxSig [Tx Signals].
 * \{
 */
 
/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComGroupSignal_E2E_TxFilteredSpeedSft_701521af        0
#define ComConf_ComGroupSignal_E2E_Tx_CRC_701521af                    1
#define ComConf_ComGroupSignal_E2E_Tx_SeqNumber_701521af              2
#define ComConf_ComSignal_EcuStatus_B0_ResetReason_f1c308b8           3
#define ComConf_ComSignal_EcuStatus_B1_HookReason_f1c308b8            4
#define ComConf_ComSignal_EcuStatus_B2_HookArgument_f1c308b8          5
#define ComConf_ComSignal_EcuStatus_B3_f1c308b8                       6
#define ComConf_ComSignal_EcuStatus_B4_f1c308b8                       7
#define ComConf_ComSignal_EcuStatus_B5_f1c308b8                       8
#define ComConf_ComSignal_EcuStatus_B6_f1c308b8                       9
#define ComConf_ComSignal_EcuStatus_B7_f1c308b8                       10
#define ComConf_ComSignal_FOTA_Responce_4123962b                      11
#define ComConf_ComSignal_SpeedFiltered_15b15a3c                      12
#define ComConf_ComSignal_TachoFiltered_15b15a3c                      13
#define ComConf_ComSignal_WrnAllTTOn_15b15a3c                         14
/**
 * \ }
 */



/* \defgroup Handle IDs of handle space comRxSigGrp [Rx SignalGroups].
 * \{
 */
 
/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignalGroup_SG_RxFilteredSpeed_a536058e            0
/**
 * \ }
 */

/* \defgroup Handle IDs of handle space comTxSigGrp [Tx SignalGroups].
 * \{
 */
 
/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignalGroup_SG_TxFilteredSpeed_196f5849            0
/**
 * \ }
 */



/* \defgroup Handle IDs.
 * \{
 */
 
/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPduGroup_TuringECU_oCAN_Rx_fcef2243               0
#define ComConf_ComIPduGroup_TuringECU_oCAN_Tx_fcef2243               1
/**
 * \ }
 */


/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE-COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PCGetRootDataMacros  Get Root Data Macros (PRE-COMPILE)
  \brief  These are used to get data pointers of root data.
  \{
*/ 
#define Com_GetFinalMagicNumberOfPCConfig()                           
#define Com_GetInitDataHashCodeOfPCConfig()                           
/** 
  \}
*/ 

/** 
  \defgroup  PCGetDuplicatedRootDataMacros  Get Duplicated Root Data Macros (PRE-COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Com_GetAllSigCntOfPCConfig()                                  48UL
#define Com_GetAllSigGrpCntOfPCConfig()                               2UL
#define Com_GetCbkRxAckFuncPtrOfPCConfig()                            Com_CbkRxAckFuncPtr  /**< the pointer to Com_CbkRxAckFuncPtr */
#define Com_GetCbkRxTOutFuncPtrOfPCConfig()                           Com_CbkRxTOutFuncPtr  /**< the pointer to Com_CbkRxTOutFuncPtr */
#define Com_GetConfigIdOfPCConfig()                                   0UL  /**< DefinitionRef: /MICROSAR/Com/ComConfig/ComConfigurationId */
#define Com_GetConstValueXInt16OfPCConfig()                           Com_ConstValueXInt16  /**< the pointer to Com_ConstValueXInt16 */
#define Com_GetConstValueXInt8OfPCConfig()                            Com_ConstValueXInt8  /**< the pointer to Com_ConstValueXInt8 */
#define Com_GetCurrentTxModeOfPCConfig()                              Com_CurrentTxMode.raw  /**< the pointer to Com_CurrentTxMode */
#define Com_GetCycleTimeCntOfPCConfig()                               Com_CycleTimeCnt.raw  /**< the pointer to Com_CycleTimeCnt */
#define Com_GetCyclicSendRequestOfPCConfig()                          Com_CyclicSendRequest.raw  /**< the pointer to Com_CyclicSendRequest */
#define Com_GetHandleRxPduDeferredOfPCConfig()                        Com_HandleRxPduDeferred.raw  /**< the pointer to Com_HandleRxPduDeferred */
#define Com_GetHandleTxPduDeferredOfPCConfig()                        Com_HandleTxPduDeferred  /**< the pointer to Com_HandleTxPduDeferred */
#define Com_GetInitializedOfPCConfig()                                Com_Initialized  /**< the pointer to Com_Initialized */
#define Com_GetPduGrpCntOfPCConfig()                                  2UL
#define Com_GetPduGrpVectorOfPCConfig()                               Com_PduGrpVector  /**< the pointer to Com_PduGrpVector */
#define Com_GetRepCntOfPCConfig()                                     Com_RepCnt.raw  /**< the pointer to Com_RepCnt */
#define Com_GetRepCycleCntOfPCConfig()                                Com_RepCycleCnt.raw  /**< the pointer to Com_RepCycleCnt */
#define Com_GetRxAccessInfoIndOfPCConfig()                            Com_RxAccessInfoInd  /**< the pointer to Com_RxAccessInfoInd */
#define Com_GetRxAccessInfoOfPCConfig()                               Com_RxAccessInfo  /**< the pointer to Com_RxAccessInfo */
#define Com_GetRxAccessInfoReplaceSigIndOfPCConfig()                  Com_RxAccessInfoReplaceSigInd  /**< the pointer to Com_RxAccessInfoReplaceSigInd */
#define Com_GetRxDefPduBufferOfPCConfig()                             Com_RxDefPduBuffer.raw  /**< the pointer to Com_RxDefPduBuffer */
#define Com_GetRxGrpSigInfoOfPCConfig()                               Com_RxGrpSigInfo  /**< the pointer to Com_RxGrpSigInfo */
#define Com_GetRxPduDmStateOfPCConfig()                               Com_RxPduDmState  /**< the pointer to Com_RxPduDmState */
#define Com_GetRxPduGrpActiveOfPCConfig()                             Com_RxPduGrpActive  /**< the pointer to Com_RxPduGrpActive */
#define Com_GetRxPduGrpInfoOfPCConfig()                               Com_RxPduGrpInfo  /**< the pointer to Com_RxPduGrpInfo */
#define Com_GetRxPduInfoOfPCConfig()                                  Com_RxPduInfo  /**< the pointer to Com_RxPduInfo */
#define Com_GetRxShdBufferXInt16OfPCConfig()                          Com_RxShdBufferXInt16.raw  /**< the pointer to Com_RxShdBufferXInt16 */
#define Com_GetRxShdBufferXInt8OfPCConfig()                           Com_RxShdBufferXInt8.raw  /**< the pointer to Com_RxShdBufferXInt8 */
#define Com_GetRxSigBufferXInt16OfPCConfig()                          Com_RxSigBufferXInt16.raw  /**< the pointer to Com_RxSigBufferXInt16 */
#define Com_GetRxSigBufferXInt8OfPCConfig()                           Com_RxSigBufferXInt8.raw  /**< the pointer to Com_RxSigBufferXInt8 */
#define Com_GetRxSigGrpInfoIndOfPCConfig()                            Com_RxSigGrpInfoInd  /**< the pointer to Com_RxSigGrpInfoInd */
#define Com_GetRxSigGrpInfoOfPCConfig()                               Com_RxSigGrpInfo  /**< the pointer to Com_RxSigGrpInfo */
#define Com_GetRxSigInfoOfPCConfig()                                  Com_RxSigInfo  /**< the pointer to Com_RxSigInfo */
#define Com_GetRxTOutCntOfPCConfig()                                  Com_RxTOutCnt  /**< the pointer to Com_RxTOutCnt */
#define Com_GetRxTOutInfoIndOfPCConfig()                              Com_RxTOutInfoInd  /**< the pointer to Com_RxTOutInfoInd */
#define Com_GetRxTOutInfoOfPCConfig()                                 Com_RxTOutInfo  /**< the pointer to Com_RxTOutInfo */
#define Com_GetSigGrpEventFlagOfPCConfig()                            Com_SigGrpEventFlag  /**< the pointer to Com_SigGrpEventFlag */
#define Com_GetSizeOfCbkRxAckFuncPtrOfPCConfig()                      8U  /**< the number of elements in Com_CbkRxAckFuncPtr */
#define Com_GetSizeOfCbkRxTOutFuncPtrOfPCConfig()                     6U  /**< the number of elements in Com_CbkRxTOutFuncPtr */
#define Com_GetSizeOfConstValueXInt16OfPCConfig()                     2U  /**< the number of elements in Com_ConstValueXInt16 */
#define Com_GetSizeOfConstValueXInt8OfPCConfig()                      8U  /**< the number of elements in Com_ConstValueXInt8 */
#define Com_GetSizeOfCurrentTxModeOfPCConfig()                        4U  /**< the number of elements in Com_CurrentTxMode */
#define Com_GetSizeOfCycleTimeCntOfPCConfig()                         4U  /**< the number of elements in Com_CycleTimeCnt */
#define Com_GetSizeOfCyclicSendRequestOfPCConfig()                    4U  /**< the number of elements in Com_CyclicSendRequest */
#define Com_GetSizeOfHandleRxPduDeferredOfPCConfig()                  12U  /**< the number of elements in Com_HandleRxPduDeferred */
#define Com_GetSizeOfHandleTxPduDeferredOfPCConfig()                  4U  /**< the number of elements in Com_HandleTxPduDeferred */
#define Com_GetSizeOfPduGrpVectorOfPCConfig()                         2U  /**< the number of elements in Com_PduGrpVector */
#define Com_GetSizeOfRepCntOfPCConfig()                               4U  /**< the number of elements in Com_RepCnt */
#define Com_GetSizeOfRepCycleCntOfPCConfig()                          4U  /**< the number of elements in Com_RepCycleCnt */
#define Com_GetSizeOfRxAccessInfoIndOfPCConfig()                      33U  /**< the number of elements in Com_RxAccessInfoInd */
#define Com_GetSizeOfRxAccessInfoOfPCConfig()                         33U  /**< the number of elements in Com_RxAccessInfo */
#define Com_GetSizeOfRxAccessInfoReplaceSigIndOfPCConfig()            1U  /**< the number of elements in Com_RxAccessInfoReplaceSigInd */
#define Com_GetSizeOfRxDefPduBufferOfPCConfig()                       45U  /**< the number of elements in Com_RxDefPduBuffer */
#define Com_GetSizeOfRxGrpSigInfoOfPCConfig()                         3U  /**< the number of elements in Com_RxGrpSigInfo */
#define Com_GetSizeOfRxPduDmStateOfPCConfig()                         4U  /**< the number of elements in Com_RxPduDmState */
#define Com_GetSizeOfRxPduGrpActiveOfPCConfig()                       12U  /**< the number of elements in Com_RxPduGrpActive */
#define Com_GetSizeOfRxPduGrpInfoOfPCConfig()                         12U  /**< the number of elements in Com_RxPduGrpInfo */
#define Com_GetSizeOfRxPduInfoOfPCConfig()                            12U  /**< the number of elements in Com_RxPduInfo */
#define Com_GetSizeOfRxShdBufferXInt16OfPCConfig()                    1U  /**< the number of elements in Com_RxShdBufferXInt16 */
#define Com_GetSizeOfRxShdBufferXInt8OfPCConfig()                     2U  /**< the number of elements in Com_RxShdBufferXInt8 */
#define Com_GetSizeOfRxSigBufferXInt16OfPCConfig()                    5U  /**< the number of elements in Com_RxSigBufferXInt16 */
#define Com_GetSizeOfRxSigBufferXInt8OfPCConfig()                     35U  /**< the number of elements in Com_RxSigBufferXInt8 */
#define Com_GetSizeOfRxSigGrpInfoIndOfPCConfig()                      1U  /**< the number of elements in Com_RxSigGrpInfoInd */
#define Com_GetSizeOfRxSigGrpInfoOfPCConfig()                         1U  /**< the number of elements in Com_RxSigGrpInfo */
#define Com_GetSizeOfRxSigInfoOfPCConfig()                            30U  /**< the number of elements in Com_RxSigInfo */
#define Com_GetSizeOfRxTOutCntOfPCConfig()                            4U  /**< the number of elements in Com_RxTOutCnt */
#define Com_GetSizeOfRxTOutInfoIndOfPCConfig()                        4U  /**< the number of elements in Com_RxTOutInfoInd */
#define Com_GetSizeOfRxTOutInfoOfPCConfig()                           4U  /**< the number of elements in Com_RxTOutInfo */
#define Com_GetSizeOfSigGrpEventFlagOfPCConfig()                      1U  /**< the number of elements in Com_SigGrpEventFlag */
#define Com_GetSizeOfTmpRxBufferOfPCConfig()                          8U  /**< the number of elements in Com_TmpRxBuffer */
#define Com_GetSizeOfTmpRxShdBufferXInt16OfPCConfig()                 1U  /**< the number of elements in Com_TmpRxShdBufferXInt16 */
#define Com_GetSizeOfTmpRxShdBufferXInt8OfPCConfig()                  2U  /**< the number of elements in Com_TmpRxShdBufferXInt8 */
#define Com_GetSizeOfTransmitRequestOfPCConfig()                      4U  /**< the number of elements in Com_TransmitRequest */
#define Com_GetSizeOfTxModeInfoOfPCConfig()                           4U  /**< the number of elements in Com_TxModeInfo */
#define Com_GetSizeOfTxModeTrueOfPCConfig()                           2U  /**< the number of elements in Com_TxModeTrue */
#define Com_GetSizeOfTxPduBufferOfPCConfig()                          26U  /**< the number of elements in Com_TxPduBuffer */
#define Com_GetSizeOfTxPduGrpActiveOfPCConfig()                       4U  /**< the number of elements in Com_TxPduGrpActive */
#define Com_GetSizeOfTxPduGrpInfoOfPCConfig()                         4U  /**< the number of elements in Com_TxPduGrpInfo */
#define Com_GetSizeOfTxPduInfoOfPCConfig()                            4U  /**< the number of elements in Com_TxPduInfo */
#define Com_GetSizeOfTxPduInitValueOfPCConfig()                       26U  /**< the number of elements in Com_TxPduInitValue */
#define Com_GetSizeOfTxSduLengthOfPCConfig()                          4U  /**< the number of elements in Com_TxSduLength */
#define Com_GetSizeOfTxShdBufferOfPCConfig()                          4U  /**< the number of elements in Com_TxShdBuffer */
#define Com_GetSizeOfTxSigGrpInfoIndOfPCConfig()                      1U  /**< the number of elements in Com_TxSigGrpInfoInd */
#define Com_GetSizeOfTxSigGrpInfoOfPCConfig()                         1U  /**< the number of elements in Com_TxSigGrpInfo */
#define Com_GetSizeOfTxSigGrpMaskOfPCConfig()                         4U  /**< the number of elements in Com_TxSigGrpMask */
#define Com_GetSizeOfTxSigInfoOfPCConfig()                            15U  /**< the number of elements in Com_TxSigInfo */
#define Com_GetSizeOfWaitingForConfirmationOfPCConfig()               4U  /**< the number of elements in Com_WaitingForConfirmation */
#define Com_GetTmpRxBufferOfPCConfig()                                Com_TmpRxBuffer  /**< the pointer to Com_TmpRxBuffer */
#define Com_GetTmpRxShdBufferXInt16OfPCConfig()                       Com_TmpRxShdBufferXInt16.raw  /**< the pointer to Com_TmpRxShdBufferXInt16 */
#define Com_GetTmpRxShdBufferXInt8OfPCConfig()                        Com_TmpRxShdBufferXInt8.raw  /**< the pointer to Com_TmpRxShdBufferXInt8 */
#define Com_GetTransmitRequestOfPCConfig()                            Com_TransmitRequest.raw  /**< the pointer to Com_TransmitRequest */
#define Com_GetTxModeInfoOfPCConfig()                                 Com_TxModeInfo  /**< the pointer to Com_TxModeInfo */
#define Com_GetTxModeTrueOfPCConfig()                                 Com_TxModeTrue  /**< the pointer to Com_TxModeTrue */
#define Com_GetTxPduBufferOfPCConfig()                                Com_TxPduBuffer.raw  /**< the pointer to Com_TxPduBuffer */
#define Com_GetTxPduGrpActiveOfPCConfig()                             Com_TxPduGrpActive  /**< the pointer to Com_TxPduGrpActive */
#define Com_GetTxPduGrpInfoOfPCConfig()                               Com_TxPduGrpInfo  /**< the pointer to Com_TxPduGrpInfo */
#define Com_GetTxPduInfoOfPCConfig()                                  Com_TxPduInfo  /**< the pointer to Com_TxPduInfo */
#define Com_GetTxPduInitValueOfPCConfig()                             Com_TxPduInitValue  /**< the pointer to Com_TxPduInitValue */
#define Com_GetTxSduLengthOfPCConfig()                                Com_TxSduLength  /**< the pointer to Com_TxSduLength */
#define Com_GetTxShdBufferOfPCConfig()                                Com_TxShdBuffer.raw  /**< the pointer to Com_TxShdBuffer */
#define Com_GetTxSigGrpInfoIndOfPCConfig()                            Com_TxSigGrpInfoInd  /**< the pointer to Com_TxSigGrpInfoInd */
#define Com_GetTxSigGrpInfoOfPCConfig()                               Com_TxSigGrpInfo  /**< the pointer to Com_TxSigGrpInfo */
#define Com_GetTxSigGrpMaskOfPCConfig()                               Com_TxSigGrpMask  /**< the pointer to Com_TxSigGrpMask */
#define Com_GetTxSigInfoOfPCConfig()                                  Com_TxSigInfo  /**< the pointer to Com_TxSigInfo */
#define Com_GetWaitingForConfirmationOfPCConfig()                     Com_WaitingForConfirmation  /**< the pointer to Com_WaitingForConfirmation */
/** 
  \}
*/ 

/** 
  \defgroup  PCGetDataMacros  Get Data Macros (PRE-COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Com_GetCbkInvFuncPtr(Index)                                   
#define Com_GetCbkRxAckFuncPtr(Index)                                 Com_GetCbkRxAckFuncPtrOfPCConfig()[(Index)]
#define Com_GetCbkRxTOutFuncPtr(Index)                                Com_GetCbkRxTOutFuncPtrOfPCConfig()[(Index)]
#define Com_GetCbkTxAckDefFuncPtr(Index)                              
#define Com_GetCbkTxAckImFuncPtr(Index)                               
#define Com_GetCbkTxErrFuncPtr(Index)                                 
#define Com_GetCbkTxTOutFuncPtr(Index)                                
#define Com_GetConstValueXInt16(Index)                                Com_GetConstValueXInt16OfPCConfig()[(Index)]
#define Com_GetConstValueXInt32(Index)                                
#define Com_GetConstValueXInt8(Index)                                 Com_GetConstValueXInt8OfPCConfig()[(Index)]
#define Com_IsCurrentTxMode(Index)                                    ((Com_GetCurrentTxModeOfPCConfig()[(Index)]) != FALSE)
#define Com_GetCycleTimeCnt(Index)                                    Com_GetCycleTimeCntOfPCConfig()[(Index)]
#define Com_IsCyclicSendRequest(Index)                                ((Com_GetCyclicSendRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetDelayTimeCnt(Index)                                    
#define Com_GetApplTypeOfFilterInfo(Index)                            
#define Com_GetFilterAlgoOfFilterInfo(Index)                          
#define Com_GetFilterParamIdxOfFilterInfo(Index)                      
#define Com_IsFilterParamUsedOfFilterInfo(Index)                      
#define Com_GetLengthOfFilterInfo(Index)                              
#define Com_IsGwEvent(Index)                                          
#define Com_GetRxAccessInfoIdxOfGwGrpSigMapping(Index)                
#define Com_GetTxSigIdOfGwGrpSigMapping(Index)                        
#define Com_GetGwSigGrpMappingEndIdxOfGwInfo(Index)                   
#define Com_GetGwSigGrpMappingStartIdxOfGwInfo(Index)                 
#define Com_IsGwSigGrpMappingUsedOfGwInfo(Index)                      
#define Com_GetGwSigMappingEndIdxOfGwInfo(Index)                      
#define Com_GetGwSigMappingStartIdxOfGwInfo(Index)                    
#define Com_IsGwSigMappingUsedOfGwInfo(Index)                         
#define Com_GetGwGrpSigMappingEndIdxOfGwSigGrpMapping(Index)          
#define Com_GetGwGrpSigMappingStartIdxOfGwSigGrpMapping(Index)        
#define Com_GetTxSigGrpIdOfGwSigGrpMapping(Index)                     
#define Com_GetRxAccessInfoIdxOfGwSigMapping(Index)                   
#define Com_GetTxSigIdOfGwSigMapping(Index)                           
#define Com_GetHandleRxPduDeferred(Index)                             Com_GetHandleRxPduDeferredOfPCConfig()[(Index)]
#define Com_IsHandleTxPduDeferred(Index)                              ((Com_GetHandleTxPduDeferredOfPCConfig()[(Index)]) != FALSE)
#define Com_GetIPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo(Index) 
#define Com_GetIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo(Index) 
#define Com_IsIPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo(Index) 
#define Com_IsInvalidHndOfIPduGroupInfo(Index)                        
#define Com_GetRxPduInfoIndEndIdxOfIPduGroupInfo(Index)               
#define Com_GetRxPduInfoIndStartIdxOfIPduGroupInfo(Index)             
#define Com_IsRxPduInfoIndUsedOfIPduGroupInfo(Index)                  
#define Com_GetTxPduInfoIndEndIdxOfIPduGroupInfo(Index)               
#define Com_GetTxPduInfoIndStartIdxOfIPduGroupInfo(Index)             
#define Com_IsTxPduInfoIndUsedOfIPduGroupInfo(Index)                  
#define Com_GetIPduGroupInfoOfRxPduInfoInd(Index)                     
#define Com_GetIPduGroupInfoOfTxPduInfoInd(Index)                     
#define Com_GetIPduGroupInfoToSubIPduGroupsInd(Index)                 
#define Com_GetIPduGroupState(Index)                                  
#define Com_IsInitialized()                                           ((Com_GetInitializedOfPCConfig()) != FALSE)
#define Com_GetPduGrpVector(Index)                                    Com_GetPduGrpVectorOfPCConfig()[(Index)]
#define Com_GetRepCnt(Index)                                          Com_GetRepCntOfPCConfig()[(Index)]
#define Com_GetRepCycleCnt(Index)                                     Com_GetRepCycleCntOfPCConfig()[(Index)]
#define Com_GetApplTypeOfRxAccessInfo(Index)                          Com_GetRxAccessInfoOfPCConfig()[(Index)].ApplTypeOfRxAccessInfo
#define Com_GetBitLengthOfRxAccessInfo(Index)                         Com_GetRxAccessInfoOfPCConfig()[(Index)].BitLengthOfRxAccessInfo
#define Com_GetBitPositionOfRxAccessInfo(Index)                       Com_GetRxAccessInfoOfPCConfig()[(Index)].BitPositionOfRxAccessInfo
#define Com_GetBufferIdxOfRxAccessInfo(Index)                         Com_GetRxAccessInfoOfPCConfig()[(Index)].BufferIdxOfRxAccessInfo
#define Com_GetBusAccOfRxAccessInfo(Index)                            Com_GetRxAccessInfoOfPCConfig()[(Index)].BusAccOfRxAccessInfo
#define Com_GetByteLengthOfRxAccessInfo(Index)                        Com_GetRxAccessInfoOfPCConfig()[(Index)].ByteLengthOfRxAccessInfo
#define Com_GetBytePositionOfRxAccessInfo(Index)                      Com_GetRxAccessInfoOfPCConfig()[(Index)].BytePositionOfRxAccessInfo
#define Com_GetGwInfoIdxOfRxAccessInfo(Index)                         
#define Com_IsGwInfoUsedOfRxAccessInfo(Index)                         
#define Com_IsInitValueUsedOfRxAccessInfo(Index)                      ((Com_GetRxAccessInfoOfPCConfig()[(Index)].InitValueUsedOfRxAccessInfo) != FALSE)
#define Com_GetPduIdOfRxAccessInfo(Index)                             Com_GetRxAccessInfoOfPCConfig()[(Index)].PduIdOfRxAccessInfo
#define Com_GetRxDataTimeoutSubstitutionValueIdxOfRxAccessInfo(Index) Com_GetRxAccessInfoOfPCConfig()[(Index)].RxDataTimeoutSubstitutionValueIdxOfRxAccessInfo
#define Com_GetShdBufferIdxOfRxAccessInfo(Index)                      Com_GetRxAccessInfoOfPCConfig()[(Index)].ShdBufferIdxOfRxAccessInfo
#define Com_IsSignExtRequiredOfRxAccessInfo(Index)                    
#define Com_GetRxAccessInfoInd(Index)                                 Com_GetRxAccessInfoIndOfPCConfig()[(Index)]
#define Com_GetRxAccessInfoReplaceGrpSigInd(Index)                    
#define Com_GetRxDefPduBuffer(Index)                                  Com_GetRxDefPduBufferOfPCConfig()[(Index)]
#define Com_GetRxDynSignalLength(Index)                               
#define Com_GetRxDynSignalTmpLengthForSignalGroups(Index)             
#define Com_GetFilterInfoIdxOfRxGrpSigInfo(Index)                     
#define Com_IsFilterInfoUsedOfRxGrpSigInfo(Index)                     
#define Com_GetInvValueIdxOfRxGrpSigInfo(Index)                       
#define Com_IsInvValueUsedOfRxGrpSigInfo(Index)                       
#define Com_GetRxAccessInfoIdxOfRxGrpSigInfo(Index)                   Com_GetRxGrpSigInfoOfPCConfig()[(Index)].RxAccessInfoIdxOfRxGrpSigInfo
#define Com_GetTmpBufferIdxOfRxGrpSigInfo(Index)                      Com_GetRxGrpSigInfoOfPCConfig()[(Index)].TmpBufferIdxOfRxGrpSigInfo
#define Com_GetRxPduCalloutFuncPtr(Index)                             
#define Com_GetRxPduDmState(Index)                                    Com_GetRxPduDmStateOfPCConfig()[(Index)]
#define Com_IsRxPduGrpActive(Index)                                   ((Com_GetRxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetPduGrpVectorStartIdxOfRxPduGrpInfo(Index)              Com_GetRxPduGrpInfoOfPCConfig()[(Index)].PduGrpVectorStartIdxOfRxPduGrpInfo
#define Com_GetGwInfoEndIdxOfRxPduInfo(Index)                         
#define Com_GetGwInfoStartIdxOfRxPduInfo(Index)                       
#define Com_IsGwInfoUsedOfRxPduInfo(Index)                            
#define Com_GetIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo(Index)    
#define Com_GetIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo(Index)  
#define Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)       
#define Com_GetRxAccessInfoIndEndIdxOfRxPduInfo(Index)                Com_GetRxPduInfoOfPCConfig()[(Index)].RxAccessInfoIndEndIdxOfRxPduInfo
#define Com_GetRxAccessInfoIndStartIdxOfRxPduInfo(Index)              Com_GetRxPduInfoOfPCConfig()[(Index)].RxAccessInfoIndStartIdxOfRxPduInfo
#define Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)                   ((Com_GetRxPduInfoOfPCConfig()[(Index)].RxAccessInfoIndUsedOfRxPduInfo) != FALSE)
#define Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index)                 Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferEndIdxOfRxPduInfo
#define Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index)               Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferStartIdxOfRxPduInfo
#define Com_GetRxPduCalloutFuncPtrIdxOfRxPduInfo(Index)               
#define Com_IsRxPduCalloutFuncPtrUsedOfRxPduInfo(Index)               
#define Com_GetRxSigGrpInfoIndEndIdxOfRxPduInfo(Index)                Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigGrpInfoIndEndIdxOfRxPduInfo
#define Com_GetRxSigGrpInfoIndStartIdxOfRxPduInfo(Index)              Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigGrpInfoIndStartIdxOfRxPduInfo
#define Com_GetRxSigInfoEndIdxOfRxPduInfo(Index)                      Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoEndIdxOfRxPduInfo
#define Com_GetRxSigInfoStartIdxOfRxPduInfo(Index)                    Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoStartIdxOfRxPduInfo
#define Com_IsRxSigInfoUsedOfRxPduInfo(Index)                         ((Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoUsedOfRxPduInfo) != FALSE)
#define Com_GetRxTOutInfoIndEndIdxOfRxPduInfo(Index)                  Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIndEndIdxOfRxPduInfo
#define Com_GetRxTOutInfoIndStartIdxOfRxPduInfo(Index)                Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIndStartIdxOfRxPduInfo
#define Com_IsRxTOutInfoUsedOfRxPduInfo(Index)                        ((Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoUsedOfRxPduInfo) != FALSE)
#define Com_GetRxTpInfoIdxOfRxPduInfo(Index)                          
#define Com_IsRxTpInfoUsedOfRxPduInfo(Index)                          
#define Com_GetRxPduInfoInd(Index)                                    
#define Com_GetRxShdBufferXInt16(Index)                               Com_GetRxShdBufferXInt16OfPCConfig()[(Index)]
#define Com_GetRxShdBufferXInt32(Index)                               
#define Com_GetRxShdBufferXInt8(Index)                                Com_GetRxShdBufferXInt8OfPCConfig()[(Index)]
#define Com_GetRxSigBufferXInt16(Index)                               Com_GetRxSigBufferXInt16OfPCConfig()[(Index)]
#define Com_GetRxSigBufferXInt32(Index)                               
#define Com_GetRxSigBufferXInt8(Index)                                Com_GetRxSigBufferXInt8OfPCConfig()[(Index)]
#define Com_IsArrayAccessUsedOfRxSigGrpInfo(Index)                    
#define Com_GetCbkInvFuncPtrIdxOfRxSigGrpInfo(Index)                  
#define Com_IsCbkInvFuncPtrUsedOfRxSigGrpInfo(Index)                  
#define Com_GetConstValueXInt8EndIdxOfRxSigGrpInfo(Index)             
#define Com_GetConstValueXInt8LengthOfRxSigGrpInfo(Index)             
#define Com_GetConstValueXInt8StartIdxOfRxSigGrpInfo(Index)           
#define Com_IsConstValueXInt8UsedOfRxSigGrpInfo(Index)                
#define Com_IsFilterEventOfRxSigGrpInfo(Index)                        
#define Com_GetGwInfoIdxOfRxSigGrpInfo(Index)                         
#define Com_IsGwInfoUsedOfRxSigGrpInfo(Index)                         
#define Com_IsInvEventOfRxSigGrpInfo(Index)                           
#define Com_IsRxPduInfoUsedOfRxSigGrpInfo(Index)                      ((Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxPduInfoUsedOfRxSigGrpInfo) != FALSE)
#define Com_GetRxShdBufferXInt8EndIdxOfRxSigGrpInfo(Index)            
#define Com_GetRxShdBufferXInt8LengthOfRxSigGrpInfo(Index)            
#define Com_GetRxShdBufferXInt8StartIdxOfRxSigGrpInfo(Index)          
#define Com_IsRxShdBufferXInt8UsedOfRxSigGrpInfo(Index)               
#define Com_GetRxTOutInfoIdxOfRxSigGrpInfo(Index)                     
#define Com_IsRxTOutInfoUsedOfRxSigGrpInfo(Index)                     
#define Com_GetUbIdxOfRxSigGrpInfo(Index)                             
#define Com_GetUbMaskIdxOfRxSigGrpInfo(Index)                         
#define Com_IsUbMaskUsedOfRxSigGrpInfo(Index)                         
#define Com_GetCbkInvFuncPtrIdxOfRxSigInfo(Index)                     
#define Com_IsCbkInvFuncPtrUsedOfRxSigInfo(Index)                     
#define Com_GetCbkRxAckFuncPtrIdxOfRxSigInfo(Index)                   Com_GetRxSigInfoOfPCConfig()[(Index)].CbkRxAckFuncPtrIdxOfRxSigInfo
#define Com_GetFilterInfoIdxOfRxSigInfo(Index)                        
#define Com_IsFilterInfoUsedOfRxSigInfo(Index)                        
#define Com_GetGwInfoIdxOfRxSigInfo(Index)                            
#define Com_IsGwInfoUsedOfRxSigInfo(Index)                            
#define Com_GetInvValueIdxOfRxSigInfo(Index)                          
#define Com_IsInvValueUsedOfRxSigInfo(Index)                          
#define Com_GetRxAccessInfoIdxOfRxSigInfo(Index)                      Com_GetRxSigInfoOfPCConfig()[(Index)].RxAccessInfoIdxOfRxSigInfo
#define Com_GetRxTOutInfoIdxOfRxSigInfo(Index)                        Com_GetRxSigInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxSigInfo
#define Com_GetSignalProcessingOfRxSigInfo(Index)                     Com_GetRxSigInfoOfPCConfig()[(Index)].SignalProcessingOfRxSigInfo
#define Com_GetUbIdxOfRxSigInfo(Index)                                
#define Com_GetUbMaskIdxOfRxSigInfo(Index)                            
#define Com_IsUbMaskUsedOfRxSigInfo(Index)                            
#define Com_GetValidDlcOfRxSigInfo(Index)                             Com_GetRxSigInfoOfPCConfig()[(Index)].ValidDlcOfRxSigInfo
#define Com_GetRxTOutCnt(Index)                                       Com_GetRxTOutCntOfPCConfig()[(Index)]
#define Com_GetCbkRxTOutFuncPtrEndIdxOfRxTOutInfo(Index)              Com_GetRxTOutInfoOfPCConfig()[(Index)].CbkRxTOutFuncPtrEndIdxOfRxTOutInfo
#define Com_GetCbkRxTOutFuncPtrStartIdxOfRxTOutInfo(Index)            Com_GetRxTOutInfoOfPCConfig()[(Index)].CbkRxTOutFuncPtrStartIdxOfRxTOutInfo
#define Com_GetFactorOfRxTOutInfo(Index)                              Com_GetRxTOutInfoOfPCConfig()[(Index)].FactorOfRxTOutInfo
#define Com_GetFirstFactorOfRxTOutInfo(Index)                         Com_GetRxTOutInfoOfPCConfig()[(Index)].FirstFactorOfRxTOutInfo
#define Com_GetRxAccessInfoReplaceGrpSigIndEndIdxOfRxTOutInfo(Index)  
#define Com_GetRxAccessInfoReplaceGrpSigIndStartIdxOfRxTOutInfo(Index) 
#define Com_IsRxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo(Index)     
#define Com_GetRxAccessInfoReplaceSigIndEndIdxOfRxTOutInfo(Index)     Com_GetRxTOutInfoOfPCConfig()[(Index)].RxAccessInfoReplaceSigIndEndIdxOfRxTOutInfo
#define Com_GetRxAccessInfoReplaceSigIndStartIdxOfRxTOutInfo(Index)   Com_GetRxTOutInfoOfPCConfig()[(Index)].RxAccessInfoReplaceSigIndStartIdxOfRxTOutInfo
#define Com_GetRxPduInfoIdxOfRxTOutInfo(Index)                        Com_GetRxTOutInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxTOutInfo
#define Com_GetRxTpBuffer(Index)                                      
#define Com_GetRxTpConnectionState(Index)                             
#define Com_GetBufferSizeOfRxTpInfo(Index)                            
#define Com_GetRxAccessInfoDynSigIdxOfRxTpInfo(Index)                 
#define Com_IsRxAccessInfoDynSigUsedOfRxTpInfo(Index)                 
#define Com_GetRxTpBufferEndIdxOfRxTpInfo(Index)                      
#define Com_GetRxTpBufferStartIdxOfRxTpInfo(Index)                    
#define Com_IsRxTpBufferUsedOfRxTpInfo(Index)                         
#define Com_GetRxTpSduLength(Index)                                   
#define Com_GetRxTpWrittenBytesCounter(Index)                         
#define Com_GetSigGrpEventFlag(Index)                                 Com_GetSigGrpEventFlagOfPCConfig()[(Index)]
#define Com_GetTmpRxBuffer(Index)                                     Com_GetTmpRxBufferOfPCConfig()[(Index)]
#define Com_GetTmpRxShdBufferXInt16(Index)                            Com_GetTmpRxShdBufferXInt16OfPCConfig()[(Index)]
#define Com_GetTmpRxShdBufferXInt32(Index)                            
#define Com_GetTmpRxShdBufferXInt8(Index)                             Com_GetTmpRxShdBufferXInt8OfPCConfig()[(Index)]
#define Com_IsTransmitRequest(Index)                                  ((Com_GetTransmitRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetTxDynSignalLength(Index)                               
#define Com_IsTxFilterInitState(Index)                                
#define Com_GetTxFilterInitValueXInt16(Index)                         
#define Com_GetTxFilterInitValueXInt32(Index)                         
#define Com_GetTxFilterInitValueXInt8(Index)                          
#define Com_GetTxFilterOldValueXInt16(Index)                          
#define Com_GetTxFilterOldValueXInt32(Index)                          
#define Com_GetTxFilterOldValueXInt8(Index)                           
#define Com_IsTxFilterState(Index)                                    
#define Com_IsDirectOfTxModeFalse(Index)                              
#define Com_IsPeriodicOfTxModeFalse(Index)                            
#define Com_GetRepCntOfTxModeFalse(Index)                             
#define Com_GetRepPeriodOfTxModeFalse(Index)                          
#define Com_GetTimeOffsetOfTxModeFalse(Index)                         
#define Com_GetTimePeriodOfTxModeFalse(Index)                         
#define Com_GetMinimumDelayOfTxModeInfo(Index)                        
#define Com_GetTxFilterInitStateEndIdxOfTxModeInfo(Index)             
#define Com_GetTxFilterInitStateStartIdxOfTxModeInfo(Index)           
#define Com_IsTxFilterInitStateUsedOfTxModeInfo(Index)                
#define Com_GetTxModeFalseIdxOfTxModeInfo(Index)                      
#define Com_IsTxModeFalseUsedOfTxModeInfo(Index)                      
#define Com_GetTxModeTrueIdxOfTxModeInfo(Index)                       Com_GetTxModeInfoOfPCConfig()[(Index)].TxModeTrueIdxOfTxModeInfo
#define Com_IsTxModeTrueUsedOfTxModeInfo(Index)                       ((Com_GetTxModeInfoOfPCConfig()[(Index)].TxModeTrueUsedOfTxModeInfo) != FALSE)
#define Com_GetTxSigInfoFilterInitValueIndEndIdxOfTxModeInfo(Index)   
#define Com_GetTxSigInfoFilterInitValueIndStartIdxOfTxModeInfo(Index) 
#define Com_IsTxSigInfoFilterInitValueIndUsedOfTxModeInfo(Index)      
#define Com_IsDirectOfTxModeTrue(Index)                               
#define Com_IsPeriodicOfTxModeTrue(Index)                             ((Com_GetTxModeTrueOfPCConfig()[(Index)].PeriodicOfTxModeTrue) != FALSE)
#define Com_GetRepCntOfTxModeTrue(Index)                              
#define Com_GetRepPeriodOfTxModeTrue(Index)                           
#define Com_GetTimeOffsetOfTxModeTrue(Index)                          
#define Com_GetTxPduBuffer(Index)                                     Com_GetTxPduBufferOfPCConfig()[(Index)]
#define Com_GetTxPduCalloutFuncPtr(Index)                             
#define Com_IsTxPduGrpActive(Index)                                   ((Com_GetTxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetPduGrpVectorStartIdxOfTxPduGrpInfo(Index)              Com_GetTxPduGrpInfoOfPCConfig()[(Index)].PduGrpVectorStartIdxOfTxPduGrpInfo
#define Com_IsCancellationSupportOfTxPduInfo(Index)                   
#define Com_GetCbkTxAckDefFuncPtrEndIdxOfTxPduInfo(Index)             
#define Com_GetCbkTxAckDefFuncPtrStartIdxOfTxPduInfo(Index)           
#define Com_IsCbkTxAckDefFuncPtrUsedOfTxPduInfo(Index)                
#define Com_GetCbkTxAckImFuncPtrEndIdxOfTxPduInfo(Index)              
#define Com_GetCbkTxAckImFuncPtrStartIdxOfTxPduInfo(Index)            
#define Com_IsCbkTxAckImFuncPtrUsedOfTxPduInfo(Index)                 
#define Com_GetCbkTxErrFuncPtrEndIdxOfTxPduInfo(Index)                
#define Com_GetCbkTxErrFuncPtrStartIdxOfTxPduInfo(Index)              
#define Com_IsCbkTxErrFuncPtrUsedOfTxPduInfo(Index)                   
#define Com_GetClrUbOfTxPduInfo(Index)                                
#define Com_GetConstValueXInt8UbClearMaskEndIdxOfTxPduInfo(Index)     
#define Com_GetConstValueXInt8UbClearMaskStartIdxOfTxPduInfo(Index)   
#define Com_IsConstValueXInt8UbClearMaskUsedOfTxPduInfo(Index)        
#define Com_GetExternalIdOfTxPduInfo(Index)                           Com_GetTxPduInfoOfPCConfig()[(Index)].ExternalIdOfTxPduInfo
#define Com_GetIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo(Index)    
#define Com_GetIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(Index)  
#define Com_IsIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo(Index)       
#define Com_GetMetaDataLengthOfTxPduInfo(Index)                       Com_GetTxPduInfoOfPCConfig()[(Index)].MetaDataLengthOfTxPduInfo
#define Com_GetTxPduBufferLengthOfTxPduInfo(Index)                    Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduBufferLengthOfTxPduInfo
#define Com_GetTxPduBufferMetaDataEndIdxOfTxPduInfo(Index)            
#define Com_GetTxPduBufferMetaDataStartIdxOfTxPduInfo(Index)          
#define Com_IsTxPduBufferMetaDataUsedOfTxPduInfo(Index)               
#define Com_GetTxPduCalloutFuncPtrIdxOfTxPduInfo(Index)               
#define Com_IsTxPduCalloutFuncPtrUsedOfTxPduInfo(Index)               
#define Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)                 Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueEndIdxOfTxPduInfo
#define Com_GetTxPduInitValueMetaDataEndIdxOfTxPduInfo(Index)         
#define Com_GetTxPduInitValueMetaDataStartIdxOfTxPduInfo(Index)       
#define Com_IsTxPduInitValueMetaDataUsedOfTxPduInfo(Index)            
#define Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)               Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueStartIdxOfTxPduInfo
#define Com_IsTxPduInitValueUsedOfTxPduInfo(Index)                    ((Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueUsedOfTxPduInfo) != FALSE)
#define Com_GetTxPduTTCalloutFuncPtrIdxOfTxPduInfo(Index)             
#define Com_IsTxPduTTCalloutFuncPtrUsedOfTxPduInfo(Index)             
#define Com_GetTxSigGrpInfoIndEndIdxOfTxPduInfo(Index)                Com_GetTxPduInfoOfPCConfig()[(Index)].TxSigGrpInfoIndEndIdxOfTxPduInfo
#define Com_GetTxSigGrpInfoIndStartIdxOfTxPduInfo(Index)              Com_GetTxPduInfoOfPCConfig()[(Index)].TxSigGrpInfoIndStartIdxOfTxPduInfo
#define Com_GetTxTOutInfoIdxOfTxPduInfo(Index)                        
#define Com_IsTxTOutInfoUsedOfTxPduInfo(Index)                        
#define Com_GetTxTpInfoIdxOfTxPduInfo(Index)                          
#define Com_IsTxTpInfoUsedOfTxPduInfo(Index)                          
#define Com_GetTxPduInfoInd(Index)                                    
#define Com_GetTxPduInitValue(Index)                                  Com_GetTxPduInitValueOfPCConfig()[(Index)]
#define Com_GetTxPduTTCalloutFuncPtr(Index)                           
#define Com_GetTxSduLength(Index)                                     Com_GetTxSduLengthOfPCConfig()[(Index)]
#define Com_GetTxShdBuffer(Index)                                     Com_GetTxShdBufferOfPCConfig()[(Index)]
#define Com_IsArrayAccessUsedOfTxSigGrpInfo(Index)                    
#define Com_GetSigGroupOnChangeOffsetOfTxSigGrpInfo(Index)            
#define Com_GetSigGroupOnChangeStartPositionOfTxSigGrpInfo(Index)     
#define Com_GetSigGroupOnChangeWithoutRepOffsetOfTxSigGrpInfo(Index)  
#define Com_GetSigGroupOnChangeWithoutRepStartPositionOfTxSigGrpInfo(Index) 
#define Com_IsTxSigGrpMaskUsedOfTxSigGrpInfo(Index)                   ((Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxSigGrpMaskUsedOfTxSigGrpInfo) != FALSE)
#define Com_GetTxSigGrpOnChangeMaskOnChangeEndIdxOfTxSigGrpInfo(Index) 
#define Com_GetTxSigGrpOnChangeMaskOnChangeLengthOfTxSigGrpInfo(Index) 
#define Com_GetTxSigGrpOnChangeMaskOnChangeStartIdxOfTxSigGrpInfo(Index) 
#define Com_IsTxSigGrpOnChangeMaskOnChangeUsedOfTxSigGrpInfo(Index)   
#define Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepEndIdxOfTxSigGrpInfo(Index) 
#define Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepLengthOfTxSigGrpInfo(Index) 
#define Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepStartIdxOfTxSigGrpInfo(Index) 
#define Com_IsTxSigGrpOnChangeMaskOnChangeWithoutRepUsedOfTxSigGrpInfo(Index) 
#define Com_GetTxSigInfoInvValueIndEndIdxOfTxSigGrpInfo(Index)        
#define Com_GetTxSigInfoInvValueIndStartIdxOfTxSigGrpInfo(Index)      
#define Com_IsTxSigInfoInvValueIndUsedOfTxSigGrpInfo(Index)           
#define Com_GetTxTOutInfoIdxOfTxSigGrpInfo(Index)                     
#define Com_IsTxTOutInfoUsedOfTxSigGrpInfo(Index)                     
#define Com_GetUbIdxOfTxSigGrpInfo(Index)                             
#define Com_GetUbMaskIdxOfTxSigGrpInfo(Index)                         
#define Com_IsUbMaskUsedOfTxSigGrpInfo(Index)                         
#define Com_GetTxSigGrpMask(Index)                                    Com_GetTxSigGrpMaskOfPCConfig()[(Index)]
#define Com_GetTxSigGrpOnChangeMask(Index)                            
#define Com_GetApplTypeOfTxSigInfo(Index)                             Com_GetTxSigInfoOfPCConfig()[(Index)].ApplTypeOfTxSigInfo
#define Com_GetBitLengthOfTxSigInfo(Index)                            Com_GetTxSigInfoOfPCConfig()[(Index)].BitLengthOfTxSigInfo
#define Com_GetBitPositionOfTxSigInfo(Index)                          Com_GetTxSigInfoOfPCConfig()[(Index)].BitPositionOfTxSigInfo
#define Com_GetBusAccOfTxSigInfo(Index)                               Com_GetTxSigInfoOfPCConfig()[(Index)].BusAccOfTxSigInfo
#define Com_GetByteLengthOfTxSigInfo(Index)                           Com_GetTxSigInfoOfPCConfig()[(Index)].ByteLengthOfTxSigInfo
#define Com_GetBytePositionOfTxSigInfo(Index)                         Com_GetTxSigInfoOfPCConfig()[(Index)].BytePositionOfTxSigInfo
#define Com_GetFilterInfoIdxOfTxSigInfo(Index)                        
#define Com_IsFilterInfoUsedOfTxSigInfo(Index)                        
#define Com_GetFilterInitValueIdxOfTxSigInfo(Index)                   
#define Com_IsFilterInitValueUsedOfTxSigInfo(Index)                   
#define Com_GetInvValueIdxOfTxSigInfo(Index)                          
#define Com_IsInvValueUsedOfTxSigInfo(Index)                          
#define Com_IsInvalidHndOfTxSigInfo(Index)                            ((Com_GetTxSigInfoOfPCConfig()[(Index)].InvalidHndOfTxSigInfo) != FALSE)
#define Com_GetOnChangeIdxOfTxSigInfo(Index)                          
#define Com_IsOnChangeUsedOfTxSigInfo(Index)                          
#define Com_GetPduIdOfTxSigInfo(Index)                                Com_GetTxSigInfoOfPCConfig()[(Index)].PduIdOfTxSigInfo
#define Com_IsTriggeredOfTxSigInfo(Index)                             
#define Com_GetTxFilterInitStateIdxOfTxSigInfo(Index)                 
#define Com_IsTxFilterInitStateUsedOfTxSigInfo(Index)                 
#define Com_GetTxSigGrpInfoIdxOfTxSigInfo(Index)                      Com_GetTxSigInfoOfPCConfig()[(Index)].TxSigGrpInfoIdxOfTxSigInfo
#define Com_GetTxTOutInfoIdxOfTxSigInfo(Index)                        
#define Com_IsTxTOutInfoUsedOfTxSigInfo(Index)                        
#define Com_GetUbIdxOfTxSigInfo(Index)                                
#define Com_GetUbMaskIdxOfTxSigInfo(Index)                            
#define Com_IsUbMaskUsedOfTxSigInfo(Index)                            
#define Com_IsWithoutRepOfTxSigInfo(Index)                            
#define Com_GetTxSigInfoFilterInitValueInd(Index)                     
#define Com_GetTxSigInfoInvValueInd(Index)                            
#define Com_GetTxTOutCnt(Index)                                       
#define Com_GetCbkTxTOutFuncPtrEndIdxOfTxTOutInfo(Index)              
#define Com_GetCbkTxTOutFuncPtrStartIdxOfTxTOutInfo(Index)            
#define Com_IsCbkTxTOutFuncPtrUsedOfTxTOutInfo(Index)                 
#define Com_GetFactorOfTxTOutInfo(Index)                              
#define Com_IsNoneModeOfTxTOutInfo(Index)                             
#define Com_GetTxPduInfoIdxOfTxTOutInfo(Index)                        
#define Com_IsTxPduInfoUsedOfTxTOutInfo(Index)                        
#define Com_GetTxTmpTpPduLength(Index)                                
#define Com_GetTxTpConnectionState(Index)                             
#define Com_GetBufferSizeOfTxTpInfo(Index)                            
#define Com_GetTxPduBufferEndIdxOfTxTpInfo(Index)                     
#define Com_GetTxPduBufferLengthOfTxTpInfo(Index)                     
#define Com_GetTxPduBufferStartIdxOfTxTpInfo(Index)                   
#define Com_IsTxPduBufferUsedOfTxTpInfo(Index)                        
#define Com_GetTxSigInfoDynSigIdxOfTxTpInfo(Index)                    
#define Com_IsTxSigInfoDynSigUsedOfTxTpInfo(Index)                    
#define Com_GetTxTpSduLength(Index)                                   
#define Com_GetTxTpWrittenBytesCounter(Index)                         
#define Com_IsWaitingForConfirmation(Index)                           ((Com_GetWaitingForConfirmationOfPCConfig()[(Index)]) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  PCGetDeduplicatedDataMacros  Get Deduplicated Data Macros (PRE-COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Com_GetAllSigCnt()                                            Com_GetAllSigCntOfPCConfig()
#define Com_GetAllSigGrpCnt()                                         Com_GetAllSigGrpCntOfPCConfig()
#define Com_GetConfigId()                                             Com_GetConfigIdOfPCConfig()
#define Com_GetFinalMagicNumber()                                     Com_GetFinalMagicNumberOfPCConfig()
#define Com_GetInitDataHashCode()                                     Com_GetInitDataHashCodeOfPCConfig()
#define Com_GetPduGrpCnt()                                            Com_GetPduGrpCntOfPCConfig()
#define Com_IsBufferUsedOfRxAccessInfo(Index)                         Com_IsInitValueUsedOfRxAccessInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxSigBufferXInt8,Com_RxSigBufferXInt16,Com_RxSigBufferXInt32 */
#define Com_GetInitValueIdxOfRxAccessInfo(Index)                      Com_GetRxDataTimeoutSubstitutionValueIdxOfRxAccessInfo(Index)  /**< the index of the 0:1 relation pointing to Com_ConstValueXInt8,Com_ConstValueXInt16,Com_ConstValueXInt32 */
#define Com_IsInvalidHndOfRxAccessInfo(Index)                         (((!(Com_IsInitValueUsedOfRxAccessInfo(Index)))) != FALSE)  /**< FALSE, if the handle of Com_RxAccessInfo is valid and can be used in the embedded code for further processing in the embedded code. */
#define Com_IsRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo(Index) Com_IsInitValueUsedOfRxAccessInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueXInt8,Com_ConstValueXInt16,Com_ConstValueXInt32 */
#define Com_IsShdBufferUsedOfRxAccessInfo(Index)                      (((boolean)(Com_GetShdBufferIdxOfRxAccessInfo(Index) != COM_NO_SHDBUFFERIDXOFRXACCESSINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxShdBufferXInt8,Com_RxShdBufferXInt16,Com_RxShdBufferXInt32 */
#define Com_GetRxAccessInfoReplaceSigInd(Index)                       ((Com_RxAccessInfoReplaceSigIndType)(((Index) + 30)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo */
#define Com_IsTmpBufferUsedOfRxGrpSigInfo(Index)                      (((boolean)(Com_GetTmpBufferIdxOfRxGrpSigInfo(Index) != COM_NO_TMPBUFFERIDXOFRXGRPSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TmpRxShdBufferXInt8,Com_TmpRxShdBufferXInt16,Com_TmpRxShdBufferXInt32 */
#define Com_GetPduGrpVectorEndIdxOfRxPduGrpInfo(Index)                ((Com_PduGrpVectorEndIdxOfRxPduGrpInfoType)((Com_GetPduGrpVectorStartIdxOfRxPduGrpInfo(Index) + 1)))  /**< the end index of the 0:n relation pointing to Com_PduGrpVector */
#define Com_IsPduGrpVectorUsedOfRxPduGrpInfo(Index)                   (((boolean)(Com_GetPduGrpVectorStartIdxOfRxPduGrpInfo(Index) != COM_NO_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_PduGrpVector */
#define Com_GetHandleRxPduDeferredIdxOfRxPduInfo(Index)               ((Com_HandleRxPduDeferredIdxOfRxPduInfoType)((Index)))  /**< the index of the 0:1 relation pointing to Com_HandleRxPduDeferred */
#define Com_IsHandleRxPduDeferredUsedOfRxPduInfo(Index)               Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_HandleRxPduDeferred */
#define Com_IsInvalidHndOfRxPduInfo(Index)                            (((!(Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)))) != FALSE)  /**< FALSE, if the handle of Com_RxPduInfo is valid and can be used in the embedded code for further processing in the embedded code. */
#define Com_GetRxDefPduBufferLengthOfRxPduInfo(Index)                 (Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index) - Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index))  /**< the number of relations pointing to Com_RxDefPduBuffer */
#define Com_IsRxDefPduBufferUsedOfRxPduInfo(Index)                    Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxDefPduBuffer */
#define Com_IsRxSigGrpInfoIndUsedOfRxPduInfo(Index)                   (((!(Com_IsRxSigInfoUsedOfRxPduInfo(Index)))) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigGrpInfoInd */
#define Com_GetRxTOutInfoIdxOfRxPduInfo(Index)                        Com_GetRxTOutInfoIndStartIdxOfRxPduInfo(Index)  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
#define Com_IsRxTOutInfoIndUsedOfRxPduInfo(Index)                     Com_IsRxTOutInfoUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxTOutInfoInd */
#define Com_GetCbkRxAckFuncPtrIdxOfRxSigGrpInfo(Index)                ((Com_CbkRxAckFuncPtrIdxOfRxSigGrpInfoType)(((Index) + 7)))  /**< the index of the 0:1 relation pointing to Com_CbkRxAckFuncPtr */
#define Com_IsCbkRxAckFuncPtrUsedOfRxSigGrpInfo(Index)                Com_IsRxPduInfoUsedOfRxSigGrpInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_CbkRxAckFuncPtr */
#define Com_IsInvalidHndOfRxSigGrpInfo(Index)                         (((!(Com_IsRxPduInfoUsedOfRxSigGrpInfo(Index)))) != FALSE)  /**< FALSE, if the handle of Com_RxSigGrpInfo is valid and can be used in the embedded code for further processing in the embedded code. */
#define Com_GetRxGrpSigInfoEndIdxOfRxSigGrpInfo(Index)                ((Com_RxGrpSigInfoEndIdxOfRxSigGrpInfoType)(((Index) + 3)))  /**< the end index of the 1:n relation pointing to Com_RxGrpSigInfo */
#define Com_GetRxGrpSigInfoStartIdxOfRxSigGrpInfo(Index)              ((Com_RxGrpSigInfoStartIdxOfRxSigGrpInfoType)((Index)))  /**< the start index of the 1:n relation pointing to Com_RxGrpSigInfo */
#define Com_GetRxPduInfoIdxOfRxSigGrpInfo(Index)                      ((Com_RxPduInfoIdxOfRxSigGrpInfoType)(((Index) + 6)))  /**< the index of the 0:1 relation pointing to Com_RxPduInfo */
#define Com_GetSignalProcessingOfRxSigGrpInfo(Index)                  ((Com_SignalProcessingOfRxSigGrpInfoType)((Index)))
#define Com_GetStartBytePositionOfRxSigGrpInfo(Index)                 ((Com_StartBytePositionOfRxSigGrpInfoType)((Index)))
#define Com_GetValidDlcOfRxSigGrpInfo(Index)                          ((Com_ValidDlcOfRxSigGrpInfoType)(((Index) + 4)))  /**< Minimum length of PDU required to completely receive the signal or signal group. ea:{0EAD864F-51F0-475a-A517-E3127ABAEBE4} */
#define Com_GetRxSigGrpInfoInd(Index)                                 ((Com_RxSigGrpInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxSigGrpInfo */
#define Com_IsCbkRxAckFuncPtrUsedOfRxSigInfo(Index)                   (((boolean)(Com_GetCbkRxAckFuncPtrIdxOfRxSigInfo(Index) != COM_NO_CBKRXACKFUNCPTRIDXOFRXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_CbkRxAckFuncPtr */
#define Com_IsRxTOutInfoUsedOfRxSigInfo(Index)                        (((boolean)(Com_GetRxTOutInfoIdxOfRxSigInfo(Index) != COM_NO_RXTOUTINFOIDXOFRXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
#define Com_IsCbkRxTOutFuncPtrUsedOfRxTOutInfo(Index)                 (((boolean)(Com_GetCbkRxTOutFuncPtrStartIdxOfRxTOutInfo(Index) != COM_NO_CBKRXTOUTFUNCPTRSTARTIDXOFRXTOUTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_CbkRxTOutFuncPtr */
#define Com_IsRxAccessInfoReplaceSigIndUsedOfRxTOutInfo(Index)        (((boolean)(Com_GetRxAccessInfoReplaceSigIndStartIdxOfRxTOutInfo(Index) != COM_NO_RXACCESSINFOREPLACESIGINDSTARTIDXOFRXTOUTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoReplaceSigInd */
#define Com_GetRxTOutInfoInd(Index)                                   ((Com_RxTOutInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxTOutInfo */
#define Com_GetSizeOfCbkRxAckFuncPtr()                                Com_GetSizeOfCbkRxAckFuncPtrOfPCConfig()
#define Com_GetSizeOfCbkRxTOutFuncPtr()                               Com_GetSizeOfCbkRxTOutFuncPtrOfPCConfig()
#define Com_GetSizeOfConstValueXInt16()                               Com_GetSizeOfConstValueXInt16OfPCConfig()
#define Com_GetSizeOfConstValueXInt8()                                Com_GetSizeOfConstValueXInt8OfPCConfig()
#define Com_GetSizeOfCurrentTxMode()                                  Com_GetSizeOfCurrentTxModeOfPCConfig()
#define Com_GetSizeOfCycleTimeCnt()                                   Com_GetSizeOfCycleTimeCntOfPCConfig()
#define Com_GetSizeOfCyclicSendRequest()                              Com_GetSizeOfCyclicSendRequestOfPCConfig()
#define Com_GetSizeOfHandleRxPduDeferred()                            Com_GetSizeOfHandleRxPduDeferredOfPCConfig()
#define Com_GetSizeOfHandleTxPduDeferred()                            Com_GetSizeOfHandleTxPduDeferredOfPCConfig()
#define Com_GetSizeOfPduGrpVector()                                   Com_GetSizeOfPduGrpVectorOfPCConfig()
#define Com_GetSizeOfRepCnt()                                         Com_GetSizeOfRepCntOfPCConfig()
#define Com_GetSizeOfRepCycleCnt()                                    Com_GetSizeOfRepCycleCntOfPCConfig()
#define Com_GetSizeOfRxAccessInfo()                                   Com_GetSizeOfRxAccessInfoOfPCConfig()
#define Com_GetSizeOfRxAccessInfoInd()                                Com_GetSizeOfRxAccessInfoIndOfPCConfig()
#define Com_GetSizeOfRxAccessInfoReplaceSigInd()                      Com_GetSizeOfRxAccessInfoReplaceSigIndOfPCConfig()
#define Com_GetSizeOfRxDefPduBuffer()                                 Com_GetSizeOfRxDefPduBufferOfPCConfig()
#define Com_GetSizeOfRxGrpSigInfo()                                   Com_GetSizeOfRxGrpSigInfoOfPCConfig()
#define Com_GetSizeOfRxPduDmState()                                   Com_GetSizeOfRxPduDmStateOfPCConfig()
#define Com_GetSizeOfRxPduGrpActive()                                 Com_GetSizeOfRxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfRxPduGrpInfo()                                   Com_GetSizeOfRxPduGrpInfoOfPCConfig()
#define Com_GetSizeOfRxPduInfo()                                      Com_GetSizeOfRxPduInfoOfPCConfig()
#define Com_GetSizeOfRxShdBufferXInt16()                              Com_GetSizeOfRxShdBufferXInt16OfPCConfig()
#define Com_GetSizeOfRxShdBufferXInt8()                               Com_GetSizeOfRxShdBufferXInt8OfPCConfig()
#define Com_GetSizeOfRxSigBufferXInt16()                              Com_GetSizeOfRxSigBufferXInt16OfPCConfig()
#define Com_GetSizeOfRxSigBufferXInt8()                               Com_GetSizeOfRxSigBufferXInt8OfPCConfig()
#define Com_GetSizeOfRxSigGrpInfo()                                   Com_GetSizeOfRxSigGrpInfoOfPCConfig()
#define Com_GetSizeOfRxSigGrpInfoInd()                                Com_GetSizeOfRxSigGrpInfoIndOfPCConfig()
#define Com_GetSizeOfRxSigInfo()                                      Com_GetSizeOfRxSigInfoOfPCConfig()
#define Com_GetSizeOfRxTOutCnt()                                      Com_GetSizeOfRxTOutCntOfPCConfig()
#define Com_GetSizeOfRxTOutInfo()                                     Com_GetSizeOfRxTOutInfoOfPCConfig()
#define Com_GetSizeOfRxTOutInfoInd()                                  Com_GetSizeOfRxTOutInfoIndOfPCConfig()
#define Com_GetSizeOfSigGrpEventFlag()                                Com_GetSizeOfSigGrpEventFlagOfPCConfig()
#define Com_GetSizeOfTmpRxBuffer()                                    Com_GetSizeOfTmpRxBufferOfPCConfig()
#define Com_GetSizeOfTmpRxShdBufferXInt16()                           Com_GetSizeOfTmpRxShdBufferXInt16OfPCConfig()
#define Com_GetSizeOfTmpRxShdBufferXInt8()                            Com_GetSizeOfTmpRxShdBufferXInt8OfPCConfig()
#define Com_GetSizeOfTransmitRequest()                                Com_GetSizeOfTransmitRequestOfPCConfig()
#define Com_GetSizeOfTxModeInfo()                                     Com_GetSizeOfTxModeInfoOfPCConfig()
#define Com_GetSizeOfTxModeTrue()                                     Com_GetSizeOfTxModeTrueOfPCConfig()
#define Com_GetSizeOfTxPduBuffer()                                    Com_GetSizeOfTxPduBufferOfPCConfig()
#define Com_GetSizeOfTxPduGrpActive()                                 Com_GetSizeOfTxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfTxPduGrpInfo()                                   Com_GetSizeOfTxPduGrpInfoOfPCConfig()
#define Com_GetSizeOfTxPduInfo()                                      Com_GetSizeOfTxPduInfoOfPCConfig()
#define Com_GetSizeOfTxPduInitValue()                                 Com_GetSizeOfTxPduInitValueOfPCConfig()
#define Com_GetSizeOfTxSduLength()                                    Com_GetSizeOfTxSduLengthOfPCConfig()
#define Com_GetSizeOfTxShdBuffer()                                    Com_GetSizeOfTxShdBufferOfPCConfig()
#define Com_GetSizeOfTxSigGrpInfo()                                   Com_GetSizeOfTxSigGrpInfoOfPCConfig()
#define Com_GetSizeOfTxSigGrpInfoInd()                                Com_GetSizeOfTxSigGrpInfoIndOfPCConfig()
#define Com_GetSizeOfTxSigGrpMask()                                   Com_GetSizeOfTxSigGrpMaskOfPCConfig()
#define Com_GetSizeOfTxSigInfo()                                      Com_GetSizeOfTxSigInfoOfPCConfig()
#define Com_GetSizeOfWaitingForConfirmation()                         Com_GetSizeOfWaitingForConfirmationOfPCConfig()
#define Com_IsInitModeOfTxModeInfo(Index)                             Com_IsTxModeTrueUsedOfTxModeInfo(Index)  /**< Initial transmission mode selector of the Tx I-PDU. ea:{EFF0A60B-2771-4765-B894-F5403EEFCFB9} */
#define Com_IsInvalidHndOfTxModeInfo(Index)                           (((!(Com_IsTxModeTrueUsedOfTxModeInfo(Index)))) != FALSE)  /**< FALSE, if the handle of Com_TxModeInfo is valid and can be used in the embedded code for further processing in the embedded code. */
#define Com_GetTimePeriodOfTxModeTrue(Index)                          ((Com_TimePeriodOfTxModeTrueType)((Index)))  /**< Cycle time factor. ea:{0B150B17-8D3B-4066-BBEC-3E234415F1F2} */
#define Com_GetPduGrpVectorEndIdxOfTxPduGrpInfo(Index)                ((Com_PduGrpVectorEndIdxOfTxPduGrpInfoType)((Com_GetPduGrpVectorStartIdxOfTxPduGrpInfo(Index) + 1)))  /**< the end index of the 0:n relation pointing to Com_PduGrpVector */
#define Com_IsPduGrpVectorUsedOfTxPduGrpInfo(Index)                   (((boolean)(Com_GetPduGrpVectorStartIdxOfTxPduGrpInfo(Index) != COM_NO_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_PduGrpVector */
#define Com_IsInvalidHndOfTxPduInfo(Index)                            (((!(Com_IsTxPduInitValueUsedOfTxPduInfo(Index)))) != FALSE)  /**< FALSE, if the handle of Com_TxPduInfo is valid and can be used in the embedded code for further processing in the embedded code. */
#define Com_GetPduWithMetaDataLengthOfTxPduInfo(Index)                Com_GetTxPduBufferLengthOfTxPduInfo(Index)  /**< Length of Pdu with MetaData. */
#define Com_GetTxPduBufferEndIdxOfTxPduInfo(Index)                    Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)  /**< the end index of the 0:n relation pointing to Com_TxPduBuffer */
#define Com_GetTxPduBufferStartIdxOfTxPduInfo(Index)                  Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)  /**< the start index of the 0:n relation pointing to Com_TxPduBuffer */
#define Com_IsTxPduBufferUsedOfTxPduInfo(Index)                       Com_IsTxPduInitValueUsedOfTxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduBuffer */
#define Com_IsTxSigGrpInfoIndUsedOfTxPduInfo(Index)                   (((boolean)(Com_GetTxSigGrpInfoIndStartIdxOfTxPduInfo(Index) != COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpInfoInd */
#define Com_IsInvalidHndOfTxSigGrpInfo(Index)                         (((!(Com_IsTxSigGrpMaskUsedOfTxSigGrpInfo(Index)))) != FALSE)  /**< FALSE, if the handle of Com_TxSigGrpInfo is valid and can be used in the embedded code for further processing in the embedded code. */
#define Com_GetPduIdOfTxSigGrpInfo(Index)                             ((Com_PduIdOfTxSigGrpInfoType)(((Index) + 2)))  /**< ID of the corresponding Tx I-PDU. ea:{9E87DADE-82EA-452d-A1C6-BA27551A45EC} */
#define Com_GetPduOffsetOfTxSigGrpInfo(Index)                         ((Com_PduOffsetOfTxSigGrpInfoType)((Index)))  /**< Byte offset relative to the PDU the signal group is starting. ea:{897A9817-3EE9-4627-9CB7-05D44DE8B18A} */
#define Com_GetTransferPropertyOfTxSigGrpInfo(Index)                  ((Com_TransferPropertyOfTxSigGrpInfoType)((Index)))
#define Com_GetTxShdBufferEndIdxOfTxSigGrpInfo(Index)                 ((Com_TxShdBufferEndIdxOfTxSigGrpInfoType)(((Index) + 4)))  /**< the end index of the 0:n relation pointing to Com_TxShdBuffer */
#define Com_GetTxShdBufferLengthOfTxSigGrpInfo(Index)                 ((Com_TxShdBufferLengthOfTxSigGrpInfoType)(((Index) + 4)))  /**< the number of relations pointing to Com_TxShdBuffer */
#define Com_GetTxShdBufferStartIdxOfTxSigGrpInfo(Index)               ((Com_TxShdBufferStartIdxOfTxSigGrpInfoType)((Index)))  /**< the start index of the 0:n relation pointing to Com_TxShdBuffer */
#define Com_IsTxShdBufferUsedOfTxSigGrpInfo(Index)                    Com_IsTxSigGrpMaskUsedOfTxSigGrpInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxShdBuffer */
#define Com_GetTxSigGrpMaskEndIdxOfTxSigGrpInfo(Index)                ((Com_TxSigGrpMaskEndIdxOfTxSigGrpInfoType)(((Index) + 4)))  /**< the end index of the 0:n relation pointing to Com_TxSigGrpMask */
#define Com_GetTxSigGrpMaskLengthOfTxSigGrpInfo(Index)                ((Com_TxSigGrpMaskLengthOfTxSigGrpInfoType)(((Index) + 4)))  /**< the number of relations pointing to Com_TxSigGrpMask */
#define Com_GetTxSigGrpMaskStartIdxOfTxSigGrpInfo(Index)              ((Com_TxSigGrpMaskStartIdxOfTxSigGrpInfoType)((Index)))  /**< the start index of the 0:n relation pointing to Com_TxSigGrpMask */
#define Com_GetTxSigGrpInfoInd(Index)                                 ((Com_TxSigGrpInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_TxSigGrpInfo */
#define Com_IsTxSigGrpInfoUsedOfTxSigInfo(Index)                      (((boolean)(Com_GetTxSigGrpInfoIdxOfTxSigInfo(Index) != COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxSigGrpInfo */
/** 
  \}
*/ 

/** 
  \defgroup  PCSetDataMacros  Set Data Macros (PRE-COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Com_SetCurrentTxMode(Index, Value)                            Com_GetCurrentTxModeOfPCConfig()[(Index)] = (Value)
#define Com_SetCycleTimeCnt(Index, Value)                             Com_GetCycleTimeCntOfPCConfig()[(Index)] = (Value)
#define Com_SetCyclicSendRequest(Index, Value)                        Com_GetCyclicSendRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetDelayTimeCnt(Index, Value)                             
#define Com_SetGwEvent(Index, Value)                                  
#define Com_SetHandleRxPduDeferred(Index, Value)                      Com_GetHandleRxPduDeferredOfPCConfig()[(Index)] = (Value)
#define Com_SetHandleTxPduDeferred(Index, Value)                      Com_GetHandleTxPduDeferredOfPCConfig()[(Index)] = (Value)
#define Com_SetIPduGroupState(Index, Value)                           
#define Com_SetInitialized(Value)                                     Com_GetInitializedOfPCConfig() = (Value)
#define Com_SetRepCnt(Index, Value)                                   Com_GetRepCntOfPCConfig()[(Index)] = (Value)
#define Com_SetRepCycleCnt(Index, Value)                              Com_GetRepCycleCntOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDefPduBuffer(Index, Value)                           Com_GetRxDefPduBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDynSignalLength(Index, Value)                        
#define Com_SetRxDynSignalTmpLengthForSignalGroups(Index, Value)      
#define Com_SetRxPduDmState(Index, Value)                             Com_GetRxPduDmStateOfPCConfig()[(Index)] = (Value)
#define Com_SetRxPduGrpActive(Index, Value)                           Com_GetRxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetRxShdBufferXInt16(Index, Value)                        Com_GetRxShdBufferXInt16OfPCConfig()[(Index)] = (Value)
#define Com_SetRxShdBufferXInt32(Index, Value)                        
#define Com_SetRxShdBufferXInt8(Index, Value)                         Com_GetRxShdBufferXInt8OfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferXInt16(Index, Value)                        Com_GetRxSigBufferXInt16OfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferXInt32(Index, Value)                        
#define Com_SetRxSigBufferXInt8(Index, Value)                         Com_GetRxSigBufferXInt8OfPCConfig()[(Index)] = (Value)
#define Com_SetRxTOutCnt(Index, Value)                                Com_GetRxTOutCntOfPCConfig()[(Index)] = (Value)
#define Com_SetRxTpBuffer(Index, Value)                               
#define Com_SetRxTpConnectionState(Index, Value)                      
#define Com_SetRxTpSduLength(Index, Value)                            
#define Com_SetRxTpWrittenBytesCounter(Index, Value)                  
#define Com_SetSigGrpEventFlag(Index, Value)                          Com_GetSigGrpEventFlagOfPCConfig()[(Index)] = (Value)
#define Com_SetTmpRxBuffer(Index, Value)                              Com_GetTmpRxBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetTmpRxShdBufferXInt16(Index, Value)                     Com_GetTmpRxShdBufferXInt16OfPCConfig()[(Index)] = (Value)
#define Com_SetTmpRxShdBufferXInt32(Index, Value)                     
#define Com_SetTmpRxShdBufferXInt8(Index, Value)                      Com_GetTmpRxShdBufferXInt8OfPCConfig()[(Index)] = (Value)
#define Com_SetTransmitRequest(Index, Value)                          Com_GetTransmitRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetTxDynSignalLength(Index, Value)                        
#define Com_SetTxFilterOldValueXInt16(Index, Value)                   
#define Com_SetTxFilterOldValueXInt32(Index, Value)                   
#define Com_SetTxFilterOldValueXInt8(Index, Value)                    
#define Com_SetTxFilterState(Index, Value)                            
#define Com_SetTxPduBuffer(Index, Value)                              Com_GetTxPduBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetTxPduGrpActive(Index, Value)                           Com_GetTxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetTxSduLength(Index, Value)                              Com_GetTxSduLengthOfPCConfig()[(Index)] = (Value)
#define Com_SetTxShdBuffer(Index, Value)                              Com_GetTxShdBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetTxTOutCnt(Index, Value)                                
#define Com_SetTxTmpTpPduLength(Index, Value)                         
#define Com_SetTxTpConnectionState(Index, Value)                      
#define Com_SetTxTpSduLength(Index, Value)                            
#define Com_SetTxTpWrittenBytesCounter(Index, Value)                  
#define Com_SetWaitingForConfirmation(Index, Value)                   Com_GetWaitingForConfirmationOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  PCGetAddressOfDataMacros  Get Address Of Data Macros (PRE-COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Com_GetAddrConstValueXInt16(Index)                            &Com_GetConstValueXInt16(Index)
#define Com_GetAddrConstValueXInt32(Index)                            
#define Com_GetAddrConstValueXInt8(Index)                             &Com_GetConstValueXInt8(Index)
#define Com_GetAddrRxDefPduBuffer(Index)                              &Com_GetRxDefPduBuffer(Index)
#define Com_GetAddrRxShdBufferXInt16(Index)                           &Com_GetRxShdBufferXInt16(Index)
#define Com_GetAddrRxShdBufferXInt32(Index)                           
#define Com_GetAddrRxShdBufferXInt8(Index)                            &Com_GetRxShdBufferXInt8(Index)
#define Com_GetAddrRxSigBufferXInt16(Index)                           &Com_GetRxSigBufferXInt16(Index)
#define Com_GetAddrRxSigBufferXInt32(Index)                           
#define Com_GetAddrRxSigBufferXInt8(Index)                            &Com_GetRxSigBufferXInt8(Index)
#define Com_GetAddrRxTpBuffer(Index)                                  
#define Com_GetAddrTmpRxBuffer(Index)                                 &Com_GetTmpRxBuffer(Index)
#define Com_GetAddrTmpRxShdBufferXInt16(Index)                        &Com_GetTmpRxShdBufferXInt16(Index)
#define Com_GetAddrTmpRxShdBufferXInt32(Index)                        
#define Com_GetAddrTmpRxShdBufferXInt8(Index)                         &Com_GetTmpRxShdBufferXInt8(Index)
#define Com_GetAddrTxFilterInitValueXInt16(Index)                     
#define Com_GetAddrTxFilterInitValueXInt32(Index)                     
#define Com_GetAddrTxFilterInitValueXInt8(Index)                      
#define Com_GetAddrTxFilterOldValueXInt16(Index)                      
#define Com_GetAddrTxFilterOldValueXInt32(Index)                      
#define Com_GetAddrTxFilterOldValueXInt8(Index)                       
#define Com_GetAddrTxPduBuffer(Index)                                 &Com_GetTxPduBuffer(Index)
#define Com_GetAddrTxPduInitValue(Index)                              &Com_GetTxPduInitValue(Index)
#define Com_GetAddrTxShdBuffer(Index)                                 &Com_GetTxShdBuffer(Index)
#define Com_GetAddrTxSigGrpMask(Index)                                &Com_GetTxSigGrpMask(Index)
#define Com_GetAddrTxSigGrpOnChangeMask(Index)                        
/** 
  \}
*/ 

/** 
  \defgroup  PCHasMacros  Has Macros (PRE-COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Com_HasAllSigCnt()                                            (TRUE != FALSE)
#define Com_HasAllSigGrpCnt()                                         (TRUE != FALSE)
#define Com_HasCbkInvFuncPtr()                                        (FALSE != FALSE)  /**< Deactivateable: 'Com_CbkInvFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasCbkRxAckFuncPtr()                                      (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtr()                                     (TRUE != FALSE)
#define Com_HasCbkTxAckDefFuncPtr()                                   (FALSE != FALSE)  /**< Deactivateable: 'Com_CbkTxAckDefFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasCbkTxAckImFuncPtr()                                    (FALSE != FALSE)  /**< Deactivateable: 'Com_CbkTxAckImFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasCbkTxErrFuncPtr()                                      (FALSE != FALSE)  /**< Deactivateable: 'Com_CbkTxErrFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasCbkTxTOutFuncPtr()                                     (FALSE != FALSE)  /**< Deactivateable: 'Com_CbkTxTOutFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasConfigId()                                             (TRUE != FALSE)
#define Com_HasConstValueXInt16()                                     (TRUE != FALSE)
#define Com_HasConstValueXInt32()                                     (FALSE != FALSE)  /**< Deactivateable: 'Com_ConstValueXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasConstValueXInt8()                                      (TRUE != FALSE)
#define Com_HasCurrentTxMode()                                        (TRUE != FALSE)
#define Com_HasCycleTimeCnt()                                         (TRUE != FALSE)
#define Com_HasCyclicSendRequest()                                    (TRUE != FALSE)
#define Com_HasDelayTimeCnt()                                         (FALSE != FALSE)  /**< Deactivateable: 'Com_DelayTimeCnt' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasFilterInfo()                                           (FALSE != FALSE)  /**< Deactivateable: 'Com_FilterInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Com_HasApplTypeOfFilterInfo()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_FilterInfo.ApplType' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasFilterAlgoOfFilterInfo()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_FilterInfo.FilterAlgo' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasFilterParamIdxOfFilterInfo()                           (FALSE != FALSE)  /**< Deactivateable: 'Com_FilterInfo.FilterParamIdx' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasFilterParamUsedOfFilterInfo()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_FilterInfo.FilterParamUsed' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasLengthOfFilterInfo()                                   (FALSE != FALSE)  /**< Deactivateable: 'Com_FilterInfo.Length' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasFinalMagicNumber()                                     (FALSE != FALSE)  /**< Deactivateable: 'Com_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Com_HasGwEvent()                                              (FALSE != FALSE)  /**< Deactivateable: 'Com_GwEvent' Reason: 'The gateway is deactivated!' */
#define Com_HasGwGrpSigMapping()                                      (FALSE != FALSE)  /**< Deactivateable: 'Com_GwGrpSigMapping' Reason: 'The gateway is deactivated!' */
#define Com_HasRxAccessInfoIdxOfGwGrpSigMapping()                     (FALSE != FALSE)  /**< Deactivateable: 'Com_GwGrpSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasTxSigIdOfGwGrpSigMapping()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_GwGrpSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define Com_HasGwInfo()                                               (FALSE != FALSE)  /**< Deactivateable: 'Com_GwInfo' Reason: 'The gateway is deactivated!' */
#define Com_HasGwSigGrpMappingEndIdxOfGwInfo()                        (FALSE != FALSE)  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasGwSigGrpMappingStartIdxOfGwInfo()                      (FALSE != FALSE)  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasGwSigGrpMappingUsedOfGwInfo()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingUsed' Reason: 'The gateway is deactivated!' */
#define Com_HasGwSigMappingEndIdxOfGwInfo()                           (FALSE != FALSE)  /**< Deactivateable: 'Com_GwInfo.GwSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasGwSigMappingStartIdxOfGwInfo()                         (FALSE != FALSE)  /**< Deactivateable: 'Com_GwInfo.GwSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasGwSigMappingUsedOfGwInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_GwInfo.GwSigMappingUsed' Reason: 'The gateway is deactivated!' */
#define Com_HasGwSigGrpMapping()                                      (FALSE != FALSE)  /**< Deactivateable: 'Com_GwSigGrpMapping' Reason: 'The gateway is deactivated!' */
#define Com_HasGwGrpSigMappingEndIdxOfGwSigGrpMapping()               (FALSE != FALSE)  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasGwGrpSigMappingStartIdxOfGwSigGrpMapping()             (FALSE != FALSE)  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasTxSigGrpIdOfGwSigGrpMapping()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_GwSigGrpMapping.TxSigGrpId' Reason: 'The gateway is deactivated!' */
#define Com_HasGwSigMapping()                                         (FALSE != FALSE)  /**< Deactivateable: 'Com_GwSigMapping' Reason: 'The gateway is deactivated!' */
#define Com_HasRxAccessInfoIdxOfGwSigMapping()                        (FALSE != FALSE)  /**< Deactivateable: 'Com_GwSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasTxSigIdOfGwSigMapping()                                (FALSE != FALSE)  /**< Deactivateable: 'Com_GwSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define Com_HasHandleRxPduDeferred()                                  (TRUE != FALSE)
#define Com_HasHandleTxPduDeferred()                                  (TRUE != FALSE)
#define Com_HasIPduGroupInfo()                                        (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasIPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo() (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo() (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasIPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo()   (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasInvalidHndOfIPduGroupInfo()                            (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo.InvalidHnd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasRxPduInfoIndEndIdxOfIPduGroupInfo()                    (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasRxPduInfoIndStartIdxOfIPduGroupInfo()                  (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasRxPduInfoIndUsedOfIPduGroupInfo()                      (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasTxPduInfoIndEndIdxOfIPduGroupInfo()                    (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasTxPduInfoIndStartIdxOfIPduGroupInfo()                  (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasTxPduInfoIndUsedOfIPduGroupInfo()                      (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasIPduGroupInfoOfRxPduInfoInd()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfoOfRxPduInfoInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasIPduGroupInfoOfTxPduInfoInd()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfoOfTxPduInfoInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasIPduGroupInfoToSubIPduGroupsInd()                      (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupInfoToSubIPduGroupsInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasIPduGroupState()                                       (FALSE != FALSE)  /**< Deactivateable: 'Com_IPduGroupState' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define Com_HasInitDataHashCode()                                     (FALSE != FALSE)  /**< Deactivateable: 'Com_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Com_HasInitialized()                                          (TRUE != FALSE)
#define Com_HasPduGrpCnt()                                            (TRUE != FALSE)
#define Com_HasPduGrpVector()                                         (TRUE != FALSE)
#define Com_HasRepCnt()                                               (TRUE != FALSE)
#define Com_HasRepCycleCnt()                                          (TRUE != FALSE)
#define Com_HasRxAccessInfo()                                         (TRUE != FALSE)
#define Com_HasApplTypeOfRxAccessInfo()                               (TRUE != FALSE)
#define Com_HasBitLengthOfRxAccessInfo()                              (TRUE != FALSE)
#define Com_HasBitPositionOfRxAccessInfo()                            (TRUE != FALSE)
#define Com_HasBufferIdxOfRxAccessInfo()                              (TRUE != FALSE)
#define Com_HasBufferUsedOfRxAccessInfo()                             (TRUE != FALSE)
#define Com_HasBusAccOfRxAccessInfo()                                 (TRUE != FALSE)
#define Com_HasByteLengthOfRxAccessInfo()                             (TRUE != FALSE)
#define Com_HasBytePositionOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasGwInfoIdxOfRxAccessInfo()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasGwInfoUsedOfRxAccessInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define Com_HasInitValueIdxOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasInitValueUsedOfRxAccessInfo()                          (TRUE != FALSE)
#define Com_HasInvalidHndOfRxAccessInfo()                             (TRUE != FALSE)
#define Com_HasPduIdOfRxAccessInfo()                                  (TRUE != FALSE)
#define Com_HasRxDataTimeoutSubstitutionValueIdxOfRxAccessInfo()      (TRUE != FALSE)
#define Com_HasRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo()     (TRUE != FALSE)
#define Com_HasShdBufferIdxOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasShdBufferUsedOfRxAccessInfo()                          (TRUE != FALSE)
#define Com_HasSignExtRequiredOfRxAccessInfo()                        (FALSE != FALSE)  /**< Deactivateable: 'Com_RxAccessInfo.SignExtRequired' Reason: 'the value of Com_SignExtRequiredOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define Com_HasRxAccessInfoInd()                                      (TRUE != FALSE)
#define Com_HasRxAccessInfoReplaceGrpSigInd()                         (FALSE != FALSE)  /**< Deactivateable: 'Com_RxAccessInfoReplaceGrpSigInd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasRxAccessInfoReplaceSigInd()                            (TRUE != FALSE)
#define Com_HasRxDefPduBuffer()                                       (TRUE != FALSE)
#define Com_HasRxDynSignalLength()                                    (FALSE != FALSE)  /**< Deactivateable: 'Com_RxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxDynSignalTmpLengthForSignalGroups()                  (FALSE != FALSE)  /**< Deactivateable: 'Com_RxDynSignalTmpLengthForSignalGroups' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxGrpSigInfo()                                         (TRUE != FALSE)
#define Com_HasFilterInfoIdxOfRxGrpSigInfo()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_RxGrpSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxGrpSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasFilterInfoUsedOfRxGrpSigInfo()                         (FALSE != FALSE)  /**< Deactivateable: 'Com_RxGrpSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxGrpSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasInvValueIdxOfRxGrpSigInfo()                            (FALSE != FALSE)  /**< Deactivateable: 'Com_RxGrpSigInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxGrpSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasInvValueUsedOfRxGrpSigInfo()                           (FALSE != FALSE)  /**< Deactivateable: 'Com_RxGrpSigInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxGrpSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxAccessInfoIdxOfRxGrpSigInfo()                        (TRUE != FALSE)
#define Com_HasTmpBufferIdxOfRxGrpSigInfo()                           (TRUE != FALSE)
#define Com_HasTmpBufferUsedOfRxGrpSigInfo()                          (TRUE != FALSE)
#define Com_HasRxPduCalloutFuncPtr()                                  (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasRxPduDmState()                                         (TRUE != FALSE)
#define Com_HasRxPduGrpActive()                                       (TRUE != FALSE)
#define Com_HasRxPduGrpInfo()                                         (TRUE != FALSE)
#define Com_HasPduGrpVectorEndIdxOfRxPduGrpInfo()                     (TRUE != FALSE)
#define Com_HasPduGrpVectorStartIdxOfRxPduGrpInfo()                   (TRUE != FALSE)
#define Com_HasPduGrpVectorUsedOfRxPduGrpInfo()                       (TRUE != FALSE)
#define Com_HasRxPduInfo()                                            (TRUE != FALSE)
#define Com_HasGwInfoEndIdxOfRxPduInfo()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfo.GwInfoEndIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasGwInfoStartIdxOfRxPduInfo()                            (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfo.GwInfoStartIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasGwInfoUsedOfRxPduInfo()                                (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define Com_HasHandleRxPduDeferredIdxOfRxPduInfo()                    (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredUsedOfRxPduInfo()                   (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo()         (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndEndIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo()       (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndStartIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo()           (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndUsed' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasInvalidHndOfRxPduInfo()                                (TRUE != FALSE)
#define Com_HasRxAccessInfoIndEndIdxOfRxPduInfo()                     (TRUE != FALSE)
#define Com_HasRxAccessInfoIndStartIdxOfRxPduInfo()                   (TRUE != FALSE)
#define Com_HasRxAccessInfoIndUsedOfRxPduInfo()                       (TRUE != FALSE)
#define Com_HasRxDefPduBufferEndIdxOfRxPduInfo()                      (TRUE != FALSE)
#define Com_HasRxDefPduBufferLengthOfRxPduInfo()                      (TRUE != FALSE)
#define Com_HasRxDefPduBufferStartIdxOfRxPduInfo()                    (TRUE != FALSE)
#define Com_HasRxDefPduBufferUsedOfRxPduInfo()                        (TRUE != FALSE)
#define Com_HasRxPduCalloutFuncPtrIdxOfRxPduInfo()                    (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxPduCalloutFuncPtrUsedOfRxPduInfo()                   (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxSigGrpInfoIndEndIdxOfRxPduInfo()                     (TRUE != FALSE)
#define Com_HasRxSigGrpInfoIndStartIdxOfRxPduInfo()                   (TRUE != FALSE)
#define Com_HasRxSigGrpInfoIndUsedOfRxPduInfo()                       (TRUE != FALSE)
#define Com_HasRxSigInfoEndIdxOfRxPduInfo()                           (TRUE != FALSE)
#define Com_HasRxSigInfoStartIdxOfRxPduInfo()                         (TRUE != FALSE)
#define Com_HasRxSigInfoUsedOfRxPduInfo()                             (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxPduInfo()                             (TRUE != FALSE)
#define Com_HasRxTOutInfoIndEndIdxOfRxPduInfo()                       (TRUE != FALSE)
#define Com_HasRxTOutInfoIndStartIdxOfRxPduInfo()                     (TRUE != FALSE)
#define Com_HasRxTOutInfoIndUsedOfRxPduInfo()                         (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxPduInfo()                            (TRUE != FALSE)
#define Com_HasRxTpInfoIdxOfRxPduInfo()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxTpInfoUsedOfRxPduInfo()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxPduInfoInd()                                         (FALSE != FALSE)  /**< Deactivateable: 'Com_RxPduInfoInd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasRxShdBufferXInt16()                                    (TRUE != FALSE)
#define Com_HasRxShdBufferXInt32()                                    (FALSE != FALSE)  /**< Deactivateable: 'Com_RxShdBufferXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasRxShdBufferXInt8()                                     (TRUE != FALSE)
#define Com_HasRxSigBufferXInt16()                                    (TRUE != FALSE)
#define Com_HasRxSigBufferXInt32()                                    (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigBufferXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasRxSigBufferXInt8()                                     (TRUE != FALSE)
#define Com_HasRxSigGrpInfo()                                         (TRUE != FALSE)
#define Com_HasArrayAccessUsedOfRxSigGrpInfo()                        (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.ArrayAccessUsed' Reason: 'the value of Com_ArrayAccessUsedOfRxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define Com_HasCbkInvFuncPtrIdxOfRxSigGrpInfo()                       (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.CbkInvFuncPtrIdx' Reason: 'the optional indirection is deactivated because CbkInvFuncPtrUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkInvFuncPtrUsedOfRxSigGrpInfo()                      (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.CbkInvFuncPtrUsed' Reason: 'the optional indirection is deactivated because CbkInvFuncPtrUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkRxAckFuncPtrIdxOfRxSigGrpInfo()                     (TRUE != FALSE)
#define Com_HasCbkRxAckFuncPtrUsedOfRxSigGrpInfo()                    (TRUE != FALSE)
#define Com_HasConstValueXInt8EndIdxOfRxSigGrpInfo()                  (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueXInt8EndIdx' Reason: 'the optional indirection is deactivated because ConstValueXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasConstValueXInt8LengthOfRxSigGrpInfo()                  (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueXInt8Length' Reason: 'the optional indirection is deactivated because ConstValueXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasConstValueXInt8StartIdxOfRxSigGrpInfo()                (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueXInt8StartIdx' Reason: 'the optional indirection is deactivated because ConstValueXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasConstValueXInt8UsedOfRxSigGrpInfo()                    (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueXInt8Used' Reason: 'the optional indirection is deactivated because ConstValueXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasFilterEventOfRxSigGrpInfo()                            (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.FilterEvent' Reason: 'the value of Com_FilterEventOfRxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define Com_HasGwInfoIdxOfRxSigGrpInfo()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasGwInfoUsedOfRxSigGrpInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define Com_HasInvEventOfRxSigGrpInfo()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.InvEvent' Reason: 'the value of Com_InvEventOfRxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define Com_HasInvalidHndOfRxSigGrpInfo()                             (TRUE != FALSE)
#define Com_HasRxGrpSigInfoEndIdxOfRxSigGrpInfo()                     (TRUE != FALSE)
#define Com_HasRxGrpSigInfoStartIdxOfRxSigGrpInfo()                   (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxSigGrpInfo()                           (TRUE != FALSE)
#define Com_HasRxPduInfoUsedOfRxSigGrpInfo()                          (TRUE != FALSE)
#define Com_HasRxShdBufferXInt8EndIdxOfRxSigGrpInfo()                 (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.RxShdBufferXInt8EndIdx' Reason: 'the optional indirection is deactivated because RxShdBufferXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxShdBufferXInt8LengthOfRxSigGrpInfo()                 (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.RxShdBufferXInt8Length' Reason: 'the optional indirection is deactivated because RxShdBufferXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxShdBufferXInt8StartIdxOfRxSigGrpInfo()               (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.RxShdBufferXInt8StartIdx' Reason: 'the optional indirection is deactivated because RxShdBufferXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxShdBufferXInt8UsedOfRxSigGrpInfo()                   (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.RxShdBufferXInt8Used' Reason: 'the optional indirection is deactivated because RxShdBufferXInt8UsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxTOutInfoIdxOfRxSigGrpInfo()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxTOutInfoUsedOfRxSigGrpInfo()                         (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasSignalProcessingOfRxSigGrpInfo()                       (TRUE != FALSE)
#define Com_HasStartBytePositionOfRxSigGrpInfo()                      (TRUE != FALSE)
#define Com_HasUbIdxOfRxSigGrpInfo()                                  (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.UbIdx' Reason: 'the value of Com_UbIdxOfRxSigGrpInfo is always 'COM_NO_UBIDXOFRXSIGGRPINFO' due to this, the array is deactivated.' */
#define Com_HasUbMaskIdxOfRxSigGrpInfo()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasUbMaskUsedOfRxSigGrpInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasValidDlcOfRxSigGrpInfo()                               (TRUE != FALSE)
#define Com_HasRxSigGrpInfoInd()                                      (TRUE != FALSE)
#define Com_HasRxSigInfo()                                            (TRUE != FALSE)
#define Com_HasCbkInvFuncPtrIdxOfRxSigInfo()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.CbkInvFuncPtrIdx' Reason: 'the optional indirection is deactivated because CbkInvFuncPtrUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkInvFuncPtrUsedOfRxSigInfo()                         (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.CbkInvFuncPtrUsed' Reason: 'the optional indirection is deactivated because CbkInvFuncPtrUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkRxAckFuncPtrIdxOfRxSigInfo()                        (TRUE != FALSE)
#define Com_HasCbkRxAckFuncPtrUsedOfRxSigInfo()                       (TRUE != FALSE)
#define Com_HasFilterInfoIdxOfRxSigInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasFilterInfoUsedOfRxSigInfo()                            (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasGwInfoIdxOfRxSigInfo()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define Com_HasGwInfoUsedOfRxSigInfo()                                (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define Com_HasInvValueIdxOfRxSigInfo()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasInvValueUsedOfRxSigInfo()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxAccessInfoIdxOfRxSigInfo()                           (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxSigInfo()                             (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxSigInfo()                            (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxSigInfo()                          (TRUE != FALSE)
#define Com_HasUbIdxOfRxSigInfo()                                     (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.UbIdx' Reason: 'the value of Com_UbIdxOfRxSigInfo is always 'COM_NO_UBIDXOFRXSIGINFO' due to this, the array is deactivated.' */
#define Com_HasUbMaskIdxOfRxSigInfo()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasUbMaskUsedOfRxSigInfo()                                (FALSE != FALSE)  /**< Deactivateable: 'Com_RxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasValidDlcOfRxSigInfo()                                  (TRUE != FALSE)
#define Com_HasRxTOutCnt()                                            (TRUE != FALSE)
#define Com_HasRxTOutInfo()                                           (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrEndIdxOfRxTOutInfo()                   (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrStartIdxOfRxTOutInfo()                 (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrUsedOfRxTOutInfo()                     (TRUE != FALSE)
#define Com_HasFactorOfRxTOutInfo()                                   (TRUE != FALSE)
#define Com_HasFirstFactorOfRxTOutInfo()                              (TRUE != FALSE)
#define Com_HasRxAccessInfoReplaceGrpSigIndEndIdxOfRxTOutInfo()       (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndEndIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxAccessInfoReplaceGrpSigIndStartIdxOfRxTOutInfo()     (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndStartIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo()         (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndUsed' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasRxAccessInfoReplaceSigIndEndIdxOfRxTOutInfo()          (TRUE != FALSE)
#define Com_HasRxAccessInfoReplaceSigIndStartIdxOfRxTOutInfo()        (TRUE != FALSE)
#define Com_HasRxAccessInfoReplaceSigIndUsedOfRxTOutInfo()            (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxTOutInfo()                             (TRUE != FALSE)
#define Com_HasRxTOutInfoInd()                                        (TRUE != FALSE)
#define Com_HasRxTpBuffer()                                           (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpBuffer' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxTpConnectionState()                                  (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxTpInfo()                                             (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasBufferSizeOfRxTpInfo()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxAccessInfoDynSigIdxOfRxTpInfo()                      (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxAccessInfoDynSigUsedOfRxTpInfo()                     (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxTpBufferEndIdxOfRxTpInfo()                           (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxTpBufferStartIdxOfRxTpInfo()                         (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxTpBufferUsedOfRxTpInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxTpSduLength()                                        (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasRxTpWrittenBytesCounter()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_RxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasSigGrpEventFlag()                                      (TRUE != FALSE)
#define Com_HasSizeOfCbkRxAckFuncPtr()                                (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtr()                               (TRUE != FALSE)
#define Com_HasSizeOfConstValueXInt16()                               (TRUE != FALSE)
#define Com_HasSizeOfConstValueXInt8()                                (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxMode()                                  (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCnt()                                   (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequest()                              (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferred()                            (TRUE != FALSE)
#define Com_HasSizeOfHandleTxPduDeferred()                            (TRUE != FALSE)
#define Com_HasSizeOfPduGrpVector()                                   (TRUE != FALSE)
#define Com_HasSizeOfRepCnt()                                         (TRUE != FALSE)
#define Com_HasSizeOfRepCycleCnt()                                    (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoInd()                                (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoReplaceSigInd()                      (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBuffer()                                 (TRUE != FALSE)
#define Com_HasSizeOfRxGrpSigInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxPduDmState()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActive()                                 (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfRxShdBufferXInt16()                              (TRUE != FALSE)
#define Com_HasSizeOfRxShdBufferXInt8()                               (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferXInt16()                              (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferXInt8()                               (TRUE != FALSE)
#define Com_HasSizeOfRxSigGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxSigGrpInfoInd()                                (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfRxTOutCnt()                                      (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfo()                                     (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoInd()                                  (TRUE != FALSE)
#define Com_HasSizeOfSigGrpEventFlag()                                (TRUE != FALSE)
#define Com_HasSizeOfTmpRxBuffer()                                    (TRUE != FALSE)
#define Com_HasSizeOfTmpRxShdBufferXInt16()                           (TRUE != FALSE)
#define Com_HasSizeOfTmpRxShdBufferXInt8()                            (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequest()                                (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfo()                                     (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrue()                                     (TRUE != FALSE)
#define Com_HasSizeOfTxPduBuffer()                                    (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActive()                                 (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValue()                                 (TRUE != FALSE)
#define Com_HasSizeOfTxSduLength()                                    (TRUE != FALSE)
#define Com_HasSizeOfTxShdBuffer()                                    (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfoInd()                                (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpMask()                                   (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfWaitingForConfirmation()                         (TRUE != FALSE)
#define Com_HasTmpRxBuffer()                                          (TRUE != FALSE)
#define Com_HasTmpRxShdBufferXInt16()                                 (TRUE != FALSE)
#define Com_HasTmpRxShdBufferXInt32()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TmpRxShdBufferXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTmpRxShdBufferXInt8()                                  (TRUE != FALSE)
#define Com_HasTransmitRequest()                                      (TRUE != FALSE)
#define Com_HasTxDynSignalLength()                                    (FALSE != FALSE)  /**< Deactivateable: 'Com_TxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxFilterInitState()                                    (FALSE != FALSE)  /**< Deactivateable: 'Com_TxFilterInitState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxFilterInitValueXInt16()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_TxFilterInitValueXInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxFilterInitValueXInt32()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_TxFilterInitValueXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxFilterInitValueXInt8()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_TxFilterInitValueXInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxFilterOldValueXInt16()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_TxFilterOldValueXInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxFilterOldValueXInt32()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_TxFilterOldValueXInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxFilterOldValueXInt8()                                (FALSE != FALSE)  /**< Deactivateable: 'Com_TxFilterOldValueXInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxFilterState()                                        (FALSE != FALSE)  /**< Deactivateable: 'Com_TxFilterState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxModeFalse()                                          (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeFalse' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Com_HasDirectOfTxModeFalse()                                  (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeFalse.Direct' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasPeriodicOfTxModeFalse()                                (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeFalse.Periodic' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasRepCntOfTxModeFalse()                                  (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeFalse.RepCnt' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasRepPeriodOfTxModeFalse()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeFalse.RepPeriod' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTimeOffsetOfTxModeFalse()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeFalse.TimeOffset' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTimePeriodOfTxModeFalse()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeFalse.TimePeriod' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxModeInfo()                                           (TRUE != FALSE)
#define Com_HasInitModeOfTxModeInfo()                                 (TRUE != FALSE)
#define Com_HasInvalidHndOfTxModeInfo()                               (TRUE != FALSE)
#define Com_HasMinimumDelayOfTxModeInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeInfo.MinimumDelay' Reason: 'the value of Com_MinimumDelayOfTxModeInfo is always '0' due to this, the array is deactivated.' */
#define Com_HasTxFilterInitStateEndIdxOfTxModeInfo()                  (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxFilterInitStateStartIdxOfTxModeInfo()                (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxFilterInitStateUsedOfTxModeInfo()                    (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxModeFalseIdxOfTxModeInfo()                           (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeInfo.TxModeFalseIdx' Reason: 'the optional indirection is deactivated because TxModeFalseUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxModeFalseUsedOfTxModeInfo()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeInfo.TxModeFalseUsed' Reason: 'the optional indirection is deactivated because TxModeFalseUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxModeTrueIdxOfTxModeInfo()                            (TRUE != FALSE)
#define Com_HasTxModeTrueUsedOfTxModeInfo()                           (TRUE != FALSE)
#define Com_HasTxSigInfoFilterInitValueIndEndIdxOfTxModeInfo()        (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxSigInfoFilterInitValueIndStartIdxOfTxModeInfo()      (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxSigInfoFilterInitValueIndUsedOfTxModeInfo()          (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndUsed' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxModeTrue()                                           (TRUE != FALSE)
#define Com_HasDirectOfTxModeTrue()                                   (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeTrue.Direct' Reason: 'the value of Com_DirectOfTxModeTrue is always 'false' due to this, the array is deactivated.' */
#define Com_HasPeriodicOfTxModeTrue()                                 (TRUE != FALSE)
#define Com_HasRepCntOfTxModeTrue()                                   (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeTrue.RepCnt' Reason: 'the value of Com_RepCntOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define Com_HasRepPeriodOfTxModeTrue()                                (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeTrue.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define Com_HasTimeOffsetOfTxModeTrue()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_TxModeTrue.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeTrue is always '1' due to this, the array is deactivated.' */
#define Com_HasTimePeriodOfTxModeTrue()                               (TRUE != FALSE)
#define Com_HasTxPduBuffer()                                          (TRUE != FALSE)
#define Com_HasTxPduCalloutFuncPtr()                                  (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxPduGrpActive()                                       (TRUE != FALSE)
#define Com_HasTxPduGrpInfo()                                         (TRUE != FALSE)
#define Com_HasPduGrpVectorEndIdxOfTxPduGrpInfo()                     (TRUE != FALSE)
#define Com_HasPduGrpVectorStartIdxOfTxPduGrpInfo()                   (TRUE != FALSE)
#define Com_HasPduGrpVectorUsedOfTxPduGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxPduInfo()                                            (TRUE != FALSE)
#define Com_HasCancellationSupportOfTxPduInfo()                       (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.CancellationSupport' Reason: 'the value of Com_CancellationSupportOfTxPduInfo is always 'false' due to this, the array is deactivated.' */
#define Com_HasCbkTxAckDefFuncPtrEndIdxOfTxPduInfo()                  (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkTxAckDefFuncPtrStartIdxOfTxPduInfo()                (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkTxAckDefFuncPtrUsedOfTxPduInfo()                    (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrUsed' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkTxAckImFuncPtrEndIdxOfTxPduInfo()                   (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkTxAckImFuncPtrStartIdxOfTxPduInfo()                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkTxAckImFuncPtrUsedOfTxPduInfo()                     (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrUsed' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkTxErrFuncPtrEndIdxOfTxPduInfo()                     (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrEndIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkTxErrFuncPtrStartIdxOfTxPduInfo()                   (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrStartIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasCbkTxErrFuncPtrUsedOfTxPduInfo()                       (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrUsed' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasClrUbOfTxPduInfo()                                     (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define Com_HasConstValueXInt8UbClearMaskEndIdxOfTxPduInfo()          (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.ConstValueXInt8UbClearMaskEndIdx' Reason: 'the optional indirection is deactivated because ConstValueXInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasConstValueXInt8UbClearMaskStartIdxOfTxPduInfo()        (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.ConstValueXInt8UbClearMaskStartIdx' Reason: 'the optional indirection is deactivated because ConstValueXInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasConstValueXInt8UbClearMaskUsedOfTxPduInfo()            (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.ConstValueXInt8UbClearMaskUsed' Reason: 'the optional indirection is deactivated because ConstValueXInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasExternalIdOfTxPduInfo()                                (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo()         (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndEndIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo()       (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndStartIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo()           (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndUsed' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasInvalidHndOfTxPduInfo()                                (TRUE != FALSE)
#define Com_HasMetaDataLengthOfTxPduInfo()                            (TRUE != FALSE)
#define Com_HasPduWithMetaDataLengthOfTxPduInfo()                     (TRUE != FALSE)
#define Com_HasTxPduBufferEndIdxOfTxPduInfo()                         (TRUE != FALSE)
#define Com_HasTxPduBufferLengthOfTxPduInfo()                         (TRUE != FALSE)
#define Com_HasTxPduBufferMetaDataEndIdxOfTxPduInfo()                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxPduBufferMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define Com_HasTxPduBufferMetaDataStartIdxOfTxPduInfo()               (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxPduBufferMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define Com_HasTxPduBufferMetaDataUsedOfTxPduInfo()                   (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxPduBufferMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define Com_HasTxPduBufferStartIdxOfTxPduInfo()                       (TRUE != FALSE)
#define Com_HasTxPduBufferUsedOfTxPduInfo()                           (TRUE != FALSE)
#define Com_HasTxPduCalloutFuncPtrIdxOfTxPduInfo()                    (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxPduCalloutFuncPtrUsedOfTxPduInfo()                   (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxPduInitValueEndIdxOfTxPduInfo()                      (TRUE != FALSE)
#define Com_HasTxPduInitValueMetaDataEndIdxOfTxPduInfo()              (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define Com_HasTxPduInitValueMetaDataStartIdxOfTxPduInfo()            (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define Com_HasTxPduInitValueMetaDataUsedOfTxPduInfo()                (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define Com_HasTxPduInitValueStartIdxOfTxPduInfo()                    (TRUE != FALSE)
#define Com_HasTxPduInitValueUsedOfTxPduInfo()                        (TRUE != FALSE)
#define Com_HasTxPduTTCalloutFuncPtrIdxOfTxPduInfo()                  (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxPduTTCalloutFuncPtrUsedOfTxPduInfo()                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxSigGrpInfoIndEndIdxOfTxPduInfo()                     (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndStartIdxOfTxPduInfo()                   (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndUsedOfTxPduInfo()                       (TRUE != FALSE)
#define Com_HasTxTOutInfoIdxOfTxPduInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxTOutInfoUsedOfTxPduInfo()                            (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxTpInfoIdxOfTxPduInfo()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxTpInfoUsedOfTxPduInfo()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxPduInfoInd()                                         (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduInfoInd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxPduInitValue()                                       (TRUE != FALSE)
#define Com_HasTxPduTTCalloutFuncPtr()                                (FALSE != FALSE)  /**< Deactivateable: 'Com_TxPduTTCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxSduLength()                                          (TRUE != FALSE)
#define Com_HasTxShdBuffer()                                          (TRUE != FALSE)
#define Com_HasTxSigGrpInfo()                                         (TRUE != FALSE)
#define Com_HasArrayAccessUsedOfTxSigGrpInfo()                        (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.ArrayAccessUsed' Reason: 'the value of Com_ArrayAccessUsedOfTxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define Com_HasInvalidHndOfTxSigGrpInfo()                             (TRUE != FALSE)
#define Com_HasPduIdOfTxSigGrpInfo()                                  (TRUE != FALSE)
#define Com_HasPduOffsetOfTxSigGrpInfo()                              (TRUE != FALSE)
#define Com_HasSigGroupOnChangeOffsetOfTxSigGrpInfo()                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasSigGroupOnChangeStartPositionOfTxSigGrpInfo()          (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasSigGroupOnChangeWithoutRepOffsetOfTxSigGrpInfo()       (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasSigGroupOnChangeWithoutRepStartPositionOfTxSigGrpInfo() (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasTransferPropertyOfTxSigGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxShdBufferEndIdxOfTxSigGrpInfo()                      (TRUE != FALSE)
#define Com_HasTxShdBufferLengthOfTxSigGrpInfo()                      (TRUE != FALSE)
#define Com_HasTxShdBufferStartIdxOfTxSigGrpInfo()                    (TRUE != FALSE)
#define Com_HasTxShdBufferUsedOfTxSigGrpInfo()                        (TRUE != FALSE)
#define Com_HasTxSigGrpMaskEndIdxOfTxSigGrpInfo()                     (TRUE != FALSE)
#define Com_HasTxSigGrpMaskLengthOfTxSigGrpInfo()                     (TRUE != FALSE)
#define Com_HasTxSigGrpMaskStartIdxOfTxSigGrpInfo()                   (TRUE != FALSE)
#define Com_HasTxSigGrpMaskUsedOfTxSigGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxSigGrpOnChangeMaskOnChangeEndIdxOfTxSigGrpInfo()     (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasTxSigGrpOnChangeMaskOnChangeLengthOfTxSigGrpInfo()     (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasTxSigGrpOnChangeMaskOnChangeStartIdxOfTxSigGrpInfo()   (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasTxSigGrpOnChangeMaskOnChangeUsedOfTxSigGrpInfo()       (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepEndIdxOfTxSigGrpInfo() (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepLengthOfTxSigGrpInfo() (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepStartIdxOfTxSigGrpInfo() (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepUsedOfTxSigGrpInfo() (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasTxSigInfoInvValueIndEndIdxOfTxSigGrpInfo()             (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigInfoInvValueIndUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxSigInfoInvValueIndStartIdxOfTxSigGrpInfo()           (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigInfoInvValueIndUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxSigInfoInvValueIndUsedOfTxSigGrpInfo()               (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndUsed' Reason: 'the optional indirection is deactivated because TxSigInfoInvValueIndUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxTOutInfoIdxOfTxSigGrpInfo()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxTOutInfoUsedOfTxSigGrpInfo()                         (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasUbIdxOfTxSigGrpInfo()                                  (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.UbIdx' Reason: 'the value of Com_UbIdxOfTxSigGrpInfo is always 'COM_NO_UBIDXOFTXSIGGRPINFO' due to this, the array is deactivated.' */
#define Com_HasUbMaskIdxOfTxSigGrpInfo()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasUbMaskUsedOfTxSigGrpInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxSigGrpInfoInd()                                      (TRUE != FALSE)
#define Com_HasTxSigGrpMask()                                         (TRUE != FALSE)
#define Com_HasTxSigGrpOnChangeMask()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigGrpOnChangeMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define Com_HasTxSigInfo()                                            (TRUE != FALSE)
#define Com_HasApplTypeOfTxSigInfo()                                  (TRUE != FALSE)
#define Com_HasBitLengthOfTxSigInfo()                                 (TRUE != FALSE)
#define Com_HasBitPositionOfTxSigInfo()                               (TRUE != FALSE)
#define Com_HasBusAccOfTxSigInfo()                                    (TRUE != FALSE)
#define Com_HasByteLengthOfTxSigInfo()                                (TRUE != FALSE)
#define Com_HasBytePositionOfTxSigInfo()                              (TRUE != FALSE)
#define Com_HasFilterInfoIdxOfTxSigInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasFilterInfoUsedOfTxSigInfo()                            (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasFilterInitValueIdxOfTxSigInfo()                        (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueIdx' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasFilterInitValueUsedOfTxSigInfo()                       (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueUsed' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasInvValueIdxOfTxSigInfo()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasInvValueUsedOfTxSigInfo()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasInvalidHndOfTxSigInfo()                                (TRUE != FALSE)
#define Com_HasOnChangeIdxOfTxSigInfo()                               (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.OnChangeIdx' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasOnChangeUsedOfTxSigInfo()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.OnChangeUsed' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasPduIdOfTxSigInfo()                                     (TRUE != FALSE)
#define Com_HasTriggeredOfTxSigInfo()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.Triggered' Reason: 'the value of Com_TriggeredOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define Com_HasTxFilterInitStateIdxOfTxSigInfo()                      (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxFilterInitStateUsedOfTxSigInfo()                     (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxSigGrpInfoIdxOfTxSigInfo()                           (TRUE != FALSE)
#define Com_HasTxSigGrpInfoUsedOfTxSigInfo()                          (TRUE != FALSE)
#define Com_HasTxTOutInfoIdxOfTxSigInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasTxTOutInfoUsedOfTxSigInfo()                            (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasUbIdxOfTxSigInfo()                                     (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.UbIdx' Reason: 'the value of Com_UbIdxOfTxSigInfo is always 'COM_NO_UBIDXOFTXSIGINFO' due to this, the array is deactivated.' */
#define Com_HasUbMaskIdxOfTxSigInfo()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasUbMaskUsedOfTxSigInfo()                                (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE-COMPILE'.' */
#define Com_HasWithoutRepOfTxSigInfo()                                (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfo.WithoutRep' Reason: 'the value of Com_WithoutRepOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define Com_HasTxSigInfoFilterInitValueInd()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfoFilterInitValueInd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxSigInfoInvValueInd()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxSigInfoInvValueInd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxTOutCnt()                                            (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTOutCnt' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxTOutInfo()                                           (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTOutInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Com_HasCbkTxTOutFuncPtrEndIdxOfTxTOutInfo()                   (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrEndIdx' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasCbkTxTOutFuncPtrStartIdxOfTxTOutInfo()                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrStartIdx' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasCbkTxTOutFuncPtrUsedOfTxTOutInfo()                     (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrUsed' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasFactorOfTxTOutInfo()                                   (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTOutInfo.Factor' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasNoneModeOfTxTOutInfo()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTOutInfo.NoneMode' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxPduInfoIdxOfTxTOutInfo()                             (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTOutInfo.TxPduInfoIdx' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxPduInfoUsedOfTxTOutInfo()                            (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTOutInfo.TxPduInfoUsed' Reason: 'the structure element is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE-COMPILE' */
#define Com_HasTxTmpTpPduLength()                                     (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTmpTpPduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxTpConnectionState()                                  (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxTpInfo()                                             (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasBufferSizeOfTxTpInfo()                                 (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxPduBufferEndIdxOfTxTpInfo()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpInfo.TxPduBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxPduBufferLengthOfTxTpInfo()                          (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpInfo.TxPduBufferLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxPduBufferStartIdxOfTxTpInfo()                        (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpInfo.TxPduBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxPduBufferUsedOfTxTpInfo()                            (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpInfo.TxPduBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxSigInfoDynSigIdxOfTxTpInfo()                         (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxSigInfoDynSigUsedOfTxTpInfo()                        (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxTpSduLength()                                        (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasTxTpWrittenBytesCounter()                              (FALSE != FALSE)  /**< Deactivateable: 'Com_TxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define Com_HasWaitingForConfirmation()                               (TRUE != FALSE)
#define Com_HasPCConfig()                                             (TRUE != FALSE)
#define Com_HasAllSigCntOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasAllSigGrpCntOfPCConfig()                               (TRUE != FALSE)
#define Com_HasCbkRxAckFuncPtrOfPCConfig()                            (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrOfPCConfig()                           (TRUE != FALSE)
#define Com_HasConfigIdOfPCConfig()                                   (TRUE != FALSE)
#define Com_HasConstValueXInt16OfPCConfig()                           (TRUE != FALSE)
#define Com_HasConstValueXInt8OfPCConfig()                            (TRUE != FALSE)
#define Com_HasCurrentTxModeOfPCConfig()                              (TRUE != FALSE)
#define Com_HasCycleTimeCntOfPCConfig()                               (TRUE != FALSE)
#define Com_HasCyclicSendRequestOfPCConfig()                          (TRUE != FALSE)
#define Com_HasFinalMagicNumberOfPCConfig()                           (FALSE != FALSE)  /**< Deactivateable: 'Com_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Com_HasHandleRxPduDeferredOfPCConfig()                        (TRUE != FALSE)
#define Com_HasHandleTxPduDeferredOfPCConfig()                        (TRUE != FALSE)
#define Com_HasInitDataHashCodeOfPCConfig()                           (FALSE != FALSE)  /**< Deactivateable: 'Com_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Com_HasInitializedOfPCConfig()                                (TRUE != FALSE)
#define Com_HasPduGrpCntOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasPduGrpVectorOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRepCntOfPCConfig()                                     (TRUE != FALSE)
#define Com_HasRepCycleCntOfPCConfig()                                (TRUE != FALSE)
#define Com_HasRxAccessInfoIndOfPCConfig()                            (TRUE != FALSE)
#define Com_HasRxAccessInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxAccessInfoReplaceSigIndOfPCConfig()                  (TRUE != FALSE)
#define Com_HasRxDefPduBufferOfPCConfig()                             (TRUE != FALSE)
#define Com_HasRxGrpSigInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxPduDmStateOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxPduGrpActiveOfPCConfig()                             (TRUE != FALSE)
#define Com_HasRxPduGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxPduInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasRxShdBufferXInt16OfPCConfig()                          (TRUE != FALSE)
#define Com_HasRxShdBufferXInt8OfPCConfig()                           (TRUE != FALSE)
#define Com_HasRxSigBufferXInt16OfPCConfig()                          (TRUE != FALSE)
#define Com_HasRxSigBufferXInt8OfPCConfig()                           (TRUE != FALSE)
#define Com_HasRxSigGrpInfoIndOfPCConfig()                            (TRUE != FALSE)
#define Com_HasRxSigGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxSigInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasRxTOutCntOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasRxTOutInfoIndOfPCConfig()                              (TRUE != FALSE)
#define Com_HasRxTOutInfoOfPCConfig()                                 (TRUE != FALSE)
#define Com_HasSigGrpEventFlagOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfCbkRxAckFuncPtrOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtrOfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfConstValueXInt16OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfConstValueXInt8OfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxModeOfPCConfig()                        (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCntOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequestOfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferredOfPCConfig()                  (TRUE != FALSE)
#define Com_HasSizeOfHandleTxPduDeferredOfPCConfig()                  (TRUE != FALSE)
#define Com_HasSizeOfPduGrpVectorOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRepCntOfPCConfig()                               (TRUE != FALSE)
#define Com_HasSizeOfRepCycleCntOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoIndOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoReplaceSigIndOfPCConfig()            (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBufferOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfRxGrpSigInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxPduDmStateOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActiveOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfRxShdBufferXInt16OfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfRxShdBufferXInt8OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferXInt16OfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferXInt8OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfRxSigGrpInfoIndOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfRxSigGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfRxTOutCntOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoIndOfPCConfig()                        (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoOfPCConfig()                           (TRUE != FALSE)
#define Com_HasSizeOfSigGrpEventFlagOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfTmpRxBufferOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfTmpRxShdBufferXInt16OfPCConfig()                 (TRUE != FALSE)
#define Com_HasSizeOfTmpRxShdBufferXInt8OfPCConfig()                  (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequestOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfoOfPCConfig()                           (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrueOfPCConfig()                           (TRUE != FALSE)
#define Com_HasSizeOfTxPduBufferOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActiveOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValueOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfTxSduLengthOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfTxShdBufferOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfoIndOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpMaskOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfWaitingForConfirmationOfPCConfig()               (TRUE != FALSE)
#define Com_HasTmpRxBufferOfPCConfig()                                (TRUE != FALSE)
#define Com_HasTmpRxShdBufferXInt16OfPCConfig()                       (TRUE != FALSE)
#define Com_HasTmpRxShdBufferXInt8OfPCConfig()                        (TRUE != FALSE)
#define Com_HasTransmitRequestOfPCConfig()                            (TRUE != FALSE)
#define Com_HasTxModeInfoOfPCConfig()                                 (TRUE != FALSE)
#define Com_HasTxModeTrueOfPCConfig()                                 (TRUE != FALSE)
#define Com_HasTxPduBufferOfPCConfig()                                (TRUE != FALSE)
#define Com_HasTxPduGrpActiveOfPCConfig()                             (TRUE != FALSE)
#define Com_HasTxPduGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasTxPduInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasTxPduInitValueOfPCConfig()                             (TRUE != FALSE)
#define Com_HasTxSduLengthOfPCConfig()                                (TRUE != FALSE)
#define Com_HasTxShdBufferOfPCConfig()                                (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndOfPCConfig()                            (TRUE != FALSE)
#define Com_HasTxSigGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasTxSigGrpMaskOfPCConfig()                               (TRUE != FALSE)
#define Com_HasTxSigInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasWaitingForConfirmationOfPCConfig()                     (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  PCIncrementDataMacros  Increment Data Macros (PRE-COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Com_IncCycleTimeCnt(Index)                                    Com_GetCycleTimeCnt(Index)++
#define Com_IncDelayTimeCnt(Index)                                    
#define Com_IncHandleRxPduDeferred(Index)                             Com_GetHandleRxPduDeferred(Index)++
#define Com_IncRepCnt(Index)                                          Com_GetRepCnt(Index)++
#define Com_IncRepCycleCnt(Index)                                     Com_GetRepCycleCnt(Index)++
#define Com_IncRxDefPduBuffer(Index)                                  Com_GetRxDefPduBuffer(Index)++
#define Com_IncRxDynSignalLength(Index)                               
#define Com_IncRxDynSignalTmpLengthForSignalGroups(Index)             
#define Com_IncRxShdBufferXInt16(Index)                               Com_GetRxShdBufferXInt16(Index)++
#define Com_IncRxShdBufferXInt32(Index)                               
#define Com_IncRxShdBufferXInt8(Index)                                Com_GetRxShdBufferXInt8(Index)++
#define Com_IncRxSigBufferXInt16(Index)                               Com_GetRxSigBufferXInt16(Index)++
#define Com_IncRxSigBufferXInt32(Index)                               
#define Com_IncRxSigBufferXInt8(Index)                                Com_GetRxSigBufferXInt8(Index)++
#define Com_IncRxTOutCnt(Index)                                       Com_GetRxTOutCnt(Index)++
#define Com_IncRxTpBuffer(Index)                                      
#define Com_IncRxTpSduLength(Index)                                   
#define Com_IncRxTpWrittenBytesCounter(Index)                         
#define Com_IncSigGrpEventFlag(Index)                                 Com_GetSigGrpEventFlag(Index)++
#define Com_IncTmpRxBuffer(Index)                                     Com_GetTmpRxBuffer(Index)++
#define Com_IncTmpRxShdBufferXInt16(Index)                            Com_GetTmpRxShdBufferXInt16(Index)++
#define Com_IncTmpRxShdBufferXInt32(Index)                            
#define Com_IncTmpRxShdBufferXInt8(Index)                             Com_GetTmpRxShdBufferXInt8(Index)++
#define Com_IncTxDynSignalLength(Index)                               
#define Com_IncTxFilterOldValueXInt16(Index)                          
#define Com_IncTxFilterOldValueXInt32(Index)                          
#define Com_IncTxFilterOldValueXInt8(Index)                           
#define Com_IncTxPduBuffer(Index)                                     Com_GetTxPduBuffer(Index)++
#define Com_IncTxSduLength(Index)                                     Com_GetTxSduLength(Index)++
#define Com_IncTxShdBuffer(Index)                                     Com_GetTxShdBuffer(Index)++
#define Com_IncTxTOutCnt(Index)                                       
#define Com_IncTxTmpTpPduLength(Index)                                
#define Com_IncTxTpSduLength(Index)                                   
#define Com_IncTxTpWrittenBytesCounter(Index)                         
/** 
  \}
*/ 

/** 
  \defgroup  PCDecrementDataMacros  Decrement Data Macros (PRE-COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Com_DecCycleTimeCnt(Index)                                    Com_GetCycleTimeCnt(Index)--
#define Com_DecDelayTimeCnt(Index)                                    
#define Com_DecHandleRxPduDeferred(Index)                             Com_GetHandleRxPduDeferred(Index)--
#define Com_DecRepCnt(Index)                                          Com_GetRepCnt(Index)--
#define Com_DecRepCycleCnt(Index)                                     Com_GetRepCycleCnt(Index)--
#define Com_DecRxDefPduBuffer(Index)                                  Com_GetRxDefPduBuffer(Index)--
#define Com_DecRxDynSignalLength(Index)                               
#define Com_DecRxDynSignalTmpLengthForSignalGroups(Index)             
#define Com_DecRxShdBufferXInt16(Index)                               Com_GetRxShdBufferXInt16(Index)--
#define Com_DecRxShdBufferXInt32(Index)                               
#define Com_DecRxShdBufferXInt8(Index)                                Com_GetRxShdBufferXInt8(Index)--
#define Com_DecRxSigBufferXInt16(Index)                               Com_GetRxSigBufferXInt16(Index)--
#define Com_DecRxSigBufferXInt32(Index)                               
#define Com_DecRxSigBufferXInt8(Index)                                Com_GetRxSigBufferXInt8(Index)--
#define Com_DecRxTOutCnt(Index)                                       Com_GetRxTOutCnt(Index)--
#define Com_DecRxTpBuffer(Index)                                      
#define Com_DecRxTpSduLength(Index)                                   
#define Com_DecRxTpWrittenBytesCounter(Index)                         
#define Com_DecSigGrpEventFlag(Index)                                 Com_GetSigGrpEventFlag(Index)--
#define Com_DecTmpRxBuffer(Index)                                     Com_GetTmpRxBuffer(Index)--
#define Com_DecTmpRxShdBufferXInt16(Index)                            Com_GetTmpRxShdBufferXInt16(Index)--
#define Com_DecTmpRxShdBufferXInt32(Index)                            
#define Com_DecTmpRxShdBufferXInt8(Index)                             Com_GetTmpRxShdBufferXInt8(Index)--
#define Com_DecTxDynSignalLength(Index)                               
#define Com_DecTxFilterOldValueXInt16(Index)                          
#define Com_DecTxFilterOldValueXInt32(Index)                          
#define Com_DecTxFilterOldValueXInt8(Index)                           
#define Com_DecTxPduBuffer(Index)                                     Com_GetTxPduBuffer(Index)--
#define Com_DecTxSduLength(Index)                                     Com_GetTxSduLength(Index)--
#define Com_DecTxShdBuffer(Index)                                     Com_GetTxShdBuffer(Index)--
#define Com_DecTxTOutCnt(Index)                                       
#define Com_DecTxTmpTpPduLength(Index)                                
#define Com_DecTxTpSduLength(Index)                                   
#define Com_DecTxTpWrittenBytesCounter(Index)                         
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE-COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE-COMPILE
  SECTION: GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**   \brief  type used in Com_AllSigCnt */
typedef uint8 Com_AllSigCntType;

/**   \brief  type used in Com_AllSigGrpCnt */
typedef uint8 Com_AllSigGrpCntType;

/**   \brief  type used in Com_ConfigId */
typedef uint8 Com_ConfigIdType;

/**   \brief  type used in Com_ConstValueXInt16 */
typedef uint16 Com_ConstValueXInt16Type;

/**   \brief  type used in Com_ConstValueXInt8 */
typedef uint8 Com_ConstValueXInt8Type;

/**   \brief  type used in Com_CurrentTxMode */
typedef boolean Com_CurrentTxModeType;

/**   \brief  type to be used as symbolic data element access to Com_CurrentTxMode */
typedef struct sCom_CurrentTxModeStructTag
{
  Com_CurrentTxModeType TxCluster_oCAN_3abd61be[1];
  Com_CurrentTxModeType TxEcuStatus_oCAN_3abd61be[1];
  Com_CurrentTxModeType TxFilteredSpeedSft_E2E_oCAN_3abd61be[1];
  Com_CurrentTxModeType Tx_FOTA_Response_oCAN_3abd61be[1];
} sCom_CurrentTxModeStructType;

/**   \brief  type used in Com_CurrentTxMode */
typedef union uCom_CurrentTxModeTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_CurrentTxModeType raw[4];
  sCom_CurrentTxModeStructType str;
} uCom_CurrentTxModeType;

/**   \brief  type used in Com_CycleTimeCnt */
typedef uint8 Com_CycleTimeCntType;

/**   \brief  type to be used as symbolic data element access to Com_CycleTimeCnt */
typedef struct sCom_CycleTimeCntStructTag
{
  Com_CycleTimeCntType TxCluster_oCAN_3abd61be[1];
  Com_CycleTimeCntType TxEcuStatus_oCAN_3abd61be[1];
  Com_CycleTimeCntType TxFilteredSpeedSft_E2E_oCAN_3abd61be[1];
  Com_CycleTimeCntType Tx_FOTA_Response_oCAN_3abd61be[1];
} sCom_CycleTimeCntStructType;

/**   \brief  type used in Com_CycleTimeCnt */
typedef union uCom_CycleTimeCntTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_CycleTimeCntType raw[4];
  sCom_CycleTimeCntStructType str;
} uCom_CycleTimeCntType;

/**   \brief  type used in Com_CyclicSendRequest */
typedef boolean Com_CyclicSendRequestType;

/**   \brief  type to be used as symbolic data element access to Com_CyclicSendRequest */
typedef struct sCom_CyclicSendRequestStructTag
{
  Com_CyclicSendRequestType TxCluster_oCAN_3abd61be[1];
  Com_CyclicSendRequestType TxEcuStatus_oCAN_3abd61be[1];
  Com_CyclicSendRequestType TxFilteredSpeedSft_E2E_oCAN_3abd61be[1];
  Com_CyclicSendRequestType Tx_FOTA_Response_oCAN_3abd61be[1];
} sCom_CyclicSendRequestStructType;

/**   \brief  type used in Com_CyclicSendRequest */
typedef union uCom_CyclicSendRequestTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_CyclicSendRequestType raw[4];
  sCom_CyclicSendRequestStructType str;
} uCom_CyclicSendRequestType;

/**   \brief  type used in Com_HandleRxPduDeferred */
typedef PduLengthType Com_HandleRxPduDeferredType;

/**   \brief  type to be used as symbolic data element access to Com_HandleRxPduDeferred */
typedef struct sCom_HandleRxPduDeferredStructTag
{
  Com_HandleRxPduDeferredType RxCarModes_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType RollingOdo_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType RxBody_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType RxButtons_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType RxDimming_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType RxECT_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType RxFilteredSpeedSft_E2E_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType RxFuel_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType RxSpeed_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType RxTacho_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType RxTurnInd_oCAN_3abd61be[1];
  Com_HandleRxPduDeferredType Rx_FOTA_Request_oCAN_3abd61be[1];
} sCom_HandleRxPduDeferredStructType;

/**   \brief  type used in Com_HandleRxPduDeferred */
typedef union uCom_HandleRxPduDeferredTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_HandleRxPduDeferredType raw[12];
  sCom_HandleRxPduDeferredStructType str;
} uCom_HandleRxPduDeferredType;

/**   \brief  type used in Com_HandleTxPduDeferred */
typedef boolean Com_HandleTxPduDeferredType;

/**   \brief  type used in Com_Initialized */
typedef boolean Com_InitializedType;

/**   \brief  type used in Com_PduGrpCnt */
typedef uint8 Com_PduGrpCntType;

/**   \brief  type used in Com_PduGrpVector */
typedef uint8 Com_PduGrpVectorType;

/**   \brief  type used in Com_RepCnt */
typedef uint16 Com_RepCntType;

/**   \brief  type to be used as symbolic data element access to Com_RepCnt */
typedef struct sCom_RepCntStructTag
{
  Com_RepCntType TxCluster_oCAN_3abd61be[1];
  Com_RepCntType TxEcuStatus_oCAN_3abd61be[1];
  Com_RepCntType TxFilteredSpeedSft_E2E_oCAN_3abd61be[1];
  Com_RepCntType Tx_FOTA_Response_oCAN_3abd61be[1];
} sCom_RepCntStructType;

/**   \brief  type used in Com_RepCnt */
typedef union uCom_RepCntTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_RepCntType raw[4];
  sCom_RepCntStructType str;
} uCom_RepCntType;

/**   \brief  type used in Com_RepCycleCnt */
typedef uint16 Com_RepCycleCntType;

/**   \brief  type to be used as symbolic data element access to Com_RepCycleCnt */
typedef struct sCom_RepCycleCntStructTag
{
  Com_RepCycleCntType TxCluster_oCAN_3abd61be[1];
  Com_RepCycleCntType TxEcuStatus_oCAN_3abd61be[1];
  Com_RepCycleCntType TxFilteredSpeedSft_E2E_oCAN_3abd61be[1];
  Com_RepCycleCntType Tx_FOTA_Response_oCAN_3abd61be[1];
} sCom_RepCycleCntStructType;

/**   \brief  type used in Com_RepCycleCnt */
typedef union uCom_RepCycleCntTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_RepCycleCntType raw[4];
  sCom_RepCycleCntStructType str;
} uCom_RepCycleCntType;

/**   \brief  type used in Com_ApplTypeOfRxAccessInfo */
typedef uint8 Com_ApplTypeOfRxAccessInfoType;

/**   \brief  type used in Com_BitLengthOfRxAccessInfo */
typedef uint8 Com_BitLengthOfRxAccessInfoType;

/**   \brief  type used in Com_BitPositionOfRxAccessInfo */
typedef uint8 Com_BitPositionOfRxAccessInfoType;

/**   \brief  type used in Com_BufferIdxOfRxAccessInfo */
typedef uint8 Com_BufferIdxOfRxAccessInfoType;

/**   \brief  type used in Com_BufferUsedOfRxAccessInfo */
typedef boolean Com_BufferUsedOfRxAccessInfoType;

/**   \brief  type used in Com_BusAccOfRxAccessInfo */
typedef uint8 Com_BusAccOfRxAccessInfoType;

/**   \brief  type used in Com_ByteLengthOfRxAccessInfo */
typedef uint8 Com_ByteLengthOfRxAccessInfoType;

/**   \brief  type used in Com_BytePositionOfRxAccessInfo */
typedef uint8 Com_BytePositionOfRxAccessInfoType;

/**   \brief  type used in Com_InitValueIdxOfRxAccessInfo */
typedef uint8 Com_InitValueIdxOfRxAccessInfoType;

/**   \brief  type used in Com_InitValueUsedOfRxAccessInfo */
typedef boolean Com_InitValueUsedOfRxAccessInfoType;

/**   \brief  type used in Com_InvalidHndOfRxAccessInfo */
typedef boolean Com_InvalidHndOfRxAccessInfoType;

/**   \brief  type used in Com_PduIdOfRxAccessInfo */
typedef uint8 Com_PduIdOfRxAccessInfoType;

/**   \brief  type used in Com_RxDataTimeoutSubstitutionValueIdxOfRxAccessInfo */
typedef uint8 Com_RxDataTimeoutSubstitutionValueIdxOfRxAccessInfoType;

/**   \brief  type used in Com_RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo */
typedef boolean Com_RxDataTimeoutSubstitutionValueUsedOfRxAccessInfoType;

/**   \brief  type used in Com_ShdBufferIdxOfRxAccessInfo */
typedef uint8 Com_ShdBufferIdxOfRxAccessInfoType;

/**   \brief  type used in Com_ShdBufferUsedOfRxAccessInfo */
typedef boolean Com_ShdBufferUsedOfRxAccessInfoType;

/**   \brief  type used in Com_RxAccessInfo */
typedef struct sCom_RxAccessInfoType
{
  Com_InitValueUsedOfRxAccessInfoType InitValueUsedOfRxAccessInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueXInt8,Com_ConstValueXInt16,Com_ConstValueXInt32 */
  Com_ApplTypeOfRxAccessInfoType ApplTypeOfRxAccessInfo;  /**< Application data type. ea:{E33B4863-9456-4cd2-84A1-94C89AF37A23} */
  Com_BitLengthOfRxAccessInfoType BitLengthOfRxAccessInfo;  /**< Bit length of the signal or group signal. ea:{646B1706-21D2-4b10-A5AC-A1113F297CD1} */
  Com_BitPositionOfRxAccessInfoType BitPositionOfRxAccessInfo;  /**< Bit position of the signal or group signal within the I-PDU. ea:{180FD2F9-6CDB-48e4-9557-FD4DFCABF773} */
  Com_BufferIdxOfRxAccessInfoType BufferIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_RxSigBufferXInt8,Com_RxSigBufferXInt16,Com_RxSigBufferXInt32 */
  Com_BusAccOfRxAccessInfoType BusAccOfRxAccessInfo;  /**< BUS access algorithm for signal or group signal packing / un-packing. ea:{63C9F63A-D1F5-474c-A7B2-BD00E0CE2BF0} */
  Com_ByteLengthOfRxAccessInfoType ByteLengthOfRxAccessInfo;  /**< Byte length of the signal or group signal. ea:{646B1706-21D2-4b10-A5AC-A1113F297CD1} */
  Com_BytePositionOfRxAccessInfoType BytePositionOfRxAccessInfo;  /**< Byte position of the signal or group signal within the I-PDU. ea:{180FD2F9-6CDB-48e4-9557-FD4DFCABF773} */
  Com_PduIdOfRxAccessInfoType PduIdOfRxAccessInfo;  /**< ID of the corresponding Tx I-PDU. ea:{A28B90E1-F27A-48c1-9EB3-0EAEB574C2D5} */
  Com_RxDataTimeoutSubstitutionValueIdxOfRxAccessInfoType RxDataTimeoutSubstitutionValueIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_ConstValueXInt8,Com_ConstValueXInt16,Com_ConstValueXInt32 */
  Com_ShdBufferIdxOfRxAccessInfoType ShdBufferIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_RxShdBufferXInt8,Com_RxShdBufferXInt16,Com_RxShdBufferXInt32 */
} Com_RxAccessInfoType;

/**   \brief  type used in Com_RxAccessInfoInd */
typedef uint8 Com_RxAccessInfoIndType;

/**   \brief  type used in Com_RxAccessInfoReplaceSigInd */
typedef uint8 Com_RxAccessInfoReplaceSigIndType;

/**   \brief  type used in Com_RxDefPduBuffer */
typedef uint8 Com_RxDefPduBufferType;

/**   \brief  type to be used as symbolic data element access to Com_RxDefPduBuffer */
typedef struct sCom_RxDefPduBufferStructTag
{
  Com_RxDefPduBufferType RxCarModes_oCAN_3abd61be[1];
  Com_RxDefPduBufferType RollingOdo_oCAN_3abd61be[2];
  Com_RxDefPduBufferType RxBody_oCAN_3abd61be[5];
  Com_RxDefPduBufferType RxButtons_oCAN_3abd61be[8];
  Com_RxDefPduBufferType RxDimming_oCAN_3abd61be[1];
  Com_RxDefPduBufferType RxECT_oCAN_3abd61be[3];
  Com_RxDefPduBufferType RxFilteredSpeedSft_E2E_oCAN_3abd61be[4];
  Com_RxDefPduBufferType RxFuel_oCAN_3abd61be[8];
  Com_RxDefPduBufferType RxSpeed_oCAN_3abd61be[2];
  Com_RxDefPduBufferType RxTacho_oCAN_3abd61be[2];
  Com_RxDefPduBufferType RxTurnInd_oCAN_3abd61be[1];
  Com_RxDefPduBufferType Rx_FOTA_Request_oCAN_3abd61be[8];
} sCom_RxDefPduBufferStructType;

/**   \brief  type used in Com_RxDefPduBuffer */
typedef union uCom_RxDefPduBufferTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_RxDefPduBufferType raw[45];
  sCom_RxDefPduBufferStructType str;
} uCom_RxDefPduBufferType;

/**   \brief  type used in Com_RxAccessInfoIdxOfRxGrpSigInfo */
typedef uint8 Com_RxAccessInfoIdxOfRxGrpSigInfoType;

/**   \brief  type used in Com_TmpBufferIdxOfRxGrpSigInfo */
typedef uint8 Com_TmpBufferIdxOfRxGrpSigInfoType;

/**   \brief  type used in Com_TmpBufferUsedOfRxGrpSigInfo */
typedef boolean Com_TmpBufferUsedOfRxGrpSigInfoType;

/**   \brief  type used in Com_RxGrpSigInfo */
typedef struct sCom_RxGrpSigInfoType
{
  Com_RxAccessInfoIdxOfRxGrpSigInfoType RxAccessInfoIdxOfRxGrpSigInfo;  /**< the index of the 1:1 relation pointing to Com_RxAccessInfo */
  Com_TmpBufferIdxOfRxGrpSigInfoType TmpBufferIdxOfRxGrpSigInfo;  /**< the index of the 0:1 relation pointing to Com_TmpRxShdBufferXInt8,Com_TmpRxShdBufferXInt16,Com_TmpRxShdBufferXInt32 */
} Com_RxGrpSigInfoType;

/**   \brief  type used in Com_RxPduDmState */
typedef uint8 Com_RxPduDmStateType;

/**   \brief  type used in Com_RxPduGrpActive */
typedef boolean Com_RxPduGrpActiveType;

/**   \brief  type used in Com_PduGrpVectorEndIdxOfRxPduGrpInfo */
typedef uint8 Com_PduGrpVectorEndIdxOfRxPduGrpInfoType;

/**   \brief  type used in Com_PduGrpVectorStartIdxOfRxPduGrpInfo */
typedef uint8 Com_PduGrpVectorStartIdxOfRxPduGrpInfoType;

/**   \brief  type used in Com_PduGrpVectorUsedOfRxPduGrpInfo */
typedef boolean Com_PduGrpVectorUsedOfRxPduGrpInfoType;

/**   \brief  type used in Com_RxPduGrpInfo */
typedef struct sCom_RxPduGrpInfoType
{
  Com_PduGrpVectorStartIdxOfRxPduGrpInfoType PduGrpVectorStartIdxOfRxPduGrpInfo;  /**< the start index of the 0:n relation pointing to Com_PduGrpVector */
} Com_RxPduGrpInfoType;

/**   \brief  type used in Com_HandleRxPduDeferredIdxOfRxPduInfo */
typedef uint8 Com_HandleRxPduDeferredIdxOfRxPduInfoType;

/**   \brief  type used in Com_HandleRxPduDeferredUsedOfRxPduInfo */
typedef boolean Com_HandleRxPduDeferredUsedOfRxPduInfoType;

/**   \brief  type used in Com_InvalidHndOfRxPduInfo */
typedef boolean Com_InvalidHndOfRxPduInfoType;

/**   \brief  type used in Com_RxAccessInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxAccessInfoIndEndIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxAccessInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxAccessInfoIndStartIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxAccessInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxAccessInfoIndUsedOfRxPduInfoType;

/**   \brief  type used in Com_RxDefPduBufferEndIdxOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferEndIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxDefPduBufferLengthOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferLengthOfRxPduInfoType;

/**   \brief  type used in Com_RxDefPduBufferStartIdxOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferStartIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxDefPduBufferUsedOfRxPduInfo */
typedef boolean Com_RxDefPduBufferUsedOfRxPduInfoType;

/**   \brief  type used in Com_RxSigGrpInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxSigGrpInfoIndEndIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxSigGrpInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxSigGrpInfoIndStartIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxSigGrpInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxSigGrpInfoIndUsedOfRxPduInfoType;

/**   \brief  type used in Com_RxSigInfoEndIdxOfRxPduInfo */
typedef uint8 Com_RxSigInfoEndIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxSigInfoStartIdxOfRxPduInfo */
typedef uint8 Com_RxSigInfoStartIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxSigInfoUsedOfRxPduInfo */
typedef boolean Com_RxSigInfoUsedOfRxPduInfoType;

/**   \brief  type used in Com_RxTOutInfoIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxTOutInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIndEndIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxTOutInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIndStartIdxOfRxPduInfoType;

/**   \brief  type used in Com_RxTOutInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxTOutInfoIndUsedOfRxPduInfoType;

/**   \brief  type used in Com_RxTOutInfoUsedOfRxPduInfo */
typedef boolean Com_RxTOutInfoUsedOfRxPduInfoType;

/**   \brief  type used in Com_RxPduInfo */
typedef struct sCom_RxPduInfoType
{
  Com_RxAccessInfoIndUsedOfRxPduInfoType RxAccessInfoIndUsedOfRxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd */
  Com_RxSigInfoUsedOfRxPduInfoType RxSigInfoUsedOfRxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo */
  Com_RxTOutInfoUsedOfRxPduInfoType RxTOutInfoUsedOfRxPduInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
  Com_RxAccessInfoIndEndIdxOfRxPduInfoType RxAccessInfoIndEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxAccessInfoInd */
  Com_RxAccessInfoIndStartIdxOfRxPduInfoType RxAccessInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxAccessInfoInd */
  Com_RxDefPduBufferEndIdxOfRxPduInfoType RxDefPduBufferEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxDefPduBuffer */
  Com_RxDefPduBufferStartIdxOfRxPduInfoType RxDefPduBufferStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxDefPduBuffer */
  Com_RxSigGrpInfoIndEndIdxOfRxPduInfoType RxSigGrpInfoIndEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxSigGrpInfoInd */
  Com_RxSigGrpInfoIndStartIdxOfRxPduInfoType RxSigGrpInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxSigGrpInfoInd */
  Com_RxSigInfoEndIdxOfRxPduInfoType RxSigInfoEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxSigInfo */
  Com_RxSigInfoStartIdxOfRxPduInfoType RxSigInfoStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxSigInfo */
  Com_RxTOutInfoIndEndIdxOfRxPduInfoType RxTOutInfoIndEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxTOutInfoInd */
  Com_RxTOutInfoIndStartIdxOfRxPduInfoType RxTOutInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxTOutInfoInd */
} Com_RxPduInfoType;

/**   \brief  type used in Com_RxShdBufferXInt16 */
typedef uint16 Com_RxShdBufferXInt16Type;

/**   \brief  type to be used as symbolic data element access to Com_RxShdBufferXInt16 */
typedef struct sCom_RxShdBufferXInt16StructTag
{
  Com_RxShdBufferXInt16Type E2E_RxFilteredSpeedSft_cb1e8587[1];
} sCom_RxShdBufferXInt16StructType;

/**   \brief  type used in Com_RxShdBufferXInt16 */
typedef union uCom_RxShdBufferXInt16Tag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_RxShdBufferXInt16Type raw[1];
  sCom_RxShdBufferXInt16StructType str;
} uCom_RxShdBufferXInt16Type;

/**   \brief  type used in Com_RxShdBufferXInt8 */
typedef uint8 Com_RxShdBufferXInt8Type;

/**   \brief  type to be used as symbolic data element access to Com_RxShdBufferXInt8 */
typedef struct sCom_RxShdBufferXInt8StructTag
{
  Com_RxShdBufferXInt8Type E2E_Rx_CRC_cb1e8587[1];
  Com_RxShdBufferXInt8Type E2E_Rx_SeqNumber_cb1e8587[1];
} sCom_RxShdBufferXInt8StructType;

/**   \brief  type used in Com_RxShdBufferXInt8 */
typedef union uCom_RxShdBufferXInt8Tag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_RxShdBufferXInt8Type raw[2];
  sCom_RxShdBufferXInt8StructType str;
} uCom_RxShdBufferXInt8Type;

/**   \brief  type used in Com_RxSigBufferXInt16 */
typedef uint16 Com_RxSigBufferXInt16Type;

/**   \brief  type to be used as symbolic data element access to Com_RxSigBufferXInt16 */
typedef struct sCom_RxSigBufferXInt16StructTag
{
  Com_RxSigBufferXInt16Type E2E_RxFilteredSpeedSft_cb1e8587[1];
  Com_RxSigBufferXInt16Type FUEL_LEVEL_CAN_24f27db7[1];
  Com_RxSigBufferXInt16Type NewRollingOdo_9d7d00df[1];
  Com_RxSigBufferXInt16Type SpeedRef_a9ab8ab7[1];
  Com_RxSigBufferXInt16Type TachoRef_3db35f78[1];
} sCom_RxSigBufferXInt16StructType;

/**   \brief  type used in Com_RxSigBufferXInt16 */
typedef union uCom_RxSigBufferXInt16Tag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_RxSigBufferXInt16Type raw[5];
  sCom_RxSigBufferXInt16StructType str;
} uCom_RxSigBufferXInt16Type;

/**   \brief  type used in Com_RxSigBufferXInt8 */
typedef uint8 Com_RxSigBufferXInt8Type;

/**   \brief  type to be used as symbolic data element access to Com_RxSigBufferXInt8 */
typedef struct sCom_RxSigBufferXInt8StructTag
{
  Com_RxSigBufferXInt8Type BrkLamp_B_Rq_610999c4[1];
  Com_RxSigBufferXInt8Type BtnCES_Down_c0440b7e[1];
  Com_RxSigBufferXInt8Type BtnCES_Left_c0440b7e[1];
  Com_RxSigBufferXInt8Type BtnCES_OK_c0440b7e[1];
  Com_RxSigBufferXInt8Type BtnCES_Right_c0440b7e[1];
  Com_RxSigBufferXInt8Type BtnCES_Up_c0440b7e[1];
  Com_RxSigBufferXInt8Type Button_1_c0440b7e[1];
  Com_RxSigBufferXInt8Type Button_2_c0440b7e[1];
  Com_RxSigBufferXInt8Type Button_3_c0440b7e[1];
  Com_RxSigBufferXInt8Type Button_4_c0440b7e[1];
  Com_RxSigBufferXInt8Type Button_5_c0440b7e[1];
  Com_RxSigBufferXInt8Type DimGeneral_0e65ef90[1];
  Com_RxSigBufferXInt8Type Disable_Neutral_Tow_610999c4[1];
  Com_RxSigBufferXInt8Type DownTranOfEngCoolantTempCAN_46dad878[1];
  Com_RxSigBufferXInt8Type DrStatDrv_B_Actl_610999c4[1];
  Com_RxSigBufferXInt8Type DrStatPsngr_B_Actl_610999c4[1];
  Com_RxSigBufferXInt8Type E2E_Rx_CRC_cb1e8587[1];
  Com_RxSigBufferXInt8Type E2E_Rx_SeqNumber_cb1e8587[1];
  Com_RxSigBufferXInt8Type Enable_Neutral_Tow_610999c4[1];
  Com_RxSigBufferXInt8Type EngineCoolantTempCAN_46dad878[1];
  Com_RxSigBufferXInt8Type FOTA_Request_e06f7a0b[8];
  Com_RxSigBufferXInt8Type KeyPos_70b9e74d[1];
  Com_RxSigBufferXInt8Type LeftTurnOn_365ba238[1];
  Com_RxSigBufferXInt8Type MyKey_Active_610999c4[1];
  Com_RxSigBufferXInt8Type RightTurnOn_365ba238[1];
  Com_RxSigBufferXInt8Type Slow_For_HDC_610999c4[1];
  Com_RxSigBufferXInt8Type Tire_Press_System_Stat_610999c4[1];
  Com_RxSigBufferXInt8Type WarningWaterTempCAN_46dad878[1];
} sCom_RxSigBufferXInt8StructType;

/**   \brief  type used in Com_RxSigBufferXInt8 */
typedef union uCom_RxSigBufferXInt8Tag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_RxSigBufferXInt8Type raw[35];
  sCom_RxSigBufferXInt8StructType str;
} uCom_RxSigBufferXInt8Type;

/**   \brief  type used in Com_CbkRxAckFuncPtrIdxOfRxSigGrpInfo */
typedef uint8 Com_CbkRxAckFuncPtrIdxOfRxSigGrpInfoType;

/**   \brief  type used in Com_CbkRxAckFuncPtrUsedOfRxSigGrpInfo */
typedef boolean Com_CbkRxAckFuncPtrUsedOfRxSigGrpInfoType;

/**   \brief  type used in Com_InvalidHndOfRxSigGrpInfo */
typedef boolean Com_InvalidHndOfRxSigGrpInfoType;

/**   \brief  type used in Com_RxGrpSigInfoEndIdxOfRxSigGrpInfo */
typedef uint8 Com_RxGrpSigInfoEndIdxOfRxSigGrpInfoType;

/**   \brief  type used in Com_RxGrpSigInfoStartIdxOfRxSigGrpInfo */
typedef uint8 Com_RxGrpSigInfoStartIdxOfRxSigGrpInfoType;

/**   \brief  type used in Com_RxPduInfoIdxOfRxSigGrpInfo */
typedef uint8 Com_RxPduInfoIdxOfRxSigGrpInfoType;

/**   \brief  type used in Com_RxPduInfoUsedOfRxSigGrpInfo */
typedef boolean Com_RxPduInfoUsedOfRxSigGrpInfoType;

/**   \brief  type used in Com_SignalProcessingOfRxSigGrpInfo */
typedef uint8 Com_SignalProcessingOfRxSigGrpInfoType;

/**   \brief  type used in Com_StartBytePositionOfRxSigGrpInfo */
typedef uint8 Com_StartBytePositionOfRxSigGrpInfoType;

/**   \brief  type used in Com_ValidDlcOfRxSigGrpInfo */
typedef uint8 Com_ValidDlcOfRxSigGrpInfoType;

/**   \brief  type used in Com_RxSigGrpInfo */
typedef struct sCom_RxSigGrpInfoType
{
  Com_RxPduInfoUsedOfRxSigGrpInfoType RxPduInfoUsedOfRxSigGrpInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxPduInfo */
} Com_RxSigGrpInfoType;

/**   \brief  type used in Com_RxSigGrpInfoInd */
typedef uint8 Com_RxSigGrpInfoIndType;

/**   \brief  type used in Com_CbkRxAckFuncPtrIdxOfRxSigInfo */
typedef uint8 Com_CbkRxAckFuncPtrIdxOfRxSigInfoType;

/**   \brief  type used in Com_CbkRxAckFuncPtrUsedOfRxSigInfo */
typedef boolean Com_CbkRxAckFuncPtrUsedOfRxSigInfoType;

/**   \brief  type used in Com_RxAccessInfoIdxOfRxSigInfo */
typedef uint8 Com_RxAccessInfoIdxOfRxSigInfoType;

/**   \brief  type used in Com_RxTOutInfoIdxOfRxSigInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxSigInfoType;

/**   \brief  type used in Com_RxTOutInfoUsedOfRxSigInfo */
typedef boolean Com_RxTOutInfoUsedOfRxSigInfoType;

/**   \brief  type used in Com_SignalProcessingOfRxSigInfo */
typedef uint8 Com_SignalProcessingOfRxSigInfoType;

/**   \brief  type used in Com_ValidDlcOfRxSigInfo */
typedef uint8 Com_ValidDlcOfRxSigInfoType;

/**   \brief  type used in Com_RxSigInfo */
typedef struct sCom_RxSigInfoType
{
  Com_CbkRxAckFuncPtrIdxOfRxSigInfoType CbkRxAckFuncPtrIdxOfRxSigInfo;  /**< the index of the 0:1 relation pointing to Com_CbkRxAckFuncPtr */
  Com_RxAccessInfoIdxOfRxSigInfoType RxAccessInfoIdxOfRxSigInfo;  /**< the index of the 1:1 relation pointing to Com_RxAccessInfo */
  Com_RxTOutInfoIdxOfRxSigInfoType RxTOutInfoIdxOfRxSigInfo;  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
  Com_SignalProcessingOfRxSigInfoType SignalProcessingOfRxSigInfo;
  Com_ValidDlcOfRxSigInfoType ValidDlcOfRxSigInfo;  /**< Minimum length of PDU required to completely receive the signal or signal group. ea:{0EAD864F-51F0-475a-A517-E3127ABAEBE4} */
} Com_RxSigInfoType;

/**   \brief  type used in Com_RxTOutCnt */
typedef uint16 Com_RxTOutCntType;

/**   \brief  type used in Com_CbkRxTOutFuncPtrEndIdxOfRxTOutInfo */
typedef uint8 Com_CbkRxTOutFuncPtrEndIdxOfRxTOutInfoType;

/**   \brief  type used in Com_CbkRxTOutFuncPtrStartIdxOfRxTOutInfo */
typedef uint8 Com_CbkRxTOutFuncPtrStartIdxOfRxTOutInfoType;

/**   \brief  type used in Com_CbkRxTOutFuncPtrUsedOfRxTOutInfo */
typedef boolean Com_CbkRxTOutFuncPtrUsedOfRxTOutInfoType;

/**   \brief  type used in Com_FactorOfRxTOutInfo */
typedef uint16 Com_FactorOfRxTOutInfoType;

/**   \brief  type used in Com_FirstFactorOfRxTOutInfo */
typedef uint8 Com_FirstFactorOfRxTOutInfoType;

/**   \brief  type used in Com_RxAccessInfoReplaceSigIndEndIdxOfRxTOutInfo */
typedef uint8 Com_RxAccessInfoReplaceSigIndEndIdxOfRxTOutInfoType;

/**   \brief  type used in Com_RxAccessInfoReplaceSigIndStartIdxOfRxTOutInfo */
typedef uint8 Com_RxAccessInfoReplaceSigIndStartIdxOfRxTOutInfoType;

/**   \brief  type used in Com_RxAccessInfoReplaceSigIndUsedOfRxTOutInfo */
typedef boolean Com_RxAccessInfoReplaceSigIndUsedOfRxTOutInfoType;

/**   \brief  type used in Com_RxPduInfoIdxOfRxTOutInfo */
typedef uint8 Com_RxPduInfoIdxOfRxTOutInfoType;

/**   \brief  type used in Com_RxTOutInfo */
typedef struct sCom_RxTOutInfoType
{
  Com_FactorOfRxTOutInfoType FactorOfRxTOutInfo;  /**< Deadline monitoring timeout factor. ea:{CC8F087B-1360-46de-A705-87379BACA0C9} */
  Com_CbkRxTOutFuncPtrEndIdxOfRxTOutInfoType CbkRxTOutFuncPtrEndIdxOfRxTOutInfo;  /**< the end index of the 0:n relation pointing to Com_CbkRxTOutFuncPtr */
  Com_CbkRxTOutFuncPtrStartIdxOfRxTOutInfoType CbkRxTOutFuncPtrStartIdxOfRxTOutInfo;  /**< the start index of the 0:n relation pointing to Com_CbkRxTOutFuncPtr */
  Com_FirstFactorOfRxTOutInfoType FirstFactorOfRxTOutInfo;  /**< Timeout factor for first deadline monitoring. ea:{95FF3731-0256-40da-9D71-4A41C169AD45} */
  Com_RxAccessInfoReplaceSigIndEndIdxOfRxTOutInfoType RxAccessInfoReplaceSigIndEndIdxOfRxTOutInfo;  /**< the end index of the 0:n relation pointing to Com_RxAccessInfoReplaceSigInd */
  Com_RxAccessInfoReplaceSigIndStartIdxOfRxTOutInfoType RxAccessInfoReplaceSigIndStartIdxOfRxTOutInfo;  /**< the start index of the 0:n relation pointing to Com_RxAccessInfoReplaceSigInd */
  Com_RxPduInfoIdxOfRxTOutInfoType RxPduInfoIdxOfRxTOutInfo;  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
} Com_RxTOutInfoType;

/**   \brief  type used in Com_RxTOutInfoInd */
typedef uint8 Com_RxTOutInfoIndType;

/**   \brief  type used in Com_SigGrpEventFlag */
typedef uint8 Com_SigGrpEventFlagType;

/**   \brief  type used in Com_SizeOfCbkRxAckFuncPtr */
typedef uint8 Com_SizeOfCbkRxAckFuncPtrType;

/**   \brief  type used in Com_SizeOfCbkRxTOutFuncPtr */
typedef uint8 Com_SizeOfCbkRxTOutFuncPtrType;

/**   \brief  type used in Com_SizeOfConstValueXInt16 */
typedef uint8 Com_SizeOfConstValueXInt16Type;

/**   \brief  type used in Com_SizeOfConstValueXInt8 */
typedef uint8 Com_SizeOfConstValueXInt8Type;

/**   \brief  type used in Com_SizeOfCurrentTxMode */
typedef uint8 Com_SizeOfCurrentTxModeType;

/**   \brief  type used in Com_SizeOfCycleTimeCnt */
typedef uint8 Com_SizeOfCycleTimeCntType;

/**   \brief  type used in Com_SizeOfCyclicSendRequest */
typedef uint8 Com_SizeOfCyclicSendRequestType;

/**   \brief  type used in Com_SizeOfHandleRxPduDeferred */
typedef uint8 Com_SizeOfHandleRxPduDeferredType;

/**   \brief  type used in Com_SizeOfHandleTxPduDeferred */
typedef uint8 Com_SizeOfHandleTxPduDeferredType;

/**   \brief  type used in Com_SizeOfPduGrpVector */
typedef uint8 Com_SizeOfPduGrpVectorType;

/**   \brief  type used in Com_SizeOfRepCnt */
typedef uint8 Com_SizeOfRepCntType;

/**   \brief  type used in Com_SizeOfRepCycleCnt */
typedef uint8 Com_SizeOfRepCycleCntType;

/**   \brief  type used in Com_SizeOfRxAccessInfo */
typedef uint8 Com_SizeOfRxAccessInfoType;

/**   \brief  type used in Com_SizeOfRxAccessInfoInd */
typedef uint8 Com_SizeOfRxAccessInfoIndType;

/**   \brief  type used in Com_SizeOfRxAccessInfoReplaceSigInd */
typedef uint8 Com_SizeOfRxAccessInfoReplaceSigIndType;

/**   \brief  type used in Com_SizeOfRxDefPduBuffer */
typedef uint8 Com_SizeOfRxDefPduBufferType;

/**   \brief  type used in Com_SizeOfRxGrpSigInfo */
typedef uint8 Com_SizeOfRxGrpSigInfoType;

/**   \brief  type used in Com_SizeOfRxPduDmState */
typedef uint8 Com_SizeOfRxPduDmStateType;

/**   \brief  type used in Com_SizeOfRxPduGrpActive */
typedef uint8 Com_SizeOfRxPduGrpActiveType;

/**   \brief  type used in Com_SizeOfRxPduGrpInfo */
typedef uint8 Com_SizeOfRxPduGrpInfoType;

/**   \brief  type used in Com_SizeOfRxPduInfo */
typedef uint8 Com_SizeOfRxPduInfoType;

/**   \brief  type used in Com_SizeOfRxShdBufferXInt16 */
typedef uint8 Com_SizeOfRxShdBufferXInt16Type;

/**   \brief  type used in Com_SizeOfRxShdBufferXInt8 */
typedef uint8 Com_SizeOfRxShdBufferXInt8Type;

/**   \brief  type used in Com_SizeOfRxSigBufferXInt16 */
typedef uint8 Com_SizeOfRxSigBufferXInt16Type;

/**   \brief  type used in Com_SizeOfRxSigBufferXInt8 */
typedef uint8 Com_SizeOfRxSigBufferXInt8Type;

/**   \brief  type used in Com_SizeOfRxSigGrpInfo */
typedef uint8 Com_SizeOfRxSigGrpInfoType;

/**   \brief  type used in Com_SizeOfRxSigGrpInfoInd */
typedef uint8 Com_SizeOfRxSigGrpInfoIndType;

/**   \brief  type used in Com_SizeOfRxSigInfo */
typedef uint8 Com_SizeOfRxSigInfoType;

/**   \brief  type used in Com_SizeOfRxTOutCnt */
typedef uint8 Com_SizeOfRxTOutCntType;

/**   \brief  type used in Com_SizeOfRxTOutInfo */
typedef uint8 Com_SizeOfRxTOutInfoType;

/**   \brief  type used in Com_SizeOfRxTOutInfoInd */
typedef uint8 Com_SizeOfRxTOutInfoIndType;

/**   \brief  type used in Com_SizeOfSigGrpEventFlag */
typedef uint8 Com_SizeOfSigGrpEventFlagType;

/**   \brief  type used in Com_SizeOfTmpRxBuffer */
typedef uint8 Com_SizeOfTmpRxBufferType;

/**   \brief  type used in Com_SizeOfTmpRxShdBufferXInt16 */
typedef uint8 Com_SizeOfTmpRxShdBufferXInt16Type;

/**   \brief  type used in Com_SizeOfTmpRxShdBufferXInt8 */
typedef uint8 Com_SizeOfTmpRxShdBufferXInt8Type;

/**   \brief  type used in Com_SizeOfTransmitRequest */
typedef uint8 Com_SizeOfTransmitRequestType;

/**   \brief  type used in Com_SizeOfTxModeInfo */
typedef uint8 Com_SizeOfTxModeInfoType;

/**   \brief  type used in Com_SizeOfTxModeTrue */
typedef uint8 Com_SizeOfTxModeTrueType;

/**   \brief  type used in Com_SizeOfTxPduBuffer */
typedef uint8 Com_SizeOfTxPduBufferType;

/**   \brief  type used in Com_SizeOfTxPduGrpActive */
typedef uint8 Com_SizeOfTxPduGrpActiveType;

/**   \brief  type used in Com_SizeOfTxPduGrpInfo */
typedef uint8 Com_SizeOfTxPduGrpInfoType;

/**   \brief  type used in Com_SizeOfTxPduInfo */
typedef uint8 Com_SizeOfTxPduInfoType;

/**   \brief  type used in Com_SizeOfTxPduInitValue */
typedef uint8 Com_SizeOfTxPduInitValueType;

/**   \brief  type used in Com_SizeOfTxSduLength */
typedef uint8 Com_SizeOfTxSduLengthType;

/**   \brief  type used in Com_SizeOfTxShdBuffer */
typedef uint8 Com_SizeOfTxShdBufferType;

/**   \brief  type used in Com_SizeOfTxSigGrpInfo */
typedef uint8 Com_SizeOfTxSigGrpInfoType;

/**   \brief  type used in Com_SizeOfTxSigGrpInfoInd */
typedef uint8 Com_SizeOfTxSigGrpInfoIndType;

/**   \brief  type used in Com_SizeOfTxSigGrpMask */
typedef uint8 Com_SizeOfTxSigGrpMaskType;

/**   \brief  type used in Com_SizeOfTxSigInfo */
typedef uint8 Com_SizeOfTxSigInfoType;

/**   \brief  type used in Com_SizeOfWaitingForConfirmation */
typedef uint8 Com_SizeOfWaitingForConfirmationType;

/**   \brief  type used in Com_TmpRxBuffer */
typedef uint8 Com_TmpRxBufferType;

/**   \brief  type used in Com_TmpRxShdBufferXInt16 */
typedef uint16 Com_TmpRxShdBufferXInt16Type;

/**   \brief  type to be used as symbolic data element access to Com_TmpRxShdBufferXInt16 */
typedef struct sCom_TmpRxShdBufferXInt16StructTag
{
  Com_TmpRxShdBufferXInt16Type E2E_RxFilteredSpeedSft_cb1e8587[1];
} sCom_TmpRxShdBufferXInt16StructType;

/**   \brief  type used in Com_TmpRxShdBufferXInt16 */
typedef union uCom_TmpRxShdBufferXInt16Tag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_TmpRxShdBufferXInt16Type raw[1];
  sCom_TmpRxShdBufferXInt16StructType str;
} uCom_TmpRxShdBufferXInt16Type;

/**   \brief  type used in Com_TmpRxShdBufferXInt8 */
typedef uint8 Com_TmpRxShdBufferXInt8Type;

/**   \brief  type to be used as symbolic data element access to Com_TmpRxShdBufferXInt8 */
typedef struct sCom_TmpRxShdBufferXInt8StructTag
{
  Com_TmpRxShdBufferXInt8Type E2E_Rx_SeqNumber_cb1e8587[1];
  Com_TmpRxShdBufferXInt8Type E2E_Rx_CRC_cb1e8587[1];
} sCom_TmpRxShdBufferXInt8StructType;

/**   \brief  type used in Com_TmpRxShdBufferXInt8 */
typedef union uCom_TmpRxShdBufferXInt8Tag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_TmpRxShdBufferXInt8Type raw[2];
  sCom_TmpRxShdBufferXInt8StructType str;
} uCom_TmpRxShdBufferXInt8Type;

/**   \brief  type used in Com_TransmitRequest */
typedef boolean Com_TransmitRequestType;

/**   \brief  type to be used as symbolic data element access to Com_TransmitRequest */
typedef struct sCom_TransmitRequestStructTag
{
  Com_TransmitRequestType TxCluster_oCAN_3abd61be[1];
  Com_TransmitRequestType TxEcuStatus_oCAN_3abd61be[1];
  Com_TransmitRequestType TxFilteredSpeedSft_E2E_oCAN_3abd61be[1];
  Com_TransmitRequestType Tx_FOTA_Response_oCAN_3abd61be[1];
} sCom_TransmitRequestStructType;

/**   \brief  type used in Com_TransmitRequest */
typedef union uCom_TransmitRequestTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_TransmitRequestType raw[4];
  sCom_TransmitRequestStructType str;
} uCom_TransmitRequestType;

/**   \brief  type used in Com_InitModeOfTxModeInfo */
typedef boolean Com_InitModeOfTxModeInfoType;

/**   \brief  type used in Com_InvalidHndOfTxModeInfo */
typedef boolean Com_InvalidHndOfTxModeInfoType;

/**   \brief  type used in Com_TxModeTrueIdxOfTxModeInfo */
typedef uint8 Com_TxModeTrueIdxOfTxModeInfoType;

/**   \brief  type used in Com_TxModeTrueUsedOfTxModeInfo */
typedef boolean Com_TxModeTrueUsedOfTxModeInfoType;

/**   \brief  type used in Com_TxModeInfo */
typedef struct sCom_TxModeInfoType
{
  Com_TxModeTrueUsedOfTxModeInfoType TxModeTrueUsedOfTxModeInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxModeTrue */
  Com_TxModeTrueIdxOfTxModeInfoType TxModeTrueIdxOfTxModeInfo;  /**< the index of the 0:1 relation pointing to Com_TxModeTrue */
} Com_TxModeInfoType;

/**   \brief  type used in Com_PeriodicOfTxModeTrue */
typedef boolean Com_PeriodicOfTxModeTrueType;

/**   \brief  type used in Com_TimePeriodOfTxModeTrue */
typedef uint8 Com_TimePeriodOfTxModeTrueType;

/**   \brief  type used in Com_TxModeTrue */
typedef struct sCom_TxModeTrueType
{
  Com_PeriodicOfTxModeTrueType PeriodicOfTxModeTrue;  /**< TRUE if transmission mode contains a cyclic part. ea:{6382A245-2644-4c2b-9B74-7F3545CA1FFD} */
} Com_TxModeTrueType;

/**   \brief  type used in Com_TxPduBuffer */
typedef uint8 Com_TxPduBufferType;

/**   \brief  type to be used as symbolic data element access to Com_TxPduBuffer */
typedef struct sCom_TxPduBufferStructTag
{
  Com_TxPduBufferType TxCluster_oCAN_3abd61be[6];
  Com_TxPduBufferType TxEcuStatus_oCAN_3abd61be[8];
  Com_TxPduBufferType TxFilteredSpeedSft_E2E_oCAN_3abd61be[4];
  Com_TxPduBufferType Tx_FOTA_Response_oCAN_3abd61be[8];
} sCom_TxPduBufferStructType;

/**   \brief  type used in Com_TxPduBuffer */
typedef union uCom_TxPduBufferTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_TxPduBufferType raw[26];
  sCom_TxPduBufferStructType str;
} uCom_TxPduBufferType;

/**   \brief  type used in Com_TxPduGrpActive */
typedef boolean Com_TxPduGrpActiveType;

/**   \brief  type used in Com_PduGrpVectorEndIdxOfTxPduGrpInfo */
typedef uint8 Com_PduGrpVectorEndIdxOfTxPduGrpInfoType;

/**   \brief  type used in Com_PduGrpVectorStartIdxOfTxPduGrpInfo */
typedef uint8 Com_PduGrpVectorStartIdxOfTxPduGrpInfoType;

/**   \brief  type used in Com_PduGrpVectorUsedOfTxPduGrpInfo */
typedef boolean Com_PduGrpVectorUsedOfTxPduGrpInfoType;

/**   \brief  type used in Com_TxPduGrpInfo */
typedef struct sCom_TxPduGrpInfoType
{
  Com_PduGrpVectorStartIdxOfTxPduGrpInfoType PduGrpVectorStartIdxOfTxPduGrpInfo;  /**< the start index of the 0:n relation pointing to Com_PduGrpVector */
} Com_TxPduGrpInfoType;

/**   \brief  type used in Com_ExternalIdOfTxPduInfo */
typedef uint8 Com_ExternalIdOfTxPduInfoType;

/**   \brief  type used in Com_InvalidHndOfTxPduInfo */
typedef boolean Com_InvalidHndOfTxPduInfoType;

/**   \brief  type used in Com_MetaDataLengthOfTxPduInfo */
typedef uint8 Com_MetaDataLengthOfTxPduInfoType;

/**   \brief  type used in Com_PduWithMetaDataLengthOfTxPduInfo */
typedef uint8 Com_PduWithMetaDataLengthOfTxPduInfoType;

/**   \brief  type used in Com_TxPduBufferEndIdxOfTxPduInfo */
typedef uint8 Com_TxPduBufferEndIdxOfTxPduInfoType;

/**   \brief  type used in Com_TxPduBufferLengthOfTxPduInfo */
typedef uint8 Com_TxPduBufferLengthOfTxPduInfoType;

/**   \brief  type used in Com_TxPduBufferStartIdxOfTxPduInfo */
typedef uint8 Com_TxPduBufferStartIdxOfTxPduInfoType;

/**   \brief  type used in Com_TxPduBufferUsedOfTxPduInfo */
typedef boolean Com_TxPduBufferUsedOfTxPduInfoType;

/**   \brief  type used in Com_TxPduInitValueEndIdxOfTxPduInfo */
typedef uint8 Com_TxPduInitValueEndIdxOfTxPduInfoType;

/**   \brief  type used in Com_TxPduInitValueStartIdxOfTxPduInfo */
typedef uint8 Com_TxPduInitValueStartIdxOfTxPduInfoType;

/**   \brief  type used in Com_TxPduInitValueUsedOfTxPduInfo */
typedef boolean Com_TxPduInitValueUsedOfTxPduInfoType;

/**   \brief  type used in Com_TxSigGrpInfoIndEndIdxOfTxPduInfo */
typedef uint8 Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType;

/**   \brief  type used in Com_TxSigGrpInfoIndStartIdxOfTxPduInfo */
typedef uint8 Com_TxSigGrpInfoIndStartIdxOfTxPduInfoType;

/**   \brief  type used in Com_TxSigGrpInfoIndUsedOfTxPduInfo */
typedef boolean Com_TxSigGrpInfoIndUsedOfTxPduInfoType;

/**   \brief  type used in Com_TxPduInfo */
typedef struct sCom_TxPduInfoType
{
  Com_TxPduInitValueUsedOfTxPduInfoType TxPduInitValueUsedOfTxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue */
  Com_ExternalIdOfTxPduInfoType ExternalIdOfTxPduInfo;  /**< External ID used to call PduR_ComTransmit(). ea:{2181D34E-EC05-425f-A841-874F4C346BB5} */
  Com_MetaDataLengthOfTxPduInfoType MetaDataLengthOfTxPduInfo;  /**< Length of MetaData. */
  Com_TxPduBufferLengthOfTxPduInfoType TxPduBufferLengthOfTxPduInfo;  /**< the number of relations pointing to Com_TxPduBuffer */
  Com_TxPduInitValueEndIdxOfTxPduInfoType TxPduInitValueEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_TxPduInitValue */
  Com_TxPduInitValueStartIdxOfTxPduInfoType TxPduInitValueStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_TxPduInitValue */
  Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType TxSigGrpInfoIndEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_TxSigGrpInfoInd */
  Com_TxSigGrpInfoIndStartIdxOfTxPduInfoType TxSigGrpInfoIndStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_TxSigGrpInfoInd */
} Com_TxPduInfoType;

/**   \brief  type used in Com_TxPduInitValue */
typedef uint8 Com_TxPduInitValueType;

/**   \brief  type used in Com_TxSduLength */
typedef PduLengthType Com_TxSduLengthType;

/**   \brief  type used in Com_TxShdBuffer */
typedef uint8 Com_TxShdBufferType;

/**   \brief  type to be used as symbolic data element access to Com_TxShdBuffer */
typedef struct sCom_TxShdBufferStructTag
{
  Com_TxShdBufferType SG_TxFilteredSpeed_196f5849[4];
} sCom_TxShdBufferStructType;

/**   \brief  type used in Com_TxShdBuffer */
typedef union uCom_TxShdBufferTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  Com_TxShdBufferType raw[4];
  sCom_TxShdBufferStructType str;
} uCom_TxShdBufferType;

/**   \brief  type used in Com_InvalidHndOfTxSigGrpInfo */
typedef boolean Com_InvalidHndOfTxSigGrpInfoType;

/**   \brief  type used in Com_PduIdOfTxSigGrpInfo */
typedef uint8 Com_PduIdOfTxSigGrpInfoType;

/**   \brief  type used in Com_PduOffsetOfTxSigGrpInfo */
typedef uint8 Com_PduOffsetOfTxSigGrpInfoType;

/**   \brief  type used in Com_TransferPropertyOfTxSigGrpInfo */
typedef uint8 Com_TransferPropertyOfTxSigGrpInfoType;

/**   \brief  type used in Com_TxShdBufferEndIdxOfTxSigGrpInfo */
typedef uint8 Com_TxShdBufferEndIdxOfTxSigGrpInfoType;

/**   \brief  type used in Com_TxShdBufferLengthOfTxSigGrpInfo */
typedef uint8 Com_TxShdBufferLengthOfTxSigGrpInfoType;

/**   \brief  type used in Com_TxShdBufferStartIdxOfTxSigGrpInfo */
typedef uint8 Com_TxShdBufferStartIdxOfTxSigGrpInfoType;

/**   \brief  type used in Com_TxShdBufferUsedOfTxSigGrpInfo */
typedef boolean Com_TxShdBufferUsedOfTxSigGrpInfoType;

/**   \brief  type used in Com_TxSigGrpMaskEndIdxOfTxSigGrpInfo */
typedef uint8 Com_TxSigGrpMaskEndIdxOfTxSigGrpInfoType;

/**   \brief  type used in Com_TxSigGrpMaskLengthOfTxSigGrpInfo */
typedef uint8 Com_TxSigGrpMaskLengthOfTxSigGrpInfoType;

/**   \brief  type used in Com_TxSigGrpMaskStartIdxOfTxSigGrpInfo */
typedef uint8 Com_TxSigGrpMaskStartIdxOfTxSigGrpInfoType;

/**   \brief  type used in Com_TxSigGrpMaskUsedOfTxSigGrpInfo */
typedef boolean Com_TxSigGrpMaskUsedOfTxSigGrpInfoType;

/**   \brief  type used in Com_TxSigGrpInfo */
typedef struct sCom_TxSigGrpInfoType
{
  Com_TxSigGrpMaskUsedOfTxSigGrpInfoType TxSigGrpMaskUsedOfTxSigGrpInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpMask */
} Com_TxSigGrpInfoType;

/**   \brief  type used in Com_TxSigGrpInfoInd */
typedef uint8 Com_TxSigGrpInfoIndType;

/**   \brief  type used in Com_TxSigGrpMask */
typedef uint8 Com_TxSigGrpMaskType;

/**   \brief  type used in Com_ApplTypeOfTxSigInfo */
typedef uint8 Com_ApplTypeOfTxSigInfoType;

/**   \brief  type used in Com_BitLengthOfTxSigInfo */
typedef uint8 Com_BitLengthOfTxSigInfoType;

/**   \brief  type used in Com_BitPositionOfTxSigInfo */
typedef uint8 Com_BitPositionOfTxSigInfoType;

/**   \brief  type used in Com_BusAccOfTxSigInfo */
typedef uint8 Com_BusAccOfTxSigInfoType;

/**   \brief  type used in Com_ByteLengthOfTxSigInfo */
typedef uint8 Com_ByteLengthOfTxSigInfoType;

/**   \brief  type used in Com_BytePositionOfTxSigInfo */
typedef uint8 Com_BytePositionOfTxSigInfoType;

/**   \brief  type used in Com_InvalidHndOfTxSigInfo */
typedef boolean Com_InvalidHndOfTxSigInfoType;

/**   \brief  type used in Com_PduIdOfTxSigInfo */
typedef uint8 Com_PduIdOfTxSigInfoType;

/**   \brief  type used in Com_TxSigGrpInfoIdxOfTxSigInfo */
typedef uint8 Com_TxSigGrpInfoIdxOfTxSigInfoType;

/**   \brief  type used in Com_TxSigGrpInfoUsedOfTxSigInfo */
typedef boolean Com_TxSigGrpInfoUsedOfTxSigInfoType;

/**   \brief  type used in Com_TxSigInfo */
typedef struct sCom_TxSigInfoType
{
  Com_InvalidHndOfTxSigInfoType InvalidHndOfTxSigInfo;  /**< FALSE, if the handle of Com_TxSigInfo is valid and can be used in the embedded code for further processing in the embedded code. */
  Com_ApplTypeOfTxSigInfoType ApplTypeOfTxSigInfo;  /**< Application data type. ea:{E33B4863-9456-4cd2-84A1-94C89AF37A23} */
  Com_BitLengthOfTxSigInfoType BitLengthOfTxSigInfo;  /**< Bit length of the signal or group signal. ea:{646B1706-21D2-4b10-A5AC-A1113F297CD1} */
  Com_BitPositionOfTxSigInfoType BitPositionOfTxSigInfo;  /**< Bit position of the signal or group signal within the I-PDU. ea:{180FD2F9-6CDB-48e4-9557-FD4DFCABF773} */
  Com_BusAccOfTxSigInfoType BusAccOfTxSigInfo;  /**< BUS access algorithm for signal or group signal packing / un-packing. ea:{63C9F63A-D1F5-474c-A7B2-BD00E0CE2BF0} */
  Com_ByteLengthOfTxSigInfoType ByteLengthOfTxSigInfo;  /**< Byte length of the signal or group signal. ea:{646B1706-21D2-4b10-A5AC-A1113F297CD1} */
  Com_BytePositionOfTxSigInfoType BytePositionOfTxSigInfo;  /**< Byte position of the signal or group signal within the I-PDU. ea:{180FD2F9-6CDB-48e4-9557-FD4DFCABF773} */
  Com_PduIdOfTxSigInfoType PduIdOfTxSigInfo;  /**< ID of the corresponding Tx I-PDU. ea:{A28B90E1-F27A-48c1-9EB3-0EAEB574C2D5} */
  Com_TxSigGrpInfoIdxOfTxSigInfoType TxSigGrpInfoIdxOfTxSigInfo;  /**< the index of the 0:1 relation pointing to Com_TxSigGrpInfo */
} Com_TxSigInfoType;

/**   \brief  type used in Com_WaitingForConfirmation */
typedef boolean Com_WaitingForConfirmationType;

/**   \brief  type used in Com_PCConfig */
typedef struct sCom_PCConfigType
{
  uint8 neverUsed;  /**< dummy entry for the config structure in the configuration variant precompile which is not used by the code. */
} Com_PCConfigType;

typedef Com_PCConfigType Com_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE-COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_CbkRxAckFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_CbkRxAckFuncPtr
  \brief  Function pointer table containing configured Rx indication notifications for signals and signal groups. ea:{8E3F31A7-8382-49fd-AA7D-C95C96ECCDE0}
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(ComCbkRxAckType, COM_CONST) Com_CbkRxAckFuncPtr[8];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CbkRxTOutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_CbkRxTOutFuncPtr
  \brief  Function pointer table containing configured Rx timeout notifications for signals and signal groups. ea:{71D75BEB-245A-468b-96DB-A4F1362E927C}
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(ComCbkRxTOutType, COM_CONST) Com_CbkRxTOutFuncPtr[6];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueXInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueXInt16
  \brief  Optimized array of commonly used values like initial or invalid values. ea:{6C5B1979-F523-4386-8DE1-63F2D0DD2BB9} (SINT16, UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_ConstValueXInt16Type, COM_CONST) Com_ConstValueXInt16[2];
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueXInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueXInt8
  \brief  Optimized array of commonly used values like initial or invalid values. ea:{6C5B1979-F523-4386-8DE1-63F2D0DD2BB9} (BOOLEAN, SINT8, UINT8, UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_ConstValueXInt8Type, COM_CONST) Com_ConstValueXInt8[8];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_PduGrpVector
**********************************************************************************************************************/
/** 
  \var    Com_PduGrpVector
  \brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups. ea:{F15774B0-CB67-4b4c-A793-5F8E0CE5009D}
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_PduGrpVectorType, COM_CONST) Com_PduGrpVector[2];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU. ea:{29ED57B2-6571-49b1-98EC-829C637CABCD}
  \details
  Element                              Description
  InitValueUsed                        TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueXInt8,Com_ConstValueXInt16,Com_ConstValueXInt32
  ApplType                             Application data type. ea:{E33B4863-9456-4cd2-84A1-94C89AF37A23}
  BitLength                            Bit length of the signal or group signal. ea:{646B1706-21D2-4b10-A5AC-A1113F297CD1}
  BitPosition                          Bit position of the signal or group signal within the I-PDU. ea:{180FD2F9-6CDB-48e4-9557-FD4DFCABF773}
  BufferIdx                            the index of the 0:1 relation pointing to Com_RxSigBufferXInt8,Com_RxSigBufferXInt16,Com_RxSigBufferXInt32
  BusAcc                               BUS access algorithm for signal or group signal packing / un-packing. ea:{63C9F63A-D1F5-474c-A7B2-BD00E0CE2BF0}
  ByteLength                           Byte length of the signal or group signal. ea:{646B1706-21D2-4b10-A5AC-A1113F297CD1}
  BytePosition                         Byte position of the signal or group signal within the I-PDU. ea:{180FD2F9-6CDB-48e4-9557-FD4DFCABF773}
  PduId                                ID of the corresponding Tx I-PDU. ea:{A28B90E1-F27A-48c1-9EB3-0EAEB574C2D5}
  RxDataTimeoutSubstitutionValueIdx    the index of the 0:1 relation pointing to Com_ConstValueXInt8,Com_ConstValueXInt16,Com_ConstValueXInt32
  ShdBufferIdx                         the index of the 0:1 relation pointing to Com_RxShdBufferXInt8,Com_RxShdBufferXInt16,Com_RxShdBufferXInt32
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[33];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[33];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxGrpSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxGrpSigInfo
  \brief  Contains all relevant information for Rx group signals. ea:{A99B463E-4702-4d49-AEE6-B8D67214FC2B}
  \details
  Element            Description
  RxAccessInfoIdx    the index of the 1:1 relation pointing to Com_RxAccessInfo
  TmpBufferIdx       the index of the 0:1 relation pointing to Com_TmpRxShdBufferXInt8,Com_TmpRxShdBufferXInt16,Com_TmpRxShdBufferXInt32
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxGrpSigInfoType, COM_CONST) Com_RxGrpSigInfo[3];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs. ea:{7825DD17-3F46-4656-A671-B7DDB2E2E4B8}
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxPduGrpInfoType, COM_CONST) Com_RxPduGrpInfo[12];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs. ea:{537E999D-6EF1-4565-9F83-90E7A5DF8EDC}
  \details
  Element                    Description
  RxAccessInfoIndUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd
  RxSigInfoUsed              TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo
  RxTOutInfoUsed             TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo
  RxAccessInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxAccessInfoInd
  RxAccessInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxAccessInfoInd
  RxDefPduBufferEndIdx       the end index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxDefPduBufferStartIdx     the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigGrpInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxSigGrpInfoInd
  RxSigGrpInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxSigGrpInfoInd
  RxSigInfoEndIdx            the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx          the start index of the 0:n relation pointing to Com_RxSigInfo
  RxTOutInfoIndEndIdx        the end index of the 0:n relation pointing to Com_RxTOutInfoInd
  RxTOutInfoIndStartIdx      the start index of the 0:n relation pointing to Com_RxTOutInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[12];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigGrpInfo
  \brief  Contains all relevant information for Rx signal groups. ea:{EB90A750-5C52-4d3c-AB11-BE103A8DFC1A}
  \details
  Element          Description
  RxPduInfoUsed    TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxSigGrpInfoType, COM_CONST) Com_RxSigGrpInfo[1];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals. ea:{248B1277-41E1-478b-A849-89452020B239}
  \details
  Element               Description
  CbkRxAckFuncPtrIdx    the index of the 0:1 relation pointing to Com_CbkRxAckFuncPtr
  RxAccessInfoIdx       the index of the 1:1 relation pointing to Com_RxAccessInfo
  RxTOutInfoIdx         the index of the 0:1 relation pointing to Com_RxTOutInfo
  SignalProcessing  
  ValidDlc              Minimum length of PDU required to completely receive the signal or signal group. ea:{0EAD864F-51F0-475a-A517-E3127ABAEBE4}
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[30];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutInfo
  \brief  Contains all relevant information for signal based and I-PDu based Rx deadline monitoring. ea:{CBB01E2C-2285-47f5-8C5F-E4EBE1AE5188}
  \details
  Element                              Description
  Factor                               Deadline monitoring timeout factor. ea:{CC8F087B-1360-46de-A705-87379BACA0C9}
  CbkRxTOutFuncPtrEndIdx               the end index of the 0:n relation pointing to Com_CbkRxTOutFuncPtr
  CbkRxTOutFuncPtrStartIdx             the start index of the 0:n relation pointing to Com_CbkRxTOutFuncPtr
  FirstFactor                          Timeout factor for first deadline monitoring. ea:{95FF3731-0256-40da-9D71-4A41C169AD45}
  RxAccessInfoReplaceSigIndEndIdx      the end index of the 0:n relation pointing to Com_RxAccessInfoReplaceSigInd
  RxAccessInfoReplaceSigIndStartIdx    the start index of the 0:n relation pointing to Com_RxAccessInfoReplaceSigInd
  RxPduInfoIdx                         the index of the 1:1 relation pointing to Com_RxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_RxTOutInfoType, COM_CONST) Com_RxTOutInfo[4];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling. ea:{5DBE10A7-4B1A-4ed4-AE15-24760894B0A7}
  \details
  Element           Description
  TxModeTrueUsed    TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxModeTrue
  TxModeTrueIdx     the index of the 0:1 relation pointing to Com_TxModeTrue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[4];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true. ea:{0CA25DE1-88A9-4e8e-AC46-5CBCD1F5A3E7}
  \details
  Element     Description
  Periodic    TRUE if transmission mode contains a cyclic part. ea:{6382A245-2644-4c2b-9B74-7F3545CA1FFD}
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[2];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Tx I-PDUs. ea:{387CF947-39DD-4e71-B0C6-B0BC540B5AB7}
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxPduGrpInfoType, COM_CONST) Com_TxPduGrpInfo[4];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs. ea:{48FE80FD-B860-4935-B50A-711C1757F351}
  \details
  Element                    Description
  TxPduInitValueUsed         TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  ExternalId                 External ID used to call PduR_ComTransmit(). ea:{2181D34E-EC05-425f-A841-874F4C346BB5}
  MetaDataLength             Length of MetaData.
  TxPduBufferLength          the number of relations pointing to Com_TxPduBuffer
  TxPduInitValueEndIdx       the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx     the start index of the 0:n relation pointing to Com_TxPduInitValue
  TxSigGrpInfoIndEndIdx      the end index of the 0:n relation pointing to Com_TxSigGrpInfoInd
  TxSigGrpInfoIndStartIdx    the start index of the 0:n relation pointing to Com_TxSigGrpInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[4];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization. ea:{F6DC1DA1-E33F-4690-8F08-3B5B786D0FFB}
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[26];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpInfo
  \brief  Contains all relevant information for Tx Signal Groups. ea:{5DE7D0E7-957C-4cab-AE25-7766C0768C05}
  \details
  Element             Description
  TxSigGrpMaskUsed    TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpMask
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxSigGrpInfoType, COM_CONST) Com_TxSigGrpInfo[1];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpMask
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpMask
  \brief  Signal group mask needed to copy interlaced signal groups to the Tx PDU buffer. ea:{338836F2-4ABA-4646-BFB5-E0D1273300FA}
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxSigGrpMaskType, COM_CONST) Com_TxSigGrpMask[4];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals. ea:{CC99987D-84AB-4c41-BADD-7B2C86FBE930}
  \details
  Element            Description
  InvalidHnd         FALSE, if the handle of Com_TxSigInfo is valid and can be used in the embedded code for further processing in the embedded code.
  ApplType           Application data type. ea:{E33B4863-9456-4cd2-84A1-94C89AF37A23}
  BitLength          Bit length of the signal or group signal. ea:{646B1706-21D2-4b10-A5AC-A1113F297CD1}
  BitPosition        Bit position of the signal or group signal within the I-PDU. ea:{180FD2F9-6CDB-48e4-9557-FD4DFCABF773}
  BusAcc             BUS access algorithm for signal or group signal packing / un-packing. ea:{63C9F63A-D1F5-474c-A7B2-BD00E0CE2BF0}
  ByteLength         Byte length of the signal or group signal. ea:{646B1706-21D2-4b10-A5AC-A1113F297CD1}
  BytePosition       Byte position of the signal or group signal within the I-PDU. ea:{180FD2F9-6CDB-48e4-9557-FD4DFCABF773}
  PduId              ID of the corresponding Tx I-PDU. ea:{A28B90E1-F27A-48c1-9EB3-0EAEB574C2D5}
  TxSigGrpInfoIdx    the index of the 0:1 relation pointing to Com_TxSigGrpInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[15];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs. ea:{ED5079EC-06ED-442b-A19B-216FAD6A321E}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission. ea:{3ADDB39D-576E-4748-899C-D5603B5E20E0}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU. ea:{DE677C5B-3122-43da-8688-6A05FE89F69D}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx(). ea:{0AD1CC67-C659-4d36-834A-23D7490767D2}
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_HandleRxPduDeferredType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleTxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleTxPduDeferred
  \brief  Flag array used for deferred Tx confirmation handling. ea:{56043229-CA4B-4603-A242-CA55DAE9978B}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_HandleTxPduDeferredType, COM_VAR_NOINIT) Com_HandleTxPduDeferred[4];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized;
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCnt
  \brief  Current repetition counter value for replication of transmission requests. ea:{5E082CB5-0604-45fc-A6AC-149C28E5C4CB}
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_RepCntType, COM_VAR_NOINIT) Com_RepCnt;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCycleCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCycleCnt
  \brief  Current counter value of repetition period for replication of transmission requests. ea:{C6AF618A-754E-46e3-9D7B-CDECCC6484BD}
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_RepCycleCntType, COM_VAR_NOINIT) Com_RepCycleCnt;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing. ea:{F49B9896-FB53-417d-997D-9D6FAD9EE7C6}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_RxDefPduBufferType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduDmState
**********************************************************************************************************************/
/** 
  \var    Com_RxPduDmState
  \brief  Rx I-PDU based deadline monitoring state (started/stopped) of the corresponding I-PDU-Group. ea:{7D75E2D2-1F0E-416a-9719-0A20987AFF39}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxPduDmStateType, COM_VAR_NOINIT) Com_RxPduDmState[4];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group. ea:{1FEA071E-983D-4471-A91C-FB71A7760C8C}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[12];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxShdBufferXInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxShdBufferXInt16
  \brief  Rx Group Signal Shadow Buffer. ea:{7F3A093E-5B6E-4016-96B6-7728AE2E232E} (SINT16, UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_RxShdBufferXInt16Type, COM_VAR_NOINIT) Com_RxShdBufferXInt16;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxShdBufferXInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxShdBufferXInt8
  \brief  Rx Group Signal Shadow Buffer. ea:{7F3A093E-5B6E-4016-96B6-7728AE2E232E} (BOOLEAN, SINT8, UINT8, UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_RxShdBufferXInt8Type, COM_VAR_NOINIT) Com_RxShdBufferXInt8;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferXInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferXInt16
  \brief  Rx Signal and Group Signal Buffer. ea:{426E0C09-86A4-4b44-857F-632E79F22E59} (SINT16, UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_RxSigBufferXInt16Type, COM_VAR_NOINIT) Com_RxSigBufferXInt16;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferXInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferXInt8
  \brief  Rx Signal and Group Signal Buffer. ea:{426E0C09-86A4-4b44-857F-632E79F22E59} (BOOLEAN, SINT8, UINT8, UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_RxSigBufferXInt8Type, COM_VAR_NOINIT) Com_RxSigBufferXInt8;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutCnt
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutCnt
  \brief  This array holds timeout counters for all Rx timeout objects. ea:{A744AB40-8016-4abd-9352-3755A735D2E9}
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_RxTOutCntType, COM_VAR_NOINIT) Com_RxTOutCnt[4];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_SigGrpEventFlag
**********************************************************************************************************************/
/** 
  \var    Com_SigGrpEventFlag
  \brief  Flag is set if a group signal write access caused a triggered event. ea:{5528FC50-EE01-4b1e-A3AA-E08381BF9C11}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_SigGrpEventFlagType, COM_VAR_NOINIT) Com_SigGrpEventFlag[1];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxBuffer
  \brief  Temporary buffer for Rx UINT8_N and UINT8_DYN signals. ea:{B3595D66-1B9F-4fef-8E80-5A7425703959}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TmpRxBufferType, COM_VAR_NOINIT) Com_TmpRxBuffer[8];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferXInt16
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferXInt16
  \brief  Temporary Rx Group Signal Shadow Buffer. ea:{4293D8FE-23A7-4333-AEDF-520B983F762F} (SINT16, UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_TmpRxShdBufferXInt16Type, COM_VAR_NOINIT) Com_TmpRxShdBufferXInt16;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferXInt8
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferXInt8
  \brief  Temporary Rx Group Signal Shadow Buffer. ea:{4293D8FE-23A7-4333-AEDF-520B983F762F} (BOOLEAN, SINT8, UINT8, UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_TmpRxShdBufferXInt8Type, COM_VAR_NOINIT) Com_TmpRxShdBufferXInt8;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission. ea:{6073E4F7-39EB-4415-9119-5C3187E718D8}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxPduBuffer
  \brief  Tx I-PDU Buffer. ea:{8FBCB61E-4F9A-4eed-BBAC-8F3EA5D20D44}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_TxPduBufferType, COM_VAR_NOINIT) Com_TxPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group. ea:{6C333DA7-FB73-42c4-86EA-1F8FC5CD1D2C}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[4];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length. ea:{7A1C61AC-8FAE-47ea-8E93-9DA53000332A}
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[4];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxShdBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxShdBuffer
  \brief  Shadow buffer used for consistent signal group transmission. ea:{E54CE654-FEEA-4509-BBFD-D50B1C9909ED}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(uCom_TxShdBufferType, COM_VAR_NOINIT) Com_TxShdBuffer;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_WaitingForConfirmation
**********************************************************************************************************************/
/** 
  \var    Com_WaitingForConfirmation
  \brief  Flag array used for Tx error notification handling. ea:{D441973A-62D6-42b6-877F-1096F9A5C295}
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Com_WaitingForConfirmationType, COM_VAR_NOINIT) Com_WaitingForConfirmation[4];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_19.1 */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE-COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* User Config File Start */

/* User Config File End */


#endif  /* COM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg.h
**********************************************************************************************************************/

