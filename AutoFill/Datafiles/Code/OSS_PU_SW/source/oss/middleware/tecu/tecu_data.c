/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : TECU global data file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_public.h"
#include "middleware/tecu/tecu_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

float32_t prev_taccom;    /* Previous accommodation temperature */
float32_t prev_tcu1;      /* Previous control unit temperature */
float32_t prev_tpsf;      /* Previous primary power supply temperature */
float32_t prev_tcu2;      /* Previous control processing core die temperature */
float32_t prev_tohs;      /* The previous overspeed high side temperature */
float32_t prev_tols;      /* The previous overspeed low side temperature */
float32_t prev_tcj;       /* The previous cold junction temperature */


float32_t last_valid_tecu_avg;    /* The last valid weighted average temperature */


float32_t max_tecu;               /* The maximum computed TECU value */
float32_t max_tecu_time;          /* Indicate the ime when the maximum TECU value is computed */


ts_tecu prev_tecua_status;        /* Previous TECU status for channel A */
ts_tecu prev_tecub_status;        /* Previous TECU status for channel B */


int16_t TECU_tcsa;                /* Temperature Sensor Calibration A */
int16_t TECU_tcsb;                /* Temperature Sensor Calibration B */


tu_tecu_err_indic_type tecu_err_indic;    /* TECU temperatures erroneous value indicators */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */
