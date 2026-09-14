-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : TCPIP_VCAST_HT
-- Unit(s) Under Test: TcpIp
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: TcpIp

-- Subprogram: LwIP_StatusCallback

-- Test Case: LwIP_StatusCallback.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIP_StatusCallback
TEST.NEW
TEST.NAME:LwIP_StatusCallback.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.test_netif.flags:0xFF
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus.TcpIp_CtrlStatus[0].TcpIpNetif
<<TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus>>[0].TcpIpNetif = ( &test_netif );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.LwIP_StatusCallback.pNetIf
<<TcpIp.LwIP_StatusCallback.pNetIf>> = ( &test_netif );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: LwIP_StatusCallback.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIP_StatusCallback
TEST.NEW
TEST.NAME:LwIP_StatusCallback.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.test_netif.flags:0xFF
TEST.VALUE:TcpIp.LwIP_StatusCallback.pNetIf:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus.TcpIp_CtrlStatus[0].TcpIpNetif
<<TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus>>[0].TcpIpNetif = ( &test_netif );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: LwIP_StatusCallback.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIP_StatusCallback
TEST.NEW
TEST.NAME:LwIP_StatusCallback.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.test_netif.flags:0x0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus.TcpIp_CtrlStatus[0].TcpIpNetif
<<TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus>>[0].TcpIpNetif = ( &test_netif );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.LwIP_StatusCallback.pNetIf
<<TcpIp.LwIP_StatusCallback.pNetIf>> = ( &test_netif );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: LwIp_EthernetifInit

-- Test Case: LwIp_EthernetifInit.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIp_EthernetifInit
TEST.NEW
TEST.NAME:LwIp_EthernetifInit.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.LwIp_EthernetifInit.pNetIf:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: LwIp_Output

-- Test Case: LwIp_Output.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIp_Output
TEST.NEW
TEST.NAME:LwIp_Output.001
TEST.VALUE:TcpIp.LwIp_Output.pNetIf:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_Output.pBuffer:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_Output.pBuffer[0].payload:VECTORCAST_BUFFER
TEST.VALUE:TcpIp.LwIp_Output.pBuffer[0].len:10
TEST.VALUE:uut_prototype_stubs.EthIf_ProvideTxBuffer.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:TcpIp.LwIp_Output.return:ERR_MEM
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: LwIp_Output.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIp_Output
TEST.NEW
TEST.NAME:LwIp_Output.002
TEST.VALUE:TcpIp.LwIp_Output.pNetIf:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_Output.pBuffer:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_Output.pBuffer[0].next:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_Output.pBuffer[0].len:15
TEST.VALUE:TcpIp.LwIp_Output.pBuffer[0].if_idx:1
TEST.VALUE:uut_prototype_stubs.EthIf_ProvideTxBuffer.return:BUFREQ_OK
TEST.VALUE:uut_prototype_stubs.EthIf_Transmit.return:E_OK
TEST.EXPECTED:TcpIp.LwIp_Output.return:ERR_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.EthIf_ProvideTxBuffer.BufPtr.BufPtr[0].BufPtr
<<uut_prototype_stubs.EthIf_ProvideTxBuffer.BufPtr>>[0] = ( &test_buf100 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.LwIp_Output.pBuffer.pBuffer[0].next.next[0].payload
<<TcpIp.LwIp_Output.pBuffer>>[0].next[0].payload = ( &test_buf100[50] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.LwIp_Output.pBuffer.pBuffer[0].payload
<<TcpIp.LwIp_Output.pBuffer>>[0].payload = ( &test_buf100 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: LwIp_Output.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIp_Output
TEST.NEW
TEST.NAME:LwIp_Output.003
TEST.VALUE:TcpIp.LwIp_Output.pNetIf:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_Output.pBuffer:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_Output.pBuffer[0].next:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_Output.pBuffer[0].len:15
TEST.VALUE:TcpIp.LwIp_Output.pBuffer[0].if_idx:1
TEST.VALUE:uut_prototype_stubs.EthIf_ProvideTxBuffer.return:BUFREQ_OK
TEST.VALUE:uut_prototype_stubs.EthIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:TcpIp.LwIp_Output.return:ERR_IF
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.EthIf_ProvideTxBuffer.BufPtr.BufPtr[0].BufPtr
<<uut_prototype_stubs.EthIf_ProvideTxBuffer.BufPtr>>[0] = ( &test_buf100 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.LwIp_Output.pBuffer.pBuffer[0].next.next[0].payload
<<TcpIp.LwIp_Output.pBuffer>>[0].next[0].payload = ( &test_buf100[50] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.LwIp_Output.pBuffer.pBuffer[0].payload
<<TcpIp.LwIp_Output.pBuffer>>[0].payload = ( &test_buf100 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: LwIp_RxIndication

-- Test Case: LwIp_RxIndication.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIp_RxIndication
TEST.NEW
TEST.NAME:LwIp_RxIndication.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.LwIp_RxIndication.CtrlIdx:0
TEST.VALUE:TcpIp.LwIp_RxIndication.LenByte:10
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<null>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: LwIp_RxIndication.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIp_RxIndication
TEST.NEW
TEST.NAME:LwIp_RxIndication.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif[0].input:netif_input
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.LwIp_RxIndication.CtrlIdx:0
TEST.VALUE:TcpIp.LwIp_RxIndication.IsBroadcast:FALSE
TEST.VALUE:TcpIp.LwIp_RxIndication.PhysAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_RxIndication.DataPtr:<<malloc 10>>
TEST.VALUE:TcpIp.LwIp_RxIndication.LenByte:10
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.netif_input.return:E_OK
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.pbuf_alloc.return.return[0].next.next[0].payload
<<uut_prototype_stubs.pbuf_alloc.return>>[0].next[0].payload = ( &test_buf[0] );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.pbuf_alloc.return.return[0].payload
<<uut_prototype_stubs.pbuf_alloc.return>>[0].payload = ( &test_buf[0] );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: LwIp_RxIndication.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIp_RxIndication
TEST.NEW
TEST.NAME:LwIp_RxIndication.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif[0].input:netif_input
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.LwIp_RxIndication.CtrlIdx:0
TEST.VALUE:TcpIp.LwIp_RxIndication.IsBroadcast:TRUE
TEST.VALUE:TcpIp.LwIp_RxIndication.PhysAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_RxIndication.DataPtr:<<malloc 10>>
TEST.VALUE:TcpIp.LwIp_RxIndication.LenByte:1536
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].tot_len:8
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].len:8
TEST.VALUE:uut_prototype_stubs.netif_input.return:E_OK
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.pbuf_alloc.return.return[0].next.next[0].payload
<<uut_prototype_stubs.pbuf_alloc.return>>[0].next[0].payload = ( &test_buf[0] );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.pbuf_alloc.return.return[0].payload
<<uut_prototype_stubs.pbuf_alloc.return>>[0].payload = ( &test_buf[0] );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: LwIp_RxIndication.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIp_RxIndication
TEST.NEW
TEST.NAME:LwIp_RxIndication.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif[0].input:netif_input
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.LwIp_RxIndication.CtrlIdx:0
TEST.VALUE:TcpIp.LwIp_RxIndication.IsBroadcast:TRUE
TEST.VALUE:TcpIp.LwIp_RxIndication.PhysAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_RxIndication.DataPtr:<<malloc 10>>
TEST.VALUE:TcpIp.LwIp_RxIndication.LenByte:1536
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].tot_len:8
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].len:8
TEST.VALUE:uut_prototype_stubs.netif_input.return:-1
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.pbuf_alloc.return.return[0].next.next[0].payload
<<uut_prototype_stubs.pbuf_alloc.return>>[0].next[0].payload = ( &test_buf[0] );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.pbuf_alloc.return.return[0].payload
<<uut_prototype_stubs.pbuf_alloc.return>>[0].payload = ( &test_buf[0] );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: LwIp_RxIndication.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:LwIp_RxIndication
TEST.NEW
TEST.NAME:LwIp_RxIndication.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<null>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.LwIp_RxIndication.CtrlIdx:0
TEST.VALUE:TcpIp.LwIp_RxIndication.IsBroadcast:TRUE
TEST.VALUE:TcpIp.LwIp_RxIndication.PhysAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.LwIp_RxIndication.DataPtr:<<malloc 10>>
TEST.VALUE:TcpIp.LwIp_RxIndication.LenByte:1536
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].tot_len:8
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].len:8
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].ref:1
TEST.VALUE:uut_prototype_stubs.netif_input.return:-1
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.pbuf_alloc.return.return[0].next.next[0].payload
<<uut_prototype_stubs.pbuf_alloc.return>>[0].next[0].payload = ( &test_buf[0] );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.pbuf_alloc.return.return[0].payload
<<uut_prototype_stubs.pbuf_alloc.return>>[0].payload = ( &test_buf[0] );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_AutomaticIpAddrAssignment

