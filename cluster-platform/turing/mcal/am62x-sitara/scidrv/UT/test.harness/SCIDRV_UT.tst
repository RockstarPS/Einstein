-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : SCIDRV_UT
-- Unit(s) Under Test: SciDrv
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: ResumeAllInterrupts

-- Test Case: ResumeAllInterrupts.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:ResumeAllInterrupts
TEST.NEW
TEST.NAME:ResumeAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciAsyncModeHold[0]:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciSyncModeHold[0]:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.return:<<MID>>
TEST.VALUE:SciDrv.UART_masterIsr.arg:VECTORCAST_INT1
TEST.VALUE:SciDrv.SciDrv_UartDmaArmTx.swChannel:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.size:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pLengthFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pParityFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pdivisorValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableDivisorLatch.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pFcrValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pTcrTlrBitVal:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pEnhanFnBitVal:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pByteTx:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldMask:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldShift:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pFieldValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldMask:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldShift:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MID>>
TEST.END

-- Test Case: ResumeAllInterrupts.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:ResumeAllInterrupts
TEST.NEW
TEST.NAME:ResumeAllInterrupts.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciAsyncModeHold[0]:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciSyncModeHold[0]:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.UART_masterIsr.arg:VECTORCAST_INT1
TEST.VALUE:SciDrv.SciDrv_UartDmaArmTx.swChannel:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[0]:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Cancel.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].data:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].read_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].write_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].fill_count:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].data:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].read_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].write_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].fill_count:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.data:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.size:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].data:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].read_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].write_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength[0]:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength[0]:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pInterruptFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pInterruptFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pLengthFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pParityFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pModeFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pdivisorValue:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DisableDivisorLatch.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pFcrValue:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pTcrTlrBitVal:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pEnhanFnBitVal:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pByteTx:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldMask:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldShift:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pFieldValue:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldMask:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldShift:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pValue:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MAX>>
TEST.END

-- Test Case: ResumeAllInterrupts.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:ResumeAllInterrupts
TEST.NEW
TEST.NAME:ResumeAllInterrupts.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciAsyncModeHold[0]:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciSyncModeHold[0]:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.UART_masterIsr.arg:VECTORCAST_INT1
TEST.VALUE:SciDrv.SciDrv_UartDmaArmTx.swChannel:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.size:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pLengthFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pParityFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pdivisorValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableDivisorLatch.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pFcrValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pTcrTlrBitVal:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pEnhanFnBitVal:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pByteTx:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldMask:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldShift:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pFieldValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldMask:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldShift:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Subprogram: SciDrv_ASyncReceive

-- Test Case: SciDrv_ASyncReceive.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncReceive
TEST.NEW
TEST.NAME:SciDrv_ASyncReceive.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_ASyncReceive.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncReceive
TEST.NEW
TEST.NAME:SciDrv_ASyncReceive.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Last
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:5
TEST.END

-- Test Case: SciDrv_ASyncReceive.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncReceive
TEST.NEW
TEST.NAME:SciDrv_ASyncReceive.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_ASyncReceive.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncReceive
TEST.NEW
TEST.NAME:SciDrv_ASyncReceive.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:eSciDrvAsyncMode_Dma
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_ASyncReceive.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncReceive
TEST.NEW
TEST.NAME:SciDrv_ASyncReceive.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:33
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:eSciDrvAsyncMode_Dma
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_ASyncReceive.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncReceive
TEST.NEW
TEST.NAME:SciDrv_ASyncReceive.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:eSciDrvAsyncMode_Dma
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:5
TEST.END

-- Test Case: SciDrv_ASyncReceive.008
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncReceive
TEST.NEW
TEST.NAME:SciDrv_ASyncReceive.008
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:3000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:eSciDrvAsyncMode_Interrupt
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Subprogram: SciDrv_ASyncTransmit

-- Test Case: SciDrv_ASyncTransmit.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncTransmit
TEST.NEW
TEST.NAME:SciDrv_ASyncTransmit.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_ASyncTransmit.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncTransmit
TEST.NEW
TEST.NAME:SciDrv_ASyncTransmit.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_ASyncTransmit.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncTransmit
TEST.NEW
TEST.NAME:SciDrv_ASyncTransmit.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:5
TEST.END

-- Test Case: SciDrv_ASyncTransmit.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncTransmit
TEST.NEW
TEST.NAME:SciDrv_ASyncTransmit.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_ASyncTransmit.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncTransmit
TEST.NEW
TEST.NAME:SciDrv_ASyncTransmit.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:eSciDrvAsyncMode_Interrupt
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_ASyncTransmit.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncTransmit
TEST.NEW
TEST.NAME:SciDrv_ASyncTransmit.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableTransmitInterrupt
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:eSciDrvAsyncMode_Interrupt
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.EXPECTED:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.END

-- Test Case: SciDrv_ASyncTransmit.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ASyncTransmit
TEST.NEW
TEST.NAME:SciDrv_ASyncTransmit.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:eSciDrvAsyncMode_Dma
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.EXPECTED:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.END

-- Subprogram: SciDrv_Cancel

-- Test Case: SciDrv_Cancel.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Cancel
TEST.NEW
TEST.NAME:SciDrv_Cancel.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_Cancel.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Cancel
TEST.NEW
TEST.NAME:SciDrv_Cancel.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_Cancel.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Cancel
TEST.NEW
TEST.NAME:SciDrv_Cancel.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:5
TEST.END

-- Test Case: SciDrv_Cancel.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Cancel
TEST.NEW
TEST.NAME:SciDrv_Cancel.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:eSciDrvDirection_Last
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_Cancel.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Cancel
TEST.NEW
TEST.NAME:SciDrv_Cancel.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_Cancel.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Cancel
TEST.NEW
TEST.NAME:SciDrv_Cancel.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwCancelTransmit
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_Cancel.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Cancel
TEST.NEW
TEST.NAME:SciDrv_Cancel.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwCancelTransmit
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_Cancel.008
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Cancel
TEST.NEW
TEST.NAME:SciDrv_Cancel.008
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwCancelReceive
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_Cancel.009
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Cancel
TEST.NEW
TEST.NAME:SciDrv_Cancel.009
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwCancelReceive
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Subprogram: SciDrv_ComputeDivisorValue

-- Test Case: SciDrv_ComputeDivisorValue.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ComputeDivisorValue
TEST.NEW
TEST.NAME:SciDrv_ComputeDivisorValue.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:48000000
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:115200
TEST.END

-- Test Case: SciDrv_ComputeDivisorValue.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ComputeDivisorValue
TEST.NEW
TEST.NAME:SciDrv_ComputeDivisorValue.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:48000000
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:115200
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:3
TEST.END

