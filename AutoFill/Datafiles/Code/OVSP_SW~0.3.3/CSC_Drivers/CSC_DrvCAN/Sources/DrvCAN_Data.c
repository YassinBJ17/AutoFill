/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvCAN CSC data definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvCAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
/* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as they are 32-bit Unsigned Long address */
/* converted to pointers which are also an 32-bit Unsigned Long. */
TS_DrvCAN_Registers * const C_DrvCAN_FlexCAN1_Registers = (TS_DrvCAN_Registers *) DRVCAN_FLEXCAN1_ADDRESS;

/* {{RELAX<SYNCHRONe_C_Code_23.2> CR lem#11175: Braces and comma have not to be on next line for "Initializer list" */
const TS_DrvCAN_CAN_Config C_DrvCAN_CAN_Config [DRVCAN_MB_MAX_NUMBER] =
{
   {0xFFFFFFFFUL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB00, DRVCAN_SELECT_RX},
   {0x0000061FUL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB01, DRVCAN_SELECT_RX},
   {0xFFFFFFFFUL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB02, DRVCAN_SELECT_RX},
   {0xFFFFFFFFUL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB03, DRVCAN_SELECT_RX},
   {0xFFFFFFFFUL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB04, DRVCAN_SELECT_RX},
   {0xFFFFFFFFUL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB05, DRVCAN_SELECT_RX},
   {0xFFFFFFFFUL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB06, DRVCAN_SELECT_RX},
   {0x000001FFUL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB07, DRVCAN_SELECT_RX},
   {0xFFFFFFFFUL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB08, DRVCAN_SELECT_RX},
   {0xFFFFFFFFUL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB09, DRVCAN_SELECT_RX},
   {0x00000000UL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB10, DRVCAN_SELECT_TX},
   {0x00000000UL, DRVCAN_IDE_NONE, DRVCAN_IDE_MB11, DRVCAN_SELECT_TX},
   {0x00000000UL, DRVCAN_IDE_NONE, DRVCAN_IDE_NONE, DRVCAN_SELECT_TX},
   {0x00000000UL, DRVCAN_IDE_NONE, DRVCAN_IDE_NONE, DRVCAN_SELECT_TX},
   {0x00000000UL, DRVCAN_IDE_NONE, DRVCAN_IDE_NONE, DRVCAN_SELECT_TX},
   {0x00000000UL, DRVCAN_IDE_NONE, DRVCAN_IDE_NONE, DRVCAN_SELECT_TX}
};
/* }} RELAX<SYNCHRONe_C_Code_23.2> */
/* }} RELAX<SYNCHRONe_C_Code_24.5> */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* None */
