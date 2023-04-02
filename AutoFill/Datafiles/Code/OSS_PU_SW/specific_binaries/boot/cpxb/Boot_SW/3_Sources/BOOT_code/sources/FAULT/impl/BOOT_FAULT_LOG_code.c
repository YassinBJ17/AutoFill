/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function records the error and enter in fault mode.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */


/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_FAULT_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "logbook_CFEX_public.h"
#include "logbook_fill_event_block_public.h"
#include "logbook_write_critical_log_public.h"
#include "logbook_write_registered_log_public.h"
#include "BOOT_LIBTIME_public.h"
#include "LIB_MATH_public.h"
#include "BOOT_FCCU_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* the timestamp is the value of the pit timer */
uint32_t V_timestamp;

/* Health word indicating the health of the cross channels */
uint32_t V_healthWord;

/* Temp : Calculator internal and external temperature */
uint32_t V_heat;

/* Speed : Rotation speed of engine */
uint32_t V_speed;

/* Mission identifier */
uint32_t V_missionId;

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_[User Project Name]_BOOT-LLR_015  */
void BOOT_FAULT_LOG ( uint32_t const p_ErrorCode,
                             const uint32_t p_originId /* in */,
                             const uint32_t p_rawData1 /* in */,
                             const uint32_t p_rawData2 /* in */,
                             const uint32_t p_rawData3 /* in */,
                             const uint32_t p_rawData4 /* in */)
{
   /* Local variables to store FCCU failures status (registers FCCU_RF_S0 and FCCU_RF_S1)in case of FCCU exception */
   uint32_t v_fccu_rf_s0_val;
   uint32_t v_fccu_rf_s1_val;

   /* Value of the PIT timer when the failure occurs */
   CMN_SYSTEM_TIME_t v_time;
   /* Temporary block event */
   ts_eventBlock V_tmp116EventBlock;

   BOOT_LIBTIME_GET( (CMN_SYSTEM_TIME_t*)&v_time);

   /* Conversion in ms */
   /*Warning, conversion in int64_t is required for the operation to work */
   V_timestamp = (uint32_t)LIB_MATH_UDIV64((int64_t)v_time,(int64_t)1000000);

   /* Fill global variables used in logbook*/

   /* Health word indicating the health of the cross channels */
   V_healthWord = LGBK_FIELD_DEFAULT_VALUE;
   /* Temp : Calculator internal and external temperature */
   V_heat = LGBK_FIELD_DEFAULT_VALUE;
   /* Speed : Rotation speed of engine */
   V_speed = LGBK_FIELD_DEFAULT_VALUE;
   /* Mission identifier */
   V_missionId = LGBK_FIELD_DEFAULT_VALUE;

   if(p_ErrorCode==BOOT_FAULT_FCCU)
   {
      /* Get FCCU failures status by reading registers FCCU_RF_Sx*/
      v_fccu_rf_s0_val = BOOT_FCCU_GET_RF_S0();
      v_fccu_rf_s1_val = BOOT_FCCU_GET_RF_S1();

      /* Clear FCCU faults in FCCU and in source modules (like MEMU, ...) */
      BOOT_FCCU_CLEAR_FAULTS();

      /* Record the FCCU error in Log Area */
      LOGBOOK_FILL_EVENT_BLOCK(FCCU_ORIGIN, p_ErrorCode, LGBK_FIELD_DEFAULT_VALUE, v_fccu_rf_s0_val, v_fccu_rf_s1_val, LGBK_FIELD_DEFAULT_VALUE, LGBK_FIELD_DEFAULT_VALUE, &V_tmp116EventBlock);
   }
   else
   {
      /* Record the error in Log Area */
      LOGBOOK_FILL_EVENT_BLOCK(p_originId, p_ErrorCode, LGBK_FIELD_DEFAULT_VALUE, p_rawData1, p_rawData2, p_rawData3, p_rawData4, &V_tmp116EventBlock);
   }

   /* Write a critical log */
   LOGBOOK_WRITE_CRITICAL_LOG(&V_tmp116EventBlock);

   /* Write a registered log */
   LOGBOOK_WRITE_REGISTERED_LOG(&V_tmp116EventBlock);

}
