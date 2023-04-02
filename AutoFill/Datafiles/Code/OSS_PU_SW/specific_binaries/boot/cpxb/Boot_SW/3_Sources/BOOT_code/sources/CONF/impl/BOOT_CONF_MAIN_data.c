/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Core mode configuration table
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_CONF_public.h"
/* ---------- include required interface: ----------------------------------- */
/* ---------- internal define constants: ------------------------------------ */

/* SMPU Registers Initialization values */
#define CONF_MEM_SMPU_RGD0_WORD0             (0x00000000ul)
#define CONF_MEM_SMPU_RGD0_WORD1             (0x0FFFFFFFul)
#define CONF_MEM_SMPU_RGD0_WORD2_FTM0_RUN    (0xFFFFFF33ul)
#define CONF_MEM_SMPU_RGD1_WORD0             (0x20000000ul)
#define CONF_MEM_SMPU_RGD1_WORD1             (0x5FFFFFFFul)
#define CONF_MEM_SMPU_RGD1_WORD2_FTM0_RUN    (0xFFFFFF33ul)
#define CONF_MEM_SMPU_RGD2_WORD0             (0x60000000ul)
#define CONF_MEM_SMPU_RGD2_WORD1             (0xEFFFFFFFul)
#define CONF_MEM_SMPU_RGD2_WORD2_FTM0_RUN    (0xFFFFFF33ul)
#define CONF_MEM_SMPU_RGD3_WORD0             (0xF0000000ul)
#define CONF_MEM_SMPU_RGD3_WORD1             (0xFFFFFFFFul)
#define CONF_MEM_SMPU_RGD3_WORD2_FTM0_RUN    (0xFFFFFF33ul)
#define CONF_MEM_SMPU_RGDx_WORD2_FTM0_DTLD   (0x0FFFCF33ul)
#define CONF_MEM_SMPU_RGDx_WORD3             (0x00000001ul)

/* Software Entry points */

#define ASTERIOS_START                       ((uint32_t)0x01000100)
#define DTLD_START                           ((uint32_t)0x016C4000)

/* SPEFSCR Cores configuration */
#define CONF_SPEFSCR_VAL                     (0x0UL)

/* ASTERIOS inputs */
#define AST_BOOT_CONFIG_DISABLE_PROFILING    ((uint32_t)0x457319E0)
#define AST_NULL_EARLY_ERROR_HANDLER         ((uint32_t)0)
#define NB_CORE_RUNNING_ASTEK                ((uint32_t)3)
#define RTC_FPGA_PERIOD                      ((uint32_t)40)
#define RTC_FPGA_TIMEOUT                     ((uint32_t) 10)




/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* */
uint32_t V_BOOT_UOD_ACTIVATION_FLAG_ADDR;
uint32_t V_BOOT_OPERATIONAL_4_PERIODIC_TASK;
uint32_t V_BOOT_OPERATIONAL_1_PERIODIC_TASK;


const ts_MAIN_ASTERIOS_RUNTIME_CONF c_CONF_ASTEK_tab[CONF_ASTEKCONF_NB] =
{
   /* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> The casts are safe since the structure is used to*/
   /* identify the address of functions. There is no loss of precision. Moreover, the pointer is not */
   /* converted to a size inferior of what is it. The conversion is valid. */
   {
	  /* Validity flag for CSS_PU_TASK_CONFIG - G3 */
	  (const uint32_t) &V_BOOT_OPERATIONAL_4_PERIODIC_TASK,
	  /* RSF address for 4 periodic task */
	  0x01080000,
#ifdef ASTERIOS_K193
	  //AST_BOOT_CONFIG_DISABLE_PROFILING,
	  0,
	  AST_NULL_EARLY_ERROR_HANDLER,
	  NB_CORE_RUNNING_ASTEK,
	  {
		  0,
		  1,
		  2
	  }
#endif
    },
	{
      /* Validity flag for UOD */
	  (const uint32_t) &V_BOOT_UOD_ACTIVATION_FLAG_ADDR,
      /* Default Address of the ASTEKCONF */
      0x01660000,
#ifdef ASTERIOS_K193
      //AST_BOOT_CONFIG_DISABLE_PROFILING,
	  0,
      AST_NULL_EARLY_ERROR_HANDLER,
      NB_CORE_RUNNING_ASTEK,
      {
          0,
          1,
          2
      }
#endif
   },
   {
      /* No address for the Validity Flag - G4 */
	  (const uint32_t) &V_BOOT_OPERATIONAL_1_PERIODIC_TASK,
      /* RSF address for 1 periodic task */
      0x01040000,
#ifdef ASTERIOS_K193
      //AST_BOOT_CONFIG_DISABLE_PROFILING,
	  0,
      AST_NULL_EARLY_ERROR_HANDLER,
      NB_CORE_RUNNING_ASTEK,
      {
          0,
          1,
          2
      }
#endif
   }
   /* }}<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */
};
const uint32_t c_CONF_RTC_PERIOD = RTC_FPGA_PERIOD;
const uint32_t c_CONF_RTC_TIMEOUT= RTC_FPGA_TIMEOUT;


