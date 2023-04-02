#ifndef BOOT_MC_REG_public_H
#define BOOT_MC_REG_public_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- internal define constants: ------------------------------------ */

/* */
#define MC_RGM_BASE_ADDR (0xFFFA8000)

/* */
#define MC_RGM_RSRVD_A_SIZE (191)

/* Clear all faults */
#define MC_RGM_DES_CLEAR_VALUE    (uint32_t)0x0180C73B

#define MC_RGM_FES_CLEAR_VALUE    (uint32_t)0x0180846F
#define MC_RGM_FES_F_ST_DONE_MASK (uint32_t)0x4

/* ---------- internal types: ----------------------------------------------- */

/*********************/
/* Mode Entry Module */
/*********************/
typedef enum
{
   e_MC_ME_MODE_RESET_FUNC = 0,
   e_MC_ME_MODE_TEST  = 1,
   e_MC_ME_MODE_SAFE  = 2,
   e_MC_ME_MODE_DRUN  = 3,
   e_MC_ME_MODE_RUN0  = 4,
   e_MC_ME_MODE_RUN1  = 5,
   e_MC_ME_MODE_RUN2  = 6,
   e_MC_ME_MODE_RUN3  = 7,
   e_MC_ME_MODE_HALT0 = 8,
   e_MC_ME_MODE_STOP0 = 10,
   e_MC_ME_MODE_RESET_DEST = 15
}
te_MC_ME_MODE;

typedef enum
{
   e_MC_ME_GS_MTRANS_NOT_ACTIV = 0,
   e_MC_ME_GS_MTRANS_ON_GOING   = 1
}
te_MC_ME_GS_MTRANS;




/************/
/* MC_RGM   */
/************/


/* */
typedef struct
{
   reg32_t s_MC_RGM_DES;
   reg32_t s_MC_rsvdA[MC_RGM_RSRVD_A_SIZE];
   reg32_t s_MC_RGM_FES;
}
ts_MC_RGM_REG;

#define MC_RGM (*(volatile ts_MC_RGM_REG *) MC_RGM_BASE_ADDR)
#define MC_RGM_FES (MC_RGM.s_MC_RGM_FES)

/* base address */
#define MC_CGM_BASE_ADDR (0xFFFB0000)

/* */
#define MC_CGM_RSRVD_A_SIZE (448)
#define MC_CGM_RSRVD_B_SIZE (1)
#define MC_CGM_RSRVD_C_SIZE (1)
#define MC_CGM_RSRVD_D_SIZE (7)
#define MC_CGM_RSRVD_E_SIZE (4)
#define MC_CGM_RSRVD_F_SIZE (6)
#define MC_CGM_RSRVD_G_SIZE (8)
#define MC_CGM_RSRVD_H_SIZE (3)
#define MC_CGM_RSRVD_I_SIZE (5)
#define MC_CGM_RSRVD_J_SIZE (5)
#define MC_CGM_RSRVD_K_SIZE (5)
#define MC_CGM_RSRVD_L_SIZE (5)

