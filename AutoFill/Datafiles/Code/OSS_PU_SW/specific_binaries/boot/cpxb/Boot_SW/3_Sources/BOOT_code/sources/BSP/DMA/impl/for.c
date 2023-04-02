#include "DMA_HAL_public.h"
#include "CMN_TYPES_common.h"
#include "DMA_CFEX_public.h"

       for ( v_line_ind = 0ul ; v_line_ind < DMA_LINE_MAX_NB ; v_line_ind++ )       {          pt_dma_reg->s_DCHPRI[v_line_ind].u_R = ( pt_dma_reg->s_DCHPRI[v_line_ind].u_R & ( ( reg8_t ) DMA_DCHPRI_MASK ) )                                                   | (reg8_t)c_DMA_CFEX_PRIORITY_tab[v_line_ind + v_offset_tab];       }
