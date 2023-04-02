/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function resets clocks.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_MC_public.h"
#include "BOOT_MC_REG_public.h"
#include "BOOT_PLL_REG_public.h"

/* ---------- internal define constants: ------------------------------------ */
/************/
/*  PRAMC   */
/************/
/* base address */
#define PRAMC_BASE_ADDR (0xFC020000)
#define MC_CGM_PCS_SDUR_VAL (100u)

/*
 * Port P0 is the main access port through the processor and/or the DMA.
 * Port P1 is the backdoor access port in case a flash page is replace by
 * a code in RAM (patch soft)
 * It is, thus, possible to choose different values of arbitration for P0 and P1.
 * Make P0 the highest priority port because the backdoor acces is usually used when
 * flash code is not replaced.
 * The configuration of the wait states depedns on the clock ratio between the crossbar and the RAM interface.
 * FT_DIS (Flow through disabled) = 0 is a mode used to optimize accesses. Read data
 * is directly send to the bus with no resynchronization.
 * This should works with somes clocks ratios.
 * It is better to set FT_DIS to 1 even if this degrade the response time.
*/
#define PRAMC_PRCR1_VAL   (0x00000101UL)

/* ---------- internal types: ----------------------------------------------- */

typedef struct
{
   reg32_t s_PRCR1;
}
ts_PRAMC_REG;

/* ---------- internal operations: ------------------------------------------ */

