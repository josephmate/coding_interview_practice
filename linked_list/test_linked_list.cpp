
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE LINKED_LIST
#include <boost/test/unit_test.hpp>
#include <stdio.h>

#include "linked_list.hpp" 

BOOST_AUTO_TEST_CASE(simpleTestCases)
{
	linked_list<int> list;

	// [0, 1, 2]
	BOOST_CHECK(list.size() == 0);
	list.add(0);
	list.add(1);
	list.add(2);
	BOOST_CHECK(list.size() == 3);
	
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 2);

	// pop the most recent
	BOOST_CHECK(list.pop() == 2);
	BOOST_CHECK(list.size() == 2);
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 1);

	// [0, 1, 2, 3, 4]
	list.add(2);
	list.add(3);
	list.add(4);
	BOOST_CHECK(list.size() == 5);
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 2);
	BOOST_CHECK(list.get(3) == 3);
	BOOST_CHECK(list.get(4) == 4);

	// removing the 2nd index
	// [0, 1, 2, 3, 4] --> [0, 1, 3, 4]
	list.remove(2);
	BOOST_CHECK(list.size() == 4);
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 3);
	BOOST_CHECK(list.get(3) == 4);

	// removing the 0th index
	// [0, 1, 3, 4] --> [1, 3, 4]
	list.remove(0);
	BOOST_CHECK(list.size() == 3);
	BOOST_CHECK(list.get(0) == 1);
	BOOST_CHECK(list.get(1) == 3);
	BOOST_CHECK(list.get(2) == 4);

	// removing the 2nd index
	// [1, 3, 4] -->  [1, 3]
	list.remove(2);
	BOOST_CHECK(list.size() == 2);
	BOOST_CHECK(list.get(0) == 1);
	BOOST_CHECK(list.get(1) == 3);

	list.remove(0);
	BOOST_CHECK(list.size() == 1);
	BOOST_CHECK(list.get(0) == 3);

	list.remove(0);
	BOOST_CHECK(list.size() == 0);

}
BOOST_AUTO_TEST_CASE(checkTemplate) {
	linked_list<char> list;

	//     _--- index 0 
	//    /     _--- the tail
	//   /     /
	//   v     v
	// [ a, b, c ]
	BOOST_CHECK(list.size() == 0);
	list.add('a');
	list.add('b');
	list.add('c');
	BOOST_CHECK(list.size() == 3);
	
	BOOST_CHECK(list.get(0) == 'a');
	BOOST_CHECK(list.get(1) == 'b');
	BOOST_CHECK(list.get(2) == 'c');
}

BOOST_AUTO_TEST_CASE(testInsertBeforeNULLOnEmpty)
{
	// test insert before NULL case on empty list
	linked_list<int> list;
	list.insertBefore(NULL,1);
	BOOST_CHECK(list.size() == 1);
}

