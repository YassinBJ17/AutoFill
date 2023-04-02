/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Init.h"
#include "LIBUTI_NAND_FS_Init_Reset.h"
#include "LIBBSP_MRAM.h"
#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* 
 * ---- LIBUTI_NAND_FS_Init ----
 * Check Load the FileSystem in ram from the MRAM. 
 * parameters :
 * 		- p_RamFS   (uint8_t*)  : address where save the filesystem in RAM
 *		- p_MramFS1 (uint32_t*) : address where the filesystem is saved in MRAM
 *		- p_MramFS2 (uint32_t*) : OPTIONAL if different from 0, address where the copy of the filesystem is saved in MRAM
 * return : (TE_NAND_FS_INIT) E_NAND_FS_INIT_OK if one filesystem has successfully loaded from MRAM (and CRC is good).
 *							  E_NAND_FS_ERROR_RST_FS if no filesystem has been loaded. The filesystem has been reset (all to 0) and the user can recreate it with LIBUTI_NAND_FS_Format().
 *							  E_NAND_FS_ERROR_BAD_ADDR p_MramFS1 is equal to 0.
 *							  E_NAND_FS_ERROR_MRAM_READ unable to read in MRAM.
 */
TE_NAND_FS_INIT LIBUTI_NAND_FS_Init(uint8_t* const p_RamFS, const uint32_t p_MramFS1, const uint32_t p_MramFS2) /* %RELAX<SYNCHRONe_C_Code_8.18> p_RamFS is output */
{
	TE_NAND_FS_INIT v_Error;
	boolean_t v_Result;
	TE_LIBBSP_MRAM_ErrorCode v_MramError;
    uint16_t v_CRCRead;
	
	if(p_MramFS1 != 0ul)
	{
		P_NAND_FS_Header = (TS_LIBUTI_NAND_FS_HEADER*)p_RamFS; /* %RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> Pointer converion: generic ptr -> ptr to specific structure*/
		P_addrFSRam = (uint8_t*)(p_RamFS + C_SIZE_HEADER_FS); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_17.4> Explitice computation of an adresse,can't be done in an another way*/
		
		V_NAND_FS_MRAM_Addr.FS1_addr = p_MramFS1;
		/* Lecture en MRAM @p_MramFS1 */
        LIBBSP_MRAM_Read(p_MramFS1, C_SIZE_CRC, (uint8_t*)&v_CRCRead, &v_MramError);/* %RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> Pointer converion to use &v_CRCRead in paramater of LIBBSP_MRAM_Read*/
        if(v_MramError == E_LIBBSP_MRAM_OK)
		{
            LIBBSP_MRAM_Read(p_MramFS1+C_SIZE_CRC, (uint32_t)C_NAND_FS_SIZE, p_RamFS, &v_MramError);
        }
		if(v_MramError == E_LIBBSP_MRAM_OK)
		{
			v_Result = LIBUTI_NAND_FS_Check(v_CRCRead);
			if(p_MramFS2 != 0ul) /* Two filesystem in MRAM */
			{
				V_NAND_FS_MRAM_Addr.FS2_addr = p_MramFS2;
				if(v_Result) /* The first filesystem is ok */
				{
					v_Error = E_NAND_FS_INIT_OK;
				}
				else /* Two filesystem but the first is corrupted*/
				{
					/* Lecture en MRAM @p_MramFS2 */
                    LIBBSP_MRAM_Read(p_MramFS2, C_SIZE_CRC, (uint8_t*)&v_CRCRead, &v_MramError); /* %RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> Pointer converion to use &v_CRCRead in paramater of LIBBSP_MRAM_Read*/
                    if(v_MramError == E_LIBBSP_MRAM_OK)
                    {
                        LIBBSP_MRAM_Read(p_MramFS2+C_SIZE_CRC, (uint32_t)C_NAND_FS_SIZE, p_RamFS, &v_MramError);
                    }
					if(v_MramError == E_LIBBSP_MRAM_OK)
					{
						v_Result = LIBUTI_NAND_FS_Check(v_CRCRead);
						
						/* If Bad CRC for FS1 and FS2 -> Reset filesystem */
						LIBUTI_NAND_FS_Init_Reset(v_Result, &v_Error);

					}
					else
					{
						/* Error : Unable to read in MRAM */
						v_Error = E_NAND_FS_ERROR_MRAM_READ;
					}
				}
			}
			else /* Only one FS in MRAM */
			{
				V_NAND_FS_MRAM_Addr.FS2_addr = 0ul;
				
				/* If Bad CRC and p_MramFS2 is 0 -> Reset filesystem */
				LIBUTI_NAND_FS_Init_Reset(v_Result, &v_Error);
			}
		}
		else
		{
			/* Error : Unable to read in MRAM */
			v_Error = E_NAND_FS_ERROR_MRAM_READ;
		}
	}
	else
	{
		/* Error : address FS1 is 0 */
		v_Error = E_NAND_FS_ERROR_BAD_ADDR;
	}
	return (v_Error);
}
/*==== END =============================================================================*/
