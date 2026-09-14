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
 *          File:  TestControl.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Project specific file that implements a Test Suite Component Instance
 *********************************************************************************************************************/

/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */

#include "string.h"
#include "Std_Types.h"
#include "Rte_Cbk.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_0883 */
#include "Rte_Main.h"


void TSC_BswCallbacks()
{
    uint8 buffer[2048];
    (void)memset(buffer, 0, 2048);
    /**********************************************************************************************************************
     * COM Callbacks for Rx Indication
     *********************************************************************************************************************/
    Rte_COMCbk_SG_ABS_oABS_oCAN00_6681ad27_Rx();

    /**********************************************************************************************************************
     * COM Callbacks for Tx Confirmation
     *********************************************************************************************************************/
    Rte_COMCbkTAck_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx();
    /**********************************************************************************************************************
     * COM Callbacks for Tx Error and Tx Timeout Notification
     *********************************************************************************************************************/
    Rte_COMCbkTErr_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx();
    Rte_COMCbkTxTOut_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx();

    /**********************************************************************************************************************
     * NvM-Callback for synchronous copying of the mirror buffer to and from the NvM
     *********************************************************************************************************************/
    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate(buffer);

    (void)Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1(buffer);
    (void)Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1(buffer);


} /* PRQA S 6050 */ /* MD_MSR_STCAL */


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
