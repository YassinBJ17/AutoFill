/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVPAD_PUBLIC_H
#define DRVPAD_PUBLIC_H

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"

/* ---------- include required interface: ----------------------------------- */
/* None */

/* ---------- provided define constants: ------------------------------------ */
/* None */

/* ---------- provided types: ----------------------------------------------- */
/* None */

/* ---------- provided constants: ------------------------------------------- */
/* None */

/* ---------- provided data: ------------------------------------------------ */
/* None */

/* ---------- provided operations: ------------------------------------------ */

/* PAD Initialize: To initialize all ports A, B, C, D and E
 *
 * Parameters:
 *   Inputs: None
 *   Outputs: None
 *
 *  */
extern void DrvPAD_Initialize(void);


/* PAD Check Ports: To check all ports A, B, C, D and E
 *
 * Parameters:
 *   Inputs: p_status
 *   Outputs: None
 *
 *  */
extern void DrvPAD_check_ports(uint32_t * p_status);
#endif /* DRVPAD_PUBLIC_H */


