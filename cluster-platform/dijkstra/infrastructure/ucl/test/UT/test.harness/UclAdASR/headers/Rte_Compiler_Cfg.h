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
 *        Config:  L21B_COM.dpa
 *   ECU-Project:  METER
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
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
 * Symbol: RTE_ALTIACDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ALTIACDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ALTIACDD_APPL_DATA

/* used for references on application functions */
# define RTE_ALTIACDD_APPL_CODE

/* used for references on application constants */
# define RTE_ALTIACDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AltiaCdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AltiaCdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AltiaCdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AltiaCdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AltiaCdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AltiaCdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AltiaCdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AltiaCdd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ALTIACTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ALTIACTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ALTIACTRL_APPL_DATA

/* used for references on application functions */
# define RTE_ALTIACTRL_APPL_CODE

/* used for references on application constants */
# define RTE_ALTIACTRL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AltiaCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AltiaCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AltiaCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AltiaCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AltiaCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AltiaCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AltiaCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AltiaCtrl_VAR_ZERO_INIT

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
 * Symbol: RTE_BSWC_APPINTRPT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BSWC_APPINTRPT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BSWC_APPINTRPT_APPL_DATA

/* used for references on application functions */
# define RTE_BSWC_APPINTRPT_APPL_CODE

/* used for references on application constants */
# define RTE_BSWC_APPINTRPT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Bswc_AppIntrpt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Bswc_AppIntrpt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Bswc_AppIntrpt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Bswc_AppIntrpt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Bswc_AppIntrpt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Bswc_AppIntrpt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Bswc_AppIntrpt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Bswc_AppIntrpt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BSWC_VCAN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BSWC_VCAN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BSWC_VCAN_APPL_DATA

/* used for references on application functions */
# define RTE_BSWC_VCAN_APPL_CODE

/* used for references on application constants */
# define RTE_BSWC_VCAN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Bswc_VCAN_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Bswc_VCAN_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Bswc_VCAN_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Bswc_VCAN_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Bswc_VCAN_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Bswc_VCAN_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Bswc_VCAN_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Bswc_VCAN_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CMCAN_CDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CMCAN_CDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CMCAN_CDD_APPL_DATA

/* used for references on application functions */
# define RTE_CMCAN_CDD_APPL_CODE

/* used for references on application constants */
# define RTE_CMCAN_CDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CMcan_cdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CMcan_cdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CMcan_cdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CMcan_cdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CMcan_cdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CMcan_cdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CMcan_cdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CMcan_cdd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CMFBSTUBS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CMFBSTUBS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CMFBSTUBS_APPL_DATA

/* used for references on application functions */
# define RTE_CMFBSTUBS_APPL_CODE

/* used for references on application constants */
# define RTE_CMFBSTUBS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CmfbStubs_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CmfbStubs_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CmfbStubs_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CmfbStubs_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CmfbStubs_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CmfbStubs_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CmfbStubs_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CmfbStubs_VAR_ZERO_INIT

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
 * Symbol: RTE_CTRL_MCANPOPUP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTRL_MCANPOPUP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTRL_MCANPOPUP_APPL_DATA

/* used for references on application functions */
# define RTE_CTRL_MCANPOPUP_APPL_CODE

/* used for references on application constants */
# define RTE_CTRL_MCANPOPUP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_McanPopup_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Ctrl_McanPopup_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_McanPopup_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Ctrl_McanPopup_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_McanPopup_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Ctrl_McanPopup_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Ctrl_McanPopup_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Ctrl_McanPopup_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTRL_WUS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTRL_WUS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTRL_WUS_APPL_DATA

/* used for references on application functions */
# define RTE_CTRL_WUS_APPL_CODE

/* used for references on application constants */
# define RTE_CTRL_WUS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WUS_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Ctrl_WUS_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WUS_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Ctrl_WUS_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WUS_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Ctrl_WUS_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Ctrl_WUS_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Ctrl_WUS_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTRL_INDICATOR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTRL_INDICATOR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTRL_INDICATOR_APPL_DATA

/* used for references on application functions */
# define RTE_CTRL_INDICATOR_APPL_CODE

