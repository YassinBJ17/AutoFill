/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : this function is used to swap the endianess of the data
 * -------------------------------------------------------------------------- */



/* ---------- include provided interface: ----------------------------------- */

#include "driver/can/can_critical_private.h"
#include "middleware/ovsp/ovsp_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0030 */
/* Implements REQ_FADEX_OS_SRD-CAN-0040 */
/* Implements REQ_FADEX_OS_SRD-CAN-0050 */

void swap_data_cmd(const uint32_t* p_data_src_addr,
                   const uint8_t* p_data_dest_addr)
{
   /* Source address */
   uint32_t * p_data_src;
   /* data source */
   uint32_t   src_data;
   /* Destination address */
   uint32_t * p_data_dst;
   uint32_t   idx_src;

   /* Store source and destination address in local variables */
   p_data_src = (uint32_t*)p_data_src_addr;
   p_data_dst = (uint32_t*)p_data_dest_addr;


   /* Data can be written once and only by 32 bits accesses  */
   /* 64 bit data = 2 * 32 bit swap                          */
   for (idx_src = (uint32_t)0; idx_src < SWAP_FRAME_DATA_IT_MAX; idx_src++)
   {
      src_data = *p_data_src;
      /* 32bit word endianess swap :                */
      /* for instance AA56DD12 will become 12DD56AA */
      /* 1-            AA56DD12 >> 24 = ......AA    */
      /* 1.5-                          &000000ff    */
      /*                              = 000000AA    */
      /* 2-            AA56DD12 << 8  = 56DD12..    */
      /* 2.5-                          &00ff0000    */
      /*                              = 00DD0000    */
      /* 3-            AA56DD12 >> 8  = ..AA56DD    */
      /* 3.5-                          &0000ff00    */
      /*                              = 00005600    */
      /* 4-            AA56DD12 << 24 = 12......    */
      /* 4.5-                          &ff000000    */
      /*                              = 12000000    */
      /* 5-              000000AA |                 */
      /*                 00DD0000 |                 */
      /*                 00005600 |                 */
      /*                 12000000 |                 */
      /*-----------------------------------------   */
      /*      =          12DD56AA                   */
      *p_data_dst = ((src_data>>24)&0xff) |
                    ((src_data<<8)&0xff0000) |
                    ((src_data>>8)&0xff00) |
                    ((src_data<<24)&0xff000000);

      p_data_dst++;
      p_data_src++;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */

