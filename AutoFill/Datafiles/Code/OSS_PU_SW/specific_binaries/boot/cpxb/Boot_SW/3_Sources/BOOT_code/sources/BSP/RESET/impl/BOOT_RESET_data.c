/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Core registers initial configurations
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "BOOT_INTC_public.h"
#include "BOOT_RESET_private.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- provided datas: ------------------------------------------- */

const ts_RESET_MAPPING CORE_0_MAPPING =
{
   /*  MSR: SPV=0,WE=0,CE=0,EE=0,PR=0,FP=0,ME=0,FE0=0,DE=0,FE1=0,IS=0,DS=0,PMM=0,RI=0 */
   0x00000000,
   /*  HID0: EMCP=0,ICR=0,NHR=0,DCLREE=0,DCLRCE=0,CICLRDE=0,MCCLRDE=0,NOPTI=0 */
   0x00000000,
   /*  HID1: HP_NOR=0,HP_NMI=0,ATS=0 */
   0x00000000,
   /* Stack Init */
   0x50800100,
   /* SDA2  */
   /* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> The casts are safe : conversion from address to uint32_t */
   /* There is no loss of precision.*/
   (uint32_t)&_BOOT_SDA2_BASE_,
   /* SDA  */
   0x50800000,
   /* Exception table address */
   (CMN_SYSTEM_ADDR_VAL_t) &BOOT_INTC_VECTOR_TABLE_C0

   /*}}<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>*/
};


const ts_RESET_MAPPING CORE_1_MAPPING =
{
   /*  MSR: SPV=0,WE=0,CE=0,EE=0,PR=0,FP=0,ME=0,FE0=0,DE=0,FE1=0,IS=0,DS=0,PMM=0,RI=0 */
   0x00000000,
   /*  HID0: EMCP=0,ICR=0,NHR=0,DCLREE=0,DCLRCE=0,CICLRDE=0,MCCLRDE=0,NOPTI=0 */
   0x00000000,
   /*  HID1: HP_NOR=0,HP_NMI=0,ATS=0 */
   0x00000000,
   /* Stack Init */
   0x51800100,
   /* SDA2  */
   /* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> The casts are safe : conversion from address to uint32_t */
   /* There is no loss of precision.*/
   (uint32_t)&_BOOT_SDA2_BASE_,
   /* SDA  */
   0x51800000,
   /* Exception table address */
   (CMN_SYSTEM_ADDR_VAL_t) &BOOT_INTC_VECTOR_TABLE_C1
   /*}}<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>*/
};
const ts_RESET_MAPPING CORE_2_MAPPING =
{
   /*  MSR: SPV=0,WE=0,CE=0,EE=0,PR=0,FP=0,ME=0,FE0=0,DE=0,FE1=0,IS=0,DS=0,PMM=0,RI=0 */
   0x00000000,
   /*  HID0: EMCP=0,ICR=0,NHR=0,DCLREE=0,DCLRCE=0,CICLRDE=0,MCCLRDE=0,NOPTI=0 */
   0x00000000,
   /*  HID1: HP_NOR=0,HP_NMI=0,ATS=0 */
   0x00000000,
   /* Stack Init */
   0x52800100,
   /* SDA2  */
   /* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> The casts are safe : conversion from address to uint32_t */
   /* There is no loss of precision.*/
   (uint32_t)&_BOOT_SDA2_BASE_,
   /* SDA  */
   0x52800000,
   /* Exception table address */
   (CMN_SYSTEM_ADDR_VAL_t) &BOOT_INTC_VECTOR_TABLE_C2
   /*}}<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>*/
};

