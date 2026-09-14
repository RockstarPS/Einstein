/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 - 2016 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples respectively
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, the liability of Vector Informatik
 *                shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defines for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik GmbH
 *  Heike Honert                  Ht            Vector Informatik GmbH
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component specific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all OEMs
 *                                              rename internal variables and filter methods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-15  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-20  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-11-22  Ht                    add If_AsrIfFeeTiSub, 
 *                                              ESCAN00054718: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub, 
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    ESCAN00059365: [AUTOSAR4, compiler warning]: Wrong define name in #undef statement causes re-definition warning
 *                                              add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin 
 *            2012-09-04  Ht                    add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-01-10  Seu                   MISRA deviation comments added
 *  01.08.00  2013-03-01  Seu    ESCAN00065501  AR4-325: Add support for Post-build RAM memory section
 *            2013-04-12  Seu    ESCAN00066614  Add the deviation for violation of MISRA rule 19.6
 *  01.09.00  2013-12-10  Seu    ESCAN00072537  Add *_NOCACHE_* memory sections for variables
 *            2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *  01.10.00  2016-09-27  Seu                   FEATC-317: FEAT-2002: CommonAsr__Common: Support 64 Bit Signal Types for COM according to ASR 4.2.2
 *********************************************************************************************************************/

/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_19.6 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* PRQA S 0883 1 */ /* MD_MemMap_19.15 */
#undef MEMMAP_VENDOR_ID /* PRQA S 0841 */ /* MD_MSR_19.6 */

#define MEMMAP_VENDOR_ID        (30u)

/* AUTOSAR Software Specification Version Information */

# undef MEMMAP_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_REVISION_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

/* AUTOSAR release 4.0 R3 */
# define MEMMAP_AR_RELEASE_MAJOR_VERSION       (4u)
# define MEMMAP_AR_RELEASE_MINOR_VERSION       (0u)
# define MEMMAP_AR_RELEASE_REVISION_VERSION    (3u)

/* compatiblity to older versions */
# undef MEM_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_AR_RELEASE_MAJOR_VERSION          MEMMAP_AR_RELEASE_MAJOR_VERSION
# define MEM_AR_RELEASE_MINOR_VERSION          MEMMAP_AR_RELEASE_MINOR_VERSION
# define MEM_AR_RELEASE_PATCH_VERSION          MEMMAP_AR_RELEASE_REVISION_VERSION


# undef MEMMAP_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEMMAP_SW_MAJOR_VERSION     (1u)
# define MEMMAP_SW_MINOR_VERSION     (9u)
# define MEMMAP_SW_PATCH_VERSION     (0u)

/* compatiblity to older versions */
# undef MEM_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_SW_MAJOR_VERSION        MEMMAP_SW_MAJOR_VERSION 
# define MEM_SW_MINOR_VERSION        MEMMAP_SW_MINOR_VERSION 
# define MEM_SW_PATCH_VERSION        MEMMAP_SW_PATCH_VERSION 

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */


#include "Rte_MemMap.h"
#include "Rte_Stub.h"


/**********************************************************************************************************************
 *  COMM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef COMM_START_SEC_CODE
  #undef COMM_START_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define OPEN_COMM_CODE_SEC_START                            /* mapped to default code section */
#endif
#ifdef COMM_STOP_SEC_CODE
  #undef COMM_STOP_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define OPEN_COMM_CODE_SEC_END                             /* default code stop section */
#endif

#ifdef OPEN_COMM_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_COMM_CODE_SEC_START
#endif

#ifdef OPEN_COMM_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_COMM_CODE_SEC_END
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef COMM_START_SEC_CONST_8BIT
# undef COMM_START_SEC_CONST_8BIT                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef COMM_STOP_SEC_CONST_8BIT
# undef COMM_STOP_SEC_CONST_8BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef COMM_START_SEC_CONST_16BIT
# undef COMM_START_SEC_CONST_16BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#ifdef COMM_STOP_SEC_CONST_16BIT
# undef COMM_STOP_SEC_CONST_16BIT                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef COMM_START_SEC_CONST_UNSPECIFIED
# undef COMM_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_CONST_UNSPECIFIED
# undef COMM_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* CONST PBCFG sections */

#ifdef COMM_START_SEC_PBCFG
# undef COMM_START_SEC_PBCFG                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef COMM_STOP_SEC_PBCFG
# undef COMM_STOP_SEC_PBCFG                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef COMM_START_SEC_VAR_NOINIT_8BIT
# undef COMM_START_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_8BIT
# undef COMM_STOP_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_NOINIT_16BIT
# undef COMM_START_SEC_VAR_NOINIT_16BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_16BIT
# undef COMM_STOP_SEC_VAR_NOINIT_16BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef COMM_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR PBCFG sections */

#ifdef COMM_START_SEC_VAR_PBCFG
# undef COMM_START_SEC_VAR_PBCFG                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG                         /* mapped to default var pbcfg section */
#endif
#ifdef COMM_STOP_SEC_VAR_PBCFG
# undef COMM_STOP_SEC_VAR_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                /* default var stop section */
#endif

/* VAR ZERO INIT sections */

#ifdef COMM_START_SEC_VAR_ZERO_INIT_8BIT
# undef COMM_START_SEC_VAR_ZERO_INIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef COMM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef COMM_STOP_SEC_VAR_ZERO_INIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NVRAM sections */

#ifdef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# undef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  COMM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CanSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CANSM_START_SEC_CODE
# undef CANSM_START_SEC_CODE
# define OPEN_CANSM_CODE_SEC_START                                               /* mapped to default code section */
#endif

#ifdef CANSM_STOP_SEC_CODE
# undef CANSM_STOP_SEC_CODE
# define OPEN_CANSM_CODE_SEC_END                                                /* default code stop section */
#endif

#ifdef CANSM_START_SEC_APPL_CODE
# undef CANSM_START_SEC_APPL_CODE
# define OPEN_CANSM_CODE_SEC_START                                               /* mapped to default code section */
#endif

#ifdef CANSM_STOP_SEC_APPL_CODE
# undef CANSM_STOP_SEC_APPL_CODE
# define OPEN_CANSM_CODE_SEC_END                                                /* default code stop section */
#endif

#ifdef OPEN_CANSM_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_CANSM_CODE_SEC_START
#endif

#ifdef OPEN_CANSM_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_CANSM_CODE_SEC_END
#endif
 


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */


#ifdef CANSM_START_SEC_CONST_8BIT
# undef CANSM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_8BIT
# undef CANSM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#ifdef CANSM_START_SEC_CONST_32BIT
# undef CANSM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_32BIT
# undef CANSM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif


#ifdef CANSM_START_SEC_CONST_UNSPECIFIED
# undef CANSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_CONST_UNSPECIFIED
# undef CANSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */
#ifdef CANSM_START_SEC_CONST_FAST_8BIT
# undef CANSM_START_SEC_CONST_FAST_8BIT
# define START_SEC_CONST_FAST_8BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_FAST_8BIT
# undef CANSM_STOP_SEC_CONST_FAST_8BIT
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#ifdef CANSM_START_SEC_CONST_FAST_32BIT
# undef CANSM_START_SEC_CONST_FAST_32BIT
# define START_SEC_CONST_FAST_32BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_FAST_32BIT
# undef CANSM_STOP_SEC_CONST_FAST_32BIT
# define STOP_SEC_CONST
#endif


#ifdef CANSM_START_SEC_CONST_FAST_UNSPECIFIED
# undef CANSM_START_SEC_CONST_FAST_UNSPECIFIED
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef CANSM_STOP_SEC_CONST_FAST_UNSPECIFIED
# define STOP_SEC_CONST
#endif



/* Postbuild CFG CONST sections */



/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */


/* VAR NOINIT sections */

#ifdef CANSM_START_SEC_VAR_NOINIT_8BIT
# undef CANSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_NOINIT_8BIT
# undef CANSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif


#ifdef CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef CANSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef CANSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

#ifdef CANSM_START_SEC_VAR_FAST_NOINIT_8BIT
# undef CANSM_START_SEC_VAR_FAST_NOINIT_8BIT
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef CANSM_STOP_SEC_VAR_FAST_NOINIT_8BIT
# define STOP_SEC_VAR
#endif


#ifdef CANSM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef CANSM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef CANSM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR FAST ZERO INIT sections */

#ifdef CANSM_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef CANSM_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef CANSM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif







/**********************************************************************************************************************
 *  CanSM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHSM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined ETHSM_START_SEC_CODE
  #undef ETHSM_START_SEC_CODE                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#if defined ETHSM_STOP_SEC_CODE
  #undef ETHSM_STOP_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#if defined ETHSM_START_SEC_CONST_8BIT
# undef ETHSM_START_SEC_CONST_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#if defined ETHSM_STOP_SEC_CONST_8BIT
# undef ETHSM_STOP_SEC_CONST_8BIT                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined ETHSM_START_SEC_CONST_16BIT
# undef ETHSM_START_SEC_CONST_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined ETHSM_STOP_SEC_CONST_16BIT
# undef ETHSM_STOP_SEC_CONST_16BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined ETHSM_START_SEC_CONST_32BIT
# undef ETHSM_START_SEC_CONST_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined ETHSM_STOP_SEC_CONST_32BIT
# undef ETHSM_STOP_SEC_CONST_32BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined ETHSM_START_SEC_CONST_UNSPECIFIED
# undef ETHSM_START_SEC_CONST_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined ETHSM_STOP_SEC_CONST_UNSPECIFIED
# undef ETHSM_STOP_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined ETHSM_START_SEC_PBCFG
# undef ETHSM_START_SEC_PBCFG                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined ETHSM_STOP_SEC_PBCFG
# undef ETHSM_STOP_SEC_PBCFG                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined ETHSM_START_SEC_PBCFG_ROOT
# undef ETHSM_START_SEC_PBCFG_ROOT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined ETHSM_STOP_SEC_PBCFG_ROOT
# undef ETHSM_STOP_SEC_PBCFG_ROOT                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#if defined ETHSM_START_SEC_VAR_NOINIT_8BIT
# undef ETHSM_START_SEC_VAR_NOINIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHSM_STOP_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_NOINIT_16BIT
# undef ETHSM_START_SEC_VAR_NOINIT_16BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHSM_STOP_SEC_VAR_NOINIT_16BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_NOINIT_32BIT
# undef ETHSM_START_SEC_VAR_NOINIT_32BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHSM_STOP_SEC_VAR_NOINIT_32BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHSM_START_SEC_VAR_NOINIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_INIT_8BIT
# undef ETHSM_START_SEC_VAR_INIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_INIT_8BIT
# undef ETHSM_STOP_SEC_VAR_INIT_8BIT                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_INIT_16BIT
# undef ETHSM_START_SEC_VAR_INIT_16BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_INIT_16BIT
# undef ETHSM_STOP_SEC_VAR_INIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_INIT_32BIT
# undef ETHSM_START_SEC_VAR_INIT_32BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_INIT_32BIT
# undef ETHSM_STOP_SEC_VAR_INIT_32BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_INIT_UNSPECIFIED
# undef ETHSM_START_SEC_VAR_INIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHSM_START_SEC_VAR_ZERO_INIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_ZERO_INIT_16BIT
# undef ETHSM_START_SEC_VAR_ZERO_INIT_16BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_16BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_ZERO_INIT_32BIT
# undef ETHSM_START_SEC_VAR_ZERO_INIT_32BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_32BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined ETHSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHSM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Cdd_AsrCdd START 
 *********************************************************************************************************************/
/* Copy the memory mapping defines for each of your configured CDDs and replace the prefix _CDD with the MSN of your configured CDD as higher case. */

/*******  CODE sections **********************************************************************************************/

#ifdef _CDD_START_SEC_CODE
# undef _CDD_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef _CDD_STOP_SEC_CODE
# undef _CDD_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/* Add additional memory mapping defines for each of you configured CDDs here. */

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

/* FAST CONST sections */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data */

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

/* VAR FAST ZERO INIT sections */

/**********************************************************************************************************************
 *  Cdd_AsrCdd END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  XCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(XCP_START_SEC_CODE)
# undef XCP_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(XCP_STOP_SEC_CODE)
# undef XCP_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(XCP_START_SEC_CONST_8BIT)
# undef XCP_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(XCP_STOP_SEC_CONST_8BIT)
# undef XCP_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(XCP_START_SEC_CONST_16BIT)
# undef XCP_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(XCP_STOP_SEC_CONST_16BIT)
# undef XCP_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(XCP_START_SEC_CONST_32BIT)
# undef XCP_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(XCP_STOP_SEC_CONST_32BIT)
# undef XCP_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(XCP_START_SEC_CONST_UNSPECIFIED)
# undef XCP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_CONST_UNSPECIFIED)
# undef XCP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(XCP_START_SEC_PBCFG)
# undef XCP_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(XCP_STOP_SEC_PBCFG)
# undef XCP_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(XCP_START_SEC_VAR_INIT_8BIT)
# undef XCP_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(XCP_START_SEC_VAR_INIT_16BIT)
# undef XCP_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_INIT_32BIT)
# undef XCP_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(XCP_START_SEC_VAR_NOINIT_8BIT)
# undef XCP_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOINIT_16BIT)
# undef XCP_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOINIT_32BIT)
# undef XCP_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(XCP_START_SEC_VAR_PBCFG)
# undef XCP_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(XCP_STOP_SEC_VAR_PBCFG)
# undef XCP_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(XCP_START_SEC_VAR_ZERO_INIT_8BIT)
# undef XCP_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_ZERO_INIT_16BIT)
# undef XCP_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_ZERO_INIT_32BIT)
# undef XCP_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOCACHE INIT sections */

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR Safe sections */
#if defined (XCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE)
# undef XCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined (XCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE)
# undef XCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  XCP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANXCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CANXCP_START_SEC_CODE
  #undef CANXCP_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif

#ifdef CANXCP_STOP_SEC_CODE
  #undef CANXCP_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CANXCP_START_SEC_CONST_8BIT
  #undef CANXCP_START_SEC_CONST_8BIT
  #define START_SEC_CONST_8BIT                      /* mapped to const 8 bit section */
#endif

#ifdef CANXCP_STOP_SEC_CONST_8BIT
  #undef CANXCP_STOP_SEC_CONST_8BIT
  #define STOP_SEC_CONST                            /* default const stop section */
#endif

#ifdef CANXCP_START_SEC_CONST_UNSPECIFIED
  #undef CANXCP_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED               /* mapped to const unspecified bit section */
#endif

#ifdef CANXCP_STOP_SEC_CONST_UNSPECIFIED
  #undef CANXCP_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


/* Post build config unspecified */

#ifdef CANXCP_START_SEC_PBCFG_ROOT
  #undef CANXCP_START_SEC_PBCFG_ROOT
  #define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif

#ifdef CANXCP_STOP_SEC_PBCFG_ROOT
  #undef CANXCP_STOP_SEC_PBCFG_ROOT
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


#ifdef CANXCP_START_SEC_PBCFG
  #undef CANXCP_START_SEC_PBCFG
  #define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif

#ifdef CANXCP_STOP_SEC_PBCFG
  #undef CANXCP_STOP_SEC_PBCFG
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef CANXCP_START_SEC_VAR_INIT_8BIT
  #undef CANXCP_START_SEC_VAR_INIT_8BIT
  #define START_SEC_VAR_INIT_8BIT                 /* mapped to uninitialized RAM 8bit section */
#endif

#ifdef CANXCP_STOP_SEC_VAR_INIT_8BIT
  #undef CANXCP_STOP_SEC_VAR_INIT_8BIT
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif


#ifdef CANXCP_START_SEC_VAR_NOINIT_8BIT
  #undef CANXCP_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT                 /* mapped to uninitialized RAM 8bit section */
#endif

#ifdef CANXCP_STOP_SEC_VAR_NOINIT_8BIT
  #undef CANXCP_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif


#ifdef CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED          /* mapped to uninitialized RAM unspecified section */
#endif

#ifdef CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif


#ifdef CANXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef CANXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef CANXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef CANXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANXCP END
 *********************************************************************************************************************/

/* ==== Start sections mapping ==== */
#ifdef DCM_START_SEC_CONST_8
# undef DCM_START_SEC_CONST_8                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                                        /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_16
# undef DCM_START_SEC_CONST_16                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_32
# undef DCM_START_SEC_CONST_32                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CONST_UNSPECIFIED
# undef DCM_START_SEC_CONST_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                                 /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_8
# undef DCM_START_SEC_CALIB_8                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                                        /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_16
# undef DCM_START_SEC_CALIB_16                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_32
# undef DCM_START_SEC_CALIB_32                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_CALIB_UNSPECIFIED
# undef DCM_START_SEC_CALIB_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                                 /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_PBCFG
# undef DCM_START_SEC_PBCFG                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                                       /*mapped to default const section */
#endif

#ifdef DCM_START_SEC_VAR_PBCFG
# undef DCM_START_SEC_VAR_PBCFG                                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG                                         /*mapped to default var section */
#endif

#ifdef DCM_START_SEC_VAR_INIT_8
# undef DCM_START_SEC_VAR_INIT_8                                   	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT                                     /*mapped to default initialized var section*/
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_8
# undef DCM_START_SEC_VAR_NO_INIT_8                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT                                   /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_16
# undef DCM_START_SEC_VAR_NO_INIT_16                                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT                                  /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_32
# undef DCM_START_SEC_VAR_NO_INIT_32
# define START_SEC_VAR_NOINIT_32BIT                                  /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_VAR_INIT_32
# undef DCM_START_SEC_VAR_INIT_32                                  	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT                                    /*mapped to default initialized var section*/
#endif

#ifdef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED                            /*mapped to default var section*/
#endif

#ifdef DCM_START_SEC_CODE
# undef DCM_START_SEC_CODE                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                              /*mapped to default code section*/
#endif

#ifdef DCM_START_SEC_APPL_CODE
# undef DCM_START_SEC_APPL_CODE                                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                              /*mapped to default code section*/
#endif

#ifdef DCM_START_SEC_CALLOUT_CODE
# undef DCM_START_SEC_CALLOUT_CODE                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                              /*mapped to default code section*/
#endif

/* ==== Stop sections mapping ==== */
#ifdef DCM_STOP_SEC_CONST_8
# undef DCM_STOP_SEC_CONST_8                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_16
# undef DCM_STOP_SEC_CONST_16                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_32
# undef DCM_STOP_SEC_CONST_32
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CONST_UNSPECIFIED
# undef DCM_STOP_SEC_CONST_UNSPECIFIED                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_8
# undef DCM_STOP_SEC_CALIB_8                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_16
# undef DCM_STOP_SEC_CALIB_16                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_32
# undef DCM_STOP_SEC_CALIB_32
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_CALIB_UNSPECIFIED
# undef DCM_STOP_SEC_CALIB_UNSPECIFIED                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_PBCFG
# undef DCM_STOP_SEC_PBCFG                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                              /*default const section */
#endif

#ifdef DCM_STOP_SEC_VAR_INIT_8
# undef DCM_STOP_SEC_VAR_INIT_8                                   	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default initialized var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_8
# undef DCM_STOP_SEC_VAR_NO_INIT_8                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_16
# undef DCM_STOP_SEC_VAR_NO_INIT_16                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_32
# undef DCM_STOP_SEC_VAR_NO_INIT_32                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_INIT_32
# undef DCM_STOP_SEC_VAR_INIT_32                                  	 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default initialized var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default var section*/
#endif

#ifdef DCM_STOP_SEC_VAR_PBCFG
# undef DCM_STOP_SEC_VAR_PBCFG                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                /*default var section */
#endif

#ifdef DCM_STOP_SEC_CODE
# undef DCM_STOP_SEC_CODE                                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                               /*default code section*/
#endif

#ifdef DCM_STOP_SEC_APPL_CODE
# undef DCM_STOP_SEC_APPL_CODE                                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                               /*default code section*/
#endif

#ifdef DCM_STOP_SEC_CALLOUT_CODE
# undef DCM_STOP_SEC_CALLOUT_CODE                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                               /*default code section*/
#endif

/** DEM **********************************************************************/
/*---------------------START-MODULE-SPECIFIC-START-SECTIONS------------------*/
                                                             
                                                            /* code sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_CODE)
# undef DEM_START_SEC_CODE                                                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

#if defined (DEM_START_SEC_CALLOUT_CODE)
# undef DEM_START_SEC_CALLOUT_CODE                                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

#if defined (DEM_START_SEC_CODE_LIB)
# undef DEM_START_SEC_CODE_LIB                                                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

                                               /* uninitialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_VAR_NOINIT_8BIT)
# undef DEM_START_SEC_VAR_NOINIT_8BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_16BIT)
# undef DEM_START_SEC_VAR_NOINIT_16BIT                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_32BIT)
# undef DEM_START_SEC_VAR_NOINIT_32BIT                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_VAR_NOINIT_8BIT)
# undef DEM_START_SEC_VAR_NOINIT_8BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_16BIT)
# undef DEM_START_SEC_VAR_NOINIT_16BIT                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_32BIT)
# undef DEM_START_SEC_VAR_NOINIT_32BIT                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED                                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

                                                 /* initialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_VAR_INIT_8BIT)
# undef DEM_START_SEC_VAR_INIT_8BIT                                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_INIT_32BIT)
# undef DEM_START_SEC_VAR_INIT_32BIT                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif

                                              /* post-buildable RAM sections */
/*---------------------------------------------------------------------------*/
#if defined (DEM_START_SEC_VAR_PBCFG)
# undef DEM_START_SEC_VAR_PBCFG                                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif


                                                          /* NV RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_VAR_SAVED_ZONE0_8BIT)
# undef DEM_START_SEC_VAR_SAVED_ZONE0_8BIT                                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif

#if defined (DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
# undef DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_CONST_SAVED_RECOVERY_ZONE0)
# undef DEM_START_SEC_CONST_SAVED_RECOVERY_ZONE0                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

                                                             /* ROM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_CONST_8BIT)
# undef DEM_START_SEC_CONST_8BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#if defined (DEM_START_SEC_CONST_16BIT)
# undef DEM_START_SEC_CONST_16BIT                                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined (DEM_START_SEC_CONST_32BIT)
# undef DEM_START_SEC_CONST_32BIT                                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif

#if defined (DEM_START_SEC_CONST_8BIT)
# undef DEM_START_SEC_CONST_8BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#if defined (DEM_START_SEC_CONST_16BIT)
# undef DEM_START_SEC_CONST_16BIT                                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined (DEM_START_SEC_CONST_32BIT)
# undef DEM_START_SEC_CONST_32BIT                                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined (DEM_START_SEC_CONST_UNSPECIFIED)
# undef DEM_START_SEC_CONST_UNSPECIFIED                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_CONFIG_DATA_UNSPECIFIED)
# undef DEM_START_SEC_CONFIG_DATA_UNSPECIFIED                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_PBCFG_ROOT)
# undef DEM_START_SEC_PBCFG_ROOT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif

#if defined (DEM_START_SEC_CALIB_UNSPECIFIED)
# undef DEM_START_SEC_CALIB_UNSPECIFIED                                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_CALIB_8BIT)
# undef DEM_START_SEC_CALIB_8BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif

#if defined (DEM_START_SEC_PBCFG)
# undef DEM_START_SEC_PBCFG                                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif



/*---------------------STOP-MODULE-SPECIFIC-START-SECTIONS-------------------*/

/*---------------------START-MODULE-SPECIFIC-STOP-SECTIONS-------------------*/

                                                             
                                                            /* code sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_CODE)
# undef DEM_STOP_SEC_CODE                                                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#if defined (DEM_STOP_SEC_CALLOUT_CODE)
# undef DEM_STOP_SEC_CALLOUT_CODE                                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#if defined (DEM_STOP_SEC_CODE_LIB)
# undef DEM_STOP_SEC_CODE_LIB                                                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

                                               /* uninitialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_VAR_NOINIT_8BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_8BIT                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_16BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_16BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_32BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_32BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_NOINIT_8BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_8BIT                                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_16BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_16BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_32BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_32BIT                                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED                                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

                                                 /* initialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_VAR_INIT_8BIT)
# undef DEM_STOP_SEC_VAR_INIT_8BIT                                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_INIT_32BIT)
# undef DEM_STOP_SEC_VAR_INIT_32BIT                                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

                                              /* post-buildable RAM sections */
