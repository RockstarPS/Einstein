/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Compiler_Cfg.h
 *        Config:  JLR_RICM_VIP.dpa
 *   ECU-Project:  IGMB
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  RTE Compiler Abstraction header file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_COMPILER_CFG_H
# define _RTE_COMPILER_CFG_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * RTE specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CODE
 *********************************************************************************************************************/

/* used for code */
# define RTE_CODE

/* used for all global or static variables that are not initialized by the startup code of the compiler */
# define RTE_VAR_NOINIT

/* used for global or static variables that are initialized with zero by the startup code of the compiler or in Rte_InitMemory */
# define RTE_VAR_ZERO_INIT

/* used for global or static variables that are initialized by the startup code of the compiler or in Rte_InitMemory */
# define RTE_VAR_INIT

/* used for global or static constants */
# define RTE_CONST

/* used for references on application data (variables or constants) */
# define RTE_APPL_DATA

/* used for references on application variables */
# define RTE_APPL_VAR

/* used for references on application functions */
# define RTE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * SW-C specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_APPCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_APPCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_APPCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_APPCTRL_APPL_CODE

/* used for references on application constants */
# define RTE_APPCTRL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AppCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AppCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AppCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AppCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AppCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AppCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AppCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AppCtrl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BSWM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BSWM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BSWM_APPL_DATA

/* used for references on application functions */
# define RTE_BSWM_APPL_CODE

/* used for references on application constants */
# define RTE_BSWM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define BswM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define BswM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define BswM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define BswM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define BswM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BTNMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BTNMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BTNMDL_APPL_DATA

/* used for references on application functions */
# define RTE_BTNMDL_APPL_CODE

/* used for references on application constants */
# define RTE_BTNMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BtnMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define BtnMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BtnMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define BtnMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BtnMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define BtnMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define BtnMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define BtnMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CDD_TEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CDD_TEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CDD_TEST_APPL_DATA

/* used for references on application functions */
# define RTE_CDD_TEST_APPL_CODE

/* used for references on application constants */
# define RTE_CDD_TEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_Test_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CDD_Test_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_Test_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CDD_Test_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_Test_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CDD_Test_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CDD_Test_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CDD_Test_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CAN_DISPATCHER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CAN_DISPATCHER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CAN_DISPATCHER_APPL_DATA

/* used for references on application functions */
# define RTE_CAN_DISPATCHER_APPL_CODE

/* used for references on application constants */
# define RTE_CAN_DISPATCHER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Can_Dispatcher_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Can_Dispatcher_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Can_Dispatcher_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Can_Dispatcher_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Can_Dispatcher_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Can_Dispatcher_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Can_Dispatcher_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Can_Dispatcher_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_COMM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_COMM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_COMM_APPL_DATA

/* used for references on application functions */
# define RTE_COMM_APPL_CODE

/* used for references on application constants */
# define RTE_COMM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ComM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ComM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ComM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ComM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ComM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DCM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DCM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DCM_APPL_DATA

/* used for references on application functions */
# define RTE_DCM_APPL_CODE

/* used for references on application constants */
# define RTE_DCM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Dcm_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Dcm_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Dcm_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Dcm_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Dcm_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DCMEXT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DCMEXT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DCMEXT_APPL_DATA

/* used for references on application functions */
# define RTE_DCMEXT_APPL_CODE

/* used for references on application constants */
# define RTE_DCMEXT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmExt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DcmExt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmExt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DcmExt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmExt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DcmExt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DcmExt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DcmExt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DEM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DEM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DEM_APPL_DATA

/* used for references on application functions */
# define RTE_DEM_APPL_CODE

/* used for references on application constants */
# define RTE_DEM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Dem_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Dem_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Dem_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Dem_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Dem_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DET_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DET_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DET_APPL_DATA

/* used for references on application functions */
# define RTE_DET_APPL_CODE

/* used for references on application constants */
# define RTE_DET_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Det_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Det_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Det_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Det_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Det_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Det_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Det_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Det_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DISPCDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DISPCDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DISPCDD_APPL_DATA

/* used for references on application functions */
# define RTE_DISPCDD_APPL_CODE

/* used for references on application constants */
# define RTE_DISPCDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DispCdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DispCdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DispCdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DispCdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DispCdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DispCdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DispCdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DispCdd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DLT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DLT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DLT_APPL_DATA

/* used for references on application functions */
# define RTE_DLT_APPL_CODE

