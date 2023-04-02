LIB_NAME := LIBBSP_PSUM
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_PSUM_GetValue.c\
LIBBSP_PSUM_GetValueV.c\
LIBBSP_PSUM_GetStatus.c\
LIBBSP_PSUM_Globals.c\
LIBBSP_PSUM_InitThreshold.c\
LIBBSP_PSUM_InitDefaultThreshold.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_PSUM ../../LIBBSP_api/LIBBSP_MATH\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_CMPREG

include ../../Makefile/MakefileLib.mk




