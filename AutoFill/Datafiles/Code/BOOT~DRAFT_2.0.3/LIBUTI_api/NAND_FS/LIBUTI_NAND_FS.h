#ifndef _LIBUTI_NAND_FS_
#define _LIBUTI_NAND_FS_

#if defined(__RTRT__)
#define __attribute__(x_dummy)
#endif

#include "LIBMCP_Types.h"

#define C_NAND_FS_SIZE 0x200    /* Size of the filesystem with the header(4 bytes) */
#define C_NAND_FS_MAX_ZONE 10	/* Maximum number of zone without any subzone */
#define C_NAND_FS_LEN_ZONE_ID 8	/* Length of the zone name (zone_id field) */

typedef enum
{
	E_NAND_FS_INIT_OK,			/* (No error) One filesystem has been successfully loaded from MRAM */
	E_NAND_FS_ERROR_RST_FS,		/* (Error) The CRC verification has failed, the filesystem has been reset (all to 0) and should be recreated */
	E_NAND_FS_ERROR_BAD_ADDR,	/* (Fatal error) The address of the first filesystem is 0 */
	E_NAND_FS_ERROR_MRAM_READ	/* (Fatal error) Unable to read in MRAM */
} TE_NAND_FS_INIT;

typedef enum
{
	E_NAND_FS_UPDATE_OK,      /* (No error) Filesystem has been successfully updated */
	E_NAND_FS_NO_MEM_SPACE,   /* (Fatal error) Zone has not enough memory */
	E_NAND_FS_ZONE_NOT_FOUND  /* (Fatal error) Zone was not found in the filesystem */
} TE_NAND_FS_UPDATE;

typedef struct
{
	uint8_t  zoneID[C_NAND_FS_LEN_ZONE_ID]; /* Unique ID of the area */
	uint64_t addrStart;   /* Sector number for the area start */
	uint64_t addrEnd;	  /* Sector number for the area end */
	boolean_t way;		  /* Loopback : if TRUE the filesystem loop on the zone when the memory space allocated is full */
	uint64_t margin;	  /* Margin in number of sectors between each data write (minimum 1) */
	uint32_t lastSubZone; /* Last subzone written (used only if nbrSubZone > 1) - Must be set to 0 if unused - value is in [0; nbrSubZone-1] */
	uint32_t nbrSubZone;  /* Number of subzones (minimum 1) */
} __attribute__((packed)) TS_NAND_FS_ZONE; /* Size: 32 bytes */

typedef struct
{
	uint64_t address1; /* Sector number */
	uint64_t size1;    /* Number of sectors */
	uint64_t address2; /* Sector number */
	uint64_t size2;    /* Number of sectors */
} __attribute__((packed)) TS_NAND_FS_RW;

extern TE_NAND_FS_INIT LIBUTI_NAND_FS_Init(uint8_t* const p_RamFS, const uint32_t p_MramFS1, const uint32_t p_MramFS2);
extern boolean_t LIBUTI_NAND_FS_Check( const uint16_t v_CRCRead );
extern boolean_t LIBUTI_NAND_FS_Format(const uint16_t v_nbrZoneToCreate, const TS_NAND_FS_ZONE* const p_TabZoneToCreate);
extern boolean_t LIBUTI_NAND_FS_Reset(const uint8_t* const v_ZoneID, const uint32_t v_SubZone);
extern uint32_t LIBUTI_NAND_FS_Info(uint32_t* const p_NbrZone, TS_NAND_FS_ZONE const **pp_TabZoneFS);
extern boolean_t LIBUTI_NAND_FS_NextSubZone(const uint8_t* const p_ZoneID);
extern TE_NAND_FS_UPDATE LIBUTI_NAND_FS_Update(const uint8_t* const p_ZoneID, const uint64_t v_Size, TS_NAND_FS_RW* const p_AddrNAND);
extern boolean_t LIBUTI_NAND_FS_Commit(void);
extern boolean_t LIBUTI_NAND_FS_Read(const uint8_t* const p_ZoneID, const uint32_t v_subZone, TS_NAND_FS_RW* const p_AddrNAND);
extern TE_NAND_FS_INIT LIBUTI_NAND_FS_DrvInit(const uint8_t* const p_RamFS, const uint32_t p_MramFS1, const uint32_t p_MramFS2);
extern uint8_t* LIBUTI_NAND_FS_Get_FS( void );

#endif