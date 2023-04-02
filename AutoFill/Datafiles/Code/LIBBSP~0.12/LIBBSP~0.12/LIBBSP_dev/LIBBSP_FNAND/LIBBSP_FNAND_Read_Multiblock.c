/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Read_Multiblock.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Read v_NbrBlock block (512 bytes per block) in memory with a DMA transfer. This function is non-blocking.
 * Data are read from v_SectorAddr to v_SectorAddr + v_Length.
 * Parameters : v_SectorAddr -> Address to start in FNAND memory
 *              p_Data       -> Pointer on data reception
 *              v_Length     -> Length (number) of block to read.
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_Read_Multiblock(const uint32_t v_SectorAddr, uint32_t* const p_Data, const uint32_t v_NbrBlock) /* %RELAX<SYNCHRONe_C_Code_8.18> p_Data is output */
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;

   P_LIBBSP_FNAND_Op->CMD = C_FNAND_READ_MULTIPLE_BLOCK;
   P_LIBBSP_FNAND_Op->DATA_ADDR = (uint32_t)p_Data; /* %RELAX<SYNCHRONe_C_Code_11.1> need to give the address of buffer for the controller to use it */
   P_LIBBSP_FNAND_Op->BLK_LEN = v_NbrBlock;
   P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_TRAN_IP;

   if((P_LIBBSP_FNAND_StatusCard->B.READY_FOR_DATA != 0x00ul) &&
              (P_LIBBSP_FNAND_Host->PRSSTAT.B.DLA == 0x00ul))
   {
     if(P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE == (uint32_t)E_LIBBSP_FNAND_CARD_STATE_TRAN) /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */
     {
        /* Set BlockCount */
        v_Error = SetBlockCount(v_NbrBlock);
        if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
        {
           P_LIBBSP_FNAND_Host->BLKATTR.B.BLKCNT = v_NbrBlock;
           P_LIBBSP_FNAND_Host->DSADDR = (uint32_t)p_Data; /* %RELAX<SYNCHRONe_C_Code_11.1> need to give the address of buffer for the controller to use it */

           v_Cmd.CMD_ARG = v_SectorAddr;

           v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_READ_MULTIPLE_BLOCK; /* CMD18 - READ_MULTIPLE_BLOCK  */

           v_Cmd.CMD_PARAM.B.CMDTYP = C_FNAND_NORMAL_COMMAND;  /* Normal command */
           v_Cmd.CMD_PARAM.B.DPSEL  = 0x01ul;                  /* Data Present */
           v_Cmd.CMD_PARAM.B.CICEN  = 0x01ul;                  /* Command check disable */
           v_Cmd.CMD_PARAM.B.CCCEN  = 0x01ul;                  /* Command CRC check disable */
           v_Cmd.CMD_PARAM.B.RSPTYP = C_FNAND_R1_RESPONSE;     /* Response type R1 (48 bits) */
           v_Cmd.CMD_PARAM.B.MSBSEL = C_FNAND_MULTI_BLOCK;     /* Multiple block select */
           v_Cmd.CMD_PARAM.B.DTDSEL = C_FNAND_READ_CMD;        /* Data transfer direction : Read */
           v_Cmd.CMD_PARAM.B.AC12EN = 0x01ul;                  /* Auto CMD12 enable */
           v_Cmd.CMD_PARAM.B.BCEN   = 0x01ul;                  /* Block count enable. */
           v_Cmd.CMD_PARAM.B.DMAEN  = 0x01ul;                  /* DMA enable */

           v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R1_R1B_RSP, C_FNAND_T_10_US); /* Start transmission */
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
