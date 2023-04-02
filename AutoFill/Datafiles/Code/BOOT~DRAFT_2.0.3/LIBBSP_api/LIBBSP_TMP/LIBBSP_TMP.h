#ifndef _LIBBSP_TMP_H_
#define _LIBBSP_TMP_H_

#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/

/*==== Types ===========================================================================*/
/*typedef enum
{
	E_LIBBSP_TMP_TMP1,
	E_LIBBSP_TMP_TMP2,
	E_LIBBSP_TMP_TMP3
} TE_LIBBSP_TMP_Number;*/
/* defined in kcg_types.h */

typedef enum
{
	E_LIBBSP_TMP_VALID_ADDR,
	E_LIBBSP_TMP_INVALID_ADDR
} TE_LIBBSP_TMP_AddrStatus;


typedef struct
{
    uint32_t reg_tmp_1;
    uint32_t reg_tmp_2;
    uint32_t reg_tmp_3;
    uint32_t reg_tmp_cnt;
}TS_LIBBSP_TMP_Registers;


/*==== Variables ===========================================================================*/

/*extern uint32_t * V_address_TMP1;
extern uint32_t * V_address_TMP2;
extern uint32_t * V_address_TMP3;
extern uint32_t * V_address_TMP_CNT;*/

extern uint32_t V_LIBBSP_TMP_tmp1;
extern uint32_t V_LIBBSP_TMP_tmp2;
extern uint32_t V_LIBBSP_TMP_tmp3;

extern uint64_t V_LIBBSP_TMP_tmp_cnt;
extern uint32_t V_LIBBSP_TMP_last_tmp_cnt;

extern volatile TS_LIBBSP_TMP_Registers * const V_TMPRegs;

/*==== Services ========================================================================*/

extern TE_LIBBSP_TMP_AddrStatus LIBBSP_TMP_Configure( void );
extern uint32_t LIBBSP_TMP_GetTMPCounter( void );
extern void LIBBSP_TMP_GetTMP( const TE_LIBBSP_TMP_Number v_tmp, boolean_t * const pa_new, uint32_t * const pa_value);
extern void LIBBSP_TMP_GetTimeMs(uint32_t * const v_Time);
/*uint32_t LIBBSP_TMP_GetTimeMs(void);*/

/*==== END =============================================================================*/
#endif /* _LIBBSP_TMP_H_ */