/* used for references on application constants */
# define RTE_CTRL_INDICATOR_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_indicator_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Ctrl_indicator_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_indicator_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Ctrl_indicator_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_indicator_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Ctrl_indicator_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Ctrl_indicator_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Ctrl_indicator_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTRL_TELLTALE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTRL_TELLTALE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTRL_TELLTALE_APPL_DATA

/* used for references on application functions */
# define RTE_CTRL_TELLTALE_APPL_CODE

/* used for references on application constants */
# define RTE_CTRL_TELLTALE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_telltale_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Ctrl_telltale_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_telltale_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Ctrl_telltale_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_telltale_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Ctrl_telltale_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Ctrl_telltale_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Ctrl_telltale_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTRL_WARNING_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTRL_WARNING_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTRL_WARNING_APPL_DATA

/* used for references on application functions */
# define RTE_CTRL_WARNING_APPL_CODE

/* used for references on application constants */
# define RTE_CTRL_WARNING_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_warning_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Ctrl_warning_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_warning_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Ctrl_warning_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_warning_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Ctrl_warning_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Ctrl_warning_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Ctrl_warning_VAR_ZERO_INIT

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
 * Symbol: RTE_FUEL_CDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_FUEL_CDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_FUEL_CDD_APPL_DATA

/* used for references on application functions */
# define RTE_FUEL_CDD_APPL_CODE

/* used for references on application constants */
# define RTE_FUEL_CDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Fuel_Cdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Fuel_Cdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Fuel_Cdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Fuel_Cdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Fuel_Cdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Fuel_Cdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Fuel_Cdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Fuel_Cdd_VAR_ZERO_INIT

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
 * Symbol: RTE_IOHWAB_PWM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IOHWAB_PWM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWAB_PWM_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWAB_PWM_APPL_CODE

/* used for references on application constants */
# define RTE_IOHWAB_PWM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_PWM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define IoHwAb_PWM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_PWM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define IoHwAb_PWM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_PWM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define IoHwAb_PWM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define IoHwAb_PWM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define IoHwAb_PWM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IPCLCDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IPCLCDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IPCLCDD_APPL_DATA

/* used for references on application functions */
# define RTE_IPCLCDD_APPL_CODE

