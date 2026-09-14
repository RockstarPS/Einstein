#include "Can.h"
#include "CanIf_Types.h"
//#include "ComStack_Types.h"
#include "CanIf_Cfg.h"
#include "Can_GeneralTypes.h"
//#include "Soc_Ips.h"
//#include "Can_43_Fsl.h"
//#include "Can_IPW.h"
void InitVectorCAN(void);

extern uint8 CANIFStarted ;
#if 0
typedef enum can_controllerstatustype_enum
{
  CAN_CONTROLLER_UNINIT = 0,
  CAN_CS_STOPPED,
  CAN_CS_STARTED,
  CAN_CS_SLEEP
} Can_ControllerStatusType;
#endif

static Can_ControllerStateType CanControllerState = CAN_CS_STOPPED;

Std_ReturnType Can_SetControllerMode(
    uint8 Controller, Can_ControllerStateType Transition)
{
  CanIf_ControllerModeType CanIfMode;
  Std_ReturnType retVal = E_OK;

  /* Check for allowed transitions and if allowed, perform it. */
  switch (Transition)
  {
    case CAN_CS_STOPPED:
	    CanControllerState = CAN_CS_STOPPED;
      break;
    case CAN_CS_SLEEP:
    	 CanControllerState = CAN_CS_SLEEP;
    	 break;
    case CAN_CS_STARTED:
      /* Since the controller is already started, we can just confirm. */
	  CanControllerState = CAN_CS_STARTED;

      break;

    /* CAN_T_SLEEP and CAN_T_WAKEUP are forbidden. */
    default:
      retVal = E_NOT_OK;
      break;
  }
	
  switch (CanControllerState)
  {
    case CAN_CS_STARTED:
      CanIfMode = CANIF_CS_STARTED;
	  CANIFStarted =1;
      break;
    case CAN_CS_SLEEP:
      CanIfMode = CANIF_CS_SLEEP;
	  CANIFStarted =0;
      break;
    case CAN_CS_STOPPED:
      CanIfMode = CANIF_CS_STOPPED;
	  CANIFStarted =0;
      break;
    /* case CAN_CONTROLLER_UNINIT: */
    default:
      CanIfMode = CANIF_CS_UNINIT;
	  CANIFStarted =0;
      break;
  }

	CanIf_ControllerModeIndication( Controller, CanIfMode );
	return (retVal);
}

FUNC(Std_ReturnType, CAN_CODE)
    Can_GetControllerMode(uint8 Controller,
        Can_ControllerStateType* ControllerModePtr)
{
    Std_ReturnType    retVal = (Std_ReturnType) E_OK;
    *ControllerModePtr = CanControllerState;
    return retVal;
}


FUNC(Std_ReturnType, CAN_CODE) Can_Write(Can_HwHandleType Hth,
	const Can_PduType *PduInfo)
{
		WindowsEnterCriticalSectionOriginal(); 
	Can_Write_sim(Hth,PduInfo);
	WindowsExitCriticalSectionOriginal(); 
	return(CAN_OK);
}

Std_ReturnType Can_ChangeBaudrate( unsigned char Controller, unsigned short int Baudrate  ){}

Std_ReturnType Can_CheckBaudrate( unsigned char Controller, unsigned short int Baudrate   ){}

					
FUNC(void, CAN_CODE) Can_Init( P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config)
{
  InitVectorCAN();
}

void Can_MainFunction_BusOff(void) {}

void Can_MainFunction_Mode(void){}

void Can_MainFunction_Wakeup(void){}
