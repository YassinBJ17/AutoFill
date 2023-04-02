LIB_NAME := LIBBSP_SHM
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_SHM_GetMode.c\
LIBBSP_SHM_GetStatus.c\
LIBBSP_SHM_GetVersion.c\
LIBBSP_SHM_Reset.c\
LIBBSP_SHM_SetMode.c\
LIBBSP_SHM_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_SHM\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_CMPREG

include ../../Makefile/MakefileLib.mk

