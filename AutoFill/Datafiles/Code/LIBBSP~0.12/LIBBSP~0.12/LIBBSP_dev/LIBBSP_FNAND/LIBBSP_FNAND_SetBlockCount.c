/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_SetBlockCount.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* Private function
 * Send CMD23 to tell to the memory the quantity block which will be send in the next transfer command.
 * Perform a Reliable Write : See JEDEC standard page 56.
 * Parameters : (uint32_t) v_NbrBlock ->  Block quantity which will be send
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP SetBlockCount(const uint32_t v_NbrBlock)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;

   v_Cmd.CMD_ARG = 0x80000000ul | v_NbrBlock; /* Set block length to v_NbrBlock bytes */

   v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_SET_BLOCK_COUNT; /* CMD23 - SET_BLOCKLEN  */

   v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
   v_Cmd.CMD_PARAM.B.DPSEL  = 0x00ul;                 /* No Data Present */
   v_Cmd.CMD_PARAM.B.CICEN  = 0x01ul;                 /* Command check disable */
   v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                 /* Command CRC check disable */
   v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1_RESPONSE;    /* Response type R1 (48 bits) */
   v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;   /* Single block select */
   v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD;      /* Data transfer direction : Write */
   v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
   v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                 /* Block count disable. */
   v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                 /* DMA enable */

   v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_15_US); /* Start transmission */
   if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
   {
      P_LIBBSP_FNAND_Host->BLKATTR.B.BLKCNT = v_NbrBlock;
   }
   else
   {
      /* Nothing to do */
   }

   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
