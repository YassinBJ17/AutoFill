/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Tables description for SVOI, EMAN and DIN01 to DIN16 at INIT
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/discrete/discrete_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Discrete GPIO configuration table for INIT */
const ts_discrete_conf DISCRETE_CONF_tab[e_discrete_nb] =
{
   /* Section for EMAN */
   {
      e_eman,
      GPDI_153_EMAN,
      &shmem.s_eman.s_raw_measure,
      &shmem.s_eman.s_filt_measure,
      OSS_CONF_EMAN_N_FILTER
   }
   ,
   /* Section for din_01_n */
   {
      e_din_01_n,
      GPDI_106_DIN1,
      &shmem.s_din.s_raw_measure[0],
      &shmem.s_din.s_filt_measure[0],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_02_n */
   {
      e_din_02_n,
      GPDI_107_DIN2,
      &shmem.s_din.s_raw_measure[1],
      &shmem.s_din.s_filt_measure[1],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_03_n */
   {
      e_din_03_n,
      GPDI_108_DIN3,
      &shmem.s_din.s_raw_measure[2],
      &shmem.s_din.s_filt_measure[2],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_04_n */
   {
      e_din_04_n,
      GPDI_114_DIN4,
      &shmem.s_din.s_raw_measure[3],
      &shmem.s_din.s_filt_measure[3],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_05_n */
   {
      e_din_05_n,
      GPDI_115_DIN5,
      &shmem.s_din.s_raw_measure[4],
      &shmem.s_din.s_filt_measure[4],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_06_n */
   {
      e_din_06_n,
      GPDI_116_DIN6,
      &shmem.s_din.s_raw_measure[5],
      &shmem.s_din.s_filt_measure[5],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_07_n */
   {
      e_din_07_n,
      GPDI_128_DIN7,
      &shmem.s_din.s_raw_measure[6],
      &shmem.s_din.s_filt_measure[6],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_08_n */
   {
      e_din_08_n,
      GPDI_129_DIN8,
      &shmem.s_din.s_raw_measure[7],
      &shmem.s_din.s_filt_measure[7],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_09_n */
   {
      e_din_09_n,
      GPDI_138_DIN9,
      &shmem.s_din.s_raw_measure[8],
      &shmem.s_din.s_filt_measure[8],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_10_n */
   {
      e_din_10_n,
      GPDI_139_DIN10,
      &shmem.s_din.s_raw_measure[9],
      &shmem.s_din.s_filt_measure[9],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_11_n */
   {
      e_din_11_n,
      GPDI_140_DIN11,
      &shmem.s_din.s_raw_measure[10],
      &shmem.s_din.s_filt_measure[10],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_12_n */
   {
      e_din_12_n,
      GPDI_141_DIN12,
      &shmem.s_din.s_raw_measure[11],
      &shmem.s_din.s_filt_measure[11],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_13_n */
   {
      e_din_13_n,
      GPDI_132_DIN13,
      &shmem.s_din.s_raw_measure[12],
      &shmem.s_din.s_filt_measure[12],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_14_n */
   {
      e_din_14_n,
      GPDI_133_DIN14,
      &shmem.s_din.s_raw_measure[13],
      &shmem.s_din.s_filt_measure[13],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_15_n */
   {
      e_din_15_n,
      GPDI_134_DIN15,
      &shmem.s_din.s_raw_measure[14],
      &shmem.s_din.s_filt_measure[14],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for din_16_n */
   {
      e_din_16_n,
      GPDI_135_DIN16,
      &shmem.s_din.s_raw_measure[15],
      &shmem.s_din.s_filt_measure[15],
      OSS_CONF_DIN_N_FILTER
   }
   ,
   /* Section for SVOI */
   {
      e_svoi,
      GPDI_160_SVOI,
      &shmem.s_svoi.s_raw_measure,
      &shmem.s_svoi.s_filt_measure,
      OSS_CONF_SVOI_N_FILTER
   }
   ,
   /* Section for MDIN */
   {
      e_mdin,
      FPGA_GPIO_IN,
      &shmem.s_mdin_measure,
      NULL,
      NULL /* FADEX-PDS-00622 pour MDIN */
   }
};

/* ---------- provided operation bodies: ------------------------------------ */
/* Discrete descriptor table */
tu_discrete_counter DISCRETE_COUNTER_tab[e_discrete_nb];

/* ---------- internal operations: ------------------------------------------ */

