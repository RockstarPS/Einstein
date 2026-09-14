export V ?= 0

OUTPUT_DIR := $(CURDIR)/out

CA_TA_LIST := $(subst /,,$(dir $(wildcard */Makefile)))

.PHONY: all
all: CA_TA prepare-for-rootfs

.PHONY: clean
clean: CA_TA-clean prepare-for-rootfs-clean

CA_TA:
	@for ca_ta in $(CA_TA_LIST); do \
		$(MAKE) -C $$ca_ta CROSS_COMPILE="$(HOST_CROSS_COMPILE)" || exit 1; \
	done

CA_TA-clean:
	@for ca_ta in $(CA_TA_LIST); do \
		$(MAKE) -C $$ca_ta clean || exit 1; \
	done

prepare-for-rootfs: CA_TA
	@echo "Copying ca_ta CA and TA binaries to $(OUTPUT_DIR)..."
	@mkdir -p $(OUTPUT_DIR)/ta
	@mkdir -p $(OUTPUT_DIR)/plugins
	@mkdir -p $(OUTPUT_DIR)/lib
	@mkdir -p $(OUTPUT_DIR)/include
	@for ca_ta in $(CA_TA_LIST); do \
		if [ -e $$ca_ta/host/lib ]; then \
			cp -p $$ca_ta/host/lib/*.a $(OUTPUT_DIR)/lib/; \
			cp -p $$ca_ta/host/include/*.h $(OUTPUT_DIR)/include/; \
		fi; \
		if [ $$ca_ta != otp_CA_TA ]; then \
			cp -pr $$ca_ta/ta/*.ta $(OUTPUT_DIR)/ta/; \
			cp -pr $$ca_ta/ta/include/*.h $(OUTPUT_DIR)/include/; \
		fi; \
		if [ $$ca_ta = plugins_CA_TA ]; then \
			cp -p plugins_CA_TA/syslog/*.plugin $(OUTPUT_DIR)/plugins/; \
		fi; \
	done

prepare-for-rootfs-clean:
	@rm -rf $(OUTPUT_DIR)/ta
	@rm -rf $(OUTPUT_DIR)/ca
	@rm -rf $(OUTPUT_DIR)/plugins
	@rm -rf $(OUTPUT_DIR)/lib
	@rm -rf $(OUTPUT_DIR)/include
	@rmdir --ignore-fail-on-non-empty $(OUTPUT_DIR) || test ! -e $(OUTPUT_DIR)
