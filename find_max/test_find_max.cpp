#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FIND_MAX
#include <boost/test/unit_test.hpp>

#include <vector>     /* vector */
#include "find_max.hpp"    /* find_max */

BOOST_AUTO_TEST_CASE(simpleTestCases)
{
	// sorted
	std::vector<int> values = {1,2,3};
	BOOST_CHECK(find_max(&values) == 3);
	// unsorted
	values = {7,2,3};
	BOOST_CHECK(find_max(&values) == 7);
	// not just 3 values
	values = {7,2,10,123,124,3,10};
	BOOST_CHECK(find_max(&values) == 124);
	// all negative values
	values = {-7,-2,-3};
	BOOST_CHECK(find_max(&values) == -2);
	// only one value
	values = {-7};
	BOOST_CHECK(find_max(&values) == -7);
}
