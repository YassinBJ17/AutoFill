/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_MEGIT_Conf.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_MEGIT_ItStatus LIBBSP_MEGIT_Conf(const TE_LIBBSP_MEGIT_CpuSyncSource v_CpuSyncSource,
                                           const TE_LIBBSP_MEGIT_RsSyncSource  v_RsSyncSource,
                                           const boolean_t                     v_GlobalDebugEnable,
                                           const boolean_t                     v_SyncSignalsEnable)
{
   TE_LIBBSP_MEGIT_ItStatus v_Status;
   TS_LIBBSP_MEGIT_SourceRegister v_tempSourceRegister;
   TS_LIBBSP_MEGIT_EnableRegister v_tempEnableRegister;
   
   v_Status = E_LIBBSP_MEGIT_IT_SOURCE_INVALID;
   v_tempSourceRegister.R = 0ul;
   
   if ( (E_LIBBSP_MEGIT_CPU_NO_SOURCE < v_CpuSyncSource) && (v_CpuSyncSource < E_LIBBSP_MEGIT_CPU_NB_SOURCE) ) {
      v_tempSourceRegister.TS_RegFields.cpu_rtc_sel = (uint32_t)v_CpuSyncSource;/*%RELAX<SYNCHRONe_C_Code_10.7> No loss of precision because v_CpuSyncSource [0;8] (Type enum)*/

      if ( (E_LIBBSP_MEGIT_RS_NO_SOURCE < v_RsSyncSource) && (v_RsSyncSource < E_LIBBSP_MEGIT_RS_NB_SOURCE) ) {
         v_tempSourceRegister.TS_RegFields.rs_rtc_sel = (uint32_t)v_RsSyncSource;/*%RELAX<SYNCHRONe_C_Code_10.7> No loss of precision because v_RsSyncSource [0;6] (Type enum)*/

         v_Status = E_LIBBSP_MEGIT_IT_SOURCE_VALID;
         
         V_MegItRegs->v_SyncSourcesReg.R = v_tempSourceRegister.R;
         v_tempEnableRegister.R = 0ul;
         v_tempEnableRegister.TS_RegFields.force_rtc = (uint32_t)v_GlobalDebugEnable;
         v_tempEnableRegister.TS_RegFields.cpu_rtc_en = (uint32_t)v_SyncSignalsEnable;
         V_MegItRegs->v_RtcConfReg.R = v_tempEnableRegister.R;
      }

   }

   return v_Status;
}

/*==== END =============================================================================*/
