#include "middleware/stack_ip/ETH_IP_private.h"
#include "middleware/ethernet/ETH_porting.h"
#include "libtools/memory/LIB_MEM_public.h"

 void ETH_IP_Reassembly_L_CheckTimeOut(void) {    ts_LIB_TIME_CHRONO * pt_chrono;    if ( v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status == e_ETH_IP_FRGMT_IN_PROG  )    {       pt_chrono = &v_ETH_IP_ControlObj.s_RxFragment.s_chrono ;       LIBT_TIME_Update( pt_chrono );       if ( pt_chrono->s_ongoing >= pt_chrono->s_end )       {          v_ETH_IP_ControlObj.s_RxFragment.s_IPFRx_status = e_ETH_IP_FRGMT_TIMEOUT ;       }    } }
