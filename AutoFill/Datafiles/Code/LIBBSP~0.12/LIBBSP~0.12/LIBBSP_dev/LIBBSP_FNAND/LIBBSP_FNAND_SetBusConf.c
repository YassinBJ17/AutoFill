/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_SetBusConf.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Set bus configuration between the host and the memory.
 * Parameters : None
 * Return : TE_LIBBSP_FNAND_INIT_CARD
 */
TE_LIBBSP_FNAND_INIT_CARD SetBusConf(void)
{
   uint32_t v_Timeout = C_FNAND_T_5_MS;
   TU_LIBBSP_FNAND_CSD_REG v_CSD;

   TE_LIBBSP_FNAND_INIT_CARD v_Error = E_LIBBSP_FNAND_CARD_OK;
   TE_LIBBSP_FNAND_ERROR_OP v_ErrorCmd;
   TS_LIBBSP_FNAND_CMD v_Cmd;

   v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_SWITCH; /* CMD6 - SWITCH */

   v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
   v_Cmd.CMD_PARAM.B.DPSEL  = 0x00ul;                 /* No Data Present */
   v_Cmd.CMD_PARAM.B.CICEN  = 0x00ul;                 /* Command check disable */
   v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                 /* Command CRC check enable */
   v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1_RESPONSE;    /* Response type R1b (48 bits) */
   v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_SINGLE_BLOCK;   /* Single block select */
   v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD;      /* Data transfer direction : Write */
   v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
   v_Cmd.CMD_PARAM.B.BCEN   = 0x00ul;                 /* Block count disable. */
   v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                 /* DMA disable */

   v_ErrorCmd = SendCSD(&v_CSD.R[0]);
   if(v_ErrorCmd == E_LIBBSP_FNAND_NO_ERROR)
   {
      /* Check version >= 4 */
      /* Version is on [125:122] bits of the 128 bits response (R2 response) */
      if(v_CSD.B.SPEC_VERS < 0x04ul)
      {
         return (E_LIBBSP_FNAND_CARD_ERR_BUS_CONF); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
      }
      v_ErrorCmd = SelectCard((const uint32_t)C_FNAND_RCA);
      if(v_ErrorCmd == E_LIBBSP_FNAND_NO_ERROR)
      {
         /* Command 6 - SWITCH */
         v_Cmd.CMD_ARG = C_FNAND_POWERCLASS_2; /* SET Power class to 2 */
         v_ErrorCmd = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_200_US);
         if((v_ErrorCmd == E_LIBBSP_FNAND_NO_ERROR) &&
            (P_LIBBSP_FNAND_StatusCard->B.SWITCH_ERROR == 0x00ul))
         {
            do
            {
               /* Wait for card ready with 4 bits bus width */
               (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
               (void) IsElapsed(&v_Timeout);
            }while((v_Timeout > 0ul) && (P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE != (uint32_t)E_LIBBSP_FNAND_CARD_STATE_TRAN)); /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */

            /* Command 6 - SWITCH */
            v_Cmd.CMD_ARG = C_FNAND_DATABUS_WIDTH_4; /* SET Bus Width to 4 */
            v_ErrorCmd = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_200_US);
            if((v_ErrorCmd == E_LIBBSP_FNAND_NO_ERROR) &&
               (P_LIBBSP_FNAND_StatusCard->B.SWITCH_ERROR == 0x00ul))
            {
               P_LIBBSP_FNAND_Host->PROCTL.B.DTW = 0x01ul;
               do
               {
                  /* Wait for card ready with 4 bits bus width */
                  (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
                  (void) IsElapsed(&v_Timeout);
               }while((v_Timeout > 0ul) && (P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE != (uint32_t)E_LIBBSP_FNAND_CARD_STATE_TRAN)); /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */

               if(P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE == (uint32_t)E_LIBBSP_FNAND_CARD_STATE_TRAN) /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */
               {
                  /* Change clock speed according to BSIS */
                  P_LIBBSP_FNAND_Host->SYSCTL.B.SDCLKEN     = 0x00ul; /* Disable FNAND clock */
                  Wait(C_FNAND_T_10_MS); /* Wait for stabilize clock */
                  P_LIBBSP_FNAND_Host->SYSCTL.B.SDCLKFS     = 0x02ul; /* Change frequency :  base clock (166MHz) / [(SDCLKFS(4) x 2) x (DVS(1) + 1)] = 10MHz */
                  P_LIBBSP_FNAND_Host->SYSCTL.B.SDCLKEN     = 0x01ul; /* Enable FNAND clock */
                  Wait(C_FNAND_T_10_MS); /* Wait for stabilize clock */
                  P_LIBBSP_FNAND_Host->IRQSTATEN.B.DTOESEN  = 0x01ul; /* Enable Data Timeout flag */

               }
               else
               {
                  v_Error = E_LIBBSP_FNAND_CARD_ERR_BUS_CONF;
               }
            }
            else
            {
               v_Error = E_LIBBSP_FNAND_CARD_ERR_BUS_CONF;
            }
         }
         else
         {
           v_Error = E_LIBBSP_FNAND_CARD_ERR_BUS_CONF;
         }
      }
      else
      {
         v_Error = E_LIBBSP_FNAND_CARD_ERR_BUS_CONF;
      }
   }
   else
   {
      v_Error = E_LIBBSP_FNAND_CARD_ERR_BUS_CONF;
   }
   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
