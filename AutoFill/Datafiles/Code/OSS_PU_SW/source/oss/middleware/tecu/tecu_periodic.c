/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : TECU periodic function (CBIT)
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU-0001 */
/* Implements REQ_FADEX_OS_SRD-TECU-0010 */
/* Implements REQ_FADEX_OS_SRD-TECU-0020 */
/* TECU periodic function (CBIT) */
void tecu_periodic(const boolean_t channel_is_a)
{

   /* TECU status management function */
   tecu_manage_status(channel_is_a);

   /** NOT REQUIRED FOR THE BLUE LABEL **/
   /* Compute accomodation temperature filter */
   /* tecu_compute_taccom(channel_is_a); */

   /* Compute control unit temperature filter */
   tecu_compute_tcu1(channel_is_a);

   /* Compute control core die temperature filter */
   tecu_compute_tcu2(channel_is_a);

   /* Compute the primary power supply temperature filter */
   tecu_compute_tpsf(channel_is_a);

   /* Compute the overspeed high side temperature filter */
   /* tecu_compute_tohs(channel_is_a); */

   /* Compute the overspeed low side temperature filter */
   /* tecu_compute_tols(channel_is_a); */

   /* Compute the cold junction temperature filter */
   tecu_compute_tcj(channel_is_a);

   /* Compute weighted average TECU final temperature */
   tecu_compute_avg(channel_is_a);


}
/* ---------- internal operations: ------------------------------------------ */
