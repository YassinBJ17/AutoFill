/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : lvdt_periodic function which allows lvdt acquisition
 *               and transmission to CSS at each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/lvdt/lvdt_public.h"
#include "middleware/lvdt/lvdt_private.h"
#include "memory/shared_memory_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Variables for demodulation result */
float32_t lvdt_exc_a;
float32_t lvdt_exc_b;
float32_t lvdt_exc_c;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* Variables for voltages acquisition in V */
static float32_t voltage_lvdt_dc_raw_s1_a;
static float32_t voltage_lvdt_dc_raw_s2_a;
static float32_t voltage_lvdt_dc_raw_s1_b;
static float32_t voltage_lvdt_dc_raw_s2_b;
static float32_t voltage_lvdt_dc_raw_s1_c;
static float32_t voltage_lvdt_dc_raw_s2_c;

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-lvdt-xxxx */
void lvdt_periodic(const boolean_t channel_is_a)
{
   /* Share memory region pointer */
   ts_lvdt * shmem_local_ts_lvdt;

   /* Choose correct shmem variables */
   if(TRUE == channel_is_a)
   {
      shmem_local_ts_lvdt = &(shmem.s_lvdta);

     /* Compute values for LVDTA */
      lvdt_compute_values(TRUE,&lvdt_exc_a);
      lvdt_exc_b = 0;
   }
   else
   {
      shmem_local_ts_lvdt = &(shmem.s_lvdtb);

     /* Compute values for LVDTB */
     lvdt_compute_values(TRUE,&lvdt_exc_b);
      lvdt_exc_a = 0;
   }

   /* Compute fault word for LVDTA or LVDTB*/
   if(TRUE == channel_is_a)
   {
     lvdt_compute_fault_word(TRUE , &voltage_lvdt_dc_raw_s1_a , &voltage_lvdt_dc_raw_s2_a , lvdt_exc_a , lvdt_fault_word_thresholds_lvdtx[LVDT_SENSOR_ID_A]);
      voltage_lvdt_dc_raw_s1_b = 0;
      voltage_lvdt_dc_raw_s2_b = 0;
   }
   else
   {
      lvdt_compute_fault_word(TRUE , &voltage_lvdt_dc_raw_s1_b , &voltage_lvdt_dc_raw_s2_b , lvdt_exc_b , lvdt_fault_word_thresholds_lvdtx[LVDT_SENSOR_ID_B]);
      voltage_lvdt_dc_raw_s1_a = 0;
      voltage_lvdt_dc_raw_s2_a = 0;
   }

   /* Update shared mem */
   shmem_local_ts_lvdt->s_vs1_measure = lvdt_vs1_measure;
   shmem_local_ts_lvdt->s_vs2_measure = lvdt_vs2_measure;
   shmem_local_ts_lvdt->s_measure     = lvdt_ratio_measure;
   shmem_local_ts_lvdt->s_fault_word  = lvdt_fault_word;

   if(channel_is_a)
   {
      /* Compute values for LVDTC */
      lvdt_compute_values(FALSE,&lvdt_exc_c);

      /* Compute fault word for LVDTC */
      lvdt_compute_fault_word(FALSE , &voltage_lvdt_dc_raw_s1_c , &voltage_lvdt_dc_raw_s2_c , lvdt_exc_c , lvdt_fault_word_thresholds_lvdtx[LVDT_SENSOR_ID_C]);

      shmem.s_lvdtc.s_vs1_measure = lvdt_vs1_measure;
      shmem.s_lvdtc.s_vs2_measure = lvdt_vs2_measure;;
      shmem.s_lvdtc.s_measure     = lvdt_ratio_measure;;
      shmem.s_lvdtc.s_fault_word  = lvdt_fault_word;
   }
   else
   {
      shmem.s_lvdtc.s_vs1_measure       = 0;
      shmem.s_lvdtc.s_vs2_measure       = 0;
      shmem.s_lvdtc.s_measure           = 0;
      shmem.s_lvdtc.s_fault_word.u_word = (uint32_t) 0;
      voltage_lvdt_dc_raw_s1_c          = 0;
      voltage_lvdt_dc_raw_s2_c          = 0;
     lvdt_exc_c                        = 0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
