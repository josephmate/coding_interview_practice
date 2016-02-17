
#include <cstdio>
#include <cstdlib>
#include <cstring> //strcpy
#include "endianness.h"


int main(int nargs, char** args) {
	if(nargs != 1) {
		printf("was expecting no arguments\n");
		return -1;
	}
	
	if(is_big_endian()) {
		printf("This machine is big endian\n");
	} else if(is_little_endian()) {
		printf("This machine is little endian\n");
	} else {
		printf("This machine is neither big nor little endian. There is a bug!\n");
	}
}


