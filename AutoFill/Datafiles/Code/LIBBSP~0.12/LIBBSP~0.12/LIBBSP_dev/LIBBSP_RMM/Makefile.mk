LIB_NAME := LIBBSP_RMM
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_RMM_Close.c\
LIBBSP_RMM_Globals.c\
LIBBSP_RMM_Open.c\
LIBBSP_RMM_ReadBlock.c\
LIBBSP_RMM_Read.c\
LIBBSP_RMM_WritePage.c\
LIBBSP_RMM_Write.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_RMM ../../LIBBSP_api/LIBBSP_I2C ../../LIBBSP_api/LIBBSP_CMN ../../QACG_StdLib_source/MCP_StdLib_source\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man 

include ../../Makefile/MakefileLib.mk




