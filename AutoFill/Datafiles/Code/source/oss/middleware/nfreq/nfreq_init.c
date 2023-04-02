/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Initialization of information structure and FPGA interface
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "conf/oss_conf_public.h"
#include "middleware/nfreq/nfreq_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/memory_address_public.h"
#include "middleware/nfreq/nfreq_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Array holding parameters of all known sensors  */
ts_nfreq_sensor_info v_nfreq_sensors[e_SensorMax];

/* ---------- provided operation bodies: ------------------------------------ */
/* Initialization of information structure and FPGA interface */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0020 */
void nfreq_init(void)
{
   ts_nfreq_registers * v_nfreq_registers;
   ts_oss_conf_table * pv_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;


   /*=============================*/
   /* Information structure setup */
   /*=============================*/
   LIB_MEM_SET((void *)v_nfreq_sensors,
               (int8_t)0,
               (uint32_t)sizeof (v_nfreq_sensors));
   /* Setup NFREQ_2 */
   v_nfreq_sensors[e_nfreq_2].s_fpga_register = FPGA_MEMORY_ADDR + C_FPGA_IIP10_0_OFFSET;
   v_nfreq_sensors[e_nfreq_2].s_fpga_data     = v_nfreq_sensors[e_nfreq_2].s_fpga_register + C_NFREQ_RX_BUFF_OFFSET;
   v_nfreq_sensors[e_nfreq_2].s_gpio_input    = C_NFREQ2_MON;
   v_nfreq_sensors[e_nfreq_2].s_width         = C_1_SAMPLES_PER_PERIOD;
   v_nfreq_sensors[e_nfreq_2].s_n_max         = pv_oss_conf->s_nfreq2_nmax;
   v_nfreq_sensors[e_nfreq_2].s_n_min         = pv_oss_conf->s_nfreq2_nmin;
   v_nfreq_sensors[e_nfreq_2].s_n_rev         = pv_oss_conf->s_nfreq2_nrev;
   v_nfreq_sensors[e_nfreq_2].s_timeout       = pv_oss_conf->s_nfreq2_timeout;
   v_nfreq_sensors[e_nfreq_2].s_freq_min      = pv_oss_conf->s_nfreq2_th_frequency;
   v_nfreq_sensors[e_nfreq_2].s_freq_max      = C_MAX_FREQ_NFREQ2;
   v_nfreq_sensors[e_nfreq_2].s_max_shmem     = NFREQ2_MAX_MEAS_NB;

   v_nfreq_registers = (ts_nfreq_registers *)v_nfreq_sensors[e_nfreq_2].s_fpga_register;
   v_nfreq_registers->s_conf_register.s_inc_1_th_sel = pv_oss_conf->s_nfreq2_inc_1_th_sel;

   /* Setup NFREQ_3 */
   v_nfreq_sensors[e_nfreq_3].s_fpga_register = FPGA_MEMORY_ADDR + C_FPGA_IIP10_1_OFFSET;
   v_nfreq_sensors[e_nfreq_3].s_fpga_data     = v_nfreq_sensors[e_nfreq_3].s_fpga_register + C_NFREQ_RX_BUFF_OFFSET;
   v_nfreq_sensors[e_nfreq_3].s_gpio_input    = C_NFREQ3_MON;
   v_nfreq_sensors[e_nfreq_3].s_width         = C_2_SAMPLES_PER_PERIOD;
   v_nfreq_sensors[e_nfreq_3].s_n_max         = NFREQ3_MAX_MEAS_NB + (uint32_t)1;   /* force to nrev processing */
   v_nfreq_sensors[e_nfreq_3].s_n_min         = pv_oss_conf->s_nfreq3_nrev;
   v_nfreq_sensors[e_nfreq_3].s_n_rev         = pv_oss_conf->s_nfreq3_nrev;
   v_nfreq_sensors[e_nfreq_3].s_timeout       = pv_oss_conf->s_nfreq3_timeout;
   v_nfreq_sensors[e_nfreq_3].s_freq_min      = pv_oss_conf->s_nfreq3_th_frequency;
   v_nfreq_sensors[e_nfreq_3].s_freq_max      = C_MAX_FREQ_NFREQ3;
   v_nfreq_sensors[e_nfreq_3].s_max_shmem     = NFREQ3_MAX_MEAS_NB;

   v_nfreq_registers = (ts_nfreq_registers *)v_nfreq_sensors[e_nfreq_3].s_fpga_register;
   /* warning: inc_2_th_sel here */
   v_nfreq_registers->s_conf_register.s_inc_2_th_sel = pv_oss_conf->s_nfreq3_inc_2_th_sel;

   /* Setup NFREQ_4 */
   v_nfreq_sensors[e_nfreq_4].s_fpga_register = FPGA_MEMORY_ADDR + C_FPGA_IIP10_2_OFFSET;
   v_nfreq_sensors[e_nfreq_4].s_fpga_data     = v_nfreq_sensors[e_nfreq_4].s_fpga_register + C_NFREQ_RX_BUFF_OFFSET;
   v_nfreq_sensors[e_nfreq_4].s_gpio_input    = C_NFREQ4_MON;
   v_nfreq_sensors[e_nfreq_4].s_width         = C_1_SAMPLES_PER_PERIOD;
   v_nfreq_sensors[e_nfreq_4].s_n_max         = pv_oss_conf->s_nfreq4_nmax;
   v_nfreq_sensors[e_nfreq_4].s_n_min         = pv_oss_conf->s_nfreq4_nmin;
   v_nfreq_sensors[e_nfreq_4].s_n_rev         = pv_oss_conf->s_nfreq4_nrev;
   v_nfreq_sensors[e_nfreq_4].s_timeout       = pv_oss_conf->s_nfreq4_timeout;
   v_nfreq_sensors[e_nfreq_4].s_freq_min      = pv_oss_conf->s_nfreq4_th_frequency;
   v_nfreq_sensors[e_nfreq_4].s_freq_max      = C_MAX_FREQ_NFREQ4;
   v_nfreq_sensors[e_nfreq_4].s_max_shmem     = NFREQ4_MAX_MEAS_NB;

   v_nfreq_registers = (ts_nfreq_registers *)v_nfreq_sensors[e_nfreq_4].s_fpga_register;
   v_nfreq_registers->s_conf_register.s_inc_1_th_sel = pv_oss_conf->s_nfreq4_inc_1_th_sel;

   /* Setup NGALT */
   v_nfreq_sensors[e_ngalt].s_fpga_register = FPGA_MEMORY_ADDR + C_FPGA_IIP10_3_OFFSET;
   v_nfreq_sensors[e_ngalt].s_fpga_data     = v_nfreq_sensors[e_ngalt].s_fpga_register + C_NFREQ_RX_BUFF_OFFSET;
   v_nfreq_sensors[e_ngalt].s_gpio_input    = (uint32_t)0;
   v_nfreq_sensors[e_ngalt].s_width         = C_1_SAMPLES_PER_PERIOD;
   v_nfreq_sensors[e_ngalt].s_n_max         = pv_oss_conf->s_ngalt_nmax;
   v_nfreq_sensors[e_ngalt].s_n_min         = pv_oss_conf->s_ngalt_nmin;
   v_nfreq_sensors[e_ngalt].s_n_rev         = pv_oss_conf->s_ngalt_nrev;
   v_nfreq_sensors[e_ngalt].s_timeout       = pv_oss_conf->s_ngalt_timeout;
   v_nfreq_sensors[e_ngalt].s_freq_min      = pv_oss_conf->s_ngalt_th_frequency;
   v_nfreq_sensors[e_ngalt].s_freq_max      = C_MAX_FREQ_NGALT;
   v_nfreq_sensors[e_ngalt].s_max_shmem     = NGALT_MAX_MEAS_NB;

   v_nfreq_registers = (ts_nfreq_registers *)v_nfreq_sensors[e_ngalt].s_fpga_register;
   v_nfreq_registers->s_conf_register.s_inc_1_th_sel = pv_oss_conf->s_ngalt_inc_1_th_sel;

   /*=====================*/
   /* Shared memory setup */
   /*=====================*/
   /* Reset NFREQ_2 chA, chB */
   LIB_MEM_SET((void *)&shmem.s_nfreq2_a,
               (int8_t)0,
               (uint32_t)sizeof (ts_nfreq2));

   LIB_MEM_SET((void *)&shmem.s_nfreq2_b,
               (int8_t)0,
               (uint32_t)sizeof (ts_nfreq2));

   /* Reset NFREQ_3 chA, chB */
   LIB_MEM_SET((void *)&shmem.s_nfreq3_a,
               (int8_t)0,
               (uint32_t)sizeof (ts_nfreq3));

   LIB_MEM_SET((void *)&shmem.s_nfreq3_b,
               (int8_t)0,
               (uint32_t)sizeof (ts_nfreq3));

   /* Reset NFREQ_4 */
   LIB_MEM_SET((void *)&shmem.s_nfreq4,
               (int8_t)0,
               (uint32_t)sizeof (ts_nfreq4));

   /* Reset NGALT chA, chB */
   LIB_MEM_SET((void *)&shmem.s_ngalt_a,
               (int8_t)0,
               (uint32_t)sizeof (ts_ngalt));

   LIB_MEM_SET((void *)&shmem.s_ngalt_b,
               (int8_t)0,
               (uint32_t)sizeof (ts_ngalt));
}

/* ---------- internal operations: ------------------------------------------ */