/* used for references on application constants */
# define RTE_IPCLCDD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IpclCdd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define IpclCdd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IpclCdd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define IpclCdd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IpclCdd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define IpclCdd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define IpclCdd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define IpclCdd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_CONFIG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_CONFIG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_CONFIG_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_CONFIG_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_CONFIG_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MDL_Config_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define MDL_Config_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MDL_Config_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define MDL_Config_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MDL_Config_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define MDL_Config_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define MDL_Config_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define MDL_Config_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_PHONEMCAN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_PHONEMCAN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_PHONEMCAN_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_PHONEMCAN_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_PHONEMCAN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MDL_PhoneMcan_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define MDL_PhoneMcan_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MDL_PhoneMcan_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define MDL_PhoneMcan_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MDL_PhoneMcan_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define MDL_PhoneMcan_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define MDL_PhoneMcan_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define MDL_PhoneMcan_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ABS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ABS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ABS_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ABS_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ABS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ABS_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_ABS_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ABS_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_ABS_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ABS_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_ABS_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_ABS_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_ABS_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ASL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ASL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ASL_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ASL_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ASL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ASL_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_ASL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ASL_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_ASL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ASL_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_ASL_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_ASL_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_ASL_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ACC_CRANK_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ACC_CRANK_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ACC_CRANK_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ACC_CRANK_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ACC_CRANK_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Acc_Crank_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Acc_Crank_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Acc_Crank_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Acc_Crank_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Acc_Crank_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Acc_Crank_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Acc_Crank_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Acc_Crank_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ACCELECO_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ACCELECO_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ACCELECO_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ACCELECO_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ACCELECO_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AccelEco_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_AccelEco_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AccelEco_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_AccelEco_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AccelEco_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_AccelEco_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_AccelEco_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_AccelEco_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_AIRBAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_AIRBAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_AIRBAG_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_AIRBAG_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_AIRBAG_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Airbag_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Airbag_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Airbag_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Airbag_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Airbag_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Airbag_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Airbag_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Airbag_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ANTILOCK_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ANTILOCK_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ANTILOCK_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ANTILOCK_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ANTILOCK_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AntiLock_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_AntiLock_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AntiLock_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_AntiLock_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AntiLock_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_AntiLock_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_AntiLock_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_AntiLock_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ATCVT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ATCVT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ATCVT_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ATCVT_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ATCVT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AtCvt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_AtCvt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AtCvt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_AtCvt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AtCvt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_AtCvt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_AtCvt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_AtCvt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_AUDIOMCAN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_AUDIOMCAN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_AUDIOMCAN_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_AUDIOMCAN_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_AUDIOMCAN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AudioMcan_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_AudioMcan_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AudioMcan_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_AudioMcan_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_AudioMcan_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_AudioMcan_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_AudioMcan_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_AudioMcan_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_BUTTON_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_BUTTON_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_BUTTON_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_BUTTON_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_BUTTON_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Button_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Button_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Button_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Button_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Button_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Button_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Button_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Button_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_CANNM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_CANNM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_CANNM_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_CANNM_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_CANNM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CANNm_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_CANNm_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CANNm_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_CANNm_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CANNm_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_CANNm_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_CANNm_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_CANNm_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_CAN_ADAPTER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_CAN_ADAPTER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_CAN_ADAPTER_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_CAN_ADAPTER_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_CAN_ADAPTER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CAN_Adapter_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_CAN_Adapter_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CAN_Adapter_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_CAN_Adapter_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CAN_Adapter_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_CAN_Adapter_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_CAN_Adapter_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_CAN_Adapter_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_CENG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_CENG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_CENG_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_CENG_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_CENG_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Ceng_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Ceng_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Ceng_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Ceng_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Ceng_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Ceng_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Ceng_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Ceng_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_CHARCODE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_CHARCODE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_CHARCODE_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_CHARCODE_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_CHARCODE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CharCode_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_CharCode_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CharCode_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_CharCode_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CharCode_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_CharCode_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_CharCode_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_CharCode_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_CHARGE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_CHARGE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_CHARGE_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_CHARGE_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_CHARGE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Charge_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Charge_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Charge_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Charge_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Charge_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Charge_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Charge_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Charge_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_COMBISWITCH_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_COMBISWITCH_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_COMBISWITCH_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_COMBISWITCH_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_COMBISWITCH_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CombiSwitch_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_CombiSwitch_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CombiSwitch_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_CombiSwitch_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_CombiSwitch_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_CombiSwitch_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_CombiSwitch_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_CombiSwitch_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_DAS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_DAS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_DAS_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_DAS_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_DAS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_DAS_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_DAS_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_DAS_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_DAS_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_DAS_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_DAS_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_DAS_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_DAS_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_DATAADAPTER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_DATAADAPTER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_DATAADAPTER_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_DATAADAPTER_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_DATAADAPTER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_DataAdapter_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_DataAdapter_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_DataAdapter_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_DataAdapter_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_DataAdapter_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_DataAdapter_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_DataAdapter_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_DataAdapter_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_DIMMING_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_DIMMING_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_DIMMING_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_DIMMING_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_DIMMING_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Dimming_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Dimming_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Dimming_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Dimming_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Dimming_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Dimming_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Dimming_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Dimming_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_DOORAJAR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_DOORAJAR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_DOORAJAR_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_DOORAJAR_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_DOORAJAR_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_DoorAjar_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_DoorAjar_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_DoorAjar_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_DoorAjar_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_DoorAjar_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_DoorAjar_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_DoorAjar_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_DoorAjar_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_EAP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_EAP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_EAP_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_EAP_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_EAP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_EAP_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_EAP_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_EAP_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_EAP_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_EAP_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_EAP_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_EAP_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_EAP_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ECM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ECM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ECM_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ECM_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ECM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ECM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_ECM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ECM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_ECM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ECM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_ECM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_ECM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_ECM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_EPS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_EPS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_EPS_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_EPS_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_EPS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_EPS_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_EPS_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_EPS_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_EPS_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_EPS_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_EPS_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_EPS_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_EPS_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ECOMODE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ECOMODE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ECOMODE_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ECOMODE_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ECOMODE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_EcoMode_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_EcoMode_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_EcoMode_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_EcoMode_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_EcoMode_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_EcoMode_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_EcoMode_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_EcoMode_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ECT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ECT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ECT_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ECT_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ECT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Ect_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Ect_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Ect_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Ect_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Ect_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Ect_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Ect_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Ect_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_FEB_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_FEB_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_FEB_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_FEB_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_FEB_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_FEB_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_FEB_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_FEB_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_FEB_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_FEB_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_FEB_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_FEB_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_FEB_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_FOGIND_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_FOGIND_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_FOGIND_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_FOGIND_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_FOGIND_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_FogInd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_FogInd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_FogInd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_FogInd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_FogInd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_FogInd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_FogInd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_FogInd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_FUELCAP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_FUELCAP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_FUELCAP_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_FUELCAP_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_FUELCAP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_FuelCap_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_FuelCap_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_FuelCap_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_FuelCap_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_FuelCap_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_FuelCap_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_FuelCap_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_FuelCap_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_HMISTUB_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_HMISTUB_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_HMISTUB_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_HMISTUB_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_HMISTUB_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_HmiStub_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_HmiStub_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_HmiStub_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_HmiStub_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_HmiStub_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_HmiStub_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_HmiStub_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_HmiStub_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ICC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ICC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ICC_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ICC_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ICC_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ICC_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_ICC_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ICC_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_ICC_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ICC_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_ICC_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_ICC_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_ICC_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_IDM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_IDM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_IDM_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_IDM_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_IDM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IDM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_IDM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IDM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_IDM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IDM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_IDM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_IDM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_IDM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ITS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ITS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ITS_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ITS_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ITS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ITS_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_ITS_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ITS_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_ITS_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ITS_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_ITS_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_ITS_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_ITS_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_IBAAEB_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_IBAAEB_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_IBAAEB_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_IBAAEB_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_IBAAEB_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IbaAeb_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_IbaAeb_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IbaAeb_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_IbaAeb_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IbaAeb_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_IbaAeb_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_IbaAeb_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_IbaAeb_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_IDLSTPIND_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_IDLSTPIND_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_IDLSTPIND_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_IDLSTPIND_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_IDLSTPIND_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IdlStpInd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_IdlStpInd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IdlStpInd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_IdlStpInd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IdlStpInd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_IdlStpInd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_IdlStpInd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_IdlStpInd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_IDLESTOP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_IDLESTOP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_IDLESTOP_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_IDLESTOP_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_IDLESTOP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IdleStop_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_IdleStop_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IdleStop_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_IdleStop_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_IdleStop_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_IdleStop_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_IdleStop_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_IdleStop_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_IKEY_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_IKEY_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_IKEY_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_IKEY_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_IKEY_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Ikey_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Ikey_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Ikey_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Ikey_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Ikey_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Ikey_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Ikey_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Ikey_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_KEYINREM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_KEYINREM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_KEYINREM_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_KEYINREM_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_KEYINREM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_KeyInRem_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_KeyInRem_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_KeyInRem_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_KeyInRem_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_KeyInRem_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_KeyInRem_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_KeyInRem_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_KeyInRem_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_LEDHLAMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_LEDHLAMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_LEDHLAMP_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_LEDHLAMP_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_LEDHLAMP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_LedHlamp_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_LedHlamp_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_LedHlamp_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_LedHlamp_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_LedHlamp_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_LedHlamp_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_LedHlamp_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_LedHlamp_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_LIGHTREM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_LIGHTREM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_LIGHTREM_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_LIGHTREM_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_LIGHTREM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_LightRem_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_LightRem_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_LightRem_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_LightRem_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_LightRem_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_LightRem_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_LightRem_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_LightRem_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_LOWWASHER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_LOWWASHER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_LOWWASHER_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_LOWWASHER_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_LOWWASHER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_LowWasher_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_LowWasher_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_LowWasher_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_LowWasher_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_LowWasher_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_LowWasher_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_LowWasher_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_LowWasher_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_MSTRWRN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_MSTRWRN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_MSTRWRN_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_MSTRWRN_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_MSTRWRN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_MstrWrn_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_MstrWrn_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_MstrWrn_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_MstrWrn_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_MstrWrn_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_MstrWrn_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_MstrWrn_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_MstrWrn_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_MULTIDISP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_MULTIDISP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_MULTIDISP_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_MULTIDISP_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_MULTIDISP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_MultiDisp_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_MultiDisp_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_MultiDisp_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_MultiDisp_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_MultiDisp_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_MultiDisp_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_MultiDisp_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_MultiDisp_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_NAVIMCAN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_NAVIMCAN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_NAVIMCAN_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_NAVIMCAN_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_NAVIMCAN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_NaviMcan_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_NaviMcan_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_NaviMcan_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_NaviMcan_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_NaviMcan_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_NaviMcan_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_NaviMcan_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_NaviMcan_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_OAT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_OAT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_OAT_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_OAT_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_OAT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_OAT_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_OAT_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_OAT_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_OAT_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_OAT_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_OAT_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_OAT_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_OAT_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_OCS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_OCS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_OCS_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_OCS_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_OCS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_OCS_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_OCS_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_OCS_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_OCS_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_OCS_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_OCS_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_OCS_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_OCS_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ODOFF_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ODOFF_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ODOFF_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ODOFF_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ODOFF_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ODOff_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_ODOff_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ODOff_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_ODOff_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ODOff_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_ODOff_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_ODOff_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_ODOff_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_ODO_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_ODO_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_ODO_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_ODO_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_ODO_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Odo_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Odo_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Odo_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Odo_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Odo_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Odo_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Odo_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Odo_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_OILPRE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_OILPRE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_OILPRE_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_OILPRE_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_OILPRE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_OilPre_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_OilPre_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_OilPre_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_OilPre_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_OilPre_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_OilPre_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_OilPre_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_OilPre_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_PARKBRAKE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_PARKBRAKE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_PARKBRAKE_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_PARKBRAKE_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_PARKBRAKE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ParkBrake_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_ParkBrake_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ParkBrake_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_ParkBrake_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_ParkBrake_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_ParkBrake_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_ParkBrake_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_ParkBrake_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_POSLMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_POSLMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_POSLMP_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_POSLMP_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_POSLMP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Poslmp_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Poslmp_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Poslmp_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Poslmp_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Poslmp_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Poslmp_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Poslmp_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Poslmp_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_RES_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_RES_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_RES_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_RES_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_RES_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_RES_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_RES_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_RES_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_RES_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_RES_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_RES_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_RES_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_RES_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_REARSEATBELT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_REARSEATBELT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_REARSEATBELT_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_REARSEATBELT_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_REARSEATBELT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_RearSeatBelt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_RearSeatBelt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_RearSeatBelt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_RearSeatBelt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_RearSeatBelt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_RearSeatBelt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_RearSeatBelt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_RearSeatBelt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_REVERSE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_REVERSE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_REVERSE_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_REVERSE_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_REVERSE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Reverse_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Reverse_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Reverse_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Reverse_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Reverse_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Reverse_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Reverse_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Reverse_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_SMARTKEY_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_SMARTKEY_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_SMARTKEY_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_SMARTKEY_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_SMARTKEY_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SmartKey_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_SmartKey_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SmartKey_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_SmartKey_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SmartKey_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_SmartKey_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_SmartKey_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_SmartKey_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_SONAR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_SONAR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_SONAR_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_SONAR_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_SONAR_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Sonar_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Sonar_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Sonar_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Sonar_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Sonar_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Sonar_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Sonar_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Sonar_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_SPEED_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_SPEED_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_SPEED_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_SPEED_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_SPEED_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Speed_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Speed_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Speed_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Speed_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Speed_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Speed_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Speed_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Speed_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_TPMS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_TPMS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_TPMS_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_TPMS_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_TPMS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TPMS_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_TPMS_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TPMS_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_TPMS_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TPMS_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_TPMS_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_TPMS_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_TPMS_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_TSR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_TSR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_TSR_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_TSR_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_TSR_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TSR_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_TSR_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TSR_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_TSR_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TSR_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_TSR_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_TSR_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_TSR_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_TACHO_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_TACHO_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_TACHO_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_TACHO_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_TACHO_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Tacho_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_Tacho_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Tacho_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_Tacho_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Tacho_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_Tacho_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_Tacho_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_Tacho_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_TRIPCOMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_TRIPCOMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_TRIPCOMP_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_TRIPCOMP_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_TRIPCOMP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TripComp_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_TripComp_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TripComp_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_TripComp_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TripComp_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_TripComp_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_TripComp_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_TripComp_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_TURNIND_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_TURNIND_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_TURNIND_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_TURNIND_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_TURNIND_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TurnInd_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_TurnInd_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TurnInd_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_TurnInd_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_TurnInd_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_TurnInd_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_TurnInd_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_TurnInd_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_VDC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_VDC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_VDC_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_VDC_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_VDC_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_VDC_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_VDC_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_VDC_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_VDC_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_VDC_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_VDC_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_VDC_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_VDC_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_BRAKE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_BRAKE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_BRAKE_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_BRAKE_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_BRAKE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_brake_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_brake_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_brake_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_brake_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_brake_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_brake_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_brake_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_brake_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_CRUISE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_CRUISE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_CRUISE_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_CRUISE_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_CRUISE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_cruise_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_cruise_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_cruise_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_cruise_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_cruise_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_cruise_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_cruise_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_cruise_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_GEARSHIFT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_GEARSHIFT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_GEARSHIFT_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_GEARSHIFT_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_GEARSHIFT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_gearshift_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_gearshift_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_gearshift_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_gearshift_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_gearshift_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_gearshift_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_gearshift_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_gearshift_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_HIBEAM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_HIBEAM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_HIBEAM_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_HIBEAM_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_HIBEAM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_hibeam_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_hibeam_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_hibeam_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_hibeam_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_hibeam_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_hibeam_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_hibeam_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_hibeam_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_OPNG_MOVIE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_OPNG_MOVIE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_OPNG_MOVIE_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_OPNG_MOVIE_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_OPNG_MOVIE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_opng_movie_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_opng_movie_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_opng_movie_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_opng_movie_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_opng_movie_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_opng_movie_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_opng_movie_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_opng_movie_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_SEATBELT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_SEATBELT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_SEATBELT_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_SEATBELT_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_SEATBELT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_seatbelt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_seatbelt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_seatbelt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_seatbelt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_seatbelt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_seatbelt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_seatbelt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_seatbelt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_SHIPPING_MODE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_SHIPPING_MODE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_SHIPPING_MODE_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_SHIPPING_MODE_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_SHIPPING_MODE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_shipping_mode_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_shipping_mode_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_shipping_mode_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_shipping_mode_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_shipping_mode_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_shipping_mode_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_shipping_mode_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_shipping_mode_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_SLIP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_SLIP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_SLIP_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_SLIP_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_SLIP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_slip_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_slip_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_slip_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_slip_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_slip_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_slip_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_slip_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_slip_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_SPORT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_SPORT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_SPORT_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_SPORT_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_SPORT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_sport_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_sport_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_sport_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_sport_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_sport_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_sport_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_sport_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_sport_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MDL_TCAN_ADAPTER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_MDL_TCAN_ADAPTER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_MDL_TCAN_ADAPTER_APPL_DATA

