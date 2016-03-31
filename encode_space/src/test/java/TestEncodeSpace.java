import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public class TestEncodeSpace {
	
	@Test
	public void test() {
		// len 0
		assertArrayEquals("".toCharArray(), EncodeSpace.encodeSpace("".toCharArray()));
	}


}
