import java.util.*;

public class IsRotation {
	
	private static boolean isSubstring(String small, String big) {
		return big.indexOf(small) >= 0;
	}

	/**
	 * Since we're only allowed one call to isSubstring(), we have to construct
	 * our method call in some special way where the truth tell us we have a
	 * rotation.
	 *
	 * If we contact a string with itself, it will contain all rotations as
	 * substrings within it:
	 * ex: abc
	 * abcabc
	 *   | |   cab
	 *  | |    bca
	 * | |     abc
	 *
	 *
	 *
	 * Lastly, we need to check the length of the strings, because the non
	 * duplicated string might be longer an still match.
	 * ex: abc , cabc
	 *
	 * abcabc
	 *
	 * cabc is a substring of abcabc and would result in a false positive without
	 * the length check.
	 *
	 */
	public static boolean isRotation(String a, String b) {
		return a.length() == b.length() && isSubstring(b, a + a);
	}

}
