#ifndef RTE_STUBS_C
#define RTE_STUBS_C

#include "Std_Types.h"
#include "SciDrv.h"
#include "Dio.h"
#include "LinIf.h"
#include "LinNm.h"
#include "LinSm.h"
#include "LinStub.h"
#include "CanTp.h"
#include "Xcp.h"
#include "Dem.h"
#include "Spi.h"
#include "LedDrv.h"
#include "Rte_Type.h"
#include "sdl_ecc.h"
#include "Rte_Dlt_Type.h"
#include "NvM_Cfg.h"
#include "Cdd_Ipc.h"
#include "Cdd_IpcCfg.h"
#include "Rte_Type.h"
#include "Rte_CFltM.h"
#include "IoHwAb.h"

#ifdef VIP_UART_TEST
#include "DltExt.h"
#endif

#define ERR_CLEAR         {0xA5,0x30,0x00,0x00,0x00,0x00,\
                           0x00,0x00,0x00,0x00,0x00,0x00,\
                           0x00,0x00,0x00,0x00,0x00,0x00,\
                           0x00,0x00,0x00,0x00,0x00,0x00,\
                           0x00,0x00,0x00,0x00,0x00,0x00,\
                           0x00,0x00,0x00,0x00,0x00,0x00,\
                           0xA5,0x30,0x00,0x00,0x00,0x00,\
                           0x00,0x00,0x00,0x00,0x00,0x00,\
                           0x00,0x00,0x00,0x00,0x00,0x00,\
                           0x00,0x00,0x00,0x00,0x00,0x00,\
                           0x00,0x00,0x00,0x00,0x00,0x00,\
                           0x00,0x00,0x00,0x00,0x00,0x00}
static volatile uint8_t TestCheck = 	0;
#define LED_DATA_LENGTH              72U
static uint8 SpiBuffer_Tx[LED_DATA_LENGTH];
static uint8 SpiBuffer_Rx[LED_DATA_LENGTH];
#if LED_DRV_ENABLE
void LedDriverTest(void);
#endif

#ifdef VIP_UART_TEST
static volatile uint16 VIPTest_Count = 0;
static const char DltExt_SpinChars[4] = {'|','/','-','\\'};
static uint8 DltExt_SpinIdx = 0u;
#endif
extern Std_ReturnType Dlt_SendLogMessage(Dlt_SessionIDType sessionId, const Dlt_MessageLogInfoType *logInfo, uint8 *logData, uint16 logDataLength);
extern Std_ReturnType NvM_ReadBlock( NvM_BlockIdType BlockId,void* NvM_DstPtr);
extern void CddIpcCommunicationTestDM(void);
extern void vHsmDmnMgr_MainFunction(void);
extern void SchM_Enter_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0(void);
extern void SchM_Exit_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0(void);
extern void DM_DmnMgr_SystemChangeResponse(ESystemState Response);
extern FUNC (void, CRY_CODE) vHsmIpc_HostManager_PeriodicCheck(void);
extern void CanNm_MainFunction(void);
void Dem_MasterMainFunction(void);
void Dem_SatelliteMainFunction(void);
void MemAbstract_MainFunction(void);
void OnDre_EnetRegReq(void);
void OnDre_IgnState(void);
void AppTaskStubRunnable(void);
void AudioTaskStubRunnable(void);
void CddTaskStubRunnable(void);
void FotaTaskStubRunnable(void);
void GaugeTaskStubRunnable(void);
void GraphicsTaskStubRunnable(void);
void IndTaskStubRunnable(void);
void LinTaskStubRunnable(void);
void TripTaskStubRunnable(void);
void WarnTaskStubRunnable(void);
void WdgMgntTaskStubRunnable(void);
void EepDrv_MainFunction(void);
void MemAbstractMdl_MainFunction(void);




static volatile uint16 ESMTest_Count = 1;
#define SHUTDOWN ((uint32)0x00FF00A3u)
static volatile uint8 TestCountDM = 0;
volatile uint32 Cdd_IpcNewMsgCountEP = 0;
char Cdd_IpcAppMpu[513u];
uint32 mpuBufsize = sizeof(Cdd_IpcAppMpu);
#define  ESM_INST_TEST SDL_ESM_INST_MAIN_ESM0
static SDL_ESM_Inst gcurrEsmInstance;

#ifdef PMIC_LW_TEST_ENABLE
static volatile uint16 WdgLwFuncTest_Count = 0;
#endif

