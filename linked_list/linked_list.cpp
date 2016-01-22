
#include <cstddef>
#include "linked_list.hpp"
#include <stdexcept>




link_node::link_node(link_node* n, int d){
	next = n;
	data = d;
}

linked_list::linked_list() {
	currentSize=0;
	tail = NULL;
}

linked_list::~linked_list() {
	while(tail != NULL) {
		pop();
	}
}



void linked_list::add(int v){
	currentSize++;
	link_node * new_node = new link_node(tail, v);
	tail = new_node;
}

int linked_list::get(int idx) {
	if(idx < 0) {
		throw  std::runtime_error("the idx must be >= 0");
	}
	// figure out how many elements we need to traverse to get to the one at the index
	// recall that the first point is the item with the highest index
	int howManyToGoBack = (currentSize-1) - idx;
	if(howManyToGoBack < 0) {
		throw  std::runtime_error("the idx must be < currentSize");
	}
	link_node * curr = tail;
	for(int i = 1; i <= howManyToGoBack; i++) {
		curr = curr->next;
	}

	return curr->data;
}

int linked_list::pop() {
	if(currentSize <= 0) {
		throw std::runtime_error("cannot pop from an empty list");
	}
	int data = tail->data;
	link_node * to_delete = tail;
	tail = tail->next;
	currentSize--;
	delete to_delete;
	return data;
}

int linked_list::remove(int idx) {
	if(currentSize <= 0) {
		throw std::runtime_error("cannot remove from an empty list");
	}
	if(idx < 0) {
		throw  std::runtime_error("the idx must be >= 0");
	}

	// figure out how many elements we need to traverse to get to the one at the index
	// recall that the first point is the item with the highest index
	int howManyToGoBack = (currentSize-1) - idx;
	if(howManyToGoBack < 0) {
		throw  std::runtime_error("the idx must be < currentSize");
	}
	link_node * curr = tail;
	link_node * prev = NULL;
	for(int i = 1; i <= howManyToGoBack; i++) {
		// we need to keep track of the previous pointer because we link the
		// previous and the next of current in order to remove the current:
		//
		//
		// BEFORE  TAIL  ---->   TAIL-1 ----> ..... ----> PREV ----> CURR ----> CURR->NEXT
		// AFTER                                             \________________> CURR->NEXT
		//
		prev = curr;
		curr = curr->next;
	}
	if(prev != NULL) {
		prev->next=curr->next;
	} else {
		tail = curr->next;
	}
	int data = curr->data;
	delete curr;
	currentSize--;
	return data;
}

int linked_list::size() {
	// we keep track of changes to the size as the methods are accessed
	return currentSize;
}
