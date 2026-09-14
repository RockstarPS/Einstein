#---------------------------------------------------------------------------------------------------------------------
#
# VISTEON CORPORATION CONFIDENTIAL
# ________________________________
#
# [2022] Visteon Corporation
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
cmake_minimum_required (VERSION 3.14...3.14)


# Files to be linked into the static library
add_library(${MODULE_NAME} ${MODULE_STATIC_SHARED}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_Cancel.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_CmacGen.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_MacVerify.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_CbcDecrypt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_CbcEncrypt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_Random.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_She.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_HashCalc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_EcbDecrypt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_EcbEncrypt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Crypto_Key.c
)

target_include_directories(${MODULE_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/public
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs
    ${CMAKE_CURRENT_SOURCE_DIR}/../vHsmCryptoApplication/m4/public
    
)

target_add_dependencies(${MODULE_NAME}
    PUBLIC
    PlatformStubs
    GenBsw
    vHsmCryptoManagerR5
    Csm
    vHsmDmnMgr
    CryIf
    vHsmSWCrypto
)


#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#  3/17/2019  | MDELAFU1 |  475480   | Created initial file
#-------------------------------------------------------------------------------------------------------------------
