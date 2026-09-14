#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2020] Visteon Corporation
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

# Set library information variables

# Files to be linked into the shared library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/doip_component.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/infra_comm_doip_handler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/infra_comm_doip_ringbuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/infra_comm_doip_soad.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/infra_comm_doip_timer.cpp
 )

# Directories with header files to be shared
target_include_directories(${MODULE_NAME}
    PUBLIC
 	${CMAKE_CURRENT_SOURCE_DIR}/src/
	${GP_RTE_DIR}/gip/src/applications/diag_app_gp
)
# all the dependency including headers and lib gets pulled
target_add_dependencies(${MODULE_NAME}
        PUBLIC
		dk_logger
		GenRuntime
		dk_runtime)

# Link installed libraries that are not build with VBuild
target_link_libraries(${MODULE_NAME}
    PUBLIC
     )


# Install the library
install(TARGETS ${MODULE_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  09/04/2020  | RKRISHN8 |    N/A    | Created initial file
#-------------------------------------------------------------------------------------------------------------------