BOOST_AUTO_TEST_CASE(testInsertBeforeNULLOnSize1) 
{
	// test insert before NULL case on list of size 1
	linked_list<int> list;
	list.add(1);
	list.insertBefore(NULL,9);
	BOOST_CHECK(list.size() == 2);
	BOOST_CHECK(list.get(0) == 1);
	BOOST_CHECK(list.get(1) == 9);
}
BOOST_AUTO_TEST_CASE(testInsertBeforeNULLOnSize2)
{
	// test insert before NULL case on list of size 2
	linked_list<int> list;
	list.add(1);
	list.add(2);
	list.insertBefore(NULL,9);
	BOOST_CHECK(list.size() == 3);
	BOOST_CHECK(list.get(0) == 1);
	BOOST_CHECK(list.get(1) == 2);
	BOOST_CHECK(list.get(2) == 9);

	// test insert before NULL case on list of size > 2
	
	// test insert before norm case on list of size 1
	// test insert before NULL case on list of size 2
	// test insert before NULL case on list of size > 2
}
BOOST_AUTO_TEST_CASE(testInsertBeforeNULLOnSizeGreaterThan2)
{
	// test insert before NULL case on list of size > 2
	linked_list<int> list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.insertBefore(NULL,9);
	BOOST_CHECK(list.size() == 4);
	BOOST_CHECK(list.get(0) == 1);
	BOOST_CHECK(list.get(1) == 2);
	BOOST_CHECK(list.get(2) == 3);
	BOOST_CHECK(list.get(3) == 9);

	
	// test insert before norm case on list of size 1
	// test insert before NULL case on list of size 2
	// test insert before NULL case on list of size > 2
}
BOOST_AUTO_TEST_CASE(testInsertBeforeIDX0Len1)
{
	// test insert before norm case on list of size 1
	linked_list<int> list;
	link_node<int>* idx0 = list.add(1);
	list.insertBefore(idx0, 9);
	BOOST_CHECK(list.size() == 2);
	BOOST_CHECK(list.get(0) == 9);
	BOOST_CHECK(list.get(1) == 1);

	
	// test insert before norm case on list of size 2
	// test insert before norm case on list of size > 2
}
BOOST_AUTO_TEST_CASE(testInsertBeforeIDX0Len2)
{
	// test insert before norm case on list of size 2 before idx0 
	linked_list<int> list;
	link_node<int>* idx0 = list.add(1);
	link_node<int>* idx1 = list.add(2);
	list.insertBefore(idx0, 9);
	BOOST_CHECK(list.size() == 3);
	BOOST_CHECK(list.get(0) == 9);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 2);
}
BOOST_AUTO_TEST_CASE(testInsertBeforeIDX1Len2)
{
	// test insert before norm case on list of size 2 before idx1 
	linked_list<int> list;
	link_node<int>* idx0 = list.add(1);
	link_node<int>* idx1 = list.add(2);
	list.insertBefore(idx1, 9);
	BOOST_CHECK(list.size() == 3);
	BOOST_CHECK(list.get(0) == 1);
	BOOST_CHECK(list.get(1) == 9);
	BOOST_CHECK(list.get(2) == 2);
}
BOOST_AUTO_TEST_CASE(testInsertBeforeLen3)
{
	// test insert before norm case on list of size 2 before idx1 
	linked_list<int> list;
	link_node<int>* idx0 = list.add(1);
	link_node<int>* idx1 = list.add(2);
	link_node<int>* idx2 = list.add(3);
	list.insertBefore(idx0, 9);
	list.insertBefore(idx1, 10);
	list.insertBefore(idx2, 11);
	BOOST_CHECK(list.size() == 6);
	BOOST_CHECK(list.get(0) == 9);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 10);
	BOOST_CHECK(list.get(3) == 2);
	BOOST_CHECK(list.get(4) == 11);
	BOOST_CHECK(list.get(5) == 3);
}

// test remove on list of size 1
// test remove on list of size 2 and it is the tail (most recently added)
// test remove on list of size 2 and it is the first added (index 0)
// test remove on list of size > 2 and it is the tail
// test remove on list of size > 2 and it is the first added
// test remove on list of size > 2 and it is somewhere in the middle
BOOST_AUTO_TEST_CASE(testRemoveNode) {
	linked_list<int> list;

	// test remove on list of size 1
	link_node<int>* idx0 = list.add(1);
	BOOST_CHECK(list.remove(idx0) == 1);
	BOOST_CHECK(list.size() == 0);

	// test remove on list of size 2 and it is the tail
	idx0 = list.add(0);
	link_node<int>* idx1 = list.add(1);
	BOOST_CHECK(list.remove(idx1) == 1);
	BOOST_CHECK(list.size() == 1);
	BOOST_CHECK(list.pop() == 0);
	BOOST_CHECK(list.size() == 0);

	// test remove on list of size 2 and it is the first added (index 0)
	idx0 = list.add(0);
	idx1 = list.add(1);
	BOOST_CHECK(list.remove(idx0) == 0);
	BOOST_CHECK(list.size() == 1);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.size() == 0);

	// test remove on list of size > 2 and it is the tail
	idx0 = list.add(0);
	idx1 = list.add(1);
	link_node<int>* idx2 = list.add(2);
	BOOST_CHECK(list.remove(idx2) == 2);
	BOOST_CHECK(list.size() == 2);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.pop() == 0);
	BOOST_CHECK(list.size() == 0);

	// test remove on list of size > 2 and it is the first added
	idx0 = list.add(0);
	idx1 = list.add(1);
	idx2 = list.add(2);
	BOOST_CHECK(list.remove(idx0) == 0);
	BOOST_CHECK(list.size() == 2);
	BOOST_CHECK(list.pop() == 2);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.size() == 0);

	// test remove on list of size > 2 and it is somewhere in the middle
	idx0 = list.add(0);
	idx1 = list.add(1);
	idx2 = list.add(2);
	BOOST_CHECK(list.remove(idx1) == 1);
	BOOST_CHECK(list.size() == 2);
	BOOST_CHECK(list.pop() == 2);
	BOOST_CHECK(list.pop() == 0);
	BOOST_CHECK(list.size() == 0);
}


BOOST_AUTO_TEST_CASE(testRemoveNodeNull) {
	linked_list<int> list;
	link_node<int>* idx0 = list.add(0);
	link_node<int>* idx1 = list.add(1);
	link_node<int>* idx2 = list.add(2);
	BOOST_CHECK_THROW(
		list.remove((link_node<int>*)NULL), 
		std::runtime_error
	);
}

