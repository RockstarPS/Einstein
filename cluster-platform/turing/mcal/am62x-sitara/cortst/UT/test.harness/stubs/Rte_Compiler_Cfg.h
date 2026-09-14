/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Compiler_Cfg.h
 *        Config:  HyundaiSP2.dpa
 *   ECU-Project:  CLU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700619 for Visteon Corporation
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
 * Symbol: RTE_ABSMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ABSMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ABSMDL_APPL_DATA

/* used for references on application functions */
# define RTE_ABSMDL_APPL_CODE

/* used for references on application constants */
# define RTE_ABSMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AbsMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AbsMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AbsMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AbsMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AbsMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ACCMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ACCMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ACCMDL_APPL_DATA

/* used for references on application functions */
# define RTE_ACCMDL_APPL_CODE

/* used for references on application constants */
# define RTE_ACCMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AccMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AccMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AccMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AccMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AccMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AccMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AccMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AccMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AFEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AFEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AFEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_AFEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_AFEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AfeMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AfeMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AfeMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AfeMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AfeMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AfeMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AfeMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AfeMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AFEVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AFEVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AFEVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_AFEVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_AFEVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AfeView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AfeView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AfeView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AfeView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AfeView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AfeView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AfeView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AfeView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AIRBAGMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AIRBAGMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AIRBAGMDL_APPL_DATA

/* used for references on application functions */
# define RTE_AIRBAGMDL_APPL_CODE

/* used for references on application constants */
# define RTE_AIRBAGMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AirbagMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AirbagMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AirbagMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AirbagMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AirbagMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AirbagMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AirbagMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AirbagMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
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
 * Symbol: RTE_AUTOHOLDMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AUTOHOLDMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AUTOHOLDMDL_APPL_DATA

/* used for references on application functions */
# define RTE_AUTOHOLDMDL_APPL_CODE

/* used for references on application constants */
# define RTE_AUTOHOLDMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AutoHoldMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AutoHoldMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AutoHoldMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AutoHoldMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AutoHoldMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AutoHoldMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AutoHoldMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AutoHoldMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AVMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AVMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AVMDL_APPL_DATA

/* used for references on application functions */
# define RTE_AVMDL_APPL_CODE

/* used for references on application constants */
# define RTE_AVMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AvMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AvMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AvMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AvMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AvMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AvMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AvMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AvMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AVSMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AVSMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AVSMDL_APPL_DATA

/* used for references on application functions */
# define RTE_AVSMDL_APPL_CODE

/* used for references on application constants */
# define RTE_AVSMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AvsMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AvsMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AvsMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AvsMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AvsMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AvsMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AvsMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AvsMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AVSVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AVSVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AVSVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_AVSVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_AVSVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AvsView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AvsView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AvsView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AvsView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AvsView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AvsView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AvsView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AvsView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AWDMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AWDMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AWDMDL_APPL_DATA

/* used for references on application functions */
# define RTE_AWDMDL_APPL_CODE

/* used for references on application constants */
# define RTE_AWDMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AwdMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AwdMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AwdMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AwdMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AwdMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AwdMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AwdMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AwdMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BATTCHARGEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BATTCHARGEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BATTCHARGEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_BATTCHARGEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_BATTCHARGEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BattChargeMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define BattChargeMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BattChargeMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define BattChargeMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BattChargeMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define BattChargeMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define BattChargeMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define BattChargeMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BATTDISCHARGEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BATTDISCHARGEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BATTDISCHARGEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_BATTDISCHARGEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_BATTDISCHARGEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BattDisChargeMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define BattDisChargeMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BattDisChargeMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define BattDisChargeMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BattDisChargeMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define BattDisChargeMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define BattDisChargeMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define BattDisChargeMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BATTMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BATTMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BATTMDL_APPL_DATA

/* used for references on application functions */
# define RTE_BATTMDL_APPL_CODE

/* used for references on application constants */
# define RTE_BATTMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BattMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define BattMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BattMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define BattMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BattMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define BattMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define BattMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define BattMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BCAMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BCAMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BCAMDL_APPL_DATA

/* used for references on application functions */
# define RTE_BCAMDL_APPL_CODE

/* used for references on application constants */
# define RTE_BCAMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BcaMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define BcaMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BcaMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define BcaMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BcaMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define BcaMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define BcaMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define BcaMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BCMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BCMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BCMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_BCMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_BCMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BcmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define BcmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BcmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define BcmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BcmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define BcmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define BcmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define BcmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BCWMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BCWMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BCWMDL_APPL_DATA

/* used for references on application functions */
# define RTE_BCWMDL_APPL_CODE

/* used for references on application constants */
# define RTE_BCWMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BcwMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define BcwMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BcwMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define BcwMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BcwMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define BcwMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define BcwMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define BcwMdl_VAR_ZERO_INIT

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
 * Symbol: RTE_CANNMCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CANNMCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CANNMCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_CANNMCTRL_APPL_CODE

/* used for references on application constants */
# define RTE_CANNMCTRL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CanNmCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CanNmCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CanNmCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CanNmCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CanNmCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CanNmCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CanNmCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CanNmCtrl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CHKENGMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CHKENGMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CHKENGMDL_APPL_DATA

/* used for references on application functions */
# define RTE_CHKENGMDL_APPL_CODE

