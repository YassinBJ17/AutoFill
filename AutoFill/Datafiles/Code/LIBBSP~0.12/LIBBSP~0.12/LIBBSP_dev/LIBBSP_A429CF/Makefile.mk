LIB_NAME := LIBBSP_A429CF
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_A429CF_MuxSelection.c\
LIBBSP_A429CF_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_A429CF ../../LIBMCP_api\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_MEGREG

include ../../Makefile/MakefileLib.mk