#ifdef LED_DRV_ENABLE
static volatile uint8 Led_Test_Type = 1; // 1 - 6
static volatile uint16 Led_Test_Cnt = 0;
static volatile uint8 Led_Test_OutputSignal = 1; // 0 - 1
IoHwAb_ErrorType Iohw_Status = 0;
#endif

#if LED_DRV_ENABLE
void LedDriverTest(void)
{
  if (Led_Test_Type == 1)
  {
    /* TT On / Off */
    Led_Test_Type = 0;
	Led_Test_OutputSignal = 1;

	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_ESC_SERVICE_LED, STD_HIGH, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_TIRE_PRESSURE_LED, STD_HIGH, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_EU_BRAKE_LED, STD_HIGH, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_DRV_AIR_BAG_LED, STD_HIGH, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_SEATBELT_LED, STD_HIGH, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_US_BRAKE_LED, STD_HIGH, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_ANTILOCK_BRAKE_LED, STD_HIGH, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_RIGHT_ESC_OFF_LED, STD_HIGH, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_RIGHT_ESC_SERVICE_LED, STD_HIGH, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_RIGHT_TIRE_PRESSURE_LED, STD_HIGH, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_RIGHT_EU_BRAKE_LED, STD_HIGH, &Iohw_Status);

  }

  if (Led_Test_Cnt == 300)
  {
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_ESC_SERVICE_LED, STD_LOW, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_TIRE_PRESSURE_LED, STD_LOW, &Iohw_Status);
  }
  if (Led_Test_Cnt == 350)
  {
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_EU_BRAKE_LED, STD_LOW, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_DRV_AIR_BAG_LED, STD_LOW, &Iohw_Status);
  }
  if(Led_Test_Cnt == 400)
  {
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_SEATBELT_LED, STD_LOW, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_US_BRAKE_LED, STD_LOW, &Iohw_Status);
  }
  if(Led_Test_Cnt == 450)
  {
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_LEFT_ANTILOCK_BRAKE_LED, STD_LOW, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_RIGHT_ESC_OFF_LED, STD_LOW, &Iohw_Status);
  }
  if(Led_Test_Cnt == 500)
  {
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_RIGHT_ESC_SERVICE_LED, STD_LOW, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_RIGHT_TIRE_PRESSURE_LED, STD_LOW, &Iohw_Status);
	IoHwAb_DOut_SetOutputPin(eIO_DOUT_RIGHT_EU_BRAKE_LED, STD_LOW, &Iohw_Status);
  }

  if(Led_Test_Cnt<=500)
  {
	  Led_Test_Cnt++;
  }

}
#endif

volatile uint32 ecc_addr;
volatile uint8 ecc_aggr;
volatile uint8 ecc_ramid;
volatile SDL_ECC_InjectErrorType ecc_errortype;
volatile int32_t ecc_ret;

volatile uint8 ecc_test=0;
volatile uint8 ecc_test_param = 0;
volatile uint32 test_ecc_addr[7] = {0,0,4,0x41010000,0x41010004,0x41010008,0x4101000C};

volatile uint8 dlt_test;
volatile uint8 dlt_sessionid;

volatile uint8 dlt_logdata[20];
volatile uint16 dlt_loglength;
volatile Std_ReturnType  dlt_ret;
volatile uint8 dlt_blockId_u8;

extern void NvM_TestFunction(void);

 uint16 ErrClear[260];

 volatile uint8 dlt_test_set;

