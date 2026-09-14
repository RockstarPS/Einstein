-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : IMXRT_FT_UT
-- Unit(s) Under Test: hmi_gfx_mgr02_context hmi_gfx_mgr02_generic hmi_gfx_mgr02_imxrt hmi_gfx_mgr02_imxrt_lcdif hmi_gfx_mgr02_imxrt_pxp hmi_gfx_mgr02_layout hmi_gfx_mgr02_sw_compression hmi_gfx_mgr02_vglite imxrt_stub
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: hmi_gfx_mgr02_generic

-- Subprogram: hmi_gfx_mgr02_generic_build_text

-- Test Case: hmi_gfx_mgr02_generic_build_text.001
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.001
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.002
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.002
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x40000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.003
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.003
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.004
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.004
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:3
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.005
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.005
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:1
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.006
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.006
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].ex:100
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].ey:100
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:3
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.007
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.007
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].ex:100
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].ey:100
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.lc_text_layer_def_S[0].string_index:22
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:3
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x45000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.008
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.008
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].sx:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].sy:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].ex:100
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_dar_get_object_area.return[0].ey:100
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.lc_text_layer_def_S[0].string_index:22
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:3
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x43000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.009
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.009
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.010
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.010
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:6
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.011
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.011
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x34000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.012
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.012
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:2
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.013
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.013
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:2
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:2
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.014
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.014
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:2
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.015
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.015
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.016
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.016
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:0
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.017
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.017
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:2
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.018
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.018
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:0
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.019
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.019
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.020
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.020
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:2
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.021
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.021
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].draw_mode:2
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:3
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:2
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.022
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.022
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:1
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.023
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.023
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.024
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.024
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<null>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:0
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.025
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.025
TEST.COMPOUND_ONLY
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x54000004
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:2
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.026
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.026
TEST.COMPOUND_ONLY
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:10.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:10
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].build_text:hmi_gfx_mgr02_vglite_build_text
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP[0].get_bound:hmi_gfx_mgr02_vglite_get_bound
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_gen_build_mode_U8:2
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x55000004
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_text_actual_width:200
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.lc_text_layer_def_S[0].alignment:2
TEST.END

-- Test Case: hmi_gfx_mgr02_generic_build_text.028
TEST.UNIT:hmi_gfx_mgr02_generic
TEST.SUBPROGRAM:hmi_gfx_mgr02_generic_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_generic_build_text.028
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_lib_if_SP:<<null>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.x:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.l_anim_prop_SP[0].text_prop[0].coord.y:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_elem_SP[0].obj_id:0x44000000
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_aligned_widget:0
TEST.VALUE:hmi_gfx_mgr02_generic.hmi_gfx_mgr02_generic_build_text.p_obj_dirty_U8:1
TEST.END

-- Unit: hmi_gfx_mgr02_imxrt

-- Subprogram: hmi_gfx_mgr02_imxrt_build_widget

-- Test Case: hmi_gfx_mgr02_imxrt_build_widget.001
TEST.UNIT:hmi_gfx_mgr02_imxrt
TEST.SUBPROGRAM:hmi_gfx_mgr02_imxrt_build_widget
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_imxrt_build_widget.001
TEST.VALUE:hmi_gfx_mgr02_imxrt.hmi_gfx_mgr02_imxrt_build_widget.p_win_data_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_imxrt.hmi_gfx_mgr02_imxrt_build_widget.p_elem_list_SP:<<malloc 1>>
TEST.END

-- Unit: hmi_gfx_mgr02_layout

-- Subprogram: hmi_gfx_mgr02_layout_get_text_scroll_status

