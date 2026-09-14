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
 *          File:  Rte_MemMap.h
 *        Config:  iMX8.dpa
 *   ECU-Project:  METER
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700905 for Visteon Electronics Germany GmbH
 *
 *   Description:  RTE Memory Mapping header file
 *********************************************************************************************************************/

/* PRQA S 0883 EOF */ /* MD_Rte_0883 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * RTE specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CODE
# undef RTE_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_OsApplication_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_OsApplication_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_ZERO_INIT_8BIT
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_ZERO_INIT_8BIT
# undef RTE_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_OsApplication_VAR_8BIT
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_OsApplication_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CONST_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
# undef RTE_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_APPL_CODE
# undef RTE_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CODE
# undef RTE_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_OsApplication_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_OsApplication_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef RTE_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_OsApplication_VAR_8BIT
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_OsApplication_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CONST_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
# undef RTE_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_APPL_CODE
# undef RTE_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * SW-C specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_ABSMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_ABSMDL_APPL_CODE
# undef RTE_START_SEC_ABSMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_ACCMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_ACCMDL_APPL_CODE
# undef RTE_START_SEC_ACCMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_APPCTRL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_APPCTRL_APPL_CODE
# undef RTE_START_SEC_APPCTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AUTOHIGHBEAMFAILMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AUTOHIGHBEAMFAILMDL_APPL_CODE
# undef RTE_START_SEC_AUTOHIGHBEAMFAILMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AUTOHIGHBEAMMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AUTOHIGHBEAMMDL_APPL_CODE
# undef RTE_START_SEC_AUTOHIGHBEAMMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_AUTOLIGHTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_AUTOLIGHTMDL_APPL_CODE
# undef RTE_START_SEC_AUTOLIGHTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BATTERYMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BATTERYMDL_APPL_CODE
# undef RTE_START_SEC_BATTERYMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BRAKEAMBERMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BRAKEAMBERMDL_APPL_CODE
# undef RTE_START_SEC_BRAKEAMBERMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BRAKEHOLDMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BRAKEHOLDMDL_APPL_CODE
# undef RTE_START_SEC_BRAKEHOLDMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_BSWM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_BSWM_APPL_CODE
# undef RTE_START_SEC_BSWM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CANEVENTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CANEVENTMDL_APPL_CODE
# undef RTE_START_SEC_CANEVENTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CBRAKESYSTEM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CBRAKESYSTEM_APPL_CODE
# undef RTE_START_SEC_CBRAKESYSTEM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CGATEWAYMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CGATEWAYMDL_APPL_CODE
# undef RTE_START_SEC_CGATEWAYMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_COATMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_COATMDL_APPL_CODE
# undef RTE_START_SEC_COATMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CROTATEWHEEL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CROTATEWHEEL_APPL_CODE
# undef RTE_START_SEC_CROTATEWHEEL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CSEATBELT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CSEATBELT_APPL_CODE
# undef RTE_START_SEC_CSEATBELT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CHARGEPLUGCONNECT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CHARGEPLUGCONNECT_APPL_CODE
# undef RTE_START_SEC_CHARGEPLUGCONNECT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CHIMEMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CHIMEMDL_APPL_CODE
# undef RTE_START_SEC_CHIMEMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_COMEXT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_COMEXT_APPL_CODE
# undef RTE_START_SEC_COMEXT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_COMM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_COMM_APPL_CODE
# undef RTE_START_SEC_COMM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_COMMEXT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_COMMEXT_APPL_CODE
# undef RTE_START_SEC_COMMEXT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_COMVNIM_BCAN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_COMVNIM_BCAN_APPL_CODE
# undef RTE_START_SEC_COMVNIM_BCAN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_COMVNIM_FCAN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_COMVNIM_FCAN_APPL_CODE
# undef RTE_START_SEC_COMVNIM_FCAN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DCM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DCM_APPL_CODE
# undef RTE_START_SEC_DCM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DEMMASTER_0_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DEMMASTER_0_APPL_CODE
# undef RTE_START_SEC_DEMMASTER_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
# undef RTE_START_SEC_DEMSATELLITE_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DET_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DET_APPL_CODE
# undef RTE_START_SEC_DET_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DIMMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DIMMDL_APPL_CODE
# undef RTE_START_SEC_DIMMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_DOORAJARMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_DOORAJARMDL_APPL_CODE
# undef RTE_START_SEC_DOORAJARMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_ECUM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_ECUM_APPL_CODE
# undef RTE_START_SEC_ECUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_ECUMEXT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_ECUMEXT_APPL_CODE
# undef RTE_START_SEC_ECUMEXT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_EEP24XX_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_EEP24XX_APPL_CODE
# undef RTE_START_SEC_EEP24XX_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_FRONTFOGMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_FRONTFOGMDL_APPL_CODE
# undef RTE_START_SEC_FRONTFOGMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_GEARMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_GEARMDL_APPL_CODE
# undef RTE_START_SEC_GEARMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_HEADLIGHT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_HEADLIGHT_APPL_CODE
# undef RTE_START_SEC_HEADLIGHT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_HIBEAMMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_HIBEAMMDL_APPL_CODE
# undef RTE_START_SEC_HIBEAMMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_HILLSTARTBRAKEMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_HILLSTARTBRAKEMDL_APPL_CODE
# undef RTE_START_SEC_HILLSTARTBRAKEMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_IOHWAB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_IOHWAB_APPL_CODE
# undef RTE_START_SEC_IOHWAB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_IOHWABEXT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_IOHWABEXT_APPL_CODE
# undef RTE_START_SEC_IOHWABEXT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_LKAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_LKAS_APPL_CODE
# undef RTE_START_SEC_LKAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_LINCDD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_LINCDD_APPL_CODE
# undef RTE_START_SEC_LINCDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_LINIF_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_LINIF_APPL_CODE
# undef RTE_START_SEC_LINIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_LINSM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_LINSM_APPL_CODE
# undef RTE_START_SEC_LINSM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_LINSTUB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_LINSTUB_APPL_CODE
# undef RTE_START_SEC_LINSTUB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
# undef RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_MEMABSTRACTSTUB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_MEMABSTRACTSTUB_APPL_CODE
# undef RTE_START_SEC_MEMABSTRACTSTUB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_NVM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_NVM_APPL_CODE
# undef RTE_START_SEC_NVM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_NVMEXTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_NVMEXTMDL_APPL_CODE
# undef RTE_START_SEC_NVMEXTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_ODOTRIPMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_ODOTRIPMDL_APPL_CODE
# undef RTE_START_SEC_ODOTRIPMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE
# undef RTE_START_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_POWERCDD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_POWERCDD_APPL_CODE
# undef RTE_START_SEC_POWERCDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_POWERMODE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_POWERMODE_APPL_CODE
# undef RTE_START_SEC_POWERMODE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_POWERREDUCEDMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_POWERREDUCEDMDL_APPL_CODE
# undef RTE_START_SEC_POWERREDUCEDMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_POWERSTEERINGMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_POWERSTEERINGMDL_APPL_CODE
# undef RTE_START_SEC_POWERSTEERINGMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_POWERSYSTEMMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_POWERSYSTEMMDL_APPL_CODE
# undef RTE_START_SEC_POWERSYSTEMMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_POWERTAILGATE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_POWERTAILGATE_APPL_CODE
# undef RTE_START_SEC_POWERTAILGATE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_PRESSDOWNBRAKEMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_PRESSDOWNBRAKEMDL_APPL_CODE
# undef RTE_START_SEC_PRESSDOWNBRAKEMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_PWRMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_PWRMDL_APPL_CODE
# undef RTE_START_SEC_PWRMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_RANGE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_RANGE_APPL_CODE
# undef RTE_START_SEC_RANGE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_READYMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_READYMDL_APPL_CODE
# undef RTE_START_SEC_READYMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_REARFOGMD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_REARFOGMD_APPL_CODE
# undef RTE_START_SEC_REARFOGMD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SRS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SRS_APPL_CODE
# undef RTE_START_SEC_SRS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SEATBELTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SEATBELTMDL_APPL_CODE
# undef RTE_START_SEC_SEATBELTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SECURITY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SECURITY_APPL_CODE
# undef RTE_START_SEC_SECURITY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SMALLINDICATOR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SMALLINDICATOR_APPL_CODE
# undef RTE_START_SEC_SMALLINDICATOR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SMARTEMTRY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SMARTEMTRY_APPL_CODE
# undef RTE_START_SEC_SMARTEMTRY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SOC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SOC_APPL_CODE
# undef RTE_START_SEC_SOC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SPEEDMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SPEEDMDL_APPL_CODE
# undef RTE_START_SEC_SPEEDMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SPORTNORMALMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SPORTNORMALMDL_APPL_CODE
# undef RTE_START_SEC_SPORTNORMALMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_SWITCHCTRLMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_SWITCHCTRLMDL_APPL_CODE
# undef RTE_START_SEC_SWITCHCTRLMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TTMDL_APPL_CODE
# undef RTE_START_SEC_TTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TT_VIEW_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TT_VIEW_APPL_CODE
# undef RTE_START_SEC_TT_VIEW_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TURN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TURN_APPL_CODE
# undef RTE_START_SEC_TURN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TIMEMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TIMEMDL_APPL_CODE
# undef RTE_START_SEC_TIMEMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TMEXT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TMEXT_APPL_CODE
# undef RTE_START_SEC_TMEXT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_TPMSMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_TPMSMDL_APPL_CODE
# undef RTE_START_SEC_TPMSMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_UCLPROXYCDD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_UCLPROXYCDD_APPL_CODE
# undef RTE_START_SEC_UCLPROXYCDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_UPCL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_UPCL_APPL_CODE
# undef RTE_START_SEC_UPCL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VSA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VSA_APPL_CODE
# undef RTE_START_SEC_VSA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_WDGM_OSAPPLICATION_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_WDGM_OSAPPLICATION_APPL_CODE
# undef RTE_START_SEC_WDGM_OSAPPLICATION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_WRNCMP_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_WRNCMP_APPL_CODE
# undef RTE_START_SEC_WRNCMP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_WRNMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_WRNMDL_APPL_CODE
# undef RTE_START_SEC_WRNMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_ABSMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_ABSMDL_APPL_CODE
# undef RTE_STOP_SEC_ABSMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_ACCMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_ACCMDL_APPL_CODE
# undef RTE_STOP_SEC_ACCMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_APPCTRL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_APPCTRL_APPL_CODE
# undef RTE_STOP_SEC_APPCTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AUTOHIGHBEAMFAILMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AUTOHIGHBEAMFAILMDL_APPL_CODE
# undef RTE_STOP_SEC_AUTOHIGHBEAMFAILMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AUTOHIGHBEAMMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AUTOHIGHBEAMMDL_APPL_CODE
# undef RTE_STOP_SEC_AUTOHIGHBEAMMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_AUTOLIGHTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_AUTOLIGHTMDL_APPL_CODE
# undef RTE_STOP_SEC_AUTOLIGHTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BATTERYMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BATTERYMDL_APPL_CODE
# undef RTE_STOP_SEC_BATTERYMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BRAKEAMBERMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BRAKEAMBERMDL_APPL_CODE
# undef RTE_STOP_SEC_BRAKEAMBERMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BRAKEHOLDMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BRAKEHOLDMDL_APPL_CODE
# undef RTE_STOP_SEC_BRAKEHOLDMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_BSWM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_BSWM_APPL_CODE
# undef RTE_STOP_SEC_BSWM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CANEVENTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CANEVENTMDL_APPL_CODE
# undef RTE_STOP_SEC_CANEVENTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CBRAKESYSTEM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CBRAKESYSTEM_APPL_CODE
# undef RTE_STOP_SEC_CBRAKESYSTEM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CGATEWAYMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CGATEWAYMDL_APPL_CODE
# undef RTE_STOP_SEC_CGATEWAYMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_COATMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_COATMDL_APPL_CODE
# undef RTE_STOP_SEC_COATMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CROTATEWHEEL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CROTATEWHEEL_APPL_CODE
# undef RTE_STOP_SEC_CROTATEWHEEL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CSEATBELT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CSEATBELT_APPL_CODE
# undef RTE_STOP_SEC_CSEATBELT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CHARGEPLUGCONNECT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CHARGEPLUGCONNECT_APPL_CODE
# undef RTE_STOP_SEC_CHARGEPLUGCONNECT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CHIMEMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CHIMEMDL_APPL_CODE
# undef RTE_STOP_SEC_CHIMEMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_COMEXT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_COMEXT_APPL_CODE
# undef RTE_STOP_SEC_COMEXT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_COMM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_COMM_APPL_CODE
# undef RTE_STOP_SEC_COMM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_COMMEXT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_COMMEXT_APPL_CODE
# undef RTE_STOP_SEC_COMMEXT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_COMVNIM_BCAN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_COMVNIM_BCAN_APPL_CODE
# undef RTE_STOP_SEC_COMVNIM_BCAN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_COMVNIM_FCAN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_COMVNIM_FCAN_APPL_CODE
# undef RTE_STOP_SEC_COMVNIM_FCAN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DCM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DCM_APPL_CODE
# undef RTE_STOP_SEC_DCM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
# undef RTE_STOP_SEC_DEMMASTER_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
# undef RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DET_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DET_APPL_CODE
# undef RTE_STOP_SEC_DET_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DIMMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DIMMDL_APPL_CODE
# undef RTE_STOP_SEC_DIMMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_DOORAJARMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_DOORAJARMDL_APPL_CODE
# undef RTE_STOP_SEC_DOORAJARMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_ECUM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_ECUM_APPL_CODE
# undef RTE_STOP_SEC_ECUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_ECUMEXT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_ECUMEXT_APPL_CODE
# undef RTE_STOP_SEC_ECUMEXT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_EEP24XX_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_EEP24XX_APPL_CODE
# undef RTE_STOP_SEC_EEP24XX_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_FRONTFOGMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_FRONTFOGMDL_APPL_CODE
# undef RTE_STOP_SEC_FRONTFOGMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_GEARMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_GEARMDL_APPL_CODE
# undef RTE_STOP_SEC_GEARMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_HEADLIGHT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_HEADLIGHT_APPL_CODE
# undef RTE_STOP_SEC_HEADLIGHT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_HIBEAMMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_HIBEAMMDL_APPL_CODE
# undef RTE_STOP_SEC_HIBEAMMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_HILLSTARTBRAKEMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_HILLSTARTBRAKEMDL_APPL_CODE
# undef RTE_STOP_SEC_HILLSTARTBRAKEMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_IOHWAB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_IOHWAB_APPL_CODE
# undef RTE_STOP_SEC_IOHWAB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_IOHWABEXT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_IOHWABEXT_APPL_CODE
# undef RTE_STOP_SEC_IOHWABEXT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_LKAS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_LKAS_APPL_CODE
# undef RTE_STOP_SEC_LKAS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_LINCDD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_LINCDD_APPL_CODE
# undef RTE_STOP_SEC_LINCDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_LINIF_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_LINIF_APPL_CODE
# undef RTE_STOP_SEC_LINIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_LINSM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_LINSM_APPL_CODE
# undef RTE_STOP_SEC_LINSM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_LINSTUB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_LINSTUB_APPL_CODE
# undef RTE_STOP_SEC_LINSTUB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
# undef RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_MEMABSTRACTSTUB_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_MEMABSTRACTSTUB_APPL_CODE
# undef RTE_STOP_SEC_MEMABSTRACTSTUB_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_NVM_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_NVM_APPL_CODE
# undef RTE_STOP_SEC_NVM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_NVMEXTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_NVMEXTMDL_APPL_CODE
# undef RTE_STOP_SEC_NVMEXTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_ODOTRIPMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_ODOTRIPMDL_APPL_CODE
# undef RTE_STOP_SEC_ODOTRIPMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE
# undef RTE_STOP_SEC_OS_OSCORE_CORE0_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_POWERCDD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_POWERCDD_APPL_CODE
# undef RTE_STOP_SEC_POWERCDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_POWERMODE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_POWERMODE_APPL_CODE
# undef RTE_STOP_SEC_POWERMODE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_POWERREDUCEDMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_POWERREDUCEDMDL_APPL_CODE
# undef RTE_STOP_SEC_POWERREDUCEDMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_POWERSTEERINGMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_POWERSTEERINGMDL_APPL_CODE
# undef RTE_STOP_SEC_POWERSTEERINGMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_POWERSYSTEMMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_POWERSYSTEMMDL_APPL_CODE
# undef RTE_STOP_SEC_POWERSYSTEMMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_POWERTAILGATE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_POWERTAILGATE_APPL_CODE
# undef RTE_STOP_SEC_POWERTAILGATE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_PRESSDOWNBRAKEMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_PRESSDOWNBRAKEMDL_APPL_CODE
# undef RTE_STOP_SEC_PRESSDOWNBRAKEMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_PWRMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_PWRMDL_APPL_CODE
# undef RTE_STOP_SEC_PWRMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_RANGE_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_RANGE_APPL_CODE
# undef RTE_STOP_SEC_RANGE_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_READYMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_READYMDL_APPL_CODE
# undef RTE_STOP_SEC_READYMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_REARFOGMD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_REARFOGMD_APPL_CODE
# undef RTE_STOP_SEC_REARFOGMD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SRS_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SRS_APPL_CODE
# undef RTE_STOP_SEC_SRS_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SEATBELTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SEATBELTMDL_APPL_CODE
# undef RTE_STOP_SEC_SEATBELTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SECURITY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SECURITY_APPL_CODE
# undef RTE_STOP_SEC_SECURITY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SMALLINDICATOR_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SMALLINDICATOR_APPL_CODE
# undef RTE_STOP_SEC_SMALLINDICATOR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SMARTEMTRY_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SMARTEMTRY_APPL_CODE
# undef RTE_STOP_SEC_SMARTEMTRY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SOC_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SOC_APPL_CODE
# undef RTE_STOP_SEC_SOC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SPEEDMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SPEEDMDL_APPL_CODE
# undef RTE_STOP_SEC_SPEEDMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SPORTNORMALMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SPORTNORMALMDL_APPL_CODE
# undef RTE_STOP_SEC_SPORTNORMALMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_SWITCHCTRLMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_SWITCHCTRLMDL_APPL_CODE
# undef RTE_STOP_SEC_SWITCHCTRLMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TTMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TTMDL_APPL_CODE
# undef RTE_STOP_SEC_TTMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TT_VIEW_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TT_VIEW_APPL_CODE
# undef RTE_STOP_SEC_TT_VIEW_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TURN_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TURN_APPL_CODE
# undef RTE_STOP_SEC_TURN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TIMEMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TIMEMDL_APPL_CODE
# undef RTE_STOP_SEC_TIMEMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TMEXT_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TMEXT_APPL_CODE
# undef RTE_STOP_SEC_TMEXT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_TPMSMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_TPMSMDL_APPL_CODE
# undef RTE_STOP_SEC_TPMSMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_UCLPROXYCDD_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_UCLPROXYCDD_APPL_CODE
# undef RTE_STOP_SEC_UCLPROXYCDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_UPCL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_UPCL_APPL_CODE
# undef RTE_STOP_SEC_UPCL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VSA_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VSA_APPL_CODE
# undef RTE_STOP_SEC_VSA_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_WDGM_OSAPPLICATION_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_WDGM_OSAPPLICATION_APPL_CODE
# undef RTE_STOP_SEC_WDGM_OSAPPLICATION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_WRNCMP_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_WRNCMP_APPL_CODE
# undef RTE_STOP_SEC_WRNCMP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_WRNMDL_APPL_CODE
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_WRNMDL_APPL_CODE
# undef RTE_STOP_SEC_WRNMDL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * OS Application specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_OsApplication_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_OsApplication_NOINIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_OsApplication_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_OsApplication_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_OsApplication_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_OsApplication_ZERO_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_OsApplication_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_OsApplication_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_VAR_OsApplication_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_VAR_OsApplication_INIT_UNSPECIFIED
# undef RTE_START_SEC_VAR_OsApplication_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_START_SEC_OsApplication_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_OsApplication_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_OsApplication_NOINIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_OsApplication_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_OsApplication_VAR_NOINIT_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_OsApplication_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_OsApplication_ZERO_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_OsApplication_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_OsApplication_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_VAR_OsApplication_INIT_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_VAR_OsApplication_INIT_UNSPECIFIED
# undef RTE_STOP_SEC_VAR_OsApplication_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define OS_STOP_SEC_OsApplication_VAR_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Calibration Parameter specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# undef RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
 *********************************************************************************************************************/

#ifdef RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# undef RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!        << Start of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_OS_MEMMAP_INCLUDE
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0883:  MISRA rule: 19.15
     Reason:     AUTOSAR SWS Memory Mapping requires inclusion of MemMap.h multiple times in a file in order to
                 select appropriate #pragma directives.
     Risk:       MemMap.h is provided by the integrator, hence many risks may occur, caused by wrong implementation of this file.
     Prevention: The integrator strictly has to adhere to the definitions of the AUTOSAR SWS Memory Mapping. Extensions to
                 the file not described in the SWS may not be put into MemMap.h. This has to be verified by code inspection.

*/
