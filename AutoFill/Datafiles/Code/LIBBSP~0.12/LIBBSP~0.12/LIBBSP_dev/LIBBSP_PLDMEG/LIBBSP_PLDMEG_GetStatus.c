/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PLDMEG_GetStatus.h"

/*==== Definitions =====================================================================*/

/*#define C_PLDMEG_GLOBAL_STATUS 0x10*/
/*#define C_PLDMEG_SEU_MONITORING_1 0x14*/
/*#define C_PLDMEG_SEU_MONITORING_2 0x18*/
/*#define C_PLDMEG_SEU_MONITORING_3 0x1C*/
/*#define C_PLDMEG_IF_CPU_STATUS 0x20*/
/*#define C_PLDMEG_ENVM_STATUS 0x24*/

/*==== Variables =======================================================================*/

//TS_LIBBSP_PLDMEG_BaseAddress PLDMEG_Interface;

/*==== Services ========================================================================*/
void LIBBSP_PLDMEG_GetStatus(const TE_LIBBSP_PLDMEG_Register v_RegName, TU_LIBBSP_PLDMEG_RegValue * const v_RegValue)
{
   /*volatile uint32_t* p_reg;*/
   
   switch (v_RegName)
   {
      case E_LIBBSP_PLDMEG_GLOBAL_STATUS:
         v_RegValue->v_reg = V_PldMegRegs->reg_global_status;
         break;
      case E_LIBBSP_PLDMEG_SEU_MONITORING_1:
         v_RegValue->v_reg = 0ul; /* currently not defined in the PLD mapping */
         break;
      case E_LIBBSP_PLDMEG_SEU_MONITORING_2:
         v_RegValue->v_reg = 0ul; /* currently not defined in the PLD mapping */
         break;
      case E_LIBBSP_PLDMEG_SEU_MONITORING_3:
         v_RegValue->v_reg = 0ul; /* currently not defined in the PLD mapping */
         break;
      case E_LIBBSP_PLDMEG_IF_CPU_STATUS:
         v_RegValue->v_reg = V_PldMegRegs->reg_if_cpu_status;
         break;
      case E_LIBBSP_PLDMEG_ENVM_STATUS:
         v_RegValue->v_reg = V_PldMegRegs->reg_envm_status;
         break;
      case E_LIBBSP_PLDMEG_IDA_STATUS:
         v_RegValue->v_reg = V_PldMegRegs->reg_ida_status;
         break;
      case E_LIBBSP_PLDMEG_HPMS_RESET:
         v_RegValue->v_reg = V_PldMegRegs->reg_hpms_reset;
         break;
      case E_LIBBSP_PLDMEG_CNT_CORRECTABLE_ERROR:
         v_RegValue->v_reg = V_PldMegRegs->reg_cnt_correctable_error;
         break;
      default:
         /*DO NOTHING*/
         break;
   }
}

/*==== END =============================================================================*/
