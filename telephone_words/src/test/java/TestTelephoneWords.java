import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public class TestTelephoneWords {
	
	@Test
	public void testGetCharKey() {
		assertEquals('A', TelephoneWords.getCharKey(2,1));
		assertEquals('B', TelephoneWords.getCharKey(2,2));
		assertEquals('E', TelephoneWords.getCharKey(3,2));
		assertEquals('L', TelephoneWords.getCharKey(5,3));
		assertEquals('X', TelephoneWords.getCharKey(9,2));
	}

	@Test
	public void testCountDigits() {
		assertEquals( 1, TelephoneWords.countDigits(0));
		assertEquals( 1, TelephoneWords.countDigits(1));
		assertEquals( 1, TelephoneWords.countDigits(9));
		assertEquals( 2, TelephoneWords.countDigits(10));
		assertEquals( 2, TelephoneWords.countDigits(90));
		assertEquals( 2, TelephoneWords.countDigits(99));
		assertEquals( 3, TelephoneWords.countDigits(100));
		assertEquals( 3, TelephoneWords.countDigits(900));
		assertEquals( 3, TelephoneWords.countDigits(999));
		assertEquals(10, TelephoneWords.countDigits(2147483647));
	}
	
	private void checkList(List<String> expected, List<String> actual){
		assertEquals(expected.size(), actual.size());
		assertEquals(
				new HashSet<>(expected),
				new HashSet<>(actual)
		);
	}

	@Test
	public void testTelephoneWords() {
		checkList(
				Arrays.asList("0"),
				TelephoneWords.telephoneWords(0)
		);

		checkList(
				Arrays.asList("A", "B", "C"),
				TelephoneWords.telephoneWords(2)
		);

		checkList(
				Arrays.asList("1A", "1B", "1C"),
				TelephoneWords.telephoneWords(12)
		);

		checkList(
				Arrays.asList(
					"AJ", "BJ", "CJ",
					"AK", "BK", "CK",
					"AL", "BL", "CL"
				),
				TelephoneWords.telephoneWords(25)
		);

		checkList(
				Arrays.asList(
					"AJ0", "BJ0", "CJ0",
					"AK0", "BK0", "CK0",
					"AL0", "BL0", "CL0"
				),
				TelephoneWords.telephoneWords(250)
		);
	}

}
