#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bits.h"



char * printBits(int nOfBytes, void *bytes)
{
	int strSize = nOfBytes * 9;
	structByte *arrayBytes = (structByte *)bytes;

	char oneByte[10];
	char *strBits;


	if ((strBits = (char *)malloc(strSize)) == NULL) {
		fprintf(stderr, "Error: malloc\n");
		return NULL;
	}

	/*
	 * Initialize the string.
	 */
	strcpy(strBits, "");


	/*
	 * Reads and writes the data.
	 */
	#ifdef __BIG_ENDIAN_
	for (int i = 0; i < nOfBytes; i++)
	{
		sprintf(oneByte, "%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu ",
			   arrayBytes[i].b1,
			   arrayBytes[i].b2,
			   arrayBytes[i].b3,
			   arrayBytes[i].b4,
			   arrayBytes[i].b5,
			   arrayBytes[i].b6,
			   arrayBytes[i].b7,
			   arrayBytes[i].b8);
		strcat(strBits, oneByte);
	}
	#else
	for (int i = (nOfBytes -1); i >= 0; i--)
	{
		sprintf(oneByte, "%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu ",
			   arrayBytes[i].b8,
			   arrayBytes[i].b7,
			   arrayBytes[i].b6,
			   arrayBytes[i].b5,
			   arrayBytes[i].b4,
			   arrayBytes[i].b3,
			   arrayBytes[i].b2,
			   arrayBytes[i].b1);
		strcat(strBits, oneByte);
	}
	#endif


	/*
	 * Removes the last space character and finish the string.
	 */
	strBits[strSize - 1] = '\0';


	return strBits;
}
