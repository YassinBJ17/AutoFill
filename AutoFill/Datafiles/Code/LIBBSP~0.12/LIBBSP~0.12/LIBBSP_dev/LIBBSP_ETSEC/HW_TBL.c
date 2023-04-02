#include "HW_TBL.h"

/*************************************************************************************
 *                                                                                   *
 * Nom : tbl                                                                         *
 *                                                                                   *
 * Description :                                                                     *
 * Cette fonction permet de recuperer la valeur du time base register du Power PC    *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *                                                                                   *
 *                                                                                   *
 *************************************************************************************/
/*{{RELAX<SYNCHRONe_C_Code_16.12> The assembler instruction mftb read a 32bit word. And R3 is the return register. So this funtion return a uint32_t */ 
uint32_t tbl (void)  
{
   asm("mftb r3"); 
}
/*}}RELAX<SYNCHRONe_C_Code_16.12> */