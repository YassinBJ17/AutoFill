/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef OVSP_PUBLIC_H
#define OVSP_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "ToDetectOverspeed.h"

#include "OVSP_SW_Public.h"
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define OVSP_NGOS1_ID    0UL
#define OVSP_NGOS2_ID    1UL
#define OVSP_NTLOS1_ID   2UL
#define OVSP_NTLOS2_ID   3UL
#define OVSP_TSPEED_ID   4UL


/* ---------- provided types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void OVSP_Initialize (void);
extern void OVSP_Treatments (void);

extern uint32_t * OVSP_Get_Periods_Array (const uint32_t p_Signal_Name);

extern float32_t OVSP_Get_NGOS1_Measure (void);
extern boolean_t OVSP_Get_NGOS1_OutOfTime (void);
extern boolean_t OVSP_Get_NGOS1_OutOfHigh (void);
extern boolean_t OVSP_Get_NGOS1_Updated (void);

extern float32_t OVSP_Get_NGOS2_Measure (void);
extern boolean_t OVSP_Get_NGOS2_OutOfTime (void);
extern boolean_t OVSP_Get_NGOS2_OutOfHigh (void);
extern boolean_t OVSP_Get_NGOS2_Updated (void);

extern float32_t OVSP_Get_NTLOS1_Measure (void);
extern boolean_t OVSP_Get_NTLOS1_OutOfTime (void);
extern boolean_t OVSP_Get_NTLOS1_OutOfHigh (void);
extern boolean_t OVSP_Get_NTLOS1_Updated (void);

extern float32_t OVSP_Get_NTLOS2_Measure (void);
extern boolean_t OVSP_Get_NTLOS2_OutOfTime (void);
extern boolean_t OVSP_Get_NTLOS2_OutOfHigh (void);
extern boolean_t OVSP_Get_NTLOS2_Updated (void);

extern TE_OVSP_SW_Speed_Level OVSP_Get_Engine_SpeedLevel (void);

extern TE_OVSP_SW_Cmd OVSP_Get_DOUTINHIB (void);

extern TE_OVSP_SW_Cmd OVSP_Get_CAM_Cmd1 (void);
extern TE_OVSP_SW_Cmd OVSP_Get_CAM_Cmd2 (void);

extern TE_OVSP_SW_Cmd OVSP_Get_OSARM_Cmd (void);
extern TE_OVSP_SW_Cmd OVSP_Get_REARM_Cmd (void);

extern float32_t OVSP_Get_Test_Speed_Measure (void);


#endif /* OVSP_PUBLIC_H */
