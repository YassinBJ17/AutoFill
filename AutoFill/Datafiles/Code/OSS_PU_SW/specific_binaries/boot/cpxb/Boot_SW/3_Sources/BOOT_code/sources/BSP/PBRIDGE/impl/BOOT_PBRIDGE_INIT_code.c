/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function initialize PBRIDGE registers.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_PBRIDGE_public.h"
#include "BOOT_CONF_public.h"


/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_048 */
void BOOT_PBRIDGE_INIT( void )
{
   /* See �19 PBRIDGE */
   uint32_t v_pacr_index, v_opacr_index;

   /* {{RELAX<SYNCHRONe_C_Code_10.7> The casts are safe as the structure is used to retrieve all registers which */
   /* start at these addresses. */
   ts_PBRIDGE_REG volatile * pt_pbridgeA_regs = (ts_PBRIDGE_REG volatile *) PBRIDGE_A_BASE_ADDR;
   ts_PBRIDGE_REG volatile * pt_pbridgeB_regs = (ts_PBRIDGE_REG volatile *) PBRIDGE_B_BASE_ADDR;
   /* }}<SYNCHRONe_C_Code_10.7> */

   /* initialize PBRIDGE_A */

   pt_pbridgeA_regs->s_MPR_A = (reg32_t)c_CONF_PBRIDGEA.s_mpr_a;
   pt_pbridgeA_regs->s_MPR_B = (reg32_t)c_CONF_PBRIDGEA.s_mpr_b;

   for ( v_pacr_index = 0UL; v_pacr_index < PBRIDGE_PACR_NB; v_pacr_index++ )
   {
      if (v_pacr_index != PBRIDGE_NOT_IMPLEMENTED_REG_NB)
      {
         pt_pbridgeA_regs->s_PACR[v_pacr_index] = (reg32_t)c_CONF_PBRIDGEA.s_pacr[v_pacr_index];
      }

   }

   for ( v_opacr_index = 0UL; v_opacr_index < PBRIDGE_OPACR_NB; v_opacr_index++ )
   {
      pt_pbridgeA_regs->s_OPACR[v_opacr_index] = (reg32_t)c_CONF_PBRIDGEA.s_opacr[v_opacr_index];
   }

   /* */

   /* initialize PBRIDGE_B */

   pt_pbridgeB_regs->s_MPR_A = (reg32_t)c_CONF_PBRIDGEB.s_mpr_a;
   pt_pbridgeB_regs->s_MPR_B = (reg32_t)c_CONF_PBRIDGEB.s_mpr_b;

   for ( v_pacr_index = 0UL; v_pacr_index < PBRIDGE_PACR_NB; v_pacr_index++ )
   {
      if ( v_pacr_index != PBRIDGE_NOT_IMPLEMENTED_REG_NB )
      {
         pt_pbridgeB_regs->s_PACR[v_pacr_index] = (reg32_t)c_CONF_PBRIDGEB.s_pacr[v_pacr_index];
      }

   }

   for ( v_opacr_index = 0UL; v_opacr_index < PBRIDGE_OPACR_NB; v_opacr_index++ )
   {
      pt_pbridgeB_regs->s_OPACR[v_opacr_index] = (reg32_t)c_CONF_PBRIDGEB.s_opacr[v_opacr_index];
   }

}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
