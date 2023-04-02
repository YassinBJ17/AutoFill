/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : p0_periodic function which allows p0 management at each RTC.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/p0/p0_public.h"
#include "middleware/p0/p0_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */
#include "driver/spi/SPI_HAL_public.h"
#include "driver/spi/SPI_CFEX_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* SPI channel for P0 */
#define SPI_CHANNEL_P0        ((CMN_IOSP_ID_t)7)

/* Index of data in SPI frame */
#define INDEX_BYTE_1          ((uint32_t)0)
#define INDEX_BYTE_2          ((uint32_t)1)
#define INDEX_BYTE_3          ((uint32_t)2)

/* Mask for 1 bit */
#define MASK_1_BIT            ((uint8_t)0x01)
/* Shift of 1 bit */
#define SHIFT_1_BIT           ((uint8_t)1)
/* Shift of 1 byte */
#define SHIFT_1_BYTE          ((uint32_t)8)
/* Number of bits in 1 byte */
#define NB_BITS_IN_BYTE       ((uint32_t)8)

/* Number of bits in Address */
#define NB_BITS_IN_ADDR       ((uint32_t)4)
/* Number of bits in Status */
#define NB_BITS_IN_STATUS     ((uint32_t)3)

/* Modulo for parity */
#define MODULO_PARITY         ((uint8_t)2)

/* Built in test error codes */
#define CBIT_RESPONSE_ERR     ((uint32_t)3)
#define CBIT_RANGE_ERR        ((uint32_t)5)

/* P0 range = [10.35 ; 137.89] kPa */
#define P0_MIN                ((uint16_t)0x0C02)
#define P0_MAX                ((uint16_t)0x9FFF)

/* Conversion coefficient for P0 : 2^(-11) * 6.89476 */
#define P0_CONVERSION_COEFF   ((float32_t)0.00336658203125f)

/* Number of consecutive RTC P0 can be faulty before reset */
#define P0_FAULTY_RTC_NB      ((uint8_t)3)

/* Value of reset request */
#define RESET_REQUEST         ((uint8_t)0)

/* Number of RTC to wait before the 1st pressure request after a reset */
#define TIME_BEFORE_REQUEST   ((uint32_t)4)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* GPIO for reset of P0 */
uint8_t     *gpio_reset_p0;
/* GPIO for CE read command */
uint8_t     *gpio_ce_read_command;

/* Indicate if P0 has been reset since the beginning of the mission */
boolean_t   p0_has_been_reset;
/* Counter of faulty P0 */
uint8_t     p0_fault_counter;

/* P0 device BIT status */
uint32_t    p0_internal_cbit;
/* P0 raw value */
uint16_t    p0_raw_value;

