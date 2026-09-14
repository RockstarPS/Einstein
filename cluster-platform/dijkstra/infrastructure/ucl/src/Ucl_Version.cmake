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

# Set UCL version
set (UCL_MAJOR_VERSION 3)
set (UCL_MINOR_VERSION 0)
set (UCL_PATCH_VERSION 16)
set (UCL_VERSION ${UCL_MAJOR_VERSION}.${UCL_MINOR_VERSION}.${UCL_PATCH_VERSION})
if(DK_UPDATE_BUILDINFO)
set (UCL_BUILD_USER $ENV{USERNAME})
string(TIMESTAMP UCL_BUILD_TIMESTAMP "%Y-%m-%d %H:%M")
cmake_host_system_information(RESULT UCL_BUILD_HOSTNAME QUERY HOSTNAME)
else()
set (UCL_BUILD_USER "NA")
string(TIMESTAMP UCL_BUILD_TIMESTAMP "0000-00-00 00:00")
set(UCL_BUILD_HOSTNAME "NA")
endif()
# Generate configuration file using variables
configure_file(${UCL_ROOT_PATH}/Ucl_Version.h.in ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/ucl/Ucl_Version.h @ONLY)

#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task         |                                     Description
#------------------------------------------------------------------------------------------------------------------
#  16/12/2025 | SSRINI28 |SMQB31568-135323 | UCL Stack Version Update 3.0.16 Android and Vlite OS changes on the stack and new UT implementations for Vlite OS, Android OS, and SomeIP Adapter.
#------------------------------------------------------------------------------------------------------------------
#  13/05/2025 | PSIVAKU7 |TFDCX32348-30946 | UCL Stack Version Update 3.0.15 Klockwork fix , SYSLOG Update , Issue Fix 
#-------------------------------------------------------------------------------------------------------------------
#  01/04/2025 | PSIVAKU7 |BMIC29130-16721  | UCL Stack Version Update 3.0.14KW fixes and TI AM62Px  Mailbox abstraction
#-------------------------------------------------------------------------------------------------------------------
#  29/07/2024 | SSUBRA21 |TASK30896-30491  | UCL Stack Version Update 3.0.13 Added Serial Android PHY layer-related files, incorporating changes from version 3.0.12 across all IVI programs.
#-------------------------------------------------------------------------------------------------------------------
#  22/07/2024 | AANITHA  |AU29610-174102   | UCL Stack Version Update 3.0.12 KW fixes and UT updates 
#-------------------------------------------------------------------------------------------------------------------
#  18/04/2024 | TNAVYA   |JLR3C29298-260162| UCL Stack Version Update 3.0.11 Mutex Change in Scheduler file, added Mailbox changes
#-------------------------------------------------------------------------------------------------------------------
#  17/07/2023 | TNAVYA   |           | UCL Stack Version Update 3.0.10 Ucl Coverity fixes, Float compiler warning fixed
#-------------------------------------------------------------------------------------------------------------------
#  2/10/2023  | AANITHA  |  1914296  | UCL Stack Version Update 3.0.9 Send on Init Implementation , Mu FreeRTOS Support , ASR Adapter Initialize and Shutdown Update 
#-------------------------------------------------------------------------------------------------------------------
#  24/08/2022 | SSHANKA8 |  1732136  | UCL Stack Version Update 3.0.8 Deadlock Fix in Process Ack Timer and Remove lib version dependency
#-------------------------------------------------------------------------------------------------------------------
#  17/02/2022 | SSHANKA8 |  1580119  | UCL Stack Version Update 3.0.7 Vbuild6 fixes , ALOsPosix Update and SerialASR Update
#-------------------------------------------------------------------------------------------------------------------
#  6/10/2021  | SSHANKA8 |  1476422  | UCL Stack Version Update 3.0.6 Coverity Fix Posix and Tx ACkQ Update
#-------------------------------------------------------------------------------------------------------------------
#  3/17/2019  | MDELAFU1 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------wins