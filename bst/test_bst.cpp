
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

	delete_entire_bst(root);
}

void check_lca(bst* root, int key1, int key2, int expectedKey, int expectedVal) {
	int reskey = 0xFFFFFFFF;
	int resval = 0xFFFFFFFF;
	BOOST_CHECK_MESSAGE(lowest_common_ancestor(root, key1, key2, &reskey, &resval), "expecting ancestor for " << key1 << " and " << key2 << " to be found");
	BOOST_CHECK_MESSAGE(expectedKey = reskey, "expecting ancestor for " << key1 << " and " << key2 << " to have key " << expectedKey << " but was " << reskey);
	BOOST_CHECK_MESSAGE(expectedVal = resval, "expecting ancestor for " << key1 << " and " << key2 << " to have value " << expectedVal << " but was " << resval);
}

// test cases:
// empty
// size 1: both keys to the left
// size 1: both keys to the right 
// size 1: one key to the left, one key to the right
// size 1: node itself is one of the keys
// size 2: both keys to the left
// size 2: both keys to the right 
// size 2: one key to the left, one key to the right
// size 2: root itself is one of the keys
// size 2: left child itself is one of the keys
// size 3: both keys to the left
// size 3: both keys to the right 
// size 3: one key to the left, one key to the right
// size 3: root itself is one of the keys
// size 3: left child itself is one of the keys
// size 11: one deeper than the other
//                            100
//                   50              150
//               25      75       125   175
//             15  35  65  85
BOOST_AUTO_TEST_CASE(testLowestCommonAncestor){
	bst* root = make_root_bst();
	// empty
	BOOST_CHECK(!lowest_common_ancestor(root, 1, 2, NULL, NULL));

	// size 1: both keys to the left
	add(root,100,101);
	check_lca(root, 50, 60, 100, 101);
	// size 1: both keys to the right 
	check_lca(root, 150, 160, 100, 101);
	// size 1: one key to the left, one key to the right
	check_lca(root, 50, 160, 100, 101);
	// size 1: node itself is one of the keys
	check_lca(root, 100, 160, 100, 101);
	

	// size 2: both keys to the left
	add(root,50,51);
	check_lca(root, 25, 75, 50, 51);
	// size 2: both keys to the right 
	check_lca(root, 200, 300, 100, 101);
	// size 2: one key to the left, one key to the right
	check_lca(root, 25, 300, 100, 101);
	// size 2: root itself is one of the keys
	check_lca(root, 100, 300, 100, 101);
	// size 2: left child itself is one of the keys
	check_lca(root, 50, 300, 100, 101);
	check_lca(root, 50, 75, 50, 51);


	// size 3: both keys to the left
	add(root,150,151);
	check_lca(root, 25, 75, 50, 51);
	check_lca(root, 74, 75, 50, 51);
	check_lca(root, 24, 25, 50, 51);
	// size 3: both keys to the right 
	check_lca(root, 125, 175, 150, 151);
	check_lca(root, 174, 175, 150, 151);
	check_lca(root, 125, 126, 150, 151);
	// size 3: one key to the left, one key to the right
	check_lca(root, 50, 175, 100, 101);
	// size 3: root itself is one of the keys
	check_lca(root, 50, 100, 100, 101);
	// size 3: left child itself is one of the keys
	check_lca(root, 50, 75, 100, 101);
	check_lca(root, 50, 25, 100, 101);

	// size 11: one deeper than the other
	add(root,25,26);
	add(root,75,76);
	add(root,125,126);
	add(root,175,176);
	add(root,15,16);
	add(root,35,36);
	add(root,65,66);
	add(root,85,86);
	check_lca(root, 85, 25, 50, 51);
	check_lca(root, 90, 25, 50, 51);
	check_lca(root, 25, 125, 100, 101);

	delete_entire_bst(root);
}


