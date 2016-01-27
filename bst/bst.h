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


#endif // BST_H


#ifdef __cplusplus
}
#endif // __cplusplus