-- Test Case: TcpIp_AutomaticIpAddrAssignment.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_AutomaticIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_AutomaticIpAddrAssignment.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_AutomaticIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_AutomaticIpAddrAssignment.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_AutomaticIpAddrAssignment.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_AutomaticIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_AutomaticIpAddrAssignment.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0xEEEEEEEE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.TcpIp_AutomaticIpAddrAssignment.LocalAddrId:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_AutomaticIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_AutomaticIpAddrAssignment.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_AutomaticIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_AutomaticIpAddrAssignment.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0xEEEEEEEE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:FALSE
TEST.VALUE:TcpIp.TcpIp_AutomaticIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_AutomaticIpAddrAssignment.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_AutomaticIpAddrAssignment.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_AutomaticIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_AutomaticIpAddrAssignment.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_DHCP
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0xEEEEEEEE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:FALSE
TEST.VALUE:TcpIp.TcpIp_AutomaticIpAddrAssignment.LocalAddrId:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_AutomaticIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_AutomaticIpAddrAssignment.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_AutomaticIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_AutomaticIpAddrAssignment.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0xEEEEEEEE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:FALSE
TEST.VALUE:TcpIp.TcpIp_AutomaticIpAddrAssignment.LocalAddrId:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_AutomaticIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_AutomaticIpAddrAssignment.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_AutomaticIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_AutomaticIpAddrAssignment.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0xEEEEEEEE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:FALSE
TEST.VALUE:TcpIp.TcpIp_AutomaticIpAddrAssignment.LocalAddrId:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_AutomaticIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_AutomaticIpAddrAssignment.007
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_AutomaticIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_AutomaticIpAddrAssignment.007
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_DHCP
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0xEEEEEEEE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:FALSE
TEST.VALUE:TcpIp.TcpIp_AutomaticIpAddrAssignment.LocalAddrId:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dhcp_start.return:-1
TEST.EXPECTED:TcpIp.TcpIp_AutomaticIpAddrAssignment.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_AutomaticIpAddrAssignment.008
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_AutomaticIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_AutomaticIpAddrAssignment.008
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0x12345678
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.TcpIp_AutomaticIpAddrAssignment.LocalAddrId:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_AutomaticIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_AutomaticIpAddrAssignment.009
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_AutomaticIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_AutomaticIpAddrAssignment.009
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0x12345678
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.TcpIp_AutomaticIpAddrAssignment.LocalAddrId:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_AutomaticIpAddrAssignment.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_Bind

-- Test Case: TcpIp_Bind.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Bind
TEST.NEW
TEST.NAME:TcpIp_Bind.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_Bind.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_BIND_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_Bind.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Bind
TEST.NEW
TEST.NAME:TcpIp_Bind.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_Bind.SocketId:TCPIP_NUM_OF_SOCKETS
TEST.EXPECTED:TcpIp.TcpIp_Bind.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_BIND_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_Bind.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Bind
TEST.NEW
TEST.NAME:TcpIp_Bind.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_Bind.SocketId:0
TEST.VALUE:TcpIp.TcpIp_Bind.PortPtr:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_Bind.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_BIND_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_Bind.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Bind
TEST.NEW
TEST.NAME:TcpIp_Bind.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_Bind.SocketId:0
TEST.VALUE:TcpIp.TcpIp_Bind.LocalAddrId:1
TEST.VALUE:TcpIp.TcpIp_Bind.PortPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_Bind.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_BIND_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_ADDRNOTAVAIL
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_Bind.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Bind
TEST.NEW
TEST.NAME:TcpIp_Bind.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].ProtocolIsTcp:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_Bind.SocketId:0
TEST.VALUE:TcpIp.TcpIp_Bind.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_Bind.PortPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.tcp_bind.return:-1
TEST.EXPECTED:TcpIp.TcpIp_Bind.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_BIND_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_NOTCONN
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_Bind.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Bind
TEST.NEW
TEST.NAME:TcpIp_Bind.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].ProtocolIsTcp:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_Bind.SocketId:0
TEST.VALUE:TcpIp.TcpIp_Bind.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_Bind.PortPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.tcp_bind.return:ERR_OK
TEST.EXPECTED:TcpIp.TcpIp_Bind.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_Bind.007
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Bind
TEST.NEW
TEST.NAME:TcpIp_Bind.007
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].ProtocolIsTcp:FALSE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_Bind.SocketId:0
TEST.VALUE:TcpIp.TcpIp_Bind.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_Bind.PortPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.udp_bind.return:ERR_OK
TEST.EXPECTED:TcpIp.TcpIp_Bind.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_Bind.008
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Bind
TEST.NEW
TEST.NAME:TcpIp_Bind.008
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].ProtocolIsTcp:FALSE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_Bind.SocketId:0
TEST.VALUE:TcpIp.TcpIp_Bind.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_Bind.PortPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.udp_bind.return:-1
TEST.EXPECTED:TcpIp.TcpIp_Bind.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_BIND_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_NOTCONN
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_ChangeParameter

-- Test Case: TcpIp_ChangeParameter.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_ChangeParameter
TEST.NEW
TEST.NAME:TcpIp_ChangeParameter.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_ChangeParameter.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_CHANGEPARAMETER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_ChangeParameter.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_ChangeParameter
TEST.NEW
TEST.NAME:TcpIp_ChangeParameter.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_ChangeParameter.SocketId:TCPIP_NUM_OF_SOCKETS
TEST.EXPECTED:TcpIp.TcpIp_ChangeParameter.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_CHANGEPARAMETER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.END

-- Test Case: TcpIp_ChangeParameter.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_ChangeParameter
TEST.NEW
TEST.NAME:TcpIp_ChangeParameter.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_ChangeParameter.SocketId:0
TEST.VALUE:TcpIp.TcpIp_ChangeParameter.ParameterValue:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_ChangeParameter.ParameterValue:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_ChangeParameter.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_CHANGEPARAMETER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.END

-- Test Case: TcpIp_ChangeParameter.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_ChangeParameter
TEST.NEW
TEST.NAME:TcpIp_ChangeParameter.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_ChangeParameter.SocketId:0
TEST.VALUE:TcpIp.TcpIp_ChangeParameter.ParameterValue:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_ChangeParameter.return:E_OK
TEST.END

-- Subprogram: TcpIp_Close

-- Test Case: TcpIp_Close.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Close
TEST.NEW
TEST.NAME:TcpIp_Close.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.VALUE:TcpIp.TcpIp_Close.SocketId:TCPIP_NUM_OF_SOCKETS
TEST.EXPECTED:TcpIp.TcpIp_Close.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_CLOSE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_Close.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Close
TEST.NEW
TEST.NAME:TcpIp_Close.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_Close.SocketId:TCPIP_NUM_OF_SOCKETS
TEST.EXPECTED:TcpIp.TcpIp_Close.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_CLOSE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.END

-- Test Case: TcpIp_Close.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Close
TEST.NEW
TEST.NAME:TcpIp_Close.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].ProtocolIsTcp:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_INT1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerTcpIpEventFunc:Up_TcpIpEventFunc
TEST.VALUE:TcpIp.TcpIp_Close.SocketId:0
TEST.EXPECTED:TcpIp.TcpIp_Close.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_Close.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Close
TEST.NEW
TEST.NAME:TcpIp_Close.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].ProtocolIsTcp:FALSE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_INT1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerTcpIpEventFunc:Up_TcpIpEventFunc
TEST.VALUE:TcpIp.TcpIp_Close.SocketId:0
TEST.EXPECTED:TcpIp.TcpIp_Close.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_Close.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Close
TEST.NEW
TEST.NAME:TcpIp_Close.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].ProtocolIsTcp:FALSE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_INT1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerTcpIpEventFunc:<<null>>
TEST.VALUE:TcpIp.TcpIp_Close.SocketId:0
TEST.EXPECTED:TcpIp.TcpIp_Close.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_CtrlStateHandling

-- Test Case: TcpIp_CtrlStateHandling.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_CtrlStateHandling
TEST.NEW
TEST.NAME:TcpIp_CtrlStateHandling.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_STARTUP
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_CtrlStateHandling.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_CtrlStateHandling
TEST.NEW
TEST.NAME:TcpIp_CtrlStateHandling.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_CtrlStateHandling.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_CtrlStateHandling
TEST.NEW
TEST.NAME:TcpIp_CtrlStateHandling.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONHOLD
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_CtrlStateHandling.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_CtrlStateHandling
TEST.NEW
TEST.NAME:TcpIp_CtrlStateHandling.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_STARTUP
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_STARTUP
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_CtrlStateHandling.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_CtrlStateHandling
TEST.NEW
TEST.NAME:TcpIp_CtrlStateHandling.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_SHUTDOWN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_CtrlStateHandling.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_CtrlStateHandling
TEST.NEW
TEST.NAME:TcpIp_CtrlStateHandling.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:9
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:9
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_DhcpReadOption

