/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : lvdt_init_fault_word_thresholds function which sets
                 thresholds values for LVDT A, B and C according to oss conf
                 table.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/lvdt/lvdt_private.h"
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* Thresholds used for fault word computation */
ts_lvdt_fault_word_thresholds * lvdt_fault_word_thresholds_lvdtx[3];

/* ---------- internal constants: ------------------------------------------- */

/* Thresholds for type 1 and type 2 */
const ts_lvdt_fault_word_thresholds lvdt_fault_word_thresholds[2] = {
   { /* LVDT type 1  */
       ((float32_t) -0.04   ) , /* TBC_1  */
       ((float32_t) +0.04   ) , /* TBC_2  */
       ((float32_t) +2.4    ) , /* TBC_3  */
       ((float32_t) +2.55   ) , /* TBC_4  */
       ((float32_t) -0.04   ) , /* TBC_5  */
       ((float32_t) +0.04   ) , /* TBC_6  */
       ((float32_t) +2.4    ) , /* TBC_7  */
       ((float32_t) +2.55   ) , /* TBC_8  */
       ((float32_t) +0.15   ) , /* TBC_11 */
       ((float32_t) +1.55   ) , /* TBC_12 */
       ((float32_t) +0.15   ) , /* TBC_13 */
       ((float32_t) +1.55   ) , /* TBC_14 */
       ((float32_t) +3.0    ) , /* TBC_15 */
       ((float32_t) +9.9    ) , /* TBC_16 */
       ((float32_t) +2.00   ) , /* TBC_17 */
       ((float32_t) +0.45   ) , /* TBC_18 */
       ((float32_t) +0.08575) , /* TBC_19 */
       ((float32_t) +0.95   ) , /* TBC_20 */
       ((float32_t) +0.08575) , /* TBC_21 */
       ((float32_t) +0.95   ) , /* TBC_22 */
       ((float32_t) -0.56   ) , /* TBC_23 */
       ((float32_t) +0.56   ) , /* TBC_24 */
       ((float32_t) +0.75   ) , /* TBC_100 */
       ((float32_t) +8.8    ) , /* TBC_101 */
       ((float32_t) +0.75   ) , /* TBC_102 */
       ((float32_t) +8.8    ) , /* TBC_103 */
   },
   { /* LVDT type 2  */
       ((float32_t) -0.04   ) , /* TBC_1  */
       ((float32_t) +0.04   ) , /* TBC_2  */
       ((float32_t) +2.4    ) , /* TBC_3  */
       ((float32_t) +2.55   ) , /* TBC_4  */
       ((float32_t) -0.04   ) , /* TBC_5  */
       ((float32_t) +0.04   ) , /* TBC_6  */
       ((float32_t) +2.4    ) , /* TBC_7  */
       ((float32_t) +2.55   ) , /* TBC_8  */
       ((float32_t) +0.15   ) , /* TBC_11 */
       ((float32_t) +1.55   ) , /* TBC_12 */
       ((float32_t) +0.15   ) , /* TBC_13 */
       ((float32_t) +1.55   ) , /* TBC_14 */
       ((float32_t) +3.0    ) , /* TBC_15 */
       ((float32_t) +9.9    ) , /* TBC_16 */
       ((float32_t) +2.00   ) , /* TBC_17 */
       ((float32_t) +0.45   ) , /* TBC_18 */
       ((float32_t) +0.01525) , /* TBC_19 */
       ((float32_t) +0.723  ) , /* TBC_20 */
       ((float32_t) +0.01525) , /* TBC_21 */
       ((float32_t) +0.723  ) , /* TBC_22 */
       ((float32_t) -0.86   ) , /* TBC_23 */
       ((float32_t) +0.86   ) , /* TBC_24 */
       ((float32_t) +0.25   ) , /* TBC_100 */
       ((float32_t) +6.75   ) , /* TBC_101 */
       ((float32_t) +0.25   ) , /* TBC_102 */
       ((float32_t) +6.75   ) , /* TBC_103 */
   }
};

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-lvdt-xxxx */
void lvdt_init_fault_word_thresholds(void)
{
   /* OSS conf access */
   ts_oss_conf_table * pt_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

   /* Init thresholds */
   lvdt_fault_word_thresholds_lvdtx[LVDT_SENSOR_ID_A] = (ts_lvdt_fault_word_thresholds *)(&lvdt_fault_word_thresholds[pt_oss_conf->s_lvdta_sensor_type]);
   lvdt_fault_word_thresholds_lvdtx[LVDT_SENSOR_ID_B] = (ts_lvdt_fault_word_thresholds *)(&lvdt_fault_word_thresholds[pt_oss_conf->s_lvdtb_sensor_type]);
   lvdt_fault_word_thresholds_lvdtx[LVDT_SENSOR_ID_C] = (ts_lvdt_fault_word_thresholds *)(&lvdt_fault_word_thresholds[pt_oss_conf->s_lvdtc_sensor_type]);
}

/* ---------- internal operations: ------------------------------------------ */