-- Test Case: hmi_gfx_mgr02_layout_get_text_scroll_status.001
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_get_text_scroll_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_get_text_scroll_status.001
TEST.EXPECTED:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.return:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id>> = ( GFX_NEW_TEXTS_2_ANIM );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_get_text_scroll_status.002
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_get_text_scroll_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_get_text_scroll_status.002
TEST.COMPOUND_ONLY
TEST.EXPECTED:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.return:1
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id>> = ( GFX_NEW_TEXTS_2_ANIM );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_get_text_scroll_status.003
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_get_text_scroll_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_get_text_scroll_status.003
TEST.EXPECTED:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.return:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id>> = ( 0x45000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_get_text_scroll_status.004
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_get_text_scroll_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_get_text_scroll_status.004
TEST.EXPECTED:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.return:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id>> = ( 0x46000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_get_text_scroll_status.005
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_get_text_scroll_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_get_text_scroll_status.005
TEST.EXPECTED:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.return:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id>> = ( 0x44000006 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_get_text_scroll_status.006
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_get_text_scroll_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_get_text_scroll_status.006
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.lc_text_anim_property_S[0].base_id:6
TEST.EXPECTED:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.return:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id>> = ( 0x44000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_get_text_scroll_status.007
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_get_text_scroll_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_get_text_scroll_status.007
TEST.EXPECTED:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.return:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id>> = ( 0x54000006 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_get_text_scroll_status.008
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_get_text_scroll_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_get_text_scroll_status.008
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.lc_text_layer_def_S[0].scroll:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.lc_text_anim_property_S[0].base_id:0
TEST.EXPECTED:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.return:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id>> = ( 0x44000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_get_text_scroll_status.009
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_get_text_scroll_status
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_get_text_scroll_status.009
TEST.EXPECTED:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.return:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_get_text_scroll_status.p_obj_id>> = (0x00000000);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_layout_reset_scroll

-- Test Case: hmi_gfx_mgr02_layout_reset_scroll.001
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_reset_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_reset_scroll.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:10
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id:GFX_NEW_TEXTS_2_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_reset_scroll.002
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_reset_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_reset_scroll.002
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id:GFX_NEW_TEXTS_2_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_reset_scroll.003
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_reset_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_reset_scroll.003
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id:GFX_NEW_TEXTS_1_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_reset_scroll.004
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_reset_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_reset_scroll.004
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id:GFX_NEW_IMAGES_3_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_reset_scroll.005
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_reset_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_reset_scroll.005
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id>> = ( 0x0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_reset_scroll.006
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_reset_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_reset_scroll.006
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id>> = ( 0x45000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_reset_scroll.007
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_reset_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_reset_scroll.007
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id>> = ( 0x45000004 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_reset_scroll.008
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_reset_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_reset_scroll.008
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.lc_text_anim_property_S[0].base_id:4
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_reset_scroll.p_text_anim_id>> = ( 0x45000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_layout_start_scroll

-- Test Case: hmi_gfx_mgr02_layout_start_scroll.004
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_start_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_start_scroll.004
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id:GFX_NEW_TEXTS_2_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:"\1"
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_start_scroll_not_text
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_start_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_start_scroll_not_text
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id:GFX_IMG_SPEED_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_start_scroll_text_scroll_disabled
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_start_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_start_scroll_text_scroll_disabled
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id:GFX_NEW_TEXTS_1_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_start_scroll_text_scroll_enabled
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_start_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_start_scroll_text_scroll_enabled
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id:GFX_NEW_TEXTS_2_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:"\1"
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_start_scroll_text_scroll_enabled.001
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_start_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_start_scroll_text_scroll_enabled.001
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id>> = ( 0x05000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_start_scroll_text_scroll_enabled.002
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_start_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_start_scroll_text_scroll_enabled.002
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id>> = ( 0x05000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_start_scroll_text_scroll_enabled.003
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_start_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_start_scroll_text_scroll_enabled.003
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id>> = ( 0x45000004 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_start_scroll_text_scroll_enabled.004
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_start_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_start_scroll_text_scroll_enabled.004
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.lc_text_anim_property_S[0].base_id:4
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_start_scroll.p_text_anim_id>> = (0x45000000);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_layout_stop_reset_scroll

-- Test Case: hmi_gfx_mgr02_layout_stop_reset_scroll.001
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_stop_reset_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_stop_reset_scroll.001
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_reset_scroll.p_text_anim_id:GFX_NEW_TEXTS_2_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_gfx_mgr02_anim_data_S.text_prop[0].scroll_offset:0
TEST.END

-- Subprogram: hmi_gfx_mgr02_layout_stop_scroll

-- Test Case: hmi_gfx_mgr02_layout_stop_scroll.001
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_stop_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_stop_scroll.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id:GFX_NEW_TEXTS_2_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_stop_scroll.002
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_stop_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_stop_scroll.002
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id:GFX_NEW_TEXTS_1_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_stop_scroll.003
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_stop_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_stop_scroll.003
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id:GFX_NEW_IMAGES_3_ANIM
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_stop_scroll.004
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_stop_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_stop_scroll.004
TEST.VALUE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id:GFX_NEW_FILL_SCREENS_2_ANIM
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_stop_scroll.005
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_stop_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_stop_scroll.005
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id>> = ( 0x0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_stop_scroll.006
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_stop_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_stop_scroll.006
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.lc_text_anim_property_S[0].base_id:4
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id>> = ( 0x45000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_stop_scroll.007
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_stop_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_stop_scroll.007
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id>> = ( 0x45000004 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_stop_scroll.008
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_stop_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_stop_scroll.008
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:<<malloc 3>>
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:"\1"
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id>> = ( 0x45000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: hmi_gfx_mgr02_layout_stop_scroll.009
TEST.UNIT:hmi_gfx_mgr02_layout
TEST.SUBPROGRAM:hmi_gfx_mgr02_layout_stop_scroll
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_layout_stop_scroll.009
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.lc_text_layer_def_S[0].scroll:0
TEST.VALUE:hmi_gfx_mgr02_generic.<<GLOBAL>>.lc_text_anim_property_S[0].base_id:0
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:<<malloc 3>>
TEST.VALUE:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:"\1"
TEST.EXPECTED:hmi_gfx_mgr02_layout.<<GLOBAL>>.l_txt_scroll_status_flag_U8A:""
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id
<<hmi_gfx_mgr02_layout.hmi_gfx_mgr02_layout_stop_scroll.p_text_anim_id>> = ( 0x45000000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Unit: hmi_gfx_mgr02_vglite

-- Subprogram: hmi_gfx_mgr02_vglite_append_path_data_abs

-- Test Case: hmi_gfx_mgr02_vglite_append_path_data_abs.001
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_append_path_data_abs
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_append_path_data_abs.001
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path[0].uploaded.handle:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path[0].uploaded.memory:VECTORCAST_INT2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path[0].path:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.cmd:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.data:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_append_path_data_abs.002
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_append_path_data_abs
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_append_path_data_abs.002
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path[0].uploaded.handle:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path[0].uploaded.memory:VECTORCAST_INT2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path[0].path:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.cmd:3
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.data:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_append_path_data_abs.003
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_append_path_data_abs
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_append_path_data_abs.003
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path[0].uploaded.handle:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path[0].uploaded.memory:VECTORCAST_INT2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.path[0].path:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.cmd:3
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_append_path_data_abs.data:VECTORCAST_INT3
TEST.END

-- Subprogram: hmi_gfx_mgr02_vglite_build_text

-- Test Case: hmi_gfx_mgr02_vglite_build_text_aligncentre
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_aligncentre
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_aligncentre.001
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_aligncentre.001
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:500
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_aligncentre.002
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_aligncentre.002
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_aligncentre.003
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_aligncentre.003
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_alignright
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_alignright
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_drawmode2
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_drawmode2
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_ex_ey_if
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_ex_ey_if
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_ex_ey_if2
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_ex_ey_if2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_ex_ey_if3
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_ex_ey_if3
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_invalid_clipping
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_invalid_clipping
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_invalid_clipping.001
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_invalid_clipping.001
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_invalid_fontid
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_invalid_fontid
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_id:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_0
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_0.001
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_0.001
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:0x64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_callback_check
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_callback_check
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_text_width.p_clip_text_info_SP[0].print_width:210
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_centrealign
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_centrealign
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_centrealign.001
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_centrealign.001
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_centrealign.002
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_centrealign.002
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:0x64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_centrealign_drawmode0
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_centrealign_drawmode0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_centrealign_drawmode0.001
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_centrealign_drawmode0.001
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_centrealign_drawmode0.002
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_centrealign_drawmode0.002
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.lut_ptr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.lut_ptr[0].fcc_ptr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.lut_ptr[0].fcc_ptr[0].x_eoffset:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.lut_ptr[0].fcc_ptr[0].y_soffset:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.lut_ptr[0].fcc_ptr[0].owidth:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.lut_ptr[0].fcc_ptr[0].width:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.lut_ptr[0].fcc_ptr[0].height:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.lut_ptr[0].fcc_ptr[0].fdata:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.lut_ptr[0].fcc_ptr[0].fdata:"1"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:11
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes[0].height:11
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes[0].width:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes[0].size:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].available_sizes[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].available_sizes[0].width:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].available_sizes[0].size:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].bbox.xMax:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].bbox.yMax:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].max_advance_width:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].max_advance_height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].metrics.height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].size[0].metrics.max_advance:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].memory:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].base:<<malloc 3>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].base:"10"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].pos:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].descriptor.value:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].descriptor.pointer:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].pathname.value:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].pathname.pointer:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].cursor:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].cursor:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].limit:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].stream[0].limit:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].glyph_index:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_font_size:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_leftalign
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_leftalign
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:0x64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_rightalign
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_rightalign
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_rightalign.001
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_rightalign.001
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_scroll_rightalign.002
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_scroll_rightalign.002
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:0x64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_build_text_shrink_text
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_build_text
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_build_text_shrink_text
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].extfontsize:168932
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].height_pts:50.0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unitsPerEm:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].size_table:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_group:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_vfont:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_ffile:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].is_autohint:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].bpp:12
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].char_space:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.height:20
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].p.group_sel_index:1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].unused_index:0
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.grp_ptr:"0"
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.hmi_gfx_mgr02_get_font_pointer.return[0].f.ffile_name:"0"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.x:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.loc.y:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sx:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.sy:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ex:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].state.clip.ey:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clip_mode:4
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.clut:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_w:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fb_h:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.ft2_faceprop[1].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].string_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].num_chars:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].font_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].orientation:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].dynamic:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].scroll:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_elem_def_SP[0].anim_id:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[2]:67
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[3]:68
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[4]:69
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[5]:70
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[6]:71
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[7]:72
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[8]:73
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[9]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[10]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[11]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[12]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[13]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[14]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[15]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[16]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[17]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[18]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[19]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[20]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[21]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[22]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[23]:74
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_string[24]:74
TEST.EXPECTED:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.return:0
TEST.END

