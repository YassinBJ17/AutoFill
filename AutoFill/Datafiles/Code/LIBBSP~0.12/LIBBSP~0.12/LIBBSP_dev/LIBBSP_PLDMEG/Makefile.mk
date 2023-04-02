LIB_NAME := LIBBSP_PLDMEG
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_PLDMEG_GetVersion.c\
LIBBSP_PLDMEG_GetStatus.c\
LIBBSP_PLDMEG_SetHpmsReset.c\
LIBBSP_PLDMEG_RegSelect.c\
LIBBSP_PLDMEG_Globals.c


INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_PLDMEG\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_MEGREG


include ../../Makefile/MakefileLib.mk

