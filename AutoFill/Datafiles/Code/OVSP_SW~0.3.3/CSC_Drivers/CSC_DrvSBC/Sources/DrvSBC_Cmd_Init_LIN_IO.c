#include "DrvSBC_Private.h"
#include "DrvLPSPI_Public.h"
#include "MCP_Types.h"

 void DrvSBC_Cmd_Init_LIN_IO(void) {    uint32_t v_Read_Value;    uint32_t v_Status;    DrvLPSPI_Write (DRVSBC_INIT_CMD_INIT_LIN_IO, &v_Status);    DrvLPSPI_Read (&v_Read_Value, &v_Status); }
