/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_SendCID.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Get the CID register from the memory. Memory should be in STBY state.
 * Parameters :(uint32_t*) p_CID -> Pointer on uint32_t array of 4 elements
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP SendCID(uint32_t p_CID[C_FNAND_CID_BUFFER_SIZE]) /* %RELAX<SYNCHRONe_C_Code_8.18> p_CID is output */
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;
   uint32_t v_i;

   P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_NO_TRAN;
   P_LIBBSP_FNAND_Op->CMD = C_FNAND_SEND_CID;

   if(P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE == (uint32_t)E_LIBBSP_FNAND_CARD_STATE_STBY) /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */
   {
      /* Command 10 - SEND_CID */
      v_Cmd.CMD_ARG = (C_FNAND_RCA << 16) | 0x0000ul;

      v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_SEND_CID;       /* CMD10 - SEND_CID */
      v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
      v_Cmd.CMD_PARAM.B.DPSEL  = 0x00ul;                 /* No Data Present */
      v_Cmd.CMD_PARAM.B.CICEN  = 0x00ul;                 /* Command check disable */
      v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                 /* Command CRC check enable */
      v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R2_RESPONSE;    /* Response type R2 (136 bits) */
      v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;   /* Single block select */
      v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_READ_CMD;       /* Data transfer direction : Read */
      v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
      v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                 /* Block count disable */
      v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                 /* DMA disable */
      v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R2_RSP, C_FNAND_T_1_MS);
      if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
      {
         for(v_i = 0ul; v_i < C_FNAND_CID_BUFFER_SIZE; v_i++)
         {
           p_CID[v_i] = P_LIBBSP_FNAND_Op->CMD_RSP[v_i];
         }
      }
      else
      {
         /* Nothing to do */
      }
   }
   else
   {
      v_Error = E_LIBBSP_FNAND_BAD_STATE;
   }
   return (v_Error);
}

/*==== END =============================================================================*/
