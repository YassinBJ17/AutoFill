/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function calls BISTs.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_MC_public.h"
#include "BOOT_BIST_public.h"
#include "BOOT_BIST_CFEX_public.h"
#include "BOOT_FAULT_public.h"
#include "BOOT_FCCU_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* This function calls BISTs.                              */
/* ---------- provided operation bodies: ------------------------------------ */

void BOOT_BIST_START ( void )
{
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The casts are safe as the structures are used to retrieve all registers which */
   /* start at each respective address. */
   ts_STCU2_REG volatile* pt_stcu2_reg = (ts_STCU2_REG volatile*) STCU2_BASE_ADDR;
   /* }}<SYNCHRONe_C_Code_10.7> */

   /* Do not step through or halt the sequence from this point!! The STCU keys will time out if this happens*/
   /* Write on-line unlock keys to the STCU */
   pt_stcu2_reg->SKC = STCU2_SKC_1;
   pt_stcu2_reg->SKC = STCU2_SKC_2;

   /* MBIST Config - MBIST Will run first */

   /* Configure MBIST Control registers */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> No loss of precision, MB_CTRL[n] register is on 32 bits, such as te_MBIST_CTRL_VALUE enumeration. */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_0] = (uint32_t)e_NEXT_MBIST_1; /* MBIST CTRL00 Run concurrently, next in sequence is MBIST 1 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_1] = (uint32_t)e_NEXT_MBIST_2; /* MBIST CTRL01 Run concurrently, next in sequence is MBIST 2 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_2] = (uint32_t)e_NEXT_MBIST_3; /* MBIST CTRL02 Run concurrently, next in sequence is MBIST 3 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_3] = (uint32_t)e_NEXT_MBIST_4; /* MBIST CTRL03 Run concurrently, next in sequence is MBIST 4 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_4] = (uint32_t)e_NEXT_MBIST_5; /* MBIST CTRL04 Run concurrently, next in sequence is MBIST 5 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_5] = (uint32_t)e_NEXT_MBIST_6; /* MBIST CTRL05 Run concurrently, next in sequence is MBIST 6 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_6] = (uint32_t)e_NEXT_MBIST_7; /* MBIST CTRL06 Run concurrently, next in sequence is MBIST 7 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_7] = (uint32_t)e_NEXT_MBIST_8; /* MBIST CTRL07 Run concurrently, next in sequence is MBIST 8 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_8] = (uint32_t)e_NEXT_MBIST_9; /* MBIST CTRL08 Run concurrently, next in sequence is MBIST 9 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_9] = (uint32_t)e_NEXT_MBIST_10; /* MBIST CTRL09 Run concurrently, next in sequence is MBIST 10 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_10] = (uint32_t)e_NEXT_MBIST_11; /* MBIST CTRL10 Run concurrently, next in sequence is MBIST 11 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_11] = (uint32_t)e_NEXT_MBIST_12; /* MBIST CTRL11 Run concurrently, next in sequence is MBIST 12 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_12] = (uint32_t)e_NEXT_MBIST_13; /* MBIST CTRL12 Run concurrently, next in sequence is MBIST 13 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_13] = (uint32_t)e_NEXT_MBIST_14; /* MBIST CTRL13 Run concurrently, next in sequence is MBIST 14 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_14] = (uint32_t)e_NEXT_MBIST_15; /* MBIST CTRL14 Run concurrently, next in sequence is MBIST 15 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_15] = (uint32_t)e_NEXT_MBIST_16; /* MBIST CTRL15 Run concurrently, next in sequence is MBIST 16 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_16] = (uint32_t)e_NEXT_MBIST_17; /* MBIST CTRL16 Run concurrently, next in sequence is MBIST 17 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_17] = (uint32_t)e_NEXT_MBIST_18; /* MBIST CTRL17 Run concurrently, next in sequence is MBIST 18 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_18] = (uint32_t)e_NEXT_MBIST_19; /* MBIST CTRL18 Run concurrently, next in sequence is MBIST 19 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_19] = (uint32_t)e_NEXT_MBIST_20; /* MBIST CTRL19 Run concurrently, next in sequence is MBIST 20 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_20] = (uint32_t)e_NEXT_MBIST_21; /* MBIST CTRL20 Run concurrently, next in sequence is MBIST 21 */

   /* Write key 2 to service the watchdog */
   pt_stcu2_reg->SKC = STCU2_SKC_2;

   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_21] = (uint32_t)e_NEXT_MBIST_22; /* MBIST CTRL21 Run concurrently, next in sequence is MBIST 22 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_22] = (uint32_t)e_NEXT_MBIST_23; /* MBIST CTRL22 Run concurrently, next in sequence is MBIST 23 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_23] = (uint32_t)e_NEXT_MBIST_24; /* MBIST CTRL23 Run concurrently, next in sequence is MBIST 24 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_24] = (uint32_t)e_NEXT_MBIST_25; /* MBIST CTRL24 Run concurrently, next in sequence is MBIST 25 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_25] = (uint32_t)e_NEXT_MBIST_26; /* MBIST CTRL25 Run concurrently, next in sequence is MBIST 26 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_26] = (uint32_t)e_NEXT_MBIST_27; /* MBIST CTRL26 Run concurrently, next in sequence is MBIST 27 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_27] = (uint32_t)e_NEXT_MBIST_28; /* MBIST CTRL27 Run concurrently, next in sequence is MBIST 28 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_28] = (uint32_t)e_NEXT_MBIST_29; /* MBIST CTRL28 Run concurrently, next in sequence is MBIST 29 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_29] = (uint32_t)e_NEXT_MBIST_30; /* MBIST CTRL29 Run concurrently, next in sequence is MBIST 30 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_30] = (uint32_t)e_NEXT_MBIST_31; /* MBIST CTRL30 Run concurrently, next in sequence is MBIST 31 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_31] = (uint32_t)e_NEXT_MBIST_32; /* MBIST CTRL31 Run concurrently, next in sequence is MBIST 32 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_32] = (uint32_t)e_NEXT_MBIST_33; /* MBIST CTRL32 Run concurrently, next in sequence is MBIST 33 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_33] = (uint32_t)e_NEXT_MBIST_34; /* MBIST CTRL33 Run concurrently, next in sequence is MBIST 34 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_34] = (uint32_t)e_NEXT_MBIST_35; /* MBIST CTRL34 Run concurrently, next in sequence is MBIST 35 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_35] = (uint32_t)e_NEXT_MBIST_36; /* MBIST CTRL35 Run concurrently, next in sequence is MBIST 36 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_36] = (uint32_t)e_NEXT_MBIST_37; /* MBIST CTRL36 Run concurrently, next in sequence is MBIST 37 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_37] = (uint32_t)e_NEXT_MBIST_38; /* MBIST CTRL37 Run concurrently, next in sequence is MBIST 38 */
   /* MBIST CTRL38 Run concurrently, next in sequence is MBIST 39 - This is set to sequential so that the next group runs sequentially to this group */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_38] = (uint32_t)e_NEXT_MBIST_39;
   /* Write key 2 to service the watchdog */
   pt_stcu2_reg->SKC = STCU2_SKC_2;

   /*Group 2- Partitions 39 to 77. Overlyay RAM, IOP RAM, HSM RAM and DMA RAM*/

   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_39] = (uint32_t)e_NEXT_MBIST_40; /* MBIST CTRL39 Run concurrently, next in sequence is MBIST 40 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_40] = (uint32_t)e_NEXT_MBIST_41; /* MBIST CTRL40 Run concurrently, next in sequence is MBIST 41 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_41] = (uint32_t)e_NEXT_MBIST_42; /* MBIST CTRL41 Run concurrently, next in sequence is MBIST 42 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_42] = (uint32_t)e_NEXT_MBIST_43; /* MBIST CTRL42 Run concurrently, next in sequence is MBIST 43 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_43] = (uint32_t)e_NEXT_MBIST_44; /* MBIST CTRL43 Run concurrently, next in sequence is MBIST 44 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_44] = (uint32_t)e_NEXT_MBIST_45; /* MBIST CTRL44 Run concurrently, next in sequence is MBIST 45 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_45] = (uint32_t)e_NEXT_MBIST_46; /* MBIST CTRL45 Run concurrently, next in sequence is MBIST 46 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_46] = (uint32_t)e_NEXT_MBIST_47; /* MBIST CTRL46 Run concurrently, next in sequence is MBIST 47 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_47] = (uint32_t)e_NEXT_MBIST_48; /* MBIST CTRL47 Run concurrently, next in sequence is MBIST 48 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_48] = (uint32_t)e_NEXT_MBIST_49; /* MBIST CTRL48 Run concurrently, next in sequence is MBIST 49 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_49] = (uint32_t)e_NEXT_MBIST_50; /* MBIST CTRL49 Run concurrently, next in sequence is MBIST 50 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_50] = (uint32_t)e_NEXT_MBIST_51; /* MBIST CTRL50 Run concurrently, next in sequence is MBIST 51 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_51] = (uint32_t)e_NEXT_MBIST_52; /* MBIST CTRL51 Run concurrently, next in sequence is MBIST 52 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_52] = (uint32_t)e_NEXT_MBIST_53; /* MBIST CTRL52 Run concurrently, next in sequence is MBIST 53 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_53] = (uint32_t)e_NEXT_MBIST_54; /* MBIST CTRL53 Run concurrently, next in sequence is MBIST 54 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_54] = (uint32_t)e_NEXT_MBIST_55; /* MBIST CTRL54 Run concurrently, next in sequence is MBIST 55 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_55] = (uint32_t)e_NEXT_MBIST_56; /* MBIST CTRL55 Run concurrently, next in sequence is MBIST 56 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_56] = (uint32_t)e_NEXT_MBIST_57; /* MBIST CTRL56 Run concurrently, next in sequence is MBIST 57 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_57] = (uint32_t)e_NEXT_MBIST_58; /* MBIST CTRL57 Run concurrently, next in sequence is MBIST 58 */

   /* Write key 2 to service the watchdog */
   pt_stcu2_reg->SKC = STCU2_SKC_2;

   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_58] = (uint32_t)e_NEXT_MBIST_59; /* MBIST CTRL58 Run concurrently, next in sequence is MBIST 59 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_59] = (uint32_t)e_NEXT_MBIST_60; /* MBIST CTRL59 Run concurrently, next in sequence is MBIST 60 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_60] = (uint32_t)e_NEXT_MBIST_61; /* MBIST CTRL60 Run concurrently, next in sequence is MBIST 61 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_61] = (uint32_t)e_NEXT_MBIST_62; /* MBIST CTRL61 Run concurrently, next in sequence is MBIST 62 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_62] = (uint32_t)e_NEXT_MBIST_63; /* MBIST CTRL62 Run concurrently, next in sequence is MBIST 63 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_63] = (uint32_t)e_NEXT_MBIST_64; /* MBIST CTRL63 Run concurrently, next in sequence is MBIST 64 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_64] = (uint32_t)e_NEXT_MBIST_65; /* MBIST CTRL64 Run concurrently, next in sequence is MBIST 65 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_65] = (uint32_t)e_NEXT_MBIST_66; /* MBIST CTRL65 Run concurrently, next in sequence is MBIST 66 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_66] = (uint32_t)e_NEXT_MBIST_67; /* MBIST CTRL66 Run concurrently, next in sequence is MBIST 67 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_67] = (uint32_t)e_NEXT_MBIST_68; /* MBIST CTRL67 Run concurrently, next in sequence is MBIST 68 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_68] = (uint32_t)e_NEXT_MBIST_69; /* MBIST CTRL68 Run concurrently, next in sequence is MBIST 69 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_69] = (uint32_t)e_NEXT_MBIST_70; /* MBIST CTRL69 Run concurrently, next in sequence is MBIST 70 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_70] = (uint32_t)e_NEXT_MBIST_71; /* MBIST CTRL70 Run concurrently, next in sequence is MBIST 71 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_71] = (uint32_t)e_NEXT_MBIST_72; /* MBIST CTRL71 Run concurrently, next in sequence is MBIST 72 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_72] = (uint32_t)e_NEXT_MBIST_73; /* MBIST CTRL72 Run concurrently, next in sequence is MBIST 73 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_73] = (uint32_t)e_NEXT_MBIST_74; /* MBIST CTRL73 Run concurrently, next in sequence is MBIST 74 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_74] = (uint32_t)e_NEXT_MBIST_75; /* MBIST CTRL74 Run concurrently, next in sequence is MBIST 75 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_75] = (uint32_t)e_NEXT_MBIST_76; /* MBIST CTRL75 Run concurrently, next in sequence is MBIST 76 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_76] = (uint32_t)e_NEXT_MBIST_77; /* MBIST CTRL76 Run concurrently, next in sequence is MBIST 77 */
   pt_stcu2_reg->MB_CTRL[e_MBIST_PART_77] = (uint32_t)e_NEXT_MBIST_78; /* LBIST Partition 0 to run sequentially*/
   /* }}<SYNCHRONe_C_Code_10.7> */

   /* Write key 2 to service the watchdog */
   pt_stcu2_reg->SKC = STCU2_SKC_2;

   /*******************************************************************************************************
    *              Configure MBIST recoverable/unrecoverable fault handling
    *********************************************************************************************************/

   pt_stcu2_reg->MBUFML = STCU2_MBIST_FAULT_RECOV_LOW_VAL; /* Configure all faults as recoverable */
   pt_stcu2_reg->MBUFMM = STCU2_MBIST_FAULT_RECOV_MED_VAL; /* Configure all faults as recoverable */
   pt_stcu2_reg->MBUFMH = STCU2_MBIST_FAULT_RECOV_HIGH_VAL; /* Configure all faults as recoverable */

   /*******************************************************************************************************
    *                          On-line LBIST partition configuration
    *********************************************************************************************************/

   /* Configure Online LBIST partition coverage */

   /* HSM LBIST not launched */
   pt_stcu2_reg->LB[e_LBIST_PART_0].LB_CTRL = (uint32_t)e_NEXT_LBIST_1; /* LBIST CTRL1 Run sequentially, next in sequence is LBIST 2 */
   pt_stcu2_reg->LB[e_LBIST_PART_0].LB_PCS = (uint32_t)e_LBIST_PATTERN_COUNT_0; /* LBIST 1 pattern count */
   pt_stcu2_reg->LB[e_LBIST_PART_0].LB_MISRELSW = (uint32_t)e_LBIST_EVL_0; /* LBIST MISREL Expected Low */
   pt_stcu2_reg->LB[e_LBIST_PART_0].LB_MISREHSW = (uint32_t)e_LBIST_EVH_0; /* LBIST MISREH Expected High */

 
   /* LBIST1 IOP Core Config */
   pt_stcu2_reg->LB[e_LBIST_PART_1].LB_CTRL = (uint32_t)e_NEXT_LBIST_2; /* LBIST CTRL1 Run sequentially, next in sequence is LBIST 2 */
   pt_stcu2_reg->LB[e_LBIST_PART_1].LB_PCS = (uint32_t)e_LBIST_PATTERN_COUNT_1; /* LBIST 1 pattern count */
   pt_stcu2_reg->LB[e_LBIST_PART_1].LB_MISRELSW = (uint32_t)e_LBIST_EVL_1; /* LBIST MISREL Expected Low */
   pt_stcu2_reg->LB[e_LBIST_PART_1].LB_MISREHSW = (uint32_t)e_LBIST_EVH_1; /* LBIST MISREH Expected High */

   /* LBIST2 Peripheral Shell Config */
   pt_stcu2_reg->LB[e_LBIST_PART_2].LB_CTRL = (uint32_t)e_NEXT_LBIST_3; /* LBIST CTRL2 Run sequentially, next in sequence is LBIST 3 */
   pt_stcu2_reg->LB[e_LBIST_PART_2].LB_PCS = (uint32_t)e_LBIST_PATTERN_COUNT_2; /* LBIST 2 pattern count */
   pt_stcu2_reg->LB[e_LBIST_PART_2].LB_MISRELSW = (uint32_t)e_LBIST_EVL_2; /* LBIST MISREL Expected Low */
   pt_stcu2_reg->LB[e_LBIST_PART_2].LB_MISREHSW = (uint32_t)e_LBIST_EVH_2; /* LBIST MISREH Expected High */

   /* LBIST3 Computational Shell Config */
   pt_stcu2_reg->LB[e_LBIST_PART_3].LB_CTRL = (uint32_t)e_NEXT_LBIST_4; /* LBIST CTRL3 Run sequentially, next in sequence is LBIST 4 */
   pt_stcu2_reg->LB[e_LBIST_PART_3].LB_PCS = (uint32_t)e_LBIST_PATTERN_COUNT_3; /* LBIST 3 pattern count */
   pt_stcu2_reg->LB[e_LBIST_PART_3].LB_MISRELSW = (uint32_t)e_LBIST_EVL_3; /* LBIST MISREL Expected Low */
   pt_stcu2_reg->LB[e_LBIST_PART_3].LB_MISREHSW = (uint32_t)e_LBIST_EVH_3; /* LBIST MISREH Expected High */

   /*LBIST4 Computational Shell Config*/
   pt_stcu2_reg->LB[e_LBIST_PART_4].LB_CTRL = (uint32_t)e_NEXT_LBIST_5; /* LBIST CTRL4 Run next set sequentially, next in sequence is LBIST 5*/
   pt_stcu2_reg->LB[e_LBIST_PART_4].LB_PCS = (uint32_t)e_LBIST_PATTERN_COUNT_4; /* LBIST 4 pattern count */
   pt_stcu2_reg->LB[e_LBIST_PART_4].LB_MISRELSW = (uint32_t)e_LBIST_EVL_4; /* LBIST MISREL Expected Low */
   pt_stcu2_reg->LB[e_LBIST_PART_4].LB_MISREHSW = (uint32_t)e_LBIST_EVH_4; /* LBIST MISREH Expected High */

   /* Write key 2 to service the watchdog */
   pt_stcu2_reg->SKC = STCU2_SKC_2;

   /* LBIST5 Peripheral Shell Masters Config */
   pt_stcu2_reg->LB[e_LBIST_PART_5].LB_CTRL = (uint32_t)e_NEXT_LBIST_7; /* LBIST CTRL5 Run sequentially, next in sequence is LBIST 5 */
   pt_stcu2_reg->LB[e_LBIST_PART_5].LB_PCS = (uint32_t)e_LBIST_PATTERN_COUNT_5; /* LBIST 5 pattern count */
   pt_stcu2_reg->LB[e_LBIST_PART_5].LB_MISRELSW = (uint32_t)e_LBIST_EVL_5; /* LBIST MISREL Expected Low */
   pt_stcu2_reg->LB[e_LBIST_PART_5].LB_MISREHSW = (uint32_t)e_LBIST_EVH_5; /* LBIST MISREH Expected High */

   /* GTM LBIST not launched */

   /* LBIST7 Safety Core Config */
   pt_stcu2_reg->LB[e_LBIST_PART_7].LB_CTRL = (uint32_t)e_NEXT_LBIST_8; /* LBIST CTRL7 Run sequentially, next in sequence is LBIST 7*/
   pt_stcu2_reg->LB[e_LBIST_PART_7].LB_PCS = (uint32_t)e_LBIST_PATTERN_COUNT_7; /* LBIST 7 pattern count */
   pt_stcu2_reg->LB[e_LBIST_PART_7].LB_MISRELSW = (uint32_t)e_LBIST_EVL_7; /* LBIST MISREL Expected Low */
   pt_stcu2_reg->LB[e_LBIST_PART_7].LB_MISREHSW = (uint32_t)e_LBIST_EVH_7; /* LBIST MISREH Expected High */

   /* LBIST8 Checker Core Config */
   pt_stcu2_reg->LB[e_LBIST_PART_8].LB_CTRL = (uint32_t)e_NEXT_LBIST_9; /* LBIST CTRL8 Run sequentially, next in sequence is LBIST 8 */
   pt_stcu2_reg->LB[e_LBIST_PART_8].LB_PCS = (uint32_t)e_LBIST_PATTERN_COUNT_8; /* LBIST 8 pattern count */
   pt_stcu2_reg->LB[e_LBIST_PART_8].LB_MISRELSW = (uint32_t)e_LBIST_EVL_8; /* LBIST MISREL Expected Low */
   pt_stcu2_reg->LB[e_LBIST_PART_8].LB_MISREHSW = (uint32_t)e_LBIST_EVH_8; /* LBIST MISREH Expected High */

   /* LBIST9 Computational Core Config */
   pt_stcu2_reg->LB[e_LBIST_PART_9].LB_CTRL = (uint32_t)e_LAST_LBIST; /* LBIST CTRL9 Run concurrently, next in sequence is LBIST 9 */
   pt_stcu2_reg->LB[e_LBIST_PART_9].LB_PCS = (uint32_t)e_LBIST_PATTERN_COUNT_9; /* LBIST 9 pattern count */
   pt_stcu2_reg->LB[e_LBIST_PART_9].LB_MISRELSW = (uint32_t)e_LBIST_EVL_9; /* LBIST MISREL Expected Low */
   pt_stcu2_reg->LB[e_LBIST_PART_9].LB_MISREHSW = (uint32_t)e_LBIST_EVH_9; /* LBIST MISREH Expected High */

   /*******************************************************************************************************
    *                           Configure LBIST STCU2 Fault handling
    *********************************************************************************************************/
   /* Configure all faults as recoverable  */
   pt_stcu2_reg->LBUFM = STCU2_LBIST_FAULT_RECOV_VAL;
   /*  Configure  all faults as recoverable  */
   pt_stcu2_reg->ERR_FM = (uint32_t)0x0;
   /*  Configure LBIST RESET management register  */
   /* Set Global function Reset to occur at end of LBIST 9 */
   pt_stcu2_reg->LBRMSW = STCU2_LBIST_RESET;

   /*******************************************************************************************************
    *             Configure Watchdog Time out and  PMOS MBIST test
    *********************************************************************************************************/

   /* Set Watchdog timeout Config */
   pt_stcu2_reg->WDG = STCU2_WATCHDOG_MAX_TIMEOUT_VAL; /* Watchdog time out to Max value */

   /* Configure pointer to point to first MBIST partition and configure PMOST Test            */
   pt_stcu2_reg->CFG = STCU2_REDUCED_TEST_CONF; /*MBIST PMOS TEST is disabled for The Full online test sequence*/

   /*******************************************************************************************************
    *                          Execute Online BIST
    *********************************************************************************************************/

   /* Start the BIST sequence */
   pt_stcu2_reg->RUNSW.R = STCU2_RUN_CONF;

   while((te_STCU2_BIST_RUNNING_STATE)(pt_stcu2_reg->RUNSW.B.RUNSW) == e_STCU2_BIST_RUNNING_NOT_COMPLETED);

}