-- Test Case: TcpIp_DhcpReadOption.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_DhcpReadOption
TEST.NEW
TEST.NAME:TcpIp_DhcpReadOption.001
TEST.EXPECTED:TcpIp.TcpIp_DhcpReadOption.return:E_OK
TEST.END

-- Subprogram: TcpIp_DhcpV6ReadOption

-- Test Case: TcpIp_DhcpV6ReadOption.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_DhcpV6ReadOption
TEST.NEW
TEST.NAME:TcpIp_DhcpV6ReadOption.001
TEST.EXPECTED:TcpIp.TcpIp_DhcpV6ReadOption.return:E_OK
TEST.END

-- Subprogram: TcpIp_DhcpV6WriteOption

-- Test Case: TcpIp_DhcpV6WriteOption.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_DhcpV6WriteOption
TEST.NEW
TEST.NAME:TcpIp_DhcpV6WriteOption.001
TEST.EXPECTED:TcpIp.TcpIp_DhcpV6WriteOption.return:E_OK
TEST.END

-- Subprogram: TcpIp_DhcpWriteOption

-- Test Case: TcpIp_DhcpWriteOption.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_DhcpWriteOption
TEST.NEW
TEST.NAME:TcpIp_DhcpWriteOption.001
TEST.EXPECTED:TcpIp.TcpIp_DhcpWriteOption.return:E_OK
TEST.END

-- Subprogram: TcpIp_DisableAllIpAddrAssignments

-- Test Case: TcpIp_DisableAllIpAddrAssignments.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_DisableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_DisableAllIpAddrAssignments.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_UNICAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_AUTOMATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_DisableAllIpAddrAssignments.CtrlIdx:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_ADDRNOTAVAIL
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_DisableAllIpAddrAssignments.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_DisableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_DisableAllIpAddrAssignments.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_MULTICAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_AUTOMATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_DisableAllIpAddrAssignments.CtrlIdx:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_ADDRNOTAVAIL
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_DisableAllIpAddrAssignments.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_DisableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_DisableAllIpAddrAssignments.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_UNICAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_AUTOMATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_DisableAllIpAddrAssignments.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_DisableAllIpAddrAssignments.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_DisableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_DisableAllIpAddrAssignments.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_MULTICAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_AUTOMATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_DisableAllIpAddrAssignments.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_DisableAllIpAddrAssignments.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_DisableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_DisableAllIpAddrAssignments.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_ANYCAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_DisableAllIpAddrAssignments.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_DisableAllIpAddrAssignments.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_DisableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_DisableAllIpAddrAssignments.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_ANYCAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_DisableAllIpAddrAssignments.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_EnableAllIpAddrAssignments

-- Test Case: TcpIp_EnableAllIpAddrAssignments.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_EnableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_EnableAllIpAddrAssignments.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_UNICAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_AUTOMATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_EnableAllIpAddrAssignments.CtrlIdx:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_ADDRNOTAVAIL
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_EnableAllIpAddrAssignments.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_EnableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_EnableAllIpAddrAssignments.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_UNICAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_AUTOMATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_EnableAllIpAddrAssignments.CtrlIdx:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_EnableAllIpAddrAssignments.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_EnableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_EnableAllIpAddrAssignments.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_MULTICAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_AUTOMATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_EnableAllIpAddrAssignments.CtrlIdx:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_ADDRNOTAVAIL
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_EnableAllIpAddrAssignments.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_EnableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_EnableAllIpAddrAssignments.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_MULTICAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_AUTOMATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_EnableAllIpAddrAssignments.CtrlIdx:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_EnableAllIpAddrAssignments.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_EnableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_EnableAllIpAddrAssignments.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_ANYCAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_EnableAllIpAddrAssignments.CtrlIdx:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_EnableAllIpAddrAssignments.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_EnableAllIpAddrAssignments
TEST.NEW
TEST.NAME:TcpIp_EnableAllIpAddrAssignments.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].AddressType:TCPIP_ANYCAST
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_EnableAllIpAddrAssignments.CtrlIdx:0
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_EnterOfflineState

-- Test Case: TcpIp_EnterOfflineState.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_EnterOfflineState
TEST.NEW
TEST.NAME:TcpIp_EnterOfflineState.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_EnterOfflineState.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.END

-- Test Case: TcpIp_EnterOfflineState.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_EnterOfflineState
TEST.NEW
TEST.NAME:TcpIp_EnterOfflineState.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:-1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 2>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_EnterOfflineState.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.END

-- Test Case: TcpIp_EnterOfflineState.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_EnterOfflineState
TEST.NEW
TEST.NAME:TcpIp_EnterOfflineState.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:-1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].TcpIpAddrId:1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr[0].CtrlConfigId:1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_EnterOfflineState.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.END

-- Test Case: TcpIp_EnterOfflineState.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_EnterOfflineState
TEST.NEW
TEST.NAME:TcpIp_EnterOfflineState.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:-1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<null>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_EnterOfflineState.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.END

-- Subprogram: TcpIp_GetAndResetMeasurementData

-- Test Case: TcpIp_GetAndResetMeasurementData.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetAndResetMeasurementData
TEST.NEW
TEST.NAME:TcpIp_GetAndResetMeasurementData.001
TEST.EXPECTED:TcpIp.TcpIp_GetAndResetMeasurementData.return:E_OK
TEST.END

-- Subprogram: TcpIp_GetArpCacheEntries

-- Test Case: TcpIp_GetArpCacheEntries.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetArpCacheEntries
TEST.NEW
TEST.NAME:TcpIp_GetArpCacheEntries.001
TEST.EXPECTED:TcpIp.TcpIp_GetArpCacheEntries.return:E_OK
TEST.END

-- Subprogram: TcpIp_GetCtrlIdx

-- Test Case: TcpIp_GetCtrlIdx.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetCtrlIdx
TEST.NEW
TEST.NAME:TcpIp_GetCtrlIdx.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_GetCtrlIdx.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETCTRLIDX_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_GetCtrlIdx.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetCtrlIdx
TEST.NEW
TEST.NAME:TcpIp_GetCtrlIdx.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_GetCtrlIdx.CtrlIdxPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_GetCtrlIdx.CtrlIdxPtr:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_GetCtrlIdx.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETCTRLIDX_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.END

-- Test Case: TcpIp_GetCtrlIdx.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetCtrlIdx
TEST.NEW
TEST.NAME:TcpIp_GetCtrlIdx.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetCtrlIdx.LocalAddrId:1
TEST.VALUE:TcpIp.TcpIp_GetCtrlIdx.CtrlIdxPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetCtrlIdx.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETCTRLIDX_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_ADDRNOTAVAIL
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetCtrlIdx.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetCtrlIdx
TEST.NEW
TEST.NAME:TcpIp_GetCtrlIdx.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetCtrlIdx.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_GetCtrlIdx.CtrlIdxPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetCtrlIdx.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_GetFirstFreeSocket

-- Test Case: TcpIp_GetFirstFreeSocket.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetFirstFreeSocket
TEST.NEW
TEST.NAME:TcpIp_GetFirstFreeSocket.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_STR1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].State:TCPIP_SOCKET_INIT
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pvPcbAddr:VECTORCAST_BUFFER
TEST.VALUE:TcpIp.TcpIp_GetFirstFreeSocket.pSocketId:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.EXPECTED:TcpIp.TcpIp_GetFirstFreeSocket.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_GetIpAddr

-- Test Case: TcpIp_GetIpAddr.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetIpAddr
TEST.NEW
TEST.NAME:TcpIp_GetIpAddr.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_GetIpAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETIPADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetIpAddr.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetIpAddr
TEST.NEW
TEST.NAME:TcpIp_GetIpAddr.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.IpAddrPtr:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_GetIpAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETIPADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetIpAddr.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetIpAddr
TEST.NEW
TEST.NAME:TcpIp_GetIpAddr.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.NetmaskPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.NetmaskPtr:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_GetIpAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETIPADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetIpAddr.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetIpAddr
TEST.NEW
TEST.NAME:TcpIp_GetIpAddr.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.NetmaskPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.DefaultRouterPtr:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_GetIpAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETIPADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetIpAddr.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetIpAddr
TEST.NEW
TEST.NAME:TcpIp_GetIpAddr.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.LocalAddrId:1
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.NetmaskPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.DefaultRouterPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetIpAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETIPADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_ADDRNOTAVAIL
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetIpAddr.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetIpAddr
TEST.NEW
TEST.NAME:TcpIp_GetIpAddr.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].DomainType:TCPIP_AF_INET
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.IpAddrPtr[0].Domain:TCPIP_AF_INET6
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.NetmaskPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.DefaultRouterPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.DefaultRouterPtr[0].Domain:TCPIP_AF_INET6
TEST.EXPECTED:TcpIp.TcpIp_GetIpAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETIPADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetIpAddr.007
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetIpAddr
TEST.NEW
TEST.NAME:TcpIp_GetIpAddr.007
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].DomainType:TCPIP_AF_INET
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.IpAddrPtr[0].Domain:TCPIP_AF_INET
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.NetmaskPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.DefaultRouterPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.DefaultRouterPtr[0].Domain:TCPIP_AF_INET
TEST.EXPECTED:TcpIp.TcpIp_GetIpAddr.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetIpAddr.008
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetIpAddr
TEST.NEW
TEST.NAME:TcpIp_GetIpAddr.008
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].DomainType:TCPIP_AF_INET
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.IpAddrPtr[0].Domain:TCPIP_AF_INET
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.NetmaskPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.DefaultRouterPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetIpAddr.DefaultRouterPtr[0].Domain:TCPIP_AF_INET6
TEST.EXPECTED:TcpIp.TcpIp_GetIpAddr.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_GetNdpCacheEntries