typedef struct
{
   reg32_t s_MC_CGM_rsvdA[MC_CGM_RSRVD_A_SIZE];

   reg8_t s_MC_CGM_PCS_SDUR;
   reg32_t s_MC_CGM_PCS_DIVC1;
   reg32_t s_MC_CGM_PCS_DIVE1;
   reg32_t s_MC_CGM_PCS_DIVS1;
   reg32_t s_MC_CGM_PCS_DIVC2;
   reg32_t s_MC_CGM_PCS_DIVE2;
   reg32_t s_MC_CGM_PCS_DIVS2;
   /* >RELAX<SYNCHRONe_C_Code_7.2> MC_CGM_PCS_DIVC4 register and MC_CGM_PCS_DIVS2 register are separated by '3'*/
   /* reserved 32 bit-registers */
   reg32_t s_MC_CGM_rsvdAA[3];
   reg32_t s_MC_CGM_PCS_DIVC4;
   reg32_t s_MC_CGM_PCS_DIVE4;
   reg32_t s_MC_CGM_PCS_DIVS4;
   /* >RELAX<SYNCHRONe_C_Code_7.2> MC_CGM_SC_DIV_RC register and MC_CGM_PCS_DIVS4 register are separated by '39'*/
   /* reserved 32 bit-registers */
   reg32_t s_MC_CGM_rsvdAB[39];

   reg32_t s_MC_CGM_SC_DIV_RC;
   reg32_t s_MC_CGM_DIV_UPD;
   reg32_t s_MC_CGM_DIV_UPD_TRIG;
   reg32_t s_MC_CGM_DIV_UPD_STAT;
   reg32_t s_MC_CGM_rsvdAC[1];

   reg32_t s_MC_CGM_SC_SS;
   reg32_t s_MC_CGM_SC_DC0;
   reg32_t s_MC_CGM_SC_DC1;
   reg32_t s_MC_CGM_SC_DC2;
   reg32_t s_MC_CGM_SC_DC3;
   reg32_t s_MC_CGM_SC_DC4;

   reg32_t s_MC_CGM_rsvdB[MC_CGM_RSRVD_B_SIZE];

   reg32_t s_MC_CGM_AC0_SC;
   reg32_t s_MC_CGM_AC0_SS;
   reg32_t s_MC_CGM_AC0_DC0;
   reg32_t s_MC_CGM_AC0_DC1;
   reg32_t s_MC_CGM_AC0_DC2;
   reg32_t s_MC_CGM_AC0_DC3;
   reg32_t s_MC_CGM_AC0_DC4;

   reg32_t s_MC_CGM_rsvdC[MC_CGM_RSRVD_C_SIZE];

   reg32_t s_MC_CGM_AC1_SC;
   reg32_t s_MC_CGM_AC1_SS;
   reg32_t s_MC_CGM_AC1_DC0;

   reg32_t s_MC_CGM_rsvdD[MC_CGM_RSRVD_D_SIZE];

   reg32_t s_MC_CGM_AC2_DC0;
   reg32_t s_MC_CGM_AC2_DC1;

   reg32_t s_MC_CGM_rsvdE[MC_CGM_RSRVD_E_SIZE];

   reg32_t s_MC_CGM_AC3_SC;
   reg32_t s_MC_CGM_AC3_SS;

   reg32_t s_MC_CGM_rsvdF[MC_CGM_RSRVD_F_SIZE];

   reg32_t s_MC_CGM_AC4_SC;
   reg32_t s_MC_CGM_AC4_SS;

   reg32_t s_MC_CGM_rsvdG[MC_CGM_RSRVD_G_SIZE];

   reg32_t s_MC_CGM_AC5_DC0;
   reg32_t s_MC_CGM_AC5_DC1;
   reg32_t s_MC_CGM_AC5_DC2;

   reg32_t s_MC_CGM_rsvdH[MC_CGM_RSRVD_H_SIZE];

   reg32_t s_MC_CGM_AC6_SC;
   reg32_t s_MC_CGM_AC6_SS;
   reg32_t s_MC_CGM_AC6_DC0;

   reg32_t s_MC_CGM_rsvdI[MC_CGM_RSRVD_I_SIZE];

   reg32_t s_MC_CGM_AC7_SC;
   reg32_t s_MC_CGM_AC7_SS;
   reg32_t s_MC_CGM_AC7_DC0;

   reg32_t s_MC_CGM_rsvdJ[MC_CGM_RSRVD_J_SIZE];

   reg32_t s_MC_CGM_AC8_SC;
   reg32_t s_MC_CGM_AC8_SS;
   reg32_t s_MC_CGM_AC8_DC0;

   reg32_t s_MC_CGM_rsvdK[MC_CGM_RSRVD_K_SIZE];

   reg32_t s_MC_CGM_AC9_SC;
   reg32_t s_MC_CGM_AC9_SS;
   reg32_t s_MC_CGM_AC9_DC0;

   reg32_t s_MC_CGM_rsvdL[MC_CGM_RSRVD_L_SIZE];

   reg32_t s_MC_CGM_AC10_SC;
   reg32_t s_MC_CGM_AC10_SS;
   reg32_t s_MC_CGM_AC10_DC0;

}
ts_MC_CGM_REG;

#define MC_CGM_SC_DC_DIV_MSK   (0xFFC0FFFFUL)
#define MC_CGM_SC_DC_DIV_SHIFT (16UL)
#define MC_CGM_DIV_UPD_TRIG_VAL ((reg32_t)0xfeedfaceUL)
/* XBAR : 200MHz*/
#define MC_CGM_SC_DC0_DIV_VAL   (2UL)

/* Slow XBAR : 100MHz */
#define MC_CGM_SC_DC1_DIV_VAL   (5UL)

