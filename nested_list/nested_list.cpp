
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
	//TODO
}


