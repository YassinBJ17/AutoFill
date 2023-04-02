/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_MemoryWearInfo.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Public function
 * Get informations on the memory health status. Memory should be in TRAN state.
 * Parameters : - (TE_LIBBSP_FNAND_HEALTH_CMD) v_HealthCmd -> possible values :
 *                        E_LIBBSP_FNAND_BAD_BLOCKS (default) : The BAD BLOCK COUNTERS command indicates the total number of bad blocks (initial and later bad blocks) in the device.
 *                                                    The BAD BLOCK COUNTERS command also retrieves the total number of remaining spare blocks that allow the bad blocks to be remapped in the device.
 *                        E_LIBBSP_FNAND_ERASE_COUNTERS : The BLOCK ERASE COUNTERS command returns the minimum, maximum, and average total of block erases in the MLC and the SLC areas.
 *              - (uint32_t*) p_WearStatus -> Pointer on uint32_t array of 3 elements where to save data.
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_MemoryWearInfo(const TE_LIBBSP_FNAND_HEALTH_CMD v_HealthCmd, uint32_t * const p_WearStatus)
{
   TS_LIBBSP_FNAND_CMD v_Cmd = {0};
   TE_LIBBSP_FNAND_ERROR_OP v_Error;
   boolean_t v_Status;

   uint32_t v_Msb;
   uint32_t v_Lsb;

   P_LIBBSP_FNAND_Op->CMD = C_FNAND_GENERAL_CMD;

   if((P_LIBBSP_FNAND_StatusCard->B.READY_FOR_DATA != 0x00ul) && (P_LIBBSP_FNAND_Host->PRSSTAT.B.DLA == 0x00ul))
   {
      if(P_LIBBSP_FNAND_StatusCard->B.CURRENT_STATE == (uint32_t)E_LIBBSP_FNAND_CARD_STATE_TRAN) /* %RELAX<SYNCHRONe_C_Code_10.7> enum convertion to uint32_t do not imply loss of precision */
      {
         /* Set BlockSize */
         v_Error = SetBlockSize(C_FNAND_BLOCK_SIZE); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: constant is uint32 */
         if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
         {
            P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_TRAN_IP;
            P_LIBBSP_FNAND_Host->DSADDR = (uint32_t)&p_WearStatus; /* %RELAX<SYNCHRONe_C_Code_11.1> need to give the address of buffer for the controller to use it */
            /* Command 56 - GEN_CMD */
            if(v_HealthCmd == E_LIBBSP_FNAND_ERASE_COUNTERS)
            {
               v_Cmd.CMD_ARG = 0x21ul; /* 0b00100001 */
            }
            else
            {
               v_Cmd.CMD_ARG = 0x11ul; /* 0b00010001 */
            }

            v_Cmd.CMD_PARAM.B.CMDINX = C_FNAND_GENERAL_CMD;    /* CMD56 - GEN_CMD */
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

            v_Error = SendCommand(&v_Cmd, E_LIBBSP_FNAND_R2_RSP, C_FNAND_T_1_MS);

            if(v_Error == E_LIBBSP_FNAND_NO_ERROR)
            {
               do
               {
                  Wait(5ul);
                  v_Status = LIBBSP_FNAND_UpdateStatus();
               }while((v_Status == FALSE) && (P_LIBBSP_FNAND_Status->TRANSFER != E_LIBBSP_FNAND_TRAN_FAILED));

               if(P_LIBBSP_FNAND_Status->TRANSFER != E_LIBBSP_FNAND_TRAN_FAILED)
               {
/* {{RELAX<SYNCHRONe_C_Code_17.4> Reordering buffer values to match expected output */
                  v_Msb = p_WearStatus[1] & 0xFFul;
                  v_Lsb = (p_WearStatus[1] >> 8) & 0xFFul;
                  p_WearStatus[2] = (v_Msb << 8) | v_Lsb;

                  v_Msb = (p_WearStatus[0] >> 16) & 0xFFul;
                  v_Lsb = p_WearStatus[0] >> 24;
                  p_WearStatus[1] = (v_Msb << 8) | v_Lsb;

                  v_Msb = p_WearStatus[0] & 0xFFul;
                  v_Lsb = (p_WearStatus[0] >> 8) & 0xFFul;
                  p_WearStatus[0] = (v_Msb << 8) | v_Lsb;
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
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