/* used for references on application functions */
# define RTE_MDL_TCAN_ADAPTER_APPL_CODE

/* used for references on application constants */
# define RTE_MDL_TCAN_ADAPTER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_tcan_Adapter_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Mdl_tcan_Adapter_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_tcan_Adapter_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Mdl_tcan_Adapter_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_tcan_Adapter_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Mdl_tcan_Adapter_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Mdl_tcan_Adapter_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Mdl_tcan_Adapter_VAR_ZERO_INIT

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
 * Symbol: RTE_SENS_ADAPT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SENS_ADAPT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SENS_ADAPT_APPL_DATA

/* used for references on application functions */
# define RTE_SENS_ADAPT_APPL_CODE

/* used for references on application constants */
# define RTE_SENS_ADAPT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SENS_Adapt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SENS_Adapt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SENS_Adapt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SENS_Adapt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SENS_Adapt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SENS_Adapt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SENS_Adapt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SENS_Adapt_VAR_ZERO_INIT

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
 * Symbol: RTE_SNDCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SNDCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SNDCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_SNDCTRL_APPL_CODE

/* used for references on application constants */
# define RTE_SNDCTRL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define SndCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define SndCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: SndCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define SndCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define SndCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define SndCtrl_VAR_ZERO_INIT

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
 * Symbol: RTE_UICTRL_BUTTON_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_UICTRL_BUTTON_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_UICTRL_BUTTON_APPL_DATA

