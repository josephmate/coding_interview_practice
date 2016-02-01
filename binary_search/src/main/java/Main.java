import java.util.*;

public class Main {

	public static void main(String []args) {
		if(args.length < 2) {
			throw new IllegalArgumentException(
					"This program need at least two arguments: target array_element_1 array_element_2  ... ");
		}
		
		int target = Integer.parseInt(args[0]);
		List<Integer> vals = new ArrayList<>();
		for(int i = 1; i < args.length; i++) {
			vals.add(Integer.parseInt(args[i]));
		}

		Collections.sort(vals);

		int [] array = new int[vals.size()];
		for(int i = 0; i < vals.size(); i++) {
			array[i] = vals.get(i);
		}

		int found = BinarySearch.binarySearch(array, 0, array.length-1, target) ;
		int foundNoRecurse = BinarySearch.binarySearchNoRecurse(array, 0, array.length-1, target) ;

		System.out.println("binarySearch() returned:          " + found);
		System.out.println("binarySearchNoRecurse() returned: " + foundNoRecurse);
	}

}
