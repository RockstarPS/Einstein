-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HMI_MEM_MGMT_UT
-- Unit(s) Under Test: hmi_gfx_mgr02_mem_mgmt
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: hmi_gfx_mgr02_mem_mgmt

-- Subprogram: hmi_gfx_mgr02_get_block

-- Test Case: block_not_found
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_get_block
TEST.NEW
TEST.NAME:block_not_found
TEST.NOTES:
Search for block with addr NULL
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock[0].nextBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock[0].nextBlock[0].nextBlock:<<null>>
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.p_addr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.p_addr>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.p_heap
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.p_heap>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.return
{{ <<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.return>> == ( NULL ) }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Test Case: get_block_success
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_get_block
TEST.NEW
TEST.NAME:get_block_success
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock[0].nextBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock[0].nextBlock[0].nextBlock:<<null>>
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.p_addr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.p_addr>> = ( (void*)((UINT32)l_heap_info_S[0].startBlock->nextBlock + sizeof(GFX_MGR02_BLOCK_INFO_T)) );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.p_heap
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.p_heap>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.return
{{ <<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_get_block.return>> == ( l_heap_info_S[0].startBlock->nextBlock ) }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_mem_mgmt_create_heap

-- Test Case: heap_create_success
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_create_heap
TEST.NEW
TEST.NAME:heap_create_success
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_hdlmem:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_size:0x2000
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x2000
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalAllocatedMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalUntrackedMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:1
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numAllocatedBlocks:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_baseAddress
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_baseAddress>> = ( (UINT32)l_heap_info_S[0].startBlock );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_hdlmem.p_hdlmem[0]
{{ <<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_hdlmem>>[0] == ( &l_heap_info_S[0] ) }}
TEST.END_EXPECTED_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].startBlock
{{ <<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock == ( l_heap_info_S[0].startBlock ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].baseAddress
{{ <<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress == ( (UINT32)l_heap_info_S[0].startBlock ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: heap_handle_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_create_heap
TEST.NEW
TEST.NAME:heap_handle_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_hdlmem:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_size:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_baseAddress:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalAllocatedMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalUntrackedMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numAllocatedBlocks:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].baseAddress:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.END

-- Test Case: invalid_heap_size
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_create_heap
TEST.NEW
TEST.NAME:invalid_heap_size
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_hdlmem:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_size:0x0
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_baseAddress:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalAllocatedMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalUntrackedMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numAllocatedBlocks:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].baseAddress:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.END

-- Test Case: max_heap_created
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_create_heap
TEST.NEW
TEST.NAME:max_heap_created
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_num_heap_created:GFX_MGR02_MAX_HEAPS
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_size:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_baseAddress:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalAllocatedMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalBlockInfoMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalUntrackedMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numAllocatedBlocks:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].baseAddress:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.return:GFX_MM_ERR_MAX_HEAP_CREATED
TEST.END

-- Test Case: null_base_address
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_create_heap
TEST.NEW
TEST.NAME:null_base_address
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_hdlmem:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_size:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.p_baseAddress:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x2000
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalAllocatedMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalUntrackedMem:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:1
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numAllocatedBlocks:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].baseAddress:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_create_heap.return:GFX_MM_ERR_INVALID_MEMORY
TEST.EXPECTED_GLOBALS_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].startBlock
{{ <<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock == ( NULL) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_mem_mgmt_destroy_heap

-- Test Case: destroy_heap_success
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_destroy_heap
TEST.NEW
TEST.NAME:destroy_heap_success
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_num_heap_created:1
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_destroy_heap.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_destroy_heap.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_destroy_heap.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: heap_handle_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_destroy_heap
TEST.NEW
TEST.NAME:heap_handle_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_destroy_heap.p_hdlmem:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_destroy_heap.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.END

-- Test Case: no_heap_to_destroy
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_destroy_heap
TEST.NEW
TEST.NAME:no_heap_to_destroy
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_destroy_heap.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_destroy_heap.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_destroy_heap.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_mem_mgmt_get_free

-- Test Case: get_free_success
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_get_free
TEST.NEW
TEST.NAME:get_free_success
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_size:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_size[0]:0x2000
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: heap_handle_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_get_free
TEST.NEW
TEST.NAME:heap_handle_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_hdlmem:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_size:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_size[0]:0x0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.END

-- Test Case: size_ptr_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_get_free
TEST.NEW
TEST.NAME:size_ptr_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_size:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.ATTRIBUTES:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_size[0]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_mem_mgmt_get_largest

-- Test Case: get_largest_success
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_get_largest
TEST.NEW
TEST.NAME:get_largest_success
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].nextFreeBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].nextFreeBlock[0].nextFreeBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].nextFreeBlock[0].size:60
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].size:40
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].size:100
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_size:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_size[0]:76
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: heap_handle_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_get_largest
TEST.NEW
TEST.NAME:heap_handle_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].nextFreeBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].nextFreeBlock[0].nextFreeBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].nextFreeBlock[0].size:60
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].size:40
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].size:100
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_hdlmem:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_size:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_size:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.END

