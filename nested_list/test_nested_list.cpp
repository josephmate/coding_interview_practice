
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE NESTED_LIST
#include <boost/test/unit_test.hpp>
#include <stdio.h>
#include <unordered_map> 

#include "nested_list.hpp" 



void print_list(nested_node * node) {
	nested_node * curr = node;
	while(curr != NULL) {
		printf("%d, ", curr->data);
		curr = curr->next;
	}
}

void print_tree(nested_node * node, int depth, int rootIdx) {
	for(int i = 0; i < depth; i++) {
		printf("\t");
	}
	printf("%d:", rootIdx);
	print_list(node);
	printf("END\n");
	nested_node * curr = node;
	int c = 0;
	while(curr != NULL) {
		if(curr->child != NULL) {
			print_tree(curr->child, depth+1, c);
		}
		curr = curr->next;
		c++;
	}
}

/**
 *  top
 *  0 -> 1 -> 2 -> 3
 *  |         |    |
 *  |         |    d1c: 30
 *  |         |
 *  |         d1b: 20 -> 21
 *  |
 *  d1a: 10 -> 11 -> 12
 *        |     |     |
 *        |     |     d2a3: 60 61
 *        |     |     
 *        |     d2a2: 50
 *        |     
 *        d2a1: 40 41 42
 *
 *
 * check flatten condition with:
 * 1. iterate thru list after flatten
 * 2. check that all elements in tree have been hit once and only once
 */
BOOST_AUTO_TEST_CASE(simpleTestCases){
	printf("adding root nodes\n");
	nested_list* top = new nested_list();
	nested_node * idx0 = top->add(0);
	nested_node * idx1 = top->add(1);
	nested_node * idx2 = top->add(2);
	nested_node * idx3 = top->add(3);

		printf("\tadding depth1\n");
		nested_list* ldepth1a = new nested_list();
		nested_node * idx0depth1a = ldepth1a->add(10);
		nested_node * idx1depth1a = ldepth1a->add(11);
		nested_node * idx2depth1a = ldepth1a->add(12);
		nested_node * depth1a = nested_list::extract(ldepth1a);
		idx0->child = depth1a;
			
			printf("\t\tadding depth2\n");
			nested_list * ldepth2a1 = new nested_list();
			nested_node * idx0depth2a1 = ldepth2a1->add(40);
			nested_node * idx1depth2a1 = ldepth2a1->add(41);
			nested_node * idx2depth2a1 = ldepth2a1->add(42);
			nested_node * depth2a1 = nested_list::extract(ldepth2a1);
			idx0depth1a->child = depth2a1;

			nested_list * ldepth2a2 = new nested_list();
			nested_node * idx0depth2a2 = ldepth2a2->add(50);
			nested_node * depth2a2 = nested_list::extract(ldepth2a2);
			idx1depth1a->child = depth2a2;

			nested_list * ldepth2a3 = new nested_list();
			nested_node * idx0depth2a3 = ldepth2a3->add(60);
			nested_node * idx1depth2a3 = ldepth2a3->add(61);
			nested_node * depth2a3 = nested_list::extract(ldepth2a3);
			idx2depth1a->child = depth2a3;
			printf("\t\tdone depth2\n");

		nested_list * ldepth1b = new nested_list();
		nested_node * idx0depth1b = ldepth1b->add(20);
		nested_node * idx1depth1b = ldepth1b->add(21);
		nested_node * depth1b = nested_list::extract(ldepth1b);
		idx2->child = depth1b;

		nested_list * ldepth1c = new nested_list();
		nested_node * idx0depth1c = ldepth1c->add(30);
		nested_node * depth1c = nested_list::extract(ldepth1c);
		idx3->child = depth1c;
		printf("\tdone depth1\n");

	printf("done root\n");
	print_tree(idx0, 0, 0);

	printf("flattening\n");
	top->flatten();
	printf("done flattening\n");
	
	int expected[] = {0,1,2,3,10,11,12,40,41,42,50,60,61,20,21,30};
	std::unordered_map<int,int> visited;
	nested_node* curr = idx0;
	while(curr != NULL) {
		printf("adding %d\n", curr->data);
		std::unordered_map<int,int>::const_iterator keyval = visited.find(curr->data);
		if(keyval == visited.end()) {
			visited[curr->data] = 1;
		} else {
			visited[curr->data] += 1;
		}
		curr = curr->next;
	}

	for(int i = 0; i< 16; i++) {
		std::unordered_map<int,int>::const_iterator keyval = visited.find(expected[i]);
		printf("checking if %d is in the list\n", expected[i]);
		BOOST_CHECK(keyval != visited.end());
		if(keyval != visited.end()) {
			BOOST_CHECK(keyval->second == 1);
		}
	}

}

