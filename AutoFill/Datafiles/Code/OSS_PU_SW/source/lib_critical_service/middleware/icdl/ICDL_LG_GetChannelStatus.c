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
t_FFStatus_E ICDL_LG_GetChannelStatus(const uint32_t p_ChannelID)
{
    /* Local variables definition */
     /* None */
    /* Local variables initialization */
    /* None */

    return a_ChannelDescriptors[p_ChannelID].e_Status;
}

/* ---------- internal operation bodies: ------------------------------------ */
