/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Transmit the CCDL frame to opposite channel
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

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
uint32_t sent_frames_counter;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CCDL-0040 */
/* Implements REQ_FADEX_OS_SRD-CCDL-0050 */
void ccdl_periodic_tx(const boolean_t channel_is_a)
{
   /* Populate TX frame buffer in FPGA */
   fpga_ccdl->s_tx_data.s_index                        = shmem.s_ccdl_tx.s_index;
   fpga_ccdl->s_tx_data.s_css_data_size                = shmem.s_ccdl_tx.s_message.s_length;
   LIB_MEM_CPY((int8_t*)(fpga_ccdl->s_tx_data.s_css_data), (int8_t*)shmem.s_ccdl_tx.s_message.s_data, CCDL_MSG_SIZE);
   if(TRUE == channel_is_a)
   {
      fpga_ccdl->s_tx_data.s_a429_2ab_tx_count           = shmem.s_a429_2ab_tx.s_tx_count;
      LIB_MEM_CPY((int8_t*)(fpga_ccdl->s_tx_data.s_a429_2ab_tx_words) , (int8_t*)shmem.s_a429_2ab_tx.s_tx_word , 4 * CCDL_A429_2AB_TX_WORDS_COUNT);
      fpga_ccdl->s_tx_data.s_a429_2ab_tx_cbit_wrd        = 0;
   }
   else
   {
      fpga_ccdl->s_tx_data.s_a429_2ab_tx_count           = 0;
      LIB_MEM_SET((int8_t*)(fpga_ccdl->s_tx_data.s_a429_2ab_tx_words), 0 , 4 * CCDL_A429_2AB_TX_WORDS_COUNT);
      fpga_ccdl->s_tx_data.s_a429_2ab_tx_cbit_wrd        = shmem.s_a429_2ab_tx.s_tx_status.u_word;
   }
   {
      ts_temp * shmem_local_vrt1                       = channel_is_a ? &(shmem.s_t1a)  : &(shmem.s_t1b);
      ts_temp * shmem_local_vrt2                       = channel_is_a ? &(shmem.s_t2a)  : &(shmem.s_t2b);
      ts_temp * shmem_local_vrtff                      = channel_is_a ? &(shmem.s_tffa) : &(shmem.s_tffb);

      fpga_ccdl->s_tx_data.s_vrt1_measure              = shmem_local_vrt1 ->s_measure;
      fpga_ccdl->s_tx_data.s_vrt1_cbit_wrd             = shmem_local_vrt1 ->s_fault_word.u_word;
      fpga_ccdl->s_tx_data.s_vrt2_measure              = shmem_local_vrt2 ->s_measure;
      fpga_ccdl->s_tx_data.s_vrt2_cbit_wrd             = shmem_local_vrt2 ->s_fault_word.u_word;
      fpga_ccdl->s_tx_data.s_vrtff_measure             = shmem_local_vrtff->s_measure;
      fpga_ccdl->s_tx_data.s_vrtff_cbit_wrd            = shmem_local_vrtff->s_fault_word.u_word;
   }
   {
      ts_sg * shmem_local_ts_p3                        = channel_is_a ?  &(shmem.s_p3_a)  : &(shmem.s_p3_b);
      ts_sg * shmem_local_ts_sg_1_3                    = channel_is_a ?  &(shmem.s_sg1_a) : &(shmem.s_sg3_b);
      ts_sg * shmem_local_ts_sg_2_4                    = channel_is_a ?  &(shmem.s_sg2_a) : &(shmem.s_sg4_b);

      fpga_ccdl->s_tx_data.s_p3_measure                = shmem_local_ts_p3->s_measure;
      fpga_ccdl->s_tx_data.s_p3_cbit_wrd               = shmem_local_ts_p3->s_fault_word.u_word;
      fpga_ccdl->s_tx_data.s_sg1_sg3_measure           = shmem_local_ts_sg_1_3->s_measure;
      fpga_ccdl->s_tx_data.s_sg1_sg3_cbit_wrd          = shmem_local_ts_sg_1_3->s_fault_word.u_word;
      fpga_ccdl->s_tx_data.s_sg2_sg4_measure           = shmem_local_ts_sg_2_4->s_measure;;
      fpga_ccdl->s_tx_data.s_sg2_sg4_cbit_wrd          = shmem_local_ts_sg_2_4->s_fault_word.u_word;
      fpga_ccdl->s_tx_data.s_sg5_measure               = shmem.s_sg5_b.s_measure;
      fpga_ccdl->s_tx_data.s_sg5_cbit_wrd              = shmem.s_sg5_b.s_fault_word.u_word;
   }
   {
      ts_temp4 * shmem_local_t4                        = channel_is_a ? &(shmem.s_t4a) : &(shmem.s_t4b);

      fpga_ccdl->s_tx_data.s_t4_measure                = shmem_local_t4->s_measure;
      fpga_ccdl->s_tx_data.s_t4_cbit_wrd               = shmem_local_t4->s_fault_word.u_word;
   }
   {
      ts_pot     * shmem_local_ts_pot                 = channel_is_a ? &(shmem.s_pot1)     : &(shmem.s_pot2);
      ts_potdiff * shmem_local_ts_potdiff             = channel_is_a ? &(shmem.s_potdiff1) : &(shmem.s_potdiff2);

      fpga_ccdl->s_tx_data.s_pot_1_2_measure          = shmem_local_ts_pot->s_measure;
      fpga_ccdl->s_tx_data.s_pot_1_2_cbit_wrd         = shmem_local_ts_pot->s_fault_word.u_word;
      fpga_ccdl->s_tx_data.s_potdiff_1_2_measure      = shmem_local_ts_potdiff->s_measure;
      fpga_ccdl->s_tx_data.s_potdiff_1_2_cbit_wrd     = shmem_local_ts_potdiff->s_fault_word.u_word;

      fpga_ccdl->s_tx_data.s_pot_3_measure           = channel_is_a ? 0 : shmem.s_pot3.s_measure;
      fpga_ccdl->s_tx_data.s_pot_3_cbit_wrd          = channel_is_a ? 0 : shmem.s_pot3.s_fault_word.u_word;
   }
   {
      ts_xr * shmem_local_ts_xr                        = channel_is_a ? &(shmem.s_xr) : &(shmem.s_xr_b);

      fpga_ccdl->s_tx_data.s_xr_xrb_measure            = shmem_local_ts_xr->s_measure;
      fpga_ccdl->s_tx_data.s_xr_xrb_vcos_measure       = shmem_local_ts_xr->s_vcos_measure;
      fpga_ccdl->s_tx_data.s_xr_xrb_vsin_measure       = shmem_local_ts_xr->s_vsin_measure;
      fpga_ccdl->s_tx_data.s_xr_xrb_fault_wrd          = shmem_local_ts_xr->s_fault_word.u_word;
   }
   {
      ts_lvdt * shmem_local_ts_lvdt                    = channel_is_a ? &(shmem.s_lvdta) : &(shmem.s_lvdtb);

      fpga_ccdl->s_tx_data.s_lvdtab_ratio_measure      = shmem_local_ts_lvdt->s_measure;
      fpga_ccdl->s_tx_data.s_lvdtab_vs1_measure        = shmem_local_ts_lvdt->s_vs1_measure;
      fpga_ccdl->s_tx_data.s_lvdtab_vs2_measure        = shmem_local_ts_lvdt->s_vs2_measure;
      fpga_ccdl->s_tx_data.s_lvdtab_cbit_wrd           = shmem_local_ts_lvdt->s_fault_word.u_word;
   }
   fpga_ccdl->s_tx_data.s_lvdtc_ratio_measure          = shmem.s_lvdtc.s_measure;
   fpga_ccdl->s_tx_data.s_lvdtc_vs1_measure            = shmem.s_lvdtc.s_vs1_measure;
   fpga_ccdl->s_tx_data.s_lvdtc_vs2_measure            = shmem.s_lvdtc.s_vs2_measure;
   fpga_ccdl->s_tx_data.s_lvdtc_cbit_wrd               = shmem.s_lvdtc.s_fault_word.u_word;
   fpga_ccdl->s_tx_data.s_p0_measure                   = shmem.s_p0.s_measure;
   fpga_ccdl->s_tx_data.s_p0_cbit_wrd                  = shmem.s_p0.s_fault_word.u_word;
   fpga_ccdl->s_tx_data.s_calres_1_3_measure           = channel_is_a ? shmem.s_calres_1_2.s_calres_measure1   : shmem.s_calres_3_4.s_calres_measure1;
   fpga_ccdl->s_tx_data.s_calres_2_4_measure           = channel_is_a ? shmem.s_calres_1_2.s_calres_measure2   : shmem.s_calres_3_4.s_calres_measure2;
   fpga_ccdl->s_tx_data.s_calres_cbit_wrd              = channel_is_a ? shmem.s_calres_1_2.s_fault_word.u_word : shmem.s_calres_3_4.s_fault_word.u_word;
   {
      ts_tecu * shmem_local_ts_tecu                    = channel_is_a ? &(shmem.s_tecua)  : &(shmem.s_tecub);
      fpga_ccdl->s_tx_data.s_tecu_measure              = shmem_local_ts_tecu->s_measure;
      fpga_ccdl->s_tx_data.s_tecu_cbit_wrd             = shmem_local_ts_tecu->s_fault_word.u_word;
   }
   {
      ts_ngalt  * shmem_local_ts_ngalt                 = channel_is_a ? &(shmem.s_ngalt_a)  : &(shmem.s_ngalt_b);
      ts_nfreq2 * shmem_local_ts_nfreq2                = channel_is_a ? &(shmem.s_nfreq2_a) : &(shmem.s_nfreq2_b);
      ts_nfreq3 * shmem_local_ts_nfreq3                = channel_is_a ? &(shmem.s_nfreq3_a) : &(shmem.s_nfreq3_b);

      fpga_ccdl->s_tx_data.s_ngalt_measure             = shmem_local_ts_ngalt->s_measure;
      fpga_ccdl->s_tx_data.s_ngalt_cbit_wrd            = shmem_local_ts_ngalt->s_fault_word.u_word;
      fpga_ccdl->s_tx_data.s_nfreq2_measure            = shmem_local_ts_nfreq2->s_measure;
      fpga_ccdl->s_tx_data.s_nfreq2_cbit_wrd           = shmem_local_ts_nfreq2->s_fault_word.u_word;
      fpga_ccdl->s_tx_data.s_nfreq3_measure            = shmem_local_ts_nfreq3->s_measure;
      fpga_ccdl->s_tx_data.s_nfreq3_cbit_wrd           = shmem_local_ts_nfreq3->s_fault_word.u_word;
      fpga_ccdl->s_tx_data.s_nfreq3_ratio_measure      = shmem_local_ts_nfreq3->s_ratio;
      LIB_MEM_CPY((int8_t*)fpga_ccdl->s_tx_data.s_nfreq3_tn_measures  , (int8_t *)shmem_local_ts_nfreq3->s_t_measure   , 4 * NFREQ3_MEASURES_COUNT);
      LIB_MEM_CPY((int8_t*)fpga_ccdl->s_tx_data.s_nfreq3_tpn_measures , (int8_t *)shmem_local_ts_nfreq3->s_tpn_measure , 4 * NFREQ3_MEASURES_COUNT);
   }
   {
      ts_tmot_r * shmem_local_ts_tmot = channel_is_a ? &(shmem.s_tmot_r_a) : &(shmem.s_tmot_r_b);

      fpga_ccdl->s_tx_data.s_tmot_measure_current       = shmem_local_ts_tmot->s_current;
      fpga_ccdl->s_tx_data.s_tmot_measure_voltage       = shmem_local_ts_tmot->s_voltage;
      fpga_ccdl->s_tx_data.s_tmot_cbit_wrd              = shmem_local_ts_tmot->s_fault_word.u_word;
   }
   fpga_ccdl->s_tx_data.s_ch_health_wrd                 = shmem.s_health_wd_status.u_word;


   /* Update CCDL fault word  */
   shmem.s_ccdl_tx.s_fault_word.u_bit.s_busy           = fpga_ccdl->s_tx_status.u_bit.s_ccdl_tx_busy;
   shmem.s_ccdl_tx.s_fault_word.u_bit.s_invalid        = shmem.s_ccdl_tx.s_fault_word.u_bit.s_busy;

   /* Trigger transfer to oppposite channel if not busy */
   if (0 == shmem.s_ccdl_tx.s_fault_word.u_bit.s_busy)
   {
      /* Set transmission mode to immediate, size and start transfer */
      fpga_ccdl->s_tx_cmd.u_bit.s_ccdl_tx_mode         = (uint32_t)0;
      fpga_ccdl->s_tx_cmd.u_bit.s_ccdl_tx_size         = ccdl_frame_size_in_bytes / 4;
      fpga_ccdl->s_tx_cmd.u_bit.s_ccdl_tx_start        = (uint32_t)1;

      /* Acknowledgement for AS */
      shmem.s_ccdl_tx.s_index                          = 0;
   }
   else
   {
      /* Do nothing, as nothing can be done. */
   }
}

/* ---------- internal operations: ------------------------------------------ */
