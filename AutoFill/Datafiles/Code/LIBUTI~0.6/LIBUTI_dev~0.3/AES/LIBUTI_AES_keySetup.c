#include "LIBUTI_AES.h"
#include "LIBUTI_AES_byteOperations.h"

 void LIBUTI_AES_keySetup(const uint8_t key[], uint32_t schedule[], const int32_t keysize)  { 	int32_t Nb,Nr,Nk,idx; 	uint32_t temp; 	const uint32_t Rcon[]={0x01000000,0x02000000,0x04000000,0x08000000,0x10000000,0x20000000, 	                  0x40000000,0x80000000,0x1b000000,0x36000000,0x6c000000,0xd8000000, 	                  0xab000000,0x4d000000,0x9a000000}; 	Nb = 4l; 	switch (keysize) 	{ 		case 128:  		   Nr = 10l; 		   Nk = 4l; 		   break; 		case 192: 		   Nr = 12l; 		   Nk = 6l; 		   break; 		case 256: 		   Nr = 14l; 		   Nk = 8l; 		   break; 		default: 		   return; 		   break; 	} 	for (idx=0l; idx < Nk; ++idx)  	{ 		schedule[idx] = ( (((uint32_t) key[4l * idx]) << 24) | (((uint32_t) key[(4l * idx) + 1l]) << 16) | 				   (((uint32_t) key[(4l * idx) + 2l]) << 8) | ((uint32_t) (key[(4l * idx) + 3l])) ); 	} 	for (idx = Nk; idx < Nb * (Nr + 1l); ++idx)   	{ 		temp = schedule[idx - 1l]; 		if ((idx % Nk) == 0l) 		{ 			temp = SubWord(((temp) << 8) | ((temp) >> 24)) ^ Rcon[(idx-1l)/Nk];  		} 		else if (Nk > 6l && (idx % Nk) == 4l) 		{ 			temp = SubWord(temp); 		} 		schedule[idx] = schedule[idx-Nk] ^ temp; 	} }
