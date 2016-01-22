struct link_node {
	link_node * next;
	int data;
	link_node(link_node*, int);
};

class linked_list {

	int currentSize;
	link_node * tail;

	public:
		linked_list();
		~linked_list();

		/**
		 * Adds value v to the end of the list
		 */
		void add(int v);

		/**
		 * Return the value at index idx
		 */
		int get(int idx);

		/**
		 * Removes and returns the most recently added value
		 */
		int pop();
		
		/**
		 * Remove and returns the value at index idx.
		 */
		int remove(int idx);
	
		/**
		 * Returns the number of data items stored in this linked_list
		 */
		int size();
};

