/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox ETH init function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/mailbox/MAC_ETH_HAL_public.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "middleware/stack_ip/ETH_public.h"
#include "middleware/accom/accom_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* MBX configuration table */


/* ---------- provided operation bodies: ------------------------------------ */
/* */
uint32_t MBX_INIT( tu_CMN_RC * const p_return_code )
{
   /* Local Variable Declaration */
   MAC_ETH_MACAddr_t const * pt_conf ;
   uint32_t                  v_conf_ind;

   tu_accom_ch_bit_fault_word accom_word;
   /*
    * Configure MAC ETH tx / rx
    */
   MAC_ETH_INIT( p_return_code );

    /*
     * Configure Mailbox tx / rx
     */
   for( v_conf_ind = 0UL; v_conf_ind < c_MBX_CFEX_tab_SIZE; v_conf_ind++ )
   {
      /*
       * Get Configuration descriptor
       */
      accom_word = accom_ch_cbit();
      if( FALSE == accom_word.u_bit.s_ch_id )
      {
         pt_conf = &(c_mac_CDRAaddr);
      }
      else
      {
         pt_conf = &(c_mac_CDRBaddr);
      }

       /*
        * Configure mailbox mac address
        */
      /* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> : no loss of precision, cast are needed for syntax matching  */
      LIB_MEM_CPY( (int8_t*)MBX_CFEX_descriptor.s_mac_addr,
                    (int8_t *)pt_conf,
                    ETH_HAL_MAC_SIZE );
      /* }}<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> */

       /*
        * Configure mailbox tx
        */
      MBX_INIT_tx ( (CMN_IOSP_ID_t const) v_conf_ind );

       /*
        * Configure mailbox rx
        */
      MBX_INIT_rx ( (CMN_IOSP_ID_t const) v_conf_ind );
   }

}

/* ---------- internal operation bodies: ------------------------------------ */
