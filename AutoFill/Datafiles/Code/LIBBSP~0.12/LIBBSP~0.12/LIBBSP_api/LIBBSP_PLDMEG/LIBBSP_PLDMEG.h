/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_PLDMEG_H
#define LIBBSP_PLDMEG_H

#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/

#define C_LIBBSP_PLDMEG_UNUSED_REG 2
/*==== Types ===========================================================================*/
typedef enum {
   E_LIBBSP_PLDMEG_VALID_ADDR = 0,
   E_LIBBSP_PLDMEG_INVALID_ADDR =  1

} TE_LIBBSP_PLDMEG_AddrStatus;


typedef enum {
   E_LIBBSP_PLDMEG_GLOBAL_STATUS = 0,
   E_LIBBSP_PLDMEG_SEU_MONITORING_1 = 1,
   E_LIBBSP_PLDMEG_SEU_MONITORING_2 = 2,
   E_LIBBSP_PLDMEG_SEU_MONITORING_3 = 3,
   E_LIBBSP_PLDMEG_IF_CPU_STATUS = 4,
   E_LIBBSP_PLDMEG_ENVM_STATUS = 5,
   E_LIBBSP_PLDMEG_IDA_STATUS = 6,
   E_LIBBSP_PLDMEG_HPMS_RESET = 7,
   E_LIBBSP_PLDMEG_CNT_CORRECTABLE_ERROR = 8
} TE_LIBBSP_PLDMEG_Register;

typedef enum {
    E_LIBBSP_PLDMEG_INITIALIZATION = 0,
    E_LIBBSP_PLDMEG_OPERATIONAL = 1,
    E_LIBBSP_PLDMEG_HRG_CALIBRATION = 2,
    E_LIBBSP_PLDMEG_IMU_CALIBRATION_RS_DL = 3,
    E_LIBBSP_PLDMEG_IMU_CALIBRATION_RS_CAL = 4
} TE_LIBBSP_PLDMEG_RegSelectMode;

typedef union
{
    uint32_t v_reg;
    struct
    {
    	uint32_t seu_mbu_err : 1;
    	uint32_t cpu_if_err : 1;
    	uint32_t nvm_err : 1;
    	uint32_t reserved1 : 6;
    	uint32_t ida_err : 1;
    	uint32_t reserved2 : 2;
    	uint32_t rs_dl : 1;
    	uint32_t rs_cal : 1;
    	uint32_t reserved3 : 2;
    	uint32_t a429_tx4_err : 1;
    	uint32_t a429_tx3_err : 1;
    	uint32_t a429_tx2_err : 1;
    	uint32_t a429_tx1_err : 1;
    	uint32_t reserved4 : 1;
    	uint32_t a429_rx11_err : 1;
    	uint32_t a429_rx10_err : 1;
    	uint32_t a429_rx9_err : 1;
    	uint32_t a429_rx8_err : 1;
    	uint32_t a429_rx7_err : 1;
    	uint32_t a429_rx6_err : 1;
    	uint32_t a429_rx5_err : 1;
    	uint32_t a429_rx4_err : 1;
    	uint32_t a429_rx3_err : 1;
    	uint32_t a429_rx2_err : 1;
    	uint32_t a429_rx1_err : 1;
    } GlobalStatus;

    struct
    {
    	uint32_t NotImplemented : 32;
    } SeuMonitoring1;

    struct
    {
    	uint32_t NotImplemented : 32;
    } SeuMonitoring2;

    struct
    {
    	uint32_t NotImplemented : 32;
    } SeuMonitoring3;

    struct
    {
    	uint32_t parity_error : 1;
    	uint32_t addr_error : 1;
    	uint32_t acc_error : 1;
    	uint32_t timeout_error : 1;
    	uint32_t overload_error : 1;
    	uint32_t reserved : 19;
    	uint32_t error_counter : 8;
    } IfCpuStatus;

    struct
    {
    	uint32_t nvm_checking_error : 1;
    	uint32_t nvm_loading_error : 1;
    	uint32_t nvm_checking_rdy : 1;
    	uint32_t nvm_loading_rdy : 1;
    	uint32_t reserved : 28;
    } EnvmStatus;

    struct
    {
    	uint32_t reserved : 31;
    	uint32_t hpms_reset : 1;
    } HPMSReset;

    struct 
    {
        uint32_t cnt_correctable_error : 32;
    } CNT_CORRECTABLE_ERROR;

} TU_LIBBSP_PLDMEG_RegValue;


typedef struct
{
    uint32_t reg_id_version;
    uint32_t reg_select;
    uint32_t reg_ctrl_regs;
    uint32_t spare1;
    uint32_t reg_global_status;
    uint32_t reg_cnt_correctable_error;
    uint32_t spare2[C_LIBBSP_PLDMEG_UNUSED_REG];
    /*uint32_t reg_seu_monitoring_1;*/
    /*uint32_t reg_seu_monitoring_2;*/
    /*uint32_t reg_seu_monitoring_3;*/              
    uint32_t reg_if_cpu_status;
    uint32_t reg_envm_status;
    uint32_t reg_ida_status;
    uint32_t spare3;  
    uint32_t reg_sync_acc_delay;
    uint32_t req_irq_rtc_sel;
    uint32_t reg_rtc_en;
    uint32_t reg_hpms_reset;
}TS_LIBBSP_PLDMEG_GlobalRegisters;


/*typedef struct
{
    uint32_t* p_PLDMEG_BaseAddress;
}TS_LIBBSP_PLDMEG_BaseAddress;*/

/*==== Variables========================================================================*/


/*==== Services ========================================================================*/

extern void LIBBSP_PLDMEG_GetVersion(uint32_t * const v_version);
extern void LIBBSP_PLDMEG_GetStatus( const TE_LIBBSP_PLDMEG_Register v_RegName, TU_LIBBSP_PLDMEG_RegValue * const v_RegValue);
extern void LIBBSP_PLDMEG_SetHpmsReset(const boolean_t v_Value);
extern void LIBBSP_PLDMEG_RegSelect(const TE_LIBBSP_PLDMEG_RegSelectMode v_Mode);

/*==== END =============================================================================*/
#endif /* LIBBSP_PLDCMP_H */
