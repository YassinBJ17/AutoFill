#include "RAMBOOT_JumpToAddress.h"

void RAMBOOT_JumpToAddress(const uint32_t p_JumpAddress)
{
   asm(" mtctr r3");
   asm(" bctrl");
   (void)(p_JumpAddress); /* Used to remove warning */
}