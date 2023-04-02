#include "phy.h"

boolean_t phy_is_link_up (const t_phy_handle phy)
{
	uint32_t val;
	boolean_t ret;
	
	(void) phy_read( phy, (uint32_t)MII_BMSR );
	/* link up status is only updated on second read...*/
	val = (uint32_t)phy_read( phy, (uint32_t)MII_BMSR ); /* %RELAX<SYNCHRONe_C_Code_10.7> necessary for the variable to be uint32 */
	
	if((val & (uint32_t)BMSR_LSTATUS) == (uint32_t)BMSR_LSTATUS)
	{
		ret = TRUE;
	}
	else
	{
		ret = FALSE;
	}
	
	return ret;
}