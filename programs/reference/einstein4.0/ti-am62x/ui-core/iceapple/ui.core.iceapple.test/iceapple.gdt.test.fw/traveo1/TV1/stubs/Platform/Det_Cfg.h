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
 *            Module: Det
 *           Program: MSR_Vector_SLP4
 *          Customer: Visteon Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Spansion Traveo S6J32BALSB
 *    License Scope : The usage is restricted to CBD1400814_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Det_Cfg.h
 *   Generation Time: 2016-01-07 20:48:34
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

 
#if !defined(DET_CFG_H)
#define DET_CFG_H

#define DET_GENERATOR_CFG5
#define DET_AUTOSARVERSION                   4U

#define DET_ENABLED

#define DET_VERSION_INFO_API                 STD_OFF
#define DET_DEBUG_DISABLED
#define DET_GLOBALFILTERSIZE                 0U
#define DET_BREAKFILTERSIZE                  0U
#define DET_LOGBUFFERSIZE                    0U
#define DET_ENTRY_CALLOUT_ENABLED
#define DET_FORWARD_TO_DLT                   STD_ON

/* DetModuleId symbolic name defines */
#define Det_DetServicePort 4096U 


#endif /* DET_CFG_H */