/* used for references on application functions */
# define RTE_UICTRL_BUTTON_APPL_CODE

/* used for references on application constants */
# define RTE_UICTRL_BUTTON_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Button_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define UiCtrl_Button_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Button_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define UiCtrl_Button_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Button_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define UiCtrl_Button_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define UiCtrl_Button_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define UiCtrl_Button_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_UICTRL_HMI_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_UICTRL_HMI_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_UICTRL_HMI_APPL_DATA

/* used for references on application functions */
# define RTE_UICTRL_HMI_APPL_CODE

/* used for references on application constants */
# define RTE_UICTRL_HMI_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_HMI_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define UiCtrl_HMI_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_HMI_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define UiCtrl_HMI_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_HMI_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define UiCtrl_HMI_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define UiCtrl_HMI_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define UiCtrl_HMI_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_UICTRL_HDRFTR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_UICTRL_HDRFTR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_UICTRL_HDRFTR_APPL_DATA

/* used for references on application functions */
# define RTE_UICTRL_HDRFTR_APPL_CODE

/* used for references on application constants */
# define RTE_UICTRL_HDRFTR_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_HdrFtr_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define UiCtrl_HdrFtr_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_HdrFtr_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define UiCtrl_HdrFtr_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_HdrFtr_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define UiCtrl_HdrFtr_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define UiCtrl_HdrFtr_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define UiCtrl_HdrFtr_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_UICTRL_MENU_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_UICTRL_MENU_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_UICTRL_MENU_APPL_DATA

