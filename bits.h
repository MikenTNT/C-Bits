#ifndef __BITS_H
#define __BITS_H


// If your system is Big Endian use the line below.
//#define __BIG_ENDIAN_


/**
 * This is the struct used to get the bits.
 */
typedef struct structByte
{
	unsigned char b1:1;
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
	unsigned char b8:1;
} structByte;


/**
 * This function gets an object and its size
 * and return a string with its bits.
 */
char * printBits(int bitSetSize, void *bitSet);


#endif
