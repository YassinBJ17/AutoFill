
#include <stdio.h>
#include<stdint.h>

enum{

E_LIBUTI_SIF_CHECK_ALGORITHM_MD5,
E_LIBUTI_SIF_CHECK_ALGORITHM_SHA1,
 E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_256,
 E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_256,
    E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_256,
    E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2S_256,
    E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_512,
    E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_512,
    E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_512,

}TE_LIBUTI_SIF_check_algorithm;


uint32_t LIBUTI_SIF_get_hash_length(const TE_LIBUTI_SIF_check_algorithm algo)
{
    uint32_t ret;
    switch (algo)
    {
    case E_LIBUTI_SIF_CHECK_ALGORITHM_MD5:
        ret = (uint32_t)16;
        break;
    case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA1:
        ret = (uint32_t)20;
        break;
    case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_256:
    case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_256:
    case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_256:
    case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2S_256:
        ret = (uint32_t)32;
        break;
    case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_512:
    case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_512:
    case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_512:
    default:
        ret = (uint32_t)64;
        break;
    }
    return ret;
}

int main()
{


printf("%d",LIBUTI_SIF_get_hash_length(E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_256));


    
}