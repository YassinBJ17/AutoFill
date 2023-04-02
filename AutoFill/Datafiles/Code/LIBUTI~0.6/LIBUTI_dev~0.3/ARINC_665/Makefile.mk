LIB_NAME := ARINC_665
SCI := LIBUTI
SOURCES_FILES := \
LIBUTI_A665_ParseLUH_DataFiles.c \
LIBUTI_A665_ParseLUH_Init.c \
LIBUTI_A665_ParseLUH_NumberOfFiles.c \
LIBUTI_A665_ParseLUH_Part3.c \
LIBUTI_A665_ParseLUH_Part3Fields.c \
LIBUTI_A665_ParseLUH_Part3Targets.c \
LIBUTI_A665_ParseLUH_SupportFiles.c \
LIBUTI_A665_ParseLUH_Target.c \
LIBUTI_A665_ParseLUH_VersionPN.c \
LIBUTI_A665_ParseLUH.c

INCLUDE_FILES := ../../LIBMCP_api \
../../LIBUTI_api/ARINC_665 \
../../LIBUTI_api/MEM \
../../QACG_StdLib_source/MCP_StdLib_source

include ../../Makefile/MakefileLib.mk

CFLAGS += $(EXTRA_CFLAGS)
