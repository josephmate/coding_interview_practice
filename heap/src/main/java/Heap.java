import java.util.*;

public class Heap {
	
/*
  0    1     2     3       4       5       6
[ 1 , 1:1 , 1:2, 1:1:1 , 1:1:2 , 1:2:1 , 1:2:2 , ... ]
  \   /     /     /      /       /         /
   \_/_____/     /      /       /         /
     \     \    /      /       /         /
      \_____\__/______/       /         /
             \               /         /
              \_____________/_________/
*/

	private ArrayList<Integer> heap = new ArrayList<>();

	public Heap() {
	}

	/**
	 *              _________0_______________
	 *             |                         |
	 *        _____1_____           _________2______
	 *        |          |          |               |
	 *    ____3____   ___4___    ___5__          ___6__
	 *    |       |   |      |   |     |         |     |
	 *    7       8   9     10  11     12       13     14
	 *
	 * |_x_| indicates the for of x
	 *    figuring out the depth
	 *    |_log(0+1)_|=0       
	 *    |_log(1+1)_|=1       
	 *    |_log(2+1)_|=1       
	 *    |_log(3+1)_|=2       
	 *    |_log(4+1)_|=2
	 *    |_log(5+1)_|=2
	 *    |_log(6+1)_|=2
	 *    |_log(7+1)_|=3
	 *          ...
	 *    |_log(idx+1)_|=3
	 *
	 * Other things to observe:
	 * Looks like the left child is always *2+1
	 * Looks like the right child is always *2+2
	 * This means that to compute the parent maybe:
	 * |_(idx-1)/2_| gives the parent 
	 */
	public static int getIdxOfParent(int idxOfChild) {
		if(idxOfChild == 0) {
			return 0;
		}
		return (idxOfChild-1)/2;
	}

	public static int getIdxOfChild(int idxOfParent, boolean isLeft) {
		int val = idxOfParent*2 +1;
		if(!isLeft) {
			val++;
		}
		return val;
	}

	/**
	 * Add the value i into the heap
	 */
	public void add(int newval) {
		// append it to the list, ensure that complete/full property is met
		heap.add(newval);

		// fix it so that the parent is always bigger than the children
		int currentIdx = heap.size()-1;
		while(true) {
			int parentIdx = getIdxOfParent(currentIdx);
			if(heap.get(parentIdx) < newval) {
				// The new element is violating the second property of the heap. So
				// swapping it with the parent is enough because, all remaining children
				// and desecendants are still less than the parent. It's just this new
				// guy that isn't.
				heap.set(currentIdx, heap.get(parentIdx));
				heap.set(parentIdx, newval);
				currentIdx = parentIdx;
			} else {
				// Since the new element is smaller than the parent, we know we are no
				// longer violating the second property of a heap.
				break;
			}
		}
		
	}

	/**
	 * Removes the largest value of the heap and returns it
	 */
	public int max() {
		if(heap.size() <=0) {
			throw new IllegalArgumentException("the heap has no elements so max() cannot be called");
		}
		return heap.get(0);
	}

	/**
	 * Removes the largest value of the heap and returns it
	 */
	public int deleteMax() {
		System.out.println("deleteMax: " + heap.toString());
		if(heap.size() <=0) {
			throw new IllegalArgumentException("the heap has no elements so max() cannot be called");
		}
		int retVal = heap.get(0);

		// promote max of left and right to root
		// take last element of array and 'trickle' it down until no more swaps
		// needed
		// - swap need when node < child
		
		int leftIdx = getIdxOfChild(0, true);
		int rightIdx = getIdxOfChild(0, false);
		int currentIdx;
		
		if(heap.size() == 1) {
			heap.remove(heap.size()-1);
			return retVal;
		}

		if(heap.size() == 2) {
			int lastVal = heap.remove(heap.size()-1);
			heap.set(0, lastVal);
			return retVal;
		}

		if( heap.get(leftIdx) > heap.get(rightIdx) ) {
			currentIdx = leftIdx;
		} else {
			currentIdx = rightIdx;
		}
		heap.set(0, heap.get(currentIdx));
		int trickleVal = heap.remove(heap.size()-1);
		if(currentIdx == rightIdx && heap.size() == 2) {
			// nothing left to do, as this value was already the last value in the
			// array
			return retVal;
		}
		heap.set(currentIdx, trickleVal);

		while(true) {
			leftIdx = getIdxOfChild(currentIdx, true);
			rightIdx = getIdxOfChild(currentIdx,false);
			if(leftIdx < heap.size() && heap.get(currentIdx) < heap.get(leftIdx)) {
				heap.set(currentIdx, heap.get(leftIdx));
				heap.set(leftIdx, trickleVal);
				currentIdx = leftIdx;
			} else if(rightIdx < heap.size() && heap.get(currentIdx) < heap.get(rightIdx)) {
				heap.set(currentIdx, heap.get(rightIdx));
				heap.set(rightIdx, trickleVal);
				currentIdx = rightIdx;
			} else {
				break;
			}
		}
		
		return retVal;
	}
	

}
