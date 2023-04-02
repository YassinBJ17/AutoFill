/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/hpdisc/hpdisc_private.h"
#include "middleware/hpdisc/hpdisc_process_raw.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
/* Mask defining normaly close switches */
#define C_HP_NORMALY_CLOSE ((uint16_t)0x0002)

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */
/* Process raw data from interfaces */
uint16_t hpdisc_process_raw(uint8_t p_task, ts_hpdisk_item * p_item)
{
   uint16_t s_OutValue;

   switch (p_task)
   {
   case C_RAW_CLOSE:
      if ((p_item->s_io_mask & C_HP_NORMALY_CLOSE) != (uint16_t)0)
         s_OutValue = *p_item->s_io_pointer & p_item->s_io_mask;
      else
         s_OutValue = *p_item->s_io_pointer | p_item->s_io_mask;

      *p_item->s_io_pointer = s_OutValue;
      break;

   case C_RAW_OPEN:
      if ((p_item->s_io_mask & C_HP_NORMALY_CLOSE) != (uint16_t)0)
         s_OutValue = *p_item->s_io_pointer | (uint16_t)(~p_item->s_io_mask);
      else
         s_OutValue = *p_item->s_io_pointer & (uint16_t)(~p_item->s_io_mask);

      *p_item->s_io_pointer = s_OutValue;
      break;

   case C_RAW_READ:
      if ((p_item->s_io_mask & C_HP_NORMALY_CLOSE) != (uint16_t)0)
         s_OutValue = (uint16_t)((*p_item->s_io_pointer & (uint16_t)(~p_item->s_io_mask)) == 0);
      else
         s_OutValue = (uint16_t)((*p_item->s_io_pointer & p_item->s_io_mask) != 0);
      break;

   default:
      /* avoid warnings */
      s_OutValue = (uint16_t)0;
      break;
   }

   return s_OutValue;
}

