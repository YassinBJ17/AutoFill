#include "BOOT_JumpToAddress.h"

void BOOT_JumpToAddress(const uint32_t p_JumpAddress)
{
   asm(" mtctr r3");
   asm(" bctrl");
   (void)(p_JumpAddress);  /* Used to remove warning */
}