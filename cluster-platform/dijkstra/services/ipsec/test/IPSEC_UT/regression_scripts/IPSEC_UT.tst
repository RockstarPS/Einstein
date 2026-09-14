-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : IPSEC_UT
-- Unit(s) Under Test: ipsec_service ipsec_start_service
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: ipsec_service

-- Subprogram: DisableStrongSwan_Service

-- Test Case: 01_disable_init
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:DisableStrongSwan_Service
TEST.NEW
TEST.NAME:01_disable_init
TEST.EXPECTED:ipsec_service.DisableStrongSwan_Service.return:1
TEST.END

-- Test Case: 02_disable_positive
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:DisableStrongSwan_Service
TEST.NEW
TEST.NAME:02_disable_positive
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.EXPECTED:ipsec_service.DisableStrongSwan_Service.return:0
TEST.END

-- Test Case: 03_DisableStrongSwan
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:DisableStrongSwan_Service
TEST.NEW
TEST.NAME:03_DisableStrongSwan
TEST.VALUE:uut_prototype_stubs.system.return:0,1
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.EXPECTED:ipsec_service.DisableStrongSwan_Service.return:1
TEST.END

-- Test Case: 04_stop_fail
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:DisableStrongSwan_Service
TEST.NEW
TEST.NAME:04_stop_fail
TEST.VALUE:uut_prototype_stubs.system.return:1
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.EXPECTED:ipsec_service.DisableStrongSwan_Service.return:1
TEST.END

-- Subprogram: ErrorStrongSwan_Service

-- Test Case: 01_error_pos
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:ErrorStrongSwan_Service
TEST.NEW
TEST.NAME:01_error_pos
TEST.EXPECTED:ipsec_service.ErrorStrongSwan_Service.return:0
TEST.END

-- Test Case: 02_error_failure
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:ErrorStrongSwan_Service
TEST.NEW
TEST.NAME:02_error_failure
TEST.VALUE:uut_prototype_stubs.system.return:1
TEST.EXPECTED:ipsec_service.ErrorStrongSwan_Service.return:1
TEST.END

-- Subprogram: IpMaskStrongSwan_Service

-- Test Case: 01_IpMaskStrongSwan_pos
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:IpMaskStrongSwan_Service
TEST.NEW
TEST.NAME:01_IpMaskStrongSwan_pos
TEST.EXPECTED:ipsec_service.IpMaskStrongSwan_Service.return:1
TEST.END

-- Test Case: 02_IpMaskStrongSwan_Service_failure
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:IpMaskStrongSwan_Service
TEST.NEW
TEST.NAME:02_IpMaskStrongSwan_Service_failure
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.third_octet:<<malloc 2>>
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.third_octet:"1"
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.hex_mask:<<malloc 2>>
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.hex_mask:"2"
TEST.EXPECTED:ipsec_service.IpMaskStrongSwan_Service.third_octet:"1"
TEST.EXPECTED:ipsec_service.IpMaskStrongSwan_Service.hex_mask:"2"
TEST.EXPECTED:ipsec_service.IpMaskStrongSwan_Service.return:0
TEST.END

-- Test Case: 03_IpMaskStrongSwan_write
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:IpMaskStrongSwan_Service
TEST.NEW
TEST.NAME:03_IpMaskStrongSwan_write
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.third_octet:<<malloc 2>>
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.third_octet:"1"
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.hex_mask:<<malloc 2>>
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.hex_mask:"2"
TEST.VALUE:uut_prototype_stubs.snprintf.return:-1
TEST.EXPECTED:ipsec_service.IpMaskStrongSwan_Service.return:1
TEST.END

-- Test Case: 04_IpMaskStrongSwan_writefail
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:IpMaskStrongSwan_Service
TEST.NEW
TEST.NAME:04_IpMaskStrongSwan_writefail
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.third_octet:<<malloc 2>>
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.third_octet:"1"
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.hex_mask:<<malloc 2>>
TEST.VALUE:ipsec_service.IpMaskStrongSwan_Service.hex_mask:"2"
TEST.VALUE:uut_prototype_stubs.system.return:1
TEST.EXPECTED:ipsec_service.IpMaskStrongSwan_Service.return:1
TEST.END

-- Subprogram: LockStrongSwan_Service

-- Test Case: 01_lock_access
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:LockStrongSwan_Service
TEST.NEW
TEST.NAME:01_lock_access
TEST.EXPECTED:ipsec_service.LockStrongSwan_Service.return:1
TEST.END

-- Test Case: 02_lock_sys
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:LockStrongSwan_Service
TEST.NEW
TEST.NAME:02_lock_sys
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.EXPECTED:ipsec_service.LockStrongSwan_Service.return:0
TEST.END

-- Test Case: 03_lock_fail
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:LockStrongSwan_Service
TEST.NEW
TEST.NAME:03_lock_fail
TEST.VALUE:uut_prototype_stubs.system.return:1
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.EXPECTED:ipsec_service.LockStrongSwan_Service.return:1
TEST.END

-- Test Case: 04_lock_open
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:LockStrongSwan_Service
TEST.NEW
TEST.NAME:04_lock_open
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.fclose
TEST.VALUE:uut_prototype_stubs.fclose.return:0
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.EXPECTED:ipsec_service.LockStrongSwan_Service.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 05_chattr
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:LockStrongSwan_Service
TEST.NEW
TEST.NAME:05_chattr
TEST.VALUE:uut_prototype_stubs.system.return:0,1
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.EXPECTED:ipsec_service.LockStrongSwan_Service.return:1
TEST.END

-- Subprogram: RestartStrongSwan_Service

-- Test Case: 01_restart
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:RestartStrongSwan_Service
TEST.NEW
TEST.NAME:01_restart
TEST.EXPECTED:ipsec_service.RestartStrongSwan_Service.return:0
TEST.END

