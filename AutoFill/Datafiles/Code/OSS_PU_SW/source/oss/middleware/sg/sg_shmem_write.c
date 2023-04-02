/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Copy designated strain qauge information to shared memory
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/sg/sg_private.h"
#include "middleware/sg/sg_shmem_write.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Copy designated strain qauge information to shared memory */
/* Implements REQ_FADEX_OS_SRD-SG-0040 */
void sg_shmem_write(te_sg_signal p_sensor,
                    ts_sg*       p_value)
{
   switch (p_sensor)
   {
      case e_p3a:
         shmem.s_p3_a = *p_value;
         break;

      case e_p3b:
         shmem.s_p3_b = *p_value;
         break;

      case e_sg1:
      case e_sai1:
         shmem.s_sg1_a = *p_value;
         break;

      case e_sg2:
      case e_sai2:
         shmem.s_sg2_a = *p_value;
         break;

      case e_sg3:
      case e_sai3:
         shmem.s_sg3_b = *p_value;
         break;

      case e_sg4:
         shmem.s_sg4_b = *p_value;
         break;

      case e_sg5b:
      case e_sai4:
         shmem.s_sg5_b = *p_value;
         break;

      default:
         /* Avoid warning */
         break;
   }
}

/* ---------- internal operations: ------------------------------------------ */
