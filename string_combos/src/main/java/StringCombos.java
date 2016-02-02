import java.util.*;

public class StringCombos {
	
	private StringCombos() {
	}

	public static void stringCombos(String strToCombo, int maxLen, int charposn, int startIdx, char [] soFar, List<String> combos) {
		if(charposn >= maxLen) {
			combos.add(new String(soFar,0, maxLen));
			return;
		}
		if(startIdx >= strToCombo.length()) {
			// we didn't accumulate enough characters
			return;
		}
		
		// the strategy is to enumerate all combos starting from startIdx instead of 0
		// as in the permutation method. This ensure we do not duplicate
		// combinations. For example "12"
		// 
		// root call:recurse:stringCombos( maxLen = 2, charposn = 0, startIdx = 0 )
		//   "1"
		//     recurse:stringCombos( maxLen = 2, charposn = 1, startIdx = 1 )
		//       "2"
		//         recurse:stringCombos( maxLen = 2, charposn = 2, startIdx = 2 )
		//           char array filled, return
		//   "2"
		//     recurse:stringCombos( maxLen = 2, charposn = 1, startIdx = 2 )
		//       no more characters left
		for(int i = startIdx; i < strToCombo.length(); i++) {
			soFar[charposn] = strToCombo.charAt(i);
			stringCombos(strToCombo, maxLen, charposn+1, i+1, soFar, combos);
			soFar[charposn] = 0; // set it to null for debugging purposes
		}
	}

	public static List<String> stringCombos(String strToCombo) {
		List<String> res = new ArrayList<>();
		
		char [] buffer = new char[strToCombo.length()];
		
		for(int l = 1; l <= strToCombo.length(); l++) {
			stringCombos(strToCombo, l, 0, 0, buffer, res);
		}

		return res;
	}
}