void Test_Comp_MainFunction(void)
{
  NvM_TestFunction();

  if(dlt_test_set == 1)
  {
      dlt_loglength = 8;
      dlt_logdata[0] = 0xF3;
      dlt_logdata[1] = 0x02;
      dlt_logdata[2] = 0xad;
      dlt_logdata[3] = 0x36;
      dlt_logdata[4] = 0x73;
      dlt_logdata[5] = 0x13;
      dlt_logdata[6] = 0x09;
      dlt_logdata[7] = 0x20;
      dlt_test = 1;
      dlt_test_set = 0;
  }

  if(dlt_test_set == 2)
  {
      dlt_loglength = 8;
      dlt_logdata[0] = 0xF4;
      dlt_logdata[1] = 0x05;
      dlt_logdata[2] = 0xac;
      dlt_logdata[3] = 0x3f;
      dlt_logdata[4] = 0x54;
      dlt_logdata[5] = 0x15;
      dlt_logdata[6] = 0x03;
      dlt_logdata[7] = 0x93;
      dlt_test = 1;
      dlt_test_set = 0;
  }

  if(dlt_test_set == 23)
  {
      dlt_loglength = 8;
      dlt_logdata[0] = 0xF5;
      dlt_logdata[1] = 0x0a;
      dlt_logdata[2] = 0xab;
      dlt_logdata[3] = 0xd7;
      dlt_logdata[4] = 0x82;
      dlt_logdata[5] = 0x02;
      dlt_logdata[6] = 0x04;
      dlt_logdata[7] = 0x91;
      dlt_test = 1;
      dlt_test_set = 0;
  }

    if(dlt_test == 1)
    {
          Dlt_MessageLogInfoType logInfo = {  .argCount = 2U,
                                        .logLevel = DLT_LOG_FATAL,
                                        .options = 0U,
                                        .appId = {'F','L','T','M'},
                                        .contextId = {'F','L','T','M'},
                                     };

      dlt_ret = Dlt_SendLogMessage (0,&logInfo,dlt_logdata,dlt_loglength);
      dlt_test = 0;
    }

    if(dlt_test == 2)
    {
      dlt_blockId_u8 = NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_ResetInfo;
      NvM_ReadBlock(dlt_blockId_u8, NULL);
      dlt_test = 0;
    }

    if(dlt_test == 3)
    {
      dlt_ret = NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_ResetInfo,&dlt_logdata[0]);
      //dlt_ret = Dlt_SendLogMessage (0,&logInfo,dlt_logdata,dlt_loglength);
      dlt_test = 0;
    }

     #ifdef VIP_UART_TEST
    if(VIPTest_Count == 50)
    {
      #if (DLTEXT_UART_PRINT == STD_ON)
       (void)DltExt_Uart_Printf("VIP running # %c\r", DltExt_SpinChars[DltExt_SpinIdx]);
        DltExt_SpinIdx = (uint8)((DltExt_SpinIdx + 1u) & 0x03u);
      #endif
      VIPTest_Count = 0;
    }
    VIPTest_Count++;
    #endif
    if((ecc_test_param > 0) && (ecc_test_param < 7))
    {
      ecc_aggr = 12;
      ecc_ramid = (20+ecc_test_param);
      ecc_addr = test_ecc_addr[ecc_test_param];
      ecc_test_param = 0;
    }

    if(ecc_test_param == 7)
    {
      ecc_aggr = 28;
      ecc_ramid = 0;
      ecc_addr = 0x79100000;
      ecc_test_param = 0;
    }

    if(ecc_test_param == 8)
    {
      ecc_aggr = 8;
      ecc_ramid = 0;
      ecc_addr = 0x79140000;
      ecc_test_param = 0;
    }

    if(ecc_test_param == 9)
    {
      ecc_aggr = 21;
      ecc_ramid = 0;
      ecc_addr = 0x4E10000;
      ecc_test_param = 0;
    }

    if(ecc_test ==1)
    {
      #if (FLTM_ECC_ENABLE == STD_ON)
      ecc_ret = FltM_runECC_InjectTest(ecc_addr,ecc_aggr,ecc_ramid,ecc_errortype);
      #endif
      ecc_test = 0;
    }


  //Test code to check SPI functionality - AysncTransmit
  volatile uint16 dlt_addr;

  if(TestCheck == 1)
    {

      uint16 len = 260;
      uint16 padding = 0;
      uint8 len_copy = 32;
      dlt_addr = 0;
     for(uint16 i = 0; i < len; i++)
     {
        ErrClear[i] = i;
     }

     while(len > 0)
     {

        if(len <= 32)
        {
          len_copy = len;
        }
        SpiBuffer_Tx[0] = 0x06;
        //MemLib_MemCpy(&SpiBuffer_Tx[0],&ErrClear[0],(uint32)1);
        Spi_SetupEB(0, &SpiBuffer_Tx[0],NULL, 1);
        (void)Spi_SyncTransmit(0);

        SpiBuffer_Tx[0] = 0x02;
        SpiBuffer_Tx[1] = (uint8) ((dlt_addr >> 8) & 0x00FF);
        SpiBuffer_Tx[2] = (uint8) (dlt_addr & 0x00FF);

        uint8 copySize = (len_copy > (LED_DATA_LENGTH - 3)) ? (LED_DATA_LENGTH - 3) : len_copy;
        MemLib_MemCpy(&SpiBuffer_Tx[3],&ErrClear[0+padding],(uint32)copySize);
        Spi_SetupEB(0, &SpiBuffer_Tx[0],NULL, (copySize+3));
        (void)Spi_SyncTransmit(0);

        if(len > 32)
        {
          len = len - 32;
          dlt_addr = dlt_addr+32;
          padding = padding +32;
        }
        else
        {
          len = 0;
        }

        do
        {
                SpiBuffer_Tx[0] = 0x05;
        SpiBuffer_Tx[1] = 0xFF;
        Spi_SetupEB(0, &SpiBuffer_Tx[0],&SpiBuffer_Rx[0], 2);
     (void)Spi_SyncTransmit(0);
          /* code */

        } while ((SpiBuffer_Rx[1] & 0x01) != 0u);


     }
    TestCheck = 0;
  }

  if(TestCheck == 2)
    {
      uint8 loc = 0;
      SpiBuffer_Tx[0] = 0x03;
      dlt_addr = 9773;
        SpiBuffer_Tx[1] = (uint8) ((dlt_addr >> 8) & 0x00FF);
        SpiBuffer_Tx[2] = (uint8) (dlt_addr & 0x00FF);

  //    MemLib_MemCpy(&SpiBuffer_Tx[0],&ErrClear[0],(uint32)32);
      Spi_SetupEB(0, &SpiBuffer_Tx[0],&SpiBuffer_Rx[loc], 35);
     (void)Spi_SyncTransmit(0);

     while (dlt_addr < 10033)
     {
       dlt_addr = dlt_addr + 32;
        loc = (uint8)((loc + 35) % LED_DATA_LENGTH);
          //    MemLib_MemCpy(&SpiBuffer_Tx[0],&ErrClear[0],(uint32)32);
        Spi_SetupEB(0, &SpiBuffer_Tx[0],&SpiBuffer_Rx[loc], 35);
        (void)Spi_SyncTransmit(0);
     }
      TestCheck = 0;
  }
  #if LED_DRV_ENABLE
  LedDrv_MainFunction();
  LedDriverTest();
  #endif
    #if PMIC_LW_TEST_ENABLE
    WdgLwFuncTest_Count ++;
    if(WdgLwFuncTest_Count == 10000)
    {
        PmicCdd_ExitWdgLongWin();
    }
    if(WdgLwFuncTest_Count == 10200)
    {
        PmicCdd_EnterWdgLongWin();
    }
    if(WdgLwFuncTest_Count == 10600)
    {
      PmicCdd_ExitWdgLongWin();
    }
    if(WdgLwFuncTest_Count == 10800)
    {
        PmicCdd_EnterWdgLongWin();
    }
    #endif


	if(ESMTest_Count == 0)
    {
        SDL_ESM_ErrorConfig_t esmErrorConfig;
        gcurrEsmInstance = ESM_INST_TEST;
        esmErrorConfig.groupNumber = 2;
        esmErrorConfig.bitNumber = 0;

        SDR_ESM_errorInsert (gcurrEsmInstance,&esmErrorConfig);
        ESMTest_Count++;
    }
    //LedDrv_MainFunction();
    if(TestCountDM == 1)
    {
      TestCountDM = 0;
      CddIpcCommunicationTestDM();
      //Cdd_IpcSendMsg(CddIpcConf_IpcComChanId_Cdd_ipcMpu11_EP15, (const void *)&flword, (uint32)sizeof(flword));
    }

    #if 0
    if(TestCountDM == 100)
    {
      TestCountDM = 0;
      RetVal = Cdd_IpcSendMsg(CddIpcConf_IpcComChanId_Cdd_ipcMpu11_EP15, (const void *)&flword_DM, (uint32)sizeof(flword_DM));
      DltExt_Uart_Printf("\r\nReturn Value = %d\r\n", RetVal);
      DltExt_Uart_Printf("\r\nSending the IPC msg to DM\r\n");
    }
    if(Cdd_IpcNewMsgCountEP != 0)
    {
      /* Receive message */
            Cdd_IpcReceiveMsg(CddIpcConf_IpcComChanId_Cdd_ipcMpu11_EP15, &Cdd_IpcAppMpu[0U], &mpuBufsize);
            /* Disable global interrupts */
            SchM_Enter_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
            /* Decrement message reception variable to indicate message has been received on EP13*/
            Cdd_IpcNewMsgCountEP--;
            /* Enable global interrupts */
            SchM_Exit_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
            DltExt_Uart_Printf("\r\nMessage Received from DM:0x%08X\r\n", *(uint32*)Cdd_IpcAppMpu);
            //DltExt_Uart_Printf("\r\nMessage Received from DM: %c\r\n", Cdd_IpcAppMpu[0u]);

            if(*(uint32*)Cdd_IpcAppMpu == 0xAFAFBFBF)
            {
              DltExt_Uart_Printf("\r\n Shutdown Success\r\n");
            }
    }
    #endif

}
/* This was added for routing the printf & scanf functions if used returns 0 to discard
I/O operations. This stub need to be removed for seeeing the actual console output */