/* Implements REQ_[User Project Name]_BOOT-LLR_006 */
void BOOT_BIST_END ( void )
{
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The casts are safe as the structures are used to retrieve all registers which */
   /* start at each respective address. */
   ts_STCU2_REG volatile* pt_stcu2_reg = (ts_STCU2_REG volatile*) STCU2_BASE_ADDR;
   /* }}<SYNCHRONe_C_Code_10.7> */

   uint32_t v_LBIST_index;
   uint32_t v_lbssw = (uint32_t)pt_stcu2_reg->LBSSW;
   uint32_t v_lbesw = (uint32_t)pt_stcu2_reg->LBESW;
   uint32_t v_mbslsw = (uint32_t)pt_stcu2_reg->MBSLSW;
   uint32_t v_mbsmsw = (uint32_t)pt_stcu2_reg->MBSMSW;
   uint32_t v_mbshsw = (uint32_t)pt_stcu2_reg->MBSHSW;
   uint32_t v_mbelsw = (uint32_t)pt_stcu2_reg->MBELSW;
   uint32_t v_mbemsw = (uint32_t)pt_stcu2_reg->MBEMSW;
   uint32_t v_mbehsw = (uint32_t)pt_stcu2_reg->MBEHSW;
   te_CMN_FLAG_QUESTION v_fail = e_CMN_FLAG_NO;

   /* Check STCU2 general error */
   if ( ((uint32_t)pt_stcu2_reg->s_ERR_STAT & STCU2_GENERAL_RESULTS) != (uint32_t)0x0  )
   {
      /* LOG */
      BOOT_FAULT_LOG ( BOOT_FAULT_XBIST,
                       PBIT_ORIGIN,
                       pt_stcu2_reg->s_ERR_STAT,
                       pt_stcu2_reg->ERR_FM,
                       LGBK_FIELD_DEFAULT_VALUE,
                       LGBK_FIELD_DEFAULT_VALUE );
      v_fail = e_CMN_FLAG_YES;
   }

   /*****************************************************************************************************/
   /****************                     LBIST  RESULTS CHECKING                        *****************/
   /*****************************************************************************************************/

   /* Bits 0 to 9 corresponds respectively to LBIST 0 to LBIST 9 */
   /* Checking each bit individually means checking each LBIST*/
   /* LBIST partition 0 and 6 (HSM and GTM) are not tested */
   for ( v_LBIST_index = 0; v_LBIST_index <= 9; v_LBIST_index++ )
   {
      if (v_LBIST_index == 6)
      {
         v_fail = e_CMN_FLAG_NO;
      }
      else if ( ( ( v_lbssw >> v_LBIST_index ) & ( v_lbesw >> v_LBIST_index ) & LBIST_OK ) != LBIST_OK )
      {
         /* LOG */
         BOOT_FAULT_LOG ( ( BOOT_FAULT_LBIST_HSM + v_LBIST_index ),
                          LBIST_ORIGIN,
                          v_lbssw,
                          v_lbesw,
                          LGBK_FIELD_DEFAULT_VALUE,
                          LGBK_FIELD_DEFAULT_VALUE );
         v_fail = e_CMN_FLAG_YES;
      }
   }

   /*****************************************************************************************************/
   /****************                     MBIST  RESULTS CHECKING                        *****************/
   /*****************************************************************************************************/
   /* Check results of MBIST on Core 0 Local Memory */
   if ( ( v_mbslsw & v_mbelsw & MBIST_LMEM_0_OK ) != MBIST_LMEM_0_OK )
   {
      /* LOG */
      BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_LMEM_0,
                       MBIST_ORIGIN,
                       pt_stcu2_reg->MBSLSW,
                       pt_stcu2_reg->MBELSW,
                       LGBK_FIELD_DEFAULT_VALUE,
                       LGBK_FIELD_DEFAULT_VALUE );
      v_fail = e_CMN_FLAG_YES;
   }
   /* Check results of MBIST on Core 1 Local Memory */
   if ( ( v_mbslsw & v_mbelsw & MBIST_LMEM_1_OK ) != MBIST_LMEM_1_OK )
   {
      /* LOG */
      BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_LMEM_1,
                       MBIST_ORIGIN,
                       v_mbslsw,
                       v_mbelsw,
                       LGBK_FIELD_DEFAULT_VALUE,
                       LGBK_FIELD_DEFAULT_VALUE );
      v_fail = e_CMN_FLAG_YES;
   }
   /* Check results of MBIST on Core 2 Local Memory */
   if ( ( v_mbslsw & v_mbelsw & MBIST_LMEM_2_OK ) != MBIST_LMEM_2_OK )
   {
      /* LOG */
      BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_LMEM_2,
                       MBIST_ORIGIN,
                       v_mbslsw,
                       v_mbelsw,
                       LGBK_FIELD_DEFAULT_VALUE,
                       LGBK_FIELD_DEFAULT_VALUE );
      v_fail = e_CMN_FLAG_YES;
   }

   /* Check results of MBIST on Other RAM (on several registers)*/
   if ( ( ( v_mbslsw & v_mbelsw & MBIST_OTHER_RAM_L_OK ) != MBIST_OTHER_RAM_L_OK )
   || ( ( v_mbsmsw & v_mbemsw & MBIST_OTHER_RAM_M_OK ) != MBIST_OTHER_RAM_M_OK )
   || ( ( v_mbshsw & v_mbehsw & MBIST_OTHER_RAM_H_OK ) != MBIST_OTHER_RAM_H_OK ) )
   {
      /* LOG */
      BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_OTHER_RAM,
                       MBIST_ORIGIN,
                       v_mbslsw,
                       v_mbelsw,
                       v_mbsmsw,
                       v_mbemsw );
      v_fail = e_CMN_FLAG_YES;
      /* Ajouter des raw data pour MBSHSW et MBEHSW */
   }

   /* Check results of MBIST on DMA RAM */
   if ( ( v_mbsmsw & v_mbemsw & MBIST_DMA_RMA_OK ) != MBIST_DMA_RMA_OK )
   {
      /* LOG */
      BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_DMA_RMA,
                       MBIST_ORIGIN,
                       v_mbsmsw,
                       v_mbemsw,
                       LGBK_FIELD_DEFAULT_VALUE,
                       LGBK_FIELD_DEFAULT_VALUE );
      v_fail = e_CMN_FLAG_YES;
   }
   /* Check results of MBIST on SRAM */
   if ( ( ( v_mbsmsw & v_mbemsw & MBIST_SRAM_M_OK ) != MBIST_SRAM_M_OK )
   || ( ( v_mbshsw & v_mbehsw & MBIST_SRAM_H_OK ) != MBIST_SRAM_H_OK ) )
   {
      /* LOG */
      BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_SRAM,
                       MBIST_ORIGIN,
                       v_mbsmsw,
                       v_mbemsw,
                       v_mbshsw,
                       v_mbehsw );
      v_fail = e_CMN_FLAG_YES;
   }

   /* Check results of MBIST on BAR */
   if ( ( v_mbshsw & v_mbehsw & MBIST_BAR_OK ) != MBIST_BAR_OK )
   {
      /* LOG */
      BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_BAR,
                       MBIST_ORIGIN,
                       v_mbshsw,
                       v_mbehsw,
                       LGBK_FIELD_DEFAULT_VALUE,
                       LGBK_FIELD_DEFAULT_VALUE );
      v_fail = e_CMN_FLAG_YES;
   }
   /* Check results of MBIST on DBG_RAM */
   if ( ( v_mbshsw & v_mbehsw & MBIST_DBG_RAM_OK ) != MBIST_DBG_RAM_OK )
   {
      /* LOG */
      BOOT_FAULT_LOG ( BOOT_FAULT_MBIST_DBG_RAM,
                       MBIST_ORIGIN,
                       v_mbshsw,
                       v_mbehsw,
                       LGBK_FIELD_DEFAULT_VALUE,
                       LGBK_FIELD_DEFAULT_VALUE );
      v_fail = e_CMN_FLAG_YES;
   }

   /* Clear Reset Status registers  MC_RGM.DES, MC_RGM.FES */
   BOOT_MC_RGM_CLEAR_ERROR ();

   if ( v_fail == e_CMN_FLAG_YES )
   {
      /* Sanction in case of error */
      BOOT_FAULT_INFINITELOOP ();
   }

}


