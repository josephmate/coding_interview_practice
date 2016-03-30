
import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public class TestSortAnagram extends TestAnagram {

	public Anagram getImpl() {
		return new SortAnagram();
	}

}
