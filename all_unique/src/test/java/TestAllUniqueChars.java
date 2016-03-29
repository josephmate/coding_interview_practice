import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public abstract class TestAllUniqueChars {
	
	public abstract AllUniqueChars getImpl();

	@Test
	public void test() {
		AllUniqueChars impl = getImpl();

		// empty
		assertTrue(impl.allUniqueChars("".toCharArray()));
		// one char
		assertTrue(impl.allUniqueChars("1".toCharArray()));
		// two char
		assertTrue(impl.allUniqueChars("12".toCharArray()));
		assertFalse(impl.allUniqueChars("22".toCharArray()));
		// three char
		assertTrue(impl.allUniqueChars("132".toCharArray()));
		assertFalse(impl.allUniqueChars("133".toCharArray()));
		assertFalse(impl.allUniqueChars("313".toCharArray()));
		assertFalse(impl.allUniqueChars("331".toCharArray()));
	}


}
