-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : SWLIB_TIDSS_UT_ENV
-- Unit(s) Under Test: hmi_gfx_mgr02_swrlib hmi_gfx_mgr02_tidss_dispif
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: hmi_gfx_mgr02_swrlib

-- Subprogram: hmi_gfx_mgr02_emergency_shutdown

-- Test Case: 1_set_shutdown_flag_as_emergency
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_emergency_shutdown
TEST.NEW
TEST.NAME:1_set_shutdown_flag_as_emergency
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:1
TEST.END

-- Subprogram: hmi_gfx_mgr02_is_emergency_shutdown_req_active

-- Test Case: 1_get_shutdown_status
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_is_emergency_shutdown_req_active
TEST.NEW
TEST.NAME:1_get_shutdown_status
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:0,1
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_is_emergency_shutdown_req_active.return:0,1
TEST.END

-- Subprogram: hmi_gfx_mgr02_swrlib_build_text

-- Test Case: 10_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:10_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_CENTRE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:105
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 11_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:11_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 12_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:12_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 13_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:13_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (0 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 14_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:14_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (1 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 15_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:15_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (2 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 16_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:16_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (4 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 17_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:17_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<null>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 18_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:18_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = NULL;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 19_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:19_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB4444
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 1_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:1_render_text
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 20_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:20_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_RGB565
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (2 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 21_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:21_render_text
TEST.NOTES:

TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB4444
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (2 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 22_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:22_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_RGB565
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 23_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:23_render_text
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 24_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:24_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_RGB565
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 25_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:25_render_text
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[4] = 0xFF;
fl_font_data[5] = 0xFF;
fl_font_data[6] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 2_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:2_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:1
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[0] = 0xFFFFFFFF;
fl_fb_ptr[1] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 3_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:3_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_EMERGENCY
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[0] = 0xFFFFFFFF;
fl_fb_ptr[1] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 4_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:4_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[0] = 0xFFFFFFFF;
fl_fb_ptr[1] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 5_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:5_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[0] = 0xFFFFFFFF;
fl_fb_ptr[1] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 6_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:6_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<null>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[0] = 0xFFFFFFFF;
fl_fb_ptr[1] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 7_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:7_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_CENTRE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 8_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:8_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_RIGHT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_LEFT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 9_render_text
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_build_text
TEST.NEW
TEST.NAME:9_render_text
TEST.NOTES:
Default Configuration:

fb target format - argb8888
font aa - 8bpp
alignment -left
clip mode - textfit
drawmode - transparent
string - Hello
textbox width - 100
fg_color - 0xFFFFFFFF
bg_color - 0xFF000000
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_gfx_mgr02_swrlib.<<GLOBAL>>.l_gfx_mgr_shutdown_status:GFX_MGR02_SHUTDOWN_NORMAL
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ex:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].state.clip.ey:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_format:GFX_MGR02_PIX_FORMAT_ARGB8888
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_target:GFX_MGR02_TARGET_SOFTWARE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.alignment:GFX_MGR02_TP_ALIGN_RIGHT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.draw_mode:GFX_MGR02_TP_DRAW_TRANSP
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.clip_mode:GFX_MGR02_TP_CLIP_FIT
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_w:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fb_h:4
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.fg_color:0xFFFFFFFF
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP[0].rprop.text_width:100
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_elem_def_SP[0].alignment:GFX_MGR02_TP_ALIGN_RIGHT
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.x:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].loc.y:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].alpha:255
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].invisible:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ex:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_state_get.p_context[0].clip.ey:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].x_eoffset:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].y_soffset:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].owidth:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].width:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return[0].height:4
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:5
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_id.return:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:10
TEST.EXPECTED:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return.return[0].fdata
UINT8 * fl_font_data = malloc(20);

