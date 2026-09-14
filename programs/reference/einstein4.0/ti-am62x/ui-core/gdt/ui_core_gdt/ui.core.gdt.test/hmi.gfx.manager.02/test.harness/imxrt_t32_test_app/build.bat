echo *** Copying files from %1 to nxp_src ***

set SDK_PATH=%1
xcopy /S /I /E /Y %1\boards\evkmimxrt1170\driver_examples\pxp\blend\cm7 .\nxp_src

cd .\gui_app\build

.\build_flexspi_nor_sdram_debug.bat

echo *** ELF to Binary conversion ***
ElfToBin.bat ./flexspi_nor_sdram_debug\pxp_blend_cm7.elf

echo *** Redirecting to build directory ***
cd..
cd..

