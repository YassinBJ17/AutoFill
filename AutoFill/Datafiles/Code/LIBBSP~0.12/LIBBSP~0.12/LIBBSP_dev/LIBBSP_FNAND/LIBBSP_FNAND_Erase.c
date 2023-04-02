/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Erase.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Public function
 * Erase selected sectors using TRIM option to selected by block instead of Erase Group.
 * Parameters : (uint32_t) v_StartAddr -> Sector address to start
 *              (uint32_t) v_NbrBlock  -> number of sectors to erase
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_Erase(const uint32_t v_StartAddr, const uint32_t v_NbrBlock)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;
   uint32_t v_Timeout = C_FNAND_T_1_S;

   P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_NO_TRAN;
   P_LIBBSP_FNAND_Op->CMD = C_FNAND_ERASE;


   if(P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE != (uint32_t)E_LIBBSP_FNAND_CARD_STATE_TRAN) /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */
   {
      return (E_LIBBSP_FNAND_BAD_STATE); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
   }
   v_Error = SelectSector(v_StartAddr, v_NbrBlock);

   if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
   {
      /* Secure Trim Step 1 - Use TRIM option to set erase unit as write block */
      v_Cmd.CMD_ARG = 0x80000001ul;
      /* Command 38 - ERASE */
      v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_ERASE; /* CMD38 - ERASE  */

      v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
      v_Cmd.CMD_PARAM.B.DPSEL  = 0x00ul;                 /* No Data Present */
      v_Cmd.CMD_PARAM.B.CICEN  = 0x01ul;                 /* Command check enable */
      v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                 /* Command CRC check enable */
      v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1B_RESPONSE;   /* Response type R1b (48 bits) */
      v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;   /* Single block select */
      v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD;      /* Data transfer direction : Write */
      v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
      v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                 /* Block count disable */
      v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                 /* DMA disable */

      v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_10_US); /* Start transmission */
      if((v_Error == E_LIBBSP_FNAND_NO_ERROR) &&
         (P_LIBBSP_FNAND_StatusCard->B.ERASE_SEQ_ERROR == 0x00ul))
      {
         do
         {
            (void) IsElapsed(&v_Timeout);
            (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
         }while((v_Timeout > 0ul) && (P_LIBBSP_FNAND_StatusCard->B.READY_FOR_DATA == 0x00ul));

         v_Error = SelectSector(v_StartAddr, v_NbrBlock);
         if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
         {
            /* Secure Trim Step 2 */
            v_Cmd.CMD_ARG = 0x80008000ul;
            v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_10_US); /* Start transmission */
            if((v_Error == E_LIBBSP_FNAND_NO_ERROR) &&
               (P_LIBBSP_FNAND_StatusCard->B.ERASE_SEQ_ERROR == 0x00ul))
            {
               do
               {
                  (void) IsElapsed(&v_Timeout);
                  (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
               }while((v_Timeout > 0ul) && (P_LIBBSP_FNAND_StatusCard->B.READY_FOR_DATA == 0x00ul));
            }
            else
            {
               /* Nothing to do */
            }
         }
         else
         {
           /* Nothing to do */
         }
      }
      else
      {
         /* Nothing to do */
      }
   }
   else
   {
      /* Nothing to do */
   }

   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
