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
boolean_t ICDL_LG_ChangeChannelStatus(const uint32_t p_ChannelID, t_FFStatus_E p_NewState)
{
   /* Local variables definition */
   boolean_t v_bool_ReturnCode ;
   t_ChannelDescriptor * v_p_ChannelToUpdate;

   /* Local variables initialization */
   v_bool_ReturnCode = FALSE ;

   if ( K_MAX_NB_CHANNEL <= p_ChannelID )
   {
      /* Return an invalid code to indicate the change of status has not been
       * performed */
      /*TODO*/
   }
   /** If the given channel identifier is defined */
   else
   {
      v_p_ChannelToUpdate = &(a_ChannelDescriptors[p_ChannelID]);
      v_bool_ReturnCode = TRUE;
      switch (p_NewState)
      {
         case E_READY_FOR_FF_TRANSMISSION:
         case E_READY_FOR_FF_USE:
         case E_FF_TRANSMISSION_IN_PROGRESS:
            /** if the required new status is a defined value, the status of the channel is updated */
            v_p_ChannelToUpdate->e_Status = p_NewState;
         break;
         default:
            /** else the status of the channel is not updated */
            /* Return an invalid code to indicate the change of status has not been performed */
            v_bool_ReturnCode = FALSE;
         break;
      }
   }
   return ( v_bool_ReturnCode );
}

/* ---------- internal operation bodies: ------------------------------------ */
