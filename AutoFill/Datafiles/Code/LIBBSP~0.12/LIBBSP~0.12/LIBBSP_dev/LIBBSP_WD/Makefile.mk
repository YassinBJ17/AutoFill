LIB_NAME := LIBBSP_WD
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_WD_InitDelay.c\
LIBBSP_WD_Rearm.c\
LIBBSP_WD_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_WD\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_CMPREG

include ../../Makefile/MakefileLib.mk