/* AIPS : 50MHz */
#define MC_CGM_SC_DC2_DIV_VAL   (11UL)

/* COMP/ CHKR : 300MHz */
#define MC_CGM_SC_DC3_DIV_VAL   (1UL)

/* CLKOUT: 66,67MHz  depends on number of wait states on MRAM */
#define MC_CGM_SC_DC4_DIV_VAL   (8UL)

/* SYSCLK1 : 50MHz */
#define MC_CGM_AC7_DC0_DIV_VAL   (7UL)

/* PER_CLK : 80 MHz*/
#define MC_CGM_AC0_DC0_DIV_VAL   (5UL)

/* SAR_CLK : 14,3MHz */
#define MC_CGM_AC0_DC2_DIV_VAL   (27UL)

/* DSPI4/5/6 : 80 MHz */
#define MC_CGM_AC0_DC3_DIV_VAL   (4UL)
#define MC_CGM_AC0_DC3_DIV_FMT   (0UL)

/* DSPI0/1/2/3/12, LIN_CLK : 100 MHz */
#define MC_CGM_AC0_DC4_DIV_VAL   (3UL)

/* CAN_CLK : 80MHz */
#define MC_CGM_AC8_DC0_DIV_VAL   (4UL)

/* FEC_REF_CLK : 50MHz */
#define MC_CGM_AC10_DC0_DIV_VAL  (7UL)

/* */
#define MC_CGM_AC_DC_DE_MSK (0x7FFFFFFFUL)
#define MC_CGM_AC_DC_DE_EN  (1UL)
#define MC_CGM_AC_DC_DE_DIS (0UL)
#define MC_CGM_AC_DC_DE_SHIFT (31UL)

#define MC_CGM_AC_DC_DIV_4_MSK  (0xFFF00000UL)
#define MC_CGM_AC_DC_DIV_6_MSK  (0xFFC00000UL)
#define MC_CGM_AC_DC_DIV_7_MSK  (0xFF800000UL)
#define MC_CGM_AC_DC_DIV_9_MSK  (0xFE000000UL)

#define MC_CGM_AC_DC_DIV_SHIFT (16UL)

#define MC_CGM_AC_SC_SELCTL_MSK (0xF0FFFFFFUL)
#define MC_CGM_AC_SC_SELCTL_SHIFT (24UL)

#define MC_CGM_PCS_DIVC4_MASK       (0x0000FF00UL)
#define MC_CGM_PCS_DIVC4_INIT_VAL   (851UL)
#define MC_CGM_PCS_DIVC4_INIT_SHIFT (16UL)
#define MC_CGM_PCS_DIVC4_RATE_VAL   (12UL)
#define MC_CGM_PCS_DIVC4_RATE_SHIFT (0UL)

#define MC_CGM_PCS_DIVS4_VAL (31671UL)
#define MC_CGM_PCS_DIVE4_VAL (31671UL)

#define MC_CGM_PCS_DIVC2_MASK       (0x0000FF00UL)
#define MC_CGM_PCS_DIVC2_INIT_VAL   (851UL)
#define MC_CGM_PCS_DIVC2_INIT_SHIFT (16UL)
#define MC_CGM_PCS_DIVC2_RATE_VAL   (12UL)
#define MC_CGM_PCS_DIVC2_RATE_SHIFT (0UL)

#define MC_CGM_PCS_DIVS2_VAL (31671UL)
#define MC_CGM_PCS_DIVE2_VAL (31671UL)

/* */
typedef enum
{
   e_MC_CGM_SC_SELCTL_INROSC   = 0,
   e_MC_CGM_SC_SELCTL_XOSC     = 1,
   e_MC_CGM_SC_SELCTL_PLL0PHI  = 2,
   e_MC_CGM_SC_SELCTL_PLL0PHI1 = 3,
   e_MC_CGM_SC_SELCTL_PLL1PHI  = 4
}
te_MC_CGM_SC_SELCTL;


typedef enum
{
   e_MC_CGM_DIV_UPD_STAT_ENDED = 0,
   e_MC_CGM_DIV_UPD_STAT_GOING = 1
}
te_MC_CGM_DIV_UPD_STAT;


/*********************/
/* Mode Entry Module */
/*********************/

/* base address */
#define MC_ME_BASE_ADDR (0xFFFB8000)

