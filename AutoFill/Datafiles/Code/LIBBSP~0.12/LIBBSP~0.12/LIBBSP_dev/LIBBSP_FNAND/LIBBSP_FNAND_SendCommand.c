/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_SendCommand.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* Private function
 * Execute command received in parameter and wait the response until the timeout value.
 * Parameters : (TS_LIBBSP_FNAND_CMD)      v_Cmd         -> Command to execute
 *              (TE_LIBBSP_FNAND_RSP_TYPE) v_RspType     -> Response type expected
 *              (uint32_t)                 v_Timeout     -> Timeout value to wait before return an error.
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP SendCommand(const TS_LIBBSP_FNAND_CMD *v_Cmd, const TE_LIBBSP_FNAND_RSP_TYPE v_RspType, const uint32_t v_Timeout)
{
   TE_LIBBSP_FNAND_ERROR_OP v_CmdError = E_LIBBSP_FNAND_NO_ERROR;
   P_LIBBSP_FNAND_Status->COMMAND = FALSE;

   if(P_LIBBSP_FNAND_Host->PRSSTAT.B.CIHB == 0x00ul)
   {
      if ((v_Cmd->CMD_PARAM.B.CMDINX == C_FNAND_GO_IDLE_STATE) ||
          (v_Cmd->CMD_PARAM.B.CMDINX == C_FNAND_SEND_STATUS)   ||
          (P_LIBBSP_FNAND_Host->PRSSTAT.B.CDIHB == 0x00ul) || ((P_LIBBSP_FNAND_Host->PRSSTAT.B.CDIHB != 0x00ul) && (v_Cmd->CMD_PARAM.B.DPSEL == 0x00ul)))
      {
         P_LIBBSP_FNAND_Host->CMDARG = v_Cmd->CMD_ARG;
         P_LIBBSP_FNAND_Host->XFERTYP.R = v_Cmd->CMD_PARAM.R; /* Start transmission */
         do
         {
            (void) IsElapsed((uint32_t*)&v_Timeout);
         }while((v_Timeout > 0ul) && (P_LIBBSP_FNAND_Host->IRQSTAT.B.CC == 0x00ul));

         if(P_LIBBSP_FNAND_Host->IRQSTAT.B.CC != 0x00ul)
         {
            /* Error are on the [31:16] bits of the IRQSTAT register */
            /* Tranfert Complete has higher priority than Data TimOut Error (see 16.4.10 - eSDHC_IRQSTAT) */
            if(((P_LIBBSP_FNAND_Host->IRQSTAT.R & C_FNAND_IRQSTAT_MASK_ERROR) == 0x00ul) ||
               (P_LIBBSP_FNAND_Host->IRQSTAT.B.DTOE != 0x00ul && P_LIBBSP_FNAND_Host->IRQSTAT.B.TC != 0x00ul))
            {
               GetResponse(v_RspType);
               P_LIBBSP_FNAND_Status->COMMAND = TRUE;
               P_LIBBSP_FNAND_Host->IRQSTAT.R = 0x01ul; /* Clear *only* Command complete */
            }
            else
            {
               v_CmdError = E_LIBBSP_FNAND_ERROR_CMD;
               P_LIBBSP_FNAND_Host->IRQSTAT.B.CC = 0x01ul; /* Clear Command complete */
            }
         }
         else
         {
            v_CmdError = E_LIBBSP_FNAND_TIMEOUT_CMD;
         }

      }
      else
      {
         v_CmdError = E_LIBBSP_FNAND_DATA_LINE_BUSY;
      }
   }
   else
   {
      v_CmdError = E_LIBBSP_FNAND_CMD_LINE_BUSY;
   }

   return (v_CmdError); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
