LIB_NAME := MEM
SCI := LIBUTI
SOURCES_FILES :=\
LIBUTI_MEM.c
INCLUDE_FILES := ../../LIBMCP_api \
../../LIBUTI_api/MEM

include ../../Makefile/MakefileLib.mk

CFLAGS += $(EXTRA_CFLAGS)
