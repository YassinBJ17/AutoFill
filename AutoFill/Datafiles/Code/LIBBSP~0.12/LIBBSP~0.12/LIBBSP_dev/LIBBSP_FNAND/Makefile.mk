LIB_FOLDER := ../../LIBBSP_gen/LIBBSP_FNAND/lib
LIB_NAME := LIBBSP_FNAND
SCI := LIBBSP
OBJ_FOLDER := ../../LIBBSP_gen/LIBBSP_FNAND/obj
SOURCES_FILES:=\
LIBBSP_FNAND_Globals.c\
LIBBSP_FNAND_CardIdentification.c \
LIBBSP_FNAND_Configure.c \
LIBBSP_FNAND_Init.c \
LIBBSP_FNAND_Erase.c \
LIBBSP_FNAND_GetResponse.c \
LIBBSP_FNAND_GetStatus.c \
LIBBSP_FNAND_InitCard.c \
LIBBSP_FNAND_InitHost.c \
LIBBSP_FNAND_IsElapsed.c \
LIBBSP_FNAND_MemoryWearInfo.c \
LIBBSP_FNAND_Read_Multiblock_NoDMA.c \
LIBBSP_FNAND_Read_Multiblock.c \
LIBBSP_FNAND_Read_NoDMA.c \
LIBBSP_FNAND_Read_Singleblock_NoDMA.c \
LIBBSP_FNAND_Read_Singleblock.c \
LIBBSP_FNAND_Read.c \
LIBBSP_FNAND_ResetCard.c \
LIBBSP_FNAND_ResetDataBus.c \
LIBBSP_FNAND_SelectCard.c \
LIBBSP_FNAND_SelectSector.c \
LIBBSP_FNAND_SendCID.c \
LIBBSP_FNAND_SendCommand.c \
LIBBSP_FNAND_SendConfig.c \
LIBBSP_FNAND_SendCSD.c \
LIBBSP_FNAND_SendExtCSD.c \
LIBBSP_FNAND_SetBlockCount.c \
LIBBSP_FNAND_SetBlockSize.c \
LIBBSP_FNAND_SetBusConf.c \
LIBBSP_FNAND_StopTransmission.c \
LIBBSP_FNAND_UpdateStatus.c \
LIBBSP_FNAND_VoltageValidation.c \
LIBBSP_FNAND_Wait.c \
LIBBSP_FNAND_Write_Multiblock_NoDMA.c \
LIBBSP_FNAND_Write_Multiblock.c \
LIBBSP_FNAND_Write_NoDMA.c \
LIBBSP_FNAND_Write_Singleblock_NoDMA.c \
LIBBSP_FNAND_Write_Singleblock.c \
LIBBSP_FNAND_Write.c 

INCLUDE_FILES := includes ../../LIBBSP_api/LIBBSP_FNAND ../../LIBMCP_api ../../QACG_StdLib_source/MCP_StdLib_source \
../../LIBBSP_api/LIBBSP_CCSR\
../../LIBBSP_api/LIBBSP_CMN\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man

include ../../Makefile/MakefileLib.mk
