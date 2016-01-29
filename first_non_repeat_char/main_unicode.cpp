
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "first_non_repeat_char.hpp"
#include <boost/locale/encoding_utf.hpp>  // for conversion


using boost::locale::conv::utf_to_utf;

std::u32string utf8_to_utf32 (std::string &str) {
	return utf_to_utf<char32_t>(str.c_str(), str.c_str() + str.size());
}

std::string utf32_to_utf8_len1 (char32_t * ch) {
	return utf_to_utf<char>(ch, ch + 1);
}


int main(int nargs, char** args) {
	if(nargs!=2) {
		printf("You need to provide the string argument\n");
		return -1;
	}
	
	printf("Given: %s\n", args[1]);
	
	
	std::string str(args[1]);
	char32_t res;

	// convert to utf32 so that it's simple to iterate over the characters, even
	// with variable length characters. Once converted, all characters will be 32
	// bits no matter how many bits they are in utf8.
	if( first_non_repeat_char( utf8_to_utf32(str), &res) ) {
		std::cout << utf32_to_utf8_len1(&res) << " was the first non repeated character\n";
	} else {
		printf("All characters were repeated\n");
	}
}