-- Test Case: SciDrv_ComputeDivisorValue.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ComputeDivisorValue
TEST.NEW
TEST.NAME:SciDrv_ComputeDivisorValue.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:48000000
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:115200
TEST.END

-- Test Case: SciDrv_ComputeDivisorValue.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ComputeDivisorValue
TEST.NEW
TEST.NAME:SciDrv_ComputeDivisorValue.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:7
TEST.ATTRIBUTES:SciDrv.SciDrv_Read_Reg32.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_DeInit

-- Test Case: SciDrv_DeInit.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DeInit
TEST.NEW
TEST.NAME:SciDrv_DeInit.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.END

-- Subprogram: SciDrv_DisableChn

-- Test Case: SciDrv_DisableChn.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DisableChn
TEST.NEW
TEST.NAME:SciDrv_DisableChn.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_GetChnResult
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_DisableChn.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DisableChn
TEST.NEW
TEST.NAME:SciDrv_DisableChn.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_GetChnResult
TEST.STUB:SciDrv.SciDrv_HwChannelDeinit
TEST.STUB:SciDrv.SciDrv_HwFifoDeinit
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_DisableChn.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DisableChn
TEST.NEW
TEST.NAME:SciDrv_DisableChn.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:5
TEST.END

-- Test Case: SciDrv_DisableChn.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DisableChn
TEST.NEW
TEST.NAME:SciDrv_DisableChn.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_GetChnResult
TEST.STUB:SciDrv.SciDrv_HwChannelDeinit
TEST.STUB:SciDrv.SciDrv_HwFifoDeinit
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Subprogram: SciDrv_DisableDivisorLatch

-- Test Case: SciDrv_DisableDivisorLatch.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DisableDivisorLatch
TEST.NEW
TEST.NAME:SciDrv_DisableDivisorLatch.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.ATTRIBUTES:SciDrv.SciDrv_HwReadLineStatus.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_DivideRoundCloset

-- Test Case: SciDrv_DivideRoundCloset.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DivideRoundCloset
TEST.NEW
TEST.NAME:SciDrv_DivideRoundCloset.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:4
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:2
TEST.END

-- Subprogram: SciDrv_DmaRxComplete

-- Test Case: SciDrv_DmaRxComplete.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DmaRxComplete
TEST.NEW
TEST.NAME:SciDrv_DmaRxComplete.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_DmaRxComplete.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DmaRxComplete
TEST.NEW
TEST.NAME:SciDrv_DmaRxComplete.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.ATTRIBUTES:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:INPUT_BASE=10
TEST.END

-- Subprogram: SciDrv_DmaTxComplete

-- Test Case: SciDrv_DmaTxComplete.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DmaTxComplete
TEST.NEW
TEST.NAME:SciDrv_DmaTxComplete.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciAsyncModeHold[0]:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciSyncModeHold[0]:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.UART_masterIsr.arg:VECTORCAST_INT1
TEST.VALUE:SciDrv.SciDrv_UartDmaArmTx.swChannel:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.size:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pLengthFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pParityFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pdivisorValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableDivisorLatch.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pFcrValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pTcrTlrBitVal:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pEnhanFnBitVal:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pByteTx:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldMask:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldShift:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pFieldValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldMask:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldShift:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_DmaTxComplete.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_DmaTxComplete
TEST.NEW
TEST.NAME:SciDrv_DmaTxComplete.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:Client_PhyTransmitCallback
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Subprogram: SciDrv_EnableChn

-- Test Case: SciDrv_EnableChn.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_EnableChn
TEST.NEW
TEST.NAME:SciDrv_EnableChn.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_EnableChn.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_EnableChn
TEST.NEW
TEST.NAME:SciDrv_EnableChn.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Last
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:5
TEST.END

-- Test Case: SciDrv_EnableChn.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_EnableChn
TEST.NEW
TEST.NAME:SciDrv_EnableChn.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_InitChnInfo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:0
TEST.END

-- Test Case: SciDrv_EnableChn.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_EnableChn
TEST.NEW
TEST.NAME:SciDrv_EnableChn.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_InitChnInfo
TEST.STUB:SciDrv.SciDrv_HwChannelInit
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:0
TEST.END

-- Subprogram: SciDrv_GetChnResult

-- Test Case: SciDrv_GetChnResult.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_GetChnResult
TEST.NEW
TEST.NAME:SciDrv_GetChnResult.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_GetChnResult.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_GetChnResult
TEST.NEW
TEST.NAME:SciDrv_GetChnResult.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:eSciDrvDirection_Last
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_GetChnResult.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_GetChnResult
TEST.NEW
TEST.NAME:SciDrv_GetChnResult.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:2
TEST.END

-- Test Case: SciDrv_GetChnResult.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_GetChnResult
TEST.NEW
TEST.NAME:SciDrv_GetChnResult.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:2
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:3
TEST.END

-- Test Case: SciDrv_GetChnResult.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_GetChnResult
TEST.NEW
TEST.NAME:SciDrv_GetChnResult.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:2
TEST.END

-- Test Case: SciDrv_GetChnResult.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_GetChnResult
TEST.NEW
TEST.NAME:SciDrv_GetChnResult.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 2>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[1]:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:2
TEST.END

-- Test Case: SciDrv_GetChnResult.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_GetChnResult
TEST.NEW
TEST.NAME:SciDrv_GetChnResult.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:2
TEST.END

-- Subprogram: SciDrv_GetStatus

-- Test Case: SciDrv_GetStatus.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_GetStatus
TEST.NEW
TEST.NAME:SciDrv_GetStatus.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:eSciDrvStatus_Ready
TEST.END

-- Subprogram: SciDrv_HwBreakControl

-- Test Case: SciDrv_HwBreakControl.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwBreakControl
TEST.NEW
TEST.NAME:SciDrv_HwBreakControl.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:0
TEST.END

-- Subprogram: SciDrv_HwCancelReceive

-- Test Case: SciDrv_HwCancelReceive.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwCancelReceive
TEST.NEW
TEST.NAME:SciDrv_HwCancelReceive.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwInterruptDisable
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwCancelTransmit

-- Test Case: SciDrv_HwCancelTransmit.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwCancelTransmit
TEST.NEW
TEST.NAME:SciDrv_HwCancelTransmit.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwInterruptDisable
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:0x4A00000
TEST.EXPECTED:SciDrv.SciDrv_HwInterruptDisable.pRegBase:0
TEST.END

-- Subprogram: SciDrv_HwChannelDeinit

-- Test Case: SciDrv_HwChannelDeinit.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwChannelDeinit
TEST.NEW
TEST.NAME:SciDrv_HwChannelDeinit.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.END

