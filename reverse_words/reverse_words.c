
#include <stddef.h>        // NULL definition
#include <stdlib.h>        // malloc
#include <stdio.h>         // printf
#include <string.h>        //strcpy
#include "reverse_words.h"


void reverse_str(char * start, char * end) {
	char * startptr = start;
	char * endptr = end;
	
	// have one pointer to the start of the cstr
	// have a second pointer to the end of the cstr 
	// - this is the very last character and should never include the \0 null
	//   character
	//
	// swap
	// increment start pointer
	// decrement end pointer
	//
	// keep going until the endptr => startptr
	// - this also takes care of the edge case where the string is empty 
	while(startptr < endptr) {
		// swap characters
		char tmp = *startptr;
		*startptr = *endptr;
		*endptr = tmp;

		startptr++;
		endptr--;
	}
}

void reverse_words(char * str){
	// reverse the string
	reverse_str(str, (str+strlen(str)-1));

	// Now the words have been reversed, but all the words are written
	// right-to-left.
	//
	// We go word by word, reversing each word.
	
	char * startptr = str;
	while(*startptr != '\0') {
		if(*startptr == ' ') {  // ignore space characters
			startptr++;
			continue;
		}
		char * endptr = startptr;
		// find the next space
		while(*endptr != ' ' && *endptr != '\0') {
			endptr++;
		}
		// go to the character just before the space or null \0 character
		endptr--;

		// reverse the word, segmented by the start and end pointers
		reverse_str(startptr, endptr);

		startptr = endptr;
		startptr++; // move to the space , null , \0 char
	}
	
	
}
