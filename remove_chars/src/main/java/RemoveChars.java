import java.util.*;

public class RemoveChars {
	
	private RemoveChars() {
	}

	public static String removeChars(String input, String charsToRemove) {
		Set<Character> removeSet = new HashSet<>();
		for(int i = 0; i < charsToRemove.length(); i++) {
			removeSet.add(charsToRemove.charAt(i));
		}

		StringBuilder strBuilder = new StringBuilder();
		for(int i = 0; i < input.length(); i++) {
			char curr = input.charAt(i);
			if(!removeSet.contains(curr)) {
				strBuilder.append(curr);
			}
		}

		return strBuilder.toString();
	}

}