/*---------------------------------------------------------------------------*/
#if defined (DEM_STOP_SEC_VAR_PBCFG)
# undef DEM_STOP_SEC_VAR_PBCFG                                                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

                                                          /* NV RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
# undef DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_8BIT)
# undef DEM_STOP_SEC_VAR_SAVED_ZONE0_8BIT                                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_CONST_SAVED_RECOVERY_ZONE0)
# undef DEM_STOP_SEC_CONST_SAVED_RECOVERY_ZONE0                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

                                                             /* ROM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_CONST_8BIT)
# undef DEM_STOP_SEC_CONST_8BIT                                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_16BIT)
# undef DEM_STOP_SEC_CONST_16BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_32BIT)
# undef DEM_STOP_SEC_CONST_32BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_CONST_8BIT)
# undef DEM_STOP_SEC_CONST_8BIT                                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_16BIT)
# undef DEM_STOP_SEC_CONST_16BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_32BIT)
# undef DEM_STOP_SEC_CONST_32BIT                                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_UNSPECIFIED)
# undef DEM_STOP_SEC_CONST_UNSPECIFIED                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_PBCFG_ROOT)
# undef DEM_STOP_SEC_PBCFG_ROOT                                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_CALIB_UNSPECIFIED)
# undef DEM_STOP_SEC_CALIB_UNSPECIFIED                                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CALIB_8BIT)
# undef DEM_STOP_SEC_CALIB_8BIT                                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_PBCFG)
# undef DEM_STOP_SEC_PBCFG                                                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*---------------------STOP-MODULE-SPECIFIC-STOP-SECTIONS--------------------*/
/** End of DEM ***************************************************************/


/***********************************************************************************************************************
 *  SWCDIAG START
 **********************************************************************************************************************/


/******* CODE sections ************************************************************************************************/

#if defined(SWCDIAG_START_SEC_CODE)
# undef SWCDIAG_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE         /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_CODE */
#if defined(SWCDIAG_STOP_SEC_CODE)
# undef SWCDIAG_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif /* SWCDIAG_START_SEC_CODE */


/******* CONST sections ***********************************************************************************************/

#if defined(SWCDIAG_START_SEC_CONST_UNSPECIFIED)
# undef SWCDIAG_START_SEC_CONST_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED         /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_CONST_UNSPECIFIED */
#if defined(SWCDIAG_STOP_SEC_CONST_UNSPECIFIED)
# undef SWCDIAG_STOP_SEC_CONST_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST          /* default code stop section */
#endif /* SWCDIAG_START_SEC_CONST_UNSPECIFIED */


/******* VAR sections *************************************************************************************************/

#if defined(SWCDIAG_START_SEC_VAR_INIT_8)
# undef SWCDIAG_START_SEC_VAR_INIT_8      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8         /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_VAR_INIT_8 */
#if defined(SWCDIAG_STOP_SEC_VAR_INIT_8)
# undef SWCDIAG_STOP_SEC_VAR_INIT_8       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR          /* default code stop section */
#endif /* SWCDIAG_START_SEC_VAR_INIT_8 */

#if defined(SWCDIAG_START_SEC_VAR_NO_INIT_8)
# undef SWCDIAG_START_SEC_VAR_NO_INIT_8      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_8         /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_8 */
#if defined(SWCDIAG_STOP_SEC_VAR_NO_INIT_8)
# undef SWCDIAG_STOP_SEC_VAR_NO_INIT_8       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR          /* default code stop section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_8 */

#if defined(SWCDIAG_START_SEC_VAR_NO_INIT_16)
# undef SWCDIAG_START_SEC_VAR_NO_INIT_16      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_16         /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_16 */
#if defined(SWCDIAG_STOP_SEC_VAR_NO_INIT_16)
# undef SWCDIAG_STOP_SEC_VAR_NO_INIT_16       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR          /* default code stop section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_16 */

#if defined(SWCDIAG_START_SEC_VAR_NO_INIT_32)
# undef SWCDIAG_START_SEC_VAR_NO_INIT_32      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_32         /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_32 */
#if defined(SWCDIAG_STOP_SEC_VAR_NO_INIT_32)
# undef SWCDIAG_STOP_SEC_VAR_NO_INIT_32       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR          /* default code stop section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_32 */

/***********************************************************************************************************************
 *  SWCDIAG STOP
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  Can START 
 *********************************************************************************************************************/

#if defined (CAN_REMAP_PB_SECTIONS)
/* for none PB variants the code will be mapped to standard sections, so the generated and static code can ignore the variant handling */
# if defined (CAN_START_SEC_PBCFG)
#  undef CAN_START_SEC_PBCFG                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_START_SEC_CONST_UNSPECIFIED
# endif
# if defined (CAN_STOP_SEC_PBCFG)
#  undef CAN_STOP_SEC_PBCFG                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_STOP_SEC_CONST_UNSPECIFIED
# endif

# if defined (CAN_START_SEC_VAR_PBCFG)
#  undef CAN_START_SEC_VAR_PBCFG                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
# endif
# if defined (CAN_STOP_SEC_VAR_PBCFG)
#  undef CAN_STOP_SEC_VAR_PBCFG                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# endif
#endif

/*******  CODE sections **********************************************************************************************/

#ifdef CAN_START_SEC_CODE                             /* CAN code */
# undef CAN_START_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OPEN_CAN_CODE_SEC_START                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_CODE
# undef CAN_STOP_SEC_CODE                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OPEN_CAN_CODE_SEC_END
#endif

#ifdef CAN_START_SEC_STATIC_CODE                      /* CAN static code */
# undef CAN_START_SEC_STATIC_CODE                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OPEN_CAN_CODE_SEC_START                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_STATIC_CODE
# undef CAN_STOP_SEC_STATIC_CODE                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OPEN_CAN_CODE_SEC_END
#endif

#ifdef CAN_START_SEC_CODE_APPL                        /* Appl code (generic precopy)*/
# undef CAN_START_SEC_CODE_APPL                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OPEN_CAN_CODE_SEC_START                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_CODE_APPL
# undef CAN_STOP_SEC_CODE_APPL                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OPEN_CAN_CODE_SEC_END
#endif

#ifdef OPEN_CAN_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_CAN_CODE_SEC_START
#endif

#ifdef OPEN_CAN_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_CAN_CODE_SEC_END
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CAN_START_SEC_CONST_8BIT                       /* Const 8bit */
# undef CAN_START_SEC_CONST_8BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                         /* mapped to default const 8bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_8BIT
# undef CAN_STOP_SEC_CONST_8BIT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_16BIT                      /* Const 16bit */
# undef CAN_START_SEC_CONST_16BIT                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT                        /* mapped to default const 16bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_16BIT
# undef CAN_STOP_SEC_CONST_16BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_32BIT                      /* Const 32bit */
# undef CAN_START_SEC_CONST_32BIT                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT                        /* mapped to default const 32bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_32BIT
# undef CAN_STOP_SEC_CONST_32BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_UNSPECIFIED                /* Const unspecified */
# undef CAN_START_SEC_CONST_UNSPECIFIED                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                  /* mapped to default const unspec section */
#endif
#ifdef CAN_STOP_SEC_CONST_UNSPECIFIED
# undef CAN_STOP_SEC_CONST_UNSPECIFIED                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */
/* unused */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data (not relevant for CFG5 AutoSar4.0.3) */
#ifdef CAN_START_SEC_PBCFG_ROOT                       /* Generated Postbuild Root Table */
# undef CAN_START_SEC_PBCFG_ROOT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                        /* mapped to default const postbuild section */
#endif
#ifdef CAN_STOP_SEC_PBCFG_ROOT
# undef CAN_STOP_SEC_PBCFG_ROOT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_PBCFG                            /* Generated Postbuild */
# undef CAN_START_SEC_PBCFG                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                        /* mapped to default const postbuild section */
#endif
#ifdef CAN_STOP_SEC_PBCFG
# undef CAN_STOP_SEC_PBCFG                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef CAN_START_SEC_VAR_INIT_UNSPECIFIED             /* init RAM*/
# undef CAN_START_SEC_VAR_INIT_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED               /* mapped to default init var section */
#endif
#ifdef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef CAN_START_SEC_VAR_NOINIT_UNSPECIFIED           /* uninit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_NOINIT_8BIT                  /* uninit 8bit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_8BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_8BIT
# undef CAN_STOP_SEC_VAR_NOINIT_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_NOINIT_16BIT                  /* uninit 16bit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_16BIT
# undef CAN_STOP_SEC_VAR_NOINIT_16BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_NOINIT_32BIT                  /* uninit 32bit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_32BIT
# undef CAN_STOP_SEC_VAR_NOINIT_32BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR PBCFG sections */

#ifdef CAN_START_SEC_VAR_PBCFG           /* Generated Postbuild RAM*/
# undef CAN_START_SEC_VAR_PBCFG            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_PBCFG
# undef CAN_STOP_SEC_VAR_PBCFG             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
/* unused */

/* VAR FAST INIT sections */
/* unused */

/* VAR FAST NOINIT sections */
/* unused */

/* VAR FAST ZERO INIT sections */
/* unused */

/**********************************************************************************************************************
 *  Can END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CAN_30_SI START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef CAN_30_SI_START_SEC_CODE
# undef CAN_30_SI_START_SEC_CODE
# define START_SEC_CODE                                 /* mapped to default code section*/
#endif

#ifdef CAN_30_SI_STOP_SEC_CODE
# undef CAN_30_SI_STOP_SEC_CODE
# define STOP_SEC_CODE                                  /* default code stop section*/
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef CAN_30_SI_START_SEC_CONST_8BIT
# undef CAN_30_SI_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                           /* mapped to default const section */
#endif

#ifdef CAN_30_SI_STOP_SEC_CONST_8BIT
# undef CAN_30_SI_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef CAN_30_SI_START_SEC_CONST_16BIT
# undef CAN_30_SI_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT                          /* mapped to default const section */
#endif

#ifdef CAN_30_SI_STOP_SEC_CONST_16BIT
# undef CAN_30_SI_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef CAN_30_SI_START_SEC_CONST_32BIT
# undef CAN_30_SI_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT                          /* mapped to default const section */
#endif

#ifdef CAN_30_SI_STOP_SEC_CONST_32BIT
# undef CAN_30_SI_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef CAN_30_SI_START_SEC_CONST_UNSPECIFIED
# undef CAN_30_SI_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED                    /* mapped to default const section */
#endif

#ifdef CAN_30_SI_STOP_SEC_CONST_UNSPECIFIED
# undef CAN_30_SI_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef CAN_30_SI_START_SEC_PBCFG
# undef CAN_30_SI_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG                          /* mapped to default const section */
#endif

#ifdef CAN_30_SI_STOP_SEC_PBCFG
# undef CAN_30_SI_STOP_SEC_PBCFG
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef CAN_30_SI_START_SEC_VAR_NOINIT_8BIT
# undef CAN_30_SI_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT                      /* mapped to default var section */
#endif

#ifdef CAN_30_SI_STOP_SEC_VAR_NOINIT_8BIT
# undef CAN_30_SI_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR                                   /* default var stop section*/
#endif

#ifdef CAN_30_SI_START_SEC_VAR_NOINIT_16BIT
# undef  CAN_30_SI_START_SEC_VAR_NOINIT_16BIT                /* mapped to default var section */
# define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef CAN_30_SI_STOP_SEC_VAR_NOINIT_16BIT
# undef CAN_30_SI_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef CAN_30_SI_START_SEC_VAR_NOINIT_32BIT
# undef  CAN_30_SI_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT                     /* mapped to default var section */
#endif

#ifdef CAN_30_SI_STOP_SEC_VAR_NOINIT_32BIT
# undef CAN_30_SI_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR                                   /* default var stop section*/
#endif

#ifdef CAN_30_SI_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CAN_30_SI_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED               /* mapped to default var section */
#endif

#ifdef CAN_30_SI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CAN_30_SI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef CAN_30_SI_START_SEC_VAR_ZERO_INIT_8BIT
# undef CAN_30_SI_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT                   /* mapped to default var section */
#endif

#ifdef CAN_30_SI_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CAN_30_SI_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef CAN_30_SI_START_SEC_VAR_PBCFG
# undef CAN_30_SI_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG                            /* mapped to default var section */
#endif

#ifdef CAN_30_SI_STOP_SEC_VAR_PBCFG
# undef CAN_30_SI_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

/**********************************************************************************************************************
 *  CAN_30_SI END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CRY_30_RH850ICUM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CRY_30_RH850ICUM_START_SEC_CODE
  #undef CRY_30_RH850ICUM_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef CRY_30_RH850ICUM_STOP_SEC_CODE
  #undef CRY_30_RH850ICUM_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#ifdef CRY_30_RH850ICUM_START_SEC_CONST_UNSPECIFIED
# undef CRY_30_RH850ICUM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRY_30_RH850ICUM_STOP_SEC_CONST_UNSPECIFIED
# undef CRY_30_RH850ICUM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CRY_30_RH850ICUM_START_SEC_VAR_NOINIT_8BIT
# undef CRY_30_RH850ICUM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CRY_30_RH850ICUM_STOP_SEC_VAR_NOINIT_8BIT
# undef CRY_30_RH850ICUM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef CRY_30_RH850ICUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CRY_30_RH850ICUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef CRY_30_RH850ICUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CRY_30_RH850ICUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRY_30_RH850ICUM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CRYPTO_30_CRYWRAPPER START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_CODE
# undef CRYPTO_30_CRYWRAPPER_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_CODE
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_APPL_CODE
# undef CRYPTO_30_CRYWRAPPER_START_SEC_APPL_CODE                    /* mapped to default code section */
# define START_SEC_CODE
#endif
#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_APPL_CODE
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_CONST_UNSPECIFIED
# undef CRYPTO_30_CRYWRAPPER_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_CONST_UNSPECIFIED
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_CONST_8BIT
# undef CRYPTO_30_CRYWRAPPER_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif

#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_CONST_8BIT
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_CONST_16BIT
# undef CRYPTO_30_CRYWRAPPER_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif

#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_CONST_16BIT
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_CONST_32BIT
# undef CRYPTO_30_CRYWRAPPER_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif

#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_CONST_32BIT
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_NOINIT_8BIT
# undef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_NOINIT_8BIT
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_NOINIT_16BIT
# undef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_NOINIT_16BIT
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_NOINIT_32BIT
# undef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_NOINIT_32BIT
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_ZERO_INIT_8BIT
# undef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_ZERO_INIT_32BIT
# undef CRYPTO_30_CRYWRAPPER_START_SEC_VAR_ZERO_INIT_32BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef CRYPTO_30_CRYWRAPPER_STOP_SEC_VAR_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRYPTO_30_CRYWRAPPER END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CRYPTO_30_LIBCV START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CRYPTO_30_LIBCV_START_SEC_CODE
# undef CRYPTO_30_LIBCV_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_CODE
# undef CRYPTO_30_LIBCV_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef CRYPTO_30_LIBCV_START_SEC_APPL_CODE
# undef CRYPTO_30_LIBCV_START_SEC_APPL_CODE                    /* mapped to default code section */
# define START_SEC_CODE
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_APPL_CODE
# undef CRYPTO_30_LIBCV_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
# undef CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
# undef CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif

#ifdef CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


#ifdef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT
# undef CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRYPTO_30_LIBCV END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  EEP_30_XXSPI01 START
 *********************************************************************************************************************/

/******** CODE sections **********************************************************************************************/

#ifdef EEP_30_XXSPI01_START_SEC_CODE
# undef EEP_30_XXSPI01_START_SEC_CODE /* PRQA S 841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_CODE
# undef EEP_30_XXSPI01_STOP_SEC_CODE /* PRQA S 841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef EEP_30_XXSPI01_START_SEC_CONST_32
# undef EEP_30_XXSPI01_START_SEC_CONST_32 /* PRQA S 841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_CONST_32
# undef EEP_30_XXSPI01_STOP_SEC_CONST_32 /* PRQA S 841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXSPI01_START_SEC_CONST_UNSPECIFIED
# undef EEP_30_XXSPI01_START_SEC_CONST_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_CONST_UNSPECIFIED
# undef EEP_30_XXSPI01_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXSPI01_START_SEC_PBCFG_ROOT
# undef EEP_30_XXSPI01_START_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_PBCFG_ROOT
# undef EEP_30_XXSPI01_STOP_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXSPI01_INST2_START_SEC_PBCFG_ROOT
# undef EEP_30_XXSPI01_INST2_START_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef EEP_30_XXSPI01_INST2_STOP_SEC_PBCFG_ROOT
# undef EEP_30_XXSPI01_INST2_STOP_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef EEP_30_XXSPI01_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef EEP_30_XXSPI01_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef EEP_30_XXSPI01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef EEP_30_XXSPI01_START_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_XXSPI01_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_XXSPI01_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EEP_30_XXSPI01 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHSWT START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHSWT_30_SJA1105_START_SEC_CODE
  #undef ETHSWT_30_SJA1105_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_CODE
  #undef ETHSWT_30_SJA1105_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_CODE_FAST
  #undef ETHSWT_30_SJA1105_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_CODE_FAST
  #undef ETHSWT_30_SJA1105_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_CODE_ISR
  #undef ETHSWT_30_SJA1105_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_CODE_ISR
  #undef ETHSWT_30_SJA1105_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_CONST_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_CONST_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_CONST_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_CONST_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_CONST_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_CONST_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_CONST_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_CONST_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_FAST_CONST_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_FAST_CONST_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_FAST_CONST_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_FAST_CONST_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_FAST_CONST_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_FAST_CONST_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_FAST_CONST_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_INIT_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_INIT_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_INIT_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_INIT_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_INIT_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_INIT_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOINIT_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOINIT_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOINIT_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_INIT_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_INIT_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_INIT_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_INIT_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_INIT_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_INIT_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_NOINIT_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_NOINIT_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_NOINIT_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHSWT END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETH START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(ETH_START_SEC_CODE)
# undef ETH_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(ETH_STOP_SEC_CODE)
# undef ETH_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(ETH_START_SEC_CODE_FAST)
# undef ETH_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(ETH_STOP_SEC_CODE_FAST)
# undef ETH_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(ETH_START_SEC_CODE_ISR)
# undef ETH_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(ETH_STOP_SEC_CODE_ISR)
# undef ETH_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(ETH_START_SEC_CONST_8BIT)
# undef ETH_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(ETH_STOP_SEC_CONST_8BIT)
# undef ETH_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(ETH_START_SEC_CONST_16BIT)
# undef ETH_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(ETH_STOP_SEC_CONST_16BIT)
# undef ETH_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETH_START_SEC_CONST_32BIT)
# undef ETH_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(ETH_STOP_SEC_CONST_32BIT)
# undef ETH_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETH_START_SEC_CONST_UNSPECIFIED)
# undef ETH_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(ETH_STOP_SEC_CONST_UNSPECIFIED)
# undef ETH_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(ETH_START_SEC_FAST_CONST_8BIT)
# undef ETH_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(ETH_STOP_SEC_FAST_CONST_8BIT)
# undef ETH_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETH_START_SEC_FAST_CONST_16BIT)
# undef ETH_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(ETH_STOP_SEC_FAST_CONST_16BIT)
# undef ETH_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETH_START_SEC_FAST_CONST_32BIT)
# undef ETH_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(ETH_STOP_SEC_FAST_CONST_32BIT)
# undef ETH_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETH_START_SEC_FAST_CONST_UNSPECIFIED)
# undef ETH_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(ETH_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef ETH_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(ETH_START_SEC_PBCFG_ROOT)
# undef ETH_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(ETH_STOP_SEC_PBCFG_ROOT)
# undef ETH_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#if defined(ETH_START_SEC_PBCFG_GLOBALROOT)
# undef ETH_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(ETH_STOP_SEC_PBCFG_GLOBALROOT)
# undef ETH_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETH_START_SEC_PBCFG)
# undef ETH_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(ETH_STOP_SEC_PBCFG)
# undef ETH_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(ETH_START_SEC_VAR_INIT_8BIT)
# undef ETH_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(ETH_STOP_SEC_VAR_INIT_8BIT)
# undef ETH_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(ETH_START_SEC_VAR_INIT_16BIT)
# undef ETH_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(ETH_STOP_SEC_VAR_INIT_16BIT)
# undef ETH_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETH_START_SEC_VAR_INIT_32BIT)
# undef ETH_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(ETH_STOP_SEC_VAR_INIT_32BIT)
# undef ETH_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETH_START_SEC_VAR_INIT_UNSPECIFIED)
# undef ETH_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(ETH_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef ETH_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(ETH_START_SEC_VAR_NOINIT_8BIT)
# undef ETH_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(ETH_STOP_SEC_VAR_NOINIT_8BIT)
# undef ETH_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETH_START_SEC_VAR_NOINIT_16BIT)
# undef ETH_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(ETH_STOP_SEC_VAR_NOINIT_16BIT)
# undef ETH_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETH_START_SEC_VAR_NOINIT_32BIT)
# undef ETH_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(ETH_STOP_SEC_VAR_NOINIT_32BIT)
# undef ETH_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETH_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef ETH_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(ETH_START_SEC_VAR_PBCFG)
# undef ETH_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(ETH_STOP_SEC_VAR_PBCFG)
# undef ETH_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(ETH_START_SEC_VAR_ZERO_INIT_8BIT)
# undef ETH_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(ETH_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef ETH_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETH_START_SEC_VAR_ZERO_INIT_16BIT)
# undef ETH_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(ETH_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef ETH_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETH_START_SEC_VAR_ZERO_INIT_32BIT)
# undef ETH_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(ETH_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef ETH_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETH_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETH_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETH_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETH_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/*******  ETHERNET BUFFER AND DESCRIPTORS SECTION  *******************************************************************/


#ifdef ETH_START_SEC_VAR_NOINIT_DESCRIPTOR
# undef ETH_START_SEC_VAR_NOINIT_DESCRIPTOR
# define START_SEC_VAR_INIT_UNSPECIFIED

# pragma ghs section bss=".EthDesc"
#endif
#ifdef ETH_STOP_SEC_VAR_NOINIT_DESCRIPTOR
# undef ETH_STOP_SEC_VAR_NOINIT_DESCRIPTOR
# define STOP_SEC_VAR

# pragma ghs section bss=default
#endif

#ifdef ETH_START_SEC_VAR_NOINIT_RX_DESCRIPTOR
# undef ETH_START_SEC_VAR_NOINIT_RX_DESCRIPTOR
# define START_SEC_VAR_INIT_UNSPECIFIED

 # pragma ghs section bss=".EthDesc_Rx"
 
#endif
#ifdef ETH_STOP_SEC_VAR_NOINIT_RX_DESCRIPTOR
# undef ETH_STOP_SEC_VAR_NOINIT_RX_DESCRIPTOR
# define STOP_SEC_VAR

 # pragma ghs section bss=default
 
#endif

#ifdef ETH_START_SEC_VAR_NOINIT_TX_DESCRIPTOR
# undef ETH_START_SEC_VAR_NOINIT_TX_DESCRIPTOR
# define START_SEC_VAR_INIT_UNSPECIFIED

 # pragma ghs section bss=".EthDesc_Tx"
 
#endif
#ifdef ETH_STOP_SEC_VAR_NOINIT_TX_DESCRIPTOR
# undef ETH_STOP_SEC_VAR_NOINIT_TX_DESCRIPTOR
# define STOP_SEC_VAR

 # pragma ghs section bss=default
 
#endif
#ifdef ETH_START_SEC_VAR_NOINIT_BUFFER
# undef ETH_START_SEC_VAR_NOINIT_BUFFER
# define START_SEC_VAR_INIT_UNSPECIFIED

 # pragma ghs section bss=".EthBuffers"
 
#endif
#ifdef ETH_STOP_SEC_VAR_NOINIT_BUFFER
# undef ETH_STOP_SEC_VAR_NOINIT_BUFFER
# define STOP_SEC_VAR

 # pragma ghs section bss=default

#endif
#ifdef ETH_START_SEC_VAR_NOINIT_RX_BUFFER_0_0
# undef ETH_START_SEC_VAR_NOINIT_RX_BUFFER_0_0
# define START_SEC_VAR_INIT_UNSPECIFIED

 # pragma ghs section bss=".EthBuffers_Rx"
 
#endif
#ifdef ETH_STOP_SEC_VAR_NOINIT_RX_BUFFER_0_0
# undef ETH_STOP_SEC_VAR_NOINIT_RX_BUFFER_0_0
# define STOP_SEC_VAR

 # pragma ghs section bss=default
 
