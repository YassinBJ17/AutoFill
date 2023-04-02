/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef OVSP_PRIVATE_H
#define OVSP_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "ToDetectOverspeed.h"

#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define OVSP_NTL_VAR_THRES_NB   6UL
#define OVSP_FREQ_PERIODS_NB  100UL


/* ---------- provided types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
extern inC_ToDetectOverspeed  V_OVSP_Context_In;
extern outC_ToDetectOverspeed V_OVSP_Context_Out;

extern uint32_t V_OVSP_NGOS1_NbPeriods_Prev;
extern uint32_t V_OVSP_NGOS2_NbPeriods_Prev;
extern uint32_t V_OVSP_NTLOS1_NbPeriods_Prev;
extern uint32_t V_OVSP_NTLOS2_NbPeriods_Prev;

extern uint32_t V_OVSP_TSpeed_NbPeriods_Prev;


/* ---------- provided operations: ------------------------------------------ */
extern void OVSP_Set_SCADE_InContext (void);


#endif /* OVSP_PRIVATE_H */
