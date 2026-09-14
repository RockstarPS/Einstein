-- VectorCAST 20.sp7 (04/21/21)
-- Test Case Script
-- 
-- Environment    : UTP_DIO_RM
-- Unit(s) Under Test: CDio_HwIf CDio_HwInit CDio_RM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CDio_HwIf

-- Subprogram: dio_get_dir

-- Test Case: GET_DIR_CLEAR_BIT_STATUS_FAILURE
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_get_dir
TEST.NEW
TEST.NAME:GET_DIR_CLEAR_BIT_STATUS_FAILURE
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_set_bit_hwif:1
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_clear_bit_hwif:0
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p[0].bank_num_U32:0
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].physical_addr:0
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].bank_mask_addr:0
TEST.VALUE:uut_prototype_stubs.in32.return:40
TEST.EXPECTED:CDio_HwIf.dio_get_dir.return:0
TEST.END

-- Test Case: GET_DIR_CLEAR_BIT_STATUS_SUCCESS
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_get_dir
TEST.NEW
TEST.NAME:GET_DIR_CLEAR_BIT_STATUS_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p[0].bank_num_U32:0
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].physical_addr:0
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].bank_mask_addr:0
TEST.VALUE:uut_prototype_stubs.in32.return:40
TEST.EXPECTED:CDio_HwIf.dio_get_dir.return:0
TEST.END

-- Test Case: GET_DIR_SET_BIT_STATUS_SUCCESS
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_get_dir
TEST.NEW
TEST.NAME:GET_DIR_SET_BIT_STATUS_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p[0].bank_num_U32:0
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].physical_addr:0
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].bank_mask_addr:0
TEST.VALUE:uut_prototype_stubs.in32.return:1
TEST.EXPECTED:CDio_HwIf.dio_get_dir.return:1
TEST.END

-- Test Case: GET_DIR_SET_BIT_STATUS_SUCCESS1
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_get_dir
TEST.NEW
TEST.NAME:GET_DIR_SET_BIT_STATUS_SUCCESS1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_set_bit_hwif:2
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_clear_bit_hwif:1
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p[0].bank_num_U32:0
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].physical_addr:0
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].bank_mask_addr:0
TEST.VALUE:uut_prototype_stubs.in32.return:1
TEST.EXPECTED:CDio_HwIf.dio_get_dir.return:0
TEST.END

-- Subprogram: dio_periodic_task

-- Test Case: dio_periodic_task_direction_data_corrupted_success4
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_periodic_task
TEST.NEW
TEST.NAME:dio_periodic_task_direction_data_corrupted_success4
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_get_dir
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_get_dir.return:2
TEST.VALUE:CDio_HwIf.dio_read_channel.return:0
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.EXPECTED:CDio_HwIf.dio_periodic_task.return:0
TEST.END

-- Test Case: dio_periodic_task_pin_exported_success2
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_periodic_task
TEST.NEW
TEST.NAME:dio_periodic_task_pin_exported_success2
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p[0].dio_pin_sa[1].bank_num_U32:22
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.EXPECTED:CDio_HwIf.dio_periodic_task.return:0
TEST.END

-- Test Case: dio_periodic_task_pin_unexported_success1
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_periodic_task
TEST.NEW
TEST.NAME:dio_periodic_task_pin_unexported_success1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p[0].dio_pin_sa[1].is_valid_BOOL:false
TEST.EXPECTED:CDio_HwIf.dio_periodic_task.return:0
TEST.END

-- Test Case: dio_periodic_task_value_data_corrupted_success3
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_periodic_task
TEST.NEW
TEST.NAME:dio_periodic_task_value_data_corrupted_success3
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.return:2
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.EXPECTED:CDio_HwIf.dio_periodic_task.return:0
TEST.END

-- Test Case: dio_periodic_task_value_data_corrupted_success3.001
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_periodic_task
TEST.NEW
TEST.NAME:dio_periodic_task_value_data_corrupted_success3.001
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_get_dir
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_dio_bank_config_data_as[0].direction:0xFFFFFFFF
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_dio_bank_config_data_as[1].direction:0xFFFFFFFF
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_dio_bank_config_data_as[2].direction:0xFFFFFFFF
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_dio_bank_config_data_as[3].direction:0xFFFFFFFF
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_dio_bank_config_data_as[4].direction:0xFFFFFFFF
TEST.VALUE:CDio_HwIf.dio_get_dir.return:1
TEST.VALUE:CDio_HwIf.dio_read_channel.return:2
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwIf.dio_periodic_task.dioTimerTaskPinData_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.EXPECTED:CDio_HwIf.dio_periodic_task.return:0
TEST.END

-- Subprogram: dio_read_channel

-- Test Case: dio_read_channel_0_SUCCESS
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_read_channel
TEST.NEW
TEST.NAME:dio_read_channel_0_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_read_channel.dioReadChnlDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_read_channel.dioReadChnlAddr_p:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.in32.return:0
TEST.EXPECTED:CDio_HwIf.dio_read_channel.return:0
TEST.END

-- Test Case: dio_read_channel_1_SUCCESS
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_read_channel
TEST.NEW
TEST.NAME:dio_read_channel_1_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_read_channel.dioReadChnlDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_read_channel.dioReadChnlAddr_p:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.in32.return:1
TEST.EXPECTED:CDio_HwIf.dio_read_channel.return:1
TEST.END

-- Test Case: dio_read_channel_1_SUCESS1
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_read_channel
TEST.NEW
TEST.NAME:dio_read_channel_1_SUCESS1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_set_bit_hwif:2
TEST.VALUE:CDio_HwIf.<<GLOBAL>>.g_clear_bit_hwif:1
TEST.VALUE:CDio_HwIf.dio_read_channel.dioReadChnlDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_read_channel.dioReadChnlAddr_p:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.in32.return:1
TEST.EXPECTED:CDio_HwIf.dio_read_channel.return:0
TEST.END

-- Subprogram: dio_set_default_data

-- Test Case: dio_set_default_data.fail
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_set_default_data
TEST.NEW
TEST.NAME:dio_set_default_data.fail
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_set_default_data.dioWriteDevdefault_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_set_default_data.dioWriteDevdefault_p[0].dio_addr_sa[5].virtual_addr_dir:0
TEST.VALUE:uut_prototype_stubs.in32.return:(2)0
TEST.EXPECTED:CDio_HwIf.<<GLOBAL>>.g_dio_bank_config_data_as[5].direction:0
TEST.END

-- Test Case: dio_set_default_data_condition_0_0.pass.
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_set_default_data
TEST.NEW
TEST.NAME:dio_set_default_data_condition_0_0.pass.
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_set_default_data.dioWriteDevdefault_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_set_default_data.dioWriteDevdefault_p[0].dio_addr_sa[5].virtual_addr_dir:1
TEST.VALUE:uut_prototype_stubs.in32.return:(2)0
TEST.EXPECTED:CDio_HwIf.<<GLOBAL>>.g_dio_bank_config_data_as[5].direction:0
TEST.END

-- Test Case: dio_set_default_data_condition_1_1.pass
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_set_default_data
TEST.NEW
TEST.NAME:dio_set_default_data_condition_1_1.pass
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_set_default_data.dioWriteDevdefault_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_set_default_data.dioWriteDevdefault_p[0].dio_addr_sa[5].virtual_addr_dir:1
TEST.VALUE:uut_prototype_stubs.in32.return:(2)1
TEST.EXPECTED:CDio_HwIf.<<GLOBAL>>.g_dio_bank_config_data_as[5].direction:1
TEST.END

-- Subprogram: dio_set_dir

-- Test Case: SET_DIR_0_success1
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_set_dir
TEST.NEW
TEST.NAME:SET_DIR_0_success1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirAddr_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_set_dir.dir_UINT32:0
TEST.VALUE:uut_prototype_stubs.in32.return:0
TEST.EXPECTED:CDio_HwIf.dio_set_dir.return:1
TEST.END

-- Test Case: SET_DIR_0_success1.001
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_set_dir
TEST.NEW
TEST.NAME:SET_DIR_0_success1.001
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p[0].bank_num_U32:10
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirAddr_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_set_dir.dir_UINT32:1
TEST.VALUE:uut_prototype_stubs.in32.return:0
TEST.EXPECTED:CDio_HwIf.dio_set_dir.return:1
TEST.END

-- Test Case: SET_DIR_INVALID_fail1
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_set_dir
TEST.NEW
TEST.NAME:SET_DIR_INVALID_fail1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p[0].bank_num_U32:0
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirAddr_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirAddr_p[0].physical_addr:0
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirAddr_p[0].bank_mask_addr:0
TEST.VALUE:CDio_HwIf.dio_set_dir.dir_UINT32:2
TEST.VALUE:uut_prototype_stubs.in32.return:1
TEST.EXPECTED:CDio_HwIf.dio_set_dir.return:-1
TEST.END

-- Subprogram: dio_write_channel

