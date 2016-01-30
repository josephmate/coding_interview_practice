
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE REVERSE_WORDS 
#include <boost/test/unit_test.hpp>

#include <cstring> //strcpy strcmp
#include "reverse_words.h" 

void check_reverse_str(const char * input, const char * expected) {
	char * actual = new char[strlen(input)+1];
 	strcpy(actual, input);
	reverse_str(actual, (actual+strlen(actual)-1));
	BOOST_CHECK_MESSAGE(strcmp(expected,actual)==0, "expecting " << expected << " but got " << actual);

	free(actual);
}

BOOST_AUTO_TEST_CASE(testReverseString){
	check_reverse_str("", "");
	check_reverse_str("a", "a");
	check_reverse_str("ab", "ba");
	check_reverse_str("abc", "cba");
	check_reverse_str("ab c", "c ba");
}

void check_reverse_words(const char * input, const char * expected) {
	char * actual = new char[strlen(input)+1];
 	strcpy(actual, input);
	reverse_words(actual);
	BOOST_CHECK_MESSAGE(strcmp(expected,actual)==0, "expecting '" << expected << "' but got '" << actual << "'");

	free(actual);
}

BOOST_AUTO_TEST_CASE(testReverseWord){
	// no characters / emtpy string
	check_reverse_words("", "");
	// one character word
	check_reverse_words("a", "a");
	// only one word
	check_reverse_words("ab", "ab");
	// one character words
	check_reverse_words("a b", "b a");
	// multiple spaces
	check_reverse_words("abc  def", "def  abc");
	// special characters
	check_reverse_words("abc, def", "def abc,");
	// three words
	check_reverse_words("abc def ghi", "ghi def abc");
	// ends with space
	check_reverse_words("abc def ", " def abc");
	// starts with space
	check_reverse_words(" abc def", "def abc ");
}
