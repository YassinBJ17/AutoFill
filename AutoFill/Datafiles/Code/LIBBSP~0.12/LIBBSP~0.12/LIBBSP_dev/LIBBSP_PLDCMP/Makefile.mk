LIB_NAME := LIBBSP_PLDCMP
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_PLDCMP_GetCmpErrors.c\
LIBBSP_PLDCMP_WriteFailDisc.c\
LIBBSP_PLDCMP_FlashWriteEnable.c\
LIBBSP_PLDCMP_SetHpmsReset.c\
LIBBSP_PLDCMP_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_PLDCMP\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_CMPREG


include ../../Makefile/MakefileLib.mk




