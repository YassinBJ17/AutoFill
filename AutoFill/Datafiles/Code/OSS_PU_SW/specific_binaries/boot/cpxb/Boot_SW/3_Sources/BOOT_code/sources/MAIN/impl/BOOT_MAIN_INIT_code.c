/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function manages hardware initializations, PBIT and
 *               the selection of the software to launch.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "logbook_init_public.h"
#include "BOOT_MC_public.h"
#include "BOOT_MEM_public.h"
#include "BOOT_WDG_public.h"
#include "BOOT_PBIT_public.h"
#include "BOOT_BIST_public.h"
#include "BOOT_MAIN_private.h"
#include "BOOT_MAIN_public.h"
#include "BOOT_FAULT_public.h"
#include "BOOT_CONF_public.h"
#include "BOOT_FCCU_public.h"
#include "BOOT_LIBTIME_public.h"

/* ---------- provided datas: ------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_8.15> The memory area is modified in an assembly function which is not */
/* analysed by rulechecker*/
/* {{RELAX<SYNCHRONe_C_Code_10.7> This cast is safe. The value used correspond to addresses in memory */
uint8_t * const c_SRAM_L = SYSTEM_RAM_L;
uint8_t * const c_SRAM_H = SYSTEM_RAM_H;
/* }}<SYNCHRONe_C_Code_8.15,SYNCHRONe_C_Code_10.7> */



/* Implements REQ_[User Project Name]_BOOT-LLR_001 */
void BOOT_MAIN_INIT(void)
{
   uint32_t v_astekconf_idx;
   ts_STCU2_REG volatile* pt_stcu2_reg = (ts_STCU2_REG volatile*) STCU2_BASE_ADDR;
   
   BOOT_WDG_INIT();

   /* reset the clocks : warning after that, TRACE32 is not able to see register */
   BOOT_MC_MODE_INIT();
   /* set the PLL and stabilize it */
   BOOT_MC_SET_PLL();
  
 // /* If Online Self test has completed (Check the Functional Reset Status and Online LBIST status registers)  */
 // if( (BOOT_MC_GET_SELF_TEST_STATUS() == 1) && ( pt_stcu2_reg->LBESW != 0x0 ) )
 // {
 //    /* set the peripheric configuration  */
 //    BOOT_MAIN_PERIPH_INIT( );
 //
 //    /* Read discretes used for mode selection (second read) */
 //    BOOT_CONF_READ_DISCRETES();
 //
 //    /* A complete initialization of SRAM is now possible. It has to be done for further
 //     * operations (Set ASTERIOS Inputs)
 //     */
 //    BOOT_MEM_RAM_INIT(c_SRAM_L, c_SRAM_H );
 //
 //    /* Initialize the logbook */
 //    LOGBOOK_INIT();
 //
 //    /* Log and end Built-In Self Tests */
 //    BOOT_BIST_END();
 //
 // }
 // else
 // {
 //    /* Peripheral minimal configuration */
 //    BOOT_MAIN_PERIPH_SHORT_INIT();
 //    
 //    /* Init and read discretes used for mode selection (first read) */
 //    BOOT_CONF_INIT_ACQUISITION();
 //
 //    /* Initialisation clock and pll for the xbist execution */
 //    BOOT_MC_BIST_MODE_INIT();
 //    BOOT_MC_BIST_MODE_CHANGE(); /* Configure PLLS to 200MHz for MBIST execution */
 //
 //    /* Launch Built-In Self Tests */
 //    BOOT_BIST_START();
 //    /* Execution ends here : a functional reset is raised during BIST execution */
 // }
    
   /* set the peripheric configuration  */
   BOOT_MAIN_PERIPH_INIT( );
   
   /* Init and read discretes used for mode selection (first read) */
   BOOT_CONF_INIT_ACQUISITION();
    
   /* Read discretes used for mode selection (second read) */
   BOOT_CONF_READ_DISCRETES();

   /* A complete initialization of SRAM is now possible. It has to be done for further
    * operations (Set ASTERIOS Inputs)
    */
   BOOT_MEM_RAM_INIT(c_SRAM_L, c_SRAM_H );

   /* Initialize the logbook */
   LOGBOOK_INIT();
 
   /* Initialize the access to the xMEMs */
   BOOT_MEM_LRAM_CTRL_INIT();

   /* Deactivate the ECC mecanism */
   BOOT_MEM_ECC_CONFIG( SRAM_ECC_OFF_VALUE );

   /* Select the binary to launch */
   BOOT_MAIN_ENTRYPOINT_INIT();

   /********************************************************************/
   /****            INTEGRITY AND COMPATIBILITY CHECKS              ****/
   /********************************************************************/
   BOOT_PBIT_SW_MAIN();

   /* If ASTERIOS is launched in the selected mode, additional treatment is done */
   if ( V_BOOT_MAIN_Cores_Running_Mode ==  ((uint32_t)e_MODE_CHOICE_ASTERIOS))
   {
      /* Select the RSF ASTEKCONF to use*/
      v_astekconf_idx = BOOT_MAIN_SELECT_ASTEKCONF();

      /* Set in memory the data required by ASTERIOS */
      BOOT_MAIN_SET_ASTERIOS_INPUT( v_astekconf_idx );
   }

   /* Log FCCU non-critical errors if any  */
   BOOT_FCCU_CHECK_STATUS();

   /* change mode  => DRUN */
   BOOT_MC_CHANGE_MODE_INIT() ;

   /* No more code */
}
