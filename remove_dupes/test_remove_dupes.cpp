
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE REVERSE_WORDS 
#include <boost/test/unit_test.hpp>

#include <cstring> //strcpy strcmp
#include "remove_dupes.h" 

void check_str(const char * input, const char * expected) {
	char * actual = new char[strlen(input)+1];
 	strcpy(actual, input);
	remove_dupes(actual);
	BOOST_CHECK_MESSAGE(strcmp(expected,actual)==0, "expecting " << expected << " but got " << actual);

	free(actual);
}

BOOST_AUTO_TEST_CASE(testReverseString){
	// len 0
	check_str("", "");
	
	// len 1
	check_str("a", "a");

	// len 2
	check_str("ab", "ab");
	check_str("aa", "a");

	// len 3
	check_str("abc", "abc");
	check_str("aac", "ac");
	check_str("aaa", "a");
	check_str("aba", "ab");
	check_str("bbc", "bc");
	check_str("abb", "ab");
}