ts_MC_ME_REG volatile *  v_pt_mc_me_regs;

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_036 */
void BOOT_MC_MODE_INIT( void )
{
   uint32_t v_pc_index;
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The casts are safe as the structures are used to retrieve all registers which */
   /* start at each respective address. */
   ts_MC_CGM_REG volatile * pt_mc_cgm_regs = (ts_MC_CGM_REG volatile * ) MC_CGM_BASE_ADDR;
   ts_PLLDIG_REG volatile * pt_plldig_regs = (ts_PLLDIG_REG volatile * ) PLLDIG_BASE_ADDR;
   ts_PRAMC_REG volatile *  pt_pramc_regs  = (ts_PRAMC_REG volatile * ) PRAMC_BASE_ADDR;
   /* }}<SYNCHRONe_C_Code_10.7> */

   reg32_t * pt_mc_me_mode_reg;
   uint32_t v_mode_conf;

   te_MC_CGM_DIV_UPD_STAT v_sys_upd_status;

   v_pt_mc_me_regs  = (ts_MC_ME_REG volatile *) MC_ME_BASE_ADDR;

   /* clear all faults */

   /* Disable all interrupt events in case transition s_mode is not possible */
   v_pt_mc_me_regs->s_MC_ME_IM = (reg32_t)MC_ME_IM_DIS_ALL;

   /* Disable not required modes */
   v_pt_mc_me_regs->s_MC_ME_ME = (reg32_t)MC_ME_ME_DIS_ALL;

   /* */
   for ( v_pc_index = 0UL; v_pc_index < MC_ME_MODE_NB; v_pc_index++ )
   {
      v_pt_mc_me_regs->s_MC_ME_RUN_PC[v_pc_index] = (reg32_t)MC_ME_RUN_PC_VAL;
      v_pt_mc_me_regs->s_MC_ME_LP_PC[v_pc_index] = (reg32_t)MC_ME_LP_PC_VAL;
   }

   /* the cast of the literal 0 into 8 bit is safe. */
   v_pt_mc_me_regs->s_MC_ME_PCTL3 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL9 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL11 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL15 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL30 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL31 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL36 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL56 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL57 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL58 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL59 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL60 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL67 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL68 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL69 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL70 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL72 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL74 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL84 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL85 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL91 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL92 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL93 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL96 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL97 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL98 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL99 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL101 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL104 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL107 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL111 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL112 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL123 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL127 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL128 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL162 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL166 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL184 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL185 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL186 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL187 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL188 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL213 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL220 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL225 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL226 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL227 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL229 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL232 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL235 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL239 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL245 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL246 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL247 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL248 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL249 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL250 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL252 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL253 = MC_ME_PCTL_VAL;
   v_pt_mc_me_regs->s_MC_ME_PCTL254 = MC_ME_PCTL_VAL;


   /* TODO : check status register for all the following clocks to check that the chosen input clock is correct */
   /* system clock divider ratios will change from the current configuration to the configuration in the next update */
   pt_mc_cgm_regs->s_MC_CGM_SC_DIV_RC = (reg32_t)0x00000001UL;
   /* dividers associated with a clock are updated only on writing to the divider update trigger register*/
   /* CGM_DIV_UPD_TRIG,after which the pre-loaded configuration in the divider configuration registers will take*/
   /* effect*/
   /* >RELAX<SYNCHRONe_C_Code_7.2> MSB must be set to 1 in order to allow the update. */
   pt_mc_cgm_regs->s_MC_CGM_DIV_UPD = (reg32_t)0x80000000UL;

   /* Set slow AIPS clock */
   pt_mc_cgm_regs->s_MC_CGM_SC_DC2 = 
   ( pt_mc_cgm_regs->s_MC_CGM_SC_DC2 & (reg32_t)MC_CGM_SC_DC_DIV_MSK ) 
   | (reg32_t)( MC_CGM_SC_DC2_DIV_VAL << MC_CGM_SC_DC_DIV_SHIFT );

   /* Set slow XBAR clock */
   pt_mc_cgm_regs->s_MC_CGM_SC_DC1 = 
   ( pt_mc_cgm_regs->s_MC_CGM_SC_DC1 & (reg32_t)MC_CGM_SC_DC_DIV_MSK ) 
   | (reg32_t)( MC_CGM_SC_DC1_DIV_VAL << MC_CGM_SC_DC_DIV_SHIFT );

   /* Set XBAR clock */
   pt_mc_cgm_regs->s_MC_CGM_SC_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_SC_DC0 & (reg32_t)MC_CGM_SC_DC_DIV_MSK ) 
   | (reg32_t)( MC_CGM_SC_DC0_DIV_VAL << MC_CGM_SC_DC_DIV_SHIFT );

   /* Set COMP/CHKR clock */
   pt_mc_cgm_regs->s_MC_CGM_SC_DC3 = 
   ( pt_mc_cgm_regs->s_MC_CGM_SC_DC3 & (reg32_t)MC_CGM_SC_DC_DIV_MSK ) 
   | (reg32_t)( MC_CGM_SC_DC3_DIV_VAL << MC_CGM_SC_DC_DIV_SHIFT );

   /* Set CLKOUT */
   pt_mc_cgm_regs->s_MC_CGM_SC_DC4 = 
   ( pt_mc_cgm_regs->s_MC_CGM_SC_DC4 & (reg32_t)MC_CGM_SC_DC_DIV_MSK ) 
   | (reg32_t)( MC_CGM_SC_DC4_DIV_VAL << MC_CGM_SC_DC_DIV_SHIFT );

   /* System clock divider ratio updates triggered. Write any value */
   /* >RELAX<SYNCHRONe_C_Code_7.2> Any value written in CGM_DIV_UPD_TRIG triggers the update of all dividers, no*/
   /* matter the value. */
   pt_mc_cgm_regs->s_MC_CGM_DIV_UPD_TRIG = (reg32_t)MC_CGM_DIV_UPD_TRIG_VAL;

   do
   {
      /* {{RELAX<SYNCHRONe_C_Code_7.2> the value 0x80000000 and 31 are used in order to retrieve the MSB. */
      /* {{RELAX<SYNCHRONe_C_Code_10.3> the cast is safe as the enumerate value is either 0 or 1 and the binary*/
      /* operation (MSK + SHIFT) is done in order to retrieve a single bit. */
      /* {{RELAX<SYNCHRONe_C_Code_12.14> the use of an enumeration is safe as the enumerate value is either 0 or 1 and*/
      /* the binary operation (MSK + SHIFT) is done in order to retrieve a single bit. */
      v_sys_upd_status = 
      (te_MC_CGM_DIV_UPD_STAT)(( pt_mc_cgm_regs->s_MC_CGM_DIV_UPD_STAT & (reg32_t)0x80000000UL ) >> 31ul);
      /* }}<SYNCHRONe_C_Code_7.2,SYNCHRONe_C_Code_10.3,SYNCHRONe_C_Code_12.4> */

   }
   while ( v_sys_upd_status == e_MC_CGM_DIV_UPD_STAT_GOING );


   /********************/
   /* Auxiliary Clocks */
   /********************/

   /* program AC0 clock source as PLL0PHI */
   /* All CGM_ACx_SC bits are reserved except bits 4-7. Left shift allows the 4 bits of e_MC_CGM_SC_SELCTL_xxxx to*/
   /* correspond to the bits #4-7 of CGM_ACx_SC  */
   /* >RELAX<SYNCHRONe_C_Code_12.14> the use of an enumeration as the enumerate value is either 0, 1, 2, 3 or 4*/
   /* (3 bits) and the binary operation (MSK + SHIFT) is done in order to retrieve bits #4-7 of CGM_ACx_SC. */
   pt_mc_cgm_regs->s_MC_CGM_AC0_SC = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC0_SC & (reg32_t)MC_CGM_AC_SC_SELCTL_MSK ) 
   | (reg32_t)( e_MC_CGM_SC_SELCTL_PLL0PHI << MC_CGM_AC_SC_SELCTL_SHIFT );

   pt_mc_cgm_regs->s_MC_CGM_AC0_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC0_DC0 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_EN << MC_CGM_AC_DC_DE_SHIFT );
   pt_mc_cgm_regs->s_MC_CGM_AC0_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC0_DC0 & (reg32_t)MC_CGM_AC_DC_DIV_4_MSK ) 
   | (reg32_t)( MC_CGM_AC0_DC0_DIV_VAL << MC_CGM_AC_DC_DIV_SHIFT );

   /* disable dividers */
   pt_mc_cgm_regs->s_MC_CGM_AC0_DC1 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC0_DC1 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_DIS << MC_CGM_AC_DC_DE_SHIFT );

   /* enable dividers */
   pt_mc_cgm_regs->s_MC_CGM_AC0_DC2 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC0_DC2 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_EN  << MC_CGM_AC_DC_DE_SHIFT );
   pt_mc_cgm_regs->s_MC_CGM_AC0_DC2 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC0_DC2 & (reg32_t)MC_CGM_AC_DC_DIV_7_MSK ) 
   | (reg32_t)( MC_CGM_AC0_DC2_DIV_VAL  << MC_CGM_AC_DC_DIV_SHIFT );

   pt_mc_cgm_regs->s_MC_CGM_AC0_DC3 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC0_DC3 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_EN  << MC_CGM_AC_DC_DE_SHIFT );
   pt_mc_cgm_regs->s_MC_CGM_AC0_DC3 = 
   (( pt_mc_cgm_regs->s_MC_CGM_AC0_DC3 & (reg32_t)MC_CGM_AC_DC_DIV_9_MSK ) 
   | (reg32_t)( MC_CGM_AC0_DC3_DIV_VAL  << MC_CGM_AC_DC_DIV_SHIFT )) | (reg32_t)MC_CGM_AC0_DC3_DIV_FMT;

   pt_mc_cgm_regs->s_MC_CGM_AC0_DC4 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC0_DC4 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_EN  << MC_CGM_AC_DC_DE_SHIFT );
   pt_mc_cgm_regs->s_MC_CGM_AC0_DC4 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC0_DC4 & (reg32_t)MC_CGM_AC_DC_DIV_4_MSK ) 
   | (reg32_t)( MC_CGM_AC0_DC4_DIV_VAL  << MC_CGM_AC_DC_DIV_SHIFT );

   /* program AC1 clock source as XOSC */
   /* All CGM_ACx_SC bits are reserved except bits 4-7. Left shift allows the 4 bits of e_MC_CGM_SC_SELCTL_xxxx to*/
   /* correspond to the bits #4-7 of CGM_ACx_SC  */
   /* >RELAX<SYNCHRONe_C_Code_12.14> the use of an enumeration as the enumerate value is either 0, 1, 2, 3 or 4*/
   /* (3 bits) and the binary operation (MSK + SHIFT) is done in order to retrieve bits #4-7 of CGM_ACx_SC. */
   pt_mc_cgm_regs->s_MC_CGM_AC1_SC = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC1_SC & (reg32_t)MC_CGM_AC_SC_SELCTL_MSK ) 
   | (reg32_t)( e_MC_CGM_SC_SELCTL_XOSC << MC_CGM_AC_SC_SELCTL_SHIFT );
   /* disable divider */
   pt_mc_cgm_regs->s_MC_CGM_AC1_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC1_DC0 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_DIS << MC_CGM_AC_DC_DE_SHIFT );

   /* No program of AC2 clock source */
   /* disable dividers */
   pt_mc_cgm_regs->s_MC_CGM_AC2_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC2_DC0 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_DIS << MC_CGM_AC_DC_DE_SHIFT );
   pt_mc_cgm_regs->s_MC_CGM_AC2_DC1 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC2_DC1 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_DIS << MC_CGM_AC_DC_DE_SHIFT );

   /* No program of AC5 clock source */
   /* disable dividers */
   pt_mc_cgm_regs->s_MC_CGM_AC5_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC5_DC0 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_DIS << MC_CGM_AC_DC_DE_SHIFT );
   pt_mc_cgm_regs->s_MC_CGM_AC5_DC1 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC5_DC1 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_DIS << MC_CGM_AC_DC_DE_SHIFT );
   pt_mc_cgm_regs->s_MC_CGM_AC5_DC2 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC5_DC2 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_DIS << MC_CGM_AC_DC_DE_SHIFT );

   /* program AC6 clock source as XOSC */
   /* All CGM_ACx_SC bits are reserved except bits 4-7. Left shift allows the 4 bits of e_MC_CGM_SC_SELCTL_xxxx to*/
   /* correspond to the bits #4-7 of CGM_ACx_SC  */
   /* >RELAX<SYNCHRONe_C_Code_12.14> the use of an enumeration as the enumerate value is either 0, 1, 2, 3 or 4*/
   /* (3 bits) and the binary operation (MSK + SHIFT) is done in order to retrieve bits #4-7 of CGM_ACx_SC. */
   pt_mc_cgm_regs->s_MC_CGM_AC6_SC = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC6_SC & (reg32_t)MC_CGM_AC_SC_SELCTL_MSK ) 
   | (reg32_t)( e_MC_CGM_SC_SELCTL_XOSC << MC_CGM_AC_SC_SELCTL_SHIFT );
   /* disable dividers */
   pt_mc_cgm_regs->s_MC_CGM_AC6_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC6_DC0 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_DIS << MC_CGM_AC_DC_DE_SHIFT );

   /* program AC7 clock source as PLL0PHI */
   /* All CGM_ACx_SC bits are reserved except bits 4-7. Left shift allows the 4 bits of e_MC_CGM_SC_SELCTL_xxxx to*/
   /* correspond to the bits #4-7 of CGM_ACx_SC  */
   /* >RELAX<SYNCHRONe_C_Code_12.14> the use of an enumeration as the enumerate value is either 0, 1, 2, 3 or 4*/
   /* (3 bits) and the binary operation (MSK + SHIFT) is done in order to retrieve bits #4-7 of CGM_ACx_SC. */
   pt_mc_cgm_regs->s_MC_CGM_AC7_SC = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC7_SC & (reg32_t)MC_CGM_AC_SC_SELCTL_MSK ) 
   | (reg32_t)( e_MC_CGM_SC_SELCTL_PLL0PHI << MC_CGM_AC_SC_SELCTL_SHIFT );
   /* enable divider for SYSCLK1 */
   pt_mc_cgm_regs->s_MC_CGM_AC7_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC7_DC0 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_EN << MC_CGM_AC_DC_DE_SHIFT );
   pt_mc_cgm_regs->s_MC_CGM_AC7_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC7_DC0 & (reg32_t)MC_CGM_AC_DC_DIV_9_MSK ) 
   | (reg32_t)( MC_CGM_AC7_DC0_DIV_VAL << MC_CGM_AC_DC_DIV_SHIFT );

   /* program AC8 clock source as PLL0PHI */
   /* All CGM_ACx_SC bits are reserved except bits 4-7. Left shift allows the 4 bits of e_MC_CGM_SC_SELCTL_xxxx to*/
   /* correspond to the bits #4-7 of CGM_ACx_SC  */
   /* >RELAX<SYNCHRONe_C_Code_12.14> the use of an enumeration as the enumerate value is either 0, 1, 2, 3 or 4*/
   /* (3 bits) and the binary operation (MSK + SHIFT) is done in order to retrieve bits #4-7 of CGM_ACx_SC. */
   pt_mc_cgm_regs->s_MC_CGM_AC8_SC = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC8_SC & (reg32_t)MC_CGM_AC_SC_SELCTL_MSK ) 
   | (reg32_t)( e_MC_CGM_SC_SELCTL_PLL0PHI << MC_CGM_AC_SC_SELCTL_SHIFT );
   /* Enable divider */
   pt_mc_cgm_regs->s_MC_CGM_AC8_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC8_DC0 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_EN << MC_CGM_AC_DC_DE_SHIFT );
   pt_mc_cgm_regs->s_MC_CGM_AC8_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC8_DC0 & (reg32_t)MC_CGM_AC_DC_DIV_6_MSK ) 
   | (reg32_t)( MC_CGM_AC8_DC0_DIV_VAL << MC_CGM_AC_DC_DIV_SHIFT );

   /* program AC9 clock source as XOSC */
   /* All CGM_ACx_SC bits are reserved except bits 4-7. Left shift allows the 4 bits of e_MC_CGM_SC_SELCTL_xxxx to*/
   /* correspond to the bits #4-7 of CGM_ACx_SC  */
   /* >RELAX<SYNCHRONe_C_Code_12.14> the use of an enumeration as the enumerate value is either 0, 1, 2, 3 or 4*/
   /* (3 bits) and the binary operation (MSK + SHIFT) is done in order to retrieve bits #4-7 of CGM_ACx_SC. */
   pt_mc_cgm_regs->s_MC_CGM_AC9_SC = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC9_SC & (reg32_t)MC_CGM_AC_SC_SELCTL_MSK ) 
   | (reg32_t)( e_MC_CGM_SC_SELCTL_XOSC << MC_CGM_AC_SC_SELCTL_SHIFT );
   /* disable divider */
   pt_mc_cgm_regs->s_MC_CGM_AC9_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC9_DC0 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_DIS << MC_CGM_AC_DC_DE_SHIFT );

   /* program AC10 clock source as PLL0PHI */
   /* All CGM_ACx_SC bits are reserved except bits 4-7. Left shift allows the 4 bits of e_MC_CGM_SC_SELCTL_xxxx to*/
   /* correspond to the bits #4-7 of CGM_ACx_SC  */
   /* >RELAX<SYNCHRONe_C_Code_12.14> the use of an enumeration as the enumerate value is either 0, 1, 2, 3 or 4*/
   /* (3 bits) and the binary operation (MSK + SHIFT) is done in order to retrieve bits #4-7 of CGM_ACx_SC. */
   pt_mc_cgm_regs->s_MC_CGM_AC10_SC = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC10_SC & (reg32_t)MC_CGM_AC_SC_SELCTL_MSK ) 
   | (reg32_t)( e_MC_CGM_SC_SELCTL_PLL0PHI << MC_CGM_AC_SC_SELCTL_SHIFT );
   /* Enable divider */
   pt_mc_cgm_regs->s_MC_CGM_AC10_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC10_DC0 & (reg32_t)MC_CGM_AC_DC_DE_MSK ) 
   | (reg32_t)( MC_CGM_AC_DC_DE_EN << MC_CGM_AC_DC_DE_SHIFT );
   pt_mc_cgm_regs->s_MC_CGM_AC10_DC0 = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC10_DC0 & (reg32_t)MC_CGM_AC_DC_DIV_4_MSK ) 
   | (reg32_t)( MC_CGM_AC10_DC0_DIV_VAL << MC_CGM_AC_DC_DIV_SHIFT );


   pt_pramc_regs->s_PRCR1 = (reg32_t)PRAMC_PRCR1_VAL;


   /* program PLL0 clock source as XOSC */
   /* All CGM_ACx_SC bits are reserved except bits 4-7. Left shift allows the 4 bits of e_MC_CGM_SC_SELCTL_xxxx to*/
   /* correspond to the bits #4-7 of CGM_ACx_SC  */
   /* >RELAX<SYNCHRONe_C_Code_12.14> the use of an enumeration as the enumerate value is either 0, 1, 2, 3 or 4*/
   /* (3 bits) and the binary operation (MSK + SHIFT) is done in order to retrieve bits #4-7 of CGM_ACx_SC. */
   pt_mc_cgm_regs->s_MC_CGM_AC3_SC = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC3_SC & (reg32_t)MC_CGM_AC_SC_SELCTL_MSK ) 
   | (reg32_t)( e_MC_CGM_SC_SELCTL_XOSC << MC_CGM_AC_SC_SELCTL_SHIFT );
   /* program PLL1 clock source as PLL0PHI1 */
   /* All CGM_ACx_SC bits are reserved except bits 4-7. Left shift allows the 4 bits of e_MC_CGM_SC_SELCTL_xxxx to*/
   /* correspond to the bits #4-7 of CGM_ACx_SC  */
   /* >RELAX<SYNCHRONe_C_Code_12.14> the use of an enumeration as the enumerate value is either 0, 1, 2, 3 or 4*/
   /* (3 bits) and the binary operation (MSK + SHIFT) is done in order to retrieve bits #4-7 of CGM_ACx_SC. */
   pt_mc_cgm_regs->s_MC_CGM_AC4_SC = 
   ( pt_mc_cgm_regs->s_MC_CGM_AC4_SC & (reg32_t)MC_CGM_AC_SC_SELCTL_MSK ) 
   | (reg32_t)( e_MC_CGM_SC_SELCTL_PLL0PHI1 << MC_CGM_AC_SC_SELCTL_SHIFT );



   /* TODO : Configure IRCOSC_CTL register */
   /* TODO : Configure XOSC_CTL register */

   /* First clear s_PLLDIG_PLL0SR LOLF and EXTPDF status bits for s_PLLDIG_PLL0SR and s_PLLDIG_PLL1SR registers */
   pt_plldig_regs->s_PLLDIG_PLL0SR = (reg32_t)PLLDIG_PLL0SR_CLR_VAL;
   pt_plldig_regs->s_PLLDIG_PLL1SR = (reg32_t)PLLDIG_PLL1SR_CLR_VAL;

   /* Then program PLL0DV[PREDIV], PLL0DV[RFDPHI1], PLL0DV[MFD] and PLL0DV[RFDPHI] */
   pt_plldig_regs->s_PLLDIG_PLL0DV = 
   ( pt_plldig_regs->s_PLLDIG_PLL0DV & (reg32_t)PLLDIG_PLL0DV_MSK ) 
   | (reg32_t)PLLDIG_PLL0DV_VAL;

   /* program PLL1DV[MFD] and PLL01DV[RFDPHI] */
   pt_plldig_regs->s_PLLDIG_PLL1DV = 
   ( pt_plldig_regs->s_PLLDIG_PLL1DV & (reg32_t)PLLDIG_PLL1DV_MSK ) 
   | (reg32_t)PLLDIG_PLL1DV_VAL;

   /* TODO : program s_PLLDIG_PLL1FM register */
   /* >RELAX<SYNCHRONe_C_Code_7.2> Bit FDEN (bit #1) of PLLDIG_PLL1FD is set to 0 to disabled fractional divider.*/
   /* All other bits are left untouched with mask ~0x40000000UL */
   pt_plldig_regs->s_PLLDIG_PLL1FD = pt_plldig_regs->s_PLLDIG_PLL1FD & (reg32_t)(~0x40000000UL);


   /* TODO : FCS configuration */
   /* set Switch Duration */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast of the literal 100 into 8 bit is safe. */
   /* >RELAX<SYNCHRONe_C_Code_7.2> '100' is the switch duration in number of cycles. */
   pt_mc_cgm_regs->s_MC_CGM_PCS_SDUR = ( reg8_t )( MC_CGM_PCS_SDUR_VAL );

   /* Configure DRUN power level */
   v_pt_mc_me_regs->s_MC_ME_DRUN_MC = 
   (v_pt_mc_me_regs->s_MC_ME_DRUN_MC & (reg32_t)MC_ME_DRUN_MC_PWRLVL_MASK) 
   | (reg32_t)(MC_ME_DRUN_MC_PWRLVL_VAL << MC_ME_DRUN_MC_PWRLVL_SHIFT);

   /* Configure PLL1 PCS switch | See RM section "Progressive system clock switching" */
   /* Set the Divider Change Initial s_Value */
   /* Set the Divider Change Rate */
   pt_mc_cgm_regs->s_MC_CGM_PCS_DIVC4 = 
   ( (pt_mc_cgm_regs->s_MC_CGM_PCS_DIVC4 & (reg32_t)MC_CGM_PCS_DIVC4_MASK) 
   | (reg32_t)(MC_CGM_PCS_DIVC4_INIT_VAL << MC_CGM_PCS_DIVC4_INIT_SHIFT) )
   | (reg32_t)(MC_CGM_PCS_DIVC4_RATE_VAL << MC_CGM_PCS_DIVC4_RATE_SHIFT);

   /* Set the Divider Start s_Value. */
   pt_mc_cgm_regs->s_MC_CGM_PCS_DIVS4 = (reg32_t)MC_CGM_PCS_DIVS4_VAL;

   /* Set the Divider End s_Value */
   pt_mc_cgm_regs->s_MC_CGM_PCS_DIVE4 = (reg32_t)MC_CGM_PCS_DIVE4_VAL;


   /* Configure PLL0 PCS switch (See RM section Progressive system clock switching) */
   /* Set the Divider Change Initial s_Value */
   /* Set the Divider Change Rate */
   pt_mc_cgm_regs->s_MC_CGM_PCS_DIVC2 = 
   ( (pt_mc_cgm_regs->s_MC_CGM_PCS_DIVC2 & (reg32_t)MC_CGM_PCS_DIVC2_MASK) 
   | (reg32_t)(MC_CGM_PCS_DIVC2_INIT_VAL << MC_CGM_PCS_DIVC2_INIT_SHIFT) )
   | (reg32_t)(MC_CGM_PCS_DIVC2_RATE_VAL << MC_CGM_PCS_DIVC2_RATE_SHIFT);

   /* Set the Divider Start s_Value. */
   pt_mc_cgm_regs->s_MC_CGM_PCS_DIVS2 = (reg32_t)MC_CGM_PCS_DIVS2_VAL;

   /* Set the Divider End s_Value */
   pt_mc_cgm_regs->s_MC_CGM_PCS_DIVE2 = (reg32_t)MC_CGM_PCS_DIVE2_VAL;


   /*BOOT_MODE_CONF_SEL(e_MC_ME_MODE_DRUN, MC_ME_DRUN_MC_CONF);*/
   v_mode_conf = MC_ME_DRUN_MC_CONF;
   pt_mc_me_mode_reg = &v_pt_mc_me_regs->s_MC_ME_DRUN_MC;

   if ( ( v_mode_conf & MC_ME_DRUN_MC_XOSCON_MASK ) != 0UL )
   {
      /* activate XOSC */
      *pt_mc_me_mode_reg = (*pt_mc_me_mode_reg) | (reg32_t)MC_ME_DRUN_MC_XOSCON_MASK;
      if ( ( v_mode_conf & MC_ME_DRUN_MC_PLL0ON_MASK ) != 0UL )
      {
         /* activate PLL0 */
         *pt_mc_me_mode_reg = (*pt_mc_me_mode_reg) | (reg32_t)MC_ME_DRUN_MC_PLL0ON_MASK;
         if ( ( v_mode_conf & MC_ME_DRUN_MC_PLL1ON_MASK ) != 0UL )
         {
            /* activate PLL1 */
            *pt_mc_me_mode_reg = (*pt_mc_me_mode_reg) | (reg32_t)MC_ME_DRUN_MC_PLL1ON_MASK;
         }
         /* else            */
         /* mean using PLL0 */
      }
      /* else            */
      /* mean using XOSC */
   }
   /* else             */
   /* mean using IROSC */
}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
