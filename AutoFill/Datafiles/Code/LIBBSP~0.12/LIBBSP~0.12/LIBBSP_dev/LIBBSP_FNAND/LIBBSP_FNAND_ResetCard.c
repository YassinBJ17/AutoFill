/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_ResetCard.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Send CMD0 to reset the card in IDLE State.
 * Parameters : None
 * Return : TE_LIBBSP_FNAND_INIT_CARD
 */
TE_LIBBSP_FNAND_INIT_CARD ResetCard(void)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_INIT_CARD v_Error = E_LIBBSP_FNAND_CARD_OK;
   TE_LIBBSP_FNAND_ERROR_OP v_ErrorCmd;

   /* Command 0 - GO_IDLE_STATE */
   v_Cmd.CMD_ARG = 0x00ul;


   v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_GO_IDLE_STATE;  /* CMD0 - GO_IDLE_STATE */
   v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
   v_Cmd.CMD_PARAM.B.DPSEL  = 0x00ul;                 /* No Data Present */
   v_Cmd.CMD_PARAM.B.CICEN  = 0x00ul;                 /* Command check disable */
   v_Cmd.CMD_PARAM.B.CCCEN  = 0x00ul;                 /* Command CRC check disable */
   v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_NO_RESPONSE;    /* No Response */
   v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;   /* Single block select */
   v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD;      /* Data transfer direction : Write */
   v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
   v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                 /* Block count disable */
   v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                 /* DMA disable */
   v_ErrorCmd = SendCommand(&v_Cmd, E_LIBBSP_FNAND_NO_RSP, C_FNAND_T_1_MS);
   if(v_ErrorCmd != E_LIBBSP_FNAND_NO_ERROR)
   {
      v_Error = E_LIBBSP_FNAND_CARD_ERR_RESET_CARD;
   }
   else
   {
      /* Do Nothing */
   }

   Wait(C_FNAND_T_100_US);
   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