-- Test Case: size_ptr_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_get_largest
TEST.NEW
TEST.NAME:size_ptr_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].nextFreeBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].nextFreeBlock[0].nextFreeBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].nextFreeBlock[0].size:60
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].nextFreeBlock[0].size:40
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].size:100
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_size:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_size:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_largest.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_mem_mgmt_get_size

-- Test Case: get_size_success
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_get_size
TEST.NEW
TEST.NAME:get_size_success
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_size:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_size[0]:0x2000
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: heap_handle_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_get_size
TEST.NEW
TEST.NAME:heap_handle_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_hdlmem:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_size:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.ATTRIBUTES:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_size[0]:EXPECTED_BASE=16
TEST.END

-- Test Case: size_ptr_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_get_size
TEST.NEW
TEST.NAME:size_ptr_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_size:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.ATTRIBUTES:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_size[0]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_get_size.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_mem_mgmt_heap_alloc

-- Test Case: addr_ptr_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:addr_ptr_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:64
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_aligned
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_aligned
TEST.NOTES:
Allocation is Successful.
First block in Free list can fit required memory size
Payload address is aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)(aligned_addr - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_aligned_exact_fit
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_aligned_exact_fit
TEST.NOTES:
Allocation is Successful.
First block in Free list can exactly fit required memory size with no new free block created.
Payload address is aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:996
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)(aligned_addr - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_alignment_0
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_alignment_0
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:0
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)(aligned_addr - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_alignment_1
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_alignment_1
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:1
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)(aligned_addr - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_alignment_2
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_alignment_2
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:2
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)(aligned_addr - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned
TEST.NOTES:
Allocation is Successful.
First block in Free list can fit required memory size
Payload address is aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
#include <stdint.h>

void* block_addr = malloc(1024);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = (block_addr);
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned.001
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned.001
TEST.NOTES:
Allocation is Successful.
First block in Free list can fit required memory size
Payload address is aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char * l_heap_pool = malloc(1024);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = (&l_heap_pool[0]);
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = (&l_heap_pool[0]);
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = (&l_heap_pool[124]);
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = (&l_heap_pool[224]);
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;



TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned.002
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned.002
TEST.NOTES:
Allocation is Successful.
First block in Free list can fit required memory size
Payload address is aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char * l_heap_pool = malloc(1024);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = (&l_heap_pool[0]);
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = (&l_heap_pool[0]);
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalFreeMem = 50;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = (&l_heap_pool[124]);
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = (&l_heap_pool[224]);
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;



TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned_exact_fit
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned_exact_fit
TEST.NOTES:
Allocation is Successful.
First block in Free list can fit required memory size with exact fit
Block+Header is not aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:940
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)((aligned_addr - 4) - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned_exact_fit.001
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned_exact_fit.001
TEST.NOTES:
Allocation is Successful.
First block in Free list can fit required memory size with exact fit
Block+Header is not aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:940
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)((aligned_addr - 4) - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = NULL;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned_exact_fit_merge
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned_exact_fit_merge
TEST.NOTES:
Allocation is Successful.
First block in Free list can fit required memory size
Block+Header is not aligned as per requirement
Previous block in block list is also free, so merge with remainder block
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:950
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)(aligned_addr - 4 - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock->isUsed = 0;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned_exact_fit_merge.001
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned_exact_fit_merge.001
TEST.NOTES:
Allocation is Successful.
First block in Free list can fit required memory size
Block+Header is not aligned as per requirement
Previous block in block list is also free, so merge with remainder block
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:0
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:950
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)(aligned_addr - 4 - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock->isUsed = 0;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned_exact_fit_second_block
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned_exact_fit_second_block
TEST.NOTES:
Allocation is Successful.
Second block in the Free list can fit required memory size with exact fit
Block+header is not aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:940
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover.freeBlockRover[0].nextFreeBlock
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)((aligned_addr - 4) - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover[0].nextFreeBlock = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned_first_free_block.002
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned_first_free_block.002
TEST.NOTES:
Allocation should be Successful.
First block in the Free list can fit required memory size with extra memory available
Block+Header is not aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover.freeBlockRover[0].nextFreeBlock
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)((aligned_addr - 4) - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned_second_block
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned_second_block
TEST.NOTES:
Allocation is Successful.
Second block in the Free list can fit required memory size with extra memory available
Block+Header is not aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover.freeBlockRover[0].nextFreeBlock
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)((aligned_addr - 4) - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = NULL;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover[0].nextFreeBlock = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: alloc_heap_success_unalligned_second_block.001
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:alloc_heap_success_unalligned_second_block.001
TEST.NOTES:
Allocation is Successful.
Second block in the Free list can fit required memory size with extra memory available
Block+Header is not aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover.freeBlockRover[0].nextFreeBlock
#include <stdint.h>

#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)((aligned_addr - 4) - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = NULL;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover[0].nextFreeBlock = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: empty_free_list
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:empty_free_list
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:16
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_MM_ERR_NO_MEMORY
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: heap_alloc.001
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:heap_alloc.001
TEST.NOTES:
Allocation is Successful.
First block in Free list with aligned address cannot fit required memory
Second block in Free list can fit required memory size with excess memory available
Payload address is aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:0
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p; 
unsigned char * x;
unsigned char * aligned_addr;
void* block1_addr;
void* block2_addr;

//first block in free list
p = malloc(40 + align - 1 + header);
x = (unsigned char *)p + header;
aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
block1_addr = (void*)(aligned_addr - header);

//second block in free list
p = malloc(1024 + align - 1 + header);
x = (unsigned char *)p + header;
aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
block2_addr = (void*)(aligned_addr - header);

((GFX_MGR02_BLOCK_INFO_T*)block2_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block2_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block2_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block2_addr)->prevFreeBlock = block1_addr;
((GFX_MGR02_BLOCK_INFO_T*)block2_addr)->nextFreeBlock = malloc(24);

((GFX_MGR02_BLOCK_INFO_T*)block1_addr)->size = 40;
((GFX_MGR02_BLOCK_INFO_T*)block1_addr)->prevFreeBlock = 0;
((GFX_MGR02_BLOCK_INFO_T*)block1_addr)->nextFreeBlock = block2_addr;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = ( block1_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: heap_alloc.002
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:heap_alloc.002
TEST.NOTES:
Allocation should be Successful.
Second block in Free list can fit required memory size with excess memory available.
Payload address is aligned as per requirement.
Selected block is the last block in the complete block list and free block list

TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].size:40
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover.freeBlockRover[0].nextFreeBlock
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)(aligned_addr - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = NULL;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover[0].nextFreeBlock = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: heap_alloc.003
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:heap_alloc.003
TEST.NOTES:
Allocation is Successful.
Second block in Free list can fit required memory size with excess memory available
Payload address is aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover[0].size:40
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:10
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover.freeBlockRover[0].nextFreeBlock
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)(aligned_addr - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = malloc(24);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover[0].nextFreeBlock = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: heap_alloc.004
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:heap_alloc.004
TEST.NOTES:
Allocation should be Successful.
Second block in Free list can exactly fit required memory size with no new free block created.
Payload address is aligned as per requirement
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].totalFreeMem:1000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].numFreeBlocks:0
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:996
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S.l_heap_info_S[0].freeBlockRover.freeBlockRover[0].nextFreeBlock
#include <stdint.h>

