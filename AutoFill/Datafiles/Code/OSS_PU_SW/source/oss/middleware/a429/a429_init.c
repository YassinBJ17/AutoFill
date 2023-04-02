/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Incrementation of RTC counter
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/a429/a429_private.h"
#include "middleware/a429/a429_public.h"
#include "conf/oss_conf_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Registers for A429 1A RX & TX */
ts_a429_rx_reg* fpga_a429_1a_rx;
ts_a429_tx_reg* fpga_a429_1a_tx;

/* Registers for A429 2AB RX & TX */
ts_a429_rx_reg* fpga_a429_2ab_rx;
ts_a429_tx_reg* fpga_a429_2ab_tx;

/* Maximum number of received words to process for A429 1A and A429 2AB */
uint32_t a429_1a_words_max;
uint32_t a429_2ab_words_max;

/* Configured SDI+label read from configuration table for A429 1A and A429 2AB */
uint16_t a429_1a_rx_sdi_label[SDI_LABEL_FILTERING_CONFIGURABLE_NB];
uint16_t a429_2ab_rx_sdi_label[SDI_LABEL_FILTERING_CONFIGURABLE_NB];

/* Configuration for the transmitter of the A429 2AB */
uint32_t a429_2ab_tx_conf;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-A429-0001 */
/* Implements REQ_FADEX_OS_SRD-A429-0010 */
/* Initialize the A429 (Input : Is it the channel A?) */
void a429_init(const boolean_t ch_is_a)
{
   /* Configuration table SDI+label iterator */
   uint32_t i;

   /* TODO : Use the configuration table in the flash */
   /* Simulated by a configuration table in mram */
   ts_oss_conf_table* oss_conf;

   /* Retrieve conf in MRAM */
   oss_conf = (ts_oss_conf_table*)(OSS_CONF_START_ADDR);

   /* Initialize the pointers to registers */
   fpga_a429_1a_rx = A429_1A_RX_ADDR;
   fpga_a429_1a_tx = A429_1A_2AB_TX_ADDR;
   fpga_a429_2ab_rx = A429_2AB_RX_ADDR;
   fpga_a429_2ab_tx = A429_1A_2AB_TX_ADDR;

   /* Read the configuration for A429 2AB in the configuration table */
   a429_2ab_tx_conf = oss_conf->s_a429_2ab_config;

   /* Read the allowed SDI+label in the configuration table */
   for (i = (uint32_t)0; i < SDI_LABEL_FILTERING_CONFIGURABLE_NB; i++)
   {
      /* Set the configured sdi+label to keep after filtering to the ones in configuration table */
      a429_1a_rx_sdi_label[i] = oss_conf->s_a429_1a_rx_sdi_label[i];
      a429_2ab_rx_sdi_label[i] = oss_conf->s_a429_2ab_rx_sdi_label[i];
   }

   /* A429 2AB RX: Set the link speed from the configuration table */
   fpga_a429_2ab_rx->cmd.u_bit.s_storage_mode = (uint32_t)1;

   /* A429 2AB RX: Flush the rx ram */
   fpga_a429_2ab_rx->cmd.u_bit.s_flush_cmd = (uint32_t)1;

   /* If the channel identifier is A (=> CPMB) */
   if (TRUE == ch_is_a)
   {
      /* A429 1A RX: Configure in queueing mode */
      fpga_a429_1a_rx->cmd.u_bit.s_storage_mode = (uint32_t)1;

      /* A429 1A TX: Set the link speed from the configuration table */
      fpga_a429_1a_tx->conf.u_bit.s_speed_select = oss_conf->s_a429_1a_baud;

      /* If high speed is configured for A429 1A */
      if ((uint32_t)1 == oss_conf->s_a429_1a_baud)
      {
         /* The maximum number of words to process is A429_MAX_WORD_PROCESSED_IN_HS_NB */
         a429_1a_words_max = A429_MAX_WORD_PROCESSED_IN_HS_NB;

         /* Configure the reception times for the high speed */
         fpga_a429_1a_rx->gap.u_bit.s_filter_time = HS_FILTER_TIME;
         fpga_a429_1a_rx->gap.u_bit.s_gap_bit_time = HS_GAP_BIT_TIME;
         fpga_a429_1a_rx->hbit.u_bit.s_max_hbit_time = HS_HBIT_TIME_MAX;
         fpga_a429_1a_rx->hbit.u_bit.s_min_hbit_time = HS_HBIT_TIME_MIN;
         fpga_a429_1a_rx->bit.u_bit.s_max_bit_time = HS_BIT_TIME_MAX;
         fpga_a429_1a_rx->bit.u_bit.s_min_bit_time = HS_BIT_TIME_MIN;
      }
      /* Otherwise, if it is low speed */
      else
      {
         /* The maximum number of words to process is A429_MAX_WORD_PROCESSED_IN_LS_NB */
         a429_1a_words_max = A429_MAX_WORD_PROCESSED_IN_LS_NB;

         /* Configure the reception times for the low speed */
         fpga_a429_1a_rx->gap.u_bit.s_filter_time = LS_FILTER_TIME;
         fpga_a429_1a_rx->gap.u_bit.s_gap_bit_time = LS_GAP_BIT_TIME;
         fpga_a429_1a_rx->hbit.u_bit.s_max_hbit_time = LS_HBIT_TIME_MAX;
         fpga_a429_1a_rx->hbit.u_bit.s_min_hbit_time = LS_HBIT_TIME_MIN;
         fpga_a429_1a_rx->bit.u_bit.s_max_bit_time = LS_BIT_TIME_MAX;
         fpga_a429_1a_rx->bit.u_bit.s_min_bit_time = LS_BIT_TIME_MIN;
      }

      /* A429 1A TX: Clear the tx ram */
      fpga_a429_1a_tx->cmd.u_bit.s_flush_cmd = (uint32_t)1;

      /* A429 1A RX: Clear the rx ram */
      fpga_a429_1a_rx->cmd.u_bit.s_flush_cmd = (uint32_t)1;

      /* A429 1A RX: Enable the reception */
      fpga_a429_1a_rx->cmd.u_bit.s_enable_rx = (uint32_t)1;

      /* A429 1A TX: Enable the transmission */
      fpga_a429_1a_tx->cmd.u_bit.s_enable_tx = (uint32_t)1;
   }
   /* If the channel identifier is B (=> CPB) */
   else
   {
      /* A429 2AB TX: Set the link speed from the configuration table */
      fpga_a429_2ab_tx->conf.u_bit.s_speed_select = oss_conf->s_a429_2ab_baud;

      /* A429 2AB TX: Flush the tx ram */
      fpga_a429_2ab_tx->cmd.u_bit.s_flush_cmd = (uint32_t)1;

      /* A429 2AB TX: Enable the transmission */
      fpga_a429_2ab_tx->cmd.u_bit.s_enable_tx = (uint32_t)1;
   }

   /* If high speed is configured for A429 2AB */
   if ((uint32_t)1 == oss_conf->s_a429_2ab_baud)
   {
      /* The maximum number of words to process is A429_MAX_WORD_PROCESSED_IN_HS_NB */
      a429_2ab_words_max = A429_MAX_WORD_PROCESSED_IN_HS_NB;

      /* Configure the reception times for the high speed */
      fpga_a429_2ab_rx->gap.u_bit.s_filter_time = HS_FILTER_TIME;
      fpga_a429_2ab_rx->gap.u_bit.s_gap_bit_time = HS_GAP_BIT_TIME;
      fpga_a429_2ab_rx->hbit.u_bit.s_max_hbit_time = HS_HBIT_TIME_MAX;
      fpga_a429_2ab_rx->hbit.u_bit.s_min_hbit_time = HS_HBIT_TIME_MIN;
      fpga_a429_2ab_rx->bit.u_bit.s_max_bit_time = HS_BIT_TIME_MAX;
      fpga_a429_2ab_rx->bit.u_bit.s_min_bit_time = HS_BIT_TIME_MIN;
   }
   /* Otherwise, if it is low speed */
   else
   {
      /* The maximum number of words to process is A429_MAX_WORD_PROCESSED_IN_LS_NB */
      a429_2ab_words_max = A429_MAX_WORD_PROCESSED_IN_LS_NB;

      /* Configure the reception times for the low speed */
      fpga_a429_2ab_rx->gap.u_bit.s_filter_time = LS_FILTER_TIME;
      fpga_a429_2ab_rx->gap.u_bit.s_gap_bit_time = LS_GAP_BIT_TIME;
      fpga_a429_2ab_rx->hbit.u_bit.s_max_hbit_time = LS_HBIT_TIME_MAX;
      fpga_a429_2ab_rx->hbit.u_bit.s_min_hbit_time = LS_HBIT_TIME_MIN;
      fpga_a429_2ab_rx->bit.u_bit.s_max_bit_time = LS_BIT_TIME_MAX;
      fpga_a429_2ab_rx->bit.u_bit.s_min_bit_time = LS_BIT_TIME_MIN;
   }

   /* A429 2AB RX: Enable the reception */
   fpga_a429_2ab_rx->cmd.u_bit.s_enable_rx = (uint32_t)1;

   return;
}

/* ---------- internal operations: ------------------------------------------ */
