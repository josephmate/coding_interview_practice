
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FIRST_NON_REPEAT_CHAR
#include <boost/test/unit_test.hpp>

#include <boost/locale/encoding_utf.hpp>

#include "first_non_repeat_char.hpp" 

using boost::locale::conv::utf_to_utf;

BOOST_AUTO_TEST_CASE(testNullPointerException) {
	BOOST_CHECK_THROW(
		first_non_repeat_char(NULL, NULL), 
		std::runtime_error
	);

	BOOST_CHECK_THROW(
		first_non_repeat_char(U"", NULL), 
		std::runtime_error
	);
}

void check(const char * input, char expected) {
	char res;
	BOOST_CHECK_MESSAGE(first_non_repeat_char(input, &res), "in string " << input << " did not find non repeated char but expected to find " << expected);
	BOOST_CHECK_MESSAGE(expected == res, "in string " << input << " found non repeated char " << res << " but expected to find " << expected);
}

// empty string -> not found
// len 1 -> found
// len 2 -> not found
// len 2 -> found
// len 3 -> not found
// len 3 -> found first
// len 3 -> found second
// len 3 -> found third
BOOST_AUTO_TEST_CASE(testAscii){
	// empty string -> not found
	char res;
	BOOST_CHECK(!first_non_repeat_char("", &res));

	// len 1 -> found
	check("a", 'a');

	// len 2 -> not found
	BOOST_CHECK(!first_non_repeat_char("aa", &res));

	// len 2 -> found
	check("bc", 'b');

	// len 3 -> not found
	BOOST_CHECK(!first_non_repeat_char("bbb", &res));

	// len 3 -> found first
	check("cbb", 'c');
	check("cba", 'c');

	// len 3 -> found second
	check("cbc", 'b');

	// len 3 -> found third
	check("bbc", 'c');
}


// g++ doesn't have <codecvt> yet, so I attempted to use boost's locale
// libraries
// http://stackoverflow.com/questions/15615136/is-codecvt-not-a-std-header
std::string utf32_to_utf8 (std::u32string &str) {
	return utf_to_utf<char>(str.c_str(), str.c_str() + str.size());
}

std::string utf32_to_utf8_len1 (char32_t * ch) {
	return utf_to_utf<char>(ch, ch + 1);
}

void check(std::u32string input, char32_t expected) {
	char32_t res;
	BOOST_CHECK_MESSAGE(
			first_non_repeat_char(input, &res),
			"in string " 
				<< utf32_to_utf8(input) 
				<< " did not find non repeated char but expected to find " 
				<< utf32_to_utf8_len1(&expected)
	);
	BOOST_CHECK_MESSAGE(
			expected == res, 
			"in string " 
				<< utf32_to_utf8(input) 
				<< " found non repeated char " 
				<< utf32_to_utf8_len1(&res) 
				<< " but expected to find " 
				<< utf32_to_utf8_len1(&expected)
	);
}

// empty string -> not found
// len 1 -> found
// len 2 -> not found
// len 2 -> found
// len 3 -> not found
// len 3 -> found first
// len 3 -> found second
// len 3 -> found third
//
// obtained characters that use all 4 bytes (32 bits) from:
// http://www.i18nguy.com/unicode/supplementary-test.html
// 4 byte: 𠜎 𠜱 𠝹 𠱓 𠱸 𠲖 𠳏 𠳕 𠴕 𠵼 𠵿 𠸎 𠸏 𠹷 𠺝 𠺢 𠻗 𠻹 𠻺 𠼭 𠼮 𠽌 𠾴 𠾼 𠿪 𡁜
// 2 byte: ¶
BOOST_AUTO_TEST_CASE(testUnicode32){

	// empty string -> not found
	std::u32string len0input = U"";
	char32_t res;
	BOOST_CHECK(!first_non_repeat_char(U"", &res));


	// len 1 -> found
	check(U"𠜎", U'𠜎');

	// len 2 -> not found
	BOOST_CHECK(!first_non_repeat_char(U"𠜎𠜎", &res));

	// len 2 -> found
	check(U"𠜎𠜱", U'𠜎');

	// len 3 -> not found
	BOOST_CHECK(!first_non_repeat_char(U"𠜎𠜎𠜎", &res));

	// len 3 -> found first
	check(U"𠜱𠜎𠝹", U'𠜱');
	check(U"𠜱𠜎𠜎", U'𠜱');

	// len 3 -> found second
	check(U"𠜎𠜱𠜎", U'𠜱');

	// len 3 -> found third
	check(U"𠜎𠜎𠜱", U'𠜱');

	// check mixed 4 byte and 2 byte
	check(U"¶𠜎𠜱", U'¶');
	
	
}
