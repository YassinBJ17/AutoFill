#include "BOOT_MC_public.h"
#include "BOOT_MC_REG_public.h"
#include "BOOT_PLL_REG_public.h"

    for ( v_pc_index = 0UL; v_pc_index < MC_ME_MODE_NB; v_pc_index++ )    {       v_pt_mc_me_regs->s_MC_ME_RUN_PC[v_pc_index] = (reg32_t)MC_ME_RUN_PC_VAL;       v_pt_mc_me_regs->s_MC_ME_LP_PC[v_pc_index] = (reg32_t)MC_ME_LP_PC_VAL;    }
