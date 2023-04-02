/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function configures the SMPU_0 depending on the
 *               selected mode (run mode or dataloader mode).
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "BOOT_MEM_public.h"
#include "BOOT_MAIN_public.h"
#include "BOOT_CONF_public.h"
/* ---------- internal define constants: ------------------------------------ */
/* Forbidden access of rgd0 for core_2 */
#define SMPU_RGD0_WORD0_PBIT          (0x10000000ul)
#define SMPU_RGD0_WORD1_PBIT          (0x1FFFFFFFul)
#define SMPU_RGD0_WORD2_FTM0_PBIT     (0x00000000ul)

/* Authorized access of rgd1 et rgd2 for core_2 */
#define SMPU_RGD1_WORD0_PBIT          (0x0ul)
#define SMPU_RGD1_WORD1_PBIT          (0x0FFFFFFFul)
#define SMPU_RGD1_WORD2_FTM0_PBIT     (0x0C000C00ul)

#define SMPU_RGD2_WORD0_PBIT          (0x20000000ul)
#define SMPU_RGD2_WORD1_PBIT          (0xFFFFFFFFul)
#define SMPU_RGD2_WORD2_FTM0_PBIT     (0x0C000C00ul)

#define SMPU_RGDx_WORD3_PBIT             (0x00000001ul)

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */

/* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as the structure is used to retrieve all SMPU registers which*/
/* start at this address. */
ts_SMPU_REG volatile * const pt_smpu_reg  = (ts_SMPU_REG volatile *) SMPU_BASE_ADDR;

/* ---------- provided operations: ------------------------------------------- */
/* Implements REQ_[User Project Name]_BOOT-LLR_047 */
void BOOT_MEM_SMPU_CONFIG( void )
{
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as the structure is used to retrieve all SMPU registers which*/
   /* start at this address. */

   const ts_SMPU_CONF* c_pt_SMPU_CONF = &(c_CONF_MODES[V_BOOT_MAIN_Cores_Running_Mode].s_smpu_config);

   /*{{RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision when casting from uint32_t (unsigned long) to*/
   /* reg32_t (volatile unsigned long) : the volatile qualifier doesn't affect precision */
   /*Disable SMPU for the configuration */
   pt_smpu_reg->s_SMPU_CESR0 = (reg32_t)SMPU_CESR0_DIS;

   /* Configure Start and End addresses of regions*/
   pt_smpu_reg->s_SMPU_RGD0_WORD0 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD0_WORD0;
   pt_smpu_reg->s_SMPU_RGD0_WORD1 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD0_WORD1;


   pt_smpu_reg->s_SMPU_RGD1_WORD0 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD1_WORD0;
   pt_smpu_reg->s_SMPU_RGD1_WORD1 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD1_WORD1;


   pt_smpu_reg->s_SMPU_RGD2_WORD0 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD2_WORD0;
   pt_smpu_reg->s_SMPU_RGD2_WORD1 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD2_WORD1;


   pt_smpu_reg->s_SMPU_RGD3_WORD0 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD3_WORD0;
   pt_smpu_reg->s_SMPU_RGD3_WORD1 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD3_WORD1;

   /* Configure bus masters access rights */
   pt_smpu_reg->s_SMPU_RGD0_WORD2_FTM0 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD0_WORD2_FTM0;
   pt_smpu_reg->s_SMPU_RGD1_WORD2_FTM0 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD1_WORD2_FTM0;
   pt_smpu_reg->s_SMPU_RGD2_WORD2_FTM0 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD2_WORD2_FTM0;
   pt_smpu_reg->s_SMPU_RGD3_WORD2_FTM0 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD3_WORD2_FTM0;


   /* Set Region Descriptor as valid region */
   pt_smpu_reg->s_SMPU_RGD0_WORD3 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD0_WORD3;
   pt_smpu_reg->s_SMPU_RGD1_WORD3 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD1_WORD3;
   pt_smpu_reg->s_SMPU_RGD2_WORD3 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD2_WORD3;
   pt_smpu_reg->s_SMPU_RGD3_WORD3 = (reg32_t)c_pt_SMPU_CONF->s_CONF_SMPU_RGD3_WORD3;

   /* Last, enable the module */
   pt_smpu_reg->s_SMPU_CESR0 = (reg32_t)SMPU_CESR0;

   /*}} <SYNCHRONe_C_Code_10.7> */
}

/* Implements REQ_[User Project Name]_BOOT-LLR_047 */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as the structure is used to retrieve all SMPU registers which*/
   /* start at this address. */


   /*Disable SMPU for the configuration */

   /* Configure Start and End addresses of regions*/



   /* Configure bus masters access rights */

   /* Set Region Descriptor as valid region */

   /* Last, enable the module */


/* Implements REQ_[User Project Name]_BOOT-LLR_047 */
void BOOT_MEM_SMPU_DISABLE (void)
{

   /*Disable SMPU */
   pt_smpu_reg->s_SMPU_CESR0 = (reg32_t)SMPU_CESR0_DIS;

}
