/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_LG_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
boolean_t ICDL_LG_InitializeChannel( const uint32_t p_ChannelId )
{
   /* Local variables definition */
   boolean_t v_InitSuccess;

   /* Local variables initialization */
   v_InitSuccess = FALSE;

   if ( K_MAX_NB_CHANNEL < p_ChannelId )
   {
      /* Init success is FALSE */
      /*TODO*/
   }
   else
   {
      /**Initialize the association between channel and functional frame*/
      ICDL_LG_ChangeChannelStatus(p_ChannelId, E_READY_FOR_FF_USE);
      a_ChannelDescriptors[p_ChannelId].u32_Size = 0 ;
      a_ChannelDescriptors[p_ChannelId].p_ElectedFFInfo = &(a_FunctionalFrames[p_ChannelId]) ;

      /* Initialize device specific data structure pointer in main control object*/
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> cast is safe, array is initialized with zeros */
      LIB_MEM_SET ( (int8_t *) (int8_t *) &(a_FunctionalFrames[p_ChannelId]) ,
                    (int8_t)0x00 ,
      /* >RELAX<SYNCHRONe_C_Code_10.7> cast is safe, size_t fits in uint32_t */
                    (uint32_t)sizeof(t_FunctionalFrame) ) ;

   }

   return v_InitSuccess;
}

/* ---------- internal operation bodies: ------------------------------------ */
