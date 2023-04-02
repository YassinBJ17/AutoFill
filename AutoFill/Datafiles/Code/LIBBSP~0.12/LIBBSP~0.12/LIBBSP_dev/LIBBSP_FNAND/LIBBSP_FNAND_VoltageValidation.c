/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_VoltageValidation.h"
#include "LIBBSP_FNAND_SendCommand.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Send CMD1 - Voltage validation procedure
 * Parameters : None
 * Return : TE_LIBBSP_FNAND_INIT_CARD
 */
TE_LIBBSP_FNAND_INIT_CARD VoltageValidation(void)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_INIT_CARD v_Error = E_LIBBSP_FNAND_CARD_OK;
   TE_LIBBSP_FNAND_ERROR_OP v_ErrorCmd;

   uint32_t v_nbrRetry = C_FNAND_OPCOND_MAX_RETRIES;
   uint32_t v_nbrError = C_FNAND_OPCOND_MAX_ERROR;
   uint32_t v_OCR_Reg = 0ul;

   /* Command 1 - SEND_OP_COND */
   v_Cmd.CMD_ARG = C_FNAND_CARD_OP_COND; /* Send block & voltage capabilities */

   v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_SEND_OP_COND;   /* CMD1 - SEND_OP_COND */
   v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
   v_Cmd.CMD_PARAM.B.DPSEL  = 0x00ul;                 /* No Data Present */
   v_Cmd.CMD_PARAM.B.CICEN  = 0x00ul;                 /* Command check disable */
   v_Cmd.CMD_PARAM.B.CCCEN  = 0x00ul;                 /* Command CRC check disable */
   v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R3_RESPONSE;    /* Response type R3 (48 bits) */
   v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;   /* Single block select */
   v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD;      /* Data transfer direction : Write */
   v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
   v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                 /* Block count disable */
   v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                 /* DMA disable */

   do
   {
      v_ErrorCmd = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R3_R4_R6_RSP, C_FNAND_T_200_US);
      if(v_ErrorCmd == E_LIBBSP_FNAND_NO_ERROR)
      {
         v_OCR_Reg = P_LIBBSP_FNAND_Host->CMDRSP0;
      }
      else
      {
         v_nbrError--;
      }
      v_nbrRetry--;
      Wait(C_FNAND_T_10_US);
   }while((v_nbrRetry > 0ul) && (v_nbrError > 0ul) && (v_OCR_Reg != C_FNAND_CARD_OCR_READY));


   if((v_nbrRetry == 0ul) || (v_nbrError == 0ul))
   {
      v_Error = E_LIBBSP_FNAND_CARD_ERR_VOLTAGE_VALID;
   }
   else
   {
      /* Do Nothing */
   }

   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
