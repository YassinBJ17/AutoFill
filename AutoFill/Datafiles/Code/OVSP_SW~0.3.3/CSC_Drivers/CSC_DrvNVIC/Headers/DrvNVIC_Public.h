/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVNVIC_PUBLIC_H
#define DRVNVIC_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVNVIC_BOOT_IRQ_SELECTION   1UL
#define DRVNVIC_SEQ_IRQ_SELECTION    2UL


/* ---------- provided types: ----------------------------------------------- */
typedef void (* TPTF_DrvNVIC_VectorsTable) (void);


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void DrvNVIC_Initialize (const uint32_t p_IRQ_Selection);

extern void DrvNVIC_Init_VTOR_InSRAM (void);


#endif /* DRVNVIC_PUBLIC_H */