-- Test Case: SciDrv_HwChannelDeinit.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwChannelDeinit
TEST.NEW
TEST.NAME:SciDrv_HwChannelDeinit.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwInterruptDisable
TEST.STUB:SciDrv.SciDrv_HwInterrupt2Disable
TEST.STUB:SciDrv.SciDrv_HwOperatingModeSelect
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.END

-- Subprogram: SciDrv_HwChannelInit

-- Test Case: SciDrv_HwChannelInit.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwChannelInit
TEST.NEW
TEST.NAME:SciDrv_HwChannelInit.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.END

-- Test Case: SciDrv_HwChannelInit.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwChannelInit
TEST.NEW
TEST.NAME:SciDrv_HwChannelInit.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_ResetModule
TEST.STUB:SciDrv.SciDrv_HwLineCharConfig
TEST.STUB:SciDrv.SciDrv_HwOperatingModeSelect
TEST.STUB:SciDrv.SciDrv_HwBreakControl
TEST.STUB:SciDrv.SciDrv_HwEnableRegisterConfigMode
TEST.STUB:SciDrv.SciDrv_ComputeDivisorValue
TEST.STUB:SciDrv.SciDrv_HwWriteDivisorLatch
TEST.STUB:SciDrv.SciDrv_DisableDivisorLatch
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:48000000
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:115200
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:0
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:0x4A00000
TEST.ATTRIBUTES:SciDrv.SciDrv_HwInterruptDisable.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwDisableReceiveInterrupt

-- Test Case: SciDrv_HwDisableReceiveInterrupt.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwDisableReceiveInterrupt
TEST.NEW
TEST.NAME:SciDrv_HwDisableReceiveInterrupt.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwInterruptDisable
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwDisableTransmitInterrupt

-- Test Case: SciDrv_HwDisableTransmitInterrupt.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwDisableTransmitInterrupt
TEST.NEW
TEST.NAME:SciDrv_HwDisableTransmitInterrupt.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwInterruptDisable
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwEnableEnhaceFunc

-- Test Case: SciDrv_HwEnableEnhaceFunc.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwEnableEnhaceFunc
TEST.NEW
TEST.NAME:SciDrv_HwEnableEnhaceFunc.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableRegisterConfigMode
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwEnableReceiveInterrupt

-- Test Case: SciDrv_HwEnableReceiveInterrupt.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwEnableReceiveInterrupt
TEST.NEW
TEST.NAME:SciDrv_HwEnableReceiveInterrupt.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwInterruptEnable
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwEnableRegisterConfigMode

-- Test Case: SciDrv_HwEnableRegisterConfigMode.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwEnableRegisterConfigMode
TEST.NEW
TEST.NAME:SciDrv_HwEnableRegisterConfigMode.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:0x4A00000
TEST.END

-- Test Case: SciDrv_HwEnableRegisterConfigMode.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwEnableRegisterConfigMode
TEST.NEW
TEST.NAME:SciDrv_HwEnableRegisterConfigMode.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:0x80
TEST.END

-- Test Case: SciDrv_HwEnableRegisterConfigMode.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwEnableRegisterConfigMode
TEST.NEW
TEST.NAME:SciDrv_HwEnableRegisterConfigMode.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:0xBF
TEST.END

-- Test Case: SciDrv_HwEnableRegisterConfigMode.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwEnableRegisterConfigMode
TEST.NEW
TEST.NAME:SciDrv_HwEnableRegisterConfigMode.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:0x7F
TEST.END

-- Subprogram: SciDrv_HwEnableTransmitInterrupt

-- Test Case: SciDrv_HwEnableTransmitInterrupt.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwEnableTransmitInterrupt
TEST.NEW
TEST.NAME:SciDrv_HwEnableTransmitInterrupt.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwInterruptEnable
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwEnhanFuncBitValRestore

-- Test Case: SciDrv_HwEnhanFuncBitValRestore.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwEnhanFuncBitValRestore
TEST.NEW
TEST.NAME:SciDrv_HwEnhanFuncBitValRestore.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableRegisterConfigMode
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwFifoConfig

-- Test Case: SciDrv_HwFifoConfig.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.END

-- Test Case: SciDrv_HwFifoConfig.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0x2000230
TEST.END

-- Test Case: SciDrv_HwFifoConfig.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0x2000610
TEST.END

-- Test Case: SciDrv_HwFifoConfig.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:16
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0x2000618
TEST.END

-- Test Case: SciDrv_HwFifoConfig.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:16
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0x4000000
TEST.END

-- Test Case: SciDrv_HwFifoConfig.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:16
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0x400000
TEST.END

-- Test Case: SciDrv_HwFifoConfig.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:16
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0x40000
TEST.END

-- Test Case: SciDrv_HwFifoConfig.008
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.008
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:16
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0x20000
TEST.END

-- Test Case: SciDrv_HwFifoConfig.009
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.009
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:16
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0x80000
TEST.END

-- Test Case: SciDrv_HwFifoConfig.010
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.010
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:16
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0xE0000
TEST.END

-- Test Case: SciDrv_HwFifoConfig.011
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.011
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:16
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0x400
TEST.END

-- Test Case: SciDrv_HwFifoConfig.012
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.012
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:16
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0xE00
TEST.END

-- Test Case: SciDrv_HwFifoConfig.013
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoConfig
TEST.NEW
TEST.NAME:SciDrv_HwFifoConfig.013
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoInit
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn
TEST.STUB:SciDrv.SciDrv_HwFifoRegisterWrite
TEST.STUB:SciDrv.SciDrv_HwTcrTlrBitValRestore
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:16
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:0xF00
TEST.END

-- Subprogram: SciDrv_HwFifoDeinit

-- Test Case: SciDrv_HwFifoDeinit.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoDeinit
TEST.NEW
TEST.NAME:SciDrv_HwFifoDeinit.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.END

-- Test Case: SciDrv_HwFifoDeinit.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoDeinit
TEST.NEW
TEST.NAME:SciDrv_HwFifoDeinit.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwFifoInit

-- Test Case: SciDrv_HwFifoInit.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoInit
TEST.NEW
TEST.NAME:SciDrv_HwFifoInit.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.END

-- Test Case: SciDrv_HwFifoInit.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoInit
TEST.NEW
TEST.NAME:SciDrv_HwFifoInit.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoConfig
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:eSciDrvAsyncMode_Interrupt
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:0
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_HwFifoInit.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoInit
TEST.NEW
TEST.NAME:SciDrv_HwFifoInit.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoConfig
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:eSciDrvAsyncMode_Last
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:0
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_HwFifoInit.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoInit
TEST.NEW
TEST.NAME:SciDrv_HwFifoInit.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwFifoConfig
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:eSciDrvAsyncMode_Dma
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:0
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwFifoRegisterWrite

-- Test Case: SciDrv_HwFifoRegisterWrite.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwFifoRegisterWrite
TEST.NEW
TEST.NAME:SciDrv_HwFifoRegisterWrite.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwEnableRegisterConfigMode
TEST.STUB:SciDrv.SciDrv_HwWriteDivisorLatch
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwGetIntrIdentityStatus

