
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
	int howManyToGoBack = currentSize - idx + 1;
	if(howManyToGoBack < 0) {
		throw  std::runtime_error("the idx must be < currentSize");
	}
	link_node * curr = tail;
	for(int i = 0; i <= howManyToGoBack; i++) {
		curr = curr->next;
	}

	return curr->data;
}

int linked_list::pop() {
	int data = tail->data;
	link_node * to_delete = tail;
	tail = tail->next;
	delete to_delete;
}

int linked_list::remove(int idx) {
	if(idx < 0) {
		throw std::runtime_error("the idx must be >= 0");
	}
	int howManyToGoBack = currentSize - idx + 1;
	if(howManyToGoBack < 0) {
		throw std::runtime_error("the idx must be < currentSize");
	}
	link_node * curr = tail;
	for(int i = 0; i <= howManyToGoBack; i++) {
		curr = curr->next;
	}
	// TODO
}

int linked_list::size() {
	return currentSize;
}
