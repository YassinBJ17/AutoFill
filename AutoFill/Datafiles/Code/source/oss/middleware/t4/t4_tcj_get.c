/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : TCJ and TCJ status acquisition through I2C
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/t4/t4_private.h"
#include "middleware/t4/t4_private.h"
#include "driver/i2c/drv_I2C_public.h"
#include "middleware/rtc/rtc_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define I2C1_TCJ_ADD (uint8_t)0b10010000

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
float32_t tcj_conv;
/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-T4-0010 */
/* Implements REQ_FADEX_OS_SRD-T4-0020 */
/* Implements REQ_FADEX_OS_SRD-T4-0030 */
/* TCJ and TCJ status acquisition through I2C */
void t4_tcj_get(float32_t * const tcj, ts_temp4 * const shmem_t4)
{
   tu_CMN_RC i2c1_tcj_read_err; /* Error word when reading through I2C */
   tu_CMN_RC i2c1_tcj_cmd_err; /* Error word when reading through I2C */
   tu_CMN_RC i2c1_tcj_stat_err; /* Error word when reading through I2C */
   uint16_t tcj_read;  /* 16 bit word TCJ value retrieved from I2C */
   uint16_t tcj_stat;  /* 16 bit word TCJ status retrieved from I2C */

   /* Initialisation of variables */
   tcj_conv  = (uint16_t)0;
   tcj_stat  = (uint16_t)0;
   i2c1_tcj_read_err.u_r = (uint32_t)0;
   i2c1_tcj_cmd_err.u_r = (uint32_t)0;
   i2c1_tcj_stat_err.u_r = (uint32_t)0;

   /* Use I2C driver to get TCJ temps in one 16bit word */
   drv_I2C_READ_WORD16(e_I2C_LINE_1,I2C1_TCJ_ADD, &tcj_read ,&i2c1_tcj_read_err);

   /* Write command 0x01 to acces Status register of TMP116 */
   drv_I2C_WRITE_CMD ( e_I2C_LINE_1, I2C1_TCJ_ADD ,  (uint8_t)0x01,  &i2c1_tcj_cmd_err);

   /* Use I2C driver to get tcj statusin one 16bit word */
   drv_I2C_READ_WORD16(e_I2C_LINE_1,I2C1_TCJ_ADD, &tcj_stat ,&i2c1_tcj_stat_err);

   /* Write command 0x00 to acces TCJ temp register of TMP116 for next RTC */
   drv_I2C_WRITE_CMD ( e_I2C_LINE_1, I2C1_TCJ_ADD ,  (uint8_t)0x00,  &i2c1_tcj_cmd_err);

   tcj_stat = tcj_stat & TCJ_STATUS_MASK;

   if (tcj_stat > 0)
   {
      shmem_t4->s_fault_word.u_bit.s_tcj_status = (uint32_t)1;
   }
   else
   {
      shmem_t4->s_fault_word.u_bit.s_tcj_status = (uint32_t)0;
   }


   /* Convertion of TCJ value into understandable floating point value */
   /* If TCJ is a positive temperature -> raw_tcj in [0;32767] */
   if (tcj_read < RAW_TCJ_LIMIT_VAL)
   {
      /* Converstion with 0.0078125 resolution, see BSIS table */
      tcj_conv = TCJ_CONV_RESOLUTION * (float32_t)tcj_read;
   }
   /* Else TCJ is a negative temperature -> raw_tcj in [32768;65535] */
   else
   {
      /* Converstion with 0.0078125 resolution, see BSIS table */
      tcj_conv = (TCJ_CONV_RESOLUTION * (float32_t)tcj_read) - TCJ_NEG_OFFSET;
   }

   /* Filtering TCJ value */
   /* If it's not the first RTC */
   if ((uint32_t)1 != rtc_counter)
   {
      *tcj = (tcj_conv * ((float32_t)1.0 - TCJ_FILTER_VALUE)) + (previous_tcj_value * TCJ_FILTER_VALUE);
   }
   else
   {
      /* Else first RTC so no filter */
      *tcj = tcj_conv;
   }

   /* If TCJ is out of range */
   if (tcj_conv < RAW_TCJ_MIN || tcj_conv > RAW_TCJ_MAX)
   {
      /* Indicate TCJ out of range fault to CSS */
      shmem_t4->s_fault_word.u_bit.s_tcj_out_of_range = (uint32_t)1;
   }
   /* Else TCJ is valid */
   else
   {
      /* Update previous TCJ value */
      previous_tcj_value = *tcj ;
   }





}

/* ---------- internal operations: ------------------------------------------ */
