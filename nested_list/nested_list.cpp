
#include <cstddef>          // NULL definition
#include <stdio.h>          // printf
#include "nested_list.hpp"
#include <stdexcept>



nested_node::nested_node(nested_node* p, nested_node* n, int d){
	prev = p;
	next = n;
	data = d;
}

nested_list::nested_list() {
	currentSize=0;
	head = NULL;
	tail = NULL;
}

nested_list::~nested_list() {
	while(tail != NULL) {
		pop();
	}
}


nested_node* nested_list::add(int v){
	currentSize++;
	nested_node * new_node = new nested_node(tail, NULL, v);
	if(tail != NULL) {
		tail->next = new_node;
	}
	tail = new_node;
	if(head == NULL) {
		head = new_node;
	}
	return new_node;
}

nested_node* nested_list::get_node(int idx){
	if(idx < 0) {
		throw  std::runtime_error("the idx must be >= 0");
	}
	if(idx >= currentSize) {
		throw  std::runtime_error("the idx must be < currentSize");
	}
	nested_node * curr = head;
	for(int i = 1; i <= idx; i++) {
		curr = curr->next;
	}

	return curr;
}

int nested_list::get(int idx) {
	return get_node(idx)->data;
}

int nested_list::pop() {
	if(currentSize <= 0) {
		throw std::runtime_error("cannot pop from an empty list");
	}
	int data = tail->data;
	nested_node * to_delete = tail;
	tail = tail->next;
	currentSize--;
	delete to_delete;
	if(currentSize==0){
		head = NULL;
	}
	return data;
}

int nested_list::size() {
	// we keep track of changes to the size as the methods are accessed
	return currentSize;
}

nested_node*  nested_list::extract(nested_list* list) {
	nested_node* ret =  list->head;
	list->head = NULL;
	list->tail = NULL;
	list->currentSize = 0;
	delete list;
	return ret;
}

nested_node* find_tail(nested_node* list) {
	nested_node* curr = list;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	return curr;
}

void nested_list::flatten(){
	nested_node* curr = head;

	while(curr != NULL) {
		if(curr->child != NULL) {
			//attach the child to our tail
			tail->next = curr->child;
			curr->child->prev = tail;
			// figure out where the new tail will be
			tail=find_tail(curr->child);
		}
		curr = curr->next;
	}
}
		
void nested_list::unflatten(){
	// The strategy is to recurse on the children, until we are at the deepest
	// child
	// Then we move remove the deepest tailmost child from the flattened list
	// and continue until we reach the head of deepest tailmost child
	//
	// By proceeding in this manor, we can guarentee that the end of list so far
	// ie curr->next == NULL, is also the last member of the deepest tailmost child
	//
	// After removing it, the tail is the last member of the next deepest tailmost
	// child.
	// 
	//
	// In summary the order is:
	// - always recurse before doing anything
	// - recurse from tailmost to headmost
	nested_node* curr = tail;
	while (curr != NULL) {
		// found a node that doesn't have a child
		// remove from curr->child to tail 
		if(curr->child != NULL) {
			tail = curr->child->prev;
			curr->child->prev->next = NULL;
			curr->child->prev = NULL;
		}
		curr = curr->prev;
	}
}


