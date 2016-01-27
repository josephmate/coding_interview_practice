
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE BST
#include <boost/test/unit_test.hpp>

#include "bst.h" 


// size 0 not found
// size 1 not found
// size 1 found
// size 2 not found
// size 2 found root
// size 2 found left
// size 2 found right 
// size 3 not found
// size 3 found root 
// size 3 found left
// size 3 found right
BOOST_AUTO_TEST_CASE(simpleTestCases){
	// size 0 not found
	bst* root = make_root_bst();
	int value = 0;
	BOOST_CHECK(!find(root, 10, &value));

	delete_entire_bst(root);

	// size 1 not found
	root = make_root_bst();
	add(root, 9, 213);
	BOOST_CHECK(!find(root, 10, &value));

	// size 1 found
	BOOST_CHECK(find(root, 9, &value));
	BOOST_CHECK(value == 213);

	// size 2 not found
	add(root, 7, 12);
	BOOST_CHECK(!find(root, 10, &value));

	// size 2 found root
	value = 0;
	BOOST_CHECK(find(root, 9, &value));
	BOOST_CHECK(value == 213);

	// size 2 found left
	value = 0;
	BOOST_CHECK(find(root, 7, &value));
	BOOST_CHECK(value == 12);

	// size 2 found right 
	delete_entire_bst(root);
	root = make_root_bst();
	add(root, 9, 213);
	add(root, 12, 22);
	value = 0;
	BOOST_CHECK(find(root, 12, &value));
	BOOST_CHECK(value == 22);


	// size 3 not found
	add(root, 7, 12);
	BOOST_CHECK(!find(root, 8, &value));
	BOOST_CHECK(!find(root, 10, &value));

	// size 3 found root 
	value = 0;
	BOOST_CHECK(find(root, 9, &value));
	BOOST_CHECK(value == 213);

	// size 3 found left
	value = 0;
	BOOST_CHECK(find(root, 7, &value));
	BOOST_CHECK(value == 12);

	// size 3 found right
	value = 0;
	BOOST_CHECK(find(root, 12, &value));
	BOOST_CHECK(value == 22);
}

