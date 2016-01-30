
#include <cstdio>
#include <cstdlib>
#include <cstring> //strcpy
#include "reverse_words.h"


int main(int nargs, char** args) {
	if(nargs != 2) {
		printf("was expecting one argument, the string with words to be reversed\n");
		return -1;
	}
	
	char * original = args[1];
	char * for_rev_str = new char[strlen(original)+1];
	char * for_rev_words = new char[strlen(original)+1];
 	strcpy(for_rev_str, original);
 	strcpy(for_rev_words, original);

	reverse_str(for_rev_str, (for_rev_str+strlen(for_rev_str)-1));
	reverse_words(for_rev_words);

	printf("input string:    '%s'\n", original);
	printf("reversed string: '%s'\n", for_rev_str);
	printf("words reversed:  '%s'\n", for_rev_words);
}


