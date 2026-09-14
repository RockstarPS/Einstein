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


add_custom_target(doxygen 
    COMMENT "Generating Doxygen Docuemntation" VERBATIM
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/doc
    COMMAND "${DOXYGEN_EXECUTABLE}" doxygen.cfg
)

#-------------------------------------------------------------------------------------------------------------------
#     Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  03/12/2025  | STHANGA4 |    N/A    | Added/Updated support for linux only build, build cmds updated
#-------------------------------------------------------------------------------------------------------------------
#  07/07/2023  | MMK      |    N/A    | Created initial file from P33 program
#-------------------------------------------------------------------------------------------------------------------
