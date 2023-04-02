/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/ethernet/ETH_porting.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */


/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void DRV_COM_MNT_ETH_INIT( void )
{
   tu_CMN_RC status;

   status.u_r = 0;

   /* Initialize FEC */
   hal_init_pt(&status);

   /* Initialize IP SRC */
/*   ETH_CFEX_CDREtherAddr.u_IP =  p_myIP->u_IP;*/

   /* Initialize ETH COMM */
   ETH_COMM_INIT();

}
