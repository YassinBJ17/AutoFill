/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_ARP_common.h"
#include "middleware/stack_ip/ETH_ARP_private.h"
#include "libtools/memory/LIB_MEM_public.h"

/*---------------------------------------------------------------------------*/
/* NAME: ETH_ARP_Init()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE: Initialize ARP variables*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: None.*/
/*---------------------------------------------------------------------------*/

void ETH_ARP_INIT(void)
{
   uint32_t v_i ;

   /* number of entries in the ARP table*/
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast needed to handle v_ETH_ARP_ControlObj as bytes */
   LIB_MEM_SET( (int8_t*) &v_ETH_ARP_ControlObj, (int8_t)0x00, (uint32_t)sizeof(ts_ETH_ARP_CONTROL )) ;

   for ( v_i = 0ul ; v_i < INTEG_ETH_ARP_MAX_ARP_ENTRIES ; v_i ++)
   {
      v_ETH_ARP_ControlObj.s_Table[ v_i ].s_ARPType = e_ETH_ARP_NOT_USED;
   }
}