-- Test Case: SciDrv_HwGetIntrIdentityStatus.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwGetIntrIdentityStatus
TEST.NEW
TEST.NAME:SciDrv_HwGetIntrIdentityStatus.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:0x4A00000
TEST.ATTRIBUTES:SciDrv.SciDrv_HwPutChar.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwGetSwChnID

-- Test Case: SciDrv_HwGetSwChnID.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwGetSwChnID
TEST.NEW
TEST.NAME:SciDrv_HwGetSwChnID.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_HwGetSwChnID.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwGetSwChnID
TEST.NEW
TEST.NAME:SciDrv_HwGetSwChnID.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:5
TEST.END

-- Subprogram: SciDrv_HwInterrupt2Disable

-- Test Case: SciDrv_HwInterrupt2Disable.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterrupt2Disable
TEST.NEW
TEST.NAME:SciDrv_HwInterrupt2Disable.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwInterrupt2Enable

-- Test Case: SciDrv_HwInterrupt2Enable.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterrupt2Enable
TEST.NEW
TEST.NAME:SciDrv_HwInterrupt2Enable.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwInterruptDisable

-- Test Case: SciDrv_HwInterruptDisable.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterruptDisable
TEST.NEW
TEST.NAME:SciDrv_HwInterruptDisable.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:1
TEST.END

-- Test Case: SciDrv_HwInterruptDisable.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterruptDisable
TEST.NEW
TEST.NAME:SciDrv_HwInterruptDisable.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:0x20
TEST.END

-- Subprogram: SciDrv_HwInterruptEnable

-- Test Case: SciDrv_HwInterruptEnable.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterruptEnable
TEST.NEW
TEST.NAME:SciDrv_HwInterruptEnable.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:0x4A00000
TEST.END

-- Test Case: SciDrv_HwInterruptEnable.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterruptEnable
TEST.NEW
TEST.NAME:SciDrv_HwInterruptEnable.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:0x20
TEST.END

-- Subprogram: SciDrv_HwInterruptReadFifo

-- Test Case: SciDrv_HwInterruptReadFifo.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterruptReadFifo
TEST.NEW
TEST.NAME:SciDrv_HwInterruptReadFifo.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.END

-- Test Case: SciDrv_HwInterruptReadFifo.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterruptReadFifo
TEST.NEW
TEST.NAME:SciDrv_HwInterruptReadFifo.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_HwInterruptReadFifo.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterruptReadFifo
TEST.NEW
TEST.NAME:SciDrv_HwInterruptReadFifo.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:5
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:3
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwInterruptWriteFifo

-- Test Case: SciDrv_HwInterruptWriteFifo.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterruptWriteFifo
TEST.NEW
TEST.NAME:SciDrv_HwInterruptWriteFifo.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwPutChar
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:35
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_HwInterruptWriteFifo.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwInterruptWriteFifo
TEST.NEW
TEST.NAME:SciDrv_HwInterruptWriteFifo.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwPutChar
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:4294967295
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:30
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwLineCharConfig

-- Test Case: SciDrv_HwLineCharConfig.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwLineCharConfig
TEST.NEW
TEST.NAME:SciDrv_HwLineCharConfig.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwModuleReset

-- Test Case: SciDrv_HwModuleReset.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwModuleReset
TEST.NEW
TEST.NAME:SciDrv_HwModuleReset.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:0x4A00000
TEST.ATTRIBUTES:SciDrv.SciDrv_HwReadLineStatus.return:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_HwModuleReset.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwModuleReset
TEST.NEW
TEST.NAME:SciDrv_HwModuleReset.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:20
TEST.END

-- Subprogram: SciDrv_HwOperatingModeSelect

-- Test Case: SciDrv_HwOperatingModeSelect.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwOperatingModeSelect
TEST.NEW
TEST.NAME:SciDrv_HwOperatingModeSelect.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwPollingReadFifo

-- Test Case: SciDrv_HwPollingReadFifo.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPollingReadFifo
TEST.NEW
TEST.NAME:SciDrv_HwPollingReadFifo.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.END

-- Test Case: SciDrv_HwPollingReadFifo.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPollingReadFifo
TEST.NEW
TEST.NAME:SciDrv_HwPollingReadFifo.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_HwPollingReadFifo.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPollingReadFifo
TEST.NEW
TEST.NAME:SciDrv_HwPollingReadFifo.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:5
TEST.ATTRIBUTES:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_HwPollingReadFifo.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPollingReadFifo
TEST.NEW
TEST.NAME:SciDrv_HwPollingReadFifo.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:33
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:5
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:5
TEST.END

-- Test Case: SciDrv_HwPollingReadFifo.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPollingReadFifo
TEST.NEW
TEST.NAME:SciDrv_HwPollingReadFifo.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:5
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:10
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:10
TEST.END

-- Subprogram: SciDrv_HwPollingWriteFifo

-- Test Case: SciDrv_HwPollingWriteFifo.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPollingWriteFifo
TEST.NEW
TEST.NAME:SciDrv_HwPollingWriteFifo.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.END

-- Test Case: SciDrv_HwPollingWriteFifo.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPollingWriteFifo
TEST.NEW
TEST.NAME:SciDrv_HwPollingWriteFifo.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:10
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:40
TEST.END

-- Test Case: SciDrv_HwPollingWriteFifo.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPollingWriteFifo
TEST.NEW
TEST.NAME:SciDrv_HwPollingWriteFifo.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.END

-- Test Case: SciDrv_HwPollingWriteFifo.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPollingWriteFifo
TEST.NEW
TEST.NAME:SciDrv_HwPollingWriteFifo.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:20
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:60
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_HwPollingWriteFifo.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPollingWriteFifo
TEST.NEW
TEST.NAME:SciDrv_HwPollingWriteFifo.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:20
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:60
TEST.ATTRIBUTES:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_HwPutChar

-- Test Case: SciDrv_HwPutChar.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwPutChar
TEST.NEW
TEST.NAME:SciDrv_HwPutChar.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwReadLineStatus

-- Test Case: SciDrv_HwReadLineStatus.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwReadLineStatus
TEST.NEW
TEST.NAME:SciDrv_HwReadLineStatus.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwSubConfigTCRTLRModeEn

-- Test Case: SciDrv_HwSubConfigTCRTLRModeEn.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSubConfigTCRTLRModeEn
TEST.NEW
TEST.NAME:SciDrv_HwSubConfigTCRTLRModeEn.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableRegisterConfigMode
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwSyncReceive

-- Test Case: SciDrv_HwSyncReceive.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSyncReceive
TEST.NEW
TEST.NAME:SciDrv_HwSyncReceive.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.END

