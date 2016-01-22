
template <class T>
struct link_node {
	link_node<T> * next;
	T data;
	link_node(link_node<T>*, T);
};

template <class T>
class stack {

	int currentSize;
	link_node<T> * tail;

	public:
		stack();
		~stack();

		/**
		 * Adds value v to the end of the list
		 */
		void push(T v);

		/**
		 * Removes and returns the most recently added value
		 */
		T pop();
		
		/**
		 * Returns the number of data items stored in this linked_list
		 */
		int size();
};