/* used for references on application constants */
# define RTE_CHKENGMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ChkEngMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ChkEngMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ChkEngMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ChkEngMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ChkEngMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ChkEngMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ChkEngMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ChkEngMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CHKFUSEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CHKFUSEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CHKFUSEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_CHKFUSEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_CHKFUSEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ChkFuseMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ChkFuseMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ChkFuseMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ChkFuseMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ChkFuseMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ChkFuseMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ChkFuseMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ChkFuseMdl_VAR_ZERO_INIT

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
 * Symbol: RTE_COMMEXT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_COMMEXT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_COMMEXT_APPL_DATA

/* used for references on application functions */
# define RTE_COMMEXT_APPL_CODE

/* used for references on application constants */
# define RTE_COMMEXT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComMExt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ComMExt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComMExt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ComMExt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComMExt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ComMExt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ComMExt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ComMExt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CONVUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CONVUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CONVUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_CONVUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_CONVUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ConvUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ConvUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ConvUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ConvUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ConvUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ConvUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ConvUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ConvUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CRUISEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CRUISEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CRUISEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_CRUISEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_CRUISEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CruiseMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CruiseMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CruiseMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CruiseMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CruiseMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CruiseMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CruiseMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CruiseMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DAWMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DAWMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DAWMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DAWMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DAWMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DawMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DawMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DawMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DawMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DawMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DawMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DawMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DawMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DBCMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DBCMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DBCMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DBCMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DBCMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DbcMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DbcMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DbcMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DbcMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DbcMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DbcMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DbcMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DbcMdl_VAR_ZERO_INIT

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
 * Symbol: RTE_DCTMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DCTMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DCTMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DCTMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DCTMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DctMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DctMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DctMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DctMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DctMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DctMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DctMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DctMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DEMEXT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DEMEXT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DEMEXT_APPL_DATA

/* used for references on application functions */
# define RTE_DEMEXT_APPL_CODE

/* used for references on application constants */
# define RTE_DEMEXT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemExt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DemExt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemExt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DemExt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemExt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DemExt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DemExt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DemExt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DEMMASTER_0_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DEMMASTER_0_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DEMMASTER_0_APPL_DATA

/* used for references on application functions */
# define RTE_DEMMASTER_0_APPL_CODE

/* used for references on application constants */
# define RTE_DEMMASTER_0_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemMaster_0_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DemMaster_0_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemMaster_0_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DemMaster_0_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemMaster_0_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DemMaster_0_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DemMaster_0_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DemMaster_0_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DEMSATELLITE_0_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DEMSATELLITE_0_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DEMSATELLITE_0_APPL_DATA

/* used for references on application functions */
# define RTE_DEMSATELLITE_0_APPL_CODE

/* used for references on application constants */
# define RTE_DEMSATELLITE_0_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemSatellite_0_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DemSatellite_0_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemSatellite_0_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DemSatellite_0_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemSatellite_0_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DemSatellite_0_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DemSatellite_0_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DemSatellite_0_VAR_ZERO_INIT

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
 * Symbol: RTE_DFDMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DFDMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DFDMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DFDMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DFDMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DfdMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DfdMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DfdMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DfdMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DfdMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DfdMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DfdMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DfdMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DIMDERATEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DIMDERATEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DIMDERATEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DIMDERATEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DIMDERATEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DimDerateMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DimDerateMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DimDerateMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DimDerateMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DimDerateMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DimDerateMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DimDerateMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DimDerateMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DIMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DIMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DIMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DIMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DIMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DimMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DimMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DimMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DimMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DimMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DimMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DimMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DimMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DIMVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DIMVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DIMVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_DIMVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_DIMVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DimView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DimView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DimView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DimView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DimView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DimView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DimView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DimView_VAR_ZERO_INIT

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
 * Symbol: RTE_DLTEXT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DLTEXT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DLTEXT_APPL_DATA

/* used for references on application functions */
# define RTE_DLTEXT_APPL_CODE

/* used for references on application constants */
# define RTE_DLTEXT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DltExt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DltExt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DltExt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DltExt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DltExt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DltExt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DltExt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DltExt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DOORMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DOORMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DOORMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DOORMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DOORMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DoorMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DoorMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DoorMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DoorMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DoorMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DoorMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DoorMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DoorMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DOORUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DOORUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DOORUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DOORUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DOORUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DoorUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DoorUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DoorUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DoorUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DoorUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DoorUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DoorUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DoorUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DPFMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DPFMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DPFMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DPFMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DPFMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DpfMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DpfMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DpfMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DpfMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DpfMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DpfMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DpfMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DpfMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DRIVETIMEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DRIVETIMEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DRIVETIMEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DRIVETIMEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DRIVETIMEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DriveTimeMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DriveTimeMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DriveTimeMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DriveTimeMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DriveTimeMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DriveTimeMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DriveTimeMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DriveTimeMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DRIVETIMEVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DRIVETIMEVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DRIVETIMEVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_DRIVETIMEVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_DRIVETIMEVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DriveTimeView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DriveTimeView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DriveTimeView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DriveTimeView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DriveTimeView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DriveTimeView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DriveTimeView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DriveTimeView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DRVASTUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DRVASTUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DRVASTUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DRVASTUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DRVASTUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DrvAstUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DrvAstUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DrvAstUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DrvAstUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DrvAstUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DrvAstUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DrvAstUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DrvAstUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DRVMODEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DRVMODEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DRVMODEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DRVMODEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DRVMODEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DrvModeMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DrvModeMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DrvModeMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DrvModeMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DrvModeMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DrvModeMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DrvModeMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DrvModeMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DTEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DTEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DTEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_DTEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_DTEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DteMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DteMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DteMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DteMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DteMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DteMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DteMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DteMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DTEVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DTEVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DTEVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_DTEVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_DTEVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DteView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DteView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DteView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DteView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DteView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DteView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DteView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DteView_VAR_ZERO_INIT

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
 * Symbol: RTE_ECTVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ECTVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ECTVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_ECTVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_ECTVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EctView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EctView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EctView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EctView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EctView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EctView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EctView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EctView_VAR_ZERO_INIT

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
 * Symbol: RTE_ENGRUNMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ENGRUNMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ENGRUNMDL_APPL_DATA

