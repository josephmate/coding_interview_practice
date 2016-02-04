import java.util.*;

public class PermuteString {
	
	private PermuteString() {
	}

	/**
	 * strToPermute: the string we generate permutations from
	 * usedChars: usedChars[i] is true if we used character strToPermute.charAt(i)
	 * soFar: the buffer of used characters so far
	 * index: the index to place the next character into soFar ie: soFar[index]
	 */
	private static void permuteStringHelper(
			String strToPermute, 
			boolean [] usedChars, 
			char [] soFar, // so we only allocate an array on the first call from fascade (if we used String, a new object would be created every time we append to the string
			int index,
			List<String> permutations) {
		// we've filled the string buffer, so add it
		// clean up is handled by the caller
		if(index >= strToPermute.length()) {
			permutations.add(new String(soFar));
			return;
		}
		
		for(int i = 0; i < strToPermute.length(); i++) {
			// before trying the char, make sure that is hasn't been used yet
			if(!usedChars[i]) {
				char nextChar = strToPermute.charAt(i);
				usedChars[i] = true;
				soFar[index] = nextChar;
				permuteStringHelper(strToPermute, usedChars, soFar, index+1, permutations);

				// (clean up)/(unwind) the mess we made in the above recursive call 
				usedChars[i] = false;
				soFar[index] = 0; //we don't actually have to do this because we use an index, but it makes debugging easier
			}
		}	

	}

	public static List<String> permuteString(String strToPermute) {
		List<String> res = new ArrayList<>();
		if(strToPermute.isEmpty()) {
			return res;
		}
		permuteStringHelper(strToPermute, new boolean[strToPermute.length()], new char[strToPermute.length()], 0, res);
		return res;
	}
}
