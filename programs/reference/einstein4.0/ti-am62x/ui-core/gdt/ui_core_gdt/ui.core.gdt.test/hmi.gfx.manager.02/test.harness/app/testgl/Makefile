ifeq ($(GNU_PATH),)
GNU_PATH = C:/usr/target/linux/SDK
endif

ifeq ($(ROOTFS),)
ROOTFS = $(GNU_PATH)/marco2
endif

GNUTOOL_PATH=$(GNU_PATH)/bin
GNUTOOL_PREFIX=\arm-none-linux-gnueabi-
CC = $(GNUTOOL_PATH)$(GNUTOOL_PREFIX)gcc
AR = $(GNUTOOL_PATH)$(GNUTOOL_PREFIX)ar


TARGET_PATH_LIB = $(ROOTFS)/usr/lib
EXTRA_HEADER_PATH =$(ROOTFS)/usr/include
SOURCE_PATH = ./

CFLAGS= -Wall -mfloat-abi=softfp -mfpu=vfp  -D_LINUX \
		-DNO_SMARX_DONGLE \
		-DMATRIX_TYPE_FLOAT \
		-DHAS_ZLIB \
		-DNO_FLEXLM \
		-DNO_LICENSE \
		-DLINUX \
		-DNOSOUND \
		-DNOCRYPT \
		-DNOUNCRYPT


EXTRA_CFLAGS = 	-I$(EXTRA_HEADER_PATH)	\
				-I$(SOURCE_PATH)		

EXTRA_CPPFLAGS = 	-I$(EXTRA_HEADER_PATH)	\
				-I$(SOURCE_PATH)	


LDFLAGS= -Wl,--library-path=$(ROOTFS)/usr/lib,-rpath-link=$(ROOTFS)/usr/lib  -lopengles -lpthread -lm -lstdc++

BIN_PATH       = $(subst \,/,$(CURDIR)/$(PLATFORM))	

SOURCES=		$(SOURCE_PATH)/testgl.c	\
				$(SOURCE_PATH)/bmp_loader.c

OBJECTS=$(SOURCES:.c=.o)

EXECUTABLE=run

.PHONY: all

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
#	$(AR) -t $(ROOTFS)/usr/lib/libopengles.a
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(EXTRA_CPPFLAGS) -c $< -o $@
.c.o:
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -c $< -o $@	

.PHONY: clean
clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(OBJECTS2)
