/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Initialization of structure array holding sensors parameters
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "conf/oss_conf_public.h"
#include "middleware/sg/sg_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/sg/sg_private.h"

/* ---------- internal define constants: ------------------------------------ */
/* Sensors indexes */
#define C_SENSOR_0   ((uint8_t)0)
#define C_SENSOR_1   ((uint8_t)1)
#define C_SENSOR_2   ((uint8_t)2)
#define C_SENSOR_3   ((uint8_t)3)
#define C_SENSOR_4   ((uint8_t)4)
#define C_SENSOR_5   ((uint8_t)5)
#define C_SENSOR_6   ((uint8_t)6)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Array holding parameters of all known sensors  */
ts_sg_sensor_info v_sg_sensors[C_SENSOR_COUNT];

/* ---------- provided operation bodies: ------------------------------------ */
/* Initialization of structure array holding sensors parameters */
void sg_init(const boolean_t channel_is_a)
{
   boolean_t          v_is_channel_a;
   boolean_t          v_is_channel_b;
   uint8_t           *v_sg_sai_select;
   ts_oss_conf_table *pv_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;


   LIB_MEM_SET((int8_t *)v_sg_sensors,
              (int8_t)0,
              (uint32_t)sizeof (v_sg_sensors));

   /* Set channel specific information */
   if (TRUE == channel_is_a)
   {
      /* Set channel information */
      v_is_channel_a = TRUE;
      v_is_channel_b = FALSE;

      /* Set SLECT_SAI*_N signals */
      if (C_IS_SG == pv_oss_conf->s_sai1_select)
      {
         /* Get access to SELECT_SAI_* GPIOs */
         v_sg_sai_select = C_SELECT_SAI1_3_N;

         /* Set GPIO */
         *v_sg_sai_select = C_SET_SG;
      }

      if (C_IS_SG == pv_oss_conf->s_sai2_select)
      {
         /* Get access to SELECT_SAI_* GPIOs */
         v_sg_sai_select = C_SELECT_SAI2_4_N;

         /* Set GPIO */
         *v_sg_sai_select = C_SET_SG;
      }
   }
   else
   {
      /* Set channel information */
      v_is_channel_a = FALSE;
      v_is_channel_b = TRUE;

      /* Set SLECT_SAI*_N signals */
      if (C_IS_SG == pv_oss_conf->s_sai3_select)
      {
         /* Get access to SELECT_SAI_* GPIOs */
         v_sg_sai_select = C_SELECT_SAI1_3_N;

         /* Set GPIO */
         *v_sg_sai_select = C_SET_SG;
      }

      if (C_IS_SG == pv_oss_conf->s_sai4_select)
      {
         /* Get access to SELECT_SAI_* GPIOs */
         v_sg_sai_select = C_SELECT_SAI2_4_N;

         /* Set GPIO */
         *v_sg_sai_select = C_SET_SG;
      }
   }

   /*=============================*/
   /* Information structure setup */
   /*=============================*/
   /* Setup P3a */
   v_sg_sensors[C_SENSOR_0].s_input_id         = e_p3a;
   v_sg_sensors[C_SENSOR_0].s_is_other_channel = v_is_channel_b;
   v_sg_sensors[C_SENSOR_0].s_read_start       = C_READ_OFFSET;
   v_sg_sensors[C_SENSOR_0].s_read_count       = C_READ_COUNT;
   v_sg_sensors[C_SENSOR_0].s_mon_count        = C_MON_COUNT;
   v_sg_sensors[C_SENSOR_0].s_sig_gain         = C_P3_SIG_GAIN;
   v_sg_sensors[C_SENSOR_0].s_sig_offset       = C_P3_SIG_OFFSET;

   /* Setup P3b */
   v_sg_sensors[C_SENSOR_1].s_input_id         = e_p3b;
   v_sg_sensors[C_SENSOR_1].s_is_other_channel = v_is_channel_a;
   v_sg_sensors[C_SENSOR_1].s_read_start       = C_READ_OFFSET;
   v_sg_sensors[C_SENSOR_1].s_read_count       = C_READ_COUNT;
   v_sg_sensors[C_SENSOR_1].s_mon_count        = C_MON_COUNT;
   v_sg_sensors[C_SENSOR_1].s_sig_gain         = C_P3_SIG_GAIN;
   v_sg_sensors[C_SENSOR_1].s_sig_offset       = C_P3_SIG_OFFSET;

   /* Setup SG1/SAI1 */
   if (C_IS_SG == pv_oss_conf->s_sai1_select)
   {
      v_sg_sensors[C_SENSOR_2].s_input_id      = e_sg1;
      v_sg_sensors[C_SENSOR_2].s_sig_gain      = C_SG1_SIG_GAIN;
      v_sg_sensors[C_SENSOR_2].s_sig_offset    = C_SG1_SIG_OFFSET;
   }
   else
   {
      v_sg_sensors[C_SENSOR_2].s_input_id      = e_sai1;
      v_sg_sensors[C_SENSOR_2].s_sig_gain      = C_SAI_SIG_GAIN;
      v_sg_sensors[C_SENSOR_2].s_sig_offset    = C_SAI_SIG_OFFSET;
   }
   v_sg_sensors[C_SENSOR_2].s_is_other_channel = v_is_channel_b;
   v_sg_sensors[C_SENSOR_2].s_read_start       = C_READ_OFFSET;
   v_sg_sensors[C_SENSOR_2].s_read_count       = C_READ_COUNT;
   v_sg_sensors[C_SENSOR_2].s_mon_count        = C_MON_COUNT;

   /* Setup SG2/SAI2 */
   if (C_IS_SG == pv_oss_conf->s_sai2_select)
   {
      v_sg_sensors[C_SENSOR_3].s_input_id      = e_sg2;
      v_sg_sensors[C_SENSOR_3].s_sig_gain      = C_SG2_SIG_GAIN;
      v_sg_sensors[C_SENSOR_3].s_sig_offset    = C_SG2_SIG_OFFSET;
   }
   else
   {
      v_sg_sensors[C_SENSOR_3].s_input_id      = e_sai2;
      v_sg_sensors[C_SENSOR_3].s_sig_gain      = C_SAI_SIG_GAIN;
      v_sg_sensors[C_SENSOR_3].s_sig_offset    = C_SAI_SIG_OFFSET;
   }
   v_sg_sensors[C_SENSOR_3].s_is_other_channel = v_is_channel_b;
   v_sg_sensors[C_SENSOR_3].s_read_start       = C_READ_OFFSET;
   v_sg_sensors[C_SENSOR_3].s_read_count       = C_READ_COUNT;
   v_sg_sensors[C_SENSOR_3].s_mon_count        = C_MON_COUNT;

   /* Setup SG3/SAI3 */
   if (C_IS_SG == pv_oss_conf->s_sai3_select)
   {
      v_sg_sensors[C_SENSOR_4].s_input_id     = e_sg3;
      v_sg_sensors[C_SENSOR_4].s_sig_gain     = C_SG3_SIG_GAIN;
      v_sg_sensors[C_SENSOR_4].s_sig_offset   = C_SG3_SIG_OFFSET;
   }
   else
   {
      v_sg_sensors[C_SENSOR_4].s_input_id      = e_sai3;
      v_sg_sensors[C_SENSOR_4].s_sig_gain      = C_SAI_SIG_GAIN;
      v_sg_sensors[C_SENSOR_4].s_sig_offset    = C_SAI_SIG_OFFSET;
   }
   v_sg_sensors[C_SENSOR_4].s_is_other_channel = v_is_channel_a;
   v_sg_sensors[C_SENSOR_4].s_read_start       = C_READ_OFFSET;
   v_sg_sensors[C_SENSOR_4].s_read_count       = C_READ_COUNT;
   v_sg_sensors[C_SENSOR_4].s_mon_count        = C_MON_COUNT;

   /* Setup SG4 */
   v_sg_sensors[C_SENSOR_5].s_input_id         = e_sg4;
   v_sg_sensors[C_SENSOR_5].s_is_other_channel = v_is_channel_a;
   v_sg_sensors[C_SENSOR_5].s_read_start       = C_READ_OFFSET;
   v_sg_sensors[C_SENSOR_5].s_read_count       = C_READ_COUNT;
   v_sg_sensors[C_SENSOR_5].s_mon_count        = C_MON_COUNT;
   v_sg_sensors[C_SENSOR_5].s_sig_gain         = C_SG4_SIG_GAIN;
   v_sg_sensors[C_SENSOR_5].s_sig_offset       = C_SG4_SIG_OFFSET;

   /* Setup SG5b/SAI4 */
   if (C_IS_SG == pv_oss_conf->s_sai4_select)
   {
      v_sg_sensors[C_SENSOR_6].s_input_id      = e_sg5b;
      v_sg_sensors[C_SENSOR_6].s_sig_gain      = C_SG5_SIG_GAIN;
      v_sg_sensors[C_SENSOR_6].s_sig_offset    = C_SG5_SIG_OFFSET;
   }
   else
   {
      v_sg_sensors[C_SENSOR_6].s_input_id      = e_sai4;
      v_sg_sensors[C_SENSOR_6].s_sig_gain      = C_SAI_SIG_GAIN;
      v_sg_sensors[C_SENSOR_6].s_sig_offset    = C_SAI_SIG_OFFSET;
   }
   v_sg_sensors[C_SENSOR_6].s_is_other_channel = v_is_channel_a;
   v_sg_sensors[C_SENSOR_6].s_read_start       = C_READ_OFFSET;
   v_sg_sensors[C_SENSOR_6].s_read_count       = C_READ_COUNT;
   v_sg_sensors[C_SENSOR_6].s_mon_count        = C_MON_COUNT;

   /*=====================*/
   /* Shared memory setup */
   /*=====================*/
   /* Reset P3 chA, chB */
   LIB_MEM_SET((void *)&shmem.s_p3_a,
               (int8_t)0,
               (uint32_t)sizeof (ts_sg));

   LIB_MEM_SET((void *)&shmem.s_p3_b,
               (int8_t)0,
               (uint32_t)sizeof (ts_sg));

   /* Reset SG1/SAI1 chA */
   LIB_MEM_SET((void *)&shmem.s_sg1_a,
               (int8_t)0,
               (uint32_t)sizeof (ts_sg));

   /* Reset SG2/SAI2 chA */
   LIB_MEM_SET((void *)&shmem.s_sg2_a,
               (int8_t)0,
               (uint32_t)sizeof (ts_sg));

   /* Reset SG3/SAI3 chB */
   LIB_MEM_SET((void *)&shmem.s_sg3_b,
               (int8_t)0,
               (uint32_t)sizeof (ts_sg));

   /* Reset SG4 chA, chB */
   LIB_MEM_SET((void *)&shmem.s_sg4_b,
               (int8_t)0,
               (uint32_t)sizeof (ts_sg));

   /* Reset SG5/SAI4 chB */
   LIB_MEM_SET((void *)&shmem.s_sg5_b,
               (int8_t)0,
               (uint32_t)sizeof (ts_sg));
}

/* ---------- internal operations: ------------------------------------------ */
