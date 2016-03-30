
#include <cstdio>
#include <cstdlib>
#include <cstring> //strcpy
#include "remove_dupes.h"


int main(int nargs, char** args) {
	if(nargs != 2) {
		printf("was expecting one argument, the string to remove duplicate characters from\n");
		return -1;
	}
	int argIdx=1;
	char * input = args[argIdx++];
	char * output = new char[strlen(input)+1];
 	strcpy(output, input);

	remove_dupes(output);

	printf("input string:  '%s'\n", input);
	printf("dupes removed: '%s'\n", output);
}


