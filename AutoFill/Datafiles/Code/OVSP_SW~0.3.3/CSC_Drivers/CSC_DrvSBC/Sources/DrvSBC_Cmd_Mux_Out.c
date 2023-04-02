#include "DrvSBC_Private.h"
#include "DrvLPSPI_Public.h"
#include "MCP_Types.h"

 void DrvSBC_Cmd_Mux_Out(void) {    uint32_t v_Read_Value;    uint32_t v_Status;    DrvLPSPI_Write (DRVSBC_INIT_CMD_MUX_OUT, &v_Status);    DrvLPSPI_Read (&v_Read_Value, &v_Status); }