/* used for references on application functions */
# define RTE_UICTRL_MENU_APPL_CODE

/* used for references on application constants */
# define RTE_UICTRL_MENU_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Menu_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define UiCtrl_Menu_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Menu_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define UiCtrl_Menu_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Menu_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define UiCtrl_Menu_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define UiCtrl_Menu_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define UiCtrl_Menu_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_UICTRL_OPNGMOVIE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_UICTRL_OPNGMOVIE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_UICTRL_OPNGMOVIE_APPL_DATA

/* used for references on application functions */
# define RTE_UICTRL_OPNGMOVIE_APPL_CODE

/* used for references on application constants */
# define RTE_UICTRL_OPNGMOVIE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_OpngMovie_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define UiCtrl_OpngMovie_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_OpngMovie_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define UiCtrl_OpngMovie_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_OpngMovie_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define UiCtrl_OpngMovie_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define UiCtrl_OpngMovie_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define UiCtrl_OpngMovie_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_UICTRL_POPUP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_UICTRL_POPUP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_UICTRL_POPUP_APPL_DATA

/* used for references on application functions */
# define RTE_UICTRL_POPUP_APPL_CODE

/* used for references on application constants */
# define RTE_UICTRL_POPUP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Popup_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define UiCtrl_Popup_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Popup_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define UiCtrl_Popup_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Popup_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define UiCtrl_Popup_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define UiCtrl_Popup_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define UiCtrl_Popup_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_UICTRL_WARNING_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_UICTRL_WARNING_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_UICTRL_WARNING_APPL_DATA