fl_font_data[0] = 0xFF;
fl_font_data[10] = 0xFF;
<<uut_prototype_stubs.hmi_gfx_mgr02_get_fcc.return>>[0].fdata = ( fl_font_data );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return.return[0].f.lut_ptr
GFX_MGR02_FONT_LUT * fl_lut_ptr = malloc(sizeof(GFX_MGR02_FONT_LUT));
fl_lut_ptr->attributes = (3 << 2);
<<uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return>>[0].f.lut_ptr = ( fl_lut_ptr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP.p_cntx_SP[0].rprop.fb_P
UINT32 * fl_fb_ptr = malloc(25);

fl_fb_ptr[4] = 0xFFFFFFFF;
fl_fb_ptr[5] = 0xFFFFFFFF;
fl_fb_ptr[6] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_cntx_SP>>[0].rprop.fb_P = ( fl_fb_ptr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string
HMI_CHAR fl_string[12] = L"Hello";
<<hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_build_text.p_string>> = ( &fl_string[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_swrlib_finish

-- Test Case: hmi_gfx_mgr02_swrlib_finish.001
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_finish
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_swrlib_finish.001
TEST.END

-- Subprogram: hmi_gfx_mgr02_swrlib_get_bound

-- Test Case: hmi_gfx_mgr02_swrlib_get_bound.001
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_get_bound
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_swrlib_get_bound.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_get_bound.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_swrlib.hmi_gfx_mgr02_swrlib_get_bound.p_bounds:<<malloc 1>>
TEST.END

-- Subprogram: hmi_gfx_mgr02_swrlib_init

-- Test Case: hmi_gfx_mgr02_swrlib_init.001
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_swrlib_init.001
TEST.END

-- Subprogram: hmi_gfx_mgr02_swrlib_start

-- Test Case: hmi_gfx_mgr02_swrlib_start.001
TEST.UNIT:hmi_gfx_mgr02_swrlib
TEST.SUBPROGRAM:hmi_gfx_mgr02_swrlib_start
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_swrlib_start.001
TEST.END

-- Unit: hmi_gfx_mgr02_tidss_dispif

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_cb

-- Test Case: execute_callback
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_cb
TEST.NEW
TEST.NAME:execute_callback
TEST.END

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_config_dctrl

-- Test Case: configure_display_controller
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_config_dctrl
TEST.NEW
TEST.NAME:configure_display_controller
TEST.END

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_create

-- Test Case: config_dctrl_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_create
TEST.NEW
TEST.NAME:config_dctrl_failed
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:-1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].numFrames:2
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].frames:<<malloc 2>>
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_create.return:-7
TEST.END

-- Test Case: create_driver_success
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_create
TEST.NEW
TEST.NAME:create_driver_success
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_get_fb_addr.return:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].numFrames:2
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].frames:<<malloc 2>>
TEST.EXPECTED:uut_prototype_stubs.hmi_gfx_mgr02_context_get_fb_addr.p_frame_index:0,1
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].frames[0].fid:2
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].frames[1].fid:2
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_create.return:FVID2_SOK
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects.gDssObjects[0].instObj.instObj[0].frames.frames[0].addr.addr[0]
{{ <<hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects>>[0].instObj[0].frames[0].addr[0] == ( (unsigned long long)&VECTORCAST_INT1 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects.gDssObjects[0].instObj.instObj[0].frames.frames[1].addr.addr[0]
{{ <<hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects>>[0].instObj[0].frames[1].addr[0] == ( (unsigned long long)&VECTORCAST_INT1 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: fvid2_create_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_create
TEST.NEW
TEST.NAME:fvid2_create_failed
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:<<null>>
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:0
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].numFrames:2
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].createStatus.retVal:-1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].frames:<<malloc 2>>
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_create.return:-1
TEST.END

-- Test Case: fvid2_create_failed_1
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_create
TEST.NEW
TEST.NAME:fvid2_create_failed_1
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:0
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].numFrames:2
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].createStatus.retVal:-1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].frames:<<malloc 2>>
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_create.return:-1
TEST.END

-- Test Case: fvid2_queue_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_create
TEST.NEW
TEST.NAME:fvid2_queue_failed
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:0
TEST.VALUE:uut_prototype_stubs.Fvid2_queue.return:-1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].numFrames:2
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].frames:<<malloc 2>>
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_create.return:-1
TEST.END