#endif
#ifdef ETH_START_SEC_VAR_NOINIT_TX_BUFFER_0
# undef ETH_START_SEC_VAR_NOINIT_TX_BUFFER_0
# define START_SEC_VAR_INIT_UNSPECIFIED

 # pragma ghs section bss=".EthBuffers_Tx"
 
#endif
#ifdef ETH_STOP_SEC_VAR_NOINIT_TX_BUFFER_0
# undef ETH_STOP_SEC_VAR_NOINIT_TX_BUFFER_0
# define STOP_SEC_VAR

 # pragma ghs section bss=default

#endif
/**********************************************************************************************************************
 *  ETH END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  I2c START
 **********************************************************************************************************************/

/*******  CODE sections  **********************************************************************************************/

#ifdef I2C_START_SEC_CODE
    #undef I2C_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define START_SEC_CODE
#endif

#ifdef I2C_STOP_SEC_CODE
    #undef I2C_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define STOP_SEC_CODE
#endif

/*******  ISR sections  ***********************************************************************************************/

#ifdef I2C_START_SEC_CODE_ISR
    #undef I2C_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define START_SEC_CODE_ISR
#endif

#ifdef I2C_STOP_SEC_CODE_ISR
    #undef I2C_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  *********************************************************************************************/

#ifdef I2C_START_SEC_PBCFG_ROOT
    #undef I2C_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define START_SEC_CONST_PBCFG
#endif

#ifdef I2C_STOP_SEC_PBCFG_ROOT
    #undef I2C_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define STOP_SEC_CONST
#endif

#ifdef I2C_START_SEC_PBCFG
    #undef I2C_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define START_SEC_CONST_PBCFG
#endif

#ifdef I2C_STOP_SEC_PBCFG
    #undef I2C_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define STOP_SEC_CONST
#endif

#ifdef I2C_START_SEC_CONST_32BIT
    #undef I2C_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define START_SEC_CONST_32BIT
#endif

#ifdef I2C_STOP_SEC_CONST_32BIT
    #undef I2C_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define STOP_SEC_CONST
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    #undef I2C_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  ***********************************************************************************************/
#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define STOP_SEC_VAR
#endif

#ifdef I2C_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef I2C_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef I2C_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef I2C_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define STOP_SEC_VAR
#endif

#ifdef I2C_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef I2C_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef I2C_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef I2C_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define STOP_SEC_VAR
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_0841 */
    #define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  I2c END
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_TJA1043_START_SEC_CODE) /* PRQA S 0883 */ /* Appears only while testing */
# undef CANTRCV_30_TJA1043_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CODE)
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1043_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1043_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_FAST_CONST_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_FAST_CONST_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_FAST_CONST_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_FAST_CONST_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_FAST_CONST_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_FAST_CONST_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_FAST_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_PBCFG)
# undef CANTRCV_30_TJA1043_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_PBCFG)
# undef CANTRCV_30_TJA1043_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_TJA1100 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_TJA1100_START_SEC_CODE
  #undef ETHTRCV_30_TJA1100_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_CODE
  #undef ETHTRCV_30_TJA1100_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_TJA1100_START_SEC_CONST_8BIT
# undef ETHTRCV_30_TJA1100_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_CONST_16BIT
# undef ETHTRCV_30_TJA1100_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_CONST_32BIT
# undef ETHTRCV_30_TJA1100_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_PBCFG
# undef ETHTRCV_30_TJA1100_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_PBCFG
# undef ETHTRCV_30_TJA1100_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_TJA1100_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_TJA1100_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_TJA1100 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  WDG_30_RH850F1X START
 *********************************************************************************************************************/
 
/******** CODE sections **********************************************************************************************/
#ifdef WDG_30_RH850F1X_START_SEC_CODE                      
    #undef WDG_30_RH850F1X_START_SEC_CODE  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_CODE
#endif
#ifdef WDG_30_RH850F1X_STOP_SEC_CODE
    #undef WDG_30_RH850F1X_STOP_SEC_CODE   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/
#ifdef WDG_30_RH850F1X_START_SEC_CONST_UNSPECIFIED
    #undef WDG_30_RH850F1X_START_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef WDG_30_RH850F1X_STOP_SEC_CONST_UNSPECIFIED
    #undef WDG_30_RH850F1X_STOP_SEC_CONST_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_CONST
#endif
#ifdef WDG_30_RH850F1X_START_SEC_PBCFG_ROOT
  #undef WDG_30_RH850F1X_START_SEC_PBCFG_ROOT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CONST_PBCFG
#endif
#ifdef WDG_30_RH850F1X_STOP_SEC_PBCFG_ROOT
  #undef WDG_30_RH850F1X_STOP_SEC_PBCFG_ROOT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/
#ifdef WDG_30_RH850F1X_START_SEC_VAR_INIT_8BIT       /* Init variables */
    #undef WDG_30_RH850F1X_START_SEC_VAR_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_INIT_8BIT
#endif
#ifdef WDG_30_RH850F1X_STOP_SEC_VAR_INIT_8BIT
    #undef WDG_30_RH850F1X_STOP_SEC_VAR_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR
#endif  
#ifdef WDG_30_RH850F1X_START_SEC_VAR_ZERO_INIT_8BIT    /* Cleared variables */
    #undef WDG_30_RH850F1X_START_SEC_VAR_ZERO_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef WDG_30_RH850F1X_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef WDG_30_RH850F1X_STOP_SEC_VAR_ZERO_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_RH850F1X_START_SEC_VAR_ZERO_INIT_32BIT
    #undef WDG_30_RH850F1X_START_SEC_VAR_ZERO_INIT_32BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef WDG_30_RH850F1X_STOP_SEC_VAR_ZERO_INIT_32BIT
    #undef WDG_30_RH850F1X_STOP_SEC_VAR_ZERO_INIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_RH850F1X_START_SEC_VAR_INIT_UNSPECIFIED
    #undef WDG_30_RH850F1X_START_SEC_VAR_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef WDG_30_RH850F1X_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef WDG_30_RH850F1X_STOP_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR
#endif
  
#ifdef WDG_30_RH850F1X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDG_30_RH850F1X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef WDG_30_RH850F1X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDG_30_RH850F1X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_RH850F1X_START_SEC_VAR_NOINIT_32BIT   /* No init variables */
    #undef WDG_30_RH850F1X_START_SEC_VAR_NOINIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef WDG_30_RH850F1X_STOP_SEC_VAR_NOINIT_32BIT
    #undef WDG_30_RH850F1X_STOP_SEC_VAR_NOINIT_32BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_RH850F1X_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef WDG_30_RH850F1X_START_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef WDG_30_RH850F1X_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDG_30_RH850F1X_STOP_SEC_VAR_NOINIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  WDG_30_RH850F1X END
 *********************************************************************************************************************/
 


/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IOHWAB_START_SEC_CODE
    #undef IOHWAB_START_SEC_CODE
    #define OPEN_IOHWAB_CODE_SEC_START
#endif
#ifdef IOHWAB_STOP_SEC_CODE
    #undef IOHWAB_STOP_SEC_CODE
    #define OPEN_IOHWAB_CODE_SEC_END
#endif

#ifdef OPEN_IOHWAB_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_IOHWAB_CODE_SEC_START
#endif

#ifdef OPEN_IOHWAB_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_IOHWAB_CODE_SEC_END
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef IOHWAB_START_SEC_CONST_32
    #undef IOHWAB_START_SEC_CONST_32
    #define START_SEC_CONST_32
#endif
#ifdef IOHWAB_STOP_SEC_CONST_32
    #undef IOHWAB_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef IOHWAB_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef IOHWAB_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef IOHWAB_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef IOHWAB_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef PDUR_START_SEC_CODE
# undef PDUR_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef PDUR_STOP_SEC_CODE
# undef PDUR_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef PDUR_START_SEC_CONST_8BIT
# undef PDUR_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_8BIT
# undef PDUR_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_16BIT
# undef PDUR_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_16BIT
# undef PDUR_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_32BIT
# undef PDUR_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_32BIT
# undef PDUR_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_UNSPECIFIED
# undef PDUR_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_CONST_UNSPECIFIED
# undef PDUR_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */


/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef PDUR_START_SEC_PBCFG
# undef PDUR_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef PDUR_STOP_SEC_PBCFG
# undef PDUR_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_ZERO_INIT_8BIT
# undef PDUR_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef PDUR_START_SEC_VAR_NOINIT_8BIT
# undef PDUR_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_8BIT
# undef PDUR_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_NOINIT_16BIT
# undef PDUR_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_16BIT
# undef PDUR_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_VAR_NOINIT_32BIT
# undef PDUR_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_32BIT
# undef PDUR_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif


#ifdef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT
# undef PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT
# undef PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

/* Postbuild CFG VAR sections */

#ifdef PDUR_START_SEC_VAR_PBCFG
# undef PDUR_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef PDUR_STOP_SEC_VAR_PBCFG
# undef PDUR_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  WDGIF START
 *********************************************************************************************************************/

// patch: rmitev: WdgIf is not configured yet
//#include "WdgIf_MemMap.h"

/*******  CODE sections **********************************************************************************************/

#if defined WDGIF_START_SEC_CODE
# undef WDGIF_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#if defined WDGIF_STOP_SEC_CODE
# undef WDGIF_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#if defined WDGIF_START_SEC_CONST_8BIT
# undef WDGIF_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#if defined WDGIF_STOP_SEC_CONST_8BIT
# undef WDGIF_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGIF_START_SEC_CONST_16BIT
# undef WDGIF_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined WDGIF_STOP_SEC_CONST_16BIT
# undef WDGIF_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGIF_START_SEC_CONST_32BIT
# undef WDGIF_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined WDGIF_STOP_SEC_CONST_32BIT
# undef WDGIF_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGIF_START_SEC_CONST_UNSPECIFIED
# undef WDGIF_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_CONST_UNSPECIFIED
# undef WDGIF_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined WDGIF_START_SEC_VAR_INIT_8BIT
# undef WDGIF_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_8BIT
# undef WDGIF_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_INIT_16BIT
# undef WDGIF_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_16BIT
# undef WDGIF_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_INIT_32BIT
# undef WDGIF_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_32BIT
# undef WDGIF_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef WDGIF_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined WDGIF_START_SEC_VAR_NOINIT_8BIT
# undef WDGIF_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_NOINIT_8BIT
# undef WDGIF_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_NOINIT_16BIT
# undef WDGIF_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_NOINIT_16BIT
# undef WDGIF_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_NOINIT_32BIT
# undef WDGIF_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_NOINIT_32BIT
# undef WDGIF_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO_INIT sections */

#if defined WDGIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef WDGIF_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_ZERO_INIT_16BIT
# undef WDGIF_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_ZERO_INIT_32BIT
# undef WDGIF_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  WDGIF END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANIF START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef CANIF_START_SEC_CODE
# undef CANIF_START_SEC_CODE                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OPEN_CANIF_CODE_SEC_START                            /* mapped to default code section */
#endif
#ifdef CANIF_STOP_SEC_CODE
# undef CANIF_STOP_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OPEN_CANIF_CODE_SEC_END                             /* default code stop section */
#endif


#ifdef CANIF_START_SEC_APPL_CODE
# undef CANIF_START_SEC_APPL_CODE                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OPEN_CANIF_CODE_SEC_START                            /* mapped to default code section */
#endif

#ifdef CANIF_STOP_SEC_APPL_CODE
# undef CANIF_STOP_SEC_APPL_CODE                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OPEN_CANIF_CODE_SEC_END                             /* default code stop section */
#endif

#ifdef OPEN_CANIF_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_CANIF_CODE_SEC_START
#endif

#ifdef OPEN_CANIF_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_CANIF_CODE_SEC_END
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CANIF_START_SEC_CONST_8BIT
# undef CANIF_START_SEC_CONST_8BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                      /* mapped to const 8 bit section */
#endif
#ifdef CANIF_STOP_SEC_CONST_8BIT
# undef CANIF_STOP_SEC_CONST_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                            /* default const stop section */
#endif

#ifdef CANIF_START_SEC_CONST_16BIT
# undef CANIF_START_SEC_CONST_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#ifdef CANIF_STOP_SEC_CONST_16BIT
# undef CANIF_STOP_SEC_CONST_16BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                             /* default const stop section */
#endif


/* Const 32bit */

#ifdef CANIF_START_SEC_CONST_32BIT
# undef CANIF_START_SEC_CONST_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT                      /* mapped to const 32 bit section */
#endif
#ifdef CANIF_STOP_SEC_CONST_32BIT
# undef CANIF_STOP_SEC_CONST_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                            /* default const stop section */
#endif


/* Const unspecified */

#ifdef CANIF_START_SEC_CONST_UNSPECIFIED
# undef CANIF_START_SEC_CONST_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED               /* mapped to const unspecified section */
#endif
#ifdef CANIF_STOP_SEC_CONST_UNSPECIFIED
# undef CANIF_STOP_SEC_CONST_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                            /* default const stop section */
#endif


/* FAST CONST sections */

#ifdef CANIF_START_SEC_CONST_FAST_8BIT
# undef CANIF_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_8BIT
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_8BIT
# undef CANIF_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CANIF_START_SEC_CONST_FAST_16BIT
# undef CANIF_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_16BIT
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_16BIT
# undef CANIF_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CANIF_START_SEC_CONST_FAST_32BIT
# undef CANIF_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_32BIT
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_32BIT
# undef CANIF_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CANIF_START_SEC_CONST_FAST_UNSPECIFIED
# undef CANIF_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#ifdef CANIF_START_SEC_PBCFG
# undef CANIF_START_SEC_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif
#ifdef CANIF_STOP_SEC_PBCFG
# undef CANIF_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef CANIF_START_SEC_VAR_INIT_8BIT
# undef CANIF_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef CANIF_START_SEC_VAR_INIT_16BIT
# undef CANIF_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_INIT_32BIT
# undef CANIF_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef CANIF_START_SEC_VAR_NOINIT_8BIT
# undef CANIF_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_8BIT
# undef CANIF_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOINIT_16BIT
# undef CANIF_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_16BIT
# undef CANIF_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOINIT_32BIT
# undef CANIF_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_32BIT
# undef CANIF_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef CANIF_START_SEC_VAR_PBCFG
# undef CANIF_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#ifdef CANIF_STOP_SEC_VAR_PBCFG
# undef CANIF_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef CANIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef CANIF_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_ZERO_INIT_16BIT
# undef CANIF_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_ZERO_INIT_32BIT
# undef CANIF_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef CANIF_START_SEC_VAR_FAST_INIT_8BIT
# undef CANIF_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_INIT_16BIT
# undef CANIF_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_INIT_32BIT
# undef CANIF_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
# undef CANIF_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_16BIT
# undef CANIF_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_32BIT
# undef CANIF_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef CANIF_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef CANIF_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANIF END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CRYIF START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CRYIF_START_SEC_CODE
# undef CRYIF_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef CRYIF_STOP_SEC_CODE
# undef CRYIF_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CRYIF_START_SEC_CONST_UNSPECIFIED
# undef CRYIF_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYIF_STOP_SEC_CONST_UNSPECIFIED
# undef CRYIF_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */


/* VAR ZERO INIT sections */

#ifdef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRYIF END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  If_AsrIfEa START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef EA_START_SEC_CODE
    #undef EA_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef EA_STOP_SEC_CODE
    #undef EA_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef EA_START_SEC_CONST_8BIT
    #undef EA_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef EA_STOP_SEC_CONST_8BIT
    #undef EA_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef EA_START_SEC_CONST_16BIT
    #undef EA_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef EA_STOP_SEC_CONST_16BIT
    #undef EA_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef EA_START_SEC_CONST_32BIT
    #undef EA_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef EA_STOP_SEC_CONST_32BIT
    #undef EA_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

#ifdef EA_START_SEC_CONST_UNSPECIFIED
    #undef EA_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef EA_STOP_SEC_CONST_UNSPECIFIED
    #undef EA_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  ********************************************************************************************/

/* VAR NOINIT sections */

#ifdef EA_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef EA_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef EA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef EA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST sections */

#ifdef EA_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef EA_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef EA_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef EA_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  If_AsrIfEa END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHIF START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined ETHIF_START_SEC_CODE
  #undef ETHIF_START_SEC_CODE                       /* PRQA S 0841 */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#if defined ETHIF_STOP_SEC_CODE
  #undef ETHIF_STOP_SEC_CODE                        /* PRQA S 0841 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#if defined ETHIF_START_SEC_CODE_ISR
  #undef ETHIF_START_SEC_CODE_ISR                   /* PRQA S 0841 */
  #define START_SEC_CODE_ISR                        /* mapped to default ISR code section */
#endif
#if defined ETHIF_STOP_SEC_CODE_ISR
  #undef ETHIF_STOP_SEC_CODE_ISR                    /* PRQA S 0841 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#if defined ETHIF_START_SEC_CONST_8BIT
# undef ETHIF_START_SEC_CONST_8BIT                  /* PRQA S 0841 */
# define START_SEC_CONST_8BIT
#endif
#if defined ETHIF_STOP_SEC_CONST_8BIT
# undef ETHIF_STOP_SEC_CONST_8BIT                   /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined ETHIF_START_SEC_CONST_16BIT
# undef ETHIF_START_SEC_CONST_16BIT                 /* PRQA S 0841 */
# define START_SEC_CONST_16BIT
#endif
#if defined ETHIF_STOP_SEC_CONST_16BIT
# undef ETHIF_STOP_SEC_CONST_16BIT                  /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined ETHIF_START_SEC_CONST_32BIT
# undef ETHIF_START_SEC_CONST_32BIT                 /* PRQA S 0841 */
# define START_SEC_CONST_32BIT
#endif
#if defined ETHIF_STOP_SEC_CONST_32BIT
# undef ETHIF_STOP_SEC_CONST_32BIT                  /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined ETHIF_START_SEC_CONST_UNSPECIFIED
# undef ETHIF_START_SEC_CONST_UNSPECIFIED           /* PRQA S 0841 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined ETHIF_STOP_SEC_CONST_UNSPECIFIED
# undef ETHIF_STOP_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined ETHIF_START_SEC_PBCFG
# undef ETHIF_START_SEC_PBCFG                       /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#if defined ETHIF_STOP_SEC_PBCFG
# undef ETHIF_STOP_SEC_PBCFG                        /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined ETHIF_START_SEC_PBCFG_ROOT
# undef ETHIF_START_SEC_PBCFG_ROOT                  /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#if defined ETHIF_STOP_SEC_PBCFG_ROOT
# undef ETHIF_STOP_SEC_PBCFG_ROOT                   /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#if defined ETHIF_START_SEC_VAR_NOINIT_8BIT
# undef ETHIF_START_SEC_VAR_NOINIT_8BIT             /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined ETHIF_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHIF_STOP_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined ETHIF_START_SEC_VAR_NOINIT_16BIT
# undef ETHIF_START_SEC_VAR_NOINIT_16BIT            /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined ETHIF_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHIF_STOP_SEC_VAR_NOINIT_16BIT             /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined ETHIF_START_SEC_VAR_NOINIT_32BIT
# undef ETHIF_START_SEC_VAR_NOINIT_32BIT            /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined ETHIF_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHIF_STOP_SEC_VAR_NOINIT_32BIT             /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined ETHIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHIF_START_SEC_VAR_NOINIT_UNSPECIFIED      /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETHIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined ETHIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined ETHIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED      /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHIF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  If_AsrIfFeeSmallSector START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FEE_30_SMALLSECTOR_START_SEC_CODE
    #undef FEE_30_SMALLSECTOR_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CODE
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_16BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_16BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_32BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_32BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  ********************************************************************************************/

/* VAR NOINIT sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  If_AsrIfFeeSmallSector END
 *********************************************************************************************************************/

#ifdef MEMIF_START_SEC_CONST_8BIT 
    #undef MEMIF_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef MEMIF_STOP_SEC_CONST_8BIT 
    #undef MEMIF_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


#ifdef MEMIF_START_SEC_CONST_32BIT
    #undef MEMIF_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif

#ifdef MEMIF_STOP_SEC_CONST_32BIT
    #undef MEMIF_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif


#ifdef MEMIF_START_SEC_CODE
    #undef MEMIF_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef MEMIF_STOP_SEC_CODE
    #undef MEMIF_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  SOAD START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined SOAD_START_SEC_CODE
# undef SOAD_START_SEC_CODE                         /* PRQA S 0841 */
# define START_SEC_CODE                             /* mapped to default code section */
#endif
#if defined SOAD_STOP_SEC_CODE
# undef SOAD_STOP_SEC_CODE                          /* PRQA S 0841 */
# define STOP_SEC_CODE                              /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#if defined SOAD_START_SEC_CONST_8BIT
# undef SOAD_START_SEC_CONST_8BIT                   /* PRQA S 0841 */
# define START_SEC_CONST_8BIT
#endif
#if defined SOAD_STOP_SEC_CONST_8BIT
# undef SOAD_STOP_SEC_CONST_8BIT                    /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined SOAD_START_SEC_CONST_16BIT
# undef SOAD_START_SEC_CONST_16BIT                  /* PRQA S 0841 */
# define START_SEC_CONST_16BIT
#endif
#if defined SOAD_STOP_SEC_CONST_16BIT
# undef SOAD_STOP_SEC_CONST_16BIT                   /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined SOAD_START_SEC_CONST_32BIT
# undef SOAD_START_SEC_CONST_32BIT                  /* PRQA S 0841 */
# define START_SEC_CONST_32BIT
#endif
#if defined SOAD_STOP_SEC_CONST_32BIT
# undef SOAD_STOP_SEC_CONST_32BIT                   /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined SOAD_START_SEC_CONST_UNSPECIFIED
# undef SOAD_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined SOAD_STOP_SEC_CONST_UNSPECIFIED
# undef SOAD_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined SOAD_START_SEC_PBCFG
# undef SOAD_START_SEC_PBCFG                        /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#if defined SOAD_STOP_SEC_PBCFG
# undef SOAD_STOP_SEC_PBCFG                         /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#if defined SOAD_START_SEC_VAR_NOINIT_8BIT
# undef SOAD_START_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined SOAD_STOP_SEC_VAR_NOINIT_8BIT
# undef SOAD_STOP_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_NOINIT_16BIT
# undef SOAD_START_SEC_VAR_NOINIT_16BIT             /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined SOAD_STOP_SEC_VAR_NOINIT_16BIT
# undef SOAD_STOP_SEC_VAR_NOINIT_16BIT              /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_NOINIT_32BIT
# undef SOAD_START_SEC_VAR_NOINIT_32BIT             /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined SOAD_STOP_SEC_VAR_NOINIT_32BIT
# undef SOAD_STOP_SEC_VAR_NOINIT_32BIT              /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SOAD_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined SOAD_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SOAD_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_INIT_8BIT
# undef SOAD_START_SEC_VAR_INIT_8BIT                /* PRQA S 0841 */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined SOAD_STOP_SEC_VAR_INIT_8BIT
# undef SOAD_STOP_SEC_VAR_INIT_8BIT                 /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_INIT_16BIT
# undef SOAD_START_SEC_VAR_INIT_16BIT               /* PRQA S 0841 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined SOAD_STOP_SEC_VAR_INIT_16BIT
# undef SOAD_STOP_SEC_VAR_INIT_16BIT                /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_INIT_32BIT
# undef SOAD_START_SEC_VAR_INIT_32BIT               /* PRQA S 0841 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined SOAD_STOP_SEC_VAR_INIT_32BIT
# undef SOAD_STOP_SEC_VAR_INIT_32BIT                /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_INIT_UNSPECIFIED
# undef SOAD_START_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined SOAD_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SOAD_STOP_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_ZERO_INIT_8BIT
# undef SOAD_START_SEC_VAR_ZERO_INIT_8BIT           /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined SOAD_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SOAD_STOP_SEC_VAR_ZERO_INIT_8BIT            /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_ZERO_INIT_16BIT
# undef SOAD_START_SEC_VAR_ZERO_INIT_16BIT          /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined SOAD_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SOAD_STOP_SEC_VAR_ZERO_INIT_16BIT           /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_ZERO_INIT_32BIT
# undef SOAD_START_SEC_VAR_ZERO_INIT_32BIT          /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined SOAD_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SOAD_STOP_SEC_VAR_ZERO_INIT_32BIT           /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SOAD_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined SOAD_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SOAD_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined SOAD_START_SEC_VAR_PBCFG
# undef SOAD_START_SEC_VAR_PBCFG                    /* PRQA S 0841 */
# define START_SEC_VAR_PBCFG
#endif
#if defined SOAD_STOP_SEC_VAR_PBCFG
# undef SOAD_STOP_SEC_VAR_PBCFG                     /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SOAD END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Com START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef COM_START_SEC_CODE
# undef COM_START_SEC_CODE
# define OPEN_COM_CODE_SEC_START
#endif
#ifdef COM_STOP_SEC_CODE
# undef COM_STOP_SEC_CODE
# define OPEN_COM_CODE_SEC_END
#endif

