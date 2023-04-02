LIB_NAME := LIBBSP_ENVM
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_ENVM_Close.c\
LIBBSP_ENVM_Configure.c\
LIBBSP_ENVM_Open.c\
LIBBSP_ENVM_Read.c\
LIBBSP_ENVM_Read_Compagnon.c\
LIBBSP_ENVM_Read_Megatice.c\
LIBBSP_ENVM_ReadAddrs.c\
LIBBSP_ENVM_ReadAddrs_Compagnon.c\
LIBBSP_ENVM_ReadAddrs_Megatice.c\
LIBBSP_ENVM_Write.c\
LIBBSP_ENVM_Write_Compagnon.c\
LIBBSP_ENVM_Write_Megatice.c\
LIBBSP_ENVM_WriteCtrl_Compagnon.c\
LIBBSP_ENVM_WriteCtrl_Megatice.c\
LIBBSP_ENVM_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_PLDMEG ../../LIBBSP_api/LIBBSP_ENVM ../../LIBBSP_api/LIBBSP_CMN ../../LIBBSP_api/LIBBSP_SHM ../../LIBBSP_api/LIBBSP_PLDCMP \
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man

include ../../Makefile/MakefileLib.mk




