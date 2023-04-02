/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_LG_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void ICDL_LG_FillChannelFirstFunctionnalWord(uint32_t p_ChannelID, const t_CmdCharacteristics * const p_CmdCharacteristics , uint32_t p_data_size)
{
   /* Local variables definition */
   uint32_t v_first_functional_word ;

   /* Local variables initialization */
   v_first_functional_word = 0 ;

   if ( p_ChannelID < K_MAX_NB_CHANNEL )
   {
      /** If the channel ID is valid: */
      /** Encode the channel block length (expressed in bytes) */
      v_first_functional_word = ICDL_LG_EncodeWordOn32Bits( v_first_functional_word,
                                                            p_CmdCharacteristics->u16_ChannelBlockLength + p_data_size,
                                                            K_SHIFT_CHANNEL_BLOCK_LENGTH,
                                                            K_MASK_CHANNEL_BLOCK_LENGTH );

      /**Encode the NB_ARGUMENTS information */
      v_first_functional_word = ICDL_LG_EncodeWordOn32Bits( v_first_functional_word,
                                                            p_CmdCharacteristics->u16_NbArg,
                                                            K_SHIFT_NB_ARG,
                                                            K_MASK_NB_ARG );

      /**Encode the BOOLEAN_DATA information */
      v_first_functional_word = ICDL_LG_EncodeWordOn32Bits( v_first_functional_word,
                                                            p_CmdCharacteristics->bool_Data,
                                                            K_SHIFT_DATA,
                                                            K_MASK_DATA );

      /**Encode the Command identifier*/
      v_first_functional_word = ICDL_LG_EncodeWordOn32Bits( v_first_functional_word,
                                                            p_CmdCharacteristics->u16_Command,
                                                            K_SHIFT_COMMAND,
                                                            K_MASK_COMMAND) ;

      a_ChannelDescriptors[p_ChannelID].p_ElectedFFInfo->u32_CmdCharacteristicsWord = v_first_functional_word ;
   }
   else
   {
      /** otherwise, log an error */
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
