cmake_minimum_required(VERSION 3.14)
project(optee_system_build NONE)


# Cross-compiler prefix (must be set)
if(NOT DEFINED CROSS_COMPILE)
    set(CROSS_COMPILE "aarch64-linux-gnu-")
endif()

find_program(MAKE_BIN make REQUIRED)


# Paths

set(OPTEE_SECMGR_PATH
    ${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/libraries/optee-securitylib/SecurityManager
)

set(TA_SRC_DIR
    ${OPTEE_SECMGR_PATH}/SecureStorage_Crypto_CA_TA/ta
)

set(CA_SRC_DIR
    ${OPTEE_SECMGR_PATH}/SecureStorage_Crypto_CA_TA/host
)

set(OPTEE_CLIENT_EXPORT
    ${OPTEE_SECMGR_PATH}/../Prebuilt_client/out/export/usr
)

set(OPTEE_OS_EXPORT
    ${OPTEE_SECMGR_PATH}/../Prebuilt_OS/arm-plat-k3/export-ta_arm64
)

set(TA_DEV_KIT_DIR
    ${OPTEE_OS_EXPORT}/mk/ta_dev_kit.mk
)

# TA ANALYSIS ONLY TARGET

file(GLOB TA_ANALYSIS_SOURCES
    ${TA_SRC_DIR}/*.c
)

add_library(securitystorage_ta_analysis OBJECT
    ${TA_ANALYSIS_SOURCES}
)

target_include_directories(securitystorage_ta_analysis
    PRIVATE
        ${TA_SRC_DIR}/include
        ${OPTEE_OS_EXPORT}/include
)

target_compile_definitions(securitystorage_ta_analysis
    PRIVATE
        TA_ANALYSIS_ONLY
)


# REAL TA BUILD

add_custom_target(securitystorage_ta
    COMMAND ${MAKE_BIN}
            -C ${TA_SRC_DIR}
            CROSS_COMPILE64=${CROSS_COMPILE}
    WORKING_DIRECTORY ${TA_SRC_DIR}
    USES_TERMINAL
    COMMENT "Building SecureStorageCrypto Trusted Application"
)

add_custom_target(securitystorage_ta_clean
    COMMAND ${MAKE_BIN} -C ${TA_SRC_DIR} 
            TA_DEV_KIT_DIR=${OPTEE_OS_EXPORT}
            clean
    WORKING_DIRECTORY ${TA_SRC_DIR}
    USES_TERMINAL
    COMMENT "Cleaning SecureStorageCrypto TA"
)


# CA BUILD

add_executable(securitystorage_ca
    ${CA_SRC_DIR}/src/securitystorage_crypto_ca.c
    ${CA_SRC_DIR}/src/M1M2M3toPlainsym.c
    ${OPTEE_SECMGR_PATH}/src/optee_securestorage_crypto.c
    ${OPTEE_SECMGR_PATH}/otp_CA_TA/host/src/Security_otp.c


)

target_include_directories(securitystorage_ca
    PRIVATE
        ${CA_SRC_DIR}/include
        ${TA_SRC_DIR}/include
        ${OPTEE_CLIENT_EXPORT}/include
        ${OPTEE_OS_EXPORT}/include/k3
)

target_link_directories(securitystorage_ca
    PRIVATE
        ${OPTEE_CLIENT_EXPORT}/lib
)

target_link_libraries(securitystorage_ca
    ${OPTEE_CLIENT_EXPORT}/lib/libteec.so.2.0.0
    OpenSSL::Crypto
)

target_link_options(securitystorage_ca PRIVATE
    -Wl,--no-whole-archive
)


# DEPENDENCY ORDER

add_dependencies(securitystorage_ta_analysis securitystorage_ta)
add_dependencies(securitystorage_ca securitystorage_ta_analysis)
