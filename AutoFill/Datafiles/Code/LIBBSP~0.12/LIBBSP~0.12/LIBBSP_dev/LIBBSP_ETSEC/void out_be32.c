#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "etsec.h"
#include "tbi.h"
#include "LIBBSP_ETSEC_InitAddress.h"
#include "smi.h"

 inline void out_be32(volatile u32 __iomem * const addr, const u32 val) {     __asm__ __volatile__("sync; stw%U0%X0 %1,%0" : "=m" (*addr) : "r" (val)); }