-- Test Case: dio_write_channel_0_success2
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_write_channel
TEST.NEW
TEST.NAME:dio_write_channel_0_success2
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_write_channel.dioWriteChnlDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_write_channel.dioWriteChnlAddr_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_write_channel.dioWriteChnlAddr_p[0].set_bits_count_sa:8
TEST.VALUE:CDio_HwIf.dio_write_channel.data_UINT32:0
TEST.EXPECTED:CDio_HwIf.dio_write_channel.return:1
TEST.END

-- Test Case: dio_write_channel_1_success1
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_write_channel
TEST.NEW
TEST.NAME:dio_write_channel_1_success1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_write_channel.dioWriteChnlDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_write_channel.dioWriteChnlDev_p[0].bank_num_U32:22
TEST.VALUE:CDio_HwIf.dio_write_channel.dioWriteChnlAddr_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_write_channel.dioWriteChnlAddr_p[0].set_bits_count_sa:8
TEST.VALUE:CDio_HwIf.dio_write_channel.data_UINT32:1
TEST.EXPECTED:CDio_HwIf.dio_write_channel.return:1
TEST.END

-- Test Case: dio_write_channel_invalid_data_fail1
TEST.UNIT:CDio_HwIf
TEST.SUBPROGRAM:dio_write_channel
TEST.NEW
TEST.NAME:dio_write_channel_invalid_data_fail1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_HwIf.dio_write_channel.dioWriteChnlDev_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_write_channel.dioWriteChnlAddr_p:<<malloc 1>>
TEST.VALUE:CDio_HwIf.dio_write_channel.dioWriteChnlAddr_p[0].set_bits_count_sa:8
TEST.VALUE:CDio_HwIf.dio_write_channel.data_UINT32:2
TEST.EXPECTED:CDio_HwIf.dio_write_channel.return:-1
TEST.END

-- Unit: CDio_HwInit

-- Subprogram: dio_hw_fini

-- Test Case: FINI_MUNMAP_DEVICE_IO_DATA_FAILS
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_fini
TEST.NEW
TEST.NAME:FINI_MUNMAP_DEVICE_IO_DATA_FAILS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.munmap_device_io.return:0,-1
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_fini.return:false
TEST.END

-- Test Case: FINI_MUNMAP_DEVICE_IO_DATA_SUCCESS
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_fini
TEST.NEW
TEST.NAME:FINI_MUNMAP_DEVICE_IO_DATA_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.munmap_device_io.return:(2)0
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_fini.return:true
TEST.END

-- Test Case: FINI_MUNMAP_DEVICE_IO_DIR_FAILS
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_fini
TEST.NEW
TEST.NAME:FINI_MUNMAP_DEVICE_IO_DIR_FAILS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.munmap_device_io.return:-1
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_fini.return:false
TEST.END

-- Test Case: FINI_MUNMAP_DEVICE_IO_DIR_SUCCESS
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_fini
TEST.NEW
TEST.NAME:FINI_MUNMAP_DEVICE_IO_DIR_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.munmap_device_io.return:0
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_fini.dioHWFinipindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_fini.return:true
TEST.END

-- Subprogram: dio_hw_init

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_EINVAL_FAIL
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_EINVAL_FAIL

TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:22
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = EINVAL;
{{ errno == EINVAL }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_ENOMEM_FAIL
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_ENOMEM_FAIL

TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:12
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENOMEM;
{{ errno == ENOMEM }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_ENOMEM_FAIL.001
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_ENOMEM_FAIL.001
TEST.STUB:CDio_Debug.__get_errno_ptr
TEST.VALUE:CDio_Debug.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:12
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENOMEM;
{{ errno == ENOMEM }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_ENXIO_FAIL
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_ENXIO_FAIL
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:6
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENXIO;
{{ errno == ENXIO }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_ENXIO_FAIL.001
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_ENXIO_FAIL.001
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:12
TEST.VALUE:uut_prototype_stubs.munmap_device_io.return:12
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENXIO;
{{ errno == ENXIO }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_FAIL
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:DIO_HW_INIT_MMAP_DEVICE_IO_DATA_address_FAIL
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = EINVAL;
{{ errno == EINVAL }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_DIR_address_EINVAL_FAIL
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:DIO_HW_INIT_MMAP_DEVICE_IO_DIR_address_EINVAL_FAIL

TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:22
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = EINVAL;
{{ errno == EINVAL }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_DIR_address_ENOMEM_FAIL
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:DIO_HW_INIT_MMAP_DEVICE_IO_DIR_address_ENOMEM_FAIL

TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:12
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENOMEM;
{{ errno == ENOMEM }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_DIR_address_ENXIO_FAIL
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:DIO_HW_INIT_MMAP_DEVICE_IO_DIR_address_ENXIO_FAIL

TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:6
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENXIO;
{{ errno == ENXIO }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_DIR_address_FAIL
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW

TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:-1
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:22
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = EINVAL;
{{ errno == EINVAL }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_HW_INIT_MMAP_DEVICE_IO_SUCCESS
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:DIO_HW_INIT_MMAP_DEVICE_IO_SUCCESS
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:0
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[0].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[1].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[2].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[3].set_bits_count_sa:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].physical_addr:0
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].virtual_addr_dir:1
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p[0].dio_addr_sa[4].set_bits_count_sa:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:true
TEST.VALUE_USER_CODE:<<testcase>>
errno = 0;
{{ errno == 0 }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: INIT_THREATCTL_FAIL
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:INIT_THREATCTL_FAIL
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:-1
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:1
TEST.EXPECTED:CDio_HwInit.dio_hw_init.return:false
TEST.END

-- Test Case: dio_hw_init.001
TEST.UNIT:CDio_HwInit
TEST.SUBPROGRAM:dio_hw_init
TEST.NEW
TEST.NAME:dio_hw_init.001
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:12
TEST.VALUE:CDio_HwInit.dio_hw_init.dioHWInitpindata_p:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_init.return:false
TEST.END

-- Unit: CDio_RM

-- Subprogram: VCAST_main

-- Test Case: 01_ret_dio_init_S32
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:01_ret_dio_init_S32
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_RM.VCAST_main.argc:0
TEST.EXPECTED:CDio_RM.VCAST_main.return:0
TEST.END

-- Test Case: 02__ret_dio_enable_logging_BOOL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:02__ret_dio_enable_logging_BOOL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_usage
TEST.STUB:CDio_RM.dio_init
TEST.STUB:CDio_RM.dio_fini
TEST.STUB:CDio_RM.dio_io_open
TEST.STUB:CDio_RM.dio_io_read
TEST.STUB:CDio_RM.dio_io_write
TEST.STUB:CDio_RM.dio_io_devctl
TEST.STUB:CDio_RM.dio_getopt_chk
TEST.STUB:CDio_RM.dio_options
TEST.STUB:CDio_RM.dio_ExitSignal
TEST.STUB:CDio_RM.dio_count_mask_bits
TEST.STUB:CDio_RM.dio_data_extract
TEST.STUB:CDio_RM.dio_periodic_read_check
TEST.STUB:CDio_RM.dio_attach_pulse
TEST.STUB:CDio_RM.dio_setup_timer
TEST.STUB:CDio_RM.dio_export
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:CDio_RM.VCAST_main.argc:1
TEST.VALUE:CDio_RM.VCAST_main.argv:<<malloc 1>>
TEST.VALUE:CDio_RM.VCAST_main.argv[0]:<<malloc 1>>
TEST.VALUE:CDio_RM.VCAST_main.argv[0][0]:'1'
TEST.VALUE:CDio_RM.VCAST_main.return:0
TEST.VALUE:CDio_RM.dio_init.return:0
TEST.EXPECTED:CDio_RM.VCAST_main.argc:1
TEST.EXPECTED:CDio_RM.VCAST_main.argv[0][0]:'1'
TEST.EXPECTED:CDio_RM.VCAST_main.return:1
TEST.END

-- Test Case: 03_procmgr_ability
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:03_procmgr_ability
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_options
TEST.STUB:CDio_RM.dio_count_mask_bits
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm[0]:'p'
TEST.VALUE:CDio_RM.VCAST_main.argc:0
TEST.VALUE:CDio_RM.dio_options.return:false
TEST.VALUE:CDio_RM.dio_count_mask_bits.return:false
TEST.EXPECTED:CDio_RM.VCAST_main.return:1
TEST.END

-- Test Case: 04_set_ids_from_arg
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:04_set_ids_from_arg
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwInit.dio_hw_init
TEST.STUB:CDio_RM.dio_init
TEST.STUB:CDio_RM.dio_fini
TEST.STUB:CDio_RM.dio_options
TEST.STUB:CDio_RM.dio_count_mask_bits
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:0
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:1
TEST.VALUE:CDio_HwInit.dio_hw_init.return:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm[0]:'A'
TEST.VALUE:CDio_RM.VCAST_main.argc:13
TEST.VALUE:CDio_RM.VCAST_main.argv:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.VCAST_main.argv[0]:"main"
TEST.VALUE:CDio_RM.VCAST_main.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.VCAST_main.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.VCAST_main.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.VCAST_main.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.VCAST_main.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.VCAST_main.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.VCAST_main.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.VCAST_main.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.VCAST_main.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.VCAST_main.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.VCAST_main.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.VCAST_main.argv[12]:<<malloc 14>>
TEST.VALUE:CDio_RM.VCAST_main.argv[12]:"-m0x00000FF7 "
TEST.VALUE:CDio_RM.dio_init.return:0
TEST.VALUE:CDio_RM.dio_fini.return:true
TEST.VALUE:CDio_RM.dio_options.return:true
TEST.VALUE:CDio_RM.dio_count_mask_bits.return:true
TEST.EXPECTED:CDio_RM.VCAST_main.return:1
TEST.END

-- Test Case: 04_set_ids_from_arg.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:04_set_ids_from_arg.001
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwInit.dio_hw_init
TEST.STUB:CDio_HwInit.dio_hw_fini
TEST.STUB:CDio_RM.dio_init
TEST.STUB:CDio_RM.dio_fini
TEST.STUB:CDio_RM.dio_options
TEST.STUB:CDio_RM.dio_count_mask_bits
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:22
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:0
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:1
TEST.VALUE:CDio_HwInit.dio_hw_init.return:true
TEST.VALUE:CDio_HwInit.dio_hw_fini.return:false
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm[0]:'0'
TEST.VALUE:CDio_RM.VCAST_main.argc:13
TEST.VALUE:CDio_RM.VCAST_main.argv:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.VCAST_main.argv[0]:"main"
TEST.VALUE:CDio_RM.VCAST_main.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.VCAST_main.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.VCAST_main.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.VCAST_main.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.VCAST_main.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.VCAST_main.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.VCAST_main.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.VCAST_main.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.VCAST_main.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.VCAST_main.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.VCAST_main.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.VCAST_main.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.VCAST_main.argv[12]:<<malloc 14>>
TEST.VALUE:CDio_RM.VCAST_main.argv[12]:"-m0x00000FF7 "
TEST.VALUE:CDio_RM.dio_init.return:0
TEST.VALUE:CDio_RM.dio_fini.return:false
TEST.VALUE:CDio_RM.dio_options.return:true
TEST.VALUE:CDio_RM.dio_count_mask_bits.return:true
TEST.EXPECTED:CDio_RM.VCAST_main.return:1
TEST.END

-- Test Case: 05_ret_dio_count_mask_bits_BOOL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:05_ret_dio_count_mask_bits_BOOL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_count_mask_bits
TEST.VALUE:uut_prototype_stubs.procmgr_ability.__pid:0
TEST.VALUE:uut_prototype_stubs.procmgr_ability.__ability:55
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm[0]:'p'
TEST.VALUE:CDio_RM.VCAST_main.argc:0
TEST.VALUE:CDio_RM.dio_count_mask_bits.return:false
TEST.EXPECTED:CDio_RM.VCAST_main.return:1
TEST.END

-- Test Case: 06_ret_dio_hw_init_BOOL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:06_ret_dio_hw_init_BOOL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwInit.dio_hw_init
TEST.STUB:CDio_RM.dio_init
TEST.VALUE:CDio_HwInit.dio_hw_init.return:false
TEST.VALUE:CDio_RM.VCAST_main.argc:0
TEST.EXPECTED:CDio_RM.VCAST_main.return:1
TEST.END

-- Test Case: 07_g_DIODone_true
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:07_g_DIODone_true
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_init
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_DIODone:false
TEST.VALUE:CDio_RM.VCAST_main.argc:0
TEST.VALUE:CDio_RM.dio_init.return:0
TEST.EXPECTED:CDio_RM.VCAST_main.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dispatch_block.return
g_DIODone=true;
<<uut_prototype_stubs.dispatch_block.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 07_g_ctp
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:07_g_ctp
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_init
TEST.VALUE:CDio_RM.VCAST_main.argc:0
TEST.VALUE:CDio_RM.dio_init.return:0
TEST.EXPECTED:CDio_RM.VCAST_main.return:1
TEST.END

-- Test Case: dispatch_return_S32_00.1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:dispatch_return_S32_00.1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_init
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_block.return[0].resmgr_context.rcvid:66
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_DIODone:true,false
TEST.VALUE:CDio_RM.VCAST_main.argc:0
TEST.VALUE:CDio_RM.dio_init.return:0
TEST.EXPECTED:CDio_RM.VCAST_main.return:0
TEST.END

-- Test Case: dispatch_return_S32_00.2
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:dispatch_return_S32_00.2
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_init
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_block.return[0].resmgr_context.rcvid:66
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_DIODone:false
TEST.VALUE:CDio_RM.VCAST_main.argc:0
TEST.VALUE:CDio_RM.dio_init.return:0
TEST.EXPECTED:CDio_RM.VCAST_main.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dispatch_handler.return
g_DIODone=true;
<<uut_prototype_stubs.dispatch_handler.return>> = ( 55 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: dio_ExitSignal

-- Test Case: dio_ExitSignal.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_ExitSignal
TEST.NEW
TEST.NAME:dio_ExitSignal.001
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_RM.dio_ExitSignal.signo:1
TEST.EXPECTED:CDio_RM.dio_ExitSignal.signo:1
TEST.END

-- Subprogram: dio_attach_pulse

-- Test Case: dio_attach_pulse_message_connect_fail2
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_attach_pulse
TEST.NEW
TEST.NAME:dio_attach_pulse_message_connect_fail2
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pulse_attach.return:0
TEST.VALUE:uut_prototype_stubs.message_connect.return:-1
TEST.VALUE:CDio_RM.dio_attach_pulse.dioPulseDev_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_attach_pulse.dioPulseDev_p[0].event.__sigev_un1.__sigev_coid:-1
TEST.VALUE:CDio_RM.dio_attach_pulse.dioPulseDev_p[0].event.__sigev_un2.__st.__sigev_code:0,-1
TEST.EXPECTED:CDio_RM.dio_attach_pulse.return:false
TEST.END

-- Test Case: dio_attach_pulse_pulse_attach_fail1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_attach_pulse
TEST.NEW
TEST.NAME:dio_attach_pulse_pulse_attach_fail1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pulse_attach.return:-1
TEST.VALUE:CDio_RM.dio_attach_pulse.dioPulseDev_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_attach_pulse.dioPulseDev_p[0].event.__sigev_un1.__sigev_coid:-1
TEST.VALUE:CDio_RM.dio_attach_pulse.dioPulseDev_p[0].event.__sigev_un2.__st.__sigev_code:-1
TEST.EXPECTED:CDio_RM.dio_attach_pulse.return:false
TEST.END

-- Test Case: dio_attach_pulse_success1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_attach_pulse
TEST.NEW
TEST.NAME:dio_attach_pulse_success1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.pulse_attach.return:0
TEST.VALUE:uut_prototype_stubs.message_connect.return:0
TEST.VALUE:CDio_RM.dio_attach_pulse.dioPulseDev_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_attach_pulse.dioPulseDev_p[0].event.__sigev_un1.__sigev_coid:1
TEST.VALUE:CDio_RM.dio_attach_pulse.dioPulseDev_p[0].event.__sigev_un2.__st.__sigev_code:(2)0
TEST.EXPECTED:CDio_RM.dio_attach_pulse.return:true
TEST.END

-- Subprogram: dio_count_mask_bits

-- Test Case: dio_count_mask_bits.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_count_mask_bits
TEST.NEW
TEST.NAME:dio_count_mask_bits.001
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_options
TEST.VALUE:CDio_RM.dio_options.return:true
TEST.VALUE:CDio_RM.dio_count_mask_bits.dioCountAaddr_p:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_count_mask_bits.dioCountAaddr_p[0].bank_mask_addr:6
TEST.VALUE:CDio_RM.dio_count_mask_bits.dioCountAaddr_p[0].set_bits_count_sa:6
TEST.EXPECTED:CDio_RM.dio_count_mask_bits.return:true
TEST.END

-- Subprogram: dio_data_extract

-- Test Case: DATA_EXTRACT_INVAIDPIN_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_data_extract
TEST.NEW
TEST.NAME:DATA_EXTRACT_INVAIDPIN_FAIL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_RM.dio_data_extract.pin_U32:257
TEST.EXPECTED:CDio_RM.dio_data_extract.return:false
TEST.END

-- Test Case: DATA_EXTRACT_INVALIDPIN_FAIL.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_data_extract
TEST.NEW
TEST.NAME:DATA_EXTRACT_INVALIDPIN_FAIL.001
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].bank_mask_addr:0x6
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].set_bits_count_sa:270
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[1].dio_addr_sa[1].bank_mask_addr:6
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[1].dio_addr_sa[1].set_bits_count_sa:270
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[2].dio_addr_sa[1].bank_mask_addr:6
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[2].dio_addr_sa[1].set_bits_count_sa:6
TEST.VALUE:CDio_RM.dio_data_extract.pin_U32:256
TEST.EXPECTED:CDio_RM.dio_data_extract.return:false
TEST.END

-- Test Case: DATA_EXTRACT_VALIDPIN_BANKNUM_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_data_extract
TEST.NEW
TEST.NAME:DATA_EXTRACT_VALIDPIN_BANKNUM_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].bank_mask_addr:1
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].set_bits_count_sa:6
TEST.EXPECTED:CDio_RM.dio_data_extract.return:true
TEST.END

-- Test Case: DATA_EXTRACT_VALIDPIN_BANKNUM_SUCCESS.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_data_extract
TEST.NEW
TEST.NAME:DATA_EXTRACT_VALIDPIN_BANKNUM_SUCCESS.001
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].bank_mask_addr:0xFFFFFFFF
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].set_bits_count_sa:32
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[1].dio_addr_sa[1].bank_mask_addr:6
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[1].dio_addr_sa[1].set_bits_count_sa:6
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[2].dio_addr_sa[1].bank_mask_addr:6
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[2].dio_addr_sa[1].set_bits_count_sa:6
TEST.EXPECTED:CDio_RM.dio_data_extract.return:true
TEST.END

-- Test Case: DATA_EXTRACT_VALIDPIN_BANKNUM_SUCCESS.002
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_data_extract
TEST.NEW
TEST.NAME:DATA_EXTRACT_VALIDPIN_BANKNUM_SUCCESS.002
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].bank_mask_addr:0xFFFFFFFF
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].set_bits_count_sa:32
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[1].dio_addr_sa[1].bank_mask_addr:6
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[1].dio_addr_sa[1].set_bits_count_sa:6
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[2].dio_addr_sa[1].bank_mask_addr:6
TEST.VALUE:CDio_RM.dio_data_extract.dioPinData_p[2].dio_addr_sa[1].set_bits_count_sa:6
TEST.VALUE:CDio_RM.dio_data_extract.pin_U32:257
TEST.EXPECTED:CDio_RM.dio_data_extract.return:false
TEST.END

-- Subprogram: dio_export

-- Test Case: dio_export_resmgr_attach_direction_fail1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_export
TEST.NEW
TEST.NAME:dio_export_resmgr_attach_direction_fail1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.dio_export.p_pin_S32:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_export.return:1
TEST.END

-- Test Case: dio_export_resmgr_attach_value_fail2
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_export
TEST.NEW
TEST.NAME:dio_export_resmgr_attach_value_fail2
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1,-1
TEST.VALUE:CDio_RM.dio_export.p_pin_S32:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_export.return:1
TEST.END

-- Test Case: dio_export_success1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_export
TEST.NEW
TEST.NAME:dio_export_success1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1,2
TEST.VALUE:CDio_RM.dio_export.p_pin_S32:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_export.return:0
TEST.END

-- Subprogram: dio_fini

-- Test Case: dio_fini_dio_hw_fini_fail1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_fini
TEST.NEW
TEST.NAME:dio_fini_dio_hw_fini_fail1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwInit.dio_hw_fini
TEST.VALUE:CDio_HwInit.dio_hw_fini.return:false
TEST.EXPECTED:CDio_RM.dio_fini.return:true
TEST.END

-- Test Case: dio_fini_dio_unexport_fail2
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_fini
TEST.NEW
TEST.NAME:dio_fini_dio_unexport_fail2
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwInit.dio_hw_fini
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:CDio_HwInit.dio_hw_fini.return:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_fini.return:false
TEST.END

-- Test Case: dio_fini_dispatch_context_free_NOT_NULL_success3
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_fini
TEST.NEW
TEST.NAME:dio_fini_dispatch_context_free_NOT_NULL_success3
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwInit.dio_hw_fini
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_destroy.return:1
TEST.VALUE:uut_prototype_stubs.dispatch_context_free.ctp[0].resmgr_context.msg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_context_free.ctp[0].resmgr_context.dpp:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_fini.return:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_fini.return:false
TEST.END

-- Test Case: dio_fini_dispatch_context_free_NULL_success2
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_fini
TEST.NEW
TEST.NAME:dio_fini_dispatch_context_free_NULL_success2
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwInit.dio_hw_fini
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:CDio_HwInit.dio_hw_fini.return:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_fini.return:false
TEST.END

-- Test Case: dio_fini_resgmr_detach_export_fail3
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_fini
TEST.NEW
TEST.NAME:dio_fini_resgmr_detach_export_fail3
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.resmgr_detach.return:-1
TEST.EXPECTED:CDio_RM.dio_fini.return:false
TEST.END

-- Test Case: dio_fini_resgmr_detach_unexport_fail4
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_fini
TEST.NEW
TEST.NAME:dio_fini_resgmr_detach_unexport_fail4
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.resmgr_detach.return:0,-1
TEST.EXPECTED:CDio_RM.dio_fini.return:false
TEST.END

-- Test Case: dio_fini_success1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_fini
TEST.NEW
TEST.NAME:dio_fini_success1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwInit.dio_hw_fini
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:CDio_HwInit.dio_hw_fini.return:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_unexport.return:0
TEST.EXPECTED:CDio_RM.dio_fini.return:true
TEST.END

-- Subprogram: dio_init

-- Test Case: dio_init_dio_attach_pulse_fail4
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_init
TEST.NEW
TEST.NAME:dio_init_dio_attach_pulse_fail4
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwInit.dio_hw_init
TEST.STUB:CDio_RM.dio_attach_pulse
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(2)0
TEST.VALUE:CDio_HwInit.dio_hw_init.return:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].virtual_addr_dir:1
TEST.VALUE:CDio_RM.dio_attach_pulse.return:false
TEST.EXPECTED:CDio_RM.dio_init.return:1
TEST.END

-- Test Case: dio_init_dio_setup_timer_fail5
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_init
TEST.NEW
TEST.NAME:dio_init_dio_setup_timer_fail5
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_attach_pulse
TEST.STUB:CDio_RM.dio_setup_timer
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(2)0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:-1
TEST.VALUE:CDio_RM.dio_attach_pulse.return:true
TEST.VALUE:CDio_RM.dio_setup_timer.return:false
TEST.EXPECTED:CDio_RM.dio_init.return:1
TEST.END

-- Test Case: dio_init_dispatch_create_fail1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_init
TEST.NEW
TEST.NAME:dio_init_dispatch_create_fail1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.EXPECTED:CDio_RM.dio_init.return:12
TEST.END

-- Test Case: dio_init_dispatch_create_fail1.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_init
TEST.NEW
TEST.NAME:dio_init_dispatch_create_fail1.001
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.EXPECTED:CDio_RM.dio_init.return:12
TEST.END

-- Test Case: dio_init_resmgr_attach_export_fail2
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_init
TEST.NEW
TEST.NAME:dio_init_resmgr_attach_export_fail2
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:-1
TEST.EXPECTED:CDio_RM.dio_init.return:1
TEST.END

-- Test Case: dio_init_resmgr_attach_unexport_fail3
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_init
TEST.NEW
TEST.NAME:dio_init_resmgr_attach_unexport_fail3
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:0,-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:-1
TEST.EXPECTED:CDio_RM.dio_init.return:1
TEST.END

-- Test Case: dio_init_success1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_init
TEST.NEW
TEST.NAME:dio_init_success1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_attach_pulse
TEST.STUB:CDio_RM.dio_setup_timer
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(2)0
TEST.VALUE:uut_prototype_stubs.procmgr_daemon.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:-1
TEST.VALUE:CDio_RM.dio_attach_pulse.return:true
TEST.VALUE:CDio_RM.dio_setup_timer.return:true
TEST.EXPECTED:CDio_RM.dio_init.return:0
TEST.END

-- Subprogram: dio_io_devctl

-- Test Case: DEFAULT_DEVCTL_CMD
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:DEFAULT_DEVCTL_CMD
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:CDio_HwIf.dio_set_dir.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:0
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_devctl.return:89
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:89
TEST.END

-- Test Case: GPIO_DIRECTION_IN_READ_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_DIRECTION_IN_READ_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_get_dir
TEST.VALUE:CDio_HwIf.dio_get_dir.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:3
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:-1
TEST.END

-- Test Case: GPIO_DIRECTION_OUT_READ_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_DIRECTION_OUT_READ_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_get_dir
TEST.VALUE:CDio_HwIf.dio_get_dir.return:1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:3
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:-1
TEST.END

-- Test Case: GPIO_DIRECTION_READ_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_DIRECTION_READ_FAIL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_get_dir
TEST.VALUE:CDio_HwIf.dio_get_dir.return:2
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].bank_num_U32:22
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:3
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:-1
TEST.END