const ts_MAIN_MODE_ELT c_CONF_MODES[e_MODE_NB] =
{
   /*********************************************************************/
   /**                 CONFIGURATION OF THE RUN MODE                   **/
   /*********************************************************************/
   {
      /*        SMPU CONFIGURATION        */
      {
         CONF_MEM_SMPU_RGD0_WORD0,
         CONF_MEM_SMPU_RGD0_WORD1,
         CONF_MEM_SMPU_RGD0_WORD2_FTM0_RUN,
         CONF_MEM_SMPU_RGDx_WORD3,
         CONF_MEM_SMPU_RGD1_WORD0,
         CONF_MEM_SMPU_RGD1_WORD1,
         CONF_MEM_SMPU_RGD1_WORD2_FTM0_RUN,
         CONF_MEM_SMPU_RGDx_WORD3,
         CONF_MEM_SMPU_RGD2_WORD0,
         CONF_MEM_SMPU_RGD2_WORD1,
         CONF_MEM_SMPU_RGD2_WORD2_FTM0_RUN,
         CONF_MEM_SMPU_RGDx_WORD3,
         CONF_MEM_SMPU_RGD3_WORD0,
         CONF_MEM_SMPU_RGD3_WORD1,
         CONF_MEM_SMPU_RGD3_WORD2_FTM0_RUN,
         CONF_MEM_SMPU_RGDx_WORD3,
      }
      ,

      /* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> The casts are safe since the structure is used to*/
      /* identify the address of functions. There is no loss of precision. Moreover, the pointer is not */
      /* converted to a size inferior of what is it. The conversion is valid. */

      /*        CORES CONFIGURATION        */
      {
         /* CORE_2 */
         { 
            e_CORE_DESACTIVATE,  
            (uint32_t)NULL                 
         }
         , /* CORE_0 */  
         { 
            e_CORE_RESET,        
            ASTERIOS_START
         }
         , /* CORE_CHK */ 
         { 
            e_CORE_DESACTIVATE,  
            (uint32_t)NULL
         }
         , /* CORE_1 */
         { 
            e_CORE_RESET,        
            ASTERIOS_START                  
         }
      }
      ,

      /* }}<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */

      /*        FLOATING-POINT CONFIGURATION        */
      CONF_SPEFSCR_VAL

   }
   ,
   /*********************************************************************/
   /**             CONFIGURATION OF THE DATALOADER MODE                **/
   /*********************************************************************/
   {
      /*        SMPU CONFIGURATION        */
      {
         CONF_MEM_SMPU_RGD0_WORD0,
         CONF_MEM_SMPU_RGD0_WORD1,
         CONF_MEM_SMPU_RGDx_WORD2_FTM0_DTLD,
         CONF_MEM_SMPU_RGDx_WORD3,
         CONF_MEM_SMPU_RGD1_WORD0,
         CONF_MEM_SMPU_RGD1_WORD1,
         CONF_MEM_SMPU_RGDx_WORD2_FTM0_DTLD,
         CONF_MEM_SMPU_RGDx_WORD3,
         CONF_MEM_SMPU_RGD2_WORD0,
         CONF_MEM_SMPU_RGD2_WORD1,
         CONF_MEM_SMPU_RGDx_WORD2_FTM0_DTLD,
         CONF_MEM_SMPU_RGDx_WORD3,
         CONF_MEM_SMPU_RGD3_WORD0,
         CONF_MEM_SMPU_RGD3_WORD1,
         CONF_MEM_SMPU_RGDx_WORD2_FTM0_DTLD,
         CONF_MEM_SMPU_RGDx_WORD3,
      }
      ,

      /* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> The casts are safe since the structure is used to*/
      /* identify the address of functions. There is no loss of precision. Moreover, the pointer is not */
      /* converted to a size inferior of what is it. The conversion is valid. */

      /*        CORES CONFIGURATION        */

      {    
         /* CORE_2 */
         { 
            e_CORE_RESET,  
            DTLD_START
         }
         , /* CORE_0 */  
         { 
            e_CORE_DESACTIVATE,  
            (uint32_t)NULL                     
         }
         , /* CORE_CHK */ 
         { 
            e_CORE_DESACTIVATE,  
            (uint32_t)NULL                   
         }
         , /* CORE_1 */
         { 
            e_CORE_DESACTIVATE,  
            (uint32_t)NULL                  
         }
      }
      ,

      /* }}<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */

      /*        FLOATING-POINT CONFIGURATION        */
      CONF_SPEFSCR_VAL
   }

};

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
