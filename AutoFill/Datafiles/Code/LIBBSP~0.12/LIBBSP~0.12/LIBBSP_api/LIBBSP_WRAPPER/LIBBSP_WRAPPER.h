/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_WRAPPER_H
#define LIBBSP_WRAPPER_H

#include "LIBMCP_Types.h"
#include "LIBBSP_A429.h"
#include "LIBBSP_ETR.h"
#include "LIBBSP_ETSEC.h"
#include "LIBBSP_IMU.h"
#include "LIBBSP_PLDCMP.h"
#include "LIBBSP_PLDMEG.h"
#include "LIBBSP_SHM.h"

/*==== Types ===========================================================================*/


/*==== Variables========================================================================*/



/*==== Services ========================================================================*/

extern void LIBBSP_A429_LaunchWrapper(const TE_LIBBSP_A429_TxLine        devID, /*IN*/
                                      TE_LIBBSP_A429_TxErrorCode * const v_Error_Code, /*OUT*/
                                      boolean_t * const                  OverflowFIFO, /*OUT*/
                                      boolean_t * const                  OverflowCMD, /*OUT*/
                                      uint32_t * const                   Reg_value); /*OUT*/
extern void LIBBSP_A429_WriteWrapper(const TE_LIBBSP_A429_TxLine        devID, /*IN*/
                                     const uint32_t                     size, /*IN*/
                                     const uint32_t * const             buffer, /*IN*/
                                     TE_LIBBSP_A429_TxErrorCode * const v_Error_Code, /*OUT*/
                                     uint32_t * const                   count, /*OUT*/
                                     boolean_t * const                  OverflowFIFO, /*OUT*/
                                     boolean_t * const                  OverflowCMD, /*OUT*/
                                     uint32_t * const                   Reg_value); /*OUT*/
extern void LIBBSP_ETSEC_GetPhyStateWrapper(const TE_LIBBSP_ETSEC_Network         network,
                                            TE_LIBBSP_ETSEC_NetworkStatus * const ret,
                                            kcg_bool * const                      phyState);
extern void LIBBSP_IMU_GetAdditionalReadDataWrapper(const uint32_t    NbDataToRead,
                                                    float64_t * const AdditionnalReadData);
extern void LIBBSP_IMU_ProgAdditionalReadDataWrapper(const uint32_t CurrentCycle);
extern void LIBBSP_SHM_GetBoardStatus(TS_LIBBSP_SHM_BoardStatus * const BoardStatus,
                                      uint32_t * const                  v_regValue);
extern void LIBBSP_PLDCMP_GetCompErrorStatus(boolean_t * const v_overload_error,
                                      boolean_t * const        v_parity_error,
                                      boolean_t * const        v_addr_error,
                                      boolean_t * const        v_acc_error,
                                      boolean_t * const        v_timeout_error,
                                      uint32_t * const         v_CompErrorStatus);
extern void LIBBSP_SHM_GetCompStatus(TS_LIBBSP_SHM_CompStatus * const CompStatus,
                                     uint32_t * const                 v_regValue);
extern void LIBBSP_PLDMEG_GetStatusWrapper(boolean_t * const                    seu_mbu_err,
                                           TS_LIBBSP_PLDMEG_IfCpuStatus * const cpu_if_err,
                                           boolean_t * const                    elbc_parity_error,
                                           uint32_t * const                     p_global_status,
                                           uint32_t * const                     p_if_status,
                                           uint32_t * const                     p_envm_status,
                                           uint32_t * const                     p_ida_status,
                                           uint32_t * const                     p_cnt_correctable_error);
extern uint8_t LIBBSPP_WRAPPER_ConvertUint32ToUint8 (const uint32_t p_value32);
/******************************************************************************/


#endif /* LIBBSP_WRAPPER_H*/