/* COM application callback code section (Rte_Cbk.h)*/
#ifdef COM_START_SEC_APPL_CODE
# undef COM_START_SEC_APPL_CODE
# define OPEN_COM_CODE_SEC_START
#endif
#ifdef COM_STOP_SEC_APPL_CODE
# undef COM_STOP_SEC_APPL_CODE
# define OPEN_COM_CODE_SEC_END
#endif

#ifdef OPEN_COM_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_COM_CODE_SEC_START
#endif

#ifdef OPEN_COM_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_COM_CODE_SEC_END
#endif



/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef COM_START_SEC_CONST_8BIT
# undef COM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef COM_STOP_SEC_CONST_8BIT
# undef COM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_16BIT
# undef COM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef COM_STOP_SEC_CONST_16BIT
# undef COM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_32BIT
# undef COM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef COM_STOP_SEC_CONST_32BIT
# undef COM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_64BIT
# undef COM_START_SEC_CONST_64BIT
# define START_SEC_CONST_64BIT
#endif
#ifdef COM_STOP_SEC_CONST_64BIT
# undef COM_STOP_SEC_CONST_64BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_UNSPECIFIED
# undef COM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_CONST_UNSPECIFIED
# undef COM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_PBCFG
# undef COM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef COM_STOP_SEC_PBCFG
# undef COM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_VAR_PBCFG
# undef COM_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef COM_STOP_SEC_VAR_PBCFG
# undef COM_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef COM_START_SEC_VAR_INIT_UNSPECIFIED
# undef COM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_ZERO_INIT_8BIT
# undef COM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef COM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef COM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef COM_START_SEC_VAR_NOINIT_BOOLEAN
# undef COM_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef COM_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_8BIT
# undef COM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_8BIT
# undef COM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_16BIT
# undef COM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_16BIT
# undef COM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_32BIT
# undef COM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_32BIT
# undef COM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_64BIT
# undef COM_START_SEC_VAR_NOINIT_64BIT
# define START_SEC_VAR_NOINIT_64BIT
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_64BIT
# undef COM_STOP_SEC_VAR_NOINIT_64BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef COM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  IpduM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IPDUM_START_SEC_CODE
# undef IPDUM_START_SEC_CODE
# define START_SEC_CODE /* mapped to default code section */
#endif
#ifdef IPDUM_STOP_SEC_CODE
# undef IPDUM_STOP_SEC_CODE
# define STOP_SEC_CODE  /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* Postbuild CFG CONST sections */

#ifdef IPDUM_START_SEC_PBCFG_8BIT
# undef IPDUM_START_SEC_PBCFG_8BIT
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG_8BIT
# undef IPDUM_STOP_SEC_PBCFG_8BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_PBCFG_16BIT
# undef IPDUM_START_SEC_PBCFG_16BIT
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG_16BIT
# undef IPDUM_STOP_SEC_PBCFG_16BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_PBCFG_32BIT
# undef IPDUM_START_SEC_PBCFG_32BIT
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG_32BIT
# undef IPDUM_STOP_SEC_PBCFG_32BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_PBCFG_UNSPECIFIED
# undef IPDUM_START_SEC_PBCFG_UNSPECIFIED
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG_UNSPECIFIED
# undef IPDUM_STOP_SEC_PBCFG_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_PBCFG
# undef IPDUM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_PBCFG
# undef IPDUM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_VAR_PBCFG
# undef IPDUM_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef IPDUM_STOP_SEC_VAR_PBCFG
# undef IPDUM_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_CONST_8BIT
# undef IPDUM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef IPDUM_STOP_SEC_CONST_8BIT
# undef IPDUM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_CONST_16BIT
# undef IPDUM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef IPDUM_STOP_SEC_CONST_16BIT
# undef IPDUM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_CONST_32BIT
# undef IPDUM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef IPDUM_STOP_SEC_CONST_32BIT
# undef IPDUM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_CONST_UNSPECIFIED
# undef IPDUM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_CONST_UNSPECIFIED
# undef IPDUM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR ZERO INIT sections */

#ifdef IPDUM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef IPDUM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef IPDUM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_ZERO_INIT_8BIT
# undef IPDUM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef IPDUM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

#ifdef IPDUM_START_SEC_VAR_INIT_UNSPECIFIED
# undef IPDUM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_INIT_8BIT
# undef IPDUM_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_INIT_8BIT
# undef IPDUM_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef IPDUM_START_SEC_VAR_NOINIT_8BIT
# undef IPDUM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_8BIT
# undef IPDUM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_NOINIT_16BIT
# undef IPDUM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_16BIT
# undef IPDUM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_NOINIT_32BIT
# undef IPDUM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_32BIT
# undef IPDUM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef IPDUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef IPDUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  IpduM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LDCOM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef LDCOM_START_SEC_CODE
# undef LDCOM_START_SEC_CODE
# define START_SEC_CODE /* mapped to default code section */
#endif
#ifdef LDCOM_STOP_SEC_CODE
# undef LDCOM_STOP_SEC_CODE
# define STOP_SEC_CODE  /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef LDCOM_START_SEC_CONST_8BIT
# undef LDCOM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT   /* mapped to default const 8bit section */
#endif
#ifdef LDCOM_STOP_SEC_CONST_8BIT
# undef LDCOM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST /* default const stop section */
#endif

#ifdef LDCOM_START_SEC_CONST_16BIT
# undef LDCOM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef LDCOM_STOP_SEC_CONST_16BIT
# undef LDCOM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef LDCOM_START_SEC_CONST_32BIT
# undef LDCOM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef LDCOM_STOP_SEC_CONST_32BIT
# undef LDCOM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef LDCOM_START_SEC_CONST_UNSPECIFIED
# undef LDCOM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef LDCOM_STOP_SEC_CONST_UNSPECIFIED
# undef LDCOM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#ifdef LDCOM_START_SEC_PBCFG
# undef LDCOM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef LDCOM_STOP_SEC_PBCFG
# undef LDCOM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef LDCOM_START_SEC_VAR_INIT_8BIT
# undef LDCOM_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT        /* mapped to default var init 8bit section */
#endif
#ifdef LDCOM_STOP_SEC_VAR_INIT_8BIT
# undef LDCOM_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR   /* default var stop section */
#endif

#ifdef LDCOM_START_SEC_VAR_INIT_16BIT
# undef LDCOM_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_INIT_16BIT
# undef LDCOM_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_INIT_32BIT
# undef LDCOM_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_INIT_32BIT
# undef LDCOM_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_INIT_UNSPECIFIED
# undef LDCOM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef LDCOM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef LDCOM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef LDCOM_START_SEC_VAR_NOINIT_BOOLEAN
# undef LDCOM_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef LDCOM_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_NOINIT_8BIT
# undef LDCOM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_NOINIT_8BIT
# undef LDCOM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_NOINIT_16BIT
# undef LDCOM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_NOINIT_16BIT
# undef LDCOM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_NOINIT_32BIT
# undef LDCOM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_NOINIT_32BIT
# undef LDCOM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef LDCOM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef LDCOM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef LDCOM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef LDCOM_START_SEC_VAR_ZERO_INIT_8BIT
# undef LDCOM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef LDCOM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef LDCOM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef LDCOM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef LDCOM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

/* VAR FAST ZERO INIT sections */


/**********************************************************************************************************************
 *  LDCOM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SECOC START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(SECOC_START_SEC_CODE)
# undef SECOC_START_SEC_CODE      /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_CODE /* mapped to default code section */
#endif

#if defined(SECOC_STOP_SEC_CODE)
# undef SECOC_STOP_SEC_CODE       /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define STOP_SEC_CODE  /* default code stop section */
#endif

#if defined(SECOC_START_SEC_APPL_CODE)
# undef SECOC_START_SEC_APPL_CODE      /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_CODE /* mapped to default code section */
#endif

#if defined(SECOC_STOP_SEC_APPL_CODE)
# undef SECOC_STOP_SEC_APPL_CODE       /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define STOP_SEC_CODE  /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(SECOC_START_SEC_CONST_8BIT)
# undef SECOC_START_SEC_CONST_8BIT  /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT   /* mapped to default const 8bit section */
#endif
#if defined(SECOC_STOP_SEC_CONST_8BIT)
# undef SECOC_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_CONST /* default const stop section */
#endif

#if defined(SECOC_START_SEC_CONST_16BIT)
# undef SECOC_START_SEC_CONST_16BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(SECOC_STOP_SEC_CONST_16BIT)
# undef SECOC_STOP_SEC_CONST_16BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(SECOC_START_SEC_CONST_32BIT)
# undef SECOC_START_SEC_CONST_32BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(SECOC_STOP_SEC_CONST_32BIT)
# undef SECOC_STOP_SEC_CONST_32BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(SECOC_START_SEC_CONST_UNSPECIFIED)
# undef SECOC_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(SECOC_STOP_SEC_CONST_UNSPECIFIED)
# undef SECOC_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(SECOC_START_SEC_PBCFG)
# undef SECOC_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(SECOC_STOP_SEC_PBCFG)
# undef SECOC_STOP_SEC_PBCFG /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(SECOC_START_SEC_VAR_INIT_8BIT)
# undef SECOC_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT        /* mapped to default var init 8bit section */
#endif
#if defined(SECOC_STOP_SEC_VAR_INIT_8BIT)
# undef SECOC_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define STOP_SEC_VAR   /* default var stop section */
#endif

#if defined(SECOC_START_SEC_VAR_INIT_16BIT)
# undef SECOC_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_INIT_16BIT)
# undef SECOC_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_INIT_32BIT)
# undef SECOC_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_INIT_32BIT)
# undef SECOC_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_INIT_UNSPECIFIED)
# undef SECOC_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined SECOC_START_SEC_VAR_NOINIT_BOOLEAN
# undef SECOC_START_SEC_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined SECOC_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef SECOC_STOP_SEC_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_NOINIT_8BIT)
# undef SECOC_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_NOINIT_8BIT)
# undef SECOC_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_NOINIT_16BIT)
# undef SECOC_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_NOINIT_16BIT)
# undef SECOC_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_NOINIT_32BIT)
# undef SECOC_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_NOINIT_32BIT)
# undef SECOC_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef SECOC_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(SECOC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef SECOC_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_PBCFG)
# undef SECOC_START_SEC_VAR_PBCFG /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(SECOC_STOP_SEC_VAR_PBCFG)
# undef SECOC_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(SECOC_START_SEC_VAR_ZERO_INIT_8BIT)
# undef SECOC_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef SECOC_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_ZERO_INIT_16BIT)
# undef SECOC_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef SECOC_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_ZERO_INIT_32BIT)
# undef SECOC_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(SECOC_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef SECOC_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(SECOC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef SECOC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(SECOC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef SECOC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */


/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */


/**********************************************************************************************************************
 *  SECOC END
 *********************************************************************************************************************/

#ifdef ADC_DMA_DB_START_SEC_VAR_NO_INIT_32
  #undef ADC_DMA_DB_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ADC_DMA_DB_STOP_SEC_VAR_NO_INIT_32
  #undef ADC_DMA_DB_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef ADC_DMA_DB_START_SEC_VAR_NOINIT_32BIT
  #undef ADC_DMA_DB_START_SEC_VAR_NOINIT_32BIT
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ADC_DMA_DB_STOP_SEC_VAR_NOINIT_32BIT
  #undef ADC_DMA_DB_STOP_SEC_VAR_NOINIT_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef ADC_DMA_START_SEC_VAR_NO_INIT_16
  #undef ADC_DMA_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef ADC_DMA_STOP_SEC_VAR_NO_INIT_16
  #undef ADC_DMA_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef ADC_DMA_START_SEC_VAR_NO_INIT_32
  #undef ADC_DMA_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ADC_DMA_STOP_SEC_VAR_NO_INIT_32
  #undef ADC_DMA_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef ADC_DMA_START_SEC_VAR_NOINIT_16
  #undef ADC_DMA_START_SEC_VAR_NOINIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef ADC_DMA_STOP_SEC_VAR_NOINIT_16
  #undef ADC_DMA_STOP_SEC_VAR_NOINIT_16
  #define STOP_SEC_VAR
#endif

#ifdef ADC_DMA_START_SEC_VAR_NOINIT_32
  #undef ADC_DMA_START_SEC_VAR_NOINIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ADC_DMA_STOP_SEC_VAR_NOINIT_32
  #undef ADC_DMA_STOP_SEC_VAR_NOINIT_32
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_APPL_CODE
  #undef ADC_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_APPL_CODE
  #undef ADC_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_CODE_FAST
  #undef ADC_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef ADC_STOP_SEC_CODE_FAST
  #undef ADC_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_16
  #undef ADC_START_SEC_CONFIG_DATA_16
  #define START_SEC_CONST_16BIT
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_16
  #undef ADC_STOP_SEC_CONFIG_DATA_16
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_32
  #undef ADC_START_SEC_CONFIG_DATA_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_32
  #undef ADC_STOP_SEC_CONFIG_DATA_32
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_8
  #undef ADC_START_SEC_CONFIG_DATA_8
  #define START_SEC_CONST_8BIT
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_8
  #undef ADC_STOP_SEC_CONFIG_DATA_8
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONST_32
  #undef ADC_START_SEC_CONST_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef ADC_STOP_SEC_CONST_32
  #undef ADC_STOP_SEC_CONST_32
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_CONST_32BIT
  #undef ADC_START_SEC_CONST_32BIT
  #define START_SEC_CONST_32BIT
#endif

#ifdef ADC_STOP_SEC_CONST_32BIT
  #undef ADC_STOP_SEC_CONST_32BIT
  #define STOP_SEC_CONST
#endif

#ifdef ADC_START_SEC_PRIVATE_CODE
  #undef ADC_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_PRIVATE_CODE
  #undef ADC_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_PUBLIC_CODE
  #undef ADC_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_PUBLIC_CODE
  #undef ADC_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ADC_START_SEC_VAR_BOOLEAN
  #undef ADC_START_SEC_VAR_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_BOOLEAN
  #undef ADC_STOP_SEC_VAR_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_INIT_BOOLEAN
  #undef ADC_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_INIT_BOOLEAN
  #undef ADC_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_16
  #undef ADC_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_16
  #undef ADC_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_32
  #undef ADC_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_32
  #undef ADC_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_8
  #undef ADC_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_8
  #undef ADC_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_BOOLEAN
  #undef ADC_START_SEC_VAR_NO_INIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #undef ADC_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NOINIT_16BIT
  #undef ADC_START_SEC_VAR_NOINIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_16BIT
  #undef ADC_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NOINIT_32BIT
  #undef ADC_START_SEC_VAR_NOINIT_32BIT
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_32BIT
  #undef ADC_STOP_SEC_VAR_NOINIT_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NOINIT_8BIT
  #undef ADC_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_8BIT
  #undef ADC_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NOINIT_BOOLEAN
  #undef ADC_START_SEC_VAR_NOINIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_BOOLEAN
  #undef ADC_STOP_SEC_VAR_NOINIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef CORTST_START_SEC_APPL_CODE
  #undef CORTST_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef CORTST_STOP_SEC_APPL_CODE
  #undef CORTST_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef CORTST_START_SEC_BUFFER_CODE
  #undef CORTST_START_SEC_BUFFER_CODE
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CORTST_STOP_SEC_BUFFER_CODE
  #undef CORTST_STOP_SEC_BUFFER_CODE
  #define STOP_SEC_VAR
#endif

#ifdef CORTST_START_SEC_CODE_FAST
  #undef CORTST_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef CORTST_STOP_SEC_CODE_FAST
  #undef CORTST_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef CORTST_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef CORTST_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CORTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef CORTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CORTST_START_SEC_CONST_UNSPECIFIED
  #undef CORTST_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CORTST_STOP_SEC_CONST_UNSPECIFIED
  #undef CORTST_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef CORTST_START_SEC_PUBLIC_CODE
  #undef CORTST_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef CORTST_STOP_SEC_PUBLIC_CODE
  #undef CORTST_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef CORTST_START_SEC_VAR_INIT_UNSPECIFIED
  #undef CORTST_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef CORTST_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef CORTST_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef CORTST_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef CORTST_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CORTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef CORTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef CORTST_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef CORTST_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CORTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef CORTST_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef CORTST_START_SEC_VAR_UNSPECIFIED
  #undef CORTST_START_SEC_VAR_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef CORTST_STOP_SEC_VAR_UNSPECIFIED
  #undef CORTST_STOP_SEC_VAR_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DIO_START_SEC_CONST_UNSPECIFIED
  #undef DIO_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_CONST_UNSPECIFIED
  #undef DIO_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef DIO_START_SEC_PUBLIC_CODE
  #undef DIO_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef DIO_STOP_SEC_PUBLIC_CODE
  #undef DIO_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef DIO_START_SEC_VAR_BOOLEAN
  #undef DIO_START_SEC_VAR_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_VAR_BOOLEAN
  #undef DIO_STOP_SEC_VAR_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_INIT_BOOLEAN
  #undef DIO_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_VAR_INIT_BOOLEAN
  #undef DIO_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_NO_INIT_16
  #undef DIO_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef DIO_STOP_SEC_VAR_NO_INIT_16
  #undef DIO_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef DIO_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef DIO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef DIO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef DIO_START_SEC_VAR_NOINIT_16BIT
  #undef DIO_START_SEC_VAR_NOINIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef DIO_STOP_SEC_VAR_NOINIT_16BIT
  #undef DIO_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef FDL_START_SEC_CONST_UNSPECIFIED
  #undef FDL_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FDL_STOP_SEC_CONST_UNSPECIFIED
  #undef FDL_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FDL_START_SEC_PUBLIC_CODE
  #undef FDL_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef FDL_STOP_SEC_PUBLIC_CODE
  #undef FDL_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FDL_START_SEC_VAR_UNSPECIFIED
  #undef FDL_START_SEC_VAR_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FDL_STOP_SEC_VAR_UNSPECIFIED
  #undef FDL_STOP_SEC_VAR_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_APPL_CODE
  #undef FLS_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_APPL_CODE
  #undef FLS_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_CODE
  #undef FLS_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_CODE
  #undef FLS_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_CODE_FAST
  #undef FLS_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef FLS_STOP_SEC_CODE_FAST
  #undef FLS_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLS_START_SEC_PRIVATE_CODE
  #undef FLS_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_PRIVATE_CODE
  #undef FLS_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_PUBLIC_CODE
  #undef FLS_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_PUBLIC_CODE
  #undef FLS_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_START_SEC_VAR_BOOLEAN
  #undef FLS_START_SEC_VAR_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_BOOLEAN
  #undef FLS_STOP_SEC_VAR_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_INIT_BOOLEAN
  #undef FLS_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_INIT_BOOLEAN
  #undef FLS_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_INIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_32
  #undef FLS_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FLS_STOP_SEC_VAR_NO_INIT_32
  #undef FLS_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NOINIT_32BIT
  #undef FLS_START_SEC_VAR_NOINIT_32BIT
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FLS_STOP_SEC_VAR_NOINIT_32BIT
  #undef FLS_STOP_SEC_VAR_NOINIT_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef FLS_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_START_SEC_VAR_UNSPECIFIED
  #undef FLS_START_SEC_VAR_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLS_STOP_SEC_VAR_UNSPECIFIED
  #undef FLS_STOP_SEC_VAR_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_APPL_CODE
  #undef FLSTST_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef FLSTST_STOP_SEC_APPL_CODE
  #undef FLSTST_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLSTST_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLSTST_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLSTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef FLSTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLSTST_START_SEC_PRIVATE_CODE
  #undef FLSTST_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef FLSTST_STOP_SEC_PRIVATE_CODE
  #undef FLSTST_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLSTST_START_SEC_PUBLIC_CODE
  #undef FLSTST_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLSTST_STOP_SEC_PUBLIC_CODE
  #undef FLSTST_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLSTST_START_SEC_VAR_INIT_UNSPECIFIED
  #undef FLSTST_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FLSTST_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef FLSTST_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_VAR_NO_INIT_32
  #undef FLSTST_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FLSTST_STOP_SEC_VAR_NO_INIT_32
  #undef FLSTST_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef FLSTST_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLSTST_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FLSTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef FLSTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_APPL_CODE
  #undef GPT_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_APPL_CODE
  #undef GPT_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CODE_FAST
  #undef GPT_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef GPT_STOP_SEC_CODE_FAST
  #undef GPT_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_PRIVATE_CODE
  #undef GPT_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_PRIVATE_CODE
  #undef GPT_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_PUBLIC_CODE
  #undef GPT_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_PUBLIC_CODE
  #undef GPT_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_VAR_BOOLEAN
  #undef GPT_START_SEC_VAR_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_BOOLEAN
  #undef GPT_STOP_SEC_VAR_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
  #undef GPT_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
  #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_8
  #undef GPT_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_8
  #undef GPT_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_NOINIT_8BIT
  #undef GPT_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef GPT_STOP_SEC_VAR_NOINIT_8BIT
  #undef GPT_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef GPT_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef GPT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_APPL_CODE
  #undef ICU_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef ICU_STOP_SEC_APPL_CODE
  #undef ICU_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_CODE_FAST
  #undef ICU_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef ICU_STOP_SEC_CODE_FAST
  #undef ICU_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef ICU_START_SEC_PRIVATE_CODE
  #undef ICU_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef ICU_STOP_SEC_PRIVATE_CODE
  #undef ICU_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_PUBLIC_CODE
  #undef ICU_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef ICU_STOP_SEC_PUBLIC_CODE
  #undef ICU_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_VAR_BOOLEAN
  #undef ICU_START_SEC_VAR_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_BOOLEAN
  #undef ICU_STOP_SEC_VAR_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_INIT_BOOLEAN
  #undef ICU_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_INIT_BOOLEAN
  #undef ICU_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NO_INIT_32
  #undef ICU_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ICU_STOP_SEC_VAR_NO_INIT_32
  #undef ICU_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NOINIT_32BIT
  #undef ICU_START_SEC_VAR_NOINIT_32BIT
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef ICU_STOP_SEC_VAR_NOINIT_32BIT
  #undef ICU_STOP_SEC_VAR_NOINIT_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ICU_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef ICU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ICU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_APPL_CODE
  #undef MCU_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_APPL_CODE
  #undef MCU_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_BURAM_VAR_NO_INIT_32
  #undef MCU_START_SEC_BURAM_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_BURAM_VAR_NO_INIT_32
  #undef MCU_STOP_SEC_BURAM_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_BURAM_VAR_NOINIT_32BIT
  #undef MCU_START_SEC_BURAM_VAR_NOINIT_32BIT
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_BURAM_VAR_NOINIT_32BIT
  #undef MCU_STOP_SEC_BURAM_VAR_NOINIT_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_CODE_FAST
  #undef MCU_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef MCU_STOP_SEC_CODE_FAST
  #undef MCU_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_CONFIG_DATA_16
  #undef MCU_START_SEC_CONFIG_DATA_16
  #define START_SEC_CONST_16BIT
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA_16
  #undef MCU_STOP_SEC_CONFIG_DATA_16
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_CONST_UNSPECIFIED
  #undef MCU_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_CONST_UNSPECIFIED
  #undef MCU_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_PRIVATE_CODE
  #undef MCU_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_PRIVATE_CODE
  #undef MCU_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_PUBLIC_CODE
  #undef MCU_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_PUBLIC_CODE
  #undef MCU_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_RRAM_CODE
  #undef MCU_START_SEC_RRAM_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_RRAM_CODE
  #undef MCU_STOP_SEC_RRAM_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_RRAM_ROM_CODE
  #undef MCU_START_SEC_RRAM_ROM_CODE
  #define START_SEC_CODE
