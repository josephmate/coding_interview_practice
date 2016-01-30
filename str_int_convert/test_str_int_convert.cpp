
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE STR_INT_CONVERT 
#include <boost/test/unit_test.hpp>

#include "str_int_convert.h" 

void check_int(int expected, int actual) {
	BOOST_CHECK_MESSAGE(expected == actual, "expecting " << expected << " but got " << actual);
}

BOOST_AUTO_TEST_CASE(testNumOfDigits){
	check_int(1, num_of_digits( 0));
	check_int(1, num_of_digits( 1));
	check_int(1, num_of_digits(-1));
	check_int(1, num_of_digits( 9));
	check_int(1, num_of_digits(-9));
	check_int(2, num_of_digits( 10));
	check_int(2, num_of_digits(-10));
	check_int(2, num_of_digits( 19));
	check_int(2, num_of_digits(-19));
	check_int(3, num_of_digits( 100));
	check_int(3, num_of_digits(-100));
	check_int(3, num_of_digits( 109));
	check_int(3, num_of_digits(-109));
	check_int(3, num_of_digits( 190));
	check_int(3, num_of_digits(-190));
	check_int(3, num_of_digits( 199));
	check_int(3, num_of_digits(-199));
	// max integer 2^31-1 = 2,147,483,647
	check_int(10, num_of_digits(2147483647));
	// min integer -2^31 = 2,147,483,648
	check_int(10, num_of_digits(-2147483648));
	check_int(10, num_of_digits(-2147483647));
}

BOOST_AUTO_TEST_CASE(testStrToInt){
}

BOOST_AUTO_TEST_CASE(testIntToStr){
}