-- Test Case: SciDrv_HwSyncReceive.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSyncReceive
TEST.NEW
TEST.NAME:SciDrv_HwSyncReceive.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwPollingReadFifo
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.END

-- Test Case: SciDrv_HwSyncReceive.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSyncReceive
TEST.NEW
TEST.NAME:SciDrv_HwSyncReceive.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwPollingReadFifo
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:1
TEST.END

-- Subprogram: SciDrv_HwSyncTransmit

-- Test Case: SciDrv_HwSyncTransmit.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSyncTransmit
TEST.NEW
TEST.NAME:SciDrv_HwSyncTransmit.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:<<malloc 1>>
TEST.END

-- Test Case: SciDrv_HwSyncTransmit.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSyncTransmit
TEST.NEW
TEST.NAME:SciDrv_HwSyncTransmit.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:<<malloc 1>>
TEST.END

-- Test Case: SciDrv_HwSyncTransmit.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSyncTransmit
TEST.NEW
TEST.NAME:SciDrv_HwSyncTransmit.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwPollingWriteFifo
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:20
TEST.END

-- Test Case: SciDrv_HwSyncTransmit.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSyncTransmit
TEST.NEW
TEST.NAME:SciDrv_HwSyncTransmit.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwPollingWriteFifo
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:20
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:1
TEST.END

-- Test Case: SciDrv_HwSyncTransmit.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSyncTransmit
TEST.NEW
TEST.NAME:SciDrv_HwSyncTransmit.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwPollingWriteFifo
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:20
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:1
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:0xA0F
TEST.END

-- Test Case: SciDrv_HwSyncTransmit.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSyncTransmit
TEST.NEW
TEST.NAME:SciDrv_HwSyncTransmit.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwPollingWriteFifo
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:20
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:0x60
TEST.END

-- Test Case: SciDrv_HwSyncTransmit.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwSyncTransmit
TEST.NEW
TEST.NAME:SciDrv_HwSyncTransmit.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwPollingWriteFifo
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:0xFFFFFFFF
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData[0]:0
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:0x60
TEST.END

-- Subprogram: SciDrv_HwTcrTlrBitValRestore

-- Test Case: SciDrv_HwTcrTlrBitValRestore.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwTcrTlrBitValRestore
TEST.NEW
TEST.NAME:SciDrv_HwTcrTlrBitValRestore.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableRegisterConfigMode
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_HwWriteDivisorLatch

-- Test Case: SciDrv_HwWriteDivisorLatch.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_HwWriteDivisorLatch
TEST.NEW
TEST.NAME:SciDrv_HwWriteDivisorLatch.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableRegisterConfigMode
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_Init

-- Test Case: SciDrv_Init.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Init
TEST.NEW
TEST.NAME:SciDrv_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.END

-- Test Case: SciDrv_Init.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_Init
TEST.NEW
TEST.NAME:SciDrv_Init.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.END

-- Subprogram: SciDrv_InitChnInfo

-- Test Case: SciDrv_InitChnInfo.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_InitChnInfo
TEST.NEW
TEST.NAME:SciDrv_InitChnInfo.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.END

-- Subprogram: SciDrv_MainFunction

-- Test Case: SciDrv_MainFunction.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_MainFunction
TEST.NEW
TEST.NAME:SciDrv_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.END

-- Test Case: SciDrv_MainFunction.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_MainFunction
TEST.NEW
TEST.NAME:SciDrv_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Ok
TEST.END

-- Test Case: SciDrv_MainFunction.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_MainFunction
TEST.NEW
TEST.NAME:SciDrv_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.END

-- Test Case: SciDrv_MainFunction.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_MainFunction
TEST.NEW
TEST.NAME:SciDrv_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.ATTRIBUTES:SciDrv.SciDrv_HwReadLineStatus.return:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_MainFunction.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_MainFunction
TEST.NEW
TEST.NAME:SciDrv_MainFunction.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.ATTRIBUTES:SciDrv.SciDrv_HwModuleReset.pRegBase:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwReadLineStatus.return:INPUT_BASE=16
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_MainFunction.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_MainFunction
TEST.NEW
TEST.NAME:SciDrv_MainFunction.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:100
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.ATTRIBUTES:SciDrv.SciDrv_HwModuleReset.pRegBase:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwReadLineStatus.return:INPUT_BASE=16
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: SciDrv_ReadIB

-- Test Case: SciDrv_ReadIB.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReadIB
TEST.NEW
TEST.NAME:SciDrv_ReadIB.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<max>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<max>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<max>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MAX>>
TEST.END

-- Test Case: SciDrv_ReadIB.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReadIB
TEST.NEW
TEST.NAME:SciDrv_ReadIB.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:eSciDrvDirection_Last
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_ReadIB.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReadIB
TEST.NEW
TEST.NAME:SciDrv_ReadIB.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciAsyncModeHold[0]:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciSyncModeHold[0]:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.return:<<MID>>
TEST.VALUE:SciDrv.UART_masterIsr.arg:VECTORCAST_INT1
TEST.VALUE:SciDrv.SciDrv_UartDmaArmTx.swChannel:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.size:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pLengthFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pParityFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pdivisorValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableDivisorLatch.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pFcrValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pTcrTlrBitVal:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pEnhanFnBitVal:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pByteTx:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldMask:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldShift:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pFieldValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldMask:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldShift:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MID>>
TEST.END

-- Test Case: SciDrv_ReadIB.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReadIB
TEST.NEW
TEST.NAME:SciDrv_ReadIB.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_ReadIB.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReadIB
TEST.NEW
TEST.NAME:SciDrv_ReadIB.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_ReadIB.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReadIB
TEST.NEW
TEST.NAME:SciDrv_ReadIB.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:eSciDrvDirection_Last
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_ReadIB.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReadIB
TEST.NEW
TEST.NAME:SciDrv_ReadIB.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_RingBufferRead
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:0
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:0
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_ReadIB.008
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReadIB
TEST.NEW
TEST.NAME:SciDrv_ReadIB.008
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_RingBufferRead
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:0
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:0
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_ReadIB.009
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReadIB
TEST.NEW
TEST.NAME:SciDrv_ReadIB.009
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_RingBufferRead
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:1
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_ReadIB.010
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReadIB
TEST.NEW
TEST.NAME:SciDrv_ReadIB.010
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_RingBufferRead
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:1
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:1
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Subprogram: SciDrv_ReceiveErrorRecovery

