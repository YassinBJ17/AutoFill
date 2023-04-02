LIB_NAME := LIBBSP_BLADES
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_BLADES_Anchor.c\
LIBBSP_BLADES_RestartBlades.c\
LIBBSP_BLADES_StopBlades.c\
LIBBSP_BLADES_Write.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_BLADES\
../../LIBBSP_api/LIBBSP_CMN\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\


include ../../Makefile/MakefileLib.mk

