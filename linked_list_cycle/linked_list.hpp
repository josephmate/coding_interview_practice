

struct linked_node {
	linked_node * next;
	int data;
	linked_node(linked_node* next, int data);
};

bool has_cycle(linked_node * head) ;


