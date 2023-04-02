/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_SelectCard.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Select the card to send point-to-point command (ac or adtc command). With argument equal to 0 this function unselect the card.
 * Parameters : (uint32_t) v_AddrCard : RCA card or 0.
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP SelectCard(const uint32_t v_AddrCard)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;

   P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_NO_TRAN;
   P_LIBBSP_FNAND_Op->CMD = C_FNAND_SELECT_CARD;

   /* Command 7 - Select/Deselect card */
   v_Cmd.CMD_ARG = (v_AddrCard << 16) | 0x0000ul;

   v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_SELECT_CARD; /* CMD7 - Select/Deselect card  */


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

   v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_200_US); /* Start transmission */

   Wait(C_FNAND_T_5_US);
   (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);

   return (v_Error);
}

/*==== END =============================================================================*/
