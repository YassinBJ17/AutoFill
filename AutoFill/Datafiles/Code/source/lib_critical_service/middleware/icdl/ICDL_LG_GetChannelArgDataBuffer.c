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
void ICDL_LG_GetChannelArgDataBuffer(const uint32_t p_ChannelID, uint8_t ** p_ArgDataBuffer )
{
   /* Local variables definition */
   /* None */
   /* Local variables initialization */
   /* None */

   /* Retrieve the reference of the Arguments and Data buffer */
   /** If the channel ID is valid:*/
   if ( K_MAX_NB_CHANNEL < p_ChannelID)
   {
      /** If the ID is invalid, the output is set to K_NULL*/
      (*p_ArgDataBuffer) = NULL ;
   }
   else
   {
      /** Else, the output points to the argument structure of the channel*/
      (*p_ArgDataBuffer) = a_ChannelDescriptors[p_ChannelID].p_ElectedFFInfo->a_ArgumentSetAndDataSet ;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
