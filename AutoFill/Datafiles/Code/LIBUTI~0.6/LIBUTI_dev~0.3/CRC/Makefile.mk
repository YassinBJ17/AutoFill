LIB_NAME := CRC
SCI := LIBUTI
SOURCES_FILES := LIBUTI_CRC.c\
LIBUTI_CRC_Update.c
INCLUDE_FILES := ../../LIBMCP_api \
../../LIBUTI_api/CRC

include ../../Makefile/MakefileLib.mk

CFLAGS += $(EXTRA_CFLAGS)
