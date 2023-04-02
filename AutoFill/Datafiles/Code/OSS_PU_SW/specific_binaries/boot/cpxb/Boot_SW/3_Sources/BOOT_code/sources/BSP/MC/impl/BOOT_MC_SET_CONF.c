#include "BOOT_MC_public.h"
#include "BOOT_MC_REG_public.h"

 void BOOT_MC_SET_CONF( uint32_t             const p_numCore,                        const void *         p_start_addr,                        te_CMN_FLAG_QUESTION const p_ResetCore,                        uint16_t const       p_cctl ) {    uint32_t v_RMC ;    if ( p_ResetCore == e_CMN_FLAG_YES )    {       v_RMC = 1ul ;    }    else    {       v_RMC = 0ul ;    }    v_pt_mc_me_regs->s_MC_ME_CADDR[ p_numCore ] = (reg32_t)(( ((uint32_t)p_start_addr) & MC_ME_CADDR_MASK ) | v_RMC) ;    v_pt_mc_me_regs->s_MC_ME_CCTL[ p_numCore ] = (uint16_t)p_cctl; }
