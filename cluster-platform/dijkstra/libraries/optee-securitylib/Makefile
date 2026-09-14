include imports.mak

# Target rules
optee-securitylib:
	@echo "Building OP-TEE for TI AM62x..."
	$(MAKE) -C $(SECURITY_MANAGER_SRC) CROSS_COMPILE64=$(CROSS_COMPILE) PLATFORM=k3-am62px CFG_ARM64_core=y CFG_TEE_CORE_LOG_LEVEL=2 CFG_TEE_CORE_DEBUG=y

# Clean build
optee-securitylib_clean:
	@echo "Cleaning build..."
	$(MAKE) -C $(SECURITY_MANAGER_SRC) clean

# Phony targets to avoid conflicts with files
.PHONY: optee-securitylib optee-securitylib_clean