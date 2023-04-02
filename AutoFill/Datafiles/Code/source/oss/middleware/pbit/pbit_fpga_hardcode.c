/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : PBIT EBI test on external SRAM
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"
#include "middleware/logbook/logbook_public.h"
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-PBIT-0010 */
/* PBIT EBI test function on external SRAM */
void pbit_fpga_hardcode(void)
{
   /* pointer to read and write in external sram */
   uint32_t* ext_sram_pointer;

   /* last data tested */
   uint32_t ext_sram_last_data;

   /* set pointer for FPGA address 1 */
   ext_sram_pointer = FPGA_HARDCODED_ADD_1;
   ext_sram_last_data = *ext_sram_pointer;
   if (ext_sram_last_data != FPGA_HARDCODED_VAL_1)
   {
      /* Log fatal fault */
      logbook_pbit_fatal((uint32_t)ext_sram_pointer, ext_sram_last_data);

      /* WD reset */
      reset_critical();
   }

   /* set pointer for FPGA address 2 */
   ext_sram_pointer = FPGA_HARDCODED_ADD_2;
   ext_sram_last_data = *ext_sram_pointer;
   if (ext_sram_last_data != FPGA_HARDCODED_VAL_2)
   {
      /* Log fatal fault */
      logbook_pbit_fatal((uint32_t)ext_sram_pointer, ext_sram_last_data);

      /* WD reset */
      reset_critical();
   }

}

/* ---------- internal operations: ------------------------------------------ */
