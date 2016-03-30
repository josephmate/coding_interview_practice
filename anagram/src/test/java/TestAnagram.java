import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public abstract class TestAnagram {
	
	public abstract Anagram getImpl();

	@Test
	public void test() {
		Anagram impl = getImpl();

		// len 0
		assertTrue(impl.anagram("".toCharArray(), "".toCharArray()));

		// len 1
		assertTrue(impl.anagram("a".toCharArray(), "a".toCharArray()));
		assertFalse(impl.anagram("a".toCharArray(), "b".toCharArray()));

		// len 2
		assertTrue(impl.anagram("ba".toCharArray(), "ab".toCharArray()));
		assertTrue(impl.anagram("ab".toCharArray(), "ab".toCharArray()));
		assertTrue(impl.anagram("aa".toCharArray(), "aa".toCharArray()));
		assertFalse(impl.anagram("aa".toCharArray(), "aab".toCharArray()));
		assertFalse(impl.anagram("aa".toCharArray(), "ab".toCharArray()));
		assertFalse(impl.anagram("aa".toCharArray(), "ac".toCharArray()));

		// len 3
		assertTrue(impl.anagram("bca".toCharArray(), "acb".toCharArray()));
		assertFalse(impl.anagram("bca".toCharArray(), "acbd".toCharArray()));
		assertFalse(impl.anagram("bca".toCharArray(), "acd".toCharArray()));
	}


}
