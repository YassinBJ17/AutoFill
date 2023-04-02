/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_UpdateStatus.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Public function
 * Check the internal eSDHC register to determine if the card is ready for a new command.
 * Parameters : None
 * Return : (boolean_t) TRUE if memory is ready for a new command, FALSE otherwise.
 */
boolean_t LIBBSP_FNAND_UpdateStatus(void)
{
   boolean_t v_Status;

   if(P_LIBBSP_FNAND_Op->CMD == C_FNAND_NO_COMMAND)
   {
      /* Return ready for next command */
      (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
      return (TRUE);
   }
   /* Check if last command was correctly executed */
   if(P_LIBBSP_FNAND_Status->COMMAND == FALSE)
   {
      return (FALSE);
   }
   if(P_LIBBSP_FNAND_Status->TRANSFER == E_LIBBSP_FNAND_NO_TRAN)
   {
      /* Return ready for next command */
      (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
      P_LIBBSP_FNAND_Op->DATA_ADDR = 0ul;
      return (TRUE);
   }
   if((P_LIBBSP_FNAND_Host->IRQSTAT.B.TC == 0x00ul) &&
   ((P_LIBBSP_FNAND_Host->IRQSTAT.R & C_FNAND_IRQSTAT_MASK_ERROR) == 0x00ul))
   {
      /* Transfer in progress */
      P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_TRAN_IP;
      v_Status = FALSE;
      /* Return transfer in progress */
   }
   else if(((P_LIBBSP_FNAND_Host->IRQSTAT.R & C_FNAND_IRQSTAT_MASK_ERROR) != 0x00ul) &&
            (P_LIBBSP_FNAND_Host->IRQSTAT.B.TC == 0x00ul))
   {
      /* Transfer failed */
      P_LIBBSP_FNAND_Op->DATA_ADDR = P_LIBBSP_FNAND_Host->DSADDR;
      P_LIBBSP_FNAND_Op->BLK_LEN = P_LIBBSP_FNAND_Host->BLKATTR.B.BLKCNT;
      P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_TRAN_FAILED;
      /* Return error during last transfer */
      v_Status = FALSE;
   }
   else if((P_LIBBSP_FNAND_Host->IRQSTAT.B.TC != 0x00ul) && (P_LIBBSP_FNAND_Host->PRSSTAT.B.DLA == 0x00ul))
   {
      P_LIBBSP_FNAND_Host->IRQSTAT.B.TC = 0x01ul;
      (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
      P_LIBBSP_FNAND_Op->DATA_ADDR = 0ul;
      v_Status = TRUE;
   }
   else
   {
      v_Status = FALSE;
   }

   return (v_Status);
}

/*==== END =============================================================================*/
