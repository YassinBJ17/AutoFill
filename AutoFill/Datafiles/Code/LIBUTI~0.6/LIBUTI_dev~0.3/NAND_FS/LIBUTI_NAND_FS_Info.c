/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Info.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/*
 * ---- LIBUTI_NAND_FS_Info ----
 * Get the list of zones and the number of zone in the filesystem.
 * parameters :
 * 		- p_NbrZone (uint32_t*) : pointer on the number of zone in the filesystem.
 * 		- pp_TabZoneFS (TS_NAND_FS_ZONE**) : pointer on an array of TS_NAND_FS_ZONE pointer with C_NAND_FS_MAX_ZONE elements.
 * return : (uint32_t) size (in bytes) of the filesystem (without the header).
 */
uint32_t LIBUTI_NAND_FS_Info(uint32_t* const p_NbrZone, TS_NAND_FS_ZONE const **pp_TabZoneFS)
{
	uint16_t i;
	uint32_t v_NextZone = 0;
    
	*p_NbrZone =((uint32_t) P_NAND_FS_Header->nbrZone);
    
	for(i = (uint16_t)0; i < P_NAND_FS_Header->nbrZone; i++)
	{
		/*{{RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_17.4>*/
		/*For 11.1/10.7 line 36 : Explicit computation of the next P_addrFSRam, can't be done in an other way.*/
		/*						  Conversion of address to a pointer to specific structure*/
		/*For 17.4 line 36/37 : pp_TabZoneFS point to the adresse of the first zone. So pp_TabZoneFS is used*/
		/*						as a buffer (with array indexing) with the adress of the zones in it. Overflow is avoid by for line 29*/
		*(pp_TabZoneFS + i) = (TS_NAND_FS_ZONE*)(P_addrFSRam + v_NextZone); 
		v_NextZone += C_SIZE_ZONE_FS + ( ((*(pp_TabZoneFS + i))->nbrSubZone) * 2ul * sizeof(uint64_t) );
		
		/*}}RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_17.4> */
	}
	return v_NextZone;
}
/*==== END =============================================================================*/
