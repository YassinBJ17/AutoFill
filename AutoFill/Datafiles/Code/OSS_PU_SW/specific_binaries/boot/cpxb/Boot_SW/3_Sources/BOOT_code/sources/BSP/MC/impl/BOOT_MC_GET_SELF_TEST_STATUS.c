#include "BOOT_MC_public.h"
#include "BOOT_MC_REG_public.h"
#include "BOOT_PLL_REG_public.h"

 uint32_t BOOT_MC_GET_SELF_TEST_STATUS(void) {    ts_MC_RGM_REG volatile * pt_mc_rgm_reg = (ts_MC_RGM_REG volatile *) MC_RGM_BASE_ADDR;    return ((pt_mc_rgm_reg->s_MC_RGM_FES & MC_RGM_FES_F_ST_DONE_MASK ) >> (uint32_t)2); }