uint32_t header = sizeof(GFX_MGR02_BLOCK_INFO_T);
uint32_t align = 32;
void* p = malloc(1024 + align - 1 + header);
unsigned char * x = (unsigned char *)p + header;
unsigned char * aligned_addr = (unsigned char *)(((size_t)x + (align - 1)) & ~(size_t)(align - 1));
void* block_addr = (void*)(aligned_addr - header);

((GFX_MGR02_BLOCK_INFO_T*)block_addr)->size = 1024;
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->prevFreeBlock = malloc(24);
((GFX_MGR02_BLOCK_INFO_T*)block_addr)->nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover[0].nextFreeBlock = ( block_addr );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: heap_handle_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:heap_handle_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:64
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.END

-- Test Case: zero_size_allocation
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.NEW
TEST.NAME:zero_size_allocation
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].freeBlockRover:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:0
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_mem_mgmt_heap_free

-- Test Case: addr_ptr_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:addr_ptr_null
TEST.NOTES:
NULL pointer free
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_MM_ERR_INVALID_MEMORY
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: block_not_found
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:block_not_found
TEST.NOTES:
Block not found for passed addr

TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock[0].nextBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].baseAddress:0x6000
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_MM_ERR_INVALID_MEMORY
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( 0x7000 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: double_free
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:double_free
TEST.NOTES:
Double free action on first block in the list

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_MM_ERR_INVALID_MEMORY
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_both_ends
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_both_ends
TEST.NOTES:
Free action successful.
Previous block and Next block are free, so merge with both block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[61] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock = &l_heap_pool[248];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].prevFreeBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextFreeBlock = &l_heap_pool[512];

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + 124 + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_both_ends.001
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_both_ends.001
TEST.NOTES:
Free action successful.
Previous block and Next block are free, so merge with both block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[61] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = &l_heap_pool[124];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock = &l_heap_pool[248];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextBlock = &l_heap_pool[300];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].prevFreeBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextFreeBlock = &l_heap_pool[512];

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + 124 + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_both_ends.002
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_both_ends.002
TEST.NOTES:
Free action successful.
Previous block and Next block are free, so merge with both block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[61] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = &l_heap_pool[124];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock = &l_heap_pool[248];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextBlock = &l_heap_pool[300];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].prevFreeBlock = &l_heap_pool[500];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + 124 + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_both_ends.003
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_both_ends.003
TEST.NOTES:
Free action successful.
Previous block and Next block are free, so merge with both block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[61] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock = &l_heap_pool[248];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextBlock = &l_heap_pool[300];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].prevFreeBlock = &l_heap_pool[448];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + 124 + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_both_ends.004
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_both_ends.004
TEST.NOTES:
Free action successful.
Previous block and Next block are free, so merge with both block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[61] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalBlockInfoMem = 48;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].numFreeBlocks = 3;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock = &l_heap_pool[248];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextBlock = &l_heap_pool[300];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].prevFreeBlock = &l_heap_pool[448];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + 124 + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_both_ends.005
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_both_ends.005
TEST.NOTES:
Free action successful.
Previous block and Next block are free, so merge with both block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[61] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].numFreeBlocks = 3;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock = &l_heap_pool[248];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextBlock = &l_heap_pool[300];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].prevFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + 124 + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_both_ends.006
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_both_ends.006
TEST.NOTES:
Free action successful.
Previous block and Next block are free, so merge with both block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[61] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalBlockInfoMem = 240;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].numFreeBlocks = 3;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].numAllocatedBlocks = 7;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = &l_heap_pool[248];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock = &l_heap_pool[248];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextBlock = &l_heap_pool[300];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].prevFreeBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].nextFreeBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + 124 + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_next
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_next
TEST.NOTES:
Free action successful.
Next block is free, so merge with next block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[30] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevFreeBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextFreeBlock = &l_heap_pool[512];

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_next.001
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_next.001
TEST.NOTES:
Free action successful.
Next block is free, so merge with next block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[30] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_prev
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_prev
TEST.NOTES:
Free action successful.
Previous block is free, so merge with previous block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[61] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = &l_heap_pool[512];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].isUsed = 1;

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + 124 + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_merge_prev.001
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_merge_prev.001
TEST.NOTES:
Free action successful.
Previous block is free, so merge with previous block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[61] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].numAllocatedBlocks = 4;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].numFreeBlocks = 4;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 0;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevFreeBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextFreeBlock = &l_heap_pool[512];

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextBlock[0].isUsed = 1;

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + 124 + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_succcess.003
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_succcess.003
TEST.NOTES:
Free action successful.
Next block is free, so merge with next block.

TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[30] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = NULL;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].prevBlock = NULL;

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_success
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_success
TEST.NOTES:
Freeing First block successfully.
Next block is allocated, so no merging.
TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[30] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = &l_heap_pool[0];


<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevFreeBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextFreeBlock = &l_heap_pool[512];

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_success.001
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_success.001
TEST.NOTES:
Freeing First block successfully.
Next block is allocated, so no merging.
TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[30] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 90;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = &l_heap_pool[0];


<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevFreeBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextFreeBlock = &l_heap_pool[512];

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_success.002
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_success.002
TEST.NOTES:
Freeing First block successfully.
Next block is allocated, so no merging.
TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[30] = 0xAFFEAFFE;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 90;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].numAllocatedBlocks = 2;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].freeBlockRover = &l_heap_pool[0];


<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 124;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevFreeBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextFreeBlock = &l_heap_pool[512];

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_success_check_failed_err
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:free_success_check_failed_err
TEST.NOTES:
Freeing First block successfully.
Next block is allocated, so no merging.
Memory check failed as memory is overwritten beyond its allocated boundary
TEST.END_NOTES:
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_MM_ERR_CHECK_FAILED
TEST.VALUE_USER_CODE:<<testcase>>
unsigned char *l_heap_pool = malloc(1024);

