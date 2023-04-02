/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Format.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/*
 * ---- FormatFS ----
 * Create new zones in the filesystem.
 * parameters :
 * 		- v_nbrZoneToCreate (uint32_t) : Number of zones to create.
 * 		- p_TabZoneToCreate (TS_NAND_FS_ZONE*) : pointer on an array of TS_NAND_FS_ZONE structure with v_nbrZoneToCreate elements.
 * return : (boolean_t) TRUE if the new zones are successfully created, FALSE otherwise (not enough memory or number of zone is reached).
 */
/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on pointer p_TabZoneToCreate is used as a buffer.*/
/*with zones to creates in it. Overflow avoid with the for instruction where i is compared to v_nbrZoneToCreate */
boolean_t LIBUTI_NAND_FS_Format(const uint16_t v_nbrZoneToCreate, const TS_NAND_FS_ZONE* const p_TabZoneToCreate)
{
	boolean_t v_Result;
	uint32_t i;
	uint32_t v_SizeTabZoneToCreate;
	uint32_t v_NbrZone;
	uint32_t v_CurrentFSsize;
	TS_NAND_FS_ZONE *p_TabZoneFS[C_NAND_FS_MAX_ZONE];
	TS_NAND_FS_ZONE *v_FSAddrToAdd;

	v_SizeTabZoneToCreate = 0ul;
	v_CurrentFSsize = LIBUTI_NAND_FS_Info(&v_NbrZone, (TS_NAND_FS_ZONE**)p_TabZoneFS);
	if( (P_NAND_FS_Header->nbrZone + v_nbrZoneToCreate) <= (uint16_t)C_NAND_FS_MAX_ZONE )
	{	
		/* Determine the size of the new zones to create */
		for(i = 0ul; i < (uint32_t)v_nbrZoneToCreate; i++)
		{
			v_SizeTabZoneToCreate = (v_SizeTabZoneToCreate + C_SIZE_ZONE_FS) + (((p_TabZoneToCreate + i)->nbrSubZone * 2ul) * sizeof(uint64_t));
		}
		
		if((v_CurrentFSsize + v_SizeTabZoneToCreate) <= C_SIZE_FS)
		{
			v_FSAddrToAdd = (TS_NAND_FS_ZONE*)(P_addrFSRam + v_CurrentFSsize); /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion because explicit computation of adress */
			
			for(i = 0ul; i < (uint32_t)v_nbrZoneToCreate; i++)
			{
				*(v_FSAddrToAdd) = p_TabZoneToCreate[i];
				v_FSAddrToAdd = (TS_NAND_FS_ZONE*)((uint32_t)v_FSAddrToAdd + C_SIZE_ZONE_FS + ( ((p_TabZoneToCreate + i)->nbrSubZone * 2ul) * sizeof(uint64_t) ) ); /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion because explicit computation of adress */
			}
			P_NAND_FS_Header->nbrZone += v_nbrZoneToCreate;
			v_Result = TRUE;
		}
		else
		{
			/* Error : Not enough space in memory */
			v_Result = FALSE;
		}
	}
	else
	{
		/* Error  : Too much zone to create */
		v_Result = FALSE;
	}
	return v_Result;
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
