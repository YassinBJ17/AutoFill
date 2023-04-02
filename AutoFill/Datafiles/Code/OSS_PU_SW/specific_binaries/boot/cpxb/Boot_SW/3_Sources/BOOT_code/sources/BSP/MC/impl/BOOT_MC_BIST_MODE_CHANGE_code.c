/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Configuration for BIST 
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_MC_REG_public.h"
#include "BOOT_BIST_public.h"
#include "BOOT_PINOUT_public.h"
#include "BOOT_PBRIDGE_public.h"
#include "BOOT_PLL_REG_public.h"
#include "BOOT_MEM_public.h"

/* ---------- include required interface: ----------------------------------- */
extern void BOOT_MC_BIST_CORE_RST_ADDR(void);

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */

void BOOT_MC_BIST_MODE_INIT(void)
{
    ts_MC_ME_REG volatile*  pt_mc_me_reg  = (ts_MC_ME_REG volatile*) MC_ME_BASE_ADDR;
    ts_MC_CGM_REG volatile* pt_mc_cgm_reg = (ts_MC_CGM_REG volatile*) MC_CGM_BASE_ADDR;
    ts_SIUL2_tag volatile*  pt_gpio_reg   = (ts_SIUL2_tag volatile*) SIUL2_BASE_ADDR;
    ts_PLLDIG_REG volatile* pt_plldig_reg = (ts_PLLDIG_REG volatile*) PLLDIG_BASE_ADDR;

    // 1. Clear Reset Status registers  MC_RGM.DES, MC_RGM.FES */
    // MC_RGM.DES.R = 0x0180C73B;
    // MC_RGM.FES.R = 0x0180846F;

    // 2. Set up peripheral run modes
    pt_mc_me_reg->s_MC_ME_ME = 0x000085ff;        // Enable the modes Required: pt_mc_me_reg->ME



    // Set RUN Configuration Registers | pt_mc_me_reg->RUN_PC[n]
    pt_mc_me_reg->s_MC_ME_RUN_PC[0]=0x000000FE;      // Peripheral ON in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[1]=0x000000FE;      // Peripheral ON in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[2]=0x000000FE;      // Peripheral ON in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[3]=0x000000FE;      // Peripheral ON in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[4]=0x000000FE;      // Peripheral ON in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[5]=0x000000FE;      // Peripheral ON in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[6]=0x000000FE;      // Peripheral ON in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[7]=0x000000FE;      // Peripheral ON in every mode

    // Only CUT2 & CUT2B
    if(pt_gpio_reg->s_MIDR1 & 0x10){
   *(uint32_t*)0xFC020000 = 0;      // clear FT_DIS and use round-robin on PRAMC
   *(uint32_t*)0xFC028014 &= ~0x01110111; // set PCM_5 - disable automatic clock gating for peripherals
   pt_mc_cgm_reg->s_MC_CGM_SC_DIV_RC = 0x00000001;    // System clock divider ratios will change with next update.  Not required for Cut 1. | pt_mc_cgm_reg->SC_DIV_RC
   pt_mc_cgm_reg->s_MC_CGM_DIV_UPD = 0x80000000;    // System clock divider ratios updated on writing pt_mc_cgm_reg->DIV_UPD_TRIG.  Not required for Cut 1. | pt_mc_cgm_reg->SC_UPD_TYPE
    }

    // 3. Configure System Clock Dividers: PBRIDGE, SXBAR, FXBAR, Core0/1
    // Full speed Core 0/1 = 300MHz.  PLL1 = 600MHz.
    pt_mc_cgm_reg->s_MC_CGM_SC_DC2=0x800B0000;        // PBRIDGE Clock Divide by 12  (50MHz): pt_mc_cgm_reg->SC_DC2
    pt_mc_cgm_reg->s_MC_CGM_SC_DC1=0x80050000;        // SXBAR Clock Divide by 6    (100MHz): pt_mc_cgm_reg->SC_DC1
    pt_mc_cgm_reg->s_MC_CGM_SC_DC0=0x80020000;        // FXBAR Clock Divide by 3    (200MHz): pt_mc_cgm_reg->SC_DC0
    pt_mc_cgm_reg->s_MC_CGM_SC_DC3=0x80010000;        // Core0/1 Clock Divide by 2  (300MHz): pt_mc_cgm_reg->SC_DC3
    pt_mc_cgm_reg->s_MC_CGM_SC_DC4=0x80020000;        // CLKOUT/EBI System Clock Divide by 3   (200MHz/3 = 66.67MHz): pt_mc_cgm_reg->SC_DC4


    // Only CUT2 & CUT2B
    if(pt_gpio_reg->s_MIDR1 & 0x10){
   pt_mc_cgm_reg->s_MC_CGM_DIV_UPD_TRIG = 0xfeedface;       // System clock divider ratio updates triggered.  Not required for Cut 1. | pt_mc_cgm_reg->SC_UPD_TRIG
   while (pt_mc_cgm_reg->s_MC_CGM_DIV_UPD_STAT == 0x10000000);   // Wait for System Clock Divider Update Status == 0. Not required for Cut 1. | pt_mc_cgm_reg->SC_UPD_STAT
    }

    // 4. Configure System Clock Dividers: Enable and configure Aux clocks
    pt_mc_cgm_reg->s_MC_CGM_AC0_SC=0x02000000;    // set PLL0 PHI for Aux Clock 0 |

    pt_mc_cgm_reg->s_MC_CGM_AC0_DC0=0x80040000;    // program Aux Clock 0 divider 0 (peripheral clock) -> Divide by = 4 + 1.  400MHz/5 = 80MHz    | pt_mc_cgm_reg->AC0_DC[0]
    pt_mc_cgm_reg->s_MC_CGM_AC0_DC1=0x80180000;    // program Aux Clock 0 divider 1 (SDADC clock) -> Divide by 24 + 1.  400MHz / 25 = 16MHz       | pt_mc_cgm_reg->AC0_DC[1]
    pt_mc_cgm_reg->s_MC_CGM_AC0_DC2=0x801B0000;    // program Aux Clock 0 divider 2 (SARADC clock) -> Divide by 24 + 1.  400MHz / 28 = 14.6MHz    | pt_mc_cgm_reg->AC0_DC[2]
    pt_mc_cgm_reg->s_MC_CGM_AC0_DC3=0x80040000;    // program Aux Clock 0 divider 3 (DSPI_CLK0) -> Divide by 4 + 1.  400MHz / 5 = 80MHz          | pt_mc_cgm_reg->AC0_DC[3]
    pt_mc_cgm_reg->s_MC_CGM_AC0_DC4=0x80040000;    // program Aux Clock 0 divider 4 (DSPI_CLK1/LIN_CLK) -> Divide by 4 + 1.  400MHz / 5 = 80MHz  | pt_mc_cgm_reg->AC0_DC[4]
    pt_mc_cgm_reg->s_MC_CGM_AC2_DC0=0x80090000;    // program Aux Clock 2 divider 0 (FlexRay) -> Divide by 9 + 1.  400MHz / 10 = 40MHz | pt_mc_cgm_reg->AC2_DC[0]
    pt_mc_cgm_reg->s_MC_CGM_AC2_DC1=0x80090000;    // program Aux Clock 2 divider 1 (SENT) -> Divide by 9 + 1.  400MHz / 10 = 40MHz    | pt_mc_cgm_reg->AC2_DC[1]
    pt_mc_cgm_reg->s_MC_CGM_AC5_DC0=0x80090000;    // program Aux Clock 5 divider 0 (PSI5) -> Divide by 9 + 1.  400MHz / 10 = 40MHz  | pt_mc_cgm_reg->AC5_DC0
    pt_mc_cgm_reg->s_MC_CGM_AC5_DC1=0x80090000;    // program Aux Clock 5 divider 1 (PSI5) -> Divide by 9 + 1.  400MHz / 10 = 40MHz  | pt_mc_cgm_reg->AC5_DC1
    pt_mc_cgm_reg->s_MC_CGM_AC5_DC2=0x80090000;    // program Aux Clock 5 divider 2 (PSI5) -> Divide by 9 + 1.  400MHz / 10 = 40MHz  | pt_mc_cgm_reg->AC5_DC2

    // Enable Output System Clocks to PA15 + PF8
   pt_mc_cgm_reg->s_MC_CGM_AC6_SC=0x02000000;       //Configure SYSCLK0 pinout to be PLL0
   pt_mc_cgm_reg->s_MC_CGM_AC7_SC=0x04000000;       //Configure SYSCLK0 pinout to be PLL1
    pt_mc_cgm_reg->s_MC_CGM_AC6_DC0=0x80270000;    // program Aux Clock 6 Divider 0 (SYSCLK0)   -> Divide PLL0 by 40
    pt_mc_cgm_reg->s_MC_CGM_AC7_DC0=0x80270000;    // program Aux Clock 7 Divider 0 (SYSCLK1)   -> Divide PLL1 by 40



    // CAN Clock Runs from XOSC by Default
    pt_mc_cgm_reg->s_MC_CGM_AC8_DC0=0x80000000;    // program Aux Clock 8 divider 0 (CAN Clock)-> Divide by 1           | pt_mc_cgm_reg->AC8_DC0

    pt_mc_cgm_reg->s_MC_CGM_AC9_SC=0x01000000;       // Select XOSC for Aux Clock 9                     | pt_mc_cgm_reg->AC9_SC.B.SELCTL
    pt_mc_cgm_reg->s_MC_CGM_AC9_DC0=0x80030000;    // program Aux Clock 8 divider 0 (RTI/PIT)-> Divide by 4          | pt_mc_cgm_reg->AC9_DC0

    pt_mc_cgm_reg->s_MC_CGM_AC10_SC=0x06000000;       // Select  XOSC for Aux Clock 10                     | pt_mc_cgm_reg->AC10_SC.B.SELCTL
    pt_mc_cgm_reg->s_MC_CGM_AC10_DC0=0x800F0000;   // program Aux Clock 10 divider 0 (ENET) -> Divide by 15 + 1.  400MHz / 16 = 25MHz  | pt_mc_cgm_reg->AC10_DC0

    // 5. Configure X0SC, PLL0, PLL1
    // Route XOSC to the PLL's - IRC is default | pt_mc_cgm_reg->AC3_SC and pt_mc_cgm_reg->AC4_SC
    pt_mc_cgm_reg->s_MC_CGM_AC3_SC=0x01000000; // Connect XOSC to PLL0
    pt_mc_cgm_reg->s_MC_CGM_AC4_SC=0x01000000; // Connect XOSC to PLL1


    // Configure PLL0 Dividers - 400MHz from 40MHz XOSC
    // fPLL0_VCO = (fpll0_ref * 2 * MFD) / PREDIV
    // fPLL0_VCO = (40 MHz * 2 * 40) / 4
    // fPLL0_VCO = 800 MHz
    // fPLL0_PHI = (fpll0_ref * 2 * MFD) / (PREDIV * RFDPHI * 2)
    // fPLL0_PHI = (40 MHz * 2 * 40) / (4 * 1 * 2)
    // fPLL0_PHI = 400 MHz
//    PLLDIG.PLL0DV.B.RFDPHI = 1;
//    PLLDIG.PLL0DV.B.PREDIV = 4;
//    PLLDIG.PLL0DV.B.MFD = 40;
    pt_plldig_reg->s_PLLDIG_PLL0DV = 0x00014028;

    // Configure PLL1 Dividers - 600MHz from 40MHz XOSC
    // fPLL1_VCO = (fpll1_ref * MFD)
    // fPLL1_VCO = (40 MHz * 30)
    // fPLL1_VCO = 1200 MHz
    // fPLL1_PHI = (fpll1_ref * MFD) / (RFDPHI * 2)
    // fPLL1_PHI = (40 MHz * 30) / (1 * 2)
    // fPLL1_PHI = 600 MHz
//    PLLDIG.PLL1DV.B.RFDPHI = 1;
//    PLLDIG.PLL1DV.B.MFD = 30;
    pt_plldig_reg->s_PLLDIG_PLL1DV = 0x0001001E;


  //  PLLDIG.PLL0CR.B.CLKCFG = 3;   // PLL0 into Normal mode
  //  PLLDIG.PLL1CR.B.CLKCFG = 3; // PLL1 into Normal mode

    // 6. Configure Progressive Clock Switching (PCS) to prevent glitches - 0.05 rate 70 steps.
    pt_mc_cgm_reg->s_MC_CGM_PCS_SDUR = 100;     // set Switch Duration | pt_mc_cgm_reg->PCS_SDUR RM 30.4.1.2.2. Defines the duration of one system clock switch step. Switch Duration = Number of 16MHz clocks * SDUR * k steps
  //  pt_mc_me_reg->DRUN_MC.B.PWRLVL  = 3;  // Configure DRUN power level | pt_mc_me_reg->DRUN_MC       AT Commented out as power level should not be written as byte

    // Set the System Clock. Enable XOSC and PLLs - PLL1 is sysclk, PWRLVL = 3. | pt_mc_me_reg->DRUN_MC
    pt_mc_me_reg->s_MC_ME_DRUN_MC = 0x301300F4;

    // Configure PLL1 PCS switch | See RM section "Progressive system clock switching"
    pt_mc_cgm_reg->s_MC_CGM_PCS_DIVC4 = 0x0353000C;  // Set the Divider Change Initial Value | pt_mc_cgm_reg->PCS_DIVC4.B.INIT
    pt_mc_cgm_reg->s_MC_CGM_PCS_DIVS4 = 31671;     // Set the Divider Start Value | pt_mc_cgm_reg->PCS_DIVS4 this is the clock ramp-up start divider value.
    pt_mc_cgm_reg->s_MC_CGM_PCS_DIVE4 = 31671;     // Set the Divider End Value   | MC_CGM_PCS_DIVE4 this is the clock ramp-down end divider value.

    // Configure PLL0 PCS switch | See RM section "Progressive system clock switching"
    pt_mc_cgm_reg->s_MC_CGM_PCS_DIVC2 = 0x0353000C;  // Set the Divider Change Initial Value | pt_mc_cgm_reg->PCS_DIVC4.B.INIT
     pt_mc_cgm_reg->s_MC_CGM_PCS_DIVS2 = 31671;     // Set the Divider Start Value | pt_mc_cgm_reg->PCS_DIVS4 this is the clock ramp-up start divider value.
    pt_mc_cgm_reg->s_MC_CGM_PCS_DIVE2 = 31671;     // Set the Divider End Value   | MC_CGM_PCS_DIVE4 this is the clock ramp-down end divider value.

    // 7. Initialize e200z Cores
    // Enable cores if running from RAM and not using the BAF
    // Enable Cores - Will start on next mode transistion
    // If core n is enabled, then
    //  - Set pt_mc_me_reg->CADDR[n] to the code start address (see linker file)
    //  - Set pt_mc_me_reg->CCTL[n] to enable core in all modes

    // Enable cores if running from RAM and not using the BAF
    // Enable Cores - Will start on next mode transistion

    pt_mc_me_reg->s_MC_ME_CCTL[0] = 0x00FE;   // Enable Core 2
/*
    MC_ME.CCTL1.R = 0x00FE;   // Enable Core_0
    MC_ME.CCTL2.R = 0x00FE;   // Enable Core_0 Lock Step Core
    MC_ME.CCTL3.R = 0x00FE;   // Enable Core_1
    MC_ME.CCTL4.R = 0x00FE;   // Enable HSM
*/
    // Set Start address for other cores: Will reset and start
    // Flash Addresses
    BOOT_MC_BIST_CORE_RST_ADDR();

   // 8. Perform Mode Entry change into DRUN --- The  System Clock. Enable XOSC and PLLs - PLL1 is sysclk, PWRLVL = 3. | MC_ME.DRUN_MC as configured by MC_ME.DRUN_MC.R = 0x301300F4 at line 159

    // Execute mode change: Re-enter the DRUN mode to start cores, clock tree dividers, PCS, and PLL1
    pt_mc_me_reg->s_MC_ME_MCTL = 0x30005AF0;                    // Write Mode and Key | pt_mc_me_reg->MCTL
    pt_mc_me_reg->s_MC_ME_MCTL = 0x3000A50F;                    // Write Mode and Key inverted | pt_mc_me_reg->MCTL
    while ( (( pt_mc_me_reg->s_MC_ME_GS & (reg32_t)0x08000000UL ) >> 27ul) == e_MC_ME_GS_MTRANS_ON_GOING ); // Wait for mode entry complete | MC_ME.GS[S_MTRANS]
    while ( (( pt_mc_me_reg->s_MC_ME_GS & (reg32_t)0xF0000000UL ) >> 28ul) != e_MC_ME_MODE_DRUN );  // Check DRUN mode entered | MC_ME.GS[S_CURRENT_MODE]
}


