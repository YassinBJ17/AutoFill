LIB_NAME := SIF
SCI := LIBUTI
SOURCES_FILES := LIBUTI_SIF_getters.c \
LIBUTI_SIF_iterators.c \
LIBUTI_SIF_hashes.c \
LIBUTI_SIF_main.c\
LIBUTI_SIF_get_next_file_skip.c\
LIBUTI_SIF_getters_from_headers.c

INCLUDE_FILES := ../../LIBMCP_api \
../../LIBUTI_api/SIF \
../../LIBUTI_api/SHA \
../../LIBUTI_api/MEM \
../../QACG_StdLib_source/MCP_StdLib_source \

include ../../Makefile/MakefileLib.mk

CFLAGS += $(EXTRA_CFLAGS)
