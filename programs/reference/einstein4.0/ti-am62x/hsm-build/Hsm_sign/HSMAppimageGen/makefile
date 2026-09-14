
export RM=rm -f
export COPY=cp
SYSCONFIG_VERSION=1.15.0
LD=$(HSM_SIGN_PATH)/bin/aarch64-none-elf-ld
SYSCFG_PATH ?= $(SYSCONFIG_HOME)
SW_VERSION=0x0A010021


#------HSM Configurations---#
#------HSM Configurations---#
ifeq ($(DEVICE_TYPE),hs)
DEVICE_TYPE := HS
APP_SIGNING_KEY = $(HSM_SIGN_PATH)/signing/app_degenerateKey_Prod.pem
ENC_ENABLED := no
#Path to the app image signing script
APP_IMAGE_SIGN_CMD = $(HSM_SIGN_PATH)/signing/appimage_x509_cert_gen.py
else
APP_SIGNING_KEY = $(HSM_SIGN_PATH)/signing/app_degenerateKey.pem
#Path to the app image signing script
APP_IMAGE_SIGN_CMD = $(HSM_SIGN_PATH)/signing/appimage_x509_cert_gen.py
endif
VERSION = 1.5
SYSCFG_NODE = $(SYSCFG_PATH)/nodejs/node

HSM_LOAD_ADDR=0x43C00000
#Input binary name
HSM_BINARY_NAME = hsm.bin
#Output appimage name
HSM_APPIMAGE_NAME=hsm.appimage
#HSM core boot ID for appimage
BOOTIMAGE_CORE_ID_HSM = 6
#SBL dev ID
SBL_DEV_ID=55

HSM_BINARY = $(CMAKE_RUNTIME_OUTPUT_DIRECTORY)/binaries/Hsmbinary/$(HSM_BINARY_NAME)
HSM_APPIMAGE = $(CMAKE_RUNTIME_OUTPUT_DIRECTORY)/binaries/Hsmbinary/$(HSM_APPIMAGE_NAME)
HSM_APPIMAGE_HS = $(HSM_APPIMAGE).hs
HSM_APPIMAGE_HS_FS = $(HSM_APPIMAGE).hs_fs
HSMRPCRC = vHSMrprc

HSM_RPRC_NAME = $(addsuffix .rprc, $(basename $(HSM_BINARY_NAME)))
HSM_ELF=  $(addsuffix .elf, $(basename $(HSM_BINARY_NAME)))
HSM_RPRC = $(CMAKE_RUNTIME_OUTPUT_DIRECTORY)/binaries/Hsmbinary/$(HSM_RPRC_NAME)
HSM_APPIMAGE_PARAMS = $(BOOTIMAGE_CORE_ID_HSM) $(HSM_RPRC)

BOOTIMAGE_TEMP_OUT_FILE=temp_stdout.txt

#Path to the app image signing script
APP_IMAGE_SIGN_CMD = $(HSM_SIGN_PATH)/signing/appimage_x509_cert_gen.py

MULTI_CORE_IMAGE_GEN=$(HSM_SIGN_PATH)/multicoreImageGen/MulticoreImageGen$(EXE_EXT)
OUTRPRC_CMD = $(SYSCFG_NODE) $(HSM_SIGN_PATH)/out2rprc/elf2rprc.js

ifeq ($(OS), Windows_NT)
	PYTHON=python
else
	PYTHON=python3
endif

#################################################################################
# Targets
#################################################################################
ifeq ($(DEVICE_TYPE),HS)
all: $(HSM_APPIMAGE_HS)
else
all: $(HSM_APPIMAGE) $(HSM_APPIMAGE_HS_FS)
endif

.INTERMEDIATE: $(HSM_ELF)
ifeq ($(DEVICE_TYPE),HS)
$(HSM_APPIMAGE_HS): $(HSM_RPRC)
else
$(HSM_APPIMAGE): $(HSM_RPRC)
$(HSM_APPIMAGE_HS_FS): $(HSM_RPRC)
endif
	@echo .
	@echo Creating
	$(MULTI_CORE_IMAGE_GEN) LE $(SBL_DEV_ID) $(HSM_APPIMAGE) $(HSM_APPIMAGE_PARAMS) >> $(BOOTIMAGE_TEMP_OUT_FILE)
	#@$(info $(LD))
ifeq ($(DEVICE_TYPE),HS)
# Sign the appimage using appimage signing script
ifeq ($(ENC_ENABLED),no)
	@echo Boot image signing: Encryption is disabled.
    #
    #   Authentication type 0 with load address 0x83000000
    #
	$(PYTHON) $(APP_IMAGE_SIGN_CMD) --bin $(HSM_APPIMAGE) --authtype 0 --loadaddr 83000000 --key $(APP_SIGNING_KEY) --output $(HSM_APPIMAGE_HS) --keyversion $(VERSION)
else
	@echo Boot image signing: Encryption is enabled.
    #
    #   Authentication type 0 with load address 0x83000000
    #
	$(PYTHON) $(APP_IMAGE_SIGN_CMD) --bin $(HSM_APPIMAGE) --authtype 0 --loadaddr 83000000 --key $(APP_SIGNING_KEY) --enc y --enckey $(APP_ENCRYPTION_KEY) --output $(HSM_APPIMAGE_HS) --keyversion $(VERSION)
	$(RM) $(HSM_APPIMAGE)-enc
endif
else
    #
    #   Authentication type 0 with load address 0x83000000
    #
	$(PYTHON) $(APP_IMAGE_SIGN_CMD) --bin $(HSM_APPIMAGE) --authtype 0 --loadaddr 83000000 --key $(APP_SIGNING_KEY) --output $(HSM_APPIMAGE_HS_FS) --keyversion $(VERSION)
endif

	$(RM) $(BOOTIMAGE_TEMP_OUT_FILE)
	@echo Combined boot image: $@ Done !!!

$(HSM_RPRC): $(HSM_ELF)
	@echo Creating ATF RPRC image
	$(OUTRPRC_CMD) $(HSM_ELF) $(SW_VERSION)>> $(BOOTIMAGE_TEMP_OUT_FILE)
	$(COPY) $(HSM_RPRC_NAME) $(HSM_RPRC) >> $(BOOTIMAGE_TEMP_OUT_FILE)
	$(RM)	$(HSM_RPRC_NAME)

$(HSM_ELF):
	$(LD) -b binary -A aarch64 --oformat elf64-littleaarch64 --section-start=.data=$(HSM_LOAD_ADDR) -e $(HSM_LOAD_ADDR) $(HSM_BINARY) -o $(HSM_ELF)


clean:
	@echo Cleaning: $(HSM_APPIMAGE)
	$(RM) $(HSM_APPIMAGE)*
	$(RM) $(HSM_RPRC)
	$(RM) *.elf