int __TI_writemsg(const char *msg, unsigned len) { return 0; }
int __TI_readmsg(char *buf, unsigned len) { return 0; }

void Dem_MasterMainFunction(void)
{
    Dem_MainFunction();
    vHsmDmnMgr_MainFunction();
}

void Dem_SatelliteMainFunction(void)
{

}

/* Callback from CddIpc if New messages are received */
void CddIpc_Graceful_ShutdownResponse(void)
{
    Cdd_IpcNewMsgCountEP++;

    if(Cdd_IpcNewMsgCountEP != 0)
    {
        /* Receive message */
        Cdd_IpcReceiveMsg(CddIpcConf_IpcComChanId_Cdd_ipcMpu11_EP15, &Cdd_IpcAppMpu[0U], &mpuBufsize);
        /* Disable global interrupts */
        SchM_Enter_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();
        /* Decrement message reception variable to indicate message has been received on EP13*/
        Cdd_IpcNewMsgCountEP--;
        /* Enable global interrupts */
        SchM_Exit_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0();

        if(*(uint32*)Cdd_IpcAppMpu == 0xAFAFBFBF)
        {
            DltExt_Uart_Printf("\r\n Shutdown Success\r\n");
            DM_DmnMgr_SystemChangeResponse(E_OK);
        }
    }
}