void BOOT_MC_BIST_MODE_CHANGE (void)
{
    ts_MC_ME_REG volatile*  pt_mc_me_reg  = (ts_MC_ME_REG volatile*) MC_ME_BASE_ADDR;
    ts_SIUL2_tag volatile*  pt_gpio_reg   = (ts_SIUL2_tag volatile*) SIUL2_BASE_ADDR;
    ts_MC_CGM_REG volatile* pt_mc_cgm_reg = (ts_MC_CGM_REG volatile*) MC_CGM_BASE_ADDR;
    ts_PLLDIG_REG volatile* pt_plldig_reg = (ts_PLLDIG_REG volatile*) PLLDIG_BASE_ADDR;

/* Sequence to reconfigure PLL1 as 200MHz as this is maximum frequency for LBIST testing */
/*  Firstly peripherals are switched off in every mode, as a peripheral on can stop the mode change*/

       // Set RUN Configuration Registers | MC_ME.RUN_PC[n]
    pt_mc_me_reg->s_MC_ME_RUN_PC[0]=0;      // Peripheral OFF in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[1]=0;      // Peripheral OFF in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[2]=0;      // Peripheral OFF in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[3]=0;      // Peripheral OFF in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[4]=0;      // Peripheral OFF in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[5]=0;      // Peripheral OFF in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[6]=0;      // Peripheral OFF in every mode
    pt_mc_me_reg->s_MC_ME_RUN_PC[7]=0;      // Peripheral OFF in every mode




   // Set the System Clock. Enable XOSC and PLLs - PLL1 is sysclk, PWRLVL = 3. | MC_ME.DRUN_MC
    pt_mc_me_reg->s_MC_ME_DRUN_MC = 0x30130031;

    // Execute mode change: Re-enter the DRUN mode to start cores, clock tree dividers, PCS, and PLL1
    pt_mc_me_reg->s_MC_ME_MCTL = 0x30005AF0;                    // Write Mode and Key | pt_mc_me_reg->MCTL
    pt_mc_me_reg->s_MC_ME_MCTL = 0x3000A50F;                    // Write Mode and Key inverted | pt_mc_me_reg->MCTL
//    while(pt_mc_me_reg->s_MC_ME_GS.B.S_MTRANS == 1);              // Wait for mode entry complete | pt_mc_me_reg->GS[S_MTRANS]
//    while(pt_mc_me_reg->s_MC_ME_GS.B.S_CURRENT_MODE != 0x3);      // Check DRUN mode entered |MC_ME.GS[S_CURRENT_MODE]
    while ( (( pt_mc_me_reg->s_MC_ME_GS & (reg32_t)0x08000000UL ) >> 27ul) == e_MC_ME_GS_MTRANS_ON_GOING ); // Wait for mode entry complete | MC_ME.GS[S_MTRANS]
    while ( (( pt_mc_me_reg->s_MC_ME_GS & (reg32_t)0xF0000000UL ) >> 28ul) != e_MC_ME_MODE_DRUN );  // Check DRUN mode entered | MC_ME.GS[S_CURRENT_MODE]


    pt_plldig_reg->s_PLLDIG_PLL0DV = 0x00032030;

    pt_plldig_reg->s_PLLDIG_PLL1DV =0x0030030;



    // Set the System Clock. Enable XOSC and PLLs - PLL1 is sysclk, PWRLVL = 3. | MC_ME.DRUN_MC
    pt_mc_me_reg->s_MC_ME_DRUN_MC = 0x301300F4;

    // Execute mode change: Re-enter the DRUN mode to start cores, clock tree dividers, PCS, and PLL1
    pt_mc_me_reg->s_MC_ME_MCTL = 0x30005AF0;                    // Write Mode and Key | pt_mc_me_reg->MCTL
    pt_mc_me_reg->s_MC_ME_MCTL = 0x3000A50F;                    // Write Mode and Key inverted | pt_mc_me_reg->MCTL
//    while(pt_mc_me_reg->s_MC_ME_GS.B.S_MTRANS == 1);              // Wait for mode entry complete | pt_mc_me_reg->GS[S_MTRANS]
//    while(pt_mc_me_reg->s_MC_ME_GS.B.S_CURRENT_MODE != 0x3);      // Check DRUN mode entered |MC_ME.GS[S_CURRENT_MODE]
    while ( (( pt_mc_me_reg->s_MC_ME_GS & (reg32_t)0x08000000UL ) >> 27ul) == e_MC_ME_GS_MTRANS_ON_GOING ); // Wait for mode entry complete | MC_ME.GS[S_MTRANS]
    while ( (( pt_mc_me_reg->s_MC_ME_GS & (reg32_t)0xF0000000UL ) >> 28ul) != e_MC_ME_MODE_DRUN );  // Check DRUN mode entered | MC_ME.GS[S_CURRENT_MODE]

   // Only CUT2 & CUT2B
    if(pt_gpio_reg->s_MIDR1 & 0x10){
       pt_mc_cgm_reg->s_MC_CGM_SC_DIV_RC = 0x00000001;    // System clock divider ratios will change with next update.  Not required for Cut 1. | MC_CGM.SC_DIV_RC
       pt_mc_cgm_reg->s_MC_CGM_DIV_UPD = 0x80000000;    // System clock divider ratios updated on writing MC_CGM.DIV_UPD_TRIG.  Not required for Cut 1. | MC_CGM.SC_UPD_TYPE
    }



 /* Dividers for 200MHz Self Test */
    pt_mc_cgm_reg->s_MC_CGM_SC_DC2=0x80030000;         /* PBRIDGE Clock Divide by 4  (50MHz) */   ////STCU2 is clocked by the PBRIDGE and must be at a maximum of 50MHz////
  pt_mc_cgm_reg->s_MC_CGM_SC_DC1=0x80010000;         /* SXBAR Clock Divide by 2    (100MHz) */
  pt_mc_cgm_reg->s_MC_CGM_SC_DC0=0x80000000;         /* FXBAR Clock Divide by 1    (200MHz) */
  pt_mc_cgm_reg->s_MC_CGM_SC_DC3=0x80000000;         /* Core0/1 Clock Divide by 1  (200MHz) */
  pt_mc_cgm_reg->s_MC_CGM_SC_DC4=0x80000000;         /* System Clock Divide by 1   (200MHz) */



  // Only CUT2 & CUT2B
    if(pt_gpio_reg->s_MIDR1 & 0x10){
   pt_mc_cgm_reg->s_MC_CGM_DIV_UPD_TRIG = 0xfeedface;       // System clock divider ratio updates triggered.  Not required for Cut 1. | pt_mc_cgm_reg->SC_UPD_TRIG
   while (pt_mc_cgm_reg->s_MC_CGM_DIV_UPD_STAT == 0x10000000);   // Wait for System Clock Divider Update Status == 0. Not required for Cut 1. | MC_CGM.SC_UPD_STAT
    }

    /* Initialize PINOUT */
//        BOOT_PINOUT_INIT();
//        /* Initialize EBI */
//        BOOT_MEM_EBI_INIT();

// Disable all Auxilliary clocks except peripheral clock

    pt_mc_cgm_reg->s_MC_CGM_AC0_DC1=0;    // program Aux Clock 0 divider 1 (SDADC clock)
    pt_mc_cgm_reg->s_MC_CGM_AC0_DC2=0;    // program Aux Clock 0 divider 2 (SARADC clock)
    pt_mc_cgm_reg->s_MC_CGM_AC0_DC3=0;    // program Aux Clock 0 divider 3 (DSPI_CLK0)
    pt_mc_cgm_reg->s_MC_CGM_AC0_DC4=0;    // program Aux Clock 0 divider 4 (DSPI_CLK1/LIN_CLK)
    pt_mc_cgm_reg->s_MC_CGM_AC2_DC0=0;    // program Aux Clock 2 divider 0 (FlexRay)
    pt_mc_cgm_reg->s_MC_CGM_AC2_DC1=0;    // program Aux Clock 2 divider 1 (SENT)
    pt_mc_cgm_reg->s_MC_CGM_AC5_DC0=0;    // program Aux Clock 5 divider 0 (PSI5)
    pt_mc_cgm_reg->s_MC_CGM_AC5_DC1=0;    // program Aux Clock 5 divider 1 (PSI5)
    pt_mc_cgm_reg->s_MC_CGM_AC5_DC2=0;    // program Aux Clock 5 divider 2 (PSI5)
    pt_mc_cgm_reg->s_MC_CGM_AC6_SC=0;       //Configure SYSCLK0 pinout to be PLL0
    pt_mc_cgm_reg->s_MC_CGM_AC7_SC=0;       //Configure SYSCLK0 pinout to be PLL1
    pt_mc_cgm_reg->s_MC_CGM_AC8_DC0=0;    // program Aux Clock 8 divider 0 (CAN Clock)-
    pt_mc_cgm_reg->s_MC_CGM_AC9_DC0=0;    // program Aux Clock 8 divider 0 (RTI/PIT)
    pt_mc_cgm_reg->s_MC_CGM_AC10_DC0=0;   // program Aux Clock 10 divider 0 (ENET)

}

