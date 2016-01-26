
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
link_node<T>*  linked_list<T>::add(T v){
	currentSize++;
	link_node<T> * new_node = new link_node<T>(tail, v);
	tail = new_node;
	return new_node;
}


template <class T>
link_node<T>* linked_list<T>::insertBefore(link_node<T>* n, T d){
	if(n == NULL) {
		return add(d);
	}
	
	link_node<T>* new_node = new link_node<T>(n->next, d);
	n->next = new_node;
	currentSize++;

	return new_node;
}

template <class T>
link_node<T>* linked_list<T>::insertAfter(link_node<T> * to_insert, T data) {
	// find the node to_insert
	// while keeping track of prev
	// update prev->next to  new
	// update new->next to curr
	// 
	// NULL <-- 0 <-- 1 <-- 2 <-- tail
	// insert idx1 99
	//       new->next  _- 99 <_  prev->next
	//                 v        \
	// NULL <-- 0 <-- 1          2 <-- tail
	// 							curr        prev
	
	link_node<T>* prev = NULL;
	link_node<T>* curr = tail;
	while(curr != NULL) {
		if(curr == to_insert) {
			link_node<T>* new_node = new link_node<T>(curr, data);
			if(prev != NULL) {
				// we are inserting somewhere in the middle
				prev->next = new_node;
			} else {
				// we are inserting at the tail
				tail = new_node;
			}
			
			currentSize++;
			return new_node;
		}
		prev = curr;
		curr = curr->next;
	}

	// insert before index 0 because to_insert==NULL
	if(to_insert != NULL) {
		throw std::runtime_error("the link_node provided was not found");
	}
	
	link_node<T>* new_node = new link_node<T>(curr, data);
	if(prev != NULL) {
		prev->next = new_node;
	} else {
		// we are inserting at the tail
		tail = new_node;
	}
	currentSize++;
	return new_node;
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
T linked_list<T>::get_without_using_size(int index){
	//TODO
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
T linked_list<T>::remove(link_node<T>* to_remove) {
	// we need to find the link that appears before to_remove so we can update
	// before_to_remove->next to be to_remove_next
	
	link_node<T>* prev = NULL;
	link_node<T>* curr = tail;
	while(curr != NULL) {
		if(curr == to_remove) {
			T ret = curr->data;

			if(prev != NULL) {
				// removing non-tail is easier to handle
				prev->next = curr->next;
			} else {
				// prev == NULL means we are removing the tail of the linked_list
				tail = curr->next;
			}
			delete curr;
			
			currentSize--;
			return ret;
		}

		prev = curr;
		curr = curr->next;
	}

	// not found
	throw  std::runtime_error("the provided link_node was not found in this linked_list");
	// cannot return NULL as that might be a legitimate return value
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
