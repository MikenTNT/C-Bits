#include <stdio.h>

#include "bits.h"



void printBites(int nOfBytes, void *bytes)
{
	structByte *arrayBytes = (structByte *)bytes;

	#ifdef __BIG_ENDIAN_
	for (int i = 0; i < nOfBytes; i++)
	{
		printf("%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu ",
			   arrayBytes[i].b1,
			   arrayBytes[i].b2,
			   arrayBytes[i].b3,
			   arrayBytes[i].b4,
			   arrayBytes[i].b5,
			   arrayBytes[i].b6,
			   arrayBytes[i].b7,
			   arrayBytes[i].b8);
	}
	#else
	for (int i = (nOfBytes - 1); i >= 0; i--)
	{
		printf("%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu ",
			   arrayBytes[i].b8,
			   arrayBytes[i].b7,
			   arrayBytes[i].b6,
			   arrayBytes[i].b5,
			   arrayBytes[i].b4,
			   arrayBytes[i].b3,
			   arrayBytes[i].b2,
			   arrayBytes[i].b1);
	}
	#endif

	printf("%c", 8);  // Removes the last space.
}
