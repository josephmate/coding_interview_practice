import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public class TestIsRotation {
	
	@Test
	public void test() {
		// len 0
		assertTrue(IsRotation.isRotation("",""));
		// len 1
		assertTrue(IsRotation.isRotation("a","a"));
		assertFalse(IsRotation.isRotation("a","b"));
		// len 2
		assertTrue(IsRotation.isRotation("ab","ab"));
		assertTrue(IsRotation.isRotation("ab","ba"));
		assertFalse(IsRotation.isRotation("ab","ca"));
		// len 3
		assertTrue(IsRotation.isRotation("abc","abc"));
		assertTrue(IsRotation.isRotation("abc","cab"));
		assertTrue(IsRotation.isRotation("abc","bca"));

		// from problem statement
		assertTrue(IsRotation.isRotation("waterbottle","erbottlewat"));
		assertTrue(IsRotation.isRotation("erbottlewat","waterbottle"));
	}


}
