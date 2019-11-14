#include <stdio.h>
#include <stdlib.h>

#include "bits.h"



int main(int argc, char *argv[]) {

	unsigned char a = '\0';
	unsigned short b = -1;
	unsigned int c = 54;
	unsigned long d = -1;
	char *aBits, *bBits, *cBits, *dBits;

	aBits = printBits(sizeof(a), &a);
	bBits = printBits(sizeof(b), &b);
	cBits = printBits(sizeof(c), &c);
	dBits = printBits(sizeof(d), &d);


	printf("Value of a %hhu, size %ld bytes.\n", a, sizeof(a));
	printf("Bytes: %s\n", aBits);
	printf("Value of b %hu, size %ld bytes.\n", b, sizeof(b));
	printf("Bytes: %s\n", bBits);
	printf("Value of c %u, size %ld bytes.\n", c, sizeof(c));
	printf("Bytes: %s\n", cBits);
	printf("Value of d %lu, size %ld bytes.\n", d, sizeof(d));
	printf("Bytes: %s\n", dBits);


	// It's very important to free the string after use it.
	free(aBits);
	free(bBits);
	free(cBits);
	free(dBits);


	return 0;

}
