LIB_NAME := SHA
SCI := LIBUTI
SOURCES_FILES := LIBUTI_SHA_Computation.c \
LIBUTI_SHA_Wrapper.c\
LIBUTI_SHA_Transform.c

INCLUDE_FILES := ../../LIBMCP_api \
../../LIBUTI_api/SHA \
../../LIBUTI_api/MEM

include ../../Makefile/MakefileLib.mk

CFLAGS += $(EXTRA_CFLAGS)
