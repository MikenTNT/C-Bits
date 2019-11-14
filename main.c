#include <stdio.h>

#include "bits.h"



int main(int argc, char *argv[]) {

	unsigned char a = -1;
	unsigned short b = -1;
	unsigned int c = -1;
	unsigned long d = -1;

	printf("Value of a %hhu, size %ld bytes.\n", a, sizeof(a));
	printBites(sizeof(a), &a);
	puts("");
	printf("Value of a %hu, size %ld bytes.\n", b, sizeof(b));
	printBites(sizeof(b), &b);
	puts("");
	printf("Value of a %u, size %ld bytes.\n", c, sizeof(c));
	printBites(sizeof(c), &c);
	puts("");
	printf("Value of a %lu, size %ld bytes.\n", d, sizeof(d));
	printBites(sizeof(d), &d);
	puts("");

	return 0;

}