#endif

#ifdef MCU_STOP_SEC_RRAM_ROM_CODE
  #undef MCU_STOP_SEC_RRAM_ROM_CODE
  #define STOP_SEC_CODE
#endif

#ifdef MCU_START_SEC_VAR_1BIT
  #undef MCU_START_SEC_VAR_1BIT
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_1BIT
  #undef MCU_STOP_SEC_VAR_1BIT
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_INIT_BOOLEAN
  #undef MCU_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_INIT_BOOLEAN
  #undef MCU_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NO_INIT_16
  #undef MCU_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT_16
  #undef MCU_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NO_INIT_32
  #undef MCU_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT_32
  #undef MCU_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NO_INIT_8
  #undef MCU_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT_8
  #undef MCU_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NOINIT_16BIT
  #undef MCU_START_SEC_VAR_NOINIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef MCU_STOP_SEC_VAR_NOINIT_16BIT
  #undef MCU_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NOINIT_32BIT
  #undef MCU_START_SEC_VAR_NOINIT_32BIT
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef MCU_STOP_SEC_VAR_NOINIT_32BIT
  #undef MCU_STOP_SEC_VAR_NOINIT_32BIT
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NOINIT_8BIT
  #undef MCU_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef MCU_STOP_SEC_VAR_NOINIT_8BIT
  #undef MCU_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PORT_START_SEC_PRIVATE_CODE
  #undef PORT_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_PRIVATE_CODE
  #undef PORT_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_PUBLIC_CODE
  #undef PORT_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_PUBLIC_CODE
  #undef PORT_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_VAR_BOOLEAN
  #undef PORT_START_SEC_VAR_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_VAR_BOOLEAN
  #undef PORT_STOP_SEC_VAR_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_VAR_INIT_BOOLEAN
  #undef PORT_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_VAR_INIT_BOOLEAN
  #undef PORT_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_VAR_NO_INIT_16
  #undef PORT_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef PORT_STOP_SEC_VAR_NO_INIT_16
  #undef PORT_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_VAR_NO_INIT_8
  #undef PORT_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef PORT_STOP_SEC_VAR_NO_INIT_8
  #undef PORT_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef PORT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef PORT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_VAR_NOINIT_16BIT
  #undef PORT_START_SEC_VAR_NOINIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef PORT_STOP_SEC_VAR_NOINIT_16BIT
  #undef PORT_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_VAR_NOINIT_8BIT
  #undef PORT_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef PORT_STOP_SEC_VAR_NOINIT_8BIT
  #undef PORT_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef PORT_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef PORT_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_APPL_CODE
  #undef PWM_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef PWM_STOP_SEC_APPL_CODE
  #undef PWM_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_CODE_FAST
  #undef PWM_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef PWM_STOP_SEC_CODE_FAST
  #undef PWM_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef PWM_START_SEC_PRIVATE_CODE
  #undef PWM_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef PWM_STOP_SEC_PRIVATE_CODE
  #undef PWM_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_PUBLIC_CODE
  #undef PWM_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef PWM_STOP_SEC_PUBLIC_CODE
  #undef PWM_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_VAR_BOOLEAN
  #undef PWM_START_SEC_VAR_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_BOOLEAN
  #undef PWM_STOP_SEC_VAR_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_INIT_BOOLEAN
  #undef PWM_START_SEC_VAR_INIT_BOOLEAN
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_INIT_BOOLEAN
  #undef PWM_STOP_SEC_VAR_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NO_INIT_16
  #undef PWM_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef PWM_STOP_SEC_VAR_NO_INIT_16
  #undef PWM_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NO_INIT_8
  #undef PWM_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef PWM_STOP_SEC_VAR_NO_INIT_8
  #undef PWM_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NOINIT_16BIT
  #undef PWM_START_SEC_VAR_NOINIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_16BIT
  #undef PWM_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NOINIT_8BIT
  #undef PWM_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_8BIT
  #undef PWM_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef PWM_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef R_FDL_START_SEC_CONST
  #undef R_FDL_START_SEC_CONST
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef R_FDL_STOP_SEC_CONST
  #undef R_FDL_STOP_SEC_CONST
  #define STOP_SEC_CONST
#endif

#ifdef R_FDL_START_SEC_PUBLIC_CODE
  #undef R_FDL_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef R_FDL_STOP_SEC_PUBLIC_CODE
  #undef R_FDL_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef R_FDL_START_SEC_VAR
  #undef R_FDL_START_SEC_VAR
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef R_FDL_STOP_SEC_VAR
  #undef R_FDL_STOP_SEC_VAR
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef RAMTST_START_SEC_CONST_16
  #undef RAMTST_START_SEC_CONST_16
  #define START_SEC_CONST_16BIT
#endif

#ifdef RAMTST_STOP_SEC_CONST_16
  #undef RAMTST_STOP_SEC_CONST_16
  #define STOP_SEC_CONST
#endif

#ifdef RAMTST_START_SEC_PRIVATE_CODE
  #undef RAMTST_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef RAMTST_STOP_SEC_PRIVATE_CODE
  #undef RAMTST_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef RAMTST_START_SEC_PUBLIC_CODE
  #undef RAMTST_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef RAMTST_STOP_SEC_PUBLIC_CODE
  #undef RAMTST_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef RAMTST_START_SEC_VAR_INIT_16
  #undef RAMTST_START_SEC_VAR_INIT_16
  #define START_SEC_VAR_INIT_16BIT
#endif

#ifdef RAMTST_STOP_SEC_VAR_INIT_16
  #undef RAMTST_STOP_SEC_VAR_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_INIT_32
  #undef RAMTST_START_SEC_VAR_INIT_32
  #define START_SEC_VAR_INIT_32BIT
#endif

#ifdef RAMTST_STOP_SEC_VAR_INIT_32
  #undef RAMTST_STOP_SEC_VAR_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_INIT_8
  #undef RAMTST_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef RAMTST_STOP_SEC_VAR_INIT_8
  #undef RAMTST_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
  #undef RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_POWER_ON_INIT_8
  #undef RAMTST_START_SEC_VAR_POWER_ON_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef RAMTST_STOP_SEC_VAR_POWER_ON_INIT_8
  #undef RAMTST_STOP_SEC_VAR_POWER_ON_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_APPL_CODE
  #undef SPI_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_APPL_CODE
  #undef SPI_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CODE
  #undef SPI_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE
  #undef SPI_STOP_SEC_CODE
#define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_BUFFER_VAR_INIT_16
  #undef SPI_START_SEC_BUFFER_VAR_INIT_16
  #define START_SEC_VAR_INIT_16BIT
#endif

#ifdef SPI_STOP_SEC_BUFFER_VAR_INIT_16
  #undef SPI_STOP_SEC_BUFFER_VAR_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_BUFFER_VAR_INIT_16BIT
  #undef SPI_START_SEC_BUFFER_VAR_INIT_16BIT
  #define START_SEC_VAR_INIT_16BIT
#endif

#ifdef SPI_STOP_SEC_BUFFER_VAR_INIT_16BIT
  #undef SPI_STOP_SEC_BUFFER_VAR_INIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_BUFFER_VAR_INIT_UNSPECIFIED
  #undef SPI_START_SEC_BUFFER_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_BUFFER_VAR_INIT_UNSPECIFIED
  #undef SPI_STOP_SEC_BUFFER_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_CODE_FAST
  #undef SPI_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef SPI_STOP_SEC_CODE_FAST
  #undef SPI_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONST_UNSPECIFIED
  #undef SPI_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONST_UNSPECIFIED
  #undef SPI_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_PRIVATE_CODE
  #undef SPI_START_SEC_PRIVATE_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_PRIVATE_CODE
  #undef SPI_STOP_SEC_PRIVATE_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_PUBLIC_CODE
  #undef SPI_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_PUBLIC_CODE
  #undef SPI_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef SPI_START_SEC_VAR_INIT_8
  #undef SPI_START_SEC_VAR_INIT_8
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_8
  #undef SPI_STOP_SEC_VAR_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_INIT_8BIT
  #undef SPI_START_SEC_VAR_INIT_8BIT
  #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_8BIT
  #undef SPI_STOP_SEC_VAR_INIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_INIT_UNSPECIFIED
  #undef SPI_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_16
  #undef SPI_START_SEC_VAR_NO_INIT_16
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_16
  #undef SPI_STOP_SEC_VAR_NO_INIT_16
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_8
  #undef SPI_START_SEC_VAR_NO_INIT_8
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_8
  #undef SPI_STOP_SEC_VAR_NO_INIT_8
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_BOOLEAN
  #undef SPI_START_SEC_VAR_NO_INIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #undef SPI_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_16BIT
  #undef SPI_START_SEC_VAR_NOINIT_16BIT
  #define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_16BIT
  #undef SPI_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_8BIT
  #undef SPI_START_SEC_VAR_NOINIT_8BIT
  #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_8BIT
  #undef SPI_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_BOOLEAN
  #undef SPI_START_SEC_VAR_NOINIT_BOOLEAN
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_BOOLEAN
  #undef SPI_STOP_SEC_VAR_NOINIT_BOOLEAN
  #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_APPL_CODE
  #undef WDG_59_DRIVERA_START_SEC_APPL_CODE
  #define START_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_APPL_CODE
  #undef WDG_59_DRIVERA_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_START_SEC_CODE_FAST
  #undef WDG_59_DRIVERA_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_CODE_FAST
  #undef WDG_59_DRIVERA_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_CONFIG_DATA_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
  #undef WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
  #define START_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
  #undef WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_VAR_INIT_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_32
  #undef WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_32
  #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_32
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_32
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef WDG_59_DRIVERA_START_SEC_VAR_UNSPECIFIED
  #undef WDG_59_DRIVERA_START_SEC_VAR_UNSPECIFIED
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef WDG_59_DRIVERA_STOP_SEC_VAR_UNSPECIFIED
  #undef WDG_59_DRIVERA_STOP_SEC_VAR_UNSPECIFIED
  #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  DBG START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef DBG_START_SEC_CODE
  #undef DBG_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef DBG_STOP_SEC_CODE
  #undef DBG_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef DBG_START_SEC_CODE_FAST
  #undef DBG_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST                       /* mapped to default fast code section */
#endif
#ifdef DBG_STOP_SEC_CODE_FAST
  #undef DBG_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef DBG_START_SEC_CONST_8BIT
# undef DBG_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef DBG_STOP_SEC_CONST_8BIT
# undef DBG_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef DBG_START_SEC_CONST_16BIT
# undef DBG_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef DBG_STOP_SEC_CONST_16BIT
# undef DBG_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef DBG_START_SEC_CONST_32BIT
# undef DBG_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef DBG_STOP_SEC_CONST_32BIT
# undef DBG_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef DBG_START_SEC_CONST_UNSPECIFIED
# undef DBG_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DBG_STOP_SEC_CONST_UNSPECIFIED
# undef DBG_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef DBG_START_SEC_VAR_INIT_8BIT
# undef DBG_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT                    /* mapped to default var init 8bit section */
#endif
#ifdef DBG_STOP_SEC_VAR_INIT_8BIT
# undef DBG_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR                               /* default var stop section */
#endif

#ifdef DBG_START_SEC_VAR_INIT_16BIT
# undef DBG_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef DBG_STOP_SEC_VAR_INIT_16BIT
# undef DBG_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_INIT_32BIT
# undef DBG_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef DBG_STOP_SEC_VAR_INIT_32BIT
# undef DBG_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_INIT_UNSPECIFIED
# undef DBG_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DBG_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DBG_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef DBG_START_SEC_VAR_NOINIT_8BIT
# undef DBG_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DBG_STOP_SEC_VAR_NOINIT_8BIT
# undef DBG_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_NOINIT_16BIT
# undef DBG_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef DBG_STOP_SEC_VAR_NOINIT_16BIT
# undef DBG_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_NOINIT_32BIT
# undef DBG_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef DBG_STOP_SEC_VAR_NOINIT_32BIT
# undef DBG_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DBG_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DBG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DBG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef DBG_START_SEC_VAR_ZERO_INIT_8BIT
# undef DBG_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef DBG_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef DBG_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_ZERO_INIT_16BIT
# undef DBG_START_SEC_VAR_ZERO_INIT_16BIT
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef DBG_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef DBG_STOP_SEC_VAR_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_ZERO_INIT_32BIT
# undef DBG_START_SEC_VAR_ZERO_INIT_32BIT
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef DBG_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef DBG_STOP_SEC_VAR_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DBG_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef DBG_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DBG_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  DBG END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  RTM START 
 *********************************************************************************************************************/


/*******  CODE sections **********************************************************************************************/

#ifdef RTM_START_SEC_CODE
  #undef RTM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef RTM_STOP_SEC_CODE
  #undef RTM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR ZERO INIT sections */

#ifdef RTM_START_SEC_VAR_ZERO_INIT_8BIT
# undef RTM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef RTM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef RTM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

#ifdef RTM_START_SEC_VAR_INIT_UNSPECIFIED
# undef RTM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef RTM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef RTM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef RTM_START_SEC_VAR_INIT_UNSPECIFIED_SAFE
# undef RTM_START_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef RTM_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE
# undef RTM_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef RTM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef RTM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef RTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef RTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/*******  CONST sections  **********************************************************************************************/

#ifdef RTM_START_SEC_CONST_UNSPECIFIED
# undef RTM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef RTM_STOP_SEC_CONST_UNSPECIFIED
# undef RTM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  RTM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DLT START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef DLT_START_SEC_CODE
  #undef DLT_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef DLT_STOP_SEC_CODE
  #undef DLT_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef DLT_START_SEC_CODE_FAST
  #undef DLT_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST                       /* mapped to default fast code section */
#endif
#ifdef DLT_STOP_SEC_CODE_FAST
  #undef DLT_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


#ifdef DLTCOM_START_SEC_CODE
  #undef DLTCOM_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef DLTCOM_STOP_SEC_CODE
  #undef DLTCOM_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef DLTCOM_START_SEC_CODE_FAST
  #undef DLTCOM_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST                       /* mapped to default fast code section */
#endif
#ifdef DLTCOM_STOP_SEC_CODE_FAST
  #undef DLTCOM_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef DLT_START_SEC_CONST_8BIT
# undef DLT_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef DLT_STOP_SEC_CONST_8BIT
# undef DLT_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef DLT_START_SEC_CONST_16BIT
# undef DLT_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef DLT_STOP_SEC_CONST_16BIT
# undef DLT_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef DLT_START_SEC_CONST_32BIT
# undef DLT_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef DLT_STOP_SEC_CONST_32BIT
# undef DLT_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef DLT_START_SEC_CONST_UNSPECIFIED
# undef DLT_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DLT_STOP_SEC_CONST_UNSPECIFIED
# undef DLT_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif



#ifdef DLTCOM_START_SEC_CONST_8BIT
# undef DLTCOM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef DLTCOM_STOP_SEC_CONST_8BIT
# undef DLTCOM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef DLTCOM_START_SEC_CONST_16BIT
# undef DLTCOM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef DLTCOM_STOP_SEC_CONST_16BIT
# undef DLTCOM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef DLTCOM_START_SEC_CONST_32BIT
# undef DLTCOM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef DLTCOM_STOP_SEC_CONST_32BIT
# undef DLTCOM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef DLTCOM_START_SEC_CONST_UNSPECIFIED
# undef DLTCOM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DLTCOM_STOP_SEC_CONST_UNSPECIFIED
# undef DLTCOM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif



/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef DLT_START_SEC_VAR_INIT_8BIT
# undef DLT_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT                    /* mapped to default var init 8bit section */
#endif
#ifdef DLT_STOP_SEC_VAR_INIT_8BIT
# undef DLT_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR                               /* default var stop section */
#endif

#ifdef DLT_START_SEC_VAR_INIT_16BIT
# undef DLT_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef DLT_STOP_SEC_VAR_INIT_16BIT
# undef DLT_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_INIT_32BIT
# undef DLT_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef DLT_STOP_SEC_VAR_INIT_32BIT
# undef DLT_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_INIT_UNSPECIFIED
# undef DLT_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DLT_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DLT_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif



#ifdef DLTCOM_START_SEC_VAR_INIT_8BIT
# undef DLTCOM_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT                    /* mapped to default var init 8bit section */
#endif
#ifdef DLTCOM_STOP_SEC_VAR_INIT_8BIT
# undef DLTCOM_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR                               /* default var stop section */
#endif

#ifdef DLTCOM_START_SEC_VAR_INIT_16BIT
# undef DLTCOM_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef DLTCOM_STOP_SEC_VAR_INIT_16BIT
# undef DLTCOM_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef DLTCOM_START_SEC_VAR_INIT_32BIT
# undef DLTCOM_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef DLTCOM_STOP_SEC_VAR_INIT_32BIT
# undef DLTCOM_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef DLTCOM_START_SEC_VAR_INIT_UNSPECIFIED
# undef DLTCOM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DLTCOM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DLTCOM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef DLT_START_SEC_VAR_NOINIT_8BIT
# undef DLT_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DLT_STOP_SEC_VAR_NOINIT_8BIT
# undef DLT_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_NOINIT_16BIT
# undef DLT_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef DLT_STOP_SEC_VAR_NOINIT_16BIT
# undef DLT_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_NOINIT_32BIT
# undef DLT_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef DLT_STOP_SEC_VAR_NOINIT_32BIT
# undef DLT_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DLT_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DLT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DLT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif



#ifdef DLTCOM_START_SEC_VAR_NOINIT_8BIT
# undef DLTCOM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DLTCOM_STOP_SEC_VAR_NOINIT_8BIT
# undef DLTCOM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DLTCOM_START_SEC_VAR_NOINIT_16BIT
# undef DLTCOM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef DLTCOM_STOP_SEC_VAR_NOINIT_16BIT
# undef DLTCOM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef DLTCOM_START_SEC_VAR_NOINIT_32BIT
# undef DLTCOM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef DLTCOM_STOP_SEC_VAR_NOINIT_32BIT
# undef DLTCOM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef DLTCOM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DLTCOM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DLTCOM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DLTCOM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif



/* VAR ZERO INIT sections */

#ifdef DLT_START_SEC_VAR_ZERO_INIT_8BIT
# undef DLT_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef DLT_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef DLT_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_ZERO_INIT_16BIT
# undef DLT_START_SEC_VAR_ZERO_INIT_16BIT
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef DLT_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef DLT_STOP_SEC_VAR_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_ZERO_INIT_32BIT
# undef DLT_START_SEC_VAR_ZERO_INIT_32BIT
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef DLT_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef DLT_STOP_SEC_VAR_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DLT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef DLT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DLT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif



#ifdef DLTCOM_START_SEC_VAR_ZERO_INIT_8BIT
# undef DLTCOM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef DLTCOM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef DLTCOM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DLTCOM_START_SEC_VAR_ZERO_INIT_16BIT
# undef DLTCOM_START_SEC_VAR_ZERO_INIT_16BIT
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef DLTCOM_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef DLTCOM_STOP_SEC_VAR_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef DLTCOM_START_SEC_VAR_ZERO_INIT_32BIT
# undef DLTCOM_START_SEC_VAR_ZERO_INIT_32BIT
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef DLTCOM_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef DLTCOM_STOP_SEC_VAR_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef DLTCOM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DLTCOM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef DLTCOM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DLTCOM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif




/**********************************************************************************************************************
 *  DLT END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANNM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CANNM_START_SEC_CODE
    #undef CANNM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_CODE                              /* mapped to default code section */
#endif
#ifdef CANNM_STOP_SEC_CODE
    #undef CANNM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_CODE                               /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CANNM_START_SEC_CONST_8BIT
    #undef CANNM_START_SEC_CONST_8BIT                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_CONST_8BIT                        /* mapped to default const section */
#endif
#ifdef CANNM_STOP_SEC_CONST_8BIT
    #undef CANNM_STOP_SEC_CONST_8BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

#ifdef CANNM_START_SEC_CONST_UNSPECIFIED
    #undef CANNM_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_CONST_UNSPECIFIED                 /* mapped to default const section */
#endif
#ifdef CANNM_STOP_SEC_CONST_UNSPECIFIED
    #undef CANNM_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

/* Postbuild CFG CONST sections */

#ifdef CANNM_START_SEC_PBCFG
    #undef CANNM_START_SEC_PBCFG                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_CONST_PBCFG                       /* mapped to default postbuild section */
#endif
#ifdef CANNM_STOP_SEC_PBCFG
    #undef CANNM_STOP_SEC_PBCFG                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CANNM_START_SEC_VAR_NOINIT_8BIT
    #undef CANNM_START_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_NOINIT_8BIT                   /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_NOINIT_8BIT
    #undef CANNM_STOP_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef CANNM_START_SEC_VAR_NOINIT_16BIT
    #undef CANNM_START_SEC_VAR_NOINIT_16BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_NOINIT_16BIT                   /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_NOINIT_16BIT
    #undef CANNM_STOP_SEC_VAR_NOINIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef CANNM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef CANNM_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED            /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef CANNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/* VAR INIT sections */
#ifdef CANNM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef CANNM_START_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_INIT_UNSPECIFIED              /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef CANNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef CANNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED         /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef CANNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif


#ifdef CANNM_START_SEC_VAR_ZERO_INIT_8BIT
    #undef CANNM_START_SEC_VAR_ZERO_INIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_ZERO_INIT_8BIT                   /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef CANNM_STOP_SEC_VAR_ZERO_INIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/* VAR PBCFG sections */

#ifdef CANNM_START_SEC_VAR_PBCFG
    #undef CANNM_START_SEC_VAR_PBCFG                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define START_SEC_VAR_PBCFG                         /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_PBCFG
    #undef CANNM_STOP_SEC_VAR_PBCFG                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/**********************************************************************************************************************
 *  CANNM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  NM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef NM_START_SEC_CODE
# undef NM_START_SEC_CODE                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                 /* mapped to default code section */
#endif
#ifdef NM_STOP_SEC_CODE
# undef NM_STOP_SEC_CODE                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                  /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef NM_START_SEC_CONST_8
# undef NM_START_SEC_CONST_8                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8                              /* mapped to default const section */
#endif
#ifdef NM_STOP_SEC_CONST_8
# undef NM_STOP_SEC_CONST_8                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef NM_START_SEC_CONST_16
# undef NM_START_SEC_CONST_16                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16                             /* mapped to default const section */
#endif
#ifdef NM_STOP_SEC_CONST_16
# undef NM_STOP_SEC_CONST_16                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef NM_START_SEC_CONST_UNSPECIFIED
# undef NM_START_SEC_CONST_UNSPECIFIED                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                    /* mapped to default const section */
#endif
#ifdef NM_STOP_SEC_CONST_UNSPECIFIED
# undef NM_STOP_SEC_CONST_UNSPECIFIED                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */

#ifdef NM_START_SEC_VAR_NO_INIT_8
# undef NM_START_SEC_VAR_NO_INIT_8                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_8                        /* mapped to default var section */
#endif
#ifdef NM_STOP_SEC_VAR_NO_INIT_8
# undef NM_STOP_SEC_VAR_NO_INIT_8                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef NM_START_SEC_VAR_NO_INIT_16
# undef NM_START_SEC_VAR_NO_INIT_16                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_16                       /* mapped to default var section */
#endif
#ifdef NM_STOP_SEC_VAR_NO_INIT_16
# undef NM_STOP_SEC_VAR_NO_INIT_16                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef NM_START_SEC_VAR_NO_INIT_32
# undef NM_START_SEC_VAR_NO_INIT_32                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_32                       /* mapped to default var section */
#endif
#ifdef NM_STOP_SEC_VAR_NO_INIT_32
# undef NM_STOP_SEC_VAR_NO_INIT_32                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef NM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef NM_START_SEC_VAR_NO_INIT_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED              /* mapped to default var section */
#endif
#ifdef NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

/* VAR INIT sections */

