-- VectorCAST 6.4s (05/01/17)
-- Test Case Script
-- 
-- Environment    : CAPTURE_VIDEO_SURFACE_MODE
-- Unit(s) Under Test: hmi_gfx_mgr02_capture_video
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: <<INIT>>

-- Test Case: <<INIT>>.001
TEST.SUBPROGRAM:<<INIT>>
TEST.NEW
TEST.NAME:<<INIT>>.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.active_width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.active_height:480
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.total_width:858
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.total_height:525
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.pix_clk:27.027
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.polEn:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.polHs:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.polVs:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.format:MML_GDC_CAP_VIDEO_FORMAT_YUV422
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.directCapEnable:MML_GDC_CAP_DIRECT_CAPTURE_OFF
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.video_mode:MML_GDC_CAP_MODE_INTERLACED
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:0
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.active_width:720
TEST.END

-- Unit: hmi_gfx_mgr02_capture_video

-- Subprogram: hmi_gfx_mgr02_capture_get_surface

-- Test Case: hmi_gfx_mgr02_capture_get_surface.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_get_surface
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_get_surface.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:0
TEST.VALUE:uut_prototype_stubs.mmlGdcCapGetSurface.return:10
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_get_surface.fl_video_surface:<<null>>
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_get_surface.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_get_surface
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_get_surface.002
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:1
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_get_surface.fl_video_surface:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.mmlGdcCapGetSurface.return:10
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_get_surface.fl_video_surface:<<null>>
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_to_surf_memory_allocation

-- Test Case: hmi_gfx_mgr02_capture_to_surf_memory_allocation.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surf_memory_allocation
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surf_memory_allocation.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].dim.height:480
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:VECTORCAST_BUFFER
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.return:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surf_memory_allocation.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surf_memory_allocation
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surf_memory_allocation.002
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.format:MML_GDC_CAP_VIDEO_FORMAT_YUV422
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].dim.height:480
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.return:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:VECTORCAST_BUFFER
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.return:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surf_memory_allocation.003
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surf_memory_allocation
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surf_memory_allocation.003
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.format:MML_GDC_CAP_VIDEO_FORMAT_RGB
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.p_video_def[0].dim.height:480
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.return:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:VECTORCAST_BUFFER
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_memory_allocation.return:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_SUCCESS
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_to_surf_start_capture

-- Test Case: hmi_gfx_mgr02_capture_to_surf_start_capture.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surf_start_capture
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surf_start_capture.001
TEST.VALUE:uut_prototype_stubs.mmlGdcCapCommit.return:5
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_start_capture.return:GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surf_start_capture.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surf_start_capture
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surf_start_capture.002
TEST.VALUE:uut_prototype_stubs.mmlGdcCapCommit.return:MML_OK
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surf_start_capture.return:GFX_MGR02_CAPTURE_INTERNAL_INIT_SUCCESS
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_to_surface_commit

-- Test Case: hmi_gfx_mgr02_capture_to_surface_commit.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surface_commit
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surface_commit.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:1
TEST.VALUE:uut_prototype_stubs.mmlGdcCapSync.return:10
TEST.VALUE:uut_prototype_stubs.mmlGdcCapCommit.return:10
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:1
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10
 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surface_commit.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surface_commit
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surface_commit.002
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:0
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10
 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_to_surface_init

-- Test Case: hmi_gfx_mgr02_capture_to_surface_init.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surface_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surface_init.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.height:480
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:VECTORCAST_BUFFER
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.return:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 0
 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surface_init.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surface_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surface_init.002
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_MEMORY_ALLOCATION_FAILURE
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.height:480
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:VECTORCAST_BUFFER
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.return:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surface_init.003
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surface_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surface_init.003
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapCommit.return:MML_OK
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:VECTORCAST_BUFFER
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.return:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surface_init.004
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surface_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surface_init.004
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_INIT_SUCCESS
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapCommit.return:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:VECTORCAST_BUFFER
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.return:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surface_init.005
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surface_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surface_init.005
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_COMMIT_FAILURE
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapCommit.return:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.return:GFX_MGR02_CAPTURE_INIT_SIGNAL_LOSS
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surface_init.006
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surface_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surface_init.006
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:5
TEST.VALUE:uut_prototype_stubs.mmlGdcCapCommit.return:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.return:GFX_MGR02_CAPTURE_INIT_FAILURE
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surface_init.007
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surface_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surface_init.007
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_INIT_SUCCESS
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:5
TEST.VALUE:uut_prototype_stubs.mmlGdcCapCommit.return:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.return:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 10 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_to_surface_init.008
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_to_surface_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_to_surface_init.008
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.width:720
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.p_video_def[0].dim.height:480
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:MML_OK
TEST.VALUE:uut_prototype_stubs.mmlGdcCapCommit.return:MML_OK
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_amber_mem_mgmt_malloc.return:VECTORCAST_BUFFER
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_to_surface_init.return:GFX_MGR02_CAPTURE_INIT_SUCCESS
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 0
 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_video_get_status

