/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef SG_PUBLIC_H
#define SG_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Number of sensor to handle */
#define C_SENSOR_COUNT ((uint8_t)7)

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Calibrated voltage for P3/SG/SAI */
extern float32_t p3_sg_sai_calibrated_voltage[C_SENSOR_COUNT];

/* Calibrated voltage excitation for P3/SG/SAI */
extern float32_t p3_sg_sai_calibrated_voltage_exc[C_SENSOR_COUNT];

/* Low side voltage for P3/SG/SAI */
extern float32_t p3_sg_sai_ls_current[C_SENSOR_COUNT];

/* ---------- provided operations: ------------------------------------------ */
/* Setup strain gauge sensors information data-structure */
extern void sg_init(const boolean_t channel_is_a);

/* Sample and consolidate reading, then establish status word for each strain gauge sensor */
/* Implements REQ_FADEX_OS_SRD-SG-0020 */
/* Implements REQ_FADEX_OS_SRD-SG-0030 */
/* Implements REQ_FADEX_OS_SRD-SG-0050 */
extern void sg_periodic(void);


#endif /* SG_PUBLIC_H */
