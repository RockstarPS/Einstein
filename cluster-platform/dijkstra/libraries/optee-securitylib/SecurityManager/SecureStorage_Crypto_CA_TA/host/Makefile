CC      ?= $(CROSS_COMPILE)gcc
LD      ?= $(CROSS_COMPILE)ld
AR      ?= $(CROSS_COMPILE)ar
NM      ?= $(CROSS_COMPILE)nm
OBJCOPY ?= $(CROSS_COMPILE)objcopy
OBJDUMP ?= $(CROSS_COMPILE)objdump
READELF ?= $(CROSS_COMPILE)readelf

# Directories
OBJ_DIR = obj
SRC_DIR = src
LIB_DIR = lib
INC_DIR = include

OPENSSL_INCLUDE = /usr/local/openssl/include # Path to OpenSSL include directory
OPENSSL_LIB = /usr/local/openssl/lib # Path to OpenSSL library directory

# Define all source files with correct paths
SRC_FILES = $(SRC_DIR)/securitystorage_crypto_ca.c $(SRC_DIR)/M1M2M3toPlainsym.c
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:.c=.o)))

FINALOPTEELIBRARY = $(LIB_DIR)/libopteesecurity.a

# Compiler flags
CFLAGS += -Wall -I../ta/include -I./include
CFLAGS += -I$(TEEC_EXPORT)/include
CFLAGS += -I$(INC_DIR)

.PHONY: all
all: $(FINALOPTEELIBRARY)

# Define the target static library
$(FINALOPTEELIBRARY): $(OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

# Rule to build object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c  $< -o $@

.PHONY: clean
clean:
	rm -rf $(LIB_DIR) $(OBJ_DIR)