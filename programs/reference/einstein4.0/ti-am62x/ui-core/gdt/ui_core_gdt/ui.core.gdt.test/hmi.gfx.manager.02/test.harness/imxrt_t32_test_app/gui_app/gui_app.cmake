if(NOT GUI_APP_INCLUDED)
    
    set(GUI_APP_INCLUDED true CACHE BOOL "gui component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_context.c		
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_cache.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_context.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_devanagari.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_dirty_area.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_generic.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_gsub.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_layout.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_mem.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_perflog.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_safety.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_shape_engine.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_text_thai.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_capture_video.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_text.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_imxrt_pxp.c	
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_imxrt.c	
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/hmi_gfx_mgr02_imxrt_lcdif.c	
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../../../iceapple/ui.core.iceapple/view.manager.02/src/hmi_logic_state_handler.c	
		${CMAKE_CURRENT_LIST_DIR}/../../../../../../../iceapple/ui.core.iceapple/view.manager.02/src/hmi_view_manager_02.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../../../iceapple/ui.core.iceapple/view.manager.02/src/hmi_view_manager_02_autocode.c    
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../../../iceapple/ui.core.iceapple/language.core.01/src/hmi_language_interface.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../../../iceapple/ui.core.iceapple/animation.core.02/src/hmi_gfx_anim_engine.c
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../../../iceapple/ui.core.iceapple/animation.core.02/src/hmi_gfx_anim_vm02_if.c
        ${CMAKE_CURRENT_LIST_DIR}/../gui_app/src/hmi_gfx_mgr02_imxrt_mem_mgmt.c	
		${CMAKE_CURRENT_LIST_DIR}/../gui_app/src/hmi_gfx02_image_data.c
		${CMAKE_CURRENT_LIST_DIR}/../gui_app/src/hmi_language_1.c
        ${CMAKE_CURRENT_LIST_DIR}/../gui_app/autogen/hmi_gfx_mgr02_clut_table.c
		${CMAKE_CURRENT_LIST_DIR}/../gui_app/autogen/hmi_gfx_mgr02_font.c		
		${CMAKE_CURRENT_LIST_DIR}/../gui_app/autogen/hmi_gfx_mgr02_vgfont.c
        ${CMAKE_CURRENT_LIST_DIR}/../gui_app/autogen/New_fonts_1.c  
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../../../../../ui.core.gdt/hmi.gfx.manager.02/src/
		${CMAKE_CURRENT_LIST_DIR}/../../../../../../../iceapple/ui.core.iceapple/view.manager.02/src/
		${CMAKE_CURRENT_LIST_DIR}/../../../../../../../iceapple/ui.core.iceapple/language.core.01/src
		${CMAKE_CURRENT_LIST_DIR}/../gui_app/
		${CMAKE_CURRENT_LIST_DIR}/../gui_app/src
		${CMAKE_CURRENT_LIST_DIR}/../gui_app/autogen
		${CMAKE_CURRENT_LIST_DIR}/../gui_app/src
		${CMAKE_CURRENT_LIST_DIR}/../gui_app/cfg
		${CMAKE_CURRENT_LIST_DIR}/../gui_app/cfg/iceapple
    )


endif()