((unsigned int *)l_heap_pool)[30] = 0xFFFFFFFF;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].baseAddress = (UINT32)l_heap_pool;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].size = 1024;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].totalAllocatedMem = 150;

<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock = &l_heap_pool[0];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].size = 23;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock = &l_heap_pool[124];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].isUsed = 1;
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].prevFreeBlock = &l_heap_pool[248];
<<hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S>>[0].startBlock[0].nextBlock[0].nextFreeBlock = &l_heap_pool[512];

<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( (l_heap_pool + sizeof(GFX_MGR02_BLOCK_INFO_T)));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: heap_handle_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:heap_handle_null
TEST.NOTES:
Heap Handle is NULL
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_MM_ERR_INVALID_PARAMETER
TEST.END

-- Test Case: unmanaged_addr
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:unmanaged_addr
TEST.NOTES:
Unmanaged address

TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].baseAddress:0x6000
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_MM_ERR_INVALID_MEMORY
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( 0x8001 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: unmanaged_addr.001
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.NEW
TEST.NAME:unmanaged_addr.001
TEST.NOTES:
Unmanaged address

TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].size:0x2000
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].baseAddress:0x6000
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_MM_ERR_INVALID_MEMORY
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.p_addr>> = ( 0x5001 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_mem_mgmt_heap_realloc

-- Test Case: already_free_block_reallocation
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_realloc
TEST.NEW
TEST.NAME:already_free_block_reallocation
TEST.NOTES:
Block requested for reallocation is present in the block list but is already free

TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].isUsed:0
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr[0]:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.return:GFX_MM_ERR_INVALID_MEMORY
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr>> = ( (unsigned char*)(l_heap_info_S[0].startBlock) + sizeof(GFX_MGR02_BLOCK_INFO_T) );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: free_failed
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_realloc
TEST.NEW
TEST.NAME:free_failed
TEST.NOTES:
Block requested for reallocation is present in the block list but is already free

TEST.END_NOTES:
TEST.STUB:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.STUB:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].size:48
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].isUsed:1
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr[0]:0
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_MM_ERR_CHECK_FAILED
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_size:30
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:30
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr[0]:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.return:GFX_MM_ERR_CHECK_FAILED
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr>> = ( (unsigned char*)(l_heap_info_S[0].startBlock) + sizeof(GFX_MGR02_BLOCK_INFO_T) );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: invalid_block_reallocation
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_realloc
TEST.NEW
TEST.NAME:invalid_block_reallocation
TEST.NOTES:
Block requested for reallocation is not present in the block list.
TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr[0]:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.return:GFX_MM_ERR_INVALID_MEMORY
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: reallocated_addr_is_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_realloc
TEST.NEW
TEST.NAME:reallocated_addr_is_null
TEST.NOTES:
Block requested for reallocation is present in the block list.
Reallocated addr is null

