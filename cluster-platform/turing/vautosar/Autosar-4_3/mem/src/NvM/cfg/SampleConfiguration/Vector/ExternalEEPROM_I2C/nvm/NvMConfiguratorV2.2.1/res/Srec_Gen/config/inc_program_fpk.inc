FILES_C = $(PROJECT_PATH)/src/main.c\
        $(PROJECT_PATH)/src/Nvm_Writer.c\
        $(PROJECT_PATH)/src/SrecMake.c\
        $(PROJECT_PATH)/src/Nvm_BlockLengthCalc.c\
        $(PROJECT_PATH)/src/Fls_Simulator.c\
        $(PROJECT_PATH)/src/Stubs.c\
        $(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/sys/crc/src/src/Crc.c\
        $(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/mem/src/Memif/src/MemIf.c\
        $(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/mem/src/Fee/src/Fee.c\
        $(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/bsw-gen/bsw/nvm/Fee_Cfg.c\
        $(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/bsw-gen/bsw/nvm/MemIf_Lcfg.c\
        $(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/mem/src/NvM/src/NvM.c\
        $(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/mem/src/SNvM/src/SNvM.c\
        $(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/bsw-gen/bsw/nvm/NvM_Cfg.c\
        $(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/bsw-gen/bsw/nvm/SNvM_Cfg.c\


INCLUDES =-I$(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/mem/src/Memif/src\
        -I$(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/mem/src/Fee/src\
        -I$(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/diag/dem/vw/src\
        -I$(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/diag/dem/src\
        -I$(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/mem/src/NvM/src\
        -I$(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/mem/src/SNvM/src\
        -I$(RTC_PRJ_PATH)/cluster-platform/turing/vautosar/sys/crc/src/src\
        -I$(RTC_PRJ_PATH)/cluster-platform/turing/lib/memlib/src/src\
        -I$(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/vp-build/stubs/include\
        -I$(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/bsw-gen/bsw/nvm\
        -I$(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/bsw-gen/bsw/dem\
        -I$(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/ecumext/src/src\
        -I$(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/bsw-gen/bsw/crc\
        -I$(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/bsw-gen/bsw/os\
        -I$(RTC_PRJ_PATH)/programs/vw/my2022/fpkb8/vp-build/stubs\
        -I$(PROJECT_PATH)/inc/Dummy_includes\
        -I$(PROJECT_PATH)/inc\
        -I$(PROJECT_PATH)/stubs/LIB_Cmp\
        -I$(PROJECT_PATH)/stubs/Fee\
        -I$(PROJECT_PATH)/config\
        -I$(PROJECT_PATH)/stubs\