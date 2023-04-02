LIB_NAME := LIBBSP_A429
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_A429_ActivateRead.c\
LIBBSP_A429_InitInputLink.c\
LIBBSP_A429_Read.c\
LIBBSP_A429_ReadError.c\
LIBBSP_A429_ActivateWrite.c\
LIBBSP_A429_InitOutputLink.c\
LIBBSP_A429_Launch.c\
LIBBSP_A429_Write.c\
LIBBSP_A429_ReadFifo.c\
LIBBSP_A429_Globals.c\
Mask_Bit.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_A429\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_MEGREG

include ../../Makefile/MakefileLib.mk




