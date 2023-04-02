/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function applies the core configuration
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "BOOT_MC_public.h"
#include "BOOT_MC_REG_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */

/* Implements REQ_[User Project Name]_BOOT-LLR_0xx */
void BOOT_MC_SET_CONF( uint32_t             const p_numCore,
                       const void *         p_start_addr,
                       te_CMN_FLAG_QUESTION const p_ResetCore,
                       uint16_t const       p_cctl )
{
   uint32_t v_RMC ;

   if ( p_ResetCore == e_CMN_FLAG_YES )
   {
      v_RMC = 1ul ;
   }
   else
   {
      v_RMC = 0ul ;
   }

   /* >RELAX<SYNCHRONe_C_Code_11.1> The conversion is used to retrieve the address pointed by the pointer */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : pointer (on void const) to address (uint32_t) */
   v_pt_mc_me_regs->s_MC_ME_CADDR[ p_numCore ] = (reg32_t)(( ((uint32_t)p_start_addr) & MC_ME_CADDR_MASK ) | v_RMC) ;
   v_pt_mc_me_regs->s_MC_ME_CCTL[ p_numCore ] = (uint16_t)p_cctl;
}

/* Implements REQ_[User Project Name]_BOOT-LLR_040 */
void BOOT_MC_SET_PLL( void )
{

   reg32_t * pt_mc_me_mode_register;
   uint32_t v_mode_config;
   te_MC_ME_MODE v_mode_select;
   te_MC_ME_MODE v_current_mode;
   te_MC_ME_GS_MTRANS v_mtrans_status;
   te_MC_ME_GS_CLK_STABLE v_clk_status;

   v_mode_config = MC_ME_DRUN_MC_CONF;
   v_mode_select = e_MC_ME_MODE_DRUN;

   /* Configure DRUN v_mode */
   pt_mc_me_mode_register = &v_pt_mc_me_regs->s_MC_ME_DRUN_MC;
   *pt_mc_me_mode_register = ( (*pt_mc_me_mode_register) & (reg32_t)MC_ME_MODE_MC_MSK ) | (reg32_t)v_mode_config;


   /* select v_mode : first write with key and second write with inverted key */
   /* Note on the left shift: the v_mode is coded on 4 significative bits, so the 28 bits left shift does not */
   /* alterate the value of v_mode ( 32 bits - 28 bits = 4 bits). */
   /* {{RELAX<SYNCHRONe_C_Code_7.2> The value 28 is used to conserve v_mode (4 bits) as the Target Mode (bits #0-3),*/
   /* 0x5AF0 and 0xA50F are respectively the key and inverted key of MC_ME_MCTL */
   /* {{RELAX<SYNCHRONe_C_Code_12.14> Left and right operand don't interfere between each other (respectively bits*/
   /* #0-3 and bits #16-31). */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as v_mode is coded on 4 significative bits, so there is no loss*/
   /* of precision by casting in reg32_t (4 significative bits + 28 left shift bits = 32 bits) */
   v_pt_mc_me_regs->s_MC_ME_MCTL = (reg32_t)( v_mode_select << 28UL ) | (reg32_t)MC_ME_MCTL_KEY;
   v_pt_mc_me_regs->s_MC_ME_MCTL = (reg32_t)( v_mode_select << 28UL ) | (reg32_t)MC_ME_MCTL_INV_KEY;
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
      /* >RELAX<SYNCHRONe_C_Code_7.2> the value 0x08000000 and 27 are used in order to retrieve the S_MTRANS (bit*/
      /* #4) bit of MC_ME_GS. */
      v_mtrans_status = (te_MC_ME_GS_MTRANS)(( v_pt_mc_me_regs->s_MC_ME_GS & (reg32_t)0x08000000UL ) >> 27ul);
      /* TODO : manage timeout */
   }
   while ( v_mtrans_status == e_MC_ME_GS_MTRANS_ON_GOING );

   /* ============================= */
   /* NOTE POUR LE DEBUG : lorsque la PLL est stabilisee */
   /* METTRE UN POINT D'ARRET ICI ET UN AUTRE SUR LE CODE DU BOOT du COEUR A DEMARRER */
   /* ICI puis faire next step */
   /* ============================= */

   /* Poll S_CURRENT_MODE flag */
   do
   {
      /* >RELAX<SYNCHRONe_C_Code_12.14> the cast is safe as the enumerate value is encoded in 4 bits and the binary*/
      /* operation (MSK + SHIFT) is done in order to retrieve 4 bits. */
      /* >RELAX<SYNCHRONe_C_Code_10.3> the cast is safe as the enumerate value is either 0 or 1 and the binary*/
      /* operation (MSK + SHIFT) is done in order to retrieve a single bit. */
      /* >RELAX<SYNCHRONe_C_Code_7.2> the value 0xF0000000 and 28 are used in order to retrieve the S_CURRENT_MODE*/
      /* (bit #0-3) of MC_ME_GS */
      v_current_mode = (te_MC_ME_MODE)(( v_pt_mc_me_regs->s_MC_ME_GS & (reg32_t)0xF0000000UL ) >> 28ul);
      /* TODO : manage timeout */
   }
   while ( v_current_mode != e_MC_ME_MODE_DRUN );

   /* poll S_PLL0 flag to wait for stabilization */
   do
   {
      /* >RELAX<SYNCHRONe_C_Code_12.14> the cast is safe as the enumerate value is either 0 or 1 and the binary*/
      /* operation (MSK + SHIFT) is done in order to retrieve a single bit. */
      /* >RELAX<SYNCHRONe_C_Code_10.3> the cast is safe as the enumerate value is either 0 or 1 and the binary*/
      /* operation (MSK + SHIFT) is done in order to retrieve a single bit. */
      /* >RELAX<SYNCHRONe_C_Code_7.2> the value 0x00000040 and 6 are used in order to retrieve the S_PLL0 (bit #25)*/
      /* of MC_ME_GS */
      v_clk_status = (te_MC_ME_GS_CLK_STABLE)(( v_pt_mc_me_regs->s_MC_ME_GS & (reg32_t)0x00000040UL ) >> 6ul);
      /* TODO : manage timeout */
   }
   while ( v_clk_status == e_MC_ME_GS_CLK_NOT_STABLE );

   /* poll S_PLL1 flag to wait for stabilization */
   do
   {
      /* >RELAX<SYNCHRONe_C_Code_12.14> the cast is safe as the enumerate value is either 0 or 1 and the binary*/
      /* operation (MSK + SHIFT) is done in order to retrieve a single bit. */
      /* >RELAX<SYNCHRONe_C_Code_10.3> the cast is safe as the enumerate value is either 0 or 1 and the binary*/
      /* operation (MSK + SHIFT) is done in order to retrieve a single bit. */
      /* >RELAX<SYNCHRONe_C_Code_7.2> the value 0x00000080 and 7 are used in order to retrieve the S_PLL1 (bit #24)*/
      /* of MC_ME_GS */
      v_clk_status = (te_MC_ME_GS_CLK_STABLE)(( v_pt_mc_me_regs->s_MC_ME_GS & (reg32_t)0x00000080UL ) >> 7ul);
      /* TODO : manage timeout */
   }
   while ( v_clk_status == e_MC_ME_GS_CLK_NOT_STABLE );
   /* ============================= */
   /* NOTE POUR LE DEBUG */
   /* METTRE UN POINT D'ARRET ICI ET UN AUTRE SUR LE CODE DU BOOT du COEUR A DEMARRER */
   /* ICI puis faire next step */
   /* ============================= */

}
