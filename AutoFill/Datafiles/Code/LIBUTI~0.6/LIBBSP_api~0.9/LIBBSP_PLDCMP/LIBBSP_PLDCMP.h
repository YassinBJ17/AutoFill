/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2017                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_PLDCMP_H
#define LIBBSP_PLDCMP_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/


/*==== Types ===========================================================================*/
typedef enum {
   E_LIBBSP_PLDCMP_VALID_ADDR = 0,
   E_LIBBSP_PLDCMP_INVALID_ADDR =  1

} TE_LIBBSP_PLDCMP_AddrStatus;

/*typedef enum { */
/*   E_LIBBSP_PLDCMP_COMP_STATUS = 0, */
/*   E_LIBBSP_PLDCMP_BOARD_STATUS =  1, */
/*   E_LIBBSP_PLDCMP_COMP_ERR_STATUS =  2, */
/*   E_LIBBSP_PLDCMP_NB_REGISTERS =  3 */
/*} TE_LIBBSP_PLDCMP_Register; */
/* defined in kcg_types.h */


typedef union
{
    uint32_t v_reg;

    struct
    {

    	uint32_t nvm_error : 1;
    	uint32_t parity_error : 1;
    	uint32_t addr_error : 1;
    	uint32_t acc_error : 1;
    	uint32_t timeout_error : 1;
    	uint32_t overload_error : 1;
    	uint32_t comp_wd_rst : 1;
    	uint32_t spare : 25;
    } CompErrStatus;

} TU_LIBBSP_PLDCMP_RegValue;


/*typedef struct
{
    uint32_t* p_PLDCMP_BaseAddress;
}TS_PLDCMP_BaseAddress;*/

typedef struct
{
    uint32_t jtag_connect_ref;
    uint32_t jtag_connect_user;
    uint32_t boot_mode;
    uint32_t comp_err_status;
    uint32_t reg_dso_sysfail_ctrl_ref;
    uint32_t reg_dso_sysfail_ctrl_user;	
    uint32_t sw_auth_ref;
    uint32_t sw_auth_user;
    uint32_t internal_ram_wren;
}TS_LIBBSP_PLDCMP_GlobalRegisters;

/*==== Variables========================================================================*/
//extern TS_PLDCMP_BaseAddress PLDCMP_Interface;
extern volatile TS_LIBBSP_PLDCMP_GlobalRegisters * const V_PldCmpRegs;

/*==== Services ========================================================================*/

extern void LIBBSP_PLDCMP_GetCmpErrors(TU_LIBBSP_PLDCMP_RegValue * const v_RegValue);
extern void LIBBSP_PLDCMP_WriteFailDisc(const uint32_t v_GLB_User);
extern void LIBBSP_PLDCMP_ConnectJTAG(const uint32_t v_GLB_User);
extern void LIBBSP_PLDCMP_FlashWriteEnable(const uint32_t v_GLB_User);

/*==== END =============================================================================*/
#endif /* LIBBSP_PLDCMP_H */
