
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
		link_node<T>* add(T v);

		/**
		 * Insert at the index before the provided link_node
		 * - if NULL is provided, then it's equivalent to add()
		 */
		link_node<T>*  insertBefore(link_node<T>*, T);

		/**
		 * Return the link_node at index idx
		 */
		link_node<T>* get_link_node(int idx);

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
		 * Removes the provided link node from the list.
		 */
		T remove(link_node<T>*);

	
		/**
		 * Returns the number of data items stored in this linked_list
		 */
		int size();
};

