/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function initialize crossbars switch registers.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_XBAR_public.h"
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
/* Implements REQ_[User Project Name]_BOOT-LLR_055 */
void BOOT_XBAR_INIT( void )
{
   /* See RM XBAR */
   uint32_t v_xbar_index;

   /* {{RELAX<SYNCHRONe_C_Code_10.7> The casts are safe as the structure is used to retrieve all XBAR registers */
   /* which start at these addresses. */
   ts_XBAR_COMPUT_REG volatile * const c_pt_xbar_comput_regs = (ts_XBAR_COMPUT_REG volatile *) XBAR_COMPUT_BASE_ADDR;
   ts_XBAR_PERIPH_REG volatile * const c_pt_xbar_periph_regs = (ts_XBAR_PERIPH_REG volatile *) XBAR_PERIPH_BASE_ADDR;
   /* }}<SYNCHRONe_C_Code_10.7> */

   for ( v_xbar_index = 0UL; v_xbar_index < XBAR_COMPUT_NB; v_xbar_index++ )
   {

      /* >RELAX<SYNCHRONe_C_Code_7.2> Index '6' is PRS read only register */
      if ( v_xbar_index != 6UL )
      {
         c_pt_xbar_comput_regs->s_XBAR_C_ELEM[v_xbar_index].s_XBAR_CRS = (reg32_t)c_CONF_XBAR.s_XBAR_COMPUT_CRS;
      }
   }

   for ( v_xbar_index = 0UL; v_xbar_index < XBAR_PERIPH_NB; v_xbar_index++ )
   {
      /* >RELAX<SYNCHRONe_C_Code_7.2> Index '3' is PRS read only register */
      if ( v_xbar_index <= 3UL )
      {
         c_pt_xbar_periph_regs->s_XBAR_P_ELEM[v_xbar_index].s_XBAR_CRS = (reg32_t)c_CONF_XBAR.s_XBAR_PERIPH_CRS;
      }
   }

}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
