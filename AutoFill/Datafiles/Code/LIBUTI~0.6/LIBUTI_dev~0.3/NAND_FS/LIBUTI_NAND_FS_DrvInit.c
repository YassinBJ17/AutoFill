/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_DrvInit.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* 
 * ---- LIBUTI_NAND_FS_DrvInit ----
 * Set Global Variables for use of driver NAND_FS without loading FS from MRAM. 
 * parameters :
 * 		- p_RamFS   (uint8_t*)  : address where save the filesystem in RAM
 *		- p_MramFS1 (uint32_t*) : address where the filesystem is saved in MRAM
 *		- p_MramFS2 (uint32_t*) : OPTIONAL if different from 0, address where the copy of the filesystem is saved in MRAM
 * return : (TE_NAND_FS_INIT) E_NAND_FS_INIT_OK if one filesystem has successfully loaded from MRAM (and CRC is good).
 *							  E_NAND_FS_ERROR_RST_FS if no filesystem has been loaded. The filesystem has been reset (all to 0) and the user can recreate it with LIBUTI_NAND_FS_Format().
 *							  E_NAND_FS_ERROR_BAD_ADDR p_MramFS1 is equal to 0.
 *							  E_NAND_FS_ERROR_MRAM_READ unable to read in MRAM.
 */
TE_NAND_FS_INIT LIBUTI_NAND_FS_DrvInit(const uint8_t* const p_RamFS, const uint32_t p_MramFS1, const uint32_t p_MramFS2)
{
	TE_NAND_FS_INIT v_Error;
    
	if(p_MramFS1 != 0ul)
	{
		/*{{RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_17.4>*/
		/*Conversion of prt p_RamFS from generic pointer to pointer to specific structure*/
		/* Explicit computation of P_addrFSRam, can't be done in an other way*/
        P_NAND_FS_Header = (TS_LIBUTI_NAND_FS_HEADER*)p_RamFS;
        P_addrFSRam = (uint8_t*)(p_RamFS + C_SIZE_HEADER_FS);
		/*}}RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_17.4> */
        V_NAND_FS_MRAM_Addr.FS1_addr = p_MramFS1;
        
    	if(p_MramFS2 != 0ul) /* Two filesystem in MRAM */
		{	
			V_NAND_FS_MRAM_Addr.FS2_addr = p_MramFS2;
        }
        else /* Only one FS in MRAM */
		{
			V_NAND_FS_MRAM_Addr.FS2_addr = 0ul;
        }
        
        if(P_NAND_FS_Header->nbrZone > (uint16_t)C_NAND_FS_MAX_ZONE)
        {
            v_Error = E_NAND_FS_ERROR_RST_FS;
        }
        else
        {
            v_Error = E_NAND_FS_INIT_OK;
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
