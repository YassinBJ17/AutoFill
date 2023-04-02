/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function sets the DRUN mode and the PLLs.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_MC_public.h"
#include "BOOT_MC_REG_public.h"
#include "BOOT_PLL_REG_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_040 */
void BOOT_MC_PLLDIG_CLEAR_STATUS( void )
{
   /* For FCCU error 29 and 30, clear PLLDIG_PLLxSR*/
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : from uint32_t to reg32_t (only "volatile" is added) */
   PLLDIG_REGS.s_PLLDIG_PLL0SR = (reg32_t)PLLDIG_PLL0SR_LOLF_CLR;
   PLLDIG_REGS.s_PLLDIG_PLL1SR = (reg32_t)PLLDIG_PLL1SR_LOLF_CLR;

   /* For FCCU error 52, clear MC_RGM_FES */
}

void BOOT_MC_RGM_CLEAR_ERROR( void )
{
   ts_MC_RGM_REG volatile * pt_mc_rgm_regs = (ts_MC_RGM_REG volatile *) MC_RGM_BASE_ADDR;
   /* }}<SYNCHRONe_C_Code_10.7> */
   pt_mc_rgm_regs->s_MC_RGM_DES = (reg32_t)MC_RGM_DES_CLEAR_VALUE;
   pt_mc_rgm_regs->s_MC_RGM_FES = (reg32_t)MC_RGM_FES_CLEAR_VALUE;
}

uint32_t BOOT_MC_GET_SELF_TEST_STATUS(void)
{
   ts_MC_RGM_REG volatile * pt_mc_rgm_reg = (ts_MC_RGM_REG volatile *) MC_RGM_BASE_ADDR;
   return ((pt_mc_rgm_reg->s_MC_RGM_FES & MC_RGM_FES_F_ST_DONE_MASK ) >> (uint32_t)2);
}
/* ---------- internal operation bodies: ------------------------------------ */
/* none */
