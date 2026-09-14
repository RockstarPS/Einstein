-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLALPHYMUASR_IMPL
-- Unit(s) Under Test: UclALPhyMuASR_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALPhyMuASR_Impl

-- Subprogram: UclALPhyMuASR_Impl_Hw_GetRemoteMuState

-- Test Case: UclALPhyMuASR_Impl_Hw_GetRemoteMuState.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_GetRemoteMuState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs[0].SR:MU_SR_Fn_MASK
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:MU_SR_Fn_MASK
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.END_FLOW
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Hw_GetRemoteMuState.002
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_GetRemoteMuState.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs[0].SR:0xF8
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:0
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.END_FLOW
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull

-- Test Case: UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull_Return_False
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull_Return_False
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].SR:0x0
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.rxRegId:0x3
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.END_FLOW
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull_Return_True
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull_Return_True
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.rxRegId:0x3
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.END_FLOW
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty

-- Test Case: UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty_Return_True
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty_Return_True
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.txRegId:3
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.END_FLOW
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty__Return_False
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty__Return_False
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs[0].SR:0x0
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.txRegId:3
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.END_FLOW
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_MuClose

-- Test Case: UclALPhyMuASR_Impl_Hw_MuClose.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_MuClose
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_MuClose.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuClose.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuClose.pInst[0].pMuRegs:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuClose.return:UCL_E_OK
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_MuClose
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_MuClose
TEST.END_FLOW
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_MuOpen

-- Test Case: UclALPhyMuASR_Impl_Hw_MuOpen.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_MuOpen.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].pIUclALPhyCbk:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].muState:1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].pTxShMemBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].pRxShMemBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].txRingBuffer.pBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].rxRingBuffer.pBuffer:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].muState:1
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.return:0
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Hw_MuOpen.002
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_MuOpen.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.ATTRIBUTES:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].pMuRegs[0].TR.TR[3]:INPUT_BASE=16
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_MuOpen
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_MuOpen
TEST.END_FLOW
TEST.VALUE_USER_CODE:<<testcase>>
typedef struct SUclALPhyMuASRInst_t
{
    uint8 numIUclALPhyCbk;         ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;          ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhyMuASRCfg *pCfg; ///< Configuration for the UclALPhyMuASR instance

    SUclALPhyMuReg *pMuRegs;        ///< MU Registers
    uint8 muState;                  ///< MU Driver State
    uint8 *pTxShMemBuffer;          ///< Transmit Shared Memory Buffer Address
    uint8 *pRxShMemBuffer;          ///< Receive Shared Memory Buffer Address
    SUclCmnRingBuffer txRingBuffer; ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer; ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;     ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;     ///< Receive Ring Buffer Protection Mutex
    uint32 timerTaskId;             ///< MU TimerTask Id
    uint16 txBufferState;           ///< Transmit Buffer State
    uint16 txBufferSize;            ///< Transmit Buffer Size
    uint16 rxBufferState;           ///< Receive Buffer State
    uint16 rxBufferSize;            ///< Receive Buffer Size
} SUclALPhyMuASRInst;
typedef struct SUclALPhyMuReg_t
{
    volatile uint32 TR[4];       ///< Processor A Transmit Register 0, array offset: 0x0, array step: 0x4
    volatile const uint32 RR[4]; ///< Processor A Receive Register 0, array offset: 0x10, array step: 0x4
    volatile uint32 SR;          ///< Processor A Status Register, offset: 0x20
    volatile uint32 CR;          ///< Processor A Control Register, offset: 0x24
} SUclALPhyMuReg;
SUclALPhyMuASRInst *myInst = malloc(sizeof(SUclALPhyMuASRInst));
SUclALPhyMuReg *myMUReg = malloc(sizeof(SUclALPhyMuReg));
//<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst>> = ( myInst );
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst>>[0].pCfg[0].muBaseAddress = ( &myMUReg );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst.pInst[0].pCfg.pCfg[0].muBaseAddress
typedef struct SUclALPhyMuASRInst_t
{
    uint8 numIUclALPhyCbk;         ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;          ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhyMuASRCfg *pCfg; ///< Configuration for the UclALPhyMuASR instance

    SUclALPhyMuReg *pMuRegs;        ///< MU Registers
    uint8 muState;                  ///< MU Driver State
    uint8 *pTxShMemBuffer;          ///< Transmit Shared Memory Buffer Address
    uint8 *pRxShMemBuffer;          ///< Receive Shared Memory Buffer Address
    SUclCmnRingBuffer txRingBuffer; ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer; ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;     ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;     ///< Receive Ring Buffer Protection Mutex
    uint32 timerTaskId;             ///< MU TimerTask Id
    uint16 txBufferState;           ///< Transmit Buffer State
    uint16 txBufferSize;            ///< Transmit Buffer Size
    uint16 rxBufferState;           ///< Receive Buffer State
    uint16 rxBufferSize;            ///< Receive Buffer Size
} SUclALPhyMuASRInst;
typedef struct SUclALPhyMuReg_t
{
    volatile uint32 TR[4];       ///< Processor A Transmit Register 0, array offset: 0x0, array step: 0x4
    volatile const uint32 RR[4]; ///< Processor A Receive Register 0, array offset: 0x10, array step: 0x4
    volatile uint32 SR;          ///< Processor A Status Register, offset: 0x20
    volatile uint32 CR;          ///< Processor A Control Register, offset: 0x24
} SUclALPhyMuReg;
SUclALPhyMuASRInst *myInst = malloc(sizeof(SUclALPhyMuASRInst));
SUclALPhyMuReg *myMUReg = malloc(sizeof(SUclALPhyMuReg));
//<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst>> = ( myInst );
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst>>[0].pCfg[0].muBaseAddress = ( &myMUReg );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_SetMuState

