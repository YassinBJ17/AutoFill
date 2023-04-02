#include "BOOT_FCCU_REG_private.h"
#include "BOOT_FCCU_public.h"

 uint32_t BOOT_FCCU_GET_RF_S1 ( void ) {    uint32_t v_get_S1_status;    FCCU_CTRL = FCCU_CTRL_OPR_OP10;    do    {       v_get_S1_status = (uint32_t)FCCU_CTRL_OPS;    }    while (v_get_S1_status != FCCU_CTRL_OPS_SUCCESS);    return ((uint32_t)FCCU_RF_S1); }
