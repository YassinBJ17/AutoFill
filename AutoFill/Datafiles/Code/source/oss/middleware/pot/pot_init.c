/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/pot/pot_public.h"
#include "middleware/pot/pot_private.h"
#include "conf/oss_conf_public.h"
#include "memory/oss_section_def_public.h"
#include "memory/lib_critical_service_section_def_data.h"


/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/** Type of sensor for Pot_1, according to the OSS_CONF table. */
uint32_t pot_conf_pot1_sensor_type;
/** Type of sensor for Pot_2, according to the OSS_CONF table. */
uint32_t pot_conf_pot2_sensor_type;
/** Whether the local sensor is of type POTENTIOMETER or DIFFERENTIAL */
boolean_t is_sensor_type_diff;
/** Pointer to the appropriate (either Pot_1, Pot_2, Potdiff_1 or Potdiff_2)
 *    register in shared memory */
ts_pot* p_1_2_register;
/* Pointer to the Pot_3 register in shared memory */
ts_pot* p_3_register;

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/* Implements REQ_FADEX_OS_SRD-POT-0030 */
/**
 * Initialize pot_1 and pot_2 inputs
 *   (as either POT_K_POTENTIOMETER or POT_K_DIFFERENTIAL).
 *   The pot3 input is always considered as a Potentiometer and not as a Diff.
 * Then, initialize the values kept in shared memory.
 */
void pot_init(const boolean_t current_channel_is_a)
{
   ts_oss_conf_table *p_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;
   boolean_t current_channel_is_b = ! current_channel_is_a;

   /** Initialize pot_1 and pot_2 input types.
    *    (pot_3 sensor is always considered as a Potentiometer.)
    */
   pot_conf_pot1_sensor_type = p_oss_conf->s_pot1_sensor_type;
   pot_conf_pot2_sensor_type = p_oss_conf->s_pot2_sensor_type;

   /** Store the type of the local sensor for either Pot_1 or Pot_2,
    *    and according to the local channel. */
   is_sensor_type_diff = (POT_K_DIFFERENTIAL == pot_conf_pot1_sensor_type
                                                     &&   current_channel_is_a)
                    ||   (POT_K_DIFFERENTIAL == pot_conf_pot2_sensor_type
                                                     &&   current_channel_is_b);

   /* Identify which register to write for the Pot_1 or Pot_2 sensor */
   p_1_2_register = pot_identify_register_1_2_to_write(current_channel_is_a);
   /* Identify which register to write for the Pot_3 sensor */
   p_3_register   = pot_identify_register_3_to_write();

   /* Reset the values in the shared memory */
   shmem.s_pot1.s_fault_word.u_word     =   0 ;
   shmem.s_pot1.s_measure               = 0.0f;
   shmem.s_pot2.s_fault_word.u_word     =   0 ;
   shmem.s_pot2.s_measure               = 0.0f;
   shmem.s_pot3.s_fault_word.u_word     =   0 ;
   shmem.s_pot3.s_measure               = 0.0f;
   shmem.s_potdiff1.s_fault_word.u_word =   0 ;
   shmem.s_potdiff1.s_measure           = 0.0f;
   shmem.s_potdiff2.s_fault_word.u_word =   0 ;
   shmem.s_potdiff2.s_measure           = 0.0f;
}

/* ---------- internal operations: ------------------------------------------ */
