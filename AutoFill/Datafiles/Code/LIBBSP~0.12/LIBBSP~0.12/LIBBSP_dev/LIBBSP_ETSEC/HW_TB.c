#include "HW_TB.h"


/*************************************************************************************
 *                                                                                   *
 * Nom : HW_TB_wait                                                                  *
 *                                                                                   *
 * Description :                                                                     *
 * Cette fonction permet de generer une tempo en utilisant le Time Base du Power PC  *
 *  Le TBL register est incremente toutes les 40 nanosecondes avec un bus a 100Mhz   *
 *  et donc 25 fois par microseconde                                                 *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *                                                                                   *
 *                                                                                   *
 *************************************************************************************/
void HW_TB_wait (const uint32_t number_of_us) 
{
   uint32_t v_number_of_clock_periods;
   uint32_t v_initial_tbl;
   uint32_t v_current_tbl;
   uint32_t v_number_of_tbl_increments;

   v_number_of_clock_periods = number_of_us*16ul;
   v_initial_tbl = tbl();
   v_number_of_tbl_increments = (uint32_t)0;
   while (v_number_of_tbl_increments <= v_number_of_clock_periods)
   {
       v_current_tbl = tbl();
       v_number_of_tbl_increments = v_current_tbl-v_initial_tbl;
   }
}
