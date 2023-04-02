#include "DrvSBC_Private.h"
#include "DrvLPSPI_Public.h"
#include "MCP_Types.h"

 void DrvSBC_Cmd_Init_Misc(void) {    uint32_t v_Read_Value;    uint32_t v_Status;    DrvLPSPI_Write (DRVSBC_INIT_CMD_INIT_MISC, &v_Status);    DrvLPSPI_Read (&v_Read_Value, &v_Status); }
