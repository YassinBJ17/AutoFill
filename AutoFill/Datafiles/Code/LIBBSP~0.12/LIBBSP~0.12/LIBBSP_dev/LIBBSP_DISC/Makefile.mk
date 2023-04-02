LIB_NAME := LIBBSP_DISC
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_DISC_Globals.c\
LIBBSP_DISC_Close.c\
LIBBSP_DISC_Configure.c\
LIBBSP_DISC_GetReadDisc.c\
LIBBSP_DISC_Open.c\
LIBBSP_DISC_Read.c\
LIBBSP_DISC_ReadNoWait.c\
LIBBSP_DISC_Step.c\
LIBBSP_DISC_Write.c\
LIBBSP_DISC_WriteNoWait.c\
LIBBSP_DISC_WriteReg.c\

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_DISC ../../LIBBSP_api/LIBBSP_I2C ../../LIBMCP_api\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man

include ../../Makefile/MakefileLib.mk




