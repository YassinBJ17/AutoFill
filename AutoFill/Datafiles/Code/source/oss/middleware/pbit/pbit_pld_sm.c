/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"
#include "memory/memory_address_public.h"
#include "middleware/smot/smot_fpga_reg_common.h"
#include "middleware/logbook/logbook_public.h"
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void pbit_pld_sm(void)
{

   /* FPGA tmot register */
   ts_smot_fpga_reg *smot_fpga_reg;

   /* Assign the defined adress to the FPGA smot register */
   smot_fpga_reg = SMOT_FPGA_MEMORY_ADDR;

   if(smot_fpga_reg->s_smot_conf_reg.u_bit.s_tech != (uint32_t)0)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }


}

/* ---------- internal operations: ------------------------------------------ */
