-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLALPHYMUFREERTOSSLAVE_IMPL
-- Unit(s) Under Test: UclALPhyMuFreeRtosSlave_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs[0].SR:7
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:7
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].SR:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.002
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].SR:251658240
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs[0].SR:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.002
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs[0].SR:15728640
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose.pInst:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose.return:0
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.return:0
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst.pInst[0].pCfg.pCfg[0].muBaseAddress
typedef struct
{
    const SUclALPhyMuFreeRtosSlaveCfg *pCfg; ///< Configuration for the UclALPhyMuFreeRtosSlave instance
    uint8 numIUclALPhyCbk;         ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;          ///< Instance ID of the connected IUclALPhyCbk instances

    SUclALPhyMuReg *pMuRegs;        ///< MU Registers
    uint8 muState;                  ///< MU Driver State
    uint8 *pTxShMemBuffer;          ///< Transmit Shared Memory Buffer Virtual Address
    uint8 *pRxShMemBuffer;          ///< Receive Shared Memory Buffer Virtual Address
    SUclCmnRingBuffer txRingBuffer; ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer; ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;     ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;     ///< Receive Ring Buffer Protection Mutex
    uint32 timerTaskId;             ///< MU TimerTask Id
	uint32 muStateChkTimerTaskId;	///< MU State Check TimerTask Id
    uint16 txBufferState;           ///< Transmit Buffer State
    uint16 txBufferSize;            ///< Transmit Buffer Size
    uint16 rxBufferState;           ///< Receive Buffer State
    uint16 rxBufferSize;            ///< Receive Buffer Size
} SUclALPhyMuFreeRtosSlaveInst;
typedef struct
{
    volatile uint32 TR[4];       ///< Processor A Transmit Register 0, array offset: 0x0, array step: 0x4
    volatile const uint32 RR[4]; ///< Processor A Receive Register 0, array offset: 0x10, array step: 0x4
    volatile uint32 SR;          ///< Processor A Status Register, offset: 0x20
    volatile uint32 CR;          ///< Processor A Control Register, offset: 0x24
} SUclALPhyMuReg;
SUclALPhyMuFreeRtosSlaveInst *myInst = malloc(sizeof(SUclALPhyMuFreeRtosSlaveInst));
SUclALPhyMuReg *myMUReg = malloc(sizeof(SUclALPhyMuReg));
//<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosMaster_Impl_Hw_MuOpen.pInst>> = ( myInst );
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst>>[0].pCfg[0].muBaseAddress = ( &myMUReg );

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.002
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst[0].pCfg[0].txShmMemPhyAddr:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst[0].pCfg[0].rxShmMemPhyAddr:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<null>>
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.return:0
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState.pInst[0].pMuRegs[0].CR:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState.state:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState.state:1
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst[0].pCfg[0].pTxRingBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.pInst[0].pCfg[0].pRxRingBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.pData:VECTORCAST_FLT1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:0
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize.return:0
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize.002
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize.return:1
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pData:<<null>>
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.return:-3
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.002
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_ReadFrame.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.003
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_ReadFrame.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.return:-1
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.004
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pSize:<<null>>
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.return:-3
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.005
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.pSize[0]:0
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read.return:-3
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.pInst[0].timerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.return:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexDestroy.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerDestroy.TimerId:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerDestroy.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.return:0
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.002
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown.return:1
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:<<null>>
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.return:-3
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.002
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<null>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.Size:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.return:-1
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.003
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:-1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.return:-1
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.004
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.005
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:"1"
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.return:-1
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.006
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.Size:0
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write.return:-3
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:4
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.return:VECTORCAST_STR1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.002
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:4
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.return:VECTORCAST_STR1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.003
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:4
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_TimerTask

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_TimerTask.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_TimerTask.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:0
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_TimerTask.002
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_TimerTask.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:0
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_TimerTask.003
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_TimerTask.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_TimerTask.004
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_TimerTask.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_TimerTask.005
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_TimerTask.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.mu_debug:0
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_TimerTask.006
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_TimerTask.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.mu_debug:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_TimerTask.007
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_TimerTask.007
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.mu_debug:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_TimerTask.008
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_TimerTask.008
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:3
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.mu_debug:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_TimerTask.009
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_TimerTask.009
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:4
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.mu_debug:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuFreeRtosSlave_Impl_Transfer

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Transfer.001
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Transfer.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Transfer.002
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Transfer.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x12340001
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:0
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:0
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_READY
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Transfer.003
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Transfer.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0..1]:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Transfer.004
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Transfer.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Transfer.005
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Transfer.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x12340001
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:0
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Transfer.006
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Transfer.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0..1]:0x2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:0
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Transfer.007
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Transfer.007
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:1
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.END

-- Test Case: UclALPhyMuFreeRtosSlave_Impl_Transfer.008
TEST.UNIT:UclALPhyMuFreeRtosSlave_Impl
TEST.SUBPROGRAM:UclALPhyMuFreeRtosSlave_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuFreeRtosSlave_Impl_Transfer.008
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[0]:0x2
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].RR[1]:0x12340001
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].SR:0xFFFFFFFF
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:0
TEST.VALUE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:3
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:1
TEST.EXPECTED:UclALPhyMuFreeRtosSlave_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst
<<UclALPhyMuFreeRtosSlave_Impl.UclALPhyMuFreeRtosSlave_Impl_Transfer.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END
