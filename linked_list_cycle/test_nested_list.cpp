
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE NESTED_LIST
#include <boost/test/unit_test.hpp>
#include <stdio.h>
#include <unordered_map> 

#include "linked_list.hpp" 

// test no cycle len 0
// test no cycle len 1
// test no cycle len 2
// test no cycle len 3
BOOST_AUTO_TEST_CASE(noCycleCases){
	// test no cycle len 0
	BOOST_CHECK(!has_cycle(NULL));

	// test no cycle len 1
	linked_node * n0 = new linked_node(NULL, 0);
	BOOST_CHECK(!has_cycle(n0));

	// test no cycle len 2
	linked_node * n1 = new linked_node(n0, 1);
	BOOST_CHECK(!has_cycle(n1));

	// test no cycle len 3
	linked_node * n2 = new linked_node(n1, 2);
	BOOST_CHECK(!has_cycle(n2));

}

// len 1 cycle len 1
// len 2 cycle len 2 
// len 2 cycle len 1 
// len 3 cycle len 3 
// len 3 cycle len 2 
// len 3 cycle len 1 
BOOST_AUTO_TEST_CASE(cycleCases){
	// len 1 cycle len 1
	linked_node * n0 = new linked_node(NULL, 0);
	n0->next = n0;
	BOOST_CHECK(has_cycle(n0));

	// len 2 cycle len 1 
	linked_node * n1 = new linked_node(n0, 0);
	BOOST_CHECK(has_cycle(n1));
	n0->next = NULL;
	n1->next = n1;
	BOOST_CHECK(has_cycle(n1));

	// len 2 cycle len 2 
	n0->next = n1;
	n1->next = n0;
	BOOST_CHECK(has_cycle(n1));


	// len 3 cycle len 2 
	linked_node * n2 = new linked_node(n1, 0);
	BOOST_CHECK(has_cycle(n2));

	// len 3 cycle len 3 
	n0->next = n2;
	BOOST_CHECK(has_cycle(n2));

	// len 3 cycle len 1 
	n0->next = n0;
	BOOST_CHECK(has_cycle(n2));

	n0->next = NULL;
	BOOST_CHECK(!has_cycle(n2));
}