-- Test Case: UclALPhyMuASR_Impl_Hw_SetMuState.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_SetMuState
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_SetMuState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.state:0
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.state:UCL_E_OK
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_SetMuState
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_Hw_SetMuState
TEST.END_FLOW
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged

-- Test Case: UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged.pInst[0].pIUclALPhyCbk:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged.InstId:UCL_E_OK
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged
TEST.END_FLOW
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete

-- Test Case: UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete.pInst:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete.InstId:UCL_E_OK
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete
TEST.END_FLOW
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALHwCbk_TransmitComplete

-- Test Case: UclALPhyMuASR_Impl_IUclALHwCbk_TransmitComplete.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALHwCbk_TransmitComplete
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALHwCbk_TransmitComplete.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALHwCbk_TransmitComplete.pInst:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALHwCbk_TransmitComplete.InstId:UCL_E_OK
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Initialize.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.pData.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.pData.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pTxShMemBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pTxShMemBuffer[0]:VARY FROM:0 TO:100 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pRxShMemBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pRxShMemBuffer[0]:VARY FROM:0 TO:100 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].txRingBuffer.pBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].txRingBuffer.pBuffer[0]:VARY FROM:0 TO:100 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].rxRingBuffer.pBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].rxRingBuffer.pBuffer[0]:VARY FROM:0 TO:100 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].txRingBufferMutexId:VARY FROM:0 TO:100 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].rxRingBufferMutexId:VARY FROM:0 TO:100 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].timerTaskId:VARY FROM:0 TO:100 BY: 1
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pTxShMemBuffer[0]:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pRxShMemBuffer[0]:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].txRingBuffer.pBuffer[0]:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].rxRingBuffer.pBuffer[0]:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].txRingBufferMutexId:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].rxRingBufferMutexId:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].timerTaskId:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100
TEST.VALUE_USER_CODE:<<testcase>>
typedef struct SUclALPhyMuASRInst_t
{
    uint8 numIUclALPhyCbk;         ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;          ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhyMuASRCfg *pCfg; ///< Configuration for the UclALPhyMuASR instance

    SUclALPhyMuReg *pMuRegs;        ///< MU Registers
    uint8 muState;                  ///< MU Driver State
    uint8 *pTxShMemBuffer;          ///< Transmit Shared Memory Buffer Address
    uint8 *pRxShMemBuffer;          ///< Receive Shared Memory Buffer Address
    SUclCmnRingBuffer txRingBuffer; ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer; ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;     ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;     ///< Receive Ring Buffer Protection Mutex
    uint32 timerTaskId;             ///< MU TimerTask Id
    uint16 txBufferState;           ///< Transmit Buffer State
    uint16 txBufferSize;            ///< Transmit Buffer Size
    uint16 rxBufferState;           ///< Receive Buffer State
    uint16 rxBufferSize;            ///< Receive Buffer Size
} SUclALPhyMuASRInst;
typedef struct SUclALPhyMuReg_t
{
    volatile uint32 TR[4];       ///< Processor A Transmit Register 0, array offset: 0x0, array step: 0x4
    volatile const uint32 RR[4]; ///< Processor A Receive Register 0, array offset: 0x10, array step: 0x4
    volatile uint32 SR;          ///< Processor A Status Register, offset: 0x20
    volatile uint32 CR;          ///< Processor A Control Register, offset: 0x24
} SUclALPhyMuReg;
SUclALPhyMuASRInst *myInst = malloc(sizeof(SUclALPhyMuASRInst));
SUclALPhyMuReg *myMUReg = malloc(sizeof(SUclALPhyMuReg));
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &myInst );
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst>>[0].pCfg[0].muBaseAddress = ((uint32) (myMUReg));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst.pInst[0].pCfg.pCfg[0].muBaseAddress
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst>>[0].pCfg[0].muBaseAddress = ( &MuASR );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Initialize.002
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Initialize.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pTxShMemBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pTxShMemBuffer[0]:VARY FROM:0 TO:255 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pRxShMemBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pRxShMemBuffer[0]:VARY FROM:0 TO:255 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].txRingBuffer.pBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].txRingBuffer.pBuffer[0]:VARY FROM:0 TO:255 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].rxRingBuffer.pBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].rxRingBuffer.pBuffer[0]:VARY FROM:0 TO:255 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].txRingBufferMutexId:VARY FROM:0 TO:65535 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].rxRingBufferMutexId:VARY FROM:0 TO:65535 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].timerTaskId:VARY FROM:0 TO:65535 BY: 1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.pRB[0].pBuffer:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:(2)1
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pTxShMemBuffer[0]:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,(78)255
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].pRxShMemBuffer[0]:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,(78)255
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].txRingBuffer.pBuffer[0]:(333)0
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].rxRingBuffer.pBuffer[0]:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,(78)255
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].txRingBufferMutexId:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].rxRingBufferMutexId:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst[0].timerTaskId:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332
TEST.VALUE_USER_CODE:<<testcase>>
typedef struct SUclALPhyMuASRInst_t
{
    uint8 numIUclALPhyCbk;         ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;          ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhyMuASRCfg *pCfg; ///< Configuration for the UclALPhyMuASR instance

    SUclALPhyMuReg *pMuRegs;        ///< MU Registers
    uint8 muState;                  ///< MU Driver State
    uint8 *pTxShMemBuffer;          ///< Transmit Shared Memory Buffer Address
    uint8 *pRxShMemBuffer;          ///< Receive Shared Memory Buffer Address
    SUclCmnRingBuffer txRingBuffer; ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer; ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;     ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;     ///< Receive Ring Buffer Protection Mutex
    uint32 timerTaskId;             ///< MU TimerTask Id
    uint16 txBufferState;           ///< Transmit Buffer State
    uint16 txBufferSize;            ///< Transmit Buffer Size
    uint16 rxBufferState;           ///< Receive Buffer State
    uint16 rxBufferSize;            ///< Receive Buffer Size
} SUclALPhyMuASRInst;
typedef struct SUclALPhyMuReg_t
{
    volatile uint32 TR[4];       ///< Processor A Transmit Register 0, array offset: 0x0, array step: 0x4
    volatile const uint32 RR[4]; ///< Processor A Receive Register 0, array offset: 0x10, array step: 0x4
    volatile uint32 SR;          ///< Processor A Status Register, offset: 0x20
    volatile uint32 CR;          ///< Processor A Control Register, offset: 0x24
} SUclALPhyMuReg;
SUclALPhyMuASRInst *myInst = malloc(sizeof(SUclALPhyMuASRInst));
SUclALPhyMuReg *myMUReg = malloc(sizeof(SUclALPhyMuReg));
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &myInst );
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst>>[0].pCfg[0].muBaseAddress = ((uint32) (myMUReg));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst.pInst[0].pCfg.pCfg[0].muBaseAddress
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst>>[0].pCfg[0].muBaseAddress = ( &MuASR );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Initialize.003
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Initialize.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.return:1
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALPhy_Read

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Read.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Read.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Read.002
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Read.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize[0]:0
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Read.003
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Read.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.InstId:1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize[0]:1
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.return:UCL_E_OK
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Read.004
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Read.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Read.005
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Read.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.InstId:1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.return:UCL_E_NOK
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALPhy_Shutdown

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Shutdown.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Shutdown.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Shutdown.pInst:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Shutdown.return:UCL_E_OK
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Shutdown.002
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Shutdown.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Shutdown.return:1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_MuClose.return:1
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALPhy_Write

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Write.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Write.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALPhy_Write
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.END_FLOW
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Write.002
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Write.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALPhy_Write
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.END_FLOW
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Write.003
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Write.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.Size:1
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.return:UCL_E_OK
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALPhy_Write
  uut_prototype_stubs.UclALOs_MutexLock
  uut_prototype_stubs.UclCmnRingBuffer_Write
  uut_prototype_stubs.UclALOs_MutexUnlock
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.END_FLOW
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Write.004
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Write.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALPhy_Write
  uut_prototype_stubs.UclALOs_MutexLock
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.END_FLOW
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Write_RB_Write_Failed
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Write_RB_Write_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:-1
TEST.EXPECTED:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALPhy_Write
  uut_prototype_stubs.UclALOs_MutexLock
  uut_prototype_stubs.UclCmnRingBuffer_Write
  uut_prototype_stubs.UclALOs_MutexUnlock
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.END_FLOW
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_MuStateCheckTimerTask

