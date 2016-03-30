import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public abstract class TestAnagram {
	
	public abstract Anagram getImpl();

	@Test
	public void test() {
		Anagram impl = getImpl();

		// TODO
	}


}
