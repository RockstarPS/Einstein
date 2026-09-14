# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 3.1.1)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})
SET(SDK_PATH "C:/SDK_2.9.1_MIMXRT1170-EVK/")
SET(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(pxp_blend_cm7)

set(MCUX_SDK_PROJECT_NAME pxp_blend_cm7.elf)

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/../pxp_blend.c"
"${ProjDirPath}/../../nxp_src/pin_mux.c"
"${ProjDirPath}/../../nxp_src/pin_mux.h"
"${ProjDirPath}/../../nxp_src/display_support.h"
"${ProjDirPath}/../../nxp_src/display_support.c"
"${ProjDirPath}/../../nxp_src/board.c"
"${ProjDirPath}/../../nxp_src/board.h"
"${ProjDirPath}/../../nxp_src/clock_config.c"
"${ProjDirPath}/../../nxp_src/clock_config.h"
"${ProjDirPath}/../../nxp_src/dcd.c"
"${ProjDirPath}/../../nxp_src/dcd.h"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${ProjDirPath}/../../nxp_src/
	${ProjDirPath}/../../../../../../ui.core.gdt/hmi.gfx.manager.02/src/
	${ProjDirPath}/../../../../../../ui.core.gdt/osal/turing
)

set(CMAKE_MODULE_PATH
    ${ProjDirPath}/../../gui_app
    ${SDK_PATH}/components/video
    ${SDK_PATH}/components/video/display
    ${SDK_PATH}/components/video/display/rm68191
    ${SDK_PATH}/devices/MIMXRT1176/drivers
    ${SDK_PATH}/components/video/display/mipi_dsi_cmd
    ${SDK_PATH}/components/video/display/rm68200
    ${SDK_PATH}/components/video/display/dc/lcdifv2
    ${SDK_PATH}/components/video/display/dc/elcdif
    ${SDK_PATH}/devices/MIMXRT1176/utilities/debug_console_lite
    ${SDK_PATH}/components/video/display/dc
    ${SDK_PATH}/devices/MIMXRT1176
    ${SDK_PATH}/CMSIS/Include
    ${SDK_PATH}/components/uart
    ${SDK_PATH}/components/lists
    ${SDK_PATH}/devices/MIMXRT1176/xip
    ${SDK_PATH}/boards/evkmimxrt1170/xip
    ${SDK_PATH}/devices/MIMXRT1176/drivers/cm7
    ${SDK_PATH}/devices/MIMXRT1176/utilities
)

# include modules
include(gui_app)

include(driver_video-common_MIMXRT1176_cm7)

include(driver_display-common_MIMXRT1176_cm7)

include(driver_display-rm68191_MIMXRT1176_cm7)

include(driver_mipi_dsi_split_MIMXRT1176_cm7)

include(driver_display-mipi-dsi-cmd_MIMXRT1176_cm7)

include(driver_common_MIMXRT1176_cm7)

include(driver_display-rm68200_MIMXRT1176_cm7)

include(driver_dc-fb-lcdifv2_MIMXRT1176_cm7)

include(driver_soc_src_MIMXRT1176_cm7)

include(driver_elcdif_MIMXRT1176_cm7)

include(driver_dc-fb-elcdif_MIMXRT1176_cm7)

include(utility_debug_console_lite_MIMXRT1176_cm7)

include(utility_assert_lite_MIMXRT1176_cm7)

include(driver_igpio_MIMXRT1176_cm7)

include(driver_pxp_MIMXRT1176_cm7)

include(driver_dc-fb-common_MIMXRT1176_cm7)

include(driver_clock_MIMXRT1176_cm7)

include(device_MIMXRT1176_CMSIS_MIMXRT1176_cm7)

include(CMSIS_Include_core_cm7_MIMXRT1176_cm7)

include(component_lpuart_adapter_MIMXRT1176_cm7)

include(component_lists_MIMXRT1176_cm7)

include(driver_lpuart_MIMXRT1176_cm7)

include(device_MIMXRT1176_startup_MIMXRT1176_cm7)

include(driver_iomuxc_MIMXRT1176_cm7)

include(driver_xip_device_MIMXRT1176_cm7)

include(driver_xip_board_MIMXRT1176_cm7)

include(driver_pmu_1_MIMXRT1176_cm7)

include(driver_dcdc_soc_MIMXRT1176_cm7)

include(driver_cache_armv7_m7_MIMXRT1176_cm7)

include(driver_anatop_ai_MIMXRT1176_cm7)

include(driver_soc_mipi_csi2rx_MIMXRT1176_cm7)

include(driver_lcdifv2_MIMXRT1176_cm7)

include(utilities_misc_utilities_MIMXRT1176_cm7)

include(CMSIS_Include_common_MIMXRT1176_cm7)

include(CMSIS_Include_dsp_MIMXRT1176_cm7)

include(device_MIMXRT1176_system_MIMXRT1176_cm7)


TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE m)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE c)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE gcc)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE nosys)

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


