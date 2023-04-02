LIB_NAME := LIBBSP_FNOR
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_FNOR_Open.c\
LIBBSP_FNOR_Erase.c\
LIBBSP_FNOR_CloseErase.c\
LIBBSP_FNOR_Write.c\
LIBBSP_FNOR_Read.c\
LIBBSP_FNOR_FastRead.c\
LIBBSP_FNOR_ReadPage.c\
LIBBSP_FNOR_GetAvailability.c\
LIBBSP_FNOR_Close.c\
LIBBSP_FNOR_Globals.c\
LIBBSP_FNOR_PrepareCommand.c\
LIBBSP_FNOR_WritePage.c\
LIBBSP_FNOR_EraseCmd.c\
LIBBSP_FNOR_ReadPageSeg.c\
LIBBSP_FNOR_ReadEnable.c\
LIBBSP_FNOR_PrepareWritePage.c\
LIBBSP_FNOR_WritePageStatus.c\
LIBBSP_FNOR_WriteCheckAvailability.c\
LIBBSP_FNOR_WriteFirstBlock.c\
LIBBSP_FNOR_WriteNextBlock.c\
LIBBSP_FNOR_WriteLastBlock.c\
LIBBSP_FNOR_ReadCheckAvailability.c\
LIBBSP_FNOR_ClearFlagStatusReg.c\
LIBBSP_FNOR_Exit4B.c\
LIBBSP_FNOR_EnableWrite.c\
LIBBSP_FNOR_Enter4B.c\


INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_FNOR ../../LIBBSP_api/LIBBSP_SPI ../../LIBBSP_api/LIBBSP_CMN\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man

include ../../Makefile/MakefileLib.mk




