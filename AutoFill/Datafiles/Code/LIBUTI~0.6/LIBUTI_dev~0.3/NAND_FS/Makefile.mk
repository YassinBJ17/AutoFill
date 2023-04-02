LIB_NAME := NAND_FS
SCI := LIBUTI
SOURCES_FILES := \
LIBUTI_NAND_FS_Check.c \
LIBUTI_NAND_FS_CheckSubZone.c \
LIBUTI_NAND_FS_Commit.c \
LIBUTI_NAND_FS_Format.c \
LIBUTI_NAND_FS_Global.c \
LIBUTI_NAND_FS_Info.c \
LIBUTI_NAND_FS_Init.c \
LIBUTI_NAND_FS_DrvInit.c \
LIBUTI_NAND_FS_NextSubZone.c \
LIBUTI_NAND_FS_Read.c \
LIBUTI_NAND_FS_Reset.c \
LIBUTI_NAND_FS_SearchZoneByZoneId.c \
LIBUTI_NAND_FS_Update.c\
LIBUTI_NAND_FS_Get_FS.c\
LIBUTI_NAND_FS_Init_Reset.c\
LIBUTI_NAND_FS_Update_No_Loop.c

INCLUDE_FILES := ../../LIBMCP_api \
../../LIBUTI_api/NAND_FS \
../../LIBUTI_api/CRC \
../../LIBUTI_api/MEM \
../../LIBBSP_api/LIBBSP_TYPE/inc_gen \
../../LIBBSP_api/LIBBSP_TYPE/inc_man \
../../LIBBSP_api/LIBBSP_SPI \
../../LIBBSP_api/LIBBSP_MRAM

include ../../Makefile/MakefileLib.mk

CFLAGS += $(EXTRA_CFLAGS)
