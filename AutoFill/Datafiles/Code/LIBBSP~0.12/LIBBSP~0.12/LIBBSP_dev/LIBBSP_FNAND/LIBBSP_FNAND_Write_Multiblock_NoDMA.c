/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Write_Multiblock_NoDMA.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Write v_Length block (512 bytes per block) in memory without DMA.
 * Data are written from v_SectorAddr to v_SectorAddr + v_Length.
 * Parameters : (uint32_t)  v_SectorAddr -> Address to start in FNAND memory
 *              (uint32_t*) p_Data       -> Pointer on data to send
 *              (uint32_t)  v_NbrBlock   -> Number of blocks to write.
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP Write_Multiblock_NoDMA(const uint32_t v_SectorAddr, const uint32_t* const p_Data, const uint32_t v_NbrBlock)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;

   uint32_t v_i = 0ul;

   P_LIBBSP_FNAND_Op->CMD = C_FNAND_WRITE_MULTIPLE_BLOCK;
   P_LIBBSP_FNAND_Op->DATA_ADDR = (uint32_t)p_Data; /* %RELAX<SYNCHRONe_C_Code_11.1> need to give the address of buffer for the controller to use it */
   P_LIBBSP_FNAND_Op->BLK_LEN = v_NbrBlock;

   if((P_LIBBSP_FNAND_StatusCard->B.READY_FOR_DATA == 0x00ul) || (P_LIBBSP_FNAND_Host->PRSSTAT.B.DLA == 0x01ul))
   {
      return (E_LIBBSP_FNAND_CARD_NOT_READY);
   }
   if(P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE != (uint32_t)E_LIBBSP_FNAND_CARD_STATE_TRAN) /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */
   {
      return (E_LIBBSP_FNAND_BAD_STATE);
   }
   P_LIBBSP_FNAND_Host->IRQSTATEN.B.BWRSEN = 0x01ul; /* Unmask buffer write ready interrupt */

   v_Error = SetBlockCount(v_NbrBlock);
   if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
   {
      P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_TRAN_IP;

      v_Cmd.CMD_ARG = v_SectorAddr;

      v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_WRITE_MULTIPLE_BLOCK; /* CMD24 - WRITE_BLOCK  */

      v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
      v_Cmd.CMD_PARAM.B.DPSEL  = 0x01ul;                 /* Data Present */
      v_Cmd.CMD_PARAM.B.CICEN  = 0x01ul;                 /* Command check enable */
      v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                 /* Command CRC check enable */
      v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1_RESPONSE;    /* Response type R1 (48 bits) */
      v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_MULTI_BLOCK;    /* Multiple block select */
      v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD;      /* Data transfer direction : Write */
      v_Cmd.CMD_PARAM.B.AC12EN = 0x00ul;                 /* Auto CMD12 disable */
      v_Cmd.CMD_PARAM.B.BCEN   = 0x01ul;                 /* Block count enable */
      v_Cmd.CMD_PARAM.B.DMAEN  = 0x00ul;                 /* DMA disable */

      v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_10_US); /* Start transmission */
      if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
      {
         if((v_Error == E_LIBBSP_FNAND_NO_ERROR) &&
           ((P_LIBBSP_FNAND_StatusCard->R & C_FNAND_MASK_ERR_RW) == 0x00ul))
         {
            do
            {
               if((P_LIBBSP_FNAND_Host->IRQSTAT.R & C_FNAND_IRQSTAT_MASK_ERROR) != 0x00ul)
               {
                  v_Error = LIBBSP_FNAND_StopTransmission();
                  P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_TRAN_FAILED;
                  break;
               }
               if(P_LIBBSP_FNAND_Host->IRQSTAT.B.BWR != 0x00ul)
               {
                  Wait(1ul);
                  P_LIBBSP_FNAND_Host->DATPORT = *(p_Data + v_i); /* %RELAX<SYNCHRONe_C_Code_17.4> p_Data buffer size is unknown at compile time and cannot be used as an array */
                  v_i++;
               }
            }while(P_LIBBSP_FNAND_Host->IRQSTAT.B.TC == 0x00ul);
         }
         else
         {
            v_Error = E_LIBBSP_FNAND_CMD_REJECTED;
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
   P_LIBBSP_FNAND_Host->IRQSTATEN.B.BWRSEN = 0x00ul; /* Mask buffer write ready interrupt */

   return (v_Error);
}

/*==== END =============================================================================*/
