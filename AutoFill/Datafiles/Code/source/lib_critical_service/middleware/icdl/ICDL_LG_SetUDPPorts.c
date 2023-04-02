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
void ICDL_LG_SetUDPPorts(const uint32_t p_ChannelId, const uint32_t p_PortsSrc, const uint32_t p_PortsDst)
{
    /* Local variables definition */

    /* Local variables initialization */

    if (p_ChannelId >= K_MAX_NB_CHANNEL)
    {
        /**log an error. */
    }
    else
    {
        /** Set the command type */
        a_ChannelDescriptors[p_ChannelId].ethUdpInfo.s_SrcPort= p_PortsSrc;
        a_ChannelDescriptors[p_ChannelId].ethUdpInfo.s_DstPort= p_PortsDst;
    }
}

/* ---------- internal operation bodies: ------------------------------------ */
