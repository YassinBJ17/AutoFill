LIB_NAME := LIBBSP_GPIO
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_GPIO_Configure.c\
LIBBSP_GPIO_Read.c\
LIBBSP_GPIO_Write.c\
LIBBSP_GPIO_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_GPIO\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_CCSR

include ../../Makefile/MakefileLib.mk




