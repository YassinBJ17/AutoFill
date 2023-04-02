/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_WriteWrapper.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_A429_WriteWrapper(const TE_LIBBSP_A429_TxLine devID, /*IN*/
                              const uint32_t size, /*IN*/
                              const uint32_t * const buffer, /*IN*/
                              TE_LIBBSP_A429_TxErrorCode * const v_Error_Code, /*OUT*/
                              uint32_t * const count, /*OUT*/ /* %RELAX<SYNCHRONe_C_Code_8.18> Output used only as parameter in subfunction */
                              boolean_t * const OverflowFIFO, /*OUT*/
                              boolean_t * const OverflowCMD, /*OUT*/
                              uint32_t * const Reg_value) /*OUT*/
{
   TU_LIBBSP_A429_TxState v_ErrorState = { 0 };
   
   *v_Error_Code = LIBBSP_A429_Write(devID, size, buffer, count, &v_ErrorState);
   /*{{RELAX<SYNCHRONe_C_Code_10.7> TXOVFFIFO and TXOVFCMD is equal to 0 or 1 so there is no loss of precision on the conversion to boolean_t.*/
   *OverflowFIFO = (boolean_t)(v_ErrorState.TXSTAT.TXOVFFIFO);
   
   *OverflowCMD = (boolean_t)(v_ErrorState.TXSTAT.TXOVFCMD);
   /*}}RELAX<SYNCHRONe_C_Code_10.7> */
   *Reg_value = v_ErrorState.R;
}
/*==== END =============================================================================*/
