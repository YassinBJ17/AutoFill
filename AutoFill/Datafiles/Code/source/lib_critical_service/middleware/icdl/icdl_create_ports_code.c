/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/icdl/ICDL_public.h"
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"


/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/*---------------------------------------------------------------------------
-- icdl_create_ports
---------------------------------------------------------------------------*/
void icdl_create_ports ( void )
{
   /* Local variables */
   uint32_t i;
   ts_CMN_IOSP_BUFFER buffer;
   te_ETH_UDP_PORT_Status l_eth_status;

   /* Create AS ports : it is dynamically set by AS in shared memory */
   for ( i = 0; i < ICDL_AS_NB_PORT; i++ )
   {
      /* create Rx ports */
      if ( shmem.s_icdl_rx.rx_message_tab[i].s_port != 0 )
      {
         buffer.s_buffer = (int8_t*)(&(shmem.s_icdl_rx.rx_message_tab[i].s_data_buffer));
         buffer.s_buffer_size = shmem.s_icdl_rx.rx_message_tab[i].s_length;
         DRV_COM_MNT_ETH_HANDLE_PORT( K_OPEN_PORT,
                                      shmem.s_icdl_rx.rx_message_tab[i].s_port,
                                      e_CMN_FLAG_NO,
                                      (ts_CMN_IOSP_BUFFER *)&(buffer),
                                      &l_eth_status );
      }
   }

}