/* used for references on application functions */
# define RTE_ENGRUNMDL_APPL_CODE

/* used for references on application constants */
# define RTE_ENGRUNMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EngRunMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EngRunMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EngRunMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EngRunMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EngRunMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EngRunMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EngRunMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EngRunMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_EOLERRMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_EOLERRMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_EOLERRMDL_APPL_DATA

/* used for references on application functions */
# define RTE_EOLERRMDL_APPL_CODE

/* used for references on application constants */
# define RTE_EOLERRMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EolErrMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EolErrMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EolErrMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EolErrMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EolErrMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EolErrMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EolErrMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EolErrMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_EPBMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_EPBMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_EPBMDL_APPL_DATA

/* used for references on application functions */
# define RTE_EPBMDL_APPL_CODE

/* used for references on application constants */
# define RTE_EPBMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EpbMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EpbMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EpbMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EpbMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EpbMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EpbMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EpbMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EpbMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ESCMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ESCMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ESCMDL_APPL_DATA

/* used for references on application functions */
# define RTE_ESCMDL_APPL_CODE

/* used for references on application constants */
# define RTE_ESCMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EscMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EscMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EscMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EscMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EscMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EscMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EscMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EscMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_FBLMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_FBLMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_FBLMDL_APPL_DATA

/* used for references on application functions */
# define RTE_FBLMDL_APPL_CODE

/* used for references on application constants */
# define RTE_FBLMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FblMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define FblMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FblMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define FblMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FblMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define FblMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define FblMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define FblMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_FCALOWMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_FCALOWMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_FCALOWMDL_APPL_DATA

/* used for references on application functions */
# define RTE_FCALOWMDL_APPL_CODE

/* used for references on application constants */
# define RTE_FCALOWMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FcaLowMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define FcaLowMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FcaLowMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define FcaLowMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FcaLowMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define FcaLowMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define FcaLowMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define FcaLowMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_FCAMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_FCAMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_FCAMDL_APPL_DATA

/* used for references on application functions */
# define RTE_FCAMDL_APPL_CODE

/* used for references on application constants */
# define RTE_FCAMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FcaMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define FcaMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FcaMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define FcaMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FcaMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define FcaMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define FcaMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define FcaMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_FRONTFOGMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_FRONTFOGMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_FRONTFOGMDL_APPL_DATA

/* used for references on application functions */
# define RTE_FRONTFOGMDL_APPL_CODE

/* used for references on application constants */
# define RTE_FRONTFOGMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FrontFogMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define FrontFogMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FrontFogMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define FrontFogMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FrontFogMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define FrontFogMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define FrontFogMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define FrontFogMdl_VAR_ZERO_INIT

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
 * Symbol: RTE_FUELVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_FUELVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_FUELVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_FUELVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_FUELVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FuelView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define FuelView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FuelView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define FuelView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FuelView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define FuelView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define FuelView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define FuelView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_GDTCDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_GDTCDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_GDTCDD_APPL_DATA

/* used for references on application functions */
# define RTE_GDTCDD_APPL_CODE

/* used for references on application constants */
# define RTE_GDTCDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GdtCdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define GdtCdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GdtCdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define GdtCdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GdtCdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define GdtCdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define GdtCdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define GdtCdd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_GDTCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_GDTCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_GDTCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_GDTCTRL_APPL_CODE

/* used for references on application constants */
# define RTE_GDTCTRL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GdtCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define GdtCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GdtCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define GdtCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GdtCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define GdtCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define GdtCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define GdtCtrl_VAR_ZERO_INIT

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
 * Symbol: RTE_GLOWPLUGMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_GLOWPLUGMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_GLOWPLUGMDL_APPL_DATA

/* used for references on application functions */
# define RTE_GLOWPLUGMDL_APPL_CODE

/* used for references on application constants */
# define RTE_GLOWPLUGMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GlowPlugMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define GlowPlugMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GlowPlugMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define GlowPlugMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GlowPlugMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define GlowPlugMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define GlowPlugMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define GlowPlugMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_GOODBYEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_GOODBYEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_GOODBYEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_GOODBYEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_GOODBYEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GoodByeMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define GoodByeMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GoodByeMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define GoodByeMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: GoodByeMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define GoodByeMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define GoodByeMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define GoodByeMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_HBAMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_HBAMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_HBAMDL_APPL_DATA

/* used for references on application functions */
# define RTE_HBAMDL_APPL_CODE

/* used for references on application constants */
# define RTE_HBAMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HbaMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define HbaMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HbaMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define HbaMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HbaMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define HbaMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define HbaMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define HbaMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_HEADLAMPMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_HEADLAMPMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_HEADLAMPMDL_APPL_DATA

/* used for references on application functions */
# define RTE_HEADLAMPMDL_APPL_CODE

/* used for references on application constants */
# define RTE_HEADLAMPMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HeadLampMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define HeadLampMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HeadLampMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define HeadLampMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HeadLampMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define HeadLampMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define HeadLampMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define HeadLampMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_HITEMPMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_HITEMPMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_HITEMPMDL_APPL_DATA

