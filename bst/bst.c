
#include <stddef.h>          // NULL definition
#include <stdlib.h>
#include "bst.h"


bst* make_root_bst() {
	bst * ret = (bst*)malloc(sizeof(bst));
	ret->left = NULL;
	ret->right = NULL;
	ret->key = 0;
	ret->value = 0;
}


void delete_entire_bst(bst * root) {
	if(root->left != NULL) {
		delete_entire_bst(root->left);
	}
	if(root->right != NULL) {
		delete_entire_bst(root->right);
	}
	free(root);
}

int is_empty(bst * node){
	return node->left == NULL && node->right == NULL;
}

int is_leaf(bst * node) {
	if(node->left == NULL) {
		return 0;
	}
	if(node->right == NULL) {
		return 0;
	}
	
	return is_empty(node->left) && is_empty(node->right);
}

void add(bst * root, int key, int value) {
	if(is_empty(root)) {
		// we've reached an empty node, so we can place the value there
		root->left = make_root_bst();
		root->right = make_root_bst();
		root->key = key;
		root->value = value;
	} else if(root->key == key) {
		// key already exists in the tree, so just update the value
		root->value = value;
	} else if(key < root->key) {
		add(root->left, key, value);
	} else { // if (root->key < key )
		add(root->right, key, value);
	}
}


int find(bst * root, int key, int * value) {
	if(is_empty(root)) {
		return 0;
	} else if(root->key == key) {
		*value = root->value;
		return 1;
	} else if(key < root->key) {
		return find(root->left, key, value);
	} else { // if (root->key < key )
		return find(root->right, key, value);
	}
}

