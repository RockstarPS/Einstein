/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2007. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           Dcm_App_cfg.h
**
** Description:    This is the config file for the diagnostic
**                 source code.
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#ifndef DCM_APP_CFG
#define DCM_APP_CFG


/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Constants                                  *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* purpose, unit and resolution                                               *
******************************************************************************/

#ifndef DCM_E_OK
#define DCM_E_OK                            (Std_ReturnType)E_OK
#endif

#ifndef DCM_E_NOT_OK
#define DCM_E_NOT_OK                        (Std_ReturnType)E_NOT_OK
#endif

#ifndef DCM_E_GENERALPROGRAMMINGFAILURE
#define DCM_E_GENERALPROGRAMMINGFAILURE     (uint8)114
#endif

#ifndef DCM_E_REQUESTOUTOFRANGE
#define DCM_E_REQUESTOUTOFRANGE             (uint8)49
#endif

#ifndef DCM_E_RESPONSE_PENDING
#define DCM_E_RESPONSE_PENDING              (uint8)10
#endif

#define DCM_E_WRITE_OK                      ((uint8)0) /**< TBD */
#define DCM_E_WRITE_FAIL                    ((uint8)1) /**< TBD */
#define DCM_E_WRITE_INPROGRESS              ((uint8)2) /**< TBD */


#endif