/* */
#define MC_ME_RSRVD_A_SIZE (1)
#define MC_ME_RSRVD_B_SIZE (3)
#define MC_ME_RSRVD_C_SIZE (1)
#define MC_ME_RSRVD_D_SIZE (5)
#define MC_ME_RSRVD_E_SIZE (3)
#define MC_ME_RSRVD_F_SIZE (5)
#define MC_ME_RSRVD_G_SIZE (1)
#define MC_ME_RSRVD_H_SIZE (3)
#define MC_ME_RSRVD_I_SIZE (14)
#define MC_ME_RSRVD_J_SIZE (4)
#define MC_ME_RSRVD_K_SIZE (1)
#define MC_ME_RSRVD_L_SIZE (17)
#define MC_ME_RSRVD_M_SIZE (6)
#define MC_ME_RSRVD_N_SIZE (1)
#define MC_ME_RSRVD_O_SIZE (1)
#define MC_ME_RSRVD_P_SIZE (9)
#define MC_ME_RSRVD_Q_SIZE (5)
#define MC_ME_RSRVD_R_SIZE (2)
#define MC_ME_RSRVD_S_SIZE (1)
#define MC_ME_RSRVD_T_SIZE (2)
#define MC_ME_RSRVD_U_SIZE (2)
#define MC_ME_RSRVD_V_SIZE (3)
#define MC_ME_RSRVD_W_SIZE (10)
#define MC_ME_RSRVD_X_SIZE (3)
#define MC_ME_RSRVD_Y_SIZE (33)
#define MC_ME_RSRVD_Z_SIZE (3)
#define MC_ME_RSRVD_AA_SIZE (17)
#define MC_ME_RSRVD_AB_SIZE (24)
#define MC_ME_RSRVD_AC_SIZE (6)
#define MC_ME_RSRVD_AD_SIZE (4)
#define MC_ME_RSRVD_AE_SIZE (1)
#define MC_ME_RSRVD_AF_SIZE (2)
#define MC_ME_RSRVD_AG_SIZE (2)
#define MC_ME_RSRVD_AH_SIZE (3)
#define MC_ME_RSRVD_AI_SIZE (5)
#define MC_ME_RSRVD_AJ_SIZE (1)
#define MC_ME_RSRVD_AK_SIZE (1)
#define MC_ME_RSRVD_AL_SIZE (9)
/* */
#define MC_ME_MODE_NB (8UL)
/* */
#define MC_ME_CCTL_NB (5)