-- Test Case: SciDrv_ReceiveErrorRecovery.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReceiveErrorRecovery
TEST.NEW
TEST.NAME:SciDrv_ReceiveErrorRecovery.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwWriteDivisorLatch
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.ATTRIBUTES:SciDrv.SciDrv_HwModuleReset.pRegBase:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwReadLineStatus.return:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_ReceiveErrorRecovery.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ReceiveErrorRecovery
TEST.NEW
TEST.NAME:SciDrv_ReceiveErrorRecovery.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwEnableRegisterConfigMode
TEST.STUB:SciDrv.SciDrv_HwWriteDivisorLatch
TEST.STUB:SciDrv.SciDrv_HwEnhanFuncBitValRestore
TEST.STUB:SciDrv.SciDrv_Write_Field32
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.ATTRIBUTES:SciDrv.SciDrv_HwModuleReset.pRegBase:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_HwReadLineStatus.return:INPUT_BASE=16
TEST.END

-- Subprogram: SciDrv_ResetModule

-- Test Case: SciDrv_ResetModule.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_ResetModule
TEST.NEW
TEST.NAME:SciDrv_ResetModule.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableEnhaceFunc
TEST.STUB:SciDrv.SciDrv_HwModuleReset
TEST.STUB:SciDrv.SciDrv_HwInterruptDisable
TEST.STUB:SciDrv.SciDrv_HwInterrupt2Disable
TEST.STUB:SciDrv.SciDrv_HwOperatingModeSelect
TEST.STUB:SciDrv.SciDrv_Write_Reg32
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:0x4A00000
TEST.END

-- Subprogram: SciDrv_RingBufferRead

-- Test Case: SciDrv_RingBufferRead.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_RingBufferRead
TEST.NEW
TEST.NAME:SciDrv_RingBufferRead.002
TEST.VALUE:SciDrv.<<GLOBAL>>.SciAsyncModeHold[0]:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciSyncModeHold[0]:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.UART_masterIsr.arg:VECTORCAST_INT1
TEST.VALUE:SciDrv.SciDrv_UartDmaArmTx.swChannel:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.size:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pLengthFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pParityFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pdivisorValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableDivisorLatch.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pFcrValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pTcrTlrBitVal:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pEnhanFnBitVal:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pByteTx:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldMask:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldShift:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pFieldValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldMask:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldShift:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_RingBufferRead.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_RingBufferRead
TEST.NEW
TEST.NAME:SciDrv_RingBufferRead.005
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:1
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_RingBufferRead.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_RingBufferRead
TEST.NEW
TEST.NAME:SciDrv_RingBufferRead.006
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:0
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:<<malloc 8>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_RingBufferRead.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_RingBufferRead
TEST.NEW
TEST.NAME:SciDrv_RingBufferRead.007
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:0
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_RingBufferRead.008
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_RingBufferRead
TEST.NEW
TEST.NAME:SciDrv_RingBufferRead.008
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:1
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Subprogram: SciDrv_RingBufferWrite

-- Test Case: SciDrv_RingBufferWrite.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_RingBufferWrite
TEST.NEW
TEST.NAME:SciDrv_RingBufferWrite.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciAsyncModeHold[0]:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciSyncModeHold[0]:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.value:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.addr:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.mask:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.shift:<<MAX>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.return:<<MAX>>
TEST.VALUE:SciDrv.UART_masterIsr.arg:VECTORCAST_INT1
TEST.VALUE:SciDrv.SciDrv_UartDmaArmTx.swChannel:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Init.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[0]:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Cancel.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].data:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].read_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].write_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].fill_count:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].data:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].read_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].write_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].fill_count:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.data:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.size:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].data:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].read_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].write_index:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength[0]:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength[0]:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pInterruptFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pInterruptFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pLengthFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pParityFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pModeFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pdivisorValue:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_DisableDivisorLatch.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pFcrValue:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pTcrTlrBitVal:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pEnhanFnBitVal:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pByteTx:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldMask:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldShift:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pFieldValue:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldMask:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldShift:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pValue:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MAX>>
TEST.END

-- Test Case: SciDrv_RingBufferWrite.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_RingBufferWrite
TEST.NEW
TEST.NAME:SciDrv_RingBufferWrite.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciAsyncModeHold[0]:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciSyncModeHold[0]:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.value:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.addr:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.mask:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.shift:<<MIN>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.return:<<MIN>>
TEST.VALUE:SciDrv.UART_masterIsr.arg:VECTORCAST_INT1
TEST.VALUE:SciDrv.SciDrv_UartDmaArmTx.swChannel:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Init.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Cancel.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.size:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].read_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].write_index:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pInterruptFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pLengthFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pParityFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pdivisorValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_DisableDivisorLatch.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pFcrValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pTcrTlrBitVal:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pEnhanFnBitVal:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pByteTx:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldMask:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldShift:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pFieldValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldMask:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldShift:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pValue:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_RingBufferWrite.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_RingBufferWrite
TEST.NEW
TEST.NAME:SciDrv_RingBufferWrite.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciAsyncModeHold[0]:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciSyncModeHold[0]:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.return:<<MID>>
TEST.VALUE:SciDrv.UART_masterIsr.arg:VECTORCAST_INT1
TEST.VALUE:SciDrv.SciDrv_UartDmaArmTx.swChannel:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.size:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pLengthFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pParityFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pdivisorValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableDivisorLatch.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pFcrValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pTcrTlrBitVal:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pEnhanFnBitVal:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pByteTx:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldMask:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldShift:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pFieldValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldMask:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldShift:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MID>>
TEST.END

-- Subprogram: SciDrv_SetAsyncMode

-- Test Case: SciDrv_SetAsyncMode.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetAsyncMode
TEST.NEW
TEST.NAME:SciDrv_SetAsyncMode.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:eSciDrvAsyncMode_Polling
TEST.END

-- Test Case: SciDrv_SetAsyncMode.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetAsyncMode
TEST.NEW
TEST.NAME:SciDrv_SetAsyncMode.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:eSciDrvAsyncMode_Last
TEST.END

-- Test Case: SciDrv_SetAsyncMode.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetAsyncMode
TEST.NEW
TEST.NAME:SciDrv_SetAsyncMode.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:3
TEST.END

-- Test Case: SciDrv_SetAsyncMode.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetAsyncMode
TEST.NEW
TEST.NAME:SciDrv_SetAsyncMode.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:eSciDrvAsyncMode_Dma
TEST.END

-- Test Case: SciDrv_SetAsyncMode.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetAsyncMode
TEST.NEW
TEST.NAME:SciDrv_SetAsyncMode.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:0
TEST.END

-- Subprogram: SciDrv_SetSyncMode

-- Test Case: SciDrv_SetSyncMode.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetSyncMode
TEST.NEW
TEST.NAME:SciDrv_SetSyncMode.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SetSyncMode.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetSyncMode
TEST.NEW
TEST.NAME:SciDrv_SetSyncMode.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:4
TEST.END