-- Test Case: fvid2_start_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_create
TEST.NEW
TEST.NAME:fvid2_start_failed
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:(9)0,-1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_context_get_fb_addr.return:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].numFrames:2
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].frames:<<malloc 2>>
TEST.EXPECTED:uut_prototype_stubs.hmi_gfx_mgr02_context_get_fb_addr.p_frame_index:0,1
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].frames[0].fid:2
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].frames[1].fid:2
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_create.return:-1
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects.gDssObjects[0].instObj.instObj[0].frames.frames[0].addr.addr[0]
{{ <<hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects>>[0].instObj[0].frames[0].addr[0] == ( (unsigned long long)&VECTORCAST_INT1 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects.gDssObjects[0].instObj.instObj[0].frames.frames[1].addr.addr[0]
{{ <<hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects>>[0].instObj[0].frames[1].addr[0] == ( (unsigned long long)&VECTORCAST_INT1 ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_delete

-- Test Case: delete_driver_success
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_delete
TEST.NEW
TEST.NAME:delete_driver_success
TEST.VALUE:uut_prototype_stubs.Fvid2_dequeue.return:(2)0,-1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_delete.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_delete.return:0
TEST.END

-- Test Case: fvid2_control_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_delete
TEST.NEW
TEST.NAME:fvid2_control_failed
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:0,-1
TEST.VALUE:uut_prototype_stubs.Fvid2_dequeue.return:(2)0,-1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_delete.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_delete.return:-1
TEST.END

-- Test Case: fvid2_control_failed_2
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_delete
TEST.NEW
TEST.NAME:fvid2_control_failed_2
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:(2)0,-1
TEST.VALUE:uut_prototype_stubs.Fvid2_dequeue.return:(3)0,-1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_delete.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_delete.return:-1
TEST.END

-- Test Case: synclost
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_delete
TEST.NEW
TEST.NAME:synclost
TEST.VALUE:uut_prototype_stubs.Fvid2_dequeue.return:(3)0,-1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].errorStats.syncLost:10
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_delete.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_delete.return:-1
TEST.END

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_dequeue

-- Test Case: dequeue_success
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_dequeue
TEST.NEW
TEST.NAME:dequeue_success
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_dequeue.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.l_IsDequeueSuccess:true
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_dequeue.return:FVID2_SOK
TEST.END

-- Test Case: fvid2_dequeue_failed_eagain
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_dequeue
TEST.NEW
TEST.NAME:fvid2_dequeue_failed_eagain
TEST.VALUE:uut_prototype_stubs.Fvid2_dequeue.return:FVID2_EAGAIN
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_dequeue.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.l_IsDequeueSuccess:false
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_dequeue.return:FVID2_EAGAIN
TEST.END

-- Test Case: fvid2_dequeue_failed_efail_error
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_dequeue
TEST.NEW
TEST.NAME:fvid2_dequeue_failed_efail_error
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:uut_prototype_stubs.Fvid2_dequeue.return:FVID2_EFAIL
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_dequeue.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.l_IsDequeueSuccess:false
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_dequeue.return:FVID2_EFAIL
TEST.END

-- Test Case: invalid_disp_id
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_dequeue
TEST.NEW
TEST.NAME:invalid_disp_id
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_dequeue.p_disp_id:255
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.l_IsDequeueSuccess:false
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_dequeue.return:-3
TEST.END

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_init

-- Test Case: dss_init_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_init
TEST.NEW
TEST.NAME:dss_init_failed
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.gDssObjects[0].oldiParams:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.Dss_init.return:-1
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_init.return:-1
TEST.END

-- Test Case: fvid2_create_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_init
TEST.NEW
TEST.NAME:fvid2_create_failed
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.gDssObjects[0].oldiParams:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_init.return:FVID2_EFAIL
TEST.END

-- Test Case: initialize_success
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_init
TEST.NEW
TEST.NAME:initialize_success
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.gDssObjects[0].oldiParams:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:VECTORCAST_INT1
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_init.return:0
TEST.END

-- Test Case: invalid_disp_id
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_init
TEST.NEW
TEST.NAME:invalid_disp_id
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.gDssObjects[0].oldiParams:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_init.p_disp_id:255
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_init.return:-3
TEST.END

-- Test Case: oldi_param_missing
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_init
TEST.NEW
TEST.NAME:oldi_param_missing
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.gDssObjects[0].oldiParams:<<null>>
TEST.VALUE:uut_prototype_stubs.Fvid2_create.return:VECTORCAST_INT1
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_init.return:-1
TEST.END

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_init_dss_params

-- Test Case: init_dss_parameters
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_init_dss_params
TEST.NEW
TEST.NAME:init_dss_parameters
TEST.END

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_init_pipeline_params

-- Test Case: init_pipeline_parameters
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_init_pipeline_params
TEST.NEW
TEST.NAME:init_pipeline_parameters
TEST.END

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha

-- Test Case: invalid_disp_id
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha
TEST.NEW
TEST.NAME:invalid_disp_id
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:FVID2_SOK
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].dispParams.alphaCfg.globalAlpha:0
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_disp_id:255
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_pipelineId:0
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_alpha:255
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].dispParams.alphaCfg.globalAlpha:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.return:-3
TEST.END

-- Test Case: invalid_pipeline_id
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha
TEST.NEW
TEST.NAME:invalid_pipeline_id
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:FVID2_SOK
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].dispParams.alphaCfg.globalAlpha:0
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_disp_id:0
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_pipelineId:255
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_alpha:255
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].dispParams.alphaCfg.globalAlpha:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.return:-3
TEST.END

-- Test Case: pipeline_alpha_setting_success
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha
TEST.NEW
TEST.NAME:pipeline_alpha_setting_success
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:FVID2_SOK
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_disp_id:0
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_pipelineId:0
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_alpha:255
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].dispParams.alphaCfg.globalAlpha:255
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.return:FVID2_SOK
TEST.END

