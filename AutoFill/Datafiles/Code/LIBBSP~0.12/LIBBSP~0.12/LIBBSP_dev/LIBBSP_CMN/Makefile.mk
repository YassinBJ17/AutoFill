LIB_NAME := LIBBSP_CMN
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_CMN_GetTicks.c\
LIBBSP_CMN_IsElapsed.c\
LIBBSP_CMN_Wait.c\
LIBBSP_CMN_WaitForTrueCondition.c\
LIBBSP_CMN_CheckElapsedTime.c\
LIBBSP_CMN_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_CMN ../../LIBMCP_api\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man

include ../../Makefile/MakefileLib.mk




