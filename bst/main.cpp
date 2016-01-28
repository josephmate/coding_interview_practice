
#include <cstdio>
#include <cstdlib>
#include "bst.h"

void print_bst(bst*root, int depth);

int main(int nargs, char** args) {
	bst * root = make_root_bst();
	for(int i = 1; i < nargs; i++) {
		add(root, strtol(args[i], NULL, 10), i);
	}

	printf("the structure of the BST:\n");
	print_bst(root, 0);
	printf("the pre-order output of the BST :\n");
	print_preorder(root);
	print_preorder_no_recursion(root);
	printf("the in-order output of the BST :\n");
	print_inorder(root);
}


void print_bst(bst*root, int depth) {
	if(is_empty(root)) {
		return;
	}

	for(int i = 0; i < depth; i ++) {
		printf("\t");
	}
	if(depth != 0) {
		printf(" ");
	}

	printf("%d : %d\n", root->key, root->value);

	print_bst(root->left, depth+1);
	print_bst(root->right, depth+1);

}