/* Number of RTC since P0 activation */
uint32_t    p0_rtc_since_activation;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* P0 CBIT, measure and reset management */
/* Implements REQ_FADEX_OS_SRD-P0-0010 */
/* Implements REQ_FADEX_OS_SRD-P0-0020 */
void p0_periodic(const boolean_t p_is_channel_a)
{
   /* Iterators */
   uint32_t i;

   /* Temporary buffer to get P0 frame */
   uint16_t spi_tmp_frame[NB_BYTES_IN_FRAME] = {(uint16_t)0, (uint16_t)0, (uint16_t)0};

   /* Size of data read in SPI FIFO */
   uint32_t read_size;

   /* SPI P0 frame */
   ts_spi_p0_frame spi_p0_frame = {(uint8_t)0, (uint16_t)0};

   /* Indicate if the sensor is faulty or not */
   boolean_t p0_is_faulty = FALSE;

   /* When the channel is B */
   if (FALSE == p_is_channel_a)
   {
      /* When the P0 has been reset */
      if ((uint8_t)0 == *gpio_reset_p0)
      {
         /* Activate P0 after reset */
         *gpio_reset_p0 = (uint8_t)1;
         p0_rtc_since_activation = (uint32_t)0;
      }

      /* When at least 50ms has passed since last activation of P0 */
      if (TIME_BEFORE_REQUEST < p0_rtc_since_activation)
      {
         /* End the request of pressure */
         *gpio_ce_read_command = (uint8_t)1;

         /* Get P0 frames in SPI 4 FIFO */
         SPI_FIFO_READ_DATA(SPI_CHANNEL_P0, &(spi_tmp_frame[0]),
                            (uint32_t)(NB_BYTES_IN_FRAME * (uint32_t)SPI_CFEX_DATA_SIZE),
                            &read_size);

         /* Put the received frame in the P0 frame structure */
         /* Address (Byte 1, bits 0 to 3, LSB first) */
         for (i = (uint32_t)0; i < NB_BITS_IN_ADDR; i++)
         {
            spi_p0_frame.s_p0_byte_1.u_bit.s_address |= (((uint32_t)spi_tmp_frame[INDEX_BYTE_1] & (uint32_t)((uint32_t)0x01
                                                         << (NB_BITS_IN_BYTE - (uint32_t)1 - i)))
                                                         >> (NB_BITS_IN_BYTE - (uint32_t)1 - i)) << i;
         }

         /* Status (Byte 1, bits 4 to 6, LSB first) */
         for (i = (uint32_t)0; i < NB_BITS_IN_STATUS; i++)
         {
            spi_p0_frame.s_p0_byte_1.u_bit.s_status |= (((uint32_t)spi_tmp_frame[INDEX_BYTE_1] & (uint32_t)((uint32_t)0x01
                                                       << (NB_BITS_IN_BYTE - NB_BITS_IN_ADDR - (uint32_t)1 - i)))
                                                       >> (NB_BITS_IN_BYTE - NB_BITS_IN_ADDR - (uint32_t)1 - i)) << i;
         }

         /* Parity bit (Byte 1, bit 7) */
         spi_p0_frame.s_p0_byte_1.u_bit.s_parity = (uint32_t)(spi_tmp_frame[INDEX_BYTE_1]) & (uint32_t)0x01;

         /* Pressure */
         for (i = (uint32_t)0; i < NB_BITS_IN_BYTE; i++)
         {
            /* Byte 2, bit 0 to 7, LSB first */
            spi_p0_frame.s_p0_pressure |= (uint16_t)((((uint32_t)spi_tmp_frame[INDEX_BYTE_2] & ((uint32_t)0x01 << i)) >> i)
                                          << (NB_BITS_IN_BYTE - (uint32_t)1 - i));
            /* Byte 3, bit 0 to 7, LSB first */
            spi_p0_frame.s_p0_pressure |= (uint16_t)((((uint32_t)spi_tmp_frame[INDEX_BYTE_3] & ((uint32_t)0x01 << i)) >> i)
                                          << ((SHIFT_1_BYTE + NB_BITS_IN_BYTE) - (uint32_t)1 - i));
         }

         /* CBIT */
         p0_cbit(read_size, spi_tmp_frame, &spi_p0_frame, &p0_is_faulty);

         /* Compute the P0 measure and save it in the shared memory */
         shmem.s_p0.s_measure = (float32_t)(spi_p0_frame.s_p0_pressure) * P0_CONVERSION_COEFF;

         /* Indicate internal cbit and raw value for logbook */
         p0_internal_cbit = spi_p0_frame.s_p0_byte_1.u_bit.s_status;
         p0_raw_value = spi_p0_frame.s_p0_pressure;

         /* When the sensor has never been reset since the beginning of the mission */
         if (FALSE == p0_has_been_reset)
         {
            /* When the sensor is faulty */
            if (p0_is_faulty)
            {
               /* Increment the fault counter */
               p0_fault_counter++;
            }
            else
            {
               /* Reset the fault counter */
               p0_fault_counter = (uint8_t)0;
            }

            /* When the sensor is faulty during the three last consecutive RTC */
            if (P0_FAULTY_RTC_NB <= p0_fault_counter)
            {
               /* Reset the pressure transducer P0 */
               *gpio_reset_p0 = RESET_REQUEST;

               /* Indicate P0 has been reset */
               p0_has_been_reset = TRUE;
            }
         }

         /* Flush the SPI reception buffer */
         SPI_CLEAR_RX_FIFO(SPI_CHANNEL_P0);

         /* Request pressure to the sensor for next RTC */
         *gpio_ce_read_command = (uint8_t)0;
      }
      else
      {
         /* Default value in the shared memory */
         shmem.s_p0.s_measure = 0.0f;
         shmem.s_p0.s_fault_word.u_word = (uint32_t)0;

         /* Increment the counter of RTC since activation */
         p0_rtc_since_activation++;
      }
   }
   /* When the channel is A */
   else
   {
      /* Default value in the shared memory */
      shmem.s_p0.s_measure = 0.0f;
      shmem.s_p0.s_fault_word.u_word = (uint32_t)0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
