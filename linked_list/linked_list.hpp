
template <class T>
struct link_node {
	link_node<T> * next;
	T data;
	link_node(link_node<T>*, T);
};

template <class T>
class linked_list {

	int currentSize;
	link_node<T> * tail;

	public:
		linked_list();
		~linked_list();

		/**
		 * Adds value v to the end of the list
		 */
		void add(T v);

		/**
		 * Return the value at index idx
		 */
		T get(int idx);

		/**
		 * Removes and returns the most recently added value
		 */
		T pop();
		
		/**
		 * Remove and returns the value at index idx.
		 */
		T remove(int idx);
	
		/**
		 * Returns the number of data items stored in this linked_list
		 */
		int size();
};

