#include "RAMBOOT_FailMode.h"
#include "RAMBOOT_Consts.h"
#include "LIBBSP_GPIO.h"
#include "LIBBSP_PLDCMP.h"
#include "LIBBSP_SHM.h"
#include "LIBUTI_COMMON.h"

void RAMBOOT_FailMode(void)
{
   /* Turn on the red and yellow led */
   (void) LIBBSP_GPIO_Configure();
   (void) LIBBSP_GPIO_Write(E_LIBBSP_GPIO_GREEN_LED, FALSE);
   (void) LIBBSP_GPIO_Write(E_LIBBSP_GPIO_YELLOW_LED, TRUE);
   (void) LIBBSP_GPIO_Write(E_LIBBSP_GPIO_RED_LED, TRUE);

   /* PLD COMPAGNON - Fail Mode */
   LIBBSP_SHM_SetMode(E_LIBBSP_SHM_FAILURE_STATE, C_PLD_COMPAGNON_FAIL_SWITCH_GOLDEN);
   LIBBSP_PLDCMP_WriteFailDisc(C_PLD_COMPAGNON_DSO_SYSFAIL_GOLDEN);

   /* Infinite loop */
   LIBUTI_CMN_WaitUntilPowerDown( );
}