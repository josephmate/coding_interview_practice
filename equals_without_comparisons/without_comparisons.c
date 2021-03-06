
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */

bool compare(int a, int b);

int main(int argc, char* argv[]){
	if(argc != 3) {
		printf("Need to provide at least two integers\n");
	}
	int a = strtol(argv[1], NULL, 0);
	int b = strtol(argv[2], NULL, 0);
	
	if(compare(a,b)) {
		printf("true\n");
	} else {
		printf("false\n");
	}
}

bool compare(int a, int b) {
	int comparison = (a & b) | (~a & ~b);
	int res = 1;
	for(int i = 0; i < 32; i++) {
		res = res & comparison;
		comparison = comparison >> 1;
	}
	return (bool)res;
}