#ifdef NM_START_SEC_VAR_INIT_8
# undef NM_START_SEC_VAR_INIT_8                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8                           /* mapped to default var section */
#endif
#ifdef NM_STOP_SEC_VAR_INIT_8
# undef NM_STOP_SEC_VAR_INIT_8                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef NM_START_SEC_VAR_INIT_UNSPECIFIED
# undef NM_START_SEC_VAR_INIT_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED                 /* mapped to default var section */
#endif
#ifdef NM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef NM_STOP_SEC_VAR_INIT_UNSPECIFIED                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

/**********************************************************************************************************************
 *  NM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  UDPNM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(UDPNM_START_SEC_CODE)
# undef UDPNM_START_SEC_CODE                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif /* UDPNM_START_SEC_CODE */
#if defined(UDPNM_STOP_SEC_CODE)
# undef UDPNM_STOP_SEC_CODE                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif /* UDPNM_STOP_SEC_CODE */

/*******  CONST sections  ********************************************************************************************/

#if defined(UDPNM_START_SEC_CONST_8BIT)
# undef UDPNM_START_SEC_CONST_8BIT                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif /* UDPNM_START_SEC_CONST_8BIT */
#if defined(UDPNM_STOP_SEC_CONST_8BIT)
# undef UDPNM_STOP_SEC_CONST_8BIT                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif /* UDPNM_STOP_SEC_CONST_8BIT */

#if defined(UDPNM_START_SEC_CONST_16BIT)
# undef UDPNM_START_SEC_CONST_16BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif /* UDPNM_START_SEC_CONST_16BIT */
#if defined(UDPNM_STOP_SEC_CONST_16BIT)
# undef UDPNM_STOP_SEC_CONST_16BIT                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif /* UDPNM_STOP_SEC_CONST_16BIT */

#if defined(UDPNM_START_SEC_CONST_32BIT)
# undef UDPNM_START_SEC_CONST_32BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif /* UDPNM_START_SEC_CONST_32BIT */
#if defined(UDPNM_STOP_SEC_CONST_32BIT)
# undef UDPNM_STOP_SEC_CONST_32BIT                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif /* UDPNM_STOP_SEC_CONST_32BIT */

#if defined(UDPNM_START_SEC_CONST_UNSPECIFIED)
# undef UDPNM_START_SEC_CONST_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif /* UDPNM_START_SEC_CONST_UNSPECIFIED */
#if defined(UDPNM_STOP_SEC_CONST_UNSPECIFIED)
# undef UDPNM_STOP_SEC_CONST_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif /* UDPNM_STOP_SEC_CONST_UNSPECIFIED */

#if defined(UDPNM_START_SEC_PBCFG)
# undef UDPNM_START_SEC_PBCFG                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif /* UDPNM_START_SEC_PBCFG */
#if defined(UDPNM_STOP_SEC_PBCFG)
# undef UDPNM_STOP_SEC_PBCFG                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif /* UDPNM_STOP_SEC_PBCFG */

#if defined(UDPNM_START_SEC_PBCFG_ROOT)
# undef UDPNM_START_SEC_PBCFG_ROOT                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif /* UDPNM_START_SEC_PBCFG_ROOT */
#if defined(UDPNM_STOP_SEC_PBCFG_ROOT)
# undef UDPNM_STOP_SEC_PBCFG_ROOT                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                        
#endif /* UDPNM_STOP_SEC_PBCFG_ROOT */

/*******  VAR sections  **********************************************************************************************/

#if defined(UDPNM_START_SEC_VAR_NOINIT_8BIT)
# undef UDPNM_START_SEC_VAR_NOINIT_8BIT                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif /* UDPNM_START_SEC_VAR_NOINIT_8BIT */
#if defined(UDPNM_STOP_SEC_VAR_NOINIT_8BIT)
# undef UDPNM_STOP_SEC_VAR_NOINIT_8BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_NOINIT_8BIT */

#if defined(UDPNM_START_SEC_VAR_NOINIT_16BIT)
# undef UDPNM_START_SEC_VAR_NOINIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif /* UDPNM_START_SEC_VAR_NOINIT_16BIT */
#if defined(UDPNM_STOP_SEC_VAR_NOINIT_16BIT)
# undef UDPNM_STOP_SEC_VAR_NOINIT_16BIT                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_NOINIT_16BIT */

#if defined(UDPNM_START_SEC_VAR_NOINIT_32BIT)
# undef UDPNM_START_SEC_VAR_NOINIT_32BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif /* UDPNM_START_SEC_VAR_NOINIT_32BIT */
#if defined(UDPNM_STOP_SEC_VAR_NOINIT_32BIT)
# undef UDPNM_STOP_SEC_VAR_NOINIT_32BIT                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_NOINIT_32BIT */

#if defined(UDPNM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef UDPNM_START_SEC_VAR_NOINIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif /* UDPNM_START_SEC_VAR_NOINIT_UNSPECIFIED */
#if defined(UDPNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef UDPNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED */

#if defined(UDPNM_START_SEC_VAR_INIT_8BIT)
# undef UDPNM_START_SEC_VAR_INIT_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif /* UDPNM_START_SEC_VAR_INIT_8BIT */
#if defined(UDPNM_STOP_SEC_VAR_INIT_8BIT)
# undef UDPNM_STOP_SEC_VAR_INIT_8BIT                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_INIT_8BIT */

#if defined(UDPNM_START_SEC_VAR_INIT_16BIT)
# undef UDPNM_START_SEC_VAR_INIT_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif /* UDPNM_START_SEC_VAR_INIT_16BIT */
#if defined(UDPNM_STOP_SEC_VAR_INIT_16BIT)
# undef UDPNM_STOP_SEC_VAR_INIT_16BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_INIT_16BIT */

#if defined(UDPNM_START_SEC_VAR_INIT_32BIT)
# undef UDPNM_START_SEC_VAR_INIT_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif /* UDPNM_START_SEC_VAR_INIT_32BIT */
#if defined(UDPNM_STOP_SEC_VAR_INIT_32BIT)
# undef UDPNM_STOP_SEC_VAR_INIT_32BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_INIT_32BIT */

#if defined(UDPNM_START_SEC_VAR_INIT_UNSPECIFIED)
# undef UDPNM_START_SEC_VAR_INIT_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif /* UDPNM_START_SEC_VAR_INIT_UNSPECIFIED */
#if defined(UDPNM_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef UDPNM_STOP_SEC_VAR_INIT_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_INIT_UNSPECIFIED */

#if defined(UDPNM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef UDPNM_START_SEC_VAR_ZERO_INIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif /* UDPNM_START_SEC_VAR_ZERO_INIT_8BIT */
#if defined(UDPNM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef UDPNM_STOP_SEC_VAR_ZERO_INIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_ZERO_INIT_8BIT */

#if defined(UDPNM_START_SEC_VAR_ZERO_INIT_16BIT)
# undef UDPNM_START_SEC_VAR_ZERO_INIT_16BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif /* UDPNM_START_SEC_VAR_ZERO_INIT_16BIT */
#if defined(UDPNM_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef UDPNM_STOP_SEC_VAR_ZERO_INIT_16BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_ZERO_INIT_16BIT */

#if defined(UDPNM_START_SEC_VAR_ZERO_INIT_32BIT)
# undef UDPNM_START_SEC_VAR_ZERO_INIT_32BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif /* UDPNM_START_SEC_VAR_ZERO_INIT_32BIT */
#if defined(UDPNM_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef UDPNM_STOP_SEC_VAR_ZERO_INIT_32BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_ZERO_INIT_32BIT */

#if defined(UDPNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef UDPNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif /* UDPNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED */
#if defined(UDPNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef UDPNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif /* UDPNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED */

/**********************************************************************************************************************
 *  UDPNM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CSM_START_SEC_CODE
# undef CSM_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef CSM_STOP_SEC_CODE
# undef CSM_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef CSM_START_SEC_APPL_CODE
# undef CSM_START_SEC_APPL_CODE                    /* mapped to default code section */
# define START_SEC_CODE
#endif
#ifdef CSM_STOP_SEC_APPL_CODE
# undef CSM_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CSM_START_SEC_CONST_UNSPECIFIED
# undef CSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_CONST_UNSPECIFIED
# undef CSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CSM_START_SEC_VAR_NOINIT_8BIT
# undef CSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_8BIT
# undef CSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NOINIT_16BIT
# undef CSM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_16BIT
# undef CSM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef CSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef CSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SSA START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SSA_START_SEC_CODE
# undef SSA_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef SSA_STOP_SEC_CODE
# undef SSA_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef SSA_START_SEC_APPL_CODE
# undef SSA_START_SEC_APPL_CODE                    /* mapped to default code section */
# define START_SEC_CODE
#endif
#ifdef SSA_STOP_SEC_APPL_CODE
# undef SSA_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SSA_START_SEC_CONST_UNSPECIFIED
# undef SSA_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SSA_STOP_SEC_CONST_UNSPECIFIED
# undef SSA_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef SSA_START_SEC_VAR_NOINIT_8BIT
# undef SSA_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SSA_STOP_SEC_VAR_NOINIT_8BIT
# undef SSA_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef SSA_START_SEC_VAR_NOINIT_16BIT
# undef SSA_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SSA_STOP_SEC_VAR_NOINIT_16BIT
# undef SSA_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef SSA_START_SEC_VAR_ZERO_INIT_8BIT
# undef SSA_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SSA_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SSA_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef SSA_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SSA_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SSA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SSA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  SSA END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  BSWM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef BSWM_START_SEC_CODE
# undef BSWM_START_SEC_CODE
# define OPEN_BSWM_CODE_SEC_START                                 /* mapped to default code section*/
#endif

#ifdef BSWM_STOP_SEC_CODE
# undef BSWM_STOP_SEC_CODE
# define OPEN_BSWM_CODE_SEC_END                                  /* default code stop section*/
#endif

#ifdef OPEN_BSWM_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_BSWM_CODE_SEC_START
#endif

#ifdef OPEN_BSWM_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_BSWM_CODE_SEC_END
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef BSWM_START_SEC_CONST_8BIT
# undef BSWM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                           /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_8BIT
# undef BSWM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_CONST_16BIT
# undef BSWM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT                          /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_16BIT
# undef BSWM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_CONST_32BIT
# undef BSWM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT                          /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_32BIT
# undef BSWM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_CONST_UNSPECIFIED
# undef BSWM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED                    /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_CONST_UNSPECIFIED
# undef BSWM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#ifdef BSWM_START_SEC_PBCFG
# undef BSWM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG                          /* mapped to default const section */
#endif

#ifdef BSWM_STOP_SEC_PBCFG
# undef BSWM_STOP_SEC_PBCFG
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef BSWM_START_SEC_VAR_NOINIT_8BIT
# undef BSWM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT                      /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_8BIT
# undef BSWM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR                                   /* default var stop section*/
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_16BIT
# undef  BSWM_START_SEC_VAR_NOINIT_16BIT                /* mapped to default var section */
# define START_SEC_VAR_NOINIT_16BIT
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_16BIT
# undef BSWM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_32BIT
# undef  BSWM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT                     /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_32BIT
# undef BSWM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR                                   /* default var stop section*/
#endif

#ifdef BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED               /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef BSWM_START_SEC_VAR_ZERO_INIT_8BIT
# undef BSWM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT                   /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#ifdef BSWM_START_SEC_VAR_PBCFG
# undef BSWM_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG                            /* mapped to default var section */
#endif

#ifdef BSWM_STOP_SEC_VAR_PBCFG
# undef BSWM_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

/**********************************************************************************************************************
 *  BSWM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SYSSERVICE_ASR4ECUM START 
 *********************************************************************************************************************/

/*******  CONST sections  ********************************************************************************************/

#ifdef ECUM_START_SEC_CONST_UNSPECIFIED
# undef ECUM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_CONST_UNSPECIFIED
# undef ECUM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_CONST_8BIT
# undef ECUM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef ECUM_STOP_SEC_CONST_8BIT
# undef ECUM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef ECUM_START_SEC_PBCFG
# undef ECUM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_PBCFG
# undef ECUM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_PBCFG_GLOBALROOT
# undef ECUM_START_SEC_PBCFG_GLOBALROOT
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef ECUM_STOP_SEC_PBCFG_GLOBALROOT
# undef ECUM_STOP_SEC_PBCFG_GLOBALROOT
# define STOP_SEC_CONST
#endif



/*******  VAR sections  **********************************************************************************************/


/* VAR NOINIT sections */

#ifdef ECUM_START_SEC_VAR_NOINIT_8BIT
# undef ECUM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_16BIT
# undef ECUM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_32BIT
# undef ECUM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_32BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef ECUM_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef ECUM_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef ECUM_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  SYSSERVICE_ASR4ECUM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  WDGM START
 *********************************************************************************************************************/

// patch: rmitev: WdgM is not configured yet
//#include "WdgM_OsMemMap.h" 

/*******  CODE sections **********************************************************************************************/

#if defined WDGM_START_SEC_CODE
# undef WDGM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#if defined WDGM_STOP_SEC_CODE
# undef WDGM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#if defined WDGM_START_SEC_CONST_8BIT
# undef WDGM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#if defined WDGM_STOP_SEC_CONST_8BIT
# undef WDGM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_16BIT
# undef WDGM_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined WDGM_STOP_SEC_CONST_16BIT
# undef WDGM_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_32BIT
# undef WDGM_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined WDGM_STOP_SEC_CONST_32BIT
# undef WDGM_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_UNSPECIFIED
# undef WDGM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined WDGM_STOP_SEC_CONST_UNSPECIFIED
# undef WDGM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_NOINIT_8BIT
# undef WDGM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_8BIT
# undef WDGM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_NOINIT_16BIT
# undef WDGM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_16BIT
# undef WDGM_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_NOINIT_32BIT
# undef WDGM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_32BIT
# undef WDGM_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR INIT sections */

#if defined WDGM_START_SEC_VAR_8BIT
# undef WDGM_START_SEC_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined WDGM_STOP_SEC_VAR_8BIT
# undef WDGM_STOP_SEC_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_16BIT
# undef WDGM_START_SEC_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT  
#endif
#if defined WDGM_STOP_SEC_VAR_16BIT
# undef WDGM_STOP_SEC_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_32BIT
# undef WDGM_START_SEC_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined WDGM_STOP_SEC_VAR_32BIT
# undef WDGM_STOP_SEC_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_BOOLEAN
# undef WDGM_START_SEC_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined WDGM_STOP_SEC_VAR_BOOLEAN
# undef WDGM_STOP_SEC_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* Global Shared Variables of the WdgM.
 * If a SafeContext OS is used this section will be defined by the OS.
 * If no SafeContext OS is used this section has to be mapped to a memory area where all SWCs has access
 */
/*#if defined GlobalShared_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef GlobalShared_START_SEC_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_19.6 */
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined GlobalShared_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef GlobalShared_STOP_SEC_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_19.6 */
/*# define STOP_SEC_VAR
#endif*/
/* or the following section (depending on which OS version is used) */
/*#if defined OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_19.6 */
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_19.6 */
/*# define STOP_SEC_VAR
#endif*/
 
/**********************************************************************************************************************
 *  WDGM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef CRC_START_SEC_CODE
    #undef CRC_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef CRC_STOP_SEC_CODE
    #undef CRC_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/
#ifdef CRC_START_SEC_CONST_8
    #undef CRC_START_SEC_CONST_8
    #define START_SEC_CONST_8
#endif
#ifdef CRC_STOP_SEC_CONST_8
    #undef CRC_STOP_SEC_CONST_8
    #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_16
    #undef CRC_START_SEC_CONST_16
    #define START_SEC_CONST_16
#endif
#ifdef CRC_STOP_SEC_CONST_16
    #undef CRC_STOP_SEC_CONST_16
    #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_32
    #undef CRC_START_SEC_CONST_32
    #define START_SEC_CONST_32
#endif
#ifdef CRC_STOP_SEC_CONST_32
    #undef CRC_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

#ifdef CRC_START_SEC_CONST_64
    #undef CRC_START_SEC_CONST_64
    #define START_SEC_CONST_64
#endif
#ifdef CRC_STOP_SEC_CONST_64
    #undef CRC_STOP_SEC_CONST_64
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC END
 *********************************************************************************************************************/

#ifdef DET_START_SEC_CODE
# undef DET_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
# undef DET_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_NOINIT_8BIT
# undef DET_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_8BIT
# undef DET_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_INIT_UNSPECIFIED
# undef DET_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_CONST_UNSPECIFIED
# undef DET_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_CONST_UNSPECIFIED
# undef DET_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif



/**********************************************************************************************************************
 *  SysService_AsrRamTst START
 *********************************************************************************************************************/

#ifdef RAMTST_START_SEC_CODE
  #undef RAMTST_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE
#endif

#ifdef RAMTST_STOP_SEC_CODE
  #undef RAMTST_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE
#endif

#ifdef RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
  #undef RAMTST_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_NO_INIT_8
  #undef RAMTST_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_VAR_NO_INIT_8
#endif

#ifdef RAMTST_STOP_SEC_VAR_NO_INIT_8
  #undef RAMTST_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_NO_INIT_32
  #undef RAMTST_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_VAR_NO_INIT_32
#endif

#ifdef RAMTST_STOP_SEC_VAR_NO_INIT_32
  #undef RAMTST_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef RAMTST_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef RAMTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_CONST_32
  #undef RAMTST_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CONST_32
#endif

#ifdef RAMTST_STOP_SEC_CONST_32
  #undef RAMTST_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CONST
#endif

#ifdef RAMTST_START_SEC_CONST_UNSPECIFIED
  #undef RAMTST_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_CONST_UNSPECIFIED
  #undef RAMTST_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CONST
#endif

#ifdef RAMTST_START_SEC_CONST_PBCFG
  #undef RAMTST_START_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_CONST_PBCFG
  #undef RAMTST_STOP_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CONST
#endif

#ifdef RAMTST_START_SEC_CONST_PBCFG_ROOT
  #undef RAMTST_START_SEC_CONST_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_CONST_PBCFG_ROOT
  #undef RAMTST_STOP_SEC_CONST_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  SysService_AsrRamTst END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SD START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SD_START_SEC_CODE
  #undef SD_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef SD_STOP_SEC_CODE
  #undef SD_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SD_START_SEC_CONST_8BIT
# undef SD_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef SD_STOP_SEC_CONST_8BIT
# undef SD_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef SD_START_SEC_CONST_16BIT
# undef SD_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef SD_STOP_SEC_CONST_16BIT
# undef SD_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef SD_START_SEC_CONST_32BIT
# undef SD_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef SD_STOP_SEC_CONST_32BIT
# undef SD_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef SD_START_SEC_CONST_UNSPECIFIED
# undef SD_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SD_STOP_SEC_CONST_UNSPECIFIED
# undef SD_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef SD_START_SEC_PBCFG
# undef SD_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef SD_STOP_SEC_PBCFG
# undef SD_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SD_START_SEC_VAR_INIT_8BIT
# undef SD_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT                    /* mapped to default var init 8bit section */
#endif
#ifdef SD_STOP_SEC_VAR_INIT_8BIT
# undef SD_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR                               /* default var stop section */
#endif

#ifdef SD_START_SEC_VAR_INIT_16BIT
# undef SD_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SD_STOP_SEC_VAR_INIT_16BIT
# undef SD_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef SD_START_SEC_VAR_INIT_32BIT
# undef SD_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SD_STOP_SEC_VAR_INIT_32BIT
# undef SD_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef SD_START_SEC_VAR_INIT_UNSPECIFIED
# undef SD_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SD_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SD_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SD_START_SEC_VAR_NOINIT_8BIT
# undef SD_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SD_STOP_SEC_VAR_NOINIT_8BIT
# undef SD_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef SD_START_SEC_VAR_NOINIT_16BIT
# undef SD_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SD_STOP_SEC_VAR_NOINIT_16BIT
# undef SD_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef SD_START_SEC_VAR_NOINIT_32BIT
# undef SD_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SD_STOP_SEC_VAR_NOINIT_32BIT
# undef SD_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef SD_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SD_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SD_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SD_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef SD_START_SEC_VAR_PBCFG
# undef SD_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef SD_STOP_SEC_VAR_PBCFG
# undef SD_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SD_START_SEC_VAR_ZERO_INIT_8BIT
# undef SD_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SD_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SD_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef SD_START_SEC_VAR_ZERO_INIT_16BIT
# undef SD_START_SEC_VAR_ZERO_INIT_16BIT
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SD_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SD_STOP_SEC_VAR_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef SD_START_SEC_VAR_ZERO_INIT_32BIT
# undef SD_START_SEC_VAR_ZERO_INIT_32BIT
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SD_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SD_STOP_SEC_VAR_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef SD_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SD_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SD_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SD_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SD END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  STBM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(STBM_START_SEC_CODE)
# undef STBM_START_SEC_CODE
# define START_SEC_CODE          /* mapped to default code section */
#endif
#if defined(STBM_STOP_SEC_CODE)
# undef STBM_STOP_SEC_CODE
# define STOP_SEC_CODE           /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(STBM_START_SEC_CONST_UNSPECIFIED)
# undef STBM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(STBM_STOP_SEC_CONST_UNSPECIFIED)
# undef STBM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(STBM_START_SEC_VAR_NOINIT_32BIT)
# undef STBM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(STBM_STOP_SEC_VAR_NOINIT_32BIT)
# undef STBM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined(STBM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef STBM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(STBM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef STBM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(STBM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef STBM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(STBM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef STBM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  STBM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTSYN START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTSYN_START_SEC_CODE)
# undef CANTSYN_START_SEC_CODE
# define START_SEC_CODE          /* mapped to default code section */
#endif
#if defined(CANTSYN_STOP_SEC_CODE)
# undef CANTSYN_STOP_SEC_CODE
# define STOP_SEC_CODE           /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTSYN_START_SEC_CONST_UNSPECIFIED)
# undef CANTSYN_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTSYN_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTSYN_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#if defined(CANTSYN_START_SEC_CONST_8BIT)
# undef CANTSYN_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#if defined(CANTSYN_STOP_SEC_CONST_8BIT)
# undef CANTSYN_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(CANTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#if defined(CANTSYN_START_SEC_VAR_NOINIT_8BIT)
# undef CANTSYN_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTSYN_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTSYN_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(CANTSYN_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTSYN_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTSYN END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTSYN START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTSYN_START_SEC_CODE
  #undef ETHTSYN_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ETHTSYN_STOP_SEC_CODE
  #undef ETHTSYN_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ETHTSYN_START_SEC_CONST_8BIT
# undef ETHTSYN_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef ETHTSYN_STOP_SEC_CONST_8BIT
# undef ETHTSYN_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef ETHTSYN_START_SEC_CONST_16BIT
# undef ETHTSYN_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHTSYN_STOP_SEC_CONST_16BIT
# undef ETHTSYN_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTSYN_START_SEC_CONST_32BIT
# undef ETHTSYN_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTSYN_STOP_SEC_CONST_32BIT
# undef ETHTSYN_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTSYN_START_SEC_CONST_UNSPECIFIED
# undef ETHTSYN_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef ETHTSYN_START_SEC_VAR_INIT_8BIT
# undef ETHTSYN_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT                    /* mapped to default var init 8bit section */
#endif
#ifdef ETHTSYN_STOP_SEC_VAR_INIT_8BIT
# undef ETHTSYN_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR                               /* default var stop section */
#endif

