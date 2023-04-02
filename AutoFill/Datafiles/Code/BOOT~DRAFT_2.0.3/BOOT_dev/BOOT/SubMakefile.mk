LIB_NAME := $(shell pwd | sed 's/.*\///g')
OBJ_FOLDER := ../../../BOOT_gen/BOOT/$(LIB_NAME)/obj
LIB_FOLDER := ../../../BOOT_gen/BOOT/$(LIB_NAME)/lib
SOURCES_FILES := $(wildcard *.c)
SOURCES_FILES_S := $(wildcard *.s)

INCLUDE_FILES :=	$(sort $(dir $(wildcard ../*/) \
					$(wildcard ../*/*/) \
					$(wildcard ../../../LIB*_api/*/) \
					$(wildcard ../../../LIB*_api/*/*/) \
					$(wildcard ../../../LIB*_api/*/*/*/) \
					$(wildcard ../../../LIB*_api/*/*/*/*/) \
					$(wildcard ../../../QACG_StdLib_source/MCP_StdLib_source/)))

include ../../../Makefile/MakefileLibGenerical.mk

CFLAGS += $(EXTRA_CFLAGS)
