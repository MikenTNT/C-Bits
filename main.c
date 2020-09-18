#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bits.h"



int main(int argc, char *argv[]) {
	/**
	 * Examples.
	 */
	unsigned char a = '\0';
	unsigned short b = 1;
	unsigned int c = 54;
	unsigned long d = 5757;
	char *strin = (char *)calloc(1, 10);
	strcpy(strin, "Hola");

	char *aBits, *bBits, *cBits, *dBits, *strBits;

	aBits = printBits(sizeof(a), &a);
	bBits = printBits(sizeof(b), &b);
	cBits = printBits(sizeof(c), &c);
	dBits = printBits(sizeof(d), &d);
	strBits = printBits(sizeof(strin), strin);


	// Print the result
	printf("Value of a %hhu, size %ld bytes.\n", a, sizeof(a));
	printf("Bytes: %s\n", aBits);
	printf("Value of b %hu, size %ld bytes.\n", b, sizeof(b));
	printf("Bytes: %s\n", bBits);
	printf("Value of c %u, size %ld bytes.\n", c, sizeof(c));
	printf("Bytes: %s\n", cBits);
	printf("Value of d %lu, size %ld bytes.\n", d, sizeof(d));
	printf("Bytes: %s\n", dBits);
	printf("Value of string %s, size %ld bytes.\n", strin, sizeof(strin));
	printf("Bytes: %s\n", strBits);


	// It is very important to free the strings once you are done using them.
	free(aBits);
	free(bBits);
	free(cBits);
	free(dBits);
	free(strBits);
	free(strin);


	return 0;

}
