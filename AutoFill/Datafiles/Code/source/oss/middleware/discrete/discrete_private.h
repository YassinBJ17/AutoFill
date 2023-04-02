/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DISCRETE_PRIVATE_H
#define DISCRETE_PRIVATE_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"



/* ---------- provided define constants: ------------------------------------ */
/* Generic data value */
#define INIT_VALUE_32                     (uint32_t)0
#define INIT_VALUE_16                     (uint16_t)0

/* OSS_CONF access address */
#define OSS_CONF_EMAN_N_FILTER            (reg32_t*)(0x20004114)
#define OSS_CONF_SVOI_N_FILTER            (reg32_t*)(0x20004110)
#define OSS_CONF_DIN_N_FILTER             (reg32_t*)(0x2000410C)

/* Extracted from BSIS 5.2.1. Memory map by memory_address_public */
/* Built with bridge_pld_memory_map GPIO space memory */
#define FPGA_GPIO_IN                      (reg8_t*)0x24004003

/*--- GPIO address for each discrete signal ---*/
/* Addresses extracted from Table 5-2. Peripheral (PBRIDGE_A, PBRIDGE_B) memory map */
/* GPIO DIN1 to DIN16 with system Integration Unit List 2 (SIUL2) + GPDI addresses for read only */
#define GPDI_106_DIN1                     (reg8_t*)0xFFFC156A
#define GPDI_107_DIN2                     (reg8_t*)0xFFFC156B
#define GPDI_108_DIN3                     (reg8_t*)0xFFFC156C
#define GPDI_114_DIN4                     (reg8_t*)0xFFFC1572
#define GPDI_115_DIN5                     (reg8_t*)0xFFFC1573
#define GPDI_116_DIN6                     (reg8_t*)0xFFFC1574
#define GPDI_128_DIN7                     (reg8_t*)0xFFFC1580
#define GPDI_129_DIN8                     (reg8_t*)0xFFFC1581
#define GPDI_138_DIN9                     (reg8_t*)0xFFFC158A
#define GPDI_139_DIN10                    (reg8_t*)0xFFFC158B
#define GPDI_140_DIN11                    (reg8_t*)0xFFFC158C
#define GPDI_141_DIN12                    (reg8_t*)0xFFFC158D
#define GPDI_132_DIN13                    (reg8_t*)0xFFFC1584
#define GPDI_133_DIN14                    (reg8_t*)0xFFFC1585
#define GPDI_134_DIN15                    (reg8_t*)0xFFFC1586
#define GPDI_135_DIN16                    (reg8_t*)0xFFFC1587

/* GPIO EMAN and SVOI with system Integration Unit List 2 (SIUL2) + GPDI addresses for read only */
#define GPDI_153_EMAN                     (reg8_t*)0xFFFC1599
#define GPDI_160_SVOI                     (reg8_t*)0xFFFC15A0

/* GPIO for MU DISCRETE with system Integration Unit List 2 (SIUL2) + GPDO addresses for write only */
#define GPDO_81_DIN_UOD                   (reg8_t*)0xFFFC1351
#define DIN_UOD_DISABLE                   (reg8_t)0
#define DIN_UOD_ENABLE                    (reg8_t)1

/* GPIO for MU DISCRETE with system Integration Unit List 2 (SIUL2) + GPDI addresses for read only */
#define GPDI_169_OVERTEMP                 (reg8_t*)0xFFFC15A9
#define GPDI_167_SECUR_ALERT              (reg8_t*)0xFFFC15A7
#define GPDI_168_SPARE_OUT                (reg8_t*)0xFFFC15A8
#define GPDI_170_STATUS                   (reg8_t*)0xFFFC15AA

/* GPIO external mode with system Integration Unit List 2 (SIUL2) + GPDI addresses for read only */
#define GPDI_109_DINSHOP                  (reg8_t*)0xFFFC156D
#define GPDI_110_DINOLL                   (reg8_t*)0xFFFC156E
#define GPDI_111_DINTMODE                 (reg8_t*)0xFFFC156F

/* GPIO response from PBIT configuration  with system Integration Unit List 2 (SIUL2) + GPDI addresses for read only */
#define GPDI_154_COMDIN_LEVEL             (reg8_t*)0xFFFC159A

/* GPIO PBIT configuration  with system Integration Unit List 2 (SIUL2) + GPDO addresses for write */
#define GPDO_228_EMAN_SVOI_OPEN           (reg8_t*)0xFFFC13E4
#define GPDO_229_COMDIN_OPEN              (reg8_t*)0xFFFC13E5
#define GPDO_230_EMAN_SVOI_CLOSED         (reg8_t*)0xFFFC13E6
#define GPDO_231_DIN1_16_CLOSED           (reg8_t*)0xFFFC13E7
#define DISCRETE_GPDO_DISABLE             (reg8_t)0
#define DISCRETE_GPDO_ENABLE              (reg8_t)1

/* GPIO stable or unstable value during filtering GPIO function */
#define DISCRETE_INIT_VALUE               (uint32_t)0
#define DISCRETE_GPIO_LOW                 (uint32_t)0
#define DISCRETE_GPIO_HIGH                (uint32_t)2
#define DISCRETE_UNSTABLE_GPIO_VALUE      (uint32_t)1
#define DISCRETE_DATA_NB                  (uint32_t)19
#define DISCRETE_FILTER_ACTIF             (uint32_t)1

