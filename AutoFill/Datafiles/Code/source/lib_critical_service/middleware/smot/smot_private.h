/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef SMOT_PRIVATE_H
#define SMOT_PRIVATE_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- provided define constants: ------------------------------------ */
/* Smot previous phases state index intialization value */
#define SMOT_PH_PREV_STATE_INIT (uint32_t)0x00000000

/* Smot previous command initialization value */
#define SMOT_PREV_CMD_INIT (uint32_t)0x00000000

/* Smot high expected monitoring voltage threshold (V) */
#define SMOT_VOLT_LOW_TH (float32_t)10

/* Smot low expected monitoring voltage threshold (V) */
#define SMOT_VOLT_HIGH_TH (float32_t)50

/* Smot low expected monitoring current threshold (A) */
#define SMOT_CURR_LOW_TH (float32_t)0.05

/* Smot low expected monitoring current threshold for SC to GND on LS (A) */
#define SMOT_CURR_LOW_TH_SC_GND_TO_LS_SINGLE (float32_t)0.10

/* Smot middle expected monitoring current threshold (A) */
#define SMOT_CURR_MID_TH (float32_t)0.3

/* Smot high expected monitoring current threshold (A) */
#define SMOT_CURR_HIGH_TH (float32_t)0.4

/* Smot high expected monitoring current threshold (A) */
#define SMOT_CURR_HIGH_TH_BIS (float32_t)0.55

/* Smot low expected monitoring current threshold for common Voltage short to GND (A) */
#define SMOT_CURR_LOW_TH_COM_SC_TO_GND (float32_t)0.100

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* -------------------------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SMOT-0001 */
/* Implements REQ_FADEX_OS_SRD-SMOT-0010 */
/* Acquire smot phases state from GPIO */
extern void smot_ph_state_acq(uint32_t* p_smot_ph_state_idx /* out */);

/* Implements REQ_FADEX_OS_SRD-SMOT-0020 */
/* Smot CBIT */
extern void smot_cbit(const uint32_t* p_smot_ph_state_idx,   /* in */
                      const float32_t* p_smot_mon_voltage,   /* in */
                      const float32_t* p_smot_mon_current);  /* in */


/* Implements REQ_FADEX_OS_SRD-SMOT-0020 */
/* Acquire smot samples from internal ADC (SARADC_B) */
extern void smot_acquire_samples(float32_t* p_smot_computed_volt,     /* out */
                                 float32_t* p_smot_computed_current); /* out */


#endif /* SMOT_PRIVATE_H */
