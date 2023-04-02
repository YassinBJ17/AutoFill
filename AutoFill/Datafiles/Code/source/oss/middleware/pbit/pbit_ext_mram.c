/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : PBIT test on external MRAM
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"
#include "memory/lib_critical_service_section_def_data.h"



/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Last faulty address and data */
uint32_t pbit_mram_faulty_addr;
uint32_t pbit_mram_faulty_data;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-PBIT-0020 */
/* PBIT test function on external MRAM */
void pbit_ext_mram(void)
{
   /* pointer to read and write in external mram */
   uint32_t* ext_mram_pointer;
   /* saved value 1 of external MRAM */
   uint32_t ext_mram_saved_value_1;
   /* saved value 2 of external MRAM */
   uint32_t ext_mram_saved_value_2;
   /* value read to check pattern */
   uint32_t ext_mram_read_value;

   /* set ptr to mram adress 1 */
   ext_mram_pointer = MRAM_ADD_1;
   /* store the value in local variable */
   ext_mram_saved_value_1 = *ext_mram_pointer;
   /* write the corresponding pattern */
   *ext_mram_pointer = MRAM_VAL_1;
   /* read value */
   ext_mram_read_value = *ext_mram_pointer;
   /* check the pattern */
   if(ext_mram_read_value != MRAM_VAL_1)
   {
      /* Set PBIT fault word */
      shmem.s_pbit_fault_word.u_bit.s_pbit_mram_bus_ebi = (uint32_t)1;

      /* Save last faulty address and data */
      pbit_mram_faulty_addr = (uint32_t)ext_mram_pointer;
      pbit_mram_faulty_data = ext_mram_read_value;
   }
   /* restore mram value */
   *ext_mram_pointer = ext_mram_saved_value_1;


   /* set ptr to mram adress 2 */
   ext_mram_pointer = MRAM_ADD_2;
   /* store the value in local variable */
   ext_mram_saved_value_2 = *ext_mram_pointer;
   /* write the corresponding pattern */
   *ext_mram_pointer = MRAM_VAL_2;
   /* read value */
   ext_mram_read_value = *ext_mram_pointer;
   /* check the pattern */
   if(*ext_mram_pointer != MRAM_VAL_2)
   {
      /* Set PBIT fault word */
      shmem.s_pbit_fault_word.u_bit.s_pbit_mram_bus_ebi = (uint32_t)1;

      /* Save last faulty address and data */
      pbit_mram_faulty_addr = (uint32_t)ext_mram_pointer;
      pbit_mram_faulty_data = ext_mram_read_value;
   }
   /* restore mram value */
   *ext_mram_pointer = ext_mram_saved_value_2;
}

/* ---------- internal operations: ------------------------------------------ */
