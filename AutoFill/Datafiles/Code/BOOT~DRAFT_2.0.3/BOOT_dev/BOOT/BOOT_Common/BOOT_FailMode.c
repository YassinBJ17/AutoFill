#include "BOOT_FailMode.h"
#include "BOOT_Consts.h"
#include "LIBBSP_GPIO.h"
#include "LIBBSP_PLDCMP.h"
#include "LIBBSP_SHM.h"

void BOOT_FailMode(void)
{
   (void) LIBBSP_GPIO_Configure();
   (void) LIBBSP_GPIO_Write(E_LIBBSP_GPIO_GREEN_LED, FALSE);
   (void) LIBBSP_GPIO_Write(E_LIBBSP_GPIO_YELLOW_LED, FALSE);
   (void) LIBBSP_GPIO_Write(E_LIBBSP_GPIO_RED_LED, TRUE);

   LIBBSP_SHM_SetMode(E_LIBBSP_SHM_FAILURE_STATE, C_PLD_COMPAGNON_FAIL_SWITCH_GOLDEN);

   LIBBSP_PLDCMP_WriteFailDisc(C_PLD_COMPAGNON_DSO_SYSFAIL_GOLDEN);

   /* Infinite loop */
   LIBUTI_CMN_WaitUntilPowerDown( );
}