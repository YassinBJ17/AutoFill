/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function sets the DRUN mode.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_MC_public.h"
#include "BOOT_MC_REG_public.h"


/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_037 */
void BOOT_MC_CHANGE_MODE_INIT( void )
{

   reg32_t * pt_mc_me_mode;
   uint32_t v_mode_cfg;
   te_MC_ME_MODE v_mode;
   te_MC_ME_GS_MTRANS v_mode_transition_status;

   v_mode_cfg = MC_ME_DRUN_MC_CONF;
   v_mode = e_MC_ME_MODE_DRUN;

   /* Configure DRUN v_mode */
   pt_mc_me_mode = &v_pt_mc_me_regs->s_MC_ME_DRUN_MC;
   *pt_mc_me_mode = ( (*pt_mc_me_mode) & (reg32_t)MC_ME_MODE_MC_MSK ) | (reg32_t)v_mode_cfg;


   /* select v_mode : first write with key and second write with inverted key */
   /* Note on the left shift: the v_mode is coded on 4 significative bits, so the 28 bits left shift does not */
   /* alterate the value of v_mode ( 32 bits - 28 bits = 4 bits). */
   /* {{RELAX<SYNCHRONe_C_Code_7.2> The value 28 is used to conserve v_mode (4 bits) as the Target Mode (bits #0-3),*/
   /* 0x5AF0 and 0xA50F are respectively the key and inverted key of MC_ME_MCTL */
   /* {{RELAX<SYNCHRONe_C_Code_12.14> Left and right operand don't interfere between each other (respectively bits*/
   /* #0-3 and bits #16-31). */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as v_mode is coded on 4 significative bits, so there is no loss*/
   /* of precision by casting in reg32_t (4 significative bits + 28 left shift bits = 32 bits) */
   v_pt_mc_me_regs->s_MC_ME_MCTL = (reg32_t)( v_mode << 28UL ) | (reg32_t)MC_ME_MCTL_KEY;
   v_pt_mc_me_regs->s_MC_ME_MCTL = (reg32_t)( v_mode << 28UL ) | (reg32_t)MC_ME_MCTL_INV_KEY;
   /* }}<SYNCHRONe_C_Code_7.2> */
   /* }}<SYNCHRONe_C_Code_12.14> */
   /* }}<SYNCHRONe_C_Code_10.7> */

   /* Check v_mode is selected */
   /* poll S_MTRANS flag */
   do
   {
      /* >RELAX<SYNCHRONe_C_Code_12.14> the cast is safe as the enumerate value is either 0 or 1 and the binary*/
      /* operation (MSK + SHIFT) is done in order to retrieve a single bit. */
      /* >RELAX<SYNCHRONe_C_Code_10.3> the cast is safe as the enumerate value is either 0 or 1 and the binary*/
      /* operation (MSK + SHIFT) is done in order to retrieve a single bit. */
      /* >RELAX<SYNCHRONe_C_Code_7.2> the value 0x08000000 and 27 are used in order to retrieve the S_MTRANS*/
      /* (bit #4) bit of MC_ME_GS. */
      v_mode_transition_status = (te_MC_ME_GS_MTRANS)(( v_pt_mc_me_regs->s_MC_ME_GS & (reg32_t)0x08000000UL ) >> 27ul);
      /* TODO : manage timeout */
   }
   while ( v_mode_transition_status == e_MC_ME_GS_MTRANS_ON_GOING );

   /* ============================= */
   /* NOTE POUR LE DEBUG : lorsque la PLL est stabilisee */
   /* METTRE UN POINT D'ARRET ICI ET UN AUTRE SUR LE CODE DU BOOT du COEUR A DEMARRER */
   /* ICI puis faire next step */
   /* ============================= */

}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
