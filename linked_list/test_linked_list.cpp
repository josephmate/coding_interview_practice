
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE LINKED_LIST
#include <boost/test/unit_test.hpp>
#include <stdio.h>

#include "linked_list.hpp" 

BOOST_AUTO_TEST_CASE(simpleTestCases)
{
	linked_list<int> list;

	BOOST_CHECK(list.size() == 0);
	printf("adding 0\n");
	list.add(0);
	printf("adding 1\n");
	list.add(1);
	printf("adding 2\n");
	list.add(2);
	BOOST_CHECK(list.size() == 3);
	
	printf("getting 0th element\n");
	BOOST_CHECK(list.get(0) == 0);
	printf("getting 1st element\n");
	BOOST_CHECK(list.get(1) == 1);
	printf("getting 2nd element\n");
	BOOST_CHECK(list.get(2) == 2);

	printf("popping the most recent element\n");
	BOOST_CHECK(list.pop() == 2);
	BOOST_CHECK(list.size() == 2);
	printf("getting 0th element\n");
	BOOST_CHECK(list.get(0) == 0);
	printf("getting 1st element\n");
	BOOST_CHECK(list.get(1) == 1);

	printf("adding 2 back\n");
	list.add(2);
	printf("adding 3\n");
	list.add(3);
	printf("adding 4\n");
	list.add(4);
	BOOST_CHECK(list.size() == 5);
	printf("getting 0th element\n");
	BOOST_CHECK(list.get(0) == 0);
	printf("getting 1st element\n");
	BOOST_CHECK(list.get(1) == 1);
	printf("getting 2nd element\n");
	BOOST_CHECK(list.get(2) == 2);
	printf("getting 3st element\n");
	BOOST_CHECK(list.get(3) == 3);
	printf("getting 4st element\n");
	BOOST_CHECK(list.get(4) == 4);

	list.remove(2);
	BOOST_CHECK(list.size() == 4);
	printf("check that the 2 index element was removed\n");
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 3);
	BOOST_CHECK(list.get(3) == 4);

	list.remove(0);
	BOOST_CHECK(list.size() == 3);
	printf("check that the 0 index element was removed\n");
	BOOST_CHECK(list.get(0) == 1);
	BOOST_CHECK(list.get(1) == 3);
	BOOST_CHECK(list.get(2) == 4);

	list.remove(2);
	BOOST_CHECK(list.size() == 2);
	printf("check that the 2 index element was removed\n");
	BOOST_CHECK(list.get(0) == 1);
	BOOST_CHECK(list.get(1) == 3);

	list.remove(0);
	BOOST_CHECK(list.size() == 1);
	printf("check that the 0 index element was removed\n");
	BOOST_CHECK(list.get(0) == 3);

	list.remove(0);
	printf("check that the 0 index element was removed\n");
	BOOST_CHECK(list.size() == 0);

}
BOOST_AUTO_TEST_CASE(checkTemplate) {
	linked_list<char> list;

	BOOST_CHECK(list.size() == 0);
	printf("adding 0\n");
	list.add('a');
	printf("adding 1\n");
	list.add('b');
	printf("adding 2\n");
	list.add('c');
	BOOST_CHECK(list.size() == 3);
	
	printf("getting 0th element\n");
	BOOST_CHECK(list.get(0) == 'a');
	printf("getting 1st element\n");
	BOOST_CHECK(list.get(1) == 'b');
	printf("getting 2nd element\n");
	BOOST_CHECK(list.get(2) == 'c');
}
