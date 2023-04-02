/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : p0_cbit function which allows p0 CBIT at each RTC.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/p0/p0_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

/* ---------- internal define constants: ------------------------------------ */
/* Mask for 1 bit */
#define MASK_1_BIT            ((uint16_t)0x0001)
/* Shift of 1 bit */
#define SHIFT_1_BIT           ((uint8_t)1)
/* Number of bits in 1 byte */
#define NB_BITS_IN_BYTE       ((uint32_t)8)

/* Modulo for parity */
#define MODULO_PARITY         ((uint16_t)2)

/* Built in test error codes */
#define CBIT_RESPONSE_ERR     ((uint32_t)3)
#define CBIT_RANGE_ERR        ((uint32_t)5)

/* P0 range = [10.35 ; 137.89] kPa */
#define P0_MIN                ((uint16_t)0x0C02)
#define P0_MAX                ((uint16_t)0x9FFF)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* P0 CBIT, measure and reset management */
/* Implements REQ_FADEX_OS_SRD-P0-0010 */
void p0_cbit(const uint32_t p_read_size, uint16_t p_spi_tmp_frame[NB_BYTES_IN_FRAME],
             const ts_spi_p0_frame * const p_spi_p0_frame, boolean_t * const p_p0_is_faulty)
{
   /* Iterators */
   uint32_t i;
   uint32_t j;

   /* Parity of P0 frame */
   uint16_t spi_p0_frame_parity = (uint16_t)0;

   /* P0 faults */
   uint32_t p0_is_too_old = 0;
   uint32_t p0_is_com_faulty = 0;
   uint32_t p0_is_response_faulty = 0;
   uint32_t p0_is_out_of_rng_detected_by_sensor = 0;
   uint32_t p0_is_out_of_rng = 0;
   uint32_t p0_is_invalid = 0;

   /* When no frame has been received in the SPI reception buffer */
   if ((uint32_t)0 == p_read_size)
   {
      p0_is_too_old = (uint32_t)1;
   }
   /* When the frame has been refreshed */
   else
   {
      /* Compute the parity of the frame and transform pressure measure endianness */
      for(i = (uint32_t)0; i < NB_BYTES_IN_FRAME; i++)
      {
         for (j = (uint32_t)0; j < NB_BITS_IN_BYTE; j++)
         {
            /* Compute parity */
            spi_p0_frame_parity += p_spi_tmp_frame[i] & MASK_1_BIT;
            p_spi_tmp_frame[i] = p_spi_tmp_frame[i] >> SHIFT_1_BIT;
         }
      }

      /* When the parity computed from the frame is even */
      if ((uint16_t)0 == (spi_p0_frame_parity % MODULO_PARITY))
      {
         /* Indicate the communication fault */
         p0_is_com_faulty = (uint32_t)1;
      }
      /* When the communication is working */
      else
      {
         /* When the built-in tests performed by the sensor presents a response error */
         if (CBIT_RESPONSE_ERR == p_spi_p0_frame->s_p0_byte_1.u_bit.s_status)
         {
            /* Indicate the sensor response fault */
            p0_is_response_faulty = (uint32_t)1;
         }

         /* When the built-in tests performed by the sensor presents a range error */
         if (CBIT_RANGE_ERR == p_spi_p0_frame->s_p0_byte_1.u_bit.s_status)
         {
            /* Indicate the pressure is out of range */
            p0_is_out_of_rng_detected_by_sensor = (uint32_t)1;
         }

         /* When the pressure is out of range */
         if ((P0_MIN > p_spi_p0_frame->s_p0_pressure) || (P0_MAX < p_spi_p0_frame->s_p0_pressure))
         {
            /* Indicate the pressure is out of range */
            p0_is_out_of_rng = (uint32_t)1;
         }
      }
   }

   /* When at least one error has been detected */
   if (((uint32_t)0 != p0_is_com_faulty) || ((uint32_t)0 != p0_is_too_old) || ((uint32_t)0 != p0_is_response_faulty)
         || ((uint32_t)0 != p0_is_out_of_rng_detected_by_sensor) || ((uint32_t)0 != p0_is_out_of_rng))
   {
      /* Indicate the invalidity */
      p0_is_invalid = (uint32_t)1;
   }

   /* When the response is faulty or the frame is too old or the com is faulty */
   if (   ((uint32_t)0 != shmem.s_p0.s_fault_word.u_bit.s_p0_int_cbit_fault)
       || ((uint32_t)0 != shmem.s_p0.s_fault_word.u_bit.s_p0_update_frame_fault)
       || ((uint32_t)0 != shmem.s_p0.s_fault_word.u_bit.s_p0_com_fault))
   {
      /* Indicate the P0 is faulty */
      *p_p0_is_faulty = TRUE;
   }

   /* Indicate the faults to the CSS_PU/MCSS_PU */
   shmem.s_p0.s_fault_word.u_bit.s_p0_int_cbit_fault     = p0_is_response_faulty;
   shmem.s_p0.s_fault_word.u_bit.s_p0_update_frame_fault = p0_is_too_old;
   shmem.s_p0.s_fault_word.u_bit.s_p0_fatal_fault        = p0_is_out_of_rng_detected_by_sensor;
   shmem.s_p0.s_fault_word.u_bit.s_out_of_range          = p0_is_out_of_rng;
   shmem.s_p0.s_fault_word.u_bit.s_p0_com_fault          = p0_is_com_faulty;
   shmem.s_p0.s_fault_word.u_bit.s_invalid               = p0_is_invalid;
}

/* ---------- internal operations: ------------------------------------------ */
