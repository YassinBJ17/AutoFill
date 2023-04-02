#include "BOOT_TCAHW_Expander2.h"

#include "LIBBSP_DISC.h"

void BOOT_TCAHW_Expander2(
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   TE_LIBBSP_I2C_Code v_I2C_ReturnCode;
   uint16_t v_IO_Exp2Reading;

   (void) LIBBSP_I2C_Initialize();
   v_I2C_ReturnCode = LIBBSP_DISC_Open(E_LIBBSP_DISC_EXPANDER_2);
   if(v_I2C_ReturnCode == E_LIBBSP_I2C_OK)
   {
      v_I2C_ReturnCode = LIBBSP_DISC_Configure(E_LIBBSP_DISC_EXPANDER_2);
      if(v_I2C_ReturnCode == E_LIBBSP_I2C_OK)
      {
         LIBBSP_DISC_Read(
            E_LIBBSP_DISC_EXPANDER_2,
            &v_IO_Exp2Reading,
            &v_I2C_ReturnCode
         );
      }
      (void) LIBBSP_DISC_Close();
   }
   if(v_I2C_ReturnCode != E_LIBBSP_I2C_OK)
   {
      p_PBIT_Results->Expander2AccessPBIT_Failed = TRUE;
   }
}
