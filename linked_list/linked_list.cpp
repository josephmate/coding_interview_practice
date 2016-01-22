
#include <cstddef>
#include "linked_list.hpp"
#include <stdexcept>




template <class T>
link_node<T>::link_node(link_node* n, T d){
	next = n;
	data = d;
}

template <class T>
linked_list<T>::linked_list() {
	currentSize=0;
	tail = NULL;
}

template <class T>
linked_list<T>::~linked_list() {
	while(tail != NULL) {
		pop();
	}
}


template <class T>
void linked_list<T>::add(T v){
	currentSize++;
	link_node<T> * new_node = new link_node<T>(tail, v);
	tail = new_node;
}

template <class T>
T linked_list<T>::get(int idx) {
	if(idx < 0) {
		throw  std::runtime_error("the idx must be >= 0");
	}
	// figure out how many elements we need to traverse to get to the one at the index
	// recall that the first point is the item with the highest index
	int howManyToGoBack = (currentSize-1) - idx;
	if(howManyToGoBack < 0) {
		throw  std::runtime_error("the idx must be < currentSize");
	}
	link_node<T> * curr = tail;
	for(int i = 1; i <= howManyToGoBack; i++) {
		curr = curr->next;
	}

	return curr->data;
}

template <class T>
T linked_list<T>::pop() {
	if(currentSize <= 0) {
		throw std::runtime_error("cannot pop from an empty list");
	}
	T data = tail->data;
	link_node<T> * to_delete = tail;
	tail = tail->next;
	currentSize--;
	delete to_delete;
	return data;
}

template <class T>
T linked_list<T>::remove(int idx) {
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
	link_node<T> * curr = tail;
	link_node<T> * prev = NULL;
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
	T data = curr->data;
	delete curr;
	currentSize--;
	return data;
}

template <class T>
int linked_list<T>::size() {
	// we keep track of changes to the size as the methods are accessed
	return currentSize;
}


// according to this stackoverflow article:
// http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
// I need to instantaiate all templates I want to allow here.
// If I want to provide ANY template, then this code must be merged into the
// header file.
template class linked_list<int>;
template class linked_list<char>;
