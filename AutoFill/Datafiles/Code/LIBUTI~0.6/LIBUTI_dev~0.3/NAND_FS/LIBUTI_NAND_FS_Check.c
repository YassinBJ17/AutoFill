/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Check.h"
#include "LIBUTI_CRC.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/*
 * ---- LIBUTI_NAND_FS_Check ----
 * Check the CRC of the filesystem currently in RAM. 
 * parameters : 
 *          - v_CRCRead (uint16_t): CRC value read in MRAM
 * return : (boolean_t) TRUE if the CRC computed (on the filesystem) is equal to the CRC in parameter, otherwise false.
 */
boolean_t LIBUTI_NAND_FS_Check( const uint16_t v_CRCRead )
{
	uint16_t v_CRC_Compute;
	boolean_t v_correctFS;
    
    
	v_CRC_Compute = LIBUTI_CRC_ComputeCRC16((uint8_t*)P_NAND_FS_Header, (uint32_t)C_NAND_FS_SIZE); /* %RELAX<SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_10.7> Pointer converted just to be put in parameter of LIBUTI_CRC_ComputeCRC16*/
	
    if(P_NAND_FS_Header->nbrZone > (uint16_t)C_NAND_FS_MAX_ZONE)
    {
        v_correctFS = FALSE;
    }
    else
    {
        if (v_CRC_Compute == v_CRCRead)
        {
            v_correctFS = TRUE;
        }
        else
        {
            v_correctFS = FALSE;
        }
    }
    
	return (boolean_t)(v_correctFS);
}
/*==== END =============================================================================*/