-- Test Case: TcpIp_GetNdpCacheEntries.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetNdpCacheEntries
TEST.NEW
TEST.NAME:TcpIp_GetNdpCacheEntries.001
TEST.EXPECTED:TcpIp.TcpIp_GetNdpCacheEntries.return:E_OK
TEST.END

-- Subprogram: TcpIp_GetPhysAddr

-- Test Case: TcpIp_GetPhysAddr.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetPhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetPhysAddr.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_GetPhysAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETPHYSADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_GetPhysAddr.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetPhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetPhysAddr.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_GetPhysAddr.PhysAddrPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_GetPhysAddr.PhysAddrPtr:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_GetPhysAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETPHYSADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.END

-- Test Case: TcpIp_GetPhysAddr.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetPhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetPhysAddr.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.TcpIp_GetPhysAddr.LocalAddrId:1
TEST.VALUE:TcpIp.TcpIp_GetPhysAddr.PhysAddrPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetPhysAddr.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETPHYSADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_ADDRNOTAVAIL
TEST.END

-- Test Case: TcpIp_GetPhysAddr.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetPhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetPhysAddr.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.TcpIp_GetPhysAddr.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_GetPhysAddr.PhysAddrPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetPhysAddr.return:E_OK
TEST.END

-- Subprogram: TcpIp_GetRemotePhysAddr

-- Test Case: TcpIp_GetRemotePhysAddr.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetRemotePhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetRemotePhysAddr.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_GetRemotePhysAddr.return:TCPIP_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETREMOTEPHYSADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_GetRemotePhysAddr.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetRemotePhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetRemotePhysAddr.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.IpAddrPtr:<<null>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.PhysAddrPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetRemotePhysAddr.return:TCPIP_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETREMOTEPHYSADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.END

-- Test Case: TcpIp_GetRemotePhysAddr.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetRemotePhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetRemotePhysAddr.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.PhysAddrPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.PhysAddrPtr:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_GetRemotePhysAddr.return:TCPIP_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETREMOTEPHYSADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.END

-- Test Case: TcpIp_GetRemotePhysAddr.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetRemotePhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetRemotePhysAddr.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.PhysAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.initRes:TRUE
TEST.VALUE:uut_prototype_stubs.etharp_find_addr.return:-1
TEST.VALUE:uut_prototype_stubs.etharp_query.return:-1
TEST.EXPECTED:TcpIp.TcpIp_GetRemotePhysAddr.return:TCPIP_E_PHYS_ADDR_MISS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETREMOTEPHYSADDR_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.END

-- Test Case: TcpIp_GetRemotePhysAddr.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetRemotePhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetRemotePhysAddr.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.PhysAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.initRes:TRUE
TEST.VALUE:uut_prototype_stubs.etharp_find_addr.return:-1
TEST.VALUE:uut_prototype_stubs.etharp_query.return:ERR_OK
TEST.EXPECTED:TcpIp.TcpIp_GetRemotePhysAddr.return:TCPIP_E_PHYS_ADDR_MISS
TEST.END

-- Test Case: TcpIp_GetRemotePhysAddr.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetRemotePhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetRemotePhysAddr.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.PhysAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.initRes:FALSE
TEST.VALUE:uut_prototype_stubs.etharp_find_addr.return:-1
TEST.VALUE:uut_prototype_stubs.etharp_query.return:ERR_OK
TEST.EXPECTED:TcpIp.TcpIp_GetRemotePhysAddr.return:TCPIP_E_PHYS_ADDR_MISS
TEST.END

-- Test Case: TcpIp_GetRemotePhysAddr.007
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetRemotePhysAddr
TEST.NEW
TEST.NAME:TcpIp_GetRemotePhysAddr.007
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.IpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.PhysAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetRemotePhysAddr.initRes:FALSE
TEST.VALUE:uut_prototype_stubs.etharp_find_addr.return:ERR_OK
TEST.EXPECTED:TcpIp.TcpIp_GetRemotePhysAddr.return:TCPIP_E_OK
TEST.END

-- Subprogram: TcpIp_GetSocket

-- Test Case: TcpIp_GetSocket.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetSocket
TEST.NEW
TEST.NAME:TcpIp_GetSocket.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_GetSocket.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETSOCKET_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_GetSocket.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetSocket
TEST.NEW
TEST.NAME:TcpIp_GetSocket.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketIdPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketIdPtr:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_GetSocket.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETSOCKET_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.END

-- Test Case: TcpIp_GetSocket.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetSocket
TEST.NEW
TEST.NAME:TcpIp_GetSocket.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_GetSocket.Domain:TCPIP_AF_INET6
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketIdPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetSocket.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETSOCKET_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_AFNOSUPPORT
TEST.END

-- Test Case: TcpIp_GetSocket.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetSocket
TEST.NEW
TEST.NAME:TcpIp_GetSocket.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_GetSocket.Domain:TCPIP_AF_INET
TEST.VALUE:TcpIp.TcpIp_GetSocket.Protocol:3
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketIdPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetSocket.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETSOCKET_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_NOPROTOOPT
TEST.END

-- Test Case: TcpIp_GetSocket.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetSocket
TEST.NEW
TEST.NAME:TcpIp_GetSocket.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketOwnerId:0
TEST.VALUE:TcpIp.TcpIp_GetSocket.Domain:TCPIP_AF_INET
TEST.VALUE:TcpIp.TcpIp_GetSocket.Protocol:TCPIP_IPPROTO_TCP
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketIdPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetSocket.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetSocket.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetSocket
TEST.NEW
TEST.NAME:TcpIp_GetSocket.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketOwnerId:0
TEST.VALUE:TcpIp.TcpIp_GetSocket.Domain:TCPIP_AF_INET
TEST.VALUE:TcpIp.TcpIp_GetSocket.Protocol:TCPIP_IPPROTO_TCP
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketIdPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.tcp_new.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetSocket.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetSocket.007
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetSocket
TEST.NEW
TEST.NAME:TcpIp_GetSocket.007
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketOwnerId:0
TEST.VALUE:TcpIp.TcpIp_GetSocket.Domain:TCPIP_AF_INET
TEST.VALUE:TcpIp.TcpIp_GetSocket.Protocol:TCPIP_IPPROTO_UDP
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketIdPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.udp_new.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetSocket.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_GetSocket.008
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetSocket
TEST.NEW
TEST.NAME:TcpIp_GetSocket.008
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_READY
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].Handle:1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].State:TCPIP_SOCKET_UDP_READY
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketOwnerId:0
TEST.VALUE:TcpIp.TcpIp_GetSocket.Domain:TCPIP_AF_INET
TEST.VALUE:TcpIp.TcpIp_GetSocket.Protocol:TCPIP_IPPROTO_UDP
TEST.VALUE:TcpIp.TcpIp_GetSocket.SocketIdPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetSocket.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_GetVersionInfo

-- Test Case: TcpIp_GetVersionInfo.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetVersionInfo
TEST.NEW
TEST.NAME:TcpIp_GetVersionInfo.001
TEST.VALUE:TcpIp.TcpIp_GetVersionInfo.versioninfo:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_GETVERSIONINFO_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.END