#ifdef ETHTSYN_START_SEC_VAR_INIT_16BIT
# undef ETHTSYN_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef ETHTSYN_STOP_SEC_VAR_INIT_16BIT
# undef ETHTSYN_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTSYN_START_SEC_VAR_INIT_32BIT
# undef ETHTSYN_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef ETHTSYN_STOP_SEC_VAR_INIT_32BIT
# undef ETHTSYN_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTSYN_START_SEC_VAR_INIT_UNSPECIFIED
# undef ETHTSYN_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef ETHTSYN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ETHTSYN_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef ETHTSYN_START_SEC_VAR_NOINIT_8BIT
# undef ETHTSYN_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTSYN_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTSYN_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTSYN_START_SEC_VAR_NOINIT_16BIT
# undef ETHTSYN_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTSYN_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTSYN_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTSYN_START_SEC_VAR_NOINIT_32BIT
# undef ETHTSYN_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTSYN_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTSYN_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef ETHTSYN_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTSYN_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTSYN_START_SEC_VAR_ZERO_INIT_16BIT
# undef ETHTSYN_START_SEC_VAR_ZERO_INIT_16BIT
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef ETHTSYN_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef ETHTSYN_STOP_SEC_VAR_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined(ETHTSYN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETHTSYN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHTSYN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETHTSYN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTSYN END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SysService_E2eLib START
 *********************************************************************************************************************/


/*******  CODE sections **********************************************************************************************/

#ifdef E2E_START_SEC_CODE
    #undef E2E_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef E2E_STOP_SEC_CODE
    #undef E2E_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  SysService_E2eLib END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  IPBASE START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IPBASE_START_SEC_CODE
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_START_SEC_CODE
#define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef IPBASE_STOP_SEC_CODE
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_STOP_SEC_CODE
#define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef IPBASE_START_SEC_CONST_8BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_START_SEC_CONST_8BIT
#define START_SEC_CONST_8BIT
#endif
#ifdef IPBASE_STOP_SEC_CONST_8BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_STOP_SEC_CONST_8BIT
#define STOP_SEC_CONST
#endif

#ifdef IPBASE_START_SEC_CONST_16BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_START_SEC_CONST_16BIT
#define START_SEC_CONST_16BIT
#endif
#ifdef IPBASE_STOP_SEC_CONST_16BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_STOP_SEC_CONST_16BIT
#define STOP_SEC_CONST
#endif

#ifdef IPBASE_START_SEC_CONST_32BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_START_SEC_CONST_32BIT
#define START_SEC_CONST_32BIT
#endif
#ifdef IPBASE_STOP_SEC_CONST_32BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_STOP_SEC_CONST_32BIT
#define STOP_SEC_CONST
#endif

#ifdef IPBASE_START_SEC_CONST_UNSPECIFIED
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_START_SEC_CONST_UNSPECIFIED
#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef IPBASE_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_STOP_SEC_CONST_UNSPECIFIED
#define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef IPBASE_START_SEC_VAR_NOINIT_8BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_START_SEC_VAR_NOINIT_8BIT
#define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef IPBASE_STOP_SEC_VAR_NOINIT_8BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_STOP_SEC_VAR_NOINIT_8BIT
#define STOP_SEC_VAR
#endif

#ifdef IPBASE_START_SEC_VAR_NOINIT_16BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_START_SEC_VAR_NOINIT_16BIT
#define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef IPBASE_STOP_SEC_VAR_NOINIT_16BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_STOP_SEC_VAR_NOINIT_16BIT
#define STOP_SEC_VAR
#endif

#ifdef IPBASE_START_SEC_VAR_NOINIT_32BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_START_SEC_VAR_NOINIT_32BIT
#define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef IPBASE_STOP_SEC_VAR_NOINIT_32BIT
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_STOP_SEC_VAR_NOINIT_32BIT
#define STOP_SEC_VAR
#endif

#ifdef IPBASE_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_START_SEC_VAR_NOINIT_UNSPECIFIED
#define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef IPBASE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 0841 */ /* MD_MSR_19.6 */
#undef IPBASE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  IPBASE END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANTP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef   CANTP_START_SEC_CODE
# undef  CANTP_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef   CANTP_STOP_SEC_CODE
# undef  CANTP_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE      /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef   CANTP_START_SEC_CONST_UNSPECIFIED
# undef  CANTP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef   CANTP_STOP_SEC_CONST_UNSPECIFIED
# undef  CANTP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTP_START_SEC_CONST_16BIT)
# undef CANTP_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTP_STOP_SEC_CONST_16BIT)
# undef CANTP_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef   CANTP_START_SEC_CONST_8BIT
# undef  CANTP_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#ifdef   CANTP_STOP_SEC_CONST_8BIT
# undef  CANTP_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef   CANTP_START_SEC_PBCFG
# undef  CANTP_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef   CANTP_STOP_SEC_PBCFG
# undef  CANTP_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif



/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef   CANTP_START_SEC_VAR_INIT_8BIT
# undef  CANTP_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_INIT_8BIT
# undef  CANTP_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef   CANTP_START_SEC_VAR_NOINIT_8BIT
# undef  CANTP_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_NOINIT_8BIT
# undef  CANTP_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef  CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef   CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef  CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_PBCFG
# undef  CANTP_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#ifdef   CANTP_STOP_SEC_VAR_PBCFG
# undef  CANTP_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  CANTP END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DOIP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined DOIP_START_SEC_CODE
# undef DOIP_START_SEC_CODE                         /* PRQA S 0841 */
# define START_SEC_CODE                             /* mapped to default code section */
#endif
#if defined DOIP_STOP_SEC_CODE
# undef DOIP_STOP_SEC_CODE                          /* PRQA S 0841 */
# define STOP_SEC_CODE                              /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#if defined DOIP_START_SEC_CONST_8BIT
# undef DOIP_START_SEC_CONST_8BIT                   /* PRQA S 0841 */
# define START_SEC_CONST_8BIT
#endif
#if defined DOIP_STOP_SEC_CONST_8BIT
# undef DOIP_STOP_SEC_CONST_8BIT                    /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined DOIP_START_SEC_CONST_16BIT
# undef DOIP_START_SEC_CONST_16BIT                  /* PRQA S 0841 */
# define START_SEC_CONST_16BIT
#endif
#if defined DOIP_STOP_SEC_CONST_16BIT
# undef DOIP_STOP_SEC_CONST_16BIT                   /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined DOIP_START_SEC_CONST_32BIT
# undef DOIP_START_SEC_CONST_32BIT                  /* PRQA S 0841 */
# define START_SEC_CONST_32BIT
#endif
#if defined DOIP_STOP_SEC_CONST_32BIT
# undef DOIP_STOP_SEC_CONST_32BIT                   /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined DOIP_START_SEC_CONST_UNSPECIFIED
# undef DOIP_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined DOIP_STOP_SEC_CONST_UNSPECIFIED
# undef DOIP_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined DOIP_START_SEC_PBCFG
# undef DOIP_START_SEC_PBCFG                        /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#if defined DOIP_STOP_SEC_PBCFG
# undef DOIP_STOP_SEC_PBCFG                         /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#if defined DOIP_START_SEC_PBCFG_ROOT
# undef DOIP_START_SEC_PBCFG_ROOT                   /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#if defined DOIP_STOP_SEC_PBCFG_ROOT
# undef DOIP_STOP_SEC_PBCFG_ROOT                    /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#if defined DOIP_START_SEC_VAR_NOINIT_8BIT
# undef DOIP_START_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined DOIP_STOP_SEC_VAR_NOINIT_8BIT
# undef DOIP_STOP_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_NOINIT_16BIT
# undef DOIP_START_SEC_VAR_NOINIT_16BIT             /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined DOIP_STOP_SEC_VAR_NOINIT_16BIT
# undef DOIP_STOP_SEC_VAR_NOINIT_16BIT              /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_NOINIT_32BIT
# undef DOIP_START_SEC_VAR_NOINIT_32BIT             /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined DOIP_STOP_SEC_VAR_NOINIT_32BIT
# undef DOIP_STOP_SEC_VAR_NOINIT_32BIT              /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DOIP_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined DOIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DOIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_INIT_8BIT
# undef DOIP_START_SEC_VAR_INIT_8BIT                /* PRQA S 0841 */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined DOIP_STOP_SEC_VAR_INIT_8BIT
# undef DOIP_STOP_SEC_VAR_INIT_8BIT                 /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_INIT_16BIT
# undef DOIP_START_SEC_VAR_INIT_16BIT               /* PRQA S 0841 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined DOIP_STOP_SEC_VAR_INIT_16BIT
# undef DOIP_STOP_SEC_VAR_INIT_16BIT                /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_INIT_32BIT
# undef DOIP_START_SEC_VAR_INIT_32BIT               /* PRQA S 0841 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined DOIP_STOP_SEC_VAR_INIT_32BIT
# undef DOIP_STOP_SEC_VAR_INIT_32BIT                /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_INIT_UNSPECIFIED
# undef DOIP_START_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_ZERO_INIT_8BIT
# undef DOIP_START_SEC_VAR_ZERO_INIT_8BIT           /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined DOIP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef DOIP_STOP_SEC_VAR_ZERO_INIT_8BIT            /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_ZERO_INIT_16BIT
# undef DOIP_START_SEC_VAR_ZERO_INIT_16BIT          /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined DOIP_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef DOIP_STOP_SEC_VAR_ZERO_INIT_16BIT           /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_ZERO_INIT_32BIT
# undef DOIP_START_SEC_VAR_ZERO_INIT_32BIT          /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined DOIP_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef DOIP_STOP_SEC_VAR_ZERO_INIT_32BIT           /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#if defined DOIP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DOIP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined DOIP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DOIP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DOIP END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TCPIP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef TCPIP_START_SEC_CODE
  #undef TCPIP_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef TCPIP_STOP_SEC_CODE
  #undef TCPIP_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef TCPIP_START_SEC_CODE_ISR
  #undef TCPIP_START_SEC_CODE_ISR
  #define START_SEC_CODE_ISR                        /* mapped to default ISR code section */
#endif
#ifdef TCPIP_STOP_SEC_CODE_ISR
  #undef TCPIP_STOP_SEC_CODE_ISR
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef IPV4_START_SEC_CODE
  #undef IPV4_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef IPV4_STOP_SEC_CODE
  #undef IPV4_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef IPV6_START_SEC_CODE
  #undef IPV6_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef IPV6_STOP_SEC_CODE
  #undef IPV6_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef IPV6_START_SEC_CODE_FAST
  #undef IPV6_START_SEC_CODE_FAST
  #define START_SEC_CODE_FAST                       /* mapped to default fast code section */
#endif
#ifdef IPV6_STOP_SEC_CODE_FAST
  #undef IPV6_STOP_SEC_CODE_FAST
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef IPV6_START_SEC_CODE_ISR
  #undef IPV6_START_SEC_CODE_ISR
  #define START_SEC_CODE_ISR                        /* mapped to default ISR code section */
#endif
#ifdef IPV6_STOP_SEC_CODE_ISR
  #undef IPV6_STOP_SEC_CODE_ISR
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef TCPIP_START_SEC_CONST_8BIT
# undef TCPIP_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef TCPIP_STOP_SEC_CONST_8BIT
# undef TCPIP_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef TCPIP_START_SEC_CONST_16BIT
# undef TCPIP_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef TCPIP_STOP_SEC_CONST_16BIT
# undef TCPIP_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef TCPIP_START_SEC_CONST_32BIT
# undef TCPIP_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef TCPIP_STOP_SEC_CONST_32BIT
# undef TCPIP_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef TCPIP_START_SEC_CONST_UNSPECIFIED
# undef TCPIP_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef TCPIP_STOP_SEC_CONST_UNSPECIFIED
# undef TCPIP_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef TCPIP_START_SEC_CONST_BOOLEAN
# undef TCPIP_START_SEC_CONST_BOOLEAN
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef TCPIP_STOP_SEC_CONST_BOOLEAN
# undef TCPIP_STOP_SEC_CONST_BOOLEAN
# define STOP_SEC_CONST
#endif

#ifdef TCPIP_START_SEC_PBCFG
# undef TCPIP_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef TCPIP_STOP_SEC_PBCFG
# undef TCPIP_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef TCPIP_START_SEC_PBCFG_ROOT
# undef TCPIP_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef TCPIP_STOP_SEC_PBCFG_ROOT
# undef TCPIP_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef IPV4_START_SEC_CONST_8BIT
# undef IPV4_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef IPV4_STOP_SEC_CONST_8BIT
# undef IPV4_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef IPV4_START_SEC_CONST_16BIT
# undef IPV4_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef IPV4_STOP_SEC_CONST_16BIT
# undef IPV4_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef IPV4_START_SEC_CONST_32BIT
# undef IPV4_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef IPV4_STOP_SEC_CONST_32BIT
# undef IPV4_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef IPV4_START_SEC_CONST_UNSPECIFIED
# undef IPV4_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef IPV4_STOP_SEC_CONST_UNSPECIFIED
# undef IPV4_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef IPV6_START_SEC_CONST_8BIT
# undef IPV6_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef IPV6_STOP_SEC_CONST_8BIT
# undef IPV6_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef IPV6_START_SEC_CONST_16BIT
# undef IPV6_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef IPV6_STOP_SEC_CONST_16BIT
# undef IPV6_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef IPV6_START_SEC_CONST_32BIT
# undef IPV6_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef IPV6_STOP_SEC_CONST_32BIT
# undef IPV6_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef IPV6_START_SEC_CONST_UNSPECIFIED
# undef IPV6_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef IPV6_STOP_SEC_CONST_UNSPECIFIED
# undef IPV6_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef IPV6_START_SEC_FAST_CONST_8BIT
# undef IPV6_START_SEC_FAST_CONST_8BIT
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef IPV6_STOP_SEC_FAST_CONST_8BIT
# undef IPV6_STOP_SEC_FAST_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef IPV6_START_SEC_FAST_CONST_16BIT
# undef IPV6_START_SEC_FAST_CONST_16BIT
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef IPV6_STOP_SEC_FAST_CONST_16BIT
# undef IPV6_STOP_SEC_FAST_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef IPV6_START_SEC_FAST_CONST_32BIT
# undef IPV6_START_SEC_FAST_CONST_32BIT
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef IPV6_STOP_SEC_FAST_CONST_32BIT
# undef IPV6_STOP_SEC_FAST_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef IPV6_START_SEC_FAST_CONST_UNSPECIFIED
# undef IPV6_START_SEC_FAST_CONST_UNSPECIFIED
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef IPV6_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef IPV6_STOP_SEC_FAST_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef IPV6_START_SEC_PBCFG_ROOT
# undef IPV6_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPV6_STOP_SEC_PBCFG_ROOT
# undef IPV6_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef IPV6_START_SEC_PBCFG
# undef IPV6_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPV6_STOP_SEC_PBCFG
# undef IPV6_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef IPV6_START_SEC_VAR_INIT_8BIT
# undef IPV6_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT                    /* mapped to default var init 8bit section */
#endif
#ifdef IPV6_STOP_SEC_VAR_INIT_8BIT
# undef IPV6_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR                               /* default var stop section */
#endif

#ifdef IPV6_START_SEC_VAR_INIT_16BIT
# undef IPV6_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_INIT_16BIT
# undef IPV6_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_INIT_32BIT
# undef IPV6_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_INIT_32BIT
# undef IPV6_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_INIT_UNSPECIFIED
# undef IPV6_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef IPV6_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef IPV6_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NO INIT sections */

#ifdef TCPIP_START_SEC_VAR_NOINIT_8BIT
# undef TCPIP_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef TCPIP_STOP_SEC_VAR_NOINIT_8BIT
# undef TCPIP_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef TCPIP_START_SEC_VAR_NOINIT_16BIT
# undef TCPIP_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef TCPIP_STOP_SEC_VAR_NOINIT_16BIT
# undef TCPIP_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef TCPIP_START_SEC_VAR_NOINIT_32BIT
# undef TCPIP_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef TCPIP_STOP_SEC_VAR_NOINIT_32BIT
# undef TCPIP_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef TCPIP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef TCPIP_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef TCPIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef TCPIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef TCPIP_START_SEC_VAR_NOINIT_BOOLEAN
# undef TCPIP_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef TCPIP_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef TCPIP_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef IPV4_START_SEC_VAR_NOINIT_8BIT
# undef IPV4_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef IPV4_STOP_SEC_VAR_NOINIT_8BIT
# undef IPV4_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef TCPIP_START_SEC_VAR_BUFFERS
# undef TCPIP_START_SEC_VAR_BUFFERS
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef TCPIP_STOP_SEC_VAR_BUFFERS
# undef TCPIP_STOP_SEC_VAR_BUFFERS
# define STOP_SEC_VAR
#endif

#ifdef IPV4_START_SEC_VAR_NOINIT_16BIT
# undef IPV4_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef IPV4_STOP_SEC_VAR_NOINIT_16BIT
# undef IPV4_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV4_START_SEC_VAR_NOINIT_32BIT
# undef IPV4_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef IPV4_STOP_SEC_VAR_NOINIT_32BIT
# undef IPV4_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV4_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef IPV4_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef IPV4_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef IPV4_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef IPV4_START_SEC_VAR_NOINIT_BOOLEAN
# undef IPV4_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef IPV4_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef IPV4_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_NOINIT_8BIT
# undef IPV6_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_NOINIT_8BIT
# undef IPV6_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_NOINIT_16BIT
# undef IPV6_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_NOINIT_16BIT
# undef IPV6_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_NOINIT_32BIT
# undef IPV6_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_NOINIT_32BIT
# undef IPV6_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef IPV6_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef IPV6_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef IPV6_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef IPV6_START_SEC_VAR_FAST_NOINIT_8BIT
# undef IPV6_START_SEC_VAR_FAST_NOINIT_8BIT
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef IPV6_STOP_SEC_VAR_FAST_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_FAST_NOINIT_16BIT
# undef IPV6_START_SEC_VAR_FAST_NOINIT_16BIT
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef IPV6_STOP_SEC_VAR_FAST_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_FAST_NOINIT_32BIT
# undef IPV6_START_SEC_VAR_FAST_NOINIT_32BIT
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef IPV6_STOP_SEC_VAR_FAST_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef IPV6_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef IPV6_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef TCPIP_START_SEC_VAR_ZERO_INIT_8BIT
# undef TCPIP_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef TCPIP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef TCPIP_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV4_START_SEC_VAR_ZERO_INIT_8BIT
# undef IPV4_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef IPV4_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef IPV4_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_ZERO_INIT_8BIT
# undef IPV6_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef IPV6_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_ZERO_INIT_16BIT
# undef IPV6_START_SEC_VAR_ZERO_INIT_16BIT
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef IPV6_STOP_SEC_VAR_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_ZERO_INIT_32BIT
# undef IPV6_START_SEC_VAR_ZERO_INIT_32BIT
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef IPV6_STOP_SEC_VAR_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef IPV6_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef IPV6_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef IPV6_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */

#ifdef IPV6_START_SEC_VAR_FAST_INIT_8BIT
# undef IPV6_START_SEC_VAR_FAST_INIT_8BIT
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_INIT_8BIT
# undef IPV6_STOP_SEC_VAR_FAST_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_FAST_INIT_16BIT
# undef IPV6_START_SEC_VAR_FAST_INIT_16BIT
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_INIT_16BIT
# undef IPV6_STOP_SEC_VAR_FAST_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_FAST_INIT_32BIT
# undef IPV6_START_SEC_VAR_FAST_INIT_32BIT
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_INIT_32BIT
# undef IPV6_STOP_SEC_VAR_FAST_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef IPV6_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef IPV6_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef IPV6_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef IPV6_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef IPV6_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef IPV6_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef IPV6_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef IPV6_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef IPV6_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef IPV6_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef IPV6_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef IPV6_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef IPV6_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  TCPIP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VSTDLIB START
 *********************************************************************************************************************/

#if defined(VSTDLIB_START_SEC_CODE)
# undef VSTDLIB_START_SEC_CODE                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
#pragma ghs section text = ".bswcode"
#endif
#if defined(VSTDLIB_STOP_SEC_CODE)
# undef VSTDLIB_STOP_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
#pragma ghs section text = default
#endif

/**********************************************************************************************************************
 *  VSTDLIB END
 *********************************************************************************************************************/


/* Package Merger: Stop Section MemMapModuleList */


/* ------------------- provide compatibility to former specifications --------- */

#ifdef START_SEC_CONST_8
    #define START_SEC_CONST_8BIT
    #undef START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_16
    #define START_SEC_CONST_16BIT
    #undef START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_32
    #define START_SEC_CONST_32BIT
    #undef START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_64
    #define START_SEC_CONST_64BIT
    #undef START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_FAST_8
    #define START_SEC_CONST_FAST_8BIT
    #undef START_SEC_CONST_FAST_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_FAST_16
    #define START_SEC_CONST_FAST_16BIT
    #undef START_SEC_CONST_FAST_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_FAST_32
    #define START_SEC_CONST_FAST_32BIT
    #undef START_SEC_CONST_FAST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_CONST_FAST_64
    #define START_SEC_CONST_FAST_64BIT
    #undef START_SEC_CONST_FAST_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_INIT_8
    #define START_SEC_VAR_INIT_8BIT
    #undef START_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_INIT_16
    #define START_SEC_VAR_INIT_16BIT
    #undef START_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_INIT_32
    #define START_SEC_VAR_INIT_32BIT
    #undef START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_INIT_64
    #define START_SEC_VAR_INIT_64BIT
    #undef START_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NO_INIT_8
    #define START_SEC_VAR_NOINIT_8BIT
    #undef START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NO_INIT_16
    #define START_SEC_VAR_NOINIT_16BIT
    #undef START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NO_INIT_32
    #define START_SEC_VAR_NOINIT_32BIT
    #undef START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NO_INIT_64
    #define START_SEC_VAR_NOINIT_64BIT
    #undef START_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_ZERO_INIT_8BIT
    #undef START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_ZERO_INIT_16BIT
    #undef START_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_ZERO_INIT_32BIT
    #undef START_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_CLEARED_64
    #define START_SEC_VAR_ZERO_INIT_64BIT
    #undef START_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_INIT_8
    #define START_SEC_VAR_FAST_INIT_8BIT
    #undef START_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_INIT_16
    #define START_SEC_VAR_FAST_INIT_16BIT
    #undef START_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_INIT_32
    #define START_SEC_VAR_FAST_INIT_32BIT
    #undef START_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_INIT_64
    #define START_SEC_VAR_FAST_INIT_64BIT
    #undef START_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_NO_INIT_8
    #define START_SEC_VAR_FAST_NOINIT_8BIT
    #undef START_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_NO_INIT_16
    #define START_SEC_VAR_FAST_NOINIT_16BIT
    #undef START_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_NO_INIT_32
    #define START_SEC_VAR_FAST_NOINIT_32BIT
    #undef START_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_NO_INIT_64
    #define START_SEC_VAR_FAST_NOINIT_64BIT
    #undef START_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_CLEARED_8
    #define START_SEC_VAR_FAST_ZERO_INIT_8BIT
    #undef START_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_CLEARED_16
    #define START_SEC_VAR_FAST_ZERO_INIT_16BIT
    #undef START_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_CLEARED_32
    #define START_SEC_VAR_FAST_ZERO_INIT_32BIT
    #undef START_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_CLEARED_64
    #define START_SEC_VAR_FAST_ZERO_INIT_64BIT
    #undef START_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef START_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_INIT_8
    #define START_SEC_VAR_NOCACHE_INIT_8BIT
    #undef START_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_INIT_16
    #define START_SEC_VAR_NOCACHE_INIT_16BIT
    #undef START_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_INIT_32
    #define START_SEC_VAR_NOCACHE_INIT_32BIT
    #undef START_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_INIT_64
    #define START_SEC_VAR_NOCACHE_INIT_64BIT
    #undef START_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_NO_INIT_8
    #define START_SEC_VAR_NOCACHE_NOINIT_8BIT
    #undef START_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_NO_INIT_16
    #define START_SEC_VAR_NOCACHE_NOINIT_16BIT
    #undef START_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_NO_INIT_32
    #define START_SEC_VAR_NOCACHE_NOINIT_32BIT
    #undef START_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_NO_INIT_64
    #define START_SEC_VAR_NOCACHE_NOINIT_64BIT
    #undef START_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
    #undef START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_CLEARED_8
    #define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
    #undef START_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_CLEARED_16
    #define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
    #undef START_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_CLEARED_32
    #define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
    #undef START_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_CLEARED_64
    #define START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
    #undef START_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
    #undef START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

/*------------------------------GLOBAL-SECTIONS-----------------------------*/
/* Check code sections */
#if ( (defined CODE_SEC_OPEN)                            && \
     ((defined START_SEC_CODE                          ) || \
      (defined START_SEC_CODE_FAST                     ) || \
      (defined START_SEC_CODE_ISR                      )    \
      ))
    #error "MemMap.h: Close the former code segment before opening a new one."
#endif

