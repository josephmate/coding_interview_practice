import java.util.*;

public class RemoveChars {
	
	private RemoveChars() {
	}

	public static String removeChars(String input, String charsToRemove) {
		// Construct a hashset of characters to be removed for O(1) lookup to be
		// used latter.
		//
		// The construction of this map is O(M) where M is the number of characters
		// in 'charsToRemove'
		//
		// Currently there are approx 100,000 unique unicode characters. As a result
		// if the charsToRemove is much smaller than the number of unique
		// characters, it's probably better to go with a hashmap because the size of
		// the hashmap will be better than using a lookup table.
		Set<Character> removeSet = new HashSet<>();

		// Here we use .charAt instead of iterating over .toCharArray() because
		// toCharArray() creates a new array
		for(int i = 0; i < charsToRemove.length(); i++) {
			removeSet.add(charsToRemove.charAt(i));
		}
		
		// We use a StringBuilder so that we can efficiently append characters with
		// O(1) time on average. Occassionally, the append will take O(N) time when
		// it needs to expand but is amortized to become O(1).
		StringBuilder strBuilder = new StringBuilder();
		for(int i = 0; i < input.length(); i++) {
			char curr = input.charAt(i);
			if(!removeSet.contains(curr)) {
				strBuilder.append(curr);
			}
		}

		// Unfortunately, this will make a second copy of the result. The only way
		// around this would be to change the signature of the to something like:
		//
		// public static void removeChars(char[] input, char[] charsToRemove)
		// and remove the characters in place
		//
		// or
		//
		// public static char[] removeChars(char[] input, char[] charsToRemove)
		// and build the char[] array by manually instead of using StringBuilder
		return strBuilder.toString();
	}

}
