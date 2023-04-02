#include <stdio.h>
#include<stdint.h>

     switch (algo)     {     case E_LIBUTI_SIF_CHECK_ALGORITHM_MD5:         ret = (uint32_t)16;         break;     case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA1:         ret = (uint32_t)20;         break;     case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_256:     case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_256:     case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_256:     case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2S_256:         ret = (uint32_t)32;         break;     case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_512:     case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_512:     case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_512:     default:         ret = (uint32_t)64;         break;     }
