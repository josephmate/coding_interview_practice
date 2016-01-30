
#include <cstdio>
#include <cstdlib>
#include <cstring> //strcpy
#include "str_int_convert.h"


int main(int nargs, char** args) {
	if(nargs != 2) {
		printf("expecting 1 argument\n");
		printf("-1*-2147483648=%d\n", -1*-2147483648 );
		printf("-1+-2147483648= %d\n", -1+-2147483648 );
		int val = 2147483647;
		val = val + 1;
		printf("1+2147483647  =%d\n", val );

		return -1;
	}

	printf("original string:                %s\n", args[1]);
	int converted_to_int;
	if(!str_to_int(args[1],&converted_to_int)) {
		printf("the string you provided could not be converted to an integer\n");
		return -1;
	}
	printf("converted to integer:           %d\n", converted_to_int);
	printf("number of characters in string: %d\n", strlen(args[1]));
	printf("number of digits in integer:    %d\n", num_of_digits(converted_to_int));
	char * converted_to_str;
	if(int_to_str(converted_to_int, &converted_to_str)) {
		printf("the string you provided could not be converted back into a string\n");
		return -1;
	}
	printf("converted back to string: %s\n", converted_to_str);
	delete converted_to_str;
}


