/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : PBIT EBI test on external SRAM
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
const uint32_t* const ext_sram_addresses[SRAM_TEST_VAL_NB] =
{
(uint32_t*)0x21000000,
(uint32_t*)0x21000004,
(uint32_t*)0x21000008,
(uint32_t*)0x21000010,
(uint32_t*)0x21000020,
(uint32_t*)0x21000040,
(uint32_t*)0x21000080,
(uint32_t*)0x21000100,
(uint32_t*)0x21000200,
(uint32_t*)0x21000400,
(uint32_t*)0x21000800,
(uint32_t*)0x21001000,
(uint32_t*)0x21002000,
(uint32_t*)0x21004000,
(uint32_t*)0x21008000,
(uint32_t*)0x21010000,
(uint32_t*)0x21020000,
(uint32_t*)0x21040000,
(uint32_t*)0x21080000,
(uint32_t*)0x21100000,
};

uint32_t ext_sram_value_save[SRAM_TEST_VAL_NB];

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-PBIT-0010 */
/* PBIT EBI test function on external SRAM */
void pbit_ebi_ext_sram(void)
{
   /* iterator */
   uint32_t i;
   /* while iterator */
   uint32_t w_i;
   /* error flag */
   uint8_t err_flag;
   /* pointer to read and write in external sram */
   uint32_t* ext_sram_pointer = 0;
   /* value read to check pattern */
   uint32_t ext_sram_read_value = 0;

   /*variable initialisation */
   /* no error */
   err_flag = (uint8_t)0;
   w_i      = (uint32_t)0;

   /* for i in the addresses tale save the values and write the pattern*/
   for (i=(uint32_t)0; i<SRAM_TEST_VAL_NB; i++)
   {
      /* pointer will take the value store in address table */
      ext_sram_pointer = (uint32_t*)ext_sram_addresses[i];

      /* save the value at this address */
      ext_sram_value_save[i] = *ext_sram_pointer;

      /*write the test value ie the address except for the first and second one */
      if((uint32_t)0 == i)
      {
         /* if first address, store 0x55555555 */
         *ext_sram_pointer = SRAM_VAL_1_55;
      }
      else if ((uint32_t)1 == i)
      {
         /* if second address, store 0xAAAAAAAA */
         *ext_sram_pointer = SRAM_VAL_2_AA;
      }
      else
      {
         /* else store the address */
         *ext_sram_pointer = (uint32_t)(ext_sram_addresses[i]);
      }
   }

   /* Read in SRAM the pattern and check it and restore previous value*/
   /* while no error and not the end of address table : */
   while ((uint8_t)0 == err_flag && w_i < SRAM_TEST_VAL_NB)
   {
      /* pointer will take the value store in address table */
      ext_sram_pointer = (uint32_t*)ext_sram_addresses[w_i];

      ext_sram_read_value = *ext_sram_pointer;

      /*Special case for the first and second address */
      if((uint32_t)0 == w_i)
      {
         /* if first value different from 0x55555555 */
         if (ext_sram_read_value != SRAM_VAL_1_55)
         {
            /* error detected */
            err_flag = (uint8_t)1;
         }
         else
         {
            /* else no error restore value */
            *ext_sram_pointer = ext_sram_value_save[w_i];
         }
      }
      else if ((uint32_t)1 == i)
      {
         /* if second value different from 0xAAAAAAAA */
         if(ext_sram_read_value != SRAM_VAL_2_AA)
         {
            /* error detected */
            err_flag =  (uint8_t)1;
         }
         else
         {
            /* else no error restore value */
            *ext_sram_pointer = ext_sram_value_save[w_i];
         }
      }
      else
      {
         /* else if value different from the address */
         if(ext_sram_read_value != (uint32_t)(ext_sram_addresses[w_i]))
         {
            /* error detected */
            err_flag =  (uint8_t)1;
            *ext_sram_pointer = ext_sram_value_save[w_i];
         }
         else
         {
            /* else no error restore value */
            *ext_sram_pointer = ext_sram_value_save[w_i];
         }
      }
      /* increment w_i */
      w_i++;
   }

   /* in case of error, reset */
   pbit_reset((uint32_t)err_flag, (uint32_t)ext_sram_pointer, ext_sram_read_value);

   /* Check for the hardcoded value in FPGA */
   pbit_fpga_hardcode();

}

/* ---------- internal operations: ------------------------------------------ */
