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
void ICDL_LG_SetCmdType(const uint32_t p_ChannelId, const uint32_t p_CmdType)
{
    /* Local variables definition */

    /* Local variables initialization */

    if (p_ChannelId >= K_MAX_NB_CHANNEL)
    {
       /** log an error. */
    }
    else
    {
        /** Set the command type */
        a_ChannelDescriptors[p_ChannelId].u32_CommandType = p_CmdType;
    }
}

/* ---------- internal operation bodies: ------------------------------------ */
