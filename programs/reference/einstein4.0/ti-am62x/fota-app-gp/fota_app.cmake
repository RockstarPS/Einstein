# ---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL ________________________________
#
# [2019] Visteon Corporation All Rights Reserved.
#
# NOTICE: This is an unpublished work of authorship, which contains trade secrets. Visteon Corporation owns all rights
# to this work and intends to maintain it in confidence to preserve its trade secret status. Visteon Corporation
# reserves the right, under the copyright laws of the United States or those of any other country that may have
# jurisdiction, to protect this work as an unpublished work, in the event of an inadvertent or deliberate unauthorized
# publication. Visteon Corporation also reserves its rights under all copyright laws to protect this work as a published
# work, when appropriate. Those having access to this work may not copy it, use it, modify it, or disclose the
# information contained in it without the written authorization of Visteon Corporation.
#
# ----------------------------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.14)
set(BUILD_VARIANT              GP_Platform)
set(LZMA_SWITCH            OFF)
set(LZBW_SWITCH            OFF)
set(AES_SWITCH             ON)
set(TAR_SWITCH             OFF)
set(HSM_SWITCH             OFF)
set(QSPI_SWITCH            OFF)
set(HYP_SWITCH             OFF)
set(GP_APT_SWITCH          OFF)
set(BLK_DEV_APT_SWITCH     ON)
# Create Binary]
add_executable(
    ${BINARY_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/dummy.c
)


target_compile_definitions(${BINARY_NAME}  PRIVATE  DUAL_INSTANCE_POC  UDSCORE_LOG_ENABLED UDSCFG_LOG_ENABLED )

# Add target include directories
target_include_directories(
   ${BINARY_NAME}
   PRIVATE
   PUBLIC
)

# Add dependency libraries
target_add_dependencies(
	${BINARY_NAME}
	PRIVATE
	PUBLIC
   GenRuntime
   #  Fls
   )

# Link installed libraries that are not build with VBuild
target_link_libraries(${BINARY_NAME}
		PRIVATE 
	)

 # Install the binary
install(
	TARGETS ${BINARY_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
   )


# -----------------------------------------------------------------------------------------------------------------}
# Date     |   User   |   Task            |                                     Description
# -------------------------------------------------------------------------------------------------------------------
# 19/9/2024 | agodara   |                         | Created initial file
# -------------------------------------------------------------------------------------------------------------------