-- Test Case: TcpIp_GetVersionInfo.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_GetVersionInfo
TEST.NEW
TEST.NAME:TcpIp_GetVersionInfo.002
TEST.VALUE:TcpIp.TcpIp_GetVersionInfo.versioninfo:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_GetVersionInfo.versioninfo[0].vendorID:TCPIP_VENDOR_ID
TEST.EXPECTED:TcpIp.TcpIp_GetVersionInfo.versioninfo[0].moduleID:TCPIP_MODULE_ID
TEST.EXPECTED:TcpIp.TcpIp_GetVersionInfo.versioninfo[0].sw_major_version:TCPIP_SW_MAJOR_VERSION
TEST.EXPECTED:TcpIp.TcpIp_GetVersionInfo.versioninfo[0].sw_minor_version:TCPIP_SW_MINOR_VERSION
TEST.EXPECTED:TcpIp.TcpIp_GetVersionInfo.versioninfo[0].sw_patch_version:TCPIP_SW_PATCH_VERSION
TEST.END

-- Subprogram: TcpIp_HandleStateOffline

-- Test Case: TcpIp_HandleStateOffline.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateOffline
TEST.NEW
TEST.NAME:TcpIp_HandleStateOffline.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_HandleStateOffline.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_STARTUP
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_HandleStateOffline.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateOffline
TEST.NEW
TEST.NAME:TcpIp_HandleStateOffline.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONHOLD
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_HandleStateOffline.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_HandleStateOffline.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateOffline
TEST.NEW
TEST.NAME:TcpIp_HandleStateOffline.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_STARTUP
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_HandleStateOffline.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_STARTUP
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_HandleStateOnhold

-- Test Case: TcpIp_HandleStateOnhold.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateOnhold
TEST.NEW
TEST.NAME:TcpIp_HandleStateOnhold.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_HandleStateOnhold.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_HandleStateOnhold.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateOnhold
TEST.NEW
TEST.NAME:TcpIp_HandleStateOnhold.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONHOLD
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_HandleStateOnhold.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONHOLD
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_HandleStateOnline

-- Test Case: TcpIp_HandleStateOnline.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateOnline
TEST.NEW
TEST.NAME:TcpIp_HandleStateOnline.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_BUFFER
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pvPcbAddr:VECTORCAST_BUFFER
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_HandleStateOnline.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_HandleStateOnline.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateOnline
TEST.NEW
TEST.NAME:TcpIp_HandleStateOnline.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONHOLD
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_BUFFER
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pvPcbAddr:VECTORCAST_BUFFER
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_HandleStateOnline.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONHOLD
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_HandleStateStartup

-- Test Case: TcpIp_HandleStateStartup.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateStartup
TEST.NEW
TEST.NAME:TcpIp_HandleStateStartup.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_HandleStateStartup.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_HandleStateStartup.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateStartup
TEST.NEW
TEST.NAME:TcpIp_HandleStateStartup.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_HandleStateStartup.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_HandleStateStartup.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateStartup
TEST.NEW
TEST.NAME:TcpIp_HandleStateStartup.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].LinkUp:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_HandleStateStartup.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_HandleStateStartup.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_HandleStateStartup
TEST.NEW
TEST.NAME:TcpIp_HandleStateStartup.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_STARTUP
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[1].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.TcpIp_HandleStateStartup.CtrlIdx:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_STARTUP
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_IcmpTransmit

-- Test Case: TcpIp_IcmpTransmit.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_IcmpTransmit
TEST.NEW
TEST.NAME:TcpIp_IcmpTransmit.001
TEST.EXPECTED:TcpIp.TcpIp_IcmpTransmit.return:E_OK
TEST.END

-- Subprogram: TcpIp_IcmpV6Transmit

-- Test Case: TcpIp_IcmpV6Transmit.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_IcmpV6Transmit
TEST.NEW
TEST.NAME:TcpIp_IcmpV6Transmit.001
TEST.EXPECTED:TcpIp.TcpIp_IcmpV6Transmit.return:E_OK
TEST.END

-- Subprogram: TcpIp_Init

-- Test Case: TcpIp_Init.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Init
TEST.NEW
TEST.NAME:TcpIp_Init.001
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].LinkUp:FALSE
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_OFFLINE
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_OFFLINE
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<null>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<null>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].ProtocolIsTcp:FALSE
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].ErrCnt:0
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:-1
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_INIT
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<null>>
TEST.END

-- Subprogram: TcpIp_Ip4NetmaskToIpAddr

-- Test Case: TcpIp_Ip4NetmaskToIpAddr.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Ip4NetmaskToIpAddr
TEST.NEW
TEST.NAME:TcpIp_Ip4NetmaskToIpAddr.001
TEST.VALUE:TcpIp.TcpIp_Ip4NetmaskToIpAddr.NetmaskAddr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_Ip4NetmaskToIpAddr.Netmask:8
TEST.EXPECTED:TcpIp.TcpIp_Ip4NetmaskToIpAddr.NetmaskAddr[0].addr:0xFF
TEST.END

-- Test Case: TcpIp_Ip4NetmaskToIpAddr.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Ip4NetmaskToIpAddr
TEST.NEW
TEST.NAME:TcpIp_Ip4NetmaskToIpAddr.002
TEST.VALUE:TcpIp.TcpIp_Ip4NetmaskToIpAddr.NetmaskAddr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_Ip4NetmaskToIpAddr.Netmask:16
TEST.EXPECTED:TcpIp.TcpIp_Ip4NetmaskToIpAddr.NetmaskAddr[0].addr:0xFFFF
TEST.END

-- Test Case: TcpIp_Ip4NetmaskToIpAddr.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_Ip4NetmaskToIpAddr
TEST.NEW
TEST.NAME:TcpIp_Ip4NetmaskToIpAddr.003
TEST.VALUE:TcpIp.TcpIp_Ip4NetmaskToIpAddr.NetmaskAddr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_Ip4NetmaskToIpAddr.Netmask:24
TEST.EXPECTED:TcpIp.TcpIp_Ip4NetmaskToIpAddr.NetmaskAddr[0].addr:0xFFFFFF
TEST.END

-- Subprogram: TcpIp_MainFunction

-- Test Case: TcpIp_MainFunction.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_MainFunction
TEST.NEW
TEST.NAME:TcpIp_MainFunction.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_MainFunction.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_MainFunction
TEST.NEW
TEST.NAME:TcpIp_MainFunction.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.END

-- Subprogram: TcpIp_NotifyLocalIpAddrAssignmentChg

-- Test Case: TcpIp_NotifyLocalIpAddrAssignmentChg.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_NotifyLocalIpAddrAssignmentChg
TEST.NEW
TEST.NAME:TcpIp_NotifyLocalIpAddrAssignmentChg.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerLocalIpAddrAssignmentChgFunc:Up_LocalIpAddrAssignmentFunc
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[1].pSocketOwnerLocalIpAddrAssignmentChgFunc:<<null>>
TEST.VALUE:TcpIp.TcpIp_NotifyLocalIpAddrAssignmentChg.CtrlIdx:0
TEST.VALUE:TcpIp.TcpIp_NotifyLocalIpAddrAssignmentChg.IpAddrState:TCPIP_IPADDR_STATE_ASSIGNED
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_NotifyLocalIpAddrAssignmentChg.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_NotifyLocalIpAddrAssignmentChg
TEST.NEW
TEST.NAME:TcpIp_NotifyLocalIpAddrAssignmentChg.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 2>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerLocalIpAddrAssignmentChgFunc:Up_LocalIpAddrAssignmentFunc
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[1].pSocketOwnerLocalIpAddrAssignmentChgFunc:<<null>>
TEST.VALUE:TcpIp.TcpIp_NotifyLocalIpAddrAssignmentChg.CtrlIdx:1
TEST.VALUE:TcpIp.TcpIp_NotifyLocalIpAddrAssignmentChg.IpAddrState:TCPIP_IPADDR_STATE_ASSIGNED
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_RelIpAddrAssignment

-- Test Case: TcpIp_RelIpAddrAssignment.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RelIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RelIpAddrAssignment.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RelIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_RelIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RelIpAddrAssignment.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RelIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RelIpAddrAssignment.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0x7F000001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_DHCP
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0xEEEEEEEE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RelIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_RelIpAddrAssignment.return:E_OK
TEST.ATTRIBUTES:TcpIp.TcpIp_RequestIpAddrAssignment.LocalIpAddrPtr[0].SockAddrInetType.Addr[0]::INPUT_BASE=16
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RelIpAddrAssignment.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RelIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RelIpAddrAssignment.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0x7F000001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_DHCP
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0x62346512
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RelIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_RelIpAddrAssignment.return:E_OK
TEST.ATTRIBUTES:TcpIp.TcpIp_RequestIpAddrAssignment.LocalIpAddrPtr[0].SockAddrInetType.Addr[0]::INPUT_BASE=16
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RelIpAddrAssignment.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RelIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RelIpAddrAssignment.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0x7F000001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0x62346512
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RelIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_RelIpAddrAssignment.return:E_OK
TEST.ATTRIBUTES:TcpIp.TcpIp_RequestIpAddrAssignment.LocalIpAddrPtr[0].SockAddrInetType.Addr[0]::INPUT_BASE=16
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RelIpAddrAssignment.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RelIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RelIpAddrAssignment.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0x7F000001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0x62346512
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RelIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_RelIpAddrAssignment.return:E_OK
TEST.ATTRIBUTES:TcpIp.TcpIp_RequestIpAddrAssignment.LocalIpAddrPtr[0].SockAddrInetType.Addr[0]::INPUT_BASE=16
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_ReleaseIpAddrAssignment

