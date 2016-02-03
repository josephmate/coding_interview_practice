import java.util.*;

public class TelephoneWords {
	
	private TelephoneWords() {
	}

	private static char[][] teleKeyToCharMap = {
		{'0', '0', '0'},  // 0
		{'1', '1', '1'},  // 1
		{'A', 'B', 'C'},  // 2
		{'D', 'E', 'F'},  // 3
		{'G', 'H', 'I'},  // 4
		{'J', 'K', 'L'},  // 5
		{'M', 'N', 'O'},  // 6
		{'P', 'R', 'S'},  // 7
		{'T', 'U', 'V'},  // 8
		{'W', 'X', 'Y'},  // 9
	};
	
	static char getCharKey(int telephoneKey, int place) {
		if(telephoneKey >= 2 && telephoneKey <= 9 && place >=1 && place <= 3) {
			return teleKeyToCharMap[telephoneKey][place-1];
		} else {
			throw new IllegalArgumentException(
					"telephoneKey: " + telephoneKey + " needs to be between 2 and 9."
					+ "place: "  + place + " needs to be between 1 and 3."
			);
		}
	}

	private static int MAX_PLACE_VALUE = 1000000000;
	static int countDigits(int val) {
		if(val <0) {
			throw new IllegalArgumentException("The value must be 0 or positive.");
		}
		if(val == 0) {
			return 1;
		}
		int digits = 1;
		int soFar = 1;

		while(true) {
			if(soFar > val) {
				return digits-1;
			} else if (soFar == val) {
				return digits;
			} else if (soFar == MAX_PLACE_VALUE) {
				return digits;
			} else {
				digits++;
				soFar = soFar*10;
			}
		}
	}

	static int pow(int base, int exp) {
		int ret = 1;
		for(int i = 0; i < exp; i++) {
			ret = ret * base;
		}

		return ret;
	}
	
	/**
	 * Here we accumulate the characters in a buffer and add then when the buffer
	 * is filled.
	 * 
	 * telephone: stores the telephone number we are processing
	 * charIdx: the index into the next character of the buffer to be modified
	 * divisor: the divisor that gives us the place value of the current place value we're
	 *          working on
	 * words: a list of words we have accumulated so far
	 */
	private static void telephoneWordsRecurse(int telephone, int charIdx, char [] soFar, int divisor, List<String> words) {
		if(divisor == 0) {
			words.add(new String(soFar));
			return;
		}

		//            _______________________________ this part removes the prefix numbers
		//            |                        |
		int telekey = (telephone % (divisor*10))/divisor;
		//                                         \
		//                                          ---- this part the suffix numbers

		if(telekey == 0) {
			soFar[charIdx] = '0';
			telephoneWordsRecurse(telephone, charIdx+1, soFar, divisor/10, words);
			soFar[charIdx] = 0;
		} else if (telekey == 1) {
			soFar[charIdx] = '1';
			telephoneWordsRecurse(telephone, charIdx+1, soFar, divisor/10, words);
			soFar[charIdx] = 0;
		} else {
			for(int i = 1; i<=3; i++) {
				soFar[charIdx] = getCharKey(telekey, i);
				telephoneWordsRecurse(telephone, charIdx+1, soFar, divisor/10, words);
				soFar[charIdx] = 0;
			}
		}
	}

	public static List<String> telephoneWords(int telephone) {
		List<String> res = new ArrayList<>();
		int digits = countDigits(telephone);
		char [] buffer = new char[digits];
		telephoneWordsRecurse(telephone, 0, buffer, pow(10, digits-1), res);
		return res;
	}
}
