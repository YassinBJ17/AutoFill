/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/calres/calres_public.h"
#include "middleware/calres/calres_private.h"
#include "conf/oss_conf_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
#define CALRES_IS_ENABLED ((uint32_t) 0ul)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/** Whether the calres sensor (or the XR sensors)
 * are in use, according to the OSS_CONF table. */
boolean_t is_calres_sensor_enabled;

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CALRES-0010 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/**
 *  Function to initialize CALRES functionalities, unless the OSS_CONF table
 *    activated the XR capabilities.
 */
void calres_init(const boolean_t channel_is_a)
{
   ts_oss_conf_table *p_oss_conf = (ts_oss_conf_table *) OSS_CONF_START_ADDR;
   /* Initialize CALRES functionality, according to the value in OSS_CONF */
   is_calres_sensor_enabled = ( CALRES_IS_ENABLED == p_oss_conf->s_xrb_calres_select);

   /* Reset the values in the shared memory */

   shmem.s_calres_1_2.s_fault_word.u_word =   0u;
   shmem.s_calres_1_2.s_calres_measure1   = 0.0f;
   shmem.s_calres_1_2.s_calres_measure2   = 0.0f;

   shmem.s_calres_3_4.s_fault_word.u_word =   0u;
   shmem.s_calres_3_4.s_calres_measure1   = 0.0f;
   shmem.s_calres_3_4.s_calres_measure2   = 0.0f;

   /* Initialization of GPIO pointers and values */
   calres_gpio_init(is_calres_sensor_enabled, channel_is_a);

   if (is_calres_sensor_enabled)
   {
      /* Identify each register where to write the measures */
      calres_identify_registers_to_write(channel_is_a);
   }
}

/* ---------- internal operations: ------------------------------------------ */