-- Test Case: TcpIp_ReleaseIpAddrAssignment.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_ReleaseIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_ReleaseIpAddrAssignment.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_ReleaseIpAddrAssignment.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_RELEASEIPADDRASSIGNMENT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_ReleaseIpAddrAssignment.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_ReleaseIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_ReleaseIpAddrAssignment.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:1
TEST.VALUE:TcpIp.TcpIp_ReleaseIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_ReleaseIpAddrAssignment.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_RELEASEIPADDRASSIGNMENT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_ADDRNOTAVAIL
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_ReleaseIpAddrAssignment.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_ReleaseIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_ReleaseIpAddrAssignment.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_AUTOMATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_ReleaseIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_ReleaseIpAddrAssignment.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_ReleaseIpAddrAssignment.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_ReleaseIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_ReleaseIpAddrAssignment.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_ReleaseIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_ReleaseIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_RequestComMode

-- Test Case: TcpIp_RequestComMode.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestComMode
TEST.NEW
TEST.NAME:TcpIp_RequestComMode.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_REQUESTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestComMode.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestComMode
TEST.NEW
TEST.NAME:TcpIp_RequestComMode.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_RequestComMode.CtrlIdx:TCPIP_NUM_OF_CONTROLLERS
TEST.EXPECTED:TcpIp.TcpIp_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_REQUESTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestComMode.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestComMode
TEST.NEW
TEST.NAME:TcpIp_RequestComMode.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_RequestComMode.CtrlIdx:0
TEST.VALUE:TcpIp.TcpIp_RequestComMode.State:TCPIP_STATE_SHUTDOWN,TCPIP_STATE_STARTUP,8
TEST.EXPECTED:TcpIp.TcpIp_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_REQUESTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestComMode.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestComMode
TEST.NEW
TEST.NAME:TcpIp_RequestComMode.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_RequestComMode.CtrlIdx:0
TEST.VALUE:TcpIp.TcpIp_RequestComMode.State:TCPIP_STATE_ONLINE
TEST.EXPECTED:TcpIp.TcpIp_RequestComMode.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestComMode.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestComMode
TEST.NEW
TEST.NAME:TcpIp_RequestComMode.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONHOLD
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_RequestComMode.CtrlIdx:0
TEST.VALUE:TcpIp.TcpIp_RequestComMode.State:TCPIP_STATE_ONLINE,TCPIP_STATE_OFFLINE
TEST.EXPECTED:TcpIp.TcpIp_RequestComMode.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestComMode.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestComMode
TEST.NEW
TEST.NAME:TcpIp_RequestComMode.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_RequestComMode.CtrlIdx:0
TEST.VALUE:TcpIp.TcpIp_RequestComMode.State:TCPIP_STATE_ONHOLD
TEST.EXPECTED:TcpIp.TcpIp_RequestComMode.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestComMode.007
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestComMode
TEST.NEW
TEST.NAME:TcpIp_RequestComMode.007
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_RequestComMode.CtrlIdx:0
TEST.VALUE:TcpIp.TcpIp_RequestComMode.State:TCPIP_STATE_ONHOLD
TEST.EXPECTED:TcpIp.TcpIp_RequestComMode.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_RequestIpAddrAssignment

-- Test Case: TcpIp_RequestIpAddrAssignment.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_REQUESTIPADDRASSIGNMENT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestIpAddrAssignment.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalAddrId:1
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_REQUESTIPADDRASSIGNMENT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_ADDRNOTAVAIL
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestIpAddrAssignment.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_AUTOMATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestIpAddrAssignment.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:FALSE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestIpAddrAssignment.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalAddrId:0
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestIpAddrAssignment.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].AssignmentMethod:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.Type:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestIpAddrAssignment.007
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.007
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.Type:TCPIP_IPADDR_ASSIGNMENT_DHCP
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dhcp_start.return:ERR_OK
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestIpAddrAssignment.008
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.008
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.Type:TCPIP_IPADDR_ASSIGNMENT_DHCP
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dhcp_start.return:-1
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestIpAddrAssignment.009
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.009
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.Type:TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP,TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dhcp_start.return:-1
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestIpAddrAssignment.010
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.010
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.Type:TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dhcp_start.return:-1
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_RequestIpAddrAssignment.011
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RequestIpAddrAssignment
TEST.NEW
TEST.NAME:TcpIp_RequestIpAddrAssignment.011
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].TcpIpAddrId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig[0].TcpIpAssignmentTrigger:TCPIP_MANUAL
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].TcpIpStaticIpAddress:0xEEEEEEEE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig[0].IsValid:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalAddrId:0
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.Type:TCPIP_IPADDR_ASSIGNMENT_STATIC
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalIpAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RequestIpAddrAssignment.LocalIpAddrPtr[0].SockAddrInetType.Addr[0]:0xEEEEEEEE
TEST.VALUE:uut_prototype_stubs.netif_add.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dhcp_start.return:-1
TEST.EXPECTED:TcpIp.TcpIp_RequestIpAddrAssignment.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_ResetIpAssignment

-- Test Case: TcpIp_ResetIpAssignment.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_ResetIpAssignment
TEST.NEW
TEST.NAME:TcpIp_ResetIpAssignment.001
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_RxIndication

-- Test Case: TcpIp_RxIndication.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RxIndication
TEST.NEW
TEST.NAME:TcpIp_RxIndication.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_RxIndication.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RxIndication
TEST.NEW
TEST.NAME:TcpIp_RxIndication.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_RxIndication.PhysAddrPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_RxIndication.PhysAddrPtr:<<null>>
TEST.VALUE:TcpIp.TcpIp_RxIndication.DataPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.END

-- Test Case: TcpIp_RxIndication.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RxIndication
TEST.NEW
TEST.NAME:TcpIp_RxIndication.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_RxIndication.PhysAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RxIndication.DataPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_RxIndication.DataPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.END

-- Test Case: TcpIp_RxIndication.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_RxIndication
TEST.NEW
TEST.NAME:TcpIp_RxIndication.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_RxIndication.PhysAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_RxIndication.DataPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.END

-- Subprogram: TcpIp_SocketStateHandling

-- Test Case: TcpIp_SocketStateHandling.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_SocketStateHandling
TEST.NEW
TEST.NAME:TcpIp_SocketStateHandling.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_LISTENING
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_LISTENING
TEST.END

-- Test Case: TcpIp_SocketStateHandling.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_SocketStateHandling
TEST.NEW
TEST.NAME:TcpIp_SocketStateHandling.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:-1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_LISTENING
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_LISTENING
TEST.END

-- Test Case: TcpIp_SocketStateHandling.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_SocketStateHandling
TEST.NEW
TEST.NAME:TcpIp_SocketStateHandling.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:-1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECTING
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECTING
TEST.END

-- Test Case: TcpIp_SocketStateHandling.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_SocketStateHandling
TEST.NEW
TEST.NAME:TcpIp_SocketStateHandling.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:-1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_READY
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_READY
TEST.END

-- Test Case: TcpIp_SocketStateHandling.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_SocketStateHandling
TEST.NEW
TEST.NAME:TcpIp_SocketStateHandling.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_READY
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_READY
TEST.END

-- Test Case: TcpIp_SocketStateHandling.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_SocketStateHandling
TEST.NEW
TEST.NAME:TcpIp_SocketStateHandling.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0,-1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_UDP_READY
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_UDP_READY
TEST.END

-- Subprogram: TcpIp_TcpConnect