/* */
typedef struct
{
   reg32_t s_MC_ME_GS;

   reg32_t s_MC_ME_MCTL;

   reg32_t s_MC_ME_ME;
   reg32_t s_MC_ME_rsvdA[MC_ME_RSRVD_A_SIZE];

   reg32_t s_MC_ME_IM;
   reg32_t s_MC_ME_rsvdB[MC_ME_RSRVD_B_SIZE];

   reg32_t s_MC_ME_RESET_MC;
   reg32_t s_MC_ME_TEST_MC;
   reg32_t s_MC_ME_SAFE_MC;
   reg32_t s_MC_ME_DRUN_MC;
   reg32_t s_MC_ME_RUN0_MC;
   reg32_t s_MC_ME_RUN1_MC;
   reg32_t s_MC_ME_RUN2_MC;
   reg32_t s_MC_ME_RUN3_MC;
   reg32_t s_MC_ME_HALT0_MC;
   reg32_t s_MC_ME_rsvdC[MC_ME_RSRVD_C_SIZE];
   reg32_t s_MC_ME_STOP0_MC;
   reg32_t s_MC_ME_rsvdD[MC_ME_RSRVD_D_SIZE];

   reg32_t s_MC_ME_PS[MC_ME_MODE_NB];

   reg32_t s_MC_ME_RUN_PC[MC_ME_MODE_NB];

   reg32_t s_MC_ME_LP_PC[MC_ME_MODE_NB];
   reg8_t  s_MC_ME_rsvdE[MC_ME_RSRVD_E_SIZE];

   reg8_t  s_MC_ME_PCTL3;
   reg8_t  s_MC_ME_rsvdF[MC_ME_RSRVD_F_SIZE];
   reg8_t  s_MC_ME_PCTL9;
   reg8_t  s_MC_ME_rsvdG[MC_ME_RSRVD_G_SIZE];
   reg8_t  s_MC_ME_PCTL11;
   reg8_t  s_MC_ME_rsvdH[MC_ME_RSRVD_H_SIZE];
   reg8_t  s_MC_ME_PCTL15;
   reg8_t  s_MC_ME_rsvdI[MC_ME_RSRVD_I_SIZE];
   reg8_t  s_MC_ME_PCTL30;
   reg8_t  s_MC_ME_PCTL31;
   reg8_t  s_MC_ME_rsvdJ[MC_ME_RSRVD_J_SIZE];
   reg8_t  s_MC_ME_PCTL36;
   reg8_t  s_MC_ME_rsvdK[MC_ME_RSRVD_K_SIZE];
   reg8_t  s_MC_ME_PCTL38;
   reg8_t  s_MC_ME_rsvdL[MC_ME_RSRVD_L_SIZE];
   reg8_t  s_MC_ME_PCTL56;
   reg8_t  s_MC_ME_PCTL57;
   reg8_t  s_MC_ME_PCTL58;
   reg8_t  s_MC_ME_PCTL59;
   reg8_t  s_MC_ME_PCTL60;
   reg8_t  s_MC_ME_rsvdM[MC_ME_RSRVD_M_SIZE];
   reg8_t  s_MC_ME_PCTL67;
   reg8_t  s_MC_ME_PCTL68;
   reg8_t  s_MC_ME_PCTL69;
   reg8_t  s_MC_ME_PCTL70;
   reg8_t  s_MC_ME_rsvdN[MC_ME_RSRVD_N_SIZE];
   reg8_t  s_MC_ME_PCTL72;
   reg8_t  s_MC_ME_rsvdO[MC_ME_RSRVD_O_SIZE];
   reg8_t  s_MC_ME_PCTL74;
   reg8_t  s_MC_ME_rsvdP[MC_ME_RSRVD_P_SIZE];
   reg8_t  s_MC_ME_PCTL84;
   reg8_t  s_MC_ME_PCTL85;
   reg8_t  s_MC_ME_rsvdQ[MC_ME_RSRVD_Q_SIZE];
   reg8_t  s_MC_ME_PCTL91;
   reg8_t  s_MC_ME_PCTL92;
   reg8_t  s_MC_ME_PCTL93;
   reg8_t  s_MC_ME_rsvdR[MC_ME_RSRVD_R_SIZE];
   reg8_t  s_MC_ME_PCTL96;
   reg8_t  s_MC_ME_PCTL97;
   reg8_t  s_MC_ME_PCTL98;
   reg8_t  s_MC_ME_PCTL99;
   reg8_t  s_MC_ME_rsvdS[MC_ME_RSRVD_S_SIZE];
   reg8_t  s_MC_ME_PCTL101;
   reg8_t  s_MC_ME_rsvdT[MC_ME_RSRVD_T_SIZE];
   reg8_t  s_MC_ME_PCTL104;
   reg8_t  s_MC_ME_rsvdU[MC_ME_RSRVD_U_SIZE];
   reg8_t  s_MC_ME_PCTL107;
   reg8_t  s_MC_ME_rsvdV[MC_ME_RSRVD_V_SIZE];
   reg8_t  s_MC_ME_PCTL111;
   reg8_t  s_MC_ME_PCTL112;
   reg8_t  s_MC_ME_rsvdW[MC_ME_RSRVD_W_SIZE];
   reg8_t  s_MC_ME_PCTL123;
   reg8_t  s_MC_ME_rsvdX[MC_ME_RSRVD_X_SIZE];
   reg8_t  s_MC_ME_PCTL127;
   reg8_t  s_MC_ME_PCTL128;
   reg8_t  s_MC_ME_rsvdY[MC_ME_RSRVD_Y_SIZE];
   reg8_t  s_MC_ME_PCTL162;
   reg8_t  s_MC_ME_rsvdZ[MC_ME_RSRVD_Z_SIZE];
   reg8_t  s_MC_ME_PCTL166;
   reg8_t  s_MC_ME_rsvdAA[MC_ME_RSRVD_AA_SIZE];
   reg8_t  s_MC_ME_PCTL184;
   reg8_t  s_MC_ME_PCTL185;
   reg8_t  s_MC_ME_PCTL186;
   reg8_t  s_MC_ME_PCTL187;
   reg8_t  s_MC_ME_PCTL188;
   reg8_t  s_MC_ME_rsvdAB[MC_ME_RSRVD_AB_SIZE];
   reg8_t  s_MC_ME_PCTL213;
   reg8_t  s_MC_ME_rsvdAC[MC_ME_RSRVD_AC_SIZE];
   reg8_t  s_MC_ME_PCTL220;
   reg8_t  s_MC_ME_rsvdAD[MC_ME_RSRVD_AD_SIZE];
   reg8_t  s_MC_ME_PCTL225;
   reg8_t  s_MC_ME_PCTL226;
   reg8_t  s_MC_ME_PCTL227;
   reg8_t  s_MC_ME_rsvdAE[MC_ME_RSRVD_AE_SIZE];
   reg8_t  s_MC_ME_PCTL229;
   reg8_t  s_MC_ME_rsvdAF[MC_ME_RSRVD_AF_SIZE];
   reg8_t  s_MC_ME_PCTL232;
   reg8_t  s_MC_ME_rsvdAG[MC_ME_RSRVD_AG_SIZE];
   reg8_t  s_MC_ME_PCTL235;
   reg8_t  s_MC_ME_rsvdAH[MC_ME_RSRVD_AH_SIZE];
   reg8_t  s_MC_ME_PCTL239;
   reg8_t  s_MC_ME_rsvdAI[MC_ME_RSRVD_AI_SIZE];
   reg8_t  s_MC_ME_PCTL245;
   reg8_t  s_MC_ME_PCTL246;
   reg8_t  s_MC_ME_PCTL247;
   reg8_t  s_MC_ME_PCTL248;
   reg8_t  s_MC_ME_PCTL249;
   reg8_t  s_MC_ME_PCTL250;
   reg8_t  s_MC_ME_rsvdAJ[MC_ME_RSRVD_AJ_SIZE];
   reg8_t  s_MC_ME_PCTL252;
   reg8_t  s_MC_ME_PCTL253;
   reg8_t  s_MC_ME_PCTL254;
   reg8_t  s_MC_ME_rsvdAK[MC_ME_RSRVD_AK_SIZE];

   reg32_t s_MC_ME_CS;

   reg16_t s_MC_ME_CCTL[MC_ME_CCTL_NB];
   reg16_t s_rsvdAL[MC_ME_RSRVD_AL_SIZE];

   reg32_t s_MC_ME_CADDR[MC_ME_CCTL_NB];
}
ts_MC_ME_REG;


