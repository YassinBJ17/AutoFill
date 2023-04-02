/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/nfreq/nfreq_private.h"
#include "middleware/nfreq/nfreq_shmem_write_sample.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/*  */
void nfreq_shmem_write_sample(ts_nfreq_sensor_info * p_sensor_info,
                              te_nfreq_sensor        p_sensor_id,
                              float32_t            * p_dest,
                              float32_t            * p_dest_pn,
                              uint32_t             * p_dest_count)
{
   ts_nfreq_registers * pv_register;
   ts_nfreq_data      * pv_rx_data;
   uint32_t             v_sample_index;
   uint32_t             v_sample_start;
   uint32_t             v_offset;


   pv_register = (ts_nfreq_registers *)p_sensor_info->s_fpga_register;
   pv_rx_data  = (ts_nfreq_data *)p_sensor_info->s_fpga_data;

   v_sample_start = pv_register->s_status_register.s_sample_number_last;

   if (e_nfreq_3 == p_sensor_id)
   {
      if (v_sample_start >= (p_sensor_info->s_max_shmem * (uint32_t)2))
         *p_dest_count = p_sensor_info->s_max_shmem * (uint32_t)2;
      else
         *p_dest_count = v_sample_start;

      v_sample_start -= *p_dest_count;

      if ((*p_dest_count % (uint32_t)2) > (uint32_t)0)
      {
         p_dest[(uint32_t)0] = (float32_t)pv_rx_data[v_sample_start].s_period * C_PERIOD_TICK_TO_MS;

         for (v_sample_index = (uint32_t)1; v_sample_index <= (*p_dest_count / (uint32_t)2); v_sample_index++)
         {
            v_offset = v_sample_start + (v_sample_index * (uint32_t)2);
            p_dest[v_sample_index]  = (float32_t)pv_rx_data[v_offset].s_period * C_PERIOD_TICK_TO_MS;

            v_offset = v_sample_start + (v_sample_index * (uint32_t)2) - (uint32_t)1;
            p_dest_pn[v_sample_index] = (float32_t)pv_rx_data[v_offset].s_period * C_PERIOD_TICK_TO_MS;
         }
      }
      else
      {
         for (v_sample_index = (uint32_t)0; v_sample_index < (*p_dest_count / (uint32_t)2); v_sample_index++)
         {
            v_offset = v_sample_start + (v_sample_index * (uint32_t)2) + (uint32_t)1;
            p_dest[v_sample_index]    = (float32_t)pv_rx_data[v_offset].s_period * C_PERIOD_TICK_TO_MS;

            v_offset = v_sample_start + (v_sample_index * (uint32_t)2);
            p_dest_pn[v_sample_index] = (float32_t)pv_rx_data[v_offset].s_period * C_PERIOD_TICK_TO_MS;
         }
      }
   }
   else if (p_dest != (float32_t *)NULL)
   {
      if (v_sample_start >= p_sensor_info->s_max_shmem)
         *p_dest_count = p_sensor_info->s_max_shmem;
      else
         *p_dest_count = v_sample_start;

      v_sample_start -= *p_dest_count;

      for (v_sample_index = (uint32_t)0; v_sample_index < *p_dest_count; v_sample_index++)
      {
         v_offset = v_sample_start + v_sample_index;
         p_dest[v_sample_index] = (float32_t)pv_rx_data[v_offset].s_period * C_PERIOD_TICK_TO_MS;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
