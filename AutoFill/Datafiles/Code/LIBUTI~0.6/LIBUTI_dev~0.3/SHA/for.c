#include "LIBUTI_SHA_Transform.h"
#include "LIBUTI_SHA.h"

    for (i = (uint32_t)0; i < (uint32_t)64; ++i)    { 	   t1 = h + (((e >> (uint32_t)6) | (e << (uint32_t)26)) ^ ((e >> (uint32_t)11) | (e << (uint32_t)21)) ^ ((e >> (uint32_t)25) | (e << (uint32_t)7)))+  			((e & f) ^ ((~e) & g)) + k[i] + m[i]; 	   t2 = (((a >> (uint32_t)2) | (a << (uint32_t)30)) ^ ((a >> (uint32_t)13) | (a << (uint32_t)19)) ^ ((a >> (uint32_t)22) | (a << (uint32_t)10)))+ 			((a & b) ^ (a & c) ^ (b & c));        h = g;        g = f;        f = e;        e = d + t1;        d = c;        c = b;        b = a;        a = t1 + t2;    }