-- Test Case: hmi_gfx_mgr02_capture_video_get_status.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_video_get_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_video_get_status.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:1
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_video_get_status.return:1
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_video_init

-- Test Case: hmi_gfx_mgr02_capture_video_init.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_video_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_video_init.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:1
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capSurf[1]:<<null>>
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capSurf[2]:<<null>>
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.unit:0
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:10
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10
 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 0 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_video_set_status

-- Test Case: hmi_gfx_mgr02_capture_video_set_status.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_video_set_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_video_set_status.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:10
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_capture_video_set_status.p_status:1
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_gfx_mgr02_video_mode_status:1
TEST.END

-- Subprogram: hmi_gfx_mgr02_capture_video_shutdown

-- Test Case: hmi_gfx_mgr02_capture_video_shutdown.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_video_shutdown
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_video_shutdown.001
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 100 );
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
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 0
 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 0 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_capture_video_shutdown.003
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_capture_video_shutdown
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_capture_video_shutdown.003
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_INIT_SUCCESS
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_cap_init_status:GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
<<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> = ( 10
 );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx
{{ <<hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capCtx>> == ( 0 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
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
TEST.VALUE:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_get_capture_sync.return:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_get_capture_sync.return:<<null>>
TEST.END

-- Subprogram: hmi_gfx_mgr02_open_capture_unit

-- Test Case: hmi_gfx_mgr02_open_capture_unit.001
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_open_capture_unit
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_open_capture_unit.001
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.format:MML_GDC_CAP_VIDEO_FORMAT_YUV422
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:MML_ERR
TEST.VALUE:uut_prototype_stubs.mmlGdcCapSetAttribute.return:MML_ERR
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_open_capture_unit.return:GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE
TEST.END

-- Test Case: hmi_gfx_mgr02_open_capture_unit.002
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_open_capture_unit
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_open_capture_unit.002
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.format:MML_GDC_CAP_VIDEO_FORMAT_YUV444
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:0
TEST.VALUE:uut_prototype_stubs.mmlGdcCapSetAttribute.return:0
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_open_capture_unit.return:GFX_MGR02_CAPTURE_INTERNAL_OPEN_SUCCESS
TEST.END

-- Test Case: hmi_gfx_mgr02_open_capture_unit.003
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_open_capture_unit
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_open_capture_unit.003
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.format:MML_GDC_CAP_VIDEO_FORMAT_YUV422
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:MML_OK
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_open_capture_unit.return:GFX_MGR02_CAPTURE_INTERNAL_OPEN_SUCCESS
TEST.END

-- Test Case: hmi_gfx_mgr02_open_capture_unit.004
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_open_capture_unit
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_open_capture_unit.004
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.format:MML_GDC_CAP_VIDEO_FORMAT_RGB
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:MML_OK
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_open_capture_unit.return:GFX_MGR02_CAPTURE_INTERNAL_OPEN_SUCCESS
TEST.END

-- Test Case: hmi_gfx_mgr02_open_capture_unit.005
TEST.UNIT:hmi_gfx_mgr02_capture_video
TEST.SUBPROGRAM:hmi_gfx_mgr02_open_capture_unit
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_open_capture_unit.005
TEST.VALUE:hmi_gfx_mgr02_capture_video.<<GLOBAL>>.l_capProperties.format:MML_GDC_CAP_VIDEO_FORMAT_RGB
TEST.VALUE:uut_prototype_stubs.mmlGdcCapOpen.return:5
TEST.EXPECTED:hmi_gfx_mgr02_capture_video.hmi_gfx_mgr02_open_capture_unit.return:GFX_MGR02_CAPTURE_INTERNAL_OPEN_FAILURE
TEST.END
