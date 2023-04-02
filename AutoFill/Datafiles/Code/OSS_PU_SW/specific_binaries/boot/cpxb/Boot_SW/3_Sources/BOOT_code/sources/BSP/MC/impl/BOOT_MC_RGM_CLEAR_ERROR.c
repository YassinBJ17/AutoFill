#include "BOOT_MC_public.h"
#include "BOOT_MC_REG_public.h"
#include "BOOT_PLL_REG_public.h"

 void BOOT_MC_RGM_CLEAR_ERROR( void ) {    ts_MC_RGM_REG volatile * pt_mc_rgm_regs = (ts_MC_RGM_REG volatile *) MC_RGM_BASE_ADDR;    pt_mc_rgm_regs->s_MC_RGM_DES = (reg32_t)MC_RGM_DES_CLEAR_VALUE;    pt_mc_rgm_regs->s_MC_RGM_FES = (reg32_t)MC_RGM_FES_CLEAR_VALUE; }