-- Test Case: setting_same_alpha
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha
TEST.NEW
TEST.NAME:setting_same_alpha
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:FVID2_SOK
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].dispParams.alphaCfg.globalAlpha:255
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_disp_id:0
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_pipelineId:0
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.p_alpha:255
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssObjects[0].instObj[0].dispParams.alphaCfg.globalAlpha:255
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha.return:FVID2_SOK
TEST.END

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_shutdown

-- Test Case: driver_delete_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_shutdown
TEST.NEW
TEST.NAME:driver_delete_failed
TEST.VALUE:uut_prototype_stubs.Fvid2_control.return:FVID2_EFAIL
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_shutdown.p_disp_id:0
TEST.EXPECTED:uut_prototype_stubs.Fvid2_control.cmd:FVID2_STOP
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_shutdown.return:FVID2_EFAIL
TEST.END

-- Test Case: dss_deinit_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_shutdown
TEST.NEW
TEST.NAME:dss_deinit_failed
TEST.VALUE:uut_prototype_stubs.Dss_deInit.return:FVID2_EFAIL
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_shutdown.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_shutdown.return:FVID2_EFAIL
TEST.END

-- Test Case: fvid2_delete_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_shutdown
TEST.NEW
TEST.NAME:fvid2_delete_failed
TEST.VALUE:uut_prototype_stubs.Fvid2_delete.return:FVID2_EFAIL
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_shutdown.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_shutdown.return:FVID2_EFAIL
TEST.END

-- Test Case: invalid_disp_id
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_shutdown
TEST.NEW
TEST.NAME:invalid_disp_id
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_shutdown.p_disp_id:1
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_shutdown.return:-3
TEST.END

-- Test Case: shutdown_success
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_shutdown
TEST.NEW
TEST.NAME:shutdown_success
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_shutdown.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_shutdown.return:FVID2_SOK
TEST.END

-- Subprogram: hmi_gfx_mgr02_tidss_dispif_update

-- Test Case: dequeue_returned_with_error
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_update
TEST.NEW
TEST.NAME:dequeue_returned_with_error
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.l_IsDequeueSuccess:false
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_update.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_update.return:FVID2_EFAIL
TEST.END

-- Test Case: fb_update_success
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_update
TEST.NEW
TEST.NAME:fb_update_success
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.l_IsDequeueSuccess:true
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_update.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_update.return:FVID2_SOK
TEST.END

-- Test Case: fvid2_queue_failed
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_update
TEST.NEW
TEST.NAME:fvid2_queue_failed
TEST.VALUE:uut_prototype_stubs.Fvid2_queue.return:FVID2_EFAIL
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.l_IsDequeueSuccess:true
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_update.p_disp_id:0
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_update.return:FVID2_EFAIL
TEST.END

-- Test Case: invalid_disp_id
TEST.UNIT:hmi_gfx_mgr02_tidss_dispif
TEST.SUBPROGRAM:hmi_gfx_mgr02_tidss_dispif_update
TEST.NEW
TEST.NAME:invalid_disp_id
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.l_IsDequeueSuccess:true
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_update.p_disp_id:255
TEST.EXPECTED:hmi_gfx_mgr02_tidss_dispif.hmi_gfx_mgr02_tidss_dispif_update.return:-3
TEST.END
