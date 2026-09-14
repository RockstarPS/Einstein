/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @file ComM_Dcm.h
*   @ingroup ComM
*   @brief This file provides the callback function prototype of the ComM module used by the DCM module.
********************************************************************************************************************/
#ifndef COMM_DCM_H
#define COMM_DCM_H

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This method called by DCM to indicate active diagnostic.
*   @param[in]  Channel The Network Channel for which is needed for Diagnostic communication
*   @ServiceID  0x1F
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern void ComM_DCM_ActiveDiagnostic(NetworkHandleType Channel);
/*!******************************************************************************************************************
*   @brief      This method called by DCM to indicate inactive diagnostic.
*   @param[in]  Channel The Network Channel for which doesnt needed for Diagnostic communication
*   @ServiceID  0x20
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern void ComM_DCM_InactiveDiagnostic(NetworkHandleType Channel);

#endif /* COMM_DCM_H */
/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
