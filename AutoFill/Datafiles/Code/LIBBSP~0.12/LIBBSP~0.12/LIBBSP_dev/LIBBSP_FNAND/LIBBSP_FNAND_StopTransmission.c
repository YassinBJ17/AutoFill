/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_StopTransmission.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Public function
 * Send CMD12 to stop a transfer operation.
 * Parameters : NA
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_StopTransmission(void)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_ErrorCmd = E_LIBBSP_FNAND_NO_ERROR;

   P_LIBBSP_FNAND_Host->IRQSTAT.B.CC = 0x01ul; /* Clear Command complete */

   if((P_LIBBSP_FNAND_Op->CMD == C_FNAND_WRITE_SINGLE_BLOCK) || (P_LIBBSP_FNAND_Op->CMD == C_FNAND_WRITE_MULTIPLE_BLOCK))
   {
      v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1B_RESPONSE; /* Response type R1b (48 bits) */
   }
   else if((P_LIBBSP_FNAND_Op->CMD == C_FNAND_READ_SINGLE_BLOCK) || (P_LIBBSP_FNAND_Op->CMD == C_FNAND_READ_MULTIPLE_BLOCK))
   {
      v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1_RESPONSE; /* Response type R1 (48 bits) */
   }
   else
   {
      v_ErrorCmd = E_LIBBSP_FNAND_ERROR_STOP;
   }

   P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_NO_TRAN;
   (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);

   if((v_ErrorCmd != E_LIBBSP_FNAND_ERROR_STOP) && ((P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE == (uint32_t)E_LIBBSP_FNAND_CARD_STATE_DATA) || (P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE == (uint32_t)E_LIBBSP_FNAND_CARD_STATE_RCV)) ) /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */
   {
      P_LIBBSP_FNAND_Op->CMD = C_FNAND_STOP_TRANSMISSION;
      v_Cmd.CMD_ARG = 0x00ul;

      v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_STOP_TRANSMISSION; /* CMD12 - STOP_TRANSMISSION  */
      v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_ABORT_COMMAND;     /* Normal command */
      v_Cmd.CMD_PARAM.B.DPSEL  = 0x00ul;                    /* No Data Present */
      v_Cmd.CMD_PARAM.B.CICEN  = 0x00ul;                    /* Command check disable */
      v_Cmd.CMD_PARAM.B.CCCEN  = 0x00ul;                    /* Command CRC check disable */
      v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;      /* Single block select */
      v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD;         /* Data transfer direction : Write */
      v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                    /* Auto CMD12 disable */
      v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                    /* Block count disable. */
      v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                    /* DMA disable */

      v_ErrorCmd = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_200_US); /* Start transmission */
      if(v_ErrorCmd == E_LIBBSP_FNAND_NO_ERROR)
      {
         (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
         P_LIBBSP_FNAND_Status->COMMAND = TRUE;
      }
      else
      {
         v_ErrorCmd = E_LIBBSP_FNAND_ERROR_STOP;
      }
   }
   else
   {
      /* Nothing to do */
   }
   return v_ErrorCmd; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