/* used for references on application functions */
# define RTE_HITEMPMDL_APPL_CODE

/* used for references on application constants */
# define RTE_HITEMPMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HiTempMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define HiTempMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HiTempMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define HiTempMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HiTempMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define HiTempMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define HiTempMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define HiTempMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_HMIOFFCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_HMIOFFCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_HMIOFFCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_HMIOFFCTRL_APPL_CODE

/* used for references on application constants */
# define RTE_HMIOFFCTRL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HmiOffCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define HmiOffCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HmiOffCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define HmiOffCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HmiOffCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define HmiOffCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define HmiOffCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define HmiOffCtrl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_HMIONCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_HMIONCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_HMIONCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_HMIONCTRL_APPL_CODE

/* used for references on application constants */
# define RTE_HMIONCTRL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HmiOnCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define HmiOnCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HmiOnCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define HmiOnCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HmiOnCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define HmiOnCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define HmiOnCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define HmiOnCtrl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_HMIVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_HMIVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_HMIVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_HMIVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_HMIVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HmiView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define HmiView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HmiView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define HmiView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HmiView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define HmiView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define HmiView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define HmiView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_HUDUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_HUDUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_HUDUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_HUDUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_HUDUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HudUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define HudUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HudUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define HudUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HudUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define HudUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define HudUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define HudUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ICUPACMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ICUPACMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ICUPACMDL_APPL_DATA

/* used for references on application functions */
# define RTE_ICUPACMDL_APPL_CODE

/* used for references on application constants */
# define RTE_ICUPACMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IcuPacMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define IcuPacMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IcuPacMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define IcuPacMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IcuPacMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define IcuPacMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define IcuPacMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define IcuPacMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IFEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IFEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IFEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_IFEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_IFEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IfeMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define IfeMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IfeMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define IfeMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IfeMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define IfeMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define IfeMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define IfeMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IFEVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IFEVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IFEVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_IFEVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_IFEVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IfeView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define IfeView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IfeView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define IfeView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IfeView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define IfeView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define IfeView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define IfeView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IMMOMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IMMOMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IMMOMDL_APPL_DATA

/* used for references on application functions */
# define RTE_IMMOMDL_APPL_CODE

/* used for references on application constants */
# define RTE_IMMOMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ImmoMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ImmoMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ImmoMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ImmoMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ImmoMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ImmoMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ImmoMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ImmoMdl_VAR_ZERO_INIT

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
 * Symbol: RTE_IOHWABSAFE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IOHWABSAFE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWABSAFE_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWABSAFE_APPL_CODE

/* used for references on application constants */
# define RTE_IOHWABSAFE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAbSafe_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define IoHwAbSafe_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAbSafe_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define IoHwAbSafe_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAbSafe_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define IoHwAbSafe_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define IoHwAbSafe_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define IoHwAbSafe_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ISGMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ISGMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ISGMDL_APPL_DATA

/* used for references on application functions */
# define RTE_ISGMDL_APPL_CODE

/* used for references on application constants */
# define RTE_ISGMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IsgMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define IsgMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IsgMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define IsgMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IsgMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define IsgMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define IsgMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define IsgMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_LAMPFAILMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_LAMPFAILMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_LAMPFAILMDL_APPL_DATA

/* used for references on application functions */
# define RTE_LAMPFAILMDL_APPL_CODE

/* used for references on application constants */
# define RTE_LAMPFAILMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LampFailMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define LampFailMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LampFailMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define LampFailMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LampFailMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define LampFailMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define LampFailMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define LampFailMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_LANGUAGEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_LANGUAGEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_LANGUAGEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_LANGUAGEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_LANGUAGEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LanguageMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define LanguageMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LanguageMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define LanguageMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LanguageMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define LanguageMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define LanguageMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define LanguageMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_LANGUAGEUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_LANGUAGEUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_LANGUAGEUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_LANGUAGEUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_LANGUAGEUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LanguageUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define LanguageUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LanguageUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define LanguageUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LanguageUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define LanguageUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define LanguageUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define LanguageUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_LIGHTSMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_LIGHTSMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_LIGHTSMDL_APPL_DATA

/* used for references on application functions */
# define RTE_LIGHTSMDL_APPL_CODE

/* used for references on application constants */
# define RTE_LIGHTSMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LightsMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define LightsMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LightsMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define LightsMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LightsMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define LightsMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define LightsMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define LightsMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_LIGHTSUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_LIGHTSUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_LIGHTSUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_LIGHTSUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_LIGHTSUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LightsUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define LightsUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LightsUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define LightsUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LightsUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define LightsUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define LightsUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define LightsUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_LKAMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_LKAMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_LKAMDL_APPL_DATA

/* used for references on application functions */
# define RTE_LKAMDL_APPL_CODE

/* used for references on application constants */
# define RTE_LKAMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LkaMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define LkaMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LkaMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define LkaMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LkaMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define LkaMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define LkaMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define LkaMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_LOWWASHER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_LOWWASHER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_LOWWASHER_APPL_DATA

/* used for references on application functions */
# define RTE_LOWWASHER_APPL_CODE

/* used for references on application constants */
# define RTE_LOWWASHER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LowWasher_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define LowWasher_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LowWasher_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define LowWasher_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LowWasher_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define LowWasher_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define LowWasher_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define LowWasher_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_LPIMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_LPIMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_LPIMDL_APPL_DATA

