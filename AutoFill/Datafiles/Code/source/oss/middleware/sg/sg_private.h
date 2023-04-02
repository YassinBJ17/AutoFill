/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef SG_PRIVATE_H
#define SG_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "middleware/sg/sg_public.h"
#include "memory/shared_memory_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Conversions */
#define C_VOLT_TO_MILLIVOLT   ((float32_t)1000)

/* GPIO Handling */
#define C_SELECT_SAI1_3_N  ((uint8_t *)0xFFFC1348) /* GPDO 72 */
#define C_SELECT_SAI2_4_N  ((uint8_t *)0xFFFC1349) /* GPDO 73 */
#define C_SET_SG           ((uint8_t)0x01)
#define C_IS_SG            ((uint32_t)0)

/* Sample reading parameters */
#define C_READ_OFFSET      ((int16_t)4)
#define C_READ_COUNT       ((int16_t)8)
#define C_MON_COUNT        ((int16_t)12)

/* SG Sensors gains (source: BSIS_CPMB draft 7.docm) */
#define C_SG1_SIG_GAIN      ((float32_t)1.00103f)
#define C_SG1_SIG_OFFSET    ((float32_t)-0.003f)

#define C_SG2_SIG_GAIN      ((float32_t)1.039692f)
#define C_SG2_SIG_OFFSET    ((float32_t)0.002f)

#define C_SG3_SIG_GAIN      ((float32_t)1.000725f)
#define C_SG3_SIG_OFFSET    ((float32_t)-0.00366f)

#define C_SG4_SIG_GAIN      ((float32_t)1.007849f)
#define C_SG4_SIG_OFFSET    ((float32_t)0.084f)

#define C_SG5_SIG_GAIN      ((float32_t)1.005339f)
#define C_SG5_SIG_OFFSET    ((float32_t)0.0769f)

/* SAI Sensors gains (source: BSIS_CPMB draft 7.docm) */
#define C_SAI_SIG_GAIN     ((float32_t)1.0f)
#define C_SAI_SIG_OFFSET   ((float32_t)0.0f)

/* P3 Sensors gains (source: BSIS_CPMB draft 7.docm) */
#define C_P3_SIG_GAIN      ((float32_t)1.002079f)
#define C_P3_SIG_OFFSET    ((float32_t)-0.014f)

#define C_LOWSIDE_OHM      ((float32_t)301.4)

/* ---------- provided types: ----------------------------------------------- */
/* Index of all known sensors */
typedef enum
{
   e_p3a = 0,
   e_p3b,
   e_sg1,
   e_sg2,
   e_sg3,
   e_sg4,
   e_sg5b,
   e_sai1,
   e_sai2,
   e_sai3,
   e_sai4,
   e_SensorMax
}
te_sg_signal;

/* Sensors parameters */
typedef struct
{
   te_sg_signal s_input_id;
   int16_t      s_read_start;
   int16_t      s_read_count;
   int16_t      s_mon_count;
   float32_t    s_sig_gain;
   float32_t    s_sig_offset;
   boolean_t    s_is_other_channel;
   ts_sg        s_value;
}
ts_sg_sensor_info;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Array holding parameters of all known sensors  */
extern ts_sg_sensor_info v_sg_sensors[C_SENSOR_COUNT];

/* ---------- provided operations: ------------------------------------------ */


#endif /* SG_PRIVATE_H */
