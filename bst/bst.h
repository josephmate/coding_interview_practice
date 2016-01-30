#ifndef BST_H
#define BST_H



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct bst bst;

/**
 * Don't want to have a separate leaf or empty flag. As a result, a leaf is if
 * both children are empty. A node is empty is both children are NULL.
 */
struct bst {
	bst * left;
	bst * right;
	int key;
	int value;
};

/**
 * creates a single node of the bst
 */
bst* make_root_bst();

int is_empty(bst * node);

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
int find(bst * root, int key, int * value);

/**
 * Prints the BST using a pre-order traversal. Print the current node, then the
 * left, then the right.
 */
void print_preorder(bst * root);

void print_preorder_no_recursion(bst * root);

/**
 * Prints the BST using an in-order traversal. Print the left, then the
 * current node, then the right.
 */
void print_inorder(bst * root);

 /**
	* Populates the reskey and resval pointers with the key and value of the first
	* shared ancestor of key1 and key2.
	*
	* Returns 1 if common ancestor was found
	* Returns 0 if common ancestor was not found. This can only happen if the bst
	* is empty.
	*
	* If BST does not contain either key, we return the key and value from the
	* node just before the search diverges. If the search never diverges, we
	* return the leaf.
	*/
int lowest_common_ancestor(bst*root, int key1, int key2, int * reskey, int * resval);



#ifdef __cplusplus
}
#endif // __cplusplus


#endif // BST_H