-- Test Case: GPIO_DIRECTION_READ_INVALID_DIR_PATH_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_DIRECTION_READ_INVALID_DIR_PATH_FAIL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_get_dir
TEST.VALUE:CDio_HwIf.dio_get_dir.return:2
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:3
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:-1
TEST.END

-- Test Case: GPIO_DIRECTION_WRITE_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_DIRECTION_WRITE_FAIL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p[1].dir_pathID_S32:2
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p[1].bank_num_U32:22
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwIf.dio_set_dir.dir_UINT32:1
TEST.VALUE:CDio_HwIf.dio_set_dir.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.__msg[0].i.dcmd:4
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.__msg[0].i.nbytes:2
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].bank_num_U32:22
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].msg[0].devctl.i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:4
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_devctl.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.ocb[0].attr:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:22
TEST.END

-- Test Case: GPIO_DIRECTION_WRITE_FAIL_GET_ERRNO
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_DIRECTION_WRITE_FAIL_GET_ERRNO
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p[1].dir_pathID_S32:2
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p[1].is_valid_BOOL:true
TEST.VALUE:CDio_HwIf.dio_set_dir.dir_UINT32:1
TEST.VALUE:CDio_HwIf.dio_set_dir.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.__msg[0].i.dcmd:4
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.__msg[0].i.nbytes:2
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].msg[0].devctl.i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:4
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_devctl.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.ocb[0].attr:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:22
TEST.END

