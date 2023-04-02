/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef SMOT_WRITE_PUBLIC_H
#define SMOT_WRITE_PUBLIC_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- provided define constants: ------------------------------------ */
/* Smot status no fault value */
#define SMOT_STATUS_NO_FAULT (uint32_t)0x00000000

/* Delay between two critical service call (in second) */
#define SRV_CALL_DELAY (float32_t)0.0205

/* Number of smot positions */
#define SMOT_POS_NB (uint32_t)8

/* Smot phase 1 commanded corresponding index */
#define SMOT_PH1_IDX (uint32_t)0

/* Smot phase 1 and 2 commanded corresponding index */
#define SMOT_PH1_PH2_IDX (uint32_t)1

/* Smot phase 2 commanded corresponding index */
#define SMOT_PH2_IDX (uint32_t)2

/* Smot phase 2 and 3 commanded corresponding index */
#define SMOT_PH2_PH3_IDX (uint32_t)3

/* Smot phase 3 commanded corresponding index */
#define SMOT_PH3_IDX (uint32_t)4

/* Smot phase 3 and 4 commanded corresponding index */
#define SMOT_PH3_PH4_IDX (uint32_t)5

/* Smot phase 4 commanded corresponding index */
#define SMOT_PH4_IDX (uint32_t)6

/* Smot phase 1 and 4 commanded corresponding index */
#define SMOT_PH1_PH4_IDX (uint32_t)7

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Smot speed configuration (Time to move one half step in second) */
extern float32_t smot_speed_time;

/* Smot previous increment number command */
extern int32_t smot_previous_incr_cmd;

/* Smot previous common phase state index */
extern uint32_t smot_ph_prev_state_idx;

/* Smot expected position */
extern uint32_t smot_expected_position;

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-TMOT-0001 */
/* Transmit the CSS_PU command to FPGA when the command is valid */
extern void smot_write(void);

#endif /* SMOT_WRITE_PUBLIC_H */
