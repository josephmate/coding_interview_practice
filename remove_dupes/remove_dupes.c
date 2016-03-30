
#include <stddef.h>        // NULL definition
#include <stdlib.h>        // malloc
#include <stdio.h>         // printf
#include <string.h>        //strcpy
#include "remove_dupes.h"

int is_not_dupe(char * str, char ch, int endExclusive) {
	int i;
	for(i = 0; i < endExclusive; i++) {
		if(str[i] == ch) {
			return 0;
		}
	}

	return 1;
}

void remove_dupes(char * str) {
	int accumChars = 0;
	int nextChar = 0;

	while(str[nextChar] != '\0') {
		char ch = str[nextChar];
		if(is_not_dupe(str, ch, accumChars)) {
			str[accumChars] = ch;
			accumChars++;
		}
		// check if we already have this char
		
		nextChar++;
	}

	str[accumChars] = '\0';
}

