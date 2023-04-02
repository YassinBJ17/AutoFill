/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVADC_PUBLIC_H
#define DRVADC_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVADC_CAM_HS_CURRENT         0UL
#define DRVADC_CAM_LS_CURRENT         1UL
#define DRVADC_CAM_VLOAD              2UL
#define DRVADC_TEMPERATURE            3UL


/* ---------- provided types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void DrvADC_Initialize (void);

extern void DrvADC_Read (const uint32_t p_Analog_Num, float32_t * const p_pt_ADC_Value);

extern void DrvADC_Check_RegConfig (uint32_t * const p_pt_Check_Result);


#endif /* DRVADC_PUBLIC_H */
