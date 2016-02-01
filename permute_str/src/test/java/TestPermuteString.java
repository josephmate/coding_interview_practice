import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public class TestPermuteString {
	
	private Map<String, Integer> countMap(List<String> thingsToCount) {
		Map<String, Integer> map = new HashMap<>();
		for(String s : thingsToCount) {
			if(map.containsKey(s)) {
				map.put(s, map.get(s)+1);
			} else {
				map.put(s, 1);
			}
		}
		return map;
	}
	private void checkLists(List<String> a, List<String> b) {
		Map<String, Integer> aMap = countMap(a);
		Map<String, Integer> bMap = countMap(b);

		assertEquals("expected " + a.toString() + " but got " + b.toString(), aMap.size(), bMap.size());
		for(String aKey : aMap.keySet()) {
			assertEquals("expected " + a.toString() + " but got " + b.toString(), aMap.get(aKey), bMap.get(aKey));
		}
		for(String bKey : bMap.keySet()) {
			assertEquals("expected " + a.toString() + " but got " + b.toString(), aMap.get(bKey), bMap.get(bKey));
		}

	}

	@Test
	public void testPermuteString() {
		// empty case
		checkLists(new ArrayList<>(), PermuteString.permuteString(""));

		// size 1
		List<String> expected = Arrays.asList("a");
		checkLists(expected, PermuteString.permuteString("a"));
		
		// size 2
		expected = Arrays.asList("ab", "ba");
		checkLists(expected, PermuteString.permuteString("ab"));
		// duplicate
		expected = Arrays.asList("aa", "aa");
		checkLists(expected, PermuteString.permuteString("aa"));

		// size 3
		expected = Arrays.asList("abc", "acb", "bac", "bca", "cab", "cba");
		checkLists(expected, PermuteString.permuteString("abc"));
		// size 3 1 dupe
		expected = Arrays.asList("aac", "aca", "aac", "aca", "caa", "caa");
		checkLists(expected, PermuteString.permuteString("aac"));
		// size 3 1 double dupe
		expected = Arrays.asList("aaa", "aaa", "aaa", "aaa", "aaa", "aaa");
		checkLists(expected, PermuteString.permuteString("aaa"));
	}

}