-- Test Case: 02_restart_fail
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:RestartStrongSwan_Service
TEST.NEW
TEST.NAME:02_restart_fail
TEST.VALUE:uut_prototype_stubs.system.return:1
TEST.EXPECTED:ipsec_service.RestartStrongSwan_Service.return:1
TEST.END

-- Subprogram: StartStrongSwan_Service

-- Test Case: 01_start
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:StartStrongSwan_Service
TEST.NEW
TEST.NAME:01_start
TEST.VALUE:uut_prototype_stubs.system.return:1
TEST.EXPECTED:ipsec_service.StartStrongSwan_Service.return:1
TEST.END

-- Test Case: 02_start_sys
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:StartStrongSwan_Service
TEST.NEW
TEST.NAME:02_start_sys
TEST.VALUE:uut_prototype_stubs.system.return:0,1
TEST.EXPECTED:ipsec_service.StartStrongSwan_Service.return:1
TEST.END

-- Test Case: 03_start_sysenable
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:StartStrongSwan_Service
TEST.NEW
TEST.NAME:03_start_sysenable
TEST.STUB:ipsec_start_service.VCAST_main
TEST.VALUE:uut_prototype_stubs.system.return:(2)0,1
TEST.EXPECTED:ipsec_service.StartStrongSwan_Service.return:1
TEST.END

-- Test Case: 04_start_sysstart
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:StartStrongSwan_Service
TEST.NEW
TEST.NAME:04_start_sysstart
TEST.VALUE:uut_prototype_stubs.system.return:0
TEST.EXPECTED:ipsec_service.StartStrongSwan_Service.return:0
TEST.END

-- Subprogram: StatusStrongSwan_Service

-- Test Case: 01_status
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:StatusStrongSwan_Service
TEST.NEW
TEST.NAME:01_status
TEST.EXPECTED:ipsec_service.StatusStrongSwan_Service.return:0
TEST.END

-- Test Case: 02_status_Fail
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:StatusStrongSwan_Service
TEST.NEW
TEST.NAME:02_status_Fail
TEST.VALUE:uut_prototype_stubs.system.return:1
TEST.EXPECTED:ipsec_service.StatusStrongSwan_Service.return:1
TEST.END

-- Subprogram: StopStrongSwan_Service

-- Test Case: 01_stop
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:StopStrongSwan_Service
TEST.NEW
TEST.NAME:01_stop
TEST.EXPECTED:ipsec_service.StopStrongSwan_Service.return:1
TEST.END

-- Test Case: 02_stop_sys
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:StopStrongSwan_Service
TEST.NEW
TEST.NAME:02_stop_sys
TEST.VALUE:uut_prototype_stubs.system.return:0
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.EXPECTED:ipsec_service.StopStrongSwan_Service.return:0
TEST.END

-- Test Case: 03_stop_Fail
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:StopStrongSwan_Service
TEST.NEW
TEST.NAME:03_stop_Fail
TEST.VALUE:uut_prototype_stubs.system.return:1
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.EXPECTED:ipsec_service.StopStrongSwan_Service.return:1
TEST.END

-- Subprogram: UnlockStrongSwan_Service

-- Test Case: 01_unlock
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:UnlockStrongSwan_Service
TEST.NEW
TEST.NAME:01_unlock
TEST.EXPECTED:ipsec_service.UnlockStrongSwan_Service.return:0
TEST.END

-- Test Case: 02_unlock_access
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:UnlockStrongSwan_Service
TEST.NEW
TEST.NAME:02_unlock_access
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.EXPECTED:ipsec_service.UnlockStrongSwan_Service.return:1
TEST.END

-- Test Case: 03-unlock_open
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:UnlockStrongSwan_Service
TEST.NEW
TEST.NAME:03-unlock_open
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.fclose
TEST.VALUE:uut_prototype_stubs.fclose.return:0
TEST.EXPECTED:ipsec_service.UnlockStrongSwan_Service.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 06_remove
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:UnlockStrongSwan_Service
TEST.NEW
TEST.NAME:06_remove
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.fclose
TEST.VALUE:uut_prototype_stubs.fclose.return:0
TEST.VALUE:uut_prototype_stubs.remove.return:1
TEST.VALUE:uut_prototype_stubs.system.return:0,1
TEST.EXPECTED:ipsec_service.UnlockStrongSwan_Service.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 07_chattr
TEST.UNIT:ipsec_service
TEST.SUBPROGRAM:UnlockStrongSwan_Service
TEST.NEW
TEST.NAME:07_chattr
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.fclose
TEST.VALUE:uut_prototype_stubs.fclose.return:0
TEST.VALUE:uut_prototype_stubs.remove.return:1
TEST.VALUE:uut_prototype_stubs.system.return:1
TEST.EXPECTED:ipsec_service.UnlockStrongSwan_Service.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Unit: ipsec_start_service

-- Subprogram: VCAST_main

-- Test Case: 01-main
TEST.UNIT:ipsec_start_service
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:01-main
TEST.STUB:ipsec_service.StartStrongSwan_Service
TEST.EXPECTED:ipsec_start_service.VCAST_main.return:0
TEST.END

-- Test Case: 02_service
TEST.UNIT:ipsec_start_service
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:02_service
TEST.STUB:ipsec_service.StartStrongSwan_Service
TEST.VALUE:ipsec_service.StartStrongSwan_Service.return:1
TEST.EXPECTED:ipsec_start_service.VCAST_main.return:1
TEST.END

-- Test Case: 03_open
TEST.UNIT:ipsec_start_service
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:03_open
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:ipsec_start_service.VCAST_main.return:-1
TEST.END
