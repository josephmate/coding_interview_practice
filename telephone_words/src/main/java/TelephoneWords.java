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
	
	private static byte [] getKeys(int telephone) {
		int digits = countDigits(telephone);
		byte [] keys = new byte[digits+1];
		int divisor = pow(10,digits-1);
		for(int i = 1; i <= digits; i++) {
			// this is a safe cast as the result will always be between 0 and 9
			keys[i] = (byte)(telephone/divisor);
			telephone = telephone % divisor;
			divisor = divisor/10;
		}
		return keys;
	}

	private static void incrementCounter(byte[] counter) {
		for(int i = counter.length - 1; i >= 0; i--) {
			// ignore the 0 digits, because they represent the 0 and 1 keys which have
			// no alphabet enumeration
			if(counter[i] > 0) {
				// increase
				counter[i]++;

				// check if we need to carry to the next place value
				if(counter[i] <= 3) {
					break;
				} else {
					counter[i] = 1;
				}
			}
		}
	}

	private static byte[] initCounter(byte[] keys) {
		byte [] counter = new byte[keys.length];
		counter[0] = 1; // the overflow place value is always 1 (until we're done)

		for(int i = 1; i < keys.length; i++) {
			if(keys[i] != 0 && keys[i] != 1) {
				counter[i] = 1;
			}
		}
		return counter;
	}

	private static String convertToAlpha(byte[] keys, byte[] counter) {
		StringBuilder builder = new StringBuilder();
		for(int i = 1; i < keys.length; i++) {
			if(keys[i] == 0) {
				builder.append("0");
			} else if(keys[i] == 1) {
				builder.append("1");
			} else {
				builder.append(getCharKey(keys[i],counter[i]));
			}
		}
		return builder.toString();
	}

	/**
	 * The idea is to keep an array of of bytes that represent the the next string
	 * of characters to use, and we just increment it until we get all possible
	 * characters. For example:
	 *
	 * Number:                 overflow  1 2 3 1 2 4 0 3 1
	 * 1st iteration of array:     1,    0,1,1,0,1,1,0,1,0
	 * 2nd iteration of array:     1,    0,1,1,0,1,1,0,2,0
	 * 3rd iteration of array:     1,    0,1,1,0,1,1,0,3,0
	 * 4th iteration of array:     1,    0,1,1,0,1,2,0,1,0
	 * ...
	 *
	 * Notice that 1 and 0 are always represented by a 0 because they have no
	 * corresponding alphabet characters.
	 *
	 * Once overlow is 2, we know it's time to stop.
	 */
	public static List<String> telephoneWordsNoRecurse(int telephone) {
		List<String> res = new ArrayList<>();
		int digits = countDigits(telephone);

		// determine the individuals keys for easier processing
		byte [] keys = getKeys(telephone);

		byte [] counter = initCounter(keys);

		while(counter[0] <= 1) {
			res.add(convertToAlpha(keys,counter));
			incrementCounter(counter);
		}

		return res;
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
		return telephoneWordsNoRecurse(telephone);
	}
}
