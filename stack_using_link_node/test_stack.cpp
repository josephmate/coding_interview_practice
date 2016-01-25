
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE STACK
#include <boost/test/unit_test.hpp>
#include <stdio.h>

#include "stack.hpp" 


BOOST_AUTO_TEST_CASE(simpleTestCases)
{
	stack<int> s;
	BOOST_CHECK(s.size() == 0);

	s.push(1);
	BOOST_CHECK(s.size() == 1);
	BOOST_CHECK(s.pop() == 1);
	BOOST_CHECK(s.size() == 0);

	s.push(2);
	s.push(3);
	BOOST_CHECK(s.size() == 2);
	BOOST_CHECK(s.pop() == 3);
	BOOST_CHECK(s.pop() == 2);
	BOOST_CHECK(s.size() == 0);

	s.push(9);
	s.push(3);
	s.push(11);
	BOOST_CHECK(s.size() == 3);
	BOOST_CHECK(s.pop() == 11);
	BOOST_CHECK(s.pop() == 3);
	BOOST_CHECK(s.pop() == 9);
	BOOST_CHECK(s.size() == 0);
}

BOOST_AUTO_TEST_CASE(templateTestCase)
{
	stack<char> s;
	BOOST_CHECK(s.size() == 0);

	s.push('a');
	BOOST_CHECK(s.size() == 1);
	BOOST_CHECK(s.pop() == 'a');
	BOOST_CHECK(s.size() == 0);

	s.push('b');
	s.push('c');
	BOOST_CHECK(s.size() == 2);
	BOOST_CHECK(s.pop() == 'c');
	BOOST_CHECK(s.pop() == 'b');
	BOOST_CHECK(s.size() == 0);

	s.push('m');
	s.push('c');
	s.push('u');
	BOOST_CHECK(s.size() == 3);
	BOOST_CHECK(s.pop() == 'u');
	BOOST_CHECK(s.pop() == 'c');
	BOOST_CHECK(s.pop() == 'm');
	BOOST_CHECK(s.size() == 0);
}
