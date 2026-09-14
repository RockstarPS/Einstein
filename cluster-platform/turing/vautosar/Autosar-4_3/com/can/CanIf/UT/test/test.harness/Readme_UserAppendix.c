#include "CanIf.h"
#include "CanIf_Lcfg.h"
#include "CanIf_Cbk.h"
#include "SchM_CanIf.h"
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
Std_ReturnType CanIf_SetBaudrate_1(uint8 ControllerId, uint16 BaudRateConfigID)
{
return 0;
}
Std_ReturnType CanIf_SetIcomConfiguration_1
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId
)
{
return 0;
}
Std_ReturnType CanIf_TriggerTransmit_1
(
    PduIdType TxPduId,
    PduInfoType * PduInfoPtr
)
{
return 0;
}
static Can_ReturnType CanIf_WritePdu_1
(
    CanIf_ControllerIdType CtrlId,
    Can_HwHandleType CanIfTxHandle,
    Can_PduType * PduInfo
)
{
return 0;
}

Std_ReturnType CanIf_CheckWakeup_1(EcuM_WakeupSourceType WakeupSource)
{
return 0;
}
void CanIf_TxConfirmation_1(PduIdType CanTxPduId)
{
return;
}
static Std_ReturnType CanIf_SetCanCtrlMode_1
(
    uint8 ControllerId,
    Can_ControllerStateType ControllerMode
)
{
return 0;
}
void CanIf_RxIndication_1
(
    Can_HwType * Mailbox,
    PduInfoType * PduInfoPtr
)
{}
Std_ReturnType CanIf_GetControllerErrorState_1
(
    uint8 ControllerId,
    Can_ErrorStateType * ErrorStatePtr
)
{
return 0;
}
void CanIf_CurrentIcomConfiguration_1
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
){}
Can_ReturnType test_CanTrcvWrite(Can_HwHandleType can, const Can_PduType* pdutype )
{
return 0;
}
Std_ReturnType CanDrvCheckWakeupFunct1(uint8 candrv)
{
return 0;
}
void pCanIfRxIndicationFunc1(PduIdType pdu, const PduInfoType *pduinfo)
{}
Can_ReturnType test_CanDrvSetControllerModeFunctPtr1(uint8 Controller,Can_ControllerStateType Transition)
{
return 0;
}
void test_CanIf_TxConfirmationFunctConfig1 (PduIdType TxPduId,Std_ReturnType result){}
Can_ReturnType CanDrvWriteFunctPtr1(Can_HwHandleType canhw, const Can_PduType* pdu )
{
return 0;
}