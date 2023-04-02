/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVLPSPI_PUBLIC_H
#define DRVLPSPI_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
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
extern void DrvLPSPI_Initialize (void);

extern void DrvLPSPI_Read (uint32_t * const p_pt_Read_Value, uint32_t * const p_pt_Status);

extern void DrvLPSPI_Write (const uint32_t p_Value, uint32_t * const p_pt_Status);

extern void DrvLPSPI_Check_RegConfig (uint32_t * const p_pt_Check_Result);


#endif /* DRVLPSPI_PUBLIC_H */
