import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public class TestStringCombos {
	
	public void checkContains(List<String> actual, String ... possibleCombos) {
		boolean okay = false;
		for(String s : possibleCombos) {
			if(actual.contains(s)){
				return;
			}
		}
		assertTrue(false);
	}

	@Test
	public void testStringCombos() {
		List<String> actual = StringCombos.stringCombos("");
		assertTrue(actual.isEmpty());
		
		// size 1
		actual = StringCombos.stringCombos("1");
		assertEquals(1, actual.size());
		assertTrue(actual.contains("1"));

		// size 2
		actual = StringCombos.stringCombos("12");
		assertEquals(3, actual.size());
		assertTrue(actual.contains("1"));
		assertTrue(actual.contains("2"));
		checkContains(actual, "12", "21");

		// size 2 dupicates
		actual = StringCombos.stringCombos("11");
		assertEquals(3, actual.size());
		assertTrue(actual.contains("1"));
		checkContains(actual, "11");

		// size 3
		actual = StringCombos.stringCombos("123");
		assertEquals(7, actual.size());
		assertTrue(actual.contains("1"));
		assertTrue(actual.contains("2"));
		assertTrue(actual.contains("3"));
		checkContains(actual, "12", "21");
		checkContains(actual, "13", "31");
		checkContains(actual, "23", "32");
		checkContains(actual, "123", "132", "213", "231", "312", "321");
	}

}