/* used for references on application functions */
# define RTE_LPIMDL_APPL_CODE

/* used for references on application constants */
# define RTE_LPIMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LpiMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define LpiMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LpiMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define LpiMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: LpiMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define LpiMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define LpiMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define LpiMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDPSMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDPSMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDPSMDL_APPL_DATA

/* used for references on application functions */
# define RTE_MDPSMDL_APPL_CODE

/* used for references on application constants */
# define RTE_MDPSMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MdpsMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define MdpsMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MdpsMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define MdpsMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MdpsMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define MdpsMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define MdpsMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define MdpsMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MEETCDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MEETCDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MEETCDD_APPL_DATA

/* used for references on application functions */
# define RTE_MEETCDD_APPL_CODE

/* used for references on application constants */
# define RTE_MEETCDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MeetCdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define MeetCdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MeetCdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define MeetCdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MeetCdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define MeetCdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define MeetCdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define MeetCdd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MINIPOPUPVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MINIPOPUPVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MINIPOPUPVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_MINIPOPUPVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_MINIPOPUPVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MiniPopupView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define MiniPopupView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MiniPopupView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define MiniPopupView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MiniPopupView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define MiniPopupView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define MiniPopupView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define MiniPopupView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MODMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MODMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MODMDL_APPL_DATA

/* used for references on application functions */
# define RTE_MODMDL_APPL_CODE

/* used for references on application constants */
# define RTE_MODMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ModMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ModMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ModMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ModMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ModMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ModMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ModMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ModMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NV_DATA_ADAPTER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NV_DATA_ADAPTER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NV_DATA_ADAPTER_APPL_DATA

/* used for references on application functions */
# define RTE_NV_DATA_ADAPTER_APPL_CODE

/* used for references on application constants */
# define RTE_NV_DATA_ADAPTER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NV_Data_Adapter_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define NV_Data_Adapter_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NV_Data_Adapter_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define NV_Data_Adapter_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NV_Data_Adapter_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define NV_Data_Adapter_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define NV_Data_Adapter_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define NV_Data_Adapter_VAR_ZERO_INIT

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
 * Symbol: RTE_NVMADAPTERMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NVMADAPTERMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NVMADAPTERMDL_APPL_DATA

/* used for references on application functions */
# define RTE_NVMADAPTERMDL_APPL_CODE

/* used for references on application constants */
# define RTE_NVMADAPTERMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvmAdapterMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define NvmAdapterMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvmAdapterMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define NvmAdapterMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvmAdapterMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define NvmAdapterMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define NvmAdapterMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define NvmAdapterMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_OATMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_OATMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_OATMDL_APPL_DATA

/* used for references on application functions */
# define RTE_OATMDL_APPL_CODE

/* used for references on application constants */
# define RTE_OATMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OatMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define OatMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OatMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define OatMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OatMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define OatMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define OatMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define OatMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ODOCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ODOCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ODOCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_ODOCTRL_APPL_CODE

/* used for references on application constants */
# define RTE_ODOCTRL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OdoCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define OdoCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OdoCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define OdoCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OdoCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define OdoCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define OdoCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define OdoCtrl_VAR_ZERO_INIT

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
 * Symbol: RTE_OILCHANGEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_OILCHANGEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_OILCHANGEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_OILCHANGEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_OILCHANGEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OilChangeMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define OilChangeMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OilChangeMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define OilChangeMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OilChangeMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define OilChangeMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define OilChangeMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define OilChangeMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_OILPRESMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_OILPRESMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_OILPRESMDL_APPL_DATA

/* used for references on application functions */
# define RTE_OILPRESMDL_APPL_CODE

/* used for references on application constants */
# define RTE_OILPRESMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OilPresMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define OilPresMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OilPresMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define OilPresMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OilPresMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define OilPresMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define OilPresMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define OilPresMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_OS_OSCORE0_SWC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_OS_OSCORE0_SWC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_OS_OSCORE0_SWC_APPL_DATA

/* used for references on application functions */
# define RTE_OS_OSCORE0_SWC_APPL_CODE

/* used for references on application constants */
# define RTE_OS_OSCORE0_SWC_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Os_OsCore0_swc_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Os_OsCore0_swc_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Os_OsCore0_swc_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Os_OsCore0_swc_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Os_OsCore0_swc_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Os_OsCore0_swc_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Os_OsCore0_swc_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Os_OsCore0_swc_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_OTHERSUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_OTHERSUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_OTHERSUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_OTHERSUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_OTHERSUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OthersUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define OthersUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OthersUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define OthersUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: OthersUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define OthersUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define OthersUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define OthersUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PARKBRAKEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_PARKBRAKEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_PARKBRAKEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_PARKBRAKEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_PARKBRAKEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ParkBrakeMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ParkBrakeMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ParkBrakeMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ParkBrakeMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ParkBrakeMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ParkBrakeMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ParkBrakeMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ParkBrakeMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PARKUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_PARKUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_PARKUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_PARKUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_PARKUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ParkUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ParkUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ParkUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ParkUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ParkUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ParkUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ParkUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ParkUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PASMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_PASMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_PASMDL_APPL_DATA

/* used for references on application functions */
# define RTE_PASMDL_APPL_CODE

