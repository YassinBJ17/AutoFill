LIB_NAME := LIBBSP_SPI
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_SPI_Close.c\
LIBBSP_SPI_Copy_In_FIFO.c\
LIBBSP_SPI_Exchange.c\
LIBBSP_SPI_Open.c\
LIBBSP_SPI_IOCtrl.c\
LIBBSP_SPI_ReceiveData.c\
LIBBSP_SPI_WaitEndOfCom.c\
LIBBSP_SPI_Write1Bytes.c\
LIBBSP_SPI_Write2Bytes.c\
LIBBSP_SPI_Write4Bytes.c\
LIBBSP_SPI_Write6Bytes.c\
LIBBSP_SPI_Read1Bytes.c\
LIBBSP_SPI_Read2Bytes.c\
LIBBSP_SPI_Globals.c


INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_SPI ../../LIBBSP_api/LIBBSP_CMN\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_CCSR

include ../../Makefile/MakefileLib.mk




