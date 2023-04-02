/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : TECU inconsistency check function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "middleware/tecu/tecu_private.h"
#include "middleware/rtc/rtc_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU-0001 */
/* TECU inconsistency check between the acquired temperature and the previous acquired temperature */
void tecu_inconsistency_check(const float32_t p_prev_temp,           /* in */
                              const float32_t p_temp,                /* in */
                              uint32_t p_err,                        /* in */
                              boolean_t* p_inconsistency_flag)       /* out */
{
   /* If it's not the first RTC */
   if((uint32_t)1 < rtc_counter)
   {
      /* If the previous temperature is not erroneous */
      if((uint32_t)1 != p_err)
      {
         /* If the current temperature is in the range of [previous temperature - 10degC; previous temperature + 10degC] */
         if(((p_prev_temp - 10) <= p_temp)  && (p_temp <= (p_prev_temp + 10)))
         {
            /* Set the inconsistency flag to no fault */
            *p_inconsistency_flag = (boolean_t)0;
         }
         else
         {
            /* Set the inconsistency flag to fault */
            *p_inconsistency_flag = (boolean_t)1;
         }
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
