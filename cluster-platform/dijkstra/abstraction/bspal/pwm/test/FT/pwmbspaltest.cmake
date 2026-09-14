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

option(BSPAL_PWM_TESTS   	"Set to OFF to disable tests"  ON)
option(BSPAL_PWMLINUX_TESTS   	"Set to OFF to disable tests"  ON)

# Create Binary
add_executable(${BINARY_NAME} dummy_executable.c)

if(BSPAL_PWM_TESTS)
# Add test binaries
binary_scripts(
    ${CMAKE_CURRENT_SOURCE_DIR}/qnx/c_client/test01/pwm_set_dutycycle.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/qnx/c_client/test02/pwm_get_dutycycle.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/qnx/c_client/test03/pwm_set_period.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/qnx/c_client/test04/pwm_get_period.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/qnx/c_client/test05/pwm_set_enable.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/qnx/c_client/test06/pwm_get_enable.cmake
)
endif()

if(BSPAL_PWMLINUX_TESTS)
# Add test binaries
binary_scripts(
    ${CMAKE_CURRENT_SOURCE_DIR}/linux/c_client/test01/pwm_set_period.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/linux/c_client/test02/pwm_get_period.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/linux/c_client/test03/pwm_set_dutycycle.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/linux/c_client/test04/pwm_get_dutycycle.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/linux/c_client/test05/pwm_set_enable.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/linux/c_client/test06/pwm_get_enable.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/linux/c_client/test07/pwm_set_brightness.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/linux/c_client/test08/pwm_get_brightness.cmake
)
endif()