-- Test Case: GPIO_DIRECTION_WRITE_INVALID_DIR_PATH_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_DIRECTION_WRITE_INVALID_DIR_PATH_FAIL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:CDio_HwIf.dio_set_dir.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:4
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:-2147483647
TEST.END

-- Test Case: GPIO_DIRECTION_WRITE_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_DIRECTION_WRITE_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p[0].dir_pathID_S32:1
TEST.VALUE:CDio_HwIf.dio_set_dir.dioSetDirDev_p[0].is_valid_BOOL:true
TEST.VALUE:CDio_HwIf.dio_set_dir.dir_UINT32:1
TEST.VALUE:CDio_HwIf.dio_set_dir.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.__msg[0].i.dcmd:4
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.__msg[0].i.nbytes:2
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].msg[0].devctl.i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:4
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_devctl.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.ocb[0].attr:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:0
TEST.END

-- Test Case: GPIO_VALUE_READ_0_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_VALUE_READ_0_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:-1
TEST.END

-- Test Case: GPIO_VALUE_READ_1_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_VALUE_READ_1_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.return:1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:-1
TEST.END

-- Test Case: GPIO_VALUE_READ_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_VALUE_READ_FAIL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.return:-1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].bank_num_U32:22
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:-1
TEST.END

-- Test Case: GPIO_VALUE_READ_INVALID_VALPATH_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_VALUE_READ_INVALID_VALPATH_FAIL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:-1
TEST.END

-- Test Case: GPIO_VALUE_WRITE_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_VALUE_WRITE_FAIL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.VALUE:CDio_HwIf.dio_write_channel.return:-1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].bank_num_U32:22
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:2
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_devctl.return:22
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:22
TEST.END

-- Test Case: GPIO_VALUE_WRITE_FAIL_GET_ERRNO
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_VALUE_WRITE_FAIL_GET_ERRNO
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.VALUE:CDio_HwIf.dio_write_channel.return:-1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:2
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_devctl.return:22
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:22
TEST.END

-- Test Case: GPIO_VALUE_WRITE_NOVALID_DIO_PIN_PATH
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_VALUE_WRITE_NOVALID_DIO_PIN_PATH
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.VALUE:CDio_HwIf.dio_write_channel.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:2
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:-2147483647
TEST.END

-- Test Case: GPIO_VALUE_WRITE_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:GPIO_VALUE_WRITE_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.VALUE:CDio_HwIf.dio_write_channel.return:1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:2
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:0
TEST.END

-- Test Case: IOFUNC_DEVCTL_DEFAULT_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_devctl
TEST.NEW
TEST.NAME:IOFUNC_DEVCTL_DEFAULT_FAIL
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:CDio_HwIf.dio_set_dir.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:0
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.dioDevctlctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_devctl.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.dcmd:4
TEST.VALUE:CDio_RM.dio_io_devctl.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_devctl.return:11
TEST.EXPECTED:CDio_RM.dio_io_devctl.return:11
TEST.END

-- Subprogram: dio_io_open

-- Test Case: dio_io_open_iofunc_open_default_fail1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_open
TEST.NEW
TEST.NAME:dio_io_open_iofunc_open_default_fail1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.iofunc_open_default.return:28
TEST.VALUE:CDio_RM.dio_io_open.dioOpenctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_open.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_open.handle:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_io_open.return:28
TEST.END

-- Test Case: dio_io_open_iofunc_open_default_success1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_open
TEST.NEW
TEST.NAME:dio_io_open_iofunc_open_default_success1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:CDio_RM.dio_io_open.dioOpenctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_open.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_open.handle:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_io_open.return:0
TEST.END

-- Subprogram: dio_io_read

-- Test Case: dio_io_read_get_data_fail4
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_get_data_fail4
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.dioReadChnlDev_p[0].is_valid_BOOL:true
TEST.VALUE:CDio_HwIf.dio_read_channel.dioReadChnlAddr_p[0].set_bits_count_sa:5
TEST.VALUE:CDio_HwIf.dio_read_channel.return:2
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_ioattr.nbytes:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i64.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:0
TEST.END

-- Test Case: dio_io_read_get_data_fail7
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_get_data_fail7
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 7>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"in3131"
TEST.VALUE:CDio_HwIf.dio_read_channel.dioReadChnlDev_p[0].is_valid_BOOL:true
TEST.VALUE:CDio_HwIf.dio_read_channel.dioReadChnlAddr_p[0].set_bits_count_sa:5
TEST.VALUE:CDio_HwIf.dio_read_channel.return:2
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].bank_num_U32:22
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i64.nbytes:0
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:0
TEST.END

-- Test Case: dio_io_read_get_dir_fail3
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_get_dir_fail3
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_get_dir
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p[0].bank_num_U32:1
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p[0].is_valid_BOOL:true
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].set_bits_count_sa:5
TEST.VALUE:CDio_HwIf.dio_get_dir.return:-1
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_ioattr.nbytes:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].bank_num_U32:10
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p[0].id:2
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i64.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:0
TEST.END

-- Test Case: dio_io_read_get_dir_in_success1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_get_dir_in_success1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_get_dir
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p[0].bank_num_U32:1
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p[0].is_valid_BOOL:true
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].set_bits_count_sa:5
TEST.VALUE:CDio_HwIf.dio_get_dir.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_ioattr.nbytes:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p[0].id:2
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i64.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr[0].nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:0
TEST.END

-- Test Case: dio_io_read_get_dir_out_success2
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_get_dir_out_success2
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_get_dir
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p[0].bank_num_U32:1
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirDev_p[0].is_valid_BOOL:true
TEST.VALUE:CDio_HwIf.dio_get_dir.dioGetDirAddr_p[0].set_bits_count_sa:5
TEST.VALUE:CDio_HwIf.dio_get_dir.return:1
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_ioattr.nbytes:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p[0].id:2
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i64.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr[0].nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:0
TEST.END

-- Test Case: dio_io_read_get_value_0_success4
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_get_value_0_success4
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_ioattr.nbytes:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i64.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr[0].nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:0
TEST.END

-- Test Case: dio_io_read_get_value_1_success3
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_get_value_1_success3
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.return:1
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_ioattr.nbytes:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i64.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr[0].nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:0
TEST.END

-- Test Case: dio_io_read_invalid_valpathid_fail6
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_invalid_valpathid_fail6
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.return:1
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_ioattr.nbytes:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:3
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i64.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr[0].nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:1
TEST.END

-- Test Case: dio_io_read_iofunc_read_verify_fail1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_iofunc_read_verify_fail1
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:-1
TEST.EXPECTED:CDio_RM.dio_io_read.return:1
TEST.END

-- Test Case: dio_io_read_nbytes_success5
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_nbytes_success5
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.return:0
TEST.VALUE:uut_prototype_stubs.min.return:2
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_ioattr.nbytes:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i64.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr[0].nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:-1
TEST.END

-- Test Case: dio_io_read_pin_not_initialized_fail2
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_pin_not_initialized_fail2
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].bank_num_U32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:false
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:1
TEST.END

-- Test Case: dio_io_read_xtype_fail5
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_read
TEST.NEW
TEST.NAME:dio_io_read_xtype_fail5
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_HwIf.dio_read_channel
TEST.VALUE:CDio_HwIf.dio_read_channel.return:0
TEST.VALUE:uut_prototype_stubs.min.return:2
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_ioattr.nbytes:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_addr_sa[1].set_bits_count_sa:5
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.dioReadctp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_read.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i.xtype:2
TEST.VALUE:CDio_RM.dio_io_read.msg[0].i64.nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].attr[0].nbytes:2
TEST.VALUE:CDio_RM.dio_io_read.ocb[0].offset:1
TEST.EXPECTED:CDio_RM.dio_io_read.return:1
TEST.END