void BOOT_MC_BIST_CORE_RST_ADDR(void)
{
   ts_MC_ME_REG volatile*  pt_mc_me_reg  = (ts_MC_ME_REG volatile*) MC_ME_BASE_ADDR;
   ts_SIUL2_tag volatile*  pt_gpio_reg   = (ts_SIUL2_tag volatile*) SIUL2_BASE_ADDR;

    // Set Start address for other cores: Will reset and start
    // Flash Addresses
    if(pt_gpio_reg->s_MIDR1 & 0x10){    // Only CUT2 & CUT2B
       pt_mc_me_reg->s_MC_ME_CADDR[1] = 0x01200001;  // Core 0
   pt_mc_me_reg->s_MC_ME_CADDR[2] = 0x00000001;  // Core 0_s RMC bit = 1, no ADDR field in Cut 2
   pt_mc_me_reg->s_MC_ME_CADDR[3] = 0x01400001;  // Core 1
   pt_mc_me_reg->s_MC_ME_CADDR[4] = 0x01040001;  // HSM
    }else{
   pt_mc_me_reg->s_MC_ME_CADDR[1] = 0x01010001;  // Core 0
   pt_mc_me_reg->s_MC_ME_CADDR[2] = 0x01010001;  // Core 0_s
   pt_mc_me_reg->s_MC_ME_CADDR[3] = 0x01014001;  // Core 1
   pt_mc_me_reg->s_MC_ME_CADDR[4] = 0x01014001;  // HSM
    }
}
