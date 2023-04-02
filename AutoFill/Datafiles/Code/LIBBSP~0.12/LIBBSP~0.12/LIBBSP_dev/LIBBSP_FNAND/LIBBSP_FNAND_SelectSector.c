/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_SelectSector.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Send CMD35 & CMD36 to specifies to the card the sectors which will been deleted
 * CMD35 : Send the start sector to delete
 * CMD36 : Send the last sector to delete (including this)
 * Parameters : (uint32_t) v_StartAddr -> Sector address to start
 *              (uint32_t) v_length    -> number of sectors to erase
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP SelectSector(const uint32_t v_StartAddr, const uint32_t v_NbrBlock)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;

   v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
   v_Cmd.CMD_PARAM.B.DPSEL  = 0x00ul;                 /* No Data Present */
   v_Cmd.CMD_PARAM.B.CICEN  = 0x01ul;                 /* Command check enable */
   v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                 /* Command CRC check enable */
   v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1_RESPONSE;    /* Response type R1 (48 bits) */
   v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;   /* Single block select */
   v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD;      /* Data transfer direction : Write */
   v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
   v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                 /* Block count disable */
   v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                 /* DMA disable */

   /* Command 35 - ERASE_GROUP_START */
   v_Cmd.CMD_ARG = v_StartAddr; /* Start address */
   v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_ERASE_GROUP_START; /* CMD35 - ERASE_GROUP_START  */

   v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_10_US); /* Start transmission */
   if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
   {
      /* Command 36 - ERASE_GROUP_END */
      v_Cmd.CMD_ARG = v_StartAddr + (v_NbrBlock - 1ul); /* End address = Start address + length - 1 */
      v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_ERASE_GROUP_END; /* CMD36 - ERASE_GROUP_END  */
      v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_10_US); /* Start transmission */
   }
   else
   {
      /* Do nothing */
   }
   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
