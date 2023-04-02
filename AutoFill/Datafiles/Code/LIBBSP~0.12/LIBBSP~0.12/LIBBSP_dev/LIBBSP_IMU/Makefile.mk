LIB_NAME := LIBBSP_IMU
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_IMU_Activation.c\
LIBBSP_IMU_GetReadInertialData.c\
LIBBSP_IMU_ProgReadInertialData.c\
LIBBSP_IMU_Zero.c\
LIBBSP_IMU_F40toF64.c\
LIBBSP_IMU_ProgPrecStatusCommand.c\
LIBBSP_IMU_ProgAdditionalReadData.c\
LIBBSP_IMU_GetAdditionalReadData.c\
LIBBSP_IMU_RazReadData.c\
LIBBSP_IMU_ProgAdditionalWrite.c\
LIBBSP_IMU_RazWriteData.c\
LIBBSP_IMU_Globals.c



INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_IMU\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_MEGREG

include ../../Makefile/MakefileLib.mk




