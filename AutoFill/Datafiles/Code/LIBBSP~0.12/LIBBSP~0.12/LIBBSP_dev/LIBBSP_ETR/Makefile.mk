LIB_NAME := LIBBSP_ETR
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_ETR_Close.c\
LIBBSP_ETR_Configure.c\
LIBBSP_ETR_ReadInfos.c\
LIBBSP_ETR_Open.c\
LIBBSP_ETR_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_ETR ../../LIBBSP_api/LIBBSP_I2C\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man

include ../../Makefile/MakefileLib.mk