-- Test Case: SciDrv_SetSyncMode.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetSyncMode
TEST.NEW
TEST.NAME:SciDrv_SetSyncMode.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SetSyncMode.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetSyncMode
TEST.NEW
TEST.NAME:SciDrv_SetSyncMode.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:eSciDrvSyncMode_Last
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Subprogram: SciDrv_SetupEB

-- Test Case: SciDrv_SetupEB.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetupEB
TEST.NEW
TEST.NAME:SciDrv_SetupEB.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SetupEB.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetupEB
TEST.NEW
TEST.NAME:SciDrv_SetupEB.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:5
TEST.END

-- Test Case: SciDrv_SetupEB.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetupEB
TEST.NEW
TEST.NAME:SciDrv_SetupEB.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Last
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SetupEB.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetupEB
TEST.NEW
TEST.NAME:SciDrv_SetupEB.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:5
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SetupEB.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetupEB
TEST.NEW
TEST.NAME:SciDrv_SetupEB.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:eSciDrvDirection_Last
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:5
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SetupEB.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetupEB
TEST.NEW
TEST.NAME:SciDrv_SetupEB.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:eSciDrvDirection_Last
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:5
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SetupEB.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetupEB
TEST.NEW
TEST.NAME:SciDrv_SetupEB.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:5
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SetupEB.008
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetupEB
TEST.NEW
TEST.NAME:SciDrv_SetupEB.008
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:5
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SetupEB.009
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SetupEB
TEST.NEW
TEST.NAME:SciDrv_SetupEB.009
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Ok
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:5
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Subprogram: SciDrv_SyncReceive

-- Test Case: SciDrv_SyncReceive.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncReceive
TEST.NEW
TEST.NAME:SciDrv_SyncReceive.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SyncReceive.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncReceive
TEST.NEW
TEST.NAME:SciDrv_SyncReceive.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:5
TEST.END

-- Test Case: SciDrv_SyncReceive.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncReceive
TEST.NEW
TEST.NAME:SciDrv_SyncReceive.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SyncReceive.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncReceive
TEST.NEW
TEST.NAME:SciDrv_SyncReceive.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwSyncReceive
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Last
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SyncReceive.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncReceive
TEST.NEW
TEST.NAME:SciDrv_SyncReceive.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwSyncReceive
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Last
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:eSciDrvSyncMode_Last
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SyncReceive.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncReceive
TEST.NEW
TEST.NAME:SciDrv_SyncReceive.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwSyncReceive
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Last
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Subprogram: SciDrv_SyncTransmit

-- Test Case: SciDrv_SyncTransmit.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncTransmit
TEST.NEW
TEST.NAME:SciDrv_SyncTransmit.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SyncTransmit.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncTransmit
TEST.NEW
TEST.NAME:SciDrv_SyncTransmit.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:5
TEST.END

-- Test Case: SciDrv_SyncTransmit.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncTransmit
TEST.NEW
TEST.NAME:SciDrv_SyncTransmit.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwSyncTransmit
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SyncTransmit.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncTransmit
TEST.NEW
TEST.NAME:SciDrv_SyncTransmit.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwSyncTransmit
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SyncTransmit.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncTransmit
TEST.NEW
TEST.NAME:SciDrv_SyncTransmit.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwSyncTransmit
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:eSciDrvSyncMode_Last
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Test Case: SciDrv_SyncTransmit.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_SyncTransmit
TEST.NEW
TEST.NAME:SciDrv_SyncTransmit.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwSyncTransmit
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.END

-- Subprogram: SciDrv_TxRxISRHandle

-- Test Case: SciDrv_TxRxISRHandle.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:5
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_ReceiveErrorRecovery
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:0xF0
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_ReceiveErrorRecovery
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:0xF0
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_ReceiveErrorRecovery
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:eSciDrvChnResult_Busy
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:0xF0
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.008
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.008
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x50
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.009
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.009
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x0
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.010
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.010
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.011
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.011
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.012
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.012
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:1
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.013
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.013
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:40
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.014
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.014
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.015
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.015
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.016
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.016
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:10
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.017
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.017
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:40
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.018
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.018
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:40
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.019
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.019
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwInterrupt2Disable
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:20
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:40
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:0x4A00000
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:0xF
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.020
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.020
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableTransmitInterrupt
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x2
TEST.ATTRIBUTES:SciDrv.SciDrv_Read_Reg32.pRegBase:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_Read_Reg32.return:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.021
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.021
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0xF
TEST.ATTRIBUTES:SciDrv.SciDrv_ResetModule.pRegBase:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.022
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.022
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableTransmitInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptWriteFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwInterrupt2Enable
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:10
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x2
TEST.ATTRIBUTES:SciDrv.SciDrv_Read_Reg32.pRegBase:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_Read_Reg32.return:INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.023
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.023
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableTransmitInterrupt
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x2
TEST.ATTRIBUTES:SciDrv.SciDrv_Read_Reg32.pRegBase:INPUT_BASE=16
TEST.ATTRIBUTES:SciDrv.SciDrv_Read_Reg32.return:INPUT_BASE=16
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.024
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.024
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:60
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0xFFFFFFFF
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x4
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.025
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.025
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableTransmitInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptWriteFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwInterrupt2Enable
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:10
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x2
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.026
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.026
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableTransmitInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptWriteFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwInterrupt2Enable
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:10
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.027
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.027
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:60
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x6
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:0x2
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.028
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.028
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0xFFFFFFFF
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:12
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.029
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.029
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:60
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:10
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x4
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.030
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.030
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Field32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:0xFFFFFFFF
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:0
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x4
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:1
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.031
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.031
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:60
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:10
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x4
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:1
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.032
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.032
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:10
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:0
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:12
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.033
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.033
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwDisableTransmitInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptWriteFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwInterrupt2Enable
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:Client_PhyTransmitCallback
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:10
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:0
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x2
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.034
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.034
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:60
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x4
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.035
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.035
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:12
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.036
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.036
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:100
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:10
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:12
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.037
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.037
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:12
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: SciDrv_TxRxISRHandle.038
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_TxRxISRHandle
TEST.NEW
TEST.NAME:SciDrv_TxRxISRHandle.038
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwEnableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwDisableReceiveInterrupt
TEST.STUB:SciDrv.SciDrv_HwInterruptReadFifo
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.STUB:SciDrv.SciDrv_HwGetIntrIdentityStatus
TEST.STUB:SciDrv.SciDrv_HwReadLineStatus
TEST.STUB:SciDrv.SciDrv_Read_Reg32
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:0x4A00000
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:60
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:0xFFFFFFFF
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:1
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:1
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:0
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:0x4
TEST.VALUE_USER_CODE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig.pSciDrvConfig[0].pSciDrvChnCfg.pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk
<<SciDrv.<<GLOBAL>>.SciDrvGlobal>>.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk = ( &Client_PhyTransmitCallback );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: SciDrv_WriteIB

