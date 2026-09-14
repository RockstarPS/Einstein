-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLALPHYMUFREERTOSMASTER_IMPL
-- Unit(s) Under Test: UclALPhyMuFreeRtosMaster_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs[0].SR:7
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs[0].CR:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:7
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].SR:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.002
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].SR:251658240
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs[0].SR:15728640
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.002
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs[0].SR:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose.return:0
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].pCfg[0].txRingBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].pCfg[0].rxRingBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].pMuRegs[0].CR:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].muState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.return:0
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst.pInst[0].pCfg.pCfg[0].muBaseAddress
typedef struct SUclALPhyMuFreeRtosMasterInst_t
{
    uint8 numIUclALPhyCbk;         ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;          ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhyMuFreeRtosMasterCfg *pCfg; ///< Configuration for the UclALPhyMuFreeRtosMaster instance

    SUclALPhyMuReg *pMuRegs;        ///< MU Registers
    uint8 muState;                  ///< MU Driver State
    uint8 *pTxShMemBuffer;          ///< Transmit Shared Memory Buffer Address
    uint8 *pRxShMemBuffer;          ///< Receive Shared Memory Buffer Address
    SUclCmnRingBuffer txRingBuffer; ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer; ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;     ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;     ///< Receive Ring Buffer Protection Mutex
    uint32 timerTaskId;             ///< MU TimerTask Id
    uint32 muStateChkTimerTaskId;   ///< MU State Check TimerTask Id
    uint16 txBufferState;           ///< Transmit Buffer State
    uint16 txBufferSize;            ///< Transmit Buffer Size
    uint16 rxBufferState;           ///< Receive Buffer State
    uint16 rxBufferSize;            ///< Receive Buffer Size
} SUclALPhyMuFreeRtosMasterInst;
typedef struct SUclALPhyMuReg_t
{
    volatile uint32 TR[4];       ///< Processor A Transmit Register 0, array offset: 0x0, array step: 0x4
    volatile const uint32 RR[4]; ///< Processor A Receive Register 0, array offset: 0x10, array step: 0x4
    volatile uint32 SR;          ///< Processor A Status Register, offset: 0x20
    volatile uint32 CR;          ///< Processor A Control Register, offset: 0x24
} SUclALPhyMuReg;
SUclALPhyMuFreeRtosMasterInst *myInst = malloc(sizeof(SUclALPhyMuFreeRtosMasterInst));
SUclALPhyMuReg *myMUReg = malloc(sizeof(SUclALPhyMuReg));
//<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst>> = ( myInst );
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst>>[0].pCfg[0].muBaseAddress = ( &myMUReg );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.002
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].pIUclALPhyCbk:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].muState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].pTxShMemBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].pRxShMemBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].txRingBuffer.pBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].txRingBuffer.pBuffer[0]:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].rxRingBuffer.pBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst[0].rxRingBufferMutexId:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.return:0
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].pMuRegs[0].CR:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].muState:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.state:0
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_GpioChanged

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_GpioChanged.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_GpioChanged
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_GpioChanged.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_ReceiveComplete

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_ReceiveComplete.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_ReceiveComplete
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_ReceiveComplete.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_TransmitComplete

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_TransmitComplete.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_TransmitComplete
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_TransmitComplete.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.return:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.002
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.pInst[0].pCfg[0].muBaseAddress:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.pInst[0].pCfg[0].periodicityMs:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.pInst[0].txRingBuffer.pBuffer:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.pInst[0].txRingBuffer.pBuffer:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.pInst[0].rxRingBuffer.pBuffer:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.pInst[0].rxRingBuffer.pBuffer:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.pInst[0].rxRingBuffer.BufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.return:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.return:0
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].pCfg[0].txRingBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].pCfg[0].rxRingBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].muState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:0
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize.return:0
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pSize[0]:0
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.return:-3
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.002
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_ReadFrame.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.003
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_ReadFrame.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.return:-1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.004
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pData:<<null>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pSize[0]:0
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.return:-3
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.005
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.pSize:<<null>>
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read.return:-3
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.pInst[0].timerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.return:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerDestroy.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.return:0
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.002
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuClose.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown.return:1
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pData:"0"
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.return:-3
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.002
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:-1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.return:-1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.003
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.004
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.return:-1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.005
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.pData:<<null>>
TEST.EXPECTED:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write.return:-3
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].numIUclALPhyCbk:0
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].pIUclALPhyCbk:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].pIUclALPhyCbk:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_NotReady
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.002
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.pData:VECTORCAST_INT1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].pIUclALPhyCbk:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.pInst[0].pIUclALPhyCbk:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].numIUclALPhyCbk:0
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].pIUclALPhyCbk:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].pIUclALPhyCbk:"1"
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].muState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_NotReady
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.003
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.004
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_TimerTask

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_TimerTask.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_TimerTask.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData:VECTORCAST_BUFFER
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].muState:0
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:0
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_TimerTask.002
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_TimerTask.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData:VECTORCAST_INT2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState.state:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs:<<malloc 4>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.pInst[0].muState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_TimerTask.003
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_TimerTask.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_TimerTask.004
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_TimerTask.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_TimerTask.005
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_TimerTask.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_TimerTask.006
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_TimerTask.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_TimerTask.007
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_TimerTask.007
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_SetMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:3
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_TimerTask.008
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_TimerTask.008
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_TimerTask.009
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_TimerTask.009
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:4
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosMaster_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuFreeRtosMaster_Impl_Transfer

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Transfer.001
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Transfer.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.rxRegId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Transfer.002
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Transfer.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.rxRegId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Transfer.003
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Transfer.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.rxRegId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:0
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Transfer.004
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Transfer.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.rxRegId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Transfer.005
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Transfer.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Transfer.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:0x12340001
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:129
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.rxRegId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Transfer.006
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Transfer.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Transfer.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:0x12340001
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:129
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.rxRegId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosMaster_Impl_Transfer.007
TEST.UNIT:UclALPhyMuFreeRtosMaster_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosMaster_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosMaster_Impl_Transfer.007
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.rxRegId:1
TEST.VALUE:UclALPhyMuFreeRtosMaster_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:1
TEST.END
