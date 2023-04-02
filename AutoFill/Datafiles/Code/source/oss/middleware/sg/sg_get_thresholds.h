/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef SG_GET_THRESHOLDS_H
#define SG_GET_THRESHOLDS_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
#define C_SG_THRES_COUNT   4

/* ---------- provided types: ----------------------------------------------- */
/* Thresholds structure */
typedef struct
{
   float32_t s_threshold_1;   /* Volt */
   float32_t s_threshold_2;   /* Volt */
   float32_t s_threshold_3;   /* Volt */
   float32_t s_threshold_4;   /* Volt */
   float32_t s_threshold_5;   /* Volt */
   float32_t s_threshold_6;   /* Volt */
   float32_t s_threshold_7;   /* mA */
   float32_t s_threshold_8;   /* mA */
   float32_t s_threshold_9;   /* Volt */
   float32_t s_threshold_10;  /* mA */
   float32_t s_threshold_11;  /* mV / Volt */
   float32_t s_threshold_12;  /* mV / Volt */
}
ts_sg_thresholds;

/* ---------- provided constants: ------------------------------------------- */
/*  */
extern const ts_sg_thresholds v_check_values[C_SG_THRES_COUNT];

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/*  */
extern const ts_sg_thresholds * sg_get_thresholds(uint8_t p_sendor_id);

#endif /* SG_GET_THRESHOLDS_H */
