#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2019] Visteon Corporation
# All Rights Reserved.
#
# NOTICE: This is an unpublished work of authorship, which contains trade secrets.
# Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
# its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
# or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
# in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
# under all copyright laws to protect this work as a published work, when appropriate.
# Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
# without the written authorization of Visteon Corporation.
#
#---------------------------------------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.14)

# Set a variable indicating to compile required features
option(COMPILE_LZMA "Compile LZMA" ${LZMA_SWITCH})
option(COMPILE_LZBW "Compile LZBW" ${LZBW_SWITCH})
option(COMPILE_AES  "Compile AES"  ${AES_SWITCH})
option(COMPILE_TAR  "Compile TAR"  ${TAR_SWITCH})

option(COMPILE_HYP  "Compile HyperFlash IO Adapter"  ${HYP_SWITCH})
option(COMPILE_QSPI  "Compile HyperFlash IO Adapter"  ${QSPI_SWITCH})
option(COMPILE_HSM  "Compile HSM IO Adapter"  ${HSM_SWITCH})
option(COMPILE_GP_APT  "Compile GIP IO Adapter"  ${GP_APT_SWITCH})

# Add the selected C files you want to compile
set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_AbstractInstaller.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_AesDecoder.c
	#${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_BlockDevIoAdapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_BlockInstaller.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_DeltaDecoder.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_FlashIoAdapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_QSPIIoAdapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_GenDecoder.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_InstallMan.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_IoAdapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_LocalIoAdapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_LzmaDecoder.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_Session.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_SparseDecoder.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_TarDecoder.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_Target.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_UpdateCdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_UpdateMan.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/UPDi_VdtDecoder.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Tool/UpdPack/Lzma/LzmaDec.c
)

if(BUILD_VARIANT STREQUAL BL_Platform)
set(DEPENDENCIES
    blupdateclient
    GenMcal
    Fls
)

else()
set(DEPENDENCIES
    vpupdateclient
    GenMcal
)
endif()

# Files to be linked into the static library
add_library( ${MODULE_NAME} ${MODULE_STATIC_SHARED} ${SOURCE_FILES} )

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/public 
    ${CMAKE_CURRENT_SOURCE_DIR}/Tool/UpdPack/Lzma
    ${CMAKE_CURRENT_SOURCE_DIR}/Tool/UpdPack/SparseDec/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Tool/UpdPack/SparseDec/public
    ${CMAKE_CURRENT_SOURCE_DIR}/UPDd
)

# Add dependency libraries
target_add_dependencies(${MODULE_NAME}
    PRIVATE
    ${DEPENDENCIES}
)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  3/17/2019  | MDELAFU1 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
