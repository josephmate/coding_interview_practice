
#include <cstddef>
#include <stdexcept>

template <class T>
struct link_node {
	link_node<T> * next;
	T data;
	link_node(link_node<T>*, T);
};

template <class T>
class stack {

	int currentSize;
	/**
	 *
	 *  ln     --> ln     --> ln
	 *  * ----/    * ----/    * : NULL
	 *  1          2          3
	 *
	 */
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


template <class T>
link_node<T>::link_node(link_node<T>* n, T d) {
	next = n;
	data = d;
}

template <class T>
stack<T>::stack() {
	currentSize = 0;
	tail = NULL;
}

template <class T>
stack<T>::~stack() {
	while(tail != NULL) {
		pop();
	}
}

template <class T>
void stack<T>::push(T v) {
	link_node<T> * new_node = new link_node<T>(tail, v);
	tail = new_node;
	currentSize++;
}

template <class T>
T stack<T>::pop() {
	if(currentSize <= 0) {
		throw std::runtime_error("cannot pop from an empty list");
	}
	T ret = tail->data;

	link_node<T> * to_delete = tail;
	tail = tail->next;
	delete to_delete;

	currentSize--;

	return ret;
}

template <class T>
int stack<T>::size() {
	return currentSize;
}