/* used for references on application constants */
# define RTE_DLT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Dlt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Dlt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Dlt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Dlt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Dlt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ECTMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ECTMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ECTMDL_APPL_DATA

/* used for references on application functions */
# define RTE_ECTMDL_APPL_CODE

/* used for references on application constants */
# define RTE_ECTMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EctMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EctMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EctMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EctMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EctMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EctMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EctMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EctMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ECTMDLWRP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ECTMDLWRP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ECTMDLWRP_APPL_DATA

/* used for references on application functions */
# define RTE_ECTMDLWRP_APPL_CODE

/* used for references on application constants */
# define RTE_ECTMDLWRP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EctMdlWrp_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EctMdlWrp_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EctMdlWrp_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EctMdlWrp_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EctMdlWrp_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EctMdlWrp_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EctMdlWrp_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EctMdlWrp_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ECUM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ECUM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ECUM_APPL_DATA

/* used for references on application functions */
# define RTE_ECUM_APPL_CODE

/* used for references on application constants */
# define RTE_ECUM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EcuM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EcuM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EcuM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EcuM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EcuM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ECUMEXT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ECUMEXT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ECUMEXT_APPL_DATA

/* used for references on application functions */
# define RTE_ECUMEXT_APPL_CODE

/* used for references on application constants */
# define RTE_ECUMEXT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EcumExt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EcumExt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EcumExt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EcumExt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EcumExt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EcumExt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EcumExt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EcumExt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_EEP24XX_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_EEP24XX_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_EEP24XX_APPL_DATA

/* used for references on application functions */
# define RTE_EEP24XX_APPL_CODE

/* used for references on application constants */
# define RTE_EEP24XX_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Eep24xx_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Eep24xx_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Eep24xx_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Eep24xx_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Eep24xx_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Eep24xx_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Eep24xx_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Eep24xx_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ENGMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ENGMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ENGMDL_APPL_DATA

/* used for references on application functions */
# define RTE_ENGMDL_APPL_CODE

/* used for references on application constants */
# define RTE_ENGMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EngMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EngMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EngMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EngMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EngMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EngMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EngMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EngMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_FUELMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_FUELMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_FUELMDL_APPL_DATA

/* used for references on application functions */
# define RTE_FUELMDL_APPL_CODE

/* used for references on application constants */
# define RTE_FUELMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FuelMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define FuelMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FuelMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define FuelMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FuelMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define FuelMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define FuelMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define FuelMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_FUELMDLWRP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_FUELMDLWRP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_FUELMDLWRP_APPL_DATA

/* used for references on application functions */
# define RTE_FUELMDLWRP_APPL_CODE

/* used for references on application constants */
# define RTE_FUELMDLWRP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FuelMdlWrp_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define FuelMdlWrp_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FuelMdlWrp_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define FuelMdlWrp_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FuelMdlWrp_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define FuelMdlWrp_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define FuelMdlWrp_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define FuelMdlWrp_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_GEARMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_GEARMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_GEARMDL_APPL_DATA

/* used for references on application functions */
# define RTE_GEARMDL_APPL_CODE

/* used for references on application constants */
# define RTE_GEARMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GearMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define GearMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GearMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define GearMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GearMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define GearMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define GearMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define GearMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IOHWAB_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IOHWAB_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWAB_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWAB_APPL_CODE

/* used for references on application constants */
# define RTE_IOHWAB_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define IoHwAb_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define IoHwAb_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define IoHwAb_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define IoHwAb_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define IoHwAb_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NVM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NVM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NVM_APPL_DATA

/* used for references on application functions */
# define RTE_NVM_APPL_CODE

/* used for references on application constants */
# define RTE_NVM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define NvM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define NvM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define NvM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define NvM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define NvM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ODOMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ODOMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ODOMDL_APPL_DATA

/* used for references on application functions */
# define RTE_ODOMDL_APPL_CODE

/* used for references on application constants */
# define RTE_ODOMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OdoMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define OdoMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OdoMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define OdoMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OdoMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define OdoMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define OdoMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define OdoMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SNDCDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SNDCDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SNDCDD_APPL_DATA

/* used for references on application functions */
# define RTE_SNDCDD_APPL_CODE

/* used for references on application constants */
# define RTE_SNDCDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndCdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SndCdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndCdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SndCdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndCdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SndCdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SndCdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SndCdd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SPDMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SPDMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SPDMDL_APPL_DATA

