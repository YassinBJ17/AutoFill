/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_CardIdentification.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Send CMD2 & 3 - Card Identification Procedure
 * Parameters : None
 * Return : TE_LIBBSP_FNAND_INIT_CARD
 */
TE_LIBBSP_FNAND_INIT_CARD CardIdentification(void)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_ErrorCmd;
   TE_LIBBSP_FNAND_INIT_CARD v_Error = E_LIBBSP_FNAND_CARD_OK;

   v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
   v_Cmd.CMD_PARAM.B.DPSEL  = 0x00ul;                 /* No Data Present */
   v_Cmd.CMD_PARAM.B.CICEN  = 0x00ul;                 /* Command check disable */
   v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                 /* Command CRC check enable */
   v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;   /* Single block select */
   v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD;      /* Data transfer direction : Write */
   v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
   v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                 /* Block count disable */
   v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                 /* DMA disable */

   /* Command 2 - ALL_SEND_CID */
   v_Cmd.CMD_ARG = 0x00ul;
   v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_ALL_SEND_CID; /* CMD2 - ALL_SEND_CID */
   v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R2_RESPONSE; /* Response type R2 (136 bits) */
   v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_READ_CMD; /* Data transfer direction : Read */

   v_ErrorCmd = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R2_RSP, C_FNAND_T_10_MS);
   if(v_ErrorCmd == E_LIBBSP_FNAND_NO_ERROR)
   {
      /* Command 3 - SET_RELATIVE_ADDR */
      v_Cmd.CMD_ARG = (C_FNAND_RCA << 16) | 0x0000ul;
      v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_SET_RELATIVE_ADDR; /* CMD3 - SET_RELATIVE_ADDR */
      v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1_RESPONSE; /* Response type R1 (48 bits) */
      v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD; /* Data transfer direction : Write */

      v_ErrorCmd = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_200_US);
      if(v_ErrorCmd == E_LIBBSP_FNAND_NO_ERROR)
      {
         (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
      }
      else
      {
         v_Error = E_LIBBSP_FNAND_CARD_ERR_CARD_ID;
      }

   }
   else
   {
      v_Error = E_LIBBSP_FNAND_CARD_ERR_CARD_ID;
   }
   return (v_Error);
}
/*==== END =============================================================================*/
