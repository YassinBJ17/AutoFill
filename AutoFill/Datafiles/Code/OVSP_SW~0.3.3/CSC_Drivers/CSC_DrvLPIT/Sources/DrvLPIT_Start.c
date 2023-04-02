#include "MCP_Types.h"
#include "DrvLPIT_Private.h"
#include "DrvLPIT_Public.h"

 void DrvLPIT_Start (uint32_t const p_TimerId, uint32_t const p_Timeout) {    uint32_t v_wait;    uint32_t v_timeout;    v_timeout = p_Timeout * DRVLPIT_DIV_FACTOR_375;    DrvLPIT_LPIT_Registers->S_MCR =        ((1UL << DRVLPIT_MCR_M_CEN_SHIFT) & DRVLPIT_MCR_M_CEN_MASK);    for (v_wait = 0UL ; v_wait < 4UL ; v_wait++)    {     }    if (p_TimerId == DRVLPIT_IDENT_0)    {       DrvLPIT_LPIT_Registers->S_MIER |=           ((1UL << DRVLPIT_MIER_TIE_0_SHIFT) & DRVLPIT_MIER_TIE_0_MASK);    }    else    {       DrvLPIT_LPIT_Registers->S_MIER |=           ((1UL << DRVLPIT_MIER_TIE_1_SHIFT) & DRVLPIT_MIER_TIE_1_MASK);    }    DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [p_TimerId].S_TVAL = v_timeout - 1UL;    DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [p_TimerId].S_TCTRL |=        ((1UL << DRVLPIT_TCTRL_T_EN_SHIFT) & DRVLPIT_TCTRL_T_EN_MASK); }
