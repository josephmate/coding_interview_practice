import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public class TestEncodeSpace {
	
	@Test
	public void test() {
		// len 0
		assertArrayEquals("".toCharArray(), EncodeSpace.encodeSpace("".toCharArray()));

		// len 1
		assertArrayEquals("a".toCharArray(), EncodeSpace.encodeSpace("a".toCharArray()));
		assertArrayEquals("%20".toCharArray(), EncodeSpace.encodeSpace(" ".toCharArray()));

		//len 2
		assertArrayEquals("ab".toCharArray(), EncodeSpace.encodeSpace("ab".toCharArray()));
		assertArrayEquals("a%20".toCharArray(), EncodeSpace.encodeSpace("a ".toCharArray()));
		assertArrayEquals("%20b".toCharArray(), EncodeSpace.encodeSpace(" b".toCharArray()));

		//len 2
		assertArrayEquals("abc".toCharArray(), EncodeSpace.encodeSpace("abc".toCharArray()));
		assertArrayEquals("a%20c".toCharArray(), EncodeSpace.encodeSpace("a c".toCharArray()));
		assertArrayEquals("a%20%20".toCharArray(), EncodeSpace.encodeSpace("a  ".toCharArray()));
	}


}
