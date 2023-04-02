/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_SendExtCSD.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Get the Extended CSD register from the memory. Send a block (512 bytes) on data line.
 * Memory should be in TRAN state.
 * Parameters : (uint32_t*) p_ExtCSD pointer on uint32_t array of 128 elements variable.
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP SendExtCSD(uint32_t p_ExtCSD[C_FNAND_EXTCSD_BUFFER_SIZE]) /* %RELAX<SYNCHRONe_C_Code_8.18> p_ExtCSD is output */
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;
   boolean_t v_Status;
   uint32_t i;
   uint32_t swap;

   P_LIBBSP_FNAND_Op->CMD = C_FNAND_SEND_EXT_CSD;

   if((P_LIBBSP_FNAND_StatusCard->B.READY_FOR_DATA != 0x00ul) &&
              (P_LIBBSP_FNAND_Host->PRSSTAT.B.DLA == 0x00ul))
   {
      if(P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE == (uint32_t)E_LIBBSP_FNAND_CARD_STATE_TRAN) /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */
      {
         P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_TRAN_IP;
         P_LIBBSP_FNAND_Host->DSADDR = (uint32_t)p_ExtCSD; /* %RELAX<SYNCHRONe_C_Code_11.1> need to give the address of buffer for the controller to use it */
         /* CMD8 - SEND_EXT_CSD */
         v_Cmd.CMD_ARG = 0x00ul;

         v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_SEND_EXT_CSD;   /* CMD8 - SEND_EXT_CSD */
         v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
         v_Cmd.CMD_PARAM.B.DPSEL  = 0x01ul;                 /* Data Present */
         v_Cmd.CMD_PARAM.B.CICEN  = 0x01ul;                 /* Command check enable */
         v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                 /* Command CRC check enable */
         v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1_RESPONSE;    /* Response type R1 (48 bits) */
         v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;   /* Single block select */
         v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_READ_CMD;       /* Data transfer direction : Read */
         v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
         v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                 /* Block count disable */
         v_Cmd.CMD_PARAM.B.DMAEN  = 0x01ul;                 /* DMA enable */

         v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_200_US);
         if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
         {
            do
            {
               Wait(10ul);
               v_Status = LIBBSP_FNAND_UpdateStatus();
            }while((v_Status == FALSE) && (P_LIBBSP_FNAND_Status->TRANSFER != E_LIBBSP_FNAND_TRAN_FAILED));

            if(P_LIBBSP_FNAND_Status->TRANSFER == E_LIBBSP_FNAND_TRAN_FAILED)
            {
               v_Error = E_LIBBSP_FNAND_ERROR_CMD;
            }
            else
            {
               for (i = 0ul; i < (C_FNAND_EXTCSD_BUFFER_SIZE / 2ul); ++i)
               {
                  swap = p_ExtCSD[i];
                  p_ExtCSD[i] = p_ExtCSD[C_FNAND_EXTCSD_BUFFER_SIZE - i - 1ul];
                  p_ExtCSD[C_FNAND_EXTCSD_BUFFER_SIZE - i - 1ul] = swap;
               }
            }
         }
         else
         {
            v_Error = E_LIBBSP_FNAND_ERROR_CMD;
         }
      }
      else
      {
        v_Error = E_LIBBSP_FNAND_BAD_STATE;
      }
   }
   else
   {
      v_Error = E_LIBBSP_FNAND_CARD_NOT_READY;
   }
   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
