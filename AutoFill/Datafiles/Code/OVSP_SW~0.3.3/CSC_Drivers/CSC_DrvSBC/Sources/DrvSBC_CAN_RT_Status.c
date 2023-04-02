#include "DrvSBC_Private.h"
#include "DrvLPSPI_Public.h"
#include "MCP_Types.h"

 TE_DrvSBC_CAN_Status DrvSBC_CAN_RT_Status (void) {    TE_DrvSBC_CAN_Status v_CAN_Status;    uint32_t v_Read_Value;    uint32_t v_Status;    DrvLPSPI_Write (DRVSBC_INIT_CAN_RT_STATUS, &v_Status);    DrvLPSPI_Read (&v_Read_Value, &v_Status);    if ((DRVSBC_CAN_STATUS_CAN_DRV_STATE_MASK == (v_Read_Value & DRVSBC_CAN_STATUS_CAN_DRV_STATE_MASK)) &&        (DRVSBC_CAN_STATUS_CAN_RCV_STATE_MASK == (v_Read_Value & DRVSBC_CAN_STATUS_CAN_RCV_STATE_MASK)))    {       v_CAN_Status = E_DrvSBC_CAN_OK;    }    else    {       v_CAN_Status = E_DrvSBC_CAN_KO;    }    return (v_CAN_Status); }
