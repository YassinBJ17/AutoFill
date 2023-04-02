#include "RAMBOOT_Consts.h"
#include "RAMBOOT_Types.h"
#include "RAMBOOT_CopyAndBootBoot.h"
#include "RAMBOOT_ConfigureELBC.h"
#include "RAMBOOT_TestSelfIntegrity.h"
#include "RAMBOOT_RamBootEndMarker.h"
#include "RAMBOOT_JumpToAddress.h"
#include "RAMBOOT_FailMode.h"

/* >RELAX<SYNCHRONe_C_Code_24.4> Called from VECT_Reset, not a local function  */
void RAMBOOT_PostTCBHW_Main(void) /* %RELAX<SYNCHRONe_C_Code_8.1> main() do not need a prototype */
{
   /* Autotest for RAMBOOT */
   RAMBOOT_TestSelfIntegrity( );

   /* Copy, Test and Launch the BOOT soft */
   RAMBOOT_CopyAndBootBoot( );
}
