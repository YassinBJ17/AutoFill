/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"
#include "middleware/stack_ip/ETH_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */


/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void DRV_COM_MNT_ETH_HANDLE_RECEPTION ( void )
{
   /* Manage Ethernet reception for UOD and/or  AS */
   ETH_DRV_HandleReception();
}
