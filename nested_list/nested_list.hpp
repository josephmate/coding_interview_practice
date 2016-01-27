

struct nested_node {
	nested_node * prev;
	nested_node * next;
	// we cannot make this a nested_list beacuse
	// as we flatten a list, the head and tail of the nested list
	// may not alonger apply and we must maintain a pointer to
	// the children so that we can unflatten it
	nested_node * child;
	int data;
	nested_node(nested_node* prev, nested_node* next, int);
};



class nested_list {

	int currentSize;
	nested_node * head; // the least recently added
	nested_node * tail; // the most recently added

	void unflatten_recurse(nested_node * curr);

	public:
		nested_list();
		~nested_list();
		
		static nested_node* extract(nested_list*);

		/**
		 * Adds value v to the end of the list
		 */
		nested_node* add(int v);

		/**
		 * Return the node at index idx
		 */
		nested_node* get_node(int idx);

		/**
		 * Return the value at index idx
		 */
		int get(int idx);

		/**
		 * Removes and returns the most recently added value
		 * ie: the value in the highest index
		 */
		int pop();
		
		/**
		 * Returns the number of data items stored in this nested_list (not
		 * including children) 
		 */
		int size();

		/**
		 * Places the children nodes, into the nested_list
		 * - does not modify the children points, only the prev, next, head tail
		 *   pointers can be modified
		 * - assume that you do not have the add() method available
		 */
		void flatten();
		
		/**
		 * Undo the effects of flatten()
		 */
		void unflatten();
};

