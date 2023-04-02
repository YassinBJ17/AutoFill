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

boolean_t ICDL_LG_GetFreeChannelID(uint32_t *p_ChannelId)
{
  boolean_t v_AChannelIsFree = FALSE;
  uint32_t v_NbOfFreeChannel = 0;
  uint32_t v_a_FreeChannelIdList[K_MAX_NB_CHANNEL];

  {
     uint32_t v_IndexOfChannel;
     for (v_IndexOfChannel = 0; v_IndexOfChannel < K_MAX_NB_CHANNEL;++v_IndexOfChannel)
     {
       if (E_READY_FOR_FF_USE == ICDL_LG_GetChannelStatus(v_IndexOfChannel))
       {
         v_a_FreeChannelIdList[v_NbOfFreeChannel] = v_IndexOfChannel;
         v_NbOfFreeChannel = v_NbOfFreeChannel + 1;
       }
     }
  }

  if (v_NbOfFreeChannel > 0)
     v_AChannelIsFree = TRUE;

  if (TRUE == v_AChannelIsFree)
  {
     *(p_ChannelId) =  v_a_FreeChannelIdList[0];
  }

  return v_AChannelIsFree;
}

/* ---------- internal operation bodies: ------------------------------------ */
