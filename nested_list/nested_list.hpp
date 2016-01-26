
struct nested_node;
class nested_list;

struct nested_node {
	nested_node * prev;
	nested_node * next;
	nested_list * child;
	int data;
	nested_node(nested_node* prev, nested_node* next, int);
};

class nested_list {

	int currentSize;
	nested_node * head; // the least recently added
	nested_node * tail; // the most recently added

	public:
		nested_list();
		~nested_list();

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

