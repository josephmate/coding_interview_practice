import java.util.*;

public class BinarySearch {
	
	private BinarySearch() {
	}


	/**
	 * array: the array to search in
	 * lower: the lowest index to search from
	 * upper: the highest index to search to
	 * target: the value being search for in the array
	 *
	 * Returns the index that the target was found in. Otherwise, this method
	 * returns -1.
	 */
	public static int binarySearch(int[] array, int lower, int upper, int target) {
		// in this case we were unable to find the target element
		if(lower > upper) {
			return -1;
		}

		if(lower >= array.length || lower < 0) {
			throw new IllegalArgumentException("lower (" + lower + ") must be > 0 and < the array length. It must be able to index a valid element in the array");
		}
		if(upper >= array.length || upper < 0) {
			throw new IllegalArgumentException("upper (" + upper + ") must be > 0 and < the array length. It must be able to index a valid element in the array");
		}

		int mid = (upper+lower)/2;

		if(array[mid] == target) {
			// we have found the element, so we're done
			return mid;
		} else if(target > array[mid]) {
			// We can conclude that everything below array[mid] is not equal to the
			// target because they are smaller than the target.
			// 
			// The mid+1 is because we already looked at the array[mid] element and
			// there is no point in looking at it again. Secondly, it provides a
			// convenient exit condition as when lower==upper, mid+1 will be greater
			// than upper, and we'll exit.
			return binarySearch(array, mid+1, upper, target);
		} else { //if(target < array[mid]) {
			return binarySearch(array, lower, mid-1, target);
		}

	}

	public static int binarySearchNoRecurse(int[] array, int lower, int upper, int target) {
		if(lower >= array.length || lower < 0) {
			throw new IllegalArgumentException("lower (" + lower + ") must be > 0 and < the array length. It must be able to index a valid element in the array");
		}
		if(upper >= array.length || upper < 0) {
			throw new IllegalArgumentException("lower (" + lower + ") must be > 0 and < the array length. It must be able to index a valid element in the array");
		}

		while(true) {
			// in this case we were unable to find the target element
			if(lower > upper) {
				return -1;
			}

			int mid = (upper+lower)/2;

			if(array[mid] == target) {
				// found the element
				return mid;
			} else if(target > array[mid]) {
				// target definately isn't in lower half, so update values so we can
				// narrow in on the upper half
				lower = mid+1;
			} else { //if(target < array[mid]) {
				upper = mid-1;
			}

		}
	}


}