/* used for references on application functions */
# define RTE_UICTRL_WARNING_APPL_CODE

/* used for references on application constants */
# define RTE_UICTRL_WARNING_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Warning_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define UiCtrl_Warning_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Warning_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define UiCtrl_Warning_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: UiCtrl_Warning_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define UiCtrl_Warning_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define UiCtrl_Warning_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define UiCtrl_Warning_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VIEW_POINTERS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_VIEW_POINTERS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_VIEW_POINTERS_APPL_DATA

/* used for references on application functions */
# define RTE_VIEW_POINTERS_APPL_CODE

/* used for references on application constants */
# define RTE_VIEW_POINTERS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: View_Pointers_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define View_Pointers_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: View_Pointers_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define View_Pointers_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: View_Pointers_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define View_Pointers_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define View_Pointers_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define View_Pointers_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VIEW_TELLTALE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_VIEW_TELLTALE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_VIEW_TELLTALE_APPL_DATA

/* used for references on application functions */
# define RTE_VIEW_TELLTALE_APPL_CODE

/* used for references on application constants */
# define RTE_VIEW_TELLTALE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: View_telltale_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define View_telltale_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: View_telltale_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define View_telltale_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: View_telltale_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define View_telltale_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define View_telltale_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define View_telltale_VAR_ZERO_INIT

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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* _RTE_COMPILER_CFG_H */
