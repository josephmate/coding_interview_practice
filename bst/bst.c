
#include <stddef.h>     // NULL definition
#include <stdlib.h>     // malloc
#include <stdio.h>      // printf
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

void print_preorder_helper(bst * root, int isRoot) {
	if(is_empty(root)) {
		return;
	}
	if(!isRoot) {
		printf(", ");
	}
	printf("%d->%d", root->key, root->value);
	print_preorder_helper(root->left, 0);
	print_preorder_helper(root->right, 0);

	if(isRoot) {
		printf("\n");
	}
}

void print_preorder(bst * root) {
	print_preorder_helper(root, 1);
}

/**
 * Unfortunately, C doesn't come with a stack implementation, so we have to
 * provide our own.
 */
typedef struct stack stack;
struct stack {
	stack * next;
	bst * data;
};

stack* make_stack() {
	return NULL;
}

stack* make_stack_helper(stack* next, bst * data) {
	stack* ret = malloc(sizeof(stack));
	ret->next = next;
	ret->data = data;
	return ret;
}

/**
 * Returns a pointer to the new head
 */
void push(stack ** head, bst * data) {
	stack* new_head = make_stack_helper(*head, data);
	*head = new_head;
}

/**
 * Returns a pointer to the new head
 * populates data with the data
 */
bst* pop(stack ** head) {
	bst *data = (*head)->data;
	stack * new_head = (*head)->next;
	free(*head);
	*head = new_head;
	return data;
}

int stack_is_empty(stack * head) {
	return head == NULL;
}


void print_preorder_no_recursion(bst * root) {
	int isFirst = 1;
	bst * curr = NULL;
	stack * stack = make_stack();

	push(&stack, root);
	while(!stack_is_empty(stack)) {
		bst * curr = pop(&stack);
		if(is_empty(curr)) {
			continue;
		}
		if(!isFirst) {
			printf(", ");
		} else {
			isFirst = 0;
		}
		printf("%d->%d", curr->key, curr->value);
		push(&stack, curr->right);
		push(&stack, curr->left);
	}
	printf("\n");
}

void print_inorder_helper(bst * root, int isRoot, int * isFirst) {
	if(is_empty(root)) {
		return;
	}
	print_inorder_helper(root->left, 0, isFirst);
	if(!*isFirst) {
		printf(", ");
	} else {
		*isFirst = 0;
	}
	printf("%d->%d", root->key, root->value);
	print_inorder_helper(root->right, 0, isFirst);

	if(isRoot) {
		printf("\n");
	}
}

void print_inorder(bst * root) {
	int isFirst = 1;
	print_inorder_helper(root, 1, &isFirst);
}




