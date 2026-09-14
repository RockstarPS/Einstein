/*=================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
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
**==================================================================================================================
**
** Name:           Commdiagcdd
**
** Description:    Contains Communication related services
**
**
**===================================================================================================================*/

#ifndef ETHDIAGCDD_C
#define ETHDIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"

#ifdef ETHERNET_DIAG_MODULE_ENABLE
#include "Ethdiagcdd.h"
#include "Ethernetdiagcdd_cfg.h"

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef ETHERNET_SQI_READ
/*=====================================================================================================================
**
** Function Name    :  Ethernet_diag_read_SQI
**
** Visibility       :  Public
**
** Description      :  allows to Select a mode for ethernet test
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_STA_Diag_FD0E
**
** Inputs           :  Data[In]: Modes to be selected
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Ethernet_diag_read_SQI(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Ethernetdiag_SqiReadConfig.Read_EthernetSQI(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef ETHERNET_LINK_STATUS_READ
/*=====================================================================================================================
**
** Function Name    :  Ethernet_diag_read_Link_Status
**
** Visibility       :  Public
**
** Description      :  allows to Select a mode for ethernet test
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_STA_Diag_FD0E
**
** Inputs           :  Data[In]: Modes to be selected
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Ethernet_diag_read_Link_Status(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Ethernetdiag_LinkStatusConfig.Read_EthernetLinkStatus(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef ETHERNET_TEST_MODE_IOCTRL
/*=====================================================================================================================
**
** Function Name    :  Ethdiag_EthTestModeControl_STA
**
** Visibility       :  Public
**
** Description      :  allows to Select a mode for ethernet test
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_STA_Diag_FD1C
**
** Inputs           :  Data[In]: Modes to be selected
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ethdiag_EthTestModeControl_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = EthTestModeConfig.EthTestModeDiag_STA(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Ethdiag_EthTestModeControl_RCTE
**
** Visibility       :  Public
**
** Description      :  Returns Ethernet test mode Control to ECU
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_RCTE_Diag_FD1C
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ethdiag_EthTestModeControl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = EthTestModeConfig.EthTestModeDiag_RCTE(ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#endif
/*=====================================================================================================================
**  for each change to this file, be sure to record:
**  1.  who made the change and when the change was made
**  2.  why the change was made and the intended result
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation and MEET Pre-Condition check.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/08/2022
** CDSID             :  ajadhav5
** Traceability      :
** Change Description:  Ethernet service addition.
**====================================================================================================================*/
#endif