// insertAfter Null empty
// insertAfter Null size==1
// insertAfter Null size==2
// insertAfter Null size==3
//
// insertAfter idx0 size==1
// insertAfter idx0 (head) size==2
// insertAfter idx1 (tail) size==2
// insertAfter idx0 (head) size==3
// insertAfter idx2 (tail) size==3
// insertAfter idx1 (middle) size==3
BOOST_AUTO_TEST_CASE(insertAfter) {
	linked_list<int> list;

	// insertAfter Null empty
	list.insertAfter(NULL, 99);
	BOOST_CHECK(list.size() == 1);
	BOOST_CHECK(list.get(0) == 99);
	BOOST_CHECK(list.pop() == 99);
	BOOST_CHECK(list.size() == 0);
	
	// insertAfter Null size==1
	list.add(1);
	list.insertAfter(NULL, 99);
	BOOST_CHECK(list.size() == 2);
	BOOST_CHECK(list.get(0) == 99);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.pop() == 99);
	BOOST_CHECK(list.size() == 0);

	// insertAfter Null size==2
	list.add(1);
	list.add(2);
	list.insertAfter(NULL, 99);
	BOOST_CHECK(list.size() == 3);
	BOOST_CHECK(list.get(0) == 99);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 2);
	BOOST_CHECK(list.pop() == 2);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.pop() == 99);
	BOOST_CHECK(list.size() == 0);

	// insertAfter Null size==3
	list.add(1);
	list.add(2);
	list.add(3);
	list.insertAfter(NULL, 99);
	BOOST_CHECK(list.size() == 4);
	BOOST_CHECK(list.get(0) == 99);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 2);
	BOOST_CHECK(list.get(3) == 3);
	BOOST_CHECK(list.pop() == 3);
	BOOST_CHECK(list.pop() == 2);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.pop() == 99);
	BOOST_CHECK(list.size() == 0);

	// insertAfter idx0 size==1
	link_node<int>* idx0 = list.add(0);
	list.insertAfter(idx0, 99);
	BOOST_CHECK(list.size() == 2);
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 99);
	BOOST_CHECK(list.pop() == 99);
	BOOST_CHECK(list.pop() == 0);
	BOOST_CHECK(list.size() == 0);

	// insertAfter idx0 (head) size==2
	idx0 = list.add(0);
	link_node<int>* idx1 = list.add(1);
	list.insertAfter(idx0, 99);
	BOOST_CHECK(list.size() == 3);
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 99);
	BOOST_CHECK(list.get(2) == 1);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.pop() == 99);
	BOOST_CHECK(list.pop() == 0);
	BOOST_CHECK(list.size() == 0);

	// insertAfter idx1 (tail) size==2
	idx0 = list.add(0);
	idx1 = list.add(1);
	list.insertAfter(idx1, 99);
	BOOST_CHECK(list.size() == 3);
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 99);
	BOOST_CHECK(list.pop() == 99);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.pop() == 0);
	BOOST_CHECK(list.size() == 0);

	// insertAfter idx0 (head) size==3
	idx0 = list.add(0);
	idx1 = list.add(1);
	link_node<int>* idx2 = list.add(2);
	list.insertAfter(idx0, 99);
	BOOST_CHECK(list.size() == 4);
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 99);
	BOOST_CHECK(list.get(2) == 1);
	BOOST_CHECK(list.get(3) == 2);
	BOOST_CHECK(list.pop() == 2);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.pop() == 99);
	BOOST_CHECK(list.pop() == 0);
	BOOST_CHECK(list.size() == 0);

	// insertAfter idx2 (tail) size==3
	idx0 = list.add(0);
	idx1 = list.add(1);
	idx2 = list.add(2);
	list.insertAfter(idx2, 99);
	BOOST_CHECK(list.size() == 4);
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 2);
	BOOST_CHECK(list.get(3) == 99);
	BOOST_CHECK(list.pop() == 99);
	BOOST_CHECK(list.pop() == 2);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.pop() == 0);
	BOOST_CHECK(list.size() == 0);

	// insertAfter idx1 (middle) size==3
	idx0 = list.add(0);
	idx1 = list.add(1);
	idx2 = list.add(2);
	list.insertAfter(idx1, 99);
	BOOST_CHECK(list.size() == 4);
	BOOST_CHECK(list.get(0) == 0);
	BOOST_CHECK(list.get(1) == 1);
	BOOST_CHECK(list.get(2) == 99);
	BOOST_CHECK(list.get(3) == 2);
	BOOST_CHECK(list.pop() == 2);
	BOOST_CHECK(list.pop() == 99);
	BOOST_CHECK(list.pop() == 1);
	BOOST_CHECK(list.pop() == 0);
	BOOST_CHECK(list.size() == 0);
}

