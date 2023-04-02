/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Write_Multiblock.h"
#include "LIBBSP_FNAND_Configure.h"
#include "LIBBSP_FNAND_SendCommand.h"
#include "LIBBSP_FNAND_SetBlockCount.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Write v_NbrBlock block (512 bytes per block) in memory with a DMA transfer. This function is non-blocking.
 * Data are written from v_SectorAddr to v_SectorAddr + v_Length.
 * Parameters : (uint32_t)  v_SectorAddr -> Address to start in FNAND memory
 *              (uint32_t*) p_Data       -> Pointer on data to send
 *              (uint32_t)  v_NbrBlock   -> Number of blocks to write.
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP Write_Multiblock(const uint32_t v_SectorAddr, const uint32_t* const p_Data, const uint32_t v_NbrBlock)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;

   P_LIBBSP_FNAND_Op->CMD = C_FNAND_WRITE_MULTIPLE_BLOCK;
   P_LIBBSP_FNAND_Op->DATA_ADDR = (uint32_t)p_Data; /* %RELAX<SYNCHRONe_C_Code_11.1> need to give the address of buffer for the controller to use it */
   P_LIBBSP_FNAND_Op->BLK_LEN = v_NbrBlock;

   if((P_LIBBSP_FNAND_StatusCard->B.READY_FOR_DATA) &&
              (P_LIBBSP_FNAND_Host->PRSSTAT.B.DLA == 0x00ul))
   {
     if(P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE == (uint32_t)E_LIBBSP_FNAND_CARD_STATE_TRAN) /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */
     {
         v_Error = SetBlockCount(v_NbrBlock);
         if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
         {
            P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_TRAN_IP;
            P_LIBBSP_FNAND_Host->DSADDR = (uint32_t)p_Data; /* %RELAX<SYNCHRONe_C_Code_11.1> need to give the address of buffer for the controller to use it */

            v_Cmd.CMD_ARG = v_SectorAddr;

            v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_WRITE_MULTIPLE_BLOCK; /* CMD25 - WRITE_MULTIPLE_BLOCK  */

            v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND; /* Normal command */
            v_Cmd.CMD_PARAM.B.DPSEL  = 0x01ul;                 /* Data Present */
            v_Cmd.CMD_PARAM.B.CICEN  = 0x01ul;                 /* Command check disable */
            v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                 /* Command CRC check disable */
            v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1_RESPONSE;    /* Response type R1 (48 bits) */
            v_Cmd.CMD_PARAM.B.MSBSEL = 0x01ul;                 /* Multiple block select */
            v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_WRITE_CMD;      /* Data transfer direction : Write */
            v_Cmd.CMD_PARAM.B.AC12EN = 0x01ul;                 /* Auto CMD12 enable */
            v_Cmd.CMD_PARAM.B.BCEN   = 0x01ul;                 /* Block count enable. */
            v_Cmd.CMD_PARAM.B.DMAEN  = 0x01ul;                 /* DMA enable */

            v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_15_US); /* Start transmission */
            if((v_Error == E_LIBBSP_FNAND_NO_ERROR) &&
              ((P_LIBBSP_FNAND_StatusCard->R & C_FNAND_MASK_ERR_RW) != 0x00ul))
            {
               v_Error = E_LIBBSP_FNAND_CMD_REJECTED;
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
