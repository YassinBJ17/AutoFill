/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Copy designated nFreq information to shared memory
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/nfreq/nfreq_private.h"
#include "middleware/nfreq/nfreq_shmem_write_measure.h"
#include "middleware/nfreq/nfreq_shmem_write_sample.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Copy designated nFreq information to shared memory */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0010 */
void nfreq_shmem_write_measure(const boolean_t        p_channel_is_a,
                               te_nfreq_sensor        p_sensor_id,
                               ts_nfreq_sensor_info * p_sensor_info)
{
   float32_t          * v_dest_array;
   float32_t          * v_dest_array_pn;
   uint32_t           * v_dest_array_count;


   /* Initialization */
   v_dest_array       = (float32_t *)NULL;
   v_dest_array_pn    = (float32_t *)NULL;
   v_dest_array_count = (uint32_t *)NULL;

   /*====================*/
   /* Store measurements */
   if (TRUE == p_channel_is_a)
   {
      switch (p_sensor_id)
      {
         case e_nfreq_2:
            shmem.s_nfreq2_a.s_measure = p_sensor_info->s_measure_freq;

            v_dest_array       = shmem.s_nfreq2_a.s_t_measure;
            v_dest_array_count = &shmem.s_nfreq2_a.s_t_sample_count;
            break;

         case e_nfreq_3:
            shmem.s_nfreq3_a.s_measure = p_sensor_info->s_measure_freq;
            shmem.s_nfreq3_a.s_ratio   = p_sensor_info->s_measure_ratio;

            v_dest_array       = shmem.s_nfreq3_a.s_t_measure;
            v_dest_array_pn    = shmem.s_nfreq3_a.s_tpn_measure;
            v_dest_array_count = &shmem.s_nfreq3_a.s_t_sample_count;
            break;

         case e_nfreq_4:
            shmem.s_nfreq4.s_measure = p_sensor_info->s_measure_freq;

            v_dest_array       = shmem.s_nfreq4.s_t_measure;
            v_dest_array_count = &shmem.s_nfreq4.s_t_sample_count;
            break;

         case e_ngalt:
            shmem.s_ngalt_a.s_measure = p_sensor_info->s_measure_freq;

            v_dest_array       = shmem.s_ngalt_a.s_t_measure;
            v_dest_array_count = &shmem.s_ngalt_a.s_t_sample_count;
            break;

         default:
            /* Avoid warning */
            break;
      }
   }
   else
   {
      switch (p_sensor_id)
      {
         case e_nfreq_2:
            shmem.s_nfreq2_b.s_measure = p_sensor_info->s_measure_freq;

            v_dest_array       = shmem.s_nfreq2_b.s_t_measure;
            v_dest_array_count = &shmem.s_nfreq2_b.s_t_sample_count;
            break;

         case e_nfreq_3:
            shmem.s_nfreq3_b.s_measure = p_sensor_info->s_measure_freq;
            shmem.s_nfreq3_b.s_ratio   = p_sensor_info->s_measure_ratio;

            v_dest_array       = shmem.s_nfreq3_b.s_t_measure;
            v_dest_array_pn    = shmem.s_nfreq3_b.s_tpn_measure;
            v_dest_array_count = &shmem.s_nfreq3_b.s_t_sample_count;
            break;

         case e_nfreq_4:
            shmem.s_nfreq4.s_measure = p_sensor_info->s_measure_freq;

            v_dest_array       = shmem.s_nfreq4.s_t_measure;
            v_dest_array_count = &shmem.s_nfreq4.s_t_sample_count;
            break;

         case e_ngalt:
            shmem.s_ngalt_b.s_measure = p_sensor_info->s_measure_freq;

            v_dest_array       = shmem.s_ngalt_b.s_t_measure;
            v_dest_array_count = &shmem.s_ngalt_b.s_t_sample_count;
            break;

         default:
            /* Avoid warning */
            break;
      }
   }

   /*==========================*/
   /* Store latest RTC samples */
    nfreq_shmem_write_sample(p_sensor_info,
                             p_sensor_id,
                             v_dest_array,
                             v_dest_array_pn,
                             v_dest_array_count);
}

/* ---------- internal operations: ------------------------------------------ */
