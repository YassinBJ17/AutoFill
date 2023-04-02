/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */
/* ---------- include required interface: ----------------------------------- */
#include "libtools/time/LIB_TIME_public.h"
#include "libtools/time/LIBT_TIME_private.h"

/* ---------- internal define constants: ------------------------------------ */
#define e_LIBT_TIME_PIT_LDVAL_VAL   ((uint32_t) 0xFFFFFFFF)

/* ---------- internal types: ----------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_8.17> : initialisation literal : all possible initialisation is defined
 even if only 1 is used. */
typedef enum
{
   e_LIBT_TIME_PIT_MCR_MDIS_EN   = 0,
   e_LIBT_TIME_PIT_MCR_MDIS_DIS  = 1
}
te_LIBT_TIME_PIT_MCR_MDIS;

/* */
typedef enum
{
   e_LIBT_TIME_PIT_MCR_FRZ_DIS   = 0,
   e_LIBT_TIME_PIT_MCR_FRZ_EN    = 1
}
te_LIBT_TIME_PIT_MCR_FRZ;

/* */
typedef enum
{
   e_LIBT_TIME_PIT_TCTRL_TEN_DIS = 0,
   e_LIBT_TIME_PIT_TCTRL_TEN_EN  = 1
}
te_LIBT_TIME_PIT_TCTRL_TEN;


/* */
typedef enum
{
   e_LIBT_TIME_PIT_TCTRL_CHN_NO   = 0,
   e_LIBT_TIME_PIT_TCTRL_CHN_YES  = 1
}
te_LIBT_TIME_PIT_TCTRL_CHN;

/* */
typedef enum
{
   e_LIBT_TIME_PIT_TCTRL_TIE_DIS = 0,
   e_LIBT_TIME_PIT_TCTRL_TIE_EN  = 1
}
te_LIBT_TIME_PIT_TCTRL_TIE;
/* }}<SYNCHRONe_C_Code_8.17> */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_12.14>: initialisation value.all implicit cast are on value that can be coded in 8 bits. */
void LIBT_TIME_INIT(void)
{
   /* Check PIT is enabled */

   /* PIT initialization */
   LIBT_pit_ctrl->s_PIT_MCR.u_field.s_MDIS = e_LIBT_TIME_PIT_MCR_MDIS_EN;
   LIBT_pit_ctrl->s_PIT_MCR.u_field.s_FRZ  = e_LIBT_TIME_PIT_MCR_FRZ_EN;

   /* channel 0 */
   LIBT_pit_ctrl->s_PIT_DESC_CHANNEL[e_PIT_CHANNEL_0].s_PIT_LDVAL            = e_LIBT_TIME_PIT_LDVAL_VAL;
   LIBT_pit_ctrl->s_PIT_DESC_CHANNEL[e_PIT_CHANNEL_0].s_PIT_TCTRL.u_field.s_CHN  = e_LIBT_TIME_PIT_TCTRL_CHN_NO;
   LIBT_pit_ctrl->s_PIT_DESC_CHANNEL[e_PIT_CHANNEL_0].s_PIT_TCTRL.u_field.s_TIE  = e_LIBT_TIME_PIT_TCTRL_TIE_DIS;
   LIBT_pit_ctrl->s_PIT_DESC_CHANNEL[e_PIT_CHANNEL_0].s_PIT_TCTRL.u_field.s_TEN  = e_LIBT_TIME_PIT_TCTRL_TEN_EN;

   /* channel 1 */
   LIBT_pit_ctrl->s_PIT_DESC_CHANNEL[e_PIT_CHANNEL_1].s_PIT_LDVAL            = e_LIBT_TIME_PIT_LDVAL_VAL;
   LIBT_pit_ctrl->s_PIT_DESC_CHANNEL[e_PIT_CHANNEL_1].s_PIT_TCTRL.u_field.s_CHN  = e_LIBT_TIME_PIT_TCTRL_CHN_YES;
   LIBT_pit_ctrl->s_PIT_DESC_CHANNEL[e_PIT_CHANNEL_1].s_PIT_TCTRL.u_field.s_TIE  = e_LIBT_TIME_PIT_TCTRL_TIE_DIS;
   LIBT_pit_ctrl->s_PIT_DESC_CHANNEL[e_PIT_CHANNEL_1].s_PIT_TCTRL.u_field.s_TEN  = e_LIBT_TIME_PIT_TCTRL_TEN_EN;

}

/* }}<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_12.14> */
