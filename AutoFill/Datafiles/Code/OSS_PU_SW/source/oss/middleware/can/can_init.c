/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"
#include "middleware/can/can_public.h"
#include "driver/can/can_private.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "driver/can/can_critical_public.h"
#include "memory/memory_address_public.h"
#include "conf/oss_conf_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */
ts_can_conf can2_conf;

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0010 */
void can_init(void)
{
   /* OSS CONF SET */
   /* ---------------------------------------*/
   /* declaration of the struc to retrieve conf in MRAM */
   ts_oss_conf_table * oss_conf;
   /* Declaration of generical configuration */

   /* Set the request for configure to not done so at least one configure is done in the 1st rtc */
   shmem.s_can1_configure.s_configure_on_request = e_not_done;
   shmem.s_can2_configure.s_configure_on_request = e_not_done;

   /* Set Rx frames nb to 1 in init so when the CSS reset it to 0 OSS send all the frames received before 1st rtc */
   shmem.s_can1_rx.s_frames_nb = (uint32_t)1;
   shmem.s_can2_rx.s_frames_nb = (uint32_t)1;

   /* retrieve conf in MRAM */
   oss_conf = (ts_oss_conf_table *)(OSS_CONF_START_ADDR);

   /* initialise the memory map and set MPC the register configuration for CAN1 and CAN2*/
   LIB_MEM_SET( (void*)(CAN1_RAM_ADDR), (int8_t)0x00000000, CAN_CAN_RAM_OFF );
   LIB_MEM_SET( (void*)(CAN2_RAM_ADDR), (int8_t)0x00000000, CAN_CAN_RAM_OFF );

   /* initialise and set the configuration for CAN1 */
   /* Set the genreical can conf with oss can1 configuration */
   can1_conf.s_can_type_id = oss_conf->s_can1_02b_authorized;
   can1_conf.s_can_baudrate = oss_conf->s_can1_baud;
   can1_conf.s_can_adapt_pres = oss_conf->s_can1_adapt_presence;
   can_init_register(CAN1_REG_ADDR, &can1_conf, CAN1_RAM_ADDR);

   /* initialise and set the configuration for CAN2 */
   /* Set the genreical can conf with oss can2 configuration */
   can2_conf.s_can_type_id = oss_conf->s_can2_02b_authorized;
   can2_conf.s_can_baudrate = oss_conf->s_can2_baud;
   can2_conf.s_can_adapt_pres = (uint32_t)1; /* No Adapt res for CAN2 */
   can_init_register(CAN2_REG_ADDR, &can2_conf, CAN2_RAM_ADDR);

}

/* ---------- internal operation bodies: ------------------------------------ */
