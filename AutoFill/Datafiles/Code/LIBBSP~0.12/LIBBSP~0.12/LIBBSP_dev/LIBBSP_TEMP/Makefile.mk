LIB_NAME := LIBBSP_TEMP
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_TEMP_Close.c\
LIBBSP_TEMP_Configure.c\
LIBBSP_TEMP_GetTemp.c\
LIBBSP_TEMP_Open.c\
LIBBSP_TEMP_ReadTemp.c\
LIBBSP_TEMP_ReadTempStep.c\
LIBBSP_TEMP_WriteReg.c\
LIBBSP_TEMP_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_TEMP ../../LIBBSP_api/LIBBSP_I2C ../../LIBMCP_api\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man

include ../../Makefile/MakefileLib.mk




