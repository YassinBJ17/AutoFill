/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#include "LIBMCP_Types.h"

/*==== Types ===========================================================================*/

typedef struct
{
	TS_NAND_FS_ZONE* addrZone;
	uint64_t* addrSubZoneStart;
	uint64_t* addrSubZoneEnd;
} __attribute__((packed)) TS_NAND_FS_ADDR_ZONE;

typedef struct
{
	uint16_t nbrZone;
} __attribute__((packed)) TS_LIBUTI_NAND_FS_HEADER;

typedef struct
{
	uint32_t FS1_addr;
	uint32_t FS2_addr;
} __attribute__((packed)) TS_NAND_FS_MRAM_ADDR;