import org.junit.Test;
import static org.junit.Assert.*;

public class TestBinarySearch {

	private void check(int [] input, int target, int expected) {
		assertEquals(expected, BinarySearch.binarySearch(input, 0, input.length-1, target));
		assertEquals(expected, BinarySearch.binarySearchNoRecurse(input, 0, input.length-1, target));
	}

	@Test
	public void testBinarySearch() {
		//1 elements, not found lower
		//1 elements, not found upper
		//1 elements, found
		int [] size1array = {100};
		check(size1array, 50, -1);
		check(size1array, 150, -1);
		check(size1array, 100, 0);

		// even number of elements
		// left of 1st
		// right of 1st
		// right of 2nd
		int [] size2array = {50,100};
		check(size2array,  50,  0);
		check(size2array, 100,  1);
		check(size2array,  25, -1);
		check(size2array,  75, -1);
		check(size2array, 150, -1);

		// odd number of elements
		// inbetween each element
		int [] size3array = {50,100,150};
		check(size3array,  50,  0);
		check(size3array, 100,  1);
		check(size3array, 150,  2);
		check(size3array,  25, -1);
		check(size3array,  75, -1);
		check(size3array, 125, -1);
		check(size3array, 175, -1);

		// larger test
		int [] size10array = {5,20,100,150,235,325,432,1235,2134,3534};
		check(size10array, 5, 0);
		check(size10array, 100, 2);
		check(size10array, 325, 5);
		check(size10array, 432, 6);
		check(size10array, 3534, 9);

		check(size10array, 324, -1);
		check(size10array, 326, -1);
		check(size10array, -123, -1);
		check(size10array, 4000, -1);

		//duplicates
		int [] dupeArray = {10, 20, 20, 30, 40};
		int v1 = BinarySearch.binarySearch(dupeArray, 0, dupeArray.length-1, 20);
		int v2 = BinarySearch.binarySearchNoRecurse(dupeArray, 0, dupeArray.length-1, 20);
		assertTrue((v1 == 1 || v1 == 2) && (v2 == 1 || v2 == 2));
	}

}