-- Test Case: TcpIp_TcpConnect.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpConnect
TEST.NEW
TEST.NAME:TcpIp_TcpConnect.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_TcpConnect.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPCONNECT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_TcpConnect.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpConnect
TEST.NEW
TEST.NAME:TcpIp_TcpConnect.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_TcpConnect.SocketId:TCPIP_NUM_OF_SOCKETS
TEST.EXPECTED:TcpIp.TcpIp_TcpConnect.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPCONNECT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpConnect.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpConnect
TEST.NEW
TEST.NAME:TcpIp_TcpConnect.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_TcpConnect.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_TcpConnect.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPCONNECT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpConnect.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpConnect
TEST.NEW
TEST.NAME:TcpIp_TcpConnect.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_TcpConnect.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr[0].Domain:TCPIP_AF_INET6
TEST.EXPECTED:TcpIp.TcpIp_TcpConnect.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpConnect.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpConnect
TEST.NEW
TEST.NAME:TcpIp_TcpConnect.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpConnect.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr[0].Domain:TCPIP_AF_INET
TEST.VALUE:uut_prototype_stubs.tcp_connect.return:ERR_OK
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECTING
TEST.EXPECTED:TcpIp.TcpIp_TcpConnect.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpConnect.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpConnect
TEST.NEW
TEST.NAME:TcpIp_TcpConnect.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_BIND
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpConnect.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr[0].Domain:TCPIP_AF_INET
TEST.VALUE:uut_prototype_stubs.tcp_connect.return:ERR_OK
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECTING
TEST.EXPECTED:TcpIp.TcpIp_TcpConnect.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpConnect.007
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpConnect
TEST.NEW
TEST.NAME:TcpIp_TcpConnect.007
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_BIND
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpConnect.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr[0].Domain:TCPIP_AF_INET
TEST.VALUE:uut_prototype_stubs.tcp_connect.return:-1
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_BIND
TEST.EXPECTED:TcpIp.TcpIp_TcpConnect.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPCONNECT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_NOTCONN
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpConnect.008
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpConnect
TEST.NEW
TEST.NAME:TcpIp_TcpConnect.008
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_LISTENING
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpConnect.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpConnect.RemoteAddrPtr[0].Domain:TCPIP_AF_INET
TEST.VALUE:uut_prototype_stubs.tcp_connect.return:-1
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_LISTENING
TEST.EXPECTED:TcpIp.TcpIp_TcpConnect.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_TcpListen

-- Test Case: TcpIp_TcpListen.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpListen
TEST.NEW
TEST.NAME:TcpIp_TcpListen.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_TcpListen.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPLISTEN_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpListen.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpListen
TEST.NEW
TEST.NAME:TcpIp_TcpListen.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_TcpListen.SocketId:TCPIP_NUM_OF_SOCKETS
TEST.EXPECTED:TcpIp.TcpIp_TcpListen.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPLISTEN_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpListen.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpListen
TEST.NEW
TEST.NAME:TcpIp_TcpListen.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_BIND
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_TcpListen.SocketId:0
TEST.EXPECTED:TcpIp.TcpIp_TcpListen.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpListen.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpListen
TEST.NEW
TEST.NAME:TcpIp_TcpListen.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_TcpListen.SocketId:0
TEST.VALUE:uut_prototype_stubs.tcp_listen_with_backlog.return:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_TcpListen.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpListen.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpListen
TEST.NEW
TEST.NAME:TcpIp_TcpListen.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_TcpListen.SocketId:0
TEST.EXPECTED:TcpIp.TcpIp_TcpListen.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_TcpReceived

-- Test Case: TcpIp_TcpReceived.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpReceived
TEST.NEW
TEST.NAME:TcpIp_TcpReceived.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_TcpReceived.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPRECEIVED_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpReceived.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpReceived
TEST.NEW
TEST.NAME:TcpIp_TcpReceived.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_TcpReceived.SocketId:TCPIP_NUM_OF_SOCKETS
TEST.EXPECTED:TcpIp.TcpIp_TcpReceived.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPRECEIVED_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpReceived.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpReceived
TEST.NEW
TEST.NAME:TcpIp_TcpReceived.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_TcpReceived.SocketId:0
TEST.EXPECTED:TcpIp.TcpIp_TcpReceived.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_TcpTransmit

-- Test Case: TcpIp_TcpTransmit.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_TcpTransmit.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:TCPIP_NUM_OF_SOCKETS
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.END

-- Test Case: TcpIp_TcpTransmit.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:-1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_TCPTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_NOTCONN
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpTransmit.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpTransmit.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.AvailableLength:21
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus.TcpIp_SocketStatus[0].pvPcbAddr
struct tcp_pcb temp_tcp_pcb;
temp_tcp_pcb.snd_buf = 20;
<<TcpIp.<<GLOBAL>>.TcpIp_SocketStatus>>[0].pvPcbAddr = ( &temp_tcp_pcb );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpTransmit.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc1
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.AvailableLength:21
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus.TcpIp_SocketStatus[0].pvPcbAddr
struct tcp_pcb temp_tcp_pcb;
temp_tcp_pcb.snd_buf = 20;
<<TcpIp.<<GLOBAL>>.TcpIp_SocketStatus>>[0].pvPcbAddr = ( &temp_tcp_pcb );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpTransmit.007
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.007
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc2
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.AvailableLength:21
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus.TcpIp_SocketStatus[0].pvPcbAddr
struct tcp_pcb temp_tcp_pcb;
temp_tcp_pcb.snd_buf = 20;
<<TcpIp.<<GLOBAL>>.TcpIp_SocketStatus>>[0].pvPcbAddr = ( &temp_tcp_pcb );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpTransmit.008
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.008
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc2
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.AvailableLength:10
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus.TcpIp_SocketStatus[0].pvPcbAddr
struct tcp_pcb temp_tcp_pcb;
temp_tcp_pcb.snd_buf = 20;
<<TcpIp.<<GLOBAL>>.TcpIp_SocketStatus>>[0].pvPcbAddr = ( &temp_tcp_pcb );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpTransmit.009
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.009
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc2
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.DataPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.AvailableLength:10
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus.TcpIp_SocketStatus[0].pvPcbAddr
struct tcp_pcb temp_tcp_pcb;
temp_tcp_pcb.snd_buf = 20;
<<TcpIp.<<GLOBAL>>.TcpIp_SocketStatus>>[0].pvPcbAddr = ( &temp_tcp_pcb );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpTransmit.010
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.010
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc2
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.DataPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.AvailableLength:10
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.tcp_write.return:-1
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus.TcpIp_SocketStatus[0].pvPcbAddr
struct tcp_pcb temp_tcp_pcb;
temp_tcp_pcb.snd_buf = 20;
<<TcpIp.<<GLOBAL>>.TcpIp_SocketStatus>>[0].pvPcbAddr = ( &temp_tcp_pcb );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpTransmit.011
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.011
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc2
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.DataPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.AvailableLength:10
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.tcp_write.return:-1
TEST.VALUE:uut_prototype_stubs.tcp_output.return:-1
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus.TcpIp_SocketStatus[0].pvPcbAddr
struct tcp_pcb temp_tcp_pcb;
temp_tcp_pcb.snd_buf = 20;
<<TcpIp.<<GLOBAL>>.TcpIp_SocketStatus>>[0].pvPcbAddr = ( &temp_tcp_pcb );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpTransmit.012
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.012
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc2
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.DataPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.AvailableLength:10
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.tcp_write.return:-1
TEST.VALUE:uut_prototype_stubs.tcp_output.return:-1
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus.TcpIp_SocketStatus[0].pvPcbAddr
struct tcp_pcb temp_tcp_pcb;
temp_tcp_pcb.snd_buf = 0;
<<TcpIp.<<GLOBAL>>.TcpIp_SocketStatus>>[0].pvPcbAddr = ( &temp_tcp_pcb );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_TcpTransmit.013
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_TcpTransmit
TEST.NEW
TEST.NAME:TcpIp_TcpTransmit.013
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECT_LISTEN
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc2
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.DataPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_TcpTransmit.AvailableLength:10
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].ref:1
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].ref:1
TEST.VALUE:uut_prototype_stubs.tcp_write.return:-1
TEST.VALUE:uut_prototype_stubs.tcp_output.return:-1
TEST.EXPECTED:TcpIp.TcpIp_TcpTransmit.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus.TcpIp_SocketStatus[0].pvPcbAddr
struct tcp_pcb temp_tcp_pcb;
temp_tcp_pcb.snd_buf = 0;
<<TcpIp.<<GLOBAL>>.TcpIp_SocketStatus>>[0].pvPcbAddr = ( &temp_tcp_pcb );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: TcpIp_UdpTransmit

-- Test Case: TcpIp_UdpTransmit.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:FALSE
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_UDPTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_UNINIT
TEST.END

