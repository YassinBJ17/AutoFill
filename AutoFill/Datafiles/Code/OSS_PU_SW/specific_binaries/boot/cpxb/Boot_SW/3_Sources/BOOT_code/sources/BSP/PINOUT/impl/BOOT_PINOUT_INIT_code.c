/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function initialize input and output port registers.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */

#include "BOOT_PINOUT_public.h"
#include "BOOT_CONF_public.h"

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_049 */
void BOOT_PINOUT_INIT( void )
{
   uint32_t v_pad_index;

   for ( v_pad_index = 0UL; v_pad_index < PAD_IO_CFG_MAX; v_pad_index++ )
   {
      /* >RELAX<SYNCHRONe_C_Code_10.2> SIUL2.s_MSCR_xxx[x].u_R is reg32_t. */
      /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : from address (uint32_t) to pointer (on volatile struct) */
      SIUL2.s_MSCR_IO[v_pad_index] = c_conf_pad_io_st.s_conf_pad_io_elt[v_pad_index].s_Value;
   }
   
   for ( v_pad_index = 0UL; v_pad_index < PAD_MUX_CFG_MAX; v_pad_index++ )
   {
      /* >RELAX<SYNCHRONe_C_Code_10.2> SIUL2.s_MSCR_xxx[x].u_R is reg32_t. */
      /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : from address (uint32_t) to pointer (on volatile struct) */
      SIUL2.s_MSCR_MUX[v_pad_index] = c_conf_pad_mux_st.s_conf_pad_mux_elt[v_pad_index].s_Value;
   }
}


/* ---------- internal operation bodies: ------------------------------------ */
/* none */
