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
#include "middleware/nfreq/nfreq_shmem_write_status.h"

/* ---------- internal define constants: ------------------------------------ */
#define C_NFREQ24_STATUS_MASK ((uint32_t)0xA0000F83)
#define C_NFREQ3_STATUS_MASK  ((uint32_t)0xB1000F83)
#define C_NGALT_STATUS_MASK   ((uint32_t)0xC0000F83)

#define C_MASK_INVALD_STATUS_OR_NFREQ  ((uint32_t)0xA0000C80)
#define C_MASK_INVALD_STATUS_OR_NGALT  ((uint32_t)0xC0000C80)
#define C_MASK_INVALD_STATUS_AND       ((uint32_t)0x00000202)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Copy designated nFreq information to shared memory */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0010 */
void nfreq_shmem_write_status(const boolean_t        p_channel_is_a,
                              te_nfreq_sensor        p_sensor_id,
                              ts_nfreq_sensor_info * p_sensor_info)
{
   boolean_t   v_flag;


   /* Check general invalid status */
   if (e_nfreq_3 == p_sensor_id)
   {
      p_sensor_info->s_status_word.u_bit.s_out_of_range =  p_sensor_info->s_status_word.u_bit.s_out_of_range_freq
                                                         | p_sensor_info->s_status_word.u_bit.s_out_of_range_duty;
   }

   if (e_ngalt == p_sensor_id)
   {
      v_flag = ((p_sensor_info->s_status_word.u_word & C_MASK_INVALD_STATUS_OR_NGALT) != (uint32_t)0);
   }
   else
   {
      v_flag = ((p_sensor_info->s_status_word.u_word & C_MASK_INVALD_STATUS_OR_NFREQ) != (uint32_t)0);
   }

   v_flag |= ((p_sensor_info->s_status_word.u_word & C_MASK_INVALD_STATUS_AND) == C_MASK_INVALD_STATUS_AND);
   p_sensor_info->s_status_word.u_bit.s_invalid = (uint32_t)v_flag;

   /* Store measurements */
   if (TRUE == p_channel_is_a)
   {
      switch (p_sensor_id)
      {
         case e_nfreq_2:
            shmem.s_nfreq2_a.s_fault_word.u_word = C_NFREQ24_STATUS_MASK & p_sensor_info->s_status_word.u_word;
            break;

         case e_nfreq_3:
            shmem.s_nfreq3_a.s_fault_word.u_word = C_NFREQ3_STATUS_MASK & p_sensor_info->s_status_word.u_word;
            break;

         case e_nfreq_4:
            shmem.s_nfreq4.s_fault_word.u_word = C_NFREQ24_STATUS_MASK & p_sensor_info->s_status_word.u_word;
            break;

         case e_ngalt:
            shmem.s_ngalt_a.s_fault_word.u_word = C_NGALT_STATUS_MASK & p_sensor_info->s_status_word.u_word;
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
            shmem.s_nfreq2_b.s_fault_word.u_word = C_NFREQ24_STATUS_MASK & p_sensor_info->s_status_word.u_word;
            break;

         case e_nfreq_3:
            shmem.s_nfreq3_b.s_fault_word.u_word = C_NFREQ3_STATUS_MASK & p_sensor_info->s_status_word.u_word;
            break;

         case e_nfreq_4:
            shmem.s_nfreq4.s_fault_word.u_word = C_NFREQ24_STATUS_MASK & p_sensor_info->s_status_word.u_word;
            break;

         case e_ngalt:
            shmem.s_ngalt_b.s_fault_word.u_word = C_NGALT_STATUS_MASK & p_sensor_info->s_status_word.u_word;
            break;

         default:
            /* Avoid warning */
            break;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
