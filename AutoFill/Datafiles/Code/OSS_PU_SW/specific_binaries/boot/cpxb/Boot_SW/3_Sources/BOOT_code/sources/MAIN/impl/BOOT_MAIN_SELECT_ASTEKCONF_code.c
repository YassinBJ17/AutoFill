/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function selects the Repetitive Sequence of Frame
 *               (ASTEKCONF) to be used by ASTERIOS.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "BOOT_MAIN_public.h"
#include "BOOT_MAIN_private.h"
#include "BOOT_CONF_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define ASTEKCONF_ADDR_INVALID (0xDEADBEEFul)
#define ASTEKCONF_ADDR_VALID (0x0FACADE0ul)

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */
/* Implements REQ_[User Project Name]_BOOT-LLR_057 */
uint32_t BOOT_MAIN_SELECT_ASTEKCONF ( void )
{
   uint32_t v_ASTEKCONF_index= 0;
   uint32_t* pt_flag_addr;
   uint32_t v_returnval = ASTEKCONF_ADDR_INVALID;

   /* Search for the first valid RSF */
   while ( ( v_ASTEKCONF_index < CONF_ASTEKCONF_NB ) && ( v_returnval == ASTEKCONF_ADDR_INVALID ) )
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : s_validity_flag_addr is an address */
      pt_flag_addr = (uint32_t*) c_CONF_ASTEK_tab[v_ASTEKCONF_index].s_validity_flag_addr;

      /* >RELAX<SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_10.7> The cast is safe. It is used to get the address of the*/
      /* pointed data. */
      if ((uint32_t)pt_flag_addr ==  (uint32_t)NULL)
      {
         /* No validity flag to check in memory. Select the current ASTEKCONF */
         v_returnval = v_ASTEKCONF_index;
      }
      else
      {
         if( (*pt_flag_addr) == ASTEKCONF_ADDR_VALID )
         {
            v_returnval = v_ASTEKCONF_index;
         }
         v_ASTEKCONF_index++;
      }
   }

   return ( v_returnval );

}
