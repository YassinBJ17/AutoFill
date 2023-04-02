/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

/*==== Definitions =====================================================================*/
#include "LIBUTI_NAND_FS_Get_FS.h"

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/*
 * ---- LIBUTI_NAND_FS_Update ----
 * Return P_NAND_FS_Header cast to (uint8_t*).
 * parameters : 
*
 * return : (uint8_t*) P_NAND_FS_Header
 */
uint8_t* LIBUTI_NAND_FS_Get_FS( void )
{

   /* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> P_NAND_FS_Header is cast to (uint8_t*) juste to bo used as parameter in funcions*/
   return (uint8_t*)P_NAND_FS_Header;
   /* }} RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */
}
/*==== END =============================================================================*/