/* Check const sections */
#if ( (defined CONST_SEC_OPEN)                           && \
     ((defined START_SEC_CONST_8BIT                    ) || \
      (defined START_SEC_CONST_16BIT                   ) || \
      (defined START_SEC_CONST_32BIT                   ) || \
      (defined START_SEC_CONST_64BIT                   ) || \
      (defined START_SEC_CONST_UNSPECIFIED             ) || \
      (defined START_SEC_CONST_FAST_8BIT               ) || \
      (defined START_SEC_CONST_FAST_16BIT              ) || \
      (defined START_SEC_CONST_FAST_32BIT              ) || \
      (defined START_SEC_CONST_FAST_64BIT              ) || \
      (defined START_SEC_CONST_FAST_UNSPECIFIED        ) || \
      (defined START_SEC_CONST_PBCFG                   ) || \
      (defined START_SEC_PBCFG_GLOBALROOT              )    \
      ))
    #error "MemMap.h: Close the former const segment before opening a new one."
#endif

/* Check data sections */
#if ( (defined VAR_SEC_OPEN)                             && \
     ((defined START_SEC_VAR_INIT_8BIT                 ) || \
      (defined START_SEC_VAR_INIT_16BIT                ) || \
      (defined START_SEC_VAR_INIT_32BIT                ) || \
      (defined START_SEC_VAR_INIT_64BIT                ) || \
      (defined START_SEC_VAR_INIT_UNSPECIFIED          ) || \
      (defined START_SEC_VAR_NOINIT_8BIT               ) || \
      (defined START_SEC_VAR_NOINIT_16BIT              ) || \
      (defined START_SEC_VAR_NOINIT_32BIT              ) || \
      (defined START_SEC_VAR_NOINIT_64BIT              ) || \
      (defined START_SEC_VAR_NOINIT_UNSPECIFIED        ) || \
      (defined START_SEC_VAR_PBCFG                     ) || \
      (defined START_SEC_VAR_ZERO_INIT_8BIT            ) || \
      (defined START_SEC_VAR_ZERO_INIT_16BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_32BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_64BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_INIT_8BIT            ) || \
      (defined START_SEC_VAR_FAST_INIT_16BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_32BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_64BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_NOINIT_8BIT          ) || \
      (defined START_SEC_VAR_FAST_NOINIT_16BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_32BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_64BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT       ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_64BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED) || \
      (defined START_SEC_VAR_NOCACHE_INIT_8BIT         ) || \
      (defined START_SEC_VAR_NOCACHE_INIT_16BIT        ) || \
      (defined START_SEC_VAR_NOCACHE_INIT_32BIT        ) || \
      (defined START_SEC_VAR_NOCACHE_INIT_64BIT        ) || \
      (defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED  ) || \
      (defined START_SEC_VAR_NOCACHE_NOINIT_8BIT       ) || \
      (defined START_SEC_VAR_NOCACHE_NOINIT_16BIT      ) || \
      (defined START_SEC_VAR_NOCACHE_NOINIT_32BIT      ) || \
      (defined START_SEC_VAR_NOCACHE_NOINIT_64BIT      ) || \
      (defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED) || \
      (defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT    ) || \
      (defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT   ) || \
      (defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT   ) || \
      (defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT   ) || \
      (defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)    \
      ))
    #error "MemMap.h: Close the former variable segment before opening a new one."
#endif

/* ASSERTLIB Code Section */
#ifdef ASSERTLIB_CODE_SEC_START
#define OPEN_ASSERTLIB_CODE_SEC_START
#undef ASSERTLIB_CODE_SEC_START
#endif

#ifdef ASSERTLIB_CODE_SEC_END
#define OPEN_ASSERTLIB_CODE_SEC_END
#undef ASSERTLIB_CODE_SEC_END
#endif

#ifdef OPEN_ASSERTLIB_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_ASSERTLIB_CODE_SEC_START
#endif

#ifdef OPEN_ASSERTLIB_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_ASSERTLIB_CODE_SEC_END
#endif

/* BSWM Code Section */
#ifdef BSWM_CODE_SEC_START
#define OPEN_BSWM_CODE_SEC_START
#undef BSWM_CODE_SEC_START
#endif

#ifdef BSWM_CODE_SEC_END
#define OPEN_BSWM_CODE_SEC_END
#undef BSWM_CODE_SEC_END
#endif

#ifdef OPEN_BSWM_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_BSWM_CODE_SEC_START
#endif

#ifdef OPEN_BSWM_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_BSWM_CODE_SEC_END
#endif

/* CAN Code Section */
#ifdef CAN_CODE_SEC_START
#define OPEN_CAN_CODE_SEC_START
#undef CAN_CODE_SEC_START
#endif

#ifdef CAN_CODE_SEC_END
#define OPEN_CAN_CODE_SEC_END
#undef CAN_CODE_SEC_END
#endif

#ifdef OPEN_CAN_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_CAN_CODE_SEC_START
#endif

#ifdef OPEN_CAN_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_CAN_CODE_SEC_END
#endif

/* CMBLIB Code Section */
#ifdef CMBLIB_CODE_SEC_START
#define OPEN_CMBLIB_CODE_SEC_START
#undef CMBLIB_CODE_SEC_START
#endif

#ifdef CMBLIB_CODE_SEC_END
#define OPEN_CMBLIB_CODE_SEC_END
#undef CMBLIB_CODE_SEC_END
#endif

#ifdef OPEN_CMBLIB_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_CMBLIB_CODE_SEC_START
#endif

#ifdef OPEN_CMBLIB_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_CMBLIB_CODE_SEC_END
#endif


/* COMM Code SEction */
#ifdef COMM_CODE_SEC_START
#define OPEN_COMM_CODE_SEC_START
#undef COMM_CODE_SEC_START
#endif

#ifdef COMM_CODE_SEC_END
#define OPEN_COMM_CODE_SEC_END
#undef COMM_CODE_SEC_END
#endif

#ifdef OPEN_COMM_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_COMM_CODE_SEC_START
#endif

#ifdef OPEN_COMM_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_COMM_CODE_SEC_END
#endif

/* CRCLIB Code Section */
#ifdef CRCLIB_CODE_SEC_START
#define OPEN_CRCLIB_CODE_SEC_START
#undef CRCLIB_CODE_SEC_START
#endif

#ifdef CRCLIB_CODE_SEC_END
#define OPEN_CRCLIB_CODE_SEC_END
#undef CRCLIB_CODE_SEC_END
#endif

#ifdef OPEN_CRCLIB_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_CRCLIB_CODE_SEC_START
#endif

#ifdef OPEN_CRCLIB_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_CRCLIB_CODE_SEC_END
#endif

/* ECUMGR Code Section */
#ifdef ECUM_CODE_SEC_START
#define OPEN_ECUMGR_CODE_SEC_START
#undef ECUM_CODE_SEC_START
#endif

#ifdef ECUM_CODE_SEC_END
#define OPEN_ECUMGR_CODE_SEC_END
#undef ECUM_CODE_SEC_END
#endif
/* EcuM #2*/
#ifdef ECUM_START_SEC_CODE
#define OPEN_ECUMGR_CODE_SEC_START
#undef ECUM_START_SEC_CODE
#endif

#ifdef ECUM_STOP_SEC_CODE
#define OPEN_ECUMGR_CODE_SEC_END
#undef ECUM_STOP_SEC_CODE
#endif

#ifdef OPEN_ECUMGR_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_ECUMGR_CODE_SEC_START
#endif

#ifdef OPEN_ECUMGR_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_ECUMGR_CODE_SEC_END
#endif

/* MATHLIB Code Section */
#ifdef MATHLIB_CODE_SEC_START
#define OPEN_MATHLIB_CODE_SEC_START
#undef MATHLIB_CODE_SEC_START
#endif

#ifdef MATHLIB_CODE_SEC_END
#define OPEN_MATHLIB_CODE_SEC_END
#undef MATHLIB_CODE_SEC_END
#endif

#ifdef OPEN_MATHLIB_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_MATHLIB_CODE_SEC_START
#endif

#ifdef OPEN_MATHLIB_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_MATHLIB_CODE_SEC_END
#endif

/* MEMLIB Code Section */
#ifdef MEMLIB_CODE_SEC_START
#define OPEN_MEMLIB_CODE_SEC_START
#undef MEMLIB_CODE_SEC_START
#endif

#ifdef MEMLIB_CODE_SEC_END
#define OPEN_MEMLIB_CODE_SEC_END
#undef MEMLIB_CODE_SEC_END
#endif

#ifdef OPEN_MEMLIB_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_MEMLIB_CODE_SEC_START
#endif

#ifdef OPEN_MEMLIB_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_MEMLIB_CODE_SEC_END
#endif

/* TMEXT Code Section */
#ifdef TMEXT_CODE_SEC_START
#define OPEN_TMEXT_CODE_SEC_START
#undef TMEXT_CODE_SEC_START
#endif

#ifdef TMEXT_CODE_SEC_END
#define OPEN_TMEXT_CODE_SEC_END
#undef TMEXT_CODE_SEC_END
#endif

#ifdef OPEN_TMEXT_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_TMEXT_CODE_SEC_START
#endif

#ifdef OPEN_TMEXT_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_TMEXT_CODE_SEC_END
#endif

/* WDGMGR Code Section */
#ifdef WDGMGR_CODE_SEC_START
#define OPEN_WDGMGR_CODE_SEC_START
#undef WDGMGR_CODE_SEC_START
#endif

#ifdef WDGMGR_CODE_SEC_END
#define OPEN_WDGMGR_CODE_SEC_END
#undef WDGMGR_CODE_SEC_END
#endif

#ifdef OPEN_WDGMGR_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_WDGMGR_CODE_SEC_START
#endif

#ifdef OPEN_WDGMGR_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_WDGMGR_CODE_SEC_END
#endif

/* STUBS Code Section */
#ifdef STUBS_CODE_SEC_START
#define OPEN_STUBS_CODE_SEC_START
#undef STUBS_CODE_SEC_START
#endif

#ifdef STUBS_CODE_SEC_END
#define OPEN_STUBS_CODE_SEC_END
#undef STUBS_CODE_SEC_END
#endif

#ifdef OPEN_STUBS_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_STUBS_CODE_SEC_START
#endif

#ifdef OPEN_STUBS_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_STUBS_CODE_SEC_END
#endif

/* SWCGEN Code Section */
#ifdef SWCGEN_CODE_SEC_START
#define OPEN_SWCGEN_CODE_SEC_START
#undef SWCGEN_CODE_SEC_START
#endif

#ifdef SWCGEN_CODE_SEC_END
#define OPEN_SWCGEN_CODE_SEC_END
#undef SWCGEN_CODE_SEC_END
#endif

#ifdef OPEN_SWCGEN_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_SWCGEN_CODE_SEC_START
#endif

#ifdef OPEN_SWCGEN_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_SWCGEN_CODE_SEC_END
#endif


/* ECUMEXT Code Section */
#ifdef ECUMEXT_CODE_SEC_START
#define OPEN_ECUMEXT_CODE_SEC_START
#undef ECUMEXT_CODE_SEC_START
#endif

#ifdef ECUMEXT_CODE_SEC_END
#define OPEN_ECUMEXT_CODE_SEC_END
#undef ECUMEXT_CODE_SEC_END
#endif

#ifdef OPEN_ECUMEXT_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_ECUMEXT_CODE_SEC_START
#endif

#ifdef OPEN_ECUMEXT_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_ECUMEXT_CODE_SEC_END
#endif

/* IOHWABEXT Code Section */
#ifdef IOHWABEXT_START_SEC_CODE
#define OPEN_IOHWABMEXT_CODE_SEC_START
#undef IOHWABEXT_START_SEC_CODE
#endif

#ifdef IOHWABEXT_STOP_SEC_CODE
#define OPEN_IOHWABMEXT_CODE_SEC_END
#undef IOHWABEXT_STOP_SEC_CODE
#endif

#ifdef OPEN_IOHWABMEXT_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_IOHWABMEXT_CODE_SEC_START
#endif

#ifdef OPEN_IOHWABMEXT_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_IOHWABMEXT_CODE_SEC_END
#endif

/* MCUMEXT Code Section */
#ifdef MCUMEXT_CODE_SEC_START
#define OPEN_MCUMEXT_CODE_SEC_START
#undef MCUMEXT_CODE_SEC_START
#endif

#ifdef MCUMEXT_CODE_SEC_END
#define OPEN_MCUMEXT_CODE_SEC_END
#undef MCUMEXT_CODE_SEC_END
#endif

#ifdef OPEN_MCUMEXT_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_MCUMEXT_CODE_SEC_START
#endif

#ifdef OPEN_MCUMEXT_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_MCUMEXT_CODE_SEC_END
#endif

/* UCL Code Section */
#ifdef UCL_CODE_SEC_START
#define OPEN_UCL_CODE_SEC_START
#undef UCL_CODE_SEC_START
#endif

#ifdef UCL_CODE_SEC_END
#define OPEN_UCL_CODE_SEC_END
#undef UCL_CODE_SEC_END
#endif

#ifdef OPEN_UCL_CODE_SEC_START
#pragma ghs section text = ".bswcode"
#undef OPEN_UCL_CODE_SEC_START
#endif

#ifdef OPEN_UCL_CODE_SEC_END
#pragma ghs section text = default
#undef OPEN_UCL_CODE_SEC_END
#endif


/* NvM Stack sections - Vasu*/
#ifdef NVM_START_SEC_CODE
    #undef NVM_START_SEC_CODE
    #pragma ghs section text = ".bswcode"
#endif

#ifdef MEMIF_START_SEC_CODE
    #undef MEMIF_START_SEC_CODE
    #pragma ghs section text = ".bswcode"
#endif

#ifdef FEE_START_SEC_CODE
    #undef FEE_START_SEC_CODE
    #pragma ghs section text = ".bswcode"
#endif

#ifdef EA_START_SEC_CODE
    #undef EA_START_SEC_CODE
    #pragma ghs section text = ".bswcode"
#endif

#ifdef EEPDRV_START_SEC_CODE
    #undef EEPDRV_START_SEC_CODE
    #pragma ghs section text = ".bswcode"
#endif

#ifdef NVM_STOP_SEC_CODE
    #undef NVM_STOP_SEC_CODE
    #pragma ghs section text = default
#endif

#ifdef MEMIF_STOP_SEC_CODE
    #undef MEMIF_STOP_SEC_CODE
    #pragma ghs section text = default
#endif

#ifdef FEE_STOP_SEC_CODE
    #undef FEE_STOP_SEC_CODE
    #pragma ghs section text = default
#endif

#ifdef EA_STOP_SEC_CODE
    #undef EA_STOP_SEC_CODE
    #pragma ghs section text = default
#endif

#ifdef EEPDRV_STOP_SEC_CODE
    #undef EEPDRV_STOP_SEC_CODE
    #pragma ghs section text = default
#endif
/*
#ifdef NVM_START_SEC_DATA
    #undef NVM_START_SEC_DATA
    #pragma ghs section bss =".bswdata"
#endif

#ifdef MEMIF_START_SEC_DATA
    #undef MEMIF_START_SEC_DATA
    #pragma ghs section bss =".bswdata"
#endif

#ifdef FEE_START_SEC_DATA
    #undef FEE_START_SEC_DATA
    #pragma ghs section bss =".bswdata"
#endif

#ifdef EA_START_SEC_DATA
    #undef EA_START_SEC_DATA
    #pragma ghs section bss =".bswdata"
#endif

#ifdef EEPDRV_START_SEC_DATA
    #undef EEPDRV_START_SEC_DATA
    #pragma ghs section bss =".bswdata"
#endif

#ifdef NVM_STOP_SEC_DATA
    #undef NVM_STOP_SEC_DATA
    #pragma ghs section bss = default
#endif

#ifdef MEMIF_STOP_SEC_DATA
    #undef MEMIF_STOP_SEC_DATA
    #pragma ghs section bss = default
#endif

#ifdef FEE_STOP_SEC_DATA
    #undef FEE_STOP_SEC_DATA
    #pragma ghs section bss = default
#endif

#ifdef EA_STOP_SEC_DATA
    #undef EA_STOP_SEC_DATA
    #pragma ghs section bss = default
#endif

#ifdef EEPDRV_STOP_SEC_DATA
    #undef EEPDRV_STOP_SEC_DATA
    #pragma ghs section bss = default
#endif
*/
#ifdef NVM_START_SEC_CONST
    #undef NVM_START_SEC_CONST
    #pragma ghs section rodata = ".bswconst"
#endif

#ifdef MEMIF_START_SEC_CONST
    #undef MEMIF_START_SEC_CONST
    #pragma ghs section rodata = ".bswconst"
#endif

#ifdef EA_START_SEC_CONST
    #undef EA_START_SEC_CONST
    #pragma ghs section rodata = ".bswconst"
#endif

#ifdef EEPDRV_START_SEC_CONST
    #undef EEPDRV_START_SEC_CONST
    #pragma ghs section rodata = ".bswconst"
#endif

#ifdef NVM_STOP_SEC_CONST
    #undef NVM_STOP_SEC_CONST
    #pragma ghs section rodata = default
#endif

#ifdef MEMIF_STOP_SEC_CONST
    #undef MEMIF_STOP_SEC_CONST
    #pragma ghs section rodata = default
#endif

#ifdef EA_STOP_SEC_CONST
    #undef EA_STOP_SEC_CONST
    #pragma ghs section rodata = default
#endif

#ifdef EEPDRV_STOP_SEC_CONST
    #undef EEPDRV_STOP_SEC_CONST
    #pragma ghs section rodata = default
#endif
#ifdef MEMMAP_ERROR
    //#error "MemMap.h, wrong pragma command"
#endif

/* Nvm #2*/
#ifdef NVM_CODE_SEC_START
    #undef NVM_CODE_SEC_START
    #pragma ghs section text = ".bswcode"
#endif

#ifdef MEMIF_CODE_SEC_START
    #undef MEMIF_CODE_SEC_START
    #pragma ghs section text = ".bswcode"
#endif

#ifdef FEE_CODE_SEC_START
    #undef FEE_CODE_SEC_START
    #pragma ghs section text = ".bswcode"
#endif

#ifdef EA_CODE_SEC_START
    #undef EA_CODE_SEC_START
    #pragma ghs section text = ".bswcode"
#endif

#ifdef EEPDRV_CODE_SEC_START
    #undef EEPDRV_CODE_SEC_START
    #pragma ghs section text = ".bswcode"
#endif

#ifdef NVM_CODE_SEC_END
    #undef NVM_CODE_SEC_END
    #pragma ghs section text = default
#endif

#ifdef MEMIF_CODE_SEC_END
    #undef MEMIF_CODE_SEC_END
    #pragma ghs section text = default
#endif

#ifdef FEE_CODE_SEC_END
    #undef FEE_CODE_SEC_END
    #pragma ghs section text = default
#endif

#ifdef EA_CODE_SEC_END
    #undef EA_CODE_SEC_END
    #pragma ghs section text = default
#endif

#ifdef EEPDRV_CODE_SEC_END
    #undef EEPDRV_CODE_SEC_END
    #pragma ghs section text = default
#endif
/*
#ifdef NVM_DATA_SEC_START
    #undef NVM_DATA_SEC_START
    #pragma ghs section bss =".bswdata"
#endif

#ifdef MEMIF_DATA_SEC_START
    #undef MEMIF_DATA_SEC_START
    #pragma ghs section bss =".bswdata"
#endif

#ifdef FEE_DATA_SEC_START
    #undef FEE_DATA_SEC_START
    #pragma ghs section bss =".bswdata"
#endif

#ifdef EA_DATA_SEC_START
    #undef EA_DATA_SEC_START
    #pragma ghs section bss =".bswdata"
#endif

#ifdef EEPDRV_DATA_SEC_START
    #undef EEPDRV_DATA_SEC_START
    #pragma ghs section bss =".bswdata"
#endif

#ifdef NVM_DATA_SEC_END
    #undef NVM_DATA_SEC_END
    #pragma ghs section bss = default
#endif

#ifdef MEMIF_DATA_SEC_END
    #undef MEMIF_DATA_SEC_END
    #pragma ghs section bss = default
#endif

#ifdef FEE_DATA_SEC_END
    #undef FEE_DATA_SEC_END
    #pragma ghs section bss = default
#endif

#ifdef EA_DATA_SEC_END
    #undef EA_DATA_SEC_END
    #pragma ghs section bss = default
#endif

#ifdef EEPDRV_DATA_SEC_END
    #undef EEPDRV_DATA_SEC_END
    #pragma ghs section bss = default
#endif
*/
#ifdef NVM_CONST_SEC_START
    #undef NVM_CONST_SEC_START
    #pragma ghs section rodata = ".bswconst"
#endif

#ifdef MEMIF_CONST_SEC_START
    #undef MEMIF_CONST_SEC_START
    #pragma ghs section rodata = ".bswconst"
#endif

#ifdef EA_CONST_SEC_START
    #undef EA_CONST_SEC_START
    #pragma ghs section rodata = ".bswconst"
#endif

#ifdef EEPDRV_CONST_SEC_START
    #undef EEPDRV_CONST_SEC_START
    #pragma ghs section rodata = ".bswconst"
#endif

#ifdef NVM_CONST_SEC_END
    #undef NVM_CONST_SEC_END
    #pragma ghs section rodata = default
#endif

#ifdef MEMIF_CONST_SEC_END
    #undef MEMIF_CONST_SEC_END
    #pragma ghs section rodata = default
#endif

#ifdef EA_CONST_SEC_END
    #undef EA_CONST_SEC_END
    #pragma ghs section rodata = default
#endif

#ifdef EEPDRV_CONST_SEC_END
    #undef EEPDRV_CONST_SEC_END
    #pragma ghs section rodata = default
#endif
#ifdef MEMMAP_ERROR
    //#error "MemMap.h, wrong pragma command"
#endif

/* Code section */
#ifdef START_SEC_CODE                          
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CODE_FAST                     
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_FAST                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CODE_ISR                      
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_ISR                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif




/* Const section */
#ifdef START_SEC_CONST_8BIT                    
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_8BIT                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_16BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_16BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_32BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_32BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_64BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_64BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_UNSPECIFIED             
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_FAST_8BIT               
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_8BIT                /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_FAST_16BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_16BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_FAST_32BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_32BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_FAST_64BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_64BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_FAST_UNSPECIFIED        
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_CONST_PBCFG                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_PBCFG                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_PBCFG_GLOBALROOT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_PBCFG_GLOBALROOT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif




/* Var section */
#ifdef START_SEC_VAR_INIT_8BIT                 
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_INIT_16BIT                
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_INIT_32BIT                
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_INIT_64BIT                
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_64BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_INIT_UNSPECIFIED          
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_INIT_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOINIT_8BIT               
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_8BIT                /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOINIT_16BIT              
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOINIT_32BIT              
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_32BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOINIT_64BIT              
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_64BIT               /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOINIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_PBCFG                     
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_ZERO_INIT_8BIT            
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_ZERO_INIT_16BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_16BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_ZERO_INIT_32BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_32BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_ZERO_INIT_64BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_64BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED     
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_INIT_8BIT            
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_INIT_16BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_16BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_INIT_32BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_32BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_INIT_64BIT           
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_64BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_INIT_UNSPECIFIED     
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_INIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_8BIT          
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_16BIT         
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_16BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_32BIT         
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_32BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_64BIT         
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_64BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_8BIT       
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_8BIT        /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_16BIT      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_16BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_32BIT      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_32BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_64BIT      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_64BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_INIT_8BIT         
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_INIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_INIT_16BIT        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_INIT_16BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_INIT_32BIT        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_INIT_32BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_INIT_64BIT        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_INIT_64BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED  
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_NOINIT_8BIT       
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_NOINIT_8BIT        /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_NOINIT_16BIT      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_NOINIT_16BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_NOINIT_32BIT      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_NOINIT_32BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_NOINIT_64BIT      
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_NOINIT_64BIT       /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT    
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT     /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT   
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT   
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT   
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT    /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif



/*------------------------------GENERAL-STOP-SECTIONS-------------------------------*/

/*default segment for Code*/
#ifdef STOP_SEC_CODE
    #undef CODE_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST
    #undef CONST_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_CONST /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

/*default segment for Datas*/
#ifdef STOP_SEC_VAR
    #undef VAR_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
/*    #pragma */
    #undef STOP_SEC_VAR /* PRQA S 0841 */ /* MD_MSR_19.6 */
    #undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#include "Os_MemMap.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/

/* PRQA L:MEMMAP_0841_TAG */

