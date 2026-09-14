/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TrustecSWC.c
 *        Config:  BMW.dpa
 *     SW-C Type:  TrustecSWC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <TrustecSWC>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_TrustecSWC.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_TrustecSWC.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void TrustecSWC_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Alive_101: Integer in interval [0...15]
 * Alive_200: Integer in interval [0...255]
 * Battery_Voltage: Integer in interval [0...255]
 * CRC_101: Integer in interval [0...255]
 * CRC_200: Integer in interval [0...255]
 * VehicleSpeedABS: Integer in interval [0...65535]
 *
 * Enumeration Types:
 * ==================
 * Airbag: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 *   Cx2_Blink (2U)
 *   Cx3_Reserved (3U)
 *
 * Record Types:
 * =============
 * SG_ABS: Record with elements
 *   Airbag of type Airbag
 *   Alive_101 of type Alive_101
 *   CRC_101 of type CRC_101
 *   VehicleSpeedABS of type VehicleSpeedABS
 * SG_COM_HS: Record with elements
 *   Alive_200 of type Alive_200
 *   Battery_Voltage of type Battery_Voltage
 *   CRC_200 of type CRC_200
 *
 *********************************************************************************************************************/


#define TrustecSWC_START_SEC_CODE
#include "TrustecSWC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrustedSwc_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 30ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(SG_ABS *data, Rte_TransformerError *transformerError)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PP_TX_SG_COM_HS_SG_COM_HS(const SG_COM_HS *data, Rte_TransformerError *transformerError)
 *
 * Status Interfaces:
 * ==================
 *   Tx Acknowledge:
 *   ----------------
 *   Std_ReturnType Rte_Feedback_PP_TX_SG_COM_HS_SG_COM_HS(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TrustedSwc_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TrustecSWC_CODE) TrustedSwc_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrustedSwc_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;
  Rte_TransformerError transformerError = {0U, 0U};

  SG_ABS Read_RP_RX_SG_ABS_RP_SR_TX_SG_ABS;

  SG_COM_HS Write_PP_TX_SG_COM_HS_SG_COM_HS;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_TrustecSWC_Rte_Read_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(&Read_RP_RX_SG_ABS_RP_SR_TX_SG_ABS, &transformerError);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_PP_TX_SG_COM_HS_SG_COM_HS, 0, sizeof(Write_PP_TX_SG_COM_HS_SG_COM_HS));
  fct_status = TSC_TrustecSWC_Rte_Write_PP_TX_SG_COM_HS_SG_COM_HS(&Write_PP_TX_SG_COM_HS_SG_COM_HS, &transformerError);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_TrustecSWC_Rte_Feedback_PP_TX_SG_COM_HS_SG_COM_HS();
  switch (fct_status)
  {
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TRANSMIT_ACK:
      fct_error = 1;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
  }

  TrustecSWC_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define TrustecSWC_STOP_SEC_CODE
#include "TrustecSWC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void TrustecSWC_TestDefines(void)
{
  /* Enumeration Data Types */

  Airbag Test_Airbag_V_1 = Cx0_Off;
  Airbag Test_Airbag_V_2 = Cx1_On;
  Airbag Test_Airbag_V_3 = Cx2_Blink;
  Airbag Test_Airbag_V_4 = Cx3_Reserved;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
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
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
