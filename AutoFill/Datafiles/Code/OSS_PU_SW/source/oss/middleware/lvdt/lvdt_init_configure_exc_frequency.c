/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : lvdt_init_fault_word_thresholds function which sets
                 thresholds values for LVDT A, B and C according to oss conf
                 table.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/lvdt/lvdt_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"
#include "libtools/time/LIB_TIME_public.h"
#include "driver/spi/SPI_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define SIN_GEN_2500HZ 0x51CD0000
#define SIN_GEN_2950HZ 0x74C40000
#define LVDT_TYPE_2    1

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-lvdt-xxxx */
void lvdt_init_configure_exc_frequency(const boolean_t channel_is_a)
{
   /* OSS conf access */
   ts_oss_conf_table * pt_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

   /* Frequency selection register */
   uint32_t frequency_register_lvdt_a = SIN_GEN_2500HZ;
   uint32_t frequency_register_lvdt_b = SIN_GEN_2500HZ;
   uint32_t frequency_register_lvdt_c = SIN_GEN_2500HZ;

   /* Select sin generator frequency LVDT A*/
   if(LVDT_TYPE_2 == pt_oss_conf->s_lvdta_exc_freq)
   {
      frequency_register_lvdt_a = SIN_GEN_2950HZ;
   }

   /* Select sin generator frequency LVDT B*/
   if(LVDT_TYPE_2 == pt_oss_conf->s_lvdtb_exc_freq)
   {
      frequency_register_lvdt_b = SIN_GEN_2950HZ;
   }

   /* Select sin generator frequency LVDT C*/
   if(LVDT_TYPE_2 == pt_oss_conf->s_lvdtc_exc_freq)
   {
      frequency_register_lvdt_c = SIN_GEN_2950HZ;
   }

   {
      /* Select correct frequency values for SPI chip select CS1 & CS2 */
      uint32_t applied_frequency_for_cs_1;
      uint32_t applied_frequency_for_cs_2;
      if(TRUE == channel_is_a)
      {
         applied_frequency_for_cs_1 = frequency_register_lvdt_a;
      }
      else
      {
         applied_frequency_for_cs_1 = frequency_register_lvdt_b;
      }
      applied_frequency_for_cs_2 = frequency_register_lvdt_c;

      /* Select sinus generator frequency for LVDT A or B according to conf table */
      {
         CMN_SYSTEM_SIZE_t ws;

         uint32_t pushr = 0x01000000;
         SPI_FIFO_WRITE_DATA ( 4,
                  &pushr,
                  2,
                  &ws);

         LIBT_TIME_Wait(10* 20 * 1000);

         pushr = applied_frequency_for_cs_1;
         SPI_FIFO_WRITE_DATA  ( 4 ,
                 &pushr,
                 2,
                 &ws);
         LIBT_TIME_Wait(10* 20 * 1000);

         pushr = 0x11000000;
         SPI_FIFO_WRITE_DATA  ( 4 ,
                 &pushr,
                 2,
                 &ws);
         LIBT_TIME_Wait(10* 20 * 1000);

         pushr = 0x40030000;
         SPI_FIFO_WRITE_DATA  ( 4 ,
                 &pushr,
                 2,
                 &ws);
         LIBT_TIME_Wait(10* 20 * 1000);

         pushr = 0xC0000000;
         SPI_FIFO_WRITE_DATA  ( 4 ,
                 &pushr,
                 2,
                 &ws);
         LIBT_TIME_Wait(10* 20 * 1000);

         pushr = 0x00000000;
         SPI_FIFO_WRITE_DATA  ( 4 ,
                 &pushr,
                 2,
                 &ws);
         LIBT_TIME_Wait(10* 20 * 1000);
      }

      /* Select sinus generator frequency for LVDT C according to conf table */
      if(TRUE == channel_is_a)
      {
         CMN_SYSTEM_SIZE_t ws;

         uint32_t pushr = 0x01000000;
         SPI_FIFO_WRITE_DATA ( 5,
                  &pushr,
                  2,
                  &ws);

         LIBT_TIME_Wait(10* 20 * 1000);

         pushr = applied_frequency_for_cs_2;
         SPI_FIFO_WRITE_DATA  ( 5 ,
                 &pushr,
                 2,
                 &ws);
         LIBT_TIME_Wait(10* 20 * 1000);

         pushr = 0x11000000;
         SPI_FIFO_WRITE_DATA  ( 5 ,
                 &pushr,
                 2,
                 &ws);
         LIBT_TIME_Wait(10* 20 * 1000);

         pushr = 0x40030000;
         SPI_FIFO_WRITE_DATA  ( 5 ,
                 &pushr,
                 2,
                 &ws);
         LIBT_TIME_Wait(10* 20 * 1000);

         pushr = 0xC0000000;
         SPI_FIFO_WRITE_DATA  ( 5 ,
                 &pushr,
                 2,
                 &ws);
         LIBT_TIME_Wait(10* 20 * 1000);

         pushr = 0x00000000;
         SPI_FIFO_WRITE_DATA  ( 5 ,
                 &pushr,
                 2,
                 &ws);
         LIBT_TIME_Wait(10* 20 * 1000);
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
