Follow the below steps to indegrate gdt in to pxp demo app(\boards\evkmimxrt1170\driver_examples\pxp\blend\cm7)

1. Clone gdt and iceapple as in below directory structure
	gui(any folder name)
		gdt
		iceapple
2. Change SDK_PATH with your sdk diretory path in the below file
    imxrt_t32_test_app\gui_app\build\CMakeLists.txt
3. Call build.bat with SDK path as argument
		e.g build.bat C:\SDK_2.9.1_MIMXRT1170-EVK
		elf and binary files will be created in armgcc\flexspi_nor_sdram_debug
4. Flash using the below cmm scripts
		imxrt_t32_test_app\scripts\imxrt1170-main_dialog.cmm
		imxrt_t32_test_app\scripts\imxrt1170_Reset.cmm