-- Subprogram: dio_io_write

-- Test Case: DIO_WRITE_DATA_EXTRACT_PIN_FAIL7
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_DATA_EXTRACT_PIN_FAIL7
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_data_extract
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.return:256
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:257
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_data_extract.return:false
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_export.return:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_DATA_EXTRACT_PIN_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_DATA_EXTRACT_PIN_SUCCESS
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_data_extract
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_data_extract.return:true
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_export.return:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.END

-- Test Case: DIO_WRITE_DATA_EXTRACT_PIN_SUCCESS.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_DATA_EXTRACT_PIN_SUCCESS.001
TEST.NOTES:
Requirement_PE4TI29141-3648
TEST.END_NOTES:
TEST.STUB:CDio_RM.dio_data_extract
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:2
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_data_extract.return:true
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_export.return:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.END

-- Test Case: DIO_WRITE_DIR_INDATA
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_DIR_INDATA
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 5>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"in\n"
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.END

-- Test Case: DIO_WRITE_DIR_INDATA.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_DIR_INDATA.001
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 5>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"in\n"
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].bank_num_U32:22
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.END

-- Test Case: DIO_WRITE_DIR_INDATA_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_DIR_INDATA_FAIL
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 7>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"in3131"
TEST.VALUE:CDio_HwIf.dio_set_dir.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_DIR_OUT_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_DIR_OUT_FAIL
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 5>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"outp"
TEST.VALUE:CDio_HwIf.dio_set_dir.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_DIR_SET_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_DIR_SET_FAIL
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 6>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"out\n"
TEST.VALUE:CDio_HwIf.dio_set_dir.return:-1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_DIR_SET_STRCMP_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_DIR_SET_STRCMP_FAIL
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 9>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"out12345"
TEST.VALUE:CDio_HwIf.dio_set_dir.return:-1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_EXPORT_INVALID_PIN_FAIL5
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_INVALID_PIN_FAIL5
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 4>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"255"
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[255].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_ALREADY_EXPORTED_FAIL8
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_ALREADY_EXPORTED_FAIL8
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:11
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_export.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.ATTRIBUTES:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].bank_mask_addr:INPUT_BASE=16
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_ALREADY_UNEXPORTED_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_ALREADY_UNEXPORTED_FAIL
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.return:256
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:257
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[9].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.ATTRIBUTES:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].bank_mask_addr:INPUT_BASE=16
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_DATA_EXTRACT_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_DATA_EXTRACT_FAIL
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_count_mask_bits
TEST.STUB:CDio_RM.dio_data_extract
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.return:9
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:10
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_count_mask_bits.return:true
TEST.VALUE:CDio_RM.dio_data_extract.return:false
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_export.return:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_DATA_EXTRACT_FAIL.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_DATA_EXTRACT_FAIL.001
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_count_mask_bits
TEST.STUB:CDio_RM.dio_data_extract
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.return:9
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:10
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_count_mask_bits.return:true
TEST.VALUE:CDio_RM.dio_data_extract.return:true
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_export.return:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_FAIL6
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_FAIL6
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.return:9
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:10
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_export.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.ATTRIBUTES:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].bank_mask_addr:INPUT_BASE=16
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_FAIL6.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_FAIL6.001
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.VCAST_PARAM_3:257
TEST.VALUE:uut_prototype_stubs.strtol.return:257
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:257
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_export.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_STRTOL_EINVAL_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_STRTOL_EINVAL_FAIL
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_export.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = EINVAL; 
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_STRTOL_EINVAL_FAIL.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_STRTOL_EINVAL_FAIL.001
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_export.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = EINVAL; 
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_STRTOL_ERANGE_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_STRTOL_ERANGE_FAIL
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_export.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = ERANGE; 
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_STRTOL_ERANGE_FAIL.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_STRTOL_ERANGE_FAIL.001
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_export.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
<<uut_prototype_stubs.strtol.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_EXPORT_PIN_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_EXPORT_PIN_SUCCESS
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_count_mask_bits
TEST.STUB:CDio_RM.dio_export
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.return:9
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_export_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:10
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_count_mask_bits.return:true
TEST.VALUE:CDio_RM.dio_export.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_export.return:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.ATTRIBUTES:CDio_RM.dio_data_extract.dioPinData_p[0].dio_addr_sa[1].bank_mask_addr:INPUT_BASE=16
TEST.END

-- Test Case: DIO_WRITE_INVALID_VALPATHID_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_INVALID_VALPATHID_FAIL
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:CDio_HwIf.dio_write_channel.return:-1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:2
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_FAIL
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.return:350
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:10
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[9].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_INVALID_PIN_FAIL9
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_INVALID_PIN_FAIL9
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 4>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"255"
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[255].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_PIN_FAIL10
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_PIN_FAIL10
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_PIN_STRTOL_EINVAL_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_PIN_STRTOL_EINVAL_FAIL
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = EINVAL; 
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_PIN_STRTOL_ERANGE_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_PIN_STRTOL_ERANGE_FAIL
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = ERANGE; 
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_PIN_STRTOL_ERANGE_FAIL.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_PIN_STRTOL_ERANGE_FAIL.001
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = ERANGE; 
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_PIN_STRTOL_ERANGE_FAIL.002
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_PIN_STRTOL_ERANGE_FAIL.002
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[10].is_valid_BOOL:false
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:10
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
<<uut_prototype_stubs.strtol.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_SUCCESS
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.return:9
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:10
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[9].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_unexport.return:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_SUCCESS.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_SUCCESS.001
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:10
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[9].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_unexport.return:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_SUCCESS.002
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_SUCCESS.002
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"10"
TEST.VALUE:uut_prototype_stubs.strtol.return:9
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_gpio_id_max_U32:10
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[9].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:0
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.END

-- Test Case: DIO_WRITE_UNEXPORT_VALID_PIN
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_UNEXPORT_VALID_PIN
TEST.STUB:CDio_RM.dio_unexport
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_pathID_unexport_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:1
TEST.VALUE:CDio_RM.dio_unexport.return:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.END

-- Test Case: DIO_WRITE_VALPATH_DATA
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_VALPATH_DATA
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 4>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"out"
TEST.VALUE:CDio_HwIf.dio_write_channel.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.END

-- Test Case: DIO_WRITE_VALPATH_DATA_ERANGE
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_VALPATH_DATA_ERANGE
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 19>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"0xFFFFFFFFFFFFFFFF"
TEST.VALUE:CDio_HwIf.dio_write_channel.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:0
TEST.VALUE_USER_CODE:<<testcase>>
errno = 34;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_VALPATH_DATA_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_VALPATH_DATA_FAIL
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 4>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"out"
TEST.VALUE:CDio_HwIf.dio_write_channel.return:-1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_VAL_EINVAL_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_VAL_EINVAL_FAIL
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:CDio_HwIf.dio_write_channel.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = EINVAL;
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_VAL_EINVAL_FAIL.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_VAL_EINVAL_FAIL.001
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:CDio_HwIf.dio_write_channel.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = EINVAL;
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_VAL_ERANGE_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_VAL_ERANGE_FAIL
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:CDio_HwIf.dio_write_channel.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = ERANGE;
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_VAL_ERANGE_FAIL.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_VAL_ERANGE_FAIL.001
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:CDio_HwIf.dio_write_channel.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
<<uut_prototype_stubs.strtol.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: DIO_WRITE_VAL_SET_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_VAL_SET_FAIL
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:CDio_HwIf.dio_write_channel.return:-1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].bank_num_U32:22
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: DIO_WRITE_VAL_SET_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:DIO_WRITE_VAL_SET_SUCCESS
TEST.STUB:CDio_HwIf.dio_write_channel
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 2>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"1"
TEST.VALUE:CDio_HwIf.dio_write_channel.return:1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].val_pathID_S32:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: IOFUNC_WRITE_VERIFY_FAIL1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:IOFUNC_WRITE_VERIFY_FAIL1
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 4>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"out"
TEST.VALUE:CDio_HwIf.dio_set_dir.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.iofunc_write_verify.return:1
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: MALICIOUS_WRITE_CHECK_FAIL2
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:MALICIOUS_WRITE_CHECK_FAIL2
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 4>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"out"
TEST.VALUE:CDio_HwIf.dio_set_dir.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].info.srcmsglen:0
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].offset:0
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:4294967295
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: MSG_XTYPE_NONE_FAIL3
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:MSG_XTYPE_NONE_FAIL3
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 4>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"out"
TEST.VALUE:CDio_HwIf.dio_set_dir.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:1
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.xtype:3
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:1
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.END

