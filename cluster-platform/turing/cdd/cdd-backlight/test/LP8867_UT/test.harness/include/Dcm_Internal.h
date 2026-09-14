/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2016. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
/*****************************************************************************
 *  File Name         :  Dcm_Internal.h                                       *
 *  Module Short Name :  DiagMgr                                              *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response handling functionlities.                    *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS                                                    *
 * Target Hardware  :                                                         *
 *                                                                            *
 ******************************************************************************/
#ifndef DCM_INTERNAL_H
#define DCM_INTERNAL_H

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

# define DCM_IGNORE_UNREF_PARAM(param)                  ((void)(param))

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

/**************************************************************************
 Function name   : DslInternal_SetSesCtrlType
 Arguments       : Dcm_SesCtrlType SesCtrlType
 Return type     : void
 Description     : This function sets a new session control type value in the DCM module.
 **************************************************************************/
void DslInternal_SetSesCtrlType(Dcm_SesCtrlType SesCtrlType);

/**************************************************************************
 Function name   : DslInternal_SetSecurityLevel
 Arguments       : Dcm_SecLevelType SecurityLevel)
 Return type     : void
 Description     : This function sets a new security level value in the DCM module.
 **************************************************************************/
void DslInternal_SetSecurityLevel(Dcm_SecLevelType SecurityLevel);

#endif /* DCM_INTERNAL_H_ */
