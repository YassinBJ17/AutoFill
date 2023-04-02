LIB_NAME := LIBBSP_PQRFS
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_PQRFS_Activate.c\
LIBBSP_PQRFS_Anchor.c\
LIBBSP_PQRFS_Deactivate_Line.c\
LIBBSP_PQRFS_Globals.c\
LIBBSP_PQRFS_Init_Cycle.c\
LIBBSP_PQRFS_Init_Label.c\
LIBBSP_PQRFS_Init_tic_data.c\
LIBBSP_PQRFS_Status.c\
LIBBSP_PQRFS_Write.c


INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_PQRFS\
../../LIBBSP_api/LIBBSP_BLADES\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\


include ../../Makefile/MakefileLib.mk