/* used for references on application constants */
# define RTE_PASMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PasMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define PasMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PasMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define PasMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PasMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define PasMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define PasMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define PasMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_POCRATEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_POCRATEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_POCRATEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_POCRATEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_POCRATEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PocRateMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define PocRateMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PocRateMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define PocRateMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PocRateMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define PocRateMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define PocRateMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define PocRateMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_POPUPCHMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_POPUPCHMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_POPUPCHMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_POPUPCHMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_POPUPCHMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PopupChmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define PopupChmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PopupChmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define PopupChmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PopupChmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define PopupChmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define PopupChmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define PopupChmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_POPUPVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_POPUPVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_POPUPVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_POPUPVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_POPUPVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PopupView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define PopupView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PopupView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define PopupView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PopupView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define PopupView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define PopupView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define PopupView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PTRVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_PTRVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_PTRVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_PTRVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_PTRVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PtrView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define PtrView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PtrView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define PtrView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PtrView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define PtrView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define PtrView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define PtrView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RCANADAPTERMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RCANADAPTERMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RCANADAPTERMDL_APPL_DATA

/* used for references on application functions */
# define RTE_RCANADAPTERMDL_APPL_CODE

/* used for references on application constants */
# define RTE_RCANADAPTERMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RCanAdapterMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define RCanAdapterMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RCanAdapterMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define RCanAdapterMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RCanAdapterMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define RCanAdapterMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define RCanAdapterMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define RCanAdapterMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RCCWMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RCCWMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RCCWMDL_APPL_DATA

/* used for references on application functions */
# define RTE_RCCWMDL_APPL_CODE

/* used for references on application constants */
# define RTE_RCCWMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RccwMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define RccwMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RccwMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define RccwMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RccwMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define RccwMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define RccwMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define RccwMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_REARFOGMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_REARFOGMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_REARFOGMDL_APPL_DATA

/* used for references on application functions */
# define RTE_REARFOGMDL_APPL_CODE

/* used for references on application constants */
# define RTE_REARFOGMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RearFogMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define RearFogMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RearFogMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define RearFogMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RearFogMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define RearFogMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define RearFogMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define RearFogMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RESETUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RESETUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RESETUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_RESETUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_RESETUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ResetUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ResetUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ResetUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ResetUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ResetUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ResetUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ResetUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ResetUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RTCCDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RTCCDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RTCCDD_APPL_DATA

/* used for references on application functions */
# define RTE_RTCCDD_APPL_CODE

/* used for references on application constants */
# define RTE_RTCCDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RtcCdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define RtcCdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RtcCdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define RtcCdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RtcCdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define RtcCdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define RtcCdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define RtcCdd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SCRMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SCRMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SCRMDL_APPL_DATA

/* used for references on application functions */
# define RTE_SCRMDL_APPL_CODE

/* used for references on application constants */
# define RTE_SCRMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ScrMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ScrMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ScrMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ScrMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ScrMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ScrMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ScrMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ScrMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SEAMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SEAMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SEAMDL_APPL_DATA

/* used for references on application functions */
# define RTE_SEAMDL_APPL_CODE

/* used for references on application constants */
# define RTE_SEAMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SeaMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SeaMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SeaMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SeaMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SeaMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SeaMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SeaMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SeaMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SEATBELTMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SEATBELTMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SEATBELTMDL_APPL_DATA

/* used for references on application functions */
# define RTE_SEATBELTMDL_APPL_CODE

/* used for references on application constants */
# define RTE_SEATBELTMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SeatBeltMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SeatBeltMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SeatBeltMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SeatBeltMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SeatBeltMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SeatBeltMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SeatBeltMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SeatBeltMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SERVICEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SERVICEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SERVICEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_SERVICEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_SERVICEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ServiceMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ServiceMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ServiceMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ServiceMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ServiceMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ServiceMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ServiceMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ServiceMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SLEEPCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SLEEPCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SLEEPCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_SLEEPCTRL_APPL_CODE

/* used for references on application constants */
# define RTE_SLEEPCTRL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SleepCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SleepCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SleepCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SleepCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SleepCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SleepCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SleepCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SleepCtrl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SMKMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SMKMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SMKMDL_APPL_DATA

/* used for references on application functions */
# define RTE_SMKMDL_APPL_CODE

/* used for references on application constants */
# define RTE_SMKMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SmkMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SmkMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SmkMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SmkMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SmkMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SmkMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SmkMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SmkMdl_VAR_ZERO_INIT

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
 * Symbol: RTE_SNDMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SNDMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SNDMDL_APPL_DATA

/* used for references on application functions */
# define RTE_SNDMDL_APPL_CODE

/* used for references on application constants */
# define RTE_SNDMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SndMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SndMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SndMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SndMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SndMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SNDUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SNDUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SNDUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_SNDUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_SNDUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SndUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SndUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SndUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SndUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SndUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SNDVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SNDVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SNDVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_SNDVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_SNDVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SndView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SndView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SndView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SndView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SndView_VAR_ZERO_INIT

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
 * Symbol: RTE_SPDOUTMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SPDOUTMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SPDOUTMDL_APPL_DATA

/* used for references on application functions */
# define RTE_SPDOUTMDL_APPL_CODE

/* used for references on application constants */
# define RTE_SPDOUTMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SpdOutMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SpdOutMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SpdOutMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SpdOutMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SpdOutMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SpdOutMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SpdOutMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SpdOutMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SPDVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SPDVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SPDVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_SPDVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_SPDVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SpdView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SpdView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SpdView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SpdView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SpdView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SpdView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SpdView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SpdView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SRVUSMMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SRVUSMMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SRVUSMMDL_APPL_DATA

/* used for references on application functions */
# define RTE_SRVUSMMDL_APPL_CODE

