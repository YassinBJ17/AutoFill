#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "etsec.h"
#include "tbi.h"
#include "LIBBSP_ETSEC_InitAddress.h"
#include "smi.h"

 extern inline u32 in_be32(const volatile u32 __iomem * const addr) {     u32 ret;     __asm__ __volatile__("sync; lwz%U1%X1 %0,%1;\n"                  "twi 0,%0,0;\n"                  "isync" : "=r" (ret) : "m" (*addr));     return ret; }
