LIB_NAME := LIBBSP_TMP
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_TMP_GetTimeMs.c\
LIBBSP_TMP_GetTMP.c\
LIBBSP_TMP_GetTMPCounter.c\
LIBBSP_TMP_Configure.c\
LIBBSP_TMP_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_TMP ../../LIBBSP_api/LIBBSP_MATH\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_MEGREG

include ../../Makefile/MakefileLib.mk




