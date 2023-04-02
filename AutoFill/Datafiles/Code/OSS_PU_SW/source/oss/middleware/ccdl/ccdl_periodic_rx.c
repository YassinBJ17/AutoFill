/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Read the CCDL frame from opposite channel
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/ccdl/ccdl_public.h"
#include "middleware/ccdl/ccdl_private.h"
#include "memory/memory_address_public.h"
#include "memory/shared_memory_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
#define CCDL_UNAVAILABLE  0x2

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
ts_ccdl_frame ccdl_rx_frame;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CCDL-0020 */
/* Implements REQ_FADEX_OS_SRD-CCDL-0030 */
void ccdl_periodic_rx(const boolean_t channel_is_a)
{
   /* Sample FPGA flags to have one consistent set of error fpga flags */
   ts_ccdl_rx_status_reg fpga_fault_word = fpga_ccdl->s_rx_status;

   /* Populate shmem */
   shmem.s_ccdl_rx.s_fault_word.u_bit.s_crc_invalid    = fpga_fault_word.u_bit.s_crc_valid  ? (uint32_t)0 : (uint32_t)1;
   shmem.s_ccdl_rx.s_fault_word.u_bit.s_size_invalid   = fpga_fault_word.u_bit.s_size_valid ? (uint32_t)0 : (uint32_t)1;
   shmem.s_ccdl_rx.s_fault_word.u_bit.s_sof_invalid    = fpga_fault_word.u_bit.s_sof_valid  ? (uint32_t)0 : (uint32_t)1;
   shmem.s_ccdl_rx.s_fault_word.u_bit.s_parity_invalid = fpga_fault_word.u_bit.s_parity_err;
   shmem.s_ccdl_rx.s_fault_word.u_bit.s_no_new_frame   = fpga_fault_word.u_bit.s_new_frame  ? (uint32_t)0 : (uint32_t)1;
   shmem.s_ccdl_rx.s_fault_word.u_bit.s_busy           = fpga_fault_word.u_bit.s_busy;

   shmem.s_ccdl_rx.s_fault_word.u_bit.s_invalid        = shmem.s_ccdl_rx.s_fault_word.u_bit.s_crc_invalid    ||
                                                         shmem.s_ccdl_rx.s_fault_word.u_bit.s_size_invalid   ||
                                                         shmem.s_ccdl_rx.s_fault_word.u_bit.s_sof_invalid    ||
                                                         shmem.s_ccdl_rx.s_fault_word.u_bit.s_parity_invalid ||
                                                         shmem.s_ccdl_rx.s_fault_word.u_bit.s_no_new_frame   ||
                                                         shmem.s_ccdl_rx.s_fault_word.u_bit.s_busy;

   /* Acknowledge new frame */
   if(0 == shmem.s_ccdl_rx.s_fault_word.u_bit.s_no_new_frame)
   {
      fpga_ccdl->s_rx_control.u_bit.s_new_frame_ack = 1;
   }

   /* Acknowledge parity error */
   if(1 == shmem.s_ccdl_rx.s_fault_word.u_bit.s_parity_invalid)
   {
      fpga_ccdl->s_rx_control.u_bit.s_parity_err_ack = 1;
   }

   /* Read from FPGA Rx buffer when data is ready to be read */
   if(0 == shmem.s_ccdl_rx.s_fault_word.u_bit.s_invalid)
   {
      /* Update CCDL CSS data exchanges if AS asks to transfer data */
      shmem.s_ccdl_rx.s_index = fpga_ccdl->s_rx_data.s_index;
      if(shmem.s_ccdl_rx.s_index != 0)
      {
         shmem.s_ccdl_rx.s_message.s_length                  = fpga_ccdl->s_rx_data.s_css_data_size;
         /* If FPGA payload holds anything over CCDL message size, then saturate value. */
         if(shmem.s_ccdl_rx.s_message.s_length > CCDL_MSG_SIZE)
         {
            shmem.s_ccdl_rx.s_message.s_length = CCDL_MSG_SIZE;
         }
         LIB_MEM_CPY((int8_t*)shmem.s_ccdl_rx.s_message.s_data , (int8_t*)fpga_ccdl->s_rx_data.s_css_data , CCDL_MSG_SIZE);
      }
      /* A429 data processing */
      if(FALSE == channel_is_a)
      {
         ccdl_a429_2ab_tx_from_ch_a.s_tx_count = fpga_ccdl->s_rx_data.s_a429_2ab_tx_count;
         LIB_MEM_CPY((int8_t*)ccdl_a429_2ab_tx_from_ch_a.s_tx_word , (int8_t*)(fpga_ccdl->s_rx_data.s_a429_2ab_tx_words) , 4 * CCDL_A429_2AB_TX_WORDS_COUNT);
      }
      else
      {
         ccdl_a429_2ab_tx_from_ch_a.s_tx_count  = 0;
         LIB_MEM_SET((int8_t*)ccdl_a429_2ab_tx_from_ch_a.s_tx_word, 0 , 4 * CCDL_A429_2AB_TX_WORDS_COUNT);
         shmem.s_a429_2ab_tx.s_tx_status.u_word = fpga_ccdl->s_rx_data.s_a429_2ab_tx_cbit_wrd;
      }
      /* Receive VRT data */
      {
         ts_temp * shmem_local_vrt1                       = channel_is_a ? &(shmem.s_t1b)  : &(shmem.s_t1a);
         ts_temp * shmem_local_vrt2                       = channel_is_a ? &(shmem.s_t2b)  : &(shmem.s_t2a);
         ts_temp * shmem_local_vrtff                      = channel_is_a ? &(shmem.s_tffb) : &(shmem.s_tffa);

         shmem_local_vrt1 ->s_measure                     = fpga_ccdl->s_rx_data.s_vrt1_measure;
         shmem_local_vrt1 ->s_fault_word.u_word           = fpga_ccdl->s_rx_data.s_vrt1_cbit_wrd;
         shmem_local_vrt2 ->s_measure                     = fpga_ccdl->s_rx_data.s_vrt2_measure;
         shmem_local_vrt2 ->s_fault_word.u_word           = fpga_ccdl->s_rx_data.s_vrt2_cbit_wrd;
         shmem_local_vrtff->s_measure                     = fpga_ccdl->s_rx_data.s_vrtff_measure;
         shmem_local_vrtff->s_fault_word.u_word           = fpga_ccdl->s_rx_data.s_vrtff_cbit_wrd;
      }
      /* Receive SG data from other channel */
      {
         ts_sg * shmem_local_ts_p3                        = channel_is_a ?  &(shmem.s_p3_b)  : &(shmem.s_p3_a);
         ts_sg * shmem_local_ts_sg_1_3                    = channel_is_a ?  &(shmem.s_sg3_b) : &(shmem.s_sg1_a);
         ts_sg * shmem_local_ts_sg_2_4                    = channel_is_a ?  &(shmem.s_sg4_b) : &(shmem.s_sg2_a);

         shmem_local_ts_p3->s_measure                     = fpga_ccdl->s_rx_data.s_p3_measure;
         shmem_local_ts_p3->s_fault_word.u_word           = fpga_ccdl->s_rx_data.s_p3_cbit_wrd;
         shmem_local_ts_sg_1_3->s_measure                 = fpga_ccdl->s_rx_data.s_sg1_sg3_measure;
         shmem_local_ts_sg_1_3->s_fault_word.u_word       = fpga_ccdl->s_rx_data.s_sg1_sg3_cbit_wrd;
         shmem_local_ts_sg_2_4->s_measure                 = fpga_ccdl->s_rx_data.s_sg2_sg4_measure;
         shmem_local_ts_sg_2_4->s_fault_word.u_word       = fpga_ccdl->s_rx_data.s_sg2_sg4_cbit_wrd;
         if (TRUE == channel_is_a)
         {
            shmem.s_sg5_b.s_measure                       = fpga_ccdl->s_rx_data.s_sg5_measure;
            shmem.s_sg5_b.s_fault_word.u_word             = fpga_ccdl->s_rx_data.s_sg5_cbit_wrd;
         }
         else
         {
            /* Do nothing as shmem is refreshed by corresponding capability */
         }
      }
      /* Receive T4 data from other channel */
      {
         ts_temp4 * shmem_local_t4                        = channel_is_a ? &(shmem.s_t4b) : &(shmem.s_t4a);

         shmem_local_t4->s_measure                        = fpga_ccdl->s_rx_data.s_t4_measure;
         shmem_local_t4->s_fault_word.u_word              = fpga_ccdl->s_rx_data.s_t4_cbit_wrd;
      }
      /* Receive pot data from other channel */
      {
         ts_pot     * shmem_local_ts_pot                  = channel_is_a ? &(shmem.s_pot2)     : &(shmem.s_pot1);
         ts_potdiff * shmem_local_ts_potdiff              = channel_is_a ? &(shmem.s_potdiff2) : &(shmem.s_potdiff1);

         shmem_local_ts_pot->s_measure                    = fpga_ccdl->s_rx_data.s_pot_1_2_measure;
         shmem_local_ts_pot->s_fault_word.u_word          = fpga_ccdl->s_rx_data.s_pot_1_2_cbit_wrd;
         shmem_local_ts_potdiff->s_measure                = fpga_ccdl->s_rx_data.s_potdiff_1_2_measure;
         shmem_local_ts_potdiff->s_fault_word.u_word      = fpga_ccdl->s_rx_data.s_potdiff_1_2_cbit_wrd;
      }
      if(TRUE == channel_is_a)
      {
         shmem.s_pot3.s_measure                           = fpga_ccdl->s_rx_data.s_pot_3_measure;
         shmem.s_pot3.s_fault_word.u_word                 = fpga_ccdl->s_rx_data.s_pot_3_cbit_wrd;
      }
      else
      {
         /* Do nothing as shmem is refreshed by corresponding capability */
      }
      /* Receive resolver data from other channel */
      {
         ts_xr * shmem_local_ts_xr                        = channel_is_a ? &(shmem.s_xr_b) : &(shmem.s_xr);

         shmem_local_ts_xr->s_measure                     = fpga_ccdl->s_rx_data.s_xr_xrb_measure;
         shmem_local_ts_xr->s_vcos_measure                = fpga_ccdl->s_rx_data.s_xr_xrb_vcos_measure;
         shmem_local_ts_xr->s_vsin_measure                = fpga_ccdl->s_rx_data.s_xr_xrb_vsin_measure;
         shmem_local_ts_xr->s_fault_word.u_word           = fpga_ccdl->s_rx_data.s_xr_xrb_fault_wrd;
      }
      /* Receive lvdt data from other channel */
      {
         ts_lvdt * shmem_local_ts_lvdt                    = channel_is_a ? &(shmem.s_lvdtb) : &(shmem.s_lvdta);

         shmem_local_ts_lvdt->s_measure                   = fpga_ccdl->s_rx_data.s_lvdtab_ratio_measure;
         shmem_local_ts_lvdt->s_vs1_measure               = fpga_ccdl->s_rx_data.s_lvdtab_vs1_measure;
         shmem_local_ts_lvdt->s_vs2_measure               = fpga_ccdl->s_rx_data.s_lvdtab_vs2_measure;
         shmem_local_ts_lvdt->s_fault_word.u_word         = fpga_ccdl->s_rx_data.s_lvdtab_cbit_wrd;
      }
      if (FALSE == channel_is_a)
      {
         shmem.s_lvdtc.s_measure                          = fpga_ccdl->s_rx_data.s_lvdtc_ratio_measure;
         shmem.s_lvdtc.s_vs1_measure                      = fpga_ccdl->s_rx_data.s_lvdtc_vs1_measure;
         shmem.s_lvdtc.s_vs2_measure                      = fpga_ccdl->s_rx_data.s_lvdtc_vs2_measure;
         shmem.s_lvdtc.s_fault_word.u_word                = fpga_ccdl->s_rx_data.s_lvdtc_cbit_wrd;
      }
      else
      {
         /* Do nothing as shmem is refreshed by corresponding capability */
      }
      /* Receive p0 data from other channel */
      if (TRUE == channel_is_a)
      {
         shmem.s_p0.s_measure                             = fpga_ccdl->s_rx_data.s_p0_measure;
         shmem.s_p0.s_fault_word.u_word                   = fpga_ccdl->s_rx_data.s_p0_cbit_wrd;
      }
      else
      {
         /* Do nothing as shmem is refreshed by corresponding capability */
      }
      /* Receive calres data from other channel */
      {
         ts_calres * shmem_local_ts_calres                = channel_is_a ? &(shmem.s_calres_3_4) : &(shmem.s_calres_1_2);
         shmem_local_ts_calres->s_calres_measure1         = fpga_ccdl->s_rx_data.s_calres_1_3_measure;
         shmem_local_ts_calres->s_calres_measure2         = fpga_ccdl->s_rx_data.s_calres_2_4_measure;
         shmem_local_ts_calres->s_fault_word.u_word       = fpga_ccdl->s_rx_data.s_calres_cbit_wrd;
      }
      /* Receive tecu data from other channel */
      {
         ts_tecu * shmem_local_ts_tecu                    = channel_is_a ? &(shmem.s_tecub)  : &(shmem.s_tecua);
         shmem_local_ts_tecu->s_measure                   = fpga_ccdl->s_rx_data.s_tecu_measure;
         shmem_local_ts_tecu->s_fault_word.u_word         = fpga_ccdl->s_rx_data.s_tecu_cbit_wrd;
      }
      /* Receive nfreq data from other channel */
      {
         ts_ngalt  * shmem_local_ts_ngalt                 = channel_is_a ? &(shmem.s_ngalt_b)  : &(shmem.s_ngalt_a);
         ts_nfreq2 * shmem_local_ts_nfreq2                = channel_is_a ? &(shmem.s_nfreq2_b) : &(shmem.s_nfreq2_a);
         ts_nfreq3 * shmem_local_ts_nfreq3                = channel_is_a ? &(shmem.s_nfreq3_b) : &(shmem.s_nfreq3_a);

         shmem_local_ts_ngalt->s_measure                  = fpga_ccdl->s_rx_data.s_ngalt_measure;
         shmem_local_ts_ngalt->s_fault_word.u_word        = fpga_ccdl->s_rx_data.s_ngalt_cbit_wrd;
         shmem_local_ts_nfreq2->s_measure                 = fpga_ccdl->s_rx_data.s_nfreq2_measure;
         shmem_local_ts_nfreq2->s_fault_word.u_word       = fpga_ccdl->s_rx_data.s_nfreq2_cbit_wrd;
         shmem_local_ts_nfreq3->s_measure                 = fpga_ccdl->s_rx_data.s_nfreq3_measure;
         shmem_local_ts_nfreq3->s_fault_word.u_word       = fpga_ccdl->s_rx_data.s_nfreq3_cbit_wrd;
         shmem_local_ts_nfreq3->s_ratio                   = fpga_ccdl->s_rx_data.s_nfreq3_ratio_measure;
         LIB_MEM_CPY((int8_t *)shmem_local_ts_nfreq3->s_t_measure   , (int8_t*)fpga_ccdl->s_rx_data.s_nfreq3_tn_measures  , NFREQ3_MEASURES_COUNT);
         LIB_MEM_CPY((int8_t *)shmem_local_ts_nfreq3->s_tpn_measure , (int8_t*)fpga_ccdl->s_rx_data.s_nfreq3_tpn_measures , NFREQ3_MEASURES_COUNT);
      }
      /* Receive tmot data from other channel */
      {
         ts_tmot_r * shmem_local_ts_tmot = channel_is_a ? &(shmem.s_tmot_r_b) : &(shmem.s_tmot_r_a);

         shmem_local_ts_tmot->s_current                   = fpga_ccdl->s_rx_data.s_tmot_measure_current;
         shmem_local_ts_tmot->s_voltage                   = fpga_ccdl->s_rx_data.s_tmot_measure_voltage;
         shmem_local_ts_tmot->s_fault_word.u_word         = fpga_ccdl->s_rx_data.s_tmot_cbit_wrd;
      }
      /* Receive health word data from other channel */
      shmem.s_o_health_wd_status_ccdl.u_word              = fpga_ccdl->s_rx_data.s_ch_health_wrd;
   }
   else
   {
      shmem.s_ccdl_rx.s_index = 0;

      {
         ts_temp * shmem_local_vrt1                       = channel_is_a ? &(shmem.s_t1b)  : &(shmem.s_t1a);
         ts_temp * shmem_local_vrt2                       = channel_is_a ? &(shmem.s_t1b)  : &(shmem.s_t1a);
         ts_temp * shmem_local_vrtff                      = channel_is_a ? &(shmem.s_t1b)  : &(shmem.s_t1a);

         shmem_local_vrt1 ->s_fault_word.u_word           = CCDL_UNAVAILABLE;
         shmem_local_vrt2 ->s_fault_word.u_word           = CCDL_UNAVAILABLE;
         shmem_local_vrtff->s_fault_word.u_word           = CCDL_UNAVAILABLE;
      }
      {
         ts_sg * shmem_local_ts_p3                        = channel_is_a ?  &(shmem.s_p3_b)  : &(shmem.s_p3_a);
         ts_sg * shmem_local_ts_sg_1_3                    = channel_is_a ?  &(shmem.s_sg3_b) : &(shmem.s_sg1_a);
         ts_sg * shmem_local_ts_sg_2_4                    = channel_is_a ?  &(shmem.s_sg4_b) : &(shmem.s_sg2_a);

         shmem_local_ts_p3->s_fault_word.u_word           = CCDL_UNAVAILABLE;
         shmem_local_ts_sg_1_3->s_fault_word.u_word       = CCDL_UNAVAILABLE;
         shmem_local_ts_sg_2_4->s_fault_word.u_word       = CCDL_UNAVAILABLE;
      }
      if (TRUE == channel_is_a)
      {
         shmem.s_sg5_b.s_fault_word.u_word                = CCDL_UNAVAILABLE;
      }
      {
         ts_temp4 * shmem_local_t4                        = channel_is_a ? &(shmem.s_t4b) : &(shmem.s_t4a);

         shmem_local_t4->s_fault_word.u_word              = CCDL_UNAVAILABLE;
      }
      {
         ts_pot     * shmem_local_ts_pot                  = channel_is_a ? &(shmem.s_pot2)     : &(shmem.s_pot1);
         ts_potdiff * shmem_local_ts_potdiff              = channel_is_a ? &(shmem.s_potdiff2) : &(shmem.s_potdiff1);

         shmem_local_ts_pot->s_fault_word.u_word          = CCDL_UNAVAILABLE;
         shmem_local_ts_potdiff->s_fault_word.u_word      = CCDL_UNAVAILABLE;
      }
      if(TRUE == channel_is_a)
      {
         shmem.s_pot3.s_fault_word.u_word                 = CCDL_UNAVAILABLE;
      }
      {
         ts_xr * shmem_local_ts_xr                        = channel_is_a ? &(shmem.s_xr_b) : &(shmem.s_xr);

         shmem_local_ts_xr->s_fault_word.u_word           = CCDL_UNAVAILABLE;
      }
      {
         ts_lvdt * shmem_local_ts_lvdt                    = channel_is_a ? &(shmem.s_lvdtb) : &(shmem.s_lvdta);

         shmem_local_ts_lvdt->s_fault_word.u_word         = CCDL_UNAVAILABLE;
      }
      if (FALSE == channel_is_a)
      {
         shmem.s_lvdtc.s_fault_word.u_word                = CCDL_UNAVAILABLE;
      }
      if (TRUE == channel_is_a)
      {
         shmem.s_p0.s_fault_word.u_word                   = CCDL_UNAVAILABLE;
      }
      {
         ts_calres * shmem_local_ts_calres                = channel_is_a ? &(shmem.s_calres_3_4) : &(shmem.s_calres_1_2);

         shmem_local_ts_calres->s_fault_word.u_word       = CCDL_UNAVAILABLE;
      }
      {
         ts_tecu * shmem_local_ts_tecu                    = channel_is_a ? &(shmem.s_tecub)  : &(shmem.s_tecua);

         shmem_local_ts_tecu->s_fault_word.u_word         = CCDL_UNAVAILABLE;
      }
      {
         ts_ngalt  * shmem_local_ts_ngalt                 = channel_is_a ? &(shmem.s_ngalt_b)  : &(shmem.s_ngalt_a);
         ts_nfreq2 * shmem_local_ts_nfreq2                = channel_is_a ? &(shmem.s_nfreq2_b) : &(shmem.s_nfreq2_a);
         ts_nfreq3 * shmem_local_ts_nfreq3                = channel_is_a ? &(shmem.s_nfreq3_b) : &(shmem.s_nfreq3_a);

         shmem_local_ts_ngalt->s_fault_word.u_word        = CCDL_UNAVAILABLE;
         shmem_local_ts_nfreq2->s_fault_word.u_word       = CCDL_UNAVAILABLE;
         shmem_local_ts_nfreq3->s_fault_word.u_word       = CCDL_UNAVAILABLE;
      }
      {
         ts_tmot_r * shmem_local_ts_tmot = channel_is_a ? &(shmem.s_tmot_r_b) : &(shmem.s_tmot_r_a);

         shmem_local_ts_tmot->s_fault_word.u_word         = CCDL_UNAVAILABLE;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