/* used for references on application constants */
# define RTE_SRVUSMMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SrvUsmMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SrvUsmMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SrvUsmMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SrvUsmMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SrvUsmMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SrvUsmMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SrvUsmMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SrvUsmMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STEERINGMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_STEERINGMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_STEERINGMDL_APPL_DATA

/* used for references on application functions */
# define RTE_STEERINGMDL_APPL_CODE

/* used for references on application constants */
# define RTE_STEERINGMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SteeringMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SteeringMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SteeringMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SteeringMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SteeringMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SteeringMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SteeringMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SteeringMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STPCDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_STPCDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_STPCDD_APPL_DATA

/* used for references on application functions */
# define RTE_STPCDD_APPL_CODE

/* used for references on application constants */
# define RTE_STPCDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: StpCdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define StpCdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: StpCdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define StpCdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: StpCdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define StpCdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define StpCdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define StpCdd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TCANADAPTERMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TCANADAPTERMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TCANADAPTERMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TCANADAPTERMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TCANADAPTERMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TCanAdapterMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TCanAdapterMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TCanAdapterMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TCanAdapterMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TCanAdapterMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TCanAdapterMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TCanAdapterMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TCanAdapterMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TACHMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TACHMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TACHMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TACHMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TACHMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TachMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TachMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TachMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TachMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TachMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TachMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TachMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TachMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TACHVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TACHVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TACHVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_TACHVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_TACHVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TachView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TachView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TachView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TachView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TachView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TachView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TachView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TachView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TAILLAMPMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TAILLAMPMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TAILLAMPMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TAILLAMPMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TAILLAMPMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TailLampMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TailLampMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TailLampMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TailLampMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TailLampMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TailLampMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TailLampMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TailLampMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TBTMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TBTMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TBTMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TBTMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TBTMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TbtMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TbtMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TbtMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TbtMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TbtMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TbtMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TbtMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TbtMdl_VAR_ZERO_INIT

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
 * Symbol: RTE_TPMSMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TPMSMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TPMSMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TPMSMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TPMSMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TpmsMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TpmsMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TpmsMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TpmsMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TpmsMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TpmsMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TpmsMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TpmsMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TRANSTEMPMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TRANSTEMPMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TRANSTEMPMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TRANSTEMPMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TRANSTEMPMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TransTempMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TransTempMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TransTempMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TransTempMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TransTempMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TransTempMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TransTempMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TransTempMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TRIPDISTMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TRIPDISTMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TRIPDISTMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TRIPDISTMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TRIPDISTMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TripDistMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TripDistMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TripDistMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TripDistMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TripDistMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TripDistMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TripDistMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TripDistMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TRIPFUELMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TRIPFUELMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TRIPFUELMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TRIPFUELMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TRIPFUELMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TripFuelMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TripFuelMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TripFuelMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TripFuelMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TripFuelMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TripFuelMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TripFuelMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TripFuelMdl_VAR_ZERO_INIT

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
 * Symbol: RTE_TTVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TTVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TTVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_TTVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_TTVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TtView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TtView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TtView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TtView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TtView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TtView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TtView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TtView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TURNSIGMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_TURNSIGMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TURNSIGMDL_APPL_DATA

/* used for references on application functions */
# define RTE_TURNSIGMDL_APPL_CODE

/* used for references on application constants */
# define RTE_TURNSIGMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TurnSigMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define TurnSigMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TurnSigMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define TurnSigMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TurnSigMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define TurnSigMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define TurnSigMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define TurnSigMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_UREAMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_UREAMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_UREAMDL_APPL_DATA

/* used for references on application functions */
# define RTE_UREAMDL_APPL_CODE

/* used for references on application constants */
# define RTE_UREAMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UreaMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define UreaMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UreaMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define UreaMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UreaMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define UreaMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define UreaMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define UreaMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_USMVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_USMVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_USMVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_USMVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_USMVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UsmView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define UsmView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UsmView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define UsmView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UsmView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define UsmView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define UsmView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define UsmView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VARMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_VARMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_VARMDL_APPL_DATA

/* used for references on application functions */
# define RTE_VARMDL_APPL_CODE

/* used for references on application constants */
# define RTE_VARMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: VarMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define VarMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: VarMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define VarMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: VarMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define VarMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define VarMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define VarMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_WATSEPMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_WATSEPMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WATSEPMDL_APPL_DATA

/* used for references on application functions */
# define RTE_WATSEPMDL_APPL_CODE

/* used for references on application constants */
# define RTE_WATSEPMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WatSepMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define WatSepMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WatSepMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define WatSepMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WatSepMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define WatSepMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define WatSepMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define WatSepMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_WDGM_OSAPPLICATION_TRUSTED_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_WDGM_OSAPPLICATION_TRUSTED_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WDGM_OSAPPLICATION_TRUSTED_APPL_DATA

/* used for references on application functions */
# define RTE_WDGM_OSAPPLICATION_TRUSTED_APPL_CODE

/* used for references on application constants */
# define RTE_WDGM_OSAPPLICATION_TRUSTED_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_OsApplication_Trusted_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define WdgM_OsApplication_Trusted_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_OsApplication_Trusted_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define WdgM_OsApplication_Trusted_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_OsApplication_Trusted_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define WdgM_OsApplication_Trusted_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define WdgM_OsApplication_Trusted_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define WdgM_OsApplication_Trusted_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_WELCOMEMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_WELCOMEMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WELCOMEMDL_APPL_DATA

