/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_public.h"

/* ---------- include required interface: ----------------------------------- */


/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
ts_CMN_IOSP_BUFFER udpBufferASReception;
/*int8_t udpASBuffer[ICDL_MSG_RX_MAX];*/

/* Create ICDL_NB_OS_PORTS buffers */
int8_t udpOSBuffer[ICDL_NB_OS_PORTS][ICDL_MSG_RX_MAX];

/* UOD buffer */
int8_t udpUODBuffer[ICDL_UOD2_MSG_MAX_SIZE];

uint32_t v_ICDL_WRITE_MODE ;


/* TODO GIVE A CORRECT ADDRESS */
#define SHARED_EXTERN_CRITICAL_ICDL_PARAMS ((t_extern_critical_services_icdl_params * ) 0x40000000)

t_extern_critical_services_icdl_params * const Pt_extern_critical_services_icdl_params = SHARED_EXTERN_CRITICAL_ICDL_PARAMS;

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
