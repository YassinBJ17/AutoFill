/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ECCMEM_H
#define LIBBSP_ECCMEM_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/
#define C_ECCMEM_ERROR_INJ_LO_MASK 0x1ul
#define C_ECCMEM_SBE_REG_VALUE 0x00FF0000ul
#define C_ECCMEM_NB_ECC_INJ 32ul
#define C_ECCMEM_NB_MBU_INJ 1ul
#define C_ECCMEM_MBU_ERROR_INJ 0x3ul

/*==== Types ===========================================================================*/

typedef enum {
   E_LIBBSP_ECCMEM_VALID_ADDR = 0,
   E_LIBBSP_ECCMEM_INVALID_ADDR =  1

} TE_LIBBSP_ECCMEM_AddrStatus;

/*typedef enum {*/
/*   E_LIBBSP_ECCMEM_MBU_ONLY_EN = 0x4,*/
/*   E_LIBBSP_ECCMEM_SEU_ONLY_EN = 0x8,*/
/*   E_LIBBSP_ECCMEM_MBU_SEU_EN = 0,*/
/*   E_LIBBSP_ECCMEM_MBU_SEU_DIS = 0xc*/
/*} TE_LIBBSP_ECCMEM_SeuMbuEn;*/
/* defined in kcg_types.h */

/*typedef enum {*/
/*   E_LIBBSP_ECCMEM_MBU_ONLY_IT = 0x8,*/
/*   E_LIBBSP_ECCMEM_SEU_ONLY_IT = 0x4,*/
/*   E_LIBBSP_ECCMEM_MBU_SEU_IT = 0xc,*/
/*   E_LIBBSP_ECCMEM_MBU_SEU_IT_DIS = 0*/
/*} TE_LIBBSP_ECCMEM_SeuMbuIt;*/
/* defined in kcg_types.h */

/*typedef enum { */
/*   E_LIBBSP_ECCMEM_SEU_OK = 0, */
/*   E_LIBBSP_ECCMEM_SEU_WRONG_NB = 1, */
/*   E_LIBBSP_ECCMEM_SEU_THRESH_EXCEED = 2, */
/*   E_LIBBSP_ECCMEM_MBU_NOT_DETECTED = 3 */
/*} TE_LIBBSP_ECCMEM_SeuStatus; */
/* defined in kcg_types.h */

typedef union
{
    uint32_t R;
    struct
    {
        uint32_t reserved1		    :8;
        uint32_t SBET   		    :8; //SBE threshold
        uint32_t reserved2		    :8;
        uint32_t SBEC   		    :8; //SBE counter
    } ErrSBE;

    struct
    {
        uint32_t reserved1		    :28;
        uint32_t MBU_error_detect   :1; //MBU error bit detect
        uint32_t SBE_error_detect   :1; //SBE error bit detect
        uint32_t reserved2		    :2;
    } ErrDetect;

    struct
    {
        uint32_t reserved1		    :23;
        uint32_t Err_inj_en         :1; //Error injection enable
        uint32_t reserved2		    :8;
    } ErrInjEn;

} TU_ECCMEMReg;


typedef struct
{
    uint32_t ddr_data_err_inject_hi;
    uint32_t ddr_data_err_inject_lo;
    TU_ECCMEMReg ddr_err_inject;
    uint32_t spare1[5];
    uint32_t ddr_capture_data_hi;
    uint32_t ddr_capture_data_lo;
    uint32_t ddr_capture_ecc;
    uint32_t spare2[5];
    TU_ECCMEMReg ddr_err_detect;
    uint32_t ddr_err_disable;
    uint32_t ddr_err_int_en;
    uint32_t ddr_capture_attributes;
    uint32_t ddr_capture_address;
    uint32_t ddr_capture_ext_address;
    TU_ECCMEMReg ddr_err_sbe;
}TS_LIBBSP_ECCMEM_DDRRegisters;

typedef struct
{
    uint32_t l2_err_inj_hi;
    uint32_t l2_err_inj_lo;
    TU_ECCMEMReg l2_err_inj_ctl;
    uint32_t spare1[5];
    uint32_t l2_capt_data_hi;
    uint32_t l2_capt_data_lo;
    uint32_t l2_capt_ecc;
    uint32_t spare2[5];
    TU_ECCMEMReg l2_err_det;
    uint32_t l2_err_disable;
    uint32_t l2_err_int_en;
    uint32_t l2_err_attr;
    uint32_t l2_err_addr_lo;
    uint32_t l2_err_addr_hi;
    TU_ECCMEMReg l2_err_ctl;
}TS_LIBBSP_ECCMEM_L2SRAMRegisters;

/*==== Variables========================================================================*/

extern volatile TS_LIBBSP_ECCMEM_DDRRegisters * const V_EccmemDdrRegs;
extern volatile TS_LIBBSP_ECCMEM_L2SRAMRegisters * const V_EccmemL2SRAMRegs;

/*==== Services ========================================================================*/

extern void LIBBSP_ECCMEM_InitializeDDR(const TE_LIBBSP_ECCMEM_SeuMbuEn v_SeuMbuEn,
		                                const TE_LIBBSP_ECCMEM_SeuMbuIt v_SeuMbuIT, const uint8_t v_SeuThresh );

extern TE_LIBBSP_ECCMEM_SeuStatus LIBBSP_ECCMEM_PostDDR(const uint32_t * const DDR_data_Addr);
extern void LIBBSP_ECCMEM_GetCounterDDR(uint8_t * const NbSeu, TE_LIBBSP_ECCMEM_SeuStatus * const v_ret);

extern void LIBBSP_ECCMEM_InitializeL2S( const TE_LIBBSP_ECCMEM_SeuMbuEn v_SeuMbuEn,
		                                 const TE_LIBBSP_ECCMEM_SeuMbuIt v_SeuMbuIT, const uint8_t v_SeuThresh );

extern TE_LIBBSP_ECCMEM_SeuStatus LIBBSP_ECCMEM_PostL2S(const uint32_t * const L2S_data_Addr);
extern void LIBBSP_ECCMEM_GetCounterL2S(uint8_t * const NbSeu, TE_LIBBSP_ECCMEM_SeuStatus * const v_ret);

/*==== END =============================================================================*/
#endif /* LIBBSP_ECCMEM_H */
