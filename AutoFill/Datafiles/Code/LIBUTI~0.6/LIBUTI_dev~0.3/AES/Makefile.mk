LIB_NAME := AES
SCI := LIBUTI
SOURCES_FILES :=\
LIBUTI_AES_decrypt.c\
LIBUTI_AES_decryptBlock.c\
LIBUTI_AES_byteOperations.c\
LIBUTI_AES_decrypt_in_place.c

INCLUDE_FILES := ../../LIBMCP_api \
../../LIBUTI_api/AES\
../../QACG_StdLib_source/MCP_StdLib_source

include ../../Makefile/MakefileLib.mk

CFLAGS += $(EXTRA_CFLAGS)