-- Test Case: RESMGR_REREAD_FAIL4
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_io_write
TEST.NEW
TEST.NAME:RESMGR_REREAD_FAIL4
TEST.STUB:CDio_HwIf.dio_set_dir
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 4>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"out"
TEST.VALUE:CDio_HwIf.dio_set_dir.return:0
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.__msg:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:-1
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.dioWritectp_p[0].id:1
TEST.VALUE:CDio_RM.dio_io_write.msg:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.msg[0].i.nbytes:0
TEST.VALUE:CDio_RM.dio_io_write.ocb:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_io_write.ocb[0].attr[0].nbytes:0
TEST.EXPECTED:CDio_RM.dio_io_write.return:1
TEST.VALUE_USER_CODE:<<testcase>>
errno = ESRVRFAULT;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: dio_options

-- Test Case: dio_options.EINVAL_fail
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_options
TEST.NEW
TEST.NAME:dio_options.EINVAL_fail
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:CDio_RM.dio_options.argc:16
TEST.VALUE:CDio_RM.dio_options.argv:<<malloc 16>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:"main"
TEST.VALUE:CDio_RM.dio_options.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.dio_options.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.dio_options.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.dio_options.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.dio_options.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.dio_options.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.dio_options.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.dio_options.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.dio_options.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.dio_options.argv[12]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[12]:"-m0x00000FF7"
TEST.VALUE:CDio_RM.dio_options.argv[13]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[13]:"-b1000"
TEST.VALUE:CDio_RM.dio_options.argv[14]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[14]:"-m1000"
TEST.VALUE:CDio_RM.dio_options.argv[15]:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_options.argv[15]:"-a100"
TEST.VALUE:CDio_RM.dio_options.dioOptionsAddr_p:<<malloc 16>>
TEST.EXPECTED:CDio_RM.dio_options.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = EINVAL; 
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: dio_options.EINVAL_fail.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_options
TEST.NEW
TEST.NAME:dio_options.EINVAL_fail.001
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:CDio_RM.dio_options.argc:16
TEST.VALUE:CDio_RM.dio_options.argv:<<malloc 16>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:"main"
TEST.VALUE:CDio_RM.dio_options.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.dio_options.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.dio_options.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.dio_options.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.dio_options.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.dio_options.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.dio_options.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.dio_options.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.dio_options.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.dio_options.argv[12]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[12]:"-m0x00000FF7"
TEST.VALUE:CDio_RM.dio_options.argv[13]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[13]:"-b1000"
TEST.VALUE:CDio_RM.dio_options.argv[14]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[14]:"-m1000"
TEST.VALUE:CDio_RM.dio_options.argv[15]:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_options.argv[15]:"-a100"
TEST.VALUE:CDio_RM.dio_options.dioOptionsAddr_p:<<malloc 16>>
TEST.EXPECTED:CDio_RM.dio_options.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = EINVAL; 
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: dio_options.EINVAL_fail.002
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_options
TEST.NEW
TEST.NAME:dio_options.EINVAL_fail.002
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_getopt_chk
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.optarg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.optarg[0]:'0'
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm[0]:'u'
TEST.VALUE:CDio_RM.<<GLOBAL>>.optarg:<<malloc 1>>
TEST.VALUE:CDio_RM.<<GLOBAL>>.optarg[0]:'u'
TEST.VALUE:CDio_RM.dio_getopt_chk.p_opt:"u"
TEST.VALUE:CDio_RM.dio_options.argc:16
TEST.VALUE:CDio_RM.dio_options.argv:<<malloc 16>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:"main"
TEST.VALUE:CDio_RM.dio_options.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.dio_options.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.dio_options.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.dio_options.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.dio_options.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.dio_options.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.dio_options.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.dio_options.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.dio_options.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.dio_options.argv[12]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[12]:"-m0x00000FF7"
TEST.VALUE:CDio_RM.dio_options.argv[13]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[13]:"-b1000"
TEST.VALUE:CDio_RM.dio_options.argv[14]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[14]:"-m1000"
TEST.VALUE:CDio_RM.dio_options.argv[15]:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_options.argv[15]:"-a100"
TEST.VALUE:CDio_RM.dio_options.dioOptionsAddr_p:<<malloc 16>>
TEST.EXPECTED:CDio_RM.dio_options.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
<<uut_prototype_stubs.strtol.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: dio_options.EINVAL_fail.003
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_options
TEST.NEW
TEST.NAME:dio_options.EINVAL_fail.003
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:CDio_RM.dio_options.argc:16
TEST.VALUE:CDio_RM.dio_options.argv:<<malloc 16>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:"main"
TEST.VALUE:CDio_RM.dio_options.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.dio_options.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.dio_options.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.dio_options.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.dio_options.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.dio_options.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.dio_options.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.dio_options.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.dio_options.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.dio_options.argv[12]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[12]:"-m0x00000FF7"
TEST.VALUE:CDio_RM.dio_options.argv[13]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[13]:"-b1000"
TEST.VALUE:CDio_RM.dio_options.argv[14]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[14]:"-m1000"
TEST.VALUE:CDio_RM.dio_options.argv[15]:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_options.argv[15]:"-a100"
TEST.VALUE:CDio_RM.dio_options.dioOptionsAddr_p:<<malloc 16>>
TEST.EXPECTED:CDio_RM.dio_options.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
<<uut_prototype_stubs.strtol.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: dio_options.ERANGE_BANK_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_options
TEST.NEW
TEST.NAME:dio_options.ERANGE_BANK_FAIL
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:0
TEST.VALUE:CDio_RM.dio_options.argc:12
TEST.VALUE:CDio_RM.dio_options.argv:<<malloc 17>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:"main"
TEST.VALUE:CDio_RM.dio_options.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.dio_options.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.dio_options.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.dio_options.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.dio_options.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.dio_options.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.dio_options.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.dio_options.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.dio_options.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[11]:"-b0x80F00500"
TEST.VALUE:CDio_RM.dio_options.argv[12]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[12]:"-m0x00000FF7"
TEST.VALUE:CDio_RM.dio_options.argv[13]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[13]:"-b1000"
TEST.VALUE:CDio_RM.dio_options.argv[14]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[14]:"-m1000"
TEST.VALUE:CDio_RM.dio_options.argv[15]:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_options.argv[15]:"-a100"
TEST.VALUE:CDio_RM.dio_options.dioOptionsAddr_p:<<malloc 16>>
TEST.VALUE:CDio_RM.dio_options.return:false
TEST.EXPECTED:CDio_RM.dio_options.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = ERANGE;
<<uut_prototype_stubs.strtol.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: dio_options.ERANGE_U_free
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_options
TEST.NEW
TEST.NAME:dio_options.ERANGE_U_free
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm:<<malloc 4>>
TEST.VALUE:CDio_RM.<<GLOBAL>>.UserParm:"ABC"
TEST.VALUE:CDio_RM.dio_options.argc:17
TEST.VALUE:CDio_RM.dio_options.argv:<<malloc 17>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:"main"
TEST.VALUE:CDio_RM.dio_options.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.dio_options.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.dio_options.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.dio_options.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.dio_options.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.dio_options.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.dio_options.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.dio_options.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.dio_options.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.dio_options.argv[12]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[12]:"-m0x00000FF7"
TEST.VALUE:CDio_RM.dio_options.argv[13]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[13]:"-b1000"
TEST.VALUE:CDio_RM.dio_options.argv[14]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[14]:"-m1000"
TEST.VALUE:CDio_RM.dio_options.argv[15]:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_options.argv[15]:"-a100"
TEST.VALUE:CDio_RM.dio_options.argv[16]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[16]:"-U1000"
TEST.VALUE:CDio_RM.dio_options.dioOptionsAddr_p:<<malloc 16>>
TEST.VALUE:CDio_RM.dio_options.return:false
TEST.EXPECTED:CDio_RM.dio_options.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = ERANGE;
<<uut_prototype_stubs.strtol.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: dio_options.ERANGE_fail.004
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_options
TEST.NEW
TEST.NAME:dio_options.ERANGE_fail.004
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:CDio_RM.dio_options.argc:17
TEST.VALUE:CDio_RM.dio_options.argv:<<malloc 17>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:"main"
TEST.VALUE:CDio_RM.dio_options.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.dio_options.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.dio_options.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.dio_options.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.dio_options.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.dio_options.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.dio_options.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.dio_options.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.dio_options.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.dio_options.argv[12]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[12]:"-m0x00000FF7"
TEST.VALUE:CDio_RM.dio_options.argv[13]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[13]:"-b1000"
TEST.VALUE:CDio_RM.dio_options.argv[14]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[14]:"-m1000"
TEST.VALUE:CDio_RM.dio_options.argv[15]:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_options.argv[15]:"-a100"
TEST.VALUE:CDio_RM.dio_options.argv[16]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[16]:"-U1000"
TEST.VALUE:CDio_RM.dio_options.dioOptionsAddr_p:<<malloc 16>>
TEST.VALUE:CDio_RM.dio_options.return:false
TEST.EXPECTED:CDio_RM.dio_options.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = ERANGE;
<<uut_prototype_stubs.strtol.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: dio_options.ERANGE_fail.005
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_options
TEST.NEW
TEST.NAME:dio_options.ERANGE_fail.005
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_getopt_chk
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:CDio_RM.dio_getopt_chk.return:false
TEST.VALUE:CDio_RM.dio_options.argc:17
TEST.VALUE:CDio_RM.dio_options.argv:<<malloc 17>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:"main"
TEST.VALUE:CDio_RM.dio_options.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.dio_options.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.dio_options.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.dio_options.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.dio_options.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.dio_options.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.dio_options.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.dio_options.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.dio_options.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.dio_options.argv[12]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[12]:"-m0x00000FF7"
TEST.VALUE:CDio_RM.dio_options.argv[13]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[13]:"-b1000"
TEST.VALUE:CDio_RM.dio_options.argv[14]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[14]:"-m1000"
TEST.VALUE:CDio_RM.dio_options.argv[15]:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_options.argv[15]:"-a100"
TEST.VALUE:CDio_RM.dio_options.argv[16]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[16]:"-U1000"
TEST.VALUE:CDio_RM.dio_options.dioOptionsAddr_p:<<malloc 17>>
TEST.EXPECTED:CDio_RM.dio_options.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: dio_options_ERANGE_fail
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_options
TEST.NEW
TEST.NAME:dio_options_ERANGE_fail
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_getopt_chk
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:CDio_RM.dio_options.argc:16
TEST.VALUE:CDio_RM.dio_options.argv:<<malloc 16>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:"main"
TEST.VALUE:CDio_RM.dio_options.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.dio_options.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.dio_options.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.dio_options.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.dio_options.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.dio_options.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.dio_options.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.dio_options.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.dio_options.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.dio_options.argv[12]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[12]:"-m0x00000FF7"
TEST.VALUE:CDio_RM.dio_options.argv[13]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[13]:"-b1000"
TEST.VALUE:CDio_RM.dio_options.argv[14]:<<malloc 7>>
TEST.VALUE:CDio_RM.dio_options.argv[14]:"-m1000"
TEST.VALUE:CDio_RM.dio_options.argv[15]:<<malloc 6>>
TEST.VALUE:CDio_RM.dio_options.argv[15]:"-a100"
TEST.VALUE:CDio_RM.dio_options.dioOptionsAddr_p:<<malloc 16>>
TEST.EXPECTED:CDio_RM.dio_options.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = ERANGE; 
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: dio_options_SUCCESS
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_options
TEST.NEW
TEST.NAME:dio_options_SUCCESS
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CDio_RM.dio_getopt_chk
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:1
TEST.VALUE:CDio_RM.dio_getopt_chk.return:false
TEST.VALUE:CDio_RM.dio_options.argc:12
TEST.VALUE:CDio_RM.dio_options.argv:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:<<malloc 5>>
TEST.VALUE:CDio_RM.dio_options.argv[0]:"main"
TEST.VALUE:CDio_RM.dio_options.argv[1]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[1]:"-b0x5d080000"
TEST.VALUE:CDio_RM.dio_options.argv[2]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[2]:"-m0xFF79FFFE"
TEST.VALUE:CDio_RM.dio_options.argv[3]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[3]:"-b0x80f00100"
TEST.VALUE:CDio_RM.dio_options.argv[4]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[4]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[5]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[5]:"-b0x5D0A0000"
TEST.VALUE:CDio_RM.dio_options.argv[6]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[6]:"-m0x0000000F"
TEST.VALUE:CDio_RM.dio_options.argv[7]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[7]:"-b0x80F00300"
TEST.VALUE:CDio_RM.dio_options.argv[8]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[8]:"-m0x013DFF7F"
TEST.VALUE:CDio_RM.dio_options.argv[9]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[9]:"-b0x80F00400"
TEST.VALUE:CDio_RM.dio_options.argv[10]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[10]:"-m0xFFFFFFFF"
TEST.VALUE:CDio_RM.dio_options.argv[11]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[11]:"-b0x5d0d0000"
TEST.VALUE:CDio_RM.dio_options.argv[12]:<<malloc 13>>
TEST.VALUE:CDio_RM.dio_options.argv[12]:"-m0x00000FF7"
TEST.VALUE:CDio_RM.dio_options.dioOptionsAddr_p:<<malloc 12>>
TEST.EXPECTED:CDio_RM.dio_options.return:true
TEST.END

