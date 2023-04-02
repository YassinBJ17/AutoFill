LIB_NAME := LIBBSP_MRAM
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_MRAM_Close.c\
LIBBSP_MRAM_Globals.c\
LIBBSP_MRAM_Open.c\
LIBBSP_MRAM_Read.c\
LIBBSP_MRAM_WriteBlock.c\
LIBBSP_MRAM_Write.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_MRAM ../../LIBBSP_api/LIBBSP_SPI ../../LIBBSP_api/LIBBSP_CMN\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man 

include ../../Makefile/MakefileLib.mk