-- Subprogram: hmi_gfx_mgr02_vglite_draw_outline_string

-- Test Case: hmi_gfx_mgr02_vglite_draw_outline_string.001
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_draw_outline_string
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_draw_outline_string.001
TEST.VALUE:hmi_gfx_mgr02_context.<<GLOBAL>>.l_vglite_path_cmd_buf:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_start_x:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.x:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.y:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clut:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_w:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_h:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_P:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.max_advance:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding:FT_ENCODING_MS_SYMBOL
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].platform_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_position:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_thickness:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].width:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].size:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].memory:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[2]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[3]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[4]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[5]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[6]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[7]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[8]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[9]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[10]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[11]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[12]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[13]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[14]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[15]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[16]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[17]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[18]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[19]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[20]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[21]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[22]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[23]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[24]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_str_length:25
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_draw_outline_string
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added
TEST.VALUE:uut_prototype_stubs.FT_Get_Char_Index.return:10
TEST.VALUE:hmi_gfx_mgr02_context.<<GLOBAL>>.l_vglite_path_cmd_buf:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_start_x:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.x:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.y:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clut:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_w:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_h:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_P:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.max_advance:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding:FT_ENCODING_MS_SYMBOL
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].platform_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_position:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_thickness:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].width:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].size:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].memory:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[2]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[3]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[4]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[5]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[6]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[7]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[8]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[9]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[10]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[11]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[12]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[13]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[14]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[15]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[16]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[17]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[18]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[19]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[20]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[21]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[22]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[23]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[24]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_str_length:25
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.001
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_draw_outline_string
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.001
TEST.VALUE:uut_prototype_stubs.FT_Get_Char_Index.return:10,0
TEST.VALUE:hmi_gfx_mgr02_context.<<GLOBAL>>.l_vglite_path_cmd_buf:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_start_x:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.x:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.y:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clut:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_w:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_h:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_P:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.max_advance:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding:FT_ENCODING_MS_SYMBOL
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].platform_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_position:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_thickness:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].width:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].size:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].memory:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[2]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[3]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[4]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[5]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[6]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[7]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[8]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[9]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[10]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[11]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[12]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[13]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[14]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[15]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[16]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[17]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[18]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[19]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[20]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[21]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[22]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[23]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[24]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_str_length:25
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.002
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_draw_outline_string
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.002
TEST.VALUE:uut_prototype_stubs.FT_Get_Char_Index.return:10
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].bounding_box[0]:1.0
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].quality:VG_LITE_HIGH
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].format:VG_LITE_S16
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.handle:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.memory:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.address:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.bytes:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.property:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path_length:0
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path_changed:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].pdata_internal:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].stroke_conversion:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.data_format:VG_LITE_S16
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.quality:VG_LITE_UPPER
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.return:VG_LITE_SUCCESS
TEST.VALUE:hmi_gfx_mgr02_context.<<GLOBAL>>.l_vglite_path_cmd_buf:VECTORCAST_BUFFER
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_start_x:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.x:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.y:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clut:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_w:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_h:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_P:VECTORCAST_INT2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.max_advance:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding:FT_ENCODING_MS_SYMBOL
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].platform_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_position:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_thickness:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].width:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].size:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].memory:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].format:FT_GLYPH_FORMAT_OUTLINE
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_font_size:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[2]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[3]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[4]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[5]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[6]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[7]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[8]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[9]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[10]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[11]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[12]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[13]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[14]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[15]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[16]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[17]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[18]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[19]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[20]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[21]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[22]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[23]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[24]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP[0].is_autohint:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_draw_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_str_length:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_alignment:0
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.003
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_draw_outline_string
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.003
TEST.VALUE:uut_prototype_stubs.FT_Get_Char_Index.return:10,0
TEST.VALUE:hmi_gfx_mgr02_context.<<GLOBAL>>.l_vglite_path_cmd_buf:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_start_x:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.x:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.y:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clut:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_w:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_h:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_P:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.max_advance:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding:FT_ENCODING_MS_SYMBOL
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].platform_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_position:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_thickness:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].width:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].size:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].memory:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[2]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[3]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[4]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[5]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[6]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[7]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[8]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[9]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[10]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[11]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[12]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[13]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[14]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[15]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[16]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[17]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[18]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[19]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[20]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[21]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[22]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[23]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[24]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP[0].is_autohint:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_str_length:25
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.004
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_draw_outline_string
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.004
TEST.VALUE:uut_prototype_stubs.FT_Get_Char_Index.return:10
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].bounding_box[0]:1.0
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].quality:VG_LITE_HIGH
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].format:VG_LITE_S16
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.handle:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.memory:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.address:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.bytes:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.property:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path_length:0
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path_changed:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].pdata_internal:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].stroke_conversion:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.data_format:VG_LITE_S16
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.quality:VG_LITE_UPPER
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.return:VG_LITE_SUCCESS
TEST.VALUE:hmi_gfx_mgr02_context.<<GLOBAL>>.l_vglite_path_cmd_buf:VECTORCAST_BUFFER
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_start_x:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.x:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.y:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clut:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_w:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_h:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_P:VECTORCAST_INT2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.max_advance:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding:FT_ENCODING_MS_SYMBOL
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].platform_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_position:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_thickness:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].width:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].size:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].memory:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].format:FT_GLYPH_FORMAT_OUTLINE
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_font_size:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[2]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[3]:32
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[4]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[5]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[6]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[7]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[8]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[9]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[10]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[11]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[12]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[13]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[14]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[15]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[16]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[17]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[18]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[19]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[20]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[21]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[22]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[23]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[24]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP[0].is_autohint:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_draw_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_str_length:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_alignment:0
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.005
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_draw_outline_string
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.005
TEST.VALUE:uut_prototype_stubs.FT_Get_Char_Index.return:10
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].bounding_box[0]:1.0
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].quality:VG_LITE_HIGH
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].format:VG_LITE_S16
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.handle:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.memory:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.address:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.bytes:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.property:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path_length:0
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path_changed:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].pdata_internal:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].stroke_conversion:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.data_format:VG_LITE_S16
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.quality:VG_LITE_UPPER
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.return:VG_LITE_SUCCESS
TEST.VALUE:hmi_gfx_mgr02_context.<<GLOBAL>>.l_vglite_path_cmd_buf:VECTORCAST_BUFFER
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_start_x:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.x:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.y:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.alpha:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clut:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_w:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_h:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_P:VECTORCAST_INT2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.max_advance:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding:FT_ENCODING_MS_SYMBOL
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].platform_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_position:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_thickness:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].width:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].size:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].memory:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].format:FT_GLYPH_FORMAT_OUTLINE
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_font_size:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[2]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[3]:32
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[4]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[5]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[6]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[7]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[8]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[9]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[10]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[11]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[12]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[13]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[14]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[15]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[16]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[17]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[18]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[19]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[20]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[21]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[22]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[23]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[24]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP[0].is_autohint:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_draw_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_str_length:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_alignment:0
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.006
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_draw_outline_string
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added.006
TEST.VALUE:uut_prototype_stubs.FT_Get_Char_Index.return:10
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].bounding_box[0]:1.0
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].quality:VG_LITE_HIGH
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].format:VG_LITE_S16
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.handle:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.memory:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.address:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.bytes:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].uploaded.property:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path_length:0
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].path_changed:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].pdata_internal:1
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.path[0].stroke_conversion:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.data_format:VG_LITE_S16
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.quality:VG_LITE_UPPER
TEST.VALUE:uut_prototype_stubs.vg_lite_init_path.return:VG_LITE_SUCCESS
TEST.VALUE:hmi_gfx_mgr02_context.<<GLOBAL>>.l_vglite_path_cmd_buf:VECTORCAST_BUFFER
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_start_x:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.x:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.y:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.alpha:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.alignment:2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clut:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_w:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_h:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_P:VECTORCAST_INT2
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.max_advance:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding:FT_ENCODING_MS_SYMBOL
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].platform_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_position:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_thickness:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_font_size:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[2]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[3]:32
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[4]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[5]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[6]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[7]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[8]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[9]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[10]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[11]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[12]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[13]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[14]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[15]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[16]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[17]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[18]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[19]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[20]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[21]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[22]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[23]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[24]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP[0].is_autohint:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_draw_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_str_length:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_alignment:0
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added_rightalign
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_draw_outline_string
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added_rightalign
TEST.VALUE:uut_prototype_stubs.FT_Get_Char_Index.return:10,0
TEST.VALUE:hmi_gfx_mgr02_context.<<GLOBAL>>.l_vglite_path_cmd_buf:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_start_x:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.x:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.y:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clut:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_w:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_h:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_P:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:64
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.max_advance:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding:FT_ENCODING_MS_SYMBOL
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].platform_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_position:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_thickness:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].width:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].size:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].memory:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[2]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[3]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[4]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[5]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[6]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[7]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[8]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[9]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[10]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[11]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[12]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[13]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[14]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[15]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[16]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[17]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[18]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[19]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[20]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[21]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[22]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[23]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[24]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_str_length:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_alignment:1
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- Test Case: hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added_rightalign.001
TEST.UNIT:hmi_gfx_mgr02_vglite
TEST.SUBPROGRAM:hmi_gfx_mgr02_vglite_draw_outline_string
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_vglite_draw_outline_string_char_index_added_rightalign.001
TEST.VALUE:uut_prototype_stubs.FT_Get_Char_Index.return:10,0
TEST.VALUE:hmi_gfx_mgr02_context.<<GLOBAL>>.l_vglite_path_cmd_buf:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_start_x:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.x:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.loc.y:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.alpha:255
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.invisible:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.matrix[0..8]:1.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sx:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.sy:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ex:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].state.clip.ey:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.layer_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_format:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_target:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.alignment:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.draw_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clip_mode:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_id:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.scroll_offset:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.font_size.point_size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.clut:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_w:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_h:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fb_P:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.fg_color:0xFF000000
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.bg_color:0xFF0000FF
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.text_width:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.x:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.pivot.y:0.0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].face_flags:0
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].width:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0]:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].available_sizes:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMin:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.xMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].bbox.yMax:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].face:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.x_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.y_scale:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].size[0].metrics.max_advance:200
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].memory:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.head[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].sizes_list.tail[0].data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].autohint.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].face[0].extensions:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding:FT_ENCODING_MS_SYMBOL
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].platform_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].charmaps[0][0].encoding_id:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].height:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_position:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].underline_thickness:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_faces:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_index:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].face_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_flags:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_glyphs:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].family_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].style_name:"1"
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_fixed_sizes:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].height:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].width:20
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].size:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].x_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].available_sizes[0].y_ppem:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].num_charmaps:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmaps:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.data:VECTORCAST_INT1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].generic.finalizer:hmi_gfx_mgr02_imxrt_mem_mgmt_free
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMin:10
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.xMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].bbox.yMax:100
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].units_per_EM:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].ascender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].descender:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].height:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_width:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].max_advance_height:300
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_position:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].underline_thickness:1
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].glyph:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].size:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].charmap:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].memory:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_cntx_SP[0].rprop.ft2_faceprop[0].ft2_face[0].glyph[0].face[0].stream:<<null>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p:<<malloc 25>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[0]:65
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[1]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[2]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[3]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[4]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[5]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[6]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[7]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[8]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[9]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[10]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[11]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[12]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[13]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[14]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[15]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[16]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[17]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[18]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[19]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[20]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[21]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[22]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[23]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_string_p[24]:66
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_str_length:25
TEST.VALUE:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_draw_outline_string.p_alignment:1
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.fg_color:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_gfx_mgr02_vglite.hmi_gfx_mgr02_vglite_build_text.p_cntx_SP[0].rprop.bg_color:INPUT_BASE=16
TEST.END

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:scroll_build_text
TEST.SLOT: "1", "hmi_gfx_mgr02_layout", "hmi_gfx_mgr02_layout_start_scroll", "1", "hmi_gfx_mgr02_layout_start_scroll.004"
TEST.SLOT: "2", "hmi_gfx_mgr02_generic", "hmi_gfx_mgr02_generic_build_text", "1", "hmi_gfx_mgr02_generic_build_text.003"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:scroll_build_text.001
TEST.SLOT: "1", "hmi_gfx_mgr02_layout", "hmi_gfx_mgr02_layout_start_scroll", "1", "hmi_gfx_mgr02_layout_start_scroll.004"
TEST.SLOT: "2", "hmi_gfx_mgr02_generic", "hmi_gfx_mgr02_generic_build_text", "1", "hmi_gfx_mgr02_generic_build_text.004"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:scroll_build_text.002
TEST.SLOT: "1", "hmi_gfx_mgr02_layout", "hmi_gfx_mgr02_layout_start_scroll", "1", "hmi_gfx_mgr02_layout_start_scroll.004"
TEST.SLOT: "2", "hmi_gfx_mgr02_generic", "hmi_gfx_mgr02_generic_build_text", "1", "hmi_gfx_mgr02_generic_build_text.025"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:scroll_build_text.003
TEST.SLOT: "1", "hmi_gfx_mgr02_layout", "hmi_gfx_mgr02_layout_start_scroll", "1", "hmi_gfx_mgr02_layout_start_scroll.004"
TEST.SLOT: "2", "hmi_gfx_mgr02_generic", "hmi_gfx_mgr02_generic_build_text", "1", "hmi_gfx_mgr02_generic_build_text.026"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:scroll_check
TEST.SLOT: "1", "hmi_gfx_mgr02_layout", "hmi_gfx_mgr02_layout_start_scroll", "1", "hmi_gfx_mgr02_layout_start_scroll.004"
TEST.SLOT: "2", "hmi_gfx_mgr02_layout", "hmi_gfx_mgr02_layout_get_text_scroll_status", "1", "hmi_gfx_mgr02_layout_get_text_scroll_status.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:scroll_reset
TEST.SLOT: "1", "hmi_gfx_mgr02_layout", "hmi_gfx_mgr02_layout_start_scroll", "1", "hmi_gfx_mgr02_layout_start_scroll.004"
TEST.SLOT: "2", "hmi_gfx_mgr02_layout", "hmi_gfx_mgr02_layout_reset_scroll", "1", "hmi_gfx_mgr02_layout_reset_scroll.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:scroll_stop
TEST.SLOT: "1", "hmi_gfx_mgr02_layout", "hmi_gfx_mgr02_layout_start_scroll", "1", "hmi_gfx_mgr02_layout_start_scroll.004"
TEST.SLOT: "2", "hmi_gfx_mgr02_layout", "hmi_gfx_mgr02_layout_stop_scroll", "1", "hmi_gfx_mgr02_layout_stop_scroll.001"
TEST.END
--
