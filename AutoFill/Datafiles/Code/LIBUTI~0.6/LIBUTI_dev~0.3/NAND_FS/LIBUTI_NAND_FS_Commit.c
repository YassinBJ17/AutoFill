/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Commit.h"
#include "LIBUTI_CRC.h"
#include "LIBBSP_MRAM.h"
#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/*
 * ---- LIBUTI_NAND_FS_Commit ----
 * Save the filesystem (in RAM) in the MRAM.
 * parameters : void
 * return : (boolean_t) TRUE if the filesystem is successfully write in MRAM, FALSE otherwise.
 */
boolean_t LIBUTI_NAND_FS_Commit(void)
{
	boolean_t v_Result;
	TE_LIBBSP_MRAM_ErrorCode v_MramError;
    uint16_t v_CRCComputed;
	
	/*{{RELAX <SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_10.7> Pointer converted just to be put in parameter of LIBUTI_CRC_ComputeCRC16*/
	/*or LIBBSP_MRAM_Write. Those finction need to be used for differente type of prt so (uint8_t*) is used in parameters*/
	v_CRCComputed = LIBUTI_CRC_ComputeCRC16((uint8_t*)P_NAND_FS_Header, (uint32_t)C_NAND_FS_SIZE); 
	LIBBSP_MRAM_Write((uint32_t)V_NAND_FS_MRAM_Addr.FS1_addr, C_SIZE_CRC, (uint8_t*)&v_CRCComputed, &v_MramError);
	
	if(v_MramError == E_LIBBSP_MRAM_OK)
	{
        LIBBSP_MRAM_Write((uint32_t)V_NAND_FS_MRAM_Addr.FS1_addr+C_SIZE_CRC, (uint32_t)C_NAND_FS_SIZE, (uint8_t*)P_NAND_FS_Header, &v_MramError);
	}
	/*}}RELAX<SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_10.7> */
    if(v_MramError == E_LIBBSP_MRAM_OK)
	{
		v_Result = TRUE;
	}
	else
	{
		/* Error : Failed to write FS in MRAM */
		v_Result = FALSE;
	}
	
	if( (V_NAND_FS_MRAM_Addr.FS2_addr != 0ul) && (v_MramError == E_LIBBSP_MRAM_OK) )
	{
		/*{{RELAX <SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_10.7> Pointer converted just to be put in parameter of LIBUTI_CRC_ComputeCRC16*/
		/*or LIBBSP_MRAM_Write. Those finction need to be used for differente type of prt so (uint8_t*) is used in parameters*/
        LIBBSP_MRAM_Write((uint32_t)V_NAND_FS_MRAM_Addr.FS2_addr, C_SIZE_CRC, (uint8_t*)&v_CRCComputed, &v_MramError);
        if(v_MramError == E_LIBBSP_MRAM_OK)
        {
            LIBBSP_MRAM_Write((uint32_t)V_NAND_FS_MRAM_Addr.FS2_addr+C_SIZE_CRC, (uint32_t)C_NAND_FS_SIZE, (uint8_t*)P_NAND_FS_Header, &v_MramError);
		}
		/*}}RELAX<SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_10.7> */
        if(v_MramError == E_LIBBSP_MRAM_OK)
		{
			v_Result = TRUE;
		}
		else
		{
			/* Error : Failed to write FS in MRAM */
			v_Result = FALSE;
		}
	}
	else
	{
		/* Nothing to do */
	}
	return v_Result;
}
/*==== END =============================================================================*/
