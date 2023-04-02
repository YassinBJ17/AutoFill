/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVGPIO_PUBLIC_H
#define DRVGPIO_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVGPIO_IN_DININHIB          0UL
#define DRVGPIO_IN_OSREARM           1UL
#define DRVGPIO_IN_NTLOSTEST         2UL
#define DRVGPIO_IN_DOUTINHIB_FB      3UL
#define DRVGPIO_IN_CAMLOW2_FB        4UL
#define DRVGPIO_IN_OSARM_FB          5UL

#define DRVGPIO_OUT_CAM_CMD1         6UL
#define DRVGPIO_OUT_CAM_CMD2         7UL
#define DRVGPIO_OUT_DOUTINHIB        8UL
#define DRVGPIO_OUT_OSARM_CMD        9UL
#define DRVGPIO_OUT_REARM_CMD       10UL
#define DRVGPIO_OUT_DISCRETE_TEST   11UL


/* ---------- provided types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void DrvGPIO_Initialize (void);

extern void DrvGPIO_Read (const uint32_t p_GPIO_Name, TE_OVSP_SW_Cmd * const p_pt_Read_Cmd);

extern void DrvGPIO_Write (const uint32_t p_GPIO_Name, const TE_OVSP_SW_Cmd p_Cmd_To_Write);

extern void DrvGPIO_Check_RegConfig (uint32_t * const p_pt_Check_Result);


#endif /* DRVGPIO_PUBLIC_H */
