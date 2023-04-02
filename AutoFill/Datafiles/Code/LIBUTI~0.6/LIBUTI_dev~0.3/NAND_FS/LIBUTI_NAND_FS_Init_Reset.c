/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Init_Reset.h"
#include "LIBUTI_MEM.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* 
 * ---- LIBUTI_NAND_FS_Init_Reset ----
 * Reset the filesystem if CheckCRC is KO. 
 */

void LIBUTI_NAND_FS_Init_Reset(const boolean_t CheckCRC, TE_NAND_FS_INIT * const v_Error)
{
	if(CheckCRC != FALSE)
	{
		*v_Error = E_NAND_FS_INIT_OK;
	}
	else
	{
		LIBUTI_MEM_MemSet((uint8_t*)P_NAND_FS_Header, (uint8_t)0, (uint32_t)C_NAND_FS_SIZE); /* %RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> Pointer converion to use P_NAND_FS_Header in paramater of LIBUTI_MEM_MemSet*/
		*v_Error = E_NAND_FS_ERROR_RST_FS;
	}
}