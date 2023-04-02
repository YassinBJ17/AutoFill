LIB_NAME := LIBBSP_UART
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_UART_InitInputLink.c\
LIBBSP_UART_InitOutputLink.c\
LIBBSP_UART_Launch.c\
LIBBSP_UART_ActivateRead.c\
LIBBSP_UART_ActivateWrite.c\
LIBBSP_UART_Read.c\
LIBBSP_UART_CheckUART.c\
LIBBSP_UART_CheckPLDErrors.c\
LIBBSP_UART_CheckIndex.c\
LIBBSP_UART_CheckRollOver.c\
LIBBSP_UART_ReadLastValidBytes.c\
LIBBSP_UART_ReadValidBytes.c\
LIBBSP_UART_Write.c\
LIBBSP_UART_Globals.c\

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_UART\
../../LIBBSP_api/LIBBSP_CMN\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_MEGREG

include ../../Makefile/MakefileLib.mk