-- Test Case: TcpIp_UdpTransmit.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:TCPIP_NUM_OF_SOCKETS
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_UDPTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_INV_ARG
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.003
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.003
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:-1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_UDPTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_PARAM_POINTER
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.004
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.004
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:-1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_UDPTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_NOTCONN
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.005
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.005
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECTING
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.006
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.006
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_TCP_CONNECTING
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<malloc 1>>
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.007
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.007
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_UDP_READY
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_INT1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<null>>
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:TCPIP_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:TCPIP_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:TCPIP_UDPTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:TCPIP_E_NOBUFS
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.008
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.008
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_UDP_READY
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_INT1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.DataPtr:<<malloc 15>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.TotalLength:4
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.udp_sendto.return:ERR_OK
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.009
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.009
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_UDP_READY
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_INT1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.DataPtr:<<malloc 15>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.TotalLength:4
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.udp_sendto.return:-1
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.010
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.010
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_UDP_READY
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_INT1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.DataPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.DataPtr:<<null>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.TotalLength:4
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.udp_sendto.return:-1
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.011
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.011
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_UDP_READY
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_INT1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc1
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.DataPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.DataPtr:<<null>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.TotalLength:4
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].tot_len:2
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].len:2
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].len:2
TEST.VALUE:uut_prototype_stubs.udp_sendto.return:-1
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.012
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.012
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_UDP_READY
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_INT1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc2
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.DataPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.DataPtr:<<null>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.TotalLength:50
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].tot_len:2
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].len:2
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].len:2
TEST.VALUE:uut_prototype_stubs.udp_sendto.return:-1
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TcpIp_UdpTransmit.013
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:TcpIp_UdpTransmit
TEST.NEW
TEST.NAME:TcpIp_UdpTransmit.013
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_OFFLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].pLocalUnicastAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].TcpIpNetif:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].Handle:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].State:TCPIP_SOCKET_UDP_READY
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].CtrlConfigId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pvPcbAddr:VECTORCAST_INT1
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_InitStatus:TRUE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pCtrlConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pLocalAddrConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerCopyTxDataFunc:Up_CopyTxDataFunc2
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.SocketId:0
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.DataPtr:<<malloc 9>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.DataPtr:<<null>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.RemoteAddrPtr:<<malloc 1>>
TEST.VALUE:TcpIp.TcpIp_UdpTransmit.TotalLength:50
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].tot_len:2
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].next[0].len:2
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].payload:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.pbuf_alloc.return[0].len:2
TEST.VALUE:uut_prototype_stubs.udp_sendto.return:-1
TEST.EXPECTED:TcpIp.TcpIp_UdpTransmit.return:E_NOT_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: ethernetif_init

-- Test Case: ethernetif_init.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:ethernetif_init
TEST.NEW
TEST.NAME:ethernetif_init.001
TEST.VALUE:TcpIp.ethernetif_init.pNetIf:<<null>>
TEST.EXPECTED:TcpIp.ethernetif_init.return:ERR_ARG
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ethernetif_init.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:ethernetif_init
TEST.NEW
TEST.NAME:ethernetif_init.002
TEST.VALUE:TcpIp.ethernetif_init.pNetIf:<<malloc 1>>
TEST.EXPECTED:TcpIp.ethernetif_init.return:ERR_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: tcp_accept_cb_fn

-- Test Case: tcp_accept_cb_fn.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:tcp_accept_cb_fn
TEST.NEW
TEST.NAME:tcp_accept_cb_fn.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerTcpAcceptedFunc:Up_TcpAcceptedFunc
TEST.VALUE:TcpIp.tcp_accept_cb_fn.pcb:<<malloc 1>>
TEST.EXPECTED:TcpIp.tcp_accept_cb_fn.return:ERR_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.tcp_accept_cb_fn.arg
<<TcpIp.tcp_accept_cb_fn.arg>> = ( &TcpIp_SocketStatus[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: tcp_accept_cb_fn.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:tcp_accept_cb_fn
TEST.NEW
TEST.NAME:tcp_accept_cb_fn.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerTcpAcceptedFunc:<<null>>
TEST.VALUE:TcpIp.tcp_accept_cb_fn.pcb:<<malloc 1>>
TEST.EXPECTED:TcpIp.tcp_accept_cb_fn.return:ERR_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.tcp_accept_cb_fn.arg
<<TcpIp.tcp_accept_cb_fn.arg>> = ( &TcpIp_SocketStatus[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: tcp_connect_cb_fn

-- Test Case: tcp_connect_cb_fn.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:tcp_connect_cb_fn
TEST.NEW
TEST.NAME:tcp_connect_cb_fn.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerTcpConnectedFunc:Up_TcpConnectedFunc
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.EXPECTED:TcpIp.tcp_connect_cb_fn.return:ERR_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.tcp_connect_cb_fn.arg
<<TcpIp.tcp_connect_cb_fn.arg>> = ( &TcpIp_SocketStatus[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: tcp_connect_cb_fn.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:tcp_connect_cb_fn
TEST.NEW
TEST.NAME:tcp_connect_cb_fn.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerTcpConnectedFunc:<<null>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.EXPECTED:TcpIp.tcp_connect_cb_fn.return:ERR_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.tcp_connect_cb_fn.arg
<<TcpIp.tcp_connect_cb_fn.arg>> = ( &TcpIp_SocketStatus[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: tcp_recv_cb_fn

-- Test Case: tcp_recv_cb_fn.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:tcp_recv_cb_fn
TEST.NEW
TEST.NAME:tcp_recv_cb_fn.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerRxIndicationFunc:Up_RxIndicationUpFunc
TEST.VALUE:TcpIp.tcp_recv_cb_fn.pcb:<<malloc 1>>
TEST.VALUE:TcpIp.tcp_recv_cb_fn.p:<<malloc 1>>
TEST.EXPECTED:TcpIp.tcp_recv_cb_fn.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.tcp_recv_cb_fn.arg
<<TcpIp.tcp_recv_cb_fn.arg>> = ( &TcpIp_SocketStatus[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: tcp_recv_cb_fn.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:tcp_recv_cb_fn
TEST.NEW
TEST.NAME:tcp_recv_cb_fn.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerRxIndicationFunc:<<null>>
TEST.VALUE:TcpIp.tcp_recv_cb_fn.pcb:<<malloc 1>>
TEST.VALUE:TcpIp.tcp_recv_cb_fn.p:<<malloc 1>>
TEST.EXPECTED:TcpIp.tcp_recv_cb_fn.return:E_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.tcp_recv_cb_fn.arg
<<TcpIp.tcp_recv_cb_fn.arg>> = ( &TcpIp_SocketStatus[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: tcp_sent_cb_fn

-- Test Case: tcp_sent_cb_fn.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:tcp_sent_cb_fn
TEST.NEW
TEST.NAME:tcp_sent_cb_fn.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerTxConfirmationFunc:Up_TxConfirmationFunc
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.EXPECTED:TcpIp.tcp_sent_cb_fn.return:ERR_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.tcp_sent_cb_fn.arg
<<TcpIp.tcp_sent_cb_fn.arg>> = ( &TcpIp_SocketStatus[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: tcp_sent_cb_fn.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:tcp_sent_cb_fn
TEST.NEW
TEST.NAME:tcp_sent_cb_fn.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerTxConfirmationFunc:<<null>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].CtrlState:TCPIP_STATE_ONLINE
TEST.EXPECTED:TcpIp.tcp_sent_cb_fn.return:ERR_OK
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.tcp_sent_cb_fn.arg
<<TcpIp.tcp_sent_cb_fn.arg>> = ( &TcpIp_SocketStatus[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: udp_recv_cb_fn

-- Test Case: udp_recv_cb_fn.001
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:udp_recv_cb_fn
TEST.NEW
TEST.NAME:udp_recv_cb_fn.001
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerRxIndicationFunc:Up_RxIndicationUpFunc
TEST.VALUE:TcpIp.udp_recv_cb_fn.pcb:<<malloc 1>>
TEST.VALUE:TcpIp.udp_recv_cb_fn.p:<<malloc 1>>
TEST.VALUE:TcpIp.udp_recv_cb_fn.addr:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.udp_recv_cb_fn.arg
<<TcpIp.udp_recv_cb_fn.arg>> = ( &TcpIp_SocketStatus[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: udp_recv_cb_fn.002
TEST.UNIT:TcpIp
TEST.SUBPROGRAM:udp_recv_cb_fn
TEST.NEW
TEST.NAME:udp_recv_cb_fn.002
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONLINE
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].OwnerId:0
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pAddrAssignmentConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_SocketStatus[0].pLocalAddr[0].pStaticIpAddressConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig:<<malloc 1>>
TEST.VALUE:TcpIp.<<GLOBAL>>.TcpIp_TcpIpConfig.pSocketOwnerConfig[0].pSocketOwnerRxIndicationFunc:<<null>>
TEST.VALUE:TcpIp.udp_recv_cb_fn.pcb:<<malloc 1>>
TEST.VALUE:TcpIp.udp_recv_cb_fn.p:<<malloc 1>>
TEST.VALUE:TcpIp.udp_recv_cb_fn.addr:<<malloc 1>>
TEST.EXPECTED:TcpIp.<<GLOBAL>>.TcpIp_CtrlStatus[0].ReqCtrlState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:TcpIp.<<GLOBAL>>.pTcpIpConfig
<<TcpIp.<<GLOBAL>>.pTcpIpConfig>> = ( &TcpIp_TcpIpConfig );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:TcpIp.udp_recv_cb_fn.arg
<<TcpIp.udp_recv_cb_fn.arg>> = ( &TcpIp_SocketStatus[0] );
TEST.END_VALUE_USER_CODE:
TEST.END