-- Test Case: SciDrv_WriteIB.001
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_WriteIB
TEST.NEW
TEST.NAME:SciDrv_WriteIB.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_HwGetSwChnID
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<max>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MAX>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<max>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MAX>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MAX>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<max>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MAX>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MAX>>
TEST.ATTRIBUTES:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase::INPUT_BASE=16
TEST.END

-- Test Case: SciDrv_WriteIB.002
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_WriteIB
TEST.NEW
TEST.NAME:SciDrv_WriteIB.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_WriteIB.003
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_WriteIB
TEST.NEW
TEST.NAME:SciDrv_WriteIB.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciAsyncModeHold[0]:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciSyncModeHold[0]:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MID>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG32_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG32_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG16_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG16_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_REG8_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_REG8_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD32_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD16_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_WR_FIELD8_RAW.value:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD32_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD16_RAW.return:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.addr:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.mask:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.shift:<<MID>>
TEST.VALUE:SciDrv.HW_RD_FIELD8_RAW.return:<<MID>>
TEST.VALUE:SciDrv.UART_masterIsr.arg:VECTORCAST_INT1
TEST.VALUE:SciDrv.SciDrv_UartDmaArmTx.swChannel:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaTxComplete.swChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.swChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DmaRxComplete.bytes:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].SciDrvMaxChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.pConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Init.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_SetupEB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetupEB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_ReadIB.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReadIB.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_EnableChn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ASyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.SciMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetAsyncMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.SciSyncMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_SetSyncMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_GetChnResult.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableChn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.Direction:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Cancel.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_TxRxISRHandle.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_InitChnInfo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelInit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwChannelDeinit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoInit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoDeinit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferInit.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.size:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].read_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].write_index:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.buffer[0].fill_count:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.data:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.size:<<MID>>
TEST.VALUE:SciDrv.SciDrv_RingBufferRead.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableTransmitInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableTransmitInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.pLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptWriteFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableReceiveInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwDisableReceiveInterrupt.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptReadFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.Length:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pBuffer:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSyncReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingReadFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.SciDrvSwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pData:"<<MID>>"
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.pLength[0]:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPollingWriteFifo.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelTransmit.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwCancelReceive.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.SciDrvHwChn:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetSwChnID.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaseAddr:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvInputClkFreq:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvTransmitNotificationCbk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwChnId:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvDataLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvStopBitsLength:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvEnableParity:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvOperMode:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvRxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvTxTrigLvl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ReceiveErrorRecovery.pChnCfg[0].SciDrvHwFlowControl:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ResetModule.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableEnhaceFunc.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwModuleReset.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptEnable.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterruptDisable.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Enable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwInterrupt2Disable.pInterruptFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pLengthFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwLineCharConfig.pParityFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.pModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwOperatingModeSelect.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwBreakControl.pbreakState:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.pRegisterModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnableRegisterConfigMode.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModuleClk:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pBaudRate:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.pModeFlag:<<MID>>
TEST.VALUE:SciDrv.SciDrv_ComputeDivisorValue.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivident:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.pdivisor:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DivideRoundCloset.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.pdivisorValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwWriteDivisorLatch.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_DisableDivisorLatch.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.pFifoConfig:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoConfig.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwSubConfigTCRTLRModeEn.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwFifoRegisterWrite.pFcrValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwTcrTlrBitValRestore.pTcrTlrBitVal:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwEnhanFuncBitValRestore.pEnhanFnBitVal:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwGetIntrIdentityStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwPutChar.pByteTx:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_HwReadLineStatus.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldMask:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pRegFieldShift:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Field32.pFieldValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldMask:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.pRegFieldShift:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Field32.return:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Write_Reg32.pValue:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.pRegBase:<<MID>>
TEST.VALUE:SciDrv.SciDrv_Read_Reg32.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MID>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MID>>
TEST.END

-- Test Case: SciDrv_WriteIB.004
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_WriteIB
TEST.NEW
TEST.NAME:SciDrv_WriteIB.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_WriteIB.005
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_WriteIB
TEST.NEW
TEST.NAME:SciDrv_WriteIB.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:1
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_WriteIB.006
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_WriteIB
TEST.NEW
TEST.NAME:SciDrv_WriteIB.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:eSciDrvDirection_Last
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:1
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_WriteIB.007
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_WriteIB
TEST.NEW
TEST.NAME:SciDrv_WriteIB.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:0
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_WriteIB.008
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_WriteIB
TEST.NEW
TEST.NAME:SciDrv_WriteIB.008
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.STUB:SciDrv.SciDrv_RingBufferWrite
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:eSciDrvDirection_Transmit
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:1
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:0
TEST.VALUE:SciDrv.SciDrv_RingBufferWrite.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END

-- Test Case: SciDrv_WriteIB.009
TEST.UNIT:SciDrv
TEST.SUBPROGRAM:SciDrv_WriteIB
TEST.NEW
TEST.NAME:SciDrv_WriteIB.009
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Scidrv::SciDrv_Detailed_Design::SciDrv_Class_Diagram
Requirement_PE4TI29141-7561
TEST.END_NOTES:
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.State:eSciDrvStatus_Ready
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvGlobal.pSciDrvConfig[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitSizeRemaining:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitCount:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciExtraBytesReceived:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxDataSent:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveTimeout:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciTransmitBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].pSciReceiveBuffer:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTransmitStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciReceiveStatus:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciAsyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciSyncMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciTxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:<<malloc 8>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.data:"<<MIN>>"
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.read_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.write_index:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.SciDrvChnInfo[0].SciRxIB.fill_count:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:SciDrv.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.Direction:eSciDrvDirection_Receive
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer:<<malloc 1>>
TEST.VALUE:SciDrv.SciDrv_WriteIB.pBuffer[0]:1
TEST.VALUE:SciDrv.SciDrv_WriteIB.Length:1
TEST.VALUE:SciDrv.SciDrv_WriteIB.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].SciDrvMaxChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaseAddr:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvInputClkFreq:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvTransmitNotificationCbk:<<min>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].pSciDrvReceiveNotificationCbk:<<value error>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwChnId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvBaudRate:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvDataLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvStopBitsLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvEnableParity:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvOperMode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvRxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvTxTrigLvl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.pSciDrvCfg[0].pSciDrvChnCfg[0].SciDrvHwFlowControl:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Client_PhyTransmitCallback.TransmitResult:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.sw:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.udmaInstId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerTx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.peerRx:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaAttach.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.swChn:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.buf:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.len:<<MIN>>
TEST.VALUE:uut_prototype_stubs.SciDrv_UdmaSubmitTx.return:<<MIN>>
TEST.END
