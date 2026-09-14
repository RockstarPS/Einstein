FILES_C = $(PROJECT_PATH)/src/main.c\
    $(PROJECT_PATH)/stubs/stubs.c\
    $(PROJECT_PATH)/mem/Fee/src/Fee.c\
    $(PROJECT_PATH)/mem/NvM/src/NvM.c\
    $(PROJECT_PATH)/mem/SNvM/src/SNvM.c\
    $(PROJECT_PATH)/mem/Memif/src/Memif.c\
    $(PROJECT_PATH)/mem/FeeExt/src/FeeExt.c\
    $(PROJECT_PATH)/mem/memlib/src/MemLib.c\
    $(PROJECT_PATH)/mem/crc/src/Crc.c\
    $(PROJECT_PATH)/mem_cfg/Fee_Cfg.c\
    $(PROJECT_PATH)/mem_cfg/MemIf_Lcfg.c\
    $(PROJECT_PATH)/mem_cfg/NvM_Cfg.c\
    $(PROJECT_PATH)/mem_cfg/NvMExt_Cfg.c\
    $(PROJECT_PATH)/mem_cfg/SNvM_Cfg.c\
    $(PROJECT_PATH)/src/EmulatedEEPROM.c\
    $(PROJECT_PATH)/src/SrecMake.c\
    $(PROJECT_PATH)/cfg/NvMDefault_Cfg.c\
    $(PROJECT_PATH)/cfg/General_Cfg.c\
    $(PROJECT_PATH)/cfg/FlsConst_Cfg.c\


INCLUDES =-I$(PROJECT_PATH)/mem/Ea/src\
    -I$(PROJECT_PATH)/inc\
    -I$(PROJECT_PATH)/mem/Fee/src\
    -I$(PROJECT_PATH)/mem/NvM/src\
    -I$(PROJECT_PATH)/mem/crc/src\
    -I$(PROJECT_PATH)/mem/SNvM/src\
    -I$(PROJECT_PATH)/mem/Memif/src\
    -I$(PROJECT_PATH)/mem/FeeExt/src\
    -I$(PROJECT_PATH)/mem/memlib/src\
    -I$(PROJECT_PATH)/mem_cfg\
    -I$(PROJECT_PATH)/cfg\
    -I$(PROJECT_PATH)/src\
    -I$(PROJECT_PATH)/stubs\