/* used for references on application functions */
# define RTE_SPDMDL_APPL_CODE

/* used for references on application constants */
# define RTE_SPDMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SpdMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SpdMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SpdMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SpdMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SpdMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SpdMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SpdMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SpdMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TMEXT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TMEXT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TMEXT_APPL_DATA

/* used for references on application functions */
# define RTE_TMEXT_APPL_CODE

/* used for references on application constants */
# define RTE_TMEXT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TmExt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TmExt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TmExt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TmExt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TmExt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TmExt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TRIPMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TRIPMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TRIPMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TRIPMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TRIPMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TripMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TripMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TripMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TripMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TripMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TripMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TripMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TripMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TTMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TTMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TTMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TTMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TTMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TtMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TtMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TtMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TtMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TtMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TtMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TtMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TtMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_UCLPROXYCDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_UCLPROXYCDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_UCLPROXYCDD_APPL_DATA

/* used for references on application functions */
# define RTE_UCLPROXYCDD_APPL_CODE

/* used for references on application constants */
# define RTE_UCLPROXYCDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UclProxyCdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define UclProxyCdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UclProxyCdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define UclProxyCdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UclProxyCdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define UclProxyCdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define UclProxyCdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define UclProxyCdd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_WRNCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_WRNCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WRNCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_WRNCTRL_APPL_CODE

/* used for references on application constants */
# define RTE_WRNCTRL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WrnCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define WrnCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WrnCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define WrnCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WrnCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define WrnCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define WrnCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define WrnCtrl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Calibration Parameter specific defines
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CONST_DEFAULT_RTE_CDATA_GROUP
 *********************************************************************************************************************/

# define RTE_CONST_DEFAULT_RTE_CDATA_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_IOHWABSAFE_APPL)  ****************/

/* used for references on application variables */
# define RTE_IOHWABSAFE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWABSAFE_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWABSAFE_APPL_CODE

/* used for references on application constants */
# define RTE_IOHWABSAFE_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:IoHwAbSafe_VAR)  *********************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define IoHwAbSafe_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define IoHwAbSafe_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define IoHwAbSafe_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:IoHwAbSafe_CONST)  *******************/

/* used for global or static SWC specific constants */
# define IoHwAbSafe_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:IoHwAbSafe_CODE)  ********************/

/* used for SWC specific code */
# define IoHwAbSafe_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_IOHWABSAFE_APPL)  ****************/

/* used for references on application variables */
# define RTE_IOHWABSAFE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWABSAFE_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWABSAFE_APPL_CODE

/* used for references on application constants */
# define RTE_IOHWABSAFE_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:IoHwAbSafe_CONST)  *******************/

/* used for global or static SWC specific constants */
# define IoHwAbSafe_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:IoHwAbSafe_VAR)  *********************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define IoHwAbSafe_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define IoHwAbSafe_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define IoHwAbSafe_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:IoHwAbSafe_CODE)  ********************/

/* used for SWC specific code */
# define IoHwAbSafe_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RCanAdapterMdl_CONST)  ***************/

/* used for global or static SWC specific constants */
# define RCanAdapterMdl_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_TCANADAPTERMDL_APPL)  ************/

/* used for references on application variables */
# define RTE_TCANADAPTERMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TCANADAPTERMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TCANADAPTERMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TCANADAPTERMDL_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_RCANADAPTERMDL_APPL)  ************/

/* used for references on application variables */
# define RTE_RCANADAPTERMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RCANADAPTERMDL_APPL_DATA

/* used for references on application functions */
# define RTE_RCANADAPTERMDL_APPL_CODE

/* used for references on application constants */
# define RTE_RCANADAPTERMDL_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RCanAdapterMdl_CODE)  ****************/

/* used for SWC specific code */
# define RCanAdapterMdl_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:TCanAdapterMdl_CONST)  ***************/

/* used for global or static SWC specific constants */
# define TCanAdapterMdl_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:TCanAdapterMdl_CODE)  ****************/

/* used for SWC specific code */
# define TCanAdapterMdl_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:TCanAdapterMdl_VAR)  *****************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TCanAdapterMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TCanAdapterMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TCanAdapterMdl_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RCanAdapterMdl_VAR)  *****************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define RCanAdapterMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define RCanAdapterMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define RCanAdapterMdl_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* _RTE_COMPILER_CFG_H */
