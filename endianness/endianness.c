
#include <stddef.h>        // NULL definition
#include <stdlib.h>        // malloc
#include <stdio.h>         // printf
#include <string.h>        //strcpy
#include "endianness.h"

/**
 * strategy is to look at the individual bytes of a multibyte data type by
 * casting it to a single-byte data type (character).
 *
 * Big endian should have the most significant first. If we set the least
 * sigificant bit, and notice that first byte is not set, then it's big endian
 * ie:
 * 00 00 00 01 big
 * vs.
 * 01 00 00 00 little
 */
int is_big_endian() {
	int i = 1;
	char* bytes = (char*)(&i);
	if(bytes[0]) {
		return 0;
	} else {
		return 1;
	}
}

int is_little_endian() {
	int i = 1;
	char* bytes = (char*)(&i);
	if(bytes[0]) {
		return 1;
	} else {
		return 0;
	}
}