void MemAbstract_MainFunction(void)
{

}


void OnDre_EnetRegReq(void)
{

}

void OnDre_IgnState(void)
{

}

void AppTaskStubRunnable(void)
{

}

void AudioTaskStubRunnable(void)
{

}

void CddTaskStubRunnable(void)
{
      vHsmIpc_HostManager_PeriodicCheck();
}

void FotaTaskStubRunnable(void)
{

}

void GaugeTaskStubRunnable(void)
{

}

#ifdef DSS_TEST_ENABLED
void DssDisplayTest(void);
#endif

void GraphicsTaskStubRunnable(void)
{

#ifdef DSS_TEST_ENABLED
    DssDisplayTest();
#endif
}

void IndTaskStubRunnable(void)
{

}

void LinTaskStubRunnable(void)
{
    //Lin_DrvTest();
    //LinIf_MainFunction();
    //LinNm_MainFunction();
    //LinSM_MainFunction();
    /* added CanTp here, should be moved to Rte */
    CanTp_MainFunction();
    Xcp_MainFunction();
    CanNm_MainFunction();/* Added CanNm for temperorily and move this the RTE*/

}

void TripTaskStubRunnable(void)
{

}

#pragma clang section data =".SafeData"
uint8 mpu_data = 0;
#pragma clang section data = ""

volatile uint8 UserModeCheck = 0;

void WarnTaskStubRunnable(void)
{
    if(UserModeCheck == 1)
    {
#ifndef SIMULATION_BUILD
        /* No issues in execution */
            __asm__("push {r0} \n"
                    "pop  {r0} \n");
        /* execution throws memfault */
        volatile uint32 addr = 0x7913BBFC;
        volatile uint32* Addptr = (volatile uint32*)addr;
        // volatile uint32 b = *Addptr;
        *Addptr = 1;
        UserModeCheck = 0;
#endif
    }

    if(UserModeCheck == 2)
    {
        mpu_data = 10;
    }
}

uint16 PmicAdcResult = 0;

void WdgMgntTaskStubRunnable(void)
{

}

void Eep24xx_MainFunction(void);

void EepDrv_MainFunction(void)
{
    Eep24xx_MainFunction();


}

void MemAbstractMdl_MainFunction(void)
{

}


// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element;
// uint8 Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element;







#endif /* RTE_STUBS_C */

