
#include <vector>     /* vector */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */
#include "find_max.hpp"    /* find_max */

int main(int nargs, char ** argv) {
	if(nargs <= 1) {
		printf("Need to provide at least one integer\n");
	}
	std::vector<int> values = std::vector<int>(nargs-1);
	for(int i = 1; i < nargs; i++) {
		values[i-1] = strtol(argv[i], NULL, 0);
	}
	
	printf("%d\n", find_max(&values));
}