-- Test Case: UclALPhyMuASR_Impl_MuStateCheckTimerTask_MU_State_Init
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_MuStateCheckTimerTask_MU_State_Init
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_INIT_ST
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:MU_READY_ST
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_ERROR_ST
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pIUclALPhyCbk
<<UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pIUclALPhyCbk = ( &UclALPhyInst_0_IUclALPhyCbk );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_MuStateCheckTimerTask_MU_State_Ready
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_MuStateCheckTimerTask_MU_State_Ready
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:2
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_READY_ST
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:MU_INIT_ST
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_ERROR_ST
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pIUclALPhyCbk
<<UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pIUclALPhyCbk = ( &UclALPhyInst_0_IUclALPhyCbk );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_MuStateCheckTimerTask_MU_State_Ready.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_MuStateCheckTimerTask_MU_State_Ready.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:2
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_READY_ST
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:MU_READY_ST
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_READY_ST
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pIUclALPhyCbk
<<UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pIUclALPhyCbk = ( &UclALPhyInst_0_IUclALPhyCbk );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_TimerTask

-- Test Case: UclALPhyMuASR_Impl_TimerTask.004
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_TimerTask.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:2
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:VARY FROM:0 TO:25 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.pData.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.pData.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.pData.muState:0
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:2
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:25
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.pData.muState:0
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
TEST.END_FLOW
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_TimerTask.RMU_SETUP
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_TimerTask.RMU_SETUP
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_TimerTask_RMU_INIT
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_TimerTask_RMU_INIT
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:VARY FROM:0 TO:25 BY: 1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.pData.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.pData.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.pData.muState:0
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:25
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.pData.muState:0
TEST.FLOW
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
  UclALPhyMuASR_Impl.c.UclALPhyMuASR_Impl_TimerTask
TEST.END_FLOW
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Transfer

-- Test Case: UclALPhyMuASR_Impl_Transfer.001
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Transfer.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x12340001
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x2
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Transfer.002
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Transfer.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x12340001
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Transfer.003
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Transfer.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x12340001
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Transfer.004
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Transfer.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x2
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Transfer.005
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Transfer.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0..1]:0x2
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Transfer.006
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Transfer.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x12340001
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x2
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferSize:1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:1
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Transfer_Mutex_Fail
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Transfer_Mutex_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x12340001
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x2
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Transfer_RxSize_Zero
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Transfer_RxSize_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x2
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Transfer_TxReg_Empty
TEST.UNIT:UclALPhyMuASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Transfer_TxReg_Empty
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x1
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x20
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0x0
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.EXPECTED:UclALPhyMuASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.VALUE_USER_CODE:UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst
<<UclALPhyMuASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
