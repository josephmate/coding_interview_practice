
#include <cstddef>          // NULL definition
#include <stdio.h>          // printf
#include "linked_list.hpp"
#include <stdexcept>



linked_node::linked_node(linked_node* n, int d){
	next = n;
	data = d;
}

/**
 * General idea of the approach is to move one pointer slowly and another one
 * quickly.
 * 
 * If the fast pointer reaches NULL, we know that there is no cycle.
 *
 * If the faster pointer reaches the slow pointer, then there must be a cycle.
 * The slow pointer should never catchup to the fast pointer since the speeds
 * are constant.
 */
bool has_cycle(linked_node * head) {
	linked_node * slow_pointer = head; 
	linked_node * fast_pointer = head; 

	while(fast_pointer != NULL) {
		fast_pointer = fast_pointer->next;
		if(fast_pointer == NULL){
			return false;
		}
		if(fast_pointer == slow_pointer) {
			return true;
		}
		fast_pointer = fast_pointer->next;
		if(fast_pointer == slow_pointer) {
			return true;
		}
		slow_pointer = slow_pointer->next;
	}

	return false;
}