/* used for references on application functions */
# define RTE_WELCOMEMDL_APPL_CODE

/* used for references on application constants */
# define RTE_WELCOMEMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WelcomeMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define WelcomeMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WelcomeMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define WelcomeMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WelcomeMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define WelcomeMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define WelcomeMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define WelcomeMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_WIPERMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_WIPERMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WIPERMDL_APPL_DATA

/* used for references on application functions */
# define RTE_WIPERMDL_APPL_CODE

/* used for references on application constants */
# define RTE_WIPERMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WiperMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define WiperMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WiperMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define WiperMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WiperMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define WiperMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define WiperMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define WiperMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_WPCMDL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_WPCMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WPCMDL_APPL_DATA

/* used for references on application functions */
# define RTE_WPCMDL_APPL_CODE

/* used for references on application constants */
# define RTE_WPCMDL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WpcMdl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define WpcMdl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WpcMdl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define WpcMdl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WpcMdl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define WpcMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define WpcMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define WpcMdl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_WRNVIEW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_WRNVIEW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WRNVIEW_APPL_DATA

/* used for references on application functions */
# define RTE_WRNVIEW_APPL_CODE

/* used for references on application constants */
# define RTE_WRNVIEW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WrnView_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define WrnView_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WrnView_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define WrnView_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WrnView_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define WrnView_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define WrnView_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define WrnView_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NVBLOCKSWCOMPONENTTYPE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NVBLOCKSWCOMPONENTTYPE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NVBLOCKSWCOMPONENTTYPE_APPL_DATA

/* used for references on application functions */
# define RTE_NVBLOCKSWCOMPONENTTYPE_APPL_CODE

/* used for references on application constants */
# define RTE_NVBLOCKSWCOMPONENTTYPE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvBlockSwComponentType_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define NvBlockSwComponentType_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvBlockSwComponentType_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define NvBlockSwComponentType_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvBlockSwComponentType_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define NvBlockSwComponentType_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define NvBlockSwComponentType_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define NvBlockSwComponentType_VAR_ZERO_INIT

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
/***  Start of saved code (symbol: compiler abstraction implementation:WdgM_OsApplication_Trusted_VAR)  *****/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define WdgM_OsApplication_Trusted_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define WdgM_OsApplication_Trusted_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define WdgM_OsApplication_Trusted_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:WdgM_OsApplication_Trusted_CONST)  ***/

/* used for global or static SWC specific constants */
# define WdgM_OsApplication_Trusted_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_WDGM_OSAPPLICATION_TRUSTED_APPL)  */

/* used for references on application variables */
# define RTE_WDGM_OSAPPLICATION_TRUSTED_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WDGM_OSAPPLICATION_TRUSTED_APPL_DATA

/* used for references on application functions */
# define RTE_WDGM_OSAPPLICATION_TRUSTED_APPL_CODE

/* used for references on application constants */
# define RTE_WDGM_OSAPPLICATION_TRUSTED_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:WdgM_OsApplication_Trusted_CODE)  ****/

/* used for SWC specific code */
# define WdgM_OsApplication_Trusted_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:WdgM_SafetyOsApplication_CONST)  *****/

/* used for global or static SWC specific constants */
# define WdgM_SafetyOsApplication_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:WdgM_SafetyOsApplication_CODE)  ******/

/* used for SWC specific code */
# define WdgM_SafetyOsApplication_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:WdgM_SafetyOsApplication_VAR)  *******/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define WdgM_SafetyOsApplication_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define WdgM_SafetyOsApplication_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define WdgM_SafetyOsApplication_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_WDGM_SAFETYOSAPPLICATION_APPL)  **/

/* used for references on application variables */
# define RTE_WDGM_SAFETYOSAPPLICATION_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WDGM_SAFETYOSAPPLICATION_APPL_DATA

/* used for references on application functions */
# define RTE_WDGM_SAFETYOSAPPLICATION_APPL_CODE

/* used for references on application constants */
# define RTE_WDGM_SAFETYOSAPPLICATION_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_MULTIFUNSWMDL_APPL)  *************/

/* used for references on application variables */
# define RTE_MULTIFUNSWMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MULTIFUNSWMDL_APPL_DATA

/* used for references on application functions */
# define RTE_MULTIFUNSWMDL_APPL_CODE

/* used for references on application constants */
# define RTE_MULTIFUNSWMDL_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:MultiFunSwMdl_CODE)  *****************/

/* used for SWC specific code */
# define MultiFunSwMdl_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:MultiFunSwMdl_VAR)  ******************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define MultiFunSwMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define MultiFunSwMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define MultiFunSwMdl_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:MultiFunSwMdl_CONST)  ****************/

/* used for global or static SWC specific constants */
# define MultiFunSwMdl_CONST

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CONST_DEFAULT_RTE_CDATA_GROUP)  **/

# define RTE_CONST_DEFAULT_RTE_CDATA_GROUP

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:HudMdl_CODE)  ************************/

/* used for SWC specific code */
# define HudMdl_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:HudMdl_VAR)  *************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define HudMdl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define HudMdl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define HudMdl_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:HudMdl_CONST)  ***********************/

/* used for global or static SWC specific constants */
# define HudMdl_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_HUDMDL_APPL)  ********************/

/* used for references on application variables */
# define RTE_HUDMDL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_HUDMDL_APPL_DATA

/* used for references on application functions */
# define RTE_HUDMDL_APPL_CODE

/* used for references on application constants */
# define RTE_HUDMDL_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* _RTE_COMPILER_CFG_H */
