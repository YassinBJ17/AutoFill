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

boolean_t ICDL_LG_GetChannelToFree(uint32_t * p_ChannelId)
{
    /* Local variables definition */
    boolean_t v_ChannelToFree;

    /* Local variables initialization */
    v_ChannelToFree = FALSE;

    {
       uint32_t v_LoopIndex;
       for (v_LoopIndex = 0; ((v_LoopIndex < K_MAX_NB_CHANNEL) && (FALSE == v_ChannelToFree)); v_LoopIndex = v_LoopIndex + 1)
       {
           switch (a_ChannelDescriptors[v_LoopIndex].e_Status)
           {
               case E_FF_TRANSMISSION_IN_PROGRESS:
                   /** If a functional frame is associated to a channel which status
                    * is equal to E_READY_FOR_FF_TRANSMISSION,
                    * the channel is elected for transmission and its status is updated as in transmission; */
                    v_ChannelToFree = TRUE;
                    p_ElectedFFInTransmission = &(a_ChannelDescriptors[v_LoopIndex]);
                    *p_ChannelId = v_LoopIndex;
                    break;
               default:
                   /* Robustness: Functional range */
                   /*TODO*/
                   break;
                   /** otherwise, no functional frame is elected. */
           }
       }
   }
    return v_ChannelToFree;
}

/* ---------- internal operation bodies: ------------------------------------ */

