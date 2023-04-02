/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function compute the CRC32 of a given zone using the 
 *               module HWCRC of MPC5777M and the DMA.
 * -------------------------------------------------------------------------- */


/* ---------- include provided interface: ----------------------------------- */
#include "CMN_TYPES_common.h"

/* ---------- include required interface: ----------------------------------- */
#include "LIB_CHKSUM_internal.h"
#include "DMA_HAL_public.h"
#include "HWCRC_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
extern TS_LIB_CHKSUM_CRC_Registers * v_LIB_CHKSUM_CRC_Registers;

/* ---------- provided operation bodies: ------------------------------------ */

/* BOOT CRC Hardware DMA Computation: To compute the compute the 32-bit Cyclic Redundancy Check using S32K CRC hardware module
 *                                    and DMA with 32-bit data
 *
 * Parameters:
 *   Inputs:
 *     - pt_StartAddr1 : pointer to the 1st memory area for CRC32 computation
 *     - p_Length1     : length of the 1st memory area
 *     - pt_StartAddr2 : pointer to the 2nd memory area for CRC32 computation
 *     - p_Length2     : length of the 2nd memory area
 *
 *   Outputs:
 *     - pt_CrcComputed : Computed CRC32
 *
 *   -------------------------------------------
 *   Pre-condition: Pointer(s) shall not be null
 *   -------------------------------------------
 *
 *  */
void BOOT_LIBCHK_CRC_HwDmaComputation32(const uint32_t * const pt_StartAddr1, const uint32_t p_Length1,
                                         const uint32_t * const pt_StartAddr2, const uint32_t p_Length2,
                                         uint32_t *       const pt_CrcComputed)
{
    /* Local variable definition */
    uint32_t v_i;
    ts_DMA_STATUS  v_hwcrc_dma_status;
    ts_DMA_PROG v_hwcrc_dma_prog;
    uint32_t *pt_area_start;

    DMA_CLEAR_DONE(K_LIB_CHKSUM_DMA_LINE_0, e_CMN_FLAG_DO);

    DMA_STATUS(K_LIB_CHKSUM_DMA_LINE_0, &v_hwcrc_dma_status);

    if(v_hwcrc_dma_status.s_cycle_count == v_hwcrc_dma_status.s_cycle_nb)
    {
        /* Set start address of zone 1 */
        pt_area_start = (uint32_t *)pt_StartAddr1;

        /* Transfer code section */
        v_hwcrc_dma_prog.s_nb_byte_req    = (uint32_t)p_Length1;
        v_hwcrc_dma_prog.s_src_addr       = (uint32_t)pt_area_start;
        v_hwcrc_dma_prog.s_src_last_addr  = (uint32_t)pt_area_start + p_Length1;

        v_hwcrc_dma_prog.s_src_off        = K_LIB_CHKSUM_CRC_UINT32_4;
        v_hwcrc_dma_prog.s_dest_addr      = (uint32_t)v_LIB_CHKSUM_CRC_Registers + K_LIB_CHKSUM_CRC_UINT32_4;
        v_hwcrc_dma_prog.s_dest_last_addr = (uint32_t)v_LIB_CHKSUM_CRC_Registers + K_LIB_CHKSUM_CRC_UINT32_4;
        v_hwcrc_dma_prog.s_dest_off       = K_LIB_CHKSUM_CRC_UINT32_0;
        v_hwcrc_dma_prog.s_nb_cycle       = K_LIB_CHKSUM_CRC_UINT32_1;

        v_hwcrc_dma_prog.s_buff_type      = e_DMA_BUFFER_ONE_SHOT; /* One shot by default */

        DMA_CFG(K_LIB_CHKSUM_DMA_LINE_0, &v_hwcrc_dma_prog);

        DMA_REQUEST(K_LIB_CHKSUM_DMA_LINE_0, e_CMN_FLAG_ACTIVATE);

        v_i = K_LIB_CHKSUM_CRC_UINT32_0;

        /* ~4ms pour 1000000 iterations */
        /* ~200ms pour 5000000 iterations */
        do
        {
            DMA_STATUS(K_LIB_CHKSUM_DMA_LINE_0, &v_hwcrc_dma_status);
            v_i++;
        }
        while((v_hwcrc_dma_status.s_read_done != K_LIB_CHKSUM_CRC_UINT32_1) && (v_i < 6450000));

        /* Set start address of zone 2 */
        pt_area_start = (uint32_t *)pt_StartAddr2;

        /* Transfer code section */
        v_hwcrc_dma_prog.s_nb_byte_req    = (uint32_t)p_Length2;
        v_hwcrc_dma_prog.s_src_addr       = (uint32_t)pt_area_start;
        v_hwcrc_dma_prog.s_src_last_addr  = (uint32_t)pt_area_start + p_Length2;

        v_hwcrc_dma_prog.s_src_off        = K_LIB_CHKSUM_CRC_UINT32_4;
        v_hwcrc_dma_prog.s_dest_addr      = (uint32_t)v_LIB_CHKSUM_CRC_Registers + K_LIB_CHKSUM_CRC_UINT32_4;
        v_hwcrc_dma_prog.s_dest_last_addr = (uint32_t)v_LIB_CHKSUM_CRC_Registers + K_LIB_CHKSUM_CRC_UINT32_4;
        v_hwcrc_dma_prog.s_dest_off       = K_LIB_CHKSUM_CRC_UINT32_0;
        v_hwcrc_dma_prog.s_nb_cycle       = K_LIB_CHKSUM_CRC_UINT32_1;

        v_hwcrc_dma_prog.s_buff_type      = e_DMA_BUFFER_ONE_SHOT; /* One shot by default */

        DMA_CFG(K_LIB_CHKSUM_DMA_LINE_0, &v_hwcrc_dma_prog);

        DMA_REQUEST(K_LIB_CHKSUM_DMA_LINE_0, e_CMN_FLAG_ACTIVATE);

        v_i = K_LIB_CHKSUM_CRC_UINT32_0;

        /* ~4ms pour 1000000 iterations */
        /* ~200ms pour 5000000 iterations */
        do
        {
            DMA_STATUS(K_LIB_CHKSUM_DMA_LINE_0, &v_hwcrc_dma_status);
            v_i++;
        }
        while((v_hwcrc_dma_status.s_read_done != K_LIB_CHKSUM_CRC_UINT32_1) && (v_i < 6450000));

        /* Set computed CRC32 to pointer */
        *pt_CrcComputed = v_LIB_CHKSUM_CRC_Registers->CRC_OUTP;
    }

    /* Exit function */
    return;
}

/* ---------- End of file --------------------------------------------------- */