TEST.END_NOTES:
TEST.STUB:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.STUB:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].size:48
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].isUsed:1
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr[0]:0
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_size:30
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:30
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr[0]:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr>> = ( (unsigned char*)(l_heap_info_S[0].startBlock) + sizeof(GFX_MGR02_BLOCK_INFO_T) );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: reallocation_failed
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_realloc
TEST.NEW
TEST.NAME:reallocation_failed
TEST.NOTES:
Block requested for reallocation is present in the block list.
Reallocation failed

TEST.END_NOTES:
TEST.STUB:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.STUB:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].size:48
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].isUsed:1
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_MM_ERR_NO_MEMORY
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_size:30
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:30
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr[0]:0
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.return:GFX_MM_ERR_NO_MEMORY
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr>> = ( (unsigned char*)(l_heap_info_S[0].startBlock) + sizeof(GFX_MGR02_BLOCK_INFO_T) );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: reallocation_success_less
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_realloc
TEST.NEW
TEST.NAME:reallocation_success_less
TEST.NOTES:
Block requested for reallocation is present in the block list.
Reallocation for more size is successfully done

TEST.END_NOTES:
TEST.STUB:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.STUB:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].size:48
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].isUsed:1
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_size:15
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:15
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.return:GFX_OK
TEST.STUB_VAL_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr.p_addr[0]
void* l_allocated_addr = malloc(15);
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr>>[0] = ( (unsigned long)l_allocated_addr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr>> = ( (unsigned char*)(l_heap_info_S[0].startBlock) + sizeof(GFX_MGR02_BLOCK_INFO_T) );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: reallocation_success_more
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_realloc
TEST.NEW
TEST.NAME:reallocation_success_more
TEST.NOTES:
Block requested for reallocation is present in the block list.
Reallocation for more size is successfully done

TEST.END_NOTES:
TEST.STUB:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc
TEST.STUB:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].size:48
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].isUsed:1
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.return:GFX_OK
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_free.return:GFX_OK
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_size:30
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_alignment:32
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_size:30
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_alignment:32
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.return:GFX_OK
TEST.STUB_VAL_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr.p_addr[0]
void* l_allocated_addr = malloc(30);
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_alloc.p_addr>>[0] = ( (unsigned long)l_allocated_addr );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr>> = ( (unsigned char*)(l_heap_info_S[0].startBlock) + sizeof(GFX_MGR02_BLOCK_INFO_T) );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: same_size_reallocation
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_mem_mgmt_heap_realloc
TEST.NEW
TEST.NAME:same_size_reallocation
TEST.NOTES:
Block requested for reallocation is present in the block list but is already free

TEST.END_NOTES:
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].nextBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].size:48
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.<<GLOBAL>>.l_heap_info_S[0].startBlock[0].isUsed:1
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_size:20
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.return:GFX_OK
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_hdlmem>> = ( &l_heap_info_S[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr
<<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_oldaddr>> = ( (unsigned char*)(l_heap_info_S[0].startBlock) + sizeof(GFX_MGR02_BLOCK_INFO_T) );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_USER_CODE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr.p_newaddr[0]
{{ <<hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_mem_mgmt_heap_realloc.p_newaddr>>[0] == ( (unsigned long)((unsigned char*)(l_heap_info_S[0].startBlock) + sizeof(GFX_MGR02_BLOCK_INFO_T)) ) }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Subprogram: hmi_gfx_mgr02_remove_from_free_list

-- Test Case: prev_free_block_null
TEST.UNIT:hmi_gfx_mgr02_mem_mgmt
TEST.SUBPROGRAM:hmi_gfx_mgr02_remove_from_free_list
TEST.NEW
TEST.NAME:prev_free_block_null
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_remove_from_free_list.p_block:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_remove_from_free_list.p_block[0].nextFreeBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_remove_from_free_list.p_block[0].prevFreeBlock:<<null>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_remove_from_free_list.p_heap:<<malloc 1>>
TEST.VALUE:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_remove_from_free_list.p_heap[0].freeBlockRover:<<malloc 1>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_remove_from_free_list.p_block[0].nextFreeBlock:<<null>>
TEST.EXPECTED:hmi_gfx_mgr02_mem_mgmt.hmi_gfx_mgr02_remove_from_free_list.p_block[0].prevFreeBlock:<<null>>
TEST.END
