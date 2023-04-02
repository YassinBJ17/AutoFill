/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef ETHCOM_COMMON_H
#define ETHCOM_COMMON_H

/* ---------- include required interface: ----------------------------------- */
/* >RELAX<SYNCHRONe_C_Code_19.19> : Software Architecture constraint. all POS files should include the common POS deftype file.  */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
#define ETH_COMM_MAX_COMM_TAB_SIZE 500ul

/* ---------- provided types: ----------------------------------------------- */

typedef enum
{
   e_ETHCOM_PORT_STAT,
   e_ETHCOM_PORT_ECHO,
   e_ETHCOM_PORT_LOOPBACK,
   e_ETHCOM_NB_PORT
}
te_ETHCOM_PORT;

/* */
typedef struct
{
   CMN_SYSTEM_SIZE_t s_buffer_size;
   int8_t s_buffer[ ETH_COMM_MAX_COMM_TAB_SIZE ];
}
ts_ETHCOM_LINEINFO;





/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */


/* ---------- provided operations: ------------------------------------------ */

extern void ETHCOM_INIT(void) ;
extern void ETHCOM_REFRESH_ACQUISITION(void);
extern void ETHCOM_SENT(te_ETHCOM_PORT const p_port, ts_ETHCOM_LINEINFO * const p_data );
extern void ETHCOM_BUFFER_GET(te_ETHCOM_PORT const p_port, ts_ETHCOM_LINEINFO * const p_data  ) ;
extern void ETHCOM_ESTABLISH_CONNECTION( te_CMN_FLAG_ACTIVATION * const p_done ) ;
extern te_CMN_FLAG_VALIDITY ETHCOM_GET_PORT_STATUS( te_ETHCOM_PORT port );
extern void ETHCOM_Manage_LoopBack (void);

#endif /* ETHCOM_COMMON_H */
