LIB_NAME := COMMON
SCI := LIBUTI
SOURCES_FILES :=\
LIBUTI_CMN_IdentifySupportFiles.c \
LIBUTI_CMN_ParseCMP.c \
LIBUTI_CMN_ParseLUD.c \
LIBUTI_CMN_ParseSUP.c \
LIBUTI_CMN_TestCompatibilityBetweenLoads.c\
LIBUTI_CMN_IsCompatible.c\
LIBUTI_CMN_MatchingFiles.c\
LIBUTI_CMN_TestSupportFile.c

INCLUDE_FILES := ../../LIBMCP_api \
../../LIBUTI_api/COMMON \
../../LIBUTI_api/ARINC_665 \
../../LIBUTI_api/SHA

include ../../Makefile/MakefileLib.mk

CFLAGS += $(EXTRA_CFLAGS)
