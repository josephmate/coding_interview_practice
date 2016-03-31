import java.util.*;

public class EncodeSpace {
	
	/**
	 * Replaces the spaces in str with %20
	 */
	public static char[] encodeSpace(char [] str) {
		// count how many spaces so we know how large the new buffer needs to be
		int spaceCount = 0;
		for(char ch : str) {
			if(ch == ' ') {
				spaceCount++;
			}
		}

		// allocate a new buffer to place the encoded string in
		char [] res = new char[str.length + 2*spaceCount];
		
		// fill new string with characters from the old string
		// but fill in %20 every time we see a space
		int fillIdx = 0;
		for(int currChar = 0; currChar < str.length; currChar++) {
			char ch = str[currChar];
			if(ch == ' ') {
				res[fillIdx] = '%';
				res[fillIdx+1] = '2';
				res[fillIdx+2] = '0';
				fillIdx+=3;
			} else {
				res[fillIdx] = ch;
				fillIdx++;
			}
		}

		return res;
	}

}