/* */
typedef enum
{
   e_MC_ME_GS_CLK_NOT_STABLE = 0,
   e_MC_ME_GS_CLK_STABLE = 1
}
te_MC_ME_GS_CLK_STABLE;

/* KEY */
#define MC_ME_MCTL_KEY (0x00005AF0UL)
#define MC_ME_MCTL_INV_KEY (0x0000A50FUL)


/* RESET, SAFE, DRUN, RUN0 modes can not be disabled. Disable others */
#define MC_ME_ME_DIS_ALL (0x0000801DUL)

/* Disable all events */
#define MC_ME_IM_DIS_ALL (0x00000000UL)

/* Acces to mode bits */
#define MC_ME_MODE_MC_MSK  (0xFFFCFF00UL)
/* b11111111111111 00 11111111 0 0 0 0 0000*/

/* DRUN mode configuration value:
 - Flash in normal mode
 - PLL0 and PLL1 are switched ON
 - XOSC is switched ON
 - Internal oscillator is switched ON
 - System clock is PLL1
 - Other fields keep the previous value */
#define MC_ME_DRUN_MC_CONF (0x000300F4UL)

/* */
#define MC_ME_DRUN_MC_XOSCON_MASK (0x00000020UL)
#define MC_ME_DRUN_MC_PLL0ON_MASK (0x00000040UL)
#define MC_ME_DRUN_MC_PLL1ON_MASK (0x00000080UL)

#define MC_ME_DRUN_MC_PWRLVL_VAL   (3UL)
#define MC_ME_DRUN_MC_PWRLVL_SHIFT (28UL)
#define MC_ME_DRUN_MC_PWRLVL_MASK  (0x8FFFFFFFUL)

/* */
#define MC_ME_RUN_PC_VAL (0x000000FEUL)
/* */
#define MC_ME_LP_PC_VAL  (0x00000000UL)
/* */
#define MC_ME_PCTL_VAL  ((uint8_t) 0x00)


#define MC_ME_CADDR_MASK (0xFFFFFFFCUL)

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal datas: ----------------------------------------------- */
extern ts_MC_ME_REG volatile *  v_pt_mc_me_regs;

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */
/* none */



#endif /* BOOT_MC_REG_public_H */
