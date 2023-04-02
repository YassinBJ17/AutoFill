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
void ICDL_LG_UpdateFFLength (const uint32_t p_ChannelID, const uint32_t p_Size)
{
    /* Local variables definition */
    /* None */

    /* Local variables initialization */
    /* None */

    /** Set in the size attribute of the channel the given size value */
    a_ChannelDescriptors[p_ChannelID].u32_Size = p_Size ;
}

/* ---------- internal operation bodies: ------------------------------------ */
