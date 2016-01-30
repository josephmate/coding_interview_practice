
#include <stddef.h>        // NULL definition
#include <stdlib.h>        // malloc
#include <stdio.h>         // printf
#include "str_int_convert.h"

/**
 * Remember that the max integer is 2^31-1
 *                   min integer is 2^31
 * As a result, we have to watchout for that extra 1 by converting to negative
 * as soon as possible instead of accumulating positive then multiplying by -1
 * at the end.
 *
 * Some interesting overflow scenarios to consider:
 * -1 * -2147483648 = -2147483648
 * -1 + -2147483648 =  2147483647
 *  1 +  2147483647 = -2147483648
 */
int str_to_int(const char * str, int * res){
	// empty string case
	if(*str == '\0') {
		*res = 0;
		return 1;
	}
	
	int is_neg = 0;
	if(*str == '-') {
		is_neg = 1;
	}



	return 1;
}

#define MAX_DIGITS_IN_INT 10
int num_of_digits(int val) {
	if(val == 0) {
		return 1;
	}
	int is_neg = 0;
	if(val < 0) {
		is_neg = 1;
	}
	int exp=1;
	int soFar = 10;

	// We have to handle the negative case separately from the positive case
	// because multiplying the original number by negative -1 has edge cases.
	// Consider multiplying -2^31 by -1. It will overflow and you will get -2^31
	// again.
	// 
	// IE:
	// -2^31 in binary is
	// 1000 0000 0000 0000 0000 0000 0000 0000
	if(is_neg) {
		soFar = -10;
		while(soFar >= val && exp < MAX_DIGITS_IN_INT) {
			soFar = soFar*10;
			exp++;
		}
	} else {
		while(soFar <= val && exp < MAX_DIGITS_IN_INT) {
			soFar = soFar*10;
			exp++;
		}
	}
	return exp;
}

int int_to_str(int val, char ** res) {
	int digits = num_of_digits(val);
	int array_size = digits;
	if(val < 0) {
		array_size++;
	}
	char * res_str = malloc(sizeof(char)*array_size+1);
	if(!res_str) { // could not allocate the memory
		return 0;
	}
	res_str[array_size] = '\0';

	char * startptr = res_str;
	if(val < 0) {
		*startptr = '-';
		startptr++;
	}

	// TODO

	*res = res_str;
	return 1;
}




