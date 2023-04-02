#include "BOOT_MC_public.h"
#include "BOOT_MC_REG_public.h"
#include "BOOT_PLL_REG_public.h"

    if ( ( v_mode_conf & MC_ME_DRUN_MC_XOSCON_MASK ) != 0UL )    {       *pt_mc_me_mode_reg = (*pt_mc_me_mode_reg) | (reg32_t)MC_ME_DRUN_MC_XOSCON_MASK;       if ( ( v_mode_conf & MC_ME_DRUN_MC_PLL0ON_MASK ) != 0UL )       {          *pt_mc_me_mode_reg = (*pt_mc_me_mode_reg) | (reg32_t)MC_ME_DRUN_MC_PLL0ON_MASK;          if ( ( v_mode_conf & MC_ME_DRUN_MC_PLL1ON_MASK ) != 0UL )          {             *pt_mc_me_mode_reg = (*pt_mc_me_mode_reg) | (reg32_t)MC_ME_DRUN_MC_PLL1ON_MASK;          }       }    }
