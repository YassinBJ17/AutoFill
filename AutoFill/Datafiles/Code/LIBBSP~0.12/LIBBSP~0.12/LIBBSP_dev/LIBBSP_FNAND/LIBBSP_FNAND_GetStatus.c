/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_GetStatus.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Public function
 * Get the current memory status. This function can be called at any time without interrupt card operations.
 * Update the global structure field : P_LIBBSP_FNAND_Status->StatusCard
 * Parameters : None
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_GetStatus(TU_LIBBSP_FNAND_STATUSCARD* const v_CardStatus)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;

   const uint32_t v_Timeout = C_FNAND_T_200_US;

   P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_NO_TRAN;
   P_LIBBSP_FNAND_Op->CMD = C_FNAND_SEND_STATUS;

   v_Cmd.CMD_ARG = (C_FNAND_RCA << 16) | 0x0000ul;

   v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_SEND_STATUS;    /* CMD13 - SET_RELATIVE_ADDR */

   v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
   v_Cmd.CMD_PARAM.B.DPSEL  = 0x00ul;                 /* No Data Present */
   v_Cmd.CMD_PARAM.B.CICEN  = 0x01ul;                 /* Command check enable */
   v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                 /* Command CRC check enable */
   v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1_RESPONSE;    /* Response type R1 (48 bits) */
   v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;   /* Single block select */
   v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_READ_CMD;       /* Data transfer direction : Read */
   v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
   v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                 /* Block count disable */
   v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                 /* DMA disable */

   v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, v_Timeout); /* Start transmission */

   v_CardStatus->R = P_LIBBSP_FNAND_Host->CMDRSP0; /* Update status card */

   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
