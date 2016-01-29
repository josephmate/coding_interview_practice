import org.junit.Test;
import static org.junit.Assert.*;

public class TestRemoveChars {

	@Test
	public void emtpyCases() {
		// empty input empty remove 
		assertEquals("", RemoveChars.removeChars("",""));
		
		// nonempty input empty remove
		assertEquals("abc", RemoveChars.removeChars("abc",""));

		// empty input nonempty remove 
		assertEquals("", RemoveChars.removeChars("","abc"));
	}

	@Test
	public void edgeCases() {
		// removes nothing
		assertEquals("abc", RemoveChars.removeChars("abc","efg"));
		
		// removes everything
		assertEquals("", RemoveChars.removeChars("abc","abc"));
		
		// removes contains duplicates
		assertEquals("cd", RemoveChars.removeChars("abcd","bbaa"));
		
		// input contains duplicates
		assertEquals("aaccac", RemoveChars.removeChars("aabccddbdac","bd"));
	}

}