#define DISCRETE_MASK_MDIN                (reg8_t)0x04
#define DISCRETE_BIT_SHIFT_MDIN           (reg8_t)2

/* ---------- provided types: ----------------------------------------------- */
/*--- GPIO PART ---*/
/*** DIN1..DIN16, EMAN and SVOI ***/
/* Enumeration of discrete GPIO */
typedef enum
{
   e_eman                  = 0ul,
   e_din_01_n              = 1ul,
   e_din_02_n              = 2ul,
   e_din_03_n              = 3ul,
   e_din_04_n              = 4ul,
   e_din_05_n              = 5ul,
   e_din_06_n              = 6ul,
   e_din_07_n              = 7ul,
   e_din_08_n              = 8ul,
   e_din_09_n              = 9ul,
   e_din_10_n              = 10ul,
   e_din_11_n              = 11ul,
   e_din_12_n              = 12ul,
   e_din_13_n              = 13ul,
   e_din_14_n              = 14ul,
   e_din_15_n              = 15ul,
   e_din_16_n              = 16ul,
   e_svoi                  = 17ul,
   e_mdin                  = 18ul,
   e_discrete_nb
}te_discrete_id;

/* Bit field structure for counter discrete signal */
/* During filter function, GPIO state will be upgraded in global counter structure before transmission function  */
/* GPIO counter description defined as followed                                                                  */
/* | XX | XX | XX | XX |
 *    ^    ^    ^    ^
 *    |    |    |    |---> {s_stable_counter}   in 8bits RTC counter when GPIO level is stable
 *    |    |    |--------> {c_max_counter}      in 8bits Constant value from OSS_CONF
 *    |    |-------------> {s_unstable_counter} in 8bits RTC down counter when GPIO level is unstable
 *    |------------------> {s_active_filter}    in 8bits Active filter status
 * */
typedef struct
{
   /* Filter status : 0 (unlock filter)  1 (filter value locked) */
   uint32_t    s_active_filter        : 8;
   /* Down counter before active filter                          */
   uint32_t    s_unstable_counter     : 8;
   /* High limit filter counter value from OSS_CONF or from PDS  */
   uint32_t    c_max_counter          : 8;
   /* Stable counter from unchanged discrete GPIO value          */
   uint32_t    s_stable_counter       : 8;
}ts_discrete_counter;

/* Union used to following counters for discrete signal */
typedef union
{
   uint32_t            u_word;
   ts_discrete_counter u_discrete_bit;
}tu_discrete_counter;

/* Configuration from discrete GPIO type to configure discrete GPIO descriptor table */
typedef struct
{
   /* Discrete ID of GPIO type                            */
   te_discrete_id              c_discrete_id;
   /* Discrete access GPDI address                        */
   reg8_t *                    p_discret_add;
   /* Share memory raw measure access for CSS             */
   uint32_t *                  p_shmem_access_raw;
   /* Share memory filter measure access for CSS          */
   uint32_t *                  p_shmem_access_filtered;
   /* Number of cycles for the filtering from OSS_CONF    */
   reg32_t  *                  p_conf_filter_nb_cycles;
}ts_discrete_conf;

/*** MDIN : FPGA registers for GPIO_IN Discrete Input values register ***/
/* Bit field structure register */
typedef struct
{
   uint32_t          s_spare_31_3          :29;
   uint32_t          s_mdin                : 1;
   uint32_t          s_pbit_uvd_status     : 1;
   uint32_t          s_pbit_ovd_pld_status : 1;
}ts_GPIO_IN_u_bit;

/* Union for GPIO_IN register */
typedef union
{
   uint32_t          u_word;
   ts_GPIO_IN_u_bit  u_bit;
}tu_GPIO_IN_REG;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Discrete GPIO configuration table */
extern const ts_discrete_conf DISCRETE_CONF_tab[e_discrete_nb];

/* Discrete GPIO descriptor table initiated at INIT and used during periodic task */
extern tu_discrete_counter DISCRETE_COUNTER_tab[e_discrete_nb];

/* ---------- provided operations: ------------------------------------------ */
/* Read discrete item */
extern void discrete_read(
   /* INPUT */
   const uint32_t         v_discrete_id,
   /* OUTPUT */
   uint32_t *       const p_discrete_filtred,
   uint32_t *       const p_discrete_prevdata,
   uint32_t *       const p_discrete_data);

/* Monitor discrete with filters from OSS_CONF */
extern void discrete_monitor(
   /* INPUT */
   const uint32_t          v_discrete_id,
   const uint32_t *  const p_discrete_prevdata,
   const uint32_t *  const p_discrete_data,
   /* INPUT and OUTPUT */
   uint32_t *        const p_discrete_filtred_data);

/* Write uploaded discrete value */
extern void discrete_write(
   /* INPUT */
   const uint32_t           v_discrete_id,
   const uint32_t *   const p_discrete_data,
   const uint32_t *   const p_discrete_filtred_data);

/* Perform CBIT for discrete */
extern void discrete_cbit(
   /* INPUT */
   const uint16_t *        const p_adc_value);

#endif /* End of DISCRETE_PRIVATE_H */
