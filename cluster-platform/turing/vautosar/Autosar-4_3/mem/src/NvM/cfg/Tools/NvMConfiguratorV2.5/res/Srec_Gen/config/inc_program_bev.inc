FILES_C =$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/src/main.c\
        $(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/src/Nvm_Writer.c\
        $(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/src/SrecMake.c\
        $(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/src/Nvm_BlockLengthCalc.c\
        $(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/src/Eep_Driver.c\
        $(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/src/Stubs.c\
        $(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/src/Dummy.c\
        $(RTC_PRJ_PATH)/turing.bsw.nvmmgr/Memif/src/MemIf.c\
        $(RTC_PRJ_PATH)/turing.bsw.nvmmgr/Ea/src/Ea.c\
        $(RTC_PRJ_PATH)/turing.bsw.nvmmgr/NvM/src/NvM.c\
        $(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvM_gen/Ea_Cfg.c\
        $(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvM_gen/MemIf_Lcfg.c\
        $(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvM_gen/NvM_Cfg.c\
        $(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/stubs/Crc.c\

INCLUDES =-I$(RTC_PRJ_PATH)/turing.bsw.nvmmgr/Memif/src\
        -I$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/inc\
		-I$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/stubs/LIB_Cmp\
        -I$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/stubs/Fee\
        -I$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/config\
        -I$(RTC_PRJ_PATH)/turing.bsw.nvmmgr/Ea/src\
        -I$(RTC_PRJ_PATH)/turing.bsw.nvmmgr/NvM/src\
        -I$(RTC_PRJ_PATH)/turing.bsw.crclib/src\
		-I$(RTC_PRJ_PATH)/turing.bsw.errmgr/src\
        -I$(RTC_PRJ_PATH)/turing.bsw.memlib/src\
		-I$(RTC_PRJ_PATH)/vp.build.2021.honda.bev.ic/includes\
        -I$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/include\
        -I$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvM_gen\
        -I$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/dem\
        -I$(RTC_PRJ_PATH)/vp.module.mcuext.2021.honda.bev.ic/src\
        -I$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/crclib\
        -I$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/os\
		-I$(RTC_PRJ_PATH)/turing.3rd.mcal.imx8/plugins/Base/include\
        -I$(RTC_PRJ_PATH)/vp.gen.2021.honda.bev.ic.bsw/bsw/nvm/NvMConfiguratorV2.2.1/res/Srec_Gen/inc/Dummy_includes\
    