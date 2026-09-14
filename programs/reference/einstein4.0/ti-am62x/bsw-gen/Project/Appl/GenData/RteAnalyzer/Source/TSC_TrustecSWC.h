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
 *          File:  TSC_TrustecSWC.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_TrustecSWC_Rte_Read_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(SG_ABS *data, P2VAR(Rte_TransformerError, AUTOMATIC, RTE_TRUSTECSWC_APPL_VAR) transformerError);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_TrustecSWC_Rte_Write_PP_TX_SG_COM_HS_SG_COM_HS(const SG_COM_HS *data, P2VAR(Rte_TransformerError, AUTOMATIC, RTE_TRUSTECSWC_APPL_VAR) transformerError);

/** Tx acknowledgment of S/R - Rte_Feedback */
Std_ReturnType TSC_TrustecSWC_Rte_Feedback_PP_TX_SG_COM_HS_SG_COM_HS(void);




