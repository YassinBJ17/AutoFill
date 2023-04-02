/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/stack_ip/ETH_COMM_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_private.h"

#include "libtools/memory/LIB_MEM_public.h"

#include "middleware/accom/accom_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */


/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Channel we are on, read in MRAM */

/* ---------- provided operation bodies: ------------------------------------ */
/*!@brief ICDL Ethernet UDP initialization.
 *
 *
 * @param[in] mask_disable_function Mask (binary or) of the UOD2 features to disable at runtime
 */
void ETH_COMM_INIT( void )
{
   tu_CMN_RC v_rc;
   te_CMN_FLAG_ACTIVATION itsDone;
   const MAC_ETH_MACAddr_t * pt_conf ;
   tu_accom_ch_bit_fault_word accom_word;

   /* MAC ADDR CDM */
   accom_word = accom_ch_cbit();
   if( FALSE == accom_word.u_bit.s_ch_id )
   {
      pt_conf = &(c_mac_CDMAaddr);
   }
   else
   {
      pt_conf = &(c_mac_CDMBaddr);
   }


   LIB_MEM_CPY( (int8_t*)&ethUdpInfo.s_IdDest.s_HwAddress.s_val[0],
                (int8_t*)pt_conf,
                ETH_HAL_MAC_SIZE );

   ETH_INIT( &v_rc );

   ETH_ESTABLISH_CONNECTION( &itsDone );

}
