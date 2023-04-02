LIB_NAME := LIBBSP_I2C
SCI := LIBBSP
SOURCES_FILES:=\
LIBBSP_I2C_Close.c\
LIBBSP_I2C_GetReadData.c\
LIBBSP_I2C_Initialize.c\
LIBBSP_I2C_Open.c\
LIBBSP_I2C_Step.c\
LIBBSP_I2C_Read.c\
LIBBSP_I2C_ReadNoWait.c\
LIBBSP_I2C_Write.c\
LIBBSP_I2C_WriteNoWait.c\
LIBBSP_I2C_WaitEndOfBusy.c\
LIBBSP_I2C_WaitEndOfTransmission.c\
LIBBSP_I2C_DataRead.c\
LIBBSP_I2C_WaitForSlaveReadData.c\
LIBBSP_I2C_WaitForSlaveReadCmd.c\
LIBBSP_I2C_WaitForSlaveWriteCmd.c\
LIBBSP_I2C_WaitForSlaveWriteAck.c\
LIBBSP_I2C_TransmissionWrite.c\
LIBBSP_I2C_ReceiveMode.c\
LIBBSP_I2C_Reset.c\
LIBBSP_I2C_Globals.c

INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_I2C ../../LIBBSP_api/LIBBSP_CMN ../../LIBMCP_api\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_CCSR


include ../../Makefile/MakefileLib.mk




