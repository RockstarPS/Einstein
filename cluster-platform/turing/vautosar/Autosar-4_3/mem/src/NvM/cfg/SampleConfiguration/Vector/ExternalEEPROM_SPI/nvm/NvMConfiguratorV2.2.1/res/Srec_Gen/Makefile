## Include paths
include config/inc_program_s2dot8.inc
include config/specific_defines.inc

## General Flags
TARGET = Srec_Gen.exe

## Project PATH, DO NOT EDIT, relative path
PROJECT_PATH = $(subst \,/,$(CMD_PROJECT_PATH))
RTC_PRJ_PATH = $(subst \,/,C:\__GIT\S2dot8)

CC = gcc
CFLAGS = -Wall -Wno-unknown-pragmas -Wno-missing-braces -std=c99

FILES_C_NOEXT = $(subst .c, ,$(FILES_C))

## Objects that must be built in order to link
OBJECTS_C = $(foreach file,$(FILES_C_NOEXT), $(addsuffix .o,$(file)))

## Objects that must be built in order to link used by linker (list of objects files)
OBJECTS =  $(filter %.o, $(subst /, ,$(OBJECTS_C)))

## Objects explicitly added by the user
LINKONLYOBJECTS = 

DEFINES += -DWIN32

.PHONY: all
all: build link

## Build
.PHONY: build
build: $(OBJECTS_C)
## Compile
$(OBJECTS_C): %.o : %.c
	@echo "Compiling $<"
	@$(CC) $(INCLUDES) $(CFLAGS) $(DEFINES) -c -g $< -o $(PROJECT_PATH)/obj/$(filter %.o, $(subst /, ,$@))

## Module 
link: $(TARGET)
## Link
$(TARGET): $(OBJECTS_C)
	@$(CC) -Xlinker $(addprefix obj/,$(OBJECTS)) $(LINKONLYOBJECTS) -Xlinker -g -o$(TARGET)
