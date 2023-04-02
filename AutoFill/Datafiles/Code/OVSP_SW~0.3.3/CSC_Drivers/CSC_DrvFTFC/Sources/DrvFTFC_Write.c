/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Flash memory write function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTFC_Public.h"
#include "DrvFTFC_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"
#include "DrvCPU_Public.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* DrvFTFC Write : To write a data to the Flash memory
 *   Inputs:
 *     - p_pt_SrcAddr: Source address
 *     - p_DestAddr:   Destination address
 *     - p_Length:     Length of the data to write
 *   Outputs:
 *     - p_pt_Status: Status of the Write to Flash memory operation
 *   Function return: None
 *   Pre-condition: p_DestAddr associated to p_Length have to identify a valid area
 *                  and compatible with the data source to write
*/
/* {{RELAX<SYNCHRONe_C_Code_23.2> It is clearer to align Qualifiers, Types and Names. */
void DrvFTFC_Write (const uint8_t  * const p_pt_SrcAddr,
                    const uint32_t         p_DestAddr,
                    const uint32_t         p_Length,
                          uint32_t * const p_pt_Status)
{
   /* }} RELAX<SYNCHRONe_C_Code_23.2> */
   const uint8_t  * v_pt_Source_Addr;

   uint32_t v_Dest_Addr;
   uint32_t v_Iter_Src;
   uint32_t v_Iter_Dest_Addr;

   if (((DRVFTFC_FLEXNVM_START_ADDR <= p_DestAddr) && (DRVFTFC_FLEXNVM_END_ADDR >= ((p_DestAddr + p_Length) - 1UL))))
   {
      v_pt_Source_Addr = p_pt_SrcAddr;

      v_Dest_Addr = (p_DestAddr & DRVFTFC_FLEXNVM_ADDR_MASK) | DRVFTFC_FLEXNVM_SELECTION;

      v_Iter_Src = 0UL;

      while (v_Iter_Src < p_Length)
      {
         while (DRVFTFC_FSTAT_CMD_COMPLETED == (C_DrvFTFC_Registers->S_FSTAT & DRVFTFC_FSTAT_CCIF_MASK))
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }

         if (DRVFTFC_FSTAT_NO_ERROR != (C_DrvFTFC_Registers->S_FSTAT & DRVFTFC_FSTAT_ERRORS_MASK))
         {
            C_DrvFTFC_Registers->S_FSTAT = DRVFTFC_FSTAT_ERRORS_MASK;
         }
         else
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }

         C_PtF_DrvCPU_Enter_Crit_Sect ();

         v_Iter_Dest_Addr = v_Dest_Addr + v_Iter_Src;

         /* {{RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision, the objective is to provide the address */
         /* byte per byte to the registers of byte size. */
         C_DrvFTFC_Registers->S_FCCOB3 = (uint8_t) (v_Iter_Dest_Addr & OVSP_SW_BYTE_MASK);
         C_DrvFTFC_Registers->S_FCCOB2 = (uint8_t) ((v_Iter_Dest_Addr >> OVSP_SW_DEC_1BYTE) & OVSP_SW_BYTE_MASK);
         C_DrvFTFC_Registers->S_FCCOB1 = (uint8_t) ((v_Iter_Dest_Addr >> OVSP_SW_DEC_2BYTES) & OVSP_SW_BYTE_MASK);
         /* }} RELAX<SYNCHRONe_C_Code_10.7> */

         C_DrvFTFC_Registers->S_FCCOB0 = DRVFTFC_FCCOB0_WRITE_CMD;

         /* {{RELAX<SYNCHRONe_C_Code_17.4> Waiting for SYNCHONe analyze, it seems to be a false violation. */
         /* The used form of pointer arithmetic is array indexing. */
         C_DrvFTFC_Registers->S_FCCOB7 = v_pt_Source_Addr [v_Iter_Src++];
         C_DrvFTFC_Registers->S_FCCOB6 = v_pt_Source_Addr [v_Iter_Src++];
         C_DrvFTFC_Registers->S_FCCOB5 = v_pt_Source_Addr [v_Iter_Src++];
         C_DrvFTFC_Registers->S_FCCOB4 = v_pt_Source_Addr [v_Iter_Src++];

         C_DrvFTFC_Registers->S_FCCOBB = v_pt_Source_Addr [v_Iter_Src++];
         C_DrvFTFC_Registers->S_FCCOBA = v_pt_Source_Addr [v_Iter_Src++];
         C_DrvFTFC_Registers->S_FCCOB9 = v_pt_Source_Addr [v_Iter_Src++];
         C_DrvFTFC_Registers->S_FCCOB8 = v_pt_Source_Addr [v_Iter_Src++];
         /* }} RELAX<SYNCHRONe_C_Code_17.4> */

         C_DrvFTFC_Registers->S_FSTAT = DRVFTFC_FSTAT_LAUNCH_CMD;

         while (DRVFTFC_FSTAT_CMD_COMPLETED == (C_DrvFTFC_Registers->S_FSTAT & DRVFTFC_FSTAT_CCIF_MASK))
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
         C_PtF_DrvCPU_Exit_Crit_Sect ();
      }

      *p_pt_Status = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Status = OVSP_SW_RESULT_FAILED;
   }
}
