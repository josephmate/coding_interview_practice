
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
	check_str("", "");
}

