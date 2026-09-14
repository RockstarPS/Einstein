-- VectorCAST 6.4s (05/01/17)
-- Test Case Script
-- 
-- Environment    : CAPTURE_VIDEO_WINDOW
-- Unit(s) Under Test: hmi_gfx_mgr02_capture_video
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: hmi_gfx_mgr02_capture_video

-- Subprogram: hmi_gfx_mgr02_capture_to_win_memory_allocation

-- Test Case: hmi_gfx_mgr02_capture_to_win_memory_allocation.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_win_memory_allocation
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_win_memory_allocation.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.ringBufferVirt:VECTORCAST_BUFFER
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_ringBufferSize:100
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_win_memory_allocation.p_modeline_param:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_win_memory_allocation.p_video_def.coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_win_memory_allocation.p_video_def.coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_win_memory_allocation.p_video_def.dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_win_memory_allocation.p_video_def.dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapAssignCapToWinBuffer.return:MML_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_win_memory_allocation.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_win_memory_allocation
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_win_memory_allocation.002
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.ringBufferVirt:VECTORCAST_BUFFER
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_ringBufferSize:100
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_win_memory_allocation.p_modeline_param:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_win_memory_allocation.p_video_def.coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_win_memory_allocation.p_video_def.coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_win_memory_allocation.p_video_def.dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_win_memory_allocation.p_video_def.dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapAssignCapToWinBuffer.return:MML_ERR
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_to_window_init

-- Test Case: hmi_gfx_mgr02_capture_to_window_init.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_window_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_window_init.001
TEST.STUB:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_open_capture_unit
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].pixelClock:27.0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horDisplayPeriod:858
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horPulseStart:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horPulseEnd:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horTotal:858
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertDisplayPeriod:525
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertPulseStart:3
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertPulseEnd:2
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertTotal:2
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horTotalMin:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horTotalMax:858
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertTotalMin:520
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertTotalMax:525
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].DCKDelay:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].DCKInvertEnable:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].syncPolarity:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapAssignCapToWinBuffer.return:MML_OK
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.CalculateRingbufferSize.return:10
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.return:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_window_init.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_window_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_window_init.002
TEST.STUB:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_open_capture_unit
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].pixelClock:27.0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horDisplayPeriod:858
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horPulseStart:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horPulseEnd:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horTotal:858
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertDisplayPeriod:525
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertPulseStart:3
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertPulseEnd:2
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertTotal:2
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horTotalMin:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horTotalMax:858
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertTotalMin:520
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertTotalMax:525
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].DCKDelay:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].DCKInvertEnable:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].syncPolarity:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:MML_OK
TEST.VALUE:uut_prototype_stubs.mmlGdcCapAssignCapToWinBuffer.return:MML_ERR
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.p_meminfo:<<null>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:<<null>>
TEST.VALUE:uut_prototype_stubs.CalculateRingbufferSize.return:10
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.return:GFX_MGR02_CAPTURE_INIT_FAILURE
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_window_init.003
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_window_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_window_init.003
TEST.STUB:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_open_capture_unit
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].pixelClock:27.0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horDisplayPeriod:858
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horPulseStart:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horPulseEnd:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horTotal:858
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertDisplayPeriod:525
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertPulseStart:3
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertPulseEnd:2
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertTotal:2
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horTotalMin:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].horTotalMax:858
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertTotalMin:520
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].vertTotalMax:525
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].DCKDelay:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].DCKInvertEnable:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_modeline_param[0].syncPolarity:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.p_video_def.dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapAssignCapToWinBuffer.return:MML_OK
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.CalculateRingbufferSize.return:10
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.return:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 0
 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_window_init.004
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_window_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_window_init.004
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_window_init.return:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_video_get_status

-- Test Case: hmi_gfx_mgr02_capture_video_get_status.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_video_get_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_video_get_status.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:0
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_video_get_status.return:0
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_video_init

-- Test Case: hmi_gfx_mgr02_capture_video_init.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_video_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_video_init.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:10
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.ringBufferVirt:VECTORCAST_BUFFER
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 0 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.ringBufferVirt
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.ringBufferVirt>> == ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_video_set_status

-- Test Case: hmi_gfx_mgr02_capture_video_set_status.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_video_set_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_video_set_status.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_video_set_status.p_status:1
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:1
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_video_shutdown

-- Test Case: hmi_gfx_mgr02_capture_video_shutdown.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_video_shutdown
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_video_shutdown.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.ringBufferVirt:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_free.pAddr:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10
 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 0 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_video_shutdown.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_video_shutdown
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_video_shutdown.002
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_get_capture_init_status

-- Test Case: hmi_gfx_mgr02_get_capture_init_status.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_get_capture_init_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_get_capture_init_status.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_get_capture_init_status.return:GFX_MGR02_CAPTURE_INIT_FAILURE
TEST.END

-- Test Case: hmi_gfx_mgr02_get_capture_init_status.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_get_capture_init_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_get_capture_init_status.002
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_get_capture_init_status.return:GFX_MGR02_CAPTURE_INIT_FAILURE
TEST.END

-- Test Case: hmi_gfx_mgr02_get_capture_init_status.003
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_get_capture_init_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_get_capture_init_status.003
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_get_capture_init_status.return:GFX_MGR02_CAPTURE_INIT_SIGNAL_LOSS
TEST.END

-- Test Case: hmi_gfx_mgr02_get_capture_init_status.004
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_get_capture_init_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_get_capture_init_status.004
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_INIT_SUCCESS
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_get_capture_init_status.return:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.END

-- Subprogram: hmi_gfx_mgr02_get_capture_sync

-- Test Case: hmi_gfx_mgr02_get_capture_sync.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_get_capture_sync
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_get_capture_sync.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capSync:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capSync:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_get_capture_sync.return:<<null>>
TEST.END

-- Subprogram: hmi_gfx_mgr02_open_capture_unit

-- Test Case: hmi_gfx_mgr02_open_capture_unit.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_open_capture_unit
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_open_capture_unit.001
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:MML_ERR
TEST.VALUE:uut_prototype_stubs.mmlGdcCapSetAttribute.return:MML_ERR
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_open_capture_unit.return:GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE
TEST.END

-- Test Case: hmi_gfx_mgr02_open_capture_unit.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_open_capture_unit
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_open_capture_unit.002
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:MML_OK
TEST.VALUE:uut_prototype_stubs.mmlGdcCapSetAttribute.return:MML_OK
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_open_capture_unit.return:GFX_MGR02_CAPTURE_INTERNAL_OPEN_SUCCESS
TEST.END

-- Subprogram: hmi_gfx_mgr02_set_capture_signal_loss

-- Test Case: hmi_gfx_mgr02_set_capture_signal_loss.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_set_capture_signal_loss
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_set_capture_signal_loss.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_set_capture_signal_loss.fl_init_status:GFX_MGR02_CAPTURE_INIT_SIGNAL_LOSS
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE
TEST.END

-- Test Case: hmi_gfx_mgr02_set_capture_signal_loss.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_set_capture_signal_loss
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_set_capture_signal_loss.002
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_set_capture_signal_loss.fl_init_status:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE
TEST.END