-- Subprogram: dio_periodic_read_check

-- Test Case: dio_periodic_read_check.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_periodic_read_check
TEST.NEW
TEST.NAME:dio_periodic_read_check.001
TEST.STUB:CDio_HwIf.dio_periodic_task
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 5>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"helo"
TEST.VALUE:CDio_HwIf.dio_periodic_task.return:0
TEST.VALUE:CDio_RM.dio_periodic_read_check.dioPeriodicctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_periodic_read_check.code:1
TEST.VALUE:CDio_RM.dio_periodic_read_check.flags:1
TEST.VALUE:CDio_RM.dio_periodic_read_check.handle:VECTORCAST_STR1
TEST.EXPECTED:CDio_RM.dio_periodic_read_check.return:0
TEST.END

-- Test Case: dio_periodic_read_check_FAIL
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_periodic_read_check
TEST.NEW
TEST.NAME:dio_periodic_read_check_FAIL
TEST.STUB:CDio_HwIf.dio_periodic_task
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 5>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"helo"
TEST.VALUE:CDio_HwIf.dio_periodic_task.return:1
TEST.VALUE:CDio_RM.dio_periodic_read_check.dioPeriodicctp_p:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_periodic_read_check.code:1
TEST.VALUE:CDio_RM.dio_periodic_read_check.flags:1
TEST.VALUE:CDio_RM.dio_periodic_read_check.handle:VECTORCAST_STR1
TEST.EXPECTED:CDio_RM.dio_periodic_read_check.return:1
TEST.END

-- Subprogram: dio_setup_timer

-- Test Case: dio_setup_timer_create_fail1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_setup_timer
TEST.NEW
TEST.NAME:dio_setup_timer_create_fail1
TEST.VALUE:uut_prototype_stubs.TimerCreate.return:-1
TEST.VALUE:CDio_RM.dio_setup_timer.dioTimerDev_p:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_setup_timer.return:false
TEST.END

-- Test Case: dio_setup_timer_create_success
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_setup_timer
TEST.NEW
TEST.NAME:dio_setup_timer_create_success
TEST.VALUE:uut_prototype_stubs.TimerCreate.return:0
TEST.VALUE:CDio_RM.dio_setup_timer.dioTimerDev_p:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_setup_timer.return:true
TEST.END

-- Test Case: dio_setup_timer_settime_fail
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_setup_timer
TEST.NEW
TEST.NAME:dio_setup_timer_settime_fail
TEST.VALUE:uut_prototype_stubs.TimerCreate.return:0
TEST.VALUE:uut_prototype_stubs.TimerSettime.return:-1
TEST.VALUE:CDio_RM.dio_setup_timer.dioTimerDev_p:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_setup_timer.return:false
TEST.END

-- Subprogram: dio_unexport

-- Test Case: dio_unexport_resmgr_detach_direction_fail1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_unexport
TEST.NEW
TEST.NAME:dio_unexport_resmgr_detach_direction_fail1
TEST.VALUE:uut_prototype_stubs.resmgr_detach.return:-1
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_unexport.return:1
TEST.END

-- Test Case: dio_unexport_resmgr_detach_value_fail2
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_unexport
TEST.NEW
TEST.NAME:dio_unexport_resmgr_detach_value_fail2
TEST.VALUE:uut_prototype_stubs.resmgr_detach.return:1,-1
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_unexport.return:1
TEST.END

-- Test Case: dio_unexport_resmgr_detach_value_fail2.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_unexport
TEST.NEW
TEST.NAME:dio_unexport_resmgr_detach_value_fail2.001
TEST.VALUE:uut_prototype_stubs.resmgr_detach.return:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].dir_pathID_S32:0
TEST.VALUE:CDio_RM.<<GLOBAL>>.g_dio_pindata.dio_pin_sa[1].is_valid_BOOL:true
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32:<<malloc 1>>
TEST.EXPECTED:CDio_RM.dio_unexport.return:0
TEST.END

-- Test Case: dio_unexport_success1
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_unexport
TEST.NEW
TEST.NAME:dio_unexport_success1
TEST.VALUE:uut_prototype_stubs.resmgr_detach.return:1,2
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32:<<malloc 1>>
TEST.VALUE:CDio_RM.dio_unexport.p_pin_S32[0]:257
TEST.VALUE:CDio_RM.dio_unexport.return:1
TEST.EXPECTED:CDio_RM.dio_unexport.return:1
TEST.END

-- Subprogram: dio_usage

-- Test Case: dio_usage.001
TEST.UNIT:CDio_RM
TEST.SUBPROGRAM:dio_usage
TEST.NEW
TEST.NAME:dio_usage.001
TEST.FLOW
  CDio_RM.c.dio_usage
  CDio_RM.c.dio_usage
TEST.END_FLOW
TEST.END
