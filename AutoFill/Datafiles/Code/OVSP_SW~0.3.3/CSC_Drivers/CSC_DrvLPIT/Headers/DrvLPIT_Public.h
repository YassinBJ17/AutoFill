/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVLPIT_PUBLIC_H
#define DRVLPIT_PUBLIC_H

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"

/* ---------- include required interface: ----------------------------------- */
/* None */

/* ---------- provided define constants: ------------------------------------ */
/* Maximum number of Timers */
#define DRVLPIT_MAX_NB              2UL

#define DRVLPIT_IDENT_0             0UL
#define DRVLPIT_IDENT_1             1UL
#define DRVLPIT_IDENT_ERROR         2UL

#define DRV_LPIT_CHANNEL_0          0UL
#define DRV_LPIT_CHANNEL_1          1UL
#define DRV_LPIT_CHANNEL_2          2UL
#define DRV_LPIT_CHANNEL_3          3UL

#define DRVLPIT_500_US              50UL

/* ---------- provided types: ----------------------------------------------- */
/* None */

/* ---------- provided constants: ------------------------------------------- */
/* None */

/* ---------- provided data: ------------------------------------------------ */
/* None */

/* ---------- provided operations: ------------------------------------------ */

extern void DrvLPIT_Initialize(void);

extern void DrvLPIT_Check_Init_RegConfig (uint32_t * p_pt_Check_Result);
extern void DrvLPIT_Check_Run_RegConfig (uint32_t * p_pt_Check_Result);

extern void DrvLPIT_Start(uint32_t const p_TimerId, uint32_t const p_Timeout);
extern void DrvLPIT_Stop(uint32_t const p_TimerId);
extern void DrvLPIT_Reset(void);



#endif /* DRVLPIT_PUBLIC_H */


