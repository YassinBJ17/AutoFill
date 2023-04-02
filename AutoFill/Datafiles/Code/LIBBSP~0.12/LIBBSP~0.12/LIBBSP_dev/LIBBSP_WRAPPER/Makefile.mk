LIB_NAME := LIBBSP_WRAPPER
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_PLDMEG_GetStatusWrapper.c\
LIBBSP_PLDCMP_GetCompErrorStatus.c\
LIBBSP_IMU_ProgAdditionalReadDataWrapper.c\
LIBBSP_A429_WriteWrapper.c\
LIBBSP_A429_LaunchWrapper.c\
LIBBSP_SHM_GetCompStatus.c\
LIBBSP_SHM_GetBoardStatus.c\
LIBBSP_IMU_GetAdditionalReadDataWrapper.c\
LIBBSPP_WRAPPER_ConvertUint32ToUint8.c\
LIBBSP_WRAPPER_Globals.c


INCLUDE_FILES := ../../LIBMCP_api\
../../LIBBSP_api/LIBBSP_PLDCMP\
../../LIBBSP_api/LIBBSP_WRAPPER\
../../LIBBSP_api/LIBBSP_PLDMEG\
../../LIBBSP_api/LIBBSP_IMU\
../../LIBBSP_api/LIBBSP_ETR\
../../LIBBSP_api/LIBBSP_ETSEC\
../../LIBBSP_api/LIBBSP_I2C\
../../LIBBSP_api/LIBBSP_A429\
../../LIBBSP_api/LIBBSP_SHM\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen


include ../../Makefile/MakefileLib.mk

