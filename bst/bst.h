

struct bst {
	bst * left;
	bst * right;
	int key;
	int value;
};

/**
 * creates a single node of the bst
 */
bst* make_bst_node(bst * left, bst* right, int data);


/**
 * given the root of the tree, safely deletes all nodes in it
 */
void delete_entire_bst(bst * root);

/**
 * After calling add(root, key, value), find(root, key, &vp) will place value
 * in vp.
 */
void add(bst * root, int key, int value);

/**
 * Returns true if key is found in the tree. int*value will be populated with
 * the found value.
 *
 * Otherwise, returns false and int*value is left untouched.
 */
bool find(bst * root, int key, int * value);

