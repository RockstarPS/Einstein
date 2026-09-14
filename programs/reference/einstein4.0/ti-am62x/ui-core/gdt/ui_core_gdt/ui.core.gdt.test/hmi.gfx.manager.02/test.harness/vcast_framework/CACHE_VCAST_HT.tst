-- VectorCAST 6.4s (05/01/17)
-- Test Case Script
-- 
-- Environment    : CACHE_VCAST_HT
-- Unit(s) Under Test: hmi_gfx_mgr02_cache
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: hmi_gfx_mgr02_add_string_in_cache_queue

-- Test Case: hmi_gfx_mgr02_add_string_in_cache_queue.001
TEST.UNIT:hmi_gfx_mgr02_cache
TEST.SUBPROGRAM:hmi_gfx_mgr02_add_string_in_cache_queue
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_add_string_in_cache_queue.001
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].Prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].FontId:00
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].FontSize:20
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].StringLen:25
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].bmpWidth:200
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].Buf:<<malloc 11>>
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].Buf:"0x50000000"
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[0]:1
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[1]:2
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[2]:3
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[3]:4
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[4]:5
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[5]:6
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[6]:7
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[7]:8
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[8]:9
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[9]:10
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[10]:11
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[11]:12
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[12]:13
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[13]:14
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[14]:15
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[15]:16
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[16]:17
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[17]:18
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[18]:19
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[19]:20
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[20]:21
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[21]:22
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[22]:23
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[23]:24
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[24]:0
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].Next:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_cache.<<GLOBAL>>.cur_cache_size:1
TEST.END

-- Test Case: hmi_gfx_mgr02_add_string_in_cache_queue.002
TEST.UNIT:hmi_gfx_mgr02_cache
TEST.SUBPROGRAM:hmi_gfx_mgr02_add_string_in_cache_queue
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_add_string_in_cache_queue.002
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Buf:<<malloc 5>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Buf:"2500"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.cur_cache_size:49,50
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].FontId:1
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].FontSize:25
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].StringLen:5,35
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].bmpWidth:200
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].Buf:<<malloc 11>>
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].Buf:"0x50002000"
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[0]:50
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_add_string_in_cache_queue.element[0].String[1]:0
TEST.EXPECTED:hmi_gfx_mgr02_cache.<<GLOBAL>>.cur_cache_size:50
TEST.END

-- Subprogram: hmi_gfx_mgr02_cache_init

-- Test Case: hmi_gfx_mgr02_cache_init.001
TEST.UNIT:hmi_gfx_mgr02_cache
TEST.SUBPROGRAM:hmi_gfx_mgr02_cache_init
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_cache_init.001
TEST.EXPECTED:hmi_gfx_mgr02_cache.<<GLOBAL>>.head:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_cache.<<GLOBAL>>.cur_cache_size:0
TEST.END

-- Subprogram: hmi_gfx_mgr02_cache_shutdown

-- Test Case: hmi_gfx_mgr02_cache_shutdown.001
TEST.UNIT:hmi_gfx_mgr02_cache
TEST.SUBPROGRAM:hmi_gfx_mgr02_cache_shutdown
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_cache_shutdown.001
TEST.EXPECTED:hmi_gfx_mgr02_cache.<<GLOBAL>>.head:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_cache.<<GLOBAL>>.cur_cache_size:0
TEST.END

-- Subprogram: hmi_gfx_mgr02_get_string_cache_ptr

-- Test Case: hmi_gfx_mgr02_get_string_cache_ptr.001
TEST.UNIT:hmi_gfx_mgr02_cache
TEST.SUBPROGRAM:hmi_gfx_mgr02_get_string_cache_ptr
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_get_string_cache_ptr.001
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].FontId:2
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].FontSize:40
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].StringLen:2
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].bmpWidth:400
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Buf:<<malloc 7>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Buf:"0x9000"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].String[0]:90
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].String[1]:80
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].String[2]:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].FontId:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].FontSize:25
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].StringLen:1
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].bmpWidth:200
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Buf:<<malloc 7>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Buf:"0x5000"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].String[0]:30
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].String[1..2]:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].FontId:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].FontSize:20
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].StringLen:2
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].bmpWidth:100
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Buf:<<malloc 7>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Buf:"0x6000"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].String[0]:40
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].String[1]:41
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].String[2..4]:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].Prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].FontId:1
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].FontSize:10
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].StringLen:5
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].bmpWidth:50
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].Buf:<<malloc 7>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].Buf:"0x7000"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].String[0]:10
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].String[1]:11
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].String[2]:12
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].String[3]:13
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].String[4]:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next[0].Next[0].Next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Prev:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Prev[0].FontId:2
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Prev[0].FontSize:40
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Prev[0].StringLen:2
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Prev[0].bmpWidth:400
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Prev[0].Buf:<<malloc 7>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Prev[0].Buf:"0x9000"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Prev[0].String[0]:90
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Prev[0].String[1]:80
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Prev[0].String[2..3]:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].FontId:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].FontSize:25
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].StringLen:1
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].bmpWidth:200
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Buf:<<malloc 7>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Buf:"0x5000"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].String[0]:30
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].String[1]:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Prev[0].Next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].FontId:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].FontSize:20
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].StringLen:2
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].bmpWidth:100
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Buf:<<malloc 7>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].Buf:"0x6000"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].String[0]:40
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].String[1]:41
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev[0].String[2]:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].FontId:1
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].FontSize:10
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].StringLen:4
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].bmpWidth:50
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Buf:<<malloc 7>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Buf:"0x7000"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].String[0]:10
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].String[1]:11
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].String[2]:12
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].String[3]:13
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].String[4]:0
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.cur_cache_size:0,1,2,49,50,51
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_string_p:<<malloc 5>>
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_string_p[0]:40,10,30,90
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_string_p[1]:41,11,0,80
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_string_p[2]:0,12,(2)0
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_string_p[3]:0,13,(2)0
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_string_p[4]:(4)0
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_cntx_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_cntx_SP[0].rprop.font_id:0,1,0,2
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_font_SP:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_font_SP[0].height_pts:25.0
TEST.VALUE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.p_font_SP[0].p.height:20,10,25,40
TEST.EXPECTED_USER_CODE:hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.return
{{ <<hmi_gfx_mgr02_cache.hmi_gfx_mgr02_get_string_cache_ptr.return>> == ( 0x6000),(0x7000),(0x5000),(0x9000) }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_shutdown_string_cache

-- Test Case: hmi_gfx_mgr02_shutdown_string_cache.001
TEST.UNIT:hmi_gfx_mgr02_cache
TEST.SUBPROGRAM:hmi_gfx_mgr02_shutdown_string_cache
TEST.NEW
TEST.NAME:hmi_gfx_mgr02_shutdown_string_cache.001
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Buf:<<malloc 11>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Buf:"0x50000000"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Buf:<<malloc 2>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Buf:"0"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.head[0].Next[0].Next:<<null>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Prev:<<null>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Buf:<<malloc 16>>
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Buf:"0x50000000","NULL"
TEST.VALUE:hmi_gfx_mgr02_cache.<<GLOBAL>>.tail[0].Next:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_cache.<<GLOBAL>>.cur_cache_size:0
TEST.END
