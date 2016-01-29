
#include <cstdio>
#include <cstdlib>
#include "first_non_repeat_char.hpp"


int main(int nargs, char** args) {
	if(nargs!=2) {
		printf("You need to provide the string argument\n");
		return -1;
	}
	
	printf("Given: %s\n", args[1]);

	char res;
	if( first_non_repeat_char( args[1], &res ) ) {
		printf("%c was the first non repeated character\n", res);
	} else {
		printf("All characters were repeated\n");
	}
}